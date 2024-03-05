#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  GoParser : public GoParserBase {
public:
  enum {
    BREAK = 1, DEFAULT = 2, FUNC = 3, INTERFACE = 4, SELECT = 5, CASE = 6, 
    DEFER = 7, GO = 8, MAP = 9, STRUCT = 10, CHAN = 11, ELSE = 12, GOTO = 13, 
    PACKAGE = 14, SWITCH = 15, CONST = 16, FALLTHROUGH = 17, IF = 18, RANGE = 19, 
    TYPE = 20, CONTINUE = 21, FOR = 22, IMPORT = 23, RETURN = 24, VAR = 25, 
    NIL_LIT = 26, IDENTIFIER = 27, L_PAREN = 28, R_PAREN = 29, L_CURLY = 30, 
    R_CURLY = 31, L_BRACKET = 32, R_BRACKET = 33, ASSIGN = 34, COMMA = 35, 
    SEMI = 36, COLON = 37, DOT = 38, PLUS_PLUS = 39, MINUS_MINUS = 40, DECLARE_ASSIGN = 41, 
    ELLIPSIS = 42, LOGICAL_OR = 43, LOGICAL_AND = 44, EQUALS = 45, NOT_EQUALS = 46, 
    LESS = 47, LESS_OR_EQUALS = 48, GREATER = 49, GREATER_OR_EQUALS = 50, 
    OR = 51, DIV = 52, MOD = 53, LSHIFT = 54, RSHIFT = 55, BIT_CLEAR = 56, 
    UNDERLYING = 57, EXCLAMATION = 58, PLUS = 59, MINUS = 60, CARET = 61, 
    STAR = 62, AMPERSAND = 63, RECEIVE = 64, DECIMAL_LIT = 65, BINARY_LIT = 66, 
    OCTAL_LIT = 67, HEX_LIT = 68, FLOAT_LIT = 69, DECIMAL_FLOAT_LIT = 70, 
    HEX_FLOAT_LIT = 71, IMAGINARY_LIT = 72, RUNE_LIT = 73, BYTE_VALUE = 74, 
    OCTAL_BYTE_VALUE = 75, HEX_BYTE_VALUE = 76, LITTLE_U_VALUE = 77, BIG_U_VALUE = 78, 
    RAW_STRING_LIT = 79, INTERPRETED_STRING_LIT = 80, WS = 81, COMMENT = 82, 
    TERMINATOR = 83, LINE_COMMENT = 84, WS_NLSEMI = 85, COMMENT_NLSEMI = 86, 
    LINE_COMMENT_NLSEMI = 87, EOS = 88, OTHER = 89
  };

  enum {
    RuleSourceFile = 0, RulePackageClause = 1, RuleImportDecl = 2, RuleImportSpec = 3, 
    RuleImportPath = 4, RuleDeclaration = 5, RuleConstDecl = 6, RuleConstSpec = 7, 
    RuleIdentifierList = 8, RuleExpressionList = 9, RuleTypeDecl = 10, RuleTypeSpec = 11, 
    RuleAliasDecl = 12, RuleTypeDef = 13, RuleTypeParameters = 14, RuleTypeParameterDecl = 15, 
    RuleTypeElement = 16, RuleTypeTerm = 17, RuleFunctionDecl = 18, RuleMethodDecl = 19, 
    RuleReceiver = 20, RuleVarDecl = 21, RuleVarSpec = 22, RuleBlock = 23, 
    RuleStatementList = 24, RuleStatement = 25, RuleSimpleStmt = 26, RuleExpressionStmt = 27, 
    RuleSendStmt = 28, RuleIncDecStmt = 29, RuleAssignment = 30, RuleAssign_op = 31, 
    RuleShortVarDecl = 32, RuleLabeledStmt = 33, RuleReturnStmt = 34, RuleBreakStmt = 35, 
    RuleContinueStmt = 36, RuleGotoStmt = 37, RuleFallthroughStmt = 38, 
    RuleDeferStmt = 39, RuleIfStmt = 40, RuleSwitchStmt = 41, RuleExprSwitchStmt = 42, 
    RuleExprCaseClause = 43, RuleExprSwitchCase = 44, RuleTypeSwitchStmt = 45, 
    RuleTypeSwitchGuard = 46, RuleTypeCaseClause = 47, RuleTypeSwitchCase = 48, 
    RuleTypeList = 49, RuleSelectStmt = 50, RuleCommClause = 51, RuleCommCase = 52, 
    RuleRecvStmt = 53, RuleForStmt = 54, RuleForClause = 55, RuleRangeClause = 56, 
    RuleGoStmt = 57, RuleType_ = 58, RuleTypeArgs = 59, RuleTypeName = 60, 
    RuleTypeLit = 61, RuleArrayType = 62, RuleArrayLength = 63, RuleElementType = 64, 
    RulePointerType = 65, RuleInterfaceType = 66, RuleSliceType = 67, RuleMapType = 68, 
    RuleChannelType = 69, RuleMethodSpec = 70, RuleFunctionType = 71, RuleSignature = 72, 
    RuleResult = 73, RuleParameters = 74, RuleParameterDecl = 75, RuleExpression = 76, 
    RulePrimaryExpr = 77, RuleConversion = 78, RuleOperand = 79, RuleLiteral = 80, 
    RuleBasicLit = 81, RuleInteger = 82, RuleOperandName = 83, RuleQualifiedIdent = 84, 
    RuleCompositeLit = 85, RuleLiteralType = 86, RuleLiteralValue = 87, 
    RuleElementList = 88, RuleKeyedElement = 89, RuleKey = 90, RuleElement = 91, 
    RuleStructType = 92, RuleFieldDecl = 93, RuleString_ = 94, RuleEmbeddedField = 95, 
    RuleFunctionLit = 96, RuleIndex = 97, RuleSlice_ = 98, RuleTypeAssertion = 99, 
    RuleArguments = 100, RuleMethodExpr = 101, RuleEos = 102
  };

  explicit GoParser(antlr4::TokenStream *input);
  ~GoParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class SourceFileContext;
  class PackageClauseContext;
  class ImportDeclContext;
  class ImportSpecContext;
  class ImportPathContext;
  class DeclarationContext;
  class ConstDeclContext;
  class ConstSpecContext;
  class IdentifierListContext;
  class ExpressionListContext;
  class TypeDeclContext;
  class TypeSpecContext;
  class AliasDeclContext;
  class TypeDefContext;
  class TypeParametersContext;
  class TypeParameterDeclContext;
  class TypeElementContext;
  class TypeTermContext;
  class FunctionDeclContext;
  class MethodDeclContext;
  class ReceiverContext;
  class VarDeclContext;
  class VarSpecContext;
  class BlockContext;
  class StatementListContext;
  class StatementContext;
  class SimpleStmtContext;
  class ExpressionStmtContext;
  class SendStmtContext;
  class IncDecStmtContext;
  class AssignmentContext;
  class Assign_opContext;
  class ShortVarDeclContext;
  class LabeledStmtContext;
  class ReturnStmtContext;
  class BreakStmtContext;
  class ContinueStmtContext;
  class GotoStmtContext;
  class FallthroughStmtContext;
  class DeferStmtContext;
  class IfStmtContext;
  class SwitchStmtContext;
  class ExprSwitchStmtContext;
  class ExprCaseClauseContext;
  class ExprSwitchCaseContext;
  class TypeSwitchStmtContext;
  class TypeSwitchGuardContext;
  class TypeCaseClauseContext;
  class TypeSwitchCaseContext;
  class TypeListContext;
  class SelectStmtContext;
  class CommClauseContext;
  class CommCaseContext;
  class RecvStmtContext;
  class ForStmtContext;
  class ForClauseContext;
  class RangeClauseContext;
  class GoStmtContext;
  class Type_Context;
  class TypeArgsContext;
  class TypeNameContext;
  class TypeLitContext;
  class ArrayTypeContext;
  class ArrayLengthContext;
  class ElementTypeContext;
  class PointerTypeContext;
  class InterfaceTypeContext;
  class SliceTypeContext;
  class MapTypeContext;
  class ChannelTypeContext;
  class MethodSpecContext;
  class FunctionTypeContext;
  class SignatureContext;
  class ResultContext;
  class ParametersContext;
  class ParameterDeclContext;
  class ExpressionContext;
  class PrimaryExprContext;
  class ConversionContext;
  class OperandContext;
  class LiteralContext;
  class BasicLitContext;
  class IntegerContext;
  class OperandNameContext;
  class QualifiedIdentContext;
  class CompositeLitContext;
  class LiteralTypeContext;
  class LiteralValueContext;
  class ElementListContext;
  class KeyedElementContext;
  class KeyContext;
  class ElementContext;
  class StructTypeContext;
  class FieldDeclContext;
  class String_Context;
  class EmbeddedFieldContext;
  class FunctionLitContext;
  class IndexContext;
  class Slice_Context;
  class TypeAssertionContext;
  class ArgumentsContext;
  class MethodExprContext;
  class EosContext; 

  class  SourceFileContext : public antlr4::ParserRuleContext {
  public:
    SourceFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PackageClauseContext *packageClause();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<ImportDeclContext *> importDecl();
    ImportDeclContext* importDecl(size_t i);
    std::vector<FunctionDeclContext *> functionDecl();
    FunctionDeclContext* functionDecl(size_t i);
    std::vector<MethodDeclContext *> methodDecl();
    MethodDeclContext* methodDecl(size_t i);
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SourceFileContext* sourceFile();

  class  PackageClauseContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *packageName = nullptr;
    PackageClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageClauseContext* packageClause();

  class  ImportDeclContext : public antlr4::ParserRuleContext {
  public:
    ImportDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<ImportSpecContext *> importSpec();
    ImportSpecContext* importSpec(size_t i);
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportDeclContext* importDecl();

  class  ImportSpecContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *alias = nullptr;
    ImportSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImportPathContext *importPath();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportSpecContext* importSpec();

  class  ImportPathContext : public antlr4::ParserRuleContext {
  public:
    ImportPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    String_Context *string_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportPathContext* importPath();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    TypeDeclContext *typeDecl();
    VarDeclContext *varDecl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    std::vector<ConstSpecContext *> constSpec();
    ConstSpecContext* constSpec(size_t i);
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclContext* constDecl();

  class  ConstSpecContext : public antlr4::ParserRuleContext {
  public:
    ConstSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionListContext *expressionList();
    Type_Context *type_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstSpecContext* constSpec();

  class  IdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierListContext* identifierList();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  TypeDeclContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    std::vector<TypeSpecContext *> typeSpec();
    TypeSpecContext* typeSpec(size_t i);
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclContext* typeDecl();

  class  TypeSpecContext : public antlr4::ParserRuleContext {
  public:
    TypeSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AliasDeclContext *aliasDecl();
    TypeDefContext *typeDef();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSpecContext* typeSpec();

  class  AliasDeclContext : public antlr4::ParserRuleContext {
  public:
    AliasDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    Type_Context *type_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasDeclContext* aliasDecl();

  class  TypeDefContext : public antlr4::ParserRuleContext {
  public:
    TypeDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Type_Context *type_();
    TypeParametersContext *typeParameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDefContext* typeDef();

  class  TypeParametersContext : public antlr4::ParserRuleContext {
  public:
    TypeParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    std::vector<TypeParameterDeclContext *> typeParameterDecl();
    TypeParameterDeclContext* typeParameterDecl(size_t i);
    antlr4::tree::TerminalNode *R_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParametersContext* typeParameters();

  class  TypeParameterDeclContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    TypeElementContext *typeElement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParameterDeclContext* typeParameterDecl();

  class  TypeElementContext : public antlr4::ParserRuleContext {
  public:
    TypeElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeTermContext *> typeTerm();
    TypeTermContext* typeTerm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeElementContext* typeElement();

  class  TypeTermContext : public antlr4::ParserRuleContext {
  public:
    TypeTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *UNDERLYING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeTermContext* typeTerm();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    antlr4::tree::TerminalNode *IDENTIFIER();
    SignatureContext *signature();
    TypeParametersContext *typeParameters();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  MethodDeclContext : public antlr4::ParserRuleContext {
  public:
    MethodDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    ReceiverContext *receiver();
    antlr4::tree::TerminalNode *IDENTIFIER();
    SignatureContext *signature();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodDeclContext* methodDecl();

  class  ReceiverContext : public antlr4::ParserRuleContext {
  public:
    ReceiverContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParametersContext *parameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReceiverContext* receiver();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    std::vector<VarSpecContext *> varSpec();
    VarSpecContext* varSpec(size_t i);
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VarSpecContext : public antlr4::ParserRuleContext {
  public:
    VarSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    Type_Context *type_();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarSpecContext* varSpec();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    StatementListContext *statementList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOS();
    antlr4::tree::TerminalNode* EOS(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    LabeledStmtContext *labeledStmt();
    SimpleStmtContext *simpleStmt();
    GoStmtContext *goStmt();
    ReturnStmtContext *returnStmt();
    BreakStmtContext *breakStmt();
    ContinueStmtContext *continueStmt();
    GotoStmtContext *gotoStmt();
    FallthroughStmtContext *fallthroughStmt();
    BlockContext *block();
    IfStmtContext *ifStmt();
    SwitchStmtContext *switchStmt();
    SelectStmtContext *selectStmt();
    ForStmtContext *forStmt();
    DeferStmtContext *deferStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  SimpleStmtContext : public antlr4::ParserRuleContext {
  public:
    SimpleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SendStmtContext *sendStmt();
    IncDecStmtContext *incDecStmt();
    AssignmentContext *assignment();
    ExpressionStmtContext *expressionStmt();
    ShortVarDeclContext *shortVarDecl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStmtContext* simpleStmt();

  class  ExpressionStmtContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStmtContext* expressionStmt();

  class  SendStmtContext : public antlr4::ParserRuleContext {
  public:
    GoParser::ExpressionContext *channel = nullptr;
    SendStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RECEIVE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SendStmtContext* sendStmt();

  class  IncDecStmtContext : public antlr4::ParserRuleContext {
  public:
    IncDecStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS_PLUS();
    antlr4::tree::TerminalNode *MINUS_MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncDecStmtContext* incDecStmt();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionListContext *> expressionList();
    ExpressionListContext* expressionList(size_t i);
    Assign_opContext *assign_op();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Assign_opContext : public antlr4::ParserRuleContext {
  public:
    Assign_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *CARET();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *BIT_CLEAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_opContext* assign_op();

  class  ShortVarDeclContext : public antlr4::ParserRuleContext {
  public:
    ShortVarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *DECLARE_ASSIGN();
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShortVarDeclContext* shortVarDecl();

  class  LabeledStmtContext : public antlr4::ParserRuleContext {
  public:
    LabeledStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabeledStmtContext* labeledStmt();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStmtContext* returnStmt();

  class  BreakStmtContext : public antlr4::ParserRuleContext {
  public:
    BreakStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreakStmtContext* breakStmt();

  class  ContinueStmtContext : public antlr4::ParserRuleContext {
  public:
    ContinueStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContinueStmtContext* continueStmt();

  class  GotoStmtContext : public antlr4::ParserRuleContext {
  public:
    GotoStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GotoStmtContext* gotoStmt();

  class  FallthroughStmtContext : public antlr4::ParserRuleContext {
  public:
    FallthroughStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FALLTHROUGH();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FallthroughStmtContext* fallthroughStmt();

  class  DeferStmtContext : public antlr4::ParserRuleContext {
  public:
    DeferStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFER();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeferStmtContext* deferStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    ExpressionContext *expression();
    EosContext *eos();
    SimpleStmtContext *simpleStmt();
    antlr4::tree::TerminalNode *ELSE();
    IfStmtContext *ifStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  SwitchStmtContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprSwitchStmtContext *exprSwitchStmt();
    TypeSwitchStmtContext *typeSwitchStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtContext* switchStmt();

  class  ExprSwitchStmtContext : public antlr4::ParserRuleContext {
  public:
    ExprSwitchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    EosContext *eos();
    std::vector<ExprCaseClauseContext *> exprCaseClause();
    ExprCaseClauseContext* exprCaseClause(size_t i);
    ExpressionContext *expression();
    SimpleStmtContext *simpleStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprSwitchStmtContext* exprSwitchStmt();

  class  ExprCaseClauseContext : public antlr4::ParserRuleContext {
  public:
    ExprCaseClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprSwitchCaseContext *exprSwitchCase();
    antlr4::tree::TerminalNode *COLON();
    StatementListContext *statementList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprCaseClauseContext* exprCaseClause();

  class  ExprSwitchCaseContext : public antlr4::ParserRuleContext {
  public:
    ExprSwitchCaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprSwitchCaseContext* exprSwitchCase();

  class  TypeSwitchStmtContext : public antlr4::ParserRuleContext {
  public:
    TypeSwitchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    TypeSwitchGuardContext *typeSwitchGuard();
    EosContext *eos();
    SimpleStmtContext *simpleStmt();
    std::vector<TypeCaseClauseContext *> typeCaseClause();
    TypeCaseClauseContext* typeCaseClause(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSwitchStmtContext* typeSwitchStmt();

  class  TypeSwitchGuardContext : public antlr4::ParserRuleContext {
  public:
    TypeSwitchGuardContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExprContext *primaryExpr();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *R_PAREN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *DECLARE_ASSIGN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSwitchGuardContext* typeSwitchGuard();

  class  TypeCaseClauseContext : public antlr4::ParserRuleContext {
  public:
    TypeCaseClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSwitchCaseContext *typeSwitchCase();
    antlr4::tree::TerminalNode *COLON();
    StatementListContext *statementList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeCaseClauseContext* typeCaseClause();

  class  TypeSwitchCaseContext : public antlr4::ParserRuleContext {
  public:
    TypeSwitchCaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    TypeListContext *typeList();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSwitchCaseContext* typeSwitchCase();

  class  TypeListContext : public antlr4::ParserRuleContext {
  public:
    TypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NIL_LIT();
    antlr4::tree::TerminalNode* NIL_LIT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeListContext* typeList();

  class  SelectStmtContext : public antlr4::ParserRuleContext {
  public:
    SelectStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    std::vector<CommClauseContext *> commClause();
    CommClauseContext* commClause(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectStmtContext* selectStmt();

  class  CommClauseContext : public antlr4::ParserRuleContext {
  public:
    CommClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CommCaseContext *commCase();
    antlr4::tree::TerminalNode *COLON();
    StatementListContext *statementList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommClauseContext* commClause();

  class  CommCaseContext : public antlr4::ParserRuleContext {
  public:
    CommCaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    SendStmtContext *sendStmt();
    RecvStmtContext *recvStmt();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommCaseContext* commCase();

  class  RecvStmtContext : public antlr4::ParserRuleContext {
  public:
    GoParser::ExpressionContext *recvExpr = nullptr;
    RecvStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *ASSIGN();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *DECLARE_ASSIGN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecvStmtContext* recvStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    BlockContext *block();
    ForClauseContext *forClause();
    ExpressionContext *expression();
    RangeClauseContext *rangeClause();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  ForClauseContext : public antlr4::ParserRuleContext {
  public:
    GoParser::SimpleStmtContext *initStmt = nullptr;
    GoParser::SimpleStmtContext *postStmt = nullptr;
    ForClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);
    ExpressionContext *expression();
    std::vector<SimpleStmtContext *> simpleStmt();
    SimpleStmtContext* simpleStmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForClauseContext* forClause();

  class  RangeClauseContext : public antlr4::ParserRuleContext {
  public:
    RangeClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE();
    ExpressionContext *expression();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *ASSIGN();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *DECLARE_ASSIGN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeClauseContext* rangeClause();

  class  GoStmtContext : public antlr4::ParserRuleContext {
  public:
    GoStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GO();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GoStmtContext* goStmt();

  class  Type_Context : public antlr4::ParserRuleContext {
  public:
    Type_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    TypeArgsContext *typeArgs();
    TypeLitContext *typeLit();
    antlr4::tree::TerminalNode *L_PAREN();
    Type_Context *type_();
    antlr4::tree::TerminalNode *R_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_Context* type_();

  class  TypeArgsContext : public antlr4::ParserRuleContext {
  public:
    TypeArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    TypeListContext *typeList();
    antlr4::tree::TerminalNode *R_BRACKET();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgsContext* typeArgs();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedIdentContext *qualifiedIdent();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  TypeLitContext : public antlr4::ParserRuleContext {
  public:
    TypeLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayTypeContext *arrayType();
    StructTypeContext *structType();
    PointerTypeContext *pointerType();
    FunctionTypeContext *functionType();
    InterfaceTypeContext *interfaceType();
    SliceTypeContext *sliceType();
    MapTypeContext *mapType();
    ChannelTypeContext *channelType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeLitContext* typeLit();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    ArrayLengthContext *arrayLength();
    antlr4::tree::TerminalNode *R_BRACKET();
    ElementTypeContext *elementType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ArrayLengthContext : public antlr4::ParserRuleContext {
  public:
    ArrayLengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayLengthContext* arrayLength();

  class  ElementTypeContext : public antlr4::ParserRuleContext {
  public:
    ElementTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementTypeContext* elementType();

  class  PointerTypeContext : public antlr4::ParserRuleContext {
  public:
    PointerTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    Type_Context *type_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointerTypeContext* pointerType();

  class  InterfaceTypeContext : public antlr4::ParserRuleContext {
  public:
    InterfaceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);
    std::vector<MethodSpecContext *> methodSpec();
    MethodSpecContext* methodSpec(size_t i);
    std::vector<TypeElementContext *> typeElement();
    TypeElementContext* typeElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceTypeContext* interfaceType();

  class  SliceTypeContext : public antlr4::ParserRuleContext {
  public:
    SliceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *R_BRACKET();
    ElementTypeContext *elementType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SliceTypeContext* sliceType();

  class  MapTypeContext : public antlr4::ParserRuleContext {
  public:
    MapTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *L_BRACKET();
    Type_Context *type_();
    antlr4::tree::TerminalNode *R_BRACKET();
    ElementTypeContext *elementType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MapTypeContext* mapType();

  class  ChannelTypeContext : public antlr4::ParserRuleContext {
  public:
    ChannelTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementTypeContext *elementType();
    antlr4::tree::TerminalNode *CHAN();
    antlr4::tree::TerminalNode *RECEIVE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChannelTypeContext* channelType();

  class  MethodSpecContext : public antlr4::ParserRuleContext {
  public:
    MethodSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ParametersContext *parameters();
    ResultContext *result();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodSpecContext* methodSpec();

  class  FunctionTypeContext : public antlr4::ParserRuleContext {
  public:
    FunctionTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    SignatureContext *signature();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionTypeContext* functionType();

  class  SignatureContext : public antlr4::ParserRuleContext {
  public:
    SignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParametersContext *parameters();
    ResultContext *result();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignatureContext* signature();

  class  ResultContext : public antlr4::ParserRuleContext {
  public:
    ResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParametersContext *parameters();
    Type_Context *type_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResultContext* result();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<ParameterDeclContext *> parameterDecl();
    ParameterDeclContext* parameterDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  ParameterDeclContext : public antlr4::ParserRuleContext {
  public:
    ParameterDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *ELLIPSIS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDeclContext* parameterDecl();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *unary_op = nullptr;
    antlr4::Token *mul_op = nullptr;
    antlr4::Token *add_op = nullptr;
    antlr4::Token *rel_op = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExprContext *primaryExpr();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *CARET();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *RECEIVE();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *BIT_CLEAR();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *NOT_EQUALS();
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_OR_EQUALS();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *GREATER_OR_EQUALS();
    antlr4::tree::TerminalNode *LOGICAL_AND();
    antlr4::tree::TerminalNode *LOGICAL_OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  PrimaryExprContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperandContext *operand();
    ConversionContext *conversion();
    MethodExprContext *methodExpr();
    PrimaryExprContext *primaryExpr();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    IndexContext *index();
    Slice_Context *slice_();
    TypeAssertionContext *typeAssertion();
    ArgumentsContext *arguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryExprContext* primaryExpr();
  PrimaryExprContext* primaryExpr(int precedence);
  class  ConversionContext : public antlr4::ParserRuleContext {
  public:
    ConversionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *L_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *R_PAREN();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConversionContext* conversion();

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    OperandNameContext *operandName();
    TypeArgsContext *typeArgs();
    antlr4::tree::TerminalNode *L_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *R_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandContext* operand();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BasicLitContext *basicLit();
    CompositeLitContext *compositeLit();
    FunctionLitContext *functionLit();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  BasicLitContext : public antlr4::ParserRuleContext {
  public:
    BasicLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NIL_LIT();
    IntegerContext *integer();
    String_Context *string_();
    antlr4::tree::TerminalNode *FLOAT_LIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicLitContext* basicLit();

  class  IntegerContext : public antlr4::ParserRuleContext {
  public:
    IntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL_LIT();
    antlr4::tree::TerminalNode *BINARY_LIT();
    antlr4::tree::TerminalNode *OCTAL_LIT();
    antlr4::tree::TerminalNode *HEX_LIT();
    antlr4::tree::TerminalNode *IMAGINARY_LIT();
    antlr4::tree::TerminalNode *RUNE_LIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerContext* integer();

  class  OperandNameContext : public antlr4::ParserRuleContext {
  public:
    OperandNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandNameContext* operandName();

  class  QualifiedIdentContext : public antlr4::ParserRuleContext {
  public:
    QualifiedIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedIdentContext* qualifiedIdent();

  class  CompositeLitContext : public antlr4::ParserRuleContext {
  public:
    CompositeLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralTypeContext *literalType();
    LiteralValueContext *literalValue();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeLitContext* compositeLit();

  class  LiteralTypeContext : public antlr4::ParserRuleContext {
  public:
    LiteralTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StructTypeContext *structType();
    ArrayTypeContext *arrayType();
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *ELLIPSIS();
    antlr4::tree::TerminalNode *R_BRACKET();
    ElementTypeContext *elementType();
    SliceTypeContext *sliceType();
    MapTypeContext *mapType();
    TypeNameContext *typeName();
    TypeArgsContext *typeArgs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralTypeContext* literalType();

  class  LiteralValueContext : public antlr4::ParserRuleContext {
  public:
    LiteralValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    ElementListContext *elementList();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralValueContext* literalValue();

  class  ElementListContext : public antlr4::ParserRuleContext {
  public:
    ElementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<KeyedElementContext *> keyedElement();
    KeyedElementContext* keyedElement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementListContext* elementList();

  class  KeyedElementContext : public antlr4::ParserRuleContext {
  public:
    KeyedElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementContext *element();
    KeyContext *key();
    antlr4::tree::TerminalNode *COLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyedElementContext* keyedElement();

  class  KeyContext : public antlr4::ParserRuleContext {
  public:
    KeyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    LiteralValueContext *literalValue();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyContext* key();

  class  ElementContext : public antlr4::ParserRuleContext {
  public:
    ElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    LiteralValueContext *literalValue();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementContext* element();

  class  StructTypeContext : public antlr4::ParserRuleContext {
  public:
    StructTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRUCT();
    antlr4::tree::TerminalNode *L_CURLY();
    antlr4::tree::TerminalNode *R_CURLY();
    std::vector<FieldDeclContext *> fieldDecl();
    FieldDeclContext* fieldDecl(size_t i);
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructTypeContext* structType();

  class  FieldDeclContext : public antlr4::ParserRuleContext {
  public:
    GoParser::String_Context *tag = nullptr;
    FieldDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    Type_Context *type_();
    EmbeddedFieldContext *embeddedField();
    String_Context *string_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldDeclContext* fieldDecl();

  class  String_Context : public antlr4::ParserRuleContext {
  public:
    String_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAW_STRING_LIT();
    antlr4::tree::TerminalNode *INTERPRETED_STRING_LIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  String_Context* string_();

  class  EmbeddedFieldContext : public antlr4::ParserRuleContext {
  public:
    EmbeddedFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *STAR();
    TypeArgsContext *typeArgs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmbeddedFieldContext* embeddedField();

  class  FunctionLitContext : public antlr4::ParserRuleContext {
  public:
    FunctionLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    SignatureContext *signature();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionLitContext* functionLit();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *R_BRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  Slice_Context : public antlr4::ParserRuleContext {
  public:
    Slice_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *R_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Slice_Context* slice_();

  class  TypeAssertionContext : public antlr4::ParserRuleContext {
  public:
    TypeAssertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *L_PAREN();
    Type_Context *type_();
    antlr4::tree::TerminalNode *R_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAssertionContext* typeAssertion();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    ExpressionListContext *expressionList();
    Type_Context *type_();
    antlr4::tree::TerminalNode *ELLIPSIS();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  MethodExprContext : public antlr4::ParserRuleContext {
  public:
    MethodExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodExprContext* methodExpr();

  class  EosContext : public antlr4::ParserRuleContext {
  public:
    EosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *EOS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EosContext* eos();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool statementListSempred(StatementListContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool primaryExprSempred(PrimaryExprContext *_localctx, size_t predicateIndex);
  bool eosSempred(EosContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

