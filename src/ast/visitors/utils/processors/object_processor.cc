#include <ast/visitors/utils/processors/object_processor.h>

namespace mocha {

ObjectProccessor::ObjectProccessor( ObjectLikeLiteral* literal , ProcessorInfo* info ) :
    literal_( literal ) , info_( info ){}

void ObjectProccessor::ProcessNode() {
  VisitorInfo* visitor_info = info->GetInfo();
  visitor_info->EnterObject();
  NodeIterator iterator = element_list->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* element = iterator.Next();
    element->first_child()->Accept( this );
    element->Accept( this );
  }
  visitor_info->EscapeObject();
  if ( literal_->record() ) {
    ProcessRecord();
  } else {
    if ( !visitor_info->IsInObject() ) {
      if ( visitor_info->GetObjectPrivateList().size() > 0 ) {
        AstNode* parent = ast_node->parent_node();
        while ( !parent->CastToStatement() ) {
          parent = parent->parent_node();
        }
        Literal* name = AstUtils::CreateTmpNode( visitor_info_->GetTmpIndex() );
        Literal* exp = AstUtils::CreateVarInitiliser( name->Symbol() , literal->Clone() );
        VariableStmt* stmt = AstUtils::CreateVarStmt( exp );
        parent->parent_node()->InsertBefore( stmt , parent );
        literal_->set_value( name->Symbol() );
        literal_->set_value_type( Literal::kIdentifier );
        literal_->RemoveAllChild();
        literal_->AddChild( name->Clone() );
        ProcessPrivateProperty( name );
      }
    }
  }
}

bool IsPropertParent( Literal* literal ) {
  return literal->value_type() == Literal::kPrivateProperty ||
      literal->value_type() == Literal::kProperty ||
      literal->value_type() == Literal::kString ||
      literal->value_type() == Literal::kNumeric ||
      literal->value_type() == Literal::kObjectLikeLiteral
}

typedef std::vector<Literal*> LiteralArray;

void CollectParentExpression( LiteralArray* expression_array , AstNode* parent , Literal* maybe_value ) {
  while ( name_parent && maybe_value && IsPropertParent( maybe_value ) ) {
    Literal* val = parent->CastToLiteral();
    if ( val && val->value_type() != Literal::kObjectLikeLiteral ) {
      expression_array->push_back( val );
    }
    parent = parent->parent_node();
    maybe_value = parent->CastToLiteral();
  }
}

void ObjectProccessor::ProcessPrivateProperty( Literal *name ) {
  VisitorInfo::PrivateNameList &list = visitor_info->GetObjectPrivateList();
  VisitorInfo::PrivateNameList::reverse_iterator begin = list.rbegin(),end = list.rend();
  while ( begin != end ) {
    LiteralArray expression_array;
    AstNode* cur_name = (*begin).first;
    exp_list.push_back( cur_name->CastToLiteral() );
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
          exp =  AstUtils::CreateArrayAccessor( name->Clone() , val->first_child()->Clone() );
        } else {
          exp =  AstUtils::CreateArrayAccessor( exp , val->first_child()->Clone() );
        }
      } else if ( val->value_type() == Literal::kIdentifier ||
                  val->value_type() == Literal::kProperty ) {
        val->set_value_type( Literal::kProperty );
        if ( exp == 0 ) {
          exp =  AstUtils::CreateDotAccessor( name->Clone() , val->Clone() );
        } else {
          exp =  AstUtils::CreateDotAccessor( exp , val->Clone() );
        }
      } else {
        if ( exp == 0 ) {
          exp =  AstUtils::CreateArrayAccessor( name->Clone() , val->Clone() );
        } else {
          exp =  AstUtils::CreateArrayAccessor( exp , val->Clone() );
        }
      }
      ++expression_begin;
    }
    Literal* unenum = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateUnenumProp ),
                                                Token::JS_PROPERTY , 0 , Literal::kProperty );
    CallExp* runtime_call = AstUtils::CreateRuntimeMod( unenum );
    NodeList* args = AstUtils::CreateNodeList( 3 , exp->callable() , exp->args() , (*begin).second->Clone() );
    CallExp* runtime_normal_call = AstUtils::CreateNormalAccessor( runtime_call , args );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime_normal_call );
    parent->parent_node()->InsertBefore( stmt , parent );
    ++begin;
  }
  list.clear();
}

void ObjectProccessor::ProcessRecord() {
  AstNode* parent = ast_node->parent_node();
  Literal* create_record = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateRecord ),
                                                     Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_record );
  NodeList* args = AstUtils::CreateNodeList( 1 , literal_ );
  CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args );
  parent->ReplaceChild( ast_node , runtime_call );
}

}
