#include <ast/visitors/utils/processors/syntax_sugar_processor.h>

namespace mocha {

void FoldStatement( NodeIterator* iterator ) {
  bool is_first = true;
  AstNode* first;
  AstNode* current;
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
  return current;
}

void CreateClosure( AstNode* body , IVisitor* visitor , int64_t line ) {
  Function* fn = AstUtils::CreateFunctionDecl( Empty::New() , Empty::New() , body );
  fn->Accept( visitor );
  Expression* exp = ManagedHandle::Retain<Expression>();
  exp->AddChild( fn );
  exp->IsParenthesis();
  Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                Token::JS_THIS , line , Literal::kThis );
  NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
  CallExp* dot = AstUtils::CreateDotAccessor( exp , call_sym );
  CallExp* this_call = AstUtils::CreateNormalAccessor( dot , arg );
  ast_node->parent_node()->ReplaceChild( ast_node , this_call );
}

void SyntaxSugarProcessor::ProcessArrayComprehensions( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  Literal* call_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCall ),
                                                Token::JS_PROPERTY , literal->line_number() , Literal::kProperty );
  Literal* tmp = AstUtils::CreateTmpNode( visitor_info_->tmp_index() );
  ArrayLikeLiteral* array = ArrayLikeLiteral::New( literal->line_number() );
  VariableStmt* var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarInitiliser( tmp->value() , array ) );
  AstNode* expression = ast_node->first_child();
  NodeIterator iterator = expression->next_sibling()->ChildNodes();
  AstNode* result = FoldStatement( &iterator );
  Literal* push = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPush ),
                                            Token::JS_PROPERTY , 0 , Literal::kProperty );
  NodeList* list = AstUtils::CreateNodeList( 1 , expression );
  CallExp* push_accessor = AstUtils::CreateDotAccessor( tmp->Clone() , push );
  CallExp* push_call = AstUtils::CreateNormalAccessor( push_accessor , list );
  ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( push_call );
  if ( result->node_type() == AstNode::kIFStmt ) {
    IFStmt* if_stmt = current->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement( exp_stmt );
    if_stmt->set_else_statement( Empty::New() );
  } else {
    result->AddChild( exp_stmt );
  }
  ReturnStmt* stmt = AstUtils::CreateReturnStmt( tmp->Clone() );
  NodeList* body = AstUtils::CreateNodeList( 3 , var_stmt , first , stmt );
  CreateClosure( body , visitor , literal->line_number() );
}

void SyntaxSugarProcessor::ProcessGeneratorExpression( GeneratorExpression* generator , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  Literal* call_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCall ),
                                                Token::JS_PROPERTY , generator->line_number() , Literal::kProperty );
  NodeIterator iterator = generator->first_child()->ChildNodes();
  AstNode* result = FoldStatement( &iterator );
  YieldExp* yield_exp = YieldExp::New( generator->line_number() );
  yield_exp->AddChild( generator->expression()->Clone() );
  ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( yield_exp );
  if ( current->node_type() == AstNode::kIFStmt ) {
    IFStmt* if_stmt = current->CastToStatement()->CastToIFStmt();
    if_stmt->set_then_statement( exp_stmt );
    if_stmt->set_else_statement( Empty::New() );
  } else {
    result->AddChild( exp_stmt );
  }
  NodeList* body = AstUtils::CreateNodeList( 1 , first );
  CreateClosure( body , visitor , generator->line_number() );
}

}
