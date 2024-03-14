//
// Created by volodya on 12.03.24.
//

#include "FunctionWrapper.h"

ValueWrapper::ptr FunctionWrapper::getValue() {
  return ValueWrapper::Create(true, type, Function);
}

ValueWrapper::ptr FunctionWrapper::bind(ValueWrapper::ptr binder) {
  return ValueWrapper::Create(true, type, Function, binder);
}
FunctionWrapper::FunctionWrapper(std::string name, TypeWrapper type, llvm::Function *function, std::string linkName) : Function(function),
                                                                                                                       type(type),
                                                                                                                       Name(name),
                                                                                                                       LinkName(linkName)
                                                                                                                       {
  if (linkName.empty()) {
    LinkName = name;
  }

}
