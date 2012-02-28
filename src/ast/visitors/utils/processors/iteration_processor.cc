#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/iteration_processor.h>
#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/js_token.h>
#include <ast/visitors/utils/processors/processor_info.h>

namespace mocha {

void InsertBlock( IterationStmt* ast_node ) {
  AstNode* maybe_block = ast_node->first_child();
  if ( maybe_block->node_type() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( maybe_block->line_number() , 1 , maybe_block );
    ast_node->AddChild( stmt );
  }
}

void IterationProcessor::ProcessForNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  InsertBlock( ast_node );
  IVisitor *visitor = info->GetVisitor();
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* cond_exp = ( index_exp )? index_exp->next_sibling() : 0;
  AstNode* incr_exp = ( cond_exp )? cond_exp->next_sibling() : 0;
  index_exp->Accept( visitor );
  if ( cond_exp ) {
    cond_exp->Accept( visitor );
  }
  if ( incr_exp ) {
    incr_exp->Accept( visitor );
  }  
  ast_node->first_child()->Accept( visitor );
  if ( ast_node->generator() ) {
    info->GetInfo()->GetFunction()->set_statement_in_generator( ast_node );
  }
}

void IterationProcessor::ProcessForInNode( IterationStmt* ast_node , ProcessorInfo* info , bool is_regist ) {
  InsertBlock( ast_node );
  IVisitor *visitor = info->GetVisitor();
  bool has_variable = ast_node->node_type() == AstNode::kForInWithVar || ast_node->node_type() == AstNode::kForOfWithVar;
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  Literal* dsta_value = 0;
  bool is_dst = false;
  if ( AstUtils::IsDestructringLeftHandSide( index_exp ) ) {
    is_dst = true;
    dsta_value = DstaProcessor::ProcessNode( index_exp , info );
  } else {
    index_exp->Accept( visitor );
  }
  
  if ( is_dst && has_variable ) {
    dsta_value->set_value_type( Literal::kVariable );
    dsta_value->RemoveAllChild();
    dsta_value->AddChild( Empty::New() );
  } else {
    is_dst = ast_node->dsta_flag();
  }
  
  AstNode* dsta_stmt = 0;
  if ( is_dst && has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , info );
    dsta_stmt = AstUtils::CreateVarStmt( list , ast_node->line_number() );
  } else if ( is_dst && !has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
    dsta_stmt = AstUtils::CreateExpStmt( list , ast_node->line_number() );
  }
  
  target_exp->Accept( visitor );
  ast_node->first_child()->Accept( visitor );
  
  AstNode* body = ast_node->first_child();
  if ( is_dst ) {
    body->first_child()->InsertBefore( dsta_stmt );
  }
  if ( ast_node->generator() && is_regist ) {
    info->GetInfo()->GetFunction()->set_statement_in_generator( ast_node );
  }
}


