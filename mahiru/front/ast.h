#ifndef MAHIRU_SRC_FRONT_AST_H
#define MAHIRU_SRC_FRONT_AST_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mahiru/common/common.h"

class ExprAST;
using ExprASTPtr = std::unique_ptr<ExprAST>;
using ExprPtrVector = std::vector<ExprASTPtr>;

class ExprAST {
 public:
  ExprAST() = default;
  virtual ~ExprAST() = default;

  friend std::ostream& operator<<(std::ostream& os, ExprAST& expression);

 protected:
  virtual void dump(std::ostream& os){};
};

class NumberAST : public ExprAST {
 public:
  NumberAST(const std::string& number) : mNumber(number) {}
  ~NumberAST() = default;

 private:
  std::string mNumber;
};

class VariableAST : public ExprAST {
 public:
  explicit VariableAST(const std::string& variable) : mVariable(variable){};
  ~VariableAST() = default;

 protected:
  void dump(std::ostream& os) override { os << mVariable; }

 private:
  std::string mVariable;
};

class BinaryExprAST : public ExprAST {
 public:
  explicit BinaryExprAST(OpType opType, ExprASTPtr leftChild,
                         ExprASTPtr rightChild)
      : mOpType(opType),
        mLeftChild(std::move(leftChild)),
        mRightChild(std::move(rightChild)) {}

 protected:
  void dump(std::ostream& os) override {
    os << *mLeftChild;
    os << " + ";
    os << *mRightChild;
  }

 private:
  OpType mOpType;
  ExprASTPtr mLeftChild;
  ExprASTPtr mRightChild;
};

class CallExprAST : public ExprAST {
 public:
  explicit CallExprAST(const std::string callee, ExprPtrVector arguments)
      : mCallee(callee), mArguments(std::move(arguments)) {}

 private:
  std::string mCallee;
  ExprPtrVector mArguments;
};

class PrototypeAST : public ExprAST {
 public:
  explicit PrototypeAST(const std::string& funcName, ExprPtrVector arguments)
      : mFuncName(funcName), mArguments(std::move(arguments)) {}
  ~PrototypeAST() = default;

  const std::string& funcName() const { return mFuncName; }

 private:
  std::string mFuncName;
  ExprPtrVector mArguments;
};

class FunctionAST : public ExprAST {
 public:
  explicit FunctionAST(std::unique_ptr<PrototypeAST> prototype, ExprASTPtr body)
      : mPrototype(std::move(prototype)), mBody(std::move(body)) {}
  ~FunctionAST() = default;

 private:
  std::unique_ptr<PrototypeAST> mPrototype;
  ExprASTPtr mBody;
};

#endif  // ! MAHIRU_SRC_FRONT_AST_H