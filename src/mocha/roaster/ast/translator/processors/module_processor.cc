#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/module_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/ast/ast.h>
namespace mocha {

ModuleProcessor::ModuleProcessor(ModuleStmt* stmt, ProcessorInfo* info)
    : Processor(), stmt_(stmt), info_(info){};

void ModuleProcessor::ProcessNode() {
  TranslatorData* translator_data = info_->translator_data();
  AstNode* body = stmt_->first_child();
  AstNode* name = stmt_->name();
  bool is_runtime = translator_data->runtime();
  Function* fn_node = builder()->CreateFunctionDecl(name, new(pool()) Empty, body, stmt_->line_number());
  fn_node->set_name(new(pool()) Empty);
  builder()->FindDirectivePrologue(fn_node, fn_node);
  ExpressionStmt* an_stmt_node = ProcessBody_(body, fn_node, name);
  //For anonymous module.
  if (!name->IsEmpty()) {
    Literal* maybe_value = name->CastToLiteral();
    if (maybe_value) {
      maybe_value->set_value_type(Literal::kProperty);
    }
    ProcessAnonymousModule_(an_stmt_node, name, is_runtime);
  } else {
    stmt_->parent_node()->ReplaceChild(stmt_, an_stmt_node);
  }
  Finish_(name, fn_node);
}

/*
 * In anonymous modules,
 * all export properties are directly add to global export symbol.
 * Like this -> __MC_global_alias__.<name> = ...;
 */
void ModuleProcessor::ProcessAnonymousModule_(ExpressionStmt* an_stmt_node, AstNode* name, bool is_runtime) {
  TranslatorData* translator_data = info_->translator_data();
  if (!is_runtime) {
    Literal* alias = 0;
    if (translator_data->IsInModules()) {
      alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                         Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    } else {
      alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                         Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    }
    CallExp* dot_accessor = builder()->CreateDotAccessor(alias, name, stmt_->line_number());
    AssignmentExp* exp = builder()->CreateAssignment('=', dot_accessor, an_stmt_node->first_child(), stmt_->line_number());
    AstNode* stmt = 0;//init after.
    if (!name->IsEmpty()) {
      Literal* var_node = builder()->CreateVarInitiliser(name->CastToLiteral()->value(), exp, stmt_->line_number());
      stmt = builder()->CreateVarStmt(builder()->CreateVarDeclList(stmt_->line_number(), 1, var_node), stmt_->line_number());
    } else {
      stmt = builder()->CreateExpStmt(exp, stmt_->line_number());
    }
    stmt_->parent_node()->ReplaceChild(stmt_, stmt);
  } else {
    Literal *var_node = builder()->CreateVarInitiliser(name->CastToLiteral()->value(), an_stmt_node->first_child(), stmt_->line_number());
    VariableStmt *var_stmt = builder()->CreateVarStmt(builder()->CreateVarDeclList(stmt_->line_number(), 1, var_node), stmt_->line_number());
    stmt_->parent_node()->ReplaceChild(stmt_, var_stmt);
  }
}

/**
 * Create anonymous function call like (function(){ ... })()
 * to create module scopes.
 */
ExpressionStmt* ModuleProcessor::ProcessBody_(AstNode* body, Function* fn_node, AstNode*) {
  TranslatorData* translator_data = info_->translator_data();
  IVisitor* visitor = info_->visitor();
  ExpressionStmt* an_stmt_node = builder()->CreateAnonymousFnCall(fn_node, new(pool()) Empty, stmt_->line_number());
  translator_data->EnterModuel();
  body->Accept(visitor);
  translator_data->EscapeModuel();
  return an_stmt_node;
}


void ModuleProcessor::Finish_(AstNode* name, Function* fn_node) {
  TokenInfo* local = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kLocalExport),
                                            Token::JS_IDENTIFIER, stmt_->line_number());
  Literal* ret_local = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                                  Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
  Literal* init = 0;//init after.
  if (!name->IsEmpty()) {
    init = builder()->CreateVarInitiliser(local,
                                           builder()->CreateObjectLiteral(new(pool()) Empty, stmt_->line_number()), stmt_->line_number());
  } else {
    Literal* alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                                Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    init = builder()->CreateVarInitiliser(local, alias, stmt_->line_number());
  }
  VariableDeclarationList* list = new(pool()) VariableDeclarationList(stmt_->line_number());
  ReturnStmt* ret = builder()->CreateReturnStmt(ret_local, stmt_->line_number());
  list->AddChild(init);
  VariableStmt* var_stmt = builder()->CreateVarStmt(list, stmt_->line_number());
  fn_node->InsertBefore(var_stmt);
  fn_node->AddChild(ret);
}
}
