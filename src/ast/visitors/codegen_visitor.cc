#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast.h>
#include <ast/visitors/codegen_visitor.h>
#include <ast/visitors/utils/codewriter.h>
#include <utils/pool/managed_handle.h>
#include <utils/file_system/file_system.h>
#include <grammar/grammar.tab.hh>


namespace mocha {

#define TOKEN yy::ParserImplementation::token
#define VISITOR_IMPL(type) void CodegenVisitor::Accept##type( type* ast_node )
#define ITERATOR(name) begin = name.begin(),end = name.end()
#define PRINT_NODE_NAME ast_node->PrintNodeName()
#define ACCEPT( ast )                           \
  if ( ast != 0 )                               \
    ast->Accept(this)



CodegenVisitor::CodegenVisitor( Options* option ) :
    tmp_index_( 0 ),is_line_( false ),has_rest_( false ),
    stream_( new CodeStream( &default_buffer_ ) ),
    writer_( new CodeWriter( option->IsPrettyPrint() , option->IsDebug() ) ),
    current_class_ ( 0 ){}


VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  stream_->Write( "(function()" );
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );
  writer_->InsertDebugSymbol( stream_.Get() );
  writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
  stream_->Write( "__global_export__" );
  writer_->WriteOp( '=' , 0 , stream_.Get() );
  stream_->Write( "{}" );
  writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
  stream_->Write( "__MC_tmp__" );
  writer_->WriteOp( '=' , 0 , stream_.Get() );
  stream_->Write( "undefined" );
  writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kArgs , stream_.Get() );
  stream_->Write( ")()" );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  stream_->Write( "(function()" );
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );
  writer_->InitializeFileName( ast_node->FileName() , stream_.Get() );
  current_root_ = ast_node;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kArgs , stream_.Get() );
  stream_->Write( ")()" );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
  AstNode* node_list = ast_node->FirstChild();
  if ( !node_list->IsEmpty() ) {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }
  writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
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


VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* statement = iterator.Next();
    statement->Accept( this );
  }
}


void CodegenVisitor::VarListProcessor_( AstNode* ast_node ) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  printf( "%d\n" , ast_node->ChildLength() );
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( !item->IsEmpty() ) {
      ValueNode* value = item->CastToValue();
      item->Accept( this );
      if ( iterator.HasNext() ) {
        if ( CurrentState_() == CodeWriter::kFor ) {
          stream_->Write( ',' );
        } else {
          writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
        }
      } else if ( CurrentState_() != CodeWriter::kFunctionEndBrace ) {
        if ( CurrentState_() != CodeWriter::kFor ) {
          writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
        }
      }
    }
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
  VarListProcessor_( ast_node );
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  ast_node->FirstChild()->Accept( this );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  if ( !MatchState_( TOKEN::JS_ELSE ) ) {
    writer_->SetLine( ast_node->Line() , stream_.Get() );
  }
  writer_->WriteOp( TOKEN::JS_IF , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  AstNode* maybeBlock = ast_node->Then();
  AstNode* maybeElse = ast_node->Else();
  
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    maybeBlock->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
    if ( maybeElse->IsEmpty() ) {
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    ast_node->Then()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      if ( maybeElse->IsEmpty() ) {
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
    }
  }
  
  if ( !maybeElse->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_ELSE , 0 , stream_.Get() );
    BeginState_( TOKEN::JS_ELSE );
    if ( maybeElse->NodeType() == AstNode::kBlockStmt ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
      maybeElse->FirstChild()->Accept( this );
      writer_->WriteOp( '}' , CodeWriter::kElseBlockEnd , stream_.Get() );
    } else {
      if ( is_line_ ) {
        writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
      }
      maybeElse->Accept( this );
      if ( is_line_ ) {
        writer_->WriteOp( '}' , CodeWriter::kElseBlockEnd , stream_.Get() );
      }
    }
    EndLastState_();
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


void CodegenVisitor::ForProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode* exp = ast_node->Exp();
  writer_->WriteOp( TOKEN::JS_FOR , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    BeginState_( CodeWriter::kFor );
    writer_->WriteOp( TOKEN::JS_VAR , CodeWriter::kFor , stream_.Get() );
  }
  
  AstNode* index_exp = exp->FirstChild();
  AstNode* cond_exp = ( index_exp )? index_exp->NextSibling() : 0;
  AstNode* incr_exp = ( cond_exp )? cond_exp->NextSibling() : 0;

  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    VarListProcessor_( index_exp );
    EndLastState_();
  } else {
    index_exp->Accept( this );
  }
  stream_->Write( ';' );
  if ( cond_exp ) {
    cond_exp->Accept( this );
  }
  stream_->Write( ';' );
  if ( incr_exp ) {
    incr_exp->Accept( this );
  }
  writer_->WriteOp( ')' , 0 , stream_.Get() );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  }
}

