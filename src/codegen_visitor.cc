#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include "scope.h"
#include "token_info.h"
#include "codegen_visitor.h"
#include "managed_handle.h"
#include "ast.h"
#include "grammar.tab.hh"
#include "codewriter.h"
#include "file_system.h"

namespace mocha {

#define TOKEN yy::ParserImplementation::token
#define VISITOR_IMPL(type) void CodegenVisitor::Accept##type( type* ast_node )
#define ITERATOR(name) begin = name.begin(),end = name.end()
#define PRINT_NODE_NAME ast_node->PrintNodeName()
#define ACCEPT( ast )                           \
  if ( ast != 0 )                               \
    ast->Accept(this)



CodegenVisitor::CodegenVisitor( Options* option ) :
    tmp_index_( 0 ),is_line_( false ) , writer_( new CodeWriter( option->IsPrettyPrint() , option->IsEmbedLine() ) ){}


VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  buffer_ += "(function()";
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , buffer_ );
  writer_->InsertDebugSymbol( buffer_ );
  buffer_ += "var __global_export__ = {}";
  writer_->WriteOp( ';' , 0 , buffer_ );
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kArgs , buffer_ );
  buffer_ += ")()";
  writer_->WriteOp( ';' , 0 , buffer_ );
}


VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  buffer_ += "(function()";
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , buffer_ );
  writer_->InitializeFileName( ast_node->FileName() , buffer_ );
  current_root_ = ast_node;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kArgs , buffer_ );
  buffer_ += ")()";
  writer_->WriteOp( ';' , 0 , buffer_ );
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
  AstNode* node_list = ast_node->FirstChild();
  if ( !node_list->IsEmpty() ) {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
    }
  }
  writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
  writer_->WriteOp( ';' , 0 , buffer_ );
}



VISITOR_IMPL( ModuleStmt ) {
  PRINT_NODE_NAME;
  StrHandle key = FileSystem::GetModuleKey( current_root_->FileName() );
  writer_->ModuleBeginProccessor( key.Get() , ast_node->Name()->Symbol()->GetToken() , buffer_ );
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* maybeBlock = ast_node->FirstChild();
  printf( "module child type = %d\n" , maybeBlock->NodeType() );
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    maybeBlock->FirstChild()->Accept( this );
  } else {
    maybeBlock->Accept( this );
  }
  writer_->ModuleEndProccessor( buffer_ );
}



VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
  AstNode *node = ast_node->FirstChild();
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->Write( "__export__." , buffer_ );
  if ( node->NodeType() == AstNode::kFunction ) {
    Function* fn = reinterpret_cast<Function*>( node );
    writer_->Write( fn->Name()->CastToValue()->Symbol()->GetToken() , buffer_ );
    writer_->WriteOp( '=' , 0 , buffer_ );
    fn->Accept( this );
  } else if ( node->NodeType() == AstNode::kValueNode ) {
    ValueNode *value = node->CastToValue();
    VarInitialiserProccessor_( value );
    if ( value->FirstChild()->IsEmpty() ) {
      writer_->WriteOp( '=' , 0 , buffer_ );
      writer_->Write( value->Symbol()->GetToken() , buffer_ );
    }
  }
  writer_->WriteOp( ';' , 0 , buffer_ );
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
      if ( value && value->ValueType() == ValueNode::kDst || value->ValueType() == ValueNode::kDstArray ) {
        item->Accept( this );
        buffer_ += tmp_ref_;
        AstNode* initialiser = item->FirstChild();
        if ( !initialiser->IsEmpty() ) {
          writer_->WriteOp( '=' , 0 , buffer_ );
          initialiser->Accept( this );
          if ( CurrentState_() == CodeWriter::kFor ) {
            buffer_ += ',';
          } else {
            writer_->WriteOp( ',' , CodeWriter::kVarsComma , buffer_ );
          }
        }
        std::vector<std::string>::iterator ITERATOR( dst_code_ );
        while ( begin != end ) {
          buffer_ += (*begin);
          ++begin;
          if ( begin != end ) {
            if ( CurrentState_() == CodeWriter::kFor ) {
              buffer_ += ',';
            } else {
              writer_->WriteOp( ',' , CodeWriter::kVarsComma , buffer_ );
            }
          }
        }
        tmp_ref_.clear();
        dst_code_.clear();
        dst_accessor_.clear();
      } else {
        item->Accept( this );
      }
      if ( iterator.HasNext() ) {
        if ( CurrentState_() == CodeWriter::kFor ) {
          buffer_ += ',';
        } else {
          writer_->WriteOp( ',' , CodeWriter::kVarsComma , buffer_ );
        }
      } else if ( CurrentState_() != CodeWriter::kFunctionEndBrace ) {
        if ( CurrentState_() != CodeWriter::kFor ) {
          writer_->WriteOp( ';' , CodeWriter::kVarsEnd , buffer_ );
        }
      }
    }
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( TOKEN::JS_VAR , 0 , buffer_ );
  VarListProcessor_( ast_node );
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  ast_node->FirstChild()->Accept( this );
  writer_->WriteOp( ';' , 0 , buffer_ );
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  if ( !MatchState_( TOKEN::JS_ELSE ) ) {
    writer_->SetLine( ast_node->Line() , buffer_ );
  }
  writer_->WriteOp( TOKEN::JS_IF , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ')' , 0 , buffer_ );
  AstNode* maybeBlock = ast_node->Then();
  AstNode* maybeElse = ast_node->Else();
  
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    maybeBlock->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
    if ( maybeElse->IsEmpty() ) {
      writer_->WriteOp( ';' , 0 , buffer_ );
    }
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->Then()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
      if ( maybeElse->IsEmpty() ) {
        writer_->WriteOp( ';' , 0 , buffer_ );
      }
    }
  }
  
  if ( !maybeElse->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_ELSE , 0 , buffer_ );
    BeginState_( TOKEN::JS_ELSE );
    if ( maybeElse->NodeType() == AstNode::kBlockStmt ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
      maybeElse->FirstChild()->Accept( this );
      writer_->WriteOp( '}' , CodeWriter::kElseBlockEnd , buffer_ );
    } else {
      if ( is_line_ ) {
        writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
      }
      maybeElse->Accept( this );
      if ( is_line_ ) {
        writer_->WriteOp( '}' , CodeWriter::kElseBlockEnd , buffer_ );
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
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* exp = ast_node->Exp();
  writer_->WriteOp( TOKEN::JS_FOR , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    BeginState_( CodeWriter::kFor );
    writer_->WriteOp( TOKEN::JS_VAR , CodeWriter::kFor , buffer_ );
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
  buffer_ += ';';
  if ( cond_exp ) {
    cond_exp->Accept( this );
  }
  buffer_ += ';';
  if ( incr_exp ) {
    incr_exp->Accept( this );
  }
  writer_->WriteOp( ')' , 0 , buffer_ );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
      writer_->WriteOp( ';' , 0 , buffer_ );
    }
  }
}

void CodegenVisitor::ForInProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* exp = ast_node->Exp();
  writer_->WriteOp( TOKEN::JS_FOR , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  if ( ast_node->NodeType() == AstNode::kForInWithVar ) {
    writer_->WriteOp( TOKEN::JS_VAR , CodeWriter::kFor , buffer_ );
  }
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();

  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    VarInitialiserProccessor_( index_exp->CastToValue() );
  } else {
    index_exp->Accept( this );
  }
  
  writer_->WriteOp( TOKEN::JS_IN , 0 , buffer_ );
  target_exp->Accept( this );
  
  writer_->WriteOp( ')' , 0 , buffer_ );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
      writer_->WriteOp( ';' , 0 , buffer_ );
    }
  }
}


void CodegenVisitor::WhileProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* exp = ast_node->Exp()->FirstChild();
  writer_->WriteOp( TOKEN::JS_WHILE , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  exp->Accept( this );
  writer_->WriteOp( ')' , 0 , buffer_ );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
      writer_->WriteOp( ';' , 0 , buffer_ );
    }
  }
}


void CodegenVisitor::DoWhileProccessor_( IterationStmt* ast_node ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* exp = ast_node->Exp()->FirstChild();
  writer_->WriteOp( TOKEN::JS_DO , 0 , buffer_ );
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    maybeBlock->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
    }
  }
  writer_->WriteOp( TOKEN::JS_WHILE , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  exp->Accept( this );
  writer_->WriteOp( ')' , 0 , buffer_ );
  writer_->WriteOp( ';' , 0 , buffer_ );
}


