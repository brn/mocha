#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/iteration_processor.h>
#include <mocha/roaster/ast/translator/processors/variable_processor.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>

namespace mocha {

void IterationProcessor::InsertBlock(IterationStmt* ast_node) {
  AstNode* maybe_block = ast_node->first_child();
  if (maybe_block->node_type() != AstNode::kBlockStmt) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = LocalBuilder()->CreateBlockStmt(maybe_block->line_number(), 1, maybe_block);
    ast_node->AddChild(stmt);
  }
}

void IterationProcessor::ProcessForNode(IterationStmt* ast_node, ProcessorInfo* info) {
  InsertBlock(ast_node);
  IVisitor *visitor = info->visitor();
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* cond_exp = (index_exp)? index_exp->next_sibling() : 0;
  AstNode* incr_exp = (cond_exp)? cond_exp->next_sibling() : 0;
  index_exp->Accept(visitor);
  if (cond_exp) {
    cond_exp->Accept(visitor);
  }
  if (incr_exp) {
    incr_exp->Accept(visitor);
  }  
  ast_node->first_child()->Accept(visitor);
  if (ast_node->IsContainYield()) {
    info->translator_data()->function()->set_statement_in_generator(ast_node);
  }
}

void IterationProcessor::ProcessForInNode(IterationStmt* ast_node, ProcessorInfo* info, bool is_regist) {
  InsertBlock(ast_node);
  IVisitor *visitor = info->visitor();
  bool has_variable = ast_node->node_type() == AstNode::kForInWithVar || ast_node->node_type() == AstNode::kForOfWithVar;
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  Literal* dsta_value = 0;
  bool is_dst = false;
  if (LocalBuilder()->IsDestructringLeftHandSide(index_exp)) {
    is_dst = true;
    DstaProcessor processor(index_exp, info);
    dsta_value = processor.ProcessNode();
  } else {
    index_exp->Accept(visitor);
  }
                                
  if (is_dst && has_variable) {
    dsta_value->set_value_type(Literal::kVariable);
    dsta_value->RemoveAllChild();
    dsta_value->AddChild(new(LocalPool()) Empty);
  } else {
    is_dst = ast_node->IsContainDestructuring();
  }
                                
  AstNode* dsta_stmt = 0;
  if (is_dst && has_variable) {
    VariableDeclarationList* decl_list = new(LocalPool()) VariableDeclarationList(ast_node->line_number());
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt(ast_node, info);
    decl_list->Append(list);
    dsta_stmt = LocalBuilder()->CreateVarStmt(decl_list, ast_node->line_number());
  } else if (is_dst && !has_variable) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, info);
    dsta_stmt = LocalBuilder()->CreateExpStmt(list, ast_node->line_number());
  }
                                
  target_exp->Accept(visitor);
  ast_node->first_child()->Accept(visitor);
                                
  AstNode* body = ast_node->first_child();
  if (is_dst) {
    body->first_child()->InsertBefore(dsta_stmt);
  }
  if (ast_node->IsContainYield() && is_regist) {
    info->translator_data()->function()->set_statement_in_generator(ast_node);
  }
}


