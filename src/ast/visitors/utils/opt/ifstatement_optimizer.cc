#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <utils/int_types.h>
#include <ast/visitors/utils/opt/ifstatement_optimizer.h>
#include <ast/utils/ast_utils.h>
#include <ast/ast.h>
#include <ast/visitors/optimizer_visitor.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/utils/compile_info.h>
#include <utils/pool/managed_handle.h>

namespace mocha {

bool IsOptimizableBlock( AstNode* block ) {
  if ( block->NodeType() == AstNode::kBlockStmt ) {
    if ( block->FirstChild()->ChildLength() == 1 ) {
      return true;
    }
  }
  return false;
}

AstNode* GetReturnValue( AstNode* node ) {
  if ( node->IsEmpty() ) {
    return AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                     Token::JS_IDENTIFIER , node->Line() , ValueNode::kIdentifier );
  }
  return node;
}


bool CheckAssoc( AstNode* node ) {
  if ( node->NodeType() == AstNode::kValueNode ) {
    ValueNode* value = node->CastToValue();
    if ( value->ValueType() == ValueNode::kObject ) {
      return true;
    }
  } else if ( node->NodeType() == AstNode::kAssignmentExp ) {
    return true;
  } else if ( node->NodeType() == AstNode::kCompareExp ) {
    CompareExp* comp = node->CastToExpression()->CastToCompareExp();
    if ( comp->Op() == Token::JS_LOGICAL_OR ) {
      return true;
    }
  } else if ( node->NodeType() == AstNode::kExpression ) {
    if ( node->ChildLength() > 1 ) {
      return true;
    }
  }
  return false;
}

AstNode* ToExpression( AstNode* node ) {
  if ( CheckAssoc( node ) ) {
    if ( node->NodeType() == AstNode::kExpression ) {
      node->CastToExpression()->Paren();
      return node;
    } else {
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->AddChild( node );
      exp->Paren();
      return exp;
    }
  }
  return node;
}

IFStmtOptimizer::IFStmtOptimizer( CompileInfo* info , IFStmt* stmt ) :
    info_( info ) , stmt_( stmt ){}


void IFStmtOptimizer::Optimize( IVisitor* visitor ) {
  stmt_->Exp()->Accept( visitor );
  stmt_->Then()->Accept( visitor );
  stmt_->Else()->Accept( visitor );
  DetermineOptimizeType_();
}


void IFStmtOptimizer::DetermineOptimizeType_() {
  AstNode* then_block = stmt_->Then();
  AstNode* else_block = stmt_->Else();
  OptimizeBlock_( then_block , kThen );
  OptimizeBlock_( else_block , kElse );
  ToIFStmtCompatibleExpression_();
}

int IFStmtOptimizer::IsConvertableToExpression_( AstNode* then_stmt , AstNode* else_stmt ) {
  if ( IsOptimizableBlock( then_stmt ) ) {
    return kNone;
  }
  if ( IsOptimizableBlock( else_stmt ) ) {
    return kNone;
  }
  if ( else_stmt->NodeType() != AstNode::kIFStmt ) {
    int then_type = then_stmt->NodeType();
    int else_type = else_stmt->NodeType();
    if ( then_type == AstNode::kReturnStmt &&
         else_type == AstNode::kReturnStmt ) {
      return kCondtionalReturn;
    } else if ( ( then_type == AstNode::kReturnStmt ||
                  then_type == AstNode::kBreakStmt ||
                  then_type == AstNode::kContinueStmt ||
                  then_type == AstNode::kThrowStmt ) &&
                else_type != AstNode::kEmpty ) {
      return kNoElse;
    } else if ( then_type == AstNode::kExpressionStmt &&
                else_type == AstNode::kEmpty ) {
      return kLogical;
    } else if ( then_type == AstNode::kExpressionStmt &&
                else_type == AstNode::kExpressionStmt ) {
      return kConditional;
    }
  }
  return kNone;
}

void IFStmtOptimizer::OptimizeBlock_( AstNode* block , int type ) {
  if ( IsOptimizableBlock( block ) ) {
    AstNode* insert = block->FirstChild()->FirstChild();
    if ( type == kThen ) {
      stmt_->Then( insert );
    } else {
      stmt_->Else( insert );
    }
  }
}

void IFStmtOptimizer::ToIFStmtCompatibleExpression_() {
  AstNode* then_block = stmt_->Then();
  AstNode* else_block = stmt_->Else();
  int type = IsConvertableToExpression_( then_block , else_block );
  switch ( type ) {
    case kCondtionalReturn :
      ToConditionalReturn_( then_block , else_block );
      break;

    case kLogical :
      ToLogical_( then_block );
      break;

    case kNoElse :
      ToNoElse_( then_block , else_block );
      break;

    case kConditional :
      ToConditional_( then_block , else_block );
      break;
  }
}

void IFStmtOptimizer::ToConditionalReturn_( AstNode* then_stmt , AstNode* else_stmt ) {
  AstNode* then_return = GetReturnValue( then_stmt->FirstChild() );
  AstNode* else_return = GetReturnValue( else_stmt->FirstChild() );
  ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( stmt_->Exp(),
                                                                    then_return,
                                                                    else_return ) );
  ReturnStmt* ret = ManagedHandle::Retain<ReturnStmt>();
  ret->AddChild( cond );
  stmt_->ParentNode()->ReplaceChild( stmt_ , ret );
}


void IFStmtOptimizer::ToLogical_( AstNode* then_stmt ) {
  AstNode* cond = ToExpression( stmt_->Exp() );
  AstNode* then_exp = ToExpression( then_stmt->FirstChild() );
  CompareExp* logical = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , cond , then_exp ) );
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( logical );
  stmt->Line( stmt_->Line() );
  stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
}

void IFStmtOptimizer::ToNoElse_( AstNode* then_stmt , AstNode* else_stmt ) {
  stmt_->Else( ManagedHandle::Retain<Empty>() );
  stmt_->ParentNode()->InsertAfter( else_stmt , stmt_ );
}

void IFStmtOptimizer::ToConditional_( AstNode* then_stmt , AstNode* else_stmt ) {
  ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( stmt_->Exp(),
                                                                    then_stmt->FirstChild(),
                                                                    else_stmt->FirstChild() ) );
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( cond );
  stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
}

}
