#ifndef mocha_external_ast_h_
#define mocha_external_ast_h_
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

class ExternalAst : private Uncopyable {
 public :
  static SharedPtr<ExternalAst> Create();
  AstRoot* GetRoot() { return root_; }
  memory::Pool* pool() { return &pool_; }
  ~ExternalAst(){}
 private :
  ExternalAst();
  memory::Pool pool_;
  AstRoot* root_;
};

}

#endif
