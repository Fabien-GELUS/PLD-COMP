
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalVariables(ifccParser::GlobalVariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBloc(ifccParser::BlocContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlocRet(ifccParser::BlocRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctions(ifccParser::FunctionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDecDef(ifccParser::FuncDecDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDecStrict(ifccParser::FuncDecStrictContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCall(ifccParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgsDecVar(ifccParser::ArgsDecVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastArgDec(ifccParser::LastArgDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoArgDec(ifccParser::NoArgDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgsVar(ifccParser::ArgsVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgsConst(ifccParser::ArgsConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastArgVar(ifccParser::LastArgVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastArgConst(ifccParser::LastArgConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoArg(ifccParser::NoArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(ifccParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementDeclaration(ifccParser::StatementDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementAffectation(ifccParser::StatementAffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementReturn(ifccParser::StatementReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoucleIf(ifccParser::BoucleIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoucleWhile(ifccParser::BoucleWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallAFunction(ifccParser::CallAFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarExpr(ifccParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharExpr(ifccParser::CharExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitsExpr(ifccParser::BitsExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpr(ifccParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(ifccParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicationExpr(ifccParser::MultiplicationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(ifccParser::FuncCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpr(ifccParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinusExpr(ifccParser::MinusExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstExpr(ifccParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalTestExpr(ifccParser::RelationalTestExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityTestExpr(ifccParser::EqualityTestExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParTestExpr(ifccParser::ParTestExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclMult(ifccParser::DeclMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastDecl(ifccParser::LastDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec(ifccParser::DecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffDecConst(ifccParser::AffDecConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffDecVar(ifccParser::AffDecVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffDecChar(ifccParser::AffDecCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffDecArray(ifccParser::AffDecArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffDecExpr(ifccParser::AffDecExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffVar(ifccParser::AffVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffConst(ifccParser::AffConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffChar(ifccParser::AffCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffExpr(ifccParser::AffExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffEltVar(ifccParser::AffEltVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffEltConst(ifccParser::AffEltConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffEltExpr(ifccParser::AffEltExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecGMult(ifccParser::DecGMultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastDecG(ifccParser::LastDecGContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecG(ifccParser::DecGContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecGAffConst(ifccParser::DecGAffConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecGAffChar(ifccParser::DecGAffCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfNoElse(ifccParser::IfNoElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfWithElse(ifccParser::IfWithElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElseIf(ifccParser::IfElseIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(ifccParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetVar(ifccParser::RetVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetConst(ifccParser::RetConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetExpr(ifccParser::RetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncType(ifccParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_elt(ifccParser::Array_eltContext *ctx) override {
    return visitChildren(ctx);
  }


};

