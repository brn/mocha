#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>
#include <grammar/grammar.tab.hh>

#define TOKEN yy::ParserImplementation::token

namespace mocha {

void DstaProcessor::ProcessNode( ValueNode* ast_node , ProcessorInfo* info ) {
  char buf[50];
  VisitorInfo* visitor_info = info->GetInfo();
  const char *tmp_ref = AstUtils::CreateTmpRef( buf , visitor_info->GetTmpIndex() );
  ValueNode* value = AstUtils::CreateNameNode( tmp_ref , TOKEN::JS_IDENTIFIER , ast_node->Line() , true );
  DstaTree* tree = ManagedHandle::Retain<DstaTree>();
  if ( !visitor_info->GetCurrentStmt()->HasDsta() ) {
    visitor_info->GetCurrentStmt()->SetDsta( ManagedHandle::Retain<DstaExtractedExpressions>() );
    visitor_info->GetCurrentStmt()->GetDsta()->AddChild( ManagedHandle::Retain<NodeList>() );
    visitor_info->GetCurrentStmt()->GetDsta()->Refs( value );
  }
  if ( ast_node->ValueType() == ValueNode::kDstArray ) {
    ArrayProcessor_( ast_node , tree , 0 , info );
  } else {
    ObjectProcessor_( ast_node , tree , 0 , info );
  }
  ast_node->ValueType( ValueNode::kIdentifier );
  ast_node->Symbol( value->Symbol() );
}

VariableStmt* DstaProcessor::CreateTmpVarDecl( Statement* stmt , ProcessorInfo* info ) {
  DstaExtractedExpressions* dsta_extr = stmt->GetDsta();
  NodeList* list = dsta_extr->Refs();
  NodeIterator iterator = list->ChildNodes();
  NodeList* var_list = ManagedHandle::Retain<NodeList>();
  while ( iterator.HasNext() ) {
    ValueNode* value = iterator.Next()->Clone()->CastToValue();
    value->ValueType( ValueNode::kVariable );
    var_list->AddChild( value );    
  }
  return AstUtils::CreateVarStmt( var_list );
}

NodeList* DstaProcessor::CreateDstaExtractedVarStmt( Statement* stmt , ProcessorInfo* info ) {
  NodeList* result = ManagedHandle::Retain<NodeList>();
  NodeIterator iterator = stmt->GetDsta()->ChildNodes();
  printf( "%d\n" , stmt->GetDsta()->ChildLength() );
  while ( iterator.HasNext() ) {
    AstNode* node_list = iterator.Next();
    NodeIterator list = node_list->ChildNodes();
    printf( "child length %d\n",node_list->ChildLength() );
    while ( list.HasNext() ) {
      AstNode *first = list.Next();
      NodeIterator exps = first->ChildNodes();
      AstNode* last_exp = 0;
      CallExp* exp = reinterpret_cast<CallExp*>( first->FirstChild() );
      if ( first->ChildLength() > 1 && !exp->IsRest() ) {
        while ( exps.HasNext() ) {
          CallExp* item = reinterpret_cast<CallExp*>( exps.Next() );
          if ( !last_exp ) {
            CallExp* next = reinterpret_cast<CallExp*>( exps.Next() );
            if ( !next->IsRest() ) {
              last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , item , next ) );
            } else {
              last_exp = item;
            }
          } else {
            if ( !item->IsRest() ) {
              last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , last_exp , item ) );
            }
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
  return result;
}

NodeList* DstaProcessor::CreateDstaExtractedAssignment( Statement* stmt , ProcessorInfo *info ) {
  NodeList* result = ManagedHandle::Retain<NodeList>();
  NodeIterator iterator = stmt->GetDsta()->ChildNodes();
  printf( "child size%d\n" , stmt->GetDsta()->ChildLength() );
  while ( iterator.HasNext() ) {
    AstNode* node_list = iterator.Next();
    NodeIterator list = node_list->ChildNodes();
    while ( list.HasNext() ) {
      AstNode *first = list.Next();
      CallExp* exp = reinterpret_cast<CallExp*>( first->FirstChild() );
      NodeIterator exps = first->ChildNodes();
      AstNode* last_exp = 0;
      if ( first->ChildLength() > 1 && !exp->IsRest() ) {
        while ( exps.HasNext() ) {
          CallExp* item = reinterpret_cast<CallExp*>( exps.Next() );
          if ( !last_exp ) {
            CallExp* next = reinterpret_cast<CallExp*>( exps.Next() );
            if ( !next->IsRest() ) {
              last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , item , next ) );
            }
          } else {
            if ( !item->IsRest() ) {
              last_exp = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_AND , last_exp , item ) );
            }
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
  return result;
}

#define UPDATE_TREE                             \
  if ( depth == 0 ) {                           \
    tree = ManagedHandle::Retain<DstaTree>();   \
  } else {                                      \
    tree = tree->Clone()->CastToDstaTree();     \
    tree->RemoveChild( tree->LastChild() );     \
  }



void DstaProcessor::ObjectProcessor_( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  VisitorInfo* visitor_info = info->GetInfo();
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
        case ValueNode::kIdentifier : {
          if ( value->ChildLength() > 0 ) {
            MemberProcessor_( value , tree , info );
            AstNode* child_node = value->FirstChild();
            ValueNode* prop = child_node->CastToValue();
            if ( prop ) {
              if ( prop->ValueType() == ValueNode::kDst ) {
                ObjectProcessor_( prop , tree , ( depth + 1 ) , info );
              } else if ( prop->ValueType() == ValueNode::kDstArray ) {
                ArrayProcessor_( prop , tree , ( depth + 1 ) , info );
              } else {
                tree->Symbol( prop );
                visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
                UPDATE_TREE;
              }
            }
          } else {
            tree->Symbol( value );
            MemberProcessor_( value , tree , info );
            visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
            UPDATE_TREE;
          }
        }
          break;

        case ValueNode::kDst :
        case ValueNode::kDstArray : {
          MemberProcessor_( value , tree , info );
          AstNode* child_node = value->FirstChild();
          ValueNode* value = child_node->CastToValue();
          if ( value ) {
            if ( value->ValueType() == ValueNode::kDstArray ) {
              ArrayProcessor_( ast_node , tree , ( depth + 1 ) , info );
            } else {
              ObjectProcessor_( ast_node , tree , ( depth + 1 ) , info );
            }
          }
          UPDATE_TREE;
        }
          break;
      }
    }
  }
}



