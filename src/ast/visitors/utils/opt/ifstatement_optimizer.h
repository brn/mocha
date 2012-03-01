#ifndef mocha_ifstatement_optimizer_h_
#define mocha_ifstatement_optimizer_h_
#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>
namespace mocha {
class CompileInfo;
class IVisitor;
class IFStmtOptimizer {
 public :
  IFStmtOptimizer( CompileInfo* info , IFStmt* stmt );
  ~IFStmtOptimizer(){}
  void Optimize( IVisitor* visitor );
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
  void OptimizeBlock( AstNode* block , int type );
  void ToIFStmtCompatibleExpression();
  void ToConditionalReturn( AstNode* then_stmt , AstNode* else_stmt );
  void ToLogical( AstNode* then_stmt );
  void ToNoElse( AstNode* then_stmt , AstNode* else_stmt );
  void ToConditional( AstNode* then_stmt , AstNode* else_stmt );
  int IsConvertableToExpression( AstNode* then_stmt , AstNode* else_stmt );
  CompileInfo* info_;
  IFStmt* stmt_;
};

}

#endif
