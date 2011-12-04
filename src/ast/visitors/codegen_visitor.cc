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
    tmp_index_( 0 ),is_line_( false ),
    has_dst_( false ),has_rest_( false ),
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
  StrHandle key = FileSystem::GetModuleKey( current_root_->FileName() );
  AstNode* name = ast_node->Name();
  bool is_anony = name->IsEmpty();
  if ( !is_anony ) {
    writer_->ModuleBeginProccessor( key.Get() , name->CastToValue()->Symbol()->GetToken() , stream_.Get() );
  } else {
    writer_->AnonymousModuleBeginProccessor( key.Get() , stream_.Get() );
  }
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  AstNode* maybeBlock = ast_node->FirstChild();
  printf( "module child type = %d\n" , maybeBlock->NodeType() );
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    maybeBlock->FirstChild()->Accept( this );
  } else {
    maybeBlock->Accept( this );
  }
  if ( !is_anony ) {
    writer_->ModuleEndProccessor( stream_.Get() );
  } else {
    writer_->AnonymousModuleEndProccessor( stream_.Get() );
  }
}



VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
  AstNode *node = ast_node->FirstChild();
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->Write( "__export__." , stream_.Get() );
  if ( node->NodeType() == AstNode::kFunction ) {
    Function* fn = reinterpret_cast<Function*>( node );
    writer_->Write( fn->Name()->CastToValue()->Symbol()->GetToken() , stream_.Get() );
    writer_->WriteOp( '=' , 0 , stream_.Get() );
    fn->Accept( this );
  } else if ( node->NodeType() == AstNode::kValueNode ) {
    ValueNode *value = node->CastToValue();
    VarInitialiserProccessor_( value );
    if ( value->FirstChild()->IsEmpty() ) {
      writer_->WriteOp( '=' , 0 , stream_.Get() );
      writer_->Write( value->Symbol()->GetToken() , stream_.Get() );
    }
  }
  writer_->WriteOp( ';' , 0 , stream_.Get() );
}



