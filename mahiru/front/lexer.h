#ifndef MAHIRU_SRC_FRONT_LEXER_H
#define MAHIRU_SRC_FRONT_LEXER_H

#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/common/common.h"

class Lexer {
 public:
  Lexer(std::ifstream& fileIn) : mFileIn(fileIn), mLastChar(' ') {}
  ~Lexer() = default;

  MAHIRU_DISALLOW_COPY_AND_MOVE(Lexer);

  TokenType extractNextToken();
  const std::string& getNextToken() const { return mNextToken; }

 private:
  std::ifstream& mFileIn;
  char mLastChar;
  std::string mNextToken;
};

#endif  // ! MAHIRU_SRC_FRONT_LEXER_H