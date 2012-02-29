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
  IVisitor* visitor = info->visitor();
  NodeIterator iterator = ast_node->ChildNodes();
  Function* fn = info->visitor_info()->function();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      if ( AstUtils::IsDestructringLeftHandSide( item ) ) {
        Literal* value = DstaProcessor::ProcessNode( item , info );
        value->set_value_type( Literal::kVariable );
        AstNode* initialiser = value->first_child();
        if ( !initialiser->IsEmpty() ) {
          initialiser->Accept( visitor );
        }
        Function* fn = info->visitor_info()->function();
        if ( fn ) {
          fn->set_variable_list( value );
        }
      } else {
        if ( !item->IsEmpty() ) {
          ProcessVarInitialiser( item->CastToLiteral() , info );
        }
      }
    }
  }
}


void VariableProcessor::ProcessVarInitialiser( Literal* ast_node , ProcessorInfo* info ) {
  Function* fn = info->visitor_info()->function();
  if ( fn ) {
    fn->set_variable_list( ast_node );
  }
  AstNode* initialiser = ast_node->first_child();
  if ( initialiser && !initialiser->IsEmpty() ) {
    initialiser->Accept( info->visitor() );
  }  
}

}
