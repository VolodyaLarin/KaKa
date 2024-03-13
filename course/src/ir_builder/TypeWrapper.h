//
// Created by volodya on 12.03.24.
//

#ifndef APP_TYPEWRAPPER_H
#define APP_TYPEWRAPPER_H

#include <memory>
#include <vector>
#include <optional>
#include <llvm/IR/Type.h>
#include <llvm/IR/DataLayout.h>
#include <map>

class TypeWrapper;

struct TypeDetails {
  struct IntInfo {
    bool isSigned;
    size_t bitSize;
  };
  struct FloatInfo {
    size_t bitSize;
  };

  struct FunctionInfo {
    bool isVarargs = false;
    std::shared_ptr<TypeWrapper> retType;
    std::vector<TypeWrapper> arguments;
  };

  struct StructInfo {
    std::vector<TypeWrapper> fields;
    std::vector<std::string> fieldNames;
    bool isInterface = false;
  };

  struct PointerInfo {
    std::shared_ptr<TypeWrapper> type;
  };
  struct ArrayInfo {
    size_t size;
    std::shared_ptr<TypeWrapper> type;
  };

  std::optional<IntInfo> intInfo = {};
  std::optional<FloatInfo> floatInfo = {};
  std::optional<FunctionInfo> functionInfo = {};
  std::optional<StructInfo> structInfo = {};
  std::optional<PointerInfo> pointerInfo = {};
  std::optional<ArrayInfo> arrayInfo = {};
};

class TypeWrapper {
  TypeDetails _typeDetails = {};
  llvm::Type *_llvmType;
  std::string _name;

  explicit TypeWrapper(llvm::Type *llvmType);

 public:
  const std::string &getName() const;

  void setName(const std::string &name);

  const bool isNumber();

  const TypeDetails &getTypeDetails() const;

  static TypeWrapper GetInt(llvm::LLVMContext &TheContext, bool isSigned, size_t size);

  static TypeWrapper GetFloat(llvm::LLVMContext &TheContext, bool isLong = true);

  static TypeWrapper GetStruct(llvm::LLVMContext &TheContext,
                               std::vector<std::pair<std::string, TypeWrapper>> &fields,
                               bool isInterface = false);

  static TypeWrapper GetFunction(llvm::LLVMContext &TheContext,
                                 std::optional<TypeWrapper> retType,
                                 std::vector<TypeWrapper> arguments,
                                 bool isVarArg = false);

  llvm::Type *getType() const;

  TypeWrapper getPointerTo();

  TypeWrapper getArrayOf(size_t count);

  static std::optional<TypeWrapper> GetTypeByName(const std::string &typeName,
                                                  llvm::LLVMContext &TheContext,
                                                  std::map<std::string, TypeWrapper> &typeStorage);

  std::optional<TypeWrapper> getHigherType(llvm::LLVMContext &context, TypeWrapper right);

  static TypeWrapper GetPointer(llvm::LLVMContext &context, std::optional<TypeWrapper> ty);

  size_t getSizeOf(const llvm::DataLayout &dl);

  std::vector<size_t> getLinkPositions(const llvm::DataLayout &dl);

};

#endif //APP_TYPEWRAPPER_H
