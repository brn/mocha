#include <string.h>
#include <stdio.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/optimizer_visitor.h>
#include <mocha/roaster/ast/visitors/utils/opt/constant_optimizer.h>
#include <mocha/roaster/ast/visitors/utils/opt/ifstatement_optimizer.h>
#include <mocha/roaster/tokens/symbol_list.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/utils/compilation_info.h>
namespace mocha {

#define VISITOR_IMPL(type) void OptimizerVisitor::Visit##type(type* ast_node)
#ifdef PRINTABLE
#define PRINT_NODE_NAME fprintf(stderr, "depth = %d name = %s\n", depth_++, ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif


OptimizerVisitor::OptimizerVisitor(CompilationInfo* info) :
    depth_(0),
    is_debug_(info->Debug()),
    info_(info),
    pool_(memory::Pool::Local()),
    builder_(AstBuilder::Local()){}

VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  scope_ = ast_node->scope();
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after.
  while (iterator.HasNext()) {
    AstNode* node = iterator.Next();
    if (last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt) {
      node->Accept(this);
      last->first_child()->Append(node->first_child());
      ast_node->RemoveChild(node);
    } else {
      node->Accept(this);
    }
    last = node;
  }
}


VISITOR_IMPL(NodeList) {
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after.
  while (iterator.HasNext()) {
    AstNode* node = iterator.Next();
    if (last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt) {
      node->Accept(this);
      last->first_child()->Append(node->first_child());
      ast_node->RemoveChild(node);
    } else {
      node->Accept(this);
    }
    last = node;
  }
}



VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}