void CodegenVisitor::ForInProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  bool is_dst = false;
  int for_in_type = ast_node->NodeType();
  bool is_each = ast_node->NodeType() == AstNode::kForEachWithVar;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode* exp = ast_node->Exp();
  writer_->WriteOp( TOKEN::JS_FOR , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  if ( for_in_type == AstNode::kForInWithVar || for_in_type == AstNode::kForEachWithVar ) {
    writer_->WriteOp( TOKEN::JS_VAR , CodeWriter::kFor , stream_.Get() );
  }
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();
  
  if ( for_in_type == AstNode::kForInWithVar || for_in_type == AstNode::kForEachWithVar ) {
    ValueNode* var = index_exp->CastToValue();
    if ( var ) {
      VarInitialiserProccessor_( index_exp->CastToValue() );
    }
  } else {
    index_exp->Accept( this );
  }
  
  writer_->WriteOp( TOKEN::JS_IN , 0 , stream_.Get() );
  target_exp->Accept( this );
  
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  ast_node->FirstChild()->Accept( this );
}



void CodegenVisitor::WhileProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode* exp = ast_node->Exp()->FirstChild();
  writer_->WriteOp( TOKEN::JS_WHILE , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  BeginState_( CodeWriter::kExpSp );
  exp->Accept( this );
  EndLastState_();
  writer_->WriteOp( ')' , 0 , stream_.Get() );

  AstNode* maybeBlock = ast_node->FirstChild();
  
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  }
}


void CodegenVisitor::DoWhileProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  
  AstNode* exp = ast_node->Exp()->FirstChild();
  AstNode* maybeBlock = ast_node->FirstChild();


  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_DO , 0 , stream_.Get() );
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
      maybeBlock->FirstChild()->Accept( this );
    } else {
      ast_node->FirstChild()->Accept( this );
    }
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
    }
  }

  writer_->WriteOp( TOKEN::JS_WHILE , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  exp->Accept( this );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


void CodegenVisitor::JumpStmt_( AstNode* ast_node , int type ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( type , 0 , stream_.Get() );
  AstNode* identifer = ast_node->FirstChild();
  if ( !identifer->IsEmpty() ) {
    ValueNode* value = identifer->CastToValue();
    writer_->Write( value->Symbol()->GetToken() , stream_.Get() );
  }
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
  JumpStmt_( ast_node , TOKEN::JS_CONTINUE );
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
  JumpStmt_( ast_node , TOKEN::JS_BREAK );
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_RETURN , 0 , stream_.Get() );
  AstNode* identifer = ast_node->FirstChild();
  identifer->Accept( this );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_WITH , 0 , stream_.Get() );
  ast_node->Exp()->Accept( this );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  }
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_SWITCH , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kSwitchEndBrace , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}

VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  if ( !exp->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_CASE , 0 , stream_.Get() );
    exp->Accept( this );
  } else {
    writer_->WriteOp( TOKEN::JS_DEFAULT , 0 , stream_.Get() );
  }
  writer_->WriteOp( ':' , CodeWriter::kCase , stream_.Get() );
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode *node = ast_node->FirstChild();
  node->Accept( this );
}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode* symbol = ast_node->FirstChild();
  AstNode* statement = symbol->NextSibling();
  writer_->Write( symbol->CastToValue()->Symbol()->GetToken() , stream_.Get() );
  writer_->WriteOp( ':' , 0 , stream_.Get() );
  statement->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_THROW , 0 , stream_.Get() );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  writer_->WriteOp( TOKEN::JS_TRY , 0 , stream_.Get() );
  AstNode* try_block = ast_node->FirstChild();
  writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
  try_block->FirstChild()->Accept( this );
  writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
  
  AstNode* catch_block = ast_node->Catch();
  AstNode* finally_block = ast_node->Finally();

  if ( !catch_block->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_CATCH , 0 , stream_.Get() );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    writer_->Write( catch_block->CastToValue()->Symbol()->GetToken() , stream_.Get() );
    writer_->WriteOp( ')',  0 , stream_.Get() );
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() ); 
    catch_block->FirstChild()->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
  }

  if ( !finally_block->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_FINALLY , 0 , stream_.Get() );
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() ); 
    finally_block->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
  }

  writer_->WriteOp( ';' , 0 , stream_.Get() );
}


void CodegenVisitor::ArrayAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  writer_->WriteOp( '[' , 0 , stream_.Get() );
  BeginState_( CodeWriter::kArgs );
  exp->Args()->Accept( this );
  EndLastState_();
  writer_->WriteOp( ']' , 0 , stream_.Get() );
}


void CodegenVisitor::DotAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  writer_->WriteOp( '.' , 0 , stream_.Get() );
  exp->Args()->Accept( this );
}

void CodegenVisitor::NewCallProccessor_( CallExp* exp ) {
  AstNode* args = exp->Args();
  if ( args->IsEmpty() ) {
    stream_->Write( '(' );
  }
  writer_->WriteOp( TOKEN::JS_NEW , 0 , stream_.Get() );
  exp->Callable()->Accept( this );

  if ( args->IsEmpty() ) {
    stream_->Write( ')' );
  } else {
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    NodeIterator iterator = exp->Args()->ChildNodes();
    BeginState_( CodeWriter::kArgs );
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        writer_->WriteOp( ',' , 0 , stream_.Get() );
      }
    }
    EndLastState_();
    writer_->WriteOp( ')' , 0 , stream_.Get() );
  }
}

void CodegenVisitor::NormalFunctionCall_( CallExp* exp ) {
  AstNode* args = exp->Args();
  exp->Callable()->Accept( this );
  if ( args->IsEmpty() ) {
    writer_->Write( "()" , stream_.Get() );
  } else {
    BeginState_( CodeWriter::kArgs );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    NodeIterator iterator = args->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        stream_->Write( ',' );
      }
    }
    EndLastState_();
    writer_->WriteOp( ')' , 0 , stream_.Get() );
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
  writer_->WriteOp( TOKEN::JS_NEW , 0 , stream_.Get() );
  ast_node->Constructor()->Accept( this );
}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ast_node->PostType() , 0 , stream_.Get() );
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  writer_->WriteOp( ast_node->Op() , 0 , stream_.Get() );
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , stream_.Get() );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL( CompareExp ) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , stream_.Get() );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  ast_node->Cond()->Accept( this );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( '?' , 0 , stream_.Get() );
  ast_node->True()->Accept( this );
  writer_->WriteOp( ':' , 0 , stream_.Get() );
  ast_node->False()->Accept( this );
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , stream_.Get() );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  if ( ast_node->IsParen() ) {
    BeginState_( CodeWriter::kParenExp );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
  }
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
    if ( iterator.HasNext() ) {
      writer_->WriteOp( ',' , 0 , stream_.Get() );
    }
  }
  if ( ast_node->IsParen() ) {
    writer_->WriteOp( ')' , 0 , stream_.Get() );
    EndLastState_();
  }
}


