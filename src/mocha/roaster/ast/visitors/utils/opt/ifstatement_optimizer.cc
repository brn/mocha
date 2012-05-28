#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/ast/visitors/utils/opt/ifstatement_optimizer.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/optimizer_visitor.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>

namespace mocha {

bool IFStmtOptimizer::IsOptimizableBlock(AstNode* block, int type) {
  if (block->node_type() == AstNode::kBlockStmt) {
    if (block->child_length() == 1) {
      if (type == kElse && block->first_child()->node_type() == AstNode::kIFStmt) {
        return false;
      }
      return true;
    }
  }
  return false;
}

AstNode* IFStmtOptimizer::GetReturnValue(AstNode* node) {
  if (node->IsEmpty()) {
    return builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                     Token::JS_IDENTIFIER, node->line_number(), Literal::kIdentifier);
  }
  return node;
}


bool IFStmtOptimizer::CheckAssoc(AstNode* node) {
  if (node->node_type() == AstNode::kObjectLikeLiteral) {
    return true;
  } else if (node->node_type() == AstNode::kAssignmentExp) {
    return true;
  } else if (node->node_type() == AstNode::kCompareExp) {
    CompareExp* comp = node->CastToExpression()->CastToCompareExp();
    if (comp->operand() == Token::JS_LOGICAL_OR) {
      return true;
    }
  } else if (node->node_type() == AstNode::kExpression) {
    if (node->child_length() > 1) {
      return true;
    }
  }
  return false;
}

AstNode* IFStmtOptimizer::ToExpression(AstNode* node) {
  if (this->CheckAssoc(node)) {
    if (node->node_type() == AstNode::kExpression) {
      node->CastToExpression()->MarkParenthesis();
      return node;
    } else {
      Expression* exp = new(pool()) Expression(node->line_number());
      exp->AddChild(node);
      exp->MarkParenthesis();
      return exp;
    }
  }
  return node;
}

IFStmtOptimizer::IFStmtOptimizer(CompilationInfo* info, IFStmt* stmt) :
    Processor(), info_(info), stmt_(stmt){}


void IFStmtOptimizer::Optimize(IVisitor* visitor) {
  stmt_->condition()->Accept(visitor);
  stmt_->then_statement()->Accept(visitor);
  stmt_->else_statement()->Accept(visitor);
  DetermineOptimizeType();
}


void IFStmtOptimizer::DetermineOptimizeType() {
  AstNode* then_block = stmt_->then_statement();
  AstNode* else_block = stmt_->else_statement();
  OptimizeBlock(then_block, kThen);
  OptimizeBlock(else_block, kElse);
  ToIFStmtCompatibleExpression();
}

int IFStmtOptimizer::IsConvertableToExpression(AstNode* then_stmt, AstNode* else_stmt) {
  if (IsOptimizableBlock(then_stmt, kThen)) {
    return kNone;
  }
  if (IsOptimizableBlock(else_stmt, kElse)) {
    return kNone;
  }
  if (else_stmt->node_type() != AstNode::kIFStmt) {
    int then_type = then_stmt->node_type();
    int else_type = else_stmt->node_type();
    if (then_type == AstNode::kReturnStmt &&
         else_type == AstNode::kReturnStmt) {
      return kCondtionalReturn;
    } else if ((then_type == AstNode::kReturnStmt ||
                  then_type == AstNode::kBreakStmt ||
                  then_type == AstNode::kContinueStmt ||
                  then_type == AstNode::kThrowStmt) &&
                else_type != AstNode::kEmpty) {
      return kNoElse;
    } else if (then_type == AstNode::kExpressionStmt &&
                else_type == AstNode::kEmpty) {
      return kLogical;
    } else if (then_type == AstNode::kExpressionStmt &&
                else_type == AstNode::kExpressionStmt) {
      return kConditional;
    }
  }
  return kNone;
}

void IFStmtOptimizer::OptimizeBlock(AstNode* block, int type) {
  if (IsOptimizableBlock(block, type)) {
    AstNode* insert = block->first_child();
    if (type == kThen) {
      stmt_->set_then_statement(insert);
    } else {
      stmt_->set_else_statement(insert);
    }
  }
}

void IFStmtOptimizer::ToIFStmtCompatibleExpression() {
  AstNode* then_block = stmt_->then_statement();
  AstNode* else_block = stmt_->else_statement();
  int type = IsConvertableToExpression(then_block, else_block);
  switch (type) {
    case kCondtionalReturn :
      ToConditionalReturn(then_block, else_block);
      break;

    case kLogical :
      ToLogical(then_block);
      break;

    case kNoElse :
      ToNoElse(then_block, else_block);
      break;

    case kConditional :
      ToConditional(then_block, else_block);
      break;
  }
}

void IFStmtOptimizer::ToConditionalReturn(AstNode* then_stmt, AstNode* else_stmt) {
  AstNode* then_return = GetReturnValue(then_stmt->first_child());
  AstNode* else_return = GetReturnValue(else_stmt->first_child());
  ConditionalExp* cond = new(pool()) ConditionalExp(stmt_->condition(),
                                                     then_return,
                                                     else_return,
                                                     then_stmt->line_number());
  ReturnStmt* ret = new(pool()) ReturnStmt(then_stmt->line_number());
  ret->AddChild(cond);
  stmt_->parent_node()->ReplaceChild(stmt_, ret);
}


void IFStmtOptimizer::ToLogical(AstNode* then_stmt) {
  AstNode* cond = ToExpression(stmt_->condition());
  AstNode* then_exp = ToExpression(then_stmt->first_child());
  CompareExp* logical = new(pool()) CompareExp(Token::JS_LOGICAL_AND, cond, then_exp, then_stmt->line_number());
  ExpressionStmt* stmt = builder()->CreateExpStmt(logical, then_stmt->line_number());
  stmt_->parent_node()->ReplaceChild(stmt_, stmt);
}

void IFStmtOptimizer::ToNoElse(AstNode*, AstNode* else_stmt) {
  stmt_->set_else_statement(new(pool()) Empty);
  stmt_->parent_node()->InsertAfter(else_stmt, stmt_);
}

void IFStmtOptimizer::ToConditional(AstNode* then_stmt, AstNode* else_stmt) {
  ConditionalExp* cond = new(pool()) ConditionalExp(stmt_->condition(),
                                                     then_stmt->first_child(),
                                                     else_stmt->first_child(),
                                                     then_stmt->line_number());
  ExpressionStmt* stmt = builder()->CreateExpStmt(cond, then_stmt->line_number());
  stmt_->parent_node()->ReplaceChild(stmt_, stmt);
}

}
