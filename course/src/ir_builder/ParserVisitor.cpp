//
// Created by volodya on 12.03.24.
//

#include <algorithm>
#include "ParserVisitor.h"

antlrcpp::Any ParserVisitor::visitSourceFile(GoParser::SourceFileContext *ctx) {
  goIrBuilder->setModuleName(ctx->packageClause()->IDENTIFIER()->getText());
  goIrBuilder->generateBuiltIns();

  for (auto &child : ctx->children) {
    child->accept(this);
  }

  return ValueWrapper::ptr(nullptr);
}

antlrcpp::Any ParserVisitor::visitImportDecl(GoParser::ImportDeclContext *ctx) {
  std::cerr << "Warning: Import statement is not supported: " << ctx->getText() << std::endl;
  return ValueWrapper::ptr(nullptr);
}

antlrcpp::Any ParserVisitor::visitTypeDecl(GoParser::TypeDeclContext *ctx) {
  auto err = goIrBuilder->createTypeDecl(ctx);
  if (err) {
    std::cerr << err->toString() << std::endl;
  }
  return EValue();
}

antlrcpp::Any ParserVisitor::visitFunctionDecl(GoParser::FunctionDeclContext *ctx) {
  auto res = goIrBuilder->createFunction(ctx, nullptr, ctx->IDENTIFIER(), ctx->signature(), ctx->block(), this);
  if (!res) {
    std::cerr << res.getError().toString() << std::endl;
  }
  return EValue();
}

ParserVisitor::ParserVisitor() {
  goIrBuilder = std::make_shared<GoIrBuilder>();
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
  auto typeNode = ctx->constSpec()[0]->type_();
  auto llvmType = goIrBuilder->GetType(typeNode);
  if (!llvmType) {
    std::cerr << "Can't find type : " << ctx->getText() << std::endl;
    return ValueWrapper::ptr(nullptr);
  }

  EValue expr = ctx->constSpec(0)->expressionList()->expression(0)->accept(this);
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
    EValue expr = exprNode->accept(this);
    if (!expr) {
      std::cerr << expr.getError().toString() << std::endl;
      return expr;
    }
    return goIrBuilder->toRHS(expr);
  });

  return goIrBuilder->createReturn(values);
}

antlrcpp::Any ParserVisitor::visitVarDecl(GoParser::VarDeclContext *ctx) {
  std::vector<ValueWrapper::ptr> right;
  auto varSpec = ctx->varSpec(0);

  if (varSpec->expressionList()) {
    auto exprList = varSpec->expressionList()->expression();
    std::transform(exprList.begin(), exprList.end(), std::back_inserter(right), [this](auto &expr) {
      EValue res = expr->accept(this);
      return res.GetValuePtr();
    });
  }

  std::optional<TypeWrapper> typeToCast;

  if (varSpec->type_()) {
    auto typeNode = varSpec->type_();
    typeToCast = goIrBuilder->GetType(typeNode);
    if (!typeToCast) {
      return EValue(Error::Create("Can't find type", ctx));
    }
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
    auto name = ids[0]->getText();
    auto mem = goIrBuilder->allocateMemory(*ty);

    if (!right.empty()) {
      auto val = goIrBuilder->assign(mem, right[i]);
      if (!val) {
        return val;
      }
    }
    goIrBuilder->addNamedValue(name, mem);
  }

  return EValue();
}

antlrcpp::Any ParserVisitor::visitPrimaryExpr(GoParser::PrimaryExprContext *ctx) {
  if (ctx->arguments()) {
    EValue function = ctx->primaryExpr()->accept(this);
    if (!function) {
      // try check casting
      auto function_name = ctx->primaryExpr()->getText();
      auto type2Cast = goIrBuilder->GetType(function_name);
      if (!type2Cast) {
        return function;
      }
      if (ctx->arguments()->expressionList()->expression().size() != 1) {
        return EValue(Error::Create("can't cast more than one value ", ctx));
      }

      EValue right = ctx->arguments()->expressionList()->expression(0)->accept(this);
      right = goIrBuilder->cast(right, *type2Cast);
      return right;
    }

    std::vector<EValue> ArgsV;

    if (ctx->arguments()->expressionList()) {
      auto exprs = ctx->arguments()->expressionList()->expression();
      std::transform(exprs.begin(), exprs.end(), std::back_inserter(ArgsV), [this](auto expr) -> EValue {
        return expr->accept(this);
      });
    }

    return goIrBuilder->createCall(function, ArgsV);
  }

  if (ctx->index()) {
    EValue left = ctx->primaryExpr()->accept(this);
    EValue indexV = ctx->index()->expression()->accept(this);

    return goIrBuilder->getByIndex(left, indexV);
  }

  if (ctx->DOT()) {
    EValue left = ctx->primaryExpr()->accept(this);
    auto fieldName = ctx->IDENTIFIER()->getText();

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
//  @todo: multile assign
  EValue lexpr = ctx->expressionList(0)->expression(0)->accept(this);
  EValue expr = ctx->expressionList(1)->expression(0)->accept(this);

  return goIrBuilder->assign(lexpr, expr);
}

antlrcpp::Any ParserVisitor::visitExpression(GoParser::ExpressionContext *ctx) {
  if (ctx->add_op || ctx->rel_op || ctx->mul_op) {
    EValue L = ctx->expression(0)->accept(this);
    EValue R = ctx->expression(1)->accept(this);

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
      EValue child = ctx->expression(0)->accept(this);
      if (!child) return child;

      auto value = child->getPointerTo();
      if (!value)
        return EValue(Error::Create("Can't get address", ctx));

      return EValue(value);
    }
    if (ctx->STAR()) {
      EValue child = ctx->expression(0)->accept(this);

      return goIrBuilder->deref(child);
    }
  }

  return GoParserBaseVisitor::visitExpression(ctx);
}

antlrcpp::Any ParserVisitor::visitShortVarDecl(GoParser::ShortVarDeclContext *ctx) {
  std::string name = ctx->identifierList()->IDENTIFIER(0)->getText();

  EValue expr = ctx->expressionList()->expression(0)->accept(this);

  auto mem = goIrBuilder->allocateMemory(expr->getType());
  goIrBuilder->addNamedValue(name, mem);
  return goIrBuilder->assign(mem, expr);
}

antlrcpp::Any ParserVisitor::visitIfStmt(GoParser::IfStmtContext *ctx) {
  EValue CondV = ctx->expression()->accept(this);
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
  auto Init = [this, ctx]() {
    ctx->forClause()->children[0]->accept(this);
  };
  auto Cond = [this, ctx]() -> EValue {
    return ctx->forClause()->children[2]->accept(this);
  };
  auto After = [this, ctx]() {
    ctx->forClause()->children[4]->accept(this);
  };

  auto Block = [this, ctx]() {
    ctx->block()->statementList()->accept(this);
  };

  return goIrBuilder->createFor(Init, Cond, After, Block);
}
const std::shared_ptr<GoIrBuilder> &ParserVisitor::GetGoIrBuilder() const {
  return goIrBuilder;
}
