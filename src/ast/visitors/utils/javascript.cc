#include <ast/visitors/utils/javascript.h>

#define COMMON_PARAMETER visitor_ , util_ , state_
#define VARS CodeStream *stream = util_->GetStream();CodeWriter* writer = util_->GetWriter()

namespace mocha {
namespace javascript

static char anonymouse_scope_begin_exp[] = { "(function()" };
static char anonymouse_scope_end_exp[] = { ")()" };
static char open_brace = '{';
static char close_brace = '}';
static char dst_tmp_var[] = { "__MC_tmp__" };
static char global_export_symbol[] = { "__MC_global_export__" };
static char empty_brace_pair[] = { "{}" };
static char undefined[] = { "undefined" };


void IteratorAcceptor( NodeIterator* iterator , CodegenVisitor* visitor ) {
  while ( iterator->HasNext() ) {
    iterator->Next()->Accept( visitor );
  }
}

AnonymousScopeProcessor::OpenScope() {
  VARS;
  stream->Write( anonymouse_scope_begin_exp );
  
  state_->Push( GeneratorState::kFunctionBeginBrace );
  writer->WriteOp( open_brace , state_ , stream );
  state_->Pop();
}

AnonymousScopeProcessor::CloseScope() {
  VARS;
  state_->Push( GeneratorState::kArgs );
  writer->WriteOp( close_brace , state_ , stream );
  state_->Pop();
  
  stream->Write( anonymouse_scope_end_exp );
  writer->WriteOp( ';' , state_ , stream );
}


BlockProcessor::OpenBlock() {
  VARS;
  writer->WriteOp( open_brace , state_ , stream );
}


BlockProcessor::CloseBlock() {
  VARS;
  writer->WriteOp( close_brace , state_ , stream );
}


Prologue::Process( AstNode* ast_node ) {
  VARS;
  writer->InsertDebugSymbol( stream_.Get() );
  writer->WriteOp( TOKEN::JS_VAR , state_ , stream_.Get() );

  stream->Write( global_export_symbol );
  writer->WriteOp( '=' , state_ , stream_.Get() );
  stream_->Write( empty_brace_pair );

  state_->Push( GeneratorState::kVarsComma );
  writer->WriteOp( ',' , state_ , stream_.Get() );
  state_->Pop();

  stream->Write( dst_tmp_var );
  writer->WriteOp( '=' , 0 , stream_.Get() );
  stream->Write( undefined );

  state_->Push( GeneratorState::kVarsEnd );
  writer->WriteOp( ';' , CodeWriter::kVarsEnd , stream_.Get() );
  state_->Pop();
  
  NodeIterator iterator = ast_node->ChildNodes();
  IteratorAcceptor( &iterator );
}


}
}
