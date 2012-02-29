#include <string.h>
#include <stdio.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/optimizer_visitor.h>
#include <ast/visitors/utils/opt/constant_optimizer.h>
#include <ast/visitors/utils/opt/ifstatement_optimizer.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/utils/compile_info.h>
#include <utils/pool/managed_handle.h>
namespace mocha {

#define VISITOR_IMPL(type) void OptimizerVisitor::Visit##type( type* ast_node )
#ifdef PRINTABLE
#define PRINT_NODE_NAME printf( "depth = %d name = %s\n" , depth_++ , ast_node->GetName() )
#else
#define PRINT_NODE_NAME
#endif


OptimizerVisitor::OptimizerVisitor( CompileInfo* info ) :
    depth_( 0 ), is_debug_( info->Debug() ) , info_( info ){}

VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  scope_ = ast_node->GetScope();
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after.
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    if ( last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt ) {
      node->Accept( this );
      last->Append( node );
      ast_node->RemoveChild( node );
    } else {
      node->Accept( this );
    }
    last = node;
  }
}


VISITOR_IMPL( NodeList ) {
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after.
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    if ( last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt ) {
      node->Accept( this );
      last->Append( node );
      ast_node->RemoveChild( node );
    } else {
      node->Accept( this );
    }
    last = node;
  }
}


VISITOR_IMPL( PragmaStmt ) {
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept( this );
}



VISITOR_IMPL( ModuleStmt ) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL( ImportStmt ) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL( Statement ) {}

VISITOR_IMPL( VersionStmt ) {
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL( AssertStmt ) {}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    if ( last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt ) {
      node->Accept( this );
      last->Append( node );
      ast_node->RemoveChild( node );
    } else {
      node->Accept( this );
    }
    last = node;
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept( this );
  //Analyzer analyzer( scope_ );
  //JSValue* value = ast_node->first_child()->CastToExpression()->Analyze( &analyzer );
  //printf( "@@@@@@@@@@@@@@@@@@@@@@@@ --- %s\n" , value->name() );
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  IFStmtOptimizer opt( info_ , ast_node );
  opt.Optimize( this );
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  if ( ast_node->node_type() == AstNode::kWhile || ast_node->node_type() == AstNode::kDoWhile ) {
    ast_node->Exp()->Accept( this );
  } else {
    AstNode* index_exp = exp->first_child();
    AstNode* cond_exp = ( index_exp )? index_exp->NextSibling() : 0;
    AstNode* incr_exp = ( cond_exp )? cond_exp->NextSibling() : 0;
    index_exp->Accept( this );
    if ( cond_exp ) {
      cond_exp->Accept( this );
    }
    if ( incr_exp ) {
      incr_exp->Accept( this );
    }
  }
  AstNode* body = ast_node->first_child();
  if ( body->node_type() == AstNode::kBlockStmt ) {
    if ( body->first_child()->child_length() == 1 ) {
      body = body->first_child()->first_child();
      ast_node->RemoveAllChild();
      ast_node->AddChild( body );
    }
  }
  body->Accept( this );
}

VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->first_child();
  exp->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  NodeIterator iterator = ast_node->first_child()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}

VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->first_child()->Accept( this );
}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  ast_node->LastChild()->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept( this );
  ast_node->Catch()->Accept( this );
  ast_node->Finally()->Accept( this );
}


void OptimizerVisitor::ArrayAccessorProccessor_( CallExp* exp ) {
  AstNode* callable = exp->Callable();
  AstNode* arg = exp->Args();
  callable->Accept( this );
  arg->Accept( this );
  callable = exp->Callable();
  arg = exp->Args();
  if ( arg->node_type() == AstNode::kLiteral ) {
    Literal* value = arg->CastToLiteral();
    if ( value->ValueType() == Literal::kString ) {
      bool is_valid_property_name = true;
      std::string tmp = value->Symbol()->GetToken();
      tmp.erase( tmp.size() - 1 , tmp.size() );
      if ( !isalpha( tmp[ 1 ] ) && tmp[ 1 ] != '_' && tmp[ 1 ] != '$' ) {
        is_valid_property_name = false;
      }
      if ( is_valid_property_name ) {
        for ( int i = 2,len = tmp.size(); i < len; i++ ) {
          if ( !isalpha( tmp[ i ] ) && tmp[ i ] != '_' && tmp[ i ] != '$' && !isdigit( tmp[ i ] ) ) {
            is_valid_property_name = false;
          }
        }
      }
      if ( is_valid_property_name ) {
        Literal* ident = AstUtils::CreateNameNode( &tmp[ 1 ] , Token::JS_PROPERTY , exp->Line() , Literal::kProperty );
        CallExp* call_exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
        call_exp->Callable( callable );
        call_exp->Args( ident );
        exp->ParentNode()->ReplaceChild( exp , call_exp );
        arg = ident;
        ident->Accept( this );
      }
    }
  }
}


