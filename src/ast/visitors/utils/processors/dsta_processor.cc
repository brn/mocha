/**
 *@author Taketoshi Aono
 *@fileOverview
 *Implementation of destructuring assignment processor.
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#include <assert.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <compiler/compiler.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/utils/exception_handler.h>
#include <grammar/grammar.tab.hh>

#define ERROR(info,func)                                                \
  AST_ERROR( ( info->GetInfo() ) , "mocha bugs in DstaProcessor::"#func"." )

#define TOKEN yy::ParserImplementation::token

namespace mocha {

/**
 * We express destructuring assingment as dsta.
 * Let's begin transform of abstract syntax tree!
 * Buf before that , describe target tree structure overview on following.
 *
 * Statement<Current active statement>
 *                  |
 *                  DstaExtractedExpression -----Refs
 *                  |                              |-----
 *                  NodeList--------               |    |
 *                  |    |    |    |               Ref1 Ref2 ...
 *                  Tree Tree Tree Tree
 *                  |
 *                  CallExp<Result of processing>
 *
 * The DstaExtractedExpression could has multiple Tree class,
 * but appling this case will be only in case that dsta appear in the formal_parameter_list.
 * Now mocha implements dsta as the conditional expression or simple property accessor.
 * This implementation not throw error, except if lhs is null or undefined,
 * this based on firefox implemetation, not harmony.
 */



#define UPDATE_TREE                             \
  if ( depth == 0 ) {                           \
    tree = ManagedHandle::Retain<DstaTree>();   \
  } else {                                      \
    tree = tree->Clone()->CastToDstaTree();     \
    tree->RemoveChild( tree->LastChild() );     \
  }

//prototypes.
void ProcessObject( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );
void ProcessArray( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );

/**
 * Process the Object pattern's property member.
 * Create an accessor for conditional_expression, like _mochaLocalTmp.x[0].y
 */
void ProcessMember( ValueNode* ast_node , DstaTree* tree , ProcessorInfo* proc_info ) {
  VisitorInfo *visitor_info = proc_info->GetInfo();
  TokenInfo* info = ast_node->Symbol();
  switch( info->GetType() ) {
    //In case of { Identifier : ... } or { Identifier }
    case Token::JS_IDENTIFIER : {
      if ( tree->ChildLength() > 0 ) {
        /*
         * If the Tree has the one or more children,
         * connect new identifier accessor to the tree last accessor expressions.
         */
        CallExp* dot_accessor = AstUtils::CreateDotAccessor( tree->LastChild() , ast_node );
        tree->AddChild( dot_accessor );
      } else {
        /*
         * If the Tree hasn't children,
         * add first identifier accessor to tree.
         */
        AstNode* node = visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild()->Clone();
        CallExp* dot_accessor = AstUtils::CreateDotAccessor( node , ast_node );
        tree->AddChild( dot_accessor );
      }
    }
      break;
      //In case of { "string" : ... } or { 0 : ... }
    case Token::JS_NUMERIC_LITERAL :
    case Token::JS_STRING_LITERAL : {
      if ( tree->ChildLength() > 0 ) {
        //As stated above, connect node.
        CallExp* arr_accessor = AstUtils::CreateArrayAccessor( tree->LastChild() , ast_node );
        tree->AddChild( arr_accessor );
      } else {
        //Same as above.
        AstNode* node = visitor_info->GetCurrentStmt()->GetDsta()->Refs()->LastChild();
        CallExp* arr_accessor = AstUtils::CreateArrayAccessor( node , ast_node );
        tree->AddChild( arr_accessor );
      }
    }
      break;
      
  }
}


/**
 * Process { x : <...> } or { <...> }
 */
void ProcessPropertyMember( ValueNode* value , DstaTree* tree , ProcessorInfo* info , int depth ) {
  VisitorInfo* visitor_info = info->GetInfo();
  if ( value->ChildLength() > 0 ) {
    ProcessMember( value , tree , info );
    AstNode* child_node = value->FirstChild();
    ValueNode* prop = child_node->CastToValue();
    if ( prop ) {
      if ( prop->ValueType() == ValueNode::kDst ) {
        ProcessObject( prop , tree , ( depth + 1 ) , info );
      } else if ( prop->ValueType() == ValueNode::kDstArray ) {
        ProcessArray( prop , tree , ( depth + 1 ) , info );
      } else {
        prop->ValueType( ValueNode::kProperty );
        tree->Symbol( prop );
        visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
        UPDATE_TREE;
      }
    }
  } else {
    value->ValueType( ValueNode::kProperty );
    tree->Symbol( value );
    ProcessMember( value , tree , info );
    visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
    UPDATE_TREE;
  }
}



