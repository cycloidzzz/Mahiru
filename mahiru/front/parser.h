#ifndef MAHIRU_SRC_FRONT_PARSER_H
#define MAHIRU_SRC_FRONT_PARSER_H

#include "mahiru/common/common.h"
#include "mahiru/front/ast.h"
#include "mahiru/front/lexer.h"

class Parser {
 public:
  explicit Parser(Lexer& lexer) : mLexer(lexer) {}
  ~Parser() = default;

  MAHIRU_DISALLOW_COPY_AND_MOVE(Parser);

  // numberExpr := Number
  ExprASTPtr parseNumberExpr();
  // bracketExpr := ( Expr )
  ExprASTPtr parseBracketExpr();
  // identifierExpr := identifier
  //               := identifier '(' Arguments* ')'
  ExprASTPtr parseIdentifierExpr();

  // RelExpr := AddExpr {(>|<) AddExpr} *
  // AddExpr := MulExpr {(+|-) MulExpr} *
  // MulExpr := FactorExpr {(*|/|%) FactExpr} *
  ExprASTPtr parseRelExpr();
  ExprASTPtr parseAddExpr();
  ExprASTPtr parseMulExpr();

  // FactorExpr := numberExpr
  //            := bracketExpr
  //            := identifierExpr
  ExprASTPtr parseFactorExpr();

 private:
  Lexer& mLexer;
};

#endif  // ! MAHIRU_SRC_FRONT_PARSER_H