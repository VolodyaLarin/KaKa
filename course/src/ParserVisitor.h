//
// Created by volodya on 05.03.24.
//

#ifndef APP_PARSERVISITOR_H
#define APP_PARSERVISITOR_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <regex>

#include <boost/algorithm/string/replace.hpp>
#include "./parser/GoParserBaseVisitor.h"


class TypeWrapper;

struct TypeDetails {
    struct IntInfo {
        bool isSigned;
        size_t bitSize;
    };
    struct FloatInfo {
        size_t bitSize;
    };

    struct FunctionInfo {
        bool isVarargs = false;
        std::shared_ptr<TypeWrapper> retType;
        std::vector<TypeWrapper> arguments;
    };

    struct StructInfo {
        std::vector<TypeWrapper> fields;
        std::vector<std::string> fieldNames;
    };

    struct PointerInfo {
        std::shared_ptr<TypeWrapper> type;
    };

    std::optional<IntInfo> intInfo = {};
    std::optional<FloatInfo> floatInfo = {};
    std::optional<FunctionInfo> functionInfo = {};
    std::optional<StructInfo> structInfo = {};
    std::optional<PointerInfo> pointerInfo = {};

};


class TypeWrapper {
    TypeDetails typeDetails = {};
    llvm::Type *Type;

    explicit TypeWrapper(llvm::Type *type) : Type(type) {

    }

public:
    const bool isNumber() {
        return typeDetails.intInfo || typeDetails.floatInfo;
    }

    const TypeDetails &getTypeDetails() const {
        return typeDetails;
    }

    static TypeWrapper GetInt(llvm::LLVMContext &TheContext, bool isSigned, size_t size) {
        auto ty = TypeWrapper(
                llvm::Type::getIntNTy(TheContext, size)
        );
        ty.typeDetails.intInfo = TypeDetails::IntInfo{
                isSigned,
                size
        };
        return std::move(ty);
    }

    static TypeWrapper GetFloat(llvm::LLVMContext &TheContext, bool isLong = true) {
        auto ty = TypeWrapper(
                llvm::Type::getDoubleTy(TheContext)
        );
        ty.typeDetails.floatInfo = TypeDetails::FloatInfo{
                64
        };
        return std::move(ty);
    }

    static TypeWrapper GetStruct(
            llvm::LLVMContext &TheContext,
            std::vector<std::pair<std::string, TypeWrapper>> &fields
    ) {
        std::vector<TypeWrapper> fieldsTypes;
        std::vector<llvm::Type *> llvmTypes;
        std::vector<std::string> fieldsNames;

        for (auto field: fields) {
            fieldsNames.push_back(field.first);
            fieldsTypes.push_back(field.second);
            llvmTypes.push_back(field.second.getType());
        }

        auto ty = TypeWrapper(llvm::StructType::get(TheContext, llvmTypes));

        ty.typeDetails.structInfo = TypeDetails::StructInfo{
                fieldsTypes,
                fieldsNames
        };

        return std::move(ty);
    }

    static TypeWrapper GetFunction(
            llvm::LLVMContext &TheContext,
            std::optional<TypeWrapper> retType,
            std::vector<TypeWrapper> arguments,
            bool isVarArg = false
    ) {
        std::vector<llvm::Type *> args = {};
        for (auto arg: arguments) {
            args.push_back(arg.getType());
        }

        llvm::FunctionType *type = llvm::FunctionType::get(
                retType ? retType->getType() : llvm::Type::getVoidTy(TheContext), args, false);

        auto ty = TypeWrapper(type);

        std::shared_ptr<TypeWrapper> retT = nullptr;
        if (retType) {
            retT = std::make_shared<TypeWrapper>(*retType);
        }

        ty.typeDetails.functionInfo = TypeDetails::FunctionInfo{
                isVarArg,
                retT,
                arguments
        };

        return std::move(ty);
    }

    llvm::Type *getType() const {
        return Type;
    }

    TypeWrapper getArrayElementType() {
        return TypeWrapper(
                Type->getArrayElementType()
        );
    }

    TypeWrapper getPointerTo() {
        return TypeWrapper(
                Type->getPointerTo()

        );
    }

    TypeWrapper getArrayOf(size_t count) {
        return TypeWrapper(
                llvm::ArrayType::get(Type, count)
        );
    }

    static std::optional<TypeWrapper> GetTypeByName(const std::string &typeName, llvm::LLVMContext &TheContext,
                                                    std::map<std::string, TypeWrapper> &typeStorage) {
        if (typeStorage.find(typeName) == typeStorage.end()) {
            return {};
        }

        return typeStorage.find(typeName)->second;
    }