/**
 * Iterate Object pattern like
 * var { x, y , z : { x } } = {...}
 */
void ProcessObject( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  AstNode* child = ast_node->Node();
  int value_type = ast_node->ValueType();
  bool is_child = ( child &&
                    ( value_type == ValueNode::kDst ||
                      value_type == ValueNode::kDstArray ) &&
                    child->ChildLength() > 0 && !child->IsEmpty() );
  NodeIterator iterator = ( is_child )? child->ChildNodes() : ast_node->ChildNodes();
  //Iterate member.
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    ValueNode* value = node->CastToValue();
    if ( value ) {
      switch ( value->ValueType() ) {
        case ValueNode::kNumeric :
        case ValueNode::kString :
        case ValueNode::kProperty :
        case ValueNode::kIdentifier : {
          ProcessPropertyMember( value , tree , info , depth );
        }
          break;
        default :
          ERROR( info , "ProcessObject" );
      }
    }
  }
}



void ArrayHelper( ValueNode* ast_node,
                  VisitorInfo* visitor_info,
                  DstaTree* tree,
                  int index,
                  ValueNode* symbol,
                  bool is_rest ) {
  char tmp_index[ 10 ];
  sprintf( tmp_index , "%d" , index );
  TokenInfo* info = ManagedHandle::Retain( new TokenInfo( tmp_index,
                                                          Token::JS_NUMERIC_LITERAL , ast_node->Line() ) );
  CallExp* exp;
  if ( is_rest ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    char num[50];
    sprintf( num , "%d" , index );
    ValueNode* arg = AstUtils::CreateNameNode( num , Token::JS_NUMERIC_LITERAL , ast_node->Line() , ValueNode::kNumeric );
    ValueNode* to_array = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kToArray ),
                                                    Token::JS_IDENTIFIER , ast_node->Line() , ValueNode::kProperty );
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


/**
 * Process each member of array pattern.
 */
DstaTree* ProcessArrayElement( ValueNode* ast_node,
                          AstNode* element,
                          DstaTree* tree,
                          int depth,
                          int index,
                          ProcessorInfo* info ) {
  printf( "depth is = %d\n" , depth );
  VisitorInfo* visitor_info = info->GetInfo();
  if ( !element->IsEmpty() ) {
    if ( element->NodeType() == AstNode::kValueNode ) {
      ValueNode* elem = element->CastToValue();
      switch( elem->ValueType() ) {
        //In case of [ x , y ]
        case ValueNode::kIdentifier : //fall through
        case ValueNode::kProperty : {
          ArrayHelper( ast_node , visitor_info , tree , index , elem , false );
          visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
          UPDATE_TREE;
        }
          break;
          //In case of [ {x,y} ]
        case ValueNode::kDst : {
          ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
          ProcessObject( elem , tree , ( depth + 1 ) , info );
          UPDATE_TREE;
        }
          break;
          //In case of [ [x,y] ]
        case ValueNode::kDstArray : {
          ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
          ProcessArray( elem , tree , ( depth + 1 ) , info );
          UPDATE_TREE;
        }
          break;
          //In case of [ x ,y ,...rest ]
        case ValueNode::kRest : {
          ArrayHelper( ast_node , visitor_info , tree , index , elem , true );
          visitor_info->GetCurrentStmt()->GetDsta()->LastChild()->AddChild( tree );
          UPDATE_TREE;
        }
          break;
      }
    }
  }
  return tree;
}


/**
 * Process Array pattern.
 * Array pattern is this,
 * [ x, y, z ],
 * [ x, {x,y,z} ],
 * [ x , [ x,y ] ],
 * [ x, y , ...rest ]
 */
void ProcessArray( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  NodeIterator list_child = ast_node->ChildNodes();
  int index = 0;
  while ( list_child.HasNext() ) {
    AstNode* item = list_child.Next();
    if ( !item->IsEmpty() ) {
      NodeIterator iter = item->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        tree = ProcessArrayElement( ast_node , element , tree , depth , index , info );
        if ( iter.HasNext() ) {
          index++;
        }
      }
    }
  }
}