void CodegenVisitor::JumpStmt_( AstNode* ast_node , int type ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( type , 0 , buffer_ );
  AstNode* identifer = ast_node->FirstChild();
  if ( !identifer->IsEmpty() ) {
    ValueNode* value = identifer->CastToValue();
    writer_->Write( value->Symbol()->GetToken() , buffer_ );
  }
  writer_->WriteOp( ';' , 0 , buffer_ );
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
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( TOKEN::JS_RETURN , 0 , buffer_ );
  AstNode* identifer = ast_node->FirstChild();
  identifer->Accept( this );
  writer_->WriteOp( ';' , 0 , buffer_ );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( TOKEN::JS_WITH , 0 , buffer_ );
  ast_node->Exp()->Accept( this );

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( this );
  } else {
    if ( is_line_ ) {
      writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
    }
    ast_node->FirstChild()->Accept( this );
    if ( is_line_ ) {
      writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
      writer_->WriteOp( ';' , 0 , buffer_ );
    }
  }
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( TOKEN::JS_SWITCH , 0 , buffer_ );
  writer_->WriteOp( '(' , 0 , buffer_ );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ')' , 0 , buffer_ );
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , buffer_ );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  writer_->WriteOp( '}' , CodeWriter::kSwitchEndBrace , buffer_ );
  writer_->WriteOp( ';' , 0 , buffer_ );
}

VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->Exp();
  if ( !exp->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_CASE , 0 , buffer_ );
    exp->Accept( this );
  } else {
    writer_->WriteOp( TOKEN::JS_DEFAULT , 0 , buffer_ );
  }
  writer_->WriteOp( ':' , CodeWriter::kCase , buffer_ );
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode *node = ast_node->FirstChild();
  node->Accept( this );
}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  AstNode* symbol = ast_node->FirstChild();
  AstNode* statement = symbol->NextSibling();
  writer_->Write( symbol->CastToValue()->Symbol()->GetToken() , buffer_ );
  writer_->WriteOp( ':' , 0 , buffer_ );
  statement->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->WriteOp( TOKEN::JS_THROW , 0 , buffer_ );
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ';' , 0 , buffer_ );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  writer_->WriteOp( TOKEN::JS_TRY , 0 , buffer_ );
  AstNode* try_block = ast_node->FirstChild();
  writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ );
  try_block->FirstChild()->Accept( this );
  writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
  
  AstNode* catch_block = ast_node->Catch();
  AstNode* finally_block = ast_node->Finally();

  if ( !catch_block->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_CATCH , 0 , buffer_ );
    writer_->WriteOp( '(' , 0 , buffer_ );
    writer_->Write( catch_block->CastToValue()->Symbol()->GetToken() , buffer_ );
    writer_->WriteOp( ')',  0 , buffer_ );
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ ); 
    catch_block->FirstChild()->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
  }

  if ( !finally_block->IsEmpty() ) {
    writer_->WriteOp( TOKEN::JS_FINALLY , 0 , buffer_ );
    writer_->WriteOp( '{' , CodeWriter::kBlockBeginBrace , buffer_ ); 
    finally_block->FirstChild()->Accept( this );
    writer_->WriteOp( '}' , CodeWriter::kBlockEndBrace , buffer_ );
  }

  writer_->WriteOp( ';' , 0 , buffer_ );
}


void CodegenVisitor::ArrayAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  writer_->WriteOp( '[' , 0 , buffer_ );
  BeginState_( CodeWriter::kArgs );
  exp->Args()->Accept( this );
  EndLastState_();
  writer_->WriteOp( ']' , 0 , buffer_ );
}


void CodegenVisitor::DotAccessorProccessor_( CallExp* exp ) {
  exp->Callable()->Accept( this );
  writer_->WriteOp( '.' , 0 , buffer_ );
  exp->Args()->Accept( this );
}

void CodegenVisitor::NewCallProccessor_( CallExp* exp ) {
  AstNode* args = exp->Args();
  if ( args->IsEmpty() ) {
    buffer_ += '(';
  }
  writer_->WriteOp( TOKEN::JS_NEW , 0 , buffer_ );
  exp->Callable()->Accept( this );

  if ( args->IsEmpty() ) {
    buffer_ += ')';
  } else {
    writer_->WriteOp( '(' , 0 , buffer_ );
    NodeIterator iterator = exp->Args()->ChildNodes();
    BeginState_( CodeWriter::kArgs );
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        writer_->WriteOp( ',' , 0 , buffer_ );
      }
    }
    EndLastState_();
    writer_->WriteOp( ')' , 0 , buffer_ );
  }
}

