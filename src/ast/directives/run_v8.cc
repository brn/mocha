#include <ast/directives/run_v8.h>
#include <ast/ast.h>
#include <ast/visitors/utils/processors/processor_info.h>
namespace mocha {
RunV8::RunV8( ProcessorInfo* info ) :
    info_( info ){}

RunV8::~RunV8() {
  global_object_->Dispose();
  context_->Dispose();
  global_->Dispose();
  env_->Dispose();
}
void RunV8::Init() {
  v8::HandleScope handle_scope;
  global = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
  context_ = v8::Context::New( NULL, global );
  v8::Context::Scope context_scope( context );
  global_object = Persistent<Object>::New ( context->Global() );
  global_object->Set( String::New( "ast" ) , AstForV8::InitCreator( global_object , info_ ) );
  global_object->Set( String::New( "env" ) , AstForV8::InitEnv( global_object , info_ ) );
  const char *code = "function env( args , code ) {var fn = Function( 'return ' + code )();fn.apply( null , args );};";
  env_ = v8::Persistent<v8::Script>::New( v8::Script::Compile( v8::String::New( code ) , v8::Undefined() ) );
}

AstNode* RunV8::Run( AstNode* ast_node , const char* script ) {
  v8::HandleScope handle_scope;
  v8::Context::Scope context_scope( context_ );
  NodeIterator iterator = ast_node_->ChildNodes();
  v8::Handle<v8::Array> arg_object = Array::New(2);
  int count = 0;
  while ( iterator.HasNext() ) {
    arg_object->Set( Number::New( count ) , AstForV8::Init( global_object , iterator.Next() , info_ ) );
    count++;
  }
  v8::Handle<v8::Value> args[ 2 ] = { args , v8::String::New( script ) };
  arg_object->Set( String::New( "length" ) , Number::New( ast_node_->ChildLength() ) );
  v8::Handle<v8::Function> fn = v8::Handle<v8::Function>::Cast( context_->Global()->Get( v8::String::New( "env" ) ) );
  Handle<Value> result = fn->Call( global_object_ , 2 , args );
  Handle<Object> val = Handle<Object>::Cast( result )->GetInternalField( 0 );
  return reinterpret_cast<AstNode*>( val );
}
}
