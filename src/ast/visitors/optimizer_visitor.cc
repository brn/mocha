#include <stdio.h>
#include <ast/ast.h>
#include <ast/visitors/optimizer_visitor.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
namespace mocha {

#define TOKEN yy::ParserImplementation::token
#define VISITOR_IMPL(type) void OptimizerVisitor::Visit##type( type* ast_node )
#define PRINT_NODE_NAME ast_node->PrintNodeName()


OptimizerVisitor::OptimizerVisitor( Scope* scope ) : scope_( scope ){}

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


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  AstNode* node_list = ast_node->FirstChild();
  if ( !node_list->IsEmpty() ) {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }
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

VISITOR_IMPL( VersionStmt ) {}

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
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->Then()->Accept( this );
  ast_node->Else()->Accept( this );
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->FirstChild();
  if ( ast_node->NodeType() == AstNode::kWhile || ast_node->NodeType() == AstNode::kDoWhile ) {
    ast_node->Exp()->Accept( this );
  } else {
    AstNode* index_exp = exp->FirstChild();
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
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->FirstChild();
  exp->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}

VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->FirstChild()->Accept( this );
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
  ast_node->FirstChild()->Accept( this );
  ast_node->Catch()->Accept( this );
  ast_node->Finally()->Accept( this );
}


void OptimizerVisitor::ArrayAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
}


void OptimizerVisitor::DotAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
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
  ast_node->Constructor()->Accept( this );
}


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


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  AstNode* name = ast_node->Name();
  ValueNode* name_node = name->CastToValue();
  if ( !name->IsEmpty() ) {
    scope_->Insert( name_node->Symbol() );
  }
  ast_node->SetScope( scope_->Enter() );
  NodeIterator arg_iterator = ast_node->Argv()->ChildNodes();
  while ( arg_iterator.HasNext() ) {
    ValueNode* arg = arg_iterator.Next()->CastToValue();
    if ( arg ) {
      scope_->Insert( arg->Symbol() );
    }
  }
  NodeIterator body_iterator = ast_node->ChildNodes();
  while ( body_iterator.HasNext() ) {
    body_iterator.Next()->Accept( this );
  }
  scope_->Escape();
};


VISITOR_IMPL( ValueNode ) {
  switch ( ast_node->ValueType() ) {
    case ValueNode::kVariable :
      scope_->Insert( ast_node->Symbol() );
      ast_node->FirstChild()->Accept( this );
      break;
      
    case ValueNode::kIdentifier :
      if ( strcmp( ast_node->Symbol()->GetToken() , SymbolList::GetSymbol( SymbolList::kScopeModule ) ) == 0 ) {
        ast_node->Symbol()->SetToken( SymbolList::GetSymbol( SymbolList::kGlobalAlias ) );
      }
      scope_->Ref( ast_node->Symbol() );
      AstNode* first_child = ast_node->FirstChild();
      if ( first_child ) {
        first_child->Accept( this );
      }
      break;
  }
}

}
