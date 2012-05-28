#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/module_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/utils/utils.h>
#include <mocha/roaster/ast/ast.h>
namespace mocha {

ModuleProcessor::ModuleProcessor(ModuleStmt* stmt, ProcessorInfo* info)
    : Processor(), stmt_(stmt), info_(info){};


void ModuleProcessor::ProcessNode() {
  TranslatorData* translator_data = info_->translator_data();
  AstNode* body = stmt_->first_child();
  Literal* name = stmt_->name()->CastToLiteral();
  bool is_runtime = translator_data->runtime();
  if (translator_data->IsInModules()) {
    translator_data->modules()->back()->SetModule(name->value()->token(), stmt_);
  } else {
    stmt_->MarkAsRoot();
    translator_data->file_root()->SetModule(name->value()->token(), stmt_);
  }
  translator_data->EnterModule(stmt_);
  AstNode* result;
  if (stmt_->module_type() == ModuleStmt::kBlock) {
    Function* fn_node = builder()->CreateFunctionDecl(name, new(pool()) Empty, body, stmt_->line_number());
    fn_node->set_name(new(pool()) Empty);
    builder()->FindDirectivePrologue(fn_node, fn_node);
    result = ProcessBody(body, fn_node, name);
    result = result->first_child();
    name->CastToLiteral()->set_value_type(Literal::kProperty);
    ProcessModule(result, name, is_runtime);
    Finish(name, fn_node);
  } else {
    result = ProcessAssignment(body, name);
    name->CastToLiteral()->set_value_type(Literal::kProperty);
    ProcessModule(result, name, is_runtime);
  }
}

/*
 * In anonymous modules,
 * all export properties are directly add to global export symbol.
 * Like this -> __MC_global_alias__.<name> = ...;
 */
void ModuleProcessor::ProcessModule(AstNode* node, AstNode* name, bool is_runtime) {
  TranslatorData* translator_data = info_->translator_data();
  if (!is_runtime) {
    AstNode* alias = 0;
    if (translator_data->IsInModules()) {
      alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                         Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    } else {
      Literal* get = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGet),
                                               Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kProperty);
      Literal* module = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kModules),
                                                  Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kProperty);
      std::string key_str;
#ifndef PACKING_RUNTIME
      nexc_utils::ManglingName(&key_str, translator_data->filename(), translator_data->compilation_event()->path());
#else
      os::SPrintf(&key_str, "'%s'", translator_data->filename());
      key_str.erase(key_str.size() - 4, 3);
#endif
      Literal* key = builder()->CreateNameNode(key_str.c_str(), Token::JS_STRING_LITERAL, stmt_->line_number(), Literal::kString);
                                                                
      CallExp* runtime_accessor = builder()->CreateRuntimeMod(module, stmt_->line_number());
      CallExp* add_accessor = builder()->CreateDotAccessor(runtime_accessor, get, stmt_->line_number());
      NodeList* args = builder()->CreateNodeList(1, key);
      alias = builder()->CreateNormalAccessor(add_accessor, args, stmt_->line_number());
    }
    CallExp* dot_accessor = builder()->CreateDotAccessor(alias, name, stmt_->line_number());
    AssignmentExp* exp = builder()->CreateAssignment('=', dot_accessor, node, stmt_->line_number());
    Literal* var_node = builder()->CreateVarInitiliser(name->CastToLiteral()->value(), exp, stmt_->line_number());
    AstNode* stmt = builder()->CreateVarStmt(builder()->CreateVarDeclList(stmt_->line_number(), 1, var_node), stmt_->line_number());
    stmt_->parent_node()->ReplaceChild(stmt_, stmt);
  } else {
    Literal *var_node =
        builder()->CreateVarInitiliser(name->CastToLiteral()->value(), node, stmt_->line_number());
    VariableStmt *var_stmt = builder()->CreateVarStmt(builder()->CreateVarDeclList(stmt_->line_number(), 1, var_node), stmt_->line_number());
    stmt_->parent_node()->ReplaceChild(stmt_, var_stmt);
  }
}

/**
 * Create anonymous function call like (function(){ ... })()
 * to create module scopes.
 */
AstNode* ModuleProcessor::ProcessBody(AstNode* body, Function* fn_node, AstNode*) {
  TranslatorData* translator_data = info_->translator_data();
  IVisitor* visitor = info_->visitor();
  ExpressionStmt* an_stmt_node = builder()->CreateAnonymousFnCall(fn_node, new(pool()) Empty, stmt_->line_number());
  body->Accept(visitor);
  translator_data->EscapeModule();
  return an_stmt_node;
}


AstNode* ModuleProcessor::ProcessAssignment(AstNode* body, AstNode*) {
  TranslatorData* translator_data = info_->translator_data();
  IVisitor* visitor = info_->visitor();
  body->Accept(visitor);
  translator_data->EscapeModule();
  return body;
}


void ModuleProcessor::Finish(AstNode* name, AstNode* node) {
  TokenInfo* local = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kLocalExport),
                                            Token::JS_IDENTIFIER, stmt_->line_number());
  Literal* ret_local = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                                  Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
  ObjectLikeLiteral* object =
      builder()->CreateObjectLiteral(new(pool()) Empty, stmt_->line_number());
  Literal* init = builder()->CreateVarInitiliser(local, object, stmt_->line_number());
  VariableDeclarationList* list = new(pool()) VariableDeclarationList(stmt_->line_number());
  ReturnStmt* ret = builder()->CreateReturnStmt(ret_local, stmt_->line_number());
  list->AddChild(init);
  VariableStmt* var_stmt = builder()->CreateVarStmt(list, stmt_->line_number());
  node->InsertBefore(var_stmt);
  node->AddChild(ret);
}
}
