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
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(node()->line_number());
  NodeList* list = new(pool()) NodeList;
  NodeIterator iterator = node()->elements()->ChildNodes();
  int count = 0;
  while (iterator.HasNext()) {
    std::stringstream st;
    st << count;
    std::string cnt = st.str();
    Literal* num = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL, node()->line_number(), Literal::kNumeric);
    AstNode* item = iterator.Next();
    item->Accept(visitor);
    num->AddChild(item);
    list->AddChild(num);
    count++;
  }
  std::stringstream st;
  st << count;
  Literal* num = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL, node()->line_number(), Literal::kNumeric);
  object->Append(list);
  Literal* create_tuple = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCreateTuple),
                                                     Token::JS_IDENTIFIER, node()->line_number(), Literal::kProperty);
  CallExp* runtime_accessor = builder()->CreateRuntimeMod(create_tuple, node()->line_number());
  NodeList* args = builder()->CreateNodeList(2, object, num);
  CallExp* runtime_call = builder()->CreateNormalAccessor(runtime_accessor, args, node()->line_number());
  node()->parent_node()->ReplaceChild(node(), runtime_call);
}

}
