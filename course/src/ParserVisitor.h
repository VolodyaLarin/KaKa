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

class Context {
public:

    std::shared_ptr<llvm::LLVMContext> TheContext;
    std::shared_ptr<llvm::IRBuilder<>> Builder;
    std::shared_ptr<llvm::Module> TheModule;

    std::string ModuleName;

    std::vector<std::pair<llvm::BasicBlock *, std::map<std::string, std::pair<llvm::Type *, llvm::Value *>>>> Stack = {};


    std::map<std::string, llvm::Function *> Functions;

    [[nodiscard]] std::string GetFunctionID(const std::string &name) const {
        return this->ModuleName + '_' + name;
    }

    Context() {
        TheContext = std::make_shared<llvm::LLVMContext>();
        Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);
        TheModule = std::make_shared<llvm::Module>("main", *TheContext);
    }

    llvm::Type *GetType(GoParser::Type_Context *typeContext) {
        if (typeContext->typeName()) {
            auto typeName = typeContext->typeName()->getText();
            return getType(typeName);
        }
        if (typeContext->type_()) {
            return GetType(typeContext->type_());
        }

        if (!typeContext->typeLit()) {
            std::cerr << "Smth go wrong :" << typeContext->getText() << std::endl;
            return nullptr;
        }

        if (typeContext->typeLit()->arrayType()) {
            auto child = typeContext->typeLit()->arrayType()->elementType()->type_();
            auto childType = GetType(child);
            if (!childType) {
                return nullptr;
            }
            auto countText = typeContext->typeLit()->arrayType()->arrayLength()->getText();
            auto count = atoi(countText.c_str());

            if (count <= 0) {
                std::cerr << "Can't create array with length " << count << ": " << typeContext->getText();
                return nullptr;
            }

            auto at = llvm::ArrayType::get(childType, count);

            return at;
        }
    }

    llvm::Type *getType(const std::string &typeName) {
        auto typeMap = std::map<std::string, llvm::Type *>{{"int",   llvm::Type::getInt32Ty(*TheContext)},
                                                           {"float", llvm::Type::getFloatTy(*TheContext)},
                                                           {"rune",  llvm::Type::getInt32Ty(*TheContext)}};

        if (typeMap.find(typeName) == typeMap.end()) {
            std::cerr << typeName << " is not supported" << std::endl;
            return nullptr;
        }

        return typeMap[typeName];
    }

    int AMPSERSAND_level = 0;

    std::optional<std::pair<llvm::Type *, llvm::Value *>> FindVarible(const std::string &varName) {
        for (auto block = Stack.rbegin(); block != Stack.rend(); block++) {
            if (block->second.find(varName) != block->second.end()) {
                return block->second[varName];
            }
        }
        return {};
    }

};


class ParserVisitor : public GoParserBaseVisitor {

public:
    void GenereateBuildins() {
        std::vector<std::pair<std::string, std::pair<llvm::Type *, std::vector<llvm::Type *>>>> functions =
                {{"printf", {
                                    llvm::Type::getInt32Ty(*context->TheContext),
                                    {llvm::Type::getInt8PtrTy(
                                            *context->TheContext)}}},
                 {"scanf",  {
                                    llvm::Type::getInt32Ty(*context->TheContext),
                                    {llvm::Type::getInt8PtrTy(
                                            *context->TheContext)}}},
                };

        for (const auto &func: functions) {
            auto args = func.second.second;
            auto name = func.first;
            auto rt = func.second.first;


            auto fId = context->GetFunctionID(name);
            llvm::FunctionType *type = llvm::FunctionType::get(rt, args, false);

            auto f = llvm::Function::Create(type, llvm::Function::ExternalLinkage, name, *context->TheModule);
            context->Functions[fId] = f;

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
        std::vector<llvm::Type *> args;

        for (auto arg: ctx->signature()->parameters()->parameterDecl()) {
            auto llvmType = context->getType(arg->type_()->getText());
            if (!llvmType) {
                std::cerr << "Can't find type : " << ctx->getText() << std::endl;
                return nullptr;
            }
            for (auto argN: arg->identifierList()->IDENTIFIER()) {
                args.emplace_back(llvmType);
            }
        }


        llvm::FunctionType *type = llvm::FunctionType::get(llvm::Type::getVoidTy(*context->TheContext), args, false);


        auto name = context->GetFunctionID(ctx->IDENTIFIER()->getText());

        auto func = llvm::Function::Create(type, llvm::Function::ExternalLinkage, name, *context->TheModule);

        auto BB = llvm::BasicBlock::Create(*context->TheContext, "entry", func);
        context->Builder->SetInsertPoint(BB);


        context->Functions[name] = func;


        context->Stack.emplace_back(BB, std::map<std::string, std::pair<llvm::Type *, llvm::Value *>>());


        {
            int i = 0;
            for (auto arg: ctx->signature()->parameters()->parameterDecl()) {
                auto llvmType = context->getType(arg->type_()->getText());
                for (auto argN: arg->identifierList()->IDENTIFIER()) {
                    auto llvmArg = func->getArg(i);
                    i++;
                    std::cout << "ADD ARG " << argN->getText() << " to stack" << std::endl;

                    auto var = context->Builder->CreateAlloca(llvmType);

                    context->Builder->CreateStore(llvmArg, var);


                    context->Stack.rbegin()->second[argN->getText()] = std::make_pair((llvm::Type *) llvmType,
                                                                                      (llvm::Value *) var);
                }
            }
        }


        for (auto statement: ctx->block()->statementList()->statement()) {
            statement->accept(this);
        }

        context->Builder->CreateRetVoid();

        llvm::verifyFunction(*func);

        context->Stack.pop_back();

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
        if (ctx->RUNE_LIT()) {
            value = toascii(ctx->RUNE_LIT()->getText()[1]);
        } else if (ctx->DECIMAL_LIT()) {
            value = atoi(ctx->getText().c_str());
        }
        // @todo: support other types

        llvm::Value *retv = llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, value));


