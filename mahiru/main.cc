#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/front/lexer.h"

int main() {
  std::ifstream fin("/Users/ZiriusOu/Mahiru/example/test.txt");
  Lexer lexer(fin);

  while (TokenType::kEOF != lexer.extractNextToken()) {
    std::cout << lexer.getNextToken() << std::endl;
  }

  fin.close();

  return 0;
}