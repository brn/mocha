#include <mocha/roaster/ast/translator/processors/syntax_sugar_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/processors/syntax_sugar_processor.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>

namespace mocha {

typedef std::pair<AstNode*,AstNode*> AstPair;

AstPair FoldStatement(NodeIterator* iterator) {
  bool is_first = true;
  AstNode* first = 0;
  AstNode* current = 0;
  while (iterator->HasNext()) {
    if (is_first) {
      current = first = iterator->Next();
      is_first = false;
    } else {
      AstNode* item = iterator->Next();
      current->AddChild(item);
      current = item;
    }
  }
  return AstPair(first, current);
}

void SyntaxSugarProcessor::CreateClosure(AstNode* ast_node, AstNode* body, IVisitor* visitor, int64_t line) {
  Function* fn = LocalBuilder()->CreateFunctionDecl(new(LocalPool()) Empty, new(LocalPool()) Empty, body, line);
  fn->Accept(visitor);
  Expression* exp = new(LocalPool()) Expression(line);
  exp->AddChild(fn);
  exp->MarkParenthesis();
  Literal* call_sym = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kCall),
                                                Token::JS_IDENTIFIER ,line, Literal::kProperty);
  Literal* this_sym = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                Token::JS_THIS, line, Literal::kThis);
  NodeList* arg = LocalBuilder()->CreateNodeList(1, this_sym);
  CallExp* dot = LocalBuilder()->CreateDotAccessor(exp, call_sym, line);
  CallExp* this_call = LocalBuilder()->CreateNormalAccessor(dot, arg, line);
  ast_node->parent_node()->ReplaceChild(ast_node, this_call);
}

void SyntaxSugarProcessor::ProcessArrayComprehensions(ArrayLikeLiteral* literal, ProcessorInfo* info) {
  IVisitor* visitor = info->visitor();
  Literal* tmp = LocalBuilder()->CreateTmpNode(info->translator_data()->tmp_index(), literal->line_number());
  ArrayLikeLiteral* array = new(LocalPool()) ArrayLikeLiteral(literal->line_number());
  VariableDeclarationList* decl_list = LocalBuilder()->CreateVarDeclList(literal->line_number(),
                                                                    1,
                                                                    LocalBuilder()->CreateVarInitiliser(tmp->value(), array, literal->line_number()));
  VariableStmt* var_stmt = LocalBuilder()->CreateVarStmt(decl_list, literal->line_number());
  AstNode* expression = literal->elements()->first_child()->first_child();
  NodeIterator iterator = expression->next_sibling()->ChildNodes();
  AstPair result = FoldStatement(&iterator);
  Literal* push = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kPush),
                                            Token::JS_IDENTIFIER, literal->line_number(), Literal::kProperty);
  NodeList* list = LocalBuilder()->CreateNodeList(1, expression, literal->line_number());
  CallExp* push_accessor = LocalBuilder()->CreateDotAccessor(tmp->Clone(LocalPool()), push, literal->line_number());
  CallExp* push_call = LocalBuilder()->CreateNormalAccessor(push_accessor, list, literal->line_number());
  ExpressionStmt* exp_stmt = LocalBuilder()->CreateExpStmt(push_call, literal->line_number());
  if (result.second->node_type() == AstNode::kIFStmt) {
    IFStmt* if_stmt = result.second->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement(exp_stmt);
    if_stmt->set_else_statement(new(LocalPool()) Empty);
  } else {
    result.second->AddChild(exp_stmt);
  }
  ReturnStmt* stmt = LocalBuilder()->CreateReturnStmt(tmp->Clone(LocalPool()), literal->line_number());
  NodeList* body = LocalBuilder()->CreateNodeList(3, var_stmt, result.first, stmt);
  CreateClosure(literal, body, visitor, literal->line_number());
}

void SyntaxSugarProcessor::ProcessGeneratorExpression(GeneratorExpression* generator, ProcessorInfo* info) {
  IVisitor* visitor = info->visitor();
  NodeIterator iterator = generator->first_child()->ChildNodes();
  AstPair result = FoldStatement(&iterator);
  YieldExp* yield_exp = new(LocalPool()) YieldExp(generator->line_number());
  yield_exp->AddChild(generator->expression()->Clone(LocalPool()));
  ExpressionStmt* exp_stmt = LocalBuilder()->CreateExpStmt(yield_exp, generator->line_number());
  if (result.second->node_type() == AstNode::kIFStmt) {
    IFStmt* if_stmt = result.second->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement(exp_stmt);
    if_stmt->set_else_statement(new(LocalPool()) Empty);
  } else {
    result.second->AddChild(exp_stmt);
  }
  NodeList* body = LocalBuilder()->CreateNodeList(1, result.first);
  CreateClosure(generator, body, visitor, generator->line_number());
}

}
