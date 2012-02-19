#ifndef mocha_symbol_collector_h_
#define mocha_symbol_collector_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
namespace mocha {
class Scope;
class SymbolCollector : public IVisitor {
 public :
  SymbolCollector( Scope* scope , bool is_debug );
  ~SymbolCollector(){};
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
  Scope* scope_;
};

}

#endif
