/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
namespace mocha {

AstNode::AstNode(int type, const char* name, int64_t line)
    : type_(type),
      child_length_(0),
      line_(line),
      name_(name),
      parent_(0),
      first_child_(0),
      last_child_(0),
      next_sibling_(0),
      prev_sibling_(0){}

void AstNode::AddChild(AstNode* node) {
  ASSERT(true, this != node);
  if (first_child_ == 0) {
    first_child_ = node;
    last_child_ = node;
    node->parent_ = this;
    node->next_sibling_ = 0;
    node->prev_sibling_ = 0;
  } else {
    last_child_->next_sibling_ = node;
    node->prev_sibling_ = last_child_;
    last_child_ = node;
    node->next_sibling_ = 0;
    node->parent_ = this;
  }
  child_length_++;
}

void AstNode::InsertBefore(AstNode* node) {
  ASSERT(true, this != node);
  if (first_child_ == 0) {
    first_child_ = node;
    last_child_ = node;
    node->next_sibling_ = 0;
    node->prev_sibling_ = 0;
  } else {
    first_child_->prev_sibling_ = node;
    node->next_sibling_ = first_child_;
    first_child_ = node;
    node->prev_sibling_ = 0;
  }
  node->parent_ = this;
  child_length_++;
}

void AstNode::InsertBefore(AstNode* insert, AstNode* target) {
  ASSERT(true, this != insert);
  ASSERT(true, this != target);
  ASSERT(true, target != insert);
  bool is_insert = false;
  if (first_child_ == target) {
    first_child_ = insert;
    target->prev_sibling_ = insert;
    insert->next_sibling_ = target;
    insert->prev_sibling_ = 0;
    is_insert = true;
  }

  if (!is_insert) {
    insert->prev_sibling_ = target->prev_sibling_;
    if (target->prev_sibling_) {
      target->prev_sibling_->next_sibling_ = insert;
    }
    target->prev_sibling_ = insert;
    insert->next_sibling_ = target;
  }
  insert->parent_ = this;
  child_length_++;
}

void AstNode::InsertAfter(AstNode* insert, AstNode* target) {
  ASSERT(true, this != insert);
  ASSERT(true, target != insert);
  ASSERT(true, this != target);
  bool is_insert = false;

  if (last_child_ == target  ) {
    last_child_ = insert;
    insert->prev_sibling_ = target;
    target->next_sibling_ = insert;
    insert->next_sibling_ = 0;
    is_insert = true;
  }

  if (!is_insert) {
    insert->next_sibling_ = target->next_sibling_;
    if (target->next_sibling_) {
      target->next_sibling_->prev_sibling_ = insert;
    }
    target->next_sibling_ = insert;
    insert->prev_sibling_ = target;
  }
  insert->parent_ = this;
  child_length_++;
}

void AstNode::Append(AstNode* node) {
  ASSERT(true, this != node);
  if (node) {
    typedef std::vector<AstNode*> AstArray;
    AstArray ast_array;
    NodeIterator iterator = node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      ASSERT(true, this != item);
      ASSERT(true, node != item);
      ast_array.push_back(item);
    }
    AstArray::iterator begin = ast_array.begin(), end = ast_array.end();
    while (begin != end) {
      AddChild((*begin));
      ++begin;
    }
  }
}

void AstNode::RemoveAllChild() {
  NodeIterator iterator = ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (item->parent_ == this) {
      item->parent_ = 0;
    }
  }
  first_child_ = 0;
  last_child_ = 0;
  child_length_ = 0;
}

AstNode* NodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->next_sibling();
  return ret;
}


AstNode* ReverseNodeIterator::Next() {
  AstNode* ret = node_;
  node_ = node_->previous_sibling();
  return ret;
}

void AstNode::RemoveChild(AstNode* node) {
  ASSERT(true, this != node);
  AstNode* match_ptr = 0;
  NodeIterator iterator = ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (item == node) {
      match_ptr = item;
      break;
    }
  }
  if (match_ptr) {
    child_length_--;
    if (match_ptr->parent_ == this) {
      match_ptr->parent_ = 0;
    }
    if (match_ptr->next_sibling_) {
      match_ptr->next_sibling_->prev_sibling_ = match_ptr->prev_sibling_;
    }
    if (match_ptr->prev_sibling_) {
      match_ptr->prev_sibling_->next_sibling_ = match_ptr->next_sibling_;
    }
                
    if (first_child_ == match_ptr) {
      if (match_ptr->next_sibling_) {
        first_child_ = match_ptr->next_sibling_;
      } else {
        first_child_ = 0;
      }
    }

    if (last_child_ == match_ptr) {
      if (match_ptr->prev_sibling_) {
        last_child_ = match_ptr->prev_sibling_;
      } else {
        last_child_ = 0;
      }
    }
                
  }
}


