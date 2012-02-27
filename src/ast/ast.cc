#include <ast/ast.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

AstNode::AstNode( int type , const char* name , int64_t line ) :
    Managed(),
    type_( type ) , child_length_( 0 ) ,line_( line ) , name_( name ),
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
  node_ = node_->next_sibling();
  return ret;
}


AstNode* ReverseNodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->previous_sibling();
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
  new_node->set_parent_node( this );
}

template <typename T , typename T2>
inline T2* CopyChildren( T* dest , T2* source ) {
  dest->set_parent_node( source->parent_node() );
  NodeIterator iter = source->ChildNodes();
  while ( iter.HasNext() ) {
    dest->AddChild( iter.Next()->Clone() );
  }
  return dest;
}

#define NORMAL_CLONE( name )                    \
  AstNode* name::Clone() {                      \
    name* ret = name::New();                    \
    return CopyChildren( ret , this );          \
  }

#define LINED_CLONE( name )                     \
  AstNode* name::Clone() {                      \
    name* ret = name::New( line_number() );     \
    return CopyChildren( ret , this );          \
  }

NORMAL_CLONE(NodeList);
NORMAL_CLONE(Empty);
NORMAL_CLONE(AstRoot);
AstNode* FileRoot::Clone() {
  FileRoot* root = FileRoot::New( filename_.c_str() );
  root->is_file_root_ = is_file_root_;
  return CopyChildren( root , this );
}
NORMAL_CLONE(StatementList);

AstNode* VersionStmt::Clone() {
  TokenInfo *info = TokenInfo::New( version_->token() , version_->type() , version_->line_number() );
  VersionStmt* stmt = VersionStmt::New( info , line_number() );
  return CopyChildren( stmt , this );
}

LINED_CLONE(BlockStmt);

AstNode* ModuleStmt::Clone() {
  ModuleStmt* stmt = ModuleStmt::New( name_ , line_number() );
  return CopyChildren( stmt , this );
}

LINED_CLONE(ExportStmt);

AstNode* ImportStmt::Clone() {
  ImportStmt* ret = ImportStmt::New( expression_type_ , module_type_ , line_number() );
  if ( expression_ ) {
    ret->expression_ = expression_->Clone();
    ret->expression_->set_parent_node( ret );
  }
  if ( from_ ) {
    ret->from_ = from_->Clone();
    ret->from_->set_parent_node( ret );
  }
  if ( module_key_ ) {
    ret->module_key_ = TokenInfo::New( module_key_->token() , module_key_->type() , module_key_->line_number() );
  }
  return CopyChildren( ret , this );
}

AstNode* VariableStmt::Clone() {
  VariableStmt* stmt = VariableStmt::New( line_number() );
  stmt->declaration_type_ = declaration_type_;
  return CopyChildren( stmt , this );
}

AstNode* LetStmt::Clone() {
  LetStmt* stmt = LetStmt::New( expression_ , line_number() );
  return CopyChildren( stmt ,this );
}

LINED_CLONE(ExpressionStmt);

