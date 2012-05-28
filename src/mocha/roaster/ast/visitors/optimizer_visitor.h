#ifndef mocha_optimizer_visitor_h_
#define mocha_optimizer_visitor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
namespace mocha {
namespace memory {
class Pool;
}
class AstBuilder;
class CompilationInfo;
class JsToken;
class OptimizerVisitor : public IVisitor {
 public :
  OptimizerVisitor(CompilationInfo* info);
  ~OptimizerVisitor(){}
#include <mocha/roaster/ast/visitors/visitor_decl.h>
 private :
  void ArrayAccessorProccessor_(CallExp* exp);
  void DotAccessorProccessor_(CallExp* exp);
  void NewCallProccessor_(CallExp* exp);
  void NormalFunctionCall_(CallExp* exp);
  void ArrayProccessor_(AstNode* ast_node);
  void ObjectProccessor_(AstNode* ast_node);
  memory::Pool* pool() { return pool_; }
  AstBuilder* builder() { return builder_; }
  int depth_;
  bool is_debug_;
  CompilationInfo* info_;
  Scope* scope_;
  memory::Pool* pool_;
  AstBuilder* builder_;
  JsToken* js_token_;
};
}

#endif