void IterationProcessor::ProcessForOfNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  InsertBlock( ast_node );
  ProcessForInNode( ast_node , info , false );
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  IterationStmt* while_stmt = IterationStmt::New( AstNode::kWhile , ast_node->line_number() );
  Literal* maybe_ident = target_exp->CastToLiteral();
  if ( ast_node->node_type() == AstNode::kForOfWithVar ) {
    AstNode* val = index_exp->Clone();
    Literal* maybe_value = index_exp->CastToLiteral();
    if ( maybe_value ) {
      maybe_value->set_value_type( Literal::kVariable );
      maybe_value->RemoveAllChild();
      maybe_value->AddChild( Empty::New() );
      VariableStmt* stmt = AstUtils::CreateVarStmt( index_exp , ast_node->line_number() );
      ast_node->parent_node()->InsertBefore( stmt , ast_node );
    }
    if ( val->CastToLiteral() ) {
      val->CastToLiteral()->set_value_type( Literal::kIdentifier );
    }
    index_exp = val;
  }
  if ( !maybe_ident ) {
    Literal* tmp = AstUtils::CreateTmpNode( info->GetInfo()->GetTmpIndex() , ast_node->line_number() );
    Literal* init = AstUtils::CreateVarInitiliser( tmp->value() , target_exp , ast_node->line_number() );
    VariableStmt* stmt = AstUtils::CreateVarStmt( init , ast_node->line_number() );
    Literal* target = tmp->Clone()->CastToLiteral();

    Literal* has_iterator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kHasIterator ),
                                                      Token::JS_IDENTIFIER , 0 , Literal::kProperty );
    Literal* get_iterator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGetIterator ),
                                                      Token::JS_IDENTIFIER , 0 , Literal::kProperty );
    CallExp* runtime_key = AstUtils::CreateRuntimeMod( has_iterator , ast_node->line_number() );
    CallExp* runtime_key2 = AstUtils::CreateRuntimeMod( get_iterator , ast_node->line_number() );
    NodeList* args = AstUtils::CreateNodeList( 1 , tmp->Clone() );
    CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_key , args , ast_node->line_number() );
    CallExp* get_iterator_call = AstUtils::CreateNormalAccessor( runtime_key2 , args->Clone() , ast_node->line_number() );
    ConditionalExp* cond_exp = ConditionalExp::New( runtime_call , get_iterator_call , tmp->Clone() , ast_node->line_number() );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , target->Clone() , cond_exp , ast_node->line_number() );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , ast_node->line_number() );
    ast_node->parent_node()->InsertBefore( stmt , ast_node );
    ast_node->parent_node()->InsertBefore( exp_stmt , ast_node );
    exp->ReplaceChild( target_exp , target );
    target_exp = target;
  }
  Literal* next = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kNoThrow ),
                                            Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kProperty );
  CallExp* next_call = AstUtils::CreateNormalAccessor( next , NodeList::New() , ast_node->line_number() );
  CallExp* dot_call = AstUtils::CreateDotAccessor( target_exp , next_call , ast_node->line_number() );
  CallExp* dot_exp = AstUtils::CreateDotAccessor( target_exp , next->Clone() , ast_node->line_number() );
  AssignmentExp* assign = AstUtils::CreateAssignment( '=' , index_exp , dot_call , ast_node->line_number() );
  Expression* expression = Expression::New( ast_node->line_number() );
  expression->AddChild( assign );
  expression->set_paren();
  while_stmt->set_expression( expression );

  while_stmt->AddChild( ast_node->first_child() );
  Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kExceptionHandler ),
                                               Token::JS_IDENTIFIER , 0 , Literal::kProperty );
  CallExp* runtime_call = AstUtils::CreateRuntimeMod( handler , ast_node->line_number() );
  char line_tmp[50];
  sprintf( line_tmp , "%lld" , ast_node->line_number() );
  Literal* line_num = AstUtils::CreateNameNode( line_tmp , Token::JS_NUMERIC_LITERAL , ast_node->line_number() , Literal::kNumeric );
  Literal* file_name = AstUtils::CreateNameNode( info->GetInfo()->GetRelativePath() , Token::JS_STRING_LITERAL  , ast_node->line_number() , Literal::kString );
  Literal* error = AstUtils::CreateNameNode( "'for of statement expect iterator or generator object.'",
                                               Token::JS_STRING_LITERAL , 0 , Literal::kString );
  NodeList* args = AstUtils::CreateNodeList( 3 , line_num , file_name , error );
  CallExp* handler_call = AstUtils::CreateNormalAccessor( runtime_call , args , ast_node->line_number() );
  ExpressionStmt* handler_stmt = AstUtils::CreateExpStmt( handler_call , ast_node->line_number() );
  BlockStmt* then_block = AstUtils::CreateBlockStmt( ast_node->line_number() , 1 , while_stmt );
  BlockStmt* else_block = AstUtils::CreateBlockStmt( ast_node->line_number() , 1 , handler_stmt );
  IFStmt* if_stmt = AstUtils::CreateIFStmt( dot_exp , then_block , else_block , ast_node->line_number() );
  ast_node->parent_node()->ReplaceChild( ast_node , if_stmt );

  if ( ast_node->generator() ) {
    info->GetInfo()->GetFunction()->set_statement_in_generator( while_stmt );
    info->GetInfo()->GetFunction()->set_statement_in_generator( if_stmt );
  }
}


