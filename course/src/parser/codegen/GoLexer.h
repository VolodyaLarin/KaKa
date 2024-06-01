
// Generated from GoLexer.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"




class  GoLexer : public antlr4::Lexer {
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
    NLSEMI = 1
  };

  explicit GoLexer(antlr4::CharStream *input);

  ~GoLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

