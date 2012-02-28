#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/ivisitor.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

void VariableProcessor::ProcessVarList( AstNode* ast_node , ProcessorInfo* info ) {
  IVisitor* visitor = info->GetVisitor();
  NodeIterator iterator = ast_node->ChildNodes();
  Function* fn = info->GetInfo()->GetFunction();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->empty() ) {
      if ( AstUtils::IsDestructringLeftHandSide( item ) ) {
        Literal* value = DstaProcessor::ProcessNode( item , info );
        value->set_value_type( Literal::kVariable );
        AstNode* initialiser = value->first_child();
        if ( !initialiser->empty() ) {
          initialiser->Accept( visitor );
        }
        Function* fn = info->GetInfo()->GetFunction();
        if ( fn ) {
          fn->set_variable_list( value );
        }
      } else {
        if ( !item->empty() ) {
          ProcessVarInitialiser( item->CastToLiteral() , info );
        }
      }
    }
  }
}


void VariableProcessor::ProcessVarInitialiser( Literal* ast_node , ProcessorInfo* info ) {
  Function* fn = info->GetInfo()->GetFunction();
  if ( fn ) {
    fn->set_variable_list( ast_node );
  }
  AstNode* initialiser = ast_node->first_child();
  if ( initialiser && !initialiser->empty() ) {
    initialiser->Accept( info->GetVisitor() );
  }  
}

}
