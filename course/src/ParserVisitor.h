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

    std::optional<IntInfo> intInfo = {};
    std::optional<FloatInfo> floatInfo = {};
    std::optional<FunctionInfo> functionInfo = {};


};


class TypeWrapper {
    TypeDetails typeDetails = {};
    llvm::Type *Type;

    explicit TypeWrapper(llvm::Type *type) : Type(type) {

    }

public:
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

    static std::optional<TypeWrapper> GetTypeByName(const std::string &typeName, llvm::LLVMContext &TheContext) {
        size_t standartIntSize = 32;

        static auto typeMap = std::map<std::string, TypeWrapper>{
                {"bool",    TypeWrapper::GetInt(TheContext, false, 1)},
                {"int",     TypeWrapper::GetInt(TheContext, true, standartIntSize)},
                {"int8",    TypeWrapper::GetInt(TheContext, true, 8)},
                {"int16",   TypeWrapper::GetInt(TheContext, true, 16)},
                {"int32",   TypeWrapper::GetInt(TheContext, true, 32)},
                {"int64",   TypeWrapper::GetInt(TheContext, true, 64)},
                {"uint",    TypeWrapper::GetInt(TheContext, false, standartIntSize)},
                {"uint8",   TypeWrapper::GetInt(TheContext, false, 8)},
                {"uint16",  TypeWrapper::GetInt(TheContext, false, 16)},
                {"uint32",  TypeWrapper::GetInt(TheContext, false, 32)},
                {"uint64",  TypeWrapper::GetInt(TheContext, false, 64)},
                {"byte",    TypeWrapper::GetInt(TheContext, false, 8)},
                {"float32", TypeWrapper::GetFloat(TheContext, false)},
                {"float64", TypeWrapper::GetFloat(TheContext, true)},
                {"rune",    TypeWrapper::GetInt(TheContext, false, 8)},
                {"string",  TypeWrapper::GetInt(TheContext, false, 8).getPointerTo()},
        };

        if (typeMap.find(typeName) == typeMap.end()) {
            std::cerr << typeName << " is not supported" << std::endl;
            return {};
        }

        return typeMap.find(typeName)->second;
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

    [[nodiscard]] std::string GetFunctionID(const std::string &name) const {
        return this->ModuleName + '_' + name;
    }

    Context() {
        TheContext = std::make_shared<llvm::LLVMContext>();
        Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);
        TheModule = std::make_shared<llvm::Module>("main", *TheContext);
    }

    std::optional<TypeWrapper> GetType(GoParser::Type_Context *typeContext) {
        if (typeContext->typeName()) {
            auto typeName = typeContext->typeName()->getText();
            return TypeWrapper::GetTypeByName(typeName, *TheContext);
        }
        if (typeContext->type_()) {
            return GetType(typeContext->type_());
        }

        if (!typeContext->typeLit()) {
            std::cerr << "Smth go wrong :" << typeContext->getText() << std::endl;
            return {};
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
        std::string typeName = "int";

        if (ctx->RUNE_LIT()) {
            value = toascii(ctx->RUNE_LIT()->getText()[1]);
        } else if (ctx->DECIMAL_LIT()) {
            value = atoi(ctx->getText().c_str());
        }

        auto ty = TypeWrapper::GetTypeByName(typeName, *context->TheContext);

        llvm::Value *retv = llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, value));

        return ValueWrapper::Create(true, *ty, retv);
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

        auto ty = TypeWrapper::GetTypeByName("string", *context->TheContext);

        return ValueWrapper::Create(true, *ty, llvmVar);
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
                    *retType ,
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

        return GoParserBaseVisitor::visitPrimaryExpr(ctx);
    }

//    antlrcpp::Any visitChildren(antlr4::tree::ParseTree *node) override {
//        return (*node->children.rbegin())->accept(this);
//    }

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

            llvm::Value *res = nullptr;
            auto type = L->getType();
            if (ctx->PLUS()) {
                res = context->Builder->CreateAdd(L->getValue(), R->getValue());
            } else if (ctx->MINUS()) {
                res = context->Builder->CreateSub(L->getValue(), R->getValue());
            } else if (ctx->GREATER()) {
                res = context->Builder->CreateICmpSGT(L->getValue(), R->getValue());
                type = *TypeWrapper::GetTypeByName("bool", *context->TheContext);
            } else if (ctx->LESS()) {
                res = context->Builder->CreateICmpSLT(L->getValue(), R->getValue());
                type = *TypeWrapper::GetTypeByName("bool", *context->TheContext);
            } else if (ctx->EQUALS()) {
                res = context->Builder->CreateICmpEQ(L->getValue(), R->getValue());
                type = *TypeWrapper::GetTypeByName("bool", *context->TheContext);
            } else if (ctx->NOT_EQUALS()) {
                res = context->Builder->CreateICmpNE(L->getValue(), R->getValue());
                type = *TypeWrapper::GetTypeByName("bool", *context->TheContext);
            } else if (ctx->STAR()) {
                res = context->Builder->CreateMul(L->getValue(), R->getValue());
            } else if (ctx->DIV()) {
                res = context->Builder->CreateSDiv(L->getValue(), R->getValue());
            } else if (ctx->MOD()) {
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

        } else if (ctx->AMPERSAND()) {
            ValueWrapper::ptr child = ctx->expression(0)->accept(this);

            auto value = child->getPointerTo();
            if (!value) {
                std::cerr << "Can't get address of constant" << ctx->getText() << std::endl;
                return nullptr;
            }

            return value;
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
