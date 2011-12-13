#include <ast/utils/ast_utils.h>
#include <ast/ast.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>
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


CallExp* AstUtils::CreateConstantProp( AstNode* lhs , AstNode* prop , AstNode* value ) {
  ValueNode* constant = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstant ),
                                                  TOKEN::JS_IDENTIFIER , lhs->Line() );
  ValueNode* prop_str = prop->CastToValue();
  AstNode* property = prop;
  if ( prop_str && prop_str->ValueType() == ValueNode::kIdentifier ) {
    char tmp[50];
    sprintf( tmp , "'%s'" , prop_str->Symbol()->GetToken() );
    property = AstUtils::CreateNameNode( tmp , TOKEN::JS_STRING_LITERAL , prop_str->Line() );
  }
  NodeList* args = ManagedHandle::Retain<NodeList>();
  args->AddChild( lhs );
  args->AddChild( property );
  args->AddChild( value );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( constant );
  return AstUtils::CreateNormalAccessor( runtime_accessor , args );
}


CallExp* AstUtils::CreatePrototypeNode( AstNode* lhs ) {
  ValueNode* prototype = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrototype ),
                                                   TOKEN::JS_IDENTIFIER , lhs->Line() );
  return AstUtils::CreateDotAccessor( lhs , prototype );
}


CallExp* AstUtils::CreateRuntimeMod( AstNode* member ) {
  ValueNode* value = CreateNameNode( SymbolList::GetSymbol( SymbolList::kRuntime ),
                                     TOKEN::JS_IDENTIFIER , 0 );
  CallExp* exp = CreateDotAccessor( value , member );
  return exp;
}

const char* AstUtils::CreateTmpRef( char* buf , int index ) {
  sprintf( buf , "%s%d", SymbolList::GetSymbol( SymbolList::kLocalTmp ) , index );
  return buf;
}

CallExp* AstUtils::CreateGlobalExportNode( AstNode* ast_node , const char* filename ) {
  StrHandle key = FileSystem::GetModuleKey( filename );
  ValueNode* value = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalExport ),
                                               TOKEN::JS_IDENTIFIER , ast_node->Line() );
  ValueNode* name = AstUtils::CreateNameNode( key.Get() , TOKEN::JS_IDENTIFIER , ast_node->Line() );
  CallExp* arr = AstUtils::CreateArrayAccessor( value , name );
  return arr;
}

}
