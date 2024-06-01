//
// Created by volodya on 12.03.24.
//

#include <algorithm>
#include <boost/algorithm/string/replace.hpp>
#include <support/Any.h>
#include "ParserVisitor.h"

antlrcpp::Any ParserVisitor::visitSourceFile(GoParser::SourceFileContext *ctx) {
  auto res = goIrBuilder->generateBuiltIns();
  if (res.hasError()) {
    return res;
  }

  for (auto &child : ctx->children) {
    child->accept(this);
  }

  return ValueWrapper::ptr(nullptr);
}

antlrcpp::Any ParserVisitor::visitImportDecl(GoParser::ImportDeclContext *ctx) {
  for (auto spec: ctx->importSpec()) {
    auto path = spec->importPath()->getText();
    path = path.substr(1, path.size()-2);

    std::string alias = "";
    if (spec->alias) {
      alias = spec->alias->getText();
    }

    auto res = goIrBuilder->importPackage(path, alias);
    if (res.hasError()) {
      return res;
    }
  }
  return EValue();
}

antlrcpp::Any ParserVisitor::visitTypeDecl(GoParser::TypeDeclContext *ctx) {
  if (ctx->typeSpec(0)->aliasDecl()) {
    return EValue(Error::Create("Warning: Aliases is not supported", ctx));
  }

  if (ctx->typeSpec().size() > 1) {
    // @todo: support multiple;
    Error::Create("Warning: multiple type declaration is not supported. Use first spec", ctx);
  }

  auto def = ctx->typeSpec(0)->typeDef();

  auto defName = def->IDENTIFIER()->getText();
  EValue type = std::any_cast<EValue>(def->type_()->accept(this));
  if (!type.GetTypePtr()) {
    return EValue(Error::Create("Error: Can't declare type " + defName, ctx));
  }
  return goIrBuilder->createTypeDecl(defName, *type.GetTypePtr());
}
antlrcpp::Any ParserVisitor::visitType_(GoParser::Type_Context *ctx) {
  if (ctx->typeName()) {
    auto typeName = ctx->typeName()->getText();
    return goIrBuilder->getNamed(typeName);
  }
  if (ctx->type_()) {
    return ctx->type_()->accept(this);
  }
  if (!ctx->typeLit()) {
    return EValue(Error::Create("This type isn't supported. Smth go wrong", ctx));
  }
  if (ctx->typeLit()->interfaceType()) {
    auto interfaceTN = ctx->typeLit()->interfaceType();

    std::vector<std::pair<std::string, TypeWrapper>> fields = {{"_", TypeWrapper::GetPointer({})},};

    for (auto &method : interfaceTN->methodSpec()) {
      auto name = method->IDENTIFIER()->getText();
      std::optional<TypeWrapper> result;

      if (method->result()) {
        EValue resultEV = std::any_cast<EValue>(method->result()->type_()->accept(this));
        if (!resultEV.GetTypePtr()) {
          return resultEV;
        }
        result = *resultEV.GetTypePtr();
      }

      std::vector<TypeWrapper> params = {TypeWrapper::GetPointer({})};
      for (auto decl : method->parameters()->parameterDecl()) {
        EValue ty = std::any_cast<EValue>(decl->type_()->accept(this));
        if (!ty.GetTypePtr()) {
          return ty;
        }
        params.push_back(*ty.GetTypePtr());
      }

      auto func = TypeWrapper::GetFunction(result, params).getPointerTo();
      fields.emplace_back(name, func);
    }

    return EValue(TypeWrapper::GetStruct(fields, true));
  }

  if (ctx->typeLit()->structType()) {
    auto structTN = ctx->typeLit()->structType();

    std::vector<std::pair<std::string, TypeWrapper>> fields = {};

    for (auto &field : structTN->fieldDecl()) {
      // @todo support multiple
      if (field->identifierList()->IDENTIFIER().size() > 1) {
        Error::Create("Warning: multiple field declare is not supported", ctx);
      }
      auto fieldName = field->identifierList()->IDENTIFIER(0)->getText();
      EValue fieldT = std::any_cast<EValue>(field->type_()->accept(this));
      if (!fieldT.GetTypePtr()) {
        return fieldT;
      }

      fields.emplace_back(fieldName, *fieldT.GetTypePtr());
    }

    return EValue(TypeWrapper::GetStruct(fields));

  }

  if (ctx->typeLit()->arrayType()) {
    auto child = ctx->typeLit()->arrayType()->elementType()->type_();
    EValue childType = std::any_cast<EValue>(child->accept(this));
    if (!childType.GetTypePtr()) {
      return childType;
    }
    auto countText = ctx->typeLit()->arrayType()->arrayLength()->getText();
    auto count = atoi(countText.c_str());

    if (count <= 0) {
      return EValue(Error::Create( "Can't create array with length " + std::to_string(count), ctx));
    }

    return EValue(childType.GetTypePtr()->getArrayOf(count));
  }
  if (ctx->typeLit()->pointerType()) {
    EValue pointTo = std::any_cast<EValue>(ctx->typeLit()->pointerType()->type_()->accept(this));
    if (!pointTo.GetTypePtr()) {
      Error::Create("Warning: Declare as void pointer", ctx);
      return EValue(TypeWrapper::GetPointer({}));
    }

    return EValue(TypeWrapper::GetPointer(*pointTo.GetTypePtr()));

  }
  return EValue(Error::Create("This type is not supported", ctx));
}
antlrcpp::Any ParserVisitor::visitFunctionDecl(GoParser::FunctionDeclContext *ctx) {
  auto res = goIrBuilder->createFunction(ctx, nullptr, ctx->IDENTIFIER(), ctx->signature(), ctx->block(), this);
  if (!res) {
    std::cerr << res.getError().toString() << std::endl;
  }
  return EValue();
}