//Create a conditional expression that dsta converted result.
inline AstNode* CreateConditional( AstNode* last_exp , AstNode* first , ProcessorInfo *info , bool is_assign ) {
  ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , last_exp->Line() , ValueNode::kIdentifier );
  ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( last_exp , first->LastChild() , undefined ) );
  DstaTree* tree = 0;//init after.
  if ( first->NodeType() == AstNode::kDstaTree ) {
    tree = reinterpret_cast<DstaTree*>( first );
  } else {
    ERROR( info , CreateConditional );
    return 0;
  }
  if ( !is_assign ) {
    ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    var->Symbol( tree->Symbol()->Symbol() );
    var->AddChild( cond );
    return var;
  } else {
    AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( '=' , tree->Symbol() , cond ) );
    return assign;
  }
}



NodeList* IterateTree( NodeList* result,
                       AstNode* first,
                       ProcessorInfo *info,
                       bool is_assign ) {
  AstNode* maybe_callexp = 0;//init after.
  AstNode* last_exp = 0;//init after.
  //The Children of tree.
  NodeIterator exps = first->ChildNodes();
  /**
   * The iteration of each Tree children.
   * Tree                 Tree
   * |--------|-------|   |--------|-------|   
   * CallExp  CallExp ... CallExp  CallExp ... 
   */
  while ( exps.HasNext() ) {
    maybe_callexp = exps.Next();
    CallExp* item = 0;//init after.
    if ( maybe_callexp->NodeType() == AstNode::kCallExp ) {
      item = reinterpret_cast<CallExp*>( maybe_callexp );
    } else {
      ERROR( info , "CreateDstaExtractedVarStmt" );
      return 0;
    }
    //Only first time.
    if ( !last_exp ) {
      maybe_callexp = exps.Next();
      CallExp* next = 0;//init after.
      if ( maybe_callexp->NodeType() == AstNode::kCallExp ) {
        next = reinterpret_cast<CallExp*>( maybe_callexp );
      } else {
        ERROR( info , "CreateDstaExtractedVarStmt" );
        return 0;
      }
      if ( !next->IsRest() ) {
        //Create and exparession. like -> a && b
        last_exp = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , item , next ) );
      } else {
        /*
         * In case of rest,
         * we don't set an item to logical_and_expression.
         */
        last_exp = item;
      }
    } else {
      if ( !item->IsRest() ) {
        last_exp = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , last_exp , item ) );
      }
    }
  }
  AstNode* ret = CreateConditional( last_exp , first , info , is_assign );
  if ( !ret ) {
    return 0;
  }
  result->AddChild( ret );
  return result;
}



/**
 * Simple property accessor.
 * This Implementation based on firefox's javascript 1.8.5.
 * In javascript, all value treat as Object , so not throw exception if lhs is there,
 * in firefox, destructuring assignment is implemented like this ->
 * <lhs is javascript object except null or undefined> -> no throw
 * <lhs is null or undefined> -> throw TypeError <... is has no property.>
 */
AstNode* CreateSimpleAccessor( AstNode* first , bool is_assign ) {
  if ( !is_assign ) {
    ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    DstaTree* tree = reinterpret_cast<DstaTree*>( first );
    var->Symbol( tree->Symbol()->Symbol() );
    var->AddChild( first->FirstChild() );
    return var;
  } else {
    DstaTree* tree = reinterpret_cast<DstaTree*>( first );
    AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( '=' , tree->Symbol() , first->FirstChild() ) );
    return assign;
  }
}



/**
 * Create a statement,
 * from the results of analyzing dsta expressions.
 */
