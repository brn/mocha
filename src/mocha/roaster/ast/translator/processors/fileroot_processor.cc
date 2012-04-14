#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/fileroot_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/utils/utils.h>
namespace mocha {

void FileRootProcessor::ProcessNode() {
  TranslatorData *translator_data = info()->translator_data();
  IVisitor* visitor = info()->visitor();
  bool is_runtime = translator_data->runtime();
  if (!is_runtime) {
    Function *fn = builder()->CreateFunctionDecl(new(pool()) Empty,
                                                  new(pool()) Empty, node(), 1);
    ExpressionStmt *stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, node()->line_number());
    Literal* global_export = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalExport),
                                                       Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    ObjectLikeLiteral* object_literal = new(pool()) ObjectLikeLiteral(node()->line_number());
    std::string key_str;
#ifndef PACKING_RUNTIME
    nexc_utils::ManglingName(&key_str, translator_data->filename(), translator_data->compilation_event()->path());
#else
    os::SPrintf(&key_str, "'%s'", translator_data->filename());
    key_str.erase(key_str.size() - 4, 3);
#endif
    Literal* key = builder()->CreateNameNode(key_str.c_str(), Token::JS_STRING_LITERAL, node()->line_number(), Literal::kString);
                                                                
    CallExp* global_export_accessor = builder()->CreateArrayAccessor(global_export, key, node()->line_number());
    AssignmentExp* exp = builder()->CreateAssignment('=', global_export_accessor, object_literal, node()->line_number());

    Literal* alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                               Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    Literal* init = builder()->CreateVarInitiliser(alias->value(), global_export_accessor->Clone(pool()), node()->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(node()->line_number(), 1, init);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, 3);
    ExpressionStmt* extend_global = builder()->CreateExpStmt(exp, 2);
    key_str.erase(0, 1);
    key_str.erase(key_str.size() - 1, 1);
    FileRoot* root = new(pool()) FileRoot(key_str.c_str());
    root->AddChild(stmt);
    fn->InsertBefore(var_stmt);
    fn->InsertBefore(extend_global);
    fn->MarkAsRoot();
    node()->parent_node()->ReplaceChild(node(), root);
    info_->translator_data()->set_root(root);
    fn->Accept(visitor);
  } else {
    node()->set_runtime();
    info_->translator_data()->set_root(node());
    NodeIterator iterator = node()->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(visitor);
    }
  }
}

}