VISITOR_IMPL( ImportStmt ) {
  PRINT_NODE_NAME;
  int var_type = ast_node->VarType();
  if ( var_type == ImportStmt::kVar ) {
    writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    stream_->Write( ast_node->Exp()->CastToValue()->Symbol()->GetToken() );
    writer_->WriteOp( '=' , 0 , stream_.Get() );
  } else if ( var_type == ImportStmt::kDst ) {
    writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    ast_node->Exp()->Accept( this );
    writer_->WriteOp( '=' , 0 , stream_.Get() );
  }

  
  if ( ast_node->ModType() == ImportStmt::kFile ) {
    stream_->Write( "__global_export__" );
    writer_->WriteOp( '[' , 0 , stream_.Get() );
    stream_->Write( ast_node->ModKey()->GetToken() );
    writer_->WriteOp( ']' , 0 , stream_.Get() );
  } else {
    stream_->Write( "__export__" );
  }

  NodeIterator iterator = ast_node->From()->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    ValueNode* value = node->CastToValue();
    if ( value && value->ValueType() == ValueNode::kIdentifier ) {
      stream_->Write( '.' );
      stream_->Write( value->Symbol()->GetToken() );
    }
  }

  if ( var_type == ImportStmt::kDst ) {
    if ( dst_code_list_.size() > 0 ) {
      writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
      DstCodeProccessor_();
    }
  }
  writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
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
      if ( value && ( value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) ) {
        item->CastToValue()->Node()->Accept( this );
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          writer_->WriteOp( '=' , 0 , stream_.Get() );
          initialiser->Accept( this );
          if ( CurrentState_() == CodeWriter::kFor ) {
            stream_->Write( ',' );
          } else {
            writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
          }
        }
        DstCodeProccessor_();
      } else {
        item->Accept( this );
      }
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
  CodeBuffer tmp_buffer_;
  stream_->SwitchBuffer( &tmp_buffer_ );
  writer_->SetLine( ast_node->Line() , stream_.Get() );
  ast_node->FirstChild()->Accept( this );
  writer_->WriteOp( ';' , 0 , stream_.Get() );
  stream_->SwitchBuffer();
  if ( has_dst_ ) {
    std::vector<Handle<DstCodeContainer> >::iterator ITERATOR( dst_code_list_ );
    writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    while ( begin != end ) {
      stream_->Write( (*begin)->GetRef() );
      ++begin;
      if ( begin != end ) {
        writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
      }
    }
    writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
    stream_->Write( tmp_buffer_.GetData() );
    DstCodeProccessor_();
    writer_->WriteOp( ';' , 0 , stream_.Get() );
  } else {
    stream_->Write( tmp_buffer_.GetData() );
  }
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
      if ( var->ValueType() == ValueNode::kDst ) {
        is_dst = true;
        var->Node()->Accept( this );
      } else {
        VarInitialiserProccessor_( index_exp->CastToValue() );
      }
    }
  } else {
    index_exp->Accept( this );
    if ( has_dst_ == true ) {
      is_dst = true;
      has_dst_ = false;
    }
  }
  
  writer_->WriteOp( TOKEN::JS_IN , 0 , stream_.Get() );
  target_exp->Accept( this );
  
  writer_->WriteOp( ')' , 0 , stream_.Get() );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    if ( is_dst ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
      if ( is_each ) {
        stream_->Write( tmp_ref_ );
        writer_->WriteOp( '=' , 0 , stream_.Get() );
        target_exp->Accept( this );
        writer_->WriteOp( '[' , 0 , stream_.Get() );
        stream_->Write( tmp_ref_ );
        writer_->WriteOp( ']' , 0 , stream_.Get() );
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
      writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
      DstCodeProccessor_();
      writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
      ast_node->FirstChild()->FirstChild()->Accept( this );
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    } else {
      if ( is_line_ || is_each ) {
        goto NO_BLOCK;
      }
      ast_node->FirstChild()->Accept( this );
    }
  } else {
 NO_BLOCK :
    if ( is_line_ || is_dst || is_each ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
      if ( is_dst ) {
        writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
        if ( is_each ) {
          stream_->Write( tmp_ref_ );
          writer_->WriteOp( '=' , 0 , stream_.Get() );
          target_exp->Accept( this );
          writer_->WriteOp( ';' , 0 , stream_.Get() );
        }
        DstCodeProccessor_();
        writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
      } else if ( is_each ) {
        index_exp->Accept( this );
        writer_->WriteOp( '=' , 0 , stream_.Get() );
        target_exp->Accept( this );
        writer_->WriteOp( '[' , 0 , stream_.Get() );
        index_exp->Accept( this );
        writer_->WriteOp( ']' , 0 , stream_.Get() );
        writer_->WriteOp( ';' , 0 , stream_.Get() );
      }
    }
    if ( ast_node->FirstChild()->NodeType() == AstNode::kBlockStmt ) {
      ast_node->FirstChild()->FirstChild()->Accept( this );
    } else {
      ast_node->FirstChild()->Accept( this );
    }
    if ( is_line_ || is_dst || is_each ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , stream_.Get() );
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
  }
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
  
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt && !has_dst_ ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    }
    if ( has_dst_ ) {
      DstCodeProccessor_();
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
  CodeBuffer tmp_buffer_;
  stream_->SwitchBuffer( &tmp_buffer_ );
  AstNode* exp = ast_node->Exp()->FirstChild();
  AstNode* maybeBlock = ast_node->FirstChild();

  writer_->WriteOp( TOKEN::JS_WHILE , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  exp->Accept( this );
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( ';' , 0 , stream_.Get() );

  stream_->SwitchBuffer( &default_buffer_ );
  
  if ( has_dst_ ) {
    writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    stream_->Write( tmp_ref_ );
    writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
  }

  writer_->SetLine( ast_node->Line() , stream_.Get() );
  writer_->WriteOp( TOKEN::JS_DO , 0 , stream_.Get() );
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt || has_dst_ ) {
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , stream_.Get() );
    if ( has_dst_ ) {
      DstCodeProccessor_();
      writer_->WriteOp( ';' , 0 , stream_.Get() );
    }
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
  
  stream_->Write( tmp_buffer_.GetData() );
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
  ResetDstArray_();
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
  ResetDstArray_();
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
  ResetDstArray_();
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
  bool has_dst;
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
    if ( has_rest_ ) {
      stream_->Erase( stream_->Size() - 1 , stream_->Size() );
    }
    writer_->WriteOp( ')' , 0 , stream_.Get() );
  }
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , stream_.Get() );
  if ( has_dst_ ) {
    writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    DstCodeProccessor_();
    has_dst = true;
  }
  int child_length = ast_node->Argv()->ChildLength();
  if ( has_rest_ ) {
    char tmp[20];
    sprintf( tmp , "%d" , ( ( child_length > 0 )? child_length - 1 : 0 ) );
    if ( has_dst ) {
      writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
    } else {
      writer_->WriteOp( TOKEN::JS_VAR , 0 , stream_.Get() );
    }
    stream_->Write( rest_name_ );
    writer_->WriteOp( '=' , 0 , stream_.Get() );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    stream_->Write( "arguments.length" );
    writer_->WriteOp( '>' , 0 , stream_.Get() );
    stream_->Write( tmp );
    writer_->WriteOp( ')' , 0 , stream_.Get() );
    writer_->WriteOp( '?' , 0 , stream_.Get() );
    stream_->Write( "Array.prototype.slice.call" );
    writer_->WriteOp( '(' , 0 , stream_.Get() );
    stream_->Write( "arguments" );
    if ( child_length  > 0 ) {
      stream_->Write( ',' );
      stream_->Write( tmp );
    }
    writer_->WriteOp( ')' , 0 , stream_.Get() );
    writer_->WriteOp( ':' , 0 , stream_.Get() );
    stream_->Write( "[]" );
  }
  if ( has_rest_ || has_dst_ ) {
    writer_->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
    has_rest_ = false;
  }
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


