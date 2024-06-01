#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "GoParserVisitor.h"


/**
 * This class provides an empty implementation of GoParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GoParserBaseVisitor : public GoParserVisitor {
public:

  virtual std::any visitSourceFile(GoParser::SourceFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPackageClause(GoParser::PackageClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportDecl(GoParser::ImportDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportSpec(GoParser::ImportSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportPath(GoParser::ImportPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(GoParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(GoParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstSpec(GoParser::ConstSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierList(GoParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(GoParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDecl(GoParser::TypeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeSpec(GoParser::TypeSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAliasDecl(GoParser::AliasDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDef(GoParser::TypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeParameters(GoParser::TypeParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeParameterDecl(GoParser::TypeParameterDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeElement(GoParser::TypeElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeTerm(GoParser::TypeTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(GoParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodDecl(GoParser::MethodDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReceiver(GoParser::ReceiverContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(GoParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarSpec(GoParser::VarSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(GoParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementList(GoParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(GoParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleStmt(GoParser::SimpleStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStmt(GoParser::ExpressionStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSendStmt(GoParser::SendStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncDecStmt(GoParser::IncDecStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(GoParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_op(GoParser::Assign_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabeledStmt(GoParser::LabeledStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(GoParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(GoParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(GoParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGotoStmt(GoParser::GotoStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFallthroughStmt(GoParser::FallthroughStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeferStmt(GoParser::DeferStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(GoParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmt(GoParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprSwitchStmt(GoParser::ExprSwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprCaseClause(GoParser::ExprCaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprSwitchCase(GoParser::ExprSwitchCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeSwitchStmt(GoParser::TypeSwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeSwitchGuard(GoParser::TypeSwitchGuardContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeCaseClause(GoParser::TypeCaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeSwitchCase(GoParser::TypeSwitchCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeList(GoParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectStmt(GoParser::SelectStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommClause(GoParser::CommClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommCase(GoParser::CommCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecvStmt(GoParser::RecvStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(GoParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForClause(GoParser::ForClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangeClause(GoParser::RangeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoStmt(GoParser::GoStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_(GoParser::Type_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeArgs(GoParser::TypeArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeName(GoParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeLit(GoParser::TypeLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(GoParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLength(GoParser::ArrayLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementType(GoParser::ElementTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointerType(GoParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceType(GoParser::InterfaceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSliceType(GoParser::SliceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapType(GoParser::MapTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChannelType(GoParser::ChannelTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodSpec(GoParser::MethodSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionType(GoParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignature(GoParser::SignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResult(GoParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(GoParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterDecl(GoParser::ParameterDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(GoParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConversion(GoParser::ConversionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperand(GoParser::OperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(GoParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasicLit(GoParser::BasicLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteger(GoParser::IntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperandName(GoParser::OperandNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualifiedIdent(GoParser::QualifiedIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompositeLit(GoParser::CompositeLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralType(GoParser::LiteralTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralValue(GoParser::LiteralValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementList(GoParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyedElement(GoParser::KeyedElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKey(GoParser::KeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElement(GoParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructType(GoParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldDecl(GoParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString_(GoParser::String_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmbeddedField(GoParser::EmbeddedFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionLit(GoParser::FunctionLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(GoParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice_(GoParser::Slice_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeAssertion(GoParser::TypeAssertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(GoParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodExpr(GoParser::MethodExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEos(GoParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

