#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include <compiler/compiler.h>
#include <compiler/tokens/token_info.h>
#include <compiler/scopes/scope.h>
#include <ast/visitors/ast_visitor.h>
#include <ast/ast.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/pool/managed_handle.h>
#include <ast/utils/ast_utils.h>
#include <grammar/grammar.tab.hh>

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
  
  AstNode* body = ast_node->FirstChild();
  AstNode* name = ast_node->Name();

  if ( body->NodeType() == AstNode::kBlockStmt ) {
    //Get block inner node.
    body = body->FirstChild();
  } else {
    //Create node list.
    StatementList *list = ManagedHandle::Retain<StatementList>();
    list->AddChild( body );
    body = list;
  }

  /**
   * Create anonymous function call like (function(){ ... })()
   * to create module scopes.
   */
  Function *fn_node = AstUtils::CreateFunctionDecl( name , ManagedHandle::Retain<Empty>() , body );
  ExpressionStmt* an_stmt_node = AstUtils::CreateAnonymousFnCall( fn_node , ManagedHandle::Retain<Empty>() );
  body->Accept( this );
  //For anonymous module.
  if ( !name->IsEmpty() ) {
    /*
     * In anonymous modules,
     * all export properties are directly add to global export symbol.
     * Like this -> __MC_global_alias__.<name> = ...;
     */
    ValueNode* alias = AstUtils::CreateNameNode( AstUtils::GetGlobalAliasSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
    CallExp* dot_accessor = AstUtils::CreateDotAccessor( alias , name );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , dot_accessor , an_stmt_node->FirstChild() );
    ExpressionStmt* exp_stmt =  AstUtils::CreateExpStmt( exp );
    ast_node->ParentNode()->ReplaceChild( ast_node , exp_stmt );
  } else {
    ast_node->ParentNode()->ReplaceChild( ast_node , an_stmt_node );
  }

  TokenInfo* local = ManagedHandle::Retain( new TokenInfo( AstUtils::GetLocalExportSymbol(),
                                                           TOKEN::JS_IDENTIFIER , ast_node->Line() ) );
  ValueNode* ret_local = AstUtils::CreateNameNode( AstUtils::GetLocalExportSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );

  ValueNode* init;
  if ( !name->IsEmpty() ) {
    init = AstUtils::CreateVarInitiliser( local,
                                          AstUtils::CreateObjectLiteral( ManagedHandle::Retain<Empty>() ) );
  } else {
    ValueNode* alias = AstUtils::CreateNameNode( AstUtils::GetGlobalAliasSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
    init = AstUtils::CreateVarInitiliser( local,
                                          alias );
  }
  NodeList* list = ManagedHandle::Retain<NodeList>();
  ReturnStmt* ret = AstUtils::CreateReturnStmt( ret_local );
  list->AddChild( init );
  VariableStmt* var_stmt = AstUtils::CreateVarStmt( list );
  fn_node->InsertBefore( var_stmt );
  fn_node->AddChild( ret );
}


VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
  AstNode* node = ast_node->FirstChild();
  node->Accept( this );
  if ( node->NodeType() == AstNode::kFunction ) {
    Function* fn = reinterpret_cast<Function*>( node );
    ValueNode* name = fn->Name()->CastToValue();
    ValueNode* local = AstUtils::CreateNameNode( AstUtils::GetLocalExportSymbol(),
                                                 TOKEN::JS_IDENTIFIER , ast_node->Line() );
    CallExp *export_prop = AstUtils::CreateDotAccessor( local , name );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , export_prop , fn );
    ExpressionStmt* exp_stmt_node = AstUtils::CreateExpStmt( assign );
    ast_node->ParentNode()->ReplaceChild( ast_node , exp_stmt_node );
  } else if ( node->NodeType() == AstNode::kNodeList ) {
    NodeIterator iterator = node->ChildNodes();
    bool is_replaced = false;
    while ( iterator.HasNext() ) {
      AstNode *item = iterator.Next();
      TokenInfo *name_info = item->CastToValue()->Symbol();
      ValueNode *name = AstUtils::CreateNameNode( name_info->GetToken() , TOKEN::JS_IDENTIFIER , ast_node->Line() , true );
      ValueNode *local = AstUtils::CreateNameNode( AstUtils::GetLocalExportSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
      CallExp *export_prop = AstUtils::CreateDotAccessor( local , name );
      AssignmentExp* assign;
      if ( !item->FirstChild()->IsEmpty() ) {
        assign = AstUtils::CreateAssignment( '=' , export_prop , item->FirstChild() );
      } else {
        assign = AstUtils::CreateAssignment( '=' , export_prop , name );
      }
      ExpressionStmt* exp_stmt_node = AstUtils::CreateExpStmt( assign );
      if ( !is_replaced ) {
        ast_node->ParentNode()->ReplaceChild( ast_node , exp_stmt_node );
        is_replaced = true;
      } else {
        ast_node->ParentNode()->AddChild( exp_stmt_node );
      }
    }
  }
}

