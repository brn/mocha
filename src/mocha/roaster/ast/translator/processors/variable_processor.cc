#include <string.h>
#include <mocha/roaster/ast/translator/processors/variable_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
namespace mocha {

void VariableProcessor::ProcessVarList(AstNode* ast_node, ProcessorInfo* info) {
  IVisitor* visitor = info->visitor();
  NodeIterator iterator = ast_node->ChildNodes();
  bool has_dsta = false;
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (!item->IsEmpty()) {
      if (LocalBuilder()->IsDestructringLeftHandSide(item)) {
        has_dsta = true;
        Statement stmt;
        info->translator_data()->set_current_statement(&stmt);
        DstaProcessor processor(item, info);
        Literal* value = processor.ProcessNode();
        value->set_value_type(Literal::kVariable);
        AstNode* initialiser = value->first_child();
        if (!initialiser->IsEmpty()) {
          initialiser->Accept(visitor);
        }
        Function* fn = info->translator_data()->function();
        if (fn) {
          fn->set_variable_list(value);
        }
        NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt(&stmt, info);
        NodeIterator dsta_it = list->ChildNodes();
        AstNode* last = value;
        while (dsta_it.HasNext()) {
          AstNode* node = dsta_it.Next();
          ast_node->InsertAfter(node, last);
          last = node;
        }
      } else {
        if (!item->IsEmpty()) {
          ProcessVarInitialiser(item->CastToLiteral(), info);
        }
      }
    }
  }
  if (has_dsta) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* var = iterator.Next();
      Literal* var_literal = var->CastToLiteral();
      if (var_literal->first_child()->CastToLiteral()) {
        Literal* literal = var_literal->first_child()->CastToLiteral();
        if (literal->value_type() == Literal::kIdentifier) {
          if (strcmp(var_literal->value()->token(), literal->value()->token()) == 0) {
            if (var_literal->parent_node()->child_length() == 1) {
              ast_node->parent_node()->parent_node()->RemoveChild(ast_node->parent_node());
            } else {
              var_literal->parent_node()->RemoveChild(var_literal);
            }
          }
        }
      }
    }
  }
}


void VariableProcessor::ProcessVarInitialiser(Literal* ast_node, ProcessorInfo* info) {
  Function* fn = info->translator_data()->function();
  if (fn) {
    fn->set_variable_list(ast_node);
  }
  AstNode* initialiser = ast_node->first_child();
  if (initialiser && !initialiser->IsEmpty()) {
    initialiser->Accept(info->visitor());
  }  
}

}
