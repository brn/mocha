#include <mocha/roaster/ast/translator/processors/function_processor.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/token_info.h>

namespace mocha {

FunctionProcessor::FunctionProcessor(Function* function, ProcessorInfo* info) :
    Processor(), function_(function), info_(info), formal_parameter_(function->argv()),
    default_parameter_(new(pool()) NodeList) {
  argc_ = formal_parameter_->child_length();
}

FunctionProcessor::~FunctionProcessor(){}

void FunctionProcessor::ProcessNode() {
  TranslatorData* translator_data = info_->translator_data();
  Statement* tmp_statement = new(pool()) Statement;
  translator_data->set_current_statement(tmp_statement);
  translator_data->set_function(function_);
  ProcessFormalParameter();
  translator_data->set_rest_injection(false);
  VariableStmt* dsta_stmt = 0;
  VariableStmt* rest_stmt = 0;
  if (tmp_statement->IsContainDestructuring()) {
    NodeList *list = DstaProcessor::CreateDstaExtractedVarStmt(tmp_statement, info_);
    VariableDeclarationList* decl_list = new(pool()) VariableDeclarationList(function_->line_number());
    decl_list->Append(list);
    dsta_stmt = builder()->CreateVarStmt(decl_list, function_->line_number());
  }
  ProcessBody();
  if (function_->IsGenerator()) {
    ProcessYield();
  }
  if (dsta_stmt && rest_stmt) {
    dsta_stmt->AddChild(rest_stmt->first_child());
    function_->InsertBefore(dsta_stmt);
  } else if (dsta_stmt) {
    function_->InsertBefore(dsta_stmt);
  } else if (rest_stmt) {
    function_->InsertBefore(rest_stmt);
  }
  if (default_parameter_->child_length() > 0) {
    NodeIterator iterator = default_parameter_->ChildNodes();
    while (iterator.HasNext()) {
      ExpressionStmt* stmt = builder()->CreateExpStmt(iterator.Next(), function_->line_number());
      function_->InsertBefore(stmt);
    }
  }
}

bool FunctionProcessor::IsDestructuring(AstNode* node) {
  if (node->node_type() == AstNode::kArrayLikeLiteral || node->node_type() == AstNode::kObjectLikeLiteral) {
    return true;
  } else {
    if (node->node_type() == AstNode::kAssignmentExp) {
      return builder()->IsDestructringLeftHandSide(node->CastToExpression()->CastToAssigment()->left_value());
    }
    return false;
  }
}

void FunctionProcessor::ProcessFormalParameter() {
  if (!formal_parameter_->IsEmpty() && argc_ > 0) {
    IVisitor* visitor = info_->visitor();
    NodeIterator iterator = formal_parameter_->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* node = iterator.Next();
      Expression* expression = node->CastToExpression();
      AssignmentExp* maybe_initialiser = expression->CastToAssigment();
      if (maybe_initialiser) {
        ProcessDefaultParameter(maybe_initialiser);
      } else if (IsDestructuring(node)) {
        bool has_default_parameter = node->node_type() == AstNode::kAssignmentExp;
        DstaProcessor processor(node, info_);
        Literal* value = processor.ProcessNode();
        if (has_default_parameter) {
          AstNode* arg = value->Clone(pool());
          AssignmentExp* assign = new(pool()) AssignmentExp('=', arg, maybe_initialiser->right_value()->Clone(pool()), function_->line_number());
          value->parent_node()->ReplaceChild(value, assign);
          ProcessDefaultParameter(assign);
        }
      } else if (node->node_type() == AstNode::kAssignmentExp) {
        ProcessDefaultParameter(node->CastToExpression()->CastToAssigment());
      } else if (node->node_type() == AstNode::kCallExp) {
        ProcessPropertyParameter(node->CastToExpression()->CastToCallExp());
      } else if (node->node_type() == AstNode::kLiteral &&
                 node->CastToLiteral()->value_type() == Literal::kRest) {
        ProcessRestParameter(node);
      } else {
        node->Accept(visitor);
      }
    }
  }
}



void FunctionProcessor::ProcessDefaultParameter(Literal *value) {
  Literal* initialiser = value->Clone(pool())->CastToLiteral();
  Literal* arg = initialiser->Clone(pool())->CastToLiteral();
  AstNode* default_value = initialiser->first_child();
  arg->RemoveAllChild();
  initialiser->RemoveAllChild();
  CompareExp* logical_or = new(pool()) CompareExp(Token::JS_LOGICAL_OR, arg, default_value, function_->line_number());
  AssignmentExp* exp = builder()->CreateAssignment('=', initialiser, logical_or, value->line_number());
  default_parameter_->InsertBefore(exp);
}


void FunctionProcessor::ProcessDefaultParameter(AssignmentExp *exp) {
  Literal* arg = builder()->CreateTmpNode(info_->translator_data()->tmp_index(), function_->line_number());
  exp->parent_node()->ReplaceChild(exp, arg);
  CompareExp* logical_or =
      new(pool()) CompareExp(Token::JS_LOGICAL_OR, arg->Clone(pool()), exp->right_value(), function_->line_number());
  AssignmentExp* ret = builder()->CreateAssignment('=', exp->left_value()->Clone(pool()), logical_or, function_->line_number());
  default_parameter_->InsertBefore(ret);
  ret->Accept(info_->visitor());
}


void FunctionProcessor::ProcessPropertyParameter(CallExp *exp) {
  Literal* arg = builder()->CreateTmpNode(info_->translator_data()->tmp_index(), function_->line_number());
  exp->parent_node()->ReplaceChild(exp, arg);
  AssignmentExp* ret = builder()->CreateAssignment('=', exp, arg->Clone(pool()), function_->line_number());
  default_parameter_->InsertBefore(ret);
  exp->Accept(info_->visitor());
}



void FunctionProcessor::ProcessBody() {
  IVisitor *visitor = info_->visitor();
  if (function_->context_type() == Function::kThis) {
    bool is_assignment = false;
    if (!function_->IsDeclared()) {
      is_assignment = true;
    }
    if (!is_assignment) {
      AstNode* name = function_->name();
      if (!name) {
        return;
      }
      Literal* fn_name = name->CastToLiteral();
      Literal* bind_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kBind),
                                                    Token::JS_IDENTIFIER, function_->line_number(), Literal::kProperty);
      Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                    Token::JS_THIS, function_->line_number(), Literal::kThis);
      NodeList* arg = builder()->CreateNodeList(1, this_sym);
      CallExp* bind_call = builder()->CreateNormalAccessor(bind_sym, arg, function_->line_number());
      CallExp* new_context = builder()->CreateDotAccessor(fn_name->Clone(pool()), bind_call, function_->line_number());
      AssignmentExp* initialiser = builder()->CreateAssignment('=', fn_name->Clone(pool()), new_context, function_->line_number());
      AstNode* statement = function_->parent_node();
      ExpressionStmt* assignment_stmt = builder()->CreateExpStmt(initialiser, function_->line_number());
      statement->InsertBefore(assignment_stmt, statement->first_child());
    } else {
      Statement* mark = new(pool()) Statement;
      Literal* bind_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kBind),
                                                    Token::JS_IDENTIFIER, function_->line_number(), Literal::kProperty);
      Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                    Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
      NodeList* arg = builder()->CreateNodeList(1, this_sym);
      CallExp* bind_call = builder()->CreateNormalAccessor(bind_sym, arg, function_->line_number());
      AstNode* parent = function_->parent_node();
      parent->ReplaceChild(function_, mark);
      CallExp* binding_function = builder()->CreateDotAccessor(function_, bind_call, function_->line_number());
      parent->ReplaceChild(mark, binding_function);
    }
  }
  if (function_->function_type() == Function::kShorten) {
    Statement* stmt_tmp = new(pool()) Statement;
    info_->translator_data()->set_current_statement(stmt_tmp);
    function_->first_child()->Accept(visitor);
    ReturnStmt* ret_stmt = builder()->CreateReturnStmt(function_->first_child()->Clone(pool()), function_->line_number());
    function_->RemoveAllChild();
    if (stmt_tmp->IsContainDestructuring()) {
      NodeList* list = new(pool()) NodeList;
      list->AddChild(DstaProcessor::CreateTmpVarDecl(stmt_tmp, info_));
      list->AddChild(ret_stmt);
      function_->Append(list);
    }
    function_->AddChild(ret_stmt);
  } else {
    NodeIterator iterator = function_->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(visitor);
    }
  }
}


