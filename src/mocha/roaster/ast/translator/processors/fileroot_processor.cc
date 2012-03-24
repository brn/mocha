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
  NodeIterator iterator = node()->ChildNodes();
  bool is_runtime = translator_data->runtime();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(visitor);
  }
  if (!is_runtime) {
    Function *fn = builder()->CreateFunctionDecl(new(pool()) Empty,
                                                  new(pool()) Empty, node(), 1);
    ExpressionStmt *stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, node()->line_number());
    Literal* global_export = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalExport),
                                                       Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    ObjectLikeLiteral* object_literal = new(pool()) ObjectLikeLiteral(node()->line_number());
    std::string key_str;
    nexc_utils::ManglingName(&key_str, translator_data->filename(), translator_data->compilation_event()->path());
    Literal* key = builder()->CreateNameNode(key_str.c_str(), Token::JS_STRING_LITERAL, node()->line_number(), Literal::kString);
                                                                
    CallExp* global_export_accessor = builder()->CreateArrayAccessor(global_export, key, node()->line_number());
    AssignmentExp* exp = builder()->CreateAssignment('=', global_export_accessor, object_literal, node()->line_number());

    Literal* alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                               Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    Literal* init = builder()->CreateVarInitiliser(alias->value(), global_export_accessor->Clone(pool()), node()->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(node()->line_number(), 1, init);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, 3);
    ExpressionStmt* extend_global = builder()->CreateExpStmt(exp, 2);
    FileRoot* root = new(pool()) FileRoot(node()->filename());
    root->AddChild(stmt);
    fn->InsertBefore(var_stmt);
    fn->InsertBefore(extend_global);
    fn->MarkAsRoot();
    node()->parent_node()->ReplaceChild(node(), root);
  } else {
    node()->set_runtime();
  }
}

}