void IterationProcessor::ProcessForOfNode(IterationStmt* ast_node, ProcessorInfo* info) {
  InsertBlock(ast_node);
  ProcessForInNode(ast_node, info, false);
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  IterationStmt* while_stmt = new(LocalPool()) IterationStmt(AstNode::kWhile, ast_node->line_number());
  Literal* maybe_ident = target_exp->CastToLiteral();
  if (ast_node->node_type() == AstNode::kForOfWithVar) {
    AstNode* val = index_exp->Clone(LocalPool());
    Literal* maybe_value = index_exp->CastToLiteral();
    if (maybe_value) {
      maybe_value->set_value_type(Literal::kVariable);
      maybe_value->RemoveAllChild();
      maybe_value->AddChild(new(LocalPool()) Empty());
      VariableDeclarationList* list = LocalBuilder()->CreateVarDeclList(ast_node->line_number(), 1, index_exp);
      VariableStmt* stmt = LocalBuilder()->CreateVarStmt(list, ast_node->line_number());
      ast_node->parent_node()->InsertBefore(stmt, ast_node);
    }
    if (val->CastToLiteral()) {
      val->CastToLiteral()->set_value_type(Literal::kIdentifier);
    }
    index_exp = val;
  }
  if (!maybe_ident) {
    Literal* tmp = LocalBuilder()->CreateTmpNode(info->translator_data()->tmp_index(), ast_node->line_number());
    Literal* init = LocalBuilder()->CreateVarInitiliser(tmp->value(), target_exp, ast_node->line_number());
    VariableDeclarationList* decl_list = LocalBuilder()->CreateVarDeclList(ast_node->line_number(), 1, init);
    VariableStmt* stmt = LocalBuilder()->CreateVarStmt(decl_list, ast_node->line_number());
    Literal* target = tmp->Clone(LocalPool())->CastToLiteral();

    Literal* has_iterator = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kHasIterator),
                                                      Token::JS_IDENTIFIER, 0, Literal::kProperty);
    Literal* get_iterator = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kGetIterator),
                                                      Token::JS_IDENTIFIER, 0, Literal::kProperty);
    CallExp* runtime_key = LocalBuilder()->CreateRuntimeMod(has_iterator, ast_node->line_number());
    CallExp* runtime_key2 = LocalBuilder()->CreateRuntimeMod(get_iterator, ast_node->line_number());
    NodeList* args = LocalBuilder()->CreateNodeList(1, tmp->Clone(LocalPool()));
    CallExp* runtime_call = LocalBuilder()->CreateNormalAccessor(runtime_key, args, ast_node->line_number());
    CallExp* get_iterator_call = LocalBuilder()->CreateNormalAccessor(runtime_key2, args->Clone(LocalPool()), ast_node->line_number());
    ConditionalExp* cond_exp = new(LocalPool()) ConditionalExp(runtime_call, get_iterator_call, tmp->Clone(LocalPool()), ast_node->line_number());
    AssignmentExp* assign = LocalBuilder()->CreateAssignment('=', target->Clone(LocalPool()), cond_exp, ast_node->line_number());
    ExpressionStmt* exp_stmt = LocalBuilder()->CreateExpStmt(assign, ast_node->line_number());
    ast_node->parent_node()->InsertBefore(stmt, ast_node);
    ast_node->parent_node()->InsertBefore(exp_stmt, ast_node);
    exp->ReplaceChild(target_exp, target);
    target_exp = target;
  }
  Literal* next = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kNoThrow),
                                            Token::JS_IDENTIFIER, ast_node->line_number(), Literal::kProperty);
  CallExp* next_call = LocalBuilder()->CreateNormalAccessor(next, new(LocalPool()) NodeList, ast_node->line_number());
  CallExp* dot_call = LocalBuilder()->CreateDotAccessor(target_exp, next_call, ast_node->line_number());
  CallExp* dot_exp = LocalBuilder()->CreateDotAccessor(target_exp, next->Clone(LocalPool()), ast_node->line_number());
  AssignmentExp* assign = LocalBuilder()->CreateAssignment('=', index_exp, dot_call, ast_node->line_number());
  Expression* expression = new(LocalPool()) Expression(ast_node->line_number());
  expression->AddChild(assign);
  expression->MarkParenthesis();
  while_stmt->set_expression(expression);

  while_stmt->AddChild(ast_node->first_child());
  Literal* handler = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kExceptionHandler),
                                               Token::JS_IDENTIFIER, 0, Literal::kProperty);
  CallExp* runtime_call = LocalBuilder()->CreateRuntimeMod(handler, ast_node->line_number());
  std::stringstream st;
  st << ast_node->line_number();
  Literal* line_num = LocalBuilder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL, ast_node->line_number(), Literal::kNumeric);
  std::string buf;
  os::SPrintf(&buf, "'%s'", info->translator_data()->filename());
  Literal* file_name = LocalBuilder()->CreateNameNode(buf.c_str(), Token::JS_STRING_LITERAL, ast_node->line_number(), Literal::kString);
  Literal* error = LocalBuilder()->CreateNameNode("'for of statement expect iterator or generator object.'",
                                             Token::JS_STRING_LITERAL, 0, Literal::kString);
  NodeList* args = LocalBuilder()->CreateNodeList(3, line_num, file_name, error);
  CallExp* handler_call = LocalBuilder()->CreateNormalAccessor(runtime_call, args, ast_node->line_number());
  ExpressionStmt* handler_stmt = LocalBuilder()->CreateExpStmt(handler_call, ast_node->line_number());
  BlockStmt* then_block = LocalBuilder()->CreateBlockStmt(ast_node->line_number(), 1, while_stmt);
  BlockStmt* else_block = LocalBuilder()->CreateBlockStmt(ast_node->line_number(), 1, handler_stmt);
  IFStmt* if_stmt = LocalBuilder()->CreateIFStmt(dot_exp, then_block, else_block, ast_node->line_number());
  ast_node->parent_node()->ReplaceChild(ast_node, if_stmt);

  if (ast_node->IsContainYield()) {
    info->translator_data()->function()->set_statement_in_generator(while_stmt);
    info->translator_data()->function()->set_statement_in_generator(if_stmt);
  }
}