void CodegenVisitor::PrototypeMemberProccessor( NodeIterator& iterator , AstNode* name , bool is_private ) {
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next()->FirstChild();
    ValueNode* val = node->CastToValue();
    if ( node->NodeType() == AstNode::kNodeList ) {
      NodeIterator iter = node->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* item = iter.Next();
        if ( !is_private ) {
          name->Accept( this );
          stream_->Write( ".prototype." );
          item->Accept( this );
          writer_->WriteOp( ';' , 0 , stream_.Get() );
        } else {
          stream_->Write( "__MC_Runtime_.__class_prop_def" );
          writer_->WriteOp( '(' , 0 , stream_.Get() );
          stream_->Write( "this" );
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          stream_->Write( '"' );
          stream_->Write( item->CastToValue()->Symbol()->GetToken() );
          stream_->Write( '"' );
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          if ( item->ChildLength() > 0 && !item->FirstChild()->IsEmpty() ) {
            item->FirstChild()->Accept( this );
          } else {
            stream_->Write( "undefined" );
          }
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          if ( is_private ) {
            stream_->Write( "true" );
          } else {
            stream_->Write( "false" );
          }
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          stream_->Write( "false" );
          writer_->WriteOp( ')' , 0 , stream_.Get() );
          writer_->WriteOp( ';' , 0 , stream_.Get() );
        }
      }
    } else if ( val && val->ValueType() == ValueNode::kConstant ) {
      NodeIterator iter = val->Node()->ChildNodes();
      while ( iter.HasNext() ) {
        ValueNode* item = iter.Next()->CastToValue();
        if ( item ) {
          stream_->Write( "__MC_Runtime_.__proto_member_def" );
          writer_->WriteOp( '(' , 0 , stream_.Get() );
          name->Accept( this );
          stream_->Write( ".prototype" );
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          if ( item->ValueType() == ValueNode::kVariable ) {
            stream_->Write( '"' );
            stream_->Write( item->Symbol()->GetToken() );
            stream_->Write( '"' );
            writer_->WriteOp( ',' , 0 , stream_.Get() );
            if ( item->ChildLength() > 0 && !item->FirstChild()->IsEmpty() ) {
              item->FirstChild()->Accept( this );
            } else {
              stream_->Write( "undefined" );
            }
          }
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          if ( is_private ) {
            stream_->Write( "true" );
          } else {
            stream_->Write( "false" );
          }
          writer_->WriteOp( ',' , 0 , stream_.Get() );
          stream_->Write( "true" );
          writer_->WriteOp( ')' , 0 , stream_.Get() );
          writer_->WriteOp( ';' , 0 , stream_.Get() );
        }
      }
    } else if ( node->NodeType() == AstNode::kFunction ) {
      if ( !is_private ) {
        name->Accept( this );
        stream_->Write( ".prototype." );
        Function *fn = reinterpret_cast<Function*>( node );
        fn->Name()->Accept( this );
        writer_->WriteOp( '=' , 0 , stream_.Get() );
        fn->Accept( this );
      } else {
        stream_->Write( "__MC_Runtime_.__proto_member_def_" );
        writer_->WriteOp( '(' , 0 , stream_.Get() );
        name->Accept( this );
        stream_->Write( ".prototype." );
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        Function *fn = reinterpret_cast<Function*>( node );
        writer_->WriteOp( '"' , 0 , stream_.Get() );
        fn->Name()->Accept( this );
        writer_->WriteOp( '"' , 0 , stream_.Get() );
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        fn->Accept( this );
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        if ( is_private ) {
          stream_->Write( "true" );
        } else {
          stream_->Write( "false" );
        }
        writer_->WriteOp( ')' , 0 , stream_.Get() );
      }
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  }
}