void DstaProcessor::MemberProcessor_( ValueNode* ast_node , DstaTree* tree , ProcessorInfo* proc_info ) {
  VisitorInfo *visitor_info = proc_info->GetInfo();
  TokenInfo* info = ast_node->Symbol();
  switch( info->GetType() ) {
    case TOKEN::JS_IDENTIFIER :
      {
        if ( tree->ChildLength() > 0 ) {
          CallExp* dot_accessor = AstUtils::CreateDotAccessor( tree->LastChild() , ast_node );
          tree->AddChild( dot_accessor );
        } else {
          CallExp* dot_accessor = AstUtils::CreateDotAccessor( visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild() , ast_node );
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
          CallExp* arr_accessor = AstUtils::CreateArrayAccessor( visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild() , ast_node );
          tree->AddChild( arr_accessor );
        }
      }
      break;
      
  }
}



inline void ArrayHelper( ValueNode* ast_node,
                         VisitorInfo* visitor_info,
                         DstaTree* tree,
                         int index,
                         ValueNode* symbol,
                         bool is_rest ) {
  char tmp_index[ 10 ];
  sprintf( tmp_index , "%d" , index );
  TokenInfo* info = ManagedHandle::Retain( new TokenInfo( tmp_index,
                                                          TOKEN::JS_NUMERIC_LITERAL , ast_node->Line() ) );
  CallExp* exp;
  if ( is_rest ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    char num[50];
    sprintf( num , "%d" , index );
    ValueNode* arg = AstUtils::CreateNameNode( num , TOKEN::JS_NUMERIC_LITERAL , ast_node->Line() );
    ValueNode* to_array = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kToArray ),
                                                    TOKEN::JS_IDENTIFIER , ast_node->Line() );
    list->AddChild( visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild() );
    list->AddChild( arg );
    CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list );
    CallExp* std_to_array = AstUtils::CreateRuntimeMod( nrm );
    std_to_array->Rest();
    exp = std_to_array;
  } else {  
    ValueNode* accessor_index = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    accessor_index->Symbol( info );
    if ( tree->ChildLength() > 0 ) {
      exp = AstUtils::CreateArrayAccessor( tree->LastChild() , accessor_index );
    } else {
      exp = AstUtils::CreateArrayAccessor( visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild() , accessor_index );
    }
  }
  if ( symbol ) {
    tree->Symbol( symbol );
  }
  tree->AddChild( exp );
}



void DstaProcessor::ArrayProcessor_( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  VisitorInfo* visitor_info = info->GetInfo();
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
              ArrayHelper( ast_node , visitor_info , tree , index , elem , false );
              visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
              UPDATE_TREE;
            } else if ( elem->ValueType() == ValueNode::kDst ) {
              ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
              ObjectProcessor_( elem , tree , ( depth + 1 ) , info );
              UPDATE_TREE;
            } else if ( elem->ValueType() == ValueNode::kDstArray ) {
              ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
              ArrayProcessor_( elem , tree , ( depth + 1 ) , info );
              UPDATE_TREE;
            } else if ( elem->ValueType() == ValueNode::kRest ) {
              ArrayHelper( ast_node , visitor_info , tree , index , elem , true );
              visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
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
