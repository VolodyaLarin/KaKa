//
// Created by volodya on 12.03.24.
//

#ifndef APP_GOIRBUILDER_H
#define APP_GOIRBUILDER_H

#include <utility>

#include "Context.h"
#include "Error.h"
#include "codegen/GoParserVisitor.h"

class GoIrBuilder {
 public:
  const Context &GetContext() const;
  enum BinaryOperation {
    Add, Sub, Mul, Div, Mod, Gt, Lt, Ge, Le, Eq, Ne, BinaryOperationSize
  };
  void generateBuiltIns();

  Error::ptr createTypeDecl(GoParser::TypeDeclContext *ctx);

  void setModuleName(std::string name);
  EValue createFunction(antlr4::tree::ParseTree *ctx,
                        GoParser::ReceiverContext *receiver,
                        antlr4::tree::TerminalNode *IDENTIFIER,
                        GoParser::SignatureContext *signature,
                        GoParser::BlockContext *block = nullptr,
                        GoParserVisitor *visitor = nullptr);
  EValue createIntConstant(int value);
  EValue createFloatConstant(double num);
  EValue createNil();
  EValue createStringConstant(const std::string &data);
  std::optional<TypeWrapper> GetType(GoParser::Type_Context *typeContext);
  std::optional<TypeWrapper> GetType(const std::string &name);
  EValue toRHS(EValue val);
  EValue addNamedValue(const std::string &name, EValue value);
  EValue createReturn(std::vector<EValue> values);
  EValue allocateMemory(TypeWrapper ty, size_t count = 1, const std::string &name = "");
  EValue assign(EValue left, EValue right);
  EValue cast(EValue value, const TypeWrapper &right);
  EValue createCall(EValue func, std::vector<EValue> args);
  EValue getByIndex(EValue array, EValue index);
  EValue getStructField(EValue, std::string);
  EValue deref(EValue);
  EValue getNamed(const std::string &name);
  EValue createBinOperation(BinaryOperation op, EValue left, EValue right);
  EValue createIf(EValue condition, std::function<void()> ifBuilder, std::function<void()> elseBuilder = nullptr);
  EValue createFor(std::function<void()> Init,
                   std::function<EValue()> Cond,
                   std::function<void()> After,
                   std::function<void()> Block);
  EValue createAnd(EValue left, std::function<EValue ()> rightBuilder);
  EValue createOr(EValue left, std::function<EValue ()> rightBuilder);
 private:
  Context context;

  EValue assignToInterface(ValueWrapper::ptr interface, const ValueWrapper::ptr &value);
  EValue _getByIndex(EValue &left, EValue indexV, const TypeWrapper &type);

  struct IFContext {
    llvm::BasicBlock *_if;
    llvm::BasicBlock *_else;
    llvm::BasicBlock *_merge;
  };

  IFContext _createIf(EValue condition, std::function<void()> ifBuilder, std::function<void()> elseBuilder = nullptr);
  EValue _createAndOr(bool isAnd, EValue left, std::function<EValue()> rightBuilder);
  EValue _createIntConstant(int value, bool isSigned, size_t size);
};

#endif //APP_GOIRBUILDER_H
