#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include "scope.h"
#include "ast_visitor.h"
#include "ast_state.h"
#include "codegen.h"
#include "managed_handle.h"
#include "ast.h"
#include "token_info.h"
#include "compiler.h"
#include "grammar.tab.hh"
#include "virtual_directory.h"

namespace mocha {

#define VISITOR_IMPL(type) void AstVisitor::Accept##type( type* ast_node )
#define TOKEN yy::ParserImplementation::token
#define PRINT_NODE_NAME ast_node->PrintNodeName();


AstVisitor::AstVisitor ( Scope* scope,
                         Compiler* compiler,
                         const char* modulename,
                         const char* filename ) :
    tmp_index_(0),
    module_name_ ( modulename ),
    filename_ ( filename ),
    scope_ ( scope ),
    compiler_( compiler ){};

AstVisitor::~AstVisitor () {}


VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  AstNode* root = ast_node->FirstChild();
  if ( root ) {
    root->Accept( this );
  }
}

VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ModuleStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ImportStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( Statement ) {
  PRINT_NODE_NAME;
  
}


VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    node->Accept( this );
    if ( node->ChildLength() > 0 ) {
      node->FirstChild()->Accept( this );
    }
  }
}

VISITOR_IMPL(LetStmt) {
  PRINT_NODE_NAME;
}


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->Then()->Accept( this );
  AstNode* maybeElse = ast_node->Else();
  if ( !maybeElse->IsEmpty() ) {
    maybeElse->Accept( this );
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  exp->FirstChild()->Accept( this );
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  AstNode* list = exp->FirstChild();
  while ( list ) {
    NodeIterator iterator = list->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
    if ( list->HasNext() ) {
      list = list->NextSibling();
    } else {
      break;
    }
  }
}


VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  AstNode *node = ast_node->FirstChild();
  node->Accept( this );
}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  AstNode* symbol = ast_node->FirstChild();
  AstNode* statement = symbol->NextSibling();
  symbol->Accept( this );
  statement->Accept( this );
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


void AstVisitor::RequireProccessor_( CallExp* ast_node ) {
  AstNode* js_filepath_node = ast_node->Args();
  if ( !js_filepath_node->IsEmpty() ) {
    js_filepath_node = js_filepath_node->FirstChild();
    ValueNode* value = js_filepath_node->CastToValue();
    if ( value && value->ValueType() == ValueNode::kString ) {
      TokenInfo* info = value->Symbol();
      std::string js_path = info->GetToken();
      js_path.erase( 0 , 1 );
      js_path.erase( js_path.size() - 1 , js_path.size() );
      StrHandle current_dir = VirtualDirectory::GetInstance()->GetCurrentDir();
      StrHandle real_path = compiler_->Load( js_path.c_str() );
      VirtualDirectory::GetInstance()->Chdir( current_dir.Get() );
      ValueNode* exporter_value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
      ValueNode* key_value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
      exporter_value->Line( ast_node->Line() );
      TokenInfo* exporter = ManagedHandle::Retain( new TokenInfo( "__global_export__" , TOKEN::JS_IDENTIFIER , ast_node->Line() ) );
      StrHandle key_str = FileSystem::GetModuleKey( real_path.Get() );
      TokenInfo* key = ManagedHandle::Retain( new TokenInfo( key_str.Get() , TOKEN::JS_IDENTIFIER , ast_node->Line() ) );
      exporter_value->Symbol( exporter );
      key_value->Symbol( key );
      CallExp *module_accessor = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
      module_accessor->Callable( exporter_value );
      module_accessor->Args( key_value );
      module_accessor->Depth( 0 );
      AstNode* parent = ast_node->ParentNode();
      if ( parent->NodeType() == AstNode::kCallExp ) {
        reinterpret_cast<CallExp*>( parent )->Callable( module_accessor );
      } else {
        parent->ReplaceChild( ast_node , module_accessor );
      }
    }
  }
}


VISITOR_IMPL( CallExp ) {
  PRINT_NODE_NAME;
  
  ast_node->Callable()->Accept( this );
  AstNode* arg_list = ast_node->Args();
  int call_type = ast_node->CallType();

  if ( call_type == CallExp::kNormal ) {
    AstNode* name = ast_node->Callable();
    ValueNode* value_node = name->CastToValue();
    if ( value_node != 0 && value_node->ValueType() == ValueNode::kIdentifier ) {
      const char* name = value_node->Symbol()->GetToken();
      if ( strcmp( name , "require" ) == 0 ) {
        RequireProccessor_( ast_node );
      } else {
        goto NORMAL_FN_CALL;
      }
    } else {
      goto NORMAL_FN_CALL;
    }
  } else {
    if ( call_type == CallExp::kDot || call_type == CallExp::kBracket ) {
      arg_list->Accept( this );
    } else if ( !arg_list->IsEmpty() ) {
   NORMAL_FN_CALL :
      NodeIterator iterator = arg_list->ChildNodes();
      while ( iterator.HasNext() ) {
        iterator.Next()->Accept( this );
      }
    }
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

VISITOR_IMPL(CompareExp) {
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

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  ast_node->Name()->Accept( this );
  AstNode* argv = ast_node->Argv();
  if ( !argv->IsEmpty() ) {
    NodeIterator iterator = argv->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }
  printf("chile size%d\n" , ast_node->ChildLength());
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
};


VISITOR_IMPL( ValueNode ) {
  PRINT_NODE_NAME;
  if ( ast_node->ValueType() == ValueNode::kIdentifier ) {
    printf( "symbol %s\n" , ast_node->Symbol()->GetToken() );
  } else if ( ast_node->ValueType() == ValueNode::kThis ) {
     printf( "symbol this\n" );
  } else {
    printf( "%d\n" , ast_node->ValueType() );
  }
}
}

#undef PRINT_NODE_NAME
