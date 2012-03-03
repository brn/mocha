#include <stdarg.h>
#include <mocha/roaster/ast/utils/ast_utils.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/symbol_list.h>
#include <utils/pool/managed_handle.h>
#include <utils/file_system/file_system.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha{

Function* AstUtils::CreateFunctionDecl( AstNode* name , AstNode* argv , AstNode* body , int64_t line ) {
  Function *fn = Function::New( line );
  fn->set_name( name );
  fn->set_argv( argv );
  fn->Append( body );
  return fn;
}

CallExp* AstUtils::CreateArrayAccessor( AstNode* callable , AstNode* args , int64_t line ) {
  CallExp* exp = CallExp::New( CallExp::kBracket , line );
  exp->set_callable( callable );
  exp->set_args( args );
  return exp;
}

CallExp* AstUtils::CreateDotAccessor( AstNode* callable , AstNode* args , int64_t line ) {
  CallExp* exp = CallExp::New( CallExp::kDot , line );
  exp->set_callable( callable );
  exp->set_args( args );
  return exp;
}

static const char prototype[] = { "prototype" };

CallExp* AstUtils::CreatePrototypeAccessor( AstNode* callable , AstNode* args , int64_t line ) {
  Literal* prototype_node = CreateNameNode( prototype , Token::JS_IDENTIFIER , line , Literal::kProperty );
  CallExp* depth1 = CreateDotAccessor( callable , prototype_node , line );
  CallExp* depth2 = CreateDotAccessor( depth1 , args , line );
  return depth2;
}

CallExp* AstUtils::CreateNormalAccessor( AstNode* callable , AstNode* args , int64_t line ) {
  CallExp* exp = CallExp::New( CallExp::kNormal , line );
  exp->set_callable( callable );
  exp->set_args( args );
  return exp;
}

Literal* AstUtils::CreateNameNode( const char* name , int type , int64_t line , int value_type , bool is_empty ) {
  TokenInfo* info = TokenInfo::New( name , type , line );
  Literal* value = Literal::New( value_type , line );
  if ( is_empty ) {
    value->AddChild( Empty::New() );
  }
  value->set_value( info );
  return value;
}

AssignmentExp* AstUtils::CreateAssignment( int type , AstNode* lhs , AstNode* rhs , int64_t line ) {
  AssignmentExp* assign = AssignmentExp::New( type , lhs , rhs , line );
  return assign;
}

UnaryExp* AstUtils::CreateUnaryExp( int type , AstNode* exp , int64_t line ) {
  UnaryExp* unary = UnaryExp::New( type , exp , line );
  return unary;
}

ObjectLikeLiteral* AstUtils::CreateObjectLiteral( AstNode* body , int64_t line ) {
  ObjectLikeLiteral* object = ObjectLikeLiteral::New( line );
  object->Append( body );
  return object;
}

ExpressionStmt* AstUtils::CreateAnonymousFnCall( Function *fn , AstNode* args , int64_t line ) {
  Expression* exp = Expression::New( line );
  CallExp* call = CallExp::New( CallExp::kNormal , line );
  exp->AddChild( fn );
  exp->MarkParenthesis();
  call->set_callable( exp );
  call->set_args( args );
  ExpressionStmt* ret_stmt = ExpressionStmt::New( line );
  ret_stmt->AddChild( call );
  return ret_stmt;
}

ExpressionStmt* AstUtils::CreateExpStmt( AstNode* node , int64_t line ) {
  Expression* exp = Expression::New( line );
  exp->AddChild( node );
  ExpressionStmt* stmt = ExpressionStmt::New( line );
  stmt->AddChild( exp );
  return stmt;
}

VariableStmt* AstUtils::CreateVarStmt( VariableDeclarationList* list , int64_t line ) {
  VariableStmt* var = VariableStmt::New( line );
  var->AddChild( list );
  return var;
}


Literal* AstUtils::CreateVarInitiliser( TokenInfo* lhs , AstNode* rhs , int64_t line ) {
  Literal* node = Literal::New( Literal::kVariable , line );
  node->set_value( lhs );
  node->AddChild( rhs );
  return node;
}

ReturnStmt* AstUtils::CreateReturnStmt( AstNode* exp , int64_t line ) {
  ReturnStmt* return_stmt = ReturnStmt::New( line );
  return_stmt->AddChild( exp );
  return return_stmt;
}


CallExp* AstUtils::CreateConstantProp( AstNode* lhs , AstNode* prop , AstNode* value , int64_t line ) {
  Literal* constant = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kConstant ),
                                                Token::JS_IDENTIFIER , line , Literal::kIdentifier );
  Literal* prop_str = prop->CastToLiteral();
  AstNode* property = prop;
  if ( prop_str && ( prop_str->value_type() == Literal::kIdentifier || prop_str->value_type() == Literal::kProperty ) ) {
    char tmp[50];
    sprintf( tmp , "'%s'" , prop_str->value()->token() );
    property = AstUtils::CreateNameNode( tmp , Token::JS_STRING_LITERAL , line , Literal::kString );
  }
  NodeList* args = NodeList::New();
  args->AddChild( lhs );
  args->AddChild( property );
  args->AddChild( value );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( constant , line );
  return AstUtils::CreateNormalAccessor( runtime_accessor , args , line );
}


