#include <mocha/roaster/ast/visitors/utils/processors/syntax_sugar_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/utils/ast_utils.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/syntax_sugar_processor.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>

namespace mocha {

typedef std::pair<AstNode*,AstNode*> AstPair;

AstPair FoldStatement( NodeIterator* iterator ) {
  bool is_first = true;
  AstNode* first = 0;
  AstNode* current = 0;
  while ( iterator->HasNext() ) {
    if ( is_first ) {
      current = first = iterator->Next();
      is_first = false;
    } else {
      AstNode* item = iterator->Next();
      current->AddChild( item );
      current = item;
    }
  }
  return AstPair( first , current );
}

void CreateClosure( AstNode* ast_node , AstNode* body , IVisitor* visitor , int64_t line ) {
  Function* fn = AstUtils::CreateFunctionDecl( Empty::New() , Empty::New() , body , line );
  fn->Accept( visitor );
  Expression* exp = Expression::New( line );
  exp->AddChild( fn );
  exp->MarkParenthesis();
  Literal* call_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCall ),
                                                Token::JS_IDENTIFIER ,line , Literal::kProperty );
  Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                Token::JS_THIS , line , Literal::kThis );
  NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
  CallExp* dot = AstUtils::CreateDotAccessor( exp , call_sym , line );
  CallExp* this_call = AstUtils::CreateNormalAccessor( dot , arg , line );
  ast_node->parent_node()->ReplaceChild( ast_node , this_call );
}

void SyntaxSugarProcessor::ProcessArrayComprehensions( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  Literal* tmp = AstUtils::CreateTmpNode( info->visitor_info()->tmp_index() , literal->line_number() );
  ArrayLikeLiteral* array = ArrayLikeLiteral::New( literal->line_number() );
  VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( literal->line_number(),
                                                                    1,
                                                                    AstUtils::CreateVarInitiliser( tmp->value() , array , literal->line_number() ) );
  VariableStmt* var_stmt = AstUtils::CreateVarStmt( decl_list , literal->line_number() );
  AstNode* expression = literal->elements()->first_child()->first_child();
  NodeIterator iterator = expression->next_sibling()->ChildNodes();
  AstPair result = FoldStatement( &iterator );
  Literal* push = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kPush ),
                                            Token::JS_IDENTIFIER , literal->line_number() , Literal::kProperty );
  NodeList* list = AstUtils::CreateNodeList( 1 , expression , literal->line_number() );
  CallExp* push_accessor = AstUtils::CreateDotAccessor( tmp->Clone() , push , literal->line_number() );
  CallExp* push_call = AstUtils::CreateNormalAccessor( push_accessor , list , literal->line_number() );
  ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( push_call , literal->line_number() );
  if ( result.second->node_type() == AstNode::kIFStmt ) {
    IFStmt* if_stmt = result.second->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement( exp_stmt );
    if_stmt->set_else_statement( Empty::New() );
  } else {
    result.second->AddChild( exp_stmt );
  }
  ReturnStmt* stmt = AstUtils::CreateReturnStmt( tmp->Clone() , literal->line_number() );
  NodeList* body = AstUtils::CreateNodeList( 3 , var_stmt , result.first , stmt );
  CreateClosure( literal , body , visitor , literal->line_number() );
}

void SyntaxSugarProcessor::ProcessGeneratorExpression( GeneratorExpression* generator , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  NodeIterator iterator = generator->first_child()->ChildNodes();
  AstPair result = FoldStatement( &iterator );
  YieldExp* yield_exp = YieldExp::New( generator->line_number() );
  yield_exp->AddChild( generator->expression()->Clone() );
  ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( yield_exp , generator->line_number() );
  if ( result.second->node_type() == AstNode::kIFStmt ) {
    IFStmt* if_stmt = result.second->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement( exp_stmt );
    if_stmt->set_else_statement( Empty::New() );
  } else {
    result.second->AddChild( exp_stmt );
  }
  NodeList* body = AstUtils::CreateNodeList( 1 , result.first );
  CreateClosure( generator , body , visitor , generator->line_number() );
}

}