antlrcpp::Any ParserVisitor::visitStatement(GoParser::StatementContext *ctx) {
  return GoParserBaseVisitor::visitStatement(ctx);
}

antlrcpp::Any ParserVisitor::visitInteger(GoParser::IntegerContext *ctx) {
  int value = 0;

  if (ctx->RUNE_LIT()) {
    value = toascii(ctx->RUNE_LIT()->getText()[1]);
  } else if (ctx->DECIMAL_LIT()) {
    value = atoi(ctx->getText().c_str());
  }

  return goIrBuilder->createIntConstant(value);
}

antlrcpp::Any ParserVisitor::visitBasicLit(GoParser::BasicLitContext *ctx) {
  if (ctx->FLOAT_LIT()) {
    auto string = ctx->FLOAT_LIT()->getText();
    auto num = std::stod(string);

    return goIrBuilder->createFloatConstant(num);
  }
  if (ctx->NIL_LIT()) {
    return goIrBuilder->createNil();
  }
  return GoParserBaseVisitor::visitBasicLit(ctx);
}

antlrcpp::Any ParserVisitor::visitString_(GoParser::String_Context *ctx) {
  auto data = ctx->INTERPRETED_STRING_LIT()->getText();
  // @todo: add normal deserelisation
  boost::replace_all(data, "\\\\", "<SUPEREQ>");

  boost::replace_all(data, "\\n", "\n");
  boost::replace_all(data, "\\t", "\t");
  boost::replace_all(data, "\\r", "\r");

  boost::replace_all(data, "<SUPEREQ>", "\\");

  data = data.substr(1, data.size() - 2);

  return goIrBuilder->createStringConstant(data);
}

antlrcpp::Any ParserVisitor::visitConstDecl(GoParser::ConstDeclContext *ctx) {
  // @todo support multiple declaration
  // @todo: compute type
  EValue typeNode = std::any_cast<EValue>(ctx->constSpec()[0]->type_()->accept(this));
  if (!typeNode.GetTypePtr()) {
    return EValue(Error::Create("Can't find type", ctx));
  }

  auto llvmType = typeNode.GetTypePtr();

  EValue expr = std::any_cast<EValue>(ctx->constSpec(0)->expressionList()->expression(0)->accept(this));
  if (!expr) {
    return expr;
  }
  expr = goIrBuilder->toRHS(expr);
  auto name = ctx->constSpec(0)->identifierList()->IDENTIFIER(0)->getText();
  goIrBuilder->addNamedValue(name, expr);

  return expr;
}

antlrcpp::Any ParserVisitor::visitReturnStmt(GoParser::ReturnStmtContext *ctx) {
  auto exprs = ctx->expressionList()->expression();
  std::vector<EValue> values;
  std::transform(exprs.cbegin(), exprs.cend(), std::back_inserter(values), [this](auto exprNode) {
    auto expr = std::any_cast<EValue>(exprNode->accept(this));
    if (!expr) {
      std::cerr << expr.getError().toString() << std::endl;
      return expr;
    }
    return goIrBuilder->toRHS(expr);
  });

  return goIrBuilder->createReturn(values);
}

