#include <sstream>
#include <mocha/roaster/ast/translator/processors/array_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/processors/syntax_sugar_processor.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
namespace mocha {

ArrayProcessor::ArrayProcessor(ArrayLikeLiteral* literal, ProcessorInfo* info)
    : Processor(), literal_(literal), info_(info){}

void ArrayProcessor::ProcessNode() {
  IVisitor* visitor = info()->visitor();
  if (node()->IsComprehensions()) {
    SyntaxSugarProcessor::ProcessArrayComprehensions(node(), info());
  } else if (node()->IsTuple()) {
    ProcessTuple();
  } else {
    NodeIterator iterator = node()->elements()->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      element->Accept(visitor);
    }
  }
}

void ArrayProcessor::ProcessTuple() {
  IVisitor* visitor = info()->visitor();
  Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTuple),
                                            Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
  NewExp* new_exp = new(pool()) NewExp(node()->line_number());
  CallExp* call = builder()->CreateNormalAccessor(name, node()->elements(), node()->line_number());
  new_exp->AddChild(call);
  node()->parent_node()->ReplaceChild(node(), new_exp);
}

}
