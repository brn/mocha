#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/fileroot_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/utils/utils.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
namespace mocha {

void FileRootProcessor::ProcessNode() {
  TranslatorData *translator_data = info()->translator_data();
  IVisitor* visitor = info()->visitor();
  bool is_runtime = translator_data->runtime();
  bool has_filescope = info()->translator_data()->compilation_info()->FileScope();
  bool has_module = info()->translator_data()->compilation_event()->IsUsed(CompilationEvent::kModule);
  if (!is_runtime) {
    Literal* add = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kAdd),
                                             Token::JS_IDENTIFIER, node()->line_number(), Literal::kProperty);
    Literal* module = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kModules),
                                                Token::JS_IDENTIFIER, node()->line_number(), Literal::kProperty);
    std::string key_str;
#ifndef PACKING_RUNTIME
    nexc_utils::ManglingName(&key_str, translator_data->filename(), translator_data->compilation_event()->path());
#else
    os::SPrintf(&key_str, "'%s'", translator_data->filename());
    key_str.erase(key_str.size() - 4, 3);
#endif
    ExpressionStmt* extend_global = NULL;
    if (!info()->translator_data()->compilation_event()->nomodule() &&
        has_module) {
      Literal* key = builder()->CreateNameNode(key_str.c_str(), Token::JS_STRING_LITERAL, node()->line_number(), Literal::kString);
                                                                
      CallExp* runtime_accessor = builder()->CreateRuntimeMod(module, node()->line_number());
      CallExp* add_accessor = builder()->CreateDotAccessor(runtime_accessor, add, node()->line_number());
      NodeList* args = builder()->CreateNodeList(1, key);
      CallExp* call = builder()->CreateNormalAccessor(add_accessor, args, node()->line_number());
      extend_global = builder()->CreateExpStmt(call, 2);
      key_str.erase(0, 1);
      key_str.erase(key_str.size() - 1, 1);
    } else {
      key_str = "";
    }
    info()->translator_data()->compilation_event()->unset_nomodule();
    if (has_filescope) {
      Function *fn = builder()->CreateFunctionDecl(new(pool()) Empty,
                                                   new(pool()) Empty, node(), 1);
      ExpressionStmt *stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, node()->line_number());
      if (extend_global != NULL) {
        if (info_->translator_data()->compilation_event()->IsUsed(CompilationEvent::kModule)) {
          fn->InsertBefore(extend_global);
        }
        fn->MarkAsRoot();
      }
      FileRoot* root = new(pool()) FileRoot(key_str.c_str());
      root->AddChild(stmt);
      node()->parent_node()->ReplaceChild(node(), root);
      info_->translator_data()->set_root(root);
      fn->Accept(visitor);
    } else {
      info_->translator_data()->set_root(node());
      if (extend_global != NULL) {
        node()->InsertBefore(extend_global);
      }
      NodeIterator iterator = node()->ChildNodes();
      while (iterator.HasNext()) {
        iterator.Next()->Accept(visitor);
      }
    }
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