antlrcpp::Any ParserVisitor::visitVarDecl(GoParser::VarDeclContext *ctx) {
  for (const auto &varSpec : ctx->varSpec()) {
    std::vector<ValueWrapper::ptr> right;

    if (varSpec->expressionList()) {
      auto exprList = varSpec->expressionList()->expression();
      std::transform(exprList.begin(), exprList.end(), std::back_inserter(right), [this](auto &expr) {
        auto res = std::any_cast<EValue>(expr->accept(this));
        return res.GetValuePtr();
      });
    }

    std::optional<TypeWrapper> typeToCast;

    if (varSpec->type_()) {
      EValue typeV = std::any_cast<EValue>(varSpec->type_()->accept(this));
      if (!typeV.GetTypePtr()) {
        return EValue(Error::Create("Can't find type", ctx));
      }
      typeToCast = *typeV.GetTypePtr();
    }

    if (right.empty() && !typeToCast) {
      return EValue(Error::Create("Need type for var declaration", ctx));
    }
    auto ids = varSpec->identifierList()->IDENTIFIER();
    if (!right.empty() && ids.size() != right.size()) {
      return EValue(Error::Create("Left and right section have a different sizes", ctx));
    }
    for (size_t i = 0; i < ids.size(); i++) {
      auto ty = typeToCast;
      if (!ty) {
        ty = right[i]->getType();
      }
      auto name = ids[i]->getText();
      auto mem = goIrBuilder->allocateMemory(*ty);

      if (!right.empty()) {
        auto val = goIrBuilder->assign(mem, right[i]);
        if (!val) {
          return val;
        }
      }
      goIrBuilder->addNamedValue(name, mem);
    }
  }
  return EValue();
}

antlrcpp::Any ParserVisitor::visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) {
  if (ctx->arguments()) {
    EValue function = std::any_cast<EValue>(ctx->primaryExpr()->accept(this));
    if (function.GetTypePtr()) {
      auto type2Cast = function.GetTypePtr();
      if (!type2Cast) {
        return function;
      }
      if (ctx->arguments()->expressionList()->expression().size() != 1) {
        return EValue(Error::Create("can't cast more than one value ", ctx));
      }

      EValue right = std::any_cast<EValue>(ctx->arguments()->expressionList()->expression(0)->accept(this));
      right = goIrBuilder->cast(right, *type2Cast);
      return right;
    }

    std::vector<EValue> ArgsV;

    if (ctx->arguments()->expressionList()) {
      auto exprs = ctx->arguments()->expressionList()->expression();
      std::transform(exprs.begin(), exprs.end(), std::back_inserter(ArgsV), [this](auto expr) -> EValue {
        return std::any_cast<EValue>(expr->accept(this));
      });
    }

    return goIrBuilder->createCall(function, ArgsV);
  }

  if (ctx->index()) {
    EValue left = std::any_cast<EValue>(ctx->primaryExpr()->accept(this));
    EValue indexV = std::any_cast<EValue>(ctx->index()->expression()->accept(this));

    return goIrBuilder->getByIndex(left, indexV);
  }

  if (ctx->DOT()) {
    EValue left = std::any_cast<EValue>(ctx->primaryExpr()->accept(this));
    auto fieldName = ctx->IDENTIFIER()->getText();

    if (left.GetPackagePtr()) {
      return goIrBuilder->getNamed(fieldName, left.GetPackagePtr());
    }
    if (!left) {
      return left;
    }
    return goIrBuilder->getStructField(left, fieldName);
  }

  return GoParserBaseVisitor::visitPrimaryExpr(ctx);
}

antlrcpp::Any ParserVisitor::visitMethodDecl(GoParser::MethodDeclContext *ctx) {
  return goIrBuilder->createFunction(ctx, ctx->receiver(), ctx->IDENTIFIER(), ctx->signature(), ctx->block(), this);
}

antlrcpp::Any ParserVisitor::visitOperand(GoParser::OperandContext *ctx) {
  if (ctx->operandName()) {
    return ctx->operandName()->accept(this);
  } else if (ctx->expression()) {
    return ctx->expression()->accept(this);
  } else if (ctx->literal()) {
    return ctx->literal()->accept(this);
  }
  return ValueWrapper::ptr(nullptr);
}

antlrcpp::Any ParserVisitor::visitOperandName(GoParser::OperandNameContext *ctx) {
  auto varName = ctx->IDENTIFIER()->getText();
  return goIrBuilder->getNamed(varName);
}