void FunctionProcessor::ProcessRestParameter(AstNode* rest_expression) {
  AstNode* dummy_literal = rest_expression;
  rest_expression = rest_expression->first_child();
  Literal* rhs = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kArguments),
                                           Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
  NodeList* list = new(pool()) NodeList;
  std::stringstream st;
  st << (argc_ - 1);
  Literal* arg =
      builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL,function_->line_number(), Literal::kNumeric);
  Literal* to_array = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kToArray),
                                                Token::JS_IDENTIFIER, function_->line_number(), Literal::kProperty);
  list->AddChild(rhs);
  list->AddChild(arg);
  CallExp* nrm = builder()->CreateNormalAccessor(to_array, list, function_->line_number());
  CallExp* std_to_array = builder()->CreateRuntimeMod(nrm, function_->line_number());
  AstNode* node = rest_expression->Clone(pool());
  AssignmentExp* assign = new(pool()) AssignmentExp('=', rest_expression, std_to_array, function_->line_number());
  default_parameter_->AddChild(assign);
  if (node->CastToLiteral()) {
    dummy_literal->parent_node()->ReplaceChild(dummy_literal, rest_expression);
  } else {
    Literal* tmp_node = builder()->CreateTmpNode(info_->translator_data()->tmp_index(), function_->line_number());
    dummy_literal->parent_node()->ReplaceChild(dummy_literal, tmp_node);
  }
}


class YieldHelper : private Processor {
 public :
  YieldHelper(Function* function, ProcessorInfo* info)
      : Processor(), state_(0), is_state_injection_(false), no_state_injection_(false),
      function_(function), info_(info),
      clause_(CreateCaseClause(state_)),
      body_(new(pool()) NodeList){}

  void ProcessYield() {
    ProcessIteration();
    ProcessTryCatch();
    ProcessVarDecl();
    iterator_ = function_->ChildNodes();
    while (iterator_.HasNext()) {
      AstNode* yield_stmt = iterator_.Next();
      if (yield_stmt->node_type() != AstNode::kVariableStmt) {
        ProcessStmtInYield(yield_stmt);
      }
    }
    std::list<YieldMark*>::iterator begin = mark_list_.begin(),end = mark_list_.end();
    while (begin != end) {
      YieldMark* mark = (*begin);
      int state_num = mark->Adjust(state_);
      std::stringstream st;
      st << state_num;
      mark->ReEntrantNode()->value()->set_token(st);
      ++begin;
    }
    body_->AddChild(clause_);
    Finish();
  }

  NodeList* GetBody() {
    return body_;
  }
                                
