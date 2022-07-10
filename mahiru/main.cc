#include <cctype>
#include <iostream>

int main() {
  char a1 = '\n';
  char a2 = ' ';
  char a3 = '\f';
  char a4 = '\r';
  if (std::isspace(static_cast<unsigned char>(a4))) {
    std::cout << "a4 is space" << std::endl;
  } else {
    std::cout << "a4 is not space" << std::endl;
  }
}