VISITOR_IMPL( ImportStmt ) {
  PRINT_NODE_NAME;
  ImportProccessor_( ast_node );
  if ( ast_node->VarType() == ImportStmt::kDst ) {
    ast_node->Exp()->Accept( this );
  }
}


void AstVisitor::ImportProccessor_( ImportStmt* ast_node ) {
  AstNode* from = ast_node->From();
  AstNode* file = from->FirstChild();
  ValueNode* value = file->CastToValue();

  if ( value && value->ValueType() == ValueNode::kString ) {
    //Create path from js string literal.
    TokenInfo* info = value->Symbol();
    std::string js_path = info->GetToken();
    js_path.erase( 0 , 1 );
    //"path to file" -> path to file
    js_path.erase( js_path.size() - 1 , js_path.size() );
    
    StrHandle current_dir = VirtualDirectory::GetInstance()->GetCurrentDir();
    //Get full path of module.
    StrHandle real_path = compiler_->Load( js_path.c_str() );

    //Set virtual dir to current context dir.
    VirtualDirectory::GetInstance()->Chdir( current_dir.Get() );

    //Get module uuid key.
    StrHandle key_str = FileSystem::GetModuleKey( real_path.Get() );
    TokenInfo* key = ManagedHandle::Retain( new TokenInfo( key_str.Get() , TOKEN::JS_IDENTIFIER , ast_node->Line() ) );

    //Reserve module key string for later code generation.
    ast_node->ModKey( key );
  }
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


void AstVisitor::VarListProcessor_( AstNode* ast_node ) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      ValueNode* value = item->CastToValue();
      if ( value && ( value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) ) {
        item->CastToValue()->Node()->Accept( this );
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          initialiser->Accept( this );
        }
      } else {
        item->Accept( this );
      }
    }
  }
}


VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  VarListProcessor_( ast_node );
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
  AstNode* maybeBlock = ast_node->Then();
  AstNode* maybeElse = ast_node->Else();
  ast_node->Then()->Accept( this );
  if ( !maybeElse->IsEmpty() ) {
    maybeElse->Accept( this );
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  switch ( ast_node->NodeType() ) {
    case AstNode::kFor : //Fall Through
    case AstNode::kForWithVar :
      ForProccessor_( ast_node );
      break;

    case AstNode::kForIn :
    case AstNode::kForInWithVar :
    case AstNode::kForEach :
    case AstNode::kForEachWithVar :
      ForInProccessor_( ast_node );
      break;

    case AstNode::kDoWhile :
      DoWhileProccessor_( ast_node );
      break;

    case AstNode::kWhile :
      WhileProccessor_( ast_node );
      break;
  }
}


void AstVisitor::ForProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* cond_exp = ( index_exp )? index_exp->NextSibling() : 0;
  AstNode* incr_exp = ( cond_exp )? cond_exp->NextSibling() : 0;

  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    VarListProcessor_( index_exp );
  } else {
    index_exp->Accept( this );
  }
  
  if ( cond_exp ) {
    cond_exp->Accept( this );
  }
  
  if ( incr_exp ) {
    incr_exp->Accept( this );
  }
  

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    ast_node->FirstChild()->Accept( this );
  }
}

void AstVisitor::ForInProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  bool is_each = ast_node->NodeType() == AstNode::kForEachWithVar;
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();
  exp->Accept( this );
  index_exp->Accept( this );
  target_exp->Accept( this );
  ast_node->FirstChild()->Accept( this );
}



void AstVisitor::WhileProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp()->FirstChild();
  exp->Accept( this );
  ast_node->FirstChild()->Accept( this );
}


void AstVisitor::DoWhileProccessor_( IterationStmt* ast_node ) {
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
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
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


void AstVisitor::ArrayAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
}


void AstVisitor::DotAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  exp->Args()->Accept( this );
}

void AstVisitor::NewCallProccessor_( CallExp* exp ) {
  AstNode* args = exp->Args();
  exp->Callable()->Accept( this );

  if ( !args->IsEmpty() ) {
    NodeIterator iterator = exp->Args()->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }
}

void AstVisitor::NormalFunctionCall_( CallExp* exp ) {
  AstNode* args = exp->Args();
  exp->Callable()->Accept( this );
  if ( !args->IsEmpty() ) {
    NodeIterator iterator = args->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
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

VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->Body()->Accept( this );
  ast_node->Name()->Accept( this );
}

VISITOR_IMPL(ClassProperties) {
  AstNode* pr = ast_node->Private();
  AstNode* pb = ast_node->Public();
  AstNode* st = ast_node->Static();
  AstNode* cn = ast_node->Constructor();
  AstNode* proto = ast_node->Prototype();

#define ITERATION( name )                               \
  if ( name ) {                                         \
    NodeIterator name##_iterator = name->ChildNodes();  \
    while ( name##_iterator.HasNext() ) {               \
      name##_iterator.Next()->Accept( this );           \
    }                                                   \
  }

  ITERATION( cn );
  ITERATION( proto );
  ITERATION( pb );
  ITERATION( pr );
  ITERATION( st );
}

VISITOR_IMPL(ClassExpandar) {
}

VISITOR_IMPL(ClassMember) {
  PRINT_NODE_NAME;
  ast_node->FirstChild()->Accept( this );
  
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
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
};


void AstVisitor::ArrayProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->FirstChild();
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
    }
  }
}


