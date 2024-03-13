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
#include "../parser/codegen/GoParserBaseVisitor.h"
#include "TypeWrapper.h"
#include "ValueWrapper.h"
#include "FunctionWrapper.h"
#include "Context.h"
#include "GoIrBuilder.h"

class ParserVisitor : public GoParserBaseVisitor {
 public:
  [[nodiscard]] const std::shared_ptr<GoIrBuilder> &GetGoIrBuilder() const;
  explicit ParserVisitor();

  antlrcpp::Any visitSourceFile(GoParser::SourceFileContext *ctx) override;
  antlrcpp::Any visitImportDecl(GoParser::ImportDeclContext *ctx) override;
  antlrcpp::Any visitTypeDecl(GoParser::TypeDeclContext *ctx) override;
  antlrcpp::Any visitFunctionDecl(GoParser::FunctionDeclContext *ctx) override;
  antlrcpp::Any visitStatement(GoParser::StatementContext *ctx) override;
  antlrcpp::Any visitInteger(GoParser::IntegerContext *ctx) override;
  antlrcpp::Any visitBasicLit(GoParser::BasicLitContext *ctx) override;
  antlrcpp::Any visitString_(GoParser::String_Context *ctx) override;
  antlrcpp::Any visitConstDecl(GoParser::ConstDeclContext *ctx) override;
  antlrcpp::Any visitReturnStmt(GoParser::ReturnStmtContext *ctx) override;
  antlrcpp::Any visitVarDecl(GoParser::VarDeclContext *ctx) override;
  antlrcpp::Any visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) override;
  antlrcpp::Any visitMethodDecl(GoParser::MethodDeclContext *ctx) override;
  antlrcpp::Any visitOperand(GoParser::OperandContext *ctx) override;
  antlrcpp::Any visitOperandName(GoParser::OperandNameContext *ctx) override;
  antlrcpp::Any visitAssignment(GoParser::AssignmentContext *ctx) override;
  antlrcpp::Any visitExpression(GoParser::ExpressionContext *ctx) override;
  antlrcpp::Any visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) override;
  antlrcpp::Any visitIfStmt(GoParser::IfStmtContext *ctx) override;
  antlrcpp::Any visitForStmt(GoParser::ForStmtContext *ctx) override;

 private:
  std::shared_ptr<GoIrBuilder> goIrBuilder;

};

#endif //APP_PARSERVISITOR_H
