#include <ast/ast.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

AstNode::AstNode( int type , const char* name ) : Managed(),
    type_( type ) , child_length_( 0 ) , name_( name ),
    parent_( 0 ), first_child_( 0 ) , last_child_( 0 ),
    next_sibling_( 0 ) , prev_sibling_( 0 ){}

void AstNode::AddChild( AstNode* node ) {
  if ( first_child_ == 0 ) {
    first_child_ = node;
    last_child_ = node;
    node->parent_ = this;
    node->next_sibling_ = 0;
    node->prev_sibling_ = 0;
  } else {
    last_child_->next_sibling_ = node;
    node->prev_sibling_ = last_child_;
    last_child_ = node;
    node->next_sibling_ = 0;
    node->parent_ = this;
  }
  child_length_++;
}

void AstNode::InsertBefore( AstNode* node ) {
  if ( first_child_ == 0 ) {
    first_child_ = node;
    last_child_ = node;
    node->next_sibling_ = 0;
    node->prev_sibling_ = 0;
    node->parent_ = this;
  } else {
    first_child_->prev_sibling_ = node;
    node->next_sibling_ = first_child_;
    first_child_ = node;
    node->prev_sibling_ = 0;
    node->parent_ = this;
  }
  child_length_++;
}

void AstNode::InsertBefore( AstNode* insert , AstNode* target ) {
  bool is_insert = false;
  if ( first_child_ == target ) {
    first_child_ = insert;
    target->prev_sibling_ = insert;
    insert->next_sibling_ = target;
    insert->prev_sibling_ = 0;
    is_insert = true;
  }

  if ( !is_insert ) {
    insert->prev_sibling_ = target->prev_sibling_;
    target->prev_sibling_->next_sibling_ = insert;
    target->prev_sibling_ = insert;
    insert->next_sibling_ = target;
  }
  
  child_length_++;
}

void AstNode::InsertAfter( AstNode* insert , AstNode* target ) {
  bool is_insert = false;

  if ( last_child_ == target  ) {
    last_child_ = insert;
    insert->prev_sibling_ = target;
    target->next_sibling_ = insert;
    insert->next_sibling_ = 0;
    is_insert = true;
  }

  if ( !is_insert ) {
    insert->next_sibling_ = target->next_sibling_;
    target->next_sibling_ = insert;
    insert->prev_sibling_ = target;
  }
  
  child_length_++;
}

void AstNode::Append( AstNode* node ) {
  if ( node ) {
    NodeIterator iterator = node->ChildNodes();
    while ( iterator.HasNext() ) {
      AddChild( iterator.Next() );
    }
  }
}

AstNode* NodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->NextSibling();
  return ret;
}

AstNode* NodeIterator::Item() {
  return node_;
}

AstNode* ReverseNodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->PreviousSibling();
  return ret;
}

AstNode* ReverseNodeIterator::Item() {
  return node_;
}

void AstNode::RemoveChild( AstNode* node ) {
  AstNode* match_ptr = 0;
  NodeIterator iterator = ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( item == node ) {
      match_ptr = item;
    }
  }
  if ( match_ptr ) {
    child_length_--;
    if ( match_ptr->next_sibling_ ) {
      match_ptr->next_sibling_->prev_sibling_ = match_ptr->prev_sibling_;
    }
    if ( match_ptr->prev_sibling_ ) {
      match_ptr->prev_sibling_->next_sibling_ = match_ptr->next_sibling_;
    }
    
    if ( first_child_ == match_ptr ) {
      if ( match_ptr->next_sibling_ ) {
        first_child_ = match_ptr->next_sibling_;
      } else {
        first_child_ = 0;
      }
    }

    if ( last_child_ == match_ptr ) {
      if ( match_ptr->prev_sibling_ ) {
        last_child_ = match_ptr->prev_sibling_;
      } else {
        last_child_ = 0;
      }
    }
    
  }
}

void AstNode::ReplaceWith( AstNode* node ) {
  node->parent_ = parent_;
  node->next_sibling_ = next_sibling_;
  node->prev_sibling_ = prev_sibling_;
  if ( next_sibling_ ) {
    next_sibling_->prev_sibling_ = node;
  }
  if ( prev_sibling_ ) {
    prev_sibling_->next_sibling_ = node;
  }
}


void AstNode::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( first_child_ ) {
    if ( old_node == first_child_ ) {
      first_child_ = new_node;
    }
    if ( old_node == last_child_ ) {
      last_child_ = new_node;
    }
    old_node->ReplaceWith( new_node );
  }
}