void OptimizerVisitor::DotAccessorProccessor_( CallExp* exp ) {
  AstNode* callable = exp->Callable();
  AstNode* args = exp->Args();
  bool is_delete;
  bool is_lhs = exp->IsLhs();
  bool in_assignment = false;
  AstNode* parent = exp->ParentNode();
  while ( parent ) {
    if ( parent->CastToExpression() ) {
      UnaryExp* exp = parent->CastToExpression()->CastToUnaryExp();
      if ( exp ) {
        if ( exp->Op() == Token::JS_DELETE ) {
          is_delete = true;
        }
      }
      if ( parent->CastToExpression()->IsLhs() ) {
        is_lhs = true;
      }
    } else if ( parent->node_type() == AstNode::kAssignmentExp ||
                parent->node_type() == AstNode::kVariableStmt ) {
      in_assignment = true;
      break;
    } else if ( parent->CastToStatement() ) {
      break;
    }
    parent = parent->ParentNode();
  }
  if ( !is_lhs &&
       !is_delete &&
       callable->node_type() == AstNode::kLiteral &&
       args->node_type() == AstNode::kLiteral &&
       exp->ParentNode()->node_type() == AstNode::kCallExp ) {
    Literal* ident = callable->CastToLiteral();
    Literal* prototype = args->CastToLiteral();
    if ( ident->ValueType() == Literal::kIdentifier &&
         prototype->ValueType() == Literal::kProperty ) {
      if ( strcmp( prototype->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kPrototype ) ) == 0 ) {
        if ( strcmp( ident->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kArrayConstructor ) ) == 0 ) {
          Literal* array = ManagedHandle::Retain( new Literal( Literal::kArray ) );
          exp->ParentNode()->ReplaceChild( exp , array );
          return;
        } else if ( strcmp( ident->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kObjectConstructor ) ) == 0 ) {
          Literal* object = ManagedHandle::Retain( new Literal( Literal::kObject ) );
          object->Node( ManagedHandle::Retain<Empty>() );
          if ( !in_assignment ) {
            Expression* expression = ManagedHandle::Retain<Expression>();
            expression->AddChild( object );
            expression->Paren();
            exp->ParentNode()->ReplaceChild( exp , expression );
            return;
          }
          exp->ParentNode()->ReplaceChild( exp , object );
          return;
        } else if ( strcmp( ident->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kStringConstructor ) ) == 0 ) {
          Literal* str = AstUtils::CreateNameNode( "''" , Token::JS_STRING_LITERAL , exp->Line() , Literal::kString );
          exp->ParentNode()->ReplaceChild( exp , str );
          return;
        }
      }
    }
  }
  callable->Accept( this );
  args->Accept( this );
}

void OptimizerVisitor::NewCallProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  NodeIterator iterator = exp->Args()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}

