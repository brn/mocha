#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/token_info.h>
#include <grammar/grammar.tab.hh>

#define TOKEN yy::ParserImplementation::token

namespace mocha {

void DstaProcessor::ProcessNode( ValueNode* ast_node ) {
  char buf[50];
  visitor_info_->SetDstaInjection( true );
  const char *tmp_ref = AstUtils::CreateTmpRef( buf , visitor_info_->GetTmpIndex() );
  ValueNode* value = AstUtils::CreateNameNode( tmp_ref , TOKEN::JS_IDENTIFIER , ast_node->Line() , true );
  DstaTree* tree = ManagedHandle::Retain<DstaTree>();
  visitor_info_->GetDstaExtr()->AddChild( ManagedHandle::Retain<NodeList>() );
  visitor_info_->GetDstaExtr()->Refs( value );
  if ( ast_node->ValueType() == ValueNode::kDstArray ) {
    ArrayProcessor_( ast_node , tree , 0 );
  } else {
    ObjectProcessor_( ast_node , tree , 0 );
  }
  ast_node->ValueType( ValueNode::kIdentifier );
  ast_node->Symbol( value->Symbol() );
}

NodeList* DstaProcessor::CreateDstaExtractedVarStmt() {
  NodeList* result = ManagedHandle::Retain<NodeList>();
  NodeIterator iterator = visitor_info_->GetDstaExtr()->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* node_list = iterator.Next();
    NodeIterator list = node_list->ChildNodes();
    printf( "child length %d\n",node_list->ChildLength() );
    while ( list.HasNext() ) {
      AstNode *first = list.Next();
      NodeIterator exps = first->ChildNodes();
      AstNode* last_exp = 0;
      if ( first->ChildLength() > 1 ) {
        while ( exps.HasNext() ) {
          AstNode* item = exps.Next();
          if ( !last_exp ) {
            AstNode* next = exps.Next();
            last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , item , next ) );
          } else {
            last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , last_exp , item ) );
          }
        }
        ValueNode* undefined = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
        TokenInfo* undef_info = ManagedHandle::Retain( new TokenInfo( "undefined" , TOKEN::JS_IDENTIFIER , 0 ) );
        undefined->Symbol( undef_info );
        ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( last_exp , first->LastChild() , undefined ) );
        ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
        DstaTree* tree = reinterpret_cast<DstaTree*>( first );
        var->Symbol( tree->Symbol()->Symbol() );
        var->AddChild( cond );
        result->AddChild( var );
      } else {
        ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
        DstaTree* tree = reinterpret_cast<DstaTree*>( first );
        var->Symbol( tree->Symbol()->Symbol() );
        var->AddChild( first->FirstChild() );
        result->AddChild( var );
      }
    }
  }
  visitor_info_->SetDstaInjection( false );
  visitor_info_->GetDstaExtr()->RemoveAllChild();
  visitor_info_->GetDstaExtr()->Refs()->RemoveAllChild();
  return result;
}

NodeList* DstaProcessor::CreateDstaExtractedAssignment() {
  NodeList* result = ManagedHandle::Retain<NodeList>();
  NodeIterator iterator = visitor_info_->GetDstaExtr()->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* node_list = iterator.Next();
    NodeIterator list = node_list->ChildNodes();
    while ( list.HasNext() ) {
      AstNode *first = list.Next();
      NodeIterator exps = first->ChildNodes();
      AstNode* last_exp = 0;
      if ( first->ChildLength() > 1 ) {
        while ( exps.HasNext() ) {
          AstNode* item = exps.Next();
          if ( !last_exp ) {
            AstNode* next = exps.Next();
            last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , item , next ) );
          } else {
            last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , last_exp , item ) );
          }
        }
        ValueNode* undefined = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
        TokenInfo* undef_info = ManagedHandle::Retain( new TokenInfo( "undefined" , TOKEN::JS_IDENTIFIER , 0 ) );
        undefined->Symbol( undef_info );
        ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( last_exp , first->LastChild() , undefined ) );
        DstaTree* tree = reinterpret_cast<DstaTree*>( first );
        AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( '=' , tree->Symbol() , cond ) );
        result->AddChild( assign );
      } else {
        DstaTree* tree = reinterpret_cast<DstaTree*>( first );
        AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( '=' , tree->Symbol() , first->FirstChild() ) );
        result->AddChild( assign );
      }
    }
  }
  visitor_info_->SetDstaInjection( false );
  visitor_info_->GetDstaExtr()->RemoveAllChild();
  return result;
}

#define UPDATE_TREE                             \
  if ( depth == 0 ) {                           \
    tree = ManagedHandle::Retain<DstaTree>();   \
  } else {                                      \
    tree = tree->Clone()->CastToDstaTree();     \
    tree->RemoveChild( tree->LastChild() );     \
  }



