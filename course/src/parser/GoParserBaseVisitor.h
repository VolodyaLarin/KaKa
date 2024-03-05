#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "GoParserVisitor.h"


/**
 * This class provides an empty implementation of GoParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GoParserBaseVisitor : public GoParserVisitor {
public:

  virtual antlrcpp::Any visitSourceFile(GoParser::SourceFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackageClause(GoParser::PackageClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportDecl(GoParser::ImportDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportSpec(GoParser::ImportSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportPath(GoParser::ImportPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(GoParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDecl(GoParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstSpec(GoParser::ConstSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(GoParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(GoParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDecl(GoParser::TypeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSpec(GoParser::TypeSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasDecl(GoParser::AliasDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDef(GoParser::TypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeParameters(GoParser::TypeParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeParameterDecl(GoParser::TypeParameterDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeElement(GoParser::TypeElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeTerm(GoParser::TypeTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDecl(GoParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDecl(GoParser::MethodDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReceiver(GoParser::ReceiverContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(GoParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarSpec(GoParser::VarSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(GoParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(GoParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(GoParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleStmt(GoParser::SimpleStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStmt(GoParser::ExpressionStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSendStmt(GoParser::SendStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncDecStmt(GoParser::IncDecStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(GoParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_op(GoParser::Assign_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabeledStmt(GoParser::LabeledStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(GoParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakStmt(GoParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinueStmt(GoParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGotoStmt(GoParser::GotoStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFallthroughStmt(GoParser::FallthroughStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferStmt(GoParser::DeferStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(GoParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmt(GoParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprSwitchStmt(GoParser::ExprSwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprCaseClause(GoParser::ExprCaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprSwitchCase(GoParser::ExprSwitchCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSwitchStmt(GoParser::TypeSwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSwitchGuard(GoParser::TypeSwitchGuardContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeCaseClause(GoParser::TypeCaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSwitchCase(GoParser::TypeSwitchCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeList(GoParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectStmt(GoParser::SelectStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommClause(GoParser::CommClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommCase(GoParser::CommCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecvStmt(GoParser::RecvStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(GoParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForClause(GoParser::ForClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRangeClause(GoParser::RangeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGoStmt(GoParser::GoStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_(GoParser::Type_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeArgs(GoParser::TypeArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(GoParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeLit(GoParser::TypeLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(GoParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLength(GoParser::ArrayLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementType(GoParser::ElementTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPointerType(GoParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterfaceType(GoParser::InterfaceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSliceType(GoParser::SliceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMapType(GoParser::MapTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChannelType(GoParser::ChannelTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodSpec(GoParser::MethodSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionType(GoParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignature(GoParser::SignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult(GoParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(GoParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDecl(GoParser::ParameterDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(GoParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConversion(GoParser::ConversionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperand(GoParser::OperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(GoParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicLit(GoParser::BasicLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger(GoParser::IntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperandName(GoParser::OperandNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualifiedIdent(GoParser::QualifiedIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompositeLit(GoParser::CompositeLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralType(GoParser::LiteralTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralValue(GoParser::LiteralValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementList(GoParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyedElement(GoParser::KeyedElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKey(GoParser::KeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement(GoParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructType(GoParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldDecl(GoParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString_(GoParser::String_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmbeddedField(GoParser::EmbeddedFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionLit(GoParser::FunctionLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex(GoParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSlice_(GoParser::Slice_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAssertion(GoParser::TypeAssertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(GoParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodExpr(GoParser::MethodExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(GoParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

