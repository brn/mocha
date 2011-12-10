#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/ivisitor.h>
#include <ast/ast.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

void VariableProcessor::ProcessVarList( AstNode* ast_node , ProcessorInfo* info ) {
  IVisitor* visitor = info->GetVisitor();
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      ValueNode* value = item->CastToValue();
      if ( value && ( value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) ) {
        value->Node()->Accept( visitor );
        printf( "type %s\n" ,value->Node()->CastToValue()->Symbol()->GetToken() );
        value->ValueType( ValueNode::kVariable );
        value->Symbol( value->Node()->CastToValue()->Symbol() );
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          initialiser->Accept( visitor );
        }
      } else {
        item->Accept( visitor );
      }
    }
  }
}


void VariableProcessor::ProcessVarInitialiser( ValueNode* ast_node , ProcessorInfo* info ) {
  if ( ast_node->ValueType() == ValueNode::kVariable ) {
    //ast_node->Symbol()->Accept( this );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( !initialiser->IsEmpty() ) {
    initialiser->Accept( info->GetVisitor() );
  }  
}

}
