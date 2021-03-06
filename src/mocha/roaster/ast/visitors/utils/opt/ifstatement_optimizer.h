#ifndef mocha_ifstatement_optimizer_h_
#define mocha_ifstatement_optimizer_h_
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class CompilationInfo;
class IVisitor;
class IFStmtOptimizer : public Processor {
 public :
  IFStmtOptimizer(CompilationInfo* info, IFStmt* stmt);
  ~IFStmtOptimizer(){}
  void Optimize(IVisitor* visitor);
 private :
  enum {
    kThen,
    kElse
  };
  enum {
    kNone,
    kCondtionalReturn,
    kLogical,
    kNoElse,
    kConditional
  };
  void DetermineOptimizeType();
  void OptimizeBlock(AstNode* block, int type);
  void ToIFStmtCompatibleExpression();
  void ToConditionalReturn(AstNode* then_stmt, AstNode* else_stmt);
  void ToLogical(AstNode* then_stmt);
  void ToNoElse(AstNode* then_stmt, AstNode* else_stmt);
  void ToConditional(AstNode* then_stmt, AstNode* else_stmt);
  int IsConvertableToExpression(AstNode* then_stmt, AstNode* else_stmt);
  AstNode* ToExpression(AstNode* node);
  bool IsOptimizableBlock(AstNode* block, int type);
  AstNode* GetReturnValue(AstNode* node);
  bool CheckAssoc(AstNode* node);
  CompilationInfo* info_;
  IFStmt* stmt_;
};

}

#endif
