//
// Created by volodya on 12.03.24.
//

#ifndef APP_VALUEWRAPPER_H
#define APP_VALUEWRAPPER_H

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include "TypeWrapper.h"
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
