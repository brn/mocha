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
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include <sstream>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/ast/translator/translator.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/ast/translator/processors/iteration_processor.h>
#include <mocha/roaster/ast/translator/processors/variable_processor.h>
#include <mocha/roaster/ast/translator/processors/class_processor.h>
#include <mocha/roaster/ast/translator/processors/trait_processor.h>
#include <mocha/roaster/ast/translator/processors/function_processor.h>
#include <mocha/roaster/ast/translator/processors/fileroot_processor.h>
#include <mocha/roaster/ast/translator/processors/module_processor.h>
#include <mocha/roaster/ast/translator/processors/export_processor.h>
#include <mocha/roaster/ast/translator/processors/import_processor.h>
#include <mocha/roaster/ast/translator/processors/call_processor.h>
#include <mocha/roaster/ast/translator/processors/yield_processor.h>
#include <mocha/roaster/ast/translator/processors/array_processor.h>
#include <mocha/roaster/ast/translator/processors/object_processor.h>
#include <mocha/roaster/ast/translator/processors/syntax_sugar_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>

namespace mocha {


#define VISITOR_IMPL(type) void AstTransformer::Visit##type(type* ast_node)
#define TOKEN yy::ParserImplementation::token

#ifdef PRINTABLE
#define PRINT_NODE_NAME ast_node->PrintNodeName();
#else
#define PRINT_NODE_NAME
#endif

#define REGIST(node) visitor_info_->set_current_statement(node)


Translator::Translator(bool is_runtime, CompilationEvent* e)
    : pool_(memory::Pool::Local()),
      builder_(AstBuilder::Local()),
      visitor_info_(new TranslatorData(is_runtime, e, new(pool()) DstaExtractedExpressions)),
      event_(e) {
  proc_info_(new ProcessorInfo(this, visitor_info_.Get()));
}

Translator::~Translator(){}


VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  AstNode* root = ast_node->first_child();
  if (root) {
    root->Accept(this);
  }
}

VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  FileRootProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}


VISITOR_IMPL(NodeList) {
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(VersionStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* body = ast_node->first_child();
  ast_node->RemoveAllChild();
  Function *fn_node =
      builder()->CreateFunctionDecl(new(pool()) Empty, new(pool()) Empty, body, ast_node->line_number());
  Expression* exp = new(pool()) Expression(ast_node->line_number());
  exp->AddChild(fn_node);
  exp->MarkParenthesis();
  Literal* call = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCall), Token::JS_IDENTIFIER,
                                            ast_node->line_number(), Literal::kProperty);
  CallExp* call_accessor = builder()->CreateDotAccessor(exp, call, ast_node->line_number());
  NodeList* args = builder()->CreateNodeList(1, builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                                           Token::JS_THIS, ast_node->line_number(),
                                                                           Literal::kThis));
  CallExp* fn_call = builder()->CreateNormalAccessor(call_accessor, args, ast_node->line_number());
  ExpressionStmt* an_stmt_node = builder()->CreateExpStmt(fn_call, ast_node->line_number());
  ast_node->AddChild(an_stmt_node);
  body->Accept(this);
}



VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

VISITOR_IMPL(ModuleStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ModuleProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}


VISITOR_IMPL(ExportStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ExportProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}

VISITOR_IMPL(ImportStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ImportProccessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}


VISITOR_IMPL(Statement) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
}


VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  VariableProcessor::ProcessVarList(ast_node->first_child(), proc_info_.Get());
  if (ast_node->IsContainDestructuring()) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt(ast_node, proc_info_.Get());
    ast_node->first_child()->Append(list);
  }
}


