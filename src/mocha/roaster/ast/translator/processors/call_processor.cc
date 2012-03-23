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
    CallExp* runtime_call = builder()->BuildPrivateRecordAccessor(ast_node_->line_number());
    ast_node_->set_callable(runtime_call);
    maybe_ident = ast_node_->args()->CastToLiteral();
    if (maybe_ident && maybe_ident->value_type() == Literal::kProperty) {
      ast_node_->set_call_type(CallExp::kDot);
    } else {
      ast_node_->set_call_type(CallExp::kBracket);
    }
  }
}


void CallProcessor::CallSuper (CallExp* ast_node_) {
  AstNode* args = ast_node_->args();
  Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                Token::JS_THIS, ast_node_->line_number(), Literal::kThis);
  Literal* call = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCall),
                                            Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
  Literal* constructor = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                   Token::JS_IDENTIFIER, ast_node_->line_number(), Literal::kProperty);
  CallExp* constructor_accessor = builder()->CreateDotAccessor(ast_node_->callable(), constructor, ast_node_->line_number());
  CallExp* normal = builder()->CreateDotAccessor(constructor_accessor, call, ast_node_->line_number());
  ast_node_->set_callable(normal);
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
    CallSuper(ast_node_);
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
        CallSuper(ast_node_);
      }
    }
    ast_node_->callable()->Accept(visitor);
  }
  if (!args->IsEmpty()) {
    NodeIterator iterator = ast_node_->args()->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(visitor);
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
