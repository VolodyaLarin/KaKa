//
// Created by volodya on 12.03.24.
//

#ifndef APP_FUNCTIONWRAPPER_H
#define APP_FUNCTIONWRAPPER_H

#include <string>
#include <llvm/IR/Function.h>
#include "TypeWrapper.h"
#include "ValueWrapper.h"

class FunctionWrapper {
 public:

  std::string ModuleId = "";
  std::string Name = "";

  TypeWrapper type;
  llvm::Function *Function;

  FunctionWrapper(const std::string &moduleId, const std::string &name, TypeWrapper type, llvm::Function *function);

  ValueWrapper::ptr getValue();

  ValueWrapper::ptr bind(ValueWrapper::ptr binder);
};

#endif //APP_FUNCTIONWRAPPER_H
