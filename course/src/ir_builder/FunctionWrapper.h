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

  std::string Name = "";
  std::string LinkName = "";

  TypeWrapper type;
  llvm::Function *Function;

  FunctionWrapper(std::string name, TypeWrapper type, llvm::Function *function = nullptr, std::string linkName = "");

  ValueWrapper::ptr getValue();

  ValueWrapper::ptr bind(ValueWrapper::ptr binder);
};

#endif //APP_FUNCTIONWRAPPER_H
