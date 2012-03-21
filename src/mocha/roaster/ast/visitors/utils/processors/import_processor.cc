#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/symbol_list.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/dsta_processor.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/import_processor.h>

namespace mocha {

ImportProccessor::ImportProccessor(ImportStmt* stmt, ProcessorInfo* info)
    : Processor(), stmt_(stmt), info_(info) {}

void ImportProccessor::ProcessNode() {
  IVisitor *visitor = info()->visitor();
  if (stmt_->expression_type() == ImportStmt::kDst) {
    DstaProcessor processor(stmt_->expression(), info());
    processor.ProcessNode();
  } else {
    stmt_->expression()->Accept(visitor);
  }
  AstNode* exp = 0;//init after;
  if (stmt_->module_type() == ImportStmt::kFile) {
    LoadModule_();
    AstNode *name = builder()->CreateNameNode(stmt_->module_key()->token(),
                                              Token::JS_STRING_LITERAL, stmt_->line_number(), Literal::kString);
    Literal *global = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalExport),
                                                Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    exp = builder()->CreateArrayAccessor(global, name, stmt_->line_number());
  } else {
    if (!stmt_->IsContainDestructuring()) {
      Literal *global = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                                  Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
      CallExp* dot = builder()->CreateDotAccessor(stmt_->from(), stmt_->expression(), stmt_->line_number());
      exp = builder()->CreateDotAccessor(global, dot, stmt_->line_number());
    } else {
      exp = stmt_->from();
    }
  }
  if (stmt_->from()->child_length() > 1 && stmt_->module_type() == ImportStmt::kFile) {
    NodeIterator iter = stmt_->from()->ChildNodes();
    iter.Next();
    while (iter.HasNext()) {
      Literal* item = iter.Next()->CastToLiteral();
      if (!item->IsEmpty()) {
        if (item->value_type() == Literal::kString) {
          exp = builder()->CreateArrayAccessor(exp, item, stmt_->line_number());
        } else {
          item->set_value_type(Literal::kProperty);
          exp = builder()->CreateDotAccessor(exp, item, stmt_->line_number());
        }
      }
    }
  }
  VariableDeclarationList* list = new(pool()) VariableDeclarationList(stmt_->line_number());
  if (stmt_->IsContainDestructuring()) {
    Literal* value = builder()->CreateVarInitiliser(stmt_->expression()->CastToLiteral()->value(), exp, stmt_->line_number());
    NodeList* var_list = DstaProcessor::CreateDstaExtractedVarStmt(stmt_, info());
    list->AddChild(value);
    list->Append(var_list);
    VariableStmt* stmt = builder()->CreateVarStmt(list, stmt_->line_number());
    stmt_->parent_node()->ReplaceChild(stmt_, stmt);
  } else {
    Literal* value = builder()->CreateVarInitiliser(stmt_->expression()->CastToLiteral()->value(), exp, stmt_->line_number());
    list->AddChild(value);
    VariableStmt* stmt = builder()->CreateVarStmt(list, stmt_->line_number());
    stmt_->parent_node()->ReplaceChild(stmt_, stmt);
  }
}


void ImportProccessor::LoadModule_() {
  VisitorInfo* visitor_info = info()->visitor_info();
  AstNode* from = stmt_->from();
  AstNode* file = from->first_child();
  Literal* value = file->CastToLiteral();

  if (value && value->value_type() == Literal::kString) {
    //Create path from js string literal.
    TokenInfo* info = value->value();
    std::string js_path = info->token();
    js_path.erase(0, 1);
    //"path to file" -> path to file
    js_path.erase(js_path.size() - 1, js_path.size());
                                                                
    SharedStr current_dir = os::fs::VirtualDirectory::GetInstance()->GetCurrentDir();
    bool is_runtime_module = false;
    //Get full path of module.
    SharedPtr<os::fs::Path> real_path = visitor_info->compiler()->Load(js_path.c_str(), &is_runtime_module);

    //Set virtual dir to current context dir.
    os::fs::VirtualDirectory::GetInstance()->Chdir(current_dir.Get());

    //Get module uuid key.
    os::fs::Path path(visitor_info->main_file_path());
    std::string mod_name = 
        visitor_info->compiler()->ModuleKey(((!is_runtime_module)?real_path->absolute_path() : real_path->raw_path()));
    std::string modkey = "'";
    modkey += mod_name;
    modkey += "'";
    TokenInfo* key = new(pool()) TokenInfo(modkey.c_str(), Token::JS_IDENTIFIER, stmt_->line_number());

    //Reserve module key string for later code generation.
    stmt_->set_module_key(key);
  }
}

}