void IFStmt::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( condition_ == old_node ) {
    condition_ = new_node;
    new_node->After( old_node->next_sibling() );
    new_node->Before( old_node->previous_sibling() );
    new_node->set_parent_node( this );
  } else if ( then_statement_ == old_node ) {
    then_statement_ = new_node;
    new_node->After( old_node->next_sibling() );
    new_node->Before( old_node->previous_sibling() );
    new_node->set_parent_node( this );
  } else if ( else_statement_ == old_node ) {
    else_statement_ = new_node;
    new_node->After( old_node->next_sibling() );
    new_node->Before( old_node->previous_sibling() );
    new_node->set_parent_node( this );
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* IFStmt::Clone() {
  IFStmt* stmt = IFStmt::New( line_number() );
  if ( condition_ ) {
    stmt->condition_ = condition_->Clone();
    stmt->condition_->set_parent_node( stmt );
  }
  if ( then_statement_ ) {
    stmt->then_statement_ = then_statement_->Clone();
    stmt->then_statement_->set_parent_node( stmt );
  }
  if ( else_statement_ ) {
    stmt->else_statement_ = else_statement_->Clone();
    stmt->else_statement_->set_parent_node( stmt );
  }
  return CopyChildren( stmt ,this );
}

AstNode* IterationStmt::Clone() {
  IterationStmt* stmt = IterationStmt::New( node_type() , line_number() );
  if ( expression_ ) {
    stmt->expression_ = expression_->Clone();
    stmt->expression_->set_parent_node( stmt );
  }
  return CopyChildren( stmt , this );
}

LINED_CLONE(ContinueStmt);
LINED_CLONE(BreakStmt);
LINED_CLONE(ReturnStmt);

AstNode* WithStmt::Clone() {
  WithStmt* stmt = WithStmt::New( line_number() );
  if ( expression_ ) {
    stmt->expression_ = expression_->Clone();
    stmt->expression_->set_parent_node( stmt );
  }
  return CopyChildren( stmt , this );
}

LINED_CLONE(LabelledStmt);

AstNode* SwitchStmt::Clone() {
  SwitchStmt* stmt = SwitchStmt::New( line_number() );
  if ( expression_ ) {
    stmt->expression_ = expression_->Clone();
    stmt->expression_->set_parent_node( stmt );
  }
  return CopyChildren( stmt ,this );
}

AstNode* ThrowStmt::Clone() {
  ThrowStmt* stmt = ThrowStmt::New( line_number() );
  if ( expression_ ) {
    stmt->expression_ = expression_->Clone();
    stmt->expression_->set_parent_node( stmt );
  }
  return CopyChildren( stmt , this );
}

AstNode* TryStmt::Clone() {
  TryStmt* stmt = TryStmt::New( line_number() );
  if ( catch_block_ ) {
    stmt->catch_block_ = catch_block_->Clone();
    stmt->catch_block_->set_parent_node( stmt );
  }
  if ( finally_block_ ) {
    stmt->finally_block_ = finally_block_->Clone();
    stmt->finally_block_->set_parent_node( stmt );
  }
  return CopyChildren( stmt , this );
}

LINED_CLONE(AssertStmt);

AstNode* CaseClause::Clone() {
  CaseClause* clause = CaseClause::New( line_number() );
  if ( expression_ ) {
    clause->expression_ = expression_->Clone();
    clause->expression_->set_parent_node( clause );
  }
  return CopyChildren( clause , this );
}

AstNode* Expression::Clone() {
  Expression* exp = Expression::New( line_number() );
  exp->flags_ = flags_;
  return CopyChildren( exp , this );
}

AstNode* Class::Clone() {
  Class* cls = Class::New( expandar_->Clone() , line_number() );
  if ( name_ ) {
    cls->name_ = name_->Clone();
    cls->name_->set_parent_node( cls );
  }
  if ( body_ ) {
    cls->body_ = body_->Clone();
    cls->body_->set_parent_node( cls );
  }
  cls->flags_ = flags_;
  return CopyChildren( cls , this );
}

AstNode* ClassProperties::Clone() {
  ClassProperties *prop = ClassProperties::New( line_number() );
  CopyChildren( &( prop->public_ ) , &public_ );
  CopyChildren( &( prop->private_ ) , &private_ );
  CopyChildren( &( prop->public_static_ ) , &public_static_ );
  CopyChildren( &( prop->private_static_ ) , &private_static_ );
  CopyChildren( &( prop->prototype_ ) , &prototype_ );
  prop->constructor_ = constructor_->Clone();
  return CopyChildren( prop , this );
}

AstNode* ClassExpandar::Clone() {
  ClassExpandar* exp = ClassExpandar::New( attr_ , line_number() );
  return CopyChildren( exp , this );
}

AstNode* ClassMember::Clone() {
  ClassMember* member = ClassMember::New( attr_ , line_number() );
  return CopyChildren( member , this );
}

AstNode* Function::Clone() {
  Function *fn = Function::New( line_number() );
  if ( name_ ) {
    fn->set_name( name_->Clone() );
  }
  if ( argv_ ) {
    fn->set_argv( argv_->Clone() );
    fn->argv_->set_parent_node( fn );
  }
  fn->fn_type_ = fn_type_;
  fn->context_ = context_;
  fn->fn_attr_ = fn_attr_;
  fn->flags_ = flags_;
  fn->replaced_this_ = replaced_this_;
  fn->statement_list_ = statement_list_;
  fn->variable_list_ = variable_list_;
  fn->try_catch_list_ = try_catch_list_;
  return CopyChildren( fn , this );
}

void CallExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == callable_ ) {
    new_node->Before( 0 );
    new_node->After( 0 );
    new_node->set_parent_node( this );
    callable_ = new_node;
  } else if ( old_node == args_ ) {
    new_node->Before( 0 );
    new_node->After( 0 );
    new_node->set_parent_node( this );
    args_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* CallExp::Clone() {
  CallExp *exp = CallExp::New( call_type_ , line_number() );
  if ( callable_ ) {
    exp->callable_ = callable_->Clone();
    exp->callable_->set_parent_node( exp );
  }
  if ( args_ ) {
    exp->args_ = args_->Clone();
    exp->args_->set_parent_node( exp );
  }
  return CopyChildren( exp , this );
}

AstNode* NewExp::Clone() {
  NewExp* exp = NewExp::New( line_number() );
  return CopyChildren( exp , this );
}

LINED_CLONE(YieldExp);


void PostfixExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == expression_ ) {
    new_node->Before( expression_->previous_sibling() );
    new_node->After( expression_->next_sibling() );
    new_node->set_parent_node( this );
    expression_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* PostfixExp::Clone() {
  PostfixExp* exp = PostfixExp::New( operand_ , expression_ , line_number() );
  return CopyChildren( exp , this );
}


void UnaryExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == expression_ ) {
    new_node->Before( expression_->previous_sibling() );
    new_node->After( expression_->next_sibling() );
    new_node->set_parent_node( this );
    expression_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* UnaryExp::Clone() {
  UnaryExp* exp = UnaryExp::New( operand_ , expression_ , line_number() );
  return CopyChildren( exp , this );
}

void BinaryExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_value_ ) {
    new_node->Before( left_value_->previous_sibling() );
    new_node->After( left_value_->next_sibling() );
    new_node->set_parent_node( this );
    left_value_ = new_node;
  } else if ( old_node == right_value_ ) {
    new_node->Before( right_value_->previous_sibling() );
    new_node->After( right_value_->next_sibling() );
    new_node->set_parent_node( this );
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* BinaryExp::Clone() {
  BinaryExp* exp = BinaryExp::New( operand_ , left_value_->Clone() , right_value_->Clone() , line_number() );
  exp->left_value()->set_parent_node( exp );
  exp->right_value()->set_parent_node( exp );
  return CopyChildren( exp , this );
}


void CompareExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_value_ ) {
    new_node->Before( left_value_->previous_sibling() );
    new_node->After( left_value_->next_sibling() );
    new_node->set_parent_node( this );
    left_value_ = new_node;
  } else if ( old_node == right_value_ ) {
    new_node->Before( right_value_->previous_sibling() );
    new_node->After( right_value_->next_sibling() );
    new_node->set_parent_node( this );
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* CompareExp::Clone() {
  CompareExp* exp = CompareExp::New( operand_ , left_value_->Clone() , right_value_->Clone() , line_number() );
  exp->left_value()->set_parent_node( exp );
  exp->right_value()->set_parent_node( exp );
  return CopyChildren( exp , this );
}


void ConditionalExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == condition_ ) {
    new_node->Before( condition_->previous_sibling() );
    new_node->After( condition_->next_sibling() );
    new_node->set_parent_node( this );
    condition_ = new_node;
  } else if ( old_node == case_true_ ) {
    new_node->Before( case_true_->previous_sibling() );
    new_node->After( case_true_->next_sibling() );
    new_node->set_parent_node( this );
    case_true_ = new_node;
  } else if ( old_node == case_false_ ) {
    new_node->Before( case_false_->previous_sibling() );
    new_node->After( case_false_->next_sibling() );
    new_node->set_parent_node( this );
    case_false_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}


