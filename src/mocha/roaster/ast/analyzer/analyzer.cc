#include <stdio.h>
#include <string.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/ast/analyzer/analyzer.h>
#include <mocha/roaster/ast/analyzer/js_values.h>
namespace mocha {

#define VISITOR_IMPL(type) JSValue* Analyzer::Visit##type(type* ast_node)

#ifdef PRINTABLE
#define PRINT_NODE_NAME printf("depth = %d name = %s\n", depth_++, ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif

Analyzer::Analyzer(CompilationInfo* info)
    : info_(info){}

VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  scope_ = ast_node->scope();
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  scope_ = scope_->parent();
  return NULL;
}

VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(NodeList) {
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(VersionStmt) {
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* statement = iterator.Next();
    statement->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
  return NULL;
}

VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  ast_node->condition()->Accept(this);
  ast_node->then_statement()->Accept(this);
  ast_node->else_statement()->Accept(this);
  return NULL;
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
  return NULL;
}

VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
  return NULL;
}


VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
  return NULL;
}


VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->first_child();
  exp->Accept(this);
  return NULL;
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  ast_node->first_child()->Accept(this);
  return NULL;
}

VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
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
  return NULL;
}

const char* FindProperty(JSValue* prop) {
  switch (prop->type()) {
    case JSValue::kProperty :
    case JSValue::kSymbol :
    case JSValue::kNumber :
    case JSValue::kRegExp :
    case JSValue::kBoolean :
    case JSValue::kUndefined :
    case JSValue::kNull :
    case JSValue::kNaN :
      return prop->ToString();
    case JSValue::kObject : {
      JSValue* tostring = prop->CastToObject()->Get("toString");
      if (tostring == NULL) {
        return "[object Object]";
      } else {
        return tostring->ToString();
      }
    }
    case JSValue::kArray : {
      JSValue* tostring = prop->CastToArray()->FindProperty("toString");
      if (ToString == NULL) {
        return prop->ToString();
      } else {
        return tostring->ToString();
      }
    }
  }
}

JSValue* Analyzer::ArrayAccessorProccessor_(CallExp* exp) {
  JSValue* val = exp->callable()->Accept(this);
  JSValue* prop = exp->args()->Accept(this);
  if (prop->type() != JSValue::kNotConstant) {
    const char* property = FindProperty(prop);
    switch (val->type()) {
      case JSValue::kFunction :
        return val->CastToFunction()->FindProperty(property);
  }
  } else {
    return prop;
  }
}


JSValue* Analyzer::DotAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  exp->args()->Accept(this);
  return NULL;
}


JSValue* Analyzer::NewCallProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  NodeIterator iterator = exp->args()->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}


JSValue* Analyzer::NormalFunctionCall_(CallExp* exp) {
  AstNode* args = exp->args();
  exp->callable()->Accept(this);
  NodeIterator iterator = args->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  switch (ast_node->call_type()) {
    case CallExp::kNormal :
      return NormalFunctionCall_(ast_node);
      break;

    case CallExp::kDot :
      return DotAccessorProccessor_(ast_node);
      break;

    case CallExp::kNew :
      return NewCallProccessor_(ast_node);
      break;

    case CallExp::kBracket :
      return ArrayAccessorProccessor_(ast_node);
      break;
  }
}

VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  return ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  return ast_node->expression()->Accept(this);
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  return ast_node->expression()->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
  return NULL;
}


VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  ast_node->right_value()->Accept(this);
  return NULL;
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  ast_node->condition()->Accept(this);
  ast_node->case_true()->Accept(this);
  ast_node->case_false()->Accept(this);
  return NULL;
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  JSValue* left = ast_node->left_value()->Accept(this);
  JSValue* right = ast_node->right_value()->Accept(this);
  if (ast_node->operand() == '=') {
    if (left) {
      if (left->type() == JSValue::kSymbol) {
        scope_->InsertAlias(left->CastToSymbol(), right);
      } else if (left->type() == JSValue::kProperty) {
        left->CastToProperty()->parent()->Add(left->CastToProperty(), right);
      }
    }
  }
  return NULL;
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  AstNode* name = ast_node->name();
  Literal* name_node = name->CastToLiteral();
  scope_ = ast_node->scope();
  //NodeIterator arg_iterator = ast_node->argv()->ChildNodes();
  NodeIterator body_iterator = ast_node->ChildNodes();
  while (body_iterator.HasNext()) {
    body_iterator.Next()->Accept(this);
  }
  scope_ = scope_->parent();
  const char* name = (name->IsEmpty())? NULL : name->CastToLiteral()->value()->token();
  JSFunction* function = new(&pool_) JSFunction(name, ast_node);
  return function;
};


JSValue* Analyzer::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  JSArray* array = new(&pool_) JSArray(ast_node);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    array->Add(item);
    item->Accept(this);
  }
  return array;
}


JSValue* Analyzer::ObjectProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  JSObject* object = new(&pool_) JSObject(ast_node);
  if (ast_node->child_length() > 0) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      JSValue* value_prop = element->Accept(this);
      JSProperty* prop = NULL;
      if (value_prop->type() == JSValue::kProperty) {
        prop = value_prop->CastToProperty();
      } else {
        prop = new(&pool_) JSProperty(value_prop->CastToString()->node());
      }
      prop->set_parent(object);
      if (element->CastToLiteral()) {
        if (element->first_child()) {
          JSValue* result = element->first_child()->Accept(this);
          object->Add(prop, result);
        }
      }
    }
  }
  return object;
}

VISITOR_IMPL(Literal) {
  switch (ast_node->value_type()) {

    case Literal::kVariable :
      return ast_node->first_child()->Accept(this);
      break;

    case Literal::kProperty : {
      JSProperty* symbol = new(&pool_) JSProperty(ast_node);
      return symbol;
    }

    case Literal::kIdentifier : {
      JSSymbol* symbol = new(&pool_) JSSymbol(ast_node);
      return symbol;
    }

    case Literal::kUndefined :
      JSUndefined* undef = new(&pool_) JSUndefined(ast_node);
      return undef;

    case Literal::kNull :
      JSNull null = new(&pool_) JSNull(ast_node);
      return null;

    case Literal::kNaN :
      JSNaN nan = new(&pool_) JSNaN(ast_node);
      return nan;

    case Literal::kRegExp :
      JSRegExp reg = new(&pool_) JSRegExp(ast_node);
      return reg;

    case Literal::kThis :
      JSThis this_node = new(&pool_) JSThis(ast_node);
      return this_node;

    case Literal::kString :
      JSString str = new(&pool_) JSString(ast_node->value()->token(), ast_node);
      return str;

    case Literal::kNumber :
      JSNumber num = new(&pool_) JSNumber(strtod(ast_node->value()->token(), NULL), ast_node);
      return num;

    case Literal::kTrue :
      JSBoolean ret = new(&pool_) JSBoolean(true, ast_node);
      return ret;

    case Literal::kFalse :
      JSBoolean ret = new(&pool_) JSBoolean(false, ast_node);
      return ret;
      
    default :
      return NULL;
  }
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  return NULL;
}

VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  return ArrayProccessor_(ast_node->elements());
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  return ObjectProccessor_(ast_node->elements());
}
}
