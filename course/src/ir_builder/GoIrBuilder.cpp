//
// Created by volodya on 12.03.24.
//

#include "GoIrBuilder.h"

#include <utility>
#include <llvm/IR/Verifier.h>

void GoIrBuilder::generateBuiltIns() {
  std::vector<FunctionWrapper> functions = {FunctionWrapper("",
                                                            "printf",
                                                            TypeWrapper::GetFunction(*context.TheContext,
                                                                                     TypeWrapper::GetInt(*context.TheContext,
                                                                                                         true,
                                                                                                         32),
                                                                                     std::vector<TypeWrapper>{
                                                                                         TypeWrapper::GetInt(*context.TheContext,
                                                                                                             true,
                                                                                                             8).getPointerTo()},
                                                                                     true),
                                                            nullptr), FunctionWrapper("",
                                                                                      "scanf",
                                                                                      TypeWrapper::GetFunction(*context.TheContext,
                                                                                                               TypeWrapper::GetInt(
                                                                                                                   *context.TheContext,
                                                                                                                   true,
                                                                                                                   32),
                                                                                                               std::vector<
                                                                                                                   TypeWrapper>{
                                                                                                                   TypeWrapper::GetInt(
                                                                                                                       *context.TheContext,
                                                                                                                       true,
                                                                                                                       8).getPointerTo()},
                                                                                                               true),
                                                                                      nullptr), FunctionWrapper("",
                                                                                                                "ALLOCATE",
                                                                                                                TypeWrapper::GetFunction(
                                                                                                                    *context.TheContext,
                                                                                                                    TypeWrapper::GetPointer(
                                                                                                                        *context.TheContext,
                                                                                                                        {}),
                                                                                                                    std::vector<
                                                                                                                        TypeWrapper>{
                                                                                                                        TypeWrapper::GetInt(
                                                                                                                            *context.TheContext,
                                                                                                                            true,
                                                                                                                            32)},
                                                                                                                    true),
                                                                                                                nullptr),
                                            FunctionWrapper("",
                                                            "GC_CALL",
                                                            TypeWrapper::GetFunction(*context.TheContext,
                                                                                     {},
                                                                                     std::vector<TypeWrapper>{
                                                                                         TypeWrapper::GetInt(*context.TheContext,
                                                                                                             true,
                                                                                                             32)},
                                                                                     true),
                                                            nullptr), FunctionWrapper("",
                                                                                      "GC_PUSHSTACK",
                                                                                      TypeWrapper::GetFunction(*context.TheContext,
                                                                                                               {},
                                                                                                               {},
                                                                                                               false),
                                                                                      nullptr),};

  for (auto &func : functions) {
    auto fId = context.GetFunctionID(func.Name);
    auto f = llvm::Function::Create((llvm::FunctionType *) func.type.getType(),
                                    llvm::Function::ExternalLinkage,
                                    func.Name,
                                    *context.TheModule);

    func.Function = f;
    context.Functions.insert({fId, func});
  }

  context.stackController.PushLevel(nullptr);
  context.stackController.AddNamedValue("true", _createIntConstant(1, false, 1).GetValuePtr());
  context.stackController.AddNamedValue("false", _createIntConstant(0, false, 1).GetValuePtr());
}

