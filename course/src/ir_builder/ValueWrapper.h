//
// Created by volodya on 12.03.24.
//

#ifndef APP_VALUEWRAPPER_H
#define APP_VALUEWRAPPER_H

#include "TypeWrapper.h"
#include "../parser/codegen/GoParserBaseVisitor.h"
#include <boost/algorithm/string/replace.hpp>
#include <regex>
#include <string>
#include <memory>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/APFloat.h"
#include "Error.h"

class ValueWrapper {
 public:
  typedef std::shared_ptr<ValueWrapper> ptr;
 private:
  bool _isConstant = false;
  TypeWrapper _type;
  llvm::Value *_llvmValue;
  ValueWrapper::ptr _binding;

  ValueWrapper(bool isConstant, TypeWrapper typeW, llvm::Value *value, ValueWrapper::ptr binding) : _isConstant(
      isConstant), _type(typeW), _llvmValue(value), _binding(binding) {}

 public:

  const ptr &getBinding() const;

  static ptr Create(bool isConstant, TypeWrapper typeW, llvm::Value *value, ValueWrapper::ptr bind = nullptr);

  bool isConstant() const;

  TypeWrapper getType() const;

  llvm::Value *getValue() const;

  ValueWrapper::ptr toRHS(llvm::IRBuilder<> &builder) const;

  ValueWrapper::ptr getPointerTo() const;

  ValueWrapper::ptr castTo(llvm::IRBuilder<> &builder, TypeWrapper ty) const;
};

class EValue {
  ValueWrapper::ptr value_ptr;
  Error::ptr error_ptr;
 public:
  explicit operator bool() const;

  ValueWrapper operator*();

  ValueWrapper *operator->() {
    return value_ptr.get();
  }
  [[nodiscard]] Error getError() const;
  const ValueWrapper::ptr &GetValuePtr() const;
  EValue(ValueWrapper::ptr valuePtr = nullptr, Error::ptr errorPtr = nullptr);
  EValue(Error::ptr errorPtr);
};

#endif //APP_VALUEWRAPPER_H
