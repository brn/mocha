#ifndef mocha_optimizer_visitor_h_
#define mocha_optimizer_visitor_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
namespace mocha {
class Scope;
class OptimizerVisitor : public IVisitor {
 public :
  OptimizerVisitor( Scope* scope );
  ~OptimizerVisitor(){};
#include <ast/visitors/visitor_decl.h>
 private :
  void ArrayAccessorProccessor_( CallExp* exp );
  void DotAccessorProccessor_( CallExp* exp );
  void NewCallProccessor_( CallExp* exp );
  void NormalFunctionCall_( CallExp* exp );
  Scope* scope_;
};

}

#endif