void CodegenVisitor::StaticMemberProccessor( NodeIterator& iterator , AstNode* name ) {
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next()->FirstChild();
    ValueNode* val = node->CastToValue();
    if ( node->NodeType() == AstNode::kNodeList ) {
      NodeIterator iter = node->ChildNodes();
      while ( iter.HasNext() ) {
        name->Accept( this );
        stream_->Write( "." );
        iter.Next()->Accept( this );
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
    } else if ( val && val->ValueType() == ValueNode::kConstant ) {
      NodeIterator iter = val->Node()->ChildNodes();
      while ( iter.HasNext() ) {
        name->Accept( this );
        stream_->Write( "." );
        iter.Next()->Accept( this );
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
    } else if ( node->NodeType() == AstNode::kFunction ) {
      name->Accept( this );
      stream_->Write( "." );
      Function *fn = reinterpret_cast<Function*>( node );
      fn->Name()->Accept( this );
      writer_->WriteOp( '=' , 0 , stream_.Get() );
      node->Accept( this );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  } 
}


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  current_class_ = ast_node;
  bool is_decl = ast_node->Decl();
  AstNode* body = ast_node->Body();
  ClassProperties* prop = reinterpret_cast<ClassProperties*>( body );
  AstNode* constructor = prop->Constructor();
  printf( "decl = %d\n" , is_decl );
  writer_->WriteOp( TOKEN::JS_FUNCTION , 0 , stream_.Get() );
  ast_node->Name()->Accept( this );
  stream_->Write( "()" );
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );

  if ( constructor ) {
    Function* fn = reinterpret_cast<Function*>( prop->Constructor() );
    fn->Accept( this );
  }

  ast_node->Name()->Accept( this );
  stream_->Write( ".__MC_init_.apply" );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  stream_->Write( "this" );
  writer_->WriteOp( ',' , 0 , stream_.Get() );
  stream_->Write( "arguments" );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
  stream_->Write( "__MC_Runtime_.__fix" );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  stream_->Write( "this" );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
  writer_->WriteOp( '}' , CodeWriter::kFunctionEndBrace , stream_.Get() );
  if ( is_decl ) {
    writer_->WriteOp( ';' , 0 , stream_.Get() );
    stream_->Write( "__MC_Runtime_.__unenum(" );
    ast_node->Name()->Accept( this );
    writer_->WriteOp( ',' , 0 , stream_.Get() );
    stream_->Write( "'__MC_init_'" );
    writer_->WriteOp( ',' , 0 , stream_.Get() );
    if ( constructor ) {
      constructor->FirstChild()->Accept( this );
    } else {
      stream_->Write( "__MC_Runtime_.__noop" );
    }
    writer_->WriteOp( ')' , 0 , stream_.Get() );
    writer_->WriteOp( ';' , 0 , stream_.Get() );

    AstNode* node = prop->Prototype();
    if ( node->ChildLength() > 0 ) {
      NodeIterator pr_iterator = node->ChildNodes();
      PrototypeMemberProccessor( pr_iterator , ast_node->Name() , false );
    }

    node = prop->Public();
    if ( node->ChildLength() > 0 ) {
      NodeIterator pb_iterator = node->ChildNodes();
      PrototypeMemberProccessor( pb_iterator , ast_node->Name() , false );
    }

    node = prop->Private();
    if ( node->ChildLength() > 0 ) {
      NodeIterator pv_iterator = node->ChildNodes();
      PrototypeMemberProccessor( pv_iterator , ast_node->Name() , true );
    }

    node = prop->Static();
    if ( node->ChildLength() > 0 ) {
      NodeIterator st_iterator = node->ChildNodes();
      StaticMemberProccessor( st_iterator , ast_node->Name() );
    }
    
  }
  if ( !body->IsEmpty() ) {
    body->Accept( this );
  }
}

VISITOR_IMPL(ClassProperties) {
  
}