VISITOR_IMPL(ModuleStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(ExportStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(ImportStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(Statement) {}

VISITOR_IMPL(VersionStmt) {
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(AssertStmt) {}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  AstNode* last = 0;//init after
  while (iterator.HasNext()) {
    AstNode* node = iterator.Next();
    if (last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt) {
      node->Accept(this);
      last->first_child()->Append(node->first_child());
      ast_node->RemoveChild(node);
    } else {
      node->Accept(this);
    }
    last = node;
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->first_child()->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
  //Analyzer analyzer(scope_);
  //JSValue* value = ast_node->first_child()->CastToExpression()->Analyze(&analyzer);
  //printf("@@@@@@@@@@@@@@@@@@@@@@@@ --- %s\n", value->name());
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  IFStmtOptimizer opt(info_, ast_node);
  opt.Optimize(this);
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->expression();
  if (ast_node->node_type() == AstNode::kWhile || ast_node->node_type() == AstNode::kDoWhile) {
    ast_node->expression()->Accept(this);
  } else {
    AstNode* index_exp = exp->first_child();
    AstNode* cond_exp = (index_exp)? index_exp->next_sibling() : 0;
    AstNode* incr_exp = (cond_exp)? cond_exp->next_sibling() : 0;
    index_exp->Accept(this);
    if (cond_exp) {
      cond_exp->Accept(this);
    }
    if (incr_exp) {
      incr_exp->Accept(this);
    }
  }
  AstNode* body = ast_node->first_child();
  if (body->node_type() == AstNode::kBlockStmt) {
    if (body->child_length() == 1) {
      body = body->first_child();
      ast_node->RemoveAllChild();
      ast_node->AddChild(body);
    }
  }
  body->Accept(this);
}

VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->first_child();
  exp->Accept(this);
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->first_child()->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(LabelledStmt) {
  PRINT_NODE_NAME;
  ast_node->last_child()->Accept(this);
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
  ast_node->catch_block()->Accept(this);
  ast_node->finally_block()->Accept(this);
}


void OptimizerVisitor::ArrayAccessorProccessor_(CallExp* exp) {
  AstNode* callable = exp->callable();
  AstNode* arg = exp->args();
  callable->Accept(this);
  arg->Accept(this);
  callable = exp->callable();
  arg = exp->args();
  if (arg->node_type() == AstNode::kLiteral) {
    Literal* value = arg->CastToLiteral();
    if (value->value_type() == Literal::kString) {
      bool is_valid_property_name = true;
      std::string tmp = value->value()->token();
	  if (tmp.size() < 3 ) {
		  return;
	  }
      tmp.erase(tmp.size() - 1, tmp.size());
      if (!isalpha(tmp[ 1 ]) && tmp[ 1 ] != '_' && tmp[ 1 ] != '$') {
        is_valid_property_name = false;
      }
      if (is_valid_property_name) {
        for (int i = 2,len = tmp.size(); i < len; i++) {
          if (!isalpha(tmp[ i ]) && tmp[ i ] != '_' && tmp[ i ] != '$' && !isdigit(tmp[ i ])) {
            is_valid_property_name = false;
          }
        }
      }
      if (is_valid_property_name) {
        if (!JsToken::IsReserved(&tmp[1])) {
          Literal* ident = builder()->CreateNameNode(&tmp[ 1 ], Token::JS_IDENTIFIER, exp->line_number(), Literal::kProperty);
          CallExp* call_exp = new(pool()) CallExp(CallExp::kDot, exp->line_number());
          call_exp->set_callable(callable);
          call_exp->set_args(ident);
          exp->parent_node()->ReplaceChild(exp, call_exp);
          arg = ident;
          ident->Accept(this);
        }
      }
    }
  }
}


void OptimizerVisitor::DotAccessorProccessor_(CallExp* exp) {
  AstNode* callable = exp->callable();
  AstNode* args = exp->args();
  bool is_delete = false;
  bool is_lhs = exp->IsLhs();
  bool in_assignment = false;
  AstNode* parent = exp->parent_node();
  while (parent) {
    if (parent->CastToExpression()) {
      UnaryExp* exp = parent->CastToExpression()->CastToUnaryExp();
      if (exp) {
        if (exp->operand() == Token::JS_DELETE) {
          is_delete = true;
        }
      }
      if (parent->CastToExpression()->IsLhs()) {
        is_lhs = true;
      }
    } else if (parent->node_type() == AstNode::kAssignmentExp ||
                parent->node_type() == AstNode::kVariableStmt) {
      in_assignment = true;
      break;
    } else if (parent->CastToStatement()) {
      break;
    }
    parent = parent->parent_node();
  }
  if (!is_lhs &&
       !is_delete &&
       callable->node_type() == AstNode::kLiteral &&
       args->node_type() == AstNode::kLiteral &&
       exp->parent_node()->node_type() == AstNode::kCallExp) {
    Literal* ident = callable->CastToLiteral();
    Literal* prototype = args->CastToLiteral();
    if (ident->value_type() == Literal::kIdentifier &&
         prototype->value_type() == Literal::kProperty) {
      if (strcmp(prototype->value()->token(), SymbolList::symbol(SymbolList::kPrototype)) == 0) {
        if (strcmp(ident->value()->token(), SymbolList::symbol(SymbolList::kArrayConstructor)) == 0) {
          ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(exp->line_number());
          exp->parent_node()->ReplaceChild(exp, array);
          return;
        } else if (strcmp(ident->value()->token(), SymbolList::symbol(SymbolList::kObjectConstructor)) == 0) {
          ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(exp->line_number());
          if (!in_assignment) {
            Expression* expression = new(pool()) Expression(exp->line_number());
            expression->AddChild(object);
            expression->MarkParenthesis();
            exp->parent_node()->ReplaceChild(exp, expression);
            return;
          }
          exp->parent_node()->ReplaceChild(exp, object);
          return;
        } else if (strcmp(ident->value()->token(), SymbolList::symbol(SymbolList::kStringConstructor)) == 0) {
          Literal* str = builder()->CreateNameNode("''", Token::JS_STRING_LITERAL, exp->line_number(), Literal::kString);
          exp->parent_node()->ReplaceChild(exp, str);
          return;
        }
      }
    }
  }
  callable->Accept(this);
  args->Accept(this);
}

void OptimizerVisitor::NewCallProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  NodeIterator iterator = exp->args()->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

void OptimizerVisitor::NormalFunctionCall_(CallExp* exp) {
  AstNode* args = exp->args();
  exp->callable()->Accept(this);
  NodeIterator iterator = args->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  switch (ast_node->call_type()) {
    case CallExp::kNormal :
      NormalFunctionCall_(ast_node);
      break;

    case CallExp::kDot :
      DotAccessorProccessor_(ast_node);
      break;

    case CallExp::kNew :
      NewCallProccessor_(ast_node);
      break;

    case CallExp::kBracket :
      ArrayAccessorProccessor_(ast_node);
      break;
  }
}


VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  AstNode* member = ast_node->first_child();
  if (member->node_type() == AstNode::kCallExp || member->node_type() == AstNode::kLiteral) {
    AstNode* callable;
    AstNode* args;
    if (member->node_type() == AstNode::kCallExp) {
      CallExp* exp = member->CastToExpression()->CastToCallExp();
      callable = exp->callable();
      args = exp->args();
      if (args->node_type() == AstNode::kLiteral &&
           strcmp(args->CastToLiteral()->value()->token(),
                   SymbolList::symbol(SymbolList::kPrototype)) == 0) {
        args = 0;
      }
    } else {
      callable = member;
      args = 0;
    }
    if (callable->node_type() == AstNode::kLiteral) {
      Literal* value = callable->CastToLiteral();
      if (value->value_type() == Literal::kIdentifier) {
        const char* ident = value->value()->token();
        if (strcmp(ident, SymbolList::symbol(SymbolList::kFunctionConstructor)) == 0) {
          ast_node->parent_node()->ReplaceChild(ast_node, member);
        } else if (strcmp(ident, SymbolList::symbol(SymbolList::kArrayConstructor)) == 0) {
          if (!args || args->IsEmpty()) {
            ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(ast_node->line_number());
            ast_node->parent_node()->ReplaceChild(ast_node, array);
            return;
          } else {
            ast_node->parent_node()->ReplaceChild(ast_node, member);
          }
        } else if (strcmp(ident, SymbolList::symbol(SymbolList::kObjectConstructor)) == 0) {
          if (!args || args->IsEmpty()) {
            ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(ast_node->line_number());
            ast_node->parent_node()->ReplaceChild(ast_node, object);
            return;
          } else {
            ast_node->parent_node()->ReplaceChild(ast_node, member);
          }
        } else if (strcmp(ident, SymbolList::symbol(SymbolList::kStringConstructor)) == 0) {
          if (!args || args->IsEmpty()) {
            Literal* string = builder()->CreateNameNode("''", Token::JS_STRING_LITERAL, ast_node->line_number(),
                                                        Literal::kString);
            ast_node->parent_node()->ReplaceChild(ast_node, string);
            return;
          } else {
            ast_node->parent_node()->ReplaceChild(ast_node, member);
          }
        } else if (strcmp(ident, SymbolList::symbol(SymbolList::kNumberConstructor)) == 0) {
          if (!args || args->IsEmpty()) {
            Literal* number = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, ast_node->line_number(),
                                                        Literal::kNumeric);
            ast_node->parent_node()->ReplaceChild(ast_node, number);
            return;
          } else {
            ast_node->parent_node()->ReplaceChild(ast_node, member);
          }
        }
      }
    }
  }
  member->Accept(this);
}


VISITOR_IMPL(YieldExp){}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->expression();
  exp->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  int op = ast_node->operand();
  AstNode* left = ast_node->left_value();
  AstNode* right = ast_node->right_value();
  AstNode* parent = ast_node->parent_node();
  Expression* exp = parent->CastToExpression();
  BinaryExp* binary = (exp)? exp->CastToBinary() : 0;
  bool op_assoc = (binary)? ConstantOptimizer::CheckOperatorAssoc(op, binary->operand()) : true;
  if (op_assoc && ConstantOptimizer::IsOptimizable(left, right, op)) {
    ConstantOptimizer optimizer(left, right, op);
    AstNode* ret = optimizer.Optimize();
    ast_node->parent_node()->ReplaceChild(ast_node, ret);
    return;
  }
  left->Accept(this);
  right->Accept(this);
  left = ast_node->left_value();
  right = ast_node->right_value();
  if (op_assoc && ConstantOptimizer::IsOptimizable(left, right, op)) {
    ConstantOptimizer optimizer(left, right, op);
    AstNode* ret = optimizer.Optimize();
    ast_node->parent_node()->ReplaceChild(ast_node, ret);
  }
  exp = left->CastToExpression();
  binary = (exp)? exp->CastToBinary() : 0;
  if (binary) {
    if (op_assoc && ConstantOptimizer::IsOptimizable(binary->right_value(), right, op)) {
      ConstantOptimizer optimizer(binary->right_value(), right, op);
      AstNode* ret = optimizer.Optimize();
      binary->ReplaceChild(binary->right_value(), ret);
      ast_node->parent_node()->ReplaceChild(ast_node, binary);
      binary->Accept(this);
    }
  }
}


VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  ast_node->condition()->Accept(this);
  ast_node->case_true()->Accept(this);
  ast_node->case_false()->Accept(this);
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  AstNode* left = ast_node->left_value();
  AstNode* right = ast_node->right_value();
  Expression* exp = left->CastToExpression();
  if (exp) {
    exp->MarkAsLhs();
  }
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
  if (ast_node->parent_node()->node_type() == AstNode::kExpressionStmt ||
       (ast_node->parent_node()->node_type() == AstNode::kExpression &&
         ast_node->parent_node()->parent_node() &&
         ast_node->parent_node()->parent_node()->node_type() == AstNode::kExpressionStmt)) {
    if (left->CastToLiteral() &&
         right->CastToLiteral()) {
      Literal* left_literal = left->CastToLiteral();
      Literal* right_literal = right->CastToLiteral();
      if (left_literal->value_type() == Literal::kIdentifier &&
           right_literal->value_type() == Literal::kIdentifier &&
           strcmp(left_literal->value()->token(), right_literal->value()->token()) == 0) {
        if (ast_node->parent_node()->node_type() == AstNode::kExpression) {
          ast_node->parent_node()->parent_node()->parent_node()->RemoveChild(ast_node->parent_node()->parent_node());
        } else {
          ast_node->parent_node()->parent_node()->RemoveChild(ast_node->parent_node());
        }
      }
    }
  }
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  if (ast_node->parent_node()) {
    if (ast_node->child_length() == 1 && !(ast_node->IsParenthesis())) {
      ast_node->parent_node()->ReplaceChild(ast_node, ast_node->first_child());
    }
  }
}


