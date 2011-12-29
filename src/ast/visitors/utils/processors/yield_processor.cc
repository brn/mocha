#include <vector>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/ivisitor.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/yield_processor.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <utils/pool/managed_handle.h>

namespace mocha {

YieldProcessor::YieldProcessor( YieldExp* exp , ProcessorInfo* info ) :
    exp_( exp ) , info_( info ) {}

YieldProcessor::~YieldProcessor(){}

void YieldProcessor::ProcessNode() {
  typedef std::vector<AstNode*> YieldParentIter;
  AstNode *exp = exp_->ParentNode();
  exp_->FirstChild()->Accept( info_->GetVisitor() );
  if ( exp && exp->ParentNode()->NodeType() == AstNode::kExpressionStmt ) {
    ReturnStmt* ret = AstUtils::CreateReturnStmt( exp_->FirstChild()->Clone() );
    exp->ParentNode()->ParentNode()->ReplaceChild( exp->ParentNode() , ret );
    exp_ = ret->FirstChild();
  } else {
    AstNode* tmp = exp_->FirstChild()->Clone();
    exp_->ParentNode()->ReplaceChild( exp_ , tmp );
    exp_ = tmp;
  }
  VisitorInfo* visitor_info = info_->GetInfo();
  AstNode* direct_child = exp_->ParentNode();
  YieldParentIter list;
  while ( 1 ) {
    if ( direct_child->ParentNode()->NodeType() == AstNode::kFunction ) {
      break;
    }
    direct_child = direct_child->ParentNode();
    if ( direct_child->NodeType() == AstNode::kFor ||
         direct_child->NodeType() == AstNode::kForWithVar ||
         direct_child->NodeType() == AstNode::kForIn ||
         direct_child->NodeType() == AstNode::kForInWithVar ) {
      list.push_back( direct_child );
    }
  }
  Function* fn = visitor_info->GetFunction();
  if ( !fn->GetYieldFlag() ) {
    fn->SetYieldFlag();
    YieldParentIter::iterator begin = list.begin() , end = list.end();
    while ( begin != end ) {
      IterationStmt* stmt = reinterpret_cast<IterationStmt*>( (*begin) );
      if ( stmt->NodeType() == AstNode::kForWithVar ) {
        fn->InsertBefore( stmt->Exp()->FirstChild()->Clone() , direct_child );
      }
    }
  }
  direct_child->CastToStatement()->SetYieldFlag();
}

}