AstNode* ConditionalExp::Clone() {
  ConditionalExp* exp = ConditionalExp::New( condition_->Clone(), case_true_->Clone() , case_false_->Clone() , line_number() );
  exp->condition()->set_parent_node( exp );
  exp->case_true()->set_parent_node( exp );
  exp->case_false()->set_parent_node( exp );
  return CopyChildren( exp , this );
}


void AssignmentExp::ReplaceChild( AstNode* old_node , AstNode* new_node ) {
  if ( old_node == left_value_ ) {
    new_node->Before( left_value_->previous_sibling() );
    new_node->After( left_value_->next_sibling() );
    new_node->set_parent_node( this );
    left_value_ = new_node;
  } else if ( old_node == right_value_ ) {
    new_node->Before( right_value_->previous_sibling() );
    new_node->After( right_value_->next_sibling() );
    new_node->set_parent_node( this );
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild( old_node , new_node );
  }
}

AstNode* AssignmentExp::Clone() {
  AssignmentExp* exp = AssignmentExp::New( operand_ , left_value_->Clone() , right_value_->Clone() , line_number() );
  exp->left_value()->set_parent_node( exp );
  exp->right_value()->set_parent_node( exp );
  return CopyChildren( exp , this );
}

AstNode* Literal::Clone() {
  Literal* ret = Literal::New( value_type_ , line_number() );
  ret->set_value( value_ );
  return CopyChildren( ret , this );
}

AstNode* ArrayLikeLiteral::Clone() {
  ArrayLikeLiteral* array = ArrayLikeLiteral::New( line_number() );
  array->flags_ = flags_;
  return CopyChildren( array , this );
}

AstNode* ObjectLikeLiteral::Clone() {
  ObjectLikeLiteral* object = ObjectLikeLiteral::New( line_number() );
  object->record_ = record_;
  return CopyChildren( object , this );
}

AstNode* GeneratorExpression::Clone() {
  GeneratorExpression* generator = GeneratorExpression::New( expression_ , line_number() );
  return CopyChildren( generator , this );
}

AstNode* DstaTree::Clone() {
  DstaTree* tree = DstaTree::New();
  if ( symbol_ ) {
    tree->symbol_ = symbol_->Clone()->CastToLiteral();
  }
  return CopyChildren( tree , this );
}

AstNode* DstaExtractedExpressions::Clone() {
  DstaExtractedExpressions* exp = DstaExtractedExpressions::New();
  CopyChildren( &exp->refs_ , &refs_ );
  return CopyChildren( exp , this );
}

}
