#ifndef mocha_optimizer_visitor_h_
#define mocha_optimizer_visitor_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
namespace mocha {
class CompileInfo;
class OptimizerVisitor : public IVisitor {
 public :
  OptimizerVisitor( CompileInfo* info );
  ~OptimizerVisitor(){}
#include <ast/visitors/visitor_decl.h>
 private :
  void ArrayAccessorProccessor_( CallExp* exp );
  void DotAccessorProccessor_( CallExp* exp );
  void NewCallProccessor_( CallExp* exp );
  void NormalFunctionCall_( CallExp* exp );
  void ArrayProccessor_( ValueNode* ast_node );
  void ObjectProccessor_( ValueNode* ast_node );
  int depth_;
  bool is_debug_;
  CompileInfo* info_;
  InnerScope* scope_;
};
}

#endif
