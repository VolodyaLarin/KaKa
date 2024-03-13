//
// Created by volodya on 12.03.24.
//

#include "FunctionWrapper.h"

FunctionWrapper::FunctionWrapper(const std::string &moduleId,
                                 const std::string &name,
                                 TypeWrapper type,
                                 llvm::Function *function)
    : ModuleId(moduleId), Name(name), type(type), Function(function) {}

ValueWrapper::ptr FunctionWrapper::getValue() {
  return ValueWrapper::Create(true, type, Function);
}

ValueWrapper::ptr FunctionWrapper::bind(ValueWrapper::ptr binder) {
  return ValueWrapper::Create(true, type, Function, binder);
}
