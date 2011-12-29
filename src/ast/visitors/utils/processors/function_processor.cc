#include <ast/visitors/utils/processors/function_processor.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/token_info.h>
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
  visitor_info->SetFunction( function_ );
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

  if ( function_->GetYieldFlag() ) {
    ProcessYield_();
  }
  
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
  CompareExp* logical_or = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_OR , arg , default_value ) );
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
    ret_stmt->Line( function_->FirstChild()->Line() );
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
                                             Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  char num[50];
  sprintf( num , "%d" , argc_ - 1 );
  ValueNode* arg = AstUtils::CreateNameNode( num , Token::JS_NUMERIC_LITERAL , function_->Line() , ValueNode::kNumeric );
  ValueNode* to_array = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kToArray ),
                                                  Token::JS_IDENTIFIER , function_->Line() , ValueNode::kProperty );
  list->AddChild( rhs );
  list->AddChild( arg );
  CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list );
  CallExp* std_to_array = AstUtils::CreateRuntimeMod( nrm );
  ValueNode* var_node = AstUtils::CreateVarInitiliser( info_->GetInfo()->GetRestExp() , std_to_array );
  NodeList* var_list = ManagedHandle::Retain<NodeList>();
  var_list->AddChild( var_node );
  return AstUtils::CreateVarStmt( var_list );
}


class YieldHelper {
 public :
  YieldHelper( Function* function , ProcessorInfo* info ) :
      state_( 0 ), function_( function ) , info_( info ),
      clause_( CreateCaseClause_( state_ ) ),
      clause_body_( clause_->FirstChild() ),
      body_( ManagedHandle::Retain<NodeList>() ){
    iterator_ = function_->ChildNodes();
  }

  void ProcessYield() {
    while ( iterator_.HasNext() ) {
      AstNode* yield_stmt = iterator_.Next();
      if ( yield_stmt->NodeType() == AstNode::kVariableStmt ) {
        ProcessVarStmtInYield_( yield_stmt );
      } else {
        ProcessStmtInYield_( yield_stmt );
      }
    }
    body_->AddChild( clause_ );
    Finish_();
  }

  NodeList* GetBody() {
    return body_;
  }
  
