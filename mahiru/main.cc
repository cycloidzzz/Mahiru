#include <cctype>
#include <fstream>
#include <iostream>

#include "mahiru/front/ast.h"
#include "mahiru/front/lexer.h"

int main() {
  std::ifstream fin("/Users/ZiriusOu/Mahiru/example/test.txt");
  Lexer lexer(fin);

  // while (!lexer.isStop()) {
  //   lexer.extractNextToken();
  //   std::cout << lexer.nextToken() << std::endl;
  // }

  // fin.close();

  auto left = std::make_unique<VariableAST>("x");
  auto right = std::make_unique<VariableAST>("y");
  auto expression = std::make_unique<BinaryExprAST>(
      OpType::kOpAdd, std::move(left), std::move(right));

  std::cout << *expression << std::endl;

  return 0;
}