void AstNode::ReplaceWith(AstNode* node) {
  ASSERT(true, this != node);
  node->parent_ = parent_;
  node->next_sibling_ = next_sibling_;
  node->prev_sibling_ = prev_sibling_;
  if (next_sibling_) {
    next_sibling_->prev_sibling_ = node;
  }
  if (prev_sibling_) {
    prev_sibling_->next_sibling_ = node;
  }
}


void AstNode::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  ASSERT(true, old_node != new_node);
  ASSERT(true, this != old_node);
  ASSERT(true, this != new_node);
  if (first_child_) {
    if (old_node == first_child_) {
      first_child_ = new_node;
    }
    if (old_node == last_child_) {
      last_child_ = new_node;
    }
    old_node->ReplaceWith(new_node);
  }
  new_node->set_parent_node(this);
}

template <typename T, typename T2>
inline T2* CopyChildren(T* dest, T2* source, memory::Pool* pool) {
  ASSERT(true, dest != source);
  dest->set_parent_node(source->parent_node());
  NodeIterator iter = source->ChildNodes();
  while (iter.HasNext()) {
    AstNode* item = iter.Next();
    ASSERT(true, source != item);
    dest->AddChild(item->Clone(pool));
  }
  return dest;
}

#define NORMAL_CLONE(name)                      \
  AstNode* name::Clone(memory::Pool* pool) {    \
    name* ret = new(pool) name;                 \
    return CopyChildren(ret, this, pool);       \
  }

#define LINED_CLONE(name)                       \
  AstNode* name::Clone(memory::Pool* pool) {    \
    name* ret = new(pool) name(line_number());  \
    return CopyChildren(ret, this, pool);       \
  }

NORMAL_CLONE(NodeList);
NORMAL_CLONE(Empty);
NORMAL_CLONE(AstRoot);
AstNode* FileRoot::Clone(memory::Pool* pool) {
  FileRoot* root = new(pool) FileRoot(filename_.c_str());
  root->flags_ = flags_;
  return CopyChildren(root, this, pool);
}
NORMAL_CLONE(StatementList);

