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
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/iteration_processor.h>
#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <grammar/grammar.tab.hh>

namespace mocha {


#define VISITOR_IMPL(type) void AstVisitor::Accept##type( type* ast_node )
#define TOKEN yy::ParserImplementation::token
#define PRINT_NODE_NAME ast_node->PrintNodeName();
#define REGIST(node) visitor_info_->SetCurrentStmt( node )


AstVisitor::AstVisitor( Scope* scope , Compiler* compiler , const char* modulename,
                        const char* filename ) :
    visitor_info_( new VisitorInfo( scope , compiler ,
                                    ManagedHandle::Retain<DstaExtractedExpressions>() , modulename , filename ) ),
    proc_info_( new ProcessorInfo( this , scope , visitor_info_.Get() ) ){}

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
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ModuleStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
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
  REGIST(ast_node);
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
  REGIST(ast_node);
  ImportProccessor_( ast_node );
  
  ast_node->Exp()->Accept( this );
  
  ValueNode *name = AstUtils::CreateNameNode( ast_node->ModKey()->GetToken() , TOKEN::JS_STRING_LITERAL , ast_node->Line() );
  ValueNode *global = AstUtils::CreateNameNode( AstUtils::GetGloablExportSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
  CallExp* exp = AstUtils::CreateArrayAccessor( global , name );
  if ( ast_node->From()->ChildLength() > 1 ) {
    NodeIterator iter = ast_node->From()->ChildNodes();
    iter.Next();
    while ( iter.HasNext() ) {
      ValueNode* item = iter.Next()->CastToValue();
      if ( !item->IsEmpty() ) {
        if ( item->ValueType() == ValueNode::kString ) {
          exp = AstUtils::CreateArrayAccessor( exp , item );
        } else {
          exp = AstUtils::CreateDotAccessor( exp , item );
        }
      }
    }
  }
  
  if ( ast_node->HasDsta() ) {
    ValueNode* value = AstUtils::CreateVarInitiliser( ast_node->Exp()->CastToValue()->Symbol() , exp );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    list->Append( DstaProcessor::CreateDstaExtractedVarStmt( ast_node , proc_info_.Get() ) );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    ast_node->ParentNode()->ReplaceChild( ast_node , stmt );
  } else {
    ValueNode* value = AstUtils::CreateVarInitiliser( ast_node->Exp()->CastToValue()->Symbol() , exp );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    ast_node->ParentNode()->ReplaceChild( ast_node , stmt );
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
    StrHandle real_path = visitor_info_->GetCompiler()->Load( js_path.c_str() );

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
  REGIST(ast_node);
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
  REGIST(ast_node);
  VariableProcessor::ProcessVarList( ast_node , proc_info_.Get() );
  if ( ast_node->HasDsta() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , proc_info_.Get() );
    ast_node->Append( list );
  }
}

VISITOR_IMPL(LetStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
}


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
  if ( ast_node->HasDsta() ) {
    NodeIterator iterator = ast_node->GetDsta()->Refs()->ChildNodes();
    NodeList* var_list = ManagedHandle::Retain<NodeList>();
    while ( iterator.HasNext() ) {
      ValueNode* node = AstUtils::CreateVarInitiliser( iterator.Next()->CastToValue()->Symbol() , ManagedHandle::Retain<Empty>() );
      var_list->AddChild( node );
    }
    VariableStmt *var_stmt = AstUtils::CreateVarStmt( var_list );
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->Paren();
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
    ast_node->ParentNode()->InsertAfter( stmt , ast_node );
  }
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->Exp()->Accept( this );
  AstNode* maybeBlock = ast_node->Then();
  AstNode* maybeElse = ast_node->Else();
  ast_node->Then()->Accept( this );
  if ( ast_node->HasDsta() ) {
    if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      maybeBlock->FirstChild()->InsertBefore( exp_stmt );
    } else {
      BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
      stmt_list->AddChild( exp_stmt );
      stmt_list->AddChild( maybeBlock->Clone() );
      block->AddChild( stmt_list );
      ast_node->Then()->RemoveAllChild();
      ast_node->Then( block );
    }
    AstNode* parent = ast_node;
    AstNode* first_if = ast_node;
    while ( parent->NodeType() == AstNode::kIFStmt ) {
      parent = parent->ParentNode();
      if ( parent->NodeType() != AstNode::kIFStmt ) {
        break;
      } else {
        first_if = parent;
      }
    }
    if ( first_if->HasPrev() && first_if->PreviousSibling()->NodeType() == AstNode::kVariableStmt ) {
      first_if->PreviousSibling()->Append( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ) );
    } else {
      parent->InsertBefore( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ), first_if );
    }
  }
  if ( !maybeElse->IsEmpty() ) {
    maybeElse->Accept( this );
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  switch ( ast_node->NodeType() ) {
    case AstNode::kFor : //Fall Through
    case AstNode::kForWithVar :
      IterationProcessor::ProcessForNode( ast_node , proc_info_.Get() );
      break;

    case AstNode::kForIn :
    case AstNode::kForInWithVar :
      IterationProcessor::ProcessForInNode( ast_node , proc_info_.Get() );
      break;
    case AstNode::kForEach :
    case AstNode::kForEachWithVar :
      IterationProcessor::ProcessForEachNode( ast_node , proc_info_.Get() );
      break;

    case AstNode::kDoWhile :
    case AstNode::kWhile :
      IterationProcessor::ProcessWhileNode( ast_node , proc_info_.Get() );
      break;
  }
}


VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->Exp();
  AstNode* body = ast_node->FirstChild();
  exp->Accept( this );
  body->Accept( this );
  if ( ast_node->HasDsta() ) {
    VariableStmt* var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() );
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
    if ( body->NodeType() == AstNode::kBlockStmt ) {
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      body->FirstChild()->InsertBefore( exp_stmt );
    } else {
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      stmt_list->AddChild( exp_stmt );
      stmt_list->AddChild( body->Clone() );
      block->AddChild( stmt_list );
      ast_node->RemoveAllChild();
      ast_node->AddChild( block );
    }
  }
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  Statement* stmt_tmp = ManagedHandle::Retain<Statement>();
  REGIST(stmt_tmp);
  AstNode *parent = ast_node->ParentNode();
  SwitchStmt *switch_stmt = reinterpret_cast<SwitchStmt* >( parent->ParentNode() );
ast_node->Exp()->Accept( this );
AstNode *node = ast_node->FirstChild();
node->Accept( this );
ExpressionStmt* case_exp_stmt = 0;
ExpressionStmt* cond_exp_stmt = 0;
if ( stmt_tmp->HasDsta() ) {
  NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( stmt_tmp , proc_info_.Get() );
  Expression* exp = ManagedHandle::Retain<Expression>();
  exp->Append( list );
  exp->Paren();
  case_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
  case_exp_stmt->AddChild( exp );
  if ( !node->IsEmpty() ) {
    node->InsertBefore( case_exp_stmt );
  } else {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    list->AddChild( case_exp_stmt );
    ast_node->RemoveAllChild();
    ast_node->AddChild( list );
    node = list;
  }
}
if ( switch_stmt->HasDsta() ) {
  NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( switch_stmt , proc_info_.Get() );
  Expression* exp = ManagedHandle::Retain<Expression>();
  exp->Append( list );
  exp->Paren();
  cond_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
  cond_exp_stmt->AddChild( exp );
  if ( !node->IsEmpty() ) {
    node->InsertBefore( cond_exp_stmt );
  } else {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    list->AddChild( case_exp_stmt );
    node->RemoveAllChild();
    node->AddChild( list );
  }
}

}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* symbol = ast_node->FirstChild();
  AstNode* statement = symbol->NextSibling();
  symbol->Accept( this );
  statement->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
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
  Statement* stmt = ManagedHandle::Retain<Statement>();
  REGIST(stmt);
  ast_node->Name()->Accept( this );
  AstNode* argv = ast_node->Argv();
  int argc = 0;
  
  if ( !argv->IsEmpty() ) {
    argc = argv->ChildLength();
    NodeIterator iterator = argv->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }

  bool is_rest = visitor_info_->IsRestInjection();
  visitor_info_->SetRestInjection( false );
  if ( ast_node->FunctionType() == Function::kShorten ) {
    Statement* stmt_tmp = ManagedHandle::Retain<Statement>();
    REGIST( stmt_tmp );
    ast_node->FirstChild()->Accept( this );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ReturnStmt* ret_stmt = AstUtils::CreateReturnStmt( ast_node->FirstChild()->Clone() );
    if ( stmt_tmp->HasDsta() ) {
      list->AddChild( DstaProcessor::CreateTmpVarDecl( stmt_tmp , proc_info_.Get() ) );
    }
    list->AddChild( ret_stmt );
    ast_node->RemoveAllChild();
    ast_node->Append( list );
  } else {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }

  VariableStmt* dsta_stmt = 0;
  VariableStmt* rest_stmt = 0;
  if ( stmt->HasDsta() ) {
    NodeList *list = DstaProcessor::CreateDstaExtractedVarStmt( stmt , proc_info_.Get() );
    dsta_stmt = AstUtils::CreateVarStmt( list );
  }
  
  if ( is_rest ) {
    ValueNode* rhs = AstUtils::CreateNameNode( AstUtils::GetArgumentsSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    char num[50];
    sprintf( num , "%d" , argc - 1 );
    ValueNode* arg = AstUtils::CreateNameNode( num , TOKEN::JS_NUMERIC_LITERAL , ast_node->Line() );
    ValueNode* to_array = AstUtils::CreateNameNode( AstUtils::GetToArraySymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
    list->AddChild( rhs );
    list->AddChild( arg );
    CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list );
    CallExp* std_to_array = AstUtils::CreateStdMod( nrm );
    ValueNode* var_node = AstUtils::CreateVarInitiliser( visitor_info_->GetRestExp() , std_to_array );
    NodeList* var_list = ManagedHandle::Retain<NodeList>();
    var_list->AddChild( var_node );
    rest_stmt = AstUtils::CreateVarStmt( var_list );
  }

  if ( dsta_stmt && rest_stmt ) {
    dsta_stmt->AddChild( rest_stmt->FirstChild() );
    ast_node->InsertBefore( dsta_stmt );
  } else if ( dsta_stmt ) {
    ast_node->InsertBefore( dsta_stmt );
  } else if ( rest_stmt ) {
    ast_node->InsertBefore( rest_stmt );
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
      VariableProcessor::ProcessVarList( ast_node , proc_info_.Get() );
      break;

    case ValueNode::kDst :
    case ValueNode::kDstArray :
      printf( "Dst\n" );
      DstaProcessor::ProcessNode( ast_node , proc_info_.Get() );
      break;

    case ValueNode::kRest : {
      printf( "Rest\n" );
      visitor_info_->SetRestInjection( true );
      ast_node->ValueType( ValueNode::kIdentifier );
      ast_node->ParentNode()->RemoveChild( ast_node );
      visitor_info_->SetRestExp( ast_node->Symbol() );
    }
      break;
      
    default :
      const char* symbol = ast_node->Symbol()->GetToken();
      printf( "%s\n" , symbol );
  }
}
}

#undef PRINT_NODE_NAME