template <typename T , typename T2>
inline T2* CopyChildren( T* dest , T2* source ) {
  NodeIterator iter = source->ChildNodes();
  while ( iter.HasNext() ) {
    dest->AddChild( iter.Next()->Clone() );
  }
  return dest;
}

#define NORMAL_CLONE( name )                    \
  AstNode* name::Clone() {                      \
    name* ret = ManagedHandle::Retain<name>();  \
    return CopyChildren( ret , this );          \
  }

NORMAL_CLONE(NodeList);
NORMAL_CLONE(Empty);
NORMAL_CLONE(AstRoot);
NORMAL_CLONE(FileRoot);
NORMAL_CLONE(StatementList);

AstNode* VersionStmt::Clone() {
  TokenInfo *info = new TokenInfo( ver_->GetToken() , ver_->GetType() , ver_->GetLineNumber() );
  VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( info ) );
  return CopyChildren( stmt , this );
}

NORMAL_CLONE(BlockStmt);
NORMAL_CLONE(ModuleStmt);
NORMAL_CLONE(ExportStmt);

AstNode* ImportStmt::Clone() {
  ImportStmt* ret = ManagedHandle::Retain( new ImportStmt( var_type_ , mod_type_ ) );
  if ( exp_ ) {
    ret->exp_ = exp_->Clone();
  }
  if ( from_ ) {
    ret->from_ = from_->Clone();
  }
  if ( key_ ) {
    ret->key_ = ManagedHandle::Retain( new TokenInfo( key_->GetToken() , key_->GetType() , key_->GetLineNumber() ) );
  }
  return CopyChildren( ret , this );
}

AstNode* VariableStmt::Clone() {
  VariableStmt* stmt = ManagedHandle::Retain<VariableStmt>();
  stmt->var_type_ = var_type_;
  return CopyChildren( stmt , this );
}

AstNode* LetStmt::Clone() {
  LetStmt* stmt = ManagedHandle::Retain<LetStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }
  return CopyChildren( stmt ,this );
}

NORMAL_CLONE(ExpressionStmt);

AstNode* IFStmt::Clone() {
  IFStmt* stmt = ManagedHandle::Retain<IFStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }

  if ( then_ ) {
    stmt->then_ = then_->Clone();
  }

  if ( else_ ) {
    stmt->else_ = else_->Clone();
  }
  return CopyChildren( stmt ,this );
}

AstNode* IterationStmt::Clone() {
  IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( NodeType() ) );
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }
  return CopyChildren( stmt , this );
}

NORMAL_CLONE(ContinueStmt);
NORMAL_CLONE(BreakStmt);
NORMAL_CLONE(ReturnStmt);

AstNode* WithStmt::Clone() {
  WithStmt* stmt = ManagedHandle::Retain<WithStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }
  return CopyChildren( stmt , this );
}

NORMAL_CLONE(LabelledStmt);

AstNode* SwitchStmt::Clone() {
  SwitchStmt* stmt = ManagedHandle::Retain<SwitchStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }
  return CopyChildren( stmt ,this );
}

AstNode* ThrowStmt::Clone() {
  ThrowStmt* stmt = ManagedHandle::Retain<ThrowStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
  }
  return CopyChildren( stmt , this );
}

AstNode* TryStmt::Clone() {
  TryStmt* stmt = ManagedHandle::Retain<TryStmt>();
  if ( catch_ ) {
    stmt->catch_ = catch_->Clone();
  }
  if ( finally_ ) {
    stmt->finally_ = finally_->Clone();
  }
  return CopyChildren( stmt , this );
}

AstNode* CaseClause::Clone() {
  CaseClause* clause = ManagedHandle::Retain<CaseClause>();
  if ( exp_ ) {
    clause->exp_ = exp_->Clone();
  }
  return CopyChildren( clause , this );
}

AstNode* Expression::Clone() {
  Expression* exp = ManagedHandle::Retain<Expression>();
  exp->paren_ = paren_;
  return CopyChildren( exp , this );
}

AstNode* Class::Clone() {
  Class* cls = ManagedHandle::Retain( new Class( expandar_->Clone() , is_const_ ) );
  if ( name_ ) {
    cls->name_ = name_->Clone();
  }
  if ( body_ ) {
    cls->body_ = body_->Clone();
  }
  return CopyChildren( cls , this );
}

AstNode* ClassProperties::Clone() {
  ClassProperties *prop = ManagedHandle::Retain<ClassProperties>();
  CopyChildren( &( prop->public_ ) , &public_ );
  CopyChildren( &( prop->private_ ) , &private_ );
  CopyChildren( &( prop->static_ ) , &static_ );
  CopyChildren( &( prop->prototype_ ) , &prototype_ );
  CopyChildren( prop->constructor_ , constructor_ );
  return CopyChildren( prop , this );
}

