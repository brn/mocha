#ifndef mocha_optimizer_visitor_h_
#define mocha_optimizer_visitor_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
#include <options/options.h>
namespace mocha {
class OptimizerVisitor : public IVisitor {
 public :
  OptimizerVisitor( Scope* scope ,  Options* option );
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
  Scope* scope_;
};
}

#endif
