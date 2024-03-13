#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "GoParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GoParser.
 */
class  GoParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GoParser.
   */
    virtual antlrcpp::Any visitSourceFile(GoParser::SourceFileContext *context) = 0;

    virtual antlrcpp::Any visitPackageClause(GoParser::PackageClauseContext *context) = 0;

    virtual antlrcpp::Any visitImportDecl(GoParser::ImportDeclContext *context) = 0;

    virtual antlrcpp::Any visitImportSpec(GoParser::ImportSpecContext *context) = 0;

    virtual antlrcpp::Any visitImportPath(GoParser::ImportPathContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(GoParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstDecl(GoParser::ConstDeclContext *context) = 0;

    virtual antlrcpp::Any visitConstSpec(GoParser::ConstSpecContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(GoParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(GoParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitTypeDecl(GoParser::TypeDeclContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpec(GoParser::TypeSpecContext *context) = 0;

    virtual antlrcpp::Any visitAliasDecl(GoParser::AliasDeclContext *context) = 0;

    virtual antlrcpp::Any visitTypeDef(GoParser::TypeDefContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameters(GoParser::TypeParametersContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameterDecl(GoParser::TypeParameterDeclContext *context) = 0;

    virtual antlrcpp::Any visitTypeElement(GoParser::TypeElementContext *context) = 0;

    virtual antlrcpp::Any visitTypeTerm(GoParser::TypeTermContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDecl(GoParser::FunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodDecl(GoParser::MethodDeclContext *context) = 0;

    virtual antlrcpp::Any visitReceiver(GoParser::ReceiverContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(GoParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarSpec(GoParser::VarSpecContext *context) = 0;

    virtual antlrcpp::Any visitBlock(GoParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(GoParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(GoParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStmt(GoParser::SimpleStmtContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStmt(GoParser::ExpressionStmtContext *context) = 0;

    virtual antlrcpp::Any visitSendStmt(GoParser::SendStmtContext *context) = 0;

    virtual antlrcpp::Any visitIncDecStmt(GoParser::IncDecStmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(GoParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitAssign_op(GoParser::Assign_opContext *context) = 0;

    virtual antlrcpp::Any visitShortVarDecl(GoParser::ShortVarDeclContext *context) = 0;

    virtual antlrcpp::Any visitLabeledStmt(GoParser::LabeledStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(GoParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitBreakStmt(GoParser::BreakStmtContext *context) = 0;

    virtual antlrcpp::Any visitContinueStmt(GoParser::ContinueStmtContext *context) = 0;

    virtual antlrcpp::Any visitGotoStmt(GoParser::GotoStmtContext *context) = 0;

    virtual antlrcpp::Any visitFallthroughStmt(GoParser::FallthroughStmtContext *context) = 0;

    virtual antlrcpp::Any visitDeferStmt(GoParser::DeferStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(GoParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmt(GoParser::SwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprSwitchStmt(GoParser::ExprSwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprCaseClause(GoParser::ExprCaseClauseContext *context) = 0;

    virtual antlrcpp::Any visitExprSwitchCase(GoParser::ExprSwitchCaseContext *context) = 0;

    virtual antlrcpp::Any visitTypeSwitchStmt(GoParser::TypeSwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitTypeSwitchGuard(GoParser::TypeSwitchGuardContext *context) = 0;

    virtual antlrcpp::Any visitTypeCaseClause(GoParser::TypeCaseClauseContext *context) = 0;

    virtual antlrcpp::Any visitTypeSwitchCase(GoParser::TypeSwitchCaseContext *context) = 0;

    virtual antlrcpp::Any visitTypeList(GoParser::TypeListContext *context) = 0;

    virtual antlrcpp::Any visitSelectStmt(GoParser::SelectStmtContext *context) = 0;

    virtual antlrcpp::Any visitCommClause(GoParser::CommClauseContext *context) = 0;

    virtual antlrcpp::Any visitCommCase(GoParser::CommCaseContext *context) = 0;

    virtual antlrcpp::Any visitRecvStmt(GoParser::RecvStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(GoParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForClause(GoParser::ForClauseContext *context) = 0;

    virtual antlrcpp::Any visitRangeClause(GoParser::RangeClauseContext *context) = 0;

    virtual antlrcpp::Any visitGoStmt(GoParser::GoStmtContext *context) = 0;

    virtual antlrcpp::Any visitType_(GoParser::Type_Context *context) = 0;

    virtual antlrcpp::Any visitTypeArgs(GoParser::TypeArgsContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(GoParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitTypeLit(GoParser::TypeLitContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(GoParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayLength(GoParser::ArrayLengthContext *context) = 0;

    virtual antlrcpp::Any visitElementType(GoParser::ElementTypeContext *context) = 0;

    virtual antlrcpp::Any visitPointerType(GoParser::PointerTypeContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceType(GoParser::InterfaceTypeContext *context) = 0;

    virtual antlrcpp::Any visitSliceType(GoParser::SliceTypeContext *context) = 0;

    virtual antlrcpp::Any visitMapType(GoParser::MapTypeContext *context) = 0;

    virtual antlrcpp::Any visitChannelType(GoParser::ChannelTypeContext *context) = 0;

    virtual antlrcpp::Any visitMethodSpec(GoParser::MethodSpecContext *context) = 0;

    virtual antlrcpp::Any visitFunctionType(GoParser::FunctionTypeContext *context) = 0;

    virtual antlrcpp::Any visitSignature(GoParser::SignatureContext *context) = 0;

    virtual antlrcpp::Any visitResult(GoParser::ResultContext *context) = 0;

    virtual antlrcpp::Any visitParameters(GoParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameterDecl(GoParser::ParameterDeclContext *context) = 0;

    virtual antlrcpp::Any visitExpression(GoParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExpr(GoParser::PrimaryExprContext *context) = 0;

    virtual antlrcpp::Any visitConversion(GoParser::ConversionContext *context) = 0;

    virtual antlrcpp::Any visitOperand(GoParser::OperandContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(GoParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBasicLit(GoParser::BasicLitContext *context) = 0;

    virtual antlrcpp::Any visitInteger(GoParser::IntegerContext *context) = 0;

    virtual antlrcpp::Any visitOperandName(GoParser::OperandNameContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedIdent(GoParser::QualifiedIdentContext *context) = 0;

    virtual antlrcpp::Any visitCompositeLit(GoParser::CompositeLitContext *context) = 0;

    virtual antlrcpp::Any visitLiteralType(GoParser::LiteralTypeContext *context) = 0;

    virtual antlrcpp::Any visitLiteralValue(GoParser::LiteralValueContext *context) = 0;

    virtual antlrcpp::Any visitElementList(GoParser::ElementListContext *context) = 0;

    virtual antlrcpp::Any visitKeyedElement(GoParser::KeyedElementContext *context) = 0;

    virtual antlrcpp::Any visitKey(GoParser::KeyContext *context) = 0;

    virtual antlrcpp::Any visitElement(GoParser::ElementContext *context) = 0;

    virtual antlrcpp::Any visitStructType(GoParser::StructTypeContext *context) = 0;

    virtual antlrcpp::Any visitFieldDecl(GoParser::FieldDeclContext *context) = 0;

    virtual antlrcpp::Any visitString_(GoParser::String_Context *context) = 0;

    virtual antlrcpp::Any visitEmbeddedField(GoParser::EmbeddedFieldContext *context) = 0;

    virtual antlrcpp::Any visitFunctionLit(GoParser::FunctionLitContext *context) = 0;

    virtual antlrcpp::Any visitIndex(GoParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitSlice_(GoParser::Slice_Context *context) = 0;

    virtual antlrcpp::Any visitTypeAssertion(GoParser::TypeAssertionContext *context) = 0;

    virtual antlrcpp::Any visitArguments(GoParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitMethodExpr(GoParser::MethodExprContext *context) = 0;

    virtual antlrcpp::Any visitEos(GoParser::EosContext *context) = 0;


};

