#include "rewirter_util.h"
namespace mocha {

void RewriterUtil::AddNode( AstTypeBase* node , kAstTypeTag tag ) {
  node_ = node;
  tag_ = tag_;
}

void RewriterUtil::Connect( AstTypeBase* node , kAstTypeTag tag ) {
  switch ( tag_ ) {
    case kExpression :
      node_->Exp( node );
      break;
  }
}

}