NodeList* CreateDstaExtractedNode( Statement* stmt , ProcessorInfo* info , bool is_assign ) {
  NodeList* result = ManagedHandle::Retain<NodeList>();
  DstaExtractedExpressions* extr = stmt->GetDsta();
  if ( extr == 0 ) {
    ERROR( info , "CreateDstaExtractedVarStmt" );
    return 0;
  }
  AstNode* node_list = extr->FirstChild();
  NodeIterator list = node_list->ChildNodes();
  /**
   * The iteration of DstaExtractedExpressions children.
   * DstaExtractedExpressions
   *   |
   *   NodeList
   *   |    |
   * [ Tree Tree ] this line.
   */
  while ( list.HasNext() ) {
    AstNode *first = list.Next();
    AstNode* maybe_callexp = first->FirstChild();
    CallExp* exp = 0;//init after. 
    if ( maybe_callexp != 0 && maybe_callexp->NodeType() == AstNode::kCallExp ) {
      exp = reinterpret_cast<CallExp*>( first->FirstChild() );
    } else {
      ERROR( info , "CreateDstaExtractedVarStmt" );
      return 0;
    }
    if ( first->ChildLength() > 1 && !exp->IsRest() ) {
      AstNode* ret = IterateTree( result , first , info , is_assign );
      if ( ret == 0 ) {
        return 0;
      }
    } else {
      AstNode* ret = CreateSimpleAccessor( first , is_assign );
      result->AddChild( ret );
    }
  }
  return result;
}



/**
 * Create a variable statement,
 * from the results of analyzing dsta expressions.
 */
NodeList* DstaProcessor::CreateDstaExtractedVarStmt( Statement* stmt , ProcessorInfo* info ) {
  return CreateDstaExtractedNode( stmt , info , false );
}



/**
 * Create a Assignment expression,
 * from the results of analyzing dsta expressions.
 */
NodeList* DstaProcessor::CreateDstaExtractedAssignment( Statement* stmt , ProcessorInfo* info ) {
  return CreateDstaExtractedNode( stmt , info , true );
}



int DstaProcessor::ProcessNode( ValueNode* ast_node , ProcessorInfo* info ) {
  /**
   * Create a variable has the temporary referrence to assignment right hand side.
   * That like this -> _mochaLocalTmp<current number of tmporary variable> = <LHS>
   */
  char buf[50];
  VisitorInfo* visitor_info = info->GetInfo();
  const char *tmp_ref = AstUtils::CreateTmpRef( buf , visitor_info->GetTmpIndex() );
  ValueNode* value = AstUtils::CreateNameNode( tmp_ref , Token::JS_IDENTIFIER , ast_node->Line(),
                                               ValueNode::kIdentifier , true );
  /**
   * Create a tree node that is stored the result of processing.
   */
  DstaTree* tree = ManagedHandle::Retain<DstaTree>();
  /**
   * If we have not dsta yet,
   * add DstaExtractedAssignment to current active statement.
   */
  Statement* stmt = visitor_info->GetCurrentStmt();
  if ( stmt && !stmt->HasDsta() ) {
    visitor_info->GetCurrentStmt()->SetDsta( ManagedHandle::Retain<DstaExtractedExpressions>() );
    visitor_info->GetCurrentStmt()->GetDsta()->AddChild( ManagedHandle::Retain<NodeList>() );
  } else if ( !stmt ) {
    ERROR( info , "ProcessNode" );
    return kError;
  }
  /**
   * Now add a temporary referrence variable to Refs node.
   */
  visitor_info->GetCurrentStmt()->GetDsta()->Refs( value );
  if ( ast_node->ValueType() == ValueNode::kDstArray ) {
    ProcessArray( ast_node , tree , 0 , info );
  } else {
    ProcessObject( ast_node , tree , 0 , info );
  }
  /**
   * Convert {x,y,z} => _mochaLocalTmp
   */
  ast_node->ValueType( ValueNode::kIdentifier );
  ast_node->Symbol( value->Symbol() );
  return kSuccess;
}


/**
 * Create temporary referrence variable.
 */
VariableStmt* DstaProcessor::CreateTmpVarDecl( Statement* stmt , ProcessorInfo* info ) {
  DstaExtractedExpressions* dsta_extr = stmt->GetDsta();
  
  if ( dsta_extr == 0 ) {
    ERROR( info , "CreateTmpVarDecl" );
    return 0;
  }
  
  NodeList* list = dsta_extr->Refs();
  NodeIterator iterator = list->ChildNodes();
  NodeList* var_list = ManagedHandle::Retain<NodeList>();

  /**
   * Iterate all Refs node, and create variable_declaration node.
   */
  while ( iterator.HasNext() ) {
    ValueNode* value = iterator.Next()->Clone()->CastToValue();
    if ( value == 0 ) {
      ERROR( info , "CreateTmpVarDecl" );
      return 0;
    }
    value->ValueType( ValueNode::kVariable );
    var_list->AddChild( value );    
  }
  return AstUtils::CreateVarStmt( var_list );
}


}
