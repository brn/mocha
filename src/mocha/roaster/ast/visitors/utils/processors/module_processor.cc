#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/utils/ast_utils.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/module_processor.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <utils/pool/managed_handle.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/ast/ast.h>
namespace mocha {

ModuleProcessor::ModuleProcessor( ModuleStmt* stmt , ProcessorInfo* info ) :
    stmt_( stmt ) , info_( info ){};

void ModuleProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->visitor_info();
  AstNode* body = stmt_->first_child();
  AstNode* name = stmt_->name();
  bool is_runtime = visitor_info->runtime();
  Function* fn_node = AstUtils::CreateFunctionDecl( name , Empty::New() , body , stmt_->line_number() );
  fn_node->set_name( Empty::New() );
  AstUtils::FindDirectivePrologue( fn_node , fn_node );
  ExpressionStmt* an_stmt_node = ProcessBody_( body , fn_node , name );
  //For anonymous module.
  if ( !name->IsEmpty() ) {
    Literal* maybe_value = name->CastToLiteral();
    if ( maybe_value ) {
      maybe_value->set_value_type( Literal::kProperty );
    }
    ProcessAnonymousModule_( an_stmt_node , name , is_runtime );
  } else {
    stmt_->parent_node()->ReplaceChild( stmt_ , an_stmt_node );
  }
  Finish_( name , fn_node );
}

/*
 * In anonymous modules,
 * all export properties are directly add to global export symbol.
 * Like this -> __MC_global_alias__.<name> = ...;
 */
void ModuleProcessor::ProcessAnonymousModule_( ExpressionStmt* an_stmt_node , AstNode* name , bool is_runtime ) {
  VisitorInfo* visitor_info = info_->visitor_info();
  if ( !is_runtime ) {
    Literal* alias = 0;
    if ( visitor_info->IsInModules() ) {
      alias = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLocalExport ),
                                        Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
    } else {
      alias = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalAlias ),
                                        Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
    }
    CallExp* dot_accessor = AstUtils::CreateDotAccessor( alias , name , stmt_->line_number() );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , dot_accessor , an_stmt_node->first_child() , stmt_->line_number() );
    AstNode* stmt = 0;//init after.
    if ( !name->IsEmpty() ) {
      Literal* var_node = AstUtils::CreateVarInitiliser( name->CastToLiteral()->value() , exp , stmt_->line_number() );
      stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarDeclList( stmt_->line_number() , 1 , var_node ) , stmt_->line_number() );
    } else {
      stmt = AstUtils::CreateExpStmt( exp , stmt_->line_number() );
    }
    stmt_->parent_node()->ReplaceChild( stmt_ , stmt );
  } else {
    Literal *var_node = AstUtils::CreateVarInitiliser( name->CastToLiteral()->value() , an_stmt_node->first_child() , stmt_->line_number() );
    VariableStmt *var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarDeclList( stmt_->line_number() , 1 , var_node ) , stmt_->line_number() );
    stmt_->parent_node()->ReplaceChild( stmt_ , var_stmt );
  }
}

/**
 * Create anonymous function call like (function(){ ... })()
 * to create module scopes.
 */
ExpressionStmt* ModuleProcessor::ProcessBody_( AstNode* body , Function* fn_node , AstNode* name ) {
  VisitorInfo* visitor_info = info_->visitor_info();
  IVisitor* visitor = info_->visitor();
  ExpressionStmt* an_stmt_node = AstUtils::CreateAnonymousFnCall( fn_node , Empty::New() , stmt_->line_number() );
  visitor_info->EnterModuel();
  body->Accept( visitor );
  visitor_info->EscapeModuel();
  return an_stmt_node;
}


void ModuleProcessor::Finish_( AstNode* name , Function* fn_node ) {
  TokenInfo* local = TokenInfo::New( SymbolList::symbol( SymbolList::kLocalExport ),
                                     Token::JS_IDENTIFIER , stmt_->line_number() );
  Literal* ret_local = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLocalExport ),
                                                 Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
  Literal* init = 0;//init after.
  if ( !name->IsEmpty() ) {
    init = AstUtils::CreateVarInitiliser( local,
                                          AstUtils::CreateObjectLiteral( Empty::New() , stmt_->line_number() ) , stmt_->line_number() );
  } else {
    Literal* alias = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalAlias ),
                                               Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
    init = AstUtils::CreateVarInitiliser( local , alias , stmt_->line_number() );
  }
  VariableDeclarationList* list = VariableDeclarationList::New( stmt_->line_number() );
  ReturnStmt* ret = AstUtils::CreateReturnStmt( ret_local , stmt_->line_number() );
  list->AddChild( init );
  VariableStmt* var_stmt = AstUtils::CreateVarStmt( list , stmt_->line_number() );
  fn_node->InsertBefore( var_stmt );
  fn_node->AddChild( ret );
}
}
