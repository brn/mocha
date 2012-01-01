#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/iteration_processor.h>
#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <compiler/scopes/scope.h>
#include <ast/visitors/utils/processors/processor_info.h>

namespace mocha {

void IterationProcessor::ProcessForNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->GetVisitor();
  AstNode* exp = ast_node->Exp();
  AstNode* index_exp = exp->FirstChild();
  AstNode* cond_exp = ( index_exp )? index_exp->NextSibling() : 0;
  AstNode* incr_exp = ( cond_exp )? cond_exp->NextSibling() : 0;

  if ( ast_node->NodeType() == AstNode::kForWithVar ) {
    VariableProcessor::ProcessVarList( ast_node , info );
  } else {
    index_exp->Accept( visitor );
  }
  
  if ( cond_exp ) {
    cond_exp->Accept( visitor );
  }
  
  if ( incr_exp ) {
    incr_exp->Accept( visitor );
  }
  

  AstNode* maybeBlock = ast_node->FirstChild();
  if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
    ast_node->FirstChild()->Accept( visitor );
  } else {
    ast_node->FirstChild()->Accept( visitor );
  }
}

void IterationProcessor::ProcessForInNode( IterationStmt* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->GetVisitor();
  bool has_variable = ast_node->NodeType() == AstNode::kForInWithVar;
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
    body->InsertBefore( dsta_stmt );
  }
}

void IterationProcessor::ProcessForEachNode( IterationStmt *ast_node , ProcessorInfo *info ) {
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
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , index_exp->Clone() , call );
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
      body->InsertBefore( dsta_stmt );
    }
    body->InsertBefore( stmt );
  }
}

void IterationProcessor::ProcessWhileNode( IterationStmt *ast_node , ProcessorInfo *info ) {
  IVisitor* visitor = info->GetVisitor();
  bool is_dst = false;
  NodeList* dsta_list = 0;
  VariableStmt* var_stmt = 0;
  ast_node->Exp()->Accept( visitor );
  if ( ( is_dst = ast_node->HasDsta() ) ) {
    var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , info );
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
      body->InsertBefore( stmt );
    } else {
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      block->AddChild( stmt );
      body->ParentNode()->ReplaceChild( body , block );
      block->AddChild( body );
    }
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
  }
}

}

