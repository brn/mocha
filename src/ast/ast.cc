#include <ast/ast.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

AstNode::AstNode( int type , const char* name ) :
    Managed(),
    type_( type ) , child_length_( 0 ) ,line_( 0 ) , name_( name ),
    parent_( 0 ), first_child_( 0 ) , last_child_( 0 ),
    next_sibling_( 0 ) , prev_sibling_( 0 ) {}

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
  } else {
    first_child_->prev_sibling_ = node;
    node->next_sibling_ = first_child_;
    first_child_ = node;
    node->prev_sibling_ = 0;
  }
  node->parent_ = this;
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
    if ( target->prev_sibling_ ) {
      target->prev_sibling_->next_sibling_ = insert;
    }
    target->prev_sibling_ = insert;
    insert->next_sibling_ = target;
  }
  insert->parent_ = this;
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
    if ( target->next_sibling_ ) {
      target->next_sibling_->prev_sibling_ = insert;
    }
    target->next_sibling_ = insert;
    insert->prev_sibling_ = target;
  }
  insert->parent_ = this;
  child_length_++;
}

void AstNode::Append( AstNode* node ) {
  if ( node ) {
    typedef std::list<AstNode*> AstArray;
    AstArray ast_array;
    NodeIterator iterator = node->ChildNodes();
    while ( iterator.HasNext() ) {
      ast_array.push_back( iterator.Next() );
    }
    AstArray::iterator begin = ast_array.begin() , end = ast_array.end();
    while ( begin != end ) {
      AddChild( (*begin) );
      ++begin;
    }
  }
}

void AstNode::RemoveAllChild() {
  NodeIterator iterator = ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( item->parent_ == this ) {
      item->parent_ = 0;
    }
  }
  first_child_ = 0;
  last_child_ = 0;
  child_length_ = 0;
}

AstNode* NodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->NextSibling();
  return ret;
}


AstNode* ReverseNodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->PreviousSibling();
  return ret;
}

void AstNode::RemoveChild( AstNode* node ) {
  AstNode* match_ptr = 0;
  NodeIterator iterator = ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( item == node ) {
      match_ptr = item;
      break;
    }
  }
  if ( match_ptr ) {
    child_length_--;
    if ( match_ptr->parent_ == this ) {
      match_ptr->parent_ = 0;
    }
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
  new_node->ParentNode( this );
}

template <typename T , typename T2>
inline T2* CopyChildren( T* dest , T2* source ) {
  dest->ParentNode( source->ParentNode() );
  NodeIterator iter = source->ChildNodes();
  while ( iter.HasNext() ) {
    dest->AddChild( iter.Next()->Clone() );
  }
  return dest;
}

#define NORMAL_CLONE( name )                    \
  AstNode* name::Clone() {                      \
    name* ret = ManagedHandle::Retain<name>();  \
    ret->Line( Line() );                        \
    return CopyChildren( ret , this );          \
  }

NORMAL_CLONE(NodeList);
NORMAL_CLONE(Empty);
NORMAL_CLONE(AstRoot);
AstNode* FileRoot::Clone() {
  FileRoot* root = ManagedHandle::Retain<FileRoot>();
  root->is_file_root_ = is_file_root_;
  root->filepath_ = filepath_;
  return CopyChildren( root , this );
}
NORMAL_CLONE(StatementList);

AstNode* VersionStmt::Clone() {
  TokenInfo *info = new TokenInfo( ver_->GetToken() , ver_->GetType() , ver_->GetLineNumber() );
  VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( info ) );
  return CopyChildren( stmt , this );
}

AstNode* PragmaStmt::Clone() {
  AstNode* op = op_->Clone();
  PragmaStmt* prg_stmt = ManagedHandle::Retain<PragmaStmt>();
  prg_stmt->Op( op->CastToValue() );
  return CopyChildren( prg_stmt , this );
}

void PragmaStmt::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( op_ == old_node ) {
    op_ = new_node;
    new_node->After( old_node->NextSibling() );
    new_node->Before( old_node->PreviousSibling() );
    new_node->ParentNode( this );
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

NORMAL_CLONE(BlockStmt);
NORMAL_CLONE(ModuleStmt);
NORMAL_CLONE(ExportStmt);

AstNode* ImportStmt::Clone() {
  ImportStmt* ret = ManagedHandle::Retain( new ImportStmt( var_type_ , mod_type_ ) );
  if ( exp_ ) {
    ret->exp_ = exp_->Clone();
    ret->exp_->ParentNode( ret );
  }
  if ( from_ ) {
    ret->from_ = from_->Clone();
    ret->from_->ParentNode( ret );
  }
  if ( key_ ) {
    ret->key_ = ManagedHandle::Retain( new TokenInfo( key_->GetToken() , key_->GetType() , key_->GetLineNumber() ) );
  }
  return CopyChildren( ret , this );
}

AstNode* VariableStmt::Clone() {
  VariableStmt* stmt = ManagedHandle::Retain<VariableStmt>();
  stmt->var_type_ = var_type_;
  if ( ChildLength() > 0 ) {
    return CopyChildren( stmt , this );
  }
}

AstNode* LetStmt::Clone() {
  LetStmt* stmt = ManagedHandle::Retain<LetStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
    stmt->exp_->ParentNode( stmt );
  }
  return CopyChildren( stmt ,this );
}

