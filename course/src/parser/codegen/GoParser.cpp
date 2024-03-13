#include "GoParserBase.h"

// Generated from GoParser.g4 by ANTLR 4.9


#include "GoParserVisitor.h"

#include "GoParser.h"


using namespace antlrcpp;
using namespace antlr4;

GoParser::GoParser(TokenStream *input) : GoParserBase(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GoParser::~GoParser() {
  delete _interpreter;
}

std::string GoParser::getGrammarFileName() const {
  return "GoParser.g4";
}

const std::vector<std::string>& GoParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GoParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SourceFileContext ------------------------------------------------------------------

GoParser::SourceFileContext::SourceFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::PackageClauseContext* GoParser::SourceFileContext::packageClause() {
  return getRuleContext<GoParser::PackageClauseContext>(0);
}

std::vector<GoParser::EosContext *> GoParser::SourceFileContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::SourceFileContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}

tree::TerminalNode* GoParser::SourceFileContext::EOF() {
  return getToken(GoParser::EOF, 0);
}

std::vector<GoParser::ImportDeclContext *> GoParser::SourceFileContext::importDecl() {
  return getRuleContexts<GoParser::ImportDeclContext>();
}

GoParser::ImportDeclContext* GoParser::SourceFileContext::importDecl(size_t i) {
  return getRuleContext<GoParser::ImportDeclContext>(i);
}

std::vector<GoParser::FunctionDeclContext *> GoParser::SourceFileContext::functionDecl() {
  return getRuleContexts<GoParser::FunctionDeclContext>();
}

GoParser::FunctionDeclContext* GoParser::SourceFileContext::functionDecl(size_t i) {
  return getRuleContext<GoParser::FunctionDeclContext>(i);
}

std::vector<GoParser::MethodDeclContext *> GoParser::SourceFileContext::methodDecl() {
  return getRuleContexts<GoParser::MethodDeclContext>();
}

GoParser::MethodDeclContext* GoParser::SourceFileContext::methodDecl(size_t i) {
  return getRuleContext<GoParser::MethodDeclContext>(i);
}

std::vector<GoParser::DeclarationContext *> GoParser::SourceFileContext::declaration() {
  return getRuleContexts<GoParser::DeclarationContext>();
}

GoParser::DeclarationContext* GoParser::SourceFileContext::declaration(size_t i) {
  return getRuleContext<GoParser::DeclarationContext>(i);
}


size_t GoParser::SourceFileContext::getRuleIndex() const {
  return GoParser::RuleSourceFile;
}


antlrcpp::Any GoParser::SourceFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSourceFile(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SourceFileContext* GoParser::sourceFile() {
  SourceFileContext *_localctx = _tracker.createInstance<SourceFileContext>(_ctx, getState());
  enterRule(_localctx, 0, GoParser::RuleSourceFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    packageClause();
    setState(207);
    eos();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::IMPORT) {
      setState(208);
      importDecl();
      setState(209);
      eos();
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::VAR))) != 0)) {
      setState(219);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(216);
        functionDecl();
        break;
      }

      case 2: {
        setState(217);
        methodDecl();
        break;
      }

      case 3: {
        setState(218);
        declaration();
        break;
      }

      default:
        break;
      }
      setState(221);
      eos();
      setState(227);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(228);
    match(GoParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageClauseContext ------------------------------------------------------------------

GoParser::PackageClauseContext::PackageClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::PackageClauseContext::PACKAGE() {
  return getToken(GoParser::PACKAGE, 0);
}

tree::TerminalNode* GoParser::PackageClauseContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::PackageClauseContext::getRuleIndex() const {
  return GoParser::RulePackageClause;
}


antlrcpp::Any GoParser::PackageClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitPackageClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::PackageClauseContext* GoParser::packageClause() {
  PackageClauseContext *_localctx = _tracker.createInstance<PackageClauseContext>(_ctx, getState());
  enterRule(_localctx, 2, GoParser::RulePackageClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(GoParser::PACKAGE);
    setState(231);
    dynamic_cast<PackageClauseContext *>(_localctx)->packageName = match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclContext ------------------------------------------------------------------

GoParser::ImportDeclContext::ImportDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ImportDeclContext::IMPORT() {
  return getToken(GoParser::IMPORT, 0);
}

std::vector<GoParser::ImportSpecContext *> GoParser::ImportDeclContext::importSpec() {
  return getRuleContexts<GoParser::ImportSpecContext>();
}

GoParser::ImportSpecContext* GoParser::ImportDeclContext::importSpec(size_t i) {
  return getRuleContext<GoParser::ImportSpecContext>(i);
}

tree::TerminalNode* GoParser::ImportDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ImportDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EosContext *> GoParser::ImportDeclContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::ImportDeclContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}


size_t GoParser::ImportDeclContext::getRuleIndex() const {
  return GoParser::RuleImportDecl;
}


antlrcpp::Any GoParser::ImportDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitImportDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ImportDeclContext* GoParser::importDecl() {
  ImportDeclContext *_localctx = _tracker.createInstance<ImportDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, GoParser::RuleImportDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(GoParser::IMPORT);
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER:
      case GoParser::DOT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        setState(234);
        importSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(235);
        match(GoParser::L_PAREN);
        setState(241);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 27) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 27)) & ((1ULL << (GoParser::IDENTIFIER - 27))
          | (1ULL << (GoParser::DOT - 27))
          | (1ULL << (GoParser::RAW_STRING_LIT - 27))
          | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 27)))) != 0)) {
          setState(236);
          importSpec();
          setState(237);
          eos();
          setState(243);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(244);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportSpecContext ------------------------------------------------------------------

GoParser::ImportSpecContext::ImportSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ImportPathContext* GoParser::ImportSpecContext::importPath() {
  return getRuleContext<GoParser::ImportPathContext>(0);
}

tree::TerminalNode* GoParser::ImportSpecContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::ImportSpecContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::ImportSpecContext::getRuleIndex() const {
  return GoParser::RuleImportSpec;
}


antlrcpp::Any GoParser::ImportSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitImportSpec(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ImportSpecContext* GoParser::importSpec() {
  ImportSpecContext *_localctx = _tracker.createInstance<ImportSpecContext>(_ctx, getState());
  enterRule(_localctx, 6, GoParser::RuleImportSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::IDENTIFIER

    || _la == GoParser::DOT) {
      setState(247);
      dynamic_cast<ImportSpecContext *>(_localctx)->alias = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == GoParser::IDENTIFIER

      || _la == GoParser::DOT)) {
        dynamic_cast<ImportSpecContext *>(_localctx)->alias = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(250);
    importPath();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportPathContext ------------------------------------------------------------------

GoParser::ImportPathContext::ImportPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::String_Context* GoParser::ImportPathContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}


size_t GoParser::ImportPathContext::getRuleIndex() const {
  return GoParser::RuleImportPath;
}


antlrcpp::Any GoParser::ImportPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitImportPath(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ImportPathContext* GoParser::importPath() {
  ImportPathContext *_localctx = _tracker.createInstance<ImportPathContext>(_ctx, getState());
  enterRule(_localctx, 8, GoParser::RuleImportPath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    string_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

GoParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ConstDeclContext* GoParser::DeclarationContext::constDecl() {
  return getRuleContext<GoParser::ConstDeclContext>(0);
}

GoParser::TypeDeclContext* GoParser::DeclarationContext::typeDecl() {
  return getRuleContext<GoParser::TypeDeclContext>(0);
}

GoParser::VarDeclContext* GoParser::DeclarationContext::varDecl() {
  return getRuleContext<GoParser::VarDeclContext>(0);
}


size_t GoParser::DeclarationContext::getRuleIndex() const {
  return GoParser::RuleDeclaration;
}


antlrcpp::Any GoParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

GoParser::DeclarationContext* GoParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, GoParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(254);
        constDecl();
        break;
      }

      case GoParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(255);
        typeDecl();
        break;
      }

      case GoParser::VAR: {
        enterOuterAlt(_localctx, 3);
        setState(256);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

GoParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ConstDeclContext::CONST() {
  return getToken(GoParser::CONST, 0);
}

std::vector<GoParser::ConstSpecContext *> GoParser::ConstDeclContext::constSpec() {
  return getRuleContexts<GoParser::ConstSpecContext>();
}

GoParser::ConstSpecContext* GoParser::ConstDeclContext::constSpec(size_t i) {
  return getRuleContext<GoParser::ConstSpecContext>(i);
}

tree::TerminalNode* GoParser::ConstDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ConstDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EosContext *> GoParser::ConstDeclContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::ConstDeclContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}


size_t GoParser::ConstDeclContext::getRuleIndex() const {
  return GoParser::RuleConstDecl;
}


antlrcpp::Any GoParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ConstDeclContext* GoParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, GoParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(GoParser::CONST);
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(260);
        constSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(261);
        match(GoParser::L_PAREN);
        setState(267);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(262);
          constSpec();
          setState(263);
          eos();
          setState(269);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(270);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstSpecContext ------------------------------------------------------------------

GoParser::ConstSpecContext::ConstSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::ConstSpecContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ConstSpecContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::ConstSpecContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

GoParser::Type_Context* GoParser::ConstSpecContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ConstSpecContext::getRuleIndex() const {
  return GoParser::RuleConstSpec;
}


antlrcpp::Any GoParser::ConstSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitConstSpec(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ConstSpecContext* GoParser::constSpec() {
  ConstSpecContext *_localctx = _tracker.createInstance<ConstSpecContext>(_ctx, getState());
  enterRule(_localctx, 14, GoParser::RuleConstSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    identifierList();
    setState(279);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(275);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 3) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 3)) & ((1ULL << (GoParser::FUNC - 3))
        | (1ULL << (GoParser::INTERFACE - 3))
        | (1ULL << (GoParser::MAP - 3))
        | (1ULL << (GoParser::STRUCT - 3))
        | (1ULL << (GoParser::CHAN - 3))
        | (1ULL << (GoParser::IDENTIFIER - 3))
        | (1ULL << (GoParser::L_PAREN - 3))
        | (1ULL << (GoParser::L_BRACKET - 3))
        | (1ULL << (GoParser::STAR - 3))
        | (1ULL << (GoParser::RECEIVE - 3)))) != 0)) {
        setState(274);
        type_();
      }
      setState(277);
      match(GoParser::ASSIGN);
      setState(278);
      expressionList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

GoParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GoParser::IdentifierListContext::IDENTIFIER() {
  return getTokens(GoParser::IDENTIFIER);
}

tree::TerminalNode* GoParser::IdentifierListContext::IDENTIFIER(size_t i) {
  return getToken(GoParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> GoParser::IdentifierListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::IdentifierListContext::getRuleIndex() const {
  return GoParser::RuleIdentifierList;
}


antlrcpp::Any GoParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

GoParser::IdentifierListContext* GoParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 16, GoParser::RuleIdentifierList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(GoParser::IDENTIFIER);
    setState(286);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(282);
        match(GoParser::COMMA);
        setState(283);
        match(GoParser::IDENTIFIER); 
      }
      setState(288);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

GoParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::ExpressionContext *> GoParser::ExpressionListContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ExpressionListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ExpressionListContext::getRuleIndex() const {
  return GoParser::RuleExpressionList;
}


antlrcpp::Any GoParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ExpressionListContext* GoParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 18, GoParser::RuleExpressionList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(289);
    expression(0);
    setState(294);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(290);
        match(GoParser::COMMA);
        setState(291);
        expression(0); 
      }
      setState(296);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

GoParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeDeclContext::TYPE() {
  return getToken(GoParser::TYPE, 0);
}

std::vector<GoParser::TypeSpecContext *> GoParser::TypeDeclContext::typeSpec() {
  return getRuleContexts<GoParser::TypeSpecContext>();
}

GoParser::TypeSpecContext* GoParser::TypeDeclContext::typeSpec(size_t i) {
  return getRuleContext<GoParser::TypeSpecContext>(i);
}

tree::TerminalNode* GoParser::TypeDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EosContext *> GoParser::TypeDeclContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::TypeDeclContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}


size_t GoParser::TypeDeclContext::getRuleIndex() const {
  return GoParser::RuleTypeDecl;
}


antlrcpp::Any GoParser::TypeDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeDeclContext* GoParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, GoParser::RuleTypeDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(GoParser::TYPE);
    setState(309);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(298);
        typeSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(299);
        match(GoParser::L_PAREN);
        setState(305);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(300);
          typeSpec();
          setState(301);
          eos();
          setState(307);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(308);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecContext ------------------------------------------------------------------

GoParser::TypeSpecContext::TypeSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::AliasDeclContext* GoParser::TypeSpecContext::aliasDecl() {
  return getRuleContext<GoParser::AliasDeclContext>(0);
}

GoParser::TypeDefContext* GoParser::TypeSpecContext::typeDef() {
  return getRuleContext<GoParser::TypeDefContext>(0);
}


size_t GoParser::TypeSpecContext::getRuleIndex() const {
  return GoParser::RuleTypeSpec;
}