 private :
  void Finish_() {
    ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kExceptionHandler ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    CallExp* exp = AstUtils::CreateNormalAccessor( handler , list );
    CallExp* runtime = AstUtils::CreateRuntimeMod( exp );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime );
    CreateCaseClause_( 0 , true );
    clause_body_->AddChild( stmt );
    body_->AddChild( clause_ );
  }
  
  CaseClause* CreateCaseClause_( long line , bool is_error = false ) {
    clause_ = ManagedHandle::Retain<CaseClause>();
    clause_body_ = ManagedHandle::Retain<StatementList>();
    clause_->AddChild( clause_body_ );
    clause_->Line( function_->Line() );
    if ( !is_error ) {
      ValueNode* state = CreateCurrentState_( line );
      clause_->Exp( state );
    } else {
      ValueNode* error = AstUtils::CreateNameNode( "-1" , Token::JS_IDENTIFIER , 0 , ValueNode::kNumeric );
      clause_->Exp( error );
    }
    return clause_;
  }

  ValueNode* CreateCurrentState_( long line ) {
    char tmp_state_exp[10];
    sprintf( tmp_state_exp , "%d" , state_ );
    ValueNode* state_exp = AstUtils::CreateNameNode( tmp_state_exp , Token::JS_NUMERIC_LITERAL,
                                                     line , ValueNode::kNumeric );
    return state_exp;
  }

  ExpressionStmt* CreateNextState_( long line ) {
    ValueNode* yield_state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                       Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    char tmp_state_str[10];
    sprintf( tmp_state_str , "%d" , state_ + 1 );
    ValueNode* state = AstUtils::CreateNameNode( tmp_state_str , Token::JS_NUMERIC_LITERAL,
                                                 line , ValueNode::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , yield_state->Clone() , state );
    return AstUtils::CreateExpStmt( exp );
  }

  void ProcessVarStmtInYield_( AstNode* yield_stmt ) {
    bool is_end = yield_stmt->CastToStatement()->GetYieldFlag();
    NodeIterator iter = yield_stmt->ChildNodes();
    while ( iter.HasNext() ) {
      ValueNode* orig = iter.Next()->CastToValue();
      ValueNode* val = orig->Clone()->CastToValue();
      orig->RemoveAllChild();
      orig->AddChild( ManagedHandle::Retain<Empty>() );
      AstNode* child = val->FirstChild();
      val->RemoveAllChild();
      val->ValueType( ValueNode::kIdentifier );
      val->AddChild( ManagedHandle::Retain<Empty>() );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , val , child );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
      clause_body_->AddChild( stmt );
    }
    if ( is_end ) {
      body_->AddChild( clause_ );
      if ( !iterator_.HasNext() ) {
        state_ = -2;
        clause_body_->InsertBefore( CreateNextState_( 0 ) );
      } else {
        clause_body_->InsertBefore( CreateNextState_( 0 ) );
        state_++;
      }
      if ( iterator_.HasNext() ) {
        CreateCaseClause_( function_->Line() );
      }
    }
  }

  void ProcessStmtInYield_( AstNode* yield_stmt ) {
    function_->RemoveChild( yield_stmt );
    if ( yield_stmt->CastToStatement()->GetYieldFlag() ) {
      if ( !iterator_.HasNext() ) {
        state_ = -2;
        clause_body_->InsertBefore( CreateNextState_( 0 ) );
      } else {
        clause_body_->InsertBefore( CreateNextState_( 0 ) );
        state_++;
      }
      clause_body_->AddChild( yield_stmt );
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause_( function_->Line() );
      }
    } else {
      clause_body_->AddChild( yield_stmt );
    }
  }
  
  int state_;
  Function* function_;
  ProcessorInfo* info_;
  CaseClause* clause_;
  AstNode* clause_body_;
  NodeList* body_;
  NodeIterator iterator_;
};


class GeneratorHelper {
 public :
  GeneratorHelper( Function* function , NodeList* body , ProcessorInfo* info ) :
      function_( function ) , body_( body ) , switch_stmt_( ManagedHandle::Retain<SwitchStmt>() ),
      info_( info ) {}
  
  void ProcessGenerator() {
    ValueNode* yield_state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                       Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    switch_stmt_->Line( function_->Line() );
    switch_stmt_->Exp( yield_state );
    switch_stmt_->AddChild( body_ );
    ProcessReturn_();
    CreateStateInitialiser_();
  }
 private :
  void CreateStateInitialiser_() {
    TokenInfo* state = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                             Token::JS_IDENTIFIER , function_->Line() ) );
    ValueNode* begin_state = AstUtils::CreateNameNode( "0" ,Token::JS_NUMERIC_LITERAL,
                                                       function_->Line() , ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( state , begin_state );
    VariableStmt* stmt = AstUtils::CreateVarStmt( value );
    function_->InsertBefore( stmt );
  }
  
  void ProcessReturn_() {
    Function* fn = ManagedHandle::Retain<Function>();
    fn->Name( ManagedHandle::Retain<Empty>() );
    fn->Argv( ManagedHandle::Retain<Empty>() );
    fn->AddChild( switch_stmt_ );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    TokenInfo* next = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kYieldNext ),
                                                            Token::JS_IDENTIFIER , function_->Line() ) );
    val->Symbol( next );
    val->Line( function_->Line() );
    val->AddChild( fn );
    list->AddChild( val );
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    value->Node( list );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( value );
    function_->AddChild( ret );
  }
  
  Function* function_;
  NodeList* body_;
  SwitchStmt *switch_stmt_;
  ProcessorInfo* info_;
  
};


void FunctionProcessor::ProcessYield_() {
  YieldHelper helper( function_ , info_ );
  helper.ProcessYield();
  NodeList* body = helper.GetBody();
  GeneratorHelper ge_helper( function_ , body , info_ );
  ge_helper.ProcessGenerator();
}

}
