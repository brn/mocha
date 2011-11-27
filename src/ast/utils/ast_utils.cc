#include <ast/utils/ast_utils.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast.h>
#include <utils/pool/managed_handle.h>

namespace mocha {
ValueNode* AstUtils::CreateVariable( TokenInfo* token , AstNode* value ) {
  ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  node->Symbol( token );
  node->AddChild( value );
  return node;
}

CallExp* AstUtils::CreateAnonymousFunctionCall( AstNode* body , int is_append ) {
  CallExp *call = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
  Expression *exp = ManagedHandle::Retain<Expression>();
  Function *fn = ManagedHandle::Retain<Function>();
  fn->Name( GetEmptyNode() );
  fn->Argv ( GetEmptyNode() );
  if ( is_append == AstUtils::kAppend ) {
    NodeList* list = reinterpret_cast<NodeList*>( body );
    fn->Append( list );
  } else {
    fn->AddChild( body );
  }
  exp->AddChild( fn );
  exp->Paren();
  call->Callable( exp );
  call->Args( GetEmptyNode() );
  return call;
}

CallExp* AstUtils::CreateDotAccessor( AstNode* name , AstNode* prop ) {
  CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
  exp->Callable( name );
  exp->Args( prop );
  return exp;
}


AssignmentExp* AstUtils::CreateAssignment( int op , AstNode* left , AstNode* right ) {
  return ManagedHandle::Retain ( new AssignmentExp( op , left , right ) );
}


Empty* AstUtils::GetEmptyNode() {
  static Empty empty;
  return &empty;
}

}