void AstVisitor::ObjectProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( !element_list->IsEmpty() ) {
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( this );
      element->FirstChild()->Accept( this );
    }
  }
}


void AstVisitor::VarInitialiserProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  if ( ast_node->ValueType() == ValueNode::kVariable ) {
    //ast_node->Symbol()->Accept( this );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( !initialiser->IsEmpty() ) {
    initialiser->Accept( this );
  }
}


void AstVisitor::DstArrayProccessor_( ValueNode* ast_node , int depth ) {
  PRINT_NODE_NAME;
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
              //CreateDstAssignment_( elem->Symbol()->GetToken() );
            } else if ( elem->ValueType() == ValueNode::kDst ) {
              DstObjectProcessor_( elem , ( depth + 1 ) );
            } else if ( elem->ValueType() == ValueNode::kDstArray ) {
              DstArrayProccessor_( elem , ( depth + 1 ) );
            }
          }
        }
        if ( iter.HasNext() ) {
          index++;
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


void AstVisitor::DstMemberProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  TokenInfo* info = ast_node->Symbol();
  /**switch( info->GetType() ) {
    case TOKEN::JS_IDENTIFIER :
      {
        char tmp[ 100 ];
        sprintf( tmp , ".%s" , info->GetToken() );
        dst_accessor_.push_back( tmp );
      }
      break;

    case TOKEN::JS_NUMERIC_LITERAL :
    case TOKEN::JS_STRING_LITERAL :
      {
        char tmp[ 100 ];
        sprintf( tmp , "[%s]" , info->GetToken() );
        dst_accessor_.push_back( tmp );
      }
      break;
      
      }*/
}


void AstVisitor::DstObjectProcessor_( ValueNode* ast_node , int depth ) {
  PRINT_NODE_NAME;
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
            DstMemberProccessor_( value );
            AstNode* child_node = value->FirstChild();
            ValueNode* prop = child_node->CastToValue();
            if ( prop ) {
              if ( prop->ValueType() == ValueNode::kDst ) {
                DstObjectProcessor_( prop , ( depth + 1 ) );
              } else if ( prop->ValueType() == ValueNode::kDstArray ) {
                DstArrayProccessor_( prop , ( depth + 1 ) );
              } else {
                //CreateDstAssignment_( prop->Symbol()->GetToken() );
              }
            }
          } else {
            /*TokenInfo *info = value->Symbol();
            const char* name = info->GetToken();
            char tmp[ 100 ];
            sprintf( tmp , ".%s" , name );
            printf( "%s\n" , name );
            dst_accessor_.push_back( tmp );
            CreateDstAssignment_( name );*/
          }
          break;

        case ValueNode::kDst :
        case ValueNode::kDstArray :
          DstMemberProccessor_( value );
          AstNode* child_node = value->FirstChild();
          ValueNode* value = child_node->CastToValue();
          if ( value ) {
            if ( value->ValueType() == ValueNode::kDstArray ) {
              DstArrayProccessor_( ast_node , ( depth + 1 ) );
            } else {
              DstObjectProcessor_( ast_node , ( depth + 1 ) );
            }
          }
      }
    }
  }
}


void AstVisitor::DstProcessor_( ValueNode* ast_node ) {
  if ( ast_node->ValueType() == ValueNode::kDstArray ) {
    DstArrayProccessor_( ast_node , 0 );
  } else {
    DstObjectProcessor_( ast_node , 0 );
  }
}


VISITOR_IMPL( ValueNode ) {
  PRINT_NODE_NAME;
  switch ( ast_node->ValueType() ) {
    case ValueNode::kArray :
      printf( "Array\n" );
      //ArrayProccessor_( ast_node );
      break;

    case ValueNode::kObject :
      printf( "Object\n" );
      ObjectProccessor_( ast_node );
      break;

    case ValueNode::kVariable :
      printf( "var\n" );
      VarInitialiserProccessor_( ast_node );
      break;

    case ValueNode::kDst :
    case ValueNode::kDstArray :
      printf( "Dst\n" );
      DstProcessor_( ast_node );
      break;

    case ValueNode::kRest :
      printf( "Rest\n" );
      //ast_node->Accept( this );
      break;
      
    default :
      const char* symbol = ast_node->Symbol()->GetToken();
      printf( "%s\n" , symbol );
  }
}
}

#undef PRINT_NODE_NAME