 private :
  void Finish() {
    Literal* handler = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThrowStopIteration),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Empty* empty = new(pool()) Empty;
    CallExp* exp = builder()->CreateNormalAccessor(handler, empty, function_->line_number());
    CallExp* runtime = builder()->CreateRuntimeMod(exp, function_->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(runtime, function_->line_number());
    Literal* is_safe = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSafeFlag),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                   Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    ReturnStmt* ret = builder()->CreateReturnStmt(undefined, function_->line_number());
    IFStmt* if_stmt = builder()->CreateIFStmt(is_safe, ret, stmt, function_->line_number());
    CreateCaseClause(0, true);
    clause_->AddChild(if_stmt);
    body_->AddChild(clause_);
  }

  VariableStmt* CreateClearCacheStmt(const char* symbol) {
    Literal* cache = builder()->CreateNameNode(symbol, Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                   Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* clear_cache = builder()->CreateVarInitiliser(cache->value(), undefined, function_->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(function_->line_number(), 1, clear_cache);
    VariableStmt* clear_cache_stmt = builder()->CreateVarStmt(decl_list, function_->line_number());
    function_->set_variable_list(clear_cache);
    return clear_cache_stmt;
  }
                                
  void ProcessTryCatch() {
    const Function::TryCatchList &list = function_->try_catch_list();
    if (list.size() > 0) {
      Function::TryCatchList::const_iterator begin = list.begin(),end = list.end();
      while (begin != end) {
        TryStmt* stmt = (*begin);
        bool has_finally = (!stmt->finally_block()->IsEmpty());
        ExpressionStmt* catch_stmt = ProcessCatch(stmt);
        VariableStmt* clear_catch_stmt = CreateClearCacheStmt(SymbolList::symbol(SymbolList::kCatchCache));
        ExpressionStmt* finally_stmt = 0;
        VariableStmt* clear_finally_stmt = 0;
        if (has_finally) {
          finally_stmt = ProcessFinally(stmt);
          clear_finally_stmt = CreateClearCacheStmt(SymbolList::symbol(SymbolList::kFinallyCache));
          clear_finally_stmt->MarkAsSplitableStatement();
        } else {
          clear_catch_stmt->MarkAsSplitableStatement();
        }
        CopyTryCatchBody(has_finally, stmt, catch_stmt,
                          clear_catch_stmt, finally_stmt, clear_finally_stmt);
        ++begin;
      }
    }
  }

  void CopyTryCatchBody(bool has_finally, TryStmt* stmt, ExpressionStmt* catch_stmt,
                         VariableStmt* clear_catch_stmt, ExpressionStmt* finally_stmt,
                         VariableStmt* clear_finally_stmt) {
    NodeIterator iterator = stmt->first_child()->ChildNodes();
    AstNode* last = 0;
    AstNode* first = 0;
    while (iterator.HasNext()) {
      if (!last) {
        first = last = iterator.Next();
        stmt->parent_node()->InsertBefore(last, stmt);
      } else {
        AstNode* item = iterator.Next();
        stmt->parent_node()->InsertAfter(item, last);
        last = item;
      }
    }
    stmt->parent_node()->InsertAfter(clear_catch_stmt, stmt);
    stmt->parent_node()->InsertBefore(catch_stmt, (first)? first : stmt);
    if (has_finally) {
      stmt->parent_node()->InsertAfter(clear_finally_stmt, clear_catch_stmt);
      stmt->parent_node()->InsertAfter(finally_stmt, catch_stmt);
    }
    stmt->parent_node()->RemoveChild(stmt);
  }
                                
  ExpressionStmt* ProcessFinally(TryStmt* stmt) {
    AstNode* block = stmt->finally_block();
    NodeList* arg = new(pool()) NodeList;
    AstNode* block_body = block->first_child();
    Function* fn = builder()->CreateFunctionDecl(new(pool()) Empty, arg, block_body, stmt->line_number());
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFinallyCache),
                                              Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    AssignmentExp* assign = builder()->CreateAssignment('=', name, fn, stmt->line_number());
    ExpressionStmt* ret = builder()->CreateExpStmt(assign, stmt->line_number());
    return ret;
  }

  ExpressionStmt* ProcessCatch(TryStmt* stmt) {
    Literal* block = stmt->catch_block()->CastToLiteral();
    NodeList* arg = new(pool()) NodeList;
    AstNode* block_body = block->first_child()->first_child();
    Literal* arg_name = block->Clone(pool())->CastToLiteral();
    arg_name->RemoveAllChild();
    arg->AddChild(arg_name);
    Function* fn = builder()->CreateFunctionDecl(new(pool()) Empty, arg, block_body, stmt->line_number());
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCatchCache),
                                              Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    AssignmentExp* assign = builder()->CreateAssignment('=', name, fn, stmt->line_number());
    YieldMark* mark = new(pool()) YieldMark;
    Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                               Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* pseudo_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
    AssignmentExp* exp = builder()->CreateAssignment('=', state, pseudo_state, stmt->line_number());
    ExpressionStmt* exp_stmt = builder()->CreateExpStmt(exp, stmt->line_number());
    mark->ReEntrantNode(pseudo_state);
    fn->InsertBefore(exp_stmt);
    stmt->parent_node()->InsertAfter(mark, stmt);
    ExpressionStmt* ret = builder()->CreateExpStmt(assign, stmt->line_number());
    return ret;
  }
                                
  void ProcessVarDecl() {
    const Function::VariableList &list = function_->variable_list();
    if (list.size() > 0) {
      TransformVarDecl(list);
      Function::VariableList::const_iterator begin = list.begin(),end = list.end();
      while (begin != end) {
        Literal* value = (*begin);
        if (value->parent_node() && value->parent_node()->parent_node() &&
             value->parent_node()->parent_node()->parent_node()) {
          value->parent_node()->parent_node()->parent_node()->RemoveChild(value->parent_node()->parent_node());
        }
        ++begin;
      }
    }
    function_->InsertBefore(CreateStateInitialiser());
    function_->InsertBefore(CreateResultInitialiser());
    function_->InsertBefore(CreateNewBornCheckFlag());
  }

  void TransformVarDecl(const Function::VariableList& list) {
    Function::VariableList::const_iterator begin = list.begin(),end = list.end();
    while (begin != end) {
      Literal* value = (*begin);
      Literal* ident = new(pool()) Literal(Literal::kIdentifier, function_->line_number());
      ident->set_value(value->value());
      ident->AddChild(new(pool()) Empty);
      if (!value->first_child()->IsEmpty()) {
        AssignmentExp* assign = builder()->CreateAssignment('=', ident, value->first_child()->Clone(pool()), value->line_number());
        ExpressionStmt* stmt = builder()->CreateExpStmt(assign, value->line_number());
        if (value->parent_node()->parent_node()->CastToStatement()->IsSplitable()) {
          stmt->MarkAsSplitableStatement();
        }
        value->parent_node()->parent_node()->parent_node()->InsertBefore(stmt, value->parent_node()->parent_node());
      }
      Literal* var = new(pool()) Literal(Literal::kVariable, value->line_number());
      var->set_value(value->value());
      var->AddChild(new(pool()) Empty);
      VariableDeclarationList* decl_list = builder()->CreateVarDeclList(value->line_number(), 1, var);
      VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, value->line_number());
      function_->InsertBefore(var_stmt);
      ++begin;
    }
  }

  VariableStmt* CreateStateInitialiser() {
    TokenInfo* state = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kYieldState),
                                       Token::JS_IDENTIFIER, function_->line_number());
    Literal* begin_state = builder()->CreateNameNode("0" ,Token::JS_NUMERIC_LITERAL,
                                                     function_->line_number(), Literal::kIdentifier);
    Literal* value = builder()->CreateVarInitiliser(state, begin_state, function_->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(function_->line_number(), 1, value);
    return builder()->CreateVarStmt(decl_list, function_->line_number());
  }

  VariableStmt* CreateResultInitialiser() {
    TokenInfo* result = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kYieldResult),
                                        Token::JS_IDENTIFIER, function_->line_number());
    Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                   Token::JS_IDENTIFIER, function_->line_number(),
                                                   Literal::kIdentifier);
    Literal* value = builder()->CreateVarInitiliser(result, undefined, function_->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(function_->line_number(), 1, value);
    return builder()->CreateVarStmt(decl_list, value->line_number());
  }


  VariableStmt* CreateNewBornCheckFlag() {
    TokenInfo* result = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kIsNewBorn),
                                        Token::JS_IDENTIFIER, function_->line_number());
    Literal* true_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                                  Token::JS_IDENTIFIER, function_->line_number(),
                                                  Literal::kIdentifier);
    Literal* value = builder()->CreateVarInitiliser(result, true_sym, function_->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(function_->line_number(), 1, value);
    return builder()->CreateVarStmt(decl_list, function_->line_number());
  }
                                
  void ProcessIteration() {
    typedef Function::StmtList::const_reverse_iterator Iterator;
    Iterator begin = function_->statement_list().rbegin(),end = function_->statement_list().rend();
    int count = 0;
    int size = function_->statement_list().size();
    YieldMark *if_escape_mark = 0;
    while (begin != end) {
      AstNode* iteration_stmt = (*begin);
      if (iteration_stmt->node_type() == AstNode::kFor ||
           iteration_stmt->node_type() == AstNode::kForWithVar) {
        ProcessFor(iteration_stmt->CastToStatement()->CastToIteration(), size, count);
      } else if (iteration_stmt->node_type() == AstNode::kForIn ||
                  iteration_stmt->node_type() == AstNode::kForInWithVar ||
                  iteration_stmt->node_type() == AstNode::kForEach ||
                  iteration_stmt->node_type() == AstNode::kForEachWithVar) {
        ProcessForIn(iteration_stmt->CastToStatement()->CastToIteration(), size, count);
      } else if (iteration_stmt->node_type() == AstNode::kWhile) {
        ProcessWhile(iteration_stmt->CastToStatement()->CastToIteration(), size, count);
      } else if (iteration_stmt->node_type() == AstNode::kDoWhile) {
        ProcessDoWhile(iteration_stmt->CastToStatement()->CastToIteration(), size, count);
      } else if (iteration_stmt->node_type() == AstNode::kIFStmt) {
        if (if_escape_mark == 0) {
          if_escape_mark = new(pool()) YieldMark;
        }
        if_escape_mark = ProcessIFStmt(iteration_stmt->CastToStatement()->CastToIFStmt(), if_escape_mark, size, count);
      } else if (iteration_stmt->node_type() == AstNode::kSwitchStmt) {
        ProcessSwitchStmt(iteration_stmt->CastToStatement()->CastToSwitchStmt(), size, count);
      }
      count++;
      ++begin;
    }
    NodeIterator iterator = function_->ChildNodes();
  }


  YieldMark* ProcessIFStmt(IFStmt* node, YieldMark* escape_mark, int, int) {
    AstNode* parent = node->parent_node();
    YieldMark* mark = new(pool()) YieldMark;
    mark->SetAdjust(1);
    parent->InsertBefore(mark, node);
    node->parent_node()->RemoveChild(node);
    AstNode* cond = node->condition();
    AstNode* then_body = node->then_statement();
    AstNode* else_body = node->else_statement();
    AstNode* current = 0;//init after.
    BlockStmt* then_block;
    BlockStmt* else_block;
                                                                
    YieldMark* normal_mark = new(pool()) YieldMark;
    YieldMark* abnormal_mark = new(pool()) YieldMark;
    {
      Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                 Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
                                                                
      Literal* dynamic_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
      AssignmentExp* assign = builder()->CreateAssignment('=', state, dynamic_state, node->line_number());
      ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
      BreakStmt *break_stmt = new(pool()) BreakStmt(node->line_number());
      break_stmt->AddChild(new(pool()) Empty);
      then_block = builder()->CreateBlockStmt(node->line_number(), 2, exp_stmt, break_stmt);
      normal_mark->ReEntrantNode(dynamic_state);
    }

    {
      Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                 Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
                                                                
      Literal* dynamic_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
      AssignmentExp* assign = builder()->CreateAssignment('=', state, dynamic_state, node->line_number());
      ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
      BreakStmt *break_stmt = new(pool()) BreakStmt(node->line_number());
      break_stmt->AddChild(new(pool()) Empty);
      else_block = builder()->CreateBlockStmt(node->line_number(), 2, exp_stmt, break_stmt);
      abnormal_mark->ReEntrantNode(dynamic_state);
    }
                                                                
    IFStmt* if_stmt = builder()->CreateIFStmt(cond, then_block, else_block, node->line_number());
    parent->InsertBefore(if_stmt, mark);
    if_stmt->MarkAsSplitableStatement();
                                                                
    AstNode* last;
    if (then_body->node_type() == AstNode::kBlockStmt) {
      NodeIterator iterator = then_body->ChildNodes();
      while (iterator.HasNext()) {
        AstNode* item = iterator.Next();
        if (!item->IsEmpty()) {
          if (!current) {
            current = item;
            parent->InsertBefore(current, mark);
          } else {
            AstNode* tmp = item;
            parent->InsertAfter(tmp, current);
            current = tmp;
          }
        }
      }
      last = current;
    } else if (!then_body->IsEmpty()) {
      current = last = then_body;
      parent->InsertBefore(last, mark);
    }
    last->parent_node()->InsertBefore(normal_mark, last);
    last->CastToStatement()->MarkAsSplitableStatement();
    AstNode* embed_ptr = 0;
    {
      Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                 Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
                                                                
      Literal* dynamic_state = 0;
      if (escape_mark->ReEntrantNode() == 0) {
        dynamic_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
        escape_mark->ReEntrantNode(dynamic_state);
      } else {
        dynamic_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
        dynamic_state->set_value(escape_mark->ReEntrantNode()->value());
      }
                                                                                                
      AssignmentExp* assign = builder()->CreateAssignment('=', state, dynamic_state, node->line_number());
      ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
      last->parent_node()->InsertAfter(exp_stmt, last);
      BreakStmt *break_stmt = new(pool()) BreakStmt(node->line_number());
      break_stmt->AddChild(new(pool()) Empty);
      last->parent_node()->InsertAfter(break_stmt, exp_stmt);
      break_stmt->MarkAsSplitableStatement();
      embed_ptr = current = break_stmt;
    }

    if (!else_body->IsEmpty()) {
      if (else_body->node_type() == AstNode::kBlockStmt) {
        NodeIterator iterator = else_body->ChildNodes();
        while (iterator.HasNext()) {
          AstNode* item = iterator.Next();
          if (!item->IsEmpty()) {
            if (!current) {
              current = item;
              parent->InsertBefore(current, mark);
            } else {
              AstNode* tmp = item;
              parent->InsertAfter(tmp, current);
              current = tmp;
            }
          }
        }
        last = current;
      } else {
        current = last = else_body;
        parent->InsertBefore(last, mark);
      }
      last->parent_node()->InsertBefore(abnormal_mark, last);
      if (else_body->node_type() != AstNode::kIFStmt) {
        last->parent_node()->InsertAfter(escape_mark, last);
        escape_mark = 0;
      }
    } else {
      last->parent_node()->InsertAfter(abnormal_mark, last);
      last->parent_node()->InsertAfter(escape_mark, abnormal_mark);
      escape_mark->SetAdjust(1);
      escape_mark = 0;
    }
                                                                
    if (!last->IsEmpty()) {
      last->CastToStatement()->MarkAsSplitableStatement();
    }
                                                                
    mark->parent_node()->RemoveChild(mark);
    return escape_mark;
  }


  void ProcessSwitchStmt(SwitchStmt* node, int, int) {
    YieldMark* mark = new(pool()) YieldMark;
    AstNode* parent = node->parent_node();
    parent->InsertAfter(mark, node);
    NodeIterator iterator = node->ChildNodes();
    AstNode* last = 0;
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      if (!item->first_child()->IsEmpty()) {
        bool has_break = false;
        bool has_child = false;
        NodeIterator inner = item->ChildNodes();
        item->RemoveAllChild();
        while (inner.HasNext()) {
          AstNode *statement = inner.Next();
          if (statement->node_type() != AstNode::kBreakStmt) {
            if (statement->node_type() == AstNode::kReturnStmt) {
              has_break = true;
            }
            if (statement->node_type() == AstNode::kBlockStmt) {
              NodeIterator block_iterator = statement->first_child()->ChildNodes();
              while (block_iterator.HasNext()) {
                AstNode* item = block_iterator.Next();
                if (item->node_type() != AstNode::kBreakStmt) {
                  if (item->node_type() == AstNode::kReturnStmt) {
                    has_break = true;
                  }
                  if (!last) {
                    parent->InsertBefore(item, mark);
                    last = item;
                    has_child = true;
                  } else {
                    parent->InsertAfter(item, last);
                    last = item;
                    has_child = true;
                  }
                } else {
                  has_break = true;
                }
              }
            } else {
              if (!last) {
                parent->InsertBefore(statement, mark);
                last = statement;
                has_child = true;
              } else {
                parent->InsertAfter(statement, last);
                last = statement;
                has_child = true;
              }
            }
          } else {
            has_break = true;
          }
        }
        Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                   Token::JS_IDENTIFIER, item->line_number(), Literal::kIdentifier);
        Literal* zero = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, node->line_number(), Literal::kNumeric);
        AssignmentExp* assign = builder()->CreateAssignment('=', state, zero, node->line_number());
        ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
        BreakStmt* stmt = new(pool()) BreakStmt(item->line_number());
        stmt->AddChild(new(pool()) Empty);
        NodeList* list = builder()->CreateNodeList(2, exp_stmt, stmt);
        item->AddChild(list);
        YieldMark* state_mark = new(pool()) YieldMark;
        state_mark->ReEntrantNode(zero);
        state_mark->SetNoStateInjection();
        if (!has_child && has_break) {
          BreakStmt* stmt = new(pool()) BreakStmt(item->line_number());
          stmt->AddChild(new(pool()) Empty);
          stmt->MarkAsSplitableStatement();
          if (last) {
            parent->InsertAfter(stmt, last);
          } else {
            parent->InsertBefore(stmt, mark);
          }
        }
        if (has_break) {
          Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                     Token::JS_IDENTIFIER, item->line_number(), Literal::kIdentifier);
          Literal* cloned = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, node->line_number(), Literal::kNumeric);
          AssignmentExp* assign;
          if (mark->ReEntrantNode() == 0) {
            assign = builder()->CreateAssignment('=', state, cloned, node->line_number());
            mark->ReEntrantNode(cloned);
          } else {
            cloned->set_value(mark->ReEntrantNode()->value());
            assign = builder()->CreateAssignment('=', state, cloned, node->line_number());
          }
          ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
          if (last) {
            if (has_child) {
              parent->InsertBefore(exp_stmt, last);
            } else {
              parent->InsertAfter(exp_stmt, last);
            }
          } else {
            parent->InsertBefore(exp_stmt, mark);
          }
        }
        if (last) {
          if (has_child) {
            parent->InsertBefore(state_mark, last);
          } else {
            parent->InsertAfter(state_mark, last);
          }
        } else {
          parent->InsertBefore(state_mark, mark);
        }
                                                                                                                                
        if (last) {
          last->CastToStatement()->MarkAsSplitableStatement();
        }
      }
    }
    BreakStmt* stmt = new(pool()) BreakStmt(node->line_number());
    stmt->AddChild(new(pool()) Empty);
    stmt->MarkAsSplitableStatement();
    parent->InsertAfter(stmt, node);
    if (!mark->ReEntrantNode()) {
      parent->RemoveChild(mark);
    }
  }
                                
  void ProcessDoWhile(IterationStmt* node, int, int) {
    if (node->previous_sibling()) {
      node->previous_sibling()->CastToStatement()->MarkAsSplitableStatement();
    }
    AstNode* parent = node->parent_node();
    YieldMark* mark = new(pool()) YieldMark;
    parent->InsertBefore(mark, node);
    node->parent_node()->RemoveChild(node);
    AstNode* cond = node->expression();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
                                                                
    YieldMark* state_mark = new(pool()) YieldMark;
    ExYieldStateNode* ex_node = ProcessDynamicState(cond);
    state_mark->ReEntrantNode(ex_node->LoopBackPtr());
    parent->InsertAfter(ex_node, mark);
    parent->InsertBefore(state_mark, mark);
    if (body->node_type() == AstNode::kBlockStmt) {
      NodeIterator iterator = body->ChildNodes();
      while (iterator.HasNext()) {
        AstNode* item = iterator.Next();
        if (!current) {
          current = item;
          parent->InsertBefore(current, mark);
        } else {
          AstNode* tmp = item;
          parent->InsertAfter(tmp, current);
          current = tmp;
        }
      }
    } else {
      parent->InsertBefore(body->first_child(), mark);
    }
    mark->parent_node()->RemoveChild(mark);
  }

                                
  void ProcessWhile(IterationStmt* node, int, int) {
    AstNode* parent = node->parent_node();
    YieldMark* mark = new(pool()) YieldMark;
    mark->SetAdjust(1);
    parent->InsertBefore(mark, node);
    node->parent_node()->RemoveChild(node);
    AstNode* cond = node->expression();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
                                                                
    YieldMark* state_mark = new(pool()) YieldMark;
    state_mark->SetAdjust(1);
    ExYieldStateNode* ex_node = ProcessDynamicState(cond);
    IFStmt* if_stmt = CreateEscapeState(cond, ex_node);
    state_mark->ReEntrantNode(ex_node->LoopBackPtr());
    parent->InsertAfter(ex_node, mark);
    parent->InsertBefore(if_stmt, mark);
    parent->InsertBefore(state_mark, if_stmt);
    if_stmt->MarkAsSplitableStatement();
                                                                
    if (body->node_type() == AstNode::kBlockStmt) {
      NodeIterator iterator = body->ChildNodes();
      while (iterator.HasNext()) {
        AstNode* item = iterator.Next();
        if (!current) {
          current = item;
          parent->InsertBefore(current, mark);
        } else {
          AstNode* tmp = item;
          parent->InsertAfter(tmp, current);
          current = tmp;
        }
      }
    } else {
      parent->InsertBefore(body->first_child(), mark);
    }
    mark->parent_node()->RemoveChild(mark);
  }

                                
  void ProcessFor(IterationStmt* node, int, int) {
    AstNode* parent = node->parent_node();
    YieldMark* mark = new(pool()) YieldMark;
    mark->SetAdjust(1);
    parent->InsertBefore(mark, node);
    node->parent_node()->RemoveChild(node);
    AstNode* exp = node->expression();
    AstNode* cond = exp->first_child()->next_sibling();
    AstNode* counter = cond->next_sibling();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    if (node->node_type() == AstNode::kForWithVar) {
      if (!exp->first_child()->IsEmpty()) {
        VariableDeclarationList* list = new(pool()) VariableDeclarationList(node->line_number());
        list->Append(exp->first_child());
        VariableStmt* stmt = builder()->CreateVarStmt(list, node->line_number());
        parent->InsertBefore(stmt, mark);
        NodeIterator iterator = list->ChildNodes();
        while (iterator.HasNext()) {
          AstNode* item = iterator.Next();
          function_->set_variable_list(item->CastToLiteral());
        }
      }
    }
    if (!cond->IsEmpty()) {
      YieldMark* state_mark = new(pool()) YieldMark;
      state_mark->SetAdjust(1);
      ExYieldStateNode* ex_node = ProcessDynamicState(cond);
      IFStmt* if_stmt = CreateEscapeState(cond, ex_node);
      state_mark->ReEntrantNode(ex_node->LoopBackPtr());
      parent->InsertAfter(ex_node, mark);
      parent->InsertBefore(if_stmt, mark);
      parent->InsertBefore(state_mark, if_stmt);
      if_stmt->MarkAsSplitableStatement();
    }
    ExpressionStmt* stmt = builder()->CreateExpStmt(counter, node->line_number());
    parent->InsertAfter(stmt, mark);
    if (body->node_type() == AstNode::kBlockStmt) {
      NodeIterator iterator = body->ChildNodes();
      while (iterator.HasNext()) {
        AstNode* item = iterator.Next();
        if (!current) {
          current = item;
          parent->InsertBefore(current, mark);
        } else {
          AstNode* tmp = item;
          parent->InsertAfter(tmp, current);
          current = tmp;
        }
      }
    } else {
      parent->InsertBefore(body->first_child(), mark);
    }
    mark->parent_node()->RemoveChild(mark);
  }


  void ProcessForIn(IterationStmt* node, int size, int count) {
    AstNode* exp = node->expression();
    TranslatorData* translator_data = info_->translator_data();
    Literal* tmp_node = builder()->CreateTmpNode(translator_data->tmp_index(), node->line_number());
    tmp_node->set_value_type(Literal::kVariable);
    tmp_node->AddChild(new(pool()) Empty);
    AstNode* index_exp = exp->first_child();
    AstNode* target_exp = index_exp->next_sibling();
    IterationStmt* iter = new(pool()) IterationStmt(AstNode::kForInWithVar, node->line_number());
    NodeList* list = new(pool()) NodeList;
    list->AddChild(tmp_node);
    list->AddChild(target_exp);
    iter->set_expression(list);
    Literal* array_lhs = builder()->CreateTmpNode(translator_data->tmp_index(), node->line_number());
    ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(node->line_number());
    Literal* tmp_array = builder()->CreateVarInitiliser(array_lhs->value(), array, node->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(node->line_number(), 1, tmp_array);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, node->line_number());
    function_->InsertBefore(var_stmt);
    Literal* push = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPush),
                                              Token::JS_IDENTIFIER, 0, Literal::kProperty);
    NodeList* arg = new(pool()) NodeList;
    Literal* name = tmp_node->Clone(pool())->CastToLiteral();
    name->set_value_type(Literal::kIdentifier);
    arg->AddChild(name);
    CallExp* push_call = builder()->CreateNormalAccessor(push, arg, node->line_number());
    CallExp* push_accessor = builder()->CreateDotAccessor(array_lhs->Clone(pool()), push_call, node->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(push_accessor, node->line_number());
    iter->AddChild(stmt);
    node->parent_node()->InsertBefore(iter, node);
    TransformForIn(node, array_lhs->Clone(pool())->CastToLiteral(), size, count);
  }


  void TransformForIn(IterationStmt* node, Literal* array, int size, int count) {
    TranslatorData* translator_data = info_->translator_data();
    AstNode* exp = node->expression();
    AstNode* index_exp = exp->first_child();
    Literal* tmp_node = builder()->CreateTmpNode(translator_data->tmp_index(), node->line_number());
    Literal* zero = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, node->line_number(), Literal::kNumeric);
    Literal* index = builder()->CreateVarInitiliser(tmp_node->value(), zero, node->line_number());
    Literal* length = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLength),
                                                Token::JS_IDENTIFIER, node->line_number(), Literal::kProperty);
    CallExp* length_accessor = builder()->CreateDotAccessor(array, length, node->line_number());
    Literal* var_length = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLength),
                                                    Token::JS_IDENTIFIER, node->line_number(), Literal::kIdentifier);
    Literal* len_cache = builder()->CreateVarInitiliser(var_length->value(), length_accessor, node->line_number());
    NodeList* var_list = builder()->CreateNodeList(2, index, len_cache);
    Literal* index_name = builder()->CreateNameNode(index->value()->token(),
                                                    Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* len_name = builder()->CreateNameNode(len_cache->value()->token(),
                                                  Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    CompareExp* cmp = new(pool()) CompareExp('<', index_name, len_name, node->line_number());
    UnaryExp* unary = builder()->CreateUnaryExp(Token::JS_INCREMENT, index_name->Clone(pool()), node->line_number());
                                                                
    IterationStmt* iter = new(pool()) IterationStmt(AstNode::kForWithVar, node->line_number());
    NodeList* list = builder()->CreateNodeList(3, var_list, cmp, unary);
    iter->set_expression(list);
    AstNode* index_stmt;
    if (index_exp->CastToLiteral()->value_type() == Literal::kVariable) {
      CallExp* accessor = builder()->CreateArrayAccessor(array->Clone(pool()), index_name->Clone(pool()), node->line_number());
      index_exp->RemoveAllChild();
      index_exp->AddChild(accessor);
      VariableDeclarationList* decl_list = builder()->CreateVarDeclList(node->line_number(), 1, index_exp);
      index_stmt = builder()->CreateVarStmt(decl_list, node->line_number());
    } else {
      CallExp* accessor = builder()->CreateArrayAccessor(array->Clone(pool()), index_name->Clone(pool()), node->line_number());
      AssignmentExp* assign = builder()->CreateAssignment('=', index_exp, accessor, node->line_number());
      index_stmt = builder()->CreateExpStmt(assign, node->line_number());
    }
                                                                
    AstNode* maybeBlock = node->first_child();
    if (maybeBlock->node_type() == AstNode::kBlockStmt) {
      maybeBlock->InsertBefore(index_stmt);
      iter->AddChild(maybeBlock);
    } else {
      BlockStmt* block = builder()->CreateBlockStmt(node->line_number(), 2, index_stmt, maybeBlock);
      iter->AddChild(block);
    }
    node->parent_node()->ReplaceChild(node, iter);
    ProcessFor(iter, size, count);
  }
                                

  IFStmt* CreateEscapeState(AstNode* cond, ExYieldStateNode *ex_node) {
    Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                               Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
                                                                
    Literal* dynamic_state = builder()->CreateNameNode("0", Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
    AssignmentExp* assign = builder()->CreateAssignment('=', state, dynamic_state, cond->line_number());
    ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, cond->line_number());

    BreakStmt *break_stmt = new(pool()) BreakStmt(cond->line_number());
    Expression *exp = new(pool()) Expression(cond->line_number());
    exp->AddChild(cond);
    exp->MarkParenthesis();
    UnaryExp *not_exp = builder()->CreateUnaryExp('!', exp, cond->line_number());
    break_stmt->AddChild(new(pool()) Empty);
                                                                
    BlockStmt* if_block = builder()->CreateBlockStmt(cond->line_number(), 2, exp_stmt, break_stmt);
    IFStmt *if_stmt = builder()->CreateIFStmt(not_exp, if_block, new(pool()) Empty, cond->line_number());
    ex_node->EscapePtr(dynamic_state);
    return if_stmt;
  }

  ExpressionStmt* CreateStateAssignment(const char* state) {
    Literal* state_node = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                    Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* state_val = builder()->CreateNameNode(state, Token::JS_NUMERIC_LITERAL, 0, Literal::kNumeric);
    AssignmentExp* assign = builder()->CreateAssignment('=', state_node, state_val, 0);
    return builder()->CreateExpStmt(assign, 0);
  }

  ExYieldStateNode* ProcessDynamicState(AstNode* cond) {
    ExpressionStmt* exp_stmt = CreateStateAssignment("0");
    ExpressionStmt* next_stmt = CreateStateAssignment("0");
    BreakStmt *break_stmt = new(pool()) BreakStmt(cond->line_number());
    break_stmt->AddChild(new(pool()) Empty);
                                                                
    BlockStmt* else_block = builder()->CreateBlockStmt(cond->line_number(), 1, next_stmt);
    BlockStmt* if_block = builder()->CreateBlockStmt(cond->line_number(), 2, exp_stmt, break_stmt);
    IFStmt* if_stmt = builder()->CreateIFStmt(cond, if_block, else_block, cond->line_number());
    ExYieldStateNode* ex_node = new(pool()) ExYieldStateNode;
    ex_node->LoopBackPtr(exp_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->right_value()->CastToLiteral());
    ex_node->NextPtr(next_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->right_value()->CastToLiteral());
    ex_node->IfStmtPtr(if_stmt);
    return ex_node;
  }
                                
                                
  CaseClause* CreateCaseClause(int64_t line, bool is_error = false) {
    clause_ = new(pool()) CaseClause(line);
    if (!is_error) {
      Literal* state = CreateCurrentState(line);
      clause_->set_expression(state);
    } else {
      Literal* error = builder()->CreateNameNode("-1", Token::JS_IDENTIFIER, 0, Literal::kNumeric);
      clause_->set_expression(error);
    }
    return clause_;
  }

  Literal* CreateCurrentState(int64_t line) {
    std::stringstream st;
    st << state_;
    Literal* state_exp = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL,
                                                   line, Literal::kNumeric);
    return state_exp;
  }

  ExpressionStmt* CreateNextState(int64_t line) {
    Literal* yield_state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                     Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    std::stringstream st;
    st << (state_ + 1);
    Literal* state = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL,
                                               line, Literal::kNumeric);
    AssignmentExp* exp = builder()->CreateAssignment('=', yield_state, state, line);
    ExpressionStmt* stmt = builder()->CreateExpStmt(exp, line);
    return stmt;
  }

  void SetState(int64_t line) {
    if (is_state_injection_) {
      if (!iterator_.HasNext()) {
        state_ = -2;
        clause_->InsertBefore(CreateNextState(line));
      } else {
        clause_->InsertBefore(CreateNextState(line));
        state_++;
      }
    } else {
      if (!iterator_.HasNext()) {
        state_ = -2;
      } else {
        state_++;
      }
    }
  }
                                
  void ProcessStmtInYield(AstNode* yield_stmt) {
    function_->RemoveChild(yield_stmt);
    if (yield_stmt->node_type() == AstNode::kReturnStmt && !no_state_injection_) {
      is_state_injection_ = true;
    }
    if (yield_stmt->node_type() == AstNode::kYieldMark) {
      YieldMark* yield_mark = yield_stmt->CastToStatement()->CastToYieldMark();
      if (yield_mark->GetNoStateInjection()) {
        no_state_injection_ = true;
        is_state_injection_ = false;
      }
      int state_num = (iterator_.HasNext())? yield_mark->Adjust(state_) : -1;
      std::stringstream st;
      st << state_num;
      yield_mark->ReEntrantNode()->value()->set_token(st);
      //mark_list_.push_back(yield_stmt->CastToStatement()->CastToYieldMark());
    } else if (yield_stmt->node_type() == AstNode::kExYieldStateNode) {
      ExYieldStateNode* ex_node = yield_stmt->CastToStatement()->CastToYieldState();
      std::stringstream st;
      Literal* esc = ex_node->EscapePtr();
      SetState(yield_stmt->line_number());
      st << ((state_ < 0)? -1 : state_);
      if (esc) {
        esc->value()->set_token(st.str());
      }
      ex_node->NextPtr()->value()->set_token(st);
      clause_->AddChild(ex_node->IfStmtPtr());
      is_state_injection_ = false;
      body_->AddChild(clause_);
      if (iterator_.HasNext()) {
        CreateCaseClause(function_->line_number());
      }
    } else if (yield_stmt->CastToStatement() && yield_stmt->CastToStatement()->IsSplitable()) {
      std::list<YieldMark*>::iterator begin = mark_list_.begin(),end = mark_list_.end();
      while (begin != end) {
        YieldMark* mark = (*begin);
        int state_num = (iterator_.HasNext())? mark->Adjust(state_) : -1;
        std::stringstream st;
        st << state_num;
        mark->ReEntrantNode()->value()->set_token(st);
        ++begin;
      }
      mark_list_.clear();
      SetState(yield_stmt->line_number());
      clause_->AddChild(yield_stmt);
      is_state_injection_ = false;
      no_state_injection_ = false;
      body_->AddChild(clause_);
      if (iterator_.HasNext()) {
        CreateCaseClause(function_->line_number());
      }
    } else {
      clause_->AddChild(yield_stmt);
    }
  }
                                
  int state_;
  bool is_state_injection_;
  bool no_state_injection_;
  Function* function_;
  ProcessorInfo* info_;
  CaseClause* clause_;
  NodeList* body_;
  NodeIterator iterator_;
  std::list<YieldMark*> mark_list_;
};