AstNode* VersionStmt::Clone(memory::Pool* pool) {
  TokenInfo *info = new(pool) TokenInfo(version_->token(), version_->type(), version_->line_number());
  VersionStmt* stmt = new(pool) VersionStmt(info, line_number());
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(BlockStmt);

void ModuleStmt::SetExports(Literal* lit) {
  exports_.insert(Pair(lit->value()->token(), lit));
}

AstNode* ModuleStmt::Clone(memory::Pool* pool) {
  ModuleStmt* stmt = new(pool) ModuleStmt((name_)?name_->Clone(pool) : name_, type_, line_number());
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(ExportStmt);

void ImportStmt::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (expression_ == old_node) {
    old_node->ReplaceWith(new_node);
    expression_ = new_node;
  } else if (from_ == old_node) {
    old_node->ReplaceWith(new_node);
    from_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* ImportStmt::Clone(memory::Pool* pool) {
  ImportStmt* ret = new(pool) ImportStmt(expression_type_, module_type_, line_number());
  if (expression_) {
    ret->expression_ = expression_->Clone(pool);
    ret->expression_->set_parent_node(ret);
  }
  if (from_) {
    ret->from_ = from_->Clone(pool);
    ret->from_->set_parent_node(ret);
  }
  if (module_key_) {
    ret->module_key_ =
        new(pool) TokenInfo(module_key_->token(), module_key_->type(), module_key_->line_number());
  }
  if (filename_) {
    ret->filename_ =
        new(pool) TokenInfo(filename_->token(), filename_->type(), filename_->line_number());
  }
  return CopyChildren(ret, this, pool);
}

AstNode* VariableStmt::Clone(memory::Pool* pool) {
  VariableStmt* stmt = new(pool) VariableStmt(line_number());
  return CopyChildren(stmt, this, pool);
}

AstNode* LetStmt::Clone(memory::Pool* pool) {
  LetStmt* stmt = new(pool) LetStmt(expression_->Clone(pool), line_number());
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(ExpressionStmt);

void IFStmt::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (condition_ == old_node) {
    condition_ = new_node;
    new_node->After(old_node->next_sibling());
    new_node->Before(old_node->previous_sibling());
    new_node->set_parent_node(this);
  } else if (then_statement_ == old_node) {
    then_statement_ = new_node;
    new_node->After(old_node->next_sibling());
    new_node->Before(old_node->previous_sibling());
    new_node->set_parent_node(this);
  } else if (else_statement_ == old_node) {
    else_statement_ = new_node;
    new_node->After(old_node->next_sibling());
    new_node->Before(old_node->previous_sibling());
    new_node->set_parent_node(this);
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* IFStmt::Clone(memory::Pool* pool) {
  IFStmt* stmt = new(pool) IFStmt(line_number());
  if (condition_) {
    stmt->condition_ = condition_->Clone(pool);
    stmt->condition_->set_parent_node(stmt);
  }
  if (then_statement_) {
    stmt->then_statement_ = then_statement_->Clone(pool);
    stmt->then_statement_->set_parent_node(stmt);
  }
  if (else_statement_) {
    stmt->else_statement_ = else_statement_->Clone(pool);
    stmt->else_statement_->set_parent_node(stmt);
  }
  return CopyChildren(stmt, this, pool);
}

AstNode* IterationStmt::Clone(memory::Pool* pool) {
  IterationStmt* stmt = new(pool) IterationStmt(node_type(), line_number());
  if (expression_) {
    stmt->expression_ = expression_->Clone(pool);
    stmt->expression_->set_parent_node(stmt);
  }
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(ContinueStmt);
LINED_CLONE(BreakStmt);
LINED_CLONE(ReturnStmt);

AstNode* WithStmt::Clone(memory::Pool* pool) {
  WithStmt* stmt = new(pool) WithStmt(line_number());
  if (expression_) {
    stmt->expression_ = expression_->Clone(pool);
    stmt->expression_->set_parent_node(stmt);
  }
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(LabelledStmt);

AstNode* SwitchStmt::Clone(memory::Pool* pool) {
  SwitchStmt* stmt = new(pool) SwitchStmt(line_number());
  if (expression_) {
    stmt->expression_ = expression_->Clone(pool);
    stmt->expression_->set_parent_node(stmt);
  }
  return CopyChildren(stmt ,this, pool);
}

AstNode* ThrowStmt::Clone(memory::Pool* pool) {
  ThrowStmt* stmt = new(pool) ThrowStmt(line_number());
  if (expression_) {
    stmt->expression_ = expression_->Clone(pool);
    stmt->expression_->set_parent_node(stmt);
  }
  return CopyChildren(stmt, this, pool);
}

AstNode* TryStmt::Clone(memory::Pool* pool) {
  TryStmt* stmt = new(pool) TryStmt(line_number());
  if (catch_block_) {
    stmt->catch_block_ = catch_block_->Clone(pool);
    stmt->catch_block_->set_parent_node(stmt);
  }
  if (finally_block_) {
    stmt->finally_block_ = finally_block_->Clone(pool);
    stmt->finally_block_->set_parent_node(stmt);
  }
  return CopyChildren(stmt, this, pool);
}

LINED_CLONE(AssertStmt);

AstNode* SourceStmt::Clone(memory::Pool* pool) {
  SourceStmt* source = new(pool) SourceStmt(path_.c_str(), line_number());
  return source;
}

AstNode* IncludeStmt::Clone(memory::Pool* pool) {
  IncludeStmt* inc = new(pool) IncludeStmt(name_.c_str(), line_number());
  return inc;
}

AstNode* CaseClause::Clone(memory::Pool* pool) {
  CaseClause* clause = new(pool) CaseClause(line_number());
  if (expression_) {
    clause->expression_ = expression_->Clone(pool);
    clause->expression_->set_parent_node(clause);
  }
  return CopyChildren(clause, this, pool);
}

AstNode* Expression::Clone(memory::Pool* pool) {
  Expression* exp = new(pool) Expression(line_number());
  exp->flags_ = flags_;
  return CopyChildren(exp, this, pool);
}

AstNode* VariableDeclarationList::Clone(memory::Pool* pool) {
  VariableDeclarationList* decl_list = new(pool) VariableDeclarationList(line_number());
  return CopyChildren(decl_list, this, pool);
}

AstNode* Class::Clone(memory::Pool* pool) {
  Class* cls = new(pool) Class(expandar_->Clone(pool), line_number());
  if (name_) {
    cls->name_ = name_->Clone(pool);
    cls->name_->set_parent_node(cls);
  }
  if (body_) {
    cls->body_ = body_->Clone(pool);
    cls->body_->set_parent_node(cls);
  }
  cls->flags_ = flags_;
  return CopyChildren(cls, this, pool);
}

AstNode* ClassProperties::Clone(memory::Pool* pool) {
  ClassProperties *prop = new(pool) ClassProperties(line_number());
  CopyChildren(&(prop->public_), &public_, pool);
  CopyChildren(&(prop->private_), &private_, pool);
  CopyChildren(&(prop->public_static_), &public_static_, pool);
  CopyChildren(&(prop->private_static_), &private_static_, pool);
  CopyChildren(&(prop->prototype_), &prototype_, pool);
  prop->constructor_ = constructor_->Clone(pool);
  return CopyChildren(prop, this, pool);
}

AstNode* ClassExpandar::Clone(memory::Pool* pool) {
  ClassExpandar* exp = new(pool) ClassExpandar(attr_, line_number());
  return CopyChildren(exp, this, pool);
}

AstNode* ClassMember::Clone(memory::Pool* pool) {
  ClassMember* member = new(pool) ClassMember(attr_, line_number());
  return CopyChildren(member, this, pool);
}


AstNode* Function::Clone(memory::Pool* pool) {
  Function *fn = new(pool) Function(line_number());
  if (name_) {
    fn->set_name(name_->Clone(pool));
  }
  if (argv_) {
    fn->set_argv(argv_->Clone(pool));
    fn->argv_->set_parent_node(fn);
  }
  fn->fn_type_ = fn_type_;
  fn->context_ = context_;
  fn->fn_attr_ = fn_attr_;
  fn->flags_ = flags_;
  if (replaced_this_) {
    fn->replaced_this_ = replaced_this_->Clone(pool)->CastToLiteral();
  }
  return CopyChildren(fn, this, pool);
}

void CallExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == callable_) {
    new_node->Before(0);
    new_node->After(0);
    new_node->set_parent_node(this);
    callable_ = new_node;
  } else if (old_node == args_) {
    new_node->Before(0);
    new_node->After(0);
    new_node->set_parent_node(this);
    args_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* CallExp::Clone(memory::Pool* pool) {
  CallExp *exp = new(pool) CallExp(call_type_, line_number());
  if (callable_) {
    exp->callable_ = callable_->Clone(pool);
    exp->callable_->set_parent_node(exp);
  }
  if (args_) {
    exp->args_ = args_->Clone(pool);
    exp->args_->set_parent_node(exp);
  }
  return CopyChildren(exp, this, pool);
}

AstNode* NewExp::Clone(memory::Pool* pool) {
  NewExp* exp = new(pool) NewExp(line_number());
  return CopyChildren(exp, this, pool);
}

LINED_CLONE(YieldExp);


void PostfixExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == expression_) {
    new_node->Before(expression_->previous_sibling());
    new_node->After(expression_->next_sibling());
    new_node->set_parent_node(this);
    expression_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}


AstNode* PostfixExp::Clone(memory::Pool* pool) {
  PostfixExp* exp = new(pool) PostfixExp(operand_, expression_->Clone(pool), line_number());
  return CopyChildren(exp, this, pool);
}


void UnaryExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == expression_) {
    new_node->Before(expression_->previous_sibling());
    new_node->After(expression_->next_sibling());
    new_node->set_parent_node(this);
    expression_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}


AstNode* UnaryExp::Clone(memory::Pool* pool) {
  UnaryExp* exp = new(pool) UnaryExp(operand_, expression_->Clone(pool), line_number());
  return CopyChildren(exp, this, pool);
}

void BinaryExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == left_value_) {
    new_node->Before(left_value_->previous_sibling());
    new_node->After(left_value_->next_sibling());
    new_node->set_parent_node(this);
    left_value_ = new_node;
  } else if (old_node == right_value_) {
    new_node->Before(right_value_->previous_sibling());
    new_node->After(right_value_->next_sibling());
    new_node->set_parent_node(this);
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* BinaryExp::Clone(memory::Pool* pool) {
  BinaryExp* exp = new(pool) BinaryExp(operand_, left_value_->Clone(pool), right_value_->Clone(pool), line_number());
  exp->left_value()->set_parent_node(exp);
  exp->right_value()->set_parent_node(exp);
  return CopyChildren(exp, this, pool);
}


void CompareExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == left_value_) {
    new_node->Before(left_value_->previous_sibling());
    new_node->After(left_value_->next_sibling());
    new_node->set_parent_node(this);
    left_value_ = new_node;
  } else if (old_node == right_value_) {
    new_node->Before(right_value_->previous_sibling());
    new_node->After(right_value_->next_sibling());
    new_node->set_parent_node(this);
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}


AstNode* CompareExp::Clone(memory::Pool* pool) {
  CompareExp* exp =
      new(pool) CompareExp(operand_, left_value_->Clone(pool), right_value_->Clone(pool), line_number());
  exp->left_value()->set_parent_node(exp);
  exp->right_value()->set_parent_node(exp);
  return CopyChildren(exp, this, pool);
}


void ConditionalExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == condition_) {
    new_node->Before(condition_->previous_sibling());
    new_node->After(condition_->next_sibling());
    new_node->set_parent_node(this);
    condition_ = new_node;
  } else if (old_node == case_true_) {
    new_node->Before(case_true_->previous_sibling());
    new_node->After(case_true_->next_sibling());
    new_node->set_parent_node(this);
    case_true_ = new_node;
  } else if (old_node == case_false_) {
    new_node->Before(case_false_->previous_sibling());
    new_node->After(case_false_->next_sibling());
    new_node->set_parent_node(this);
    case_false_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}


AstNode* ConditionalExp::Clone(memory::Pool* pool) {
  ConditionalExp* exp =
      new(pool) ConditionalExp(condition_->Clone(pool), case_true_->Clone(pool), case_false_->Clone(pool), line_number());
  exp->condition()->set_parent_node(exp);
  exp->case_true()->set_parent_node(exp);
  exp->case_false()->set_parent_node(exp);
  return CopyChildren(exp, this, pool);
}


void AssignmentExp::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (old_node == left_value_) {
    new_node->Before(left_value_->previous_sibling());
    new_node->After(left_value_->next_sibling());
    new_node->set_parent_node(this);
    left_value_ = new_node;
  } else if (old_node == right_value_) {
    new_node->Before(right_value_->previous_sibling());
    new_node->After(right_value_->next_sibling());
    new_node->set_parent_node(this);
    right_value_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* AssignmentExp::Clone(memory::Pool* pool) {
  AssignmentExp* exp =
      new(pool) AssignmentExp(operand_, left_value_->Clone(pool), right_value_->Clone(pool), line_number());
  exp->left_value()->set_parent_node(exp);
  exp->right_value()->set_parent_node(exp);
  return CopyChildren(exp, this, pool);
}

AstNode* Literal::Clone(memory::Pool* pool) {
  Literal* ret = new(pool) Literal(value_type_, line_number());
  if (value_type_ != kPrivateProperty) {
    TokenInfo* value = new(pool) TokenInfo(value_->token(), value_->type(), value_->line_number());
    ret->set_value(value);
  } else {
    ret->set_node(node_->Clone(pool));
  }
  return CopyChildren(ret, this, pool);
}

AstNode* ArrayLikeLiteral::Clone(memory::Pool* pool) {
  ArrayLikeLiteral* array = new(pool) ArrayLikeLiteral(line_number());
  array->flags_ = flags_;
  CopyChildren(&(array->elements_), &elements_, pool);
  return CopyChildren(array, this, pool);
}

AstNode* ObjectLikeLiteral::Clone(memory::Pool* pool) {
  ObjectLikeLiteral* object = new(pool) ObjectLikeLiteral(line_number());
  object->flags_ = flags_;
  CopyChildren(&(object->elements_), &elements_, pool);
  return CopyChildren(object, this, pool);
}

AstNode* GeneratorExpression::Clone(memory::Pool* pool) {
  GeneratorExpression* generator = new(pool) GeneratorExpression(expression_->Clone(pool), line_number());
  return CopyChildren(generator, this, pool);
}

void GeneratorExpression::ReplaceChild(AstNode* old_node, AstNode* new_node) {
  if (expression_ == old_node) {
    old_node->ReplaceWith(new_node);
    expression_ = new_node;
  } else {
    AstNode::ReplaceChild(old_node, new_node);
  }
}

AstNode* DstaTree::Clone(memory::Pool* pool) {
  DstaTree* tree = new(pool) DstaTree;
  if (symbol_) {
    tree->symbol_ = symbol_->Clone(pool)->CastToLiteral();
  }
  return CopyChildren(tree, this, pool);
}

AstNode* DstaExtractedExpressions::Clone(memory::Pool* pool) {
  DstaExtractedExpressions* exp = new(pool) DstaExtractedExpressions;
  CopyChildren(&exp->refs_, &refs_, pool);
  return CopyChildren(exp, this, pool);
}

}
