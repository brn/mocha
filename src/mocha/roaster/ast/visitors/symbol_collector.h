#ifndef mocha_symbol_collector_h_
#define mocha_symbol_collector_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
namespace mocha {
class ScopeRegistry;
class Scope;
class CompilationInfo;
class SymbolCollector : public IVisitor {
 public :
  SymbolCollector(ScopeRegistry* scope_registry, CompilationInfo* info);
  ~SymbolCollector(){};
#include <mocha/roaster/ast/visitors/visitor_decl.h>
 private :
  void ArrayAccessorProccessor_(CallExp* exp);
  void DotAccessorProccessor_(CallExp* exp);
  void NewCallProccessor_(CallExp* exp);
  void NormalFunctionCall_(CallExp* exp);
  void ArrayProccessor_(AstNode* ast_node);
  void ObjectProccessor_(AstNode* ast_node);
  void Rename(Literal* lit);
  int depth_;
  int scope_index_;
  CompilationInfo* info_;
  ScopeRegistry* scope_registry_;
  Scope* scope_;
};

}

#endif
