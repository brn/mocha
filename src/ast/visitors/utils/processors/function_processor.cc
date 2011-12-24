#include <ast/visitors/utils/processors/function_processor.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/symbol_list.h>
#include <grammar/grammar.tab.hh>

#define TOKEN yy::ParserImplementation::token

namespace mocha {

FunctionProcessor::FunctionProcessor( Function* function , ProcessorInfo* info ) :
    function_( function ) , info_( info ) , stmt_( ManagedHandle::Retain<Statement>() ),
    formal_parameter_( function->Argv() ) , default_parameter_( ManagedHandle::Retain<NodeList>() ) {
  argc_ = formal_parameter_->ChildLength();
  info_->GetInfo()->SetCurrentStmt( stmt_ );
}

FunctionProcessor::~FunctionProcessor() {}

void FunctionProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->GetInfo();
  ProcessFormalParameter_();
  bool is_rest = visitor_info->IsRestInjection();
  visitor_info->SetRestInjection( false );
  
  VariableStmt* dsta_stmt = 0;
  VariableStmt* rest_stmt = 0;
  
  if ( stmt_->HasDsta() ) {
    NodeList *list = DstaProcessor::CreateDstaExtractedVarStmt( stmt_ , info_ );
    dsta_stmt = AstUtils::CreateVarStmt( list );
  }
  
  if ( is_rest ) {
    rest_stmt = ProcessRestParameter_();
  }

  ProcessBody_();
  
  if ( dsta_stmt && rest_stmt ) {
    dsta_stmt->AddChild( rest_stmt->FirstChild() );
    function_->InsertBefore( dsta_stmt );
  } else if ( dsta_stmt ) {
    function_->InsertBefore( dsta_stmt );
  } else if ( rest_stmt ) {
    function_->InsertBefore( rest_stmt );
  }

  if ( default_parameter_->ChildLength() > 0 ) {
    NodeIterator iterator = default_parameter_->ChildNodes();
    while ( iterator.HasNext() ) {
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( iterator.Next() );
      function_->InsertBefore( stmt );
    }
  }
}


void FunctionProcessor::ProcessFormalParameter_() {
  if ( !formal_parameter_->IsEmpty() && argc_ > 0 ) {
    IVisitor* visitor = info_->GetVisitor();
    NodeIterator iterator = formal_parameter_->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* node = iterator.Next();
      ValueNode* maybeInitialiser = node->CastToValue();
      if ( node->ChildLength() > 0 && !node->FirstChild()->IsEmpty() && maybeInitialiser &&
           maybeInitialiser->ValueType() == ValueNode::kIdentifier ) {
        ProcessDefaultParameter_( maybeInitialiser );
      } else if ( maybeInitialiser && maybeInitialiser->ValueType() == ValueNode::kDst ) {
        bool has_default_parameter = node->ChildLength() > 0 && !node->FirstChild()->IsEmpty();
        AstNode* dsta_node = maybeInitialiser->Node();
        dsta_node->Accept( visitor );
        if ( has_default_parameter ) {
          AstNode* arg = dsta_node->Clone();
          arg->RemoveAllChild();
          arg->AddChild( node->FirstChild() );
          ProcessDefaultParameter_( arg->CastToValue() );
        }
        node->ParentNode()->ReplaceChild( node , dsta_node );
      } else {
        node->Accept( visitor );
      }
    }
  }
}



void FunctionProcessor::ProcessDefaultParameter_( ValueNode *value ) {
  ValueNode* initialiser = value->Clone()->CastToValue();
  ValueNode* arg = initialiser->Clone()->CastToValue();
  AstNode* default_value = initialiser->FirstChild();
  arg->RemoveAllChild();
  initialiser->RemoveAllChild();
  CompareExp* logical_or = ManagedHandle::Retain( new CompareExp( TOKEN::JS_LOGICAL_OR , arg , default_value ) );
  AssignmentExp* exp = AstUtils::CreateAssignment( '=', initialiser , logical_or );
  default_parameter_->InsertBefore( exp );
}



void FunctionProcessor::ProcessBody_() {
  IVisitor *visitor = info_->GetVisitor();
  if ( function_->FunctionType() == Function::kShorten ) {
    Statement* stmt_tmp = ManagedHandle::Retain<Statement>();
    info_->GetInfo()->SetCurrentStmt( stmt_tmp );
    function_->FirstChild()->Accept( visitor );
    ReturnStmt* ret_stmt = AstUtils::CreateReturnStmt( function_->FirstChild()->Clone() );
    function_->RemoveAllChild();
    if ( stmt_tmp->HasDsta() ) {
      NodeList* list = ManagedHandle::Retain<NodeList>();
      list->AddChild( DstaProcessor::CreateTmpVarDecl( stmt_tmp , info_ ) );
      list->AddChild( ret_stmt );
      function_->Append( list );
    }
    function_->AddChild( ret_stmt );
  } else {
    NodeIterator iterator = function_->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( visitor );
    }
  }
}

VariableStmt* FunctionProcessor::ProcessRestParameter_() {
  ValueNode* rhs = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kArguments ),
                                             TOKEN::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  char num[50];
  sprintf( num , "%d" , argc_ - 1 );
  ValueNode* arg = AstUtils::CreateNameNode( num , TOKEN::JS_NUMERIC_LITERAL , function_->Line() , ValueNode::kNumeric );
  ValueNode* to_array = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kToArray ),
                                                  TOKEN::JS_IDENTIFIER , function_->Line() , ValueNode::kProperty );
  list->AddChild( rhs );
  list->AddChild( arg );
  CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list );
  CallExp* std_to_array = AstUtils::CreateRuntimeMod( nrm );
  ValueNode* var_node = AstUtils::CreateVarInitiliser( info_->GetInfo()->GetRestExp() , std_to_array );
  NodeList* var_list = ManagedHandle::Retain<NodeList>();
  var_list->AddChild( var_node );
  return AstUtils::CreateVarStmt( var_list );
}

}