void DstaProcessor::ObjectProcessor_( ValueNode* ast_node , DstaTree* tree , int depth ) {
  AstNode* child = ast_node->Node();
  int value_type = ast_node->ValueType();
  NodeIterator iterator = ( child && ( value_type == ValueNode::kDst || value_type == ValueNode::kDstArray ) && child->ChildLength() > 0 && !child->IsEmpty() )?
      child->ChildNodes() :
      ast_node->ChildNodes();
  
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    ValueNode* value = node->CastToValue();
    if ( value ) {
      switch ( value->ValueType() ) {
        case ValueNode::kNumeric :
        case ValueNode::kString :
        case ValueNode::kIdentifier :
          if ( value->ChildLength() > 0 ) {
            MemberProcessor_( value , tree );
            AstNode* child_node = value->FirstChild();
            ValueNode* prop = child_node->CastToValue();
            if ( prop ) {
              if ( prop->ValueType() == ValueNode::kDst ) {
                ObjectProcessor_( prop , tree , ( depth + 1 ) );
              } else if ( prop->ValueType() == ValueNode::kDstArray ) {
                ArrayProcessor_( prop , tree , ( depth + 1 ) );
              } else {
                tree->Symbol( prop );
                visitor_info_->GetDstaExtr()->LastChild()->AddChild( tree );
                UPDATE_TREE;
              }
            }
          } else {
            tree->Symbol( value );
            MemberProcessor_( value , tree );
            visitor_info_->GetDstaExtr()->LastChild()->AddChild( tree );
            UPDATE_TREE;
          }
          break;

        case ValueNode::kDst :
        case ValueNode::kDstArray :
          MemberProcessor_( value , tree );
          AstNode* child_node = value->FirstChild();
          ValueNode* value = child_node->CastToValue();
          if ( value ) {
            if ( value->ValueType() == ValueNode::kDstArray ) {
              ArrayProcessor_( ast_node , tree , ( depth + 1 ) );
            } else {
              ObjectProcessor_( ast_node , tree , ( depth + 1 ) );
            }
          }
          UPDATE_TREE;
          break;
      }
    }
  }
}



void DstaProcessor::MemberProcessor_( ValueNode* ast_node , DstaTree* tree ) {
  TokenInfo* info = ast_node->Symbol();
  switch( info->GetType() ) {
    case TOKEN::JS_IDENTIFIER :
      {
        if ( tree->ChildLength() > 0 ) {
          CallExp* dot_accessor = AstUtils::CreateDotAccessor( tree->LastChild() , ast_node );
          tree->AddChild( dot_accessor );
        } else {
          CallExp* dot_accessor = AstUtils::CreateDotAccessor( visitor_info_->GetDstaExtr()->Refs()->LastChild() , ast_node );
          tree->AddChild( dot_accessor );
        }
      }
      break;

    case TOKEN::JS_NUMERIC_LITERAL :
    case TOKEN::JS_STRING_LITERAL :
      {
        if ( tree->ChildLength() > 0 ) {
          CallExp* arr_accessor = AstUtils::CreateArrayAccessor( tree->LastChild() , ast_node );
          tree->AddChild( arr_accessor );
        } else {
          CallExp* arr_accessor = AstUtils::CreateArrayAccessor( visitor_info_->GetDstaExtr()->Refs()->LastChild() , ast_node );
          tree->AddChild( arr_accessor );
        }
      }
      break;
      
  }
}



inline void ArrayHelper( ValueNode* ast_node , VisitorInfo* visitor_info , DstaTree* tree , int index , ValueNode* symbol ) {
  char tmp_index[ 10 ];
  sprintf( tmp_index , "%d" , index );
  TokenInfo* info = ManagedHandle::Retain( new TokenInfo( tmp_index,
                                                          TOKEN::JS_NUMERIC_LITERAL , ast_node->Line() ) );
  ValueNode* accessor_index = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
  accessor_index->Symbol( info );
  CallExp* exp;
  if ( tree->ChildLength() > 0 ) {
    exp = AstUtils::CreateArrayAccessor( tree->LastChild() , accessor_index );
  } else {
    exp = AstUtils::CreateArrayAccessor( visitor_info->GetDstaExtr()->Refs()->LastChild() , accessor_index );
  }
  if ( symbol ) {
    tree->Symbol( symbol );
  }
  tree->AddChild( exp );
}



void DstaProcessor::ArrayProcessor_( ValueNode* ast_node , DstaTree* tree , int depth ) {
  AstNode* list_child = ast_node->FirstChild();
  int index = 0;
  while ( list_child ) {
    if ( !list_child->IsEmpty() ) {
      NodeIterator iter = list_child->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        if ( !element->IsEmpty() ) {
          if ( element->NodeType() == AstNode::kValueNode ) {
            ValueNode* elem = element->CastToValue();
            if ( elem->ValueType() == ValueNode::kIdentifier ) {
              ArrayHelper( ast_node , visitor_info_ , tree , index , elem );
              visitor_info_->GetDstaExtr()->LastChild()->AddChild( tree );
              UPDATE_TREE;
            } else if ( elem->ValueType() == ValueNode::kDst ) {
              ArrayHelper( ast_node , visitor_info_ , tree , index , 0 );
              ObjectProcessor_( elem , tree , ( depth + 1 ) );
              UPDATE_TREE;
            } else if ( elem->ValueType() == ValueNode::kDstArray ) {
              ArrayHelper( ast_node , visitor_info_ , tree , index , 0 );
              ArrayProcessor_( elem , tree , ( depth + 1 ) );
              UPDATE_TREE;
            }
          }
        }
        if ( iter.HasNext() ) {
          index++;
        }
      }
    }
    if ( list_child->HasNext() ) {
      list_child = list_child->NextSibling();
    } else {
      break;
    }
  }
}

}
