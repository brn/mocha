#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/ivisitor.h>
#include <ast/ast.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

void VariableProcessor::ProcessVarList( AstNode* ast_node , ProcessorInfo* info ) {
  IVisitor* visitor = info->GetVisitor();
  NodeIterator iterator = ast_node->ChildNodes();
  Function* fn = info->GetInfo()->GetFunction();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      ValueNode* value = item->CastToValue();
      if ( value && ( value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) ) {
        value->Node()->Accept( visitor );
        printf( "type %s\n" ,value->Node()->CastToValue()->Symbol()->GetToken() );
        value->ValueType( ValueNode::kVariable );
        value->Symbol( value->Node()->CastToValue()->Symbol() );
        if ( fn ) {
          fn->SetVariable( value );
        }
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          initialiser->Accept( visitor );
        }
      } else {
        printf( "node type %d\n" , item->NodeType() );
        if ( !item->IsEmpty() ) {
          ProcessVarInitialiser( item->CastToValue() , info );
        }
      }
    }
  }
}


void VariableProcessor::ProcessVarInitialiser( ValueNode* ast_node , ProcessorInfo* info ) {
  Function* fn = info->GetInfo()->GetFunction();
  if ( fn ) {
    fn->SetVariable( ast_node );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( initialiser && !initialiser->IsEmpty() ) {
    initialiser->Accept( info->GetVisitor() );
  }  
}

}
