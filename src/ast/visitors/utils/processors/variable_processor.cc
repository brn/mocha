#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/ast.h>
namespace mocha {

VariableProcessor* VariableProcessor::GetInstance( AstVisitor* visitor , Scope* scope , VisitorInfo* info ) {
  return ProcessorUtil::GetInstance<VariableProcessor>( visitor , scope , info );
}

VariableProcessor::VariableProcessor( AstVisitor* visitor , Scope* scope , VisitorInfo* info ) :
    visitor_( visitor ) , scope_( scope ) , visitor_info_( info ) {}


void ProcessVarList( AstNode* ast_node ) {
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      ValueNode* value = item->CastToValue();
      if ( value && ( value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) ) {
        ValueNode* dst_node = item->CastToValue();
        dst_node->Node()->Accept( visitor_ );
        printf( "type %s\n" ,dst_node->Node()->CastToValue()->Symbol()->GetToken() );
        dst_node->ValueType( ValueNode::kVariable );
        dst_node->Symbol( dst_node->Node()->CastToValue()->Symbol() );
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          initialiser->Accept( visitor_ );
        }
      } else {
        item->Accept( visitor_ );
      }
    }
  }
}


void ProcessVarInitialiser( AstNode* ast_node ) {
  if ( ast_node->ValueType() == ValueNode::kVariable ) {
    //ast_node->Symbol()->Accept( this );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( !initialiser->IsEmpty() ) {
    initialiser->Accept( visitor_ );
  }  
}

}