VISITOR_IMPL(Trait){}


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  scope_ = ast_node->scope();
  AstNode* parent = ast_node->parent_node();
  bool is_exp = false;
  AstNode* exp = parent;
  bool is_unary_convertable = true;
  while (parent) {
    if (parent->node_type() == AstNode::kAssignmentExp ||
         parent->node_type() == AstNode::kLiteral ||
         (parent->node_type() == AstNode::kNodeList &&
           parent->parent_node() && parent->parent_node()->node_type() == AstNode::kFunction)) {
      is_unary_convertable = false;
      is_exp = true;
      break;
    } else if (parent->node_type() != AstNode::kExpressionStmt &&
                parent->node_type() != AstNode::kExpression &&
                parent->node_type() != AstNode::kCallExp) {
      is_unary_convertable = false;
    } else if (parent->node_type() == AstNode::kExpressionStmt &&
                is_unary_convertable == true) {
      break;
    }
    parent = parent->parent_node();
  }
  if (is_exp && exp && exp->node_type() == AstNode::kExpression) {
    Expression* expression = exp->CastToExpression();
    if (expression && expression->child_length() == 1 && expression->IsParenthesis()) {
      exp->CastToExpression()->UnMarkParenthesis();
    }
  } else if (ast_node->IsRoot() || (exp && is_unary_convertable)) {
    Expression* expression = exp->CastToExpression();
    if (expression && expression->child_length() == 1 && expression->IsParenthesis()) {
      exp->CastToExpression()->UnMarkParenthesis();
      UnaryExp* unary = new(pool()) UnaryExp('!', ast_node, ast_node->line_number());
      exp->RemoveAllChild();
      exp->AddChild(unary);
    }
  }
  NodeIterator body_iterator = ast_node->ChildNodes();
  AstNode* last = 0;
  NodeList* functions = new(pool()) NodeList;
  while (body_iterator.HasNext()) {
    AstNode* node = body_iterator.Next();
    if (last &&
         node->node_type() == AstNode::kVariableStmt &&
         last->node_type() == AstNode::kVariableStmt) {
      node->Accept(this);
      last->first_child()->Append(node->first_child());
      ast_node->RemoveChild(node);
    } else {
      node->Accept(this);
    }
    if (node->node_type() == AstNode::kFunction) {
      ast_node->RemoveChild(node);
      functions->AddChild(node);
    }
    last = node;
  }
  NodeIterator function_iterator = functions->ChildNodes();
  while (function_iterator.HasNext()) {
    ast_node->InsertBefore(function_iterator.Next());
  }
  scope_ = scope_->parent();
};


