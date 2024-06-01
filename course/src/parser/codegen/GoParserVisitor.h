#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.10

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
    virtual std::any visitSourceFile(GoParser::SourceFileContext *context) = 0;

    virtual std::any visitPackageClause(GoParser::PackageClauseContext *context) = 0;

    virtual std::any visitImportDecl(GoParser::ImportDeclContext *context) = 0;

    virtual std::any visitImportSpec(GoParser::ImportSpecContext *context) = 0;

    virtual std::any visitImportPath(GoParser::ImportPathContext *context) = 0;

    virtual std::any visitDeclaration(GoParser::DeclarationContext *context) = 0;

    virtual std::any visitConstDecl(GoParser::ConstDeclContext *context) = 0;

    virtual std::any visitConstSpec(GoParser::ConstSpecContext *context) = 0;

    virtual std::any visitIdentifierList(GoParser::IdentifierListContext *context) = 0;

    virtual std::any visitExpressionList(GoParser::ExpressionListContext *context) = 0;

    virtual std::any visitTypeDecl(GoParser::TypeDeclContext *context) = 0;

    virtual std::any visitTypeSpec(GoParser::TypeSpecContext *context) = 0;

    virtual std::any visitAliasDecl(GoParser::AliasDeclContext *context) = 0;

    virtual std::any visitTypeDef(GoParser::TypeDefContext *context) = 0;

    virtual std::any visitTypeParameters(GoParser::TypeParametersContext *context) = 0;

    virtual std::any visitTypeParameterDecl(GoParser::TypeParameterDeclContext *context) = 0;

    virtual std::any visitTypeElement(GoParser::TypeElementContext *context) = 0;

    virtual std::any visitTypeTerm(GoParser::TypeTermContext *context) = 0;

    virtual std::any visitFunctionDecl(GoParser::FunctionDeclContext *context) = 0;

    virtual std::any visitMethodDecl(GoParser::MethodDeclContext *context) = 0;

    virtual std::any visitReceiver(GoParser::ReceiverContext *context) = 0;

    virtual std::any visitVarDecl(GoParser::VarDeclContext *context) = 0;

    virtual std::any visitVarSpec(GoParser::VarSpecContext *context) = 0;

    virtual std::any visitBlock(GoParser::BlockContext *context) = 0;

    virtual std::any visitStatementList(GoParser::StatementListContext *context) = 0;

    virtual std::any visitStatement(GoParser::StatementContext *context) = 0;

    virtual std::any visitSimpleStmt(GoParser::SimpleStmtContext *context) = 0;

    virtual std::any visitExpressionStmt(GoParser::ExpressionStmtContext *context) = 0;

    virtual std::any visitSendStmt(GoParser::SendStmtContext *context) = 0;

    virtual std::any visitIncDecStmt(GoParser::IncDecStmtContext *context) = 0;

    virtual std::any visitAssignment(GoParser::AssignmentContext *context) = 0;

    virtual std::any visitAssign_op(GoParser::Assign_opContext *context) = 0;

    virtual std::any visitShortVarDecl(GoParser::ShortVarDeclContext *context) = 0;

    virtual std::any visitLabeledStmt(GoParser::LabeledStmtContext *context) = 0;

    virtual std::any visitReturnStmt(GoParser::ReturnStmtContext *context) = 0;

    virtual std::any visitBreakStmt(GoParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(GoParser::ContinueStmtContext *context) = 0;

    virtual std::any visitGotoStmt(GoParser::GotoStmtContext *context) = 0;

    virtual std::any visitFallthroughStmt(GoParser::FallthroughStmtContext *context) = 0;

    virtual std::any visitDeferStmt(GoParser::DeferStmtContext *context) = 0;

    virtual std::any visitIfStmt(GoParser::IfStmtContext *context) = 0;

    virtual std::any visitSwitchStmt(GoParser::SwitchStmtContext *context) = 0;

    virtual std::any visitExprSwitchStmt(GoParser::ExprSwitchStmtContext *context) = 0;

    virtual std::any visitExprCaseClause(GoParser::ExprCaseClauseContext *context) = 0;

    virtual std::any visitExprSwitchCase(GoParser::ExprSwitchCaseContext *context) = 0;

    virtual std::any visitTypeSwitchStmt(GoParser::TypeSwitchStmtContext *context) = 0;

    virtual std::any visitTypeSwitchGuard(GoParser::TypeSwitchGuardContext *context) = 0;

    virtual std::any visitTypeCaseClause(GoParser::TypeCaseClauseContext *context) = 0;

    virtual std::any visitTypeSwitchCase(GoParser::TypeSwitchCaseContext *context) = 0;

    virtual std::any visitTypeList(GoParser::TypeListContext *context) = 0;

    virtual std::any visitSelectStmt(GoParser::SelectStmtContext *context) = 0;

    virtual std::any visitCommClause(GoParser::CommClauseContext *context) = 0;

    virtual std::any visitCommCase(GoParser::CommCaseContext *context) = 0;

    virtual std::any visitRecvStmt(GoParser::RecvStmtContext *context) = 0;

    virtual std::any visitForStmt(GoParser::ForStmtContext *context) = 0;

    virtual std::any visitForClause(GoParser::ForClauseContext *context) = 0;

    virtual std::any visitRangeClause(GoParser::RangeClauseContext *context) = 0;

    virtual std::any visitGoStmt(GoParser::GoStmtContext *context) = 0;

    virtual std::any visitType_(GoParser::Type_Context *context) = 0;

    virtual std::any visitTypeArgs(GoParser::TypeArgsContext *context) = 0;

    virtual std::any visitTypeName(GoParser::TypeNameContext *context) = 0;

    virtual std::any visitTypeLit(GoParser::TypeLitContext *context) = 0;

    virtual std::any visitArrayType(GoParser::ArrayTypeContext *context) = 0;

    virtual std::any visitArrayLength(GoParser::ArrayLengthContext *context) = 0;

    virtual std::any visitElementType(GoParser::ElementTypeContext *context) = 0;

    virtual std::any visitPointerType(GoParser::PointerTypeContext *context) = 0;

    virtual std::any visitInterfaceType(GoParser::InterfaceTypeContext *context) = 0;

    virtual std::any visitSliceType(GoParser::SliceTypeContext *context) = 0;

    virtual std::any visitMapType(GoParser::MapTypeContext *context) = 0;

    virtual std::any visitChannelType(GoParser::ChannelTypeContext *context) = 0;

    virtual std::any visitMethodSpec(GoParser::MethodSpecContext *context) = 0;

    virtual std::any visitFunctionType(GoParser::FunctionTypeContext *context) = 0;

    virtual std::any visitSignature(GoParser::SignatureContext *context) = 0;

    virtual std::any visitResult(GoParser::ResultContext *context) = 0;

    virtual std::any visitParameters(GoParser::ParametersContext *context) = 0;

    virtual std::any visitParameterDecl(GoParser::ParameterDeclContext *context) = 0;

    virtual std::any visitExpression(GoParser::ExpressionContext *context) = 0;

    virtual std::any visitPrimaryExpr(GoParser::PrimaryExprContext *context) = 0;

    virtual std::any visitConversion(GoParser::ConversionContext *context) = 0;

    virtual std::any visitOperand(GoParser::OperandContext *context) = 0;

    virtual std::any visitLiteral(GoParser::LiteralContext *context) = 0;

    virtual std::any visitBasicLit(GoParser::BasicLitContext *context) = 0;

    virtual std::any visitInteger(GoParser::IntegerContext *context) = 0;

    virtual std::any visitOperandName(GoParser::OperandNameContext *context) = 0;

    virtual std::any visitQualifiedIdent(GoParser::QualifiedIdentContext *context) = 0;

    virtual std::any visitCompositeLit(GoParser::CompositeLitContext *context) = 0;

    virtual std::any visitLiteralType(GoParser::LiteralTypeContext *context) = 0;

    virtual std::any visitLiteralValue(GoParser::LiteralValueContext *context) = 0;

    virtual std::any visitElementList(GoParser::ElementListContext *context) = 0;

    virtual std::any visitKeyedElement(GoParser::KeyedElementContext *context) = 0;

    virtual std::any visitKey(GoParser::KeyContext *context) = 0;

    virtual std::any visitElement(GoParser::ElementContext *context) = 0;

    virtual std::any visitStructType(GoParser::StructTypeContext *context) = 0;

    virtual std::any visitFieldDecl(GoParser::FieldDeclContext *context) = 0;

    virtual std::any visitString_(GoParser::String_Context *context) = 0;

    virtual std::any visitEmbeddedField(GoParser::EmbeddedFieldContext *context) = 0;

    virtual std::any visitFunctionLit(GoParser::FunctionLitContext *context) = 0;

    virtual std::any visitIndex(GoParser::IndexContext *context) = 0;

    virtual std::any visitSlice_(GoParser::Slice_Context *context) = 0;

    virtual std::any visitTypeAssertion(GoParser::TypeAssertionContext *context) = 0;

    virtual std::any visitArguments(GoParser::ArgumentsContext *context) = 0;

    virtual std::any visitMethodExpr(GoParser::MethodExprContext *context) = 0;

    virtual std::any visitEos(GoParser::EosContext *context) = 0;


};

