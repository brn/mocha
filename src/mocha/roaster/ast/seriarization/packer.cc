#include <stdio.h>
#include <string.h>
#include <math.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/seriarization/packer.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

#define VISITOR_IMPL(type) void Packer::Visit##type(type* ast_node)

#ifdef PRINTABLE
#define PRINT_NODE_NAME DEBUG_LOG(Info, "now packing node : %s", ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif


Packer::Packer(Packed* packed)
    : packed_(packed){}

void CharPacker(const char* str, int size, Packed* packed) {
  packed->push_back(size);
  for (int i = 0; i < size; i++) {
    packed->push_back(str[i]);
  }
}

void BasePacker(AstNode* node, Packed* packed) {
  int type = node->node_type();
  int64_t line = node->line_number();
  packed->push_back(type);
  if (line == 0) {
    packed->push_back(1);
    packed->push_back(1);
  } else {
    packed->push_back(ceil(line / 2));
    packed->push_back(floor(line / 2));
  }
  if (node->node_type() != AstNode::kLiteral) {
    packed->push_back(node->child_length());
  } else {
    packed->push_back(0);
  }
}

void TokenPacker(TokenInfo* info, Packed* packed) {
  int type = info->type();
  bool const_decl = info->const_declaration();
  const char* token = info->token();
  int64_t line = info->line_number();
  packed->push_back(type);
  packed->push_back(((const_decl)? 1 : 0));
  CharPacker(token, strlen(token), packed);
  packed->push_back(ceil(line / 2));
  packed->push_back(floor(line / 2));
}

VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  CharPacker(ast_node->filename(), strlen(ast_node->filename()), packed_);
  bool runtime = ast_node->runtime();
  bool strict = ast_node->IsStrict();
  packed_->push_back((runtime? 1 : 0));
  packed_->push_back((strict? 1 : 0));
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(NodeList) {
  BasePacker(ast_node, packed_);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
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
  BasePacker(ast_node, packed_);
  TokenInfo* version = ast_node->version();
  TokenPacker(version, packed_);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(AssertStmt) {
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* statement = iterator.Next();
    statement->Accept(this);
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->condition()->Accept(this);
  ast_node->then_statement()->Accept(this);
  if (ast_node->else_statement()->node_type() == AstNode::kEmpty) {
    packed_->push_back(AstNode::kEmpty);
  } else {
    ast_node->else_statement()->Accept(this);
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  AstNode* exp = ast_node->first_child();
  exp->Accept(this);
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(LabelledStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  AstNode* symbol = ast_node->first_child();
  AstNode* statement = symbol->next_sibling();
  symbol->Accept(this);
  statement->Accept(this);
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  AstNode* catch_block = ast_node->catch_block();
  AstNode* finally_block = ast_node->finally_block();
  if (!catch_block->IsEmpty()) {
    catch_block->Accept(this);
  } else {
    packed_->push_back(AstNode::kEmpty);
  }

  if (!finally_block->IsEmpty()) {
    finally_block->Accept(this);
  } else {
    packed_->push_back(AstNode::kEmpty);
  }
}


void Packer::ArrayAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  exp->args()->Accept(this);
}


void Packer::DotAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  exp->args()->Accept(this);
}


void Packer::NewCallProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  if (exp->args()->node_type() == AstNode::kEmpty) {
    packed_->push_back(AstNode::kEmpty);
  } else {
    exp->args()->Accept(this);
  }
}


void Packer::NormalFunctionCall_(CallExp* exp) {
  exp->callable()->Accept(this);
  if (exp->args()->node_type() == AstNode::kEmpty) {
    packed_->push_back(AstNode::kEmpty);
  } else {
    exp->args()->Accept(this);
  }
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->call_type());
  packed_->push_back((ast_node->rest()? 1 : 0));
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
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(YieldExp){}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->operand());
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->operand());
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->condition()->Accept(this);
  ast_node->case_true()->Accept(this);
  ast_node->case_false()->Accept(this);
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back((ast_node->IsParenthesis()? 1 : 0));
  NodeIterator iter = ast_node->ChildNodes();
  while (iter.HasNext()) {
    iter.Next()->Accept(this);
  }
}


