//
// Created by volodya on 12.03.24.
//

#include "ValueWrapper.h"

#include <utility>

const ValueWrapper::ptr &ValueWrapper::getBinding() const {
    return _binding;
}

ValueWrapper::ptr ValueWrapper::Create(bool isConstant, TypeWrapper typeW, llvm::Value *value, ValueWrapper::ptr bind) {
    return std::make_shared<ValueWrapper>(ValueWrapper(isConstant, typeW, value, bind));
}

bool ValueWrapper::isConstant() const {
    return _isConstant;
}

TypeWrapper ValueWrapper::getType() const {
    return _type;
}

llvm::Value *ValueWrapper::getValue() const {
    return _llvmValue;
}

ValueWrapper::ptr ValueWrapper::toRHS(llvm::IRBuilder<> &builder) const {
    if (isConstant())
        return std::make_shared<ValueWrapper>(*this);

    llvm::Value *value = builder.CreateLoad(getType().getType(), this->getValue());

    return ValueWrapper::Create(true, getType(), value, _binding);
}

ValueWrapper::ptr ValueWrapper::getPointerTo() const {
    if (isConstant()) {
        return nullptr;
    }

    return ValueWrapper::Create(true, getType().getPointerTo(), getValue());

}

ValueWrapper::ptr ValueWrapper::castTo(llvm::IRBuilder<> &builder, TypeWrapper ty) const {
    auto RHS = toRHS(builder);

  if (RHS->getType().getTypeDetails().structInfo && ty.getTypeDetails().structInfo) {
    if (RHS->getType().getName() == ty.getName()) {
      return std::make_shared<ValueWrapper>(*this);
    } else {
      std::cerr << "Warning: struct (interfaces casts id not supported)" << std::endl;
      return std::make_shared<ValueWrapper>(*this);
    }
  }
    if (RHS->getType().getTypeDetails().pointerInfo) {
        if (!ty.getTypeDetails().pointerInfo) {
            std::cerr << "Can't convert pointer to not pointer" << std::endl;
        }
        return RHS;
    }

    if (!RHS->getType().isNumber()) {
        std::cerr << "Can' cast this types" << std::endl;
        return nullptr;
    }

    if (ty.getTypeDetails().floatInfo) {
        if (RHS->getType().getTypeDetails().floatInfo) {
            return RHS;
        }
        return ValueWrapper::Create(true, ty, builder.CreateSIToFP(RHS->getValue(), ty.getType()));
    } else if (ty.getTypeDetails().intInfo) {
        if (RHS->getType().getTypeDetails().floatInfo) {
            return ValueWrapper::Create(true, ty, builder.CreateFPToSI(RHS->getValue(), ty.getType()));
        } else {
            // @todo: add other casts...
            return RHS;
        }
    }
    return nullptr;
}

EValue::operator bool() const {
    return !error_ptr && value_ptr;
}

ValueWrapper EValue::operator*() {
    return *value_ptr;
}

Error EValue::getError() const {
    return *error_ptr;
}

EValue::EValue(ValueWrapper::ptr valuePtr, Error::ptr errorPtr) : value_ptr(std::move(valuePtr)),
                                                                                error_ptr(std::move(errorPtr)) {}
EValue::EValue(Error::ptr errorPtr): value_ptr(nullptr), error_ptr(std::move(errorPtr)) {

}
const ValueWrapper::ptr &EValue::GetValuePtr() const {
  return value_ptr;
}