void OptimizerVisitor::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->first_child();
  while (list_child) {
    if (!list_child->IsEmpty()) {
      NodeIterator iter = list_child->ChildNodes();
      while (iter.HasNext()) {
        AstNode* element = iter.Next();
        if (!element->IsEmpty()) {
          element->Accept(this);
        }
      }
      if (list_child->HasNext()) {
        list_child = list_child->next_sibling();
      } else {
        break;
      }
    } else {
      break;
    }
  }
}


void OptimizerVisitor::ObjectProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  if (ast_node->child_length() > 0) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      element->Accept(this);
      element->first_child()->Accept(this);
    }
  }
}


VISITOR_IMPL(Literal) {
  switch (ast_node->value_type()) {
    case Literal::kVariable : {
      ast_node->first_child()->Accept(this);
      if (ast_node->first_child()->CastToLiteral()) {
        Literal* literal = ast_node->first_child()->CastToLiteral();
        if (literal->value_type() == Literal::kIdentifier) {
          if (strcmp(ast_node->value()->token(), literal->value()->token()) == 0) {
            if (ast_node->parent_node()->child_length() == 1) {
              ast_node->parent_node()->parent_node()->parent_node()->RemoveChild(ast_node->parent_node()->parent_node());
            } else {
              ast_node->parent_node()->RemoveChild(ast_node);
            }
          }
        }
      }
    }
      break;
                        
    case Literal::kIdentifier : {
      if (ast_node->child_length() > 0) {
        ast_node->first_child()->Accept(this);
      }
    }
      break;
                        
    default :
      return;
  }
}

VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  ArrayProccessor_(ast_node);
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  ObjectProccessor_(ast_node);
}

VISITOR_IMPL(GeneratorExpression){}
VISITOR_IMPL(VariableDeclarationList){}

}