CallExp* AstUtils::CreatePrototypeNode( AstNode* lhs , int64_t line ) {
  Literal* prototype = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kPrototype ),
                                                 Token::JS_IDENTIFIER , line , Literal::kProperty );
  return AstUtils::CreateDotAccessor( lhs , prototype , line );
}


CallExp* AstUtils::CreateRuntimeMod( AstNode* member , int64_t line ) {
  Literal* value = CreateNameNode( SymbolList::symbol( SymbolList::kRuntime ),
                                   Token::JS_IDENTIFIER , line , Literal::kIdentifier );
  return CreateDotAccessor( value , member , line );
}

const char* AstUtils::CreateTmpRef( char* buf , int index ) {
  sprintf( buf , "%s%d", SymbolList::symbol( SymbolList::kLocalTmp ) , index );
  return buf;
}

Literal* AstUtils::CreateTmpNode( int index , int64_t line ) {
  char buf[ 100 ];
  const char* tmp = AstUtils::CreateTmpRef( buf , index );
  return AstUtils::CreateNameNode( tmp , Token::JS_IDENTIFIER , line , Literal::kIdentifier );
}

CallExp* AstUtils::CreateGlobalExportNode( AstNode* ast_node , VisitorInfo* visitor_info,
                                           const char* base , const char* filename , int64_t line ) {
  Handle<PathInfo> base_path_info = FileSystem::GetPathInfo( visitor_info->main_file_path() );
  Handle<PathInfo> target_path_info = FileSystem::GetPathInfo( filename );
  StrHandle handle = FileSystem::GetModuleKey( base_path_info->GetDirPath().Get() , target_path_info->GetDirPath().Get() );
  std::string modkey = "'";
  modkey += handle.Get();
  modkey += target_path_info->GetFileName().Get();
  modkey += "'";
  Literal* value = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalExport ),
                                             Token::JS_IDENTIFIER , line , Literal::kIdentifier );
  Literal* name = AstUtils::CreateNameNode( modkey.c_str() , Token::JS_IDENTIFIER , line , Literal::kString );
  return AstUtils::CreateArrayAccessor( value , name , line );
}

IFStmt* AstUtils::CreateIFStmt( AstNode* exp , AstNode* then_stmt , AstNode* else_stmt , int64_t line ) {
  IFStmt* if_stmt = IFStmt::New( line );
  if_stmt->set_condition( exp );
  if_stmt->set_then_statement( then_stmt );
  if_stmt->set_else_statement( else_stmt );
  return if_stmt;
}

NodeList* AstUtils::CreateNodeList( int num , ... ) {
  va_list list;
  va_start( list , num );
  NodeList* node_list = NodeList::New();
  for ( int i = 0; i < num; i++ ) {
    AstNode* node = va_arg( list , AstNode* );
    node_list->AddChild( node );
  }
  return node_list;
}

BlockStmt* AstUtils::CreateBlockStmt( int64_t line , int num , ... ) {
  va_list list;
  va_start( list ,      num );
  BlockStmt* block = BlockStmt::New( line );
  for ( int i = 0; i < num; i++ ) {
    AstNode* stmt = va_arg( list , AstNode* );
    block->AddChild( stmt );
  }
  return block;
}

VariableDeclarationList* AstUtils::CreateVarDeclList( int64_t line , int num , ... ) {
  va_list list;
  va_start( list , num );
  VariableDeclarationList* decl_list = VariableDeclarationList::New( line );
  for ( int i = 0; i < num; i++ ) {
    AstNode* node = va_arg( list , AstNode* );
    decl_list->AddChild( node );
  }
  return decl_list;
}

template<typename T>
void FindDirectivePrologueCommon( AstNode* node , T* target ) {
  if ( node->first_child() && node->first_child()->node_type() == AstNode::kExpressionStmt ) {
    if ( node->first_child()->first_child() && node->first_child()->first_child()->first_child() &&
         node->first_child()->first_child()->first_child()->node_type() == AstNode::kLiteral ) {
      Literal* directive = node->first_child()->first_child()->first_child()->CastToLiteral();
      if ( strcmp( directive->value()->token() , "'use strict'"  ) == 0 || strcmp( directive->value()->token() , "\"use strict\""  ) == 0 ) {
        node->RemoveChild( node->first_child() );
        target->MarkAsStrict();
      }
    }
  }
}

void AstUtils::FindDirectivePrologue( AstNode* node , FileRoot* root ) {
  FindDirectivePrologueCommon( node , root );
}

void AstUtils::FindDirectivePrologue( AstNode* node , Function* fn ) {
  FindDirectivePrologueCommon( node , fn );
}

bool AstUtils::IsDestructringLeftHandSide( AstNode* node ) {
  return ( node->node_type() == AstNode::kArrayLikeLiteral ||
           node->node_type() == AstNode::kObjectLikeLiteral ) &&
      node->CastToExpression() && node->CastToExpression()->IsValidLhs();
}

}