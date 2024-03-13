//
// Created by volodya on 12.03.24.
//

#ifndef APP_CONTEXT_H
#define APP_CONTEXT_H

#include <vector>
#include <llvm/IR/BasicBlock.h>
#include <map>
#include "ValueWrapper.h"
#include "FunctionWrapper.h"
#include "codegen/GoParser.h"

class StackController {
 public:

  std::vector<std::pair<llvm::BasicBlock *, std::map<std::string, ValueWrapper::ptr>>> Stack = {};

  void PushLevel(llvm::BasicBlock *block);

  void PopLevel();

  bool AddNamedValue(const std::string &name, ValueWrapper::ptr value);

  ValueWrapper::ptr GetNamedValue(const std::string name, std::string module = std::string());

  llvm::BasicBlock *GetBlock();
};

class Context {
 public:

  std::shared_ptr<llvm::LLVMContext> TheContext;
  std::shared_ptr<llvm::IRBuilder<>> Builder;
  std::shared_ptr<llvm::Module> TheModule;

  StackController stackController;

  std::string ModuleName;

  std::map<std::string, FunctionWrapper> Functions;
  std::map<std::string, TypeWrapper> Types;

  [[nodiscard]] std::string GetMethodId(const std::string &name, const std::string &struct_name) const;

  [[nodiscard]] std::string GetFunctionID(const std::string &name) const;

  Context();

  std::optional<TypeWrapper> GetType(GoParser::Type_Context *typeContext);
};

#endif //APP_CONTEXT_H
