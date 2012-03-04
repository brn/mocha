#include <vector>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/yield_processor.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>

namespace mocha {

YieldProcessor::YieldProcessor(YieldExp* exp, ProcessorInfo* info) :
    exp_(exp), info_(info) {}

YieldProcessor::~YieldProcessor(){}

void YieldProcessor::ProcessNode() {
  AstNode *exp = exp_->parent_node();
  exp_->first_child()->Accept(info_->visitor());
  bool is_need_mark = true;
  if (exp && exp->parent_node()->node_type() == AstNode::kExpressionStmt) {
    ReturnStmt* ret = builder()->CreateReturnStmt(exp_->first_child()->Clone(pool()), exp->parent_node()->line_number());
    ret->ContainYield();
    ret->MarkAsSplitableStatement();
    exp->parent_node()->parent_node()->ReplaceChild(exp->parent_node(), ret);
    exp_ = ret->first_child();
  } else {
    ProcessSend_(exp);
    is_need_mark = false;
  }
  VisitorInfo* visitor_info = info_->visitor_info();
  AstNode* direct_child = exp_->parent_node();
  Function* fn = visitor_info->function();
  while (1) {
    if (direct_child->parent_node()->node_type() == AstNode::kFunction) {
      break;
    }
    direct_child = direct_child->parent_node();
    if (direct_child->node_type() == AstNode::kFor ||
         direct_child->node_type() == AstNode::kForWithVar ||
         direct_child->node_type() == AstNode::kForIn ||
         direct_child->node_type() == AstNode::kForInWithVar ||
         direct_child->node_type() == AstNode::kForEachWithVar ||
         direct_child->node_type() == AstNode::kForEach ||
         direct_child->node_type() == AstNode::kWhile ||
         direct_child->node_type() == AstNode::kDoWhile ||
         direct_child->node_type() == AstNode::kTryStmt ||
         direct_child->node_type() == AstNode::kIFStmt ||
         direct_child->node_type() == AstNode::kSwitchStmt) {
      Statement* stmt = direct_child->CastToStatement();
      stmt->ContainYield();
    }
  }
        
  if (!fn->IsGenerator()) {
    fn->MarkAsGenerator();
  }
  if (is_need_mark) {
    direct_child->CastToStatement()->ContainYield();
  }
}

void YieldProcessor::ProcessSend_(AstNode* exp) {
  ReturnStmt* ret = builder()->CreateReturnStmt(exp_->first_child()->Clone(pool()), exp->parent_node()->line_number());
  ret->ContainYield();
  ret->MarkAsSplitableStatement();
  while (!exp->CastToStatement()) {
    exp = exp->parent_node();
  }
  ret->ContainYield();
  exp->parent_node()->InsertBefore(ret, exp);
  AstNode* tmp = exp_->first_child()->Clone(pool());
  Literal* is_send = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSendFlag),
                                               Token::JS_IDENTIFIER, exp->line_number(), Literal::kIdentifier);
  Literal* to_array = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kToArray),
                                                Token::JS_IDENTIFIER, exp->line_number(), Literal::kProperty);
  Literal* arguments = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kArguments),
                                                 Token::JS_IDENTIFIER, exp->line_number(), Literal::kIdentifier);
  Literal* length = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLength),
                                              Token::JS_IDENTIFIER, exp->line_number(), Literal::kProperty);
  CallExp* dot = builder()->CreateDotAccessor(arguments, length, exp->line_number());
  Literal* two = builder()->CreateNameNode("2", Token::JS_NUMERIC_LITERAL, exp->line_number(), Literal::kNumeric);
  CompareExp* length_comp = new(pool()) CompareExp('>', dot, two, exp->line_number());
  CompareExp* comp = new(pool()) CompareExp(Token::JS_LOGICAL_AND, is_send, length_comp, exp->line_number());
  Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                 Token::JS_IDENTIFIER, exp->line_number(), Literal::kIdentifier);
  AstNode* no_arg;
  if (!tmp->IsEmpty()) {
    no_arg = new(pool()) ConditionalExp(is_send->Clone(pool()), tmp, undefined, exp->line_number());
  } else {
    no_arg = undefined;
  }
  NodeList* args = new(pool()) NodeList;
  args->AddChild(arguments->Clone(pool()));
  args->AddChild(two->Clone(pool()));
  Literal* zero = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, exp->line_number(), Literal::kNumeric);
  CallExp* normal = builder()->CreateNormalAccessor(to_array, args, exp->line_number());
  CallExp* runtime_call = builder()->CreateRuntimeMod(normal, exp->line_number());
  CallExp* array_accessor = builder()->CreateArrayAccessor(runtime_call, zero, exp->line_number());
  ConditionalExp* cond = new(pool()) ConditionalExp(comp, array_accessor, no_arg, exp->line_number());
  Literal* tmp_ret = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldResult),
                                               Token::JS_IDENTIFIER, exp->line_number(), Literal::kIdentifier);
  AssignmentExp* assign = builder()->CreateAssignment('=', tmp_ret, cond, exp->line_number());
  ExpressionStmt* stmt = builder()->CreateExpStmt(assign, exp->line_number());
  ret->parent_node()->InsertAfter(stmt, ret);
  AstNode* send_val = tmp_ret->Clone(pool());
  exp_->parent_node()->ReplaceChild(exp_, send_val);
  exp_ = send_val;
}

}