void CodegenVisitor::NormalFunctionCall_( CallExp* exp ) {
  AstNode* args = exp->Args();
  exp->Callable()->Accept( this );
  if ( args->IsEmpty() ) {
    writer_->Write( "()" , buffer_ );
  } else {
    BeginState_( CodeWriter::kArgs );
    writer_->WriteOp( '(' , 0 , buffer_ );
    NodeIterator iterator = args->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        buffer_ += ',';
      }
    }
    EndLastState_();
    writer_->WriteOp( ')' , 0 , buffer_ );
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
  writer_->WriteOp( TOKEN::JS_NEW , 0 , buffer_ );
  ast_node->Constructor()->Accept( this );
}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
  writer_->WriteOp( ast_node->PostType() , 0 , buffer_ );
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  writer_->WriteOp( ast_node->Op() , 0 , buffer_ );
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , buffer_ );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL( CompareExp ) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , buffer_ );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '(' , 0 , buffer_ );
  ast_node->Cond()->Accept( this );
  writer_->WriteOp( ')' , 0 , buffer_ );
  writer_->WriteOp( '?' , 0 , buffer_ );
  ast_node->True()->Accept( this );
  writer_->WriteOp( ':' , 0 , buffer_ );
  ast_node->False()->Accept( this );
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  writer_->WriteOp( ast_node->Op() , 0 , buffer_ );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  if ( ast_node->IsParen() ) {
    BeginState_( CodeWriter::kParenExp );
    writer_->WriteOp( '(' , 0 , buffer_ );
  }
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
    if ( iterator.HasNext() ) {
      writer_->WriteOp( ',' , 0 , buffer_ );
    }
  }
  if ( ast_node->IsParen() ) {
    writer_->WriteOp( ')' , 0 , buffer_ );
    EndLastState_();
  }
}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  writer_->WriteOp( TOKEN::JS_FUNCTION , 0 , buffer_ );
  if ( !ast_node->Name()->IsEmpty() ) {
    writer_->Write( ast_node->Name()->CastToValue()->Symbol()->GetToken() , buffer_ );
  }
  if ( ast_node->Argv()->IsEmpty() ) {
    buffer_ += "()";
  } else {
    writer_->WriteOp( '(' , 0 , buffer_ );
    NodeIterator iterator = ast_node->Argv()->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( this );
      if ( iterator.HasNext() ) {
        buffer_ += ',';
      }
    }
    writer_->WriteOp( ')' , 0 , buffer_ );
  }
  writer_->WriteOp( '{' , CodeWriter::kFunctionBeginBrace , buffer_ );
  writer_->SetLine( ast_node->Line() , buffer_ );
  writer_->SetFileName( buffer_ );
  if ( ast_node->FunctionType() == Function::kNormal ) {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* node = iterator.Next();
      if ( !node->IsEmpty() ) {
        node->Accept( this );
      }
    }
  } else if ( ast_node->FunctionType() == Function::kShorten ) {
    buffer_ += "var __tmp__";
    writer_->WriteOp( '=' , 0 , buffer_ );
    ast_node->FirstChild()->Accept( this );
    writer_->WriteOp( ';' , 0 , buffer_ );
    buffer_ += "return __tmp__";
    writer_->WriteOp( ';' , 0 , buffer_ );
  }
  int state = CurrentState_();
  if ( ast_node->ContextType() == Function::kGlobal ) {
    state = ( state == CodeWriter::kArgs )? state :
        ( MatchState_( CodeWriter::kParenExp ) )? CodeWriter::kArgs : CodeWriter::kFunctionEndBrace;
    writer_->WriteOp( '}' , state , buffer_ );
  } else {
    writer_->WriteOp( '}' , CodeWriter::kArgs , buffer_ );
    buffer_ += ".bind";
    writer_->WriteOp( '(' , 0 , buffer_ );
    buffer_ += "this";
    writer_->WriteOp( ')' , 0 , buffer_ );
  }
};


