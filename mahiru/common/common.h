#ifndef MAHIRU_SRC_COMMON_COMMON_H
#define MAHIRU_SRC_COMMON_COMMON_H

enum class TokenType {
  kEOF = -1,
  kDef = 0,
  kExtern = 1,
  kIdentifier = 2,
  kNumber = 3
};

#endif  // ! MAHIRU_SRC_COMMON_COMMON_H