VISITOR_IMPL(LetStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
}


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept(this);
  if (ast_node->IsContainDestructuring()) {
    if (ast_node->IsNeedDestructuringTmpRef()) {
      NodeIterator iterator = ast_node->destructuring_node()->refs()->ChildNodes();
      VariableDeclarationList* var_list = new(pool()) VariableDeclarationList(ast_node->line_number());
      while (iterator.HasNext()) {
        Literal* node =
            builder()->CreateVarInitiliser(iterator.Next()->CastToLiteral()->value(),
                                         new(pool()) Empty, ast_node->line_number());
        var_list->AddChild(node);
      }
      VariableStmt *var_stmt = builder()->CreateVarStmt(var_list, ast_node->line_number());
      ast_node->parent_node()->InsertBefore(var_stmt, ast_node);
    }
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, proc_info_.Get());
    NodeIterator iter = list->ChildNodes();
    AstNode* last = 0;
    while (iter.HasNext()) {
      AstNode* item = iter.Next();
      ExpressionStmt* stmt = builder()->CreateExpStmt(item, ast_node->line_number());
      if (last) {
        ast_node->parent_node()->InsertAfter(stmt, last);
        last = stmt;
      } else {
        ast_node->parent_node()->InsertAfter(stmt, ast_node);
        last = stmt;
      }
    }
  }
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->condition()->Accept(this);
  AstNode* then_statement = ast_node->then_statement();
  AstNode* maybe_else_statement = ast_node->else_statement();
  if (then_statement->node_type() != AstNode::kBlockStmt) {
    BlockStmt* block = builder()->CreateBlockStmt(then_statement->line_number(), 1, then_statement);
    ast_node->set_then_statement(block);
    then_statement = block;
  }
  then_statement->Accept(this);
  if (ast_node->IsContainDestructuring()) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, proc_info_.Get());
    Expression* exp = new(pool()) Expression(ast_node->line_number());
    exp->Append(list);
    exp->IsParenthesis();
    ExpressionStmt* exp_stmt = new(pool()) ExpressionStmt(ast_node->line_number());
    exp_stmt->AddChild(exp);
    then_statement->first_child()->InsertBefore(exp_stmt);
    AstNode* parent = ast_node;
    AstNode* first_if = ast_node;
    while (parent->node_type() == AstNode::kIFStmt) {
      parent = parent->parent_node();
      if (parent->node_type() != AstNode::kIFStmt) {
        break;
      } else {
        first_if = parent;
      }
    }
    if (first_if->HasPrev() && first_if->previous_sibling()->node_type() == AstNode::kVariableStmt) {
      first_if->previous_sibling()->Append(DstaProcessor::CreateTmpVarDecl(ast_node, proc_info_.Get()));
    } else {
      parent->InsertBefore(DstaProcessor::CreateTmpVarDecl(ast_node, proc_info_.Get()), first_if);
    }
  }
  maybe_else_statement->Accept(this);
  if (ast_node->IsContainYield()) {
    visitor_info_->function()->set_statement_in_generator(ast_node);
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  switch (ast_node->node_type()) {
    case AstNode::kFor : //Fall Through
    case AstNode::kForWithVar :
      IterationProcessor::ProcessForNode(ast_node, proc_info_.Get());
      break;

    case AstNode::kForIn :
    case AstNode::kForInWithVar :
      IterationProcessor::ProcessForInNode(ast_node, proc_info_.Get());
      break;
    case AstNode::kForEach :
    case AstNode::kForEachWithVar :
      IterationProcessor::ProcessForEachNode(ast_node, proc_info_.Get());
      break;

    case AstNode::kForOf :
    case AstNode::kForOfWithVar :
      IterationProcessor::ProcessForOfNode(ast_node, proc_info_.Get());
      break;

    case AstNode::kDoWhile :
    case AstNode::kWhile :
      IterationProcessor::ProcessWhileNode(ast_node, proc_info_.Get());
      break;
  }
}


VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->expression();
  AstNode* body = ast_node->first_child();
  if (body->node_type() != AstNode::kBlockStmt) {
    BlockStmt* block = builder()->CreateBlockStmt(body->line_number(), 1, body);
    ast_node->RemoveAllChild();
    ast_node->AddChild(block);
    body = block;
  }
  exp->Accept(this);
  body->Accept(this);
  if (ast_node->IsContainDestructuring()) {
    VariableStmt* var_stmt = DstaProcessor::CreateTmpVarDecl(ast_node, proc_info_.Get());
    ast_node->parent_node()->InsertBefore(var_stmt, ast_node);
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(ast_node, proc_info_.Get());
    Expression* exp = new(pool()) Expression(ast_node->line_number());
    exp->Append(list);
    ExpressionStmt* exp_stmt = new(pool()) ExpressionStmt(ast_node->line_number());
    exp_stmt->AddChild(exp);
    body->first_child()->InsertBefore(exp_stmt);
  }
}

VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->expression();
  exp->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  if (ast_node->IsContainYield()) {
    visitor_info_->function()->set_statement_in_generator(ast_node);
  }
}


VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  Statement* stmt_tmp = new(pool()) Statement;
  REGIST(stmt_tmp);
  AstNode *parent = ast_node->parent_node();
  SwitchStmt *switch_stmt = reinterpret_cast<SwitchStmt* >(parent);
  ast_node->expression()->Accept(this);
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  ExpressionStmt* case_exp_stmt = 0;
  ExpressionStmt* cond_exp_stmt = 0;
  if (stmt_tmp->IsContainDestructuring()) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(stmt_tmp, proc_info_.Get());
    Expression* exp = new(pool()) Expression(ast_node->line_number());
    exp->Append(list);
    case_exp_stmt = new(pool()) ExpressionStmt(ast_node->line_number());
    case_exp_stmt->AddChild(exp);
    if (ast_node->child_length() > 0) {
      ast_node->InsertBefore(case_exp_stmt);
    } else {
      ast_node->AddChild(case_exp_stmt); 
    }
  }
  if (switch_stmt->IsContainDestructuring()) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment(switch_stmt, proc_info_.Get());
    Expression* exp = new(pool()) Expression(ast_node->line_number());
    exp->Append(list);
    exp->IsParenthesis();
    cond_exp_stmt = new(pool()) ExpressionStmt(ast_node->line_number());
    cond_exp_stmt->AddChild(exp);
    if (ast_node->child_length() > 0) {
      ast_node->InsertBefore(cond_exp_stmt);
    } else {
      ast_node->AddChild(cond_exp_stmt); 
    }
  }

}


VISITOR_IMPL(LabelledStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* symbol = ast_node->first_child();
  AstNode* statement = symbol->next_sibling();
  symbol->Accept(this);
  statement->Accept(this);
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* val = ast_node->expression();
  Expression* exp = val->CastToExpression();
  if (exp && !visitor_info_->runtime()) {
    if (exp->child_length() == 1) {
      Literal* name = exp->first_child()->CastToLiteral();
      if (name && name->value_type() == Literal::kIdentifier && strcmp(name->value()->token(), "StopIteration") == 0) {
        Literal* undefined = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                       Token::JS_IDENTIFIER, ast_node->line_number(), Literal::kIdentifier);
        ReturnStmt* stmt = builder()->CreateReturnStmt(undefined, ast_node->line_number());
        ast_node->parent_node()->ReplaceChild(ast_node, stmt);
      } else {
        ast_node->expression()->Accept(this);
      }
    } else {
      ast_node->expression()->Accept(this);
    }
  } else {
    ast_node->expression()->Accept(this);
  }
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept(this);
  if (!ast_node->catch_block()->IsEmpty()) {
    ast_node->catch_block()->first_child()->Accept(this);
  }
  ast_node->finally_block()->Accept(this);
  if (ast_node->IsContainYield()) {
    visitor_info_->function()->set_try_catch_list(ast_node);
  }
}


VISITOR_IMPL(AssertStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kAssert),
                                            Token::JS_IDENTIFIER, ast_node->line_number(), Literal::kProperty);
  CodegenVisitor visitor(visitor_info_->filename(), true, false);
  AstNode* expect = ast_node->first_child();
  AstNode* expression = expect->next_sibling();
  ast_node->RemoveAllChild();
  expect->Accept(this);
  expression->Accept(this);
  expression->Accept(&visitor);
  std::stringstream st;
  st << '"';
  std::string result = visitor.GetCode();
  bool is_escaped = false;
  for (int i = 0,len = result.size(); i < len; i++) {
    if (result.at(i) == '\n') {
      st << "\\n";
    } else if (result.at(i) == '\\' && !is_escaped) {
      st << '\\';
      is_escaped = true;
    } else if (result.at(i) == '"' && !is_escaped) {
      st << '\\';
      st << '"';
    } else if (is_escaped) {
      st << result.at(i);
      is_escaped = false;
    } else {
      st << result.at(i);
    }
  }
  st << '"';
  std::stringstream line_st;
  line_st << ast_node->line_number();
  Literal* line = builder()->CreateNameNode(line_st,
                                            Token::JS_NUMERIC_LITERAL, ast_node->line_number(), Literal::kNumeric);
  Literal* string_expression = builder()->CreateNameNode(st, Token::JS_STRING_LITERAL,
                                                         ast_node->line_number(), Literal::kString);
  Literal* filename = builder()->CreateNameNode(visitor_info_->relative_path(), Token::JS_STRING_LITERAL,
                                                ast_node->line_number(), Literal::kString);
  AstNode* arg = builder()->CreateNodeList(5, expect, expression, string_expression, line, filename);
  CallExp* exp = builder()->CreateRuntimeMod(name, ast_node->line_number());
  CallExp* call = builder()->CreateNormalAccessor(exp, arg, ast_node->line_number());
  ExpressionStmt* stmt = builder()->CreateExpStmt(call, ast_node->line_number());
  ast_node->AddChild(stmt);
  if (ast_node->IsContainDestructuring()) {
    AstNode* dsta_exp = DstaProcessor::CreateDstaExtractedAssignment(ast_node, proc_info_.Get());
    ExpressionStmt* exp_stmt = builder()->CreateExpStmt(dsta_exp, ast_node->line_number());
    ast_node->AddChild(exp_stmt);
  }
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  CallProcessor processor(ast_node, proc_info_.Get());
  switch (ast_node->call_type()) {
    case CallExp::kNormal :
      processor.ProcessFnCall();
      break;

    case CallExp::kDot :
    case CallExp::kBracket : {
      AstNode* args = ast_node->args();
      if (args->CastToExpression()->CastToObjectLikeLiteral()) {
        processor.ProcessExtendAccessor();
      } else {
        ast_node->callable()->Accept(this);
        ast_node->args()->Accept(this);
      }
    }
      break;

    case CallExp::kPrivate :
      processor.ProcessPrivateAccessor();
      break;

    case CallExp::kExtend :
      processor.ProcessExtendAccessor();
  }
}


VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(YieldExp) {
  PRINT_NODE_NAME;
  YieldProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}


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
  AstNode* left = ast_node->left_value();
  if (AstBuilder::IsDestructringLeftHandSide(left)) {
    DstaProcessor processor(left, proc_info_.Get());
    processor.ProcessNode();
  } else {
    ast_node->left_value()->Accept(this);
  }
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}

VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  Statement *tmp_stmt = new(pool()) Statement;
  REGIST(tmp_stmt);
  ClassProcessor cls(proc_info_.Get(), ast_node, tmp_stmt);
  cls.ProcessNode();
}

VISITOR_IMPL(Trait) {
  PRINT_NODE_NAME;
  TraitProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  FunctionProcessor processor(ast_node, proc_info_.Get());
  processor.ProcessNode();
};




VISITOR_IMPL(Literal) {
  PRINT_NODE_NAME;
  switch (ast_node->value_type()) {
    case Literal::kPrivateProperty : {
      translator_data_->set_private_property_list(TranslatorData::AstPair(ast_node, ast_node->first_child()));
    }
      break;
                        
    case Literal::kVariable :
      VariableProcessor::ProcessVarInitialiser(ast_node, proc_info_.Get());
      break;

    case Literal::kRest : {
      visitor_info_->set_rest_injection(true);
      ast_node->set_value_type(Literal::kIdentifier);
      ast_node->parent_node()->RemoveChild(ast_node);
      visitor_info_->set_rest_expression(ast_node->value());
    }
      break;

    case Literal::kThis : {
      Function* fn = visitor_info_->function();
      if (fn && fn->replaced_this()) {
        ast_node->set_value(fn->replaced_this()->value());
      }
    }
      break;

    case Literal::kPrivate : {
      CallExp* runtime_call = builder()->BuildPrivateRecordAccessor(ast_node->line_number());
      ast_node->parent_node()->ReplaceChild(ast_node, runtime_call);
    }
      break;

    case Literal::kSuper : {
      TokenInfo* info = new(pool()) TokenInfo(SymbolList::symbol(SymbolList::kSuper),
                                              Token::JS_IDENTIFIER, ast_node->line_number());
      ast_node->set_value(info);
      ast_node->set_value_type(Literal::kIdentifier);
    }
      break;
  }
}


VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  if (ast_node->IsLhs()) {
    DstaProcessor processor(ast_node, proc_info_.Get());
    processor.ProcessNode();
  } else {
    ArrayProcessor processor(ast_node, proc_info_.Get());
    processor.ProcessNode();
  }
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  if (ast_node->IsLhs()) {
    DstaProcessor processor(ast_node, proc_info_.Get());
    processor.ProcessNode();
  } else {
    ObjectProccessor processor(ast_node, proc_info_.Get());
    processor.ProcessNode();
  }
}

VISITOR_IMPL(VariableDeclarationList){}

VISITOR_IMPL(GeneratorExpression) {
  PRINT_NODE_NAME;
  SyntaxSugarProcessor::ProcessGeneratorExpression(ast_node, proc_info_.Get());
}

}

