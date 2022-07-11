#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/front/lexer.h"

int main() {
  std::ifstream fin("/Users/ZiriusOu/Mahiru/example/test.txt");
  Lexer lexer(fin);

  while (!lexer.isStop()) {
    lexer.extractNextToken();
    std::cout << lexer.nextToken() << std::endl;
  }

  fin.close();

  return 0;
}