void OptimizerVisitor::NormalFunctionCall_( CallExp* exp ) {
  AstNode* args = exp->Args();
  exp->Callable()->Accept( this );
  NodeIterator iterator = args->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( CallExp ) {
  PRINT_NODE_NAME;
  switch ( ast_node->CallType() ) {
    case CallExp::kNormal :
      NormalFunctionCall_( ast_node );
      break;

    case CallExp::kDot :
      DotAccessorProccessor_( ast_node );
      break;

    case CallExp::kNew :
      NewCallProccessor_( ast_node );
      break;

    case CallExp::kBracket :
      ArrayAccessorProccessor_( ast_node );
      break;
  }
}


VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  AstNode* member = ast_node->first_child();
  if ( member->node_type() == AstNode::kCallExp || member->node_type() == AstNode::kLiteral ) {
    AstNode* callable;
    AstNode* args;
    if ( member->node_type() == AstNode::kCallExp ) {
      CallExp* exp = member->CastToExpression()->CastToCallExp();
      callable = exp->Callable();
      args = exp->Args();
      if ( args->node_type() == AstNode::kLiteral &&
           strcmp( args->CastToLiteral()->Symbol()->GetToken(),
                   SymbolList::GetSymbol( SymbolList::kPrototype ) ) == 0 ) {
        args = 0;
      }
    } else {
      callable = member;
      args = 0;
    }
    if ( callable->node_type() == AstNode::kLiteral ) {
      Literal* value = callable->CastToLiteral();
      if ( value->ValueType() == Literal::kIdentifier ) {
        const char* ident = value->Symbol()->GetToken();
        if ( strcmp( ident , SymbolList::GetSymbol( SymbolList::kFunctionConstructor ) ) == 0 ) {
          ast_node->ParentNode()->ReplaceChild( ast_node , member );
        } else if ( strcmp( ident , SymbolList::GetSymbol( SymbolList::kArrayConstructor ) ) == 0 ) {
          if ( !args || args->IsEmpty() ) {
            Literal* array = ManagedHandle::Retain( new Literal( Literal::kArray ) );
            ast_node->ParentNode()->ReplaceChild( ast_node , array );
            return;
          } else {
            ast_node->ParentNode()->ReplaceChild( ast_node , member );
          }
        } else if ( strcmp( ident , SymbolList::GetSymbol( SymbolList::kObjectConstructor ) ) == 0 ) {
          if ( !args || args->IsEmpty() ) {
            Literal* object = ManagedHandle::Retain( new Literal( Literal::kObject ) );
            object->Node( ManagedHandle::Retain<Empty>() );
            ast_node->ParentNode()->ReplaceChild( ast_node , object );
            return;
          } else {
            ast_node->ParentNode()->ReplaceChild( ast_node , member );
          }
        } else if ( strcmp( ident , SymbolList::GetSymbol( SymbolList::kStringConstructor ) ) == 0 ) {
          if ( !args || args->IsEmpty() ) {
            Literal* string = AstUtils::CreateNameNode( "''" , Token::JS_STRING_LITERAL , ast_node->Line(),
                                                          Literal::kString );
            ast_node->ParentNode()->ReplaceChild( ast_node , string );
            return;
          } else {
            ast_node->ParentNode()->ReplaceChild( ast_node , member );
          }
        } else if ( strcmp( ident , SymbolList::GetSymbol( SymbolList::kNumberConstructor ) ) == 0 ) {
          if ( !args || args->IsEmpty() ) {
            Literal* number = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , ast_node->Line(),
                                                          Literal::kNumeric );
            ast_node->ParentNode()->ReplaceChild( ast_node , number );
            return;
          } else {
            ast_node->ParentNode()->ReplaceChild( ast_node , member );
          }
        }
      }
    }
  }
  member->Accept( this );
}


VISITOR_IMPL(YieldExp){}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  exp->CastToExpression()->Unary();
  exp->Accept( this );
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  int op = ast_node->Op();
  AstNode* left = ast_node->Left();
  AstNode* right = ast_node->Right();
  AstNode* parent = ast_node->ParentNode();
  Expression* exp = parent->CastToExpression();
  BinaryExp* binary = ( exp )? exp->CastToBinary() : 0;
  bool op_assoc = ( binary )? ConstantOptimizer::CheckOperatorAssoc( op , binary->Op() ) : true;
  if ( op_assoc && ConstantOptimizer::IsOptimizable( left , right , op ) ) {
    AstNode* ret = ConstantOptimizer::Optimize( left , right , op );
    ast_node->ParentNode()->ReplaceChild( ast_node , ret );
    return;
  }
  left->Accept( this );
  right->Accept( this );
  left = ast_node->Left();
  right = ast_node->Right();
  if ( op_assoc && ConstantOptimizer::IsOptimizable( left , right , op ) ) {
    AstNode* ret = ConstantOptimizer::Optimize( left , right , op );
    ast_node->ParentNode()->ReplaceChild( ast_node , ret );
  }
  exp = left->CastToExpression();
  binary = ( exp )? exp->CastToBinary() : 0;
  if ( binary ) {
    int lop = binary->Op();
    if ( op_assoc && ConstantOptimizer::IsOptimizable( binary->Right() , right , op ) ) {
      AstNode* ret = ConstantOptimizer::Optimize( binary->Right() , right , op );
      binary->ReplaceChild( binary->Right() , ret );
      ast_node->ParentNode()->ReplaceChild( ast_node , binary );
      binary->Accept( this );
    }
  }
}


VISITOR_IMPL( CompareExp ) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  ast_node->Cond()->Accept( this );
  ast_node->True()->Accept( this );
  ast_node->False()->Accept( this );
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  AstNode* left = ast_node->Left();
  Expression* exp = left->CastToExpression();
  if ( exp ) {
    exp->Lhs();
  }
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  if ( ast_node->child_length() == 1 && !( ast_node->IsParen() ) ) {
    ast_node->ParentNode()->ReplaceChild( ast_node , ast_node->first_child() );
  }
}


VISITOR_IMPL(Trait){}


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  scope_ = ast_node->GetScope();
  AstNode* parent = ast_node->ParentNode();
  bool is_exp = false;
  AstNode* exp = parent;
  bool is_unary_convertable = true;
  while ( parent ) {
    if ( parent->node_type() == AstNode::kAssignmentExp ||
         parent->node_type() == AstNode::kLiteral ||
         ( parent->node_type() == AstNode::kNodeList &&
           parent->ParentNode() && parent->ParentNode()->node_type() == AstNode::kFunction ) ) {
      is_unary_convertable = false;
      is_exp = true;
      break;
    } else if ( parent->node_type() != AstNode::kExpressionStmt &&
                parent->node_type() != AstNode::kExpression &&
                parent->node_type() != AstNode::kCallExp ) {
      is_unary_convertable = false;
    } else if ( parent->node_type() == AstNode::kExpressionStmt &&
                is_unary_convertable == true ) {
      break;
    }
    parent = parent->ParentNode();
  }
  
  if ( is_exp && exp && exp->node_type() == AstNode::kExpression ) {
    Expression* expression = exp->CastToExpression();
    if ( expression && expression->child_length() == 1 && expression->IsParen() ) {
      exp->CastToExpression()->NoParen();
    }
  } else if ( exp && is_unary_convertable ) {
    Expression* expression = exp->CastToExpression();
    if ( expression && expression->child_length() == 1 && expression->IsParen() ) {
      exp->CastToExpression()->NoParen();
      UnaryExp* unary = ManagedHandle::Retain( new UnaryExp( '!' ) );
      unary->Exp( exp->first_child() );
      exp->RemoveAllChild();
      exp->AddChild( unary );
    }
  }
  AstNode* name = ast_node->Name();
  Literal* name_node = name->CastToLiteral();
  NodeIterator body_iterator = ast_node->ChildNodes();
  AstNode* last = 0;
  NodeList* functions = ManagedHandle::Retain<NodeList>();
  while ( body_iterator.HasNext() ) {
    AstNode* node = body_iterator.Next();
    if ( last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt ) {
      node->Accept( this );
      last->Append( node );
      ast_node->RemoveChild( node );
    } else {
      node->Accept( this );
    }
    if ( node->node_type() == AstNode::kFunction ) {
      ast_node->RemoveChild( node );
      functions->AddChild( node );
    }
    last = node;
  }
  NodeIterator function_iterator = functions->ChildNodes();
  while ( function_iterator.HasNext() ) {
    ast_node->InsertBefore( function_iterator.Next() );
  }
  scope_ = scope_->Escape();
};


void OptimizerVisitor::ArrayProccessor_( Literal* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->first_child();
  while ( list_child ) {
    if ( !list_child->IsEmpty() ) {
      NodeIterator iter = list_child->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        if ( !element->IsEmpty() ) {
          element->Accept( this );
        }
      }
      if ( list_child->HasNext() ) {
        list_child = list_child->NextSibling();
      } else {
        break;
      }
    } else {
      break;
    }
  }
}


void OptimizerVisitor::ObjectProccessor_( Literal* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( !element_list->IsEmpty() ) {
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( this );
      element->first_child()->Accept( this );
    }
  }
}


VISITOR_IMPL( Literal ) {
  switch ( ast_node->ValueType() ) {
    case Literal::kArray :
      ArrayProccessor_( ast_node );
      break;

    case Literal::kObject :
      ObjectProccessor_( ast_node );
      break;

    case Literal::kVariable :
      ast_node->first_child()->Accept( this );
      break;
      
    case Literal::kIdentifier : {
      if ( ast_node->child_length() > 0 ) {
        ast_node->first_child()->Accept( this );
      }
    }
      break;
      
    default :
      return;
  }
}

}