EValue GoIrBuilder::assignToInterface(ValueWrapper::ptr interface, const ValueWrapper::ptr &value) {
  auto ty = interface->getType();
  if (value->isConstant()) {
    return Error::Create("Can't convert const struct to interface");
  }
  if (interface->isConstant()) {
    return Error::Create("Can't convert struct to interface; Interface must be RHS");
  }
  auto SI = ty.getTypeDetails().structInfo;

  auto mem = interface->getValue();

  std::vector<llvm::Value *> values = {value->getValue(),};
  for (const auto &field : SI->fieldNames) {
    if (field == "_") {
      continue;
    }

    auto method = context.Functions.find(context.GetFunctionID(context.GetMethodId(field, value->getType().getName())));
    if (method == context.Functions.end()) {
      return {{}, Error::Create("Can't find method " + field + ":"
                                    + context.GetFunctionID(context.GetMethodId(field, value->getType().getName())))};
    }

    values.push_back(method->second.Function);
  }

  {
    size_t fieldI = 0;
    for (auto llvmValue : values) {
      std::vector<llvm::Value *> indexes = {llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, 0)),
                                            llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, fieldI))};
      auto valptr = context.Builder->CreateGEP(ty.getType(), mem, indexes);

      context.Builder->CreateStore(llvmValue, valptr);
      fieldI++;
    }
  }

  return interface;

}
Error::ptr GoIrBuilder::createTypeDecl(GoParser::TypeDeclContext *ctx) {
  if (ctx->typeSpec(0)->aliasDecl()) {
    return Error::Create("Warning: Aliases is not supported", ctx);
  }
  auto def = ctx->typeSpec(0)->typeDef();

  auto defName = def->IDENTIFIER()->getText();
  auto type = context.GetType(def->type_());
  if (!type) {
    return Error::Create("Error: Can't declare type " + defName, ctx);
  }
  type->setName(defName);

  context.Types.insert({defName, *type});

  return nullptr;
}
EValue GoIrBuilder::createFunction(antlr4::tree::ParseTree *ctx,
                                   GoParser::ReceiverContext *receiver,
                                   antlr4::tree::TerminalNode *IDENTIFIER,
                                   GoParser::SignatureContext *signature,
                                   GoParser::BlockContext *block,
                                   GoParserVisitor *visitor) {
  std::vector<TypeWrapper> args;
  std::optional<TypeWrapper> retT = {};

  std::optional<TypeWrapper> recvTy = {};
  bool recVPtr = false;

  if (receiver) {
    recvTy = context.GetType(receiver->parameters()->parameterDecl(0)->type_());
    if (!recvTy) {
      return {{}, Error::Create("Error: can't create method of undeclared struct", signature)};
    }

    if (recvTy->getTypeDetails().pointerInfo) {
      if (!recvTy->getTypeDetails().pointerInfo->type) {
        return {{}, Error::Create("Error: can't create method of void *", receiver)};
      }
      recvTy = *recvTy->getTypeDetails().pointerInfo->type;
      recVPtr = true;
    }

    if (!recvTy->getTypeDetails().structInfo) {
      return {{}, Error::Create("Error: can't create not a struct method", receiver)};
    }

    args.push_back(recvTy->getPointerTo());
  }

  for (auto arg : signature->parameters()->parameterDecl()) {
    auto type = context.GetType(arg->type_());
    if (!type) {
      std::cerr << "Error: Can't find type : " << ctx->getText() << std::endl;
      return {{}, Error::Create("Can't find type", arg)};
    }
    for (auto argN : arg->identifierList()->IDENTIFIER()) {
      args.push_back(*type);
    }
  }

  if (signature->result()) {
    auto goType = signature->result()->type_();
    if (!goType) {
      return {{}, Error::Create("Error: Not supported multiple return", signature->result())};
    }
    auto type = context.GetType(goType);
    if (!type) {
      return {{}, Error::Create("Can't find type", signature->result())};
    }
    retT = *type;
  }

  auto nameCode = IDENTIFIER->getText();
  if (recvTy) {
    nameCode = context.GetMethodId(nameCode, recvTy->getName());
  }

  auto name = context.GetFunctionID(nameCode);

  auto funcT = TypeWrapper::GetFunction(*context.TheContext, retT, args, false);
  auto func = llvm::Function::Create((llvm::FunctionType *) funcT.getType(),
                                     llvm::Function::ExternalLinkage,
                                     name,
                                     *context.TheModule);
  auto funcWrap = FunctionWrapper(context.ModuleName, nameCode, funcT, func);
  context.Functions.insert({name, funcWrap});

  if (!block) {
    return {funcWrap.getValue(), {}};
  }

  auto BB = llvm::BasicBlock::Create(*context.TheContext, "entry", func);
  context.Builder->SetInsertPoint(BB);
  context.stackController.PushLevel(BB);

  int i = 0;
  if (recvTy) {
    i++;
    auto nameArg = receiver->parameters()->parameterDecl(0)->identifierList()->IDENTIFIER(0)->getText();
    llvm::Value *argVal = func->getArg(0);
    auto argTy = *recvTy;

    if (recVPtr) {
      auto var = context.Builder->CreateAlloca(recvTy->getType()->getPointerTo());
      context.Builder->CreateStore(argVal, var);
      argVal = var;
      argTy = argTy.getPointerTo();
    }

    context.stackController.AddNamedValue(nameArg, ValueWrapper::Create(false, argTy, argVal));
  }

  for (auto arg : signature->parameters()->parameterDecl()) {
    auto ty = context.GetType(arg->type_());
    for (auto argN : arg->identifierList()->IDENTIFIER()) {
      auto llvmArg = func->getArg(i);
      i++;

      auto var = context.Builder->CreateAlloca(ty->getType());

      context.Builder->CreateStore(llvmArg, var);

      context.stackController.AddNamedValue(argN->getText(), ValueWrapper::Create(false, *ty, (llvm::Value *) var));
    }
  }

  if (!block->statementList()) {
    return {{}, Error::Create("Error: Can't create function " + nameCode + ". Not found function body.", nullptr)};
  }

  for (auto statement : block->statementList()->statement()) {
    statement->accept(visitor);
  }

  context.stackController.PopLevel();

  if (!retT) context.Builder->CreateRetVoid();
  {
    std::string err_string;
    llvm::raw_string_ostream st(err_string);
    if (llvm::verifyFunction(*func, &st)) {
      return {{}, Error::Create("Lvvm function verify error: " + err_string, ctx)};
    }
  }
  return {funcWrap.getValue(), {}};
}
EValue GoIrBuilder::_createIntConstant(int value, bool isSigned, size_t size) {
  TypeWrapper type = TypeWrapper::GetInt(*context.TheContext, isSigned, size);
  llvm::Value *retv = llvm::ConstantInt::get(*context.TheContext, llvm::APInt(size, value, isSigned));

  return {ValueWrapper::Create(true, type, retv), {}};
}
EValue GoIrBuilder::createIntConstant(int value) {
  return _createIntConstant(value, true, 32);
}
EValue GoIrBuilder::createFloatConstant(double num) {
  auto ty = TypeWrapper::GetFloat(*context.TheContext);
  return {ValueWrapper::Create(true, ty, llvm::ConstantFP::get(ty.getType(), llvm::APFloat(num))), {}};
}
EValue GoIrBuilder::createNil() {
  auto ty = TypeWrapper::GetPointer(*context.TheContext, {});
  return {ValueWrapper::Create(true, ty, llvm::ConstantPointerNull::get((llvm::PointerType *) ty.getType())), {}};
}
void GoIrBuilder::setModuleName(std::string name) {
  context.ModuleName = std::move(name);
}
EValue GoIrBuilder::createStringConstant(const std::string &data) {
  auto strValue = llvm::ConstantDataArray::getString(*context.TheContext, data, true);

  TypeWrapper charTy = TypeWrapper::GetInt(*context.TheContext, false, 8);
  auto value = allocateMemory(charTy, data.size() + 2)->getPointerTo();

  context.Builder->CreateStore(strValue, value->getValue());

  return value;
}
std::optional<TypeWrapper> GoIrBuilder::GetType(GoParser::Type_Context *typeContext) {
  return context.GetType(typeContext);
}
EValue GoIrBuilder::toRHS(EValue val) {
  if (!val) {
    return val;
  }
  return {val->toRHS(*context.Builder), {}};
}
EValue GoIrBuilder::addNamedValue(const std::string &name, EValue value) {
  if (!value) {
    return value;
  }
  context.stackController.AddNamedValue(name, value.GetValuePtr());
  if (!value->isConstant()) value->getPointerTo()->getValue()->setName(name);

  return value->getPointerTo();
}