antlrcpp::Any ParserVisitor::visitAssignment(GoParser::AssignmentContext *ctx) {
  if (ctx->expressionList(0)->expression().size() != ctx->expressionList(0)->expression().size()) {
    return EValue(Error::Create("Left and right part of assigment should be equal sized", ctx));
  }
  for (size_t i = 0; i < ctx->expressionList(0)->expression().size(); i++) {
    if (ctx->expressionList(0)->expression(i)->getText() == "_") continue;
    EValue lexpr = std::any_cast<EValue>(ctx->expressionList(0)->expression(i)->accept(this));
    EValue expr = std::any_cast<EValue>(ctx->expressionList(1)->expression(i)->accept(this));

    auto res = goIrBuilder->assign(lexpr, expr);
    if (!res) return res;
  }

  return EValue();
}
antlrcpp::Any ParserVisitor::visitIncDecStmt(GoParser::IncDecStmtContext *ctx) {
  EValue expr = std::any_cast<EValue>(ctx->expression()->accept(this));
  EValue oneConst = goIrBuilder->createIntConstant(1);
  auto binOp = GoIrBuilder::BinaryOperation::Add;
  if (ctx->MINUS_MINUS()) {
    binOp = GoIrBuilder::BinaryOperation::Sub;
  }
  auto res = goIrBuilder->createBinOperation(binOp, expr, oneConst);

  return goIrBuilder->assign(expr, res);
}
antlrcpp::Any ParserVisitor::visitExpression(GoParser::ExpressionContext *ctx) {
  if (ctx->add_op || ctx->rel_op || ctx->mul_op) {
    EValue L = std::any_cast<EValue>(ctx->expression(0)->accept(this));
    EValue R = std::any_cast<EValue>(ctx->expression(1)->accept(this));

    std::optional<GoIrBuilder::BinaryOperation> operation;

    if (ctx->PLUS()) {
      operation = GoIrBuilder::BinaryOperation::Add;
    } else if (ctx->MINUS()) {
      operation = GoIrBuilder::BinaryOperation::Sub;
    } else if (ctx->GREATER()) {
      operation = GoIrBuilder::BinaryOperation::Gt;
    } else if (ctx->LESS()) {
      operation = GoIrBuilder::BinaryOperation::Lt;
    } else if (ctx->GREATER_OR_EQUALS()) {
      operation = GoIrBuilder::BinaryOperation::Ge;
    } else if (ctx->LESS_OR_EQUALS()) {
      operation = GoIrBuilder::BinaryOperation::Le;
    } else if (ctx->EQUALS()) {
      operation = GoIrBuilder::BinaryOperation::Eq;
    } else if (ctx->NOT_EQUALS()) {
      operation = GoIrBuilder::BinaryOperation::Ne;
    } else if (ctx->STAR()) {
      operation = GoIrBuilder::BinaryOperation::Mul;
    } else if (ctx->DIV()) {
      operation = GoIrBuilder::BinaryOperation::Div;
    } else if (ctx->MOD()) {
      operation = GoIrBuilder::BinaryOperation::Mod;
    }
    if (!operation) {
      return EValue(Error::Create("This operation is not supported ", ctx));
    }

    return goIrBuilder->createBinOperation(*operation, L, R);

  } else if (ctx->unary_op) {
    if (ctx->AMPERSAND()) {
      EValue child = std::any_cast<EValue>(ctx->expression(0)->accept(this));
      if (!child) return child;

      auto value = child->getPointerTo();
      if (!value)
        return EValue(Error::Create("Can't get address", ctx));

      return EValue(value);
    }
    if (ctx->STAR()) {
      EValue child = std::any_cast<EValue>(ctx->expression(0)->accept(this));

      return goIrBuilder->deref(child);
    }
  } else if (ctx->LOGICAL_AND() || ctx->LOGICAL_OR()) {
    EValue left = std::any_cast<EValue>(ctx->expression(0)->accept(this));
    auto rightBuilder = [this, ctx]() -> EValue {
      return std::any_cast<EValue>(ctx->expression(1)->accept(this));
    };

    if (ctx->LOGICAL_AND()) return goIrBuilder->createAnd(left, rightBuilder);
    return goIrBuilder->createOr(left, rightBuilder);
  }

  return GoParserBaseVisitor::visitExpression(ctx);
}