VISITOR_IMPL(ClassExpandar) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL(ClassMember) {
  PRINT_NODE_NAME;
  AstNode* node = ast_node->FirstChild();
  ValueNode* maybeConstant = ast_node->CastToValue();
  if ( node->NodeType() == AstNode::kNodeList ) {
    NodeIterator iterator = node->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* maybeValue = iterator.Next();
      if ( !maybeValue->IsEmpty() ) {
        ValueNode *val = maybeValue->CastToValue();
        if ( val ) {
          if ( ast_node->Attr() == ClassMember::kPublic ) {
            stream_->Write( "this." );
            if ( val->ValueType() == ValueNode::kVariable ) {
              stream_->Write( val->Symbol()->GetToken() );
              if ( !val->FirstChild()->IsEmpty() ) {
                writer_->WriteOp( '=' , 0 , stream_.Get() );
                val->FirstChild()->Accept( this );
              }
            }
            writer_->WriteOp( ';' , 0 , stream_.Get() );
          } else {
            stream_->Write( "__MC_Runtime_.__inst_prop_def" );
            writer_->WriteOp( '(' , 0 , stream_.Get() );
            stream_->Write( "this" );
            writer_->WriteOp( ',' , 0 , stream_.Get() );
            if ( val->ValueType() == ValueNode::kVariable ) {
              stream_->Write( '"' );
              stream_->Write( val->Symbol()->GetToken() );
              stream_->Write( '"' );
              writer_->WriteOp( ',' , 0 , stream_.Get() );
              if ( !val->FirstChild()->IsEmpty() ) {
                val->FirstChild()->Accept( this );
              } else {
                stream_->Write( "undefined" );
              }
            }
            writer_->WriteOp( ',' , 0 , stream_.Get() );
            stream_->Write( "true" );
            writer_->WriteOp( ',' , 0 , stream_.Get() );
            stream_->Write( "true" );
            writer_->WriteOp( ')' , 0 , stream_.Get() );
            writer_->WriteOp( ';' , 0 , stream_.Get() );
          }
        }
      }
    }
  } else if ( maybeConstant && maybeConstant->ValueType() == ValueNode::kConstant ) {
    NodeIterator iter = maybeConstant->Node()->ChildNodes();
    while ( iter.HasNext() ) {
      ValueNode* item = iter.Next()->CastToValue();
      if ( item ) {
        stream_->Write( "__MC_Runtime_.__inst_prop_def" );
        writer_->WriteOp( '(' , 0 , stream_.Get() );
        stream_->Write( "this" );
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        stream_->Write( '"' );
        item->Accept( this );
        stream_->Write( '"' );
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        if ( item->ChildLength() > 0 && !item->FirstChild()->IsEmpty() ) {
          item->FirstChild()->Accept( this );
        } else {
          stream_->Write( "undefined" );
        }
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        if ( ast_node->Attr() == ClassMember::kPrivate ) {
          stream_->Write( "true" );
        } else {
          stream_->Write( "false" );
        }
        writer_->WriteOp( ',' , 0 , stream_.Get() );
        stream_->Write( "true" );
        writer_->WriteOp( ')' , 0 , stream_.Get() );
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
    }
  } 
}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  writer_->WriteOp( TOKEN::JS_FUNCTION , 0 , stream_.Get() );
  if ( !ast_node->Name()->IsEmpty() ) {
    writer_->Write( ast_node->Name()->CastToValue()->Symbol()->GetToken() , stream_.Get() );
  }
  if ( ast_node->Argv()->IsEmpty() ) {
    stream_->Write( "()" );
  } else {
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    NodeIterator iterator = ast_node->Argv()->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        stream_->Write( ',' );
      }
    }
    writer_->WriteOp( ')' , 0 , stream_.Get() );
  }
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );
  int child_length = ast_node->Argv()->ChildLength();
  
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->SetFileName( stream_.Get() );
  if ( ast_node->FunctionType() == Function::kNormal ) {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* node = iterator.Next();
      if ( !node->IsEmpty() ) {
        node->Accept( this );
      }
    }
  } else if ( ast_node->FunctionType() == Function::kShorten ) {
    stream_->Write( "return " );
    ast_node->FirstChild()->Accept( this );
    writer_->WriteOp( ';' , 0 , stream_.Get() );
  }
  int state = CurrentState_();
  if ( ast_node->ContextType() == Function::kGlobal ) {
    state = ( state == CodeWriter::kArgs )? state :
        ( MatchState_( CodeWriter::kParenExp ) )? CodeWriter::kArgs : CodeWriter::kFunctionEndBrace;
    writer_->WriteOp( '}' , state , stream_.Get() );
  } else {
    writer_->WriteOp( '}' , CodeWriter::kArgs , stream_.Get() );
    stream_->Write( ".bind" );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    stream_->Write( "this" );
    writer_->WriteOp( ')' , 0 , stream_.Get() );
  }
};