void CodegenVisitor::ArrayProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  writer_->WriteOp( '[' , 0 , buffer_ );
  AstNode* list_child = ast_node->FirstChild();
  while ( list_child ) {
    if ( list_child->IsEmpty() ) {
      buffer_ += ',';
    } else {
      NodeIterator iter = list_child->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        if ( !element->IsEmpty() ) {
          element->Accept( this );
        }
        if ( iter.HasNext() ) {
          buffer_ += ',';
        }
      }
      if ( list_child->HasNext() ) {
        list_child = list_child->NextSibling();
      } else {
        break;
      }
    }
  }
  writer_->WriteOp( ']' , 0 , buffer_ );
}


void CodegenVisitor::ObjectProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( element_list->IsEmpty() ) {
    buffer_ += "{}";
  } else {
    writer_->WriteOp( '{' , CodeWriter::kArgs , buffer_ );
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( this );
      writer_->WriteOp( ':' , 0 , buffer_ );
      element->FirstChild()->Accept( this );
      if ( iterator.HasNext() ) {
        writer_->WriteOp( ',' , CodeWriter::kVarsComma , buffer_ );
      }
    }
    writer_->WriteOp( '}' , CodeWriter::kArgs , buffer_ );
  }
}


void CodegenVisitor::VarInitialiserProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  if ( ast_node->ValueType() == ValueNode::kVariable ) {
    writer_->Write( ast_node->Symbol()->GetToken() ,  buffer_ );
  }
  AstNode* initialiser = ast_node->FirstChild();
  if ( !initialiser->IsEmpty() ) {
    writer_->WriteOp( '=' , 0 , buffer_ );
    initialiser->Accept( this );
  }
}


void CodegenVisitor::CreateDstAssignment_( const char* name ) {
  std::string tmp = name;
  std::string last;
  std::vector<std::string>::iterator ITERATOR( dst_accessor_ );
  writer_->WriteOp( '=' , 0 , tmp );
  writer_->WriteOp( '(' , 0 , tmp );
  while ( begin != end ) {
    last += (*begin);
    tmp += tmp_ref_;
    tmp += last;
    ++begin;
    if ( begin != end ) {
      writer_->WriteOp( TOKEN::JS_LOGICAL_AND , 0 , tmp );
    }
  }
  writer_->WriteOp( ')' , 0 , tmp );
  writer_->WriteOp( '?' , 0 , tmp );
  tmp += tmp_ref_;
  tmp += last;
  writer_->WriteOp( ':' , 0 , tmp );
  tmp += "undefined";
  dst_code_.push_back( tmp );
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
  }
}


void CodegenVisitor::DstMemberProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  TokenInfo* info = ast_node->Symbol();
  switch( info->GetType() ) {
    case TOKEN::JS_IDENTIFIER :
      {
        char tmp[ strlen( info->GetToken() ) + 2 ];
        sprintf( tmp , ".%s" , info->GetToken() );
        dst_accessor_.push_back( tmp );
      }
      break;

    case TOKEN::JS_NUMERIC_LITERAL :
    case TOKEN::JS_STRING_LITERAL :
      {
        char tmp[ strlen( info->GetToken() ) + 2 ];
        sprintf( tmp , "[%s]" , info->GetToken() );
        dst_accessor_.push_back( tmp );
      }
      break;
      
  }
}


void CodegenVisitor::DstObjectProcessor_( ValueNode* ast_node , int depth ) {
  PRINT_NODE_NAME;
  AstNode* child = ast_node->Node();
  NodeIterator iterator = ( child )? child->ChildNodes() : ast_node->ChildNodes();
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
            char tmp[ strlen( name ) + 2 ];
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
    }
  }
}


void CodegenVisitor::DstProcessor_( ValueNode* ast_node ) {
  char tmp[ 20 ];
  sprintf( tmp , "__tmp__%d" , tmp_index_ );
  tmp_ref_ = tmp;
  tmp_index_++;
  if ( ast_node->ValueType() == ValueNode::kArray ) {
    DstArrayProccessor_( ast_node , 0 );
  } else {
    DstObjectProcessor_( ast_node , 0 );
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
      DstProcessor_( ast_node );
      break;
      
    default :
      writer_->Write( ast_node->Symbol()->GetToken() , buffer_ );
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

