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
#include "Package.h"

class StackController {
 private:
  struct StackBlockDetails {
    llvm::BasicBlock *thisBlock;
    llvm::BasicBlock *breakToBlock = nullptr;
    llvm::BasicBlock *continueBlockTo = nullptr;
    std::map<std::string, ValueWrapper::ptr> values = {};
  };
 public:

  std::vector<StackBlockDetails> Stack = {};

  void PushLevel(llvm::BasicBlock *block,
                 llvm::BasicBlock *breakBlockTo = nullptr,
                 llvm::BasicBlock *continueBlockTo = nullptr);

  void PopLevel();

  bool AddNamedValue(const std::string &name, ValueWrapper::ptr value);

  ValueWrapper::ptr GetNamedValue(const std::string name, std::string module = std::string());

  llvm::BasicBlock *GetBlock();
  llvm::BasicBlock *GetBreakToBlock();
  llvm::BasicBlock *GetContinueToBlock();
};

class Context {
 public:

  std::shared_ptr<llvm::LLVMContext> TheContext;
  std::shared_ptr<llvm::IRBuilder<>> Builder;
  std::shared_ptr<llvm::Module> TheModule;

  StackController stackController;

  Package currentPackage;
  std::map<std::string, Package> packages;
  std::map<std::string, Package*> importedPackages;

  [[nodiscard]] std::string GetMethodId(const std::string &name, const std::string &struct_name) const;

  [[nodiscard]] std::string GetFunctionID(const std::string &name) const;

  Context();
 private:
  std::optional<TypeWrapper> GetType(GoParser::Type_Context *typeContext);
};

#endif //APP_CONTEXT_H