EValue GoIrBuilder::createReturn(std::vector<EValue> values) {
  if (values.empty()) {
    context.Builder->CreateRetVoid();
    return {nullptr, nullptr};
  }

  if (values.size() > 1) {
    return Error::Create("Can't return more than one value");
  }
  auto expr = toRHS(values[0]);
  context.Builder->CreateRet(expr->getValue());

  return expr;
}
EValue GoIrBuilder::allocateMemory(TypeWrapper ty, size_t count, const std::string &name) {
  auto offsets = ty.getLinkPositions(context.TheModule->getDataLayout());
  auto typeSize = ty.getSizeOf(context.TheModule->getDataLayout());
  std::vector<llvm::Value *> args = {llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, typeSize * count)),
                                     llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, offsets.size()))};
  for (int i = 0; i < count; i++) {
    for (auto offset : offsets) {
      args.push_back(llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, typeSize * i + offset)));
    }
  }

  auto funcRes = context.Builder->CreateCall(context.Functions.find("main_ALLOCATE")->second.Function, args);
  funcRes->setName(name);

  return ValueWrapper::Create(false, ty, funcRes);
}
EValue GoIrBuilder::assign(EValue left, EValue right) {
  if (!left) return left;
  if (!right) return right;

  if (left->isConstant()) {
    return Error::Create("Can't assign to constant");
  }
  if (left->getType().getTypeDetails().structInfo && left->getType().getTypeDetails().structInfo->isInterface) {
    // @todo: make normal cast
    return assignToInterface(left.GetValuePtr(), right.GetValuePtr());
  }

  auto value = cast(std::move(right), left->getType());
  if (!value) {
    return value;
  }
  context.Builder->CreateStore(value->getValue(), left->getValue());

  return left;
}
EValue GoIrBuilder::cast(EValue value, const TypeWrapper &type) {
  if (!value) return value;

  auto res = value->castTo(*context.Builder, type); // @todo rewrite
  if (!res) {
    return Error::Create("Can't cast from " + value->getType().getName() + " to " + type.getName());
  }

  return res;
}
std::optional<TypeWrapper> GoIrBuilder::GetType(const std::string &name) {
  return TypeWrapper::GetTypeByName(name, *context.TheContext, context.Types);
}
EValue GoIrBuilder::createCall(EValue function, std::vector<EValue> ArgsV) {
  if (function && function->getType().getTypeDetails().pointerInfo) {
    function = toRHS(function);
    auto funcT = function->getType().getTypeDetails().pointerInfo->type;
    function = ValueWrapper::Create(true, *funcT, function->getValue(), function->getBinding());
  }

  if (!function || !function->getType().getTypeDetails().functionInfo) {
    return Error::Create("Can't call not a function");
  }
  auto funcinfo = *function->getType().getTypeDetails().functionInfo;
  {
    size_t typesCount = funcinfo.arguments.size();
    size_t argsCount = ArgsV.size();
    if (function->getBinding()) argsCount++;

    if (!funcinfo.isVarargs && typesCount != argsCount || funcinfo.isVarargs && argsCount < typesCount) {
      return Error::Create("Incorrect arguments value");
    }
  }

  std::vector<llvm::Value *> values;
  size_t typeI = 0;
  if (function->getBinding()) {
    EValue binding = function->getBinding();
    binding = cast(binding, funcinfo.arguments[0]);
    binding = toRHS(binding);
    if (!binding) {
      return binding;
    }
    values.emplace_back(binding->getValue());
    typeI++;
  }

  for (size_t argI = 0; argI < ArgsV.size(); argI++, typeI++) {
    auto arg = ArgsV[argI];
    if (typeI < funcinfo.arguments.size()) {
      auto ty = funcinfo.arguments[typeI];
      arg = cast(arg, ty);
    }
    arg = toRHS(arg);
    if (!arg) return arg;
    values.emplace_back(arg->getValue());
  }

  context.Builder->CreateCall(context.Functions.find("main_GC_PUSHSTACK")->second.Function, {});

  llvm::Value *value =
      context.Builder->CreateCall(llvm::FunctionCallee((llvm::FunctionType *) function->getType().getType(),
                                                       function->getValue()), values);

  std::vector<llvm::Value *> gcVals = {};
  auto retType = function->getType().getTypeDetails().functionInfo->retType;
  if (retType) {
    if (retType->getTypeDetails().pointerInfo) {
      gcVals.push_back(value);
    } else if (retType->getTypeDetails().structInfo) {
      // @todo
      std::cerr << "Warning: Can't safe struct" << std::endl;
    }
  }
  gcVals.insert(gcVals.begin(), llvm::ConstantInt::get(*context.TheContext, llvm::APInt(32, gcVals.size())));
  context.Builder->CreateCall(context.Functions.find("main_GC_CALL")->second.Function, gcVals);

  if (!retType) {
    return {};
  }

  return ValueWrapper::Create(true, *retType, value);
}
EValue GoIrBuilder::getByIndex(EValue left, EValue indexV) {
  indexV = toRHS(indexV);

  if (!left->getType().getTypeDetails().arrayInfo) return Error::Create("Index supports only on arrays");

  return _getByIndex(left, indexV, *left->getType().getTypeDetails().arrayInfo->type);

}
EValue GoIrBuilder::_getByIndex(EValue &left, EValue indexV, const TypeWrapper &type) {
  if (left->isConstant()) {
    auto val = context.Builder->CreateExtractElement(left->getValue(), indexV->getValue());
    return ValueWrapper::Create(true, type, val);
  }

  std::vector<llvm::Value *> indexes = {createIntConstant(0)->getValue(), indexV->getValue()};

  auto valptr = context.Builder->CreateGEP(left->getType().getType(), left->getValue(), indexes);

  return ValueWrapper::Create(false, type, valptr);
}
EValue GoIrBuilder::getStructField(EValue left, std::string fieldName) {
  if (!left) return left;
  if (left->getType().getTypeDetails().pointerInfo) {
    left = deref(left);
  }

  auto structInfo = left->getType().getTypeDetails().structInfo;
  if (!structInfo) return Error::Create("Dot operation supports only for structs");

  auto
      method = context.Functions.find(context.GetFunctionID(context.GetMethodId(fieldName, left->getType().getName())));
  if (method != context.Functions.end()) {
    return method->second.bind(left->getPointerTo());
  }

  size_t fieldI = 0;
  std::optional<TypeWrapper> fieldType;
  for (const auto &f : structInfo->fieldNames) {
    if (f == fieldName) {
      fieldType = structInfo->fields[fieldI];
      break;
    }
    fieldI++;
  }

  if (!fieldType) return Error::Create("Can't find struct field " + fieldName);

  auto res = _getByIndex(left, createIntConstant((int) fieldI), *fieldType);

  auto binding = left;
  if (structInfo->isInterface) {
    binding = _getByIndex(left, createIntConstant(0), TypeWrapper::GetPointer(*context.TheContext, {}));
  }

  return ValueWrapper::Create(res->isConstant(), *fieldType, res->getValue(), binding.GetValuePtr());
}

