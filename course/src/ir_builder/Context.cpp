//
// Created by volodya on 12.03.24.
//

#include "Context.h"

void StackController::PushLevel(llvm::BasicBlock *block,
                                llvm::BasicBlock *breakBlockTo,
                                llvm::BasicBlock *continueBlockTo) {
  Stack.emplace_back(StackBlockDetails{
      block,
      breakBlockTo ? breakBlockTo : GetBreakToBlock(),
      continueBlockTo ? continueBlockTo : GetContinueToBlock(),
  });
}

void StackController::PopLevel() {
  // @todo destruct all;

  Stack.pop_back();
}

bool StackController::AddNamedValue(const std::string &name, ValueWrapper::ptr value) {
  auto ValueInStack = Stack.rbegin()->values.find(name);
  if (ValueInStack != Stack.rbegin()->values.end()) {
    std::cerr << "Variable " << name << " allready defined" << std::endl;
    return false;
  }

  Stack.rbegin()->values.insert({name, value});
  return true;
}

ValueWrapper::ptr StackController::GetNamedValue(const std::string name, std::string module) {
  for (auto block = Stack.rbegin(); block != Stack.rend(); block++) {
    if (block->values.find(name) != block->values.end()) {
      return block->values.find(name)->second;
    }
  }
  return nullptr;
}

llvm::BasicBlock *StackController::GetBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->thisBlock;
}
llvm::BasicBlock *StackController::GetBreakToBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->breakToBlock;
}
llvm::BasicBlock *StackController::GetContinueToBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->continueBlockTo;
}

std::string Context::GetMethodId(const std::string &name, const std::string &struct_name) const {
  return struct_name + "__struct__" + name;
}

std::string Context::GetFunctionID(const std::string &name) const {
  return this->ModuleName + '_' + name;
}

Context::Context() {
  TheContext = std::make_shared<llvm::LLVMContext>();
  Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);
  TheModule = std::make_shared<llvm::Module>("main", *TheContext);

  size_t standartIntSize = 32;
  Types = std::map<std::string, TypeWrapper>{{"bool", TypeWrapper::GetInt(*TheContext, false, 1)},
                                             {"int", TypeWrapper::GetInt(*TheContext, true, standartIntSize)},
                                             {"int8", TypeWrapper::GetInt(*TheContext, true, 8)},
                                             {"int16", TypeWrapper::GetInt(*TheContext, true, 16)},
                                             {"int32", TypeWrapper::GetInt(*TheContext, true, 32)},
                                             {"int64", TypeWrapper::GetInt(*TheContext, true, 64)},
                                             {"uint", TypeWrapper::GetInt(*TheContext, false, standartIntSize)},
                                             {"uint8", TypeWrapper::GetInt(*TheContext, false, 8)},
                                             {"uint16", TypeWrapper::GetInt(*TheContext, false, 16)},
                                             {"uint32", TypeWrapper::GetInt(*TheContext, false, 32)},
                                             {"uint64", TypeWrapper::GetInt(*TheContext, false, 64)},
                                             {"byte", TypeWrapper::GetInt(*TheContext, false, 8)},
                                             {"float32", TypeWrapper::GetFloat(*TheContext, false)},
                                             {"float64", TypeWrapper::GetFloat(*TheContext, true)},
                                             {"rune", TypeWrapper::GetInt(*TheContext, false, 8)},
                                             {"string", TypeWrapper::GetInt(*TheContext, false, 8).getPointerTo()},};
}

std::optional<TypeWrapper> Context::GetType(GoParser::Type_Context *typeContext) {
  if (!typeContext) {
    std::cerr << "GetType(nil) error";
  }
  if (typeContext->typeName()) {
    auto typeName = typeContext->typeName()->getText();
    auto ty = TypeWrapper::GetTypeByName(typeName, *TheContext, Types);
    if (!ty) {
      std::cerr << typeName << " is not supported: " << typeContext->getText() << std::endl;
    };
    return ty;
  }
  if (typeContext->type_()) {
    return GetType(typeContext->type_());
  }

  if (!typeContext->typeLit()) {
    std::cerr << "Smth go wrong :" << typeContext->getText() << std::endl;
    return {};
  }
  if (typeContext->typeLit()->interfaceType()) {
    auto interfaceTN = typeContext->typeLit()->interfaceType();

    std::vector<std::pair<std::string, TypeWrapper>> fields = {{"_", TypeWrapper::GetPointer(*TheContext, {})},};

    for (auto &method : interfaceTN->methodSpec()) {
      auto name = method->IDENTIFIER()->getText();
      std::optional<TypeWrapper> result;

      if (method->result()) {
        result = GetType(method->result()->type_());
        if (!result) {
          std::cerr << "Can't compute type:" << method->getText() << std::endl;
          return {};
        }

      }

      std::vector<TypeWrapper> params = {TypeWrapper::GetPointer(*TheContext, {})};
      for (auto decl : method->parameters()->parameterDecl()) {
        auto ty = GetType(decl->type_());
        if (!ty) {
          std::cerr << "Can't compute type:" << method->getText() << std::endl;
          return {};
        }
        params.push_back(*ty);
      }

      auto func = TypeWrapper::GetFunction(*TheContext, result, params).getPointerTo();
      fields.emplace_back(name, func);
    }

    return TypeWrapper::GetStruct(*TheContext, fields, true);
  }

  if (typeContext->typeLit()->structType()) {
    auto structTN = typeContext->typeLit()->structType();

    std::vector<std::pair<std::string, TypeWrapper>> fields = {};

    for (auto &field : structTN->fieldDecl()) {
      // @todo support multiple
      auto fieldName = field->identifierList()->IDENTIFIER(0)->getText();
      auto fieldT = GetType(field->type_());
      if (!fieldT) {
        std::cerr << "Can't find type of " << fieldName << ": " << field->getText() << std::endl;
        std::cerr << typeContext->getText() << std::endl;
        return {};
      }

      fields.push_back({fieldName, *fieldT});

    }

    return TypeWrapper::GetStruct(*TheContext, fields);

  }

  if (typeContext->typeLit()->arrayType()) {
    auto child = typeContext->typeLit()->arrayType()->elementType()->type_();
    auto childType = GetType(child);
    if (!childType) {
      return {};
    }
    auto countText = typeContext->typeLit()->arrayType()->arrayLength()->getText();
    auto count = atoi(countText.c_str());

    if (count <= 0) {
      std::cerr << "Can't create array with length " << count << ": " << typeContext->getText();
      return {};
    }

    return childType->getArrayOf(count);
  }
  if (typeContext->typeLit()->pointerType()) {
    auto pointTo = GetType(typeContext->typeLit()->pointerType()->type_());
    if (!pointTo) {
      std::cerr << "Warning: can't find pointer declaration (use void ptr): " << typeContext->getText() << std::endl;
    }

    return TypeWrapper::GetPointer(*TheContext, pointTo);

  }
  return {};
}
