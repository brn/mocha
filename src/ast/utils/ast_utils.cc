#include <ast/utils/ast_utils.h>
#include <ast/ast.h>
#include <compiler/tokens/token_info.h>
#include <utils/pool/managed_handle.h>
#include <utils/file_system/file_system.h>
#include <grammar/grammar.tab.hh>

#define TOKEN yy::ParserImplementation::token

namespace mocha{
Function* AstUtils::CreateFunctionDecl( AstNode* name , AstNode* argv , AstNode* body ) {
  Function *fn = ManagedHandle::Retain<Function>();
  fn->Name( name );
  fn->Argv( argv );
  fn->Append( body );
  return fn;
}

CallExp* AstUtils::CreateArrayAccessor( AstNode* callable , AstNode* args ) {
  CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
  exp->Callable( callable );
  exp->Args( args );
  return exp;
}

CallExp* AstUtils::CreateDotAccessor( AstNode* callable , AstNode* args ) {
  CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
  exp->Callable( callable );
  exp->Args( args );
  return exp;
}

static const char prototype[] = { "prototype" };

CallExp* AstUtils::CreatePrototypeAccessor( AstNode* callable , AstNode* args ) {
  ValueNode* prototype_node = CreateNameNode( prototype , TOKEN::JS_IDENTIFIER , callable->Line() );
  CallExp* depth1 = CreateDotAccessor( callable , prototype_node );
  CallExp* depth2 = CreateDotAccessor( depth1 , args );
  return depth2;
}

CallExp* AstUtils::CreateNormalAccessor( AstNode* callable , AstNode* args ) {
  CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
  exp->Callable( callable );
  exp->Args( args );
  return exp;
}

ValueNode* AstUtils::CreateNameNode( const char* name , int type , long line , bool is_empty ) {
  TokenInfo* info = ManagedHandle::Retain( new TokenInfo( name , type , line ) );
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  if ( is_empty ) {
    value->AddChild( ManagedHandle::Retain<Empty>() );
  }
  value->Symbol( info );
  return value;
}

AssignmentExp* AstUtils::CreateAssignment( int type , AstNode* lhs , AstNode* rhs ) {
  AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( type , lhs , rhs ) );
  return assign;
}

ValueNode* AstUtils::CreateObjectLiteral( AstNode* body ) {
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
  value->Node( body );
  return value;
}

ExpressionStmt* AstUtils::CreateAnonymousFnCall( Function *fn , AstNode* args ) {
  Expression* exp = ManagedHandle::Retain<Expression>();
  CallExp* call = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
  exp->AddChild( fn );
  exp->Paren();
  call->Callable( exp );
  call->Args( args );
  Expression* ret_exp = ManagedHandle::Retain<Expression>();
  ret_exp->AddChild( call );
  ExpressionStmt* ret_stmt = ManagedHandle::Retain<ExpressionStmt>();
  ret_stmt->AddChild( ret_exp );
  return ret_stmt;
}

ExpressionStmt* AstUtils::CreateExpStmt( AstNode* node ) {
  Expression* exp = ManagedHandle::Retain<Expression>();
  exp->AddChild( node );
  ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
  stmt->AddChild( exp );
  return stmt;
}

VariableStmt* AstUtils::CreateVarStmt( NodeList* list  ) {
  VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
  var->VarType( VariableStmt::kNormal );
  var->Line( list->Line() );
  var->Append( list );
  return var;
}

VariableStmt* AstUtils::CreateVarStmt( AstNode* mem ) {
  NodeList* list = ManagedHandle::Retain<NodeList>();
  list->AddChild( mem );
  return CreateVarStmt( list );
}

ValueNode* AstUtils::CreateVarInitiliser( TokenInfo* lhs , AstNode* rhs ) {
  ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
  node->Line( lhs->GetLineNumber() );
  node->Symbol( lhs );
  node->AddChild( rhs );
  return node;
}

ReturnStmt* AstUtils::CreateReturnStmt( AstNode* exp ) {
  ReturnStmt* return_stmt = ManagedHandle::Retain<ReturnStmt>();
  return_stmt->AddChild( exp );
  return return_stmt;
}

static const char global_export[] = { "_mochaGlobalExport" };
static const char global_alias[] = { "_mochaGlobalAlias" };
static const char local_export[] = { "_mochaLocalExport" };
static const char local_tmp[] = { "_localTmp" };
static const char to_array[] = { "toArray" };
static const char mc_runtime[] = { "Runtime" };
static const char arguments[] = { "arguments" };
static const char undefined[] = {"undefined"};
static const char class_table[] = {"_mochaClassTable"};
static const char hidden[] = { "createUnenumProp" };
static const char constructor[] = {"constructor"};
static const char this_sym[] = {"this"};
static const char typeid_sym[] = {"__typeid__"};
static const char instance_id[] = {"_mochaInstanceId"};
static const char instance_table[] = {"_mochaInstanceTable"};
static const char hidden_call[] = {"createPrivateProp"};
static const char apply_sym[] = {"apply"};

CallExp* AstUtils::CreateRuntimeMod( AstNode* member ) {
  ValueNode* value = CreateNameNode( mc_runtime , TOKEN::JS_IDENTIFIER , 0 );
  CallExp* exp = CreateDotAccessor( value , member );
  return exp;
}

const char* AstUtils::GetGloablExportSymbol() {
  return global_export;
}

const char* AstUtils::GetLocalExportSymbol() {
  return local_export;
}

const char* AstUtils::GetGlobalAliasSymbol() {
  return global_alias;
}

const char* AstUtils::GetToArraySymbol() {
  return to_array;
}

const char* AstUtils::GetArgumentsSymbol() {
  return arguments;
}

const char* AstUtils::GetUndefinedSymbol() {
  return undefined;
}

const char* AstUtils::GetClassTableSymbol() {
  return class_table;
}

const char* AstUtils::GetHiddenCallSymbol() {
  return hidden_call;
}

const char* AstUtils::GetHiddenSymbol() {
  return hidden;
}

const char* AstUtils::GetConstructorSymbol() {
  return constructor;
}

const char* AstUtils::GetThisSymbol() {
  return this_sym;
}

const char* AstUtils::GetTypeIdSymbol() {
  return typeid_sym;
}

const char* AstUtils::GetInstanceIdSymbol() {
  return instance_id;
}

const char* AstUtils::GetApplySym() {
  return apply_sym;
}

const char* AstUtils::CreateTmpRef( char* buf , int index ) {
  sprintf( buf , "%s%d", local_tmp , index );
  return buf;
}

CallExp* AstUtils::CreateGlobalExportNode( AstNode* ast_node , const char* filename ) {
  StrHandle key = FileSystem::GetModuleKey( filename );
  ValueNode* value = AstUtils::CreateNameNode( AstUtils::GetGloablExportSymbol() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
  ValueNode* name = AstUtils::CreateNameNode( key.Get() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
  CallExp* arr = AstUtils::CreateArrayAccessor( value , name );
  return arr;
}

}
