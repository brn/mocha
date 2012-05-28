#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/processors/call_processor.h>
#include <mocha/roaster/ast/translator/processors/class_processor.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
namespace mocha {

void CallProcessor::ProcessPrivateAccessor() {
  Literal* maybe_ident = ast_node_->callable()->CastToLiteral();
  if (maybe_ident) {
    Literal* private_field = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGetPrivateRecord),
                                            Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
    CallExp* runtime_call = builder()->CreateRuntimeMod(private_field, ast_node_->line_number());
    ast_node_->set_callable(runtime_call);
    ast_node_->set_call_type(CallExp::kNormal);
    ast_node_->Accept(info_->visitor());
  }
}


void CallProcessor::CallSuper (CallExp* ast_node_, bool direct_call) {
  AstNode* args = ast_node_->args();
  Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                Token::JS_THIS, ast_node_->line_number(), Literal::kThis);
  Literal* call = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCall),
                                            Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
  if (direct_call) {
    Literal* constructor = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                     Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
    CallExp* constructor_accessor = builder()->CreateDotAccessor(ast_node_->callable(), constructor, ast_node_->line_number());
    CallExp* normal = builder()->CreateDotAccessor(constructor_accessor, call, ast_node_->line_number());
    ast_node_->set_callable(normal);
  } else {
    CallExp* normal = builder()->CreateDotAccessor(ast_node_->callable(), call, ast_node_->line_number());
    ast_node_->set_callable(normal);
  }
  if (!args->IsEmpty()) {
    ast_node_->args()->InsertBefore(this_sym);
  } else {
    NodeList* args = builder()->CreateNodeList(1, this_sym);
    ast_node_->set_args(args);
  }
}


void CallProcessor::ProcessFnCall() {
  IVisitor *visitor = info_->visitor();
  AstNode* args = ast_node_->args();
  AstNode* callable = ast_node_->callable();
  if (callable->node_type() == AstNode::kLiteral &&
       callable->CastToLiteral()->value_type() == Literal::kSuper) {
    ast_node_->callable()->Accept(visitor);
    CallSuper(ast_node_, true);
  } else {
    AstNode* tmp = ast_node_->callable();
    while (tmp->node_type() != AstNode::kLiteral) {
      if (tmp->node_type() == AstNode::kCallExp) {
        tmp = tmp->CastToExpression()->CastToCallExp()->callable();
      } else {
        break;
      }
    }
    if (tmp->node_type() == AstNode::kLiteral) {
      Literal* val = tmp->CastToLiteral();
      if (val->value_type() == Literal::kSuper) {
        CallSuper(ast_node_, false);
      }
    }
    ast_node_->callable()->Accept(visitor);
  }
  
  if (!args->IsEmpty()) {
    if (ast_node_->spread()) {
      info_->translator_data()->compilation_event()->Use(CompilationEvent::kSpread);
      AstNode* tmp = ast_node_->callable();
      if (tmp->node_type() == AstNode::kCallExp) {
        tmp = tmp->CastToExpression()->CastToCallExp()->callable();
      } else {
        tmp = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                        Token::JS_IDENTIFIER, ast_node_->line_number(),
                                        Literal::kUndefined);
      }
      if (tmp) {
        NodeIterator iterator = ast_node_->args()->ChildNodes();
        ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(ast_node_->line_number());
        bool is_new = ast_node_->parent_node()->node_type() == AstNode::kNewExp;
        while (iterator.HasNext()) {
          AstNode* item = iterator.Next();
          Literal* lit = item->CastToLiteral();
          if (lit && lit->value_type() == Literal::kSpread) {
            Literal* bool_value = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                                            Token::JS_TRUE, ast_node_->line_number(),
                                                            Literal::kTrue);
            array->set_element(bool_value);
            array->set_element(item->first_child()->Clone(pool()));
          } else {
            item->Accept(visitor);
            Literal* bool_value = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFalse),
                                                            Token::JS_FALSE, ast_node_->line_number(),
                                                            Literal::kFalse);
            array->set_element(bool_value);
            array->set_element(item->Clone(pool()));
          }
        }
        Literal* make_spread = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kSpreadCall),
                                                         Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
        Literal* bool_value = builder()->CreateNameNode(SymbolList::symbol((is_new)? SymbolList::kTrue : SymbolList::kFalse),
                                                        (is_new)?Token::JS_TRUE : Token::JS_FALSE,
                                                        ast_node_->line_number(), (is_new)? Literal::kTrue : Literal::kFalse);
        NodeList* args = builder()->CreateNodeList(4, tmp->Clone(pool()), ast_node_->callable()->Clone(pool()),
                                                   array, bool_value);
        CallExp* runtime_call = builder()->CreateRuntimeMod(make_spread, tmp->line_number());
        CallExp* call = builder()->CreateNormalAccessor(runtime_call, args, tmp->line_number());
        if (is_new) {
          ast_node_->parent_node()->parent_node()->ReplaceChild(ast_node_->parent_node(), call);
        } else {
          ast_node_->parent_node()->ReplaceChild(ast_node_, call);
        }
      }
    } else {
      NodeIterator iterator = ast_node_->args()->ChildNodes();
      while (iterator.HasNext()) {
        iterator.Next()->Accept(visitor);
      }
    }
  }
}

void CallProcessor::ProcessExtendAccessor() {
  IVisitor *visitor = info_->visitor();
  ast_node_->callable()->Accept(visitor);
  ast_node_->args()->Accept(visitor);
  CallExp* clone = ast_node_->Clone(pool())->CastToExpression()->CastToCallExp();
  Literal* extend = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kExtend),
                                              Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
  NodeList* args = builder()->CreateNodeList(2, clone->callable(), ast_node_->args());
  CallExp* extend_call = builder()->CreateNormalAccessor(extend, args, ast_node_->line_number());
  CallExp* extend_acessor = builder()->CreateRuntimeMod(extend_call, ast_node_->line_number());
  ast_node_->parent_node()->ReplaceChild(ast_node_, extend_acessor);
}

}
