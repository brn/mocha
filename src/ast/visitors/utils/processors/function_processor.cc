#include <ast/visitors/utils/processors/function_processor.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/class_traits/uncopyable.h>
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
      } else if ( maybeInitialiser && ( maybeInitialiser->ValueType() == ValueNode::kDst ||
                                        maybeInitialiser->ValueType() == ValueNode::kArray ||
                                        maybeInitialiser->ValueType() == ValueNode::kObject ) ) {
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


class YieldHelper : private Uncopyable {
 public :
  YieldHelper( Function* function , ProcessorInfo* info ) :
      state_( 0 ), is_state_injection_( false ), function_( function ) , info_( info ),
      clause_( CreateCaseClause_( state_ ) ),
      clause_body_( clause_->FirstChild() ),
      body_( ManagedHandle::Retain<NodeList>() ){}

  void ProcessYield() {
    ProcessIteration_();
    ProcessTryCatch_();
    ProcessVarDecl_();
    iterator_ = function_->ChildNodes();
    while ( iterator_.HasNext() ) {
      AstNode* yield_stmt = iterator_.Next();
      if ( yield_stmt->NodeType() != AstNode::kVariableStmt ) {
        printf( "yield type = %s\n" , yield_stmt->GetName() );
        ProcessStmtInYield_( yield_stmt );
      }
    }
    std::list<YieldMark*>::iterator begin = mark_list_.begin(),end = mark_list_.end();
    while ( begin != end ) {
      YieldMark* mark = (*begin);
      char state[10];
      int state_num = mark->Adjust( state_ );
      sprintf( state , "%d" , state_num );
      mark->ReEntrantNode()->Symbol()->SetToken( state );
      ++begin;
    }
    body_->AddChild( clause_ );
    Finish_();
  }

  NodeList* GetBody() {
    return body_;
  }
  
 private :
  void Finish_() {
    ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThrowException ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    
    ValueNode* stop_iteration = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kStopIteration ),
                                                        Token::JS_PROPERTY , function_->Line() , ValueNode::kProperty );
    list->AddChild( stop_iteration );
    CallExp* exp = AstUtils::CreateNormalAccessor( handler , list );
    CallExp* runtime = AstUtils::CreateRuntimeMod( exp );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime );
    ValueNode* is_safe = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSafeFlag ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( undefined );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( is_safe , ret , stmt );
    stmt->Line( function_->Line() );
    CreateCaseClause_( 0 , true );
    clause_body_->AddChild( if_stmt );
    body_->AddChild( clause_ );
  }

  VariableStmt* CreateClearCacheStmt_( const char* symbol ) {
    ValueNode* cache = AstUtils::CreateNameNode( symbol , Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                     Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* clear_cache = AstUtils::CreateVarInitiliser( cache->Symbol() , undefined );
    VariableStmt* clear_cache_stmt = AstUtils::CreateVarStmt( clear_cache );
    function_->SetVariable( clear_cache );
    return clear_cache_stmt;
  }
  
  void ProcessTryCatch_() {
    Function::TryList &list = function_->GetTryCatch();
    if ( list.size() > 0 ) {
      Function::TryList::iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        TryStmt* stmt = (*begin);
        bool has_finally = ( !stmt->Finally()->IsEmpty() );
        ExpressionStmt* catch_stmt = ProcessCatch_( stmt );
        VariableStmt* clear_catch_stmt = CreateClearCacheStmt_( SymbolList::GetSymbol( SymbolList::kCatchCache ) );
        ExpressionStmt* finally_stmt = 0;
        VariableStmt* clear_finally_stmt = 0;
        if ( has_finally ) {
          finally_stmt = ProcessFinally_( stmt );
          clear_finally_stmt = CreateClearCacheStmt_( SymbolList::GetSymbol( SymbolList::kFinallyCache ) );
          clear_finally_stmt->SetYieldFlag();
        } else {
          clear_catch_stmt->SetYieldFlag();
        }
        CopyTryCatchBody_( has_finally , stmt , catch_stmt,
                           clear_catch_stmt , finally_stmt , clear_finally_stmt );
        ++begin;
      }
    }
  }

  void CopyTryCatchBody_( bool has_finally , TryStmt* stmt , ExpressionStmt* catch_stmt,
                          VariableStmt* clear_catch_stmt , ExpressionStmt* finally_stmt,
                          VariableStmt* clear_finally_stmt ) {
    NodeIterator iterator = stmt->FirstChild()->FirstChild()->ChildNodes();
    AstNode* last = 0;
    AstNode* first = 0;
    while ( iterator.HasNext() ) {
      if ( !last ) {
        first = last = iterator.Next();
        stmt->ParentNode()->InsertBefore( last , stmt );
      } else {
        AstNode* item = iterator.Next();
        stmt->ParentNode()->InsertAfter( item , last );
        last = item;
      }
    }
    stmt->ParentNode()->InsertAfter( clear_catch_stmt , stmt );
    stmt->ParentNode()->InsertBefore( catch_stmt , ( first )? first : stmt );
    if ( has_finally ) {
      stmt->ParentNode()->InsertAfter( clear_finally_stmt , clear_catch_stmt );
      stmt->ParentNode()->InsertAfter( finally_stmt , catch_stmt );
    }
    stmt->ParentNode()->RemoveChild( stmt );
  }
  
  ExpressionStmt* ProcessFinally_( TryStmt* stmt ) {
    AstNode* block = stmt->Finally();
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    AstNode* block_body = block->FirstChild();
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , arg , block_body );
    ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFinallyCache ),
                                                Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign );
    ret->Line( block->Line() );
    return ret;
  }

  ExpressionStmt* ProcessCatch_( TryStmt* stmt ) {
    ValueNode* block = stmt->Catch()->CastToValue();
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    AstNode* block_body = block->FirstChild()->FirstChild();
    ValueNode* arg_name = block->Clone()->CastToValue();
    arg_name->RemoveAllChild();
    arg->AddChild( arg_name );
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , arg , block_body );
    ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCatchCache ),
                                                Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn );
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* pseudo_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , state , pseudo_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( exp );
    exp_stmt->Line( function_->Line() );
    mark->ReEntrantNode( pseudo_state );
    fn->InsertBefore( exp_stmt );
    stmt->ParentNode()->InsertAfter( mark , stmt );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign );
    ret->Line( block->Line() );
    return ret;
  }
  
  void ProcessVarDecl_() {
    Function::VariableList &list = function_->GetVariable();
    if ( list.size() > 0 ) {
      TransformVarDecl_( list );
      Function::VariableList::iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        ValueNode* value = (*begin);
        if ( value->ParentNode() && value->ParentNode()->ParentNode() ) {
          value->ParentNode()->ParentNode()->RemoveChild( value->ParentNode() );
        }
        ++begin;
      }
    }
    function_->InsertBefore( CreateStateInitialiser_() );
    function_->InsertBefore( CreateResultInitialiser_() );
    function_->InsertBefore( CreateNewBornCheckFlag_() );
  }

  void TransformVarDecl_( Function::VariableList& list ) {
    Function::VariableList::iterator begin = list.begin(),end = list.end();
    while ( begin != end ) {
      ValueNode* value = (*begin);
      ValueNode* ident = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
      ident->Symbol( value->Symbol() );
      ident->AddChild( ManagedHandle::Retain<Empty>() );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , ident , value->FirstChild()->Clone() );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
      stmt->Line( value->ParentNode()->Line() );
      if ( value->ParentNode()->CastToStatement()->GetYieldFlag() ) {
        stmt->SetYieldFlag();
      }
      printf( "is yield %d  parent type = %d symbol = %s\n" , value->ParentNode()->CastToStatement()->GetYieldFlag() , value->ParentNode()->ParentNode()->NodeType() , value->Symbol()->GetToken() );
      value->ParentNode()->ParentNode()->InsertBefore( stmt , value->ParentNode() );
      ValueNode* var = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
      var->Symbol( value->Symbol() );
      var->AddChild( ManagedHandle::Retain<Empty>() );
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( var );
      var_stmt->Line( value->ParentNode()->Line() );
      function_->InsertBefore( var_stmt );
      ++begin;
    }
  }

  VariableStmt* CreateStateInitialiser_() {
    TokenInfo* state = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                             Token::JS_IDENTIFIER , function_->Line() ) );
    ValueNode* begin_state = AstUtils::CreateNameNode( "0" ,Token::JS_NUMERIC_LITERAL,
                                                       function_->Line() , ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( state , begin_state );
    return AstUtils::CreateVarStmt( value );
  }

  VariableStmt* CreateResultInitialiser_() {
    TokenInfo* result = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kYieldResult ),
                                                             Token::JS_IDENTIFIER , function_->Line() ) );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                     Token::JS_IDENTIFIER, function_->Line(),
                                                     ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( result , undefined );
    return AstUtils::CreateVarStmt( value );
  }


  VariableStmt* CreateNewBornCheckFlag_() {
    TokenInfo* result = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kIsNewBorn ),
                                                             Token::JS_IDENTIFIER , function_->Line() ) );
    ValueNode* true_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTrue ),
                                                    Token::JS_IDENTIFIER, function_->Line(),
                                                    ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( result , true_sym );
    return AstUtils::CreateVarStmt( value );
  }
  
  void ProcessIteration_() {
    typedef Function::StmtList::reverse_iterator Iterator;
    Iterator begin = function_->GetStmtList().rbegin(),end = function_->GetStmtList().rend();
    int count = 0;
    int size = function_->GetStmtList().size();
    YieldMark *if_escape_mark = 0;
    while ( begin != end ) {
      AstNode* iteration_stmt = (*begin);
      if ( iteration_stmt->NodeType() == AstNode::kFor ||
           iteration_stmt->NodeType() == AstNode::kForWithVar ) {
        ProcessFor_( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->NodeType() == AstNode::kForIn ||
                  iteration_stmt->NodeType() == AstNode::kForInWithVar ||
                  iteration_stmt->NodeType() == AstNode::kForEach ||
                  iteration_stmt->NodeType() == AstNode::kForEachWithVar ) {
        ProcessForIn_( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->NodeType() == AstNode::kWhile ) {
        ProcessWhile_( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->NodeType() == AstNode::kDoWhile ) {
        ProcessDoWhile_( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->NodeType() == AstNode::kIFStmt ) {
        if ( if_escape_mark == 0 ) {
          if_escape_mark = ManagedHandle::Retain<YieldMark>();
        }
        if_escape_mark = ProcessIFStmt_( iteration_stmt->CastToStatement()->CastToIFStmt() , if_escape_mark , size , count );
      }
      count++;
      ++begin;
    }
    NodeIterator iterator = function_->ChildNodes();
  }


  YieldMark* ProcessIFStmt_( IFStmt* node , YieldMark* escape_mark , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* cond = node->Exp();
    AstNode* then_body = node->Then();
    AstNode* else_body = node->Else();
    AstNode* current = 0;//init after.
    BlockStmt* then_block;
    BlockStmt* else_block;
    
    YieldMark* normal_mark = ManagedHandle::Retain<YieldMark>();
    YieldMark* abnormal_mark = ManagedHandle::Retain<YieldMark>();
    {
      ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
      ValueNode* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
      BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
      break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
      exp_stmt->Line( function_->Line() );
      then_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
      normal_mark->ReEntrantNode( dynamic_state );
    }

    {
      YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
      ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
      ValueNode* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
      BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
      break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
      exp_stmt->Line( function_->Line() );
      else_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
      abnormal_mark->ReEntrantNode( dynamic_state );
    }
    
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , then_block , else_block );
    if_stmt->Line( node->Line() );
    parent->InsertBefore( if_stmt , mark );
    if_stmt->SetYieldFlag();
    
    AstNode* last;
    if ( then_body->NodeType() == AstNode::kBlockStmt ) {
      NodeIterator iterator = then_body->FirstChild()->ChildNodes();
      while ( iterator.HasNext() ) {
        AstNode* item = iterator.Next();
        if ( !item->IsEmpty() ) {
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
      last = current;
    } else if ( !then_body->IsEmpty() ) {
      current = last = then_body;
      parent->InsertBefore( last , mark );
    }
    last->ParentNode()->InsertBefore( normal_mark , last );
    last->CastToStatement()->SetYieldFlag();
    AstNode* embed_ptr = 0;
    {
      ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
      ValueNode* dynamic_state = 0;
      if ( escape_mark->ReEntrantNode() == 0 ) {
        dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
        escape_mark->ReEntrantNode( dynamic_state );
      } else {
        dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
        dynamic_state->Symbol( escape_mark->ReEntrantNode()->Symbol() );
      }
      
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
      last->ParentNode()->InsertAfter( exp_stmt , last );
      BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
      break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
      last->ParentNode()->InsertAfter( break_stmt , exp_stmt );
      break_stmt->SetYieldFlag();
      embed_ptr = current = break_stmt;
    }

    if ( !else_body->IsEmpty() ) {
      if ( else_body->NodeType() == AstNode::kBlockStmt ) {
        NodeIterator iterator = else_body->FirstChild()->ChildNodes();
        while ( iterator.HasNext() ) {
          AstNode* item = iterator.Next();
          if ( !item->IsEmpty() ) {
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
        last = current;
      } else {
        current = last = else_body;
        parent->InsertBefore( last , mark );
      }
      last->ParentNode()->InsertBefore( abnormal_mark , last );
      if ( else_body->NodeType() != AstNode::kIFStmt ) {
        last->ParentNode()->InsertAfter( escape_mark , last );
        escape_mark = 0;
      }
    } else {
      last->ParentNode()->InsertAfter( abnormal_mark , last );
      last->ParentNode()->InsertAfter( escape_mark , abnormal_mark );
      escape_mark->SetAdjust( 1 );
      escape_mark = 0;
    }
    
    if ( !last->IsEmpty() ) {
      last->CastToStatement()->SetYieldFlag();
    }
    
    mark->ParentNode()->RemoveChild( mark );
    return escape_mark;
  }

  
  void ProcessDoWhile_( IterationStmt* node , int size , int count ) {
    if ( node->PreviousSibling() ) {
      node->PreviousSibling()->CastToStatement()->SetYieldFlag();
    }
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* cond = node->Exp();
    AstNode* body = node->FirstChild();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
    ExYieldStateNode* ex_node = ProcessDynamicState_( cond );
    ex_node->Line( node->Line() );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( state_mark , mark );
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
    } else {
      parent->InsertBefore( body->FirstChild() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }

  
  void ProcessWhile_( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* cond = node->Exp();
    AstNode* body = node->FirstChild();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
    state_mark->SetAdjust( 1 );
    ExYieldStateNode* ex_node = ProcessDynamicState_( cond );
    ex_node->Line( node->Line() );
    IFStmt* if_stmt = CreateEscapeState_( cond , ex_node );
    if_stmt->Line( node->Line() );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( if_stmt , mark );
    parent->InsertBefore( state_mark , if_stmt );
    if_stmt->SetYieldFlag();
    
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
    } else {
      parent->InsertBefore( body->FirstChild() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }

  
  void ProcessFor_( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    mark->SetAdjust( 1 );
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
        stmt->Line( node->Line() );
        parent->InsertBefore( stmt , mark );
      }
    }
    if ( !cond->IsEmpty() ) {
      YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
      state_mark->SetAdjust( 1 );
      ExYieldStateNode* ex_node = ProcessDynamicState_( cond );
      ex_node->Line( node->Line() );
      IFStmt* if_stmt = CreateEscapeState_( cond , ex_node );
      if_stmt->Line( node->Line() );
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
    } else {
      parent->InsertBefore( body->FirstChild() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }


  void ProcessForIn_( IterationStmt* node , int size , int count ) {
    AstNode* exp = node->Exp();
    VisitorInfo* visitor_info = info_->GetInfo();
    ValueNode* tmp_node = AstUtils::CreateTmpNode( visitor_info->GetTmpIndex() );
    tmp_node->ValueType( ValueNode::kVariable );
    tmp_node->AddChild( ManagedHandle::Retain<Empty>() );
    AstNode* index_exp = exp->FirstChild();
    AstNode* target_exp = index_exp->NextSibling();
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForInWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( node->Line() );
    list->AddChild( tmp_node );
    list->AddChild( target_exp );
    iter->Exp( list );
    ValueNode* array_lhs = AstUtils::CreateTmpNode( visitor_info->GetTmpIndex() );
    ValueNode* array = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    ValueNode* tmp_array = AstUtils::CreateVarInitiliser( array_lhs->Symbol() , array );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( tmp_array );
    function_->InsertBefore( var_stmt );
    ValueNode* push = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPush ),
                                                Token::JS_PROPERTY , 0 , ValueNode::kProperty );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    ValueNode* name = tmp_node->Clone()->CastToValue();
    name->ValueType( ValueNode::kIdentifier );
    arg->AddChild( name );
    CallExp* push_call = AstUtils::CreateNormalAccessor( push , arg );
    CallExp* push_accessor = AstUtils::CreateDotAccessor( array_lhs->Clone() , push_call );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( push_accessor );
    stmt->Line( function_->Line() );
    iter->AddChild( stmt );
    node->ParentNode()->InsertBefore( iter , node );
    TransformForIn_( node , array_lhs->Clone()->CastToValue() , size , count );
  }


  void TransformForIn_( IterationStmt* node , ValueNode* array , int size , int count ) {
    VisitorInfo* visitor_info = info_->GetInfo();
    AstNode* exp = node->Exp();
    AstNode* index_exp = exp->FirstChild();
    ValueNode* tmp_node = AstUtils::CreateTmpNode( visitor_info->GetTmpIndex() );
    ValueNode* zero = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    ValueNode* index = AstUtils::CreateVarInitiliser( tmp_node->Symbol() , zero );
    ValueNode* length = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLength ),
                                                  Token::JS_PROPERTY , 0 , ValueNode::kProperty );
    CallExp* length_accessor = AstUtils::CreateDotAccessor( array , length );
    ValueNode* var_length = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLength ),
                                                  Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* len_cache = AstUtils::CreateVarInitiliser( var_length->Symbol() , length_accessor );
    NodeList* var_list = AstUtils::CreateNodeList( 2 , index , len_cache );
    function_->SetVariable( index );
    function_->SetVariable( len_cache );
    ValueNode* index_name = AstUtils::CreateNameNode( index->Symbol()->GetToken(),
                                                      Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* len_name = AstUtils::CreateNameNode( len_cache->Symbol()->GetToken(),
                                                    Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    CompareExp* cmp = ManagedHandle::Retain( new CompareExp( '<' , index_name , len_name ) );
    UnaryExp* unary = AstUtils::CreateUnaryExp( Token::JS_INCREMENT , index_name->Clone() );
    
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = AstUtils::CreateNodeList( 3 , var_list , cmp , unary );
    iter->Line( node->Line() );
    iter->Exp( list );
    AstNode* index_stmt;
    if ( index_exp->CastToValue()->ValueType() == ValueNode::kVariable ) {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() );
      index_exp->RemoveAllChild();
      index_exp->AddChild( accessor );
      index_stmt = AstUtils::CreateVarStmt( index_exp );
    } else {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , index_exp , accessor );
      index_stmt = AstUtils::CreateExpStmt( assign );
    }
    
    AstNode* maybeBlock = node->FirstChild();
    if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
      maybeBlock->FirstChild()->InsertBefore( index_stmt );
      iter->AddChild( maybeBlock );
    } else {
      BlockStmt* block = AstUtils::CreateBlockStmt( 2 , index_stmt , maybeBlock );
      iter->AddChild( block );
    }
    node->ParentNode()->ReplaceChild( node , iter );
    ProcessFor_( iter , size , count );
  }
  

  IFStmt* CreateEscapeState_( AstNode* cond , ExYieldStateNode *ex_node ) {
    ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    
    ValueNode* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
    exp_stmt->Line( function_->Line() );
    

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( cond );
    exp->Paren();
    UnaryExp *not_exp = AstUtils::CreateUnaryExp( '!' , exp );
    break_stmt->Line( function_->Line() );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    BlockStmt* if_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
    IFStmt *if_stmt = AstUtils::CreateIFStmt( not_exp , if_block , ManagedHandle::Retain<Empty>() );
    if_stmt->Line( function_->Line() );
    ex_node->EscapePtr( dynamic_state );
    return if_stmt;
  }

  ExpressionStmt* CreateStateAssignment_( const char* state ) {
    ValueNode* state_node = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* state_val = AstUtils::CreateNameNode( state , Token::JS_NUMERIC_LITERAL , 0 , ValueNode::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state_node , state_val );
    return AstUtils::CreateExpStmt( assign );
  }

  ExYieldStateNode* ProcessDynamicState_( AstNode* cond ) {
    ExpressionStmt* exp_stmt = CreateStateAssignment_( "0" );
    exp_stmt->Line( function_->Line() );
    
    ExpressionStmt* next_stmt = CreateStateAssignment_( "0" );
    next_stmt->Line( function_->Line() );

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( 0 );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    BlockStmt* else_block = AstUtils::CreateBlockStmt( 1 , next_stmt );
    BlockStmt* if_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , if_block , else_block );
    if_stmt->Line( function_->Line() );
    ExYieldStateNode* ex_node = ManagedHandle::Retain<ExYieldStateNode>();
    ex_node->LoopBackPtr( exp_stmt->FirstChild()->FirstChild()->CastToExpression()->CastToAssigment()->Right()->CastToValue() );
    ex_node->NextPtr( next_stmt->FirstChild()->FirstChild()->CastToExpression()->CastToAssigment()->Right()->CastToValue() );
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
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
    stmt->Line( line );
    return stmt;
  }

  void SetState_( long line ) {
    if ( is_state_injection_ ) {
      if ( !iterator_.HasNext() ) {
        state_ = -2;
        clause_body_->InsertBefore( CreateNextState_( line ) );
      } else {
        clause_body_->InsertBefore( CreateNextState_( line ) );
        state_++;
      }
    } else {
      if ( !iterator_.HasNext() ) {
        state_ = -2;
      } else {
        state_++;
      }
    }
  }
  
  void ProcessStmtInYield_( AstNode* yield_stmt ) {
    function_->RemoveChild( yield_stmt );
    if ( !yield_stmt->CastToStatement() )
      printf( "error type %s\n" , yield_stmt->GetName() );
    if ( yield_stmt->NodeType() == AstNode::kReturnStmt ) {
      is_state_injection_ = true;
    }
    if ( yield_stmt->NodeType() == AstNode::kYieldMark ) {
      YieldMark* yield_mark = yield_stmt->CastToStatement()->CastToYieldMark();
      char state[10];
      int state_num = ( iterator_.HasNext() )? yield_mark->Adjust( state_ ) : -1;
      sprintf( state , "%d" , state_num );
      yield_mark->ReEntrantNode()->Symbol()->SetToken( state );
      //mark_list_.push_back( yield_stmt->CastToStatement()->CastToYieldMark() );
    } else if ( yield_stmt->NodeType() == AstNode::kExYieldStateNode ) {
      ExYieldStateNode* ex_node = yield_stmt->CastToStatement()->CastToYieldState();
      char back[10];
      sprintf( back ,"%d" , ( state_ - 1 ) );
      char next[10];
      int next_state;
      ValueNode* esc = ex_node->EscapePtr();
      SetState_( yield_stmt->Line() );
      sprintf( next ,"%d" , ( ( state_ < 0 )? -1 : state_ ) );
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
    } else if ( yield_stmt->CastToStatement() && yield_stmt->CastToStatement()->GetYieldFlag() ) {
      std::list<YieldMark*>::iterator begin = mark_list_.begin(),end = mark_list_.end();
      while ( begin != end ) {
        YieldMark* mark = (*begin);
        char state[10];
        int state_num = ( iterator_.HasNext() )? mark->Adjust( state_ ) : -1;
        sprintf( state , "%d" , state_num );
        mark->ReEntrantNode()->Symbol()->SetToken( state );
        ++begin;
      }
      mark_list_.clear();
      SetState_( yield_stmt->Line() );
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
  std::list<YieldMark*> mark_list_;
};


class GeneratorHelper : private Uncopyable {
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
  }
  
 private :

  void CreateStateLoop_( Function* fn ) {
    NodeList *generator_arg = ManagedHandle::Retain<NodeList>();
    ValueNode* one_exp = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->Line() , ValueNode::kNumeric );
    ValueNode* is_send = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSendFlag ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* is_safe = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSafeFlag ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
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
    generator_arg->AddChild( is_safe );
    fn->Argv( generator_arg );
    if ( function_->GetTryCatch().size() > 0 ) {
      TryStmt* stmt = ManagedHandle::Retain<TryStmt>();
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      stmt->Catch( CreateCatchHandler_() );
      stmt->Finally( CreateFinallyHandler_() );
      AstNode* node = iter->FirstChild()->FirstChild();
      iter->RemoveAllChild();
      block->AddChild( node );
      stmt->AddChild( block );
      iter->AddChild( stmt );
    }
    fn->AddChild( iter );
  }


  BlockStmt* CreateExceptionReturnValueCheckStmt_ ( CallExp* call_handler ) {
    ValueNode* cache = AstUtils::CreateTmpNode( info_->GetInfo()->GetTmpIndex() );
    AstNode* return_value = cache->Clone();
    cache->ValueType( ValueNode::kVariable );
    cache->AddChild( call_handler );
    VariableStmt* value_stmt = AstUtils::CreateVarStmt( cache );
    ReturnStmt* return_value_stmt = AstUtils::CreateReturnStmt( return_value );
    BlockStmt* blk = AstUtils::CreateBlockStmt( 1 , return_value_stmt );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ) , Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    CompareExp* is_defined = ManagedHandle::Retain( new CompareExp( Token::JS_NOT_EQ , return_value->Clone() , undefined ) );
    IFStmt* is_return = AstUtils::CreateIFStmt( is_defined , blk , ManagedHandle::Retain<Empty>() );
    BlockStmt* check_return = AstUtils::CreateBlockStmt( 2 , value_stmt , is_return );
    return check_return;
  }
  
  ValueNode* CreateCatchHandler_() {
    ValueNode* catches = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kException ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    BlockStmt* catch_block = ManagedHandle::Retain<BlockStmt>();
    ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCatchCache ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    NodeList* args = ManagedHandle::Retain<NodeList>();
    args->AddChild( catches->Clone() );
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args );

    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt_( call_handler );
    
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    ValueNode* thrower = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThrowException ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( catches->Clone() );
    CallExp* throw_call = AstUtils::CreateNormalAccessor( thrower , list );
    CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( throw_call );
    ExpressionStmt* call_stmt = AstUtils::CreateExpStmt( runtime_accessor );
    if_stmt->Exp( handler->Clone() );
    if_stmt->Then( check_return );
    if_stmt->Else( call_stmt );
    StatementList *catch_stmt_list = ManagedHandle::Retain<StatementList>();
    catch_stmt_list->AddChild( if_stmt );
    catch_block->AddChild( catch_stmt_list );
    catches->AddChild( catch_block );
    return catches;
  }

  AstNode* CreateFinallyHandler_() {
    BlockStmt* finally_block = ManagedHandle::Retain<BlockStmt>();
    ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFinallyCache ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    NodeList* args = ManagedHandle::Retain<NodeList>();
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args );
    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt_( call_handler );
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    if_stmt->Exp( handler->Clone() );
    if_stmt->Then( check_return );
    if_stmt->Else( ManagedHandle::Retain<Empty>() );
    StatementList *finally_stmt_list = ManagedHandle::Retain<StatementList>();
    finally_stmt_list->AddChild( if_stmt );
    finally_block->AddChild( finally_stmt_list );
    return finally_block;
  }
  
  IFStmt* CreateNewBornCheckStmt_() {
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    ValueNode* is_send = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSendFlag ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* is_new_born = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kIsNewBorn ),
                                                       Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* false_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFalse ),
                                                    Token::JS_IDENTIFIER, function_->Line(),
                                                    ValueNode::kIdentifier , ValueNode::kIdentifier );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , is_new_born , false_sym ) );
    UnaryExp* not_is_send = ManagedHandle::Retain( new UnaryExp( '!' ) );
    not_is_send->Exp( is_send );
    if_stmt->Exp( not_is_send );
    BlockStmt* then_block = ManagedHandle::Retain<BlockStmt>();
    StatementList* then_list = ManagedHandle::Retain<StatementList>();
    then_list->AddChild( stmt );
    then_block->AddChild( then_list );
    if_stmt->Then( then_block );
    IFStmt* else_if_stmt = ManagedHandle::Retain<IFStmt>();
    ValueNode* arguments = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kArguments ),
                                                     Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* one = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->Line() , ValueNode::kNumeric );
    CallExp* array_accessor = AstUtils::CreateArrayAccessor( arguments , one );
    ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                     Token::JS_NUMERIC_LITERAL, function_->Line(),
                                                     ValueNode::kIdentifier );
    CompareExp* undef_check = ManagedHandle::Retain( new CompareExp( Token::JS_NOT_EQ , array_accessor , undefined ) );
    CompareExp* comp = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , is_send->Clone() , is_new_born ) );
    CompareExp* comp2 = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , comp , undef_check ) );
    BlockStmt* else_block = ManagedHandle::Retain<BlockStmt>();
    StatementList* else_list = ManagedHandle::Retain<StatementList>();
    ValueNode* handler = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kExceptionHandler ),
                                                   Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* message = AstUtils::CreateNameNode( "'attempt to send to newborn generator.'" , Token::JS_STRING_LITERAL , function_->Line() , ValueNode::kString );
    NodeList* handle_list = ManagedHandle::Retain<NodeList>();
    handle_list->AddChild( message );
    CallExp* handle_exp = AstUtils::CreateNormalAccessor( handler , handle_list );
    CallExp* runtime = AstUtils::CreateRuntimeMod( handle_exp );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( runtime );
    else_list->AddChild( exp_stmt );
    else_if_stmt->Exp( comp2 );
    else_block->AddChild( else_list );
    else_if_stmt->Then( else_block );
    else_if_stmt->Else( ManagedHandle::Retain<Empty>() );
    if_stmt->Else( else_if_stmt );
    return if_stmt;
  }

  ValueNode* ObjectInitialiser_( ValueNode* generator , bool is_send ) {
    ValueNode* name;
    ValueNode* boolean;
    if ( !is_send ) {
      name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldNext ),
                                                  Token::JS_PROPERTY , function_->Line(),
                                                  ValueNode::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTrue ),
                                                    Token::JS_IDENTIFIER , function_->Line(),
                                                    ValueNode::kIdentifier );
    } else {
      name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldSend ),
                                                  Token::JS_PROPERTY , function_->Line(),
                                                  ValueNode::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFalse ),
                                                       Token::JS_IDENTIFIER , function_->Line(),
                                                       ValueNode::kIdentifier );
    }
    ValueNode* bind_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kBind ),
                                                    Token::JS_PROPERTY , function_->Line(),
                                                    ValueNode::kProperty );
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , function_->Line(),
                                                    ValueNode::kIdentifier );
    
    CallExp* dot = AstUtils::CreateDotAccessor( generator->Clone() , bind_sym );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    arg->AddChild( this_sym );
    arg->AddChild( boolean );
    CallExp* call = AstUtils::CreateNormalAccessor( dot , arg );
    name->AddChild( call );
    return name;
  }

  Function* CloseInitialiser_() {
    ValueNode* state = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
    ValueNode* error_state = AstUtils::CreateNameNode( "-1" , Token::JS_NUMERIC_LITERAL , function_->Line() , ValueNode::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , error_state );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
    Function* close_fn = ManagedHandle::Retain<Function>();
    close_fn->Name( ManagedHandle::Retain<Empty>() );
    close_fn->Argv( ManagedHandle::Retain<NodeList>() );
    close_fn->AddChild( stmt );
    if ( function_->GetTryCatch().size() > 0 ) {
      ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kFinallyCache ),
                                                  Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier );
      CallExp* exp = AstUtils::CreateNormalAccessor( name , ManagedHandle::Retain<NodeList>() );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
      IFStmt* if_stmt = AstUtils::CreateIFStmt( name->Clone() , stmt , ManagedHandle::Retain<Empty>() );
      close_fn->AddChild( if_stmt );
    }
    return close_fn;
  }
  
  void GeneratorInitialiser_( Function* fn ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    CreateStateLoop_( fn );
    fn->InsertBefore( CreateNewBornCheckStmt_() );
    ValueNode* generator = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGenerator ),
                                                     Token::JS_IDENTIFIER , function_->Line() , ValueNode::kIdentifier , true );
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , 0 , ValueNode::kIdentifier );
    ValueNode* generator_init = AstUtils::CreateVarInitiliser( generator->Symbol() , fn );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( generator_init );
    function_->AddChild( var_stmt );
    ValueNode* create_generator = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateGenerator ),
                                                            Token::JS_PROPERTY , function_->Line() , ValueNode::kIdentifier );
    NodeList* args = AstUtils::CreateNodeList( 3 , generator->Clone() , CloseInitialiser_() , this_sym );
    CallExp* create_generator_call = AstUtils::CreateNormalAccessor( create_generator , args );
    CallExp* runtime = AstUtils::CreateRuntimeMod( create_generator_call );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( runtime );
    function_->AddChild( ret );
  }
  
  void ProcessReturn_() {
    Function* fn = ManagedHandle::Retain<Function>();
    fn->Name( ManagedHandle::Retain<Empty>() );
    GeneratorInitialiser_( fn );
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
