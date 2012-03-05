#ifndef mocha_ast_visitors_utils_processor_h_
#define mocha_ast_visitors_utils_processor_h_
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
namespace mocha {
class Processor : private Uncopyable {
 public :
  Processor()
      : builder_(AstBuilder::Local()), pool_(memory::Pool::Local()){}
  ~Processor() {}
 protected :
  static AstBuilder* LocalBuilder() { return AstBuilder::Local(); }
  static memory::Pool* LocalPool() { return memory::Pool::Local(); }
  AstBuilder* builder() { return builder_; }
  memory::Pool* pool() { return pool_; }
 private :
  AstBuilder* builder_;
  memory::Pool* pool_;
};
}

#endif
