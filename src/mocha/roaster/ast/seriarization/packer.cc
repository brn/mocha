#include <stdio.h>
#include <string.h>
#include <math.h>
#include <mocha/roaster/ast/seriarization/byte.h>
#include <mocha/roaster/assert/assert_def.h>
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
#define UNREACHABLE_IMPL(type) void Packer::Visit##type(type*){FATAL("UNREACHABLE");}

#ifdef PRINTABLE
#define PRINT_NODE_NAME DEBUG_LOG(Info, "now packing node : %s", ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif

void Packer::IterateChildren(AstNode* ast_node) {
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* node = iterator.Next();
    if (node->IsEmpty()) {
      PushBack(AstNode::kEmpty);
    } else {
      node->Accept(this);
    }
  }
}

void Packer::PushBack(int32_t val) {
  packed_->push_back(b_order_->ToNetwordByteOrder(val));
}

Packer::Packer(Packed* packed, ByteOrder* b_order)
    : packed_(packed),
      b_order_(b_order){}

void Packer::CharPacker(const char* str, int size) {
  PushBack(size);
  for (int i = 0; i < size; i++) {
    PushBack(str[i]);
  }
}

void Packer::BasePacker(AstNode* node) {
  int type = node->node_type();
  int64_t line = node->line_number();
  PushBack(type);
  if (line == 0) {
    PushBack(1);
    PushBack(1);
  } else {
    PushBack(static_cast<int32_t>(ceil(static_cast<float>(line / 2))));
    PushBack(static_cast<int32_t>(floor(static_cast<float>(line / 2))));
  }
  if (node->node_type() != AstNode::kLiteral) {
    PushBack(node->child_length());
  } else {
    PushBack(0);
  }
}

void Packer::TokenPacker(TokenInfo* info, int lit_type) {
  int type = info->type();
  bool const_decl = info->const_declaration();
  const char* token = info->token();
  int64_t line = info->line_number();
  PushBack(type);
  PushBack(((const_decl)? 1 : 0));
  if (lit_type == Literal::kVariable ||
      lit_type == Literal::kProperty ||
      lit_type == Literal::kIdentifier ||
      lit_type == Literal::kRegExp ||
      lit_type == Literal::kString ||
      lit_type == Literal::kNumeric) {
    CharPacker(token, strlen(token));
  } else {
    PushBack(0);
  }
  PushBack(static_cast<int32_t>(ceil(static_cast<float>(line / 2))));
  PushBack(static_cast<int32_t>(floor(static_cast<float>(line / 2))));
}

VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  IterateChildren(ast_node);
}


VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  CharPacker(ast_node->filename(), strlen(ast_node->filename()));
  bool runtime = ast_node->runtime();
  bool strict = ast_node->IsStrict();
  PushBack((runtime? 1 : 0));
  PushBack((strict? 1 : 0));
  IterateChildren(ast_node);
}


VISITOR_IMPL(NodeList) {
  BasePacker(ast_node);
  IterateChildren(ast_node);
}


VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  IterateChildren(ast_node);
}

UNREACHABLE_IMPL(ModuleStmt);
UNREACHABLE_IMPL(ExportStmt);
UNREACHABLE_IMPL(ImportStmt);
UNREACHABLE_IMPL(Statement);

VISITOR_IMPL(VersionStmt) {
  BasePacker(ast_node);
  TokenInfo* version = ast_node->version();
  TokenPacker(version, Literal::kIdentifier);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(AssertStmt) {
  BasePacker(ast_node);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(SourceStmt) {
  BasePacker(ast_node);
  CharPacker(ast_node->path(), strlen(ast_node->path()));
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(IncludeStmt) {
  BasePacker(ast_node);
  CharPacker(ast_node->path(), strlen(ast_node->path()));
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  IterateChildren(ast_node);
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->first_child()->Accept(this);
}

UNREACHABLE_IMPL(LetStmt);


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->RemoveAllChild();
  BasePacker(ast_node);
  ast_node->condition()->Accept(this);
  ast_node->then_statement()->Accept(this);
  if (ast_node->else_statement()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    ast_node->else_statement()->Accept(this);
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  if (ast_node->first_child()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    ast_node->first_child()->Accept(this);
  }
}


VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  if (ast_node->first_child()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    ast_node->first_child()->Accept(this);
  }
}


VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  if (ast_node->first_child()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    ast_node->first_child()->Accept(this);
  }
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->expression()->Accept(this);
  IterateChildren(ast_node);
}


VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  if (ast_node->expression()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    ast_node->expression()->Accept(this);
  }
  IterateChildren(ast_node);
}


