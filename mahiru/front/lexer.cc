#include "mahiru/front/lexer.h"

namespace detail {
bool isSpace(char ch) { return std::isspace(static_cast<unsigned char>(ch)); }
bool isAlpha(char ch) { return std::isalpha(static_cast<unsigned char>(ch)); }
bool isDigit(char ch) { return std::isdigit(static_cast<unsigned char>(ch)); }
bool isAlNum(char ch) { return std::isalnum(static_cast<unsigned char>(ch)); }
}  // namespace detail

TokenType Lexer::extractNextToken() {
  /// Skip all spaces from the input stream and get the start of the next
  /// token
  while (detail::isSpace(mLastChar)) {
    mFileIn.get(mLastChar);
  }

  std::string NextToken;

  if (detail::isAlpha(mLastChar)) {
    // Keyword or Identifier.
    while (detail::isAlNum(mLastChar)) {
      NextToken += mLastChar;
      mFileIn.get(mLastChar);
    }

    // TODO (cycloid): refactor with table-driven instead of multiple if-else
    // keyword : def
    mNextToken = std::move(NextToken);
    if (mNextToken == "def") {
      return TokenType::kDef;
    } else if (mNextToken == "extern") {
      return TokenType::kExtern;
    } else {
      return TokenType::kIdentifier;
    }
  }

  if (detail::isDigit(mLastChar)) {
    while (detail::isAlNum(mLastChar)) {
      NextToken += mLastChar;
      mFileIn.get(mLastChar);
    }

    mNextToken = std::move(NextToken);
    return TokenType::kNumber;
  }

  // TODO (cycloid) : comments
  if (mLastChar == '#') {
    // Comments
  }

  if (mLastChar != EOF) {
    // FIXME : operators with more than two chars, e.g. '>='
    NextToken += mLastChar;
    mNextToken = NextToken;

    do {
      mFileIn.get(mLastChar);
    } while (detail::isSpace(mLastChar));

    return TokenType::kOperator;
  } else {
    return TokenType::kEOF;
  }
}