NORMAL_CLONE(ExpressionStmt);

void IFStmt::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( exp_ == old_node ) {
    exp_ = new_node;
    new_node->After( old_node->NextSibling() );
    new_node->Before( old_node->PreviousSibling() );
    new_node->ParentNode( this );
  } else if ( then_ == old_node ) {
    then_ = new_node;
    new_node->After( old_node->NextSibling() );
    new_node->Before( old_node->PreviousSibling() );
    new_node->ParentNode( this );
  } else if ( else_ == old_node ) {
    else_ = new_node;
    new_node->After( old_node->NextSibling() );
    new_node->Before( old_node->PreviousSibling() );
    new_node->ParentNode( this );
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* IFStmt::Clone() {
  IFStmt* stmt = ManagedHandle::Retain<IFStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
    stmt->exp_->ParentNode( stmt );
  }
  if ( then_ ) {
    stmt->then_ = then_->Clone();
    stmt->then_->ParentNode( stmt );
  }
  if ( else_ ) {
    stmt->else_ = else_->Clone();
    stmt->else_->ParentNode( stmt );
  }
  return CopyChildren( stmt ,this );
}

AstNode* IterationStmt::Clone() {
  IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( NodeType() ) );
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
    stmt->exp_->ParentNode( stmt );
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
    stmt->exp_->ParentNode( stmt );
  }
  return CopyChildren( stmt , this );
}

NORMAL_CLONE(LabelledStmt);

AstNode* SwitchStmt::Clone() {
  SwitchStmt* stmt = ManagedHandle::Retain<SwitchStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
    stmt->exp_->ParentNode( stmt );
  }
  return CopyChildren( stmt ,this );
}

AstNode* ThrowStmt::Clone() {
  ThrowStmt* stmt = ManagedHandle::Retain<ThrowStmt>();
  if ( exp_ ) {
    stmt->exp_ = exp_->Clone();
    stmt->exp_->ParentNode( stmt );
  }
  return CopyChildren( stmt , this );
}

AstNode* TryStmt::Clone() {
  TryStmt* stmt = ManagedHandle::Retain<TryStmt>();
  if ( catch_ ) {
    stmt->catch_ = catch_->Clone();
    stmt->catch_->ParentNode( stmt );
  }
  if ( finally_ ) {
    stmt->finally_ = finally_->Clone();
    stmt->finally_->ParentNode( stmt );
  }
  return CopyChildren( stmt , this );
}

NORMAL_CLONE(AssertStmt);

AstNode* CaseClause::Clone() {
  CaseClause* clause = ManagedHandle::Retain<CaseClause>();
  if ( exp_ ) {
    clause->exp_ = exp_->Clone();
    clause->exp_->ParentNode( clause );
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
    cls->body_->ParentNode( cls );
  }
  return CopyChildren( cls , this );
}

AstNode* ClassProperties::Clone() {
  ClassProperties *prop = ManagedHandle::Retain<ClassProperties>();
  CopyChildren( &( prop->public_ ) , &public_ );
  CopyChildren( &( prop->private_ ) , &private_ );
  CopyChildren( &( prop->public_static_ ) , &public_static_ );
  CopyChildren( &( prop->private_static_ ) , &private_static_ );
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
    fn->argv_->ParentNode( fn );
  }
  fn->fn_type_ = fn_type_;
  fn->context_ = context_;
  fn->fn_attr_ = fn_attr_;
  fn->is_const_ = is_const_;
  fn->is_decl_ = is_decl_;
  fn->is_root_ = is_root_;
  fn->has_directive_ = has_directive_;
  fn->has_yield_ = has_yield_;
  fn->replaced_this_ = replaced_this_;
  fn->iteration_list_ = iteration_list_;
  fn->variable_list_ = variable_list_;
  fn->try_list_ = try_list_;
  fn->Line( Line() );
  return CopyChildren( fn , this );
}

void CallExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == callable_ ) {
    new_node->Before( 0 );
    new_node->After( 0 );
    new_node->ParentNode( this );
    callable_ = new_node;
  } else if ( old_node == args_ ) {
    new_node->Before( 0 );
    new_node->After( 0 );
    new_node->ParentNode( this );
    args_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* CallExp::Clone() {
  CallExp *exp = ManagedHandle::Retain( new CallExp( call_type_ ) );
  if ( callable_ ) {
    exp->callable_ = callable_->Clone();
    exp->callable_->ParentNode( exp );
  }
  if ( args_ ) {
    exp->args_ = args_->Clone();
    exp->args_->ParentNode( exp );
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

NORMAL_CLONE(YieldExp);


void PostfixExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == exp_ ) {
    new_node->Before( exp_->PreviousSibling() );
    new_node->After( exp_->NextSibling() );
    new_node->ParentNode( this );
    exp_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* PostfixExp::Clone() {
  PostfixExp* exp = ManagedHandle::Retain( new PostfixExp( post_type_ ) );
  if ( exp_ ) {
    exp->exp_ = exp_->Clone();
    exp->exp_->ParentNode( exp );
  }
  return CopyChildren( exp , this );
}


void UnaryExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == exp_ ) {
    new_node->Before( exp_->PreviousSibling() );
    new_node->After( exp_->NextSibling() );
    new_node->ParentNode( this );
    exp_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* UnaryExp::Clone() {
  UnaryExp* exp = ManagedHandle::Retain( new UnaryExp( op_ ) );
  if ( exp_ ) {
    exp->exp_ = exp_->Clone();
    exp->exp_->ParentNode( exp );
  }
  return CopyChildren( exp , this );
}

void BinaryExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_ ) {
    new_node->Before( left_->PreviousSibling() );
    new_node->After( left_->NextSibling() );
    new_node->ParentNode( this );
    left_ = new_node;
  } else if ( old_node == right_ ) {
    new_node->Before( right_->PreviousSibling() );
    new_node->After( right_->NextSibling() );
    new_node->ParentNode( this );
    right_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* BinaryExp::Clone() {
  BinaryExp* exp = ManagedHandle::Retain( new BinaryExp( op_ , left_->Clone() , right_->Clone() ) );
  exp->Left()->ParentNode( exp );
  exp->Right()->ParentNode( exp );
  return CopyChildren( exp , this );
}


void CompareExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_ ) {
    new_node->Before( left_->PreviousSibling() );
    new_node->After( left_->NextSibling() );
    new_node->ParentNode( this );
    left_ = new_node;
  } else if ( old_node == right_ ) {
    new_node->Before( right_->PreviousSibling() );
    new_node->After( right_->NextSibling() );
    new_node->ParentNode( this );
    right_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* CompareExp::Clone() {
  CompareExp* exp = ManagedHandle::Retain( new CompareExp( op_ , left_->Clone() , right_->Clone() ) );
  exp->Left()->ParentNode( exp );
  exp->Right()->ParentNode( exp );
  return CopyChildren( exp , this );
}


void ConditionalExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == cond_ ) {
    new_node->Before( cond_->PreviousSibling() );
    new_node->After( cond_->NextSibling() );
    new_node->ParentNode( this );
    cond_ = new_node;
  } else if ( old_node == case_true_ ) {
    new_node->Before( case_true_->PreviousSibling() );
    new_node->After( case_true_->NextSibling() );
    new_node->ParentNode( this );
    case_true_ = new_node;
  } else if ( old_node == case_false_ ) {
    new_node->Before( case_false_->PreviousSibling() );
    new_node->After( case_false_->NextSibling() );
    new_node->ParentNode( this );
    case_false_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* ConditionalExp::Clone() {
  ConditionalExp* exp = ManagedHandle::Retain( new ConditionalExp( cond_->Clone(),
                                                                   case_true_->Clone() , case_false_->Clone() ) );
  exp->Cond()->ParentNode( exp );
  exp->True()->ParentNode( exp );
  exp->False()->ParentNode( exp );
  return CopyChildren( exp , this );
}


void AssignmentExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_ ) {
    new_node->Before( left_->PreviousSibling() );
    new_node->After( left_->NextSibling() );
    new_node->ParentNode( this );
    left_ = new_node;
  } else if ( old_node == right_ ) {
    new_node->Before( right_->PreviousSibling() );
    new_node->After( right_->NextSibling() );
    new_node->ParentNode( this );
    right_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* AssignmentExp::Clone() {
  AssignmentExp* exp = ManagedHandle::Retain( new AssignmentExp( op_ , left_->Clone() , right_->Clone() ) );
  exp->Left()->ParentNode( exp );
  exp->Right()->ParentNode( exp );
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
    case kProperty :
    case kSuper :
      if ( value_ ) {
        TokenInfo* info = ManagedHandle::Retain( new TokenInfo( value_->GetToken() , value_->GetType(),
                                                                value_->GetLineNumber() ) );
        ret->value_ = info;
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
    case kPrivateProperty :
    case kGenerator :
    case kTuple :
    case kRecord :
      if ( node_ ) {
        ret->node_ = node_->Clone();
      } else if ( value_ ) {
        TokenInfo* info = ManagedHandle::Retain( new TokenInfo( value_->GetToken() , value_->GetType(),
                                                                value_->GetLineNumber() ) );
        ret->value_ = info;
      }
      break;
  }
  ret->Line( Line() );
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
