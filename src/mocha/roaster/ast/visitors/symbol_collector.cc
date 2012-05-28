#include <stdio.h>
#include <string.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/symbol_collector.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

#define VISITOR_IMPL(type) void SymbolCollector::Visit##type(type* ast_node)
#define UNREACHABLE_IMPL(type) void SymbolCollector::Visit##type(type*){FATAL("UNREACHABLE");}
#define EMPTY_IMPL(type) void SymbolCollector::Visit##type(type*){}

#ifdef PRINTABLE
#define PRINT_NODE_NAME printf("depth = %d name = %s\n", depth_++, ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif


SymbolCollector::SymbolCollector(ScopeRegistry* scope_registry, CompilationInfo* info)
  : depth_(0),
    scope_index_(0),
    info_(info),
    scope_registry_(scope_registry){}

void SymbolCollector::Rename(Literal* lit) {
  if (!JsToken::IsBuiltin(lit->value()->token())) {
    std::string buf;
    os::SPrintf(&buf, "%s_%d", lit->value()->token(), scope_index_);
    lit->value()->set_token(buf.c_str());
  }
}

VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  scope_ = scope_registry_->Assign();
  ast_node->set_scope(scope_);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  scope_ = scope_registry_->Return();
}


VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(NodeList) {
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


UNREACHABLE_IMPL(ModuleStmt);
UNREACHABLE_IMPL(ExportStmt);
UNREACHABLE_IMPL(ImportStmt);
UNREACHABLE_IMPL(Statement);

VISITOR_IMPL(VersionStmt) {
  ast_node->first_child()->Accept(this);
}
VISITOR_IMPL(AssertStmt) {
  ast_node->first_child()->Accept(this);
}

UNREACHABLE_IMPL(IncludeStmt);

EMPTY_IMPL(SourceStmt);

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* statement = iterator.Next();
    statement->Accept(this);
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

UNREACHABLE_IMPL(LetStmt);


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->condition()->Accept(this);
  ast_node->then_statement()->Accept(this);
  ast_node->else_statement()->Accept(this);
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
  ast_node->first_child()->Accept(this);
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
  NodeIterator iterator = ast_node->ChildNodes();
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
  AstNode* sym = ast_node->first_child();
  AstNode* stmt = sym->next_sibling();
  stmt->Accept(this);
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  AstNode* catch_block = ast_node->catch_block();
  AstNode* finally_block = ast_node->finally_block();
  ast_node->first_child()->Accept(this);
  if (!catch_block->IsEmpty()) {
    catch_block->first_child()->Accept(this);
  } else if (!finally_block->IsEmpty()) {
    finally_block->first_child()->Accept(this);
  }
}


void SymbolCollector::ArrayAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  exp->args()->Accept(this);
}


void SymbolCollector::DotAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  exp->args()->Accept(this);
}


void SymbolCollector::NewCallProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  NodeIterator iterator = exp->args()->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


void SymbolCollector::NormalFunctionCall_(CallExp* exp) {
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
  ast_node->first_child()->Accept(this);
}


UNREACHABLE_IMPL(YieldExp);


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
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
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


UNREACHABLE_IMPL(Trait);

VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
}

UNREACHABLE_IMPL(ClassProperties);
UNREACHABLE_IMPL(ClassExpandar);
UNREACHABLE_IMPL(ClassMember);


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  AstNode* name = ast_node->name();
  Literal* name_node = name->CastToLiteral();
  if (!name->IsEmpty()) {
    scope_->Insert(name_node->value(), ast_node);
  }
  scope_ = scope_registry_->Assign();
  ast_node->set_scope(scope_);
  if (info_->Debug()) {
    TokenInfo* runtime = new(memory::Pool::Local()) TokenInfo(SymbolList::symbol(SymbolList::kRuntime),
                                                              Token::JS_IDENTIFIER, ast_node->line_number());
    scope_->Ref(runtime);
  }
  NodeIterator arg_iterator = ast_node->argv()->ChildNodes();
  while (arg_iterator.HasNext()) {
    Literal* arg = arg_iterator.Next()->CastToLiteral();
    if (arg) {
      scope_->Insert(arg->value(), arg);
    }
  }
  NodeIterator body_iterator = ast_node->ChildNodes();
  while (body_iterator.HasNext()) {
    body_iterator.Next()->Accept(this);
  }
  scope_ = scope_registry_->Return();
};


void SymbolCollector::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    item->Accept(this);
  }
}


void SymbolCollector::ObjectProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  if (ast_node->child_length() > 0) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      element->Accept(this);
      if (element->first_child()) {
        element->first_child()->Accept(this);
      }
    }
  }
}


VISITOR_IMPL(Literal) {
  switch (ast_node->value_type()) {

    case Literal::kVariable :
      ast_node->first_child()->Accept(this);
      if (info_->FileScope()) {
        scope_->Insert(ast_node->value(), ast_node->first_child());
      } else {
        scope_->Insert(ast_node->value(), ast_node->first_child());
      }
      break;

    case Literal::kProperty :
      if (ast_node->child_length() > 0) {
        ast_node->first_child()->Accept(this);
      }
      break;

    case Literal::kIdentifier : {
      if (strcmp(ast_node->value()->token(), SymbolList::symbol(SymbolList::kScopeModule)) == 0) {
        ast_node->value()->set_token(SymbolList::symbol(SymbolList::kGlobalAlias));
      }
      scope_->Ref(ast_node->value());
      AstNode* first_child = ast_node->first_child();
      if (first_child) {
        first_child->Accept(this);
      }
    }
      break;
                        
    default :
      return;
  }
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  ArrayProccessor_(ast_node->elements());
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  ObjectProccessor_(ast_node->elements());
}

UNREACHABLE_IMPL(GeneratorExpression);

}
