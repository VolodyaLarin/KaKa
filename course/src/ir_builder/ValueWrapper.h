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

class Package;
class EValue {
  Package *package_ptr = nullptr;
  std::shared_ptr<TypeWrapper> type_wrapper_ = nullptr;
  ValueWrapper::ptr value_ptr = nullptr;
  Error::ptr error_ptr = nullptr;
 public:
  EValue(ValueWrapper::ptr valuePtr = nullptr);
  EValue(Error::ptr errorPtr);
  EValue(Package *package_ptr);
  EValue(std::shared_ptr<TypeWrapper> type_wrapper);
  EValue(const TypeWrapper& type_wrapper);

  explicit operator bool() const;

  [[nodiscard]] const std::shared_ptr<TypeWrapper> &GetTypePtr() const;
  [[nodiscard]] const ValueWrapper::ptr &GetValuePtr() const;
  [[nodiscard]] Error getError() const;
  [[nodiscard]] Package *GetPackagePtr() const;

  [[nodiscard]] bool hasError() const;

  ValueWrapper operator*();
  ValueWrapper *operator->();

};

#endif //APP_VALUEWRAPPER_H