void IterationProcessor::ProcessForEachNode(IterationStmt *ast_node, ProcessorInfo *info) {
  InsertBlock(ast_node);
  IVisitor* visitor = info->visitor();
  bool has_variable = ast_node->node_type() == AstNode::kForEachWithVar;
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  Literal* dsta_value = 0;
  bool is_dst = false;
                                
  if (LocalBuilder()->IsDestructringLeftHandSide(index_exp)) {
    is_dst = true;
    DstaProcessor processor(index_exp, info);
    dsta_value = processor.ProcessNode();
  } else {
    index_exp->Accept(visitor);
  }
  if (is_dst && has_variable) {
    dsta_value->set_value_type(Literal::kVariable);
    index_exp->RemoveAllChild();
    index_exp->AddChild(new(LocalPool()) Empty);
  } else {
    is_dst = ast_node->IsContainDestructuring();
  }
                                
  AstNode* dsta_stmt = 0;
  if (is_dst && has_variable) {
    VariableDeclarationList* decl_list = new(LocalPool()) VariableDeclarationList(ast_node->line_number());
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt(ast_node, info);
    decl_list->Append(list);
    dsta_stmt = LocalBuilder()->CreateVarStmt(decl_list, ast_node->line_number());
  } else if (is_dst && !has_variable) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, info);
    dsta_stmt = LocalBuilder()->CreateExpStmt(list, ast_node->line_number());
  }
                                
  target_exp->Accept(visitor);
  ast_node->first_child()->Accept(visitor);
  ExpressionStmt* stmt;
  if (has_variable) {
    Literal *value = index_exp->Clone(LocalPool())->CastToLiteral();
    value->set_value_type(Literal::kIdentifier);
    CallExp* call = LocalBuilder()->CreateArrayAccessor(target_exp->Clone(LocalPool()), value, ast_node->line_number());
    AssignmentExp* exp = LocalBuilder()->CreateAssignment('=', value->Clone(LocalPool()), call, ast_node->line_number());
    stmt = LocalBuilder()->CreateExpStmt(exp, ast_node->line_number());
  } else {
    CallExp* call = LocalBuilder()->CreateArrayAccessor(target_exp->Clone(LocalPool()), index_exp->Clone(LocalPool()), ast_node->line_number());
    AssignmentExp* exp = LocalBuilder()->CreateAssignment('=', index_exp->Clone(LocalPool()), call, ast_node->line_number());
    stmt = LocalBuilder()->CreateExpStmt(exp, ast_node->line_number());
  }
  AstNode* body = ast_node->first_child();
  if (is_dst) {
    body->InsertBefore(dsta_stmt);
  }
  body->InsertBefore(stmt);
  if (ast_node->IsContainYield()) {
    info->translator_data()->function()->set_statement_in_generator(ast_node);
  }
}

void IterationProcessor::ProcessWhileNode(IterationStmt *ast_node, ProcessorInfo *info) {
  InsertBlock(ast_node);
  IVisitor* visitor = info->visitor();
  bool is_dst = false;
  NodeList* dsta_list = 0;
  VariableStmt* var_stmt = 0;
  ast_node->expression()->Accept(visitor);
  if ((is_dst = ast_node->IsContainDestructuring())) {
    if (ast_node->node_type() == AstNode::kDoWhile) {
      var_stmt = DstaProcessor::CreateTmpVarDecl(ast_node, info);
    } else {
      var_stmt = DstaProcessor::CreateTmpVarDecl(ast_node, info);
    }
    dsta_list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, info);
  }
  AstNode* body = ast_node->first_child();
  body->Accept(visitor);
  if (is_dst) {
    Expression* exp = new(LocalPool()) Expression(ast_node->line_number());
    exp->AddChild(dsta_list);
    exp->MarkParenthesis();
    ExpressionStmt* stmt = new(LocalPool()) ExpressionStmt(ast_node->line_number());
    stmt->AddChild(exp);
    body->first_child()->InsertBefore(stmt);
    ast_node->parent_node()->InsertBefore(var_stmt, ast_node);
  }
  if (ast_node->IsContainYield()) {
    info->translator_data()->function()->set_statement_in_generator(ast_node);
  }
}

}

