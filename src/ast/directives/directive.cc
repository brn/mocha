#include <ast/directives/directive.h>
#include <ast/directives/run_v8.h>
namespace mocha {

Directive::Directive( AstNode* node , ProcessorInfo* info ) :
    node_( node ) , info_( info ){}

AstNode* Directive::Eval() {
  std::string ret;
  NodeIterator iterator = node_->ChildNodes();
  while ( iterator.HasNext() ) {
    ret += iterator.Next()->ToString();
  }
}

}
