#ifndef mocha_directive_h_
#define mocha_directive_h_
#include <utils/class_traits/uncopyable.h>
namespace mocha {

class Directive {
 public :
  Directive( AstNode* ast_node , ProcessorInfo* info );
  ~Directive(){};
  AstNode* Eval();
 private :
  AstNode* node_;
  ProcessorInfo* info_;
};

}

#endif