    std::optional<TypeWrapper> getHigherType(llvm::LLVMContext &context, TypeWrapper right) {
        if (this->getTypeDetails().pointerInfo && this->getTypeDetails().pointerInfo) {
            return TypeWrapper::GetPointer(context,
                                           TypeWrapper::GetInt(context, false, 0)
            );
        }

        if (this->isNumber() && right.isNumber()) {

            if (this->getTypeDetails().floatInfo || right.getTypeDetails().floatInfo) {
                return TypeWrapper::GetFloat(context);
            } else {
                bool isSigned = this->getTypeDetails().intInfo->isSigned || right.getTypeDetails().intInfo->isSigned;
                auto size = std::max(
                        this->getTypeDetails().intInfo->bitSize,
                        right.getTypeDetails().intInfo->bitSize
                );
                return TypeWrapper::GetInt(context, isSigned, size);
            }

        }

        return {};
    }

    static TypeWrapper GetPointer(llvm::LLVMContext &context, std::optional<TypeWrapper> ty) {
        std::shared_ptr<TypeWrapper> tyPtr;
        if (ty) {
            tyPtr = std::make_shared<TypeWrapper>(*ty);
        }


        auto tw = TypeWrapper(llvm::Type::getInt8PtrTy(context));
        tw.typeDetails.pointerInfo = {
                tyPtr
        };

        return tw;
    }

};


class FunctionWrapper {
public:

    std::string ModuleId = "";
    std::string Name = "";

    TypeWrapper type;
    llvm::Function *Function;

    FunctionWrapper(const std::string &moduleId, const std::string &name, TypeWrapper type, llvm::Function *function)
            : ModuleId(moduleId), Name(name), type(type), Function(function) {}
};


class ValueWrapper {
    bool IsConstant = false;
    TypeWrapper Type;
    llvm::Value *Value;

    ValueWrapper(bool isConstant, TypeWrapper typeW, llvm::Value *value) : IsConstant(isConstant), Type(typeW),
                                                                           Value(value) {}

public:
    typedef std::optional<ValueWrapper> optional;
    typedef std::shared_ptr<ValueWrapper> ptr;

    static ptr Create(bool isConstant, TypeWrapper typeW, llvm::Value *value) {
        return std::make_shared<ValueWrapper>(ValueWrapper(
                isConstant, typeW, value
        ));
    }

    bool isConstant() const {
        return IsConstant;
    }

    TypeWrapper getType() const {
        return Type;
    }

    llvm::Value *getValue() const {
        return Value;
    }

    ValueWrapper::ptr toRHS(llvm::IRBuilder<> &builder) const {
        if (isConstant())
            return std::make_shared<ValueWrapper>(*this);

        llvm::Value *value = builder.CreateLoad(
                getType().getType(),
                this->getValue()
        );

        return ValueWrapper::Create(
                true,
                getType(),
                value
        );
    }

    ValueWrapper::ptr getPointerTo() const {
        if (isConstant()) {
            return nullptr;
        }

        return ValueWrapper::Create(
                true,
                getType().getPointerTo(),
                getValue()
        );

    }

    ValueWrapper::ptr castTo(llvm::IRBuilder<> &builder, TypeWrapper ty) const {
        auto RHS = toRHS(builder);

        if (RHS->getType().getTypeDetails().pointerInfo) {
            if (!ty.getTypeDetails().pointerInfo) {
                std::cerr << "Can't convert pointer to not pointer" << std::endl;
            }
            return RHS;
        }

        if (!RHS->getType().isNumber()) {
            std::cerr << "Can' cast this types" << std::endl;
            return nullptr;
        }

        if (ty.getTypeDetails().floatInfo) {
            if (RHS->getType().getTypeDetails().floatInfo) {
                return RHS;
            }
            return ValueWrapper::Create(
                    true,
                    ty,
                    builder.CreateSIToFP(RHS->getValue(), ty.getType())
            );
        } else if (ty.getTypeDetails().intInfo) {
            if (RHS->getType().getTypeDetails().floatInfo) {
                return ValueWrapper::Create(
                        true,
                        ty,
                        builder.CreateFPToSI(RHS->getValue(), ty.getType())
                );
            } else {
                // @todo: add other casts...
                return RHS;
            }
        }
        return nullptr;
    }
};

class StackController {
    std::vector<std::pair<llvm::BasicBlock *, std::map<std::string, ValueWrapper::ptr>>> Stack = {};

public:
    void PushLevel(llvm::BasicBlock *block) {
        Stack.emplace_back(block, std::map<std::string, ValueWrapper::ptr>{});
    }

    void PopLevel() {
        // @todo destruct all;

        Stack.pop_back();
    }