        return retv;
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
        llvm::IRBuilder<> TmpB(context->Stack.rbegin()->first, context->Stack.rbegin()->first->begin());


        auto llvmVar = TmpB.CreateAlloca(at);


        context->Builder->CreateStore(str, llvmVar);


        return (llvm::Value *) llvmVar;
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

        std::string name = ctx->constSpec()[0]->identifierList()->IDENTIFIER(0)->getText();
        llvm::IRBuilder<> TmpB(context->Stack.rbegin()->first, context->Stack.rbegin()->first->begin());

        auto llvmVar = TmpB.CreateAlloca(llvmType);
        llvmVar->setName(name);


        context->Stack.rbegin()->second[ctx->constSpec(0)->identifierList()->IDENTIFIER(0)->getText()] = std::make_pair(
                llvmType, llvmVar);


        llvm::Value *expr = ctx->constSpec(0)->expressionList()->expression(0)->accept(this);

        context->Builder->CreateStore(expr, llvmVar);

        return nullptr;
    }


    antlrcpp::Any visitVarDecl(GoParser::VarDeclContext *ctx) override {
        // @todo support multiple declaration
        auto typeNode = ctx->varSpec()[0]->type_();
        auto llvmType = context->GetType(typeNode);
        if (!llvmType) {
            std::cerr << "Can't find type : " << ctx->getText() << std::endl;
            return nullptr;
        }

        std::string name = ctx->varSpec()[0]->identifierList()->IDENTIFIER(0)->getText();

        llvm::IRBuilder<> TmpB(context->Stack.rbegin()->first, context->Stack.rbegin()->first->begin());


        auto llvmVar = TmpB.CreateAlloca(llvmType);
        llvmVar->setName(name);


        context->Stack.rbegin()->second[ctx->varSpec(0)->identifierList()->IDENTIFIER(0)->getText()] = std::make_pair(
                llvmType, llvmVar);

        if (!ctx->varSpec(0)->expressionList()) {
            return nullptr;
        }

        llvm::Value *expr = ctx->varSpec(0)->expressionList()->expression(0)->accept(this);

        context->Builder->CreateStore(expr, llvmVar);

        return nullptr;
    }


    antlrcpp::Any visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) override {
        if (ctx->arguments()) {
            auto function_name = ctx->primaryExpr()->operand()->operandName()->IDENTIFIER()->getText();

            auto func = context->Functions[context->GetFunctionID(function_name)];

            if (!func) {
                std::cerr << "not found function " << function_name << " : " << ctx->getText() << std::endl;
                return nullptr;
            }

            std::vector<llvm::Value *> ArgsV;

            for (auto expr: ctx->arguments()->expressionList()->expression()) {
                std::cout << expr->getText() << std::endl;
                llvm::Value *value = expr->accept(this);
                ArgsV.emplace_back(value);
            }

            return context->Builder->CreateCall(func, ArgsV);
        }

        if (ctx->index()) {
            context->AMPSERSAND_level++;

            llvm::Value *left = ctx->primaryExpr()->accept(this);
            auto old_level = context->AMPSERSAND_level;
            context->AMPSERSAND_level = 0;
            llvm::Value *indexV = ctx->index()->expression()->accept(this);
            context->AMPSERSAND_level = old_level;

            std::vector<llvm::Value *> indexes = {
                    llvm::ConstantInt::get(*context->TheContext, llvm::APInt(32, 0)), indexV
            };

            llvm::AllocaInst *aa = static_cast<llvm::AllocaInst *>(left);

            context->TheModule->print(llvm::errs(), nullptr);

            auto valptr = context->Builder->CreateGEP(aa->getAllocatedType(), left, indexes);
            if (context->AMPSERSAND_level) {
                context->AMPSERSAND_level--;
                return valptr;
            }

            return (llvm::Value *) context->Builder->CreateLoad(aa->getAllocatedType()->getArrayElementType(), valptr);

            return (llvm::Value *) llvm::ExtractElementInst::Create(left, indexV);
        }

        return GoParserBaseVisitor::visitPrimaryExpr(ctx);
    }


    antlrcpp::Any visitOperandName(GoParser::OperandNameContext *ctx) override {

        auto varName = ctx->IDENTIFIER()->getText();

        auto value = context->FindVarible(varName);

        if (!value) {
            std::cerr << "Not found var name " << varName << " : " << ctx->getText() << std::endl;
            return nullptr;
        }

        auto var = *value;

        if (context->AMPSERSAND_level) {
            context->AMPSERSAND_level--;
            return (llvm::Value *) var.second;
        }

        return (llvm::Value *) context->Builder->CreateLoad(var.first, var.second);
    }

    antlrcpp::Any visitAssignment(GoParser::AssignmentContext *ctx) override {
        auto varNode = ctx->expressionList(0)->expression(0);

        context->AMPSERSAND_level++;

        llvm::Value *lexpr = varNode->accept(this);

        llvm::Value *expr = ctx->expressionList(1)->accept(this);


        context->Builder->CreateStore(expr, lexpr);

        return nullptr;
    }

    antlrcpp::Any visitExpression(GoParser::ExpressionContext *ctx) override {
        if (ctx->add_op || ctx->rel_op) {
            llvm::Value *L = ctx->expression(0)->accept(this);
            llvm::Value *R = ctx->expression(1)->accept(this);

            if (ctx->PLUS()) {
                return context->Builder->CreateAdd(L, R);
            }
            if (ctx->MINUS()) {
                return context->Builder->CreateSub(L, R);
            }
            if (ctx->GREATER()) {
                return context->Builder->CreateICmpSGT(L, R);
            }
            if (ctx->LESS()) {
                return context->Builder->CreateICmpSLT(L, R);
            }
            if (ctx->EQUALS()) {
                return context->Builder->CreateICmpEQ(L, R);
            }
            // @todo add other ops
        } else if (ctx->AMPERSAND()) {
            // @todo: remove kostyl'

            auto init_l = context->AMPSERSAND_level;
            context->AMPSERSAND_level++;
            auto child = ctx->expression(0)->accept(this);

            if (context->AMPSERSAND_level != init_l) {
                std::cerr << "Can't get pointer (&):" << ctx->getText() << std::endl;
            }
            return child;
        }

        return GoParserBaseVisitor::visitExpression(ctx);
    }

    antlrcpp::Any visitIfStmt(GoParser::IfStmtContext *ctx) override {
        auto CondV = ctx->expression()->accept(this);
        auto parent = context->Stack.rbegin()->first->getParent();

        auto ThenBB = llvm::BasicBlock::Create(*context->TheContext, "if", parent);
        auto ElseBB = llvm::BasicBlock::Create(*context->TheContext, "else");
        auto MergeBB = llvm::BasicBlock::Create(*context->TheContext, "after-if");

        context->Builder->CreateCondBr(CondV, ThenBB, ElseBB);
        context->Builder->SetInsertPoint(ThenBB);

        ctx->block(0)->statementList()->accept(this);
        context->Builder->CreateBr(MergeBB);

        parent->insert(parent->end(), ElseBB);
        context->Builder->SetInsertPoint(ElseBB);

        if (ctx->ELSE()) {
            if (ctx->ifStmt()) {
                ctx->ifStmt()->accept(this);
            } else {
                ctx->block(1)->accept(this);
            }

        }
        context->Builder->CreateBr(MergeBB);

        parent->insert(parent->end(), MergeBB);
        context->Builder->SetInsertPoint(MergeBB);

        return nullptr;
    }

    antlrcpp::Any visitForStmt(GoParser::ForStmtContext *ctx) override {
        llvm::Function *TheFunction = context->Builder->GetInsertBlock()->getParent();

        ctx->forClause()->children[0]->accept(this);

        llvm::Value *StartCond = ctx->forClause()->children[2]->accept(this);
        if (!StartCond)
            return nullptr;
        auto LoopBB = llvm::BasicBlock::Create(*context->TheContext, "loop", TheFunction);
        auto AfterBB = llvm::BasicBlock::Create(*context->TheContext, "afterloop", TheFunction);

        context->Builder->CreateCondBr(StartCond, LoopBB, AfterBB);


        context->Builder->SetInsertPoint(LoopBB);

        // @todo fix stack visiblity

        ctx->block()->statementList()->accept(this);

        ctx->forClause()->children[4]->accept(this);


        llvm::Value *EndCond = ctx->forClause()->children[2]->accept(this);
        if (!EndCond)
            return nullptr;
        context->Builder->CreateCondBr(EndCond, LoopBB, AfterBB);

        context->Builder->SetInsertPoint(AfterBB);

        return nullptr;
    }
};

#endif //APP_PARSERVISITOR_H
