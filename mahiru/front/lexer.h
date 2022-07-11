#ifndef MAHIRU_SRC_FRONT_LEXER_H
#define MAHIRU_SRC_FRONT_LEXER_H

#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/common/common.h"

class Lexer {
 public:
  Lexer(std::ifstream& fileIn)
      : mFileIn(fileIn), mIsStop(false), mLastChar(' ') {}
  ~Lexer() = default;

  MAHIRU_DISALLOW_COPY_AND_MOVE(Lexer);

  void extractNextChar();
  TokenType extractNextToken();

  bool isStop() const { return mIsStop; }
  TokenType tokenType() const { return mTokenType; }
  const std::string& nextToken() const { return mNextToken; }

 private:
  bool mIsStop;
  std::ifstream& mFileIn;
  char mLastChar;
  TokenType mTokenType;
  std::string mNextToken;
};

#endif  // ! MAHIRU_SRC_FRONT_LEXER_H