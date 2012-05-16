#include <string.h>
#include <stdarg.h>
#include <sstream>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha{

AstBuilder* AstBuilder::Local() {
  AstBuilder* builder = static_cast<AstBuilder*>(os::ThreadLocalStorage::Get(&key_));
  if (builder == NULL) {
    builder = new AstBuilder(memory::Pool::Local());
    os::ThreadLocalStorage::Set(&key_, builder);
  }
  return builder;
}
AstBuilder::~AstBuilder() {}
Function* AstBuilder::CreateFunctionDecl(AstNode* name, AstNode* argv, AstNode* body, int64_t line) {
  Function *fn = new(pool()) Function(line);
  fn->set_name(name);
  fn->set_argv(argv);
  fn->Append(body);
  return fn;
}

CallExp* AstBuilder::CreateArrayAccessor(AstNode* callable, AstNode* args, int64_t line) {
  CallExp* exp = new(pool()) CallExp(CallExp::kBracket, line);
  exp->set_callable(callable);
  exp->set_args(args);
  return exp;
}

CallExp* AstBuilder::CreateDotAccessor(AstNode* callable, AstNode* args, int64_t line) {
  CallExp* exp = new(pool()) CallExp(CallExp::kDot, line);
  exp->set_callable(callable);
  exp->set_args(args);
  return exp;
}

static const char prototype[] = { "prototype" };

CallExp* AstBuilder::CreatePrototypeAccessor(AstNode* callable, AstNode* args, int64_t line) {
  Literal* prototype_node = CreateNameNode(prototype, Token::JS_IDENTIFIER, line, Literal::kProperty);
  CallExp* depth1 = CreateDotAccessor(callable, prototype_node, line);
  CallExp* depth2 = CreateDotAccessor(depth1, args, line);
  return depth2;
}

CallExp* AstBuilder::CreateNormalAccessor(AstNode* callable, AstNode* args, int64_t line) {
  CallExp* exp = new(pool()) CallExp(CallExp::kNormal, line);
  exp->set_callable(callable);
  exp->set_args(args);
  return exp;
}

Literal* AstBuilder::CreateNameNode(const char* name, int type, int64_t line, int value_type, bool is_empty) {
  TokenInfo* info = new(pool()) TokenInfo(name, type, line);
  Literal* value = new(pool()) Literal(value_type, line);
  if (is_empty) {
    value->AddChild(new(pool()) Empty);
  }
  value->set_value(info);
  return value;
}

Literal* AstBuilder::CreateNameNode(const std::stringstream& val, int type, int64_t line, int value_type, bool is_empty) {
  TokenInfo* info = new(pool()) TokenInfo(val, type, line);
  Literal* value = new(pool()) Literal(value_type, line);
  if (is_empty) {
    value->AddChild(new(pool()) Empty);
  }
  value->set_value(info);
  return value;
}

AssignmentExp* AstBuilder::CreateAssignment(int type, AstNode* lhs, AstNode* rhs, int64_t line) {
  AssignmentExp* assign = new(pool()) AssignmentExp(type, lhs, rhs, line);
  return assign;
}

UnaryExp* AstBuilder::CreateUnaryExp(int type, AstNode* exp, int64_t line) {
  UnaryExp* unary = new(pool()) UnaryExp(type, exp, line);
  return unary;
}

ObjectLikeLiteral* AstBuilder::CreateObjectLiteral(AstNode* body, int64_t line) {
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(line);
  object->Append(body);
  return object;
}

ExpressionStmt* AstBuilder::CreateAnonymousFnCall(Function *fn, AstNode* args, int64_t line) {
  Expression* exp = new(pool()) Expression(line);
  CallExp* call = new(pool()) CallExp(CallExp::kNormal, line);
  exp->AddChild(fn);
  exp->MarkParenthesis();
  call->set_callable(exp);
  call->set_args(args);
  ExpressionStmt* ret_stmt = new(pool()) ExpressionStmt(line);
  ret_stmt->AddChild(call);
  return ret_stmt;
}

ExpressionStmt* AstBuilder::CreateExpStmt(AstNode* node, int64_t line) {
  Expression* exp = new(pool()) Expression(line);
  exp->AddChild(node);
  ExpressionStmt* stmt = new(pool()) ExpressionStmt(line);
  stmt->AddChild(exp);
  return stmt;
}

VariableStmt* AstBuilder::CreateVarStmt(VariableDeclarationList* list, int64_t line) {
  VariableStmt* var = new(pool()) VariableStmt(line);
  var->AddChild(list);
  return var;
}


Literal* AstBuilder::CreateVarInitiliser(TokenInfo* lhs, AstNode* rhs, int64_t line) {
  Literal* node = new(pool()) Literal(Literal::kVariable, line);
  node->set_value(lhs);
  node->AddChild(rhs);
  return node;
}

ReturnStmt* AstBuilder::CreateReturnStmt(AstNode* exp, int64_t line) {
  ReturnStmt* return_stmt = new(pool()) ReturnStmt(line);
  return_stmt->AddChild(exp);
  return return_stmt;
}


CallExp* AstBuilder::CreateConstantProp(AstNode* lhs, AstNode* prop, AstNode* value, int64_t line) {
  Literal* constant = AstBuilder::CreateNameNode(SymbolList::symbol(SymbolList::kConstant),
                                                Token::JS_IDENTIFIER, line, Literal::kIdentifier);
  Literal* prop_str = prop->CastToLiteral();
  AstNode* property = prop;
  if (prop_str && (prop_str->value_type() == Literal::kIdentifier || prop_str->value_type() == Literal::kProperty)) {
    std::stringstream st;
    st << '\'' << prop_str->value()->token() << '\'';
    std::string value = st.str();
    property = AstBuilder::CreateNameNode(value.c_str(), Token::JS_STRING_LITERAL, line, Literal::kString);
  }
  NodeList* args = new(pool()) NodeList;
  args->AddChild(lhs);
  args->AddChild(property);
  args->AddChild(value);
  CallExp* runtime_accessor = AstBuilder::CreateRuntimeMod(constant, line);
  return AstBuilder::CreateNormalAccessor(runtime_accessor, args, line);
}


CallExp* AstBuilder::CreatePrototypeNode(AstNode* lhs, int64_t line) {
  Literal* prototype = AstBuilder::CreateNameNode(SymbolList::symbol(SymbolList::kPrototype),
                                                 Token::JS_IDENTIFIER, line, Literal::kProperty);
  return AstBuilder::CreateDotAccessor(lhs, prototype, line);
}


CallExp* AstBuilder::CreateRuntimeMod(AstNode* member, int64_t line) {
  Literal* value = CreateNameNode(SymbolList::symbol(SymbolList::kRuntime),
                                  Token::JS_IDENTIFIER, line, Literal::kIdentifier);
  return CreateDotAccessor(value, member, line);
}

std::string AstBuilder::CreateTmpRef(int index) {
  std::stringstream st;
  st << SymbolList::symbol(SymbolList::kLocalTmp) << index;
  return st.str();
}

Literal* AstBuilder::CreateTmpNode(int index, int64_t line) {
  std::string value = AstBuilder::CreateTmpRef(index);
  return AstBuilder::CreateNameNode(value.c_str(), Token::JS_IDENTIFIER, line, Literal::kIdentifier);
}

IFStmt* AstBuilder::CreateIFStmt(AstNode* exp, AstNode* then_stmt, AstNode* else_stmt, int64_t line) {
  IFStmt* if_stmt = new(pool()) IFStmt(line);
  if_stmt->set_condition(exp);
  if_stmt->set_then_statement(then_stmt);
  if_stmt->set_else_statement(else_stmt);
  return if_stmt;
}

NodeList* AstBuilder::CreateNodeList(int num, ...) {
  va_list list;
  va_start(list, num);
  NodeList* node_list = new(pool()) NodeList;
  for (int i = 0; i < num; i++) {
    AstNode* node = va_arg(list, AstNode*);
    node_list->AddChild(node);
  }
  return node_list;
}

BlockStmt* AstBuilder::CreateBlockStmt(int64_t line, int num, ...) {
  va_list list;
  va_start(list,      num);
  BlockStmt* block = new(pool()) BlockStmt(line);
  for (int i = 0; i < num; i++) {
    AstNode* stmt = va_arg(list, AstNode*);
    block->AddChild(stmt);
  }
  return block;
}

VariableDeclarationList* AstBuilder::CreateVarDeclList(int64_t line, int num, ...) {
  va_list list;
  va_start(list, num);
  VariableDeclarationList* decl_list = new(pool()) VariableDeclarationList(line);
  for (int i = 0; i < num; i++) {
    AstNode* node = va_arg(list, AstNode*);
    decl_list->AddChild(node);
  }
  return decl_list;
}

template<typename T>
void FindDirectivePrologueCommon(AstNode* node, T* target) {
  if (node->first_child() && node->first_child()->node_type() == AstNode::kExpressionStmt) {
    if (node->first_child()->first_child() && node->first_child()->first_child()->first_child() &&
         node->first_child()->first_child()->first_child()->node_type() == AstNode::kLiteral) {
      Literal* directive = node->first_child()->first_child()->first_child()->CastToLiteral();
      if (strcmp(directive->value()->token(), "'use strict'") == 0 || strcmp(directive->value()->token(), "\"use strict\"") == 0) {
        node->RemoveChild(node->first_child());
        target->MarkAsStrict();
      }
    }
  }
}

void AstBuilder::FindDirectivePrologue(AstNode* node, FileRoot* root) {
  FindDirectivePrologueCommon(node, root);
}

void AstBuilder::FindDirectivePrologue(AstNode* node, Function* fn) {
  FindDirectivePrologueCommon(node, fn);
}

CallExp* AstBuilder::BuildPrivateRecordAccessor(int64_t line) {
  abort();/*
  Literal* private_field = CreateNameNode(SymbolList::symbol(SymbolList::kGetPrivateRecord),
                                          Token::JS_IDENTIFIER, line, Literal::kProperty);
  CallExp* normal = CreateNormalAccessor(private_field, args, line);
  return CreateRuntimeMod(normal, line);*/
  return 0;
}

bool AstBuilder::IsDestructringLeftHandSide(AstNode* node) {
  return (node->node_type() == AstNode::kArrayLikeLiteral ||
          node->node_type() == AstNode::kObjectLikeLiteral) &&
      node->CastToExpression() && node->CastToExpression()->IsValidLhs();
}

void AstBuilder::SetAutoReturnFlag(AstNode* node) {
  if (node) {
    Statement* stmt = node->CastToStatement();
    Expression* exp = node->CastToExpression();
    if (stmt) {
      stmt->set_autoreturn();
    } else if (exp) {
      Function* fn = exp->CastToFunction();
      fn->set_autoreturn();
    }
  }
}

os::ThreadLocalStorageKey AstBuilder::key_;
}
