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
    std::shared_ptr<TypeWrapper> type;
    size_t size;
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
  static llvm::LLVMContext *context;

 public:
  const std::string &getName() const;

  void setName(const std::string &name);

  const bool isNumber();

  const TypeDetails &getTypeDetails() const;

  static TypeWrapper GetInt(bool isSigned, size_t size);

  static TypeWrapper GetFloat(bool isLong = true);

  static TypeWrapper GetStruct(std::vector<std::pair<std::string, TypeWrapper>> &fields, bool isInterface = false);

  static TypeWrapper GetFunction(std::optional<TypeWrapper> retType,
                                 std::vector<TypeWrapper> arguments,
                                 bool isVarArg = false);

  llvm::Type *getType() const;

  TypeWrapper getPointerTo();

  TypeWrapper getArrayOf(size_t count);

  std::optional<TypeWrapper> getHigherType(llvm::LLVMContext &context, TypeWrapper right);

  static TypeWrapper GetPointer(std::optional<TypeWrapper> ty);

  size_t getSizeOf(const llvm::DataLayout &dl);

  std::vector<size_t> getLinkPositions(const llvm::DataLayout &dl);

  static void SetContext(llvm::LLVMContext *context);
};


#endif //APP_TYPEWRAPPER_H