VISITOR_IMPL(Trait){}


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  if (ast_node->parent_node()) {
    DEBUG_LOG(Log, "child length = %d, parent name = %s", ast_node->child_length(), ast_node->parent_node()->node_name());
  }
  BasePacker(ast_node, packed_);
  AstNode* name = ast_node->name();
  packed_->push_back((ast_node->IsDeclaredAsConst()? 1 : 0));
  packed_->push_back((ast_node->IsDeclared()? 1 : 0));
  packed_->push_back((ast_node->IsRoot()? 1 : 0));
  packed_->push_back((ast_node->IsStrict()? 1 : 0));
  packed_->push_back(ast_node->argc());
  NodeIterator arg_iterator = ast_node->argv()->ChildNodes();
  while (arg_iterator.HasNext()) {
    arg_iterator.Next()->Accept(this);
  }
  if (name->IsEmpty()) {
    packed_->push_back(AstNode::kEmpty);
  } else {
    name->Accept(this);
  }
  NodeIterator body_iterator = ast_node->ChildNodes();
  while (body_iterator.HasNext()) {
    AstNode* node = body_iterator.Next();
    if (!node->IsEmpty()) {
      node->Accept(this);
      DEBUG_LOG(Log, "child!");
    }
  }
};


void Packer::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->first_child();
  while (list_child) {
    if (!list_child->IsEmpty()) {
      NodeIterator iter = list_child->ChildNodes();
      while (iter.HasNext()) {
        AstNode* element = iter.Next();
        if (!element->IsEmpty()) {
          element->Accept(this);
        } else {
          packed_->push_back(AstNode::kEmpty);
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


void Packer::ObjectProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  if (ast_node->child_length() > 0) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      Literal* val = element->CastToLiteral();
      if ((val && element->CastToLiteral()->value_type() != Literal::kPrivateProperty)) {
        element->Accept(this);
        if (element->first_child()) {
          element->first_child()->Accept(this);
        }
      }
    }
  }
}


VISITOR_IMPL(Literal) {
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->value_type());
  TokenInfo* info = ast_node->value();
  AstNode* node = ast_node->node();
  if (info) {
    packed_->push_back(1);
    TokenPacker(info, packed_);
  } else {
    packed_->push_back(0);
  }
  if (node) {
    packed_->push_back(1);
    node->Accept(this);
  } else {
    packed_->push_back(0);
  }
  if (ast_node->value_type() == Literal::kVariable) {
    if (ast_node->first_child()) {
      packed_->push_back(1);
      ast_node->first_child()->Accept(this);
      return;
    }
  }
  if (ast_node->value_type() == Literal::kProperty) {
    AstNode* parent = ast_node->parent_node();
    while (parent) {
      if (parent->node_type() == AstNode::kObjectLikeLiteral) {
        break;
      }
      parent = parent->parent_node();
    }
    if (!parent) {
      packed_->push_back(0);
      return;
    }
    if (ast_node->first_child()) {
      packed_->push_back(1);
      return;
    }
  }
  packed_->push_back(0);
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  bool is_const = ast_node->IsDeclaredAsConst();
  bool is_let = ast_node->IsDeclaredAsLet();
  packed_->push_back((is_const? 1 : 0));
  packed_->push_back((is_let? 1 : 0));
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

int GetCount(AstNode* ast_node) {
  int count = 0;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* element = iterator.Next();
    Literal* val = element->CastToLiteral();
    if ((val && element->CastToLiteral()->value_type() != Literal::kPrivateProperty)) {
      count++;
    }
  }
  return count;
}

VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(ast_node->elements()->child_length());
  ArrayProccessor_(ast_node);
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  BasePacker(ast_node, packed_);
  packed_->push_back(GetCount(ast_node->elements()));
  ObjectProccessor_(ast_node->elements());
}

VISITOR_IMPL(GeneratorExpression){}

}