AstNode* ClassExpandar::Clone() {
  ClassExpandar* exp = ManagedHandle::Retain( new ClassExpandar( attr_ ) );
  return CopyChildren( exp , this );
}

AstNode* ClassMember::Clone() {
  ClassMember* member = ManagedHandle::Retain( new ClassMember( attr_ ) );
  return CopyChildren( member , this );
}

AstNode* Function::Clone() {
  Function *fn = ManagedHandle::Retain<Function>();
  if ( name_ ) {
    fn->Name( name_->Clone() );
  }
  if ( argv_ ) {
    fn->Argv( argv_->Clone() );
  }
  fn->fn_type_ = fn_type_;
  fn->context_ = context_;
  fn->fn_attr_ = fn_attr_;
  fn->is_const_ = is_const_;
  return CopyChildren( fn , this );
}

AstNode* CallExp::Clone() {
  CallExp *exp = ManagedHandle::Retain( new CallExp( call_type_ ) );
  if ( callable_ ) {
    exp->callable_ = callable_->Clone();
  }
  if ( args_ ) {
    exp->args_ = args_->Clone();
  }
  exp->depth_ = depth_;
  return CopyChildren( exp , this );
}

AstNode* NewExp::Clone() {
  NewExp* exp = ManagedHandle::Retain<NewExp>();
  if ( constructor_ ) {
    exp->constructor_ = constructor_->Clone();
  }
  return CopyChildren( exp , this );
}

AstNode* PostfixExp::Clone() {
  PostfixExp* exp = ManagedHandle::Retain( new PostfixExp( post_type_ ) );
  if ( exp_ ) {
    exp->exp_ = exp_->Clone();
  }
  return CopyChildren( exp , this );
}

AstNode* UnaryExp::Clone() {
  UnaryExp* exp = ManagedHandle::Retain( new UnaryExp( op_ ) );
  if ( exp_ ) {
    exp->exp_ = exp_->Clone();
  }
  return CopyChildren( exp , this );
}

AstNode* BinaryExp::Clone() {
  BinaryExp* exp = ManagedHandle::Retain( new BinaryExp( op_ , left_->Clone() , right_->Clone() ) );
  return CopyChildren( exp , this );
}

AstNode* CompareExp::Clone() {
  CompareExp* exp = ManagedHandle::Retain( new CompareExp( op_ , left_->Clone() , right_->Clone() ) );
  return CopyChildren( exp , this );
}

AstNode* ConditionalExp::Clone() {
  ConditionalExp* exp = ManagedHandle::Retain( new ConditionalExp( cond_->Clone(),
                                                                   case_true_->Clone() , case_false_->Clone() ) );
  return CopyChildren( exp , this );
}

AstNode* AssignmentExp::Clone() {
  AssignmentExp* exp = ManagedHandle::Retain( new AssignmentExp( op_ , left_->Clone() , right_->Clone() ) );
  return CopyChildren( exp , this );
}

AstNode* ValueNode::Clone() {
  ValueNode* ret = ManagedHandle::Retain( new ValueNode( value_type_ ) );
  switch ( value_type_ ) {
    case kNull :
    case kTrue :
    case kFalse :
    case kNumeric :
    case kString :
    case kRegExp :
    case kThis : 
    case kIdentifier :
    case kPropertyName :
    case kVariable :
    case kRest :
      if ( value_ ) {
        ret->value_ = value_;
      } else if ( node_ ) {
        ret->node_ = node_->Clone();
      }
      break;
      
    case kArray :
    case kArrayComp :
    case kObject :
    case kDst :
    case kDstArray :
    case kSpread :
    case kConstant :
      if ( node_ ) {
        ret->node_ = node_->Clone();
      } else if ( value_ ) {
        ret->value_ = ManagedHandle::Retain( new TokenInfo( value_->GetToken() , value_->GetType() , value_->GetLineNumber() ) );
      }
      break;
  }
  return CopyChildren( ret , this );
}

AstNode* DstaTree::Clone() {
  DstaTree* tree = ManagedHandle::Retain<DstaTree>();
  if ( symbol_ ) {
    tree->symbol_ = symbol_->Clone()->CastToValue();
  }
  return CopyChildren( tree , this );
}

AstNode* DstaExtractedExpressions::Clone() {
  DstaExtractedExpressions* exp = ManagedHandle::Retain<DstaExtractedExpressions>();
  CopyChildren( &exp->refs_ , &refs_ );
  return CopyChildren( exp , this );
}

}