EValue GoIrBuilder::deref(EValue value) {
  if (!value) return value;
  if (!value->getType().getTypeDetails().pointerInfo) return Error::Create("Can dereference only a pointer");
  if (!value->getType().getTypeDetails().pointerInfo->type)
    return Error::Create("Can dereference only a non-void pointer");

  auto res = toRHS(value);
  return ValueWrapper::Create(false, *res->getType().getTypeDetails().pointerInfo->type, res->getValue());
}
EValue GoIrBuilder::getNamed(const std::string &name) {
  auto func = context.Functions.find(context.GetFunctionID(name));
  if (func != context.Functions.end()) {
    return func->second.getValue();
  }
  auto res = context.stackController.GetNamedValue(name);
  if (!res) return Error::Create("Can't find id: " + name);

  return res;
}
EValue GoIrBuilder::createBinOperation(GoIrBuilder::BinaryOperation op, EValue left, EValue right) {
  auto L = toRHS(left);
  auto R = toRHS(right);

  auto ComputedType = L->getType().getHigherType(*context.TheContext, R->getType());
  if (!ComputedType) return Error::Create("Can't compute type of result operation (may be it's not a numbers...): ");

  llvm::Value *res = nullptr;
  auto type = *ComputedType;
  L = cast(L, type);
  R = cast(R, type);

  bool IsRetBool = false;

  typedef enum {
    Float, IntSigned, IntUnsigned, Ptr, Undefined
  } opTypeEnum;

  opTypeEnum optype = Undefined;

  if (type.getTypeDetails().intInfo) {
    if (type.getTypeDetails().intInfo->isSigned) optype = IntSigned;
    else optype = IntUnsigned;
  } else if (type.getTypeDetails().floatInfo) optype = Float;
  else if (type.getTypeDetails().pointerInfo) optype = Ptr;
  if (optype == Undefined) {
    return Error::Create("Operation with this type is not supported");
  }

  switch (op) {
    case Add:
      switch (optype) {
        case IntUnsigned:
        case IntSigned:res = context.Builder->CreateAdd(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFAdd(L->getValue(), R->getValue());
      }
      break;
    case Sub:
      switch (optype) {
        case IntUnsigned:
        case IntSigned:res = context.Builder->CreateSub(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFSub(L->getValue(), R->getValue());
      }
      break;
    case Mul:
      switch (optype) {
        case IntUnsigned:
        case IntSigned:res = context.Builder->CreateMul(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFMul(L->getValue(), R->getValue());
      }
      break;
    case Div:
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateUDiv(L->getValue(), R->getValue());
          break;
        case IntSigned:res = context.Builder->CreateSDiv(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFDiv(L->getValue(), R->getValue());
      }
      break;
    case Mod:
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateURem(L->getValue(), R->getValue());
          break;
        case IntSigned:res = context.Builder->CreateSRem(L->getValue(), R->getValue());
          break;
      }
      break;
    case Gt:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateICmpUGT(L->getValue(), R->getValue());
          break;

        case IntSigned:res = context.Builder->CreateICmpSGT(L->getValue(), R->getValue());
          break;

        case Float:res = context.Builder->CreateFCmpOGT(L->getValue(), R->getValue());
          break;

      }
      break;
    case Lt:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateICmpULT(L->getValue(), R->getValue());
          break;

        case IntSigned:res = context.Builder->CreateICmpSLT(L->getValue(), R->getValue());
          break;

        case Float:res = context.Builder->CreateFCmpOLT(L->getValue(), R->getValue());
          break;

      }
      break;
    case Ge:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateICmpUGE(L->getValue(), R->getValue());
          break;
        case IntSigned:res = context.Builder->CreateICmpSGE(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFCmpOGE(L->getValue(), R->getValue());
          break;
      }
      break;
    case Le:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:res = context.Builder->CreateICmpULE(L->getValue(), R->getValue());
          break;
        case IntSigned:res = context.Builder->CreateICmpSLE(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFCmpOLE(L->getValue(), R->getValue());
          break;
      }
      break;
    case Eq:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:
        case IntSigned:
        case Ptr:res = context.Builder->CreateICmpEQ(L->getValue(), R->getValue());
          break;
        case Float:res = context.Builder->CreateFCmpOGE(L->getValue(), R->getValue());
          break;
      }
      break;
    case Ne:IsRetBool = true;
      switch (optype) {
        case IntUnsigned:
        case IntSigned:
        case Ptr:res = context.Builder->CreateICmpNE(L->getValue(), R->getValue());
          break;
        case Float:IsRetBool = true;
          res = context.Builder->CreateFCmpONE(L->getValue(), R->getValue());
          break;

      }
      break;

  }

  if (!res) {
    return Error::Create("This operation is not supported: ");
  }

  auto retType = IsRetBool ? TypeWrapper::GetInt(*context.TheContext, false, 1) : type;
  return ValueWrapper::Create(true, retType, res);
}
EValue GoIrBuilder::createIf(EValue condition, std::function<void()> ifBuilder, std::function<void()> elseBuilder) {
  _createIf(std::move(condition), std::move(ifBuilder), std::move(elseBuilder));
  return {};
}
EValue GoIrBuilder::createFor(std::function<void()> Init,
                              std::function<EValue()> Cond,
                              std::function<void()> After,
                              std::function<void()> Block) {
  llvm::Function *TheFunction = context.Builder->GetInsertBlock()->getParent();

  context.stackController.PushLevel(context.stackController.GetBlock());

  Init();

  auto StartCond = Cond();
  StartCond = toRHS(StartCond);

  auto LoopBB = llvm::BasicBlock::Create(*context.TheContext, "loop", TheFunction);
  auto AfterBB = llvm::BasicBlock::Create(*context.TheContext, "afterloop", TheFunction);

  context.Builder->CreateCondBr(StartCond->getValue(), LoopBB, AfterBB);

  context.Builder->SetInsertPoint(LoopBB);

  Block();

  After();

  auto EndCond = Cond();
  EndCond = toRHS(EndCond);

  context.Builder->CreateCondBr(EndCond->getValue(), LoopBB, AfterBB);

  context.stackController.PopLevel();

  context.Builder->SetInsertPoint(AfterBB);

  return {};
}
const Context &GoIrBuilder::GetContext() const {
  return context;
}

