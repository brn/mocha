#include <ast/visitors/utils/processors/object_processor.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/syntax_sugar_processor.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
namespace mocha {

ObjectProccessor::ObjectProccessor( ObjectLikeLiteral* literal , ProcessorInfo* info ) :
    literal_( literal ) , info_( info ){}

void ObjectProccessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->visitor_info();
  visitor_info->EnterObject();
  NodeIterator iterator = literal_->elements()->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* element = iterator.Next();
    element->first_child()->Accept( info_->visitor() );
    element->Accept( info_->visitor() );
  }
  visitor_info->EscapeObject();
  if ( literal_->IsRecord() ) {
    ProcessRecord();
  } else {
    if ( !visitor_info->IsInObject() ) {
      if ( visitor_info->private_property_list()->size() > 0 ) {
        AstNode* parent = literal_->parent_node();
        while ( !parent->CastToStatement() ) {
          parent = parent->parent_node();
        }
        Literal* name = AstUtils::CreateTmpNode( visitor_info->tmp_index() , literal_->line_number() );
        Literal* exp = AstUtils::CreateVarInitiliser( name->value() , literal_->Clone() , literal_->line_number() );
        VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( literal_->line_number() , 1 , exp );
        VariableStmt* stmt = AstUtils::CreateVarStmt( decl_list , literal_->line_number() );
        parent->parent_node()->InsertBefore( stmt , parent );
        literal_->parent_node()->ReplaceChild( literal_ , name->Clone() );
        ProcessPrivateProperty( name );
      }
    }
  }
}


typedef std::vector<Literal*> LiteralArray;

void CollectParentExpression( LiteralArray* expression_array , AstNode* parent , Literal* maybe_value ) {
  while ( 1 ) {
    if ( parent->CastToExpression() && parent->node_type() != AstNode::kObjectLikeLiteral ) {
      expression_array->push_back( parent->CastToLiteral() );
    }
    parent = parent->parent_node();
    if ( parent->node_type() == AstNode::kObjectLikeLiteral &&
         parent->parent_node()->parent_node()->node_type() != AstNode::kObjectLikeLiteral ) {
      break;
    }
  }
}

void ObjectProccessor::ProcessPrivateProperty( Literal *name ) {
  VisitorInfo::PrivateNameList *list = info_->visitor_info()->private_property_list();
  VisitorInfo::PrivateNameList::reverse_iterator begin = list->rbegin(),end = list->rend();
  while ( begin != end ) {
    LiteralArray expression_array;
    AstNode* cur_name = (*begin).first;
    expression_array.push_back( cur_name->CastToLiteral() );
    AstNode* parent = cur_name->parent_node();
    Literal* maybe_value = parent->CastToLiteral();
    CollectParentExpression( &expression_array , parent , maybe_value );
    LiteralArray::reverse_iterator expression_begin = expression_array.rbegin();
    LiteralArray::reverse_iterator expression_end = expression_array.rend();
    CallExp* exp = 0;
    while ( expression_begin != expression_end ) {
      Literal* val = (*expression_begin);
      if ( val->value_type() == Literal::kPrivateProperty ) {
        if ( exp == 0 ) {
          exp =  AstUtils::CreateArrayAccessor( name->Clone() , val->first_child()->Clone() , literal_->line_number() );
        } else {
          exp =  AstUtils::CreateArrayAccessor( exp , val->first_child()->Clone() , literal_->line_number() );
        }
      } else if ( val->value_type() == Literal::kIdentifier ||
                  val->value_type() == Literal::kProperty ) {
        val->set_value_type( Literal::kProperty );
        if ( exp == 0 ) {
          exp =  AstUtils::CreateDotAccessor( name->Clone() , val->Clone() , literal_->line_number() );
        } else {
          exp =  AstUtils::CreateDotAccessor( exp , val->Clone() , literal_->line_number() );
        }
      } else {
        if ( exp == 0 ) {
          exp =  AstUtils::CreateArrayAccessor( name->Clone() , val->Clone() , literal_->line_number() );
        } else {
          exp =  AstUtils::CreateArrayAccessor( exp , val->Clone() , literal_->line_number() );
        }
      }
      ++expression_begin;
    }
    Literal* unenum = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateUnenumProp ),
                                                Token::JS_IDENTIFIER , literal_->line_number() , Literal::kProperty );
    CallExp* runtime_call = AstUtils::CreateRuntimeMod( unenum , literal_->line_number() );
    NodeList* args = AstUtils::CreateNodeList( 3 , exp->callable() , exp->args() , (*begin).second->Clone() );
    CallExp* runtime_normal_call = AstUtils::CreateNormalAccessor( runtime_call , args , literal_->line_number() );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime_normal_call , literal_->line_number() );
    parent->parent_node()->InsertBefore( stmt , parent );
    ++begin;
  }
  list->clear();
}

void ObjectProccessor::ProcessRecord() {
  AstNode* parent = literal_->parent_node();
  Literal* create_record = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateRecord ),
                                                     Token::JS_IDENTIFIER , literal_->line_number() , Literal::kProperty );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_record , literal_->line_number() );
  NodeList* args = AstUtils::CreateNodeList( 1 , literal_ );
  CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args , literal_->line_number() );
  parent->ReplaceChild( literal_ , runtime_call );
}

}
