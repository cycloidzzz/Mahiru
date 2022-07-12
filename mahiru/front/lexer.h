#ifndef MAHIRU_SRC_FRONT_LEXER_H
#define MAHIRU_SRC_FRONT_LEXER_H

#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/common/common.h"

class Lexer {
 public:
  Lexer(std::ifstream& inStream)
      : mIsStop(false), mLastChar(' '), mInStream(inStream) {}
  ~Lexer() = default;

  MAHIRU_DISALLOW_COPY_AND_MOVE(Lexer);

  void extractNextChar();
  TokenType extractNextToken();

  bool isStop() const { return mIsStop; }
  TokenType tokenType() const { return mTokenType; }
  const std::string& nextToken() const { return mNextToken; }

 private:
  bool mIsStop;
  char mLastChar;
  TokenType mTokenType;
  std::string mNextToken;
  std::ifstream& mInStream;
};

#endif  // ! MAHIRU_SRC_FRONT_LEXER_H