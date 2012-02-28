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
#include <ast/ast.h>
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

#define ERROR(info,func)                                                \
  //AST_ERROR( ( info->GetInfo() ) , "mocha bugs in DstaProcessor::"#func"." )

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
    tree = DstaTree::New();                     \
  } else {                                      \
    tree = tree->Clone()->CastToDstaTree();     \
    tree->RemoveChild( tree->last_child() );     \
  }

//prototypes.
void ProcessObject( ObjectLikeLiteral* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );
void ProcessArray( ArrayLikeLiteral* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );

/**
 * Process the Object pattern's property member.
 * Create an accessor for conditional_expression, like _mochaLocalTmp.x[0].y
 */
void ProcessMember( Literal* ast_node , DstaTree* tree , ProcessorInfo* proc_info ) {
  VisitorInfo *visitor_info = proc_info->GetInfo();
  TokenInfo* info = ast_node->value();
  switch( info->type() ) {
    //In case of { Identifier : ... } or { Identifier }
    case Token::JS_IDENTIFIER : {
      if ( tree->child_length() > 0 ) {
        /*
         * If the Tree has the one or more children,
         * connect new identifier accessor to the tree last accessor expressions.
         */
        CallExp* dot_accessor = AstUtils::CreateDotAccessor( tree->last_child() , ast_node , ast_node->line_number() );
        tree->AddChild( dot_accessor );
      } else {
        /*
         * If the Tree hasn't children,
         * add first identifier accessor to tree.
         */
        AstNode* node = visitor_info->GetCurrentStmt()->dsta_node()->refs()->last_child()->Clone();
        CallExp* dot_accessor = AstUtils::CreateDotAccessor( node , ast_node , ast_node->line_number() );
        tree->AddChild( dot_accessor );
      }
    }
      break;
      //In case of { "string" : ... } or { 0 : ... }
    case Token::JS_NUMERIC_LITERAL :
    case Token::JS_STRING_LITERAL : {
      if ( tree->child_length() > 0 ) {
        //As stated above, connect node.
        CallExp* arr_accessor = AstUtils::CreateArrayAccessor( tree->last_child() , ast_node , ast_node->line_number() );
        tree->AddChild( arr_accessor );
      } else {
        //Same as above.
        AstNode* node = visitor_info->GetCurrentStmt()->dsta_node()->refs()->last_child();
        CallExp* arr_accessor = AstUtils::CreateArrayAccessor( node , ast_node , ast_node->line_number() );
        tree->AddChild( arr_accessor );
      }
    }
      break;
      
  }
}


/**
 * Process { x : <...> } or { <...> }
 */
DstaTree* ProcessPropertyMember( Literal* value , DstaTree* tree , ProcessorInfo* info , int depth ) {
  VisitorInfo* visitor_info = info->GetInfo();
  if ( value->child_length() > 0 ) {
    ProcessMember( value , tree , info );
    AstNode* child_node = value->first_child();
    Literal* prop = child_node->CastToLiteral();
    ObjectLikeLiteral* object = child_node->CastToExpression()->CastToObjectLikeLiteral();
    ArrayLikeLiteral* array = child_node->CastToExpression()->CastToArrayLikeLiteral();
    if ( prop || object || array ) {
      if ( object ) {
        ProcessObject( object , tree , ( depth + 1 ) , info );
        UPDATE_TREE;
      } else if ( array ) {
        ProcessArray( array , tree , ( depth + 1 ) , info );
        UPDATE_TREE;
      } else {
        prop->set_value_type( Literal::kProperty );
        tree->set_symbol( prop );
        visitor_info->GetCurrentStmt()->dsta_node()->last_child()->AddChild( tree );
        UPDATE_TREE;
      }
    }
  } else {
    value->set_value_type( Literal::kProperty );
    tree->set_symbol( value );
    ProcessMember( value , tree , info );
    visitor_info->GetCurrentStmt()->dsta_node()->last_child()->AddChild( tree );
    UPDATE_TREE;
  }
  return tree;
}



/**
 * Iterate Object pattern like
 * var { x, y , z : { x } } = {...}
 */