    bool AddNamedValue(const std::string &name, ValueWrapper::ptr value) {
        auto ValueInStack = Stack.rbegin()->second.find(name);
        if (ValueInStack != Stack.rbegin()->second.end()) {
            std::cerr << "Variable " << name << " allready defined" << std::endl;
            return false;
        }

        Stack.rbegin()->second.insert({name, value});
        return true;
    }

    ValueWrapper::ptr GetNamedValue(const std::string name) {
        for (auto block = Stack.rbegin(); block != Stack.rend(); block++) {
            if (block->second.find(name) != block->second.end()) {
                return block->second.find(name)->second;
            }
        }
        return nullptr;
    }

    llvm::BasicBlock *GetBlock() {
        if (Stack.empty()) return nullptr;

        return Stack.rbegin()->first;
    }
};

class Context {
public:

    std::shared_ptr<llvm::LLVMContext> TheContext;
    std::shared_ptr<llvm::IRBuilder<>> Builder;
    std::shared_ptr<llvm::Module> TheModule;

    StackController stackController;

    std::string ModuleName;

    std::map<std::string, FunctionWrapper> Functions;
    std::map<std::string, TypeWrapper> Types;

    [[nodiscard]] std::string GetFunctionID(const std::string &name) const {
        return this->ModuleName + '_' + name;
    }

    Context() {
        TheContext = std::make_shared<llvm::LLVMContext>();
        Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);
        TheModule = std::make_shared<llvm::Module>("main", *TheContext);

        size_t standartIntSize = 32;
        Types = std::map<std::string, TypeWrapper>{
                {"bool",    TypeWrapper::GetInt(*TheContext, false, 1)},
                {"int",     TypeWrapper::GetInt(*TheContext, true, standartIntSize)},
                {"int8",    TypeWrapper::GetInt(*TheContext, true, 8)},
                {"int16",   TypeWrapper::GetInt(*TheContext, true, 16)},
                {"int32",   TypeWrapper::GetInt(*TheContext, true, 32)},
                {"int64",   TypeWrapper::GetInt(*TheContext, true, 64)},
                {"uint",    TypeWrapper::GetInt(*TheContext, false, standartIntSize)},
                {"uint8",   TypeWrapper::GetInt(*TheContext, false, 8)},
                {"uint16",  TypeWrapper::GetInt(*TheContext, false, 16)},
                {"uint32",  TypeWrapper::GetInt(*TheContext, false, 32)},
                {"uint64",  TypeWrapper::GetInt(*TheContext, false, 64)},
                {"byte",    TypeWrapper::GetInt(*TheContext, false, 8)},
                {"float32", TypeWrapper::GetFloat(*TheContext, false)},
                {"float64", TypeWrapper::GetFloat(*TheContext, true)},
                {"rune",    TypeWrapper::GetInt(*TheContext, false, 8)},
                {"string",  TypeWrapper::GetInt(*TheContext, false, 8).getPointerTo()},
        };
    }


    std::optional<TypeWrapper> GetType(GoParser::Type_Context *typeContext) {
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
        if (typeContext->typeLit()->structType()) {
            auto structTN = typeContext->typeLit()->structType();

            std::vector<std::pair<std::string, TypeWrapper>> fields = {};

            for (auto &field: structTN->fieldDecl()) {
                // @todo support multiple
                auto fieldName = field->identifierList()->IDENTIFIER(0)->getText();
                auto fieldT = GetType(field->type_());
                if (!fieldT) {
                    std::cerr << "Can't find type of " << fieldName << ": " << field->getText() << std::endl;
                    std::cerr << typeContext->getText() << std::endl;
                    return {};
                }

                fields.push_back({
                                         fieldName,
                                         *fieldT
                                 });

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
                std::cerr << "Warning: can't find pointer declaration (use void ptr): " << typeContext->getText()
                          << std::endl;
            }

            return TypeWrapper::GetPointer(*TheContext, pointTo);

        }
        return {};
    }
};


class ParserVisitor : public GoParserBaseVisitor {

public:
    void GenereateBuildins() {
        std::vector<FunctionWrapper> functions = {
                FunctionWrapper("", "printf", TypeWrapper::GetFunction(
                                        *context->TheContext,
                                        TypeWrapper::GetInt(*context->TheContext, true, 32),
                                        std::vector<TypeWrapper>{
                                                TypeWrapper::GetInt(*context->TheContext, true, 8).getPointerTo()
                                        },
                                        true
                                ), nullptr
                ),
                FunctionWrapper("", "scanf", TypeWrapper::GetFunction(
                                        *context->TheContext,
                                        TypeWrapper::GetInt(*context->TheContext, true, 32),
                                        std::vector<TypeWrapper>{
                                                TypeWrapper::GetInt(*context->TheContext, true, 8).getPointerTo()
                                        },
                                        true
                                ), nullptr
                ),
        };


        for (auto &func: functions) {
            auto fId = context->GetFunctionID(func.Name);
            auto f = llvm::Function::Create((llvm::FunctionType *) func.type.getType(), llvm::Function::ExternalLinkage,
                                            func.Name, *context->TheModule);
            func.Function = f;
            context->Functions.insert({
                                              fId,
                                              func
                                      });
        }


    };