EValue GoIrBuilder::_createAndOr(bool isAnd, EValue left, std::function<EValue()> rightBuilder) {
  auto boolType = TypeWrapper::GetInt(*context.TheContext, false, 1);

  left = toRHS(left);
  EValue right;
  auto rtRet = [rightBuilder, &right, this] {
    right = toRHS(rightBuilder());
  };
  auto nop = []{};

  auto ifctx = isAnd ? _createIf(left, rtRet) : _createIf(left, nop, rtRet);
  if (!right) return right;

  auto PN = context.Builder->CreatePHI(boolType.getType(), 2);
  if (isAnd) {
    PN->addIncoming(right->getValue(), ifctx._if);
    PN->addIncoming(_createIntConstant(0, false,1)->getValue(), ifctx._else);
  } else {
    PN->addIncoming(_createIntConstant(1, false,1)->getValue(), ifctx._if);
    PN->addIncoming(right->getValue(), ifctx._else);
  }
  return ValueWrapper::Create(true, boolType, PN);
}

EValue GoIrBuilder::createAnd(EValue left, std::function<EValue()> rightBuilder) {
  return _createAndOr(true, std::move(left), std::move(rightBuilder));
}

EValue GoIrBuilder::createOr(EValue left, std::function<EValue()> rightBuilder) {
  return _createAndOr(false, std::move(left), std::move(rightBuilder));
}