void ProcessObject( ObjectLikeLiteral* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  NodeIterator iterator = ast_node->elements()->ChildNodes();
  //Iterate member.
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    Literal* value = node->CastToLiteral();
    if ( value ) {
      switch ( value->value_type() ) {
        case Literal::kNumeric :
        case Literal::kString :
        case Literal::kProperty :
        case Literal::kIdentifier : {
          tree = ProcessPropertyMember( value , tree , info , depth );
        }
          break;
        default :
          ERROR( info , "ProcessObject" );
      }
    }
  }
}



void ArrayHelper( ArrayLikeLiteral* ast_node,
                  VisitorInfo* visitor_info,
                  DstaTree* tree,
                  int index,
                  Literal* symbol,
                  bool is_rest ) {
  char tmp_index[ 10 ];
  sprintf( tmp_index , "%d" , index );
  TokenInfo* info = TokenInfo::New( tmp_index , Token::JS_NUMERIC_LITERAL , ast_node->line_number() );
  CallExp* exp;
  if ( is_rest ) {
    NodeList* list = NodeList::New();
    char num[50];
    sprintf( num , "%d" , index );
    Literal* arg = AstUtils::CreateNameNode( num , Token::JS_NUMERIC_LITERAL , ast_node->line_number() , Literal::kNumeric );
    Literal* to_array = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kToArray ),
                                                  Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kProperty );
    if ( tree->child_length() > 0 ) {
      list->AddChild( tree->last_child()->Clone() );
    } else {
      list->AddChild( visitor_info->GetCurrentStmt()->dsta_node()->refs()->last_child()->Clone() );
    }
    list->AddChild( arg );
    CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list , ast_node->line_number() );
    CallExp* std_to_array = AstUtils::CreateRuntimeMod( nrm , ast_node->line_number() );
    std_to_array->set_rest();
    exp = std_to_array;
  } else {  
    Literal* accessor_index = Literal::New( Literal::kNumeric , ast_node->line_number() );
    accessor_index->set_value( info );
    if ( tree->child_length() > 0 ) {
      exp = AstUtils::CreateArrayAccessor( tree->last_child() , accessor_index , ast_node->line_number() );
    } else {
      exp = AstUtils::CreateArrayAccessor( visitor_info->GetCurrentStmt()->dsta_node()->refs()->last_child(),
                                           accessor_index , ast_node->line_number() );
    }
  }
  if ( symbol ) {
    symbol->set_value_type( Literal::kIdentifier );
    tree->set_symbol( symbol );
  }
  tree->AddChild( exp );
}


/**
 * Process each member of array pattern.
 */
