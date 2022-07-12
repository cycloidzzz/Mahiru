#include "mahiru/front/ast.h"

std::ostream& operator<<(std::ostream& os, ExprAST& expression) {
  expression.dump(os);
  return os;
}