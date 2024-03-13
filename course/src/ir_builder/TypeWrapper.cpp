//
// Created by volodya on 12.03.24.
//

#include "TypeWrapper.h"

TypeWrapper::TypeWrapper(llvm::Type *llvmType) : _llvmType(llvmType) {

}

const std::string &TypeWrapper::getName() const {
  return _name;
}

void TypeWrapper::setName(const std::string &name) {
  _name = name;
}

const bool TypeWrapper::isNumber() {
  return _typeDetails.intInfo || _typeDetails.floatInfo;
}

const TypeDetails &TypeWrapper::getTypeDetails() const {
  return _typeDetails;
}

TypeWrapper TypeWrapper::GetInt(llvm::LLVMContext &TheContext, bool isSigned, size_t size) {
  auto ty = TypeWrapper(llvm::Type::getIntNTy(TheContext, size));
  ty._typeDetails.intInfo = TypeDetails::IntInfo{isSigned, size};
  return std::move(ty);
}

TypeWrapper TypeWrapper::GetFloat(llvm::LLVMContext &TheContext, bool isLong) {
  auto ty = TypeWrapper(llvm::Type::getDoubleTy(TheContext));
  ty._typeDetails.floatInfo = TypeDetails::FloatInfo{64};
  return std::move(ty);
}

TypeWrapper TypeWrapper::GetStruct(llvm::LLVMContext &TheContext,
                                   std::vector<std::pair<std::string, TypeWrapper>> &fields,
                                   bool isInterface) {
  std::vector<TypeWrapper> fieldsTypes;
  std::vector<llvm::Type *> llvmTypes;
  std::vector<std::string> fieldsNames;

  for (auto field : fields) {
    fieldsNames.push_back(field.first);
    fieldsTypes.push_back(field.second);
    llvmTypes.push_back(field.second.getType());
  }

  auto ty = TypeWrapper(llvm::StructType::get(TheContext, llvmTypes));
  ty._typeDetails.structInfo = TypeDetails::StructInfo{fieldsTypes, fieldsNames, isInterface};

  return std::move(ty);
}

TypeWrapper TypeWrapper::GetFunction(llvm::LLVMContext &TheContext,
                                     std::optional<TypeWrapper> retType,
                                     std::vector<TypeWrapper> arguments,
                                     bool isVarArg) {
  std::vector<llvm::Type *> args = {};
  for (auto arg : arguments) {
    args.push_back(arg.getType());
  }

  llvm::FunctionType
      *type = llvm::FunctionType::get(retType ? retType->getType() : llvm::Type::getVoidTy(TheContext), args, isVarArg);

  auto ty = TypeWrapper(type);

  std::shared_ptr<TypeWrapper> retT = nullptr;
  if (retType) {
    retT = std::make_shared<TypeWrapper>(*retType);
  }

  ty._typeDetails.functionInfo = TypeDetails::FunctionInfo{isVarArg, retT, arguments};

  return std::move(ty);
}

llvm::Type *TypeWrapper::getType() const {
  return _llvmType;
}

TypeWrapper TypeWrapper::getPointerTo() {
  auto ty = TypeWrapper(_llvmType->getPointerTo());

  ty._typeDetails.pointerInfo = {std::make_shared<TypeWrapper>(*this)};

  return ty;
}

std::optional<TypeWrapper> TypeWrapper::GetTypeByName(const std::string &typeName,
                                                      llvm::LLVMContext &TheContext,
                                                      std::map<std::string, TypeWrapper> &typeStorage) {
  if (typeStorage.find(typeName) == typeStorage.end()) {
    return {};
  }

  return typeStorage.find(typeName)->second;
}

TypeWrapper TypeWrapper::getArrayOf(size_t count) {
  auto ty = TypeWrapper(llvm::ArrayType::get(_llvmType, count));

  ty._typeDetails.arrayInfo = {count, std::make_shared<TypeWrapper>(*this)};

  return ty;
}

std::optional<TypeWrapper> TypeWrapper::getHigherType(llvm::LLVMContext &context, TypeWrapper right) {
  if (this->getTypeDetails().pointerInfo && this->getTypeDetails().pointerInfo) {
    return TypeWrapper::GetPointer(context, TypeWrapper::GetInt(context, false, 0));
  }

  if (this->isNumber() && right.isNumber()) {

    if (this->getTypeDetails().floatInfo || right.getTypeDetails().floatInfo) {
      return TypeWrapper::GetFloat(context);
    } else {
      bool isSigned = this->getTypeDetails().intInfo->isSigned || right.getTypeDetails().intInfo->isSigned;
      auto size = std::max(this->getTypeDetails().intInfo->bitSize, right.getTypeDetails().intInfo->bitSize);
      return TypeWrapper::GetInt(context, isSigned, size);
    }

  }

  return {};
}

TypeWrapper TypeWrapper::GetPointer(llvm::LLVMContext &context, std::optional<TypeWrapper> ty) {
  std::shared_ptr<TypeWrapper> tyPtr;
  if (ty) {
    tyPtr = std::make_shared<TypeWrapper>(*ty);
  }

  auto tw = TypeWrapper(llvm::Type::getInt8PtrTy(context));
  tw._typeDetails.pointerInfo = {tyPtr};

  return tw;
}

size_t TypeWrapper::getSizeOf(const llvm::DataLayout &dl) {
  return dl.getTypeSizeInBits(_llvmType) / 8;
}

std::vector<size_t> TypeWrapper::getLinkPositions(const llvm::DataLayout &dl) {
  if (_typeDetails.structInfo) {
    if (_typeDetails.structInfo->isInterface) {
      return {0};
    }

    auto Sl = dl.getStructLayout((llvm::StructType *) _llvmType);
    std::vector<size_t> res = {};
    {
      size_t i = 0;
      for (auto field : _typeDetails.structInfo->fields) {
        if (field._typeDetails.pointerInfo) {
          res.emplace_back(Sl->getElementOffset(i));
        } else if (field._typeDetails.structInfo) {
          size_t offset = Sl->getElementOffset(i);
          for (auto r : field.getLinkPositions(dl)) {
            res.emplace_back(r + offset);
          }
        }
        ++i;
      }
    }
    return res;
  }
  if (_typeDetails.pointerInfo) {
    return {0};
  }
  return {};
}
