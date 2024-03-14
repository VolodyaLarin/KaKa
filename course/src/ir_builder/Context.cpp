//
// Created by volodya on 12.03.24.
//

#include "Context.h"

void StackController::PushLevel(llvm::BasicBlock *block,
                                llvm::BasicBlock *breakBlockTo,
                                llvm::BasicBlock *continueBlockTo) {
  Stack.emplace_back(StackBlockDetails{
      block,
      breakBlockTo ? breakBlockTo : GetBreakToBlock(),
      continueBlockTo ? continueBlockTo : GetContinueToBlock(),
  });
}

void StackController::PopLevel() {
  // @todo destruct all;

  Stack.pop_back();
}

bool StackController::AddNamedValue(const std::string &name, ValueWrapper::ptr value) {
  auto ValueInStack = Stack.rbegin()->values.find(name);
  if (ValueInStack != Stack.rbegin()->values.end()) {
    std::cerr << "Variable " << name << " allready defined" << std::endl;
    return false;
  }

  Stack.rbegin()->values.insert({name, value});
  return true;
}

ValueWrapper::ptr StackController::GetNamedValue(const std::string name, std::string module) {
  for (auto block = Stack.rbegin(); block != Stack.rend(); block++) {
    if (block->values.find(name) != block->values.end()) {
      return block->values.find(name)->second;
    }
  }
  return nullptr;
}

llvm::BasicBlock *StackController::GetBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->thisBlock;
}
llvm::BasicBlock *StackController::GetBreakToBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->breakToBlock;
}
llvm::BasicBlock *StackController::GetContinueToBlock() {
  if (Stack.empty()) return nullptr;

  return Stack.rbegin()->continueBlockTo;
}

std::string Context::GetMethodId(const std::string &name, const std::string &struct_name) const {
  return struct_name + "__struct__" + name;
}

std::string Context::GetFunctionID(const std::string &name) const {
  return name;
}

Context::Context(): currentPackage("","") {
  TheContext = std::make_shared<llvm::LLVMContext>();
  Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);
  TheModule = std::make_shared<llvm::Module>("main", *TheContext);
}

