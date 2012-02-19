#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/module_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/token_info.h>
#include <grammar/grammar.tab.hh>
#include <ast/ast.h>
namespace mocha {

#define TOKEN yy::ParserImplementation::token

ModuleProcessor::ModuleProcessor( ModuleStmt* stmt , ProcessorInfo* info ) :
    stmt_( stmt ) , info_( info ){};

void ModuleProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->GetInfo();
  AstNode* body = stmt_->FirstChild();
  AstNode* name = stmt_->Name();
  bool is_runtime = visitor_info->IsRuntime();
  if ( body->NodeType() == AstNode::kBlockStmt ) {
    //Get block inner node.
    body = body->FirstChild();
  } else {
    //Create node list.
    StatementList *list = ManagedHandle::Retain<StatementList>();
    list->AddChild( body );
    body = list;
  }
  Function* fn_node = AstUtils::CreateFunctionDecl( name , ManagedHandle::Retain<Empty>() , body );
  ExpressionStmt* an_stmt_node = ProcessBody_( body , fn_node , name );
  fn_node->Line( stmt_->Line() );
  //For anonymous module.
  if ( !name->IsEmpty() ) {
    ValueNode* maybe_value = name->CastToValue();
    if ( maybe_value ) {
      maybe_value->ValueType( ValueNode::kProperty );
    }
    ProcessAnonymousModule_( an_stmt_node , name , is_runtime );
  } else {
    an_stmt_node->Line( stmt_->Line() );
    stmt_->ParentNode()->ReplaceChild( stmt_ , an_stmt_node );
  }
  Finish_( name , fn_node );
}

/*
 * In anonymous modules,
 * all export properties are directly add to global export symbol.
 * Like this -> __MC_global_alias__.<name> = ...;
 */
void ModuleProcessor::ProcessAnonymousModule_( ExpressionStmt* an_stmt_node , AstNode* name , bool is_runtime ) {
  VisitorInfo* visitor_info = info_->GetInfo();
  if ( !is_runtime ) {
    ValueNode* alias = 0;
    if ( visitor_info->IsInModules() ) {
      alias = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                        Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
    } else {
      alias = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalAlias ),
                                        Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
    }
    CallExp* dot_accessor = AstUtils::CreateDotAccessor( alias , name );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , dot_accessor , an_stmt_node->FirstChild() );
    AstNode* stmt = 0;//init after.
    if ( !name->IsEmpty() ) {
      ValueNode* var_node = AstUtils::CreateVarInitiliser( name->CastToValue()->Symbol() , exp );
      stmt = AstUtils::CreateVarStmt( var_node );
    } else {
      AstUtils::CreateExpStmt( exp );
    }
    stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
  } else {
    ValueNode *var_node = AstUtils::CreateVarInitiliser( name->CastToValue()->Symbol() , an_stmt_node->FirstChild() );
    VariableStmt *var_stmt = AstUtils::CreateVarStmt( var_node );
    var_stmt->Line( stmt_->Line() );
    stmt_->ParentNode()->ReplaceChild( stmt_ , var_stmt );
  }
}

/**
 * Create anonymous function call like (function(){ ... })()
 * to create module scopes.
 */
ExpressionStmt* ModuleProcessor::ProcessBody_( AstNode* body , Function* fn_node , AstNode* name ) {
  VisitorInfo* visitor_info = info_->GetInfo();
  IVisitor* visitor = info_->GetVisitor();
  ExpressionStmt* an_stmt_node = AstUtils::CreateAnonymousFnCall( fn_node , ManagedHandle::Retain<Empty>() );
  visitor_info->EnterModuel();
  body->Accept( visitor );
  visitor_info->EscapeModuel();
  return an_stmt_node;
}


void ModuleProcessor::Finish_( AstNode* name , Function* fn_node ) {
  TokenInfo* local = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                                           Token::JS_IDENTIFIER , stmt_->Line() ) );
  ValueNode* ret_local = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                                   Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
  ValueNode* init = 0;//init after.
  if ( !name->IsEmpty() ) {
    init = AstUtils::CreateVarInitiliser( local,
                                          AstUtils::CreateObjectLiteral( ManagedHandle::Retain<Empty>() ) );
  } else {
    ValueNode* alias = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalAlias ),
                                                 Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
    init = AstUtils::CreateVarInitiliser( local,
                                          alias );
  }
  NodeList* list = ManagedHandle::Retain<NodeList>();
  ReturnStmt* ret = AstUtils::CreateReturnStmt( ret_local );
  list->AddChild( init );
  VariableStmt* var_stmt = AstUtils::CreateVarStmt( list );
  var_stmt->Line( stmt_->Line() );
  fn_node->InsertBefore( var_stmt );
  fn_node->AddChild( ret );
}
}