    antlrcpp::Any visitSourceFile(GoParser::SourceFileContext *ctx) override {
        this->context->ModuleName = ctx->packageClause()->IDENTIFIER()->getText();


        GenereateBuildins();

        for (auto importDecl: ctx->importDecl()) {
            // @todo: implement imports
        }

        for (auto decl: ctx->declaration()) {
            if (!decl->typeDecl()) {
                std::cerr << "This is not supported: " << decl->getText();
                continue;
            }

            if (decl->typeDecl()->typeSpec(0)->aliasDecl()) {
                std::cerr << "Aliases is not supported: " << decl->getText();
                continue;
            }
            auto def = decl->typeDecl()->typeSpec(0)->typeDef();

            auto defName = def->IDENTIFIER()->getText();
            auto type = context->GetType(def->type_());

            if (!type) {
                std::cerr << "Can't declare type " << defName << std::endl;
                continue;
            }

            context->Types.insert({
                                          defName,
                                          *type
                                  });


        }

        for (auto funcDecl: ctx->functionDecl()) {
            this->visitFunctionDecl(funcDecl);
        }

        return 0;
    }

    antlrcpp::Any visitFunctionDecl(GoParser::FunctionDeclContext *ctx) override {
        std::vector<TypeWrapper> args;
        std::optional<TypeWrapper> retT = {};

        for (auto arg: ctx->signature()->parameters()->parameterDecl()) {
            auto type = context->GetType(arg->type_());
            if (!type) {
                std::cerr << "Can't find type : " << ctx->getText() << std::endl;
                return nullptr;
            }
            for (auto argN: arg->identifierList()->IDENTIFIER()) {
                args.push_back(*type);
            }
        }


        if (ctx->signature()->result()) {
            auto goType = ctx->signature()->result()->type_();
            if (!goType) {
                std::cerr << "Not supported multiple return: " << ctx->signature()->getText() << std::endl;
                return nullptr;
            }
            auto type = context->GetType(goType);
            if (!type) {
                std::cerr << "Can't find type : " << ctx->getText() << std::endl;
                return nullptr;
            }
            retT = *type;
        }

        auto nameCode = ctx->IDENTIFIER()->getText();
        auto name = context->GetFunctionID(nameCode);

        auto funcT = TypeWrapper::GetFunction(*context->TheContext, retT, args);
        auto func = llvm::Function::Create((llvm::FunctionType *) funcT.getType(), llvm::Function::ExternalLinkage,
                                           name, *context->TheModule);

        auto BB = llvm::BasicBlock::Create(*context->TheContext, "entry", func);
        context->Builder->SetInsertPoint(BB);

        auto funcWrap = FunctionWrapper(
                context->ModuleName,
                nameCode,
                funcT,
                func
        );
        context->Functions.insert({
                                          name,
                                          funcWrap
                                  });

        context->stackController.PushLevel(BB);

        {
            int i = 0;
            for (auto arg: ctx->signature()->parameters()->parameterDecl()) {
                auto ty = context->GetType(arg->type_());
                for (auto argN: arg->identifierList()->IDENTIFIER()) {
                    auto llvmArg = func->getArg(i);
                    i++;

                    auto var = context->Builder->CreateAlloca(ty->getType());

                    context->Builder->CreateStore(llvmArg, var);

                    context->stackController.AddNamedValue(
                            argN->getText(),
                            ValueWrapper::Create(
                                    false,
                                    *ty,
                                    (llvm::Value *) var
                            ));
                }
            }
        }

        if (!ctx->block() || !ctx->block()->statementList() ) {
            std::cerr << "Can't create function " << nameCode << std::endl;
            return nullptr;
        }

        for (auto statement: ctx->block()->statementList()->statement()) {
            statement->accept(this);
        }

        context->stackController.PopLevel();

        if (!retT) context->Builder->CreateRetVoid();

        llvm::verifyFunction(*func);

        return 0;
    }


    std::shared_ptr<Context> context;

    explicit ParserVisitor() {
        context = std::make_shared<Context>();
    }


    antlrcpp::Any visitStatement(GoParser::StatementContext *ctx) override {
        return GoParserBaseVisitor::visitStatement(ctx);
    }