void IterationProcessor::ProcessForEachNode( IterationStmt *ast_node , ProcessorInfo *info ) {
  InsertBlock( ast_node );
  IVisitor* visitor = info->GetVisitor();
  bool has_variable = ast_node->node_type() == AstNode::kForEachWithVar;
  AstNode* exp = ast_node->expression();
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
  Literal* dsta_value = 0;
  bool is_dst = false;
  
  if ( AstUtils::IsDestructringLeftHandSide( index_exp ) ) {
    is_dst = true;
    dsta_value = DstaProcessor::ProcessNode( index_exp , info );
  } else {
    index_exp->Accept( visitor );
  }
  if ( is_dst && has_variable ) {
    dsta_value->set_value_type( Literal::kVariable );
    index_exp->RemoveAllChild();
    index_exp->AddChild( Empty::New() );
  } else {
    is_dst = ast_node->dsta_flag();
  }
  
  AstNode* dsta_stmt = 0;
  if ( is_dst && has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , info );
    dsta_stmt = AstUtils::CreateVarStmt( list , ast_node->line_number() );
  } else if ( is_dst && !has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
    dsta_stmt = AstUtils::CreateExpStmt( list , ast_node->line_number() );
  }
  
  target_exp->Accept( visitor );
  ast_node->first_child()->Accept( visitor );
  ExpressionStmt* stmt;
  if ( has_variable ) {
    Literal *value = index_exp->Clone()->CastToLiteral();
    value->set_value_type( Literal::kIdentifier );
    CallExp* call = AstUtils::CreateArrayAccessor( target_exp->Clone() , value , ast_node->line_number() );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , value->Clone() , call , ast_node->line_number() );
    stmt = AstUtils::CreateExpStmt( exp , ast_node->line_number() );
  } else {
    CallExp* call = AstUtils::CreateArrayAccessor( target_exp->Clone() , index_exp->Clone() , ast_node->line_number() );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , index_exp->Clone() , call , ast_node->line_number() );
    stmt = AstUtils::CreateExpStmt( exp , ast_node->line_number() );
  }
  AstNode* body = ast_node->first_child();
  if ( is_dst ) {
    body->first_child()->InsertBefore( dsta_stmt );
  }
  body->first_child()->InsertBefore( stmt );
  if ( ast_node->generator() ) {
    info->GetInfo()->GetFunction()->set_statement_in_generator( ast_node );
  }
}

void IterationProcessor::ProcessWhileNode( IterationStmt *ast_node , ProcessorInfo *info ) {
  InsertBlock( ast_node );
  IVisitor* visitor = info->GetVisitor();
  bool is_dst = false;
  NodeList* dsta_list = 0;
  VariableStmt* var_stmt = 0;
  ast_node->expression()->Accept( visitor );
  if ( ( is_dst = ast_node->dsta_flag() ) ) {
    if ( ast_node->node_type() == AstNode::kDoWhile ) {
      var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , info );
    } else {
      var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , info );
    }
    dsta_list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
  }
  AstNode* body = ast_node->first_child();
  body->Accept( visitor );
  if ( is_dst ) {
    Expression* exp = Expression::New( ast_node->line_number());
    exp->AddChild( dsta_list );
    exp->set_paren();
    ExpressionStmt* stmt = ExpressionStmt::New( ast_node->line_number() );
    stmt->AddChild( exp );
    body->first_child()->InsertBefore( stmt );
    ast_node->parent_node()->InsertBefore( var_stmt , ast_node );
  }
  if ( ast_node->generator() ) {
    info->GetInfo()->GetFunction()->set_statement_in_generator( ast_node );
  }
}

}