GoIrBuilder::IFContext GoIrBuilder::_createIf(EValue condition,
                                              std::function<void()> ifBuilder,
                                              std::function<void()> elseBuilder) {
  condition = toRHS(condition);
  auto parent = context.stackController.GetBlock()->getParent();

  auto ThenBB = llvm::BasicBlock::Create(*context.TheContext, "if", parent);
  auto ElseBB = llvm::BasicBlock::Create(*context.TheContext, "else");
  auto MergeBB = llvm::BasicBlock::Create(*context.TheContext, "after-if");

  context.Builder->CreateCondBr(condition->getValue(), ThenBB, ElseBB);
  context.Builder->SetInsertPoint(ThenBB);

  context.stackController.PushLevel(context.stackController.GetBlock());

  ifBuilder();

  context.Builder->CreateBr(MergeBB);

  parent->insert(parent->end(), ElseBB);
  context.Builder->SetInsertPoint(ElseBB);

  context.stackController.PopLevel();

  if (elseBuilder) {
    context.stackController.PushLevel(context.stackController.GetBlock());
    elseBuilder();
    context.stackController.PopLevel();
  }
  context.Builder->CreateBr(MergeBB);

  parent->insert(parent->end(), MergeBB);
  context.Builder->SetInsertPoint(MergeBB);

  return {ThenBB, ElseBB, MergeBB};
}