    antlrcpp::Any visitInteger(GoParser::IntegerContext *ctx) override {
        int value = 0;
        TypeWrapper type = TypeWrapper::GetInt(*context->TheContext, true, 32);

        if (ctx->RUNE_LIT()) {
            value = toascii(ctx->RUNE_LIT()->getText()[1]);
        } else if (ctx->DECIMAL_LIT()) {
            value = atoi(ctx->getText().c_str());
        }

        llvm::Value *retv = llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, value));

        return ValueWrapper::Create(true, type, retv);
    }

    antlrcpp::Any visitBasicLit(GoParser::BasicLitContext *ctx) override {
        if (ctx->FLOAT_LIT()) {
            auto string = ctx->FLOAT_LIT()->getText();
            auto num = std::stod(string);

            auto ty = TypeWrapper::GetFloat(*context->TheContext);
            return ValueWrapper::Create(
                    true,
                    ty,
                    llvm::ConstantFP::get(ty.getType(), llvm::APFloat(num))
            );
        }
        if (ctx->NIL_LIT()) {
            auto ty = TypeWrapper::GetPointer(*context->TheContext, {});
            return ValueWrapper::Create(
                    true,
                    ty,
                    llvm::ConstantPointerNull::get((llvm::PointerType *) ty.getType())
            );
        }
        return GoParserBaseVisitor::visitBasicLit(ctx);
    }

    antlrcpp::Any visitString_(GoParser::String_Context *ctx) override {
        auto data = ctx->INTERPRETED_STRING_LIT()->getText();
        // @todo: add normal deserelisation
        boost::replace_all(data, "\\\\", "<SUPEREQ>");

        boost::replace_all(data, "\\n", "\n");
        boost::replace_all(data, "\\t", "\t");
        boost::replace_all(data, "\\r", "\r");

        boost::replace_all(data, "<SUPEREQ>", "\\");

        data.pop_back();

        auto str = llvm::ConstantDataArray::getString(*context->TheContext, data.c_str() + 1, true);
        auto at = llvm::ArrayType::get(llvm::Type::getInt8Ty(*context->TheContext), data.size());

        // @todo: alloca from jopa
        llvm::IRBuilder<> TmpB(context->stackController.GetBlock(), context->stackController.GetBlock()->begin());
        auto llvmVar = TmpB.CreateAlloca(at);

        context->Builder->CreateStore(str, llvmVar);

        TypeWrapper ty = TypeWrapper::GetInt(*context->TheContext, false, 8).getPointerTo();

        return ValueWrapper::Create(true, ty, llvmVar);
    }

    antlrcpp::Any visitConstDecl(GoParser::ConstDeclContext *ctx) override {
        // @todo support multiple declaration
        // @todo: compute type
        auto typeNode = ctx->constSpec()[0]->type_();
        auto llvmType = context->GetType(typeNode);
        if (!llvmType) {
            std::cerr << "Can't find type : " << ctx->getText() << std::endl;
            return nullptr;
        }

        ValueWrapper::ptr expr = ctx->constSpec(0)->expressionList()->expression(0)->accept(this);
        expr = expr->toRHS(*context->Builder);

        context->stackController.AddNamedValue(
                ctx->constSpec(0)->identifierList()->IDENTIFIER(0)->getText(),
                expr
        );

        return nullptr;
    }

    antlrcpp::Any visitReturnStmt(GoParser::ReturnStmtContext *ctx) override {
        if (ctx->expressionList()->expression().empty()) {
            context->Builder->CreateRetVoid();
            return nullptr;
        }
        if (ctx->expressionList()->expression().size() > 1) {
            std::cerr << "Multiple return is not supported: " << ctx->getText() << std::endl;
            return nullptr;
        }

        ValueWrapper::ptr expression = ctx->expressionList()->expression(0)->accept(this);
        expression = expression->toRHS(*context->Builder);

        context->Builder->CreateRet(expression->getValue());

        return nullptr;
    }


    antlrcpp::Any visitVarDecl(GoParser::VarDeclContext *ctx) override {
        // @todo support multiple declaration
        auto typeNode = ctx->varSpec()[0]->type_();
        auto ty = context->GetType(typeNode);
        if (!ty) {
            std::cerr << "Can't find type : " << ctx->getText() << std::endl;
            return nullptr;
        }

        std::string name = ctx->varSpec()[0]->identifierList()->IDENTIFIER(0)->getText();

        llvm::IRBuilder<> TmpB(context->stackController.GetBlock(), context->stackController.GetBlock()->begin());


        auto llvmVar = TmpB.CreateAlloca(ty->getType());
        llvmVar->setName(name);


        context->stackController.AddNamedValue(
                ctx->varSpec(0)->identifierList()->IDENTIFIER(0)->getText(),
                ValueWrapper::Create(
                        false,
                        *ty,
                        llvmVar
                )
        );

        if (!ctx->varSpec(0)->expressionList()) {
            return nullptr;
        }

        ValueWrapper::ptr expr = ctx->varSpec(0)->expressionList()->expression(0)->accept(this);
        expr = expr->toRHS(*context->Builder);

        context->Builder->CreateStore(expr->getValue(), llvmVar);

        return nullptr;
    }



    antlrcpp::Any visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) override {
        if (ctx->arguments()) {
            auto function_name = ctx->primaryExpr()->operand()->operandName()->IDENTIFIER()->getText();


            auto Type2Cast = TypeWrapper::GetTypeByName(function_name, *context->TheContext, context->Types);
            if (Type2Cast) {
                if (ctx->arguments()->expressionList()->expression().size() != 1) {
                    std::cerr << "can't cast more than one value " << function_name << " : " << ctx->getText()
                              << std::endl;
                    return nullptr;
                }

                ValueWrapper::ptr RHS = ctx->arguments()->expressionList()->expression(0)->accept(this);
                return RHS->castTo(*context->Builder, *Type2Cast);
            }


            auto func = context->Functions.find(context->GetFunctionID(function_name));

            if (func == context->Functions.end()) {
                std::cerr << "not found function " << function_name << " : " << ctx->getText() << std::endl;
                return nullptr;
            }

            std::vector<llvm::Value *> ArgsV;

            for (auto expr: ctx->arguments()->expressionList()->expression()) {
                ValueWrapper::ptr value = expr->accept(this);

                // @todo make cast
                ArgsV.emplace_back(value->toRHS(*context->Builder)->getValue());
            }

            llvm::Value *value = context->Builder->CreateCall(func->second.Function, ArgsV);


            auto retType = func->second.type.getTypeDetails().functionInfo->retType;

            if (!retType) {
                return nullptr;
            }

            return ValueWrapper::Create(
                    true,
                    *retType,
                    value
            );

        }

        if (ctx->index()) {
            ValueWrapper::ptr left = ctx->primaryExpr()->accept(this);

            ValueWrapper::ptr indexV = ctx->index()->expression()->accept(this);

            std::vector<llvm::Value *> indexes = {
                    llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, 0)),
                    indexV->toRHS(*context->Builder)->getValue()
            };

            auto valptr = context->Builder->CreateGEP(left->getType().getType(), left->getValue(), indexes);


            return ValueWrapper::Create(false,
                                        left->getType().getArrayElementType(),
                                        valptr
            );
        }

        if (ctx->DOT()) {
            ValueWrapper::ptr left = ctx->primaryExpr()->accept(this);

            auto structInfo = left->getType().getTypeDetails().structInfo;
            if (!structInfo) {
                std::cerr << "Dot operation supports only for structs: " << ctx->getText() << std::endl;
                return nullptr;
            }

            auto fieldName = ctx->IDENTIFIER()->getText();
            size_t fieldI = 0;
            std::optional<TypeWrapper> fieldType;

            for (auto f: structInfo->fieldNames) {
                if (f == fieldName) {
                    fieldType = structInfo->fields[fieldI];
                    break;
                }
                fieldI++;
            }

            if (!fieldType) {
                std::cerr << "Can't find struct field " << fieldName << ": " << ctx->getText();
                return nullptr;

            }




            context->TheModule->print(llvm::errs(), nullptr);
            left->getType().getType()->print(llvm::errs());
            left->getValue()->print(llvm::errs());

            if (left->isConstant()) {
                auto valptr = context->Builder->CreateExtractElement(left->getValue(), fieldI, "");


                return ValueWrapper::Create(true,
                                            *fieldType,
                                            valptr);

            }
            std::vector<llvm::Value *> indexes = {
                    llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, 0)),
                    llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, fieldI))
            };
            auto valptr = context->Builder->CreateGEP(left->getType().getType(), left->getValue(), indexes);


            return ValueWrapper::Create(false,
                                        *fieldType,
                                        valptr);

        }

        return GoParserBaseVisitor::visitPrimaryExpr(ctx);
    }


    antlrcpp::Any visitOperand(GoParser::OperandContext *ctx) override {
        if (ctx->operandName()) {
            return ctx->operandName()->accept(this);
        } else if (ctx->expression()) {
            return ctx->expression()->accept(this);
        } else if (ctx->literal()) {
            return ctx->literal()->accept(this);
        }
        return nullptr;
    }

    antlrcpp::Any visitOperandName(GoParser::OperandNameContext *ctx) override {
        auto varName = ctx->IDENTIFIER()->getText();

        auto value = context->stackController.GetNamedValue(varName);

        if (!value) {
            std::cerr << "Not found var name " << varName << " : " << ctx->getText() << std::endl;
            return nullptr;
        }

        return value;
    }

    antlrcpp::Any visitAssignment(GoParser::AssignmentContext *ctx) override {
        auto varNode = ctx->expressionList(0)->expression(0);

        ValueWrapper::ptr lexpr = varNode->accept(this);

        ValueWrapper::ptr expr = ctx->expressionList(1)->accept(this);


        context->Builder->CreateStore(expr->toRHS(*context->Builder)->getValue(), lexpr->getValue());

        return nullptr;
    }

    antlrcpp::Any visitExpression(GoParser::ExpressionContext *ctx) override {
        if (ctx->add_op || ctx->rel_op || ctx->mul_op) {
            ValueWrapper::ptr L = ctx->expression(0)->accept(this);
            ValueWrapper::ptr R = ctx->expression(1)->accept(this);

            L = L->toRHS(*context->Builder);
            R = R->toRHS(*context->Builder);

            auto ComputedType = L->getType().getHigherType(*context->TheContext, R->getType());
            if (!ComputedType) {
                std::cerr << "Can't compute type of result operation (may be it's not a numbers...): " << ctx->getText()
                          << std::endl;
                return nullptr;
            }


            llvm::Value *res = nullptr;
            auto type = *ComputedType;

            L = L->castTo(*context->Builder, type);
            R = R->castTo(*context->Builder, type);


            if (ctx->PLUS()) {
                if (type.getTypeDetails().intInfo) {
                    res = context->Builder->CreateAdd(L->getValue(), R->getValue());
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFAdd(L->getValue(), R->getValue());
                }
            } else if (ctx->MINUS()) {
                if (type.getTypeDetails().intInfo) {
                    res = context->Builder->CreateSub(L->getValue(), R->getValue());
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFSub(L->getValue(), R->getValue());
                }
            } else if (ctx->GREATER()) {
                if (type.getTypeDetails().intInfo) {
                    if (type.getTypeDetails().intInfo->isSigned) {
                        res = context->Builder->CreateICmpSGT(L->getValue(), R->getValue());
                    } else {
                        res = context->Builder->CreateICmpUGE(L->getValue(), R->getValue());
                    }
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFCmpOGE(L->getValue(), R->getValue());
                }
                type = TypeWrapper::GetInt(*context->TheContext, false, 1);
            } else if (ctx->LESS()) {
                if (type.getTypeDetails().intInfo) {
                    if (type.getTypeDetails().intInfo->isSigned) {
                        res = context->Builder->CreateICmpSLT(L->getValue(), R->getValue());
                    } else {
                        res = context->Builder->CreateICmpULE(L->getValue(), R->getValue());
                    }
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFCmpOLE(L->getValue(), R->getValue());
                }
                type = TypeWrapper::GetInt(*context->TheContext, false, 1);
            } else if (ctx->EQUALS()) {
                if (type.getTypeDetails().intInfo) {
                    res = context->Builder->CreateICmpEQ(L->getValue(), R->getValue());
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFCmpOEQ(L->getValue(), R->getValue());
                }
                type = TypeWrapper::GetInt(*context->TheContext, false, 1);
            } else if (ctx->NOT_EQUALS()) {
                if (type.getTypeDetails().intInfo || type.getTypeDetails().pointerInfo) {
                    res = context->Builder->CreateICmpNE(L->getValue(), R->getValue());
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFCmpONE(L->getValue(), R->getValue());
                }
                type = TypeWrapper::GetInt(*context->TheContext, false, 1);
            } else if (ctx->STAR()) {
                res = context->Builder->CreateMul(L->getValue(), R->getValue());
            } else if (ctx->DIV()) {
                if (type.getTypeDetails().intInfo) {
                    if (type.getTypeDetails().intInfo->isSigned) {
                        res = context->Builder->CreateSDiv(L->getValue(), R->getValue());
                    } else {
                        res = context->Builder->CreateUDiv(L->getValue(), R->getValue());
                    }
                } else if (type.getTypeDetails().floatInfo) {
                    res = context->Builder->CreateFDiv(L->getValue(), R->getValue());
                }
            } else if (ctx->MOD()) {
                if (!type.getTypeDetails().intInfo) {
                    std::cerr << "Mod operation works only with integers: " << ctx->getText() << std::endl;
                    return nullptr;
                }
                res = context->Builder->CreateSRem(L->getValue(), R->getValue());
            }
            // @todo add other ops

            if (!res) {
                std::cerr << "This operation is not supported: " << ctx->getText() << std::endl;
                return nullptr;
            }

            return ValueWrapper::Create(
                    true,
                    type,
                    res
            );

        } else if (ctx->unary_op) {
            if (ctx->AMPERSAND()) {
                ValueWrapper::ptr child = ctx->expression(0)->accept(this);

                auto value = child->getPointerTo();
                if (!value) {
                    std::cerr << "Can't get address of: " << ctx->getText() << std::endl;
                    return nullptr;
                }

                return value;
            }
            if (ctx->STAR()) {
                ValueWrapper::ptr child = ctx->expression(0)->accept(this);

                if (!child->getType().getTypeDetails().pointerInfo) {
                    std::cerr << "Can dereference only a pointer: " << ctx->getText() << std::endl;
                    return nullptr;
                }
                if (!child->getType().getTypeDetails().pointerInfo->type) {
                    std::cerr << "Can dereference only a non-void pointer : " << ctx->getText() << std::endl;
                    return nullptr;
                }

                child = child->toRHS(*context->Builder);

//                llvm::Value *value = context->Builder->CreateLoad(
//                        child->getType().getTypeDetails().pointerInfo->type->getType(),
//                        child->getValue()
//                );

                return ValueWrapper::Create(
                        false, *child->getType().getTypeDetails().pointerInfo->type, child->getValue());
            }
        }

        return GoParserBaseVisitor::visitExpression(ctx);
    }

    antlrcpp::Any visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) override {
        std::string name = ctx->identifierList()->IDENTIFIER(0)->getText();

        ValueWrapper::ptr expr = ctx->expressionList()->expression(0)->accept(this);
        expr = expr->toRHS(*context->Builder);


        llvm::IRBuilder<> TmpB(context->stackController.GetBlock(), context->stackController.GetBlock()->begin());
        auto llvmVar = TmpB.CreateAlloca(expr->getType().getType());
        context->Builder->CreateStore(expr->getValue(), llvmVar);

        llvmVar->setName(name);

        context->stackController.AddNamedValue(
                name, ValueWrapper::Create(
                        false,
                        expr->getType(),
                        llvmVar
                )
        );

        return nullptr;
    }

    antlrcpp::Any visitIfStmt(GoParser::IfStmtContext *ctx) override {
        ValueWrapper::ptr CondV = ctx->expression()->accept(this);
        CondV = CondV->toRHS(*context->Builder);

        auto parent = context->stackController.GetBlock()->getParent();

        auto ThenBB = llvm::BasicBlock::Create(*context->TheContext, "if", parent);
        auto ElseBB = llvm::BasicBlock::Create(*context->TheContext, "else");
        auto MergeBB = llvm::BasicBlock::Create(*context->TheContext, "after-if");

        context->Builder->CreateCondBr(CondV->getValue(), ThenBB, ElseBB);
        context->Builder->SetInsertPoint(ThenBB);

        context->stackController.PushLevel(context->stackController.GetBlock());
        ctx->block(0)->statementList()->accept(this);
        context->Builder->CreateBr(MergeBB);

        parent->insert(parent->end(), ElseBB);
        context->Builder->SetInsertPoint(ElseBB);

        context->stackController.PopLevel();

        if (ctx->ELSE()) {
            context->stackController.PushLevel(context->stackController.GetBlock());
            if (ctx->ifStmt()) {
                ctx->ifStmt()->accept(this);
            } else {
                ctx->block(1)->accept(this);
            }
            context->stackController.PopLevel();
        }
        context->Builder->CreateBr(MergeBB);

        parent->insert(parent->end(), MergeBB);
        context->Builder->SetInsertPoint(MergeBB);

        return nullptr;
    }

    antlrcpp::Any visitForStmt(GoParser::ForStmtContext *ctx) override {
        llvm::Function *TheFunction = context->Builder->GetInsertBlock()->getParent();

        context->stackController.PushLevel(
                context->stackController.GetBlock()
        );

        ctx->forClause()->children[0]->accept(this);

        ValueWrapper::ptr StartCond = ctx->forClause()->children[2]->accept(this);
        StartCond = StartCond->toRHS(*context->Builder);

        auto LoopBB = llvm::BasicBlock::Create(*context->TheContext, "loop", TheFunction);
        auto AfterBB = llvm::BasicBlock::Create(*context->TheContext, "afterloop", TheFunction);

        context->Builder->CreateCondBr(StartCond->getValue(), LoopBB, AfterBB);


        context->Builder->SetInsertPoint(LoopBB);


        ctx->block()->statementList()->accept(this);

        ctx->forClause()->children[4]->accept(this);


        ValueWrapper::ptr EndCond = ctx->forClause()->children[2]->accept(this);
        EndCond = EndCond->toRHS(*context->Builder);

        context->Builder->CreateCondBr(EndCond->getValue(), LoopBB, AfterBB);

        context->stackController.PopLevel();

        context->Builder->SetInsertPoint(AfterBB);

        return nullptr;
    }
};

#endif //APP_PARSERVISITOR_H