void CodegenVisitor::CreateDstAssignment_( const char* name ) {
  CodeBuffer tmp_buffer_;
  std::string last;
  std::string char_at_tmp_ret;
  std::vector<std::string>::iterator ITERATOR( dst_accessor_ );
  stream_->SwitchBuffer( &tmp_buffer_ );
  stream_->Write( name );
  writer_->WriteOp( '=' , 0 , stream_.Get() );
  writer_->WriteOp( '(' , 0 , stream_.Get() );
  bool is_char_at = false;
  bool is_char_at_last = false;
  while ( begin != end ) {
    if ( (*begin)[0] == '[' && isdigit( (*begin)[1] ) ) {
      std::string tmp_accessor = (*begin);
      writer_->WriteOp( '(' , 0 , stream_.Get() );
      if ( !is_char_at ) {
        char_at_tmp_ret += "__MC_tmp__";
      }
      stream_->Write( char_at_tmp_ret );
      writer_->WriteOp( '=' , 0 , stream_.Get() );
      writer_->WriteOp( '(' , 0 , stream_.Get() );
      stream_->Write( ( is_char_at )? char_at_tmp_ret : tmp_ref_ );
      if ( !is_char_at_last ) {
        stream_->Write( last );
      }
      stream_->Write( (*begin) );
      writer_->WriteOp( TOKEN::JS_LOGICAL_OR , 0 , stream_.Get() );
      writer_->WriteOp( '(' , 0 , stream_.Get() );
      stream_->Write( ( is_char_at )? char_at_tmp_ret : tmp_ref_ );
      if ( !is_char_at_last ) {
        stream_->Write( last );
      }
      stream_->Write( ".charAt" );
      writer_->WriteOp( TOKEN::JS_LOGICAL_AND , 0 , stream_.Get() );
      stream_->Write( ( is_char_at )? char_at_tmp_ret : tmp_ref_ );
      if ( !is_char_at_last ) {
        stream_->Write( last );
      }
      stream_->Write( ".charAt" );
      writer_->WriteOp( '(' , 0 , stream_.Get() );
      tmp_accessor.erase( 0 , 1 );
      tmp_accessor.erase( tmp_accessor.size() - 1 , tmp_accessor.size() );
      stream_->Write( tmp_accessor );
      writer_->WriteOp( ')' , 0 , stream_.Get() );
      writer_->WriteOp( ')' , 0 , stream_.Get() );
      writer_->WriteOp( ')' , 0 , stream_.Get() );
      writer_->WriteOp( ')' , 0 , stream_.Get() );
      is_char_at = true;
      is_char_at_last = true;
    } else {
      if ( !is_char_at ) {
        stream_->Write( tmp_ref_ );
      } else {
        stream_->Write( char_at_tmp_ret );
      }

      if ( !is_char_at_last ) {
        last += (*begin);
        stream_->Write( last );
      } else {
        last = (*begin);
        stream_->Write( (*begin) );
      }
      is_char_at_last = false;
    }
    ++begin;
    if ( begin != end ) {
      writer_->WriteOp( TOKEN::JS_LOGICAL_AND , 0 , stream_.Get() );
    }
  }
  
  writer_->WriteOp( ')' , 0 , stream_.Get() );
  writer_->WriteOp( '?' , 0 , stream_.Get() );

  if ( !is_char_at ) {
    stream_->Write( tmp_ref_ );
  } else {
    stream_->Write( char_at_tmp_ret );
  }

  if ( !is_char_at_last ) {
    stream_->Write( last );
  }
  
  writer_->WriteOp( ':' , 0 , stream_.Get() );
  stream_->Write( "undefined" );
  std::string ret = stream_->Get()->GetData();
  dst_code_list_.back()->Push( &ret );
  printf( "size = %d, %s\n" , dst_code_list_.back()->GetCodeList().size() , name );
  stream_->SwitchBuffer();
}


