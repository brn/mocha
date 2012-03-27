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
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (!item->IsEmpty()) {
      if (LocalBuilder()->IsDestructringLeftHandSide(item)) {
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
      } else {
        if (!item->IsEmpty()) {
          ProcessVarInitialiser(item->CastToLiteral(), info);
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