antlrcpp::Any GoParser::TypeSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeSpec(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeSpecContext* GoParser::typeSpec() {
  TypeSpecContext *_localctx = _tracker.createInstance<TypeSpecContext>(_ctx, getState());
  enterRule(_localctx, 22, GoParser::RuleTypeSpec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(311);
      aliasDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(312);
      typeDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasDeclContext ------------------------------------------------------------------

GoParser::AliasDeclContext::AliasDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::AliasDeclContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

tree::TerminalNode* GoParser::AliasDeclContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::Type_Context* GoParser::AliasDeclContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::AliasDeclContext::getRuleIndex() const {
  return GoParser::RuleAliasDecl;
}


antlrcpp::Any GoParser::AliasDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitAliasDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::AliasDeclContext* GoParser::aliasDecl() {
  AliasDeclContext *_localctx = _tracker.createInstance<AliasDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, GoParser::RuleAliasDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(GoParser::IDENTIFIER);
    setState(316);
    match(GoParser::ASSIGN);
    setState(317);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefContext ------------------------------------------------------------------

GoParser::TypeDefContext::TypeDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeDefContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::Type_Context* GoParser::TypeDefContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

GoParser::TypeParametersContext* GoParser::TypeDefContext::typeParameters() {
  return getRuleContext<GoParser::TypeParametersContext>(0);
}


size_t GoParser::TypeDefContext::getRuleIndex() const {
  return GoParser::RuleTypeDef;
}


antlrcpp::Any GoParser::TypeDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeDef(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeDefContext* GoParser::typeDef() {
  TypeDefContext *_localctx = _tracker.createInstance<TypeDefContext>(_ctx, getState());
  enterRule(_localctx, 26, GoParser::RuleTypeDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(GoParser::IDENTIFIER);
    setState(321);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(320);
      typeParameters();
      break;
    }

    default:
      break;
    }
    setState(323);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParametersContext ------------------------------------------------------------------

GoParser::TypeParametersContext::TypeParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeParametersContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

std::vector<GoParser::TypeParameterDeclContext *> GoParser::TypeParametersContext::typeParameterDecl() {
  return getRuleContexts<GoParser::TypeParameterDeclContext>();
}

GoParser::TypeParameterDeclContext* GoParser::TypeParametersContext::typeParameterDecl(size_t i) {
  return getRuleContext<GoParser::TypeParameterDeclContext>(i);
}

tree::TerminalNode* GoParser::TypeParametersContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

std::vector<tree::TerminalNode *> GoParser::TypeParametersContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::TypeParametersContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::TypeParametersContext::getRuleIndex() const {
  return GoParser::RuleTypeParameters;
}


antlrcpp::Any GoParser::TypeParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeParameters(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeParametersContext* GoParser::typeParameters() {
  TypeParametersContext *_localctx = _tracker.createInstance<TypeParametersContext>(_ctx, getState());
  enterRule(_localctx, 28, GoParser::RuleTypeParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(GoParser::L_BRACKET);
    setState(326);
    typeParameterDecl();
    setState(331);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::COMMA) {
      setState(327);
      match(GoParser::COMMA);
      setState(328);
      typeParameterDecl();
      setState(333);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(334);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParameterDeclContext ------------------------------------------------------------------

GoParser::TypeParameterDeclContext::TypeParameterDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::TypeParameterDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

GoParser::TypeElementContext* GoParser::TypeParameterDeclContext::typeElement() {
  return getRuleContext<GoParser::TypeElementContext>(0);
}


size_t GoParser::TypeParameterDeclContext::getRuleIndex() const {
  return GoParser::RuleTypeParameterDecl;
}


antlrcpp::Any GoParser::TypeParameterDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeParameterDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeParameterDeclContext* GoParser::typeParameterDecl() {
  TypeParameterDeclContext *_localctx = _tracker.createInstance<TypeParameterDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, GoParser::RuleTypeParameterDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    identifierList();
    setState(337);
    typeElement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeElementContext ------------------------------------------------------------------

GoParser::TypeElementContext::TypeElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::TypeTermContext *> GoParser::TypeElementContext::typeTerm() {
  return getRuleContexts<GoParser::TypeTermContext>();
}

GoParser::TypeTermContext* GoParser::TypeElementContext::typeTerm(size_t i) {
  return getRuleContext<GoParser::TypeTermContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::TypeElementContext::OR() {
  return getTokens(GoParser::OR);
}

tree::TerminalNode* GoParser::TypeElementContext::OR(size_t i) {
  return getToken(GoParser::OR, i);
}


size_t GoParser::TypeElementContext::getRuleIndex() const {
  return GoParser::RuleTypeElement;
}


antlrcpp::Any GoParser::TypeElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeElement(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeElementContext* GoParser::typeElement() {
  TypeElementContext *_localctx = _tracker.createInstance<TypeElementContext>(_ctx, getState());
  enterRule(_localctx, 32, GoParser::RuleTypeElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(339);
    typeTerm();
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(340);
        match(GoParser::OR);
        setState(341);
        typeTerm(); 
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeTermContext ------------------------------------------------------------------

GoParser::TypeTermContext::TypeTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::TypeTermContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::TypeTermContext::UNDERLYING() {
  return getToken(GoParser::UNDERLYING, 0);
}


size_t GoParser::TypeTermContext::getRuleIndex() const {
  return GoParser::RuleTypeTerm;
}


antlrcpp::Any GoParser::TypeTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeTerm(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeTermContext* GoParser::typeTerm() {
  TypeTermContext *_localctx = _tracker.createInstance<TypeTermContext>(_ctx, getState());
  enterRule(_localctx, 34, GoParser::RuleTypeTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::UNDERLYING) {
      setState(347);
      match(GoParser::UNDERLYING);
    }
    setState(350);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

GoParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionDeclContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

tree::TerminalNode* GoParser::FunctionDeclContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::SignatureContext* GoParser::FunctionDeclContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::TypeParametersContext* GoParser::FunctionDeclContext::typeParameters() {
  return getRuleContext<GoParser::TypeParametersContext>(0);
}

GoParser::BlockContext* GoParser::FunctionDeclContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::FunctionDeclContext::getRuleIndex() const {
  return GoParser::RuleFunctionDecl;
}


antlrcpp::Any GoParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::FunctionDeclContext* GoParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, GoParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    match(GoParser::FUNC);
    setState(353);
    match(GoParser::IDENTIFIER);
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::L_BRACKET) {
      setState(354);
      typeParameters();
    }
    setState(357);
    signature();
    setState(359);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(358);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclContext ------------------------------------------------------------------

GoParser::MethodDeclContext::MethodDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MethodDeclContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::ReceiverContext* GoParser::MethodDeclContext::receiver() {
  return getRuleContext<GoParser::ReceiverContext>(0);
}

tree::TerminalNode* GoParser::MethodDeclContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::SignatureContext* GoParser::MethodDeclContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::BlockContext* GoParser::MethodDeclContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::MethodDeclContext::getRuleIndex() const {
  return GoParser::RuleMethodDecl;
}


antlrcpp::Any GoParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::MethodDeclContext* GoParser::methodDecl() {
  MethodDeclContext *_localctx = _tracker.createInstance<MethodDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, GoParser::RuleMethodDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(GoParser::FUNC);
    setState(362);
    receiver();
    setState(363);
    match(GoParser::IDENTIFIER);
    setState(364);
    signature();
    setState(366);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(365);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReceiverContext ------------------------------------------------------------------

GoParser::ReceiverContext::ReceiverContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::ReceiverContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}


size_t GoParser::ReceiverContext::getRuleIndex() const {
  return GoParser::RuleReceiver;
}


antlrcpp::Any GoParser::ReceiverContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitReceiver(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ReceiverContext* GoParser::receiver() {
  ReceiverContext *_localctx = _tracker.createInstance<ReceiverContext>(_ctx, getState());
  enterRule(_localctx, 40, GoParser::RuleReceiver);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    parameters();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

GoParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::VarDeclContext::VAR() {
  return getToken(GoParser::VAR, 0);
}

std::vector<GoParser::VarSpecContext *> GoParser::VarDeclContext::varSpec() {
  return getRuleContexts<GoParser::VarSpecContext>();
}

GoParser::VarSpecContext* GoParser::VarDeclContext::varSpec(size_t i) {
  return getRuleContext<GoParser::VarSpecContext>(i);
}

tree::TerminalNode* GoParser::VarDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::VarDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EosContext *> GoParser::VarDeclContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::VarDeclContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}


size_t GoParser::VarDeclContext::getRuleIndex() const {
  return GoParser::RuleVarDecl;
}


antlrcpp::Any GoParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::VarDeclContext* GoParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, GoParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(GoParser::VAR);
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(371);
        varSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(372);
        match(GoParser::L_PAREN);
        setState(378);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(373);
          varSpec();
          setState(374);
          eos();
          setState(380);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(381);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarSpecContext ------------------------------------------------------------------

GoParser::VarSpecContext::VarSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::VarSpecContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

GoParser::Type_Context* GoParser::VarSpecContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::VarSpecContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::VarSpecContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::VarSpecContext::getRuleIndex() const {
  return GoParser::RuleVarSpec;
}


antlrcpp::Any GoParser::VarSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitVarSpec(this);
  else
    return visitor->visitChildren(this);
}

GoParser::VarSpecContext* GoParser::varSpec() {
  VarSpecContext *_localctx = _tracker.createInstance<VarSpecContext>(_ctx, getState());
  enterRule(_localctx, 44, GoParser::RuleVarSpec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    identifierList();
    setState(392);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        setState(385);
        type_();
        setState(388);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(386);
          match(GoParser::ASSIGN);
          setState(387);
          expressionList();
          break;
        }

        default:
          break;
        }
        break;
      }

      case GoParser::ASSIGN: {
        setState(390);
        match(GoParser::ASSIGN);
        setState(391);
        expressionList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

GoParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BlockContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::BlockContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::StatementListContext* GoParser::BlockContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::BlockContext::getRuleIndex() const {
  return GoParser::RuleBlock;
}


antlrcpp::Any GoParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

GoParser::BlockContext* GoParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 46, GoParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(GoParser::L_CURLY);
    setState(396);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(395);
      statementList();
      break;
    }

    default:
      break;
    }
    setState(398);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

GoParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::StatementContext *> GoParser::StatementListContext::statement() {
  return getRuleContexts<GoParser::StatementContext>();
}

GoParser::StatementContext* GoParser::StatementListContext::statement(size_t i) {
  return getRuleContext<GoParser::StatementContext>(i);
}

std::vector<GoParser::EosContext *> GoParser::StatementListContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::StatementListContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::StatementListContext::SEMI() {
  return getTokens(GoParser::SEMI);
}

tree::TerminalNode* GoParser::StatementListContext::SEMI(size_t i) {
  return getToken(GoParser::SEMI, i);
}

std::vector<tree::TerminalNode *> GoParser::StatementListContext::EOS() {
  return getTokens(GoParser::EOS);
}

tree::TerminalNode* GoParser::StatementListContext::EOS(size_t i) {
  return getToken(GoParser::EOS, i);
}


size_t GoParser::StatementListContext::getRuleIndex() const {
  return GoParser::RuleStatementList;
}


antlrcpp::Any GoParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

GoParser::StatementListContext* GoParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 48, GoParser::RuleStatementList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(412); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(407);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
              case 1: {
                setState(401);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == GoParser::SEMI) {
                  setState(400);
                  match(GoParser::SEMI);
                }
                break;
              }

              case 2: {
                setState(404);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == GoParser::EOS) {
                  setState(403);
                  match(GoParser::EOS);
                }
                break;
              }

              case 3: {
                setState(406);

                if (!(this->closingBracket())) throw FailedPredicateException(this, "this->closingBracket()");
                break;
              }

              default:
                break;
              }
              setState(409);
              statement();
              setState(410);
              eos();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(414); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

GoParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::DeclarationContext* GoParser::StatementContext::declaration() {
  return getRuleContext<GoParser::DeclarationContext>(0);
}

GoParser::LabeledStmtContext* GoParser::StatementContext::labeledStmt() {
  return getRuleContext<GoParser::LabeledStmtContext>(0);
}

GoParser::SimpleStmtContext* GoParser::StatementContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

GoParser::GoStmtContext* GoParser::StatementContext::goStmt() {
  return getRuleContext<GoParser::GoStmtContext>(0);
}

GoParser::ReturnStmtContext* GoParser::StatementContext::returnStmt() {
  return getRuleContext<GoParser::ReturnStmtContext>(0);
}

GoParser::BreakStmtContext* GoParser::StatementContext::breakStmt() {
  return getRuleContext<GoParser::BreakStmtContext>(0);
}

GoParser::ContinueStmtContext* GoParser::StatementContext::continueStmt() {
  return getRuleContext<GoParser::ContinueStmtContext>(0);
}

GoParser::GotoStmtContext* GoParser::StatementContext::gotoStmt() {
  return getRuleContext<GoParser::GotoStmtContext>(0);
}

GoParser::FallthroughStmtContext* GoParser::StatementContext::fallthroughStmt() {
  return getRuleContext<GoParser::FallthroughStmtContext>(0);
}

GoParser::BlockContext* GoParser::StatementContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}

GoParser::IfStmtContext* GoParser::StatementContext::ifStmt() {
  return getRuleContext<GoParser::IfStmtContext>(0);
}

GoParser::SwitchStmtContext* GoParser::StatementContext::switchStmt() {
  return getRuleContext<GoParser::SwitchStmtContext>(0);
}

GoParser::SelectStmtContext* GoParser::StatementContext::selectStmt() {
  return getRuleContext<GoParser::SelectStmtContext>(0);
}

GoParser::ForStmtContext* GoParser::StatementContext::forStmt() {
  return getRuleContext<GoParser::ForStmtContext>(0);
}

GoParser::DeferStmtContext* GoParser::StatementContext::deferStmt() {
  return getRuleContext<GoParser::DeferStmtContext>(0);
}


size_t GoParser::StatementContext::getRuleIndex() const {
  return GoParser::RuleStatement;
}


antlrcpp::Any GoParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

GoParser::StatementContext* GoParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 50, GoParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(431);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(416);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(417);
      labeledStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(418);
      simpleStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(419);
      goStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(420);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(421);
      breakStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(422);
      continueStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(423);
      gotoStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(424);
      fallthroughStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(425);
      block();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(426);
      ifStmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(427);
      switchStmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(428);
      selectStmt();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(429);
      forStmt();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(430);
      deferStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStmtContext ------------------------------------------------------------------

GoParser::SimpleStmtContext::SimpleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::SendStmtContext* GoParser::SimpleStmtContext::sendStmt() {
  return getRuleContext<GoParser::SendStmtContext>(0);
}

GoParser::IncDecStmtContext* GoParser::SimpleStmtContext::incDecStmt() {
  return getRuleContext<GoParser::IncDecStmtContext>(0);
}

GoParser::AssignmentContext* GoParser::SimpleStmtContext::assignment() {
  return getRuleContext<GoParser::AssignmentContext>(0);
}

GoParser::ExpressionStmtContext* GoParser::SimpleStmtContext::expressionStmt() {
  return getRuleContext<GoParser::ExpressionStmtContext>(0);
}

GoParser::ShortVarDeclContext* GoParser::SimpleStmtContext::shortVarDecl() {
  return getRuleContext<GoParser::ShortVarDeclContext>(0);
}


size_t GoParser::SimpleStmtContext::getRuleIndex() const {
  return GoParser::RuleSimpleStmt;
}


antlrcpp::Any GoParser::SimpleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSimpleStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SimpleStmtContext* GoParser::simpleStmt() {
  SimpleStmtContext *_localctx = _tracker.createInstance<SimpleStmtContext>(_ctx, getState());
  enterRule(_localctx, 52, GoParser::RuleSimpleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(438);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(433);
      sendStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(434);
      incDecStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(435);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(436);
      expressionStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(437);
      shortVarDecl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStmtContext ------------------------------------------------------------------

GoParser::ExpressionStmtContext::ExpressionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ExpressionStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::ExpressionStmtContext::getRuleIndex() const {
  return GoParser::RuleExpressionStmt;
}


antlrcpp::Any GoParser::ExpressionStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ExpressionStmtContext* GoParser::expressionStmt() {
  ExpressionStmtContext *_localctx = _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
  enterRule(_localctx, 54, GoParser::RuleExpressionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendStmtContext ------------------------------------------------------------------

GoParser::SendStmtContext::SendStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SendStmtContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}

std::vector<GoParser::ExpressionContext *> GoParser::SendStmtContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::SendStmtContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}


size_t GoParser::SendStmtContext::getRuleIndex() const {
  return GoParser::RuleSendStmt;
}


antlrcpp::Any GoParser::SendStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSendStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SendStmtContext* GoParser::sendStmt() {
  SendStmtContext *_localctx = _tracker.createInstance<SendStmtContext>(_ctx, getState());
  enterRule(_localctx, 56, GoParser::RuleSendStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    dynamic_cast<SendStmtContext *>(_localctx)->channel = expression(0);
    setState(443);
    match(GoParser::RECEIVE);
    setState(444);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncDecStmtContext ------------------------------------------------------------------

GoParser::IncDecStmtContext::IncDecStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::IncDecStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::IncDecStmtContext::PLUS_PLUS() {
  return getToken(GoParser::PLUS_PLUS, 0);
}

tree::TerminalNode* GoParser::IncDecStmtContext::MINUS_MINUS() {
  return getToken(GoParser::MINUS_MINUS, 0);
}


size_t GoParser::IncDecStmtContext::getRuleIndex() const {
  return GoParser::RuleIncDecStmt;
}


antlrcpp::Any GoParser::IncDecStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitIncDecStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::IncDecStmtContext* GoParser::incDecStmt() {
  IncDecStmtContext *_localctx = _tracker.createInstance<IncDecStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, GoParser::RuleIncDecStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    expression(0);
    setState(447);
    _la = _input->LA(1);
    if (!(_la == GoParser::PLUS_PLUS

    || _la == GoParser::MINUS_MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

GoParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::ExpressionListContext *> GoParser::AssignmentContext::expressionList() {
  return getRuleContexts<GoParser::ExpressionListContext>();
}

GoParser::ExpressionListContext* GoParser::AssignmentContext::expressionList(size_t i) {
  return getRuleContext<GoParser::ExpressionListContext>(i);
}

GoParser::Assign_opContext* GoParser::AssignmentContext::assign_op() {
  return getRuleContext<GoParser::Assign_opContext>(0);
}


size_t GoParser::AssignmentContext::getRuleIndex() const {
  return GoParser::RuleAssignment;
}


antlrcpp::Any GoParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

GoParser::AssignmentContext* GoParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 60, GoParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(449);
    expressionList();
    setState(450);
    assign_op();
    setState(451);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_opContext ------------------------------------------------------------------

GoParser::Assign_opContext::Assign_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::Assign_opContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::PLUS() {
  return getToken(GoParser::PLUS, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::MINUS() {
  return getToken(GoParser::MINUS, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::OR() {
  return getToken(GoParser::OR, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::CARET() {
  return getToken(GoParser::CARET, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::DIV() {
  return getToken(GoParser::DIV, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::MOD() {
  return getToken(GoParser::MOD, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::LSHIFT() {
  return getToken(GoParser::LSHIFT, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::RSHIFT() {
  return getToken(GoParser::RSHIFT, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::AMPERSAND() {
  return getToken(GoParser::AMPERSAND, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::BIT_CLEAR() {
  return getToken(GoParser::BIT_CLEAR, 0);
}


size_t GoParser::Assign_opContext::getRuleIndex() const {
  return GoParser::RuleAssign_op;
}


antlrcpp::Any GoParser::Assign_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitAssign_op(this);
  else
    return visitor->visitChildren(this);
}

GoParser::Assign_opContext* GoParser::assign_op() {
  Assign_opContext *_localctx = _tracker.createInstance<Assign_opContext>(_ctx, getState());
  enterRule(_localctx, 62, GoParser::RuleAssign_op);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::OR)
      | (1ULL << GoParser::DIV)
      | (1ULL << GoParser::MOD)
      | (1ULL << GoParser::LSHIFT)
      | (1ULL << GoParser::RSHIFT)
      | (1ULL << GoParser::BIT_CLEAR)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET)
      | (1ULL << GoParser::STAR)
      | (1ULL << GoParser::AMPERSAND))) != 0)) {
      setState(453);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::OR)
        | (1ULL << GoParser::DIV)
        | (1ULL << GoParser::MOD)
        | (1ULL << GoParser::LSHIFT)
        | (1ULL << GoParser::RSHIFT)
        | (1ULL << GoParser::BIT_CLEAR)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(456);
    match(GoParser::ASSIGN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShortVarDeclContext ------------------------------------------------------------------

GoParser::ShortVarDeclContext::ShortVarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::ShortVarDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ShortVarDeclContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::ShortVarDeclContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::ShortVarDeclContext::getRuleIndex() const {
  return GoParser::RuleShortVarDecl;
}


antlrcpp::Any GoParser::ShortVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitShortVarDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ShortVarDeclContext* GoParser::shortVarDecl() {
  ShortVarDeclContext *_localctx = _tracker.createInstance<ShortVarDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, GoParser::RuleShortVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    identifierList();
    setState(459);
    match(GoParser::DECLARE_ASSIGN);
    setState(460);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStmtContext ------------------------------------------------------------------

GoParser::LabeledStmtContext::LabeledStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::LabeledStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

tree::TerminalNode* GoParser::LabeledStmtContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementContext* GoParser::LabeledStmtContext::statement() {
  return getRuleContext<GoParser::StatementContext>(0);
}


size_t GoParser::LabeledStmtContext::getRuleIndex() const {
  return GoParser::RuleLabeledStmt;
}


antlrcpp::Any GoParser::LabeledStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitLabeledStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::LabeledStmtContext* GoParser::labeledStmt() {
  LabeledStmtContext *_localctx = _tracker.createInstance<LabeledStmtContext>(_ctx, getState());
  enterRule(_localctx, 66, GoParser::RuleLabeledStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    match(GoParser::IDENTIFIER);
    setState(463);
    match(GoParser::COLON);
    setState(465);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(464);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

GoParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ReturnStmtContext::RETURN() {
  return getToken(GoParser::RETURN, 0);
}

GoParser::ExpressionListContext* GoParser::ReturnStmtContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::ReturnStmtContext::getRuleIndex() const {
  return GoParser::RuleReturnStmt;
}


antlrcpp::Any GoParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ReturnStmtContext* GoParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 68, GoParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(GoParser::RETURN);
    setState(469);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(468);
      expressionList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStmtContext ------------------------------------------------------------------

GoParser::BreakStmtContext::BreakStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BreakStmtContext::BREAK() {
  return getToken(GoParser::BREAK, 0);
}

tree::TerminalNode* GoParser::BreakStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::BreakStmtContext::getRuleIndex() const {
  return GoParser::RuleBreakStmt;
}


antlrcpp::Any GoParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::BreakStmtContext* GoParser::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 70, GoParser::RuleBreakStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    match(GoParser::BREAK);
    setState(473);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(472);
      match(GoParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

GoParser::ContinueStmtContext::ContinueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ContinueStmtContext::CONTINUE() {
  return getToken(GoParser::CONTINUE, 0);
}

tree::TerminalNode* GoParser::ContinueStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::ContinueStmtContext::getRuleIndex() const {
  return GoParser::RuleContinueStmt;
}


antlrcpp::Any GoParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ContinueStmtContext* GoParser::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 72, GoParser::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    match(GoParser::CONTINUE);
    setState(477);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(476);
      match(GoParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoStmtContext ------------------------------------------------------------------

GoParser::GotoStmtContext::GotoStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::GotoStmtContext::GOTO() {
  return getToken(GoParser::GOTO, 0);
}

tree::TerminalNode* GoParser::GotoStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::GotoStmtContext::getRuleIndex() const {
  return GoParser::RuleGotoStmt;
}


antlrcpp::Any GoParser::GotoStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitGotoStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::GotoStmtContext* GoParser::gotoStmt() {
  GotoStmtContext *_localctx = _tracker.createInstance<GotoStmtContext>(_ctx, getState());
  enterRule(_localctx, 74, GoParser::RuleGotoStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(GoParser::GOTO);
    setState(480);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FallthroughStmtContext ------------------------------------------------------------------

GoParser::FallthroughStmtContext::FallthroughStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FallthroughStmtContext::FALLTHROUGH() {
  return getToken(GoParser::FALLTHROUGH, 0);
}


size_t GoParser::FallthroughStmtContext::getRuleIndex() const {
  return GoParser::RuleFallthroughStmt;
}


antlrcpp::Any GoParser::FallthroughStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitFallthroughStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::FallthroughStmtContext* GoParser::fallthroughStmt() {
  FallthroughStmtContext *_localctx = _tracker.createInstance<FallthroughStmtContext>(_ctx, getState());
  enterRule(_localctx, 76, GoParser::RuleFallthroughStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    match(GoParser::FALLTHROUGH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeferStmtContext ------------------------------------------------------------------

GoParser::DeferStmtContext::DeferStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::DeferStmtContext::DEFER() {
  return getToken(GoParser::DEFER, 0);
}

GoParser::ExpressionContext* GoParser::DeferStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::DeferStmtContext::getRuleIndex() const {
  return GoParser::RuleDeferStmt;
}


antlrcpp::Any GoParser::DeferStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitDeferStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::DeferStmtContext* GoParser::deferStmt() {
  DeferStmtContext *_localctx = _tracker.createInstance<DeferStmtContext>(_ctx, getState());
  enterRule(_localctx, 78, GoParser::RuleDeferStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(GoParser::DEFER);
    setState(485);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

GoParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IfStmtContext::IF() {
  return getToken(GoParser::IF, 0);
}

std::vector<GoParser::BlockContext *> GoParser::IfStmtContext::block() {
  return getRuleContexts<GoParser::BlockContext>();
}

GoParser::BlockContext* GoParser::IfStmtContext::block(size_t i) {
  return getRuleContext<GoParser::BlockContext>(i);
}

GoParser::ExpressionContext* GoParser::IfStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::EosContext* GoParser::IfStmtContext::eos() {
  return getRuleContext<GoParser::EosContext>(0);
}

GoParser::SimpleStmtContext* GoParser::IfStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

tree::TerminalNode* GoParser::IfStmtContext::ELSE() {
  return getToken(GoParser::ELSE, 0);
}

GoParser::IfStmtContext* GoParser::IfStmtContext::ifStmt() {
  return getRuleContext<GoParser::IfStmtContext>(0);
}


size_t GoParser::IfStmtContext::getRuleIndex() const {
  return GoParser::RuleIfStmt;
}


antlrcpp::Any GoParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::IfStmtContext* GoParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 80, GoParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(GoParser::IF);
    setState(496);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(488);
      expression(0);
      break;
    }

    case 2: {
      setState(489);
      eos();
      setState(490);
      expression(0);
      break;
    }

    case 3: {
      setState(492);
      simpleStmt();
      setState(493);
      eos();
      setState(494);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(498);
    block();
    setState(504);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(499);
      match(GoParser::ELSE);
      setState(502);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case GoParser::IF: {
          setState(500);
          ifStmt();
          break;
        }

        case GoParser::L_CURLY: {
          setState(501);
          block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtContext ------------------------------------------------------------------

GoParser::SwitchStmtContext::SwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExprSwitchStmtContext* GoParser::SwitchStmtContext::exprSwitchStmt() {
  return getRuleContext<GoParser::ExprSwitchStmtContext>(0);
}

GoParser::TypeSwitchStmtContext* GoParser::SwitchStmtContext::typeSwitchStmt() {
  return getRuleContext<GoParser::TypeSwitchStmtContext>(0);
}


size_t GoParser::SwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleSwitchStmt;
}


antlrcpp::Any GoParser::SwitchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SwitchStmtContext* GoParser::switchStmt() {
  SwitchStmtContext *_localctx = _tracker.createInstance<SwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 82, GoParser::RuleSwitchStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(508);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(506);
      exprSwitchStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(507);
      typeSwitchStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprSwitchStmtContext ------------------------------------------------------------------

GoParser::ExprSwitchStmtContext::ExprSwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::SWITCH() {
  return getToken(GoParser::SWITCH, 0);
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::EosContext* GoParser::ExprSwitchStmtContext::eos() {
  return getRuleContext<GoParser::EosContext>(0);
}

std::vector<GoParser::ExprCaseClauseContext *> GoParser::ExprSwitchStmtContext::exprCaseClause() {
  return getRuleContexts<GoParser::ExprCaseClauseContext>();
}

GoParser::ExprCaseClauseContext* GoParser::ExprSwitchStmtContext::exprCaseClause(size_t i) {
  return getRuleContext<GoParser::ExprCaseClauseContext>(i);
}

GoParser::ExpressionContext* GoParser::ExprSwitchStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::SimpleStmtContext* GoParser::ExprSwitchStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}


size_t GoParser::ExprSwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleExprSwitchStmt;
}


antlrcpp::Any GoParser::ExprSwitchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExprSwitchStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ExprSwitchStmtContext* GoParser::exprSwitchStmt() {
  ExprSwitchStmtContext *_localctx = _tracker.createInstance<ExprSwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 84, GoParser::RuleExprSwitchStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    match(GoParser::SWITCH);
    setState(521);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(512);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(511);
        expression(0);
      }
      break;
    }

    case 2: {
      setState(515);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
      case 1: {
        setState(514);
        simpleStmt();
        break;
      }

      default:
        break;
      }
      setState(517);
      eos();
      setState(519);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(518);
        expression(0);
      }
      break;
    }

    default:
      break;
    }
    setState(523);
    match(GoParser::L_CURLY);
    setState(527);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(524);
      exprCaseClause();
      setState(529);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(530);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprCaseClauseContext ------------------------------------------------------------------

GoParser::ExprCaseClauseContext::ExprCaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExprSwitchCaseContext* GoParser::ExprCaseClauseContext::exprSwitchCase() {
  return getRuleContext<GoParser::ExprSwitchCaseContext>(0);
}

tree::TerminalNode* GoParser::ExprCaseClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::ExprCaseClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::ExprCaseClauseContext::getRuleIndex() const {
  return GoParser::RuleExprCaseClause;
}


antlrcpp::Any GoParser::ExprCaseClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExprCaseClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ExprCaseClauseContext* GoParser::exprCaseClause() {
  ExprCaseClauseContext *_localctx = _tracker.createInstance<ExprCaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 86, GoParser::RuleExprCaseClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    exprSwitchCase();
    setState(533);
    match(GoParser::COLON);
    setState(535);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      setState(534);
      statementList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprSwitchCaseContext ------------------------------------------------------------------

GoParser::ExprSwitchCaseContext::ExprSwitchCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ExprSwitchCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::ExpressionListContext* GoParser::ExprSwitchCaseContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::ExprSwitchCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::ExprSwitchCaseContext::getRuleIndex() const {
  return GoParser::RuleExprSwitchCase;
}


antlrcpp::Any GoParser::ExprSwitchCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExprSwitchCase(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ExprSwitchCaseContext* GoParser::exprSwitchCase() {
  ExprSwitchCaseContext *_localctx = _tracker.createInstance<ExprSwitchCaseContext>(_ctx, getState());
  enterRule(_localctx, 88, GoParser::RuleExprSwitchCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(537);
        match(GoParser::CASE);
        setState(538);
        expressionList();
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(539);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchStmtContext ------------------------------------------------------------------

GoParser::TypeSwitchStmtContext::TypeSwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::SWITCH() {
  return getToken(GoParser::SWITCH, 0);
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::TypeSwitchGuardContext* GoParser::TypeSwitchStmtContext::typeSwitchGuard() {
  return getRuleContext<GoParser::TypeSwitchGuardContext>(0);
}

GoParser::EosContext* GoParser::TypeSwitchStmtContext::eos() {
  return getRuleContext<GoParser::EosContext>(0);
}

GoParser::SimpleStmtContext* GoParser::TypeSwitchStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

std::vector<GoParser::TypeCaseClauseContext *> GoParser::TypeSwitchStmtContext::typeCaseClause() {
  return getRuleContexts<GoParser::TypeCaseClauseContext>();
}

GoParser::TypeCaseClauseContext* GoParser::TypeSwitchStmtContext::typeCaseClause(size_t i) {
  return getRuleContext<GoParser::TypeCaseClauseContext>(i);
}


size_t GoParser::TypeSwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchStmt;
}


antlrcpp::Any GoParser::TypeSwitchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeSwitchStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeSwitchStmtContext* GoParser::typeSwitchStmt() {
  TypeSwitchStmtContext *_localctx = _tracker.createInstance<TypeSwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 90, GoParser::RuleTypeSwitchStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    match(GoParser::SWITCH);
    setState(551);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      setState(543);
      typeSwitchGuard();
      break;
    }

    case 2: {
      setState(544);
      eos();
      setState(545);
      typeSwitchGuard();
      break;
    }

    case 3: {
      setState(547);
      simpleStmt();
      setState(548);
      eos();
      setState(549);
      typeSwitchGuard();
      break;
    }

    default:
      break;
    }
    setState(553);
    match(GoParser::L_CURLY);
    setState(557);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(554);
      typeCaseClause();
      setState(559);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(560);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchGuardContext ------------------------------------------------------------------

GoParser::TypeSwitchGuardContext::TypeSwitchGuardContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::PrimaryExprContext* GoParser::TypeSwitchGuardContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::TYPE() {
  return getToken(GoParser::TYPE, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::TypeSwitchGuardContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchGuard;
}


antlrcpp::Any GoParser::TypeSwitchGuardContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeSwitchGuard(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeSwitchGuardContext* GoParser::typeSwitchGuard() {
  TypeSwitchGuardContext *_localctx = _tracker.createInstance<TypeSwitchGuardContext>(_ctx, getState());
  enterRule(_localctx, 92, GoParser::RuleTypeSwitchGuard);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(562);
      match(GoParser::IDENTIFIER);
      setState(563);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(566);
    primaryExpr(0);
    setState(567);
    match(GoParser::DOT);
    setState(568);
    match(GoParser::L_PAREN);
    setState(569);
    match(GoParser::TYPE);
    setState(570);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeCaseClauseContext ------------------------------------------------------------------

GoParser::TypeCaseClauseContext::TypeCaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeSwitchCaseContext* GoParser::TypeCaseClauseContext::typeSwitchCase() {
  return getRuleContext<GoParser::TypeSwitchCaseContext>(0);
}

tree::TerminalNode* GoParser::TypeCaseClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::TypeCaseClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::TypeCaseClauseContext::getRuleIndex() const {
  return GoParser::RuleTypeCaseClause;
}


antlrcpp::Any GoParser::TypeCaseClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeCaseClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeCaseClauseContext* GoParser::typeCaseClause() {
  TypeCaseClauseContext *_localctx = _tracker.createInstance<TypeCaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 94, GoParser::RuleTypeCaseClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    typeSwitchCase();
    setState(573);
    match(GoParser::COLON);
    setState(575);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(574);
      statementList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchCaseContext ------------------------------------------------------------------

GoParser::TypeSwitchCaseContext::TypeSwitchCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeSwitchCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::TypeListContext* GoParser::TypeSwitchCaseContext::typeList() {
  return getRuleContext<GoParser::TypeListContext>(0);
}

tree::TerminalNode* GoParser::TypeSwitchCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::TypeSwitchCaseContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchCase;
}


antlrcpp::Any GoParser::TypeSwitchCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeSwitchCase(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeSwitchCaseContext* GoParser::typeSwitchCase() {
  TypeSwitchCaseContext *_localctx = _tracker.createInstance<TypeSwitchCaseContext>(_ctx, getState());
  enterRule(_localctx, 96, GoParser::RuleTypeSwitchCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(580);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(577);
        match(GoParser::CASE);
        setState(578);
        typeList();
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(579);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

GoParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::Type_Context *> GoParser::TypeListContext::type_() {
  return getRuleContexts<GoParser::Type_Context>();
}

GoParser::Type_Context* GoParser::TypeListContext::type_(size_t i) {
  return getRuleContext<GoParser::Type_Context>(i);
}

std::vector<tree::TerminalNode *> GoParser::TypeListContext::NIL_LIT() {
  return getTokens(GoParser::NIL_LIT);
}

tree::TerminalNode* GoParser::TypeListContext::NIL_LIT(size_t i) {
  return getToken(GoParser::NIL_LIT, i);
}

std::vector<tree::TerminalNode *> GoParser::TypeListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::TypeListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::TypeListContext::getRuleIndex() const {
  return GoParser::RuleTypeList;
}


antlrcpp::Any GoParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeListContext* GoParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 98, GoParser::RuleTypeList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(584);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        setState(582);
        type_();
        break;
      }

      case GoParser::NIL_LIT: {
        setState(583);
        match(GoParser::NIL_LIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(593);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(586);
        match(GoParser::COMMA);
        setState(589);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case GoParser::FUNC:
          case GoParser::INTERFACE:
          case GoParser::MAP:
          case GoParser::STRUCT:
          case GoParser::CHAN:
          case GoParser::IDENTIFIER:
          case GoParser::L_PAREN:
          case GoParser::L_BRACKET:
          case GoParser::STAR:
          case GoParser::RECEIVE: {
            setState(587);
            type_();
            break;
          }

          case GoParser::NIL_LIT: {
            setState(588);
            match(GoParser::NIL_LIT);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(595);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectStmtContext ------------------------------------------------------------------

GoParser::SelectStmtContext::SelectStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SelectStmtContext::SELECT() {
  return getToken(GoParser::SELECT, 0);
}

tree::TerminalNode* GoParser::SelectStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::SelectStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::CommClauseContext *> GoParser::SelectStmtContext::commClause() {
  return getRuleContexts<GoParser::CommClauseContext>();
}

GoParser::CommClauseContext* GoParser::SelectStmtContext::commClause(size_t i) {
  return getRuleContext<GoParser::CommClauseContext>(i);
}


size_t GoParser::SelectStmtContext::getRuleIndex() const {
  return GoParser::RuleSelectStmt;
}


antlrcpp::Any GoParser::SelectStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSelectStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SelectStmtContext* GoParser::selectStmt() {
  SelectStmtContext *_localctx = _tracker.createInstance<SelectStmtContext>(_ctx, getState());
  enterRule(_localctx, 100, GoParser::RuleSelectStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(596);
    match(GoParser::SELECT);
    setState(597);
    match(GoParser::L_CURLY);
    setState(601);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(598);
      commClause();
      setState(603);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(604);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommClauseContext ------------------------------------------------------------------

GoParser::CommClauseContext::CommClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::CommCaseContext* GoParser::CommClauseContext::commCase() {
  return getRuleContext<GoParser::CommCaseContext>(0);
}

tree::TerminalNode* GoParser::CommClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::CommClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::CommClauseContext::getRuleIndex() const {
  return GoParser::RuleCommClause;
}


antlrcpp::Any GoParser::CommClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitCommClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::CommClauseContext* GoParser::commClause() {
  CommClauseContext *_localctx = _tracker.createInstance<CommClauseContext>(_ctx, getState());
  enterRule(_localctx, 102, GoParser::RuleCommClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(606);
    commCase();
    setState(607);
    match(GoParser::COLON);
    setState(609);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(608);
      statementList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommCaseContext ------------------------------------------------------------------

GoParser::CommCaseContext::CommCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::CommCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::SendStmtContext* GoParser::CommCaseContext::sendStmt() {
  return getRuleContext<GoParser::SendStmtContext>(0);
}

GoParser::RecvStmtContext* GoParser::CommCaseContext::recvStmt() {
  return getRuleContext<GoParser::RecvStmtContext>(0);
}

tree::TerminalNode* GoParser::CommCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::CommCaseContext::getRuleIndex() const {
  return GoParser::RuleCommCase;
}


antlrcpp::Any GoParser::CommCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitCommCase(this);
  else
    return visitor->visitChildren(this);
}

GoParser::CommCaseContext* GoParser::commCase() {
  CommCaseContext *_localctx = _tracker.createInstance<CommCaseContext>(_ctx, getState());
  enterRule(_localctx, 104, GoParser::RuleCommCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(611);
        match(GoParser::CASE);
        setState(614);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
        case 1: {
          setState(612);
          sendStmt();
          break;
        }

        case 2: {
          setState(613);
          recvStmt();
          break;
        }

        default:
          break;
        }
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(616);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecvStmtContext ------------------------------------------------------------------

GoParser::RecvStmtContext::RecvStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::RecvStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::ExpressionListContext* GoParser::RecvStmtContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::RecvStmtContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::IdentifierListContext* GoParser::RecvStmtContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::RecvStmtContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::RecvStmtContext::getRuleIndex() const {
  return GoParser::RuleRecvStmt;
}


antlrcpp::Any GoParser::RecvStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitRecvStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::RecvStmtContext* GoParser::recvStmt() {
  RecvStmtContext *_localctx = _tracker.createInstance<RecvStmtContext>(_ctx, getState());
  enterRule(_localctx, 106, GoParser::RuleRecvStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      setState(619);
      expressionList();
      setState(620);
      match(GoParser::ASSIGN);
      break;
    }

    case 2: {
      setState(622);
      identifierList();
      setState(623);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(627);
    dynamic_cast<RecvStmtContext *>(_localctx)->recvExpr = expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

GoParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ForStmtContext::FOR() {
  return getToken(GoParser::FOR, 0);
}

GoParser::BlockContext* GoParser::ForStmtContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}

GoParser::ForClauseContext* GoParser::ForStmtContext::forClause() {
  return getRuleContext<GoParser::ForClauseContext>(0);
}

GoParser::ExpressionContext* GoParser::ForStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::RangeClauseContext* GoParser::ForStmtContext::rangeClause() {
  return getRuleContext<GoParser::RangeClauseContext>(0);
}


size_t GoParser::ForStmtContext::getRuleIndex() const {
  return GoParser::RuleForStmt;
}


antlrcpp::Any GoParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ForStmtContext* GoParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 108, GoParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    match(GoParser::FOR);
    setState(637);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      setState(631);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(630);
        expression(0);
      }
      break;
    }

    case 2: {
      setState(633);
      forClause();
      break;
    }

    case 3: {
      setState(635);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::RANGE)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(634);
        rangeClause();
      }
      break;
    }

    default:
      break;
    }
    setState(639);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForClauseContext ------------------------------------------------------------------

GoParser::ForClauseContext::ForClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::EosContext *> GoParser::ForClauseContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::ForClauseContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}

GoParser::ExpressionContext* GoParser::ForClauseContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

std::vector<GoParser::SimpleStmtContext *> GoParser::ForClauseContext::simpleStmt() {
  return getRuleContexts<GoParser::SimpleStmtContext>();
}

GoParser::SimpleStmtContext* GoParser::ForClauseContext::simpleStmt(size_t i) {
  return getRuleContext<GoParser::SimpleStmtContext>(i);
}


size_t GoParser::ForClauseContext::getRuleIndex() const {
  return GoParser::RuleForClause;
}


antlrcpp::Any GoParser::ForClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitForClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ForClauseContext* GoParser::forClause() {
  ForClauseContext *_localctx = _tracker.createInstance<ForClauseContext>(_ctx, getState());
  enterRule(_localctx, 110, GoParser::RuleForClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(641);
      dynamic_cast<ForClauseContext *>(_localctx)->initStmt = simpleStmt();
      break;
    }

    default:
      break;
    }
    setState(644);
    eos();
    setState(646);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(645);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(648);
    eos();
    setState(650);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET)
      | (1ULL << GoParser::STAR)
      | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(649);
      dynamic_cast<ForClauseContext *>(_localctx)->postStmt = simpleStmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeClauseContext ------------------------------------------------------------------

GoParser::RangeClauseContext::RangeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::RangeClauseContext::RANGE() {
  return getToken(GoParser::RANGE, 0);
}

GoParser::ExpressionContext* GoParser::RangeClauseContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::ExpressionListContext* GoParser::RangeClauseContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::RangeClauseContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::IdentifierListContext* GoParser::RangeClauseContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::RangeClauseContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::RangeClauseContext::getRuleIndex() const {
  return GoParser::RuleRangeClause;
}


antlrcpp::Any GoParser::RangeClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitRangeClause(this);
  else
    return visitor->visitChildren(this);
}

GoParser::RangeClauseContext* GoParser::rangeClause() {
  RangeClauseContext *_localctx = _tracker.createInstance<RangeClauseContext>(_ctx, getState());
  enterRule(_localctx, 112, GoParser::RuleRangeClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(658);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(652);
      expressionList();
      setState(653);
      match(GoParser::ASSIGN);
      break;
    }

    case 2: {
      setState(655);
      identifierList();
      setState(656);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(660);
    match(GoParser::RANGE);
    setState(661);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoStmtContext ------------------------------------------------------------------

GoParser::GoStmtContext::GoStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::GoStmtContext::GO() {
  return getToken(GoParser::GO, 0);
}

GoParser::ExpressionContext* GoParser::GoStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::GoStmtContext::getRuleIndex() const {
  return GoParser::RuleGoStmt;
}


antlrcpp::Any GoParser::GoStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitGoStmt(this);
  else
    return visitor->visitChildren(this);
}

GoParser::GoStmtContext* GoParser::goStmt() {
  GoStmtContext *_localctx = _tracker.createInstance<GoStmtContext>(_ctx, getState());
  enterRule(_localctx, 114, GoParser::RuleGoStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(663);
    match(GoParser::GO);
    setState(664);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

GoParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeNameContext* GoParser::Type_Context::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}

GoParser::TypeArgsContext* GoParser::Type_Context::typeArgs() {
  return getRuleContext<GoParser::TypeArgsContext>(0);
}

GoParser::TypeLitContext* GoParser::Type_Context::typeLit() {
  return getRuleContext<GoParser::TypeLitContext>(0);
}

tree::TerminalNode* GoParser::Type_Context::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::Type_Context* GoParser::Type_Context::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::Type_Context::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::Type_Context::getRuleIndex() const {
  return GoParser::RuleType_;
}


antlrcpp::Any GoParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

GoParser::Type_Context* GoParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 116, GoParser::RuleType_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(675);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(666);
        typeName();
        setState(668);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
        case 1: {
          setState(667);
          typeArgs();
          break;
        }

        default:
          break;
        }
        break;
      }

      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        enterOuterAlt(_localctx, 2);
        setState(670);
        typeLit();
        break;
      }

      case GoParser::L_PAREN: {
        enterOuterAlt(_localctx, 3);
        setState(671);
        match(GoParser::L_PAREN);
        setState(672);
        type_();
        setState(673);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgsContext ------------------------------------------------------------------

GoParser::TypeArgsContext::TypeArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeArgsContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::TypeListContext* GoParser::TypeArgsContext::typeList() {
  return getRuleContext<GoParser::TypeListContext>(0);
}

tree::TerminalNode* GoParser::TypeArgsContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

tree::TerminalNode* GoParser::TypeArgsContext::COMMA() {
  return getToken(GoParser::COMMA, 0);
}


size_t GoParser::TypeArgsContext::getRuleIndex() const {
  return GoParser::RuleTypeArgs;
}


antlrcpp::Any GoParser::TypeArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeArgs(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeArgsContext* GoParser::typeArgs() {
  TypeArgsContext *_localctx = _tracker.createInstance<TypeArgsContext>(_ctx, getState());
  enterRule(_localctx, 118, GoParser::RuleTypeArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(677);
    match(GoParser::L_BRACKET);
    setState(678);
    typeList();
    setState(680);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::COMMA) {
      setState(679);
      match(GoParser::COMMA);
    }
    setState(682);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

GoParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::QualifiedIdentContext* GoParser::TypeNameContext::qualifiedIdent() {
  return getRuleContext<GoParser::QualifiedIdentContext>(0);
}

tree::TerminalNode* GoParser::TypeNameContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::TypeNameContext::getRuleIndex() const {
  return GoParser::RuleTypeName;
}


antlrcpp::Any GoParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeNameContext* GoParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 120, GoParser::RuleTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(686);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(684);
      qualifiedIdent();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(685);
      match(GoParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeLitContext ------------------------------------------------------------------

GoParser::TypeLitContext::TypeLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ArrayTypeContext* GoParser::TypeLitContext::arrayType() {
  return getRuleContext<GoParser::ArrayTypeContext>(0);
}

GoParser::StructTypeContext* GoParser::TypeLitContext::structType() {
  return getRuleContext<GoParser::StructTypeContext>(0);
}

GoParser::PointerTypeContext* GoParser::TypeLitContext::pointerType() {
  return getRuleContext<GoParser::PointerTypeContext>(0);
}

GoParser::FunctionTypeContext* GoParser::TypeLitContext::functionType() {
  return getRuleContext<GoParser::FunctionTypeContext>(0);
}

GoParser::InterfaceTypeContext* GoParser::TypeLitContext::interfaceType() {
  return getRuleContext<GoParser::InterfaceTypeContext>(0);
}

GoParser::SliceTypeContext* GoParser::TypeLitContext::sliceType() {
  return getRuleContext<GoParser::SliceTypeContext>(0);
}

GoParser::MapTypeContext* GoParser::TypeLitContext::mapType() {
  return getRuleContext<GoParser::MapTypeContext>(0);
}

GoParser::ChannelTypeContext* GoParser::TypeLitContext::channelType() {
  return getRuleContext<GoParser::ChannelTypeContext>(0);
}


size_t GoParser::TypeLitContext::getRuleIndex() const {
  return GoParser::RuleTypeLit;
}


antlrcpp::Any GoParser::TypeLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeLit(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeLitContext* GoParser::typeLit() {
  TypeLitContext *_localctx = _tracker.createInstance<TypeLitContext>(_ctx, getState());
  enterRule(_localctx, 122, GoParser::RuleTypeLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(696);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(688);
      arrayType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(689);
      structType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(690);
      pointerType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(691);
      functionType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(692);
      interfaceType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(693);
      sliceType();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(694);
      mapType();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(695);
      channelType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

GoParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ArrayTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::ArrayLengthContext* GoParser::ArrayTypeContext::arrayLength() {
  return getRuleContext<GoParser::ArrayLengthContext>(0);
}

tree::TerminalNode* GoParser::ArrayTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::ArrayTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::ArrayTypeContext::getRuleIndex() const {
  return GoParser::RuleArrayType;
}


antlrcpp::Any GoParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ArrayTypeContext* GoParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 124, GoParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(698);
    match(GoParser::L_BRACKET);
    setState(699);
    arrayLength();
    setState(700);
    match(GoParser::R_BRACKET);
    setState(701);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLengthContext ------------------------------------------------------------------

GoParser::ArrayLengthContext::ArrayLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ArrayLengthContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::ArrayLengthContext::getRuleIndex() const {
  return GoParser::RuleArrayLength;
}


antlrcpp::Any GoParser::ArrayLengthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitArrayLength(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ArrayLengthContext* GoParser::arrayLength() {
  ArrayLengthContext *_localctx = _tracker.createInstance<ArrayLengthContext>(_ctx, getState());
  enterRule(_localctx, 126, GoParser::RuleArrayLength);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementTypeContext ------------------------------------------------------------------

GoParser::ElementTypeContext::ElementTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ElementTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ElementTypeContext::getRuleIndex() const {
  return GoParser::RuleElementType;
}


antlrcpp::Any GoParser::ElementTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitElementType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ElementTypeContext* GoParser::elementType() {
  ElementTypeContext *_localctx = _tracker.createInstance<ElementTypeContext>(_ctx, getState());
  enterRule(_localctx, 128, GoParser::RuleElementType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(705);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerTypeContext ------------------------------------------------------------------

GoParser::PointerTypeContext::PointerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::PointerTypeContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

GoParser::Type_Context* GoParser::PointerTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::PointerTypeContext::getRuleIndex() const {
  return GoParser::RulePointerType;
}


antlrcpp::Any GoParser::PointerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitPointerType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::PointerTypeContext* GoParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 130, GoParser::RulePointerType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(GoParser::STAR);
    setState(708);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceTypeContext ------------------------------------------------------------------

GoParser::InterfaceTypeContext::InterfaceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::InterfaceTypeContext::INTERFACE() {
  return getToken(GoParser::INTERFACE, 0);
}

tree::TerminalNode* GoParser::InterfaceTypeContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::InterfaceTypeContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::EosContext *> GoParser::InterfaceTypeContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::InterfaceTypeContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}

std::vector<GoParser::MethodSpecContext *> GoParser::InterfaceTypeContext::methodSpec() {
  return getRuleContexts<GoParser::MethodSpecContext>();
}

GoParser::MethodSpecContext* GoParser::InterfaceTypeContext::methodSpec(size_t i) {
  return getRuleContext<GoParser::MethodSpecContext>(i);
}

std::vector<GoParser::TypeElementContext *> GoParser::InterfaceTypeContext::typeElement() {
  return getRuleContexts<GoParser::TypeElementContext>();
}

GoParser::TypeElementContext* GoParser::InterfaceTypeContext::typeElement(size_t i) {
  return getRuleContext<GoParser::TypeElementContext>(i);
}


size_t GoParser::InterfaceTypeContext::getRuleIndex() const {
  return GoParser::RuleInterfaceType;
}


antlrcpp::Any GoParser::InterfaceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitInterfaceType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::InterfaceTypeContext* GoParser::interfaceType() {
  InterfaceTypeContext *_localctx = _tracker.createInstance<InterfaceTypeContext>(_ctx, getState());
  enterRule(_localctx, 132, GoParser::RuleInterfaceType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    match(GoParser::INTERFACE);
    setState(711);
    match(GoParser::L_CURLY);
    setState(720);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (GoParser::FUNC - 3))
      | (1ULL << (GoParser::INTERFACE - 3))
      | (1ULL << (GoParser::MAP - 3))
      | (1ULL << (GoParser::STRUCT - 3))
      | (1ULL << (GoParser::CHAN - 3))
      | (1ULL << (GoParser::IDENTIFIER - 3))
      | (1ULL << (GoParser::L_PAREN - 3))
      | (1ULL << (GoParser::L_BRACKET - 3))
      | (1ULL << (GoParser::UNDERLYING - 3))
      | (1ULL << (GoParser::STAR - 3))
      | (1ULL << (GoParser::RECEIVE - 3)))) != 0)) {
      setState(714);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
      case 1: {
        setState(712);
        methodSpec();
        break;
      }

      case 2: {
        setState(713);
        typeElement();
        break;
      }

      default:
        break;
      }
      setState(716);
      eos();
      setState(722);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(723);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SliceTypeContext ------------------------------------------------------------------

GoParser::SliceTypeContext::SliceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SliceTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::SliceTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::SliceTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::SliceTypeContext::getRuleIndex() const {
  return GoParser::RuleSliceType;
}


antlrcpp::Any GoParser::SliceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSliceType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SliceTypeContext* GoParser::sliceType() {
  SliceTypeContext *_localctx = _tracker.createInstance<SliceTypeContext>(_ctx, getState());
  enterRule(_localctx, 134, GoParser::RuleSliceType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    match(GoParser::L_BRACKET);
    setState(726);
    match(GoParser::R_BRACKET);
    setState(727);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapTypeContext ------------------------------------------------------------------

GoParser::MapTypeContext::MapTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MapTypeContext::MAP() {
  return getToken(GoParser::MAP, 0);
}

tree::TerminalNode* GoParser::MapTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::Type_Context* GoParser::MapTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::MapTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::MapTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::MapTypeContext::getRuleIndex() const {
  return GoParser::RuleMapType;
}


antlrcpp::Any GoParser::MapTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitMapType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::MapTypeContext* GoParser::mapType() {
  MapTypeContext *_localctx = _tracker.createInstance<MapTypeContext>(_ctx, getState());
  enterRule(_localctx, 136, GoParser::RuleMapType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(729);
    match(GoParser::MAP);
    setState(730);
    match(GoParser::L_BRACKET);
    setState(731);
    type_();
    setState(732);
    match(GoParser::R_BRACKET);
    setState(733);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChannelTypeContext ------------------------------------------------------------------

GoParser::ChannelTypeContext::ChannelTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ElementTypeContext* GoParser::ChannelTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}

tree::TerminalNode* GoParser::ChannelTypeContext::CHAN() {
  return getToken(GoParser::CHAN, 0);
}

tree::TerminalNode* GoParser::ChannelTypeContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}


size_t GoParser::ChannelTypeContext::getRuleIndex() const {
  return GoParser::RuleChannelType;
}


antlrcpp::Any GoParser::ChannelTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitChannelType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ChannelTypeContext* GoParser::channelType() {
  ChannelTypeContext *_localctx = _tracker.createInstance<ChannelTypeContext>(_ctx, getState());
  enterRule(_localctx, 138, GoParser::RuleChannelType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(740);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(735);
      match(GoParser::CHAN);
      break;
    }

    case 2: {
      setState(736);
      match(GoParser::CHAN);
      setState(737);
      match(GoParser::RECEIVE);
      break;
    }

    case 3: {
      setState(738);
      match(GoParser::RECEIVE);
      setState(739);
      match(GoParser::CHAN);
      break;
    }

    default:
      break;
    }
    setState(742);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodSpecContext ------------------------------------------------------------------

GoParser::MethodSpecContext::MethodSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MethodSpecContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::ParametersContext* GoParser::MethodSpecContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::ResultContext* GoParser::MethodSpecContext::result() {
  return getRuleContext<GoParser::ResultContext>(0);
}


size_t GoParser::MethodSpecContext::getRuleIndex() const {
  return GoParser::RuleMethodSpec;
}


antlrcpp::Any GoParser::MethodSpecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitMethodSpec(this);
  else
    return visitor->visitChildren(this);
}

GoParser::MethodSpecContext* GoParser::methodSpec() {
  MethodSpecContext *_localctx = _tracker.createInstance<MethodSpecContext>(_ctx, getState());
  enterRule(_localctx, 140, GoParser::RuleMethodSpec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(750);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(744);
      match(GoParser::IDENTIFIER);
      setState(745);
      parameters();
      setState(746);
      result();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(748);
      match(GoParser::IDENTIFIER);
      setState(749);
      parameters();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

GoParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionTypeContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::SignatureContext* GoParser::FunctionTypeContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}


size_t GoParser::FunctionTypeContext::getRuleIndex() const {
  return GoParser::RuleFunctionType;
}


antlrcpp::Any GoParser::FunctionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitFunctionType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::FunctionTypeContext* GoParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 142, GoParser::RuleFunctionType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(752);
    match(GoParser::FUNC);
    setState(753);
    signature();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignatureContext ------------------------------------------------------------------

GoParser::SignatureContext::SignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::SignatureContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::ResultContext* GoParser::SignatureContext::result() {
  return getRuleContext<GoParser::ResultContext>(0);
}


size_t GoParser::SignatureContext::getRuleIndex() const {
  return GoParser::RuleSignature;
}


antlrcpp::Any GoParser::SignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSignature(this);
  else
    return visitor->visitChildren(this);
}

GoParser::SignatureContext* GoParser::signature() {
  SignatureContext *_localctx = _tracker.createInstance<SignatureContext>(_ctx, getState());
  enterRule(_localctx, 144, GoParser::RuleSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(755);
    parameters();
    setState(757);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      setState(756);
      result();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResultContext ------------------------------------------------------------------

GoParser::ResultContext::ResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::ResultContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::Type_Context* GoParser::ResultContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ResultContext::getRuleIndex() const {
  return GoParser::RuleResult;
}


antlrcpp::Any GoParser::ResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitResult(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ResultContext* GoParser::result() {
  ResultContext *_localctx = _tracker.createInstance<ResultContext>(_ctx, getState());
  enterRule(_localctx, 146, GoParser::RuleResult);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(761);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(759);
      parameters();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(760);
      type_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

GoParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ParametersContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ParametersContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::ParameterDeclContext *> GoParser::ParametersContext::parameterDecl() {
  return getRuleContexts<GoParser::ParameterDeclContext>();
}

GoParser::ParameterDeclContext* GoParser::ParametersContext::parameterDecl(size_t i) {
  return getRuleContext<GoParser::ParameterDeclContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ParametersContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ParametersContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ParametersContext::getRuleIndex() const {
  return GoParser::RuleParameters;
}


antlrcpp::Any GoParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ParametersContext* GoParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 148, GoParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(763);
    match(GoParser::L_PAREN);
    setState(775);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (GoParser::FUNC - 3))
      | (1ULL << (GoParser::INTERFACE - 3))
      | (1ULL << (GoParser::MAP - 3))
      | (1ULL << (GoParser::STRUCT - 3))
      | (1ULL << (GoParser::CHAN - 3))
      | (1ULL << (GoParser::IDENTIFIER - 3))
      | (1ULL << (GoParser::L_PAREN - 3))
      | (1ULL << (GoParser::L_BRACKET - 3))
      | (1ULL << (GoParser::ELLIPSIS - 3))
      | (1ULL << (GoParser::STAR - 3))
      | (1ULL << (GoParser::RECEIVE - 3)))) != 0)) {
      setState(764);
      parameterDecl();
      setState(769);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(765);
          match(GoParser::COMMA);
          setState(766);
          parameterDecl(); 
        }
        setState(771);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      setState(773);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(772);
        match(GoParser::COMMA);
      }
    }
    setState(777);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclContext ------------------------------------------------------------------

GoParser::ParameterDeclContext::ParameterDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ParameterDeclContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

GoParser::IdentifierListContext* GoParser::ParameterDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ParameterDeclContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}


size_t GoParser::ParameterDeclContext::getRuleIndex() const {
  return GoParser::RuleParameterDecl;
}


antlrcpp::Any GoParser::ParameterDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitParameterDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ParameterDeclContext* GoParser::parameterDecl() {
  ParameterDeclContext *_localctx = _tracker.createInstance<ParameterDeclContext>(_ctx, getState());
  enterRule(_localctx, 150, GoParser::RuleParameterDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(780);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      setState(779);
      identifierList();
      break;
    }

    default:
      break;
    }
    setState(783);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::ELLIPSIS) {
      setState(782);
      match(GoParser::ELLIPSIS);
    }
    setState(785);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GoParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::PrimaryExprContext* GoParser::ExpressionContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

std::vector<GoParser::ExpressionContext *> GoParser::ExpressionContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::ExpressionContext::PLUS() {
  return getToken(GoParser::PLUS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::MINUS() {
  return getToken(GoParser::MINUS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::EXCLAMATION() {
  return getToken(GoParser::EXCLAMATION, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::CARET() {
  return getToken(GoParser::CARET, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::AMPERSAND() {
  return getToken(GoParser::AMPERSAND, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::DIV() {
  return getToken(GoParser::DIV, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::MOD() {
  return getToken(GoParser::MOD, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::LSHIFT() {
  return getToken(GoParser::LSHIFT, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::RSHIFT() {
  return getToken(GoParser::RSHIFT, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::BIT_CLEAR() {
  return getToken(GoParser::BIT_CLEAR, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::OR() {
  return getToken(GoParser::OR, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::EQUALS() {
  return getToken(GoParser::EQUALS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::NOT_EQUALS() {
  return getToken(GoParser::NOT_EQUALS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::LESS() {
  return getToken(GoParser::LESS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::LESS_OR_EQUALS() {
  return getToken(GoParser::LESS_OR_EQUALS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::GREATER() {
  return getToken(GoParser::GREATER, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::GREATER_OR_EQUALS() {
  return getToken(GoParser::GREATER_OR_EQUALS, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::LOGICAL_AND() {
  return getToken(GoParser::LOGICAL_AND, 0);
}

tree::TerminalNode* GoParser::ExpressionContext::LOGICAL_OR() {
  return getToken(GoParser::LOGICAL_OR, 0);
}


size_t GoParser::ExpressionContext::getRuleIndex() const {
  return GoParser::RuleExpression;
}


antlrcpp::Any GoParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


GoParser::ExpressionContext* GoParser::expression() {
   return expression(0);
}

GoParser::ExpressionContext* GoParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GoParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  GoParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 152;
  enterRecursionRule(_localctx, 152, GoParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(791);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      setState(788);
      primaryExpr(0);
      break;
    }

    case 2: {
      setState(789);
      dynamic_cast<ExpressionContext *>(_localctx)->unary_op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (GoParser::EXCLAMATION - 58))
        | (1ULL << (GoParser::PLUS - 58))
        | (1ULL << (GoParser::MINUS - 58))
        | (1ULL << (GoParser::CARET - 58))
        | (1ULL << (GoParser::STAR - 58))
        | (1ULL << (GoParser::AMPERSAND - 58))
        | (1ULL << (GoParser::RECEIVE - 58)))) != 0))) {
        dynamic_cast<ExpressionContext *>(_localctx)->unary_op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(790);
      expression(6);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(810);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(808);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(793);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(794);
          dynamic_cast<ExpressionContext *>(_localctx)->mul_op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << GoParser::DIV)
            | (1ULL << GoParser::MOD)
            | (1ULL << GoParser::LSHIFT)
            | (1ULL << GoParser::RSHIFT)
            | (1ULL << GoParser::BIT_CLEAR)
            | (1ULL << GoParser::STAR)
            | (1ULL << GoParser::AMPERSAND))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->mul_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(795);
          expression(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(796);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(797);
          dynamic_cast<ExpressionContext *>(_localctx)->add_op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << GoParser::OR)
            | (1ULL << GoParser::PLUS)
            | (1ULL << GoParser::MINUS)
            | (1ULL << GoParser::CARET))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->add_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(798);
          expression(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(799);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(800);
          dynamic_cast<ExpressionContext *>(_localctx)->rel_op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << GoParser::EQUALS)
            | (1ULL << GoParser::NOT_EQUALS)
            | (1ULL << GoParser::LESS)
            | (1ULL << GoParser::LESS_OR_EQUALS)
            | (1ULL << GoParser::GREATER)
            | (1ULL << GoParser::GREATER_OR_EQUALS))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->rel_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(801);
          expression(4);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(802);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(803);
          match(GoParser::LOGICAL_AND);
          setState(804);
          expression(3);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(805);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(806);
          match(GoParser::LOGICAL_OR);
          setState(807);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(812);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

GoParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::OperandContext* GoParser::PrimaryExprContext::operand() {
  return getRuleContext<GoParser::OperandContext>(0);
}

GoParser::ConversionContext* GoParser::PrimaryExprContext::conversion() {
  return getRuleContext<GoParser::ConversionContext>(0);
}

GoParser::MethodExprContext* GoParser::PrimaryExprContext::methodExpr() {
  return getRuleContext<GoParser::MethodExprContext>(0);
}

GoParser::PrimaryExprContext* GoParser::PrimaryExprContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

tree::TerminalNode* GoParser::PrimaryExprContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::PrimaryExprContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::IndexContext* GoParser::PrimaryExprContext::index() {
  return getRuleContext<GoParser::IndexContext>(0);
}

GoParser::Slice_Context* GoParser::PrimaryExprContext::slice_() {
  return getRuleContext<GoParser::Slice_Context>(0);
}

GoParser::TypeAssertionContext* GoParser::PrimaryExprContext::typeAssertion() {
  return getRuleContext<GoParser::TypeAssertionContext>(0);
}

GoParser::ArgumentsContext* GoParser::PrimaryExprContext::arguments() {
  return getRuleContext<GoParser::ArgumentsContext>(0);
}


size_t GoParser::PrimaryExprContext::getRuleIndex() const {
  return GoParser::RulePrimaryExpr;
}


antlrcpp::Any GoParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}


GoParser::PrimaryExprContext* GoParser::primaryExpr() {
   return primaryExpr(0);
}

GoParser::PrimaryExprContext* GoParser::primaryExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GoParser::PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, parentState);
  GoParser::PrimaryExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 154;
  enterRecursionRule(_localctx, 154, GoParser::RulePrimaryExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(817);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      setState(814);
      operand();
      break;
    }

    case 2: {
      setState(815);
      conversion();
      break;
    }

    case 3: {
      setState(816);
      methodExpr();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(830);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PrimaryExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePrimaryExpr);
        setState(819);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(826);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
        case 1: {
          setState(820);
          match(GoParser::DOT);
          setState(821);
          match(GoParser::IDENTIFIER);
          break;
        }

        case 2: {
          setState(822);
          index();
          break;
        }

        case 3: {
          setState(823);
          slice_();
          break;
        }

        case 4: {
          setState(824);
          typeAssertion();
          break;
        }

        case 5: {
          setState(825);
          arguments();
          break;
        }

        default:
          break;
        } 
      }
      setState(832);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConversionContext ------------------------------------------------------------------

GoParser::ConversionContext::ConversionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ConversionContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::ConversionContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::ExpressionContext* GoParser::ConversionContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::ConversionContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

tree::TerminalNode* GoParser::ConversionContext::COMMA() {
  return getToken(GoParser::COMMA, 0);
}


size_t GoParser::ConversionContext::getRuleIndex() const {
  return GoParser::RuleConversion;
}


antlrcpp::Any GoParser::ConversionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitConversion(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ConversionContext* GoParser::conversion() {
  ConversionContext *_localctx = _tracker.createInstance<ConversionContext>(_ctx, getState());
  enterRule(_localctx, 156, GoParser::RuleConversion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(833);
    type_();
    setState(834);
    match(GoParser::L_PAREN);
    setState(835);
    expression(0);
    setState(837);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::COMMA) {
      setState(836);
      match(GoParser::COMMA);
    }
    setState(839);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

GoParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::LiteralContext* GoParser::OperandContext::literal() {
  return getRuleContext<GoParser::LiteralContext>(0);
}

GoParser::OperandNameContext* GoParser::OperandContext::operandName() {
  return getRuleContext<GoParser::OperandNameContext>(0);
}

tree::TerminalNode* GoParser::OperandContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::ExpressionContext* GoParser::OperandContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::OperandContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::OperandContext::getRuleIndex() const {
  return GoParser::RuleOperand;
}


antlrcpp::Any GoParser::OperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitOperand(this);
  else
    return visitor->visitChildren(this);
}

GoParser::OperandContext* GoParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 158, GoParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(847);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(841);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(842);
      operandName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(843);
      match(GoParser::L_PAREN);
      setState(844);
      expression(0);
      setState(845);
      match(GoParser::R_PAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

GoParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::BasicLitContext* GoParser::LiteralContext::basicLit() {
  return getRuleContext<GoParser::BasicLitContext>(0);
}

GoParser::CompositeLitContext* GoParser::LiteralContext::compositeLit() {
  return getRuleContext<GoParser::CompositeLitContext>(0);
}

GoParser::FunctionLitContext* GoParser::LiteralContext::functionLit() {
  return getRuleContext<GoParser::FunctionLitContext>(0);
}


size_t GoParser::LiteralContext::getRuleIndex() const {
  return GoParser::RuleLiteral;
}


antlrcpp::Any GoParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

GoParser::LiteralContext* GoParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 160, GoParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(852);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::NIL_LIT:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(849);
        basicLit();
        break;
      }

      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::IDENTIFIER:
      case GoParser::L_BRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(850);
        compositeLit();
        break;
      }

      case GoParser::FUNC: {
        enterOuterAlt(_localctx, 3);
        setState(851);
        functionLit();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicLitContext ------------------------------------------------------------------

GoParser::BasicLitContext::BasicLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BasicLitContext::NIL_LIT() {
  return getToken(GoParser::NIL_LIT, 0);
}

GoParser::IntegerContext* GoParser::BasicLitContext::integer() {
  return getRuleContext<GoParser::IntegerContext>(0);
}

GoParser::String_Context* GoParser::BasicLitContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}

tree::TerminalNode* GoParser::BasicLitContext::FLOAT_LIT() {
  return getToken(GoParser::FLOAT_LIT, 0);
}


size_t GoParser::BasicLitContext::getRuleIndex() const {
  return GoParser::RuleBasicLit;
}


antlrcpp::Any GoParser::BasicLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitBasicLit(this);
  else
    return visitor->visitChildren(this);
}

GoParser::BasicLitContext* GoParser::basicLit() {
  BasicLitContext *_localctx = _tracker.createInstance<BasicLitContext>(_ctx, getState());
  enterRule(_localctx, 162, GoParser::RuleBasicLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(858);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::NIL_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(854);
        match(GoParser::NIL_LIT);
        break;
      }

      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(855);
        integer();
        break;
      }

      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(856);
        string_();
        break;
      }

      case GoParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(857);
        match(GoParser::FLOAT_LIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

GoParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IntegerContext::DECIMAL_LIT() {
  return getToken(GoParser::DECIMAL_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::BINARY_LIT() {
  return getToken(GoParser::BINARY_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::OCTAL_LIT() {
  return getToken(GoParser::OCTAL_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::HEX_LIT() {
  return getToken(GoParser::HEX_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::IMAGINARY_LIT() {
  return getToken(GoParser::IMAGINARY_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::RUNE_LIT() {
  return getToken(GoParser::RUNE_LIT, 0);
}


size_t GoParser::IntegerContext::getRuleIndex() const {
  return GoParser::RuleInteger;
}


antlrcpp::Any GoParser::IntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitInteger(this);
  else
    return visitor->visitChildren(this);
}

GoParser::IntegerContext* GoParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 164, GoParser::RuleInteger);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(860);
    _la = _input->LA(1);
    if (!(((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (GoParser::DECIMAL_LIT - 65))
      | (1ULL << (GoParser::BINARY_LIT - 65))
      | (1ULL << (GoParser::OCTAL_LIT - 65))
      | (1ULL << (GoParser::HEX_LIT - 65))
      | (1ULL << (GoParser::IMAGINARY_LIT - 65))
      | (1ULL << (GoParser::RUNE_LIT - 65)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandNameContext ------------------------------------------------------------------

GoParser::OperandNameContext::OperandNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::OperandNameContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::OperandNameContext::getRuleIndex() const {
  return GoParser::RuleOperandName;
}


antlrcpp::Any GoParser::OperandNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitOperandName(this);
  else
    return visitor->visitChildren(this);
}

GoParser::OperandNameContext* GoParser::operandName() {
  OperandNameContext *_localctx = _tracker.createInstance<OperandNameContext>(_ctx, getState());
  enterRule(_localctx, 166, GoParser::RuleOperandName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(862);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedIdentContext ------------------------------------------------------------------

GoParser::QualifiedIdentContext::QualifiedIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GoParser::QualifiedIdentContext::IDENTIFIER() {
  return getTokens(GoParser::IDENTIFIER);
}

tree::TerminalNode* GoParser::QualifiedIdentContext::IDENTIFIER(size_t i) {
  return getToken(GoParser::IDENTIFIER, i);
}

tree::TerminalNode* GoParser::QualifiedIdentContext::DOT() {
  return getToken(GoParser::DOT, 0);
}


size_t GoParser::QualifiedIdentContext::getRuleIndex() const {
  return GoParser::RuleQualifiedIdent;
}


antlrcpp::Any GoParser::QualifiedIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitQualifiedIdent(this);
  else
    return visitor->visitChildren(this);
}

GoParser::QualifiedIdentContext* GoParser::qualifiedIdent() {
  QualifiedIdentContext *_localctx = _tracker.createInstance<QualifiedIdentContext>(_ctx, getState());
  enterRule(_localctx, 168, GoParser::RuleQualifiedIdent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(864);
    match(GoParser::IDENTIFIER);
    setState(865);
    match(GoParser::DOT);
    setState(866);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeLitContext ------------------------------------------------------------------

GoParser::CompositeLitContext::CompositeLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::LiteralTypeContext* GoParser::CompositeLitContext::literalType() {
  return getRuleContext<GoParser::LiteralTypeContext>(0);
}

GoParser::LiteralValueContext* GoParser::CompositeLitContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::CompositeLitContext::getRuleIndex() const {
  return GoParser::RuleCompositeLit;
}


antlrcpp::Any GoParser::CompositeLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitCompositeLit(this);
  else
    return visitor->visitChildren(this);
}

GoParser::CompositeLitContext* GoParser::compositeLit() {
  CompositeLitContext *_localctx = _tracker.createInstance<CompositeLitContext>(_ctx, getState());
  enterRule(_localctx, 170, GoParser::RuleCompositeLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(868);
    literalType();
    setState(869);
    literalValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralTypeContext ------------------------------------------------------------------

GoParser::LiteralTypeContext::LiteralTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::StructTypeContext* GoParser::LiteralTypeContext::structType() {
  return getRuleContext<GoParser::StructTypeContext>(0);
}

GoParser::ArrayTypeContext* GoParser::LiteralTypeContext::arrayType() {
  return getRuleContext<GoParser::ArrayTypeContext>(0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::LiteralTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}

GoParser::SliceTypeContext* GoParser::LiteralTypeContext::sliceType() {
  return getRuleContext<GoParser::SliceTypeContext>(0);
}

GoParser::MapTypeContext* GoParser::LiteralTypeContext::mapType() {
  return getRuleContext<GoParser::MapTypeContext>(0);
}

GoParser::TypeNameContext* GoParser::LiteralTypeContext::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}

GoParser::TypeArgsContext* GoParser::LiteralTypeContext::typeArgs() {
  return getRuleContext<GoParser::TypeArgsContext>(0);
}


size_t GoParser::LiteralTypeContext::getRuleIndex() const {
  return GoParser::RuleLiteralType;
}


antlrcpp::Any GoParser::LiteralTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitLiteralType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::LiteralTypeContext* GoParser::literalType() {
  LiteralTypeContext *_localctx = _tracker.createInstance<LiteralTypeContext>(_ctx, getState());
  enterRule(_localctx, 172, GoParser::RuleLiteralType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(883);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(871);
      structType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(872);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(873);
      match(GoParser::L_BRACKET);
      setState(874);
      match(GoParser::ELLIPSIS);
      setState(875);
      match(GoParser::R_BRACKET);
      setState(876);
      elementType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(877);
      sliceType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(878);
      mapType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(879);
      typeName();
      setState(881);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::L_BRACKET) {
        setState(880);
        typeArgs();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

GoParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::LiteralValueContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::LiteralValueContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::ElementListContext* GoParser::LiteralValueContext::elementList() {
  return getRuleContext<GoParser::ElementListContext>(0);
}

tree::TerminalNode* GoParser::LiteralValueContext::COMMA() {
  return getToken(GoParser::COMMA, 0);
}


size_t GoParser::LiteralValueContext::getRuleIndex() const {
  return GoParser::RuleLiteralValue;
}


antlrcpp::Any GoParser::LiteralValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitLiteralValue(this);
  else
    return visitor->visitChildren(this);
}

GoParser::LiteralValueContext* GoParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 174, GoParser::RuleLiteralValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(885);
    match(GoParser::L_CURLY);
    setState(890);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET)
      | (1ULL << GoParser::STAR)
      | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(886);
      elementList();
      setState(888);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(887);
        match(GoParser::COMMA);
      }
    }
    setState(892);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

GoParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::KeyedElementContext *> GoParser::ElementListContext::keyedElement() {
  return getRuleContexts<GoParser::KeyedElementContext>();
}

GoParser::KeyedElementContext* GoParser::ElementListContext::keyedElement(size_t i) {
  return getRuleContext<GoParser::KeyedElementContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ElementListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ElementListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ElementListContext::getRuleIndex() const {
  return GoParser::RuleElementList;
}


antlrcpp::Any GoParser::ElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitElementList(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ElementListContext* GoParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 176, GoParser::RuleElementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(894);
    keyedElement();
    setState(899);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(895);
        match(GoParser::COMMA);
        setState(896);
        keyedElement(); 
      }
      setState(901);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyedElementContext ------------------------------------------------------------------

GoParser::KeyedElementContext::KeyedElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ElementContext* GoParser::KeyedElementContext::element() {
  return getRuleContext<GoParser::ElementContext>(0);
}

GoParser::KeyContext* GoParser::KeyedElementContext::key() {
  return getRuleContext<GoParser::KeyContext>(0);
}

tree::TerminalNode* GoParser::KeyedElementContext::COLON() {
  return getToken(GoParser::COLON, 0);
}


size_t GoParser::KeyedElementContext::getRuleIndex() const {
  return GoParser::RuleKeyedElement;
}


antlrcpp::Any GoParser::KeyedElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitKeyedElement(this);
  else
    return visitor->visitChildren(this);
}

GoParser::KeyedElementContext* GoParser::keyedElement() {
  KeyedElementContext *_localctx = _tracker.createInstance<KeyedElementContext>(_ctx, getState());
  enterRule(_localctx, 178, GoParser::RuleKeyedElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(905);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      setState(902);
      key();
      setState(903);
      match(GoParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(907);
    element();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyContext ------------------------------------------------------------------

GoParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::KeyContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::LiteralValueContext* GoParser::KeyContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::KeyContext::getRuleIndex() const {
  return GoParser::RuleKey;
}


antlrcpp::Any GoParser::KeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitKey(this);
  else
    return visitor->visitChildren(this);
}

GoParser::KeyContext* GoParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 180, GoParser::RuleKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(911);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::NIL_LIT:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::EXCLAMATION:
      case GoParser::PLUS:
      case GoParser::MINUS:
      case GoParser::CARET:
      case GoParser::STAR:
      case GoParser::AMPERSAND:
      case GoParser::RECEIVE:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(909);
        expression(0);
        break;
      }

      case GoParser::L_CURLY: {
        enterOuterAlt(_localctx, 2);
        setState(910);
        literalValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

GoParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ElementContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::LiteralValueContext* GoParser::ElementContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::ElementContext::getRuleIndex() const {
  return GoParser::RuleElement;
}


antlrcpp::Any GoParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ElementContext* GoParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 182, GoParser::RuleElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(915);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::NIL_LIT:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::EXCLAMATION:
      case GoParser::PLUS:
      case GoParser::MINUS:
      case GoParser::CARET:
      case GoParser::STAR:
      case GoParser::AMPERSAND:
      case GoParser::RECEIVE:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(913);
        expression(0);
        break;
      }

      case GoParser::L_CURLY: {
        enterOuterAlt(_localctx, 2);
        setState(914);
        literalValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructTypeContext ------------------------------------------------------------------

GoParser::StructTypeContext::StructTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::StructTypeContext::STRUCT() {
  return getToken(GoParser::STRUCT, 0);
}

tree::TerminalNode* GoParser::StructTypeContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::StructTypeContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::FieldDeclContext *> GoParser::StructTypeContext::fieldDecl() {
  return getRuleContexts<GoParser::FieldDeclContext>();
}

GoParser::FieldDeclContext* GoParser::StructTypeContext::fieldDecl(size_t i) {
  return getRuleContext<GoParser::FieldDeclContext>(i);
}

std::vector<GoParser::EosContext *> GoParser::StructTypeContext::eos() {
  return getRuleContexts<GoParser::EosContext>();
}

GoParser::EosContext* GoParser::StructTypeContext::eos(size_t i) {
  return getRuleContext<GoParser::EosContext>(i);
}


size_t GoParser::StructTypeContext::getRuleIndex() const {
  return GoParser::RuleStructType;
}


antlrcpp::Any GoParser::StructTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitStructType(this);
  else
    return visitor->visitChildren(this);
}

GoParser::StructTypeContext* GoParser::structType() {
  StructTypeContext *_localctx = _tracker.createInstance<StructTypeContext>(_ctx, getState());
  enterRule(_localctx, 184, GoParser::RuleStructType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(917);
    match(GoParser::STRUCT);
    setState(918);
    match(GoParser::L_CURLY);
    setState(924);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::IDENTIFIER

    || _la == GoParser::STAR) {
      setState(919);
      fieldDecl();
      setState(920);
      eos();
      setState(926);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(927);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclContext ------------------------------------------------------------------

GoParser::FieldDeclContext::FieldDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::FieldDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

GoParser::Type_Context* GoParser::FieldDeclContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

GoParser::EmbeddedFieldContext* GoParser::FieldDeclContext::embeddedField() {
  return getRuleContext<GoParser::EmbeddedFieldContext>(0);
}

GoParser::String_Context* GoParser::FieldDeclContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}


size_t GoParser::FieldDeclContext::getRuleIndex() const {
  return GoParser::RuleFieldDecl;
}


antlrcpp::Any GoParser::FieldDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitFieldDecl(this);
  else
    return visitor->visitChildren(this);
}

GoParser::FieldDeclContext* GoParser::fieldDecl() {
  FieldDeclContext *_localctx = _tracker.createInstance<FieldDeclContext>(_ctx, getState());
  enterRule(_localctx, 186, GoParser::RuleFieldDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(933);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
    case 1: {
      setState(929);
      identifierList();
      setState(930);
      type_();
      break;
    }

    case 2: {
      setState(932);
      embeddedField();
      break;
    }

    default:
      break;
    }
    setState(936);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
    case 1: {
      setState(935);
      dynamic_cast<FieldDeclContext *>(_localctx)->tag = string_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_Context ------------------------------------------------------------------

GoParser::String_Context::String_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::String_Context::RAW_STRING_LIT() {
  return getToken(GoParser::RAW_STRING_LIT, 0);
}

tree::TerminalNode* GoParser::String_Context::INTERPRETED_STRING_LIT() {
  return getToken(GoParser::INTERPRETED_STRING_LIT, 0);
}


size_t GoParser::String_Context::getRuleIndex() const {
  return GoParser::RuleString_;
}


antlrcpp::Any GoParser::String_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitString_(this);
  else
    return visitor->visitChildren(this);
}

GoParser::String_Context* GoParser::string_() {
  String_Context *_localctx = _tracker.createInstance<String_Context>(_ctx, getState());
  enterRule(_localctx, 188, GoParser::RuleString_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(938);
    _la = _input->LA(1);
    if (!(_la == GoParser::RAW_STRING_LIT

    || _la == GoParser::INTERPRETED_STRING_LIT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmbeddedFieldContext ------------------------------------------------------------------

GoParser::EmbeddedFieldContext::EmbeddedFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeNameContext* GoParser::EmbeddedFieldContext::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}

tree::TerminalNode* GoParser::EmbeddedFieldContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

GoParser::TypeArgsContext* GoParser::EmbeddedFieldContext::typeArgs() {
  return getRuleContext<GoParser::TypeArgsContext>(0);
}


size_t GoParser::EmbeddedFieldContext::getRuleIndex() const {
  return GoParser::RuleEmbeddedField;
}


antlrcpp::Any GoParser::EmbeddedFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitEmbeddedField(this);
  else
    return visitor->visitChildren(this);
}

GoParser::EmbeddedFieldContext* GoParser::embeddedField() {
  EmbeddedFieldContext *_localctx = _tracker.createInstance<EmbeddedFieldContext>(_ctx, getState());
  enterRule(_localctx, 190, GoParser::RuleEmbeddedField);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(941);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::STAR) {
      setState(940);
      match(GoParser::STAR);
    }
    setState(943);
    typeName();
    setState(945);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
    case 1: {
      setState(944);
      typeArgs();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionLitContext ------------------------------------------------------------------

GoParser::FunctionLitContext::FunctionLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionLitContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::SignatureContext* GoParser::FunctionLitContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::BlockContext* GoParser::FunctionLitContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::FunctionLitContext::getRuleIndex() const {
  return GoParser::RuleFunctionLit;
}


antlrcpp::Any GoParser::FunctionLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitFunctionLit(this);
  else
    return visitor->visitChildren(this);
}

GoParser::FunctionLitContext* GoParser::functionLit() {
  FunctionLitContext *_localctx = _tracker.createInstance<FunctionLitContext>(_ctx, getState());
  enterRule(_localctx, 192, GoParser::RuleFunctionLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(947);
    match(GoParser::FUNC);
    setState(948);
    signature();
    setState(949);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

GoParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IndexContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::ExpressionContext* GoParser::IndexContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::IndexContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}


size_t GoParser::IndexContext::getRuleIndex() const {
  return GoParser::RuleIndex;
}


antlrcpp::Any GoParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

GoParser::IndexContext* GoParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 194, GoParser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(951);
    match(GoParser::L_BRACKET);
    setState(952);
    expression(0);
    setState(953);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Slice_Context ------------------------------------------------------------------

GoParser::Slice_Context::Slice_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::Slice_Context::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::Slice_Context::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

std::vector<tree::TerminalNode *> GoParser::Slice_Context::COLON() {
  return getTokens(GoParser::COLON);
}

tree::TerminalNode* GoParser::Slice_Context::COLON(size_t i) {
  return getToken(GoParser::COLON, i);
}

std::vector<GoParser::ExpressionContext *> GoParser::Slice_Context::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::Slice_Context::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}


size_t GoParser::Slice_Context::getRuleIndex() const {
  return GoParser::RuleSlice_;
}


antlrcpp::Any GoParser::Slice_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitSlice_(this);
  else
    return visitor->visitChildren(this);
}

GoParser::Slice_Context* GoParser::slice_() {
  Slice_Context *_localctx = _tracker.createInstance<Slice_Context>(_ctx, getState());
  enterRule(_localctx, 196, GoParser::RuleSlice_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(955);
    match(GoParser::L_BRACKET);
    setState(971);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      setState(957);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(956);
        expression(0);
      }
      setState(959);
      match(GoParser::COLON);
      setState(961);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(960);
        expression(0);
      }
      break;
    }

    case 2: {
      setState(964);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET)
        | (1ULL << GoParser::STAR)
        | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(963);
        expression(0);
      }
      setState(966);
      match(GoParser::COLON);
      setState(967);
      expression(0);
      setState(968);
      match(GoParser::COLON);
      setState(969);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(973);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAssertionContext ------------------------------------------------------------------

GoParser::TypeAssertionContext::TypeAssertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeAssertionContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::TypeAssertionContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::Type_Context* GoParser::TypeAssertionContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::TypeAssertionContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::TypeAssertionContext::getRuleIndex() const {
  return GoParser::RuleTypeAssertion;
}


antlrcpp::Any GoParser::TypeAssertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitTypeAssertion(this);
  else
    return visitor->visitChildren(this);
}

GoParser::TypeAssertionContext* GoParser::typeAssertion() {
  TypeAssertionContext *_localctx = _tracker.createInstance<TypeAssertionContext>(_ctx, getState());
  enterRule(_localctx, 198, GoParser::RuleTypeAssertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(975);
    match(GoParser::DOT);
    setState(976);
    match(GoParser::L_PAREN);
    setState(977);
    type_();
    setState(978);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

GoParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ArgumentsContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ArgumentsContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

GoParser::ExpressionListContext* GoParser::ArgumentsContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

GoParser::Type_Context* GoParser::ArgumentsContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::ArgumentsContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}

std::vector<tree::TerminalNode *> GoParser::ArgumentsContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ArgumentsContext::getRuleIndex() const {
  return GoParser::RuleArguments;
}


antlrcpp::Any GoParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

GoParser::ArgumentsContext* GoParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 200, GoParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(980);
    match(GoParser::L_PAREN);
    setState(995);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET)
      | (1ULL << GoParser::STAR)
      | (1ULL << GoParser::AMPERSAND))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(987);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
      case 1: {
        setState(981);
        expressionList();
        break;
      }

      case 2: {
        setState(982);
        type_();
        setState(985);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
        case 1: {
          setState(983);
          match(GoParser::COMMA);
          setState(984);
          expressionList();
          break;
        }

        default:
          break;
        }
        break;
      }

      default:
        break;
      }
      setState(990);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::ELLIPSIS) {
        setState(989);
        match(GoParser::ELLIPSIS);
      }
      setState(993);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(992);
        match(GoParser::COMMA);
      }
    }
    setState(997);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodExprContext ------------------------------------------------------------------

GoParser::MethodExprContext::MethodExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::MethodExprContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::MethodExprContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::MethodExprContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::MethodExprContext::getRuleIndex() const {
  return GoParser::RuleMethodExpr;
}


antlrcpp::Any GoParser::MethodExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitMethodExpr(this);
  else
    return visitor->visitChildren(this);
}

GoParser::MethodExprContext* GoParser::methodExpr() {
  MethodExprContext *_localctx = _tracker.createInstance<MethodExprContext>(_ctx, getState());
  enterRule(_localctx, 202, GoParser::RuleMethodExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(999);
    type_();
    setState(1000);
    match(GoParser::DOT);
    setState(1001);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

GoParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::EosContext::SEMI() {
  return getToken(GoParser::SEMI, 0);
}

tree::TerminalNode* GoParser::EosContext::EOF() {
  return getToken(GoParser::EOF, 0);
}

tree::TerminalNode* GoParser::EosContext::EOS() {
  return getToken(GoParser::EOS, 0);
}


size_t GoParser::EosContext::getRuleIndex() const {
  return GoParser::RuleEos;
}


antlrcpp::Any GoParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GoParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

GoParser::EosContext* GoParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 204, GoParser::RuleEos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1007);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1003);
      match(GoParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1004);
      match(GoParser::EOF);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1005);
      match(GoParser::EOS);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1006);

      if (!(this->closingBracket())) throw FailedPredicateException(this, "this->closingBracket()");
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool GoParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return statementListSempred(dynamic_cast<StatementListContext *>(context), predicateIndex);
    case 76: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 77: return primaryExprSempred(dynamic_cast<PrimaryExprContext *>(context), predicateIndex);
    case 102: return eosSempred(dynamic_cast<EosContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GoParser::statementListSempred(StatementListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return this->closingBracket();

  default:
    break;
  }
  return true;
}

bool GoParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GoParser::primaryExprSempred(PrimaryExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GoParser::eosSempred(EosContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return this->closingBracket();

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> GoParser::_decisionToDFA;
atn::PredictionContextCache GoParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GoParser::_atn;
std::vector<uint16_t> GoParser::_serializedATN;

std::vector<std::string> GoParser::_ruleNames = {
  "sourceFile", "packageClause", "importDecl", "importSpec", "importPath", 
  "declaration", "constDecl", "constSpec", "identifierList", "expressionList", 
  "typeDecl", "typeSpec", "aliasDecl", "typeDef", "typeParameters", "typeParameterDecl", 
  "typeElement", "typeTerm", "functionDecl", "methodDecl", "receiver", "varDecl", 
  "varSpec", "block", "statementList", "statement", "simpleStmt", "expressionStmt", 
  "sendStmt", "incDecStmt", "assignment", "assign_op", "shortVarDecl", "labeledStmt", 
  "returnStmt", "breakStmt", "continueStmt", "gotoStmt", "fallthroughStmt", 
  "deferStmt", "ifStmt", "switchStmt", "exprSwitchStmt", "exprCaseClause", 
  "exprSwitchCase", "typeSwitchStmt", "typeSwitchGuard", "typeCaseClause", 
  "typeSwitchCase", "typeList", "selectStmt", "commClause", "commCase", 
  "recvStmt", "forStmt", "forClause", "rangeClause", "goStmt", "type_", 
  "typeArgs", "typeName", "typeLit", "arrayType", "arrayLength", "elementType", 
  "pointerType", "interfaceType", "sliceType", "mapType", "channelType", 
  "methodSpec", "functionType", "signature", "result", "parameters", "parameterDecl", 
  "expression", "primaryExpr", "conversion", "operand", "literal", "basicLit", 
  "integer", "operandName", "qualifiedIdent", "compositeLit", "literalType", 
  "literalValue", "elementList", "keyedElement", "key", "element", "structType", 
  "fieldDecl", "string_", "embeddedField", "functionLit", "index", "slice_", 
  "typeAssertion", "arguments", "methodExpr", "eos"
};

std::vector<std::string> GoParser::_literalNames = {
  "", "'break'", "'default'", "'func'", "'interface'", "'select'", "'case'", 
  "'defer'", "'go'", "'map'", "'struct'", "'chan'", "'else'", "'goto'", 
  "'package'", "'switch'", "'const'", "'fallthrough'", "'if'", "'range'", 
  "'type'", "'continue'", "'for'", "'import'", "'return'", "'var'", "'nil'", 
  "", "'('", "')'", "'{'", "'}'", "'['", "']'", "'='", "','", "';'", "':'", 
  "'.'", "'++'", "'--'", "':='", "'...'", "'||'", "'&&'", "'=='", "'!='", 
  "'<'", "'<='", "'>'", "'>='", "'|'", "'/'", "'%'", "'<<'", "'>>'", "'&^'", 
  "'~'", "'!'", "'+'", "'-'", "'^'", "'*'", "'&'", "'<-'"
};

std::vector<std::string> GoParser::_symbolicNames = {
  "", "BREAK", "DEFAULT", "FUNC", "INTERFACE", "SELECT", "CASE", "DEFER", 
  "GO", "MAP", "STRUCT", "CHAN", "ELSE", "GOTO", "PACKAGE", "SWITCH", "CONST", 
  "FALLTHROUGH", "IF", "RANGE", "TYPE", "CONTINUE", "FOR", "IMPORT", "RETURN", 
  "VAR", "NIL_LIT", "IDENTIFIER", "L_PAREN", "R_PAREN", "L_CURLY", "R_CURLY", 
  "L_BRACKET", "R_BRACKET", "ASSIGN", "COMMA", "SEMI", "COLON", "DOT", "PLUS_PLUS", 
  "MINUS_MINUS", "DECLARE_ASSIGN", "ELLIPSIS", "LOGICAL_OR", "LOGICAL_AND", 
  "EQUALS", "NOT_EQUALS", "LESS", "LESS_OR_EQUALS", "GREATER", "GREATER_OR_EQUALS", 
  "OR", "DIV", "MOD", "LSHIFT", "RSHIFT", "BIT_CLEAR", "UNDERLYING", "EXCLAMATION", 
  "PLUS", "MINUS", "CARET", "STAR", "AMPERSAND", "RECEIVE", "DECIMAL_LIT", 
  "BINARY_LIT", "OCTAL_LIT", "HEX_LIT", "FLOAT_LIT", "DECIMAL_FLOAT_LIT", 
  "HEX_FLOAT_LIT", "IMAGINARY_LIT", "RUNE_LIT", "BYTE_VALUE", "OCTAL_BYTE_VALUE", 
  "HEX_BYTE_VALUE", "LITTLE_U_VALUE", "BIG_U_VALUE", "RAW_STRING_LIT", "INTERPRETED_STRING_LIT", 
  "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT", "WS_NLSEMI", "COMMENT_NLSEMI", 
  "LINE_COMMENT_NLSEMI", "EOS", "OTHER"
};

dfa::Vocabulary GoParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GoParser::_tokenNames;

GoParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x5b, 0x3f4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xd6, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0xd9, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xde, 0xa, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xe2, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0xe5, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xf2, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xf5, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0xf8, 
    0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0xfb, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x104, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 
    0x10c, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x10f, 0xb, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x112, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x116, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x11a, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0x11f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x122, 0xb, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x127, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x12a, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x132, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x135, 0xb, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x138, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x13c, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x144, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x14c, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x14f, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x159, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x15c, 0xb, 0x12, 0x3, 0x13, 0x5, 0x13, 0x15f, 
    0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x166, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x16a, 0xa, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0x171, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x17b, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x17e, 0xb, 0x17, 0x3, 0x17, 0x5, 0x17, 0x181, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x187, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x18b, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x18f, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x5, 0x1a, 
    0x194, 0xa, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x197, 0xa, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x19a, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x6, 0x1a, 
    0x19f, 0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0x1a0, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x1b2, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x1b9, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x5, 0x21, 0x1c9, 
    0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1d4, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1d8, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x5, 0x25, 0x1dc, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1e0, 
    0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1f3, 
    0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1f9, 
    0xa, 0x2a, 0x5, 0x2a, 0x1fb, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
    0x1ff, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x203, 0xa, 0x2c, 
    0x3, 0x2c, 0x5, 0x2c, 0x206, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x20a, 0xa, 0x2c, 0x5, 0x2c, 0x20c, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x7, 0x2c, 0x210, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x213, 0xb, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x21a, 
    0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x21f, 0xa, 0x2e, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x22a, 0xa, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x7, 0x2f, 0x22e, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x231, 
    0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x237, 
    0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x242, 0xa, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x247, 0xa, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x24b, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x250, 0xa, 0x33, 0x7, 0x33, 0x252, 0xa, 0x33, 0xc, 0x33, 
    0xe, 0x33, 0x255, 0xb, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 
    0x25a, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x25d, 0xb, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x264, 0xa, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x269, 0xa, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x26c, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x274, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x27a, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x27e, 0xa, 0x38, 0x5, 0x38, 0x280, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x39, 0x5, 0x39, 0x285, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x5, 0x39, 0x289, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x28d, 
    0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x5, 0x3a, 0x295, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x29f, 
    0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 
    0x3c, 0x2a6, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 
    0x2ab, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x2b1, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x2bb, 0xa, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2cd, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x7, 0x44, 0x2d1, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x2d4, 0xb, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2e7, 0xa, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x5, 0x48, 0x2f1, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x2f8, 0xa, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x5, 0x4b, 0x2fc, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x7, 0x4c, 0x302, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x305, 
    0xb, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x308, 0xa, 0x4c, 0x5, 0x4c, 0x30a, 
    0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x5, 0x4d, 0x30f, 0xa, 0x4d, 
    0x3, 0x4d, 0x5, 0x4d, 0x312, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x31a, 0xa, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x7, 0x4e, 0x32b, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x32e, 
    0xb, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x334, 
    0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x33d, 0xa, 0x4f, 0x7, 0x4f, 0x33f, 0xa, 
    0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x342, 0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x348, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x5, 
    0x51, 0x352, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 
    0x357, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 
    0x35d, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 
    0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
    0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x374, 0xa, 0x58, 0x5, 0x58, 
    0x376, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x37b, 
    0xa, 0x59, 0x5, 0x59, 0x37d, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 
    0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x384, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 
    0x387, 0xb, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x38c, 
    0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x392, 
    0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x396, 0xa, 0x5d, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x39d, 0xa, 0x5e, 
    0xc, 0x5e, 0xe, 0x5e, 0x3a0, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 
    0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x3a8, 0xa, 0x5f, 0x3, 0x5f, 
    0x5, 0x5f, 0x3ab, 0xa, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x5, 0x61, 
    0x3b0, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3b4, 0xa, 0x61, 
    0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 
    0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x3c0, 0xa, 0x64, 
    0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x3c4, 0xa, 0x64, 0x3, 0x64, 0x5, 0x64, 
    0x3c7, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
    0x5, 0x64, 0x3ce, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x3, 0x65, 
    0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 
    0x66, 0x3, 0x66, 0x5, 0x66, 0x3dc, 0xa, 0x66, 0x5, 0x66, 0x3de, 0xa, 
    0x66, 0x3, 0x66, 0x5, 0x66, 0x3e1, 0xa, 0x66, 0x3, 0x66, 0x5, 0x66, 
    0x3e4, 0xa, 0x66, 0x5, 0x66, 0x3e6, 0xa, 0x66, 0x3, 0x66, 0x3, 0x66, 
    0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 
    0x68, 0x3, 0x68, 0x5, 0x68, 0x3f2, 0xa, 0x68, 0x3, 0x68, 0x2, 0x4, 0x9a, 
    0x9c, 0x69, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 
    0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 
    0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
    0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 
    0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0x2, 0xb, 0x4, 0x2, 
    0x1d, 0x1d, 0x28, 0x28, 0x3, 0x2, 0x29, 0x2a, 0x4, 0x2, 0x35, 0x3a, 
    0x3d, 0x41, 0x3, 0x2, 0x3c, 0x42, 0x4, 0x2, 0x36, 0x3a, 0x40, 0x41, 
    0x4, 0x2, 0x35, 0x35, 0x3d, 0x3f, 0x3, 0x2, 0x2f, 0x34, 0x4, 0x2, 0x43, 
    0x46, 0x4a, 0x4b, 0x3, 0x2, 0x51, 0x52, 0x2, 0x434, 0x2, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x6, 0xeb, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xa, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0xe, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x147, 0x3, 0x2, 0x2, 0x2, 0x20, 0x152, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x155, 0x3, 0x2, 0x2, 0x2, 0x24, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x162, 0x3, 0x2, 0x2, 0x2, 0x28, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x174, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x32, 0x19e, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x1c8, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1d0, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1d9, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1e1, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1e6, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x200, 0x3, 0x2, 0x2, 0x2, 0x58, 0x216, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x21e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x220, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x236, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x62, 0x246, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x256, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x260, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x26b, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x273, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x284, 0x3, 0x2, 0x2, 0x2, 0x72, 0x294, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x299, 0x3, 0x2, 0x2, 0x2, 0x76, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x78, 0x2a7, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x2ba, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2c1, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2c5, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2d7, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x2f0, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2f5, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2fd, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x319, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x333, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x343, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x351, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x356, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0x35c, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x35e, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0x360, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x362, 0x3, 0x2, 0x2, 0x2, 0xac, 0x366, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0x375, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x377, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0x380, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x38b, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0x391, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x395, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0x397, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x3a7, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3af, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0x3b5, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x3bd, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0xca, 0x3d6, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0xce, 0x3f1, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd1, 0x5, 0x4, 0x3, 0x2, 0xd1, 0xd7, 0x5, 0xce, 0x68, 
    0x2, 0xd2, 0xd3, 0x5, 0x6, 0x4, 0x2, 0xd3, 0xd4, 0x5, 0xce, 0x68, 0x2, 
    0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xde, 0x5, 0x26, 0x14, 0x2, 0xdb, 0xde, 0x5, 0x28, 
    0x15, 0x2, 0xdc, 0xde, 0x5, 0xc, 0x7, 0x2, 0xdd, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0xce, 0x68, 0x2, 0xe0, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0x2, 0x2, 0x3, 0xe7, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x10, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x1d, 0x2, 0x2, 
    0xea, 0x5, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xf7, 0x7, 0x19, 0x2, 0x2, 0xec, 
    0xf8, 0x5, 0x8, 0x5, 0x2, 0xed, 0xf3, 0x7, 0x1e, 0x2, 0x2, 0xee, 0xef, 
    0x5, 0x8, 0x5, 0x2, 0xef, 0xf0, 0x5, 0xce, 0x68, 0x2, 0xf0, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf8, 0x7, 0x1f, 0x2, 0x2, 0xf7, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 
    0x9, 0x2, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0xa, 
    0x6, 0x2, 0xfd, 0x9, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0xbe, 0x60, 
    0x2, 0xff, 0xb, 0x3, 0x2, 0x2, 0x2, 0x100, 0x104, 0x5, 0xe, 0x8, 0x2, 
    0x101, 0x104, 0x5, 0x16, 0xc, 0x2, 0x102, 0x104, 0x5, 0x2c, 0x17, 0x2, 
    0x103, 0x100, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0xd, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x111, 0x7, 0x12, 0x2, 0x2, 0x106, 0x112, 0x5, 0x10, 0x9, 0x2, 0x107, 
    0x10d, 0x7, 0x1e, 0x2, 0x2, 0x108, 0x109, 0x5, 0x10, 0x9, 0x2, 0x109, 
    0x10a, 0x5, 0xce, 0x68, 0x2, 0x10a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0x112, 0x7, 0x1f, 0x2, 0x2, 0x111, 0x106, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x112, 0xf, 0x3, 0x2, 0x2, 0x2, 0x113, 0x119, 
    0x5, 0x12, 0xa, 0x2, 0x114, 0x116, 0x5, 0x76, 0x3c, 0x2, 0x115, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x24, 0x2, 0x2, 0x118, 0x11a, 
    0x5, 0x14, 0xb, 0x2, 0x119, 0x115, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x120, 0x7, 
    0x1d, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x25, 0x2, 0x2, 0x11d, 0x11f, 0x7, 
    0x1d, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 
    0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x13, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x128, 0x5, 0x9a, 0x4e, 0x2, 0x124, 0x125, 0x7, 0x25, 
    0x2, 0x2, 0x125, 0x127, 0x5, 0x9a, 0x4e, 0x2, 0x126, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x127, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x137, 0x7, 0x16, 0x2, 
    0x2, 0x12c, 0x138, 0x5, 0x18, 0xd, 0x2, 0x12d, 0x133, 0x7, 0x1e, 0x2, 
    0x2, 0x12e, 0x12f, 0x5, 0x18, 0xd, 0x2, 0x12f, 0x130, 0x5, 0xce, 0x68, 
    0x2, 0x130, 0x132, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x135, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x3, 0x2, 0x2, 
    0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x7, 0x1f, 0x2, 
    0x2, 0x137, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x137, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x17, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x5, 0x1a, 0xe, 
    0x2, 0x13a, 0x13c, 0x5, 0x1c, 0xf, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x7, 0x1d, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x24, 0x2, 0x2, 
    0x13f, 0x140, 0x5, 0x76, 0x3c, 0x2, 0x140, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x143, 0x7, 0x1d, 0x2, 0x2, 0x142, 0x144, 0x5, 0x1e, 0x10, 0x2, 
    0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 
    0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x5, 0x76, 0x3c, 0x2, 
    0x146, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x7, 0x22, 0x2, 0x2, 
    0x148, 0x14d, 0x5, 0x20, 0x11, 0x2, 0x149, 0x14a, 0x7, 0x25, 0x2, 0x2, 
    0x14a, 0x14c, 0x5, 0x20, 0x11, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x150, 0x3, 0x2, 0x2, 0x2, 
    0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x7, 0x23, 0x2, 0x2, 
    0x151, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x5, 0x12, 0xa, 0x2, 
    0x153, 0x154, 0x5, 0x22, 0x12, 0x2, 0x154, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x15a, 0x5, 0x24, 0x13, 0x2, 0x156, 0x157, 0x7, 0x35, 0x2, 0x2, 
    0x157, 0x159, 0x5, 0x24, 0x13, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 
    0x159, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x15c, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x3b, 0x2, 0x2, 0x15e, 
    0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 
    0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x5, 0x76, 0x3c, 0x2, 0x161, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x7, 0x5, 0x2, 0x2, 0x163, 0x165, 
    0x7, 0x1d, 0x2, 0x2, 0x164, 0x166, 0x5, 0x1e, 0x10, 0x2, 0x165, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x5, 0x92, 0x4a, 0x2, 0x168, 0x16a, 
    0x5, 0x30, 0x19, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 
    0x3, 0x2, 0x2, 0x2, 0x16a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 
    0x5, 0x2, 0x2, 0x16c, 0x16d, 0x5, 0x2a, 0x16, 0x2, 0x16d, 0x16e, 0x7, 
    0x1d, 0x2, 0x2, 0x16e, 0x170, 0x5, 0x92, 0x4a, 0x2, 0x16f, 0x171, 0x5, 
    0x30, 0x19, 0x2, 0x170, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 
    0x2, 0x2, 0x2, 0x171, 0x29, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x5, 0x96, 
    0x4c, 0x2, 0x173, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x174, 0x180, 0x7, 0x1b, 
    0x2, 0x2, 0x175, 0x181, 0x5, 0x2e, 0x18, 0x2, 0x176, 0x17c, 0x7, 0x1e, 
    0x2, 0x2, 0x177, 0x178, 0x5, 0x2e, 0x18, 0x2, 0x178, 0x179, 0x5, 0xce, 
    0x68, 0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x177, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17f, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x7, 0x1f, 
    0x2, 0x2, 0x180, 0x175, 0x3, 0x2, 0x2, 0x2, 0x180, 0x176, 0x3, 0x2, 
    0x2, 0x2, 0x181, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x182, 0x18a, 0x5, 0x12, 
    0xa, 0x2, 0x183, 0x186, 0x5, 0x76, 0x3c, 0x2, 0x184, 0x185, 0x7, 0x24, 
    0x2, 0x2, 0x185, 0x187, 0x5, 0x14, 0xb, 0x2, 0x186, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x189, 0x7, 0x24, 0x2, 0x2, 0x189, 0x18b, 0x5, 0x14, 
    0xb, 0x2, 0x18a, 0x183, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 0x7, 0x20, 
    0x2, 0x2, 0x18d, 0x18f, 0x5, 0x32, 0x1a, 0x2, 0x18e, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x191, 0x7, 0x21, 0x2, 0x2, 0x191, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x194, 0x7, 0x26, 0x2, 0x2, 0x193, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x19a, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x197, 0x7, 0x5a, 0x2, 0x2, 0x196, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 0x197, 0x19a, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x19a, 0x6, 0x1a, 0x2, 0x2, 0x199, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x5, 0x34, 
    0x1b, 0x2, 0x19c, 0x19d, 0x5, 0xce, 0x68, 0x2, 0x19d, 0x19f, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 
    0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 
    0x2, 0x2, 0x1a1, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1b2, 0x5, 0xc, 0x7, 
    0x2, 0x1a3, 0x1b2, 0x5, 0x44, 0x23, 0x2, 0x1a4, 0x1b2, 0x5, 0x36, 0x1c, 
    0x2, 0x1a5, 0x1b2, 0x5, 0x74, 0x3b, 0x2, 0x1a6, 0x1b2, 0x5, 0x46, 0x24, 
    0x2, 0x1a7, 0x1b2, 0x5, 0x48, 0x25, 0x2, 0x1a8, 0x1b2, 0x5, 0x4a, 0x26, 
    0x2, 0x1a9, 0x1b2, 0x5, 0x4c, 0x27, 0x2, 0x1aa, 0x1b2, 0x5, 0x4e, 0x28, 
    0x2, 0x1ab, 0x1b2, 0x5, 0x30, 0x19, 0x2, 0x1ac, 0x1b2, 0x5, 0x52, 0x2a, 
    0x2, 0x1ad, 0x1b2, 0x5, 0x54, 0x2b, 0x2, 0x1ae, 0x1b2, 0x5, 0x66, 0x34, 
    0x2, 0x1af, 0x1b2, 0x5, 0x6e, 0x38, 0x2, 0x1b0, 0x1b2, 0x5, 0x50, 0x29, 
    0x2, 0x1b1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1a5, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x1b3, 0x1b9, 0x5, 0x3a, 0x1e, 0x2, 0x1b4, 0x1b9, 0x5, 0x3c, 0x1f, 0x2, 
    0x1b5, 0x1b9, 0x5, 0x3e, 0x20, 0x2, 0x1b6, 0x1b9, 0x5, 0x38, 0x1d, 0x2, 
    0x1b7, 0x1b9, 0x5, 0x42, 0x22, 0x2, 0x1b8, 0x1b3, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x5, 0x9a, 0x4e, 0x2, 
    0x1bb, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x5, 0x9a, 0x4e, 0x2, 
    0x1bd, 0x1be, 0x7, 0x42, 0x2, 0x2, 0x1be, 0x1bf, 0x5, 0x9a, 0x4e, 0x2, 
    0x1bf, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x5, 0x9a, 0x4e, 0x2, 
    0x1c1, 0x1c2, 0x9, 0x3, 0x2, 0x2, 0x1c2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x1c4, 0x5, 0x14, 0xb, 0x2, 0x1c4, 0x1c5, 0x5, 0x40, 0x21, 0x2, 0x1c5, 
    0x1c6, 0x5, 0x14, 0xb, 0x2, 0x1c6, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
    0x1c9, 0x9, 0x4, 0x2, 0x2, 0x1c8, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
    0x1cb, 0x7, 0x24, 0x2, 0x2, 0x1cb, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
    0x1cd, 0x5, 0x12, 0xa, 0x2, 0x1cd, 0x1ce, 0x7, 0x2b, 0x2, 0x2, 0x1ce, 
    0x1cf, 0x5, 0x14, 0xb, 0x2, 0x1cf, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
    0x1d1, 0x7, 0x1d, 0x2, 0x2, 0x1d1, 0x1d3, 0x7, 0x27, 0x2, 0x2, 0x1d2, 
    0x1d4, 0x5, 0x34, 0x1b, 0x2, 0x1d3, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d7, 
    0x7, 0x1a, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x14, 0xb, 0x2, 0x1d7, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x1d9, 0x1db, 0x7, 0x3, 0x2, 0x2, 0x1da, 0x1dc, 0x7, 
    0x1d, 0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 
    0x2, 0x2, 0x2, 0x1dc, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1df, 0x7, 0x17, 
    0x2, 0x2, 0x1de, 0x1e0, 0x7, 0x1d, 0x2, 0x2, 0x1df, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x1e2, 0x7, 0xf, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x1d, 0x2, 
    0x2, 0x1e3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x7, 0x13, 0x2, 
    0x2, 0x1e5, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x9, 0x2, 0x2, 
    0x1e7, 0x1e8, 0x5, 0x9a, 0x4e, 0x2, 0x1e8, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x1f2, 0x7, 0x14, 0x2, 0x2, 0x1ea, 0x1f3, 0x5, 0x9a, 0x4e, 0x2, 
    0x1eb, 0x1ec, 0x5, 0xce, 0x68, 0x2, 0x1ec, 0x1ed, 0x5, 0x9a, 0x4e, 0x2, 
    0x1ed, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x5, 0x36, 0x1c, 0x2, 
    0x1ef, 0x1f0, 0x5, 0xce, 0x68, 0x2, 0x1f0, 0x1f1, 0x5, 0x9a, 0x4e, 0x2, 
    0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ee, 0x3, 0x2, 0x2, 0x2, 
    0x1f3, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1fa, 0x5, 0x30, 0x19, 0x2, 
    0x1f5, 0x1f8, 0x7, 0xe, 0x2, 0x2, 0x1f6, 0x1f9, 0x5, 0x52, 0x2a, 0x2, 
    0x1f7, 0x1f9, 0x5, 0x30, 0x19, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x5, 0x56, 0x2c, 0x2, 
    0x1fd, 0x1ff, 0x5, 0x5c, 0x2f, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x55, 0x3, 0x2, 0x2, 0x2, 0x200, 
    0x20b, 0x7, 0x11, 0x2, 0x2, 0x201, 0x203, 0x5, 0x9a, 0x4e, 0x2, 0x202, 
    0x201, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x3, 0x2, 0x2, 0x2, 0x203, 
    0x20c, 0x3, 0x2, 0x2, 0x2, 0x204, 0x206, 0x5, 0x36, 0x1c, 0x2, 0x205, 
    0x204, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
    0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 0x209, 0x5, 0xce, 0x68, 0x2, 0x208, 
    0x20a, 0x5, 0x9a, 0x4e, 0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x209, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20b, 
    0x202, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x205, 0x3, 0x2, 0x2, 0x2, 0x20c, 
    0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x211, 0x7, 0x20, 0x2, 0x2, 0x20e, 
    0x210, 0x5, 0x58, 0x2d, 0x2, 0x20f, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 
    0x213, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 
    0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x214, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x7, 0x21, 0x2, 0x2, 0x215, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x5, 0x5a, 0x2e, 0x2, 0x217, 
    0x219, 0x7, 0x27, 0x2, 0x2, 0x218, 0x21a, 0x5, 0x32, 0x1a, 0x2, 0x219, 
    0x218, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x7, 0x8, 0x2, 0x2, 0x21c, 0x21f, 
    0x5, 0x14, 0xb, 0x2, 0x21d, 0x21f, 0x7, 0x4, 0x2, 0x2, 0x21e, 0x21b, 
    0x3, 0x2, 0x2, 0x2, 0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x220, 0x229, 0x7, 0x11, 0x2, 0x2, 0x221, 0x22a, 0x5, 
    0x5e, 0x30, 0x2, 0x222, 0x223, 0x5, 0xce, 0x68, 0x2, 0x223, 0x224, 0x5, 
    0x5e, 0x30, 0x2, 0x224, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x5, 
    0x36, 0x1c, 0x2, 0x226, 0x227, 0x5, 0xce, 0x68, 0x2, 0x227, 0x228, 0x5, 
    0x5e, 0x30, 0x2, 0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x221, 0x3, 
    0x2, 0x2, 0x2, 0x229, 0x222, 0x3, 0x2, 0x2, 0x2, 0x229, 0x225, 0x3, 
    0x2, 0x2, 0x2, 0x22a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22f, 0x7, 
    0x20, 0x2, 0x2, 0x22c, 0x22e, 0x5, 0x60, 0x31, 0x2, 0x22d, 0x22c, 0x3, 
    0x2, 0x2, 0x2, 0x22e, 0x231, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x22d, 0x3, 
    0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x7, 
    0x21, 0x2, 0x2, 0x233, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 
    0x1d, 0x2, 0x2, 0x235, 0x237, 0x7, 0x2b, 0x2, 0x2, 0x236, 0x234, 0x3, 
    0x2, 0x2, 0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 
    0x2, 0x2, 0x2, 0x238, 0x239, 0x5, 0x9c, 0x4f, 0x2, 0x239, 0x23a, 0x7, 
    0x28, 0x2, 0x2, 0x23a, 0x23b, 0x7, 0x1e, 0x2, 0x2, 0x23b, 0x23c, 0x7, 
    0x16, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x1f, 0x2, 0x2, 0x23d, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x23f, 0x5, 0x62, 0x32, 0x2, 0x23f, 0x241, 0x7, 
    0x27, 0x2, 0x2, 0x240, 0x242, 0x5, 0x32, 0x1a, 0x2, 0x241, 0x240, 0x3, 
    0x2, 0x2, 0x2, 0x241, 0x242, 0x3, 0x2, 0x2, 0x2, 0x242, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x243, 0x244, 0x7, 0x8, 0x2, 0x2, 0x244, 0x247, 0x5, 0x64, 
    0x33, 0x2, 0x245, 0x247, 0x7, 0x4, 0x2, 0x2, 0x246, 0x243, 0x3, 0x2, 
    0x2, 0x2, 0x246, 0x245, 0x3, 0x2, 0x2, 0x2, 0x247, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x248, 0x24b, 0x5, 0x76, 0x3c, 0x2, 0x249, 0x24b, 0x7, 0x1c, 0x2, 
    0x2, 0x24a, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x249, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x253, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24f, 0x7, 0x25, 0x2, 
    0x2, 0x24d, 0x250, 0x5, 0x76, 0x3c, 0x2, 0x24e, 0x250, 0x7, 0x1c, 0x2, 
    0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24e, 0x3, 0x2, 0x2, 
    0x2, 0x250, 0x252, 0x3, 0x2, 0x2, 0x2, 0x251, 0x24c, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x255, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 
    0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x7, 0x7, 0x2, 0x2, 
    0x257, 0x25b, 0x7, 0x20, 0x2, 0x2, 0x258, 0x25a, 0x5, 0x68, 0x35, 0x2, 
    0x259, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25d, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 
    0x25c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x25f, 0x7, 0x21, 0x2, 0x2, 0x25f, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x260, 0x261, 0x5, 0x6a, 0x36, 0x2, 0x261, 0x263, 0x7, 0x27, 0x2, 0x2, 
    0x262, 0x264, 0x5, 0x32, 0x1a, 0x2, 0x263, 0x262, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x69, 0x3, 0x2, 0x2, 0x2, 0x265, 
    0x268, 0x7, 0x8, 0x2, 0x2, 0x266, 0x269, 0x5, 0x3a, 0x1e, 0x2, 0x267, 
    0x269, 0x5, 0x6c, 0x37, 0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 
    0x267, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26a, 
    0x26c, 0x7, 0x4, 0x2, 0x2, 0x26b, 0x265, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x26a, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 
    0x5, 0x14, 0xb, 0x2, 0x26e, 0x26f, 0x7, 0x24, 0x2, 0x2, 0x26f, 0x274, 
    0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x5, 0x12, 0xa, 0x2, 0x271, 0x272, 
    0x7, 0x2b, 0x2, 0x2, 0x272, 0x274, 0x3, 0x2, 0x2, 0x2, 0x273, 0x26d, 
    0x3, 0x2, 0x2, 0x2, 0x273, 0x270, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 
    0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 
    0x5, 0x9a, 0x4e, 0x2, 0x276, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x277, 0x27f, 
    0x7, 0x18, 0x2, 0x2, 0x278, 0x27a, 0x5, 0x9a, 0x4e, 0x2, 0x279, 0x278, 
    0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x280, 
    0x3, 0x2, 0x2, 0x2, 0x27b, 0x280, 0x5, 0x70, 0x39, 0x2, 0x27c, 0x27e, 
    0x5, 0x72, 0x3a, 0x2, 0x27d, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 
    0x3, 0x2, 0x2, 0x2, 0x27e, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x279, 
    0x3, 0x2, 0x2, 0x2, 0x27f, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 
    0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 
    0x5, 0x30, 0x19, 0x2, 0x282, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x283, 0x285, 
    0x5, 0x36, 0x1c, 0x2, 0x284, 0x283, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 
    0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 0x288, 
    0x5, 0xce, 0x68, 0x2, 0x287, 0x289, 0x5, 0x9a, 0x4e, 0x2, 0x288, 0x287, 
    0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28a, 
    0x3, 0x2, 0x2, 0x2, 0x28a, 0x28c, 0x5, 0xce, 0x68, 0x2, 0x28b, 0x28d, 
    0x5, 0x36, 0x1c, 0x2, 0x28c, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 
    0x3, 0x2, 0x2, 0x2, 0x28d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x5, 
    0x14, 0xb, 0x2, 0x28f, 0x290, 0x7, 0x24, 0x2, 0x2, 0x290, 0x295, 0x3, 
    0x2, 0x2, 0x2, 0x291, 0x292, 0x5, 0x12, 0xa, 0x2, 0x292, 0x293, 0x7, 
    0x2b, 0x2, 0x2, 0x293, 0x295, 0x3, 0x2, 0x2, 0x2, 0x294, 0x28e, 0x3, 
    0x2, 0x2, 0x2, 0x294, 0x291, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 
    0x2, 0x2, 0x2, 0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x7, 
    0x15, 0x2, 0x2, 0x297, 0x298, 0x5, 0x9a, 0x4e, 0x2, 0x298, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x299, 0x29a, 0x7, 0xa, 0x2, 0x2, 0x29a, 0x29b, 0x5, 
    0x9a, 0x4e, 0x2, 0x29b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29e, 0x5, 
    0x7a, 0x3e, 0x2, 0x29d, 0x29f, 0x5, 0x78, 0x3d, 0x2, 0x29e, 0x29d, 0x3, 
    0x2, 0x2, 0x2, 0x29e, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a6, 0x3, 
    0x2, 0x2, 0x2, 0x2a0, 0x2a6, 0x5, 0x7c, 0x3f, 0x2, 0x2a1, 0x2a2, 0x7, 
    0x1e, 0x2, 0x2, 0x2a2, 0x2a3, 0x5, 0x76, 0x3c, 0x2, 0x2a3, 0x2a4, 0x7, 
    0x1f, 0x2, 0x2, 0x2a4, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x2a5, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a1, 0x3, 
    0x2, 0x2, 0x2, 0x2a6, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x22, 
    0x2, 0x2, 0x2a8, 0x2aa, 0x5, 0x64, 0x33, 0x2, 0x2a9, 0x2ab, 0x7, 0x25, 
    0x2, 0x2, 0x2aa, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x3, 0x2, 
    0x2, 0x2, 0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x7, 0x23, 
    0x2, 0x2, 0x2ad, 0x79, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b1, 0x5, 0xaa, 
    0x56, 0x2, 0x2af, 0x2b1, 0x7, 0x1d, 0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x2b2, 0x2bb, 0x5, 0x7e, 0x40, 0x2, 0x2b3, 0x2bb, 0x5, 0xba, 0x5e, 
    0x2, 0x2b4, 0x2bb, 0x5, 0x84, 0x43, 0x2, 0x2b5, 0x2bb, 0x5, 0x90, 0x49, 
    0x2, 0x2b6, 0x2bb, 0x5, 0x86, 0x44, 0x2, 0x2b7, 0x2bb, 0x5, 0x88, 0x45, 
    0x2, 0x2b8, 0x2bb, 0x5, 0x8a, 0x46, 0x2, 0x2b9, 0x2bb, 0x5, 0x8c, 0x47, 
    0x2, 0x2ba, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b3, 0x3, 0x2, 0x2, 
    0x2, 0x2ba, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b5, 0x3, 0x2, 0x2, 
    0x2, 0x2ba, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b7, 0x3, 0x2, 0x2, 
    0x2, 0x2ba, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b9, 0x3, 0x2, 0x2, 
    0x2, 0x2bb, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x22, 0x2, 
    0x2, 0x2bd, 0x2be, 0x5, 0x80, 0x41, 0x2, 0x2be, 0x2bf, 0x7, 0x23, 0x2, 
    0x2, 0x2bf, 0x2c0, 0x5, 0x82, 0x42, 0x2, 0x2c0, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x2c1, 0x2c2, 0x5, 0x9a, 0x4e, 0x2, 0x2c2, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x2c3, 0x2c4, 0x5, 0x76, 0x3c, 0x2, 0x2c4, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x2c5, 0x2c6, 0x7, 0x40, 0x2, 0x2, 0x2c6, 0x2c7, 0x5, 0x76, 0x3c, 
    0x2, 0x2c7, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x7, 0x6, 0x2, 0x2, 
    0x2c9, 0x2d2, 0x7, 0x20, 0x2, 0x2, 0x2ca, 0x2cd, 0x5, 0x8e, 0x48, 0x2, 
    0x2cb, 0x2cd, 0x5, 0x22, 0x12, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 0x2, 0x2, 
    0x2cc, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x3, 0x2, 0x2, 0x2, 
    0x2ce, 0x2cf, 0x5, 0xce, 0x68, 0x2, 0x2cf, 0x2d1, 0x3, 0x2, 0x2, 0x2, 
    0x2d0, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d4, 0x3, 0x2, 0x2, 0x2, 
    0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d3, 0x3, 0x2, 0x2, 0x2, 
    0x2d3, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 
    0x2d5, 0x2d6, 0x7, 0x21, 0x2, 0x2, 0x2d6, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x2d7, 0x2d8, 0x7, 0x22, 0x2, 0x2, 0x2d8, 0x2d9, 0x7, 0x23, 0x2, 0x2, 
    0x2d9, 0x2da, 0x5, 0x82, 0x42, 0x2, 0x2da, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x2db, 0x2dc, 0x7, 0xb, 0x2, 0x2, 0x2dc, 0x2dd, 0x7, 0x22, 0x2, 0x2, 
    0x2dd, 0x2de, 0x5, 0x76, 0x3c, 0x2, 0x2de, 0x2df, 0x7, 0x23, 0x2, 0x2, 
    0x2df, 0x2e0, 0x5, 0x82, 0x42, 0x2, 0x2e0, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x2e1, 0x2e7, 0x7, 0xd, 0x2, 0x2, 0x2e2, 0x2e3, 0x7, 0xd, 0x2, 0x2, 
    0x2e3, 0x2e7, 0x7, 0x42, 0x2, 0x2, 0x2e4, 0x2e5, 0x7, 0x42, 0x2, 0x2, 
    0x2e5, 0x2e7, 0x7, 0xd, 0x2, 0x2, 0x2e6, 0x2e1, 0x3, 0x2, 0x2, 0x2, 
    0x2e6, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e4, 0x3, 0x2, 0x2, 0x2, 
    0x2e7, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x5, 0x82, 0x42, 0x2, 
    0x2e9, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x7, 0x1d, 0x2, 0x2, 
    0x2eb, 0x2ec, 0x5, 0x96, 0x4c, 0x2, 0x2ec, 0x2ed, 0x5, 0x94, 0x4b, 0x2, 
    0x2ed, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x1d, 0x2, 0x2, 
    0x2ef, 0x2f1, 0x5, 0x96, 0x4c, 0x2, 0x2f0, 0x2ea, 0x3, 0x2, 0x2, 0x2, 
    0x2f0, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2f2, 
    0x2f3, 0x7, 0x5, 0x2, 0x2, 0x2f3, 0x2f4, 0x5, 0x92, 0x4a, 0x2, 0x2f4, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f7, 0x5, 0x96, 0x4c, 0x2, 0x2f6, 
    0x2f8, 0x5, 0x94, 0x4b, 0x2, 0x2f7, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f7, 
    0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fc, 
    0x5, 0x96, 0x4c, 0x2, 0x2fa, 0x2fc, 0x5, 0x76, 0x3c, 0x2, 0x2fb, 0x2f9, 
    0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x2fd, 0x309, 0x7, 0x1e, 0x2, 0x2, 0x2fe, 0x303, 0x5, 
    0x98, 0x4d, 0x2, 0x2ff, 0x300, 0x7, 0x25, 0x2, 0x2, 0x300, 0x302, 0x5, 
    0x98, 0x4d, 0x2, 0x301, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x302, 0x305, 0x3, 
    0x2, 0x2, 0x2, 0x303, 0x301, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x3, 
    0x2, 0x2, 0x2, 0x304, 0x307, 0x3, 0x2, 0x2, 0x2, 0x305, 0x303, 0x3, 
    0x2, 0x2, 0x2, 0x306, 0x308, 0x7, 0x25, 0x2, 0x2, 0x307, 0x306, 0x3, 
    0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 0x2, 0x2, 0x308, 0x30a, 0x3, 
    0x2, 0x2, 0x2, 0x309, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 0x3, 
    0x2, 0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30c, 0x7, 
    0x1f, 0x2, 0x2, 0x30c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30f, 0x5, 
    0x12, 0xa, 0x2, 0x30e, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x3, 
    0x2, 0x2, 0x2, 0x30f, 0x311, 0x3, 0x2, 0x2, 0x2, 0x310, 0x312, 0x7, 
    0x2c, 0x2, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 
    0x2, 0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x5, 
    0x76, 0x3c, 0x2, 0x314, 0x99, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 0x8, 
    0x4e, 0x1, 0x2, 0x316, 0x31a, 0x5, 0x9c, 0x4f, 0x2, 0x317, 0x318, 0x9, 
    0x5, 0x2, 0x2, 0x318, 0x31a, 0x5, 0x9a, 0x4e, 0x8, 0x319, 0x315, 0x3, 
    0x2, 0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x32c, 0x3, 
    0x2, 0x2, 0x2, 0x31b, 0x31c, 0xc, 0x7, 0x2, 0x2, 0x31c, 0x31d, 0x9, 
    0x6, 0x2, 0x2, 0x31d, 0x32b, 0x5, 0x9a, 0x4e, 0x8, 0x31e, 0x31f, 0xc, 
    0x6, 0x2, 0x2, 0x31f, 0x320, 0x9, 0x7, 0x2, 0x2, 0x320, 0x32b, 0x5, 
    0x9a, 0x4e, 0x7, 0x321, 0x322, 0xc, 0x5, 0x2, 0x2, 0x322, 0x323, 0x9, 
    0x8, 0x2, 0x2, 0x323, 0x32b, 0x5, 0x9a, 0x4e, 0x6, 0x324, 0x325, 0xc, 
    0x4, 0x2, 0x2, 0x325, 0x326, 0x7, 0x2e, 0x2, 0x2, 0x326, 0x32b, 0x5, 
    0x9a, 0x4e, 0x5, 0x327, 0x328, 0xc, 0x3, 0x2, 0x2, 0x328, 0x329, 0x7, 
    0x2d, 0x2, 0x2, 0x329, 0x32b, 0x5, 0x9a, 0x4e, 0x4, 0x32a, 0x31b, 0x3, 
    0x2, 0x2, 0x2, 0x32a, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x321, 0x3, 
    0x2, 0x2, 0x2, 0x32a, 0x324, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x32b, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32a, 0x3, 
    0x2, 0x2, 0x2, 0x32c, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x32e, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x330, 0x8, 0x4f, 
    0x1, 0x2, 0x330, 0x334, 0x5, 0xa0, 0x51, 0x2, 0x331, 0x334, 0x5, 0x9e, 
    0x50, 0x2, 0x332, 0x334, 0x5, 0xcc, 0x67, 0x2, 0x333, 0x32f, 0x3, 0x2, 
    0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x333, 0x332, 0x3, 0x2, 
    0x2, 0x2, 0x334, 0x340, 0x3, 0x2, 0x2, 0x2, 0x335, 0x33c, 0xc, 0x3, 
    0x2, 0x2, 0x336, 0x337, 0x7, 0x28, 0x2, 0x2, 0x337, 0x33d, 0x7, 0x1d, 
    0x2, 0x2, 0x338, 0x33d, 0x5, 0xc4, 0x63, 0x2, 0x339, 0x33d, 0x5, 0xc6, 
    0x64, 0x2, 0x33a, 0x33d, 0x5, 0xc8, 0x65, 0x2, 0x33b, 0x33d, 0x5, 0xca, 
    0x66, 0x2, 0x33c, 0x336, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x338, 0x3, 0x2, 
    0x2, 0x2, 0x33c, 0x339, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33a, 0x3, 0x2, 
    0x2, 0x2, 0x33c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33f, 0x3, 0x2, 
    0x2, 0x2, 0x33e, 0x335, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x342, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 0x3, 0x2, 
    0x2, 0x2, 0x341, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x342, 0x340, 0x3, 0x2, 0x2, 
    0x2, 0x343, 0x344, 0x5, 0x76, 0x3c, 0x2, 0x344, 0x345, 0x7, 0x1e, 0x2, 
    0x2, 0x345, 0x347, 0x5, 0x9a, 0x4e, 0x2, 0x346, 0x348, 0x7, 0x25, 0x2, 
    0x2, 0x347, 0x346, 0x3, 0x2, 0x2, 0x2, 0x347, 0x348, 0x3, 0x2, 0x2, 
    0x2, 0x348, 0x349, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34a, 0x7, 0x1f, 0x2, 
    0x2, 0x34a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x352, 0x5, 0xa2, 0x52, 
    0x2, 0x34c, 0x352, 0x5, 0xa8, 0x55, 0x2, 0x34d, 0x34e, 0x7, 0x1e, 0x2, 
    0x2, 0x34e, 0x34f, 0x5, 0x9a, 0x4e, 0x2, 0x34f, 0x350, 0x7, 0x1f, 0x2, 
    0x2, 0x350, 0x352, 0x3, 0x2, 0x2, 0x2, 0x351, 0x34b, 0x3, 0x2, 0x2, 
    0x2, 0x351, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x351, 0x34d, 0x3, 0x2, 0x2, 
    0x2, 0x352, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x353, 0x357, 0x5, 0xa4, 0x53, 
    0x2, 0x354, 0x357, 0x5, 0xac, 0x57, 0x2, 0x355, 0x357, 0x5, 0xc2, 0x62, 
    0x2, 0x356, 0x353, 0x3, 0x2, 0x2, 0x2, 0x356, 0x354, 0x3, 0x2, 0x2, 
    0x2, 0x356, 0x355, 0x3, 0x2, 0x2, 0x2, 0x357, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0x358, 0x35d, 0x7, 0x1c, 0x2, 0x2, 0x359, 0x35d, 0x5, 0xa6, 0x54, 0x2, 
    0x35a, 0x35d, 0x5, 0xbe, 0x60, 0x2, 0x35b, 0x35d, 0x7, 0x47, 0x2, 0x2, 
    0x35c, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x359, 0x3, 0x2, 0x2, 0x2, 
    0x35c, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35b, 0x3, 0x2, 0x2, 0x2, 
    0x35d, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 0x9, 0x9, 0x2, 0x2, 0x35f, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x7, 0x1d, 0x2, 0x2, 0x361, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 0x7, 0x1d, 0x2, 0x2, 0x363, 
    0x364, 0x7, 0x28, 0x2, 0x2, 0x364, 0x365, 0x7, 0x1d, 0x2, 0x2, 0x365, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 0xae, 0x58, 0x2, 0x367, 
    0x368, 0x5, 0xb0, 0x59, 0x2, 0x368, 0xad, 0x3, 0x2, 0x2, 0x2, 0x369, 
    0x376, 0x5, 0xba, 0x5e, 0x2, 0x36a, 0x376, 0x5, 0x7e, 0x40, 0x2, 0x36b, 
    0x36c, 0x7, 0x22, 0x2, 0x2, 0x36c, 0x36d, 0x7, 0x2c, 0x2, 0x2, 0x36d, 
    0x36e, 0x7, 0x23, 0x2, 0x2, 0x36e, 0x376, 0x5, 0x82, 0x42, 0x2, 0x36f, 
    0x376, 0x5, 0x88, 0x45, 0x2, 0x370, 0x376, 0x5, 0x8a, 0x46, 0x2, 0x371, 
    0x373, 0x5, 0x7a, 0x3e, 0x2, 0x372, 0x374, 0x5, 0x78, 0x3d, 0x2, 0x373, 
    0x372, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 
    0x376, 0x3, 0x2, 0x2, 0x2, 0x375, 0x369, 0x3, 0x2, 0x2, 0x2, 0x375, 
    0x36a, 0x3, 0x2, 0x2, 0x2, 0x375, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x375, 
    0x36f, 0x3, 0x2, 0x2, 0x2, 0x375, 0x370, 0x3, 0x2, 0x2, 0x2, 0x375, 
    0x371, 0x3, 0x2, 0x2, 0x2, 0x376, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x377, 0x37c, 
    0x7, 0x20, 0x2, 0x2, 0x378, 0x37a, 0x5, 0xb2, 0x5a, 0x2, 0x379, 0x37b, 
    0x7, 0x25, 0x2, 0x2, 0x37a, 0x379, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 
    0x3, 0x2, 0x2, 0x2, 0x37b, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x378, 
    0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 
    0x3, 0x2, 0x2, 0x2, 0x37e, 0x37f, 0x7, 0x21, 0x2, 0x2, 0x37f, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0x380, 0x385, 0x5, 0xb4, 0x5b, 0x2, 0x381, 0x382, 
    0x7, 0x25, 0x2, 0x2, 0x382, 0x384, 0x5, 0xb4, 0x5b, 0x2, 0x383, 0x381, 
    0x3, 0x2, 0x2, 0x2, 0x384, 0x387, 0x3, 0x2, 0x2, 0x2, 0x385, 0x383, 
    0x3, 0x2, 0x2, 0x2, 0x385, 0x386, 0x3, 0x2, 0x2, 0x2, 0x386, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0x387, 0x385, 0x3, 0x2, 0x2, 0x2, 0x388, 0x389, 0x5, 
    0xb6, 0x5c, 0x2, 0x389, 0x38a, 0x7, 0x27, 0x2, 0x2, 0x38a, 0x38c, 0x3, 
    0x2, 0x2, 0x2, 0x38b, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x38c, 0x3, 
    0x2, 0x2, 0x2, 0x38c, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x5, 
    0xb8, 0x5d, 0x2, 0x38e, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x392, 0x5, 
    0x9a, 0x4e, 0x2, 0x390, 0x392, 0x5, 0xb0, 0x59, 0x2, 0x391, 0x38f, 0x3, 
    0x2, 0x2, 0x2, 0x391, 0x390, 0x3, 0x2, 0x2, 0x2, 0x392, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0x393, 0x396, 0x5, 0x9a, 0x4e, 0x2, 0x394, 0x396, 0x5, 0xb0, 
    0x59, 0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 0x2, 0x395, 0x394, 0x3, 0x2, 
    0x2, 0x2, 0x396, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x7, 0xc, 0x2, 
    0x2, 0x398, 0x39e, 0x7, 0x20, 0x2, 0x2, 0x399, 0x39a, 0x5, 0xbc, 0x5f, 
    0x2, 0x39a, 0x39b, 0x5, 0xce, 0x68, 0x2, 0x39b, 0x39d, 0x3, 0x2, 0x2, 
    0x2, 0x39c, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x3a0, 0x3, 0x2, 0x2, 
    0x2, 0x39e, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 0x3, 0x2, 0x2, 
    0x2, 0x39f, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x39e, 0x3, 0x2, 0x2, 
    0x2, 0x3a1, 0x3a2, 0x7, 0x21, 0x2, 0x2, 0x3a2, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0x3a3, 0x3a4, 0x5, 0x12, 0xa, 0x2, 0x3a4, 0x3a5, 0x5, 0x76, 0x3c, 
    0x2, 0x3a5, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a8, 0x5, 0xc0, 0x61, 
    0x2, 0x3a7, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a6, 0x3, 0x2, 0x2, 
    0x2, 0x3a8, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3ab, 0x5, 0xbe, 0x60, 
    0x2, 0x3aa, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ab, 0x3, 0x2, 0x2, 
    0x2, 0x3ab, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x9, 0xa, 0x2, 0x2, 
    0x3ad, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3b0, 0x7, 0x40, 0x2, 0x2, 
    0x3af, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x3, 0x2, 0x2, 0x2, 
    0x3b0, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b3, 0x5, 0x7a, 0x3e, 0x2, 
    0x3b2, 0x3b4, 0x5, 0x78, 0x3d, 0x2, 0x3b3, 0x3b2, 0x3, 0x2, 0x2, 0x2, 
    0x3b3, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x3b5, 
    0x3b6, 0x7, 0x5, 0x2, 0x2, 0x3b6, 0x3b7, 0x5, 0x92, 0x4a, 0x2, 0x3b7, 
    0x3b8, 0x5, 0x30, 0x19, 0x2, 0x3b8, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
    0x3ba, 0x7, 0x22, 0x2, 0x2, 0x3ba, 0x3bb, 0x5, 0x9a, 0x4e, 0x2, 0x3bb, 
    0x3bc, 0x7, 0x23, 0x2, 0x2, 0x3bc, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x3bd, 
    0x3cd, 0x7, 0x22, 0x2, 0x2, 0x3be, 0x3c0, 0x5, 0x9a, 0x4e, 0x2, 0x3bf, 
    0x3be, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c0, 
    0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c3, 0x7, 0x27, 0x2, 0x2, 0x3c2, 
    0x3c4, 0x5, 0x9a, 0x4e, 0x2, 0x3c3, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c3, 
    0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3c5, 
    0x3c7, 0x5, 0x9a, 0x4e, 0x2, 0x3c6, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c6, 
    0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c8, 
    0x3c9, 0x7, 0x27, 0x2, 0x2, 0x3c9, 0x3ca, 0x5, 0x9a, 0x4e, 0x2, 0x3ca, 
    0x3cb, 0x7, 0x27, 0x2, 0x2, 0x3cb, 0x3cc, 0x5, 0x9a, 0x4e, 0x2, 0x3cc, 
    0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3cd, 
    0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3cf, 
    0x3d0, 0x7, 0x23, 0x2, 0x2, 0x3d0, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
    0x3d2, 0x7, 0x28, 0x2, 0x2, 0x3d2, 0x3d3, 0x7, 0x1e, 0x2, 0x2, 0x3d3, 
    0x3d4, 0x5, 0x76, 0x3c, 0x2, 0x3d4, 0x3d5, 0x7, 0x1f, 0x2, 0x2, 0x3d5, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3e5, 0x7, 0x1e, 0x2, 0x2, 0x3d7, 
    0x3de, 0x5, 0x14, 0xb, 0x2, 0x3d8, 0x3db, 0x5, 0x76, 0x3c, 0x2, 0x3d9, 
    0x3da, 0x7, 0x25, 0x2, 0x2, 0x3da, 0x3dc, 0x5, 0x14, 0xb, 0x2, 0x3db, 
    0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
    0x3de, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3dd, 
    0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3df, 
    0x3e1, 0x7, 0x2c, 0x2, 0x2, 0x3e0, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
    0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3e4, 0x7, 0x25, 0x2, 0x2, 0x3e3, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e3, 
    0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e5, 
    0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e6, 
    0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 0x7, 0x1f, 0x2, 0x2, 0x3e8, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x5, 0x76, 0x3c, 0x2, 0x3ea, 
    0x3eb, 0x7, 0x28, 0x2, 0x2, 0x3eb, 0x3ec, 0x7, 0x1d, 0x2, 0x2, 0x3ec, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3f2, 0x7, 0x26, 0x2, 0x2, 0x3ee, 
    0x3f2, 0x7, 0x2, 0x2, 0x3, 0x3ef, 0x3f2, 0x7, 0x5a, 0x2, 0x2, 0x3f0, 
    0x3f2, 0x6, 0x68, 0x9, 0x2, 0x3f1, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3f1, 
    0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 
    0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x79, 0xd7, 
    0xdd, 0xe3, 0xf3, 0xf7, 0xfa, 0x103, 0x10d, 0x111, 0x115, 0x119, 0x120, 
    0x128, 0x133, 0x137, 0x13b, 0x143, 0x14d, 0x15a, 0x15e, 0x165, 0x169, 
    0x170, 0x17c, 0x180, 0x186, 0x18a, 0x18e, 0x193, 0x196, 0x199, 0x1a0, 
    0x1b1, 0x1b8, 0x1c8, 0x1d3, 0x1d7, 0x1db, 0x1df, 0x1f2, 0x1f8, 0x1fa, 
    0x1fe, 0x202, 0x205, 0x209, 0x20b, 0x211, 0x219, 0x21e, 0x229, 0x22f, 
    0x236, 0x241, 0x246, 0x24a, 0x24f, 0x253, 0x25b, 0x263, 0x268, 0x26b, 
    0x273, 0x279, 0x27d, 0x27f, 0x284, 0x288, 0x28c, 0x294, 0x29e, 0x2a5, 
    0x2aa, 0x2b0, 0x2ba, 0x2cc, 0x2d2, 0x2e6, 0x2f0, 0x2f7, 0x2fb, 0x303, 
    0x307, 0x309, 0x30e, 0x311, 0x319, 0x32a, 0x32c, 0x333, 0x33c, 0x340, 
    0x347, 0x351, 0x356, 0x35c, 0x373, 0x375, 0x37a, 0x37c, 0x385, 0x38b, 
    0x391, 0x395, 0x39e, 0x3a7, 0x3aa, 0x3af, 0x3b3, 0x3bf, 0x3c3, 0x3c6, 
    0x3cd, 0x3db, 0x3dd, 0x3e0, 0x3e3, 0x3e5, 0x3f1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GoParser::Initializer GoParser::_init;