VISITOR_IMPL(LabelledStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  AstNode* symbol = ast_node->first_child();
  AstNode* statement = symbol->next_sibling();
  symbol->Accept(this);
  statement->Accept(this);
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  AstNode* catch_block = ast_node->catch_block();
  AstNode* finally_block = ast_node->finally_block();
  if (!catch_block->IsEmpty()) {
    catch_block->Accept(this);
  } else {
    PushBack(AstNode::kEmpty);
  }

  if (!finally_block->IsEmpty()) {
    finally_block->Accept(this);
  } else {
    PushBack(AstNode::kEmpty);
  }
  ast_node->first_child()->Accept(this);
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
  if (exp->args()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    exp->args()->Accept(this);
  }
}


void Packer::NormalFunctionCall_(CallExp* exp) {
  exp->callable()->Accept(this);
  if (exp->args()->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    exp->args()->Accept(this);
  }
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->call_type());
  PushBack((ast_node->rest()? 1 : 0));
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
  BasePacker(ast_node);
  ast_node->first_child()->Accept(this);
}


UNREACHABLE_IMPL(YieldExp);


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->operand());
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->operand());
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->condition()->Accept(this);
  ast_node->case_true()->Accept(this);
  ast_node->case_false()->Accept(this);
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack(ast_node->operand());
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  PushBack((ast_node->IsParenthesis()? 1 : 0));
  IterateChildren(ast_node);
}


UNREACHABLE_IMPL(Trait);


VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  ast_node->first_child()->Accept(this);
}

UNREACHABLE_IMPL(ClassProperties);
UNREACHABLE_IMPL(ClassExpandar);
UNREACHABLE_IMPL(ClassMember);


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  if (ast_node->parent_node()) {
    DEBUG_LOG(Log, "child length = %d, parent name = %s", ast_node->child_length(), ast_node->parent_node()->node_name());
  }
  BasePacker(ast_node);
  AstNode* name = ast_node->name();
  PushBack((ast_node->IsDeclaredAsConst()? 1 : 0));
  PushBack((ast_node->IsDeclared()? 1 : 0));
  PushBack((ast_node->IsRoot()? 1 : 0));
  PushBack((ast_node->IsStrict()? 1 : 0));
  DEBUG_LOG(Log, "argc = %d", ast_node->argc());
  PushBack(ast_node->argc());
  IterateChildren(ast_node->argv());
  if (name->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    name->Accept(this);
  }
  DEBUG_LOG(Log, "child length = %d", ast_node->child_length());
  IterateChildren(ast_node);
};


void Packer::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->first_child();
  if (list_child && list_child->IsEmpty()) {
    PushBack(AstNode::kEmpty);
  } else {
    IterateChildren(ast_node);
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
      }
    }
  }
}


VISITOR_IMPL(Literal) {
  BasePacker(ast_node);
  PushBack(ast_node->value_type());
  TokenInfo* info = ast_node->value();
  AstNode* node = ast_node->node();
  if (info) {
    PushBack(1);
    TokenPacker(info, ast_node->value_type());
  } else {
    PushBack(0);
  }
  if (node) {
    PushBack(1);
    node->Accept(this);
  } else {
    PushBack(0);
  }
  if (ast_node->value_type() == Literal::kVariable || ast_node->value_type() == Literal::kIdentifier) {
    if (ast_node->first_child() && ast_node->first_child()->node_type() != AstNode::kEmpty) {
      PushBack(1);
      ast_node->first_child()->Accept(this);
      return;
    } else if (ast_node->first_child() && ast_node->first_child()->node_type() == AstNode::kEmpty){
      PushBack(1);
      PushBack(AstNode::kEmpty);
      return;
    }
  }
  if (ast_node->value_type() == Literal::kProperty) {
    if (ast_node->first_child() && ast_node->first_child()->node_type() != AstNode::kEmpty) {
      PushBack(1);
      ast_node->first_child()->Accept(this);
      return;
    }
  }
  PushBack(0);
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  BasePacker(ast_node);
  bool is_const = ast_node->IsDeclaredAsConst();
  bool is_let = ast_node->IsDeclaredAsLet();
  PushBack((is_const? 1 : 0));
  PushBack((is_let? 1 : 0));
  IterateChildren(ast_node);
}

int GetObjectCount(AstNode* ast_node) {
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
  ast_node->RemoveAllChild();
  BasePacker(ast_node);
  PushBack(ast_node->elements()->child_length());
  ArrayProccessor_(ast_node->elements());
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  ast_node->RemoveAllChild();
  BasePacker(ast_node);
  PushBack(GetObjectCount(ast_node->elements()));
  ObjectProccessor_(ast_node->elements());
}

UNREACHABLE_IMPL(GeneratorExpression);


}
