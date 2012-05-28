#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/virtual_directory/virtual_directory.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/processors/import_processor.h>

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
    LoadModule();
    AstNode *name = builder()->CreateNameNode(stmt_->module_key()->token(),
                                              Token::JS_STRING_LITERAL, stmt_->line_number(), Literal::kString);
    Literal* get = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGet),
                                             Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kProperty);
    Literal* module = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kModules),
                                                Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kProperty);
    CallExp* runtime_accessor = builder()->CreateRuntimeMod(module, stmt_->line_number());
    CallExp* add_accessor = builder()->CreateDotAccessor(runtime_accessor, get, stmt_->line_number());
    NodeList* args = builder()->CreateNodeList(1, name);
    exp = builder()->CreateNormalAccessor(add_accessor, args, stmt_->line_number());
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
  
  typedef std::vector<TokenInfo*> PropertyArray;
  PropertyArray property_array;
  AstNode* expression = (stmt_->module_type() == ImportStmt::kAs)? stmt_->expression() : stmt_->from();
  if (expression->child_length() > 1 && stmt_->module_type() == ImportStmt::kFile) {
    NodeIterator iter = stmt_->from()->ChildNodes();
    iter.Next();
    while (iter.HasNext()) {
      Literal* item = iter.Next()->CastToLiteral();
      if (!item->IsEmpty()) {
        if (item->value_type() == Literal::kString) {
          property_array.push_back(item->CastToLiteral()->value());
          exp = builder()->CreateArrayAccessor(exp, item, stmt_->line_number());
        } else {
          item->set_value_type(Literal::kProperty);
          property_array.push_back(item->CastToLiteral()->value());
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
    TokenInfo* expression =
        (stmt_->module_type() == ImportStmt::kAs)? stmt_->from()->CastToLiteral()->value() :
        stmt_->expression()->CastToLiteral()->value();
    TranslatorData* translator_data = info_->translator_data();
    if (stmt_->expression_type() == ImportStmt::kAll) {
      FileRoot* root = translator_data->compilation_event()->nexc()->ast(stmt_->filename()->token());
      if (root && root->modules().size() > 0) {
        Literal* tmp_node = builder()->CreateTmpNode(translator_data->tmp_index(), stmt_->line_number());
        Literal* tmp_value = builder()->CreateVarInitiliser(tmp_node->value(), exp, stmt_->line_number());
        list->AddChild(tmp_value);
        ModuleStmt* searched = NULL;
        if (property_array.size() > 0) {
          PropertyArray::iterator it = property_array.begin();
          searched = root->FindModule((*it)->token());
          if (searched != NULL) {
            ++it;
            if (it != property_array.end()) {
              for (; it != property_array.end(); ++it) {
                searched = searched->FindModule((*it)->token());
                if (searched == NULL) {
                  break;
                }
              }
            }
          } else {
            stmt_->parent_node()->RemoveChild(stmt_);
          }
          if (searched != NULL) {
            MakeVariables(searched->exports(), tmp_node, list);
            MakeVariables(searched->modules(), tmp_node, list);
            VariableStmt* stmt = builder()->CreateVarStmt(list, stmt_->line_number());
            stmt_->parent_node()->ReplaceChild(stmt_, stmt);
          } else {
            stmt_->parent_node()->RemoveChild(stmt_);
          }
        } else {
          MakeVariables(root->modules(), tmp_node, list);
          VariableStmt* stmt = builder()->CreateVarStmt(list, stmt_->line_number());
          stmt_->parent_node()->ReplaceChild(stmt_, stmt);
        }
      } else {
        Literal* tmp_node = builder()->CreateTmpNode(translator_data->tmp_index(), stmt_->line_number());
        Literal* tmp_value = builder()->CreateVarInitiliser(tmp_node->value(), exp, stmt_->line_number());
        list->AddChild(tmp_value);
        stmt_->parent_node()->RemoveChild(stmt_);
      }
    } else {
      Literal* value = builder()->CreateVarInitiliser(expression, exp, stmt_->line_number());
      list->AddChild(value);
      VariableStmt* stmt = builder()->CreateVarStmt(list, stmt_->line_number());
      stmt_->parent_node()->ReplaceChild(stmt_, stmt);
    }
  }
}

Literal* GetName(const ModuleStmt* stmt) {return stmt->name()->CastToLiteral();}
Literal* GetName(Literal* lit) {return lit;}

template <typename T>
void ImportProccessor::MakeVariables(const T& list, AstNode* tmp_node, VariableDeclarationList* vars) {
  typename T::const_iterator it = list.begin();
  for (; it != list.end(); ++it) {
    Literal* name = GetName(it->second);
    CallExp* dot = builder()->CreateDotAccessor(tmp_node->Clone(pool()),
                                                name->Clone(pool()), stmt_->line_number());
    Literal* value = builder()->CreateVarInitiliser(name->value(), dot, stmt_->line_number());
    vars->AddChild(value);
  }
}

void ImportProccessor::LoadModule() {
  TranslatorData* translator_data = info()->translator_data();
  AstNode* from = stmt_->from();
  AstNode* file = from->first_child();
  Literal* value = file->CastToLiteral();

  if (value && value->value_type() == Literal::kString) {
    //Create path from js string literal.
    TokenInfo* info = value->value();
    std::string js_path = info->token();
    //"path to file" -> path to file
    js_path.erase(0, 1);
    js_path.erase(js_path.size() - 1, js_path.size());
    std::string modkey;
    std::string filename_buf;
    //Get full path of module.
    translator_data->compilation_event()->nexc()->ImportFile(&modkey, &filename_buf, js_path.c_str(), translator_data->compilation_event());
    TokenInfo* key = new(pool()) TokenInfo(modkey.c_str(), Token::JS_IDENTIFIER, stmt_->line_number());
    TokenInfo* filename = new(pool()) TokenInfo(filename_buf.c_str(), Token::JS_IDENTIFIER, stmt_->line_number());
    //Reserve module key string for later code generation.
    stmt_->set_module_key(key);
    stmt_->set_filename(filename);
  }
}

}
