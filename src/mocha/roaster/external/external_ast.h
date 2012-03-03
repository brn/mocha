#ifndef mocha_external_ast_h_
#define mocha_external_ast_h_
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <utils/class_traits/uncopyable.h>
namespace mocha {

class ExternalAst : private Uncopyable {
 public :
  static Handle<ExternalAst> Create();
  AstRoot* GetRoot() { return root_; }
  ~ExternalAst(){}
 private :
  ExternalAst();
  ManagedScope scope_;
  AstRoot* root_;
};

}

#endif
