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
  AstNode *exp = exp_->ParentNode();
  exp_->FirstChild()->Accept( info_->GetVisitor() );
  bool is_need_mark = true;
  if ( exp && exp->ParentNode()->NodeType() == AstNode::kExpressionStmt ) {
    ReturnStmt* ret = AstUtils::CreateReturnStmt( exp_->FirstChild()->Clone() );
    ret->SetYieldFlag();
    ret->Line( exp->ParentNode()->Line() );
    exp->ParentNode()->ParentNode()->ReplaceChild( exp->ParentNode() , ret );
    exp_ = ret->FirstChild();
  } else {
    ProcessSend_( exp );
    is_need_mark = false;
  }
  VisitorInfo* visitor_info = info_->GetInfo();
  AstNode* direct_child = exp_->ParentNode();
  Function* fn = visitor_info->GetFunction();
  fprintf( stderr , "%s %s\n" , exp_->GetName() , direct_child->ParentNode()->GetName() );
  while ( 1 ) {
    if ( direct_child->ParentNode()->NodeType() == AstNode::kFunction ) {
      break;
    }
    direct_child = direct_child->ParentNode();
    if ( direct_child->NodeType() == AstNode::kFor ||
         direct_child->NodeType() == AstNode::kForWithVar ||
         direct_child->NodeType() == AstNode::kForIn ||
         direct_child->NodeType() == AstNode::kForInWithVar ||
         direct_child->NodeType() == AstNode::kForEachWithVar ||
         direct_child->NodeType() == AstNode::kForEach ||
         direct_child->NodeType() == AstNode::kWhile ||
         direct_child->NodeType() == AstNode::kDoWhile ||
         direct_child->NodeType() == AstNode::kTryStmt ||
         direct_child->NodeType() == AstNode::kIFStmt ||
         direct_child->NodeType() == AstNode::kSwitchStmt ) {
      Statement* stmt = direct_child->CastToStatement();
      stmt->SetYieldFlag();
    }
  }
  
  if ( !fn->GetYieldFlag() ) {
    fn->SetYieldFlag();
  }
  if ( is_need_mark ) {
    direct_child->CastToStatement()->SetYieldFlag();
  }
}

void YieldProcessor::ProcessSend_( AstNode* exp ) {
  ReturnStmt* ret = AstUtils::CreateReturnStmt( exp_->FirstChild()->Clone() );
  ret->SetYieldFlag();
  while ( !exp->CastToStatement() ) {
    exp = exp->ParentNode();
  }
  ret->SetYieldFlag();
  ret->Line( exp->Line() );
  exp->ParentNode()->InsertBefore( ret , exp );
  AstNode* tmp = exp_->FirstChild()->Clone();
  ValueNode* is_send = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSendFlag ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
  ValueNode* to_array = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kToArray ),
                                                  Token::JS_PROPERTY , 0 , ValueNode::kProperty );
  ValueNode* arguments = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kArguments ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
  ValueNode* length = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLength ),
                                                Token::JS_IDENTIFIER , 0 , ValueNode::kProperty );
  CallExp* dot = AstUtils::CreateDotAccessor( arguments , length );
  ValueNode* two = AstUtils::CreateNameNode( "2" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
  CompareExp* length_comp = ManagedHandle::Retain( new CompareExp( '>' , dot , two ) );
  CompareExp* comp = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , is_send , length_comp ) );
  ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
  AstNode* no_arg;
  if ( !tmp->IsEmpty() ) {
    no_arg = ManagedHandle::Retain( new ConditionalExp( is_send->Clone() , tmp , undefined ) );
  } else {
    no_arg = undefined;
  }
  NodeList* args = ManagedHandle::Retain<NodeList>();
  args->AddChild( arguments->Clone() );
  args->AddChild( two->Clone() );
  ValueNode* zero = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
  CallExp* normal = AstUtils::CreateNormalAccessor( to_array , args );
  CallExp* runtime_call = AstUtils::CreateRuntimeMod( normal );
  CallExp* array_accessor = AstUtils::CreateArrayAccessor( runtime_call , zero );
  ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( comp , array_accessor , no_arg ) );
  ValueNode* tmp_ret = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldResult ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
  UnaryExp* unary = ManagedHandle::Retain( new UnaryExp( '!' ) );
  unary->Exp( tmp_ret->Clone() );
  CompareExp* comp2 = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , unary , comp->Clone() ) );
  AstNode* no_arg2 = ManagedHandle::Retain( new ConditionalExp( is_send->Clone() , tmp_ret->Clone() , undefined ) );
  ConditionalExp* cond2 = ManagedHandle::Retain( new ConditionalExp( comp2 , array_accessor , no_arg2 ) );
  AssignmentExp* assign2 = AstUtils::CreateAssignment( '=' , tmp_ret->Clone() , cond2 );
  AssignmentExp* assign = AstUtils::CreateAssignment( '=' , tmp_ret , cond );
  
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
  ExpressionStmt* stmt2 = AstUtils::CreateExpStmt( assign2 );
  //ret->ParentNode()->InsertBefore( stmt , ret );
  ret->ParentNode()->InsertAfter( stmt , ret );
  AstNode* send_val = tmp_ret->Clone();
  exp_->ParentNode()->ReplaceChild( exp_ , send_val );
  exp_ = send_val;
}

}
