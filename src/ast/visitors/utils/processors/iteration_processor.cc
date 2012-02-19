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

void IterationProcessor::ProcessForNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , maybeBlock );
    ast_node->AddChild( stmt );
  }
  IVisitor *visitor = info->GetVisitor();
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* cond_exp = ( index_exp )? index_exp->NextSibling() : 0;
  AstNode* incr_exp = ( cond_exp )? cond_exp->NextSibling() : 0;
  
  index_exp->Accept( visitor );
  
  if ( cond_exp ) {
    cond_exp->Accept( visitor );
  }
  
  if ( incr_exp ) {
    incr_exp->Accept( visitor );
  }
  
  ast_node->FirstChild()->Accept( visitor );
  if ( ast_node->GetYieldFlag() ) {
    info->GetInfo()->GetFunction()->SetStmtWithYield( ast_node );
  }
}

void IterationProcessor::ProcessForInNode( IterationStmt* ast_node , ProcessorInfo* info , bool is_regist ) {
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , maybeBlock );
    ast_node->AddChild( stmt );
  }
  IVisitor *visitor = info->GetVisitor();
  bool has_variable = ast_node->NodeType() == AstNode::kForInWithVar || ast_node->NodeType() == AstNode::kForOfWithVar;
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();
  ValueNode* mayBeDsta = index_exp->CastToValue();
  bool is_dst = false;
  if ( mayBeDsta && mayBeDsta->ValueType() == ValueNode::kDst ) {
    is_dst = true;
    if ( has_variable ) {
      index_exp = index_exp->CastToValue()->Node();
    }
  }
  index_exp->Accept( visitor );
  
  if ( is_dst && has_variable ) {
    ValueNode* node = mayBeDsta->Node()->CastToValue();
    node->ValueType( ValueNode::kVariable );
    exp->ReplaceChild( exp->FirstChild() , node );
    node->RemoveAllChild();
    node->AddChild( ManagedHandle::Retain<Empty>() );
  } else {
    is_dst = ast_node->HasDsta();
  }
  
  AstNode* dsta_stmt = 0;
  if ( is_dst && has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , info );
    dsta_stmt = AstUtils::CreateVarStmt( list );
  } else if ( is_dst && !has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
    dsta_stmt = AstUtils::CreateExpStmt( list );
  }
  
  target_exp->Accept( visitor );
  ast_node->FirstChild()->Accept( visitor );
  
  AstNode* body = ast_node->FirstChild();
  if ( is_dst && body->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    StatementList* list = ManagedHandle::Retain<StatementList>();
    list->AddChild( dsta_stmt );
    list->AddChild( body );
    BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
    block->AddChild( list );
    ast_node->AddChild( block );
  } else if ( is_dst ) {
    body->FirstChild()->InsertBefore( dsta_stmt );
  }
  if ( ast_node->GetYieldFlag() && is_regist ) {
    info->GetInfo()->GetFunction()->SetStmtWithYield( ast_node );
  }
}