void CodegenVisitor::DstArrayProccessor_( ValueNode* ast_node , int depth ) {
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
            char tmp[ 100 ];
            sprintf( tmp , "[%d]" , index );
            dst_accessor_.push_back( tmp );
            if ( elem->ValueType() == ValueNode::kIdentifier ) {
              CreateDstAssignment_( elem->Symbol()->GetToken() );
              dst_accessor_.pop_back();
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
  if ( depth == 0 ) {
    dst_accessor_.clear();
  } else {
    dst_accessor_.pop_back();
  }
}


void CodegenVisitor::DstMemberProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  TokenInfo* info = ast_node->Symbol();
  switch( info->GetType() ) {
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
      
  }
}


void CodegenVisitor::DstObjectProcessor_( ValueNode* ast_node , int depth ) {
  PRINT_NODE_NAME;
  AstNode* child = ast_node->Node();
  int value_type = ast_node->ValueType();
  printf( "child length = %d %d\n" , ast_node->ChildLength() , depth );
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
                CreateDstAssignment_( prop->Symbol()->GetToken() );
              }
            }
          } else {
            TokenInfo *info = value->Symbol();
            const char* name = info->GetToken();
            char tmp[ 100 ];
            sprintf( tmp , ".%s" , name );
            printf( "%s\n" , name );
            dst_accessor_.push_back( tmp );
            CreateDstAssignment_( name );
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
    if ( depth == 0 ) {
      dst_accessor_.clear();
    } else {
      dst_accessor_.pop_back();
    }
  }
}


void CodegenVisitor::DstProcessor_( ValueNode* ast_node ) {
  char tmp[ 20 ];
  Handle<DstCodeContainer> container( new DstCodeContainer );
  container->SetRef( tmp_index_ );
  dst_code_list_.push_back( container );
  sprintf( tmp , "__tmp__%d" , tmp_index_ );
  tmp_ref_ = tmp;
  tmp_index_++;
  stream_->Write( tmp_ref_.c_str() );
  if ( ast_node->ValueType() == ValueNode::kDstArray ) {
    DstArrayProccessor_( ast_node , 0 );
  } else {
    DstObjectProcessor_( ast_node , 0 );
  }
}


void CodegenVisitor::DstCodeProccessor_() {
  std::vector<Handle<DstCodeContainer> >::iterator ITERATOR( dst_code_list_ );
  printf( "dst size %d\n" , dst_code_list_.size() );
  while ( begin != end ) {
    std::vector<std::string> codes = (*begin)->GetCodeList();
    std::vector<std::string>::iterator code_begin = codes.begin();
    std::vector<std::string>::iterator code_end = codes.end();
    printf( "dst size %d\n" , codes.size() );
    while ( code_begin != code_end ) {
      stream_->Write( (*code_begin) );
      ++code_begin;
      if ( code_begin != code_end ) {
        if ( CurrentState_() == CodeWriter::kFor ) {
          stream_->Write( ',' );
        } else {
          writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
        }
      }
    }
    ++begin;
    if ( begin != end ) {
      writer_->WriteOp( ',' , CodeWriter::kVarsComma , stream_.Get() );
    }
  }
  ResetDstArray_();
}

void CodegenVisitor::ResetDstArray_() {
  has_dst_ = false;
  dst_code_.clear();
  dst_accessor_.clear();
  dst_code_list_.clear();
  tmp_ref_.clear();
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
      has_dst_ = true;
      DstProcessor_( ast_node );
      break;

    case ValueNode::kRest :
      printf( "Rest\n" );
      has_rest_ = true;
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

