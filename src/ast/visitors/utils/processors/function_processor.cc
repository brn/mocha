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
      state_( 0 ), is_state_injection_( false ), function_( function ) , info_( info ),
      clause_( CreateCaseClause_( state_ ) ),
      clause_body_( clause_->FirstChild() ),
      body_( ManagedHandle::Retain<NodeList>() ){}

  void ProcessYield() {
    ProcessIteration_();
    Function::VariableList &list = function_->GetVariable();
    if ( list.size() > 0 ) {
      Function::VariableList::iterator begin = list.begin(),end = list.end();
      NodeList* node_list = ManagedHandle::Retain<NodeList>();
      while ( begin != end ) {
        ValueNode* value = (*begin);
        ValueNode* ident = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
        ident->Symbol( value->Symbol() );
        ident->AddChild( ManagedHandle::Retain<Empty>() );
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , ident , value->FirstChild()->Clone() );
        ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
        printf( "parent type = %d symbol = %s\n" , value->ParentNode()->ParentNode()->NodeType() , value->Symbol()->GetToken() );
        value->ParentNode()->ParentNode()->ReplaceChild( value->ParentNode() , stmt );
        ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
        var->Symbol( value->Symbol() );
        var->AddChild( ManagedHandle::Retain<Empty>() );
        node_list->AddChild( var );
        ++begin;
      }
      VariableStmt* stmt = AstUtils::CreateVarStmt( node_list );
      function_->InsertBefore( stmt );
    }
    iterator_ = function_->ChildNodes();
    while ( iterator_.HasNext() ) {
      AstNode* yield_stmt = iterator_.Next();
      if ( yield_stmt->NodeType() == AstNode::kVariableStmt ) {
        //ProcessVarStmtInYield_( yield_stmt );
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

  void ProcessIteration_() {
    typedef Function::IterationList::reverse_iterator Iterator;
    Iterator begin = function_->GetIteration().rbegin(),end = function_->GetIteration().rend();
    int count = 0;
    int size = function_->GetIteration().size();
    while ( begin != end ) {
      AstNode* iteration_stmt = (*begin);
      if ( iteration_stmt->NodeType() == AstNode::kFor ||
           iteration_stmt->NodeType() == AstNode::kForWithVar ) {
        ProcessFor_( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      }
      count++;
      ++begin;
    }
  }

  void ProcessFor_( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* exp = node->Exp();
    AstNode* cond = exp->FirstChild()->NextSibling();
    AstNode* counter = cond->NextSibling();
    AstNode* body = node->FirstChild();
    AstNode* current = 0;//init after.
    if ( node->NodeType() == AstNode::kForWithVar ) {
      if ( !exp->FirstChild()->IsEmpty() ) {
        VariableStmt* stmt = AstUtils::CreateVarStmt( exp->FirstChild()->CastToNodeList() );
        if ( count == ( size - 1 ) && cond->IsEmpty() ) {
          //stmt->SetYieldFlag();
        }
        parent->InsertBefore( stmt , mark );
      }
    }
    if ( !cond->IsEmpty() ) {
      YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
      ExYieldStateNode* ex_node = ProcessDynamicState_( cond );
      IFStmt* if_stmt = CreateEscapeState_( cond , ex_node );
      state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
      parent->InsertAfter( ex_node , mark );
      parent->InsertBefore( if_stmt , mark );
      parent->InsertBefore( state_mark , if_stmt );
      if_stmt->SetYieldFlag();
    }
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( counter );
    parent->InsertAfter( stmt , mark );
    if ( body->NodeType() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->FirstChild()->ChildNodes();
      while ( iterator.HasNext() ) {
        AstNode* item = iterator.Next();
        if ( !current ) {
          current = item;
          parent->InsertBefore( current , mark );
        } else {
          AstNode* tmp = item;
          parent->InsertAfter( tmp , current );
          current = tmp;
        }
      }
    }
    mark->ParentNode()->RemoveChild( mark );
  }


  IFStmt* CreateEscapeState_( AstNode* cond , ExYieldStateNode *ex_node ) {
    ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
    ValueNode* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
    
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt>();
    
    BlockStmt* if_block = ManagedHandle::Retain<BlockStmt>();
    StatementList* if_stmt_list = ManagedHandle::Retain<StatementList>();

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( cond );
    exp->Paren();
    UnaryExp *not_exp = ManagedHandle::Retain( new UnaryExp( '!' ) );
    not_exp->Exp( exp );
    break_stmt->Line( 0 );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    if_stmt_list->AddChild( exp_stmt );
    if_stmt_list->AddChild( break_stmt );
    if_block->AddChild( if_stmt_list );
    if_stmt->Line( function_->Line() );
    if_stmt->Exp( not_exp );
    if_stmt->Then( if_block );
    if_stmt->Else( ManagedHandle::Retain<Empty>() );
    ex_node->EscapePtr( dynamic_state );
    return if_stmt;
  }
  

  ExYieldStateNode* ProcessDynamicState_( AstNode* cond ) {
    ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
    ValueNode* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );

    ValueNode* next_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* next_assign = AstUtils::CreateAssignment( '=' , state->Clone() , next_state );
    ExpressionStmt* next_stmt = AstUtils::CreateExpStmt( next_assign );
    
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt>();
    
    BlockStmt* if_block = ManagedHandle::Retain<BlockStmt>();
    BlockStmt* else_block = ManagedHandle::Retain<BlockStmt>();
    StatementList* if_stmt_list = ManagedHandle::Retain<StatementList>();
    AstNode* clone_stmt_list = if_stmt_list->Clone();

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( 0 );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    if_stmt_list->AddChild( exp_stmt );
    if_stmt_list->AddChild( break_stmt );
    clone_stmt_list->AddChild( next_stmt );
    if_block->AddChild( if_stmt_list );
    else_block->AddChild( clone_stmt_list );
    
    if_stmt->Line( function_->Line() );
    if_stmt->Exp( cond );
    if_stmt->Then( if_block );
    if_stmt->Else( else_block );
    ExYieldStateNode* ex_node = ManagedHandle::Retain<ExYieldStateNode>();
    ex_node->LoopBackPtr( dynamic_state );
    ex_node->NextPtr( next_state );
    ex_node->IfStmtPtr( if_stmt );
    return ex_node;
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
    printf( "@@@@@@@@@@@@@@@@ %d \n" , is_end );
    if ( is_end ) {
      body_->AddChild( clause_ );
      if ( is_state_injection_ ) {
        if ( !iterator_.HasNext() ) {
          state_ = -2;
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
        } else {
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
          state_++;
        }
      } else {
        if ( !iterator_.HasNext() ) {
          state_ = -2;
        } else {
          state_++;
        }
      }
      is_state_injection_ = false;
      if ( iterator_.HasNext() ) {
        CreateCaseClause_( function_->Line() );
      }
    }
  }

  void ProcessStmtInYield_( AstNode* yield_stmt ) {
    function_->RemoveChild( yield_stmt );
    if ( yield_stmt->NodeType() == AstNode::kReturnStmt ) {
      is_state_injection_ = true;
    }
    if ( yield_stmt->NodeType() == AstNode::kYieldMark ) {
      YieldMark* mark = yield_stmt->CastToStatement()->CastToYieldMark();
      char state[10];
      sprintf( state , "%d" , ( state_ + 1 ) );
      mark->ReEntrantNode()->Symbol()->SetToken( state );
    } else if ( yield_stmt->NodeType() == AstNode::kExYieldStateNode ) {
      ExYieldStateNode* ex_node = yield_stmt->CastToStatement()->CastToYieldState();
      char back[10];
      sprintf( back ,"%d" , ( state_ - 1 ) );
      char next[10];
      int next_state;
      ValueNode* esc = ex_node->EscapePtr();
      
      if ( is_state_injection_ ) {
        if ( !iterator_.HasNext() ) {
          state_ = -2;
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
        } else {
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
          state_++;
        }
      } else {
        if ( !iterator_.HasNext() ) {
          state_ = -1;
        } else {
          state_++;
        }
      }
      sprintf( next ,"%d" , ( state_ ) );
      if ( esc ) {
        esc->Symbol()->SetToken( next );
      }
      ex_node->NextPtr()->Symbol()->SetToken( next );
      clause_body_->AddChild( ex_node->IfStmtPtr() );
      is_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause_( function_->Line() );
      }
    } else if ( yield_stmt->CastToStatement()->GetYieldFlag() ) {
      if ( is_state_injection_ ) {
        if ( !iterator_.HasNext() ) {
          state_ = -2;
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
        } else {
          clause_body_->InsertBefore( CreateNextState_( 0 ) );
          state_++;
        }
      } else {
        if ( !iterator_.HasNext() ) {
          state_ = -2;
        } else {
          state_++;
        }
      }
      clause_body_->AddChild( yield_stmt );
      is_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause_( function_->Line() );
      }
    } else {
      clause_body_->AddChild( yield_stmt );
    }
  }
  
  int state_;
  bool is_state_injection_;
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
    CreateResultInitialiser_();
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

  void CreateResultInitialiser_() {
    TokenInfo* result = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kYieldResult ),
                                                             Token::JS_IDENTIFIER , function_->Line() ) );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                     Token::JS_NUMERIC_LITERAL, function_->Line(),
                                                     ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( result , undefined );
    VariableStmt* stmt = AstUtils::CreateVarStmt( value );
    function_->InsertBefore( stmt );
  }
  
  void ProcessReturn_() {
    Function* fn = ManagedHandle::Retain<Function>();
    fn->Name( ManagedHandle::Retain<Empty>() );
    NodeList *generator_arg = ManagedHandle::Retain<NodeList>();
    ValueNode* is_send = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSendFlag ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    {
      ValueNode* one_exp = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
      StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
      stmt_list->AddChild( switch_stmt_ );
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      block->AddChild( stmt_list );
      IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->AddChild( one_exp );
      iter->Line( function_->Line() );
      iter->Exp( exp );
      iter->AddChild( block );
      generator_arg->AddChild( is_send );
      fn->Argv( generator_arg );
      fn->AddChild( iter );
    }
    ValueNode* generator = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGenerator ),
                                                     Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier , true );
    ValueNode* generator_init = AstUtils::CreateVarInitiliser( generator->Symbol() , fn );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( generator_init );
    function_->AddChild( var_stmt );
    NodeList* list = ManagedHandle::Retain<NodeList>();

    ValueNode* next = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldNext ),
                                                Token::JS_PROPERTY , function_->Line(),
                                                ValueNode::kProperty );
    ValueNode* bind_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kBind ),
                                                    Token::JS_PROPERTY , function_->Line(),
                                                    ValueNode::kProperty );
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , function_->Line(),
                                                    ValueNode::kIdentifier );
    ValueNode* true_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTrue ),
                                                    Token::JS_IDENTIFIER , function_->Line(),
                                                    ValueNode::kIdentifier );
    CallExp* dot = AstUtils::CreateDotAccessor( generator->Clone() , bind_sym );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    arg->AddChild( this_sym );
    arg->AddChild( true_sym );
    CallExp* normal = AstUtils::CreateNormalAccessor( dot , arg );

    
    ValueNode* send = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSend ),
                                                Token::JS_PROPERTY , function_->Line(),
                                                ValueNode::kProperty );
    ValueNode* false_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFalse ),
                                                     Token::JS_IDENTIFIER , function_->Line(),
                                                     ValueNode::kIdentifier );
    AstNode* bind_clone = bind_sym->Clone();
    CallExp* dot_send = AstUtils::CreateDotAccessor( generator->Clone() , bind_clone );
    NodeList* arg_send = ManagedHandle::Retain<NodeList>();
    arg_send->AddChild( this_sym->Clone() );
    arg_send->AddChild( false_sym );
    CallExp* send_call = AstUtils::CreateNormalAccessor( dot_send , arg_send );

    next->AddChild( normal );
    send->AddChild( send_call );

    list->AddChild( next );
    list->AddChild( send );
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