void IterationProcessor::ProcessForOfNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , maybeBlock );
    ast_node->AddChild( stmt );
  }
  ProcessForInNode( ast_node , info , false );
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();
  IterationStmt* while_stmt = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
  ValueNode* maybeIdent = target_exp->CastToValue();
  if ( ast_node->NodeType() == AstNode::kForOfWithVar ) {
    AstNode* val = index_exp->Clone();
    ValueNode* maybe_value = index_exp->CastToValue();
    if ( maybe_value ) {
      maybe_value->ValueType( ValueNode::kVariable );
      maybe_value->RemoveAllChild();
      maybe_value->AddChild( ManagedHandle::Retain<Empty>() );
      VariableStmt* stmt = AstUtils::CreateVarStmt( index_exp );
      ast_node->ParentNode()->InsertBefore( stmt , ast_node );
    }
    if ( val->CastToValue() ) {
      val->CastToValue()->ValueType( ValueNode::kIdentifier );
    }
    index_exp = val;
  }
  if ( !maybeIdent ) {
    ValueNode* tmp = AstUtils::CreateTmpNode( info->GetInfo()->GetTmpIndex() );
    ValueNode* init = AstUtils::CreateVarInitiliser( tmp->Symbol() , target_exp );
    VariableStmt* stmt = AstUtils::CreateVarStmt( init );
    ValueNode* target = tmp->Clone()->CastToValue();

    ValueNode* has_iterator = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kHasIterator ),
                                                        Token::JS_PROPERTY , 0 , ValueNode::kProperty );
    ValueNode* get_iterator = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGetIterator ),
                                                        Token::JS_PROPERTY , 0 , ValueNode::kProperty );
    CallExp* runtime_key = AstUtils::CreateRuntimeMod( has_iterator );
    CallExp* runtime_key2 = AstUtils::CreateRuntimeMod( get_iterator );
    NodeList* args = AstUtils::CreateNodeList( 1 , tmp->Clone() );
    CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_key , args );
    CallExp* get_iterator_call = AstUtils::CreateNormalAccessor( runtime_key2 , args->Clone() );
    ConditionalExp* cond_exp = ManagedHandle::Retain( new ConditionalExp( runtime_call , get_iterator_call , tmp->Clone() ) );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , target->Clone() , cond_exp );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
    ast_node->ParentNode()->InsertBefore( stmt , ast_node );
    ast_node->ParentNode()->InsertBefore( exp_stmt , ast_node );
    exp->ReplaceChild( target_exp , target );
    target_exp = target;
  }
  ValueNode* next = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kNoThrow ),
                                              Token::JS_PROPERTY , ast_node->Line() , ValueNode::kProperty );
  CallExp* next_call = AstUtils::CreateNormalAccessor( next , ManagedHandle::Retain<NodeList>() );
  CallExp* dot_call = AstUtils::CreateDotAccessor( target_exp , next_call );
  CallExp* dot_exp = AstUtils::CreateDotAccessor( target_exp , next->Clone() );
  AssignmentExp* assign = AstUtils::CreateAssignment( '=' , index_exp , dot_call );
  Expression* expression = ManagedHandle::Retain<Expression>();
  expression->AddChild( assign );
  expression->Paren();
  while_stmt->Exp( expression );

  while_stmt->AddChild( ast_node->FirstChild() );
  ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kExceptionHandler ),
                                                 Token::JS_PROPERTY , 0 , ValueNode::kProperty );
  CallExp* runtime_call = AstUtils::CreateRuntimeMod( handler );
  char line_tmp[50];
  sprintf( line_tmp , "%ld" , ast_node->Line() );
  ValueNode* line_num = AstUtils::CreateNameNode( line_tmp , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
  ValueNode* file_name = AstUtils::CreateNameNode( info->GetInfo()->GetRelativePath() , Token::JS_STRING_LITERAL , 0 , ValueNode::kString );
  ValueNode* error = AstUtils::CreateNameNode( "'for of statement expect iterator or generator object.'",
                                               Token::JS_STRING_LITERAL , 0 , ValueNode::kString );
  NodeList* args = AstUtils::CreateNodeList( 3 , line_num , file_name , error );
  CallExp* handler_call = AstUtils::CreateNormalAccessor( runtime_call , args );
  ExpressionStmt* handler_stmt = AstUtils::CreateExpStmt( handler_call );
  BlockStmt* then_block = AstUtils::CreateBlockStmt( 1 , while_stmt );
  BlockStmt* else_block = AstUtils::CreateBlockStmt( 1 , handler_stmt );
  IFStmt* if_stmt = AstUtils::CreateIFStmt( dot_exp , then_block , else_block );
  ast_node->ParentNode()->ReplaceChild( ast_node , if_stmt );

  if ( ast_node->GetYieldFlag() ) {
    info->GetInfo()->GetFunction()->SetStmtWithYield( while_stmt );
    info->GetInfo()->GetFunction()->SetStmtWithYield( if_stmt );
  }
}