DstaTree* ProcessArrayElement( ArrayLikeLiteral* ast_node,
                               AstNode* element,
                               DstaTree* tree,
                               int depth,
                               int index,
                               ProcessorInfo* info ) {
  VisitorInfo* visitor_info = info->GetInfo();
  if ( !element->empty() ) {
    if ( element->node_type() == AstNode::kLiteral ) {
      Literal* elem = element->CastToLiteral();
      ObjectLikeLiteral* object = element->CastToExpression()->CastToObjectLikeLiteral();
      ArrayLikeLiteral* array = element->CastToExpression()->CastToArrayLikeLiteral();
      if ( elem ) {
        switch( elem->value_type() ) {
          //In case of [ x , y ]
          case Literal::kIdentifier : //fall through
          case Literal::kProperty : {
            ArrayHelper( ast_node , visitor_info , tree , index , elem , false );
            visitor_info->GetCurrentStmt()->dsta_node()->last_child()->AddChild( tree );
            UPDATE_TREE;
          }
            break;
            //In case of [ x ,y ,...rest ]
          case Literal::kRest : {
            ArrayHelper( ast_node , visitor_info , tree , index , elem , true );
            visitor_info->GetCurrentStmt()->dsta_node()->last_child()->AddChild( tree );
            UPDATE_TREE;
          }
            break;
        }
      } else if ( object ) {
        //In case of [ {x,y} ]
        ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
        ProcessObject( object , tree , ( depth + 1 ) , info );
        UPDATE_TREE;
      } else if ( array ) {
        //In case of [ [x,y] ]
        ArrayHelper( ast_node , visitor_info , tree , index , 0 , false );
        ProcessArray( array , tree , ( depth + 1 ) , info );
        UPDATE_TREE;
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
void ProcessArray( ArrayLikeLiteral* ast_node , DstaTree* tree , int depth , ProcessorInfo* info ) {
  int index = 0;
  NodeIterator iterator = ast_node->elements()->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* element = iterator.Next();
    if ( !element->empty() ) {
      tree = ProcessArrayElement( ast_node , element , tree , depth , index , info );
      if ( iterator.HasNext() ) {
        index++;
      }
    }
  }
}


//Create a conditional expression that dsta converted result.
inline AstNode* CreateConditional( AstNode* last_exp , AstNode* first , ProcessorInfo *info , bool is_assign ) {
  Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                 Token::JS_IDENTIFIER , last_exp->line_number() , Literal::kIdentifier );
  ConditionalExp* cond = ConditionalExp::New( last_exp , first->last_child() , undefined , last_exp->line_number() );
  DstaTree* tree = 0;//init after.
  if ( first->node_type() == AstNode::kDstaTree ) {
    tree = first->CastToDstaTree();
  } else {
    ERROR( info , CreateConditional );
    return 0;
  }
  if ( !is_assign ) {
    Literal* var = Literal::New( Literal::kVariable , last_exp->line_number() );
    var->set_value( tree->symbol()->value() );
    var->AddChild( cond );
    Function* fn = info->GetInfo()->GetFunction();
    if ( fn ) {
      fn->set_variable_list( var );
    }
    return var;
  } else {
    AssignmentExp* assign = AssignmentExp::New( '=' , tree->symbol()->Clone() , cond , last_exp->line_number() );
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
    if ( maybe_callexp->node_type() == AstNode::kCallExp ) {
      item = maybe_callexp->CastToExpression()->CastToCallExp();
    } else {
      ERROR( info , "CreateDstaExtractedVarStmt" );
      return 0;
    }
    //Only first time.
    if ( !last_exp ) {
      maybe_callexp = exps.Next();
      CallExp* next = 0;//init after.
      if ( maybe_callexp->node_type() == AstNode::kCallExp ) {
        next = maybe_callexp->CastToExpression()->CastToCallExp();
      } else {
        ERROR( info , "CreateDstaExtractedVarStmt" );
        return 0;
      }
      if ( !next->rest() ) {
        //Create and exparession. like -> a && b
        last_exp = CompareExp::New( Token::JS_LOGICAL_AND , item , next , first->line_number() );
      } else {
        /*
         * In case of rest,
         * we don't set an item to logical_and_expression.
         */
        last_exp = item;
      }
    } else {
      if ( !item->rest() ) {
        last_exp = CompareExp::New( Token::JS_LOGICAL_AND , last_exp , item , first->line_number() );
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
AstNode* CreateSimpleAccessor( AstNode* first , VisitorInfo* info , bool is_assign ) {
  if ( !is_assign ) {
    Literal* var = Literal::New( Literal::kVariable , first->line_number() );
    DstaTree* tree = first->CastToDstaTree();
    var->set_value( tree->symbol()->value() );
    Function* fn = info->GetFunction();
    if ( fn ) {
      fn->set_variable_list( var );
    }
    var->AddChild( first->first_child() );
    return var;
  } else {
    DstaTree* tree = first->CastToDstaTree();
    AssignmentExp* assign = AssignmentExp::New( '=' , tree->symbol()->Clone() , first->first_child() , first->line_number() );
    return assign;
  }
}



/**
 * Create a statement,
 * from the results of analyzing dsta expressions.
 */
NodeList* CreateDstaExtractedNode( Statement* stmt , ProcessorInfo* info , bool is_assign ) {
  NodeList* result = NodeList::New();
  DstaExtractedExpressions* extr = stmt->dsta_node();
  if ( extr == 0 ) {
    ERROR( info , "CreateDstaExtractedVarStmt" );
    return 0;
  }
  AstNode* node_list = extr->first_child();
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
    AstNode* maybe_callexp = first->first_child();
    CallExp* exp = 0;//init after.
    if ( maybe_callexp != 0 && maybe_callexp->node_type() == AstNode::kCallExp ) {
      exp = maybe_callexp->CastToExpression()->CastToCallExp();
    } else {
      ERROR( info , "CreateDstaExtractedVarStmt" );
      return 0;
    }
    if ( first->child_length() > 1 && !exp->rest() ) {
      AstNode* ret = IterateTree( result , first , info , is_assign );
      if ( ret == 0 ) {
        return 0;
      }
    } else {
      AstNode* ret = CreateSimpleAccessor( first , info->GetInfo() , is_assign );
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



Literal* DstaProcessor::ProcessNode( AstNode* ast_node , ProcessorInfo* info ) {
  /**
   * Create a variable has the temporary referrence to assignment right hand side.
   * That like this -> _mochaLocalTmp<current number of tmporary variable> = <LHS>
   */
  char buf[50];
  VisitorInfo* visitor_info = info->GetInfo();
  const char *tmp_ref = AstUtils::CreateTmpRef( buf , visitor_info->GetTmpIndex() );
  Literal* value = AstUtils::CreateNameNode( tmp_ref , Token::JS_IDENTIFIER , ast_node->line_number(),
                                             Literal::kIdentifier , true );
  /**
   * Create a tree node that is stored the result of processing.
   */
  DstaTree* tree = DstaTree::New();
  /**
   * If we have not dsta yet,
   * add DstaExtractedAssignment to current active statement.
   */
  Statement* stmt = visitor_info->GetCurrentStmt();
  if ( stmt && !stmt->dsta_flag() ) {
    visitor_info->GetCurrentStmt()->set_dsta( DstaExtractedExpressions::New() );
    visitor_info->GetCurrentStmt()->dsta_node()->AddChild( NodeList::New() );
  } else if ( !stmt ) {
    ERROR( info , "ProcessNode" );
    return 0;
  }
  /**
   * Now add a temporary referrence variable to Refs node.
   */
  visitor_info->GetCurrentStmt()->dsta_node()->set_refs( value );
  if ( ast_node->node_type() == AstNode::kArrayLikeLiteral ) {
    ProcessArray( ast_node->CastToExpression()->CastToArrayLikeLiteral() , tree , 0 , info );
  } else {
    ProcessObject( ast_node->CastToExpression()->CastToObjectLikeLiteral() , tree , 0 , info );
  }
  Literal* var = AstUtils::CreateNameNode( value->value()->token() , Token::JS_IDENTIFIER,
                                           ast_node->line_number() , Literal::kIdentifier );
  var->AddChild( ast_node->first_child() );
  /**
   * Convert {x,y,z} => _mochaLocalTmp
   */
  ast_node->parent_node()->ReplaceChild( ast_node , var );
  return var;
}


/**
 * Create temporary referrence variable.
 */
VariableStmt* DstaProcessor::CreateTmpVarDecl( Statement* stmt , ProcessorInfo* info ) {
  DstaExtractedExpressions* dsta_extr = stmt->dsta_node();
  if ( dsta_extr == 0 ) {
    ERROR( info , "CreateTmpVarDecl" );
    return 0;
  }
  NodeList* list = dsta_extr->refs();
  NodeIterator iterator = list->ChildNodes();
  NodeList* var_list = NodeList::New();
  /**
   * Iterate all Refs node, and create variable_declaration node.
   */
  while ( iterator.HasNext() ) {
    Literal* value = iterator.Next()->Clone()->CastToLiteral();
    if ( value == 0 ) {
      ERROR( info , "CreateTmpVarDecl" );
      return 0;
    }
    if ( value->child_length() == 0 || value->first_child()->node_type() == AstNode::kEmpty ) {
      if ( value->child_length() > 0 ) {
        value->RemoveAllChild();
      }
      value->AddChild( AstUtils::CreateObjectLiteral( Empty::New() , stmt->line_number() ) );
    }
    value->set_value_type( Literal::kVariable );
    
    var_list->AddChild( value );    
  }
  return AstUtils::CreateVarStmt( var_list , stmt->line_number() );
}


}