void CodegenVisitor::ArrayProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '[' , 0 , stream_.Get() );
  AstNode* list_child = ast_node->FirstChild();
  while ( list_child ) {
    if ( list_child->IsEmpty() ) {
      stream_->Write( ',' );
    } else {
      NodeIterator iter = list_child->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        if ( !element->IsEmpty() ) {
          element->Accept( this );
        }
        if ( iter.HasNext() ) {
          stream_->Write( ',' );
        }
      }
      if ( list_child->HasNext() ) {
        list_child = list_child->NextSibling();
      } else {
        break;
      }
    }
  }
  writer_->WriteOp( ']' , 0 , stream_.Get() );
}


void CodegenVisitor::ObjectProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( element_list->IsEmpty() ) {
    stream_->Write( "{}" );
  } else {
    writer_->WriteOp( '{' , CodeWriter::kArgs , stream_.Get() );
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( this );
      writer_->WriteOp( ':' , 0 , stream_.Get() );
      element->FirstChild()->Accept( this );
      if ( iterator.HasNext() ) {
        writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
      }
    }
    writer_->WriteOp( '}' , CodeWriter::kArgs , stream_.Get() );
  }
}


void CodegenVisitor::VarInitialiserProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  if ( ast_node->ValueType() == ValueNode::kVariable ) {
    const char* ident = ast_node->Symbol()->GetToken();
    writer_->Write( ident ,  stream_.Get() );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( !initialiser->IsEmpty() ) {
    writer_->WriteOp( '=' , 0 , stream_.Get() );
    initialiser->Accept( this );
  }
}


VISITOR_IMPL( ValueNode ) {
  switch ( ast_node->ValueType() ) {
    case ValueNode::kArray :
      printf( "Array\n" );
      ArrayProccessor_( ast_node );
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
      break;

    case ValueNode::kRest :
      printf( "Rest\n" );
      rest_name_ = ast_node->Symbol()->GetToken();
      break;
      
    default :
      const char* symbol = ast_node->Symbol()->GetToken();
      if ( symbol[ 0 ] == '@' ) {
        std::string tmp = symbol;
        if ( strlen( symbol ) > 1 ) {
          stream_->Write( "this." );
          tmp.erase( 0 , 1 );
        } else {
          stream_->Write( "this" );
        }
        stream_->Write( tmp.c_str() );
      } else {
        stream_->Write( symbol );
      }
  }
}

void CodegenVisitor::BeginState_( int state ) {
  state_.push_back( state );
}

void CodegenVisitor::EndLastState_() {
  state_.pop_back();
}

int CodegenVisitor::CurrentState_() {
  return ( state_.size() > 0 )? state_.back() : 0;
}

bool CodegenVisitor::MatchState_( int state ) {
  std::vector<int>::iterator begin = state_.begin(),end = state_.end();
  while ( begin != end ) {
    if ( (*begin) == state ) {
      return true;
    }
    ++begin;
  }
  return false;
}


}