void IterationProcessor::ProcessForEachNode( IterationStmt *ast_node , ProcessorInfo *info ) {
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , maybeBlock );
    ast_node->AddChild( stmt );
  }
  IVisitor* visitor = info->GetVisitor();
  bool has_variable = ast_node->NodeType() == AstNode::kForEachWithVar;
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* target_exp = index_exp->NextSibling();
  ValueNode* mayBeDsta = index_exp->CastToValue();
  bool is_dst = false;
  
  if ( mayBeDsta && mayBeDsta->ValueType() == ValueNode::kDst ) {
    is_dst = true;
    if ( ast_node->NodeType() == AstNode::kForEachWithVar ) {
      index_exp = index_exp->CastToValue()->Node()->CastToValue();
    }
  }
  index_exp->Accept( visitor );
  
  if ( is_dst && has_variable ) {
    index_exp->CastToValue()->ValueType( ValueNode::kVariable );
    exp->ReplaceChild( exp->FirstChild() , index_exp );
    index_exp->AddChild( ManagedHandle::Retain<Empty>() );
  } else {
    is_dst = ast_node->HasDsta();
  }
  
  AstNode* dsta_stmt = 0;
  if ( is_dst && has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , info );
    dsta_stmt = AstUtils::CreateVarStmt( list );
  } else if ( is_dst && !has_variable ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
    dsta_stmt = AstUtils::CreateExpStmt( list );
  }
  
  target_exp->Accept( visitor );
  ast_node->FirstChild()->Accept( visitor );
  ExpressionStmt* stmt;
  if ( has_variable ) {
    ValueNode *value = index_exp->Clone()->CastToValue();
    value->ValueType( ValueNode::kIdentifier );
    CallExp* call = AstUtils::CreateArrayAccessor( target_exp->Clone() , value );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , value->Clone() , call );
    stmt = AstUtils::CreateExpStmt( exp );
  } else {
    CallExp* call = AstUtils::CreateArrayAccessor( target_exp->Clone() , index_exp->Clone() );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , index_exp->Clone() , call );
    stmt = AstUtils::CreateExpStmt( exp );
  }
  AstNode* body = ast_node->FirstChild();
  if ( body->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    StatementList* list = ManagedHandle::Retain<StatementList>();
    list->AddChild( stmt );
    if ( is_dst ) {
      list->AddChild( dsta_stmt );
    }
    list->AddChild( body );
    BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
    block->AddChild( list );
    ast_node->AddChild( block );
  } else {
    if ( is_dst ) {
      body->FirstChild()->InsertBefore( dsta_stmt );
    }
    body->FirstChild()->InsertBefore( stmt );
  }
  if ( ast_node->GetYieldFlag() ) {
    info->GetInfo()->GetFunction()->SetStmtWithYield( ast_node );
  }
}

void IterationProcessor::ProcessWhileNode( IterationStmt *ast_node , ProcessorInfo *info ) {
  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() != AstNode::kBlockStmt ) {
    ast_node->RemoveAllChild();
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , maybeBlock );
    ast_node->AddChild( stmt );
  }
  IVisitor* visitor = info->GetVisitor();
  bool is_dst = false;
  NodeList* dsta_list = 0;
  VariableStmt* var_stmt = 0;
  ast_node->Exp()->Accept( visitor );
  if ( ( is_dst = ast_node->HasDsta() ) ) {
    if ( ast_node->NodeType() == AstNode::kDoWhile ) {
      var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , info );
    } else {
      var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , info );
    }
    dsta_list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , info );
  }
  AstNode* body = ast_node->FirstChild();
  body->Accept( visitor );

  if ( is_dst ) {
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( dsta_list );
    exp->Paren();
    ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( exp );
    if ( body->NodeType() == AstNode::kBlockStmt ) {
      body->FirstChild()->InsertBefore( stmt );
    } else {
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      block->AddChild( stmt );
      body->ParentNode()->ReplaceChild( body , block );
      block->AddChild( body );
    }
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
  }
  if ( ast_node->GetYieldFlag() ) {
    info->GetInfo()->GetFunction()->SetStmtWithYield( ast_node );
  }
}

}

