#ifndef MAHIRU_SRC_COMMON_COMMON_H
#define MAHIRU_SRC_COMMON_COMMON_H
#include <string>

enum class TokenType {
  kEOF = -1,
  kDef = 0,
  kExtern = 1,
  kIdentifier = 2,
  kNumber = 3,
  kOperator = 4,
};

enum class OpType {
  kOpAdd = 0,
  kOpSub = 1,
  kOpMul = 2,
  kOpDiv = 3,
  KOpBitAnd = 6,
  kOpBitOr = 7,
  kOpAssign = 8
};

struct Token {
 public:
  Token() = default;
  explicit Token(TokenType type, std::string tokenValue)
      : mType(type), mTokenValue(std::move(tokenValue)) {}

  TokenType getType() const { return mType; }
  const std::string& getTokenValue() const { return mTokenValue; }

  TokenType mType;
  std::string mTokenValue;
};

#define MAHIRU_DISALLOW_COPY(TypeName) \
  TypeName(const TypeName&) = delete;  \
  TypeName& operator=(const TypeName&) = delete;

#define MAHIRU_DISALLOW_MOVE(TypeName) \
  TypeName(TypeName&&) = delete;       \
  TypeName& operator=(TypeName&&) = delete;

#define MAHIRU_DISALLOW_COPY_AND_MOVE(TypeName) \
  MAHIRU_DISALLOW_COPY(TypeName)                \
  MAHIRU_DISALLOW_MOVE(TypeName)

#endif  // ! MAHIRU_SRC_COMMON_COMMON_H