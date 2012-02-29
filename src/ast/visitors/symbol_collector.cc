#include <stdio.h>
#include <ast/ast.h>
#include <ast/visitors/symbol_collector.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/js_token.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
#include <utils/pool/managed_handle.h>
namespace mocha {

#define TOKEN yy::ParserImplementation::token
#define VISITOR_IMPL(type) void SymbolCollector::Visit##type( type* ast_node )

#ifdef PRINTABLE
#define PRINT_NODE_NAME printf( "depth = %d name = %s\n" , depth_++ , ast_node->GetName() )
#else
#define PRINT_NODE_NAME
#endif


SymbolCollector::SymbolCollector( Scope* scope , bool is_debug_ ) : depth_( 0 ) , is_debug_( is_debug_ ), scope_( scope ){}

VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  ast_node->SetScope( scope_->Enter() );
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  scope_->Escape();
}


VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( NodeList ) {
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
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
VISITOR_IMPL( AssertStmt ) {
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* statement = iterator.Next();
    statement->Accept( this );
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
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->Then()->Accept( this );
  ast_node->Else()->Accept( this );
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
  ast_node->first_child()->Accept( this );
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
  AstNode* sym = ast_node->first_child();
  AstNode* stmt = sym->NextSibling();
  stmt->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  AstNode* catch_block = ast_node->Catch();
  AstNode* finally_block = ast_node->Finally();
  ast_node->first_child()->Accept( this );
  if ( !catch_block->IsEmpty() ) {
    catch_block->first_child()->first_child()->Accept( this );
  } else if ( !finally_block->IsEmpty() ) {
    finally_block->first_child()->Accept( this );
  }
}


void SymbolCollector::ArrayAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
}


void SymbolCollector::DotAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
}


void SymbolCollector::NewCallProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  NodeIterator iterator = exp->Args()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


void SymbolCollector::NormalFunctionCall_( CallExp* exp ) {
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
  ast_node->first_child()->Accept( this );
}


VISITOR_IMPL(YieldExp){}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
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
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
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
  AstNode* name = ast_node->Name();
  Literal* name_node = name->CastToLiteral();
  if ( !name->IsEmpty() ) {
    scope_->Insert( name_node->Symbol() , ast_node );
  }
  InnerScope* scope = scope_->Enter();
  ast_node->SetScope( scope );
  if ( is_debug_ ) {
    TokenInfo* runtime = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kRuntime ) ,
                                                               Token::JS_IDENTIFIER , ast_node->Line() ) );
    scope->Ref( runtime );
  }
  NodeIterator arg_iterator = ast_node->Argv()->ChildNodes();
  while ( arg_iterator.HasNext() ) {
    Literal* arg = arg_iterator.Next()->CastToLiteral();
    if ( arg ) {
      scope->Insert( arg->Symbol() , arg );
    }
  }
  NodeIterator body_iterator = ast_node->ChildNodes();
  while ( body_iterator.HasNext() ) {
    body_iterator.Next()->Accept( this );
  }
  scope_->Escape();
};


void SymbolCollector::ArrayProccessor_( Literal* ast_node ) {
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


void SymbolCollector::ObjectProccessor_( Literal* ast_node ) {
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
      scope_->Insert( ast_node->Symbol() , ast_node->first_child() );
      break;

    case Literal::kProperty :
      break;
      
    case Literal::kIdentifier : {
      if ( strcmp( ast_node->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kScopeModule ) ) == 0 ) {
        ast_node->Symbol()->SetToken( SymbolList::GetSymbol( SymbolList::kGlobalAlias ) );
      }
      scope_->Ref( ast_node->Symbol() );
      AstNode* first_child = ast_node->first_child();
      if ( first_child ) {
        first_child->Accept( this );
      }
    }
      break;
      
    default :
      return;
  }
}

}