antlrcpp::Any ParserVisitor::visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) {
  if (ctx->identifierList()->IDENTIFIER().size() != ctx->expressionList()->expression().size()) {
    return EValue(Error::Create("Left and right part of assigment should be equal sized", ctx));
  }

  for (int i = 0; i < ctx->identifierList()->IDENTIFIER().size(); i++) {
    std::string name = ctx->identifierList()->IDENTIFIER(i)->getText();
    if (name == "_") {
      continue;
    }
    EValue expr = std::any_cast<EValue>(ctx->expressionList()->expression(i)->accept(this));

    auto mem = goIrBuilder->getNamed(name);
    if (!mem) {
      mem = goIrBuilder->allocateMemory(expr->getType());
      goIrBuilder->addNamedValue(name, mem);
    }

    goIrBuilder->assign(mem, expr);
  }

  return EValue();
}

antlrcpp::Any ParserVisitor::visitIfStmt(GoParser::IfStmtContext *ctx) {
  EValue CondV = std::any_cast<EValue>(ctx->expression()->accept(this));
  auto ifBlockBuilder = [this, ctx]() {
    ctx->block(0)->statementList()->accept(this);
  };
  std::function<void()> elseBlock = nullptr;

  if (ctx->ELSE()) {
    elseBlock = [this, ctx]() {
      if (ctx->ifStmt()) {
        ctx->ifStmt()->accept(this);
      } else {
        ctx->block(1)->accept(this);
      }
    };
  }

  return goIrBuilder->createIf(CondV, ifBlockBuilder, elseBlock);
}

antlrcpp::Any ParserVisitor::visitForStmt(GoParser::ForStmtContext *ctx) {
  auto trueConstant = goIrBuilder->createBoolConstant(true);

  std::function<void()> Init = []() {};
  std::function<EValue()> Cond = [trueConstant]() { return trueConstant; };
  std::function<void()> After = []() {};

  if (ctx->forClause()) {
    Init = [this, ctx]() {
      ctx->forClause()->children[0]->accept(this);
    };
    Cond = [this, ctx]() -> EValue {
      return std::any_cast<EValue>(ctx->forClause()->children[2]->accept(this));
    };
    After = [this, ctx]() {
      ctx->forClause()->children[4]->accept(this);
    };
  } else if (ctx->rangeClause()) {
    auto range = ctx->rangeClause();
    EValue rExpr = std::any_cast<EValue>(range->expression()->accept(this));
    if (!rExpr) return rExpr;

    if (!rExpr->getType().getTypeDetails().intInfo) {
      return EValue(Error::Create("Supports only range(int)"));
    }
    auto lexpr = std::make_shared<EValue>();

    Init = [this, range, lexpr]() {
      EValue initVal = goIrBuilder->createIntConstant(0);
      if (range->identifierList()) {
        *lexpr = goIrBuilder->allocateMemory(initVal->getType());
        auto name = range->identifierList()->IDENTIFIER(0)->getText();
        goIrBuilder->addNamedValue(name, *lexpr);
      } else {
        *lexpr = std::any_cast<EValue>(range->expressionList()->expression(0)->accept(this));
      }
      goIrBuilder->assign(*lexpr, initVal);
    };
    Cond = [this, lexpr, rExpr]() -> EValue {
      return goIrBuilder->createBinOperation(GoIrBuilder::Lt, *lexpr, rExpr);
    };
    After = [this, lexpr]() {
      auto oneConst = goIrBuilder->createIntConstant(1);
      auto sumRes = goIrBuilder->createBinOperation(GoIrBuilder::Add, *lexpr, oneConst);
      goIrBuilder->assign(*lexpr, sumRes);
    };
  } else if (ctx->expression()) {
    Cond = [this, ctx]() -> EValue {
      return std::any_cast<EValue>(ctx->expression()->accept(this));
    };
  } else if (ctx->children.size() != 2) {
    return EValue(Error::Create("Unsupported for type", ctx));
  }

  auto Block = [this, ctx]() {
    ctx->block()->statementList()->accept(this);
  };

  return goIrBuilder->createFor(Init, Cond, After, Block);
}

antlrcpp::Any ParserVisitor::visitBreakStmt(GoParser::BreakStmtContext *ctx) {
  return goIrBuilder->createBreak();
}
antlrcpp::Any ParserVisitor::visitContinueStmt(GoParser::ContinueStmtContext *ctx) {
  return goIrBuilder->createContinue();
}
ParserVisitor::ParserVisitor(const std::shared_ptr<GoIrBuilder> &go_ir_builder) : goIrBuilder(go_ir_builder) {}
