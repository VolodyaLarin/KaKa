//
// Created by volodya on 12.03.24.
//

#ifndef APP_FUNCTIONWRAPPER_H
#define APP_FUNCTIONWRAPPER_H

#include "ValueWrapper.h"
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
