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
  void DetermineOptimizeType_();
  void OptimizeBlock_( AstNode* block , int type );
  void ToIFStmtCompatibleExpression_();
  void ToConditionalReturn_( AstNode* then_stmt , AstNode* else_stmt );
  void ToLogical_( AstNode* then_stmt );
  void ToNoElse_( AstNode* then_stmt , AstNode* else_stmt );
  void ToConditional_( AstNode* then_stmt , AstNode* else_stmt );
  int IsConvertableToExpression_( AstNode* then_stmt , AstNode* else_stmt );
  CompileInfo* info_;
  IFStmt* stmt_;
};

}

#endif