class GeneratorHelper : private Processor {
 public :

  GeneratorHelper(Function* function, NodeList* body, ProcessorInfo* info)
      : Processor(), function_(function), body_(body), switch_stmt_(new(pool()) SwitchStmt(function->line_number())),
      info_(info) {}
                                
  void ProcessGenerator() {
    Literal* yield_state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                                     Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    switch_stmt_->set_expression(yield_state);
    switch_stmt_->AddChild(body_);
    ProcessReturn();
  }
                                
 private :

  void CreateStateLoop(Function* fn) {
    NodeList *generator_arg = new(pool()) NodeList;
    Literal* one_exp = builder()->CreateNameNode("1", Token::JS_NUMERIC_LITERAL, function_->line_number(), Literal::kNumeric);
    Literal* is_send = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSendFlag),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* is_safe = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSafeFlag),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    StatementList* stmt_list = new(pool()) StatementList;
    stmt_list->AddChild(switch_stmt_);
    BlockStmt* block = new(pool()) BlockStmt(function_->line_number());
    block->AddChild(stmt_list);
    IterationStmt* iter = new(pool()) IterationStmt(AstNode::kWhile, fn->line_number());
    Expression* exp = new(pool()) Expression(fn->line_number());
    exp->AddChild(one_exp);
    iter->set_expression(exp);
    iter->AddChild(block);
    generator_arg->AddChild(is_send);
    generator_arg->AddChild(is_safe);
    fn->set_argv(generator_arg);
    if (function_->try_catch_list().size() > 0) {
      TryStmt* stmt = new(pool()) TryStmt(function_->line_number());
      BlockStmt* block = new(pool()) BlockStmt(function_->line_number());
      stmt->set_catch_block(CreateCatchHandler());
      stmt->set_finally_block(CreateFinallyHandler());
      AstNode* node = iter->first_child()->first_child();
      iter->RemoveAllChild();
      block->AddChild(node);
      stmt->AddChild(block);
      iter->AddChild(stmt);
    }
    fn->AddChild(iter);
  }


  BlockStmt* CreateExceptionReturnValueCheckStmt(CallExp* call_handler) {
    Literal* cache = builder()->CreateTmpNode(info_->translator_data()->tmp_index(), call_handler->line_number());
    AstNode* return_value = cache->Clone(pool());
    cache->set_value_type(Literal::kVariable);
    cache->AddChild(call_handler);
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(call_handler->line_number(), 1, cache);
    VariableStmt* value_stmt = builder()->CreateVarStmt(decl_list, call_handler->line_number());
    ReturnStmt* return_value_stmt = builder()->CreateReturnStmt(return_value, call_handler->line_number());
    BlockStmt* blk = builder()->CreateBlockStmt(call_handler->line_number(), 1, return_value_stmt);
    Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined), Token::JS_IDENTIFIER, call_handler->line_number(), Literal::kIdentifier);
    CompareExp* is_defined = new(pool()) CompareExp(Token::JS_NOT_EQ, return_value->Clone(pool()), undefined, call_handler->line_number());
    IFStmt* is_return = builder()->CreateIFStmt(is_defined, blk, new(pool()) Empty, call_handler->line_number());
    BlockStmt* check_return = builder()->CreateBlockStmt(call_handler->line_number(), 2, value_stmt, is_return);
    return check_return;
  }
                                
  Literal* CreateCatchHandler() {
    Literal* catches = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kException),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    BlockStmt* catch_block = new(pool()) BlockStmt(function_->line_number());
    Literal* handler = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCatchCache),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    NodeList* args = new(pool()) NodeList;
    args->AddChild(catches->Clone(pool()));
    CallExp* call_handler = builder()->CreateNormalAccessor(handler, args, function_->line_number());

    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt(call_handler);
                                                                
    IFStmt* if_stmt = new(pool()) IFStmt(function_->line_number());
    Literal* thrower = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThrowException),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    NodeList* list = new(pool()) NodeList;
    list->AddChild(catches->Clone(pool()));
    CallExp* throw_call = builder()->CreateNormalAccessor(thrower, list, function_->line_number());
    CallExp* runtime_accessor = builder()->CreateRuntimeMod(throw_call, function_->line_number());
    ExpressionStmt* call_stmt = builder()->CreateExpStmt(runtime_accessor, function_->line_number());
    if_stmt->set_condition(handler->Clone(pool()));
    if_stmt->set_then_statement(check_return);
    if_stmt->set_else_statement(call_stmt);
    StatementList *catch_stmt_list = new(pool()) StatementList;
    catch_stmt_list->AddChild(if_stmt);
    catch_block->AddChild(catch_stmt_list);
    catches->AddChild(catch_block);
    return catches;
  }

  AstNode* CreateFinallyHandler() {
    BlockStmt* finally_block = new(pool()) BlockStmt(function_->line_number());
    Literal* handler = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFinallyCache),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    NodeList* args = new(pool()) NodeList;
    CallExp* call_handler = builder()->CreateNormalAccessor(handler, args, function_->line_number());
    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt(call_handler);
    IFStmt* if_stmt = new(pool()) IFStmt(function_->line_number());
    if_stmt->set_condition(handler->Clone(pool()));
    if_stmt->set_then_statement(check_return);
    if_stmt->set_else_statement(new(pool()) Empty);
    StatementList *finally_stmt_list = new(pool()) StatementList;
    finally_stmt_list->AddChild(if_stmt);
    finally_block->AddChild(finally_stmt_list);
    return finally_block;
  }
                                
  IFStmt* CreateNewBornCheckStmt() {
    IFStmt* if_stmt = new(pool()) IFStmt(function_->line_number());
    Literal* is_send = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSendFlag),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* is_new_born = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kIsNewBorn),
                                                     Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* false_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFalse),
                                                   Token::JS_IDENTIFIER, function_->line_number(),
                                                   Literal::kIdentifier);
    ExpressionStmt* stmt = builder()->CreateExpStmt(builder()->CreateAssignment('=', is_new_born, false_sym, function_->line_number()), function_->line_number());
    UnaryExp* not_is_send = new(pool()) UnaryExp('!', is_send, function_->line_number());
    if_stmt->set_condition(not_is_send);
    BlockStmt* then_block = new(pool()) BlockStmt(function_->line_number());
    then_block->AddChild(stmt);
    if_stmt->set_then_statement(then_block);
    IFStmt* else_if_stmt = new(pool()) IFStmt(function_->line_number());
    Literal* arguments = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kArguments),
                                                   Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* one = builder()->CreateNameNode("1", Token::JS_NUMERIC_LITERAL, function_->line_number(), Literal::kNumeric);
    CallExp* array_accessor = builder()->CreateArrayAccessor(arguments, one, function_->line_number());
    Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                   Token::JS_NUMERIC_LITERAL, function_->line_number(),
                                                   Literal::kIdentifier);
    CompareExp* undef_check = new(pool()) CompareExp(Token::JS_NOT_EQ, array_accessor, undefined, function_->line_number());
    CompareExp* comp = new(pool()) CompareExp(Token::JS_LOGICAL_AND, is_send->Clone(pool()), is_new_born, function_->line_number());
    CompareExp* comp2 = new(pool()) CompareExp(Token::JS_LOGICAL_AND, comp, undef_check, function_->line_number());
    BlockStmt* else_block = new(pool()) BlockStmt(function_->line_number());
    Literal* handler = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kExceptionHandler),
                                                 Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* message = builder()->CreateNameNode("'attempt to send to newborn generator.'", Token::JS_STRING_LITERAL, function_->line_number(), Literal::kString);
    NodeList* handle_list = new(pool()) NodeList;
    handle_list->AddChild(message);
    CallExp* handle_exp = builder()->CreateNormalAccessor(handler, handle_list, function_->line_number());
    CallExp* runtime = builder()->CreateRuntimeMod(handle_exp, function_->line_number());
    ExpressionStmt* exp_stmt = builder()->CreateExpStmt(runtime, function_->line_number());
    else_if_stmt->set_condition(comp2);
    else_block->AddChild(exp_stmt);
    else_if_stmt->set_then_statement(else_block);
    else_if_stmt->set_else_statement(new(pool()) Empty);
    if_stmt->set_else_statement(else_if_stmt);
    return if_stmt;
  }

  Literal* ObjectInitialiser(Literal* generator, bool is_send) {
    Literal* name;
    Literal* boolean;
    if (!is_send) {
      name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldNext),
                                       Token::JS_IDENTIFIER, function_->line_number(),
                                       Literal::kProperty);
      boolean = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                          Token::JS_IDENTIFIER, function_->line_number(),
                                          Literal::kIdentifier);
    } else {
      name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldSend),
                                       Token::JS_IDENTIFIER, function_->line_number(),
                                       Literal::kProperty);
      boolean = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFalse),
                                          Token::JS_IDENTIFIER, function_->line_number(),
                                          Literal::kIdentifier);
    }
    Literal* bind_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kBind),
                                                  Token::JS_IDENTIFIER, function_->line_number(),
                                                  Literal::kProperty);
    Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                  Token::JS_IDENTIFIER, function_->line_number(),
                                                  Literal::kIdentifier);
                                                                
    CallExp* dot = builder()->CreateDotAccessor(generator->Clone(pool()), bind_sym, function_->line_number());
    NodeList* arg = new(pool()) NodeList;
    arg->AddChild(this_sym);
    arg->AddChild(boolean);
    CallExp* call = builder()->CreateNormalAccessor(dot, arg, function_->line_number());
    name->AddChild(call);
    return name;
  }

  Function* CloseInitialiser() {
    Literal* state = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kYieldState),
                                               Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    Literal* error_state = builder()->CreateNameNode("-1", Token::JS_NUMERIC_LITERAL, function_->line_number(), Literal::kNumeric);
    AssignmentExp* assign = builder()->CreateAssignment('=', state, error_state, function_->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(assign, function_->line_number());
    Function* close_fn = new(pool()) Function(function_->line_number());
    close_fn->set_name(new(pool()) Empty);
    close_fn->set_argv(new(pool()) NodeList);
    close_fn->AddChild(stmt);
    if (function_->try_catch_list().size() > 0) {
      Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kFinallyCache),
                                                Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
      CallExp* exp = builder()->CreateNormalAccessor(name, new(pool()) NodeList, function_->line_number());
      ExpressionStmt* stmt = builder()->CreateExpStmt(exp, function_->line_number());
      IFStmt* if_stmt = builder()->CreateIFStmt(name->Clone(pool()), stmt, new(pool()) Empty, function_->line_number());
      close_fn->AddChild(if_stmt);
    }
    return close_fn;
  }
                                
  void GeneratorInitialiser(Function* fn) {
    CreateStateLoop(fn);
    fn->InsertBefore(CreateNewBornCheckStmt());
    Literal* generator = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGenerator),
                                                   Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier, true);
    Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                  Token::JS_IDENTIFIER, 0, Literal::kIdentifier);
    Literal* generator_init = builder()->CreateVarInitiliser(generator->value(), fn, function_->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(function_->line_number(), 1, generator_init);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, function_->line_number());
    function_->AddChild(var_stmt);
    Literal* create_generator = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCreateGenerator),
                                                          Token::JS_IDENTIFIER, function_->line_number(), Literal::kIdentifier);
    NodeList* args = builder()->CreateNodeList(3, generator, CloseInitialiser(), this_sym);
    CallExp* create_generator_call = builder()->CreateNormalAccessor(create_generator, args, function_->line_number());
    CallExp* runtime = builder()->CreateRuntimeMod(create_generator_call, function_->line_number());
    ReturnStmt* ret = builder()->CreateReturnStmt(runtime, function_->line_number());
    function_->AddChild(ret);
  }
                                
  void ProcessReturn() {
    Function* fn = new(pool()) Function(function_->line_number());
    fn->set_name(new(pool()) Empty);
    GeneratorInitialiser(fn);
  }
                                
  Function* function_;
  NodeList* body_;
  SwitchStmt *switch_stmt_;
  ProcessorInfo* info_;
                                
};


void FunctionProcessor::ProcessYield() {
  YieldHelper helper(function_, info_);
  helper.ProcessYield();
  NodeList* body = helper.GetBody();
  GeneratorHelper ge_helper(function_, body, info_);
  ge_helper.ProcessGenerator();
}

}
