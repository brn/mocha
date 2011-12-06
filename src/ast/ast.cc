#include <ast/ast.h>

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
    bool is_first = false;;
    bool is_last = false;
    if ( old_node == first_child_ ) {
      first_child_ = new_node;
    }
    if ( old_node == last_child_ ) {
      last_child_ = new_node;
    }
    old_node->ReplaceWith( new_node );
  }
}

}
