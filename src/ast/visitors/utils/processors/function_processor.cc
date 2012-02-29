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

namespace mocha {

FunctionProcessor::FunctionProcessor( Function* function , ProcessorInfo* info ) :
    function_( function ) , info_( info ) , stmt_( ManagedHandle::Retain<Statement>() ),
    formal_parameter_( function->Argv() ) , default_parameter_( ManagedHandle::Retain<NodeList>() ) {
  argc_ = formal_parameter_->child_length();
  info_->visitor_info()->set_current_statement( stmt_ );
}

FunctionProcessor::~FunctionProcessor() {}

void FunctionProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->visitor_info();
  visitor_info->set_function( function_ );
  ProcessFormalParameter();
  bool is_rest = visitor_info->rest_injection();
  visitor_info->set_rest_injection( false );
  VariableStmt* dsta_stmt = 0;
  VariableStmt* rest_stmt = 0;
  if ( function_->IsContainDestructuring() ) {
    NodeList *list = DstaProcessor::CreateDstaExtractedVarStmt( stmt_ , info_ );
    VariableDeclarationList decl_list = VariableDeclarationList::New( function_->line_number() );
    decl_list->Append( list );
    dsta_stmt = AstUtils::CreateVarStmt( decl_list , function_->line_number() );
  }
  if ( is_rest ) {
    rest_stmt = ProcessRestParameter();
  }
  ProcessBody();
  if ( function_->IsGenerator() ) {
    ProcessYield();
  }
  if ( dsta_stmt && rest_stmt ) {
    dsta_stmt->AddChild( rest_stmt->first_child() );
    function_->InsertBefore( dsta_stmt );
  } else if ( dsta_stmt ) {
    function_->InsertBefore( dsta_stmt );
  } else if ( rest_stmt ) {
    function_->InsertBefore( rest_stmt );
  }
  if ( default_parameter_->child_length() > 0 ) {
    NodeIterator iterator = default_parameter_->ChildNodes();
    while ( iterator.HasNext() ) {
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( iterator.Next() );
      function_->InsertBefore( stmt );
    }
  }
}

bool IsDestructuring( AstNode* node ) {
  if ( node->node_type() == AstNode::kArrayLikeLiteral || node->node_type == AstNode::kObjectLikeLiteral ) {
    return true;
  } else {
    if ( node->node_type() == AstNode::kAssignmentExp ) {
      return AstUtils::DestructuringLeftHandSide( node->CastToExpression()->CastToAssigment()->left_value() );
    }
    return false;
  }
}

void FunctionProcessor::ProcessFormalParameter() {
  if ( !formal_parameter_->IsEmpty() && argc_ > 0 ) {
    IVisitor* visitor = info_->visitor();
    NodeIterator iterator = formal_parameter_->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* node = iterator.Next();
      Expression* expression = node->CastToExpression();
      AssignmentExp* maybe_initialiser = expression->CastToAssigment();
      if ( maybe_initialiser ) {
        ProcessDefaultParameter( maybe_initialiser );
      } else if ( IsDestructuring( node ) ) {
        bool has_default_parameter = node->node_type() == AstNode::kAssignmentExp;
        Literal* value = DstaProcessor::ProcessNode( node );
        if ( has_default_parameter ) {
          AstNode* arg = literal->Clone();
          AssignmentExp* assign = AssignmentExp::New( '=' , arg , maybe_initialiser->right_value()->Clone() , function_->line_number() );
          ProcessDefaultParameter( assign );
        }
      } else if ( node->node_type() == AstNode::kAssignmentExp ) {
        ProcessDefaultParameter( node->CastToExpression()->CastToAssigment() );
      } else if ( node->node_type() == AstNode::kCallExp ) {
        ProcessPropertyParameter( node->CastToExpression()->CastToCallExp() );
      } else {
        node->Accept( visitor );
      }
    }
  }
}



void FunctionProcessor::ProcessDefaultParameter( Literal *value ) {
  Literal* initialiser = value->Clone()->CastToLiteral();
  Literal* arg = initialiser->Clone()->CastToLiteral();
  AstNode* default_value = initialiser->first_child();
  arg->RemoveAllChild();
  initialiser->RemoveAllChild();
  CompareExp* logical_or = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_OR , arg , default_value ) );
  AssignmentExp* exp = AstUtils::CreateAssignment( '=', initialiser , logical_or );
  default_parameter_->InsertBefore( exp );
}


void FunctionProcessor::ProcessDefaultParameter( AssignmentExp *exp ) {
  Literal* arg = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , function_->line_number() );
  exp->parent_node()->ReplaceChild( exp , arg );
  CompareExp* logical_or = CompareExp::New( Token::JS_LOGICAL_OR , arg->Clone() , exp->Right() , function_->line_number() );
  AssignmentExp* ret = AstUtils::CreateAssignment( '=', exp->left_value()->Clone() , logical_or , function_->line_number() );
  default_parameter_->InsertBefore( ret );
  ret->Accept( info_->visitor() );
}


void FunctionProcessor::ProcessPropertyParameter( CallExp *exp ) {
  Literal* arg = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , function_->line_number() );
  exp->ParentNode()->ReplaceChild( exp , arg );
  AssignmentExp* ret = AstUtils::CreateAssignment( '=', exp , arg->Clone() , function_->line_number() );
  default_parameter_->InsertBefore( ret );
  exp->Accept( info_->visitor() );
}



void FunctionProcessor::ProcessBody() {
  IVisitor *visitor = info_->visitor();
  if ( function_->context_type() == Function::kThis ) {
    bool is_assignment = false;
    AstNode* tmp = function_->parent_node();
    if ( !function_->IsDeclared() ) {
      is_assignment = true;
    }
    if ( !is_assignment ) {
      Literal* tmp_name = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , function_->line_number() );
      Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                    Token::JS_THIS , function_->line_number() , Literal::kThis );
      Literal* initialiser = AstUtils::CreateVarInitiliser( tmp_name->value() , this_sym );
      AstNode* statement = function_->parent_node();
      while ( !statement->CastToStatement() &&
              statement->node_type() != AstNode::kFileRoot ||
              statement->node_type() != AstNode::kCase ) {
        if ( statement->HasParent() ) {
          statement = statement->ParentNode();
        } else {
          break;
        }
      }
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarDeclList( fucntion_->line_number() , 1 initialiser ) , function_->line_number() );
      statement->InsertBefore( var_stmt , function_ );
      function_->set_replaced_this( tmp_name );
    } else {
      Statement* mark = Statement::New();
      Literal* bind_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kBind ),
                                                      Token::JS_PROPERTY , function_->line_number() , Literal::kProperty );
      Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                      Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
      NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
      CallExp* bind_call = AstUtils::CreateNormalAccessor( bind_sym , arg );
      AstNode* parent = function_->ParentNode();
      parent->ReplaceChild( function_ , mark );
      CallExp* binding_function = AstUtils::CreateDotAccessor( function_ , bind_call );
      parent->ReplaceChild( mark , binding_function );
    }
  }
  if ( function_->function_type() == Function::kShorten ) {
    Statement* stmt_tmp = Statement::New();
    info_->visitor_info()->set_current_statement( stmt_tmp );
    function_->first_child()->Accept( visitor );
    ReturnStmt* ret_stmt = AstUtils::CreateReturnStmt( function_->first_child()->Clone() , function_->line_number() );
    function_->RemoveAllChild();
    if ( stmt_tmp->IsContainDestructuring() ) {
      NodeList* list = NodeList::New();
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


VariableStmt* FunctionProcessor::ProcessRestParameter() {
  Literal* rhs = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kArguments ),
                                           Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
  NodeList* list = NodeList::New();
  char num[50];
  sprintf( num , "%d" , argc_ - 1 );
  Literal* arg = AstUtils::CreateNameNode( num , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
  Literal* to_array = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kToArray ),
                                                Token::JS_IDENTIFIER , function_->line_number() , Literal::kProperty );
  list->AddChild( rhs );
  list->AddChild( arg );
  CallExp* nrm = AstUtils::CreateNormalAccessor( to_array , list , function_->line_number() );
  CallExp* std_to_array = AstUtils::CreateRuntimeMod( nrm , function_->line_number() );
  Literal* var_node = AstUtils::CreateVarInitiliser( info_->visitor_info()->rest_expression() , std_to_array , function_->line_number() );
  NodeList* var_list = NodeList::New();
  var_list->AddChild( var_node );
  return AstUtils::CreateVarStmt( var_list , function_->line_number() );
}


class YieldHelper : private Uncopyable {
 public :
  YieldHelper( Function* function , ProcessorInfo* info ) :
      state( 0 ), is_state_injection( false ), no_state_injection( false ),
      function( function ) , info( info ),
      clause( CreateCaseClause( state_ ) ),
      clause_body( clause_->first_child() ),
      body( ManagedHandle::Retain<NodeList>() ){}

  void ProcessYield() {
    ProcessIteration();
    ProcessTryCatch();
    ProcessVarDecl();
    iterator_ = function_->ChildNodes();
    while ( iterator_.HasNext() ) {
      AstNode* yield_stmt = iterator_.Next();
      if ( yield_stmt->node_type() != AstNode::kVariableStmt ) {
        ProcessStmtInYield( yield_stmt );
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
    Finish();
  }

  NodeList* GetBody() {
    return body_;
  }
  
 private :
  void Finish() {
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThrowStopIteration ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Empty* empty = ManagedHandle::Retain<Empty>();
    CallExp* exp = AstUtils::CreateNormalAccessor( handler , empty );
    CallExp* runtime = AstUtils::CreateRuntimeMod( exp );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime );
    Literal* is_safe = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSafeFlag ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( undefined );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( is_safe , ret , stmt );
    stmt->line_number( function_->line_number() );
    CreateCaseClause( 0 , true );
    clause_body_->AddChild( if_stmt );
    body_->AddChild( clause_ );
  }

  VariableStmt* CreateClearCacheStmt( const char* symbol ) {
    Literal* cache = AstUtils::CreateNameNode( symbol , Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                     Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* clear_cache = AstUtils::CreateVarInitiliser( cache->Symbol() , undefined );
    VariableStmt* clear_cache_stmt = AstUtils::CreateVarStmt( clear_cache );
    function_->SetVariable( clear_cache );
    return clear_cache_stmt;
  }
  
  void ProcessTryCatch() {
    Function::TryList &list = function_->GetTryCatch();
    if ( list.size() > 0 ) {
      Function::TryList::iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        TryStmt* stmt = (*begin);
        bool has_finally = ( !stmt->Finally()->IsEmpty() );
        ExpressionStmt* catch_stmt = ProcessCatch( stmt );
        VariableStmt* clear_catch_stmt = CreateClearCacheStmt( SymbolList::symbol( SymbolList::kCatchCache ) );
        ExpressionStmt* finally_stmt = 0;
        VariableStmt* clear_finally_stmt = 0;
        if ( has_finally ) {
          finally_stmt = ProcessFinally( stmt );
          clear_finally_stmt = CreateClearCacheStmt( SymbolList::symbol( SymbolList::kFinallyCache ) );
          clear_finally_stmt->SetYieldFlag();
        } else {
          clear_catch_stmt->SetYieldFlag();
        }
        CopyTryCatchBody( has_finally , stmt , catch_stmt,
                           clear_catch_stmt , finally_stmt , clear_finally_stmt );
        ++begin;
      }
    }
  }

  void CopyTryCatchBody( bool has_finally , TryStmt* stmt , ExpressionStmt* catch_stmt,
                          VariableStmt* clear_catch_stmt , ExpressionStmt* finally_stmt,
                          VariableStmt* clear_finally_stmt ) {
    NodeIterator iterator = stmt->first_child()->first_child()->ChildNodes();
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
  
  ExpressionStmt* ProcessFinally( TryStmt* stmt ) {
    AstNode* block = stmt->Finally();
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    AstNode* block_body = block->first_child();
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , arg , block_body );
    Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                                Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign );
    ret->line_number( block->line_number() );
    return ret;
  }

  ExpressionStmt* ProcessCatch( TryStmt* stmt ) {
    Literal* block = stmt->Catch()->CastToLiteral();
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    AstNode* block_body = block->first_child()->first_child();
    Literal* arg_name = block->Clone()->CastToLiteral();
    arg_name->RemoveAllChild();
    arg->AddChild( arg_name );
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , arg , block_body );
    Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCatchCache ),
                                                Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn );
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* pseudo_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , state , pseudo_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( exp );
    exp_stmt->line_number( function_->line_number() );
    mark->ReEntrantNode( pseudo_state );
    fn->InsertBefore( exp_stmt );
    stmt->ParentNode()->InsertAfter( mark , stmt );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign );
    ret->line_number( block->line_number() );
    return ret;
  }
  
  void ProcessVarDecl() {
    Function::VariableList &list = function_->GetVariable();
    if ( list.size() > 0 ) {
      TransformVarDecl( list );
      Function::VariableList::iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        Literal* value = (*begin);
        if ( value->ParentNode() && value->ParentNode()->ParentNode() ) {
          value->ParentNode()->ParentNode()->RemoveChild( value->ParentNode() );
        }
        ++begin;
      }
    }
    function_->InsertBefore( CreateStateInitialiser() );
    function_->InsertBefore( CreateResultInitialiser() );
    function_->InsertBefore( CreateNewBornCheckFlag() );
  }

  void TransformVarDecl( Function::VariableList& list ) {
    Function::VariableList::iterator begin = list.begin(),end = list.end();
    while ( begin != end ) {
      Literal* value = (*begin);
      Literal* ident = ManagedHandle::Retain( new Literal( Literal::kIdentifier ) );
      ident->Symbol( value->Symbol() );
      ident->AddChild( ManagedHandle::Retain<Empty>() );
      if ( !value->first_child()->IsEmpty() ) {
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , ident , value->first_child()->Clone() );
        ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
        stmt->line_number( value->ParentNode()->line_number() );
        if ( value->ParentNode()->CastToStatement()->GetYieldFlag() ) {
          stmt->SetYieldFlag();
        }
        value->ParentNode()->ParentNode()->InsertBefore( stmt , value->ParentNode() );
      }
      Literal* var = ManagedHandle::Retain( new Literal( Literal::kVariable ) );
      var->Symbol( value->Symbol() );
      var->AddChild( ManagedHandle::Retain<Empty>() );
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( var );
      var_stmt->line_number( value->ParentNode()->line_number() );
      function_->InsertBefore( var_stmt );
      ++begin;
    }
  }

  VariableStmt* CreateStateInitialiser() {
    TokenInfo* state = ManagedHandle::Retain( new TokenInfo( SymbolList::symbol( SymbolList::kYieldState ),
                                                             Token::JS_IDENTIFIER , function_->line_number() ) );
    Literal* begin_state = AstUtils::CreateNameNode( "0" ,Token::JS_NUMERIC_LITERAL,
                                                       function_->line_number() , Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( state , begin_state );
    return AstUtils::CreateVarStmt( value );
  }

  VariableStmt* CreateResultInitialiser() {
    TokenInfo* result = ManagedHandle::Retain( new TokenInfo( SymbolList::symbol( SymbolList::kYieldResult ),
                                                             Token::JS_IDENTIFIER , function_->line_number() ) );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                     Token::JS_IDENTIFIER, function_->line_number(),
                                                     Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( result , undefined );
    return AstUtils::CreateVarStmt( value );
  }


  VariableStmt* CreateNewBornCheckFlag() {
    TokenInfo* result = ManagedHandle::Retain( new TokenInfo( SymbolList::symbol( SymbolList::kIsNewBorn ),
                                                             Token::JS_IDENTIFIER , function_->line_number() ) );
    Literal* true_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kTrue ),
                                                    Token::JS_IDENTIFIER, function_->line_number(),
                                                    Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( result , true_sym );
    return AstUtils::CreateVarStmt( value );
  }
  
  void ProcessIteration() {
    typedef Function::StmtList::reverse_iterator Iterator;
    Iterator begin = function_->GetStmtList().rbegin(),end = function_->GetStmtList().rend();
    int count = 0;
    int size = function_->GetStmtList().size();
    YieldMark *if_escape_mark = 0;
    while ( begin != end ) {
      AstNode* iteration_stmt = (*begin);
      if ( iteration_stmt->node_type() == AstNode::kFor ||
           iteration_stmt->node_type() == AstNode::kForWithVar ) {
        ProcessFor( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->node_type() == AstNode::kForIn ||
                  iteration_stmt->node_type() == AstNode::kForInWithVar ||
                  iteration_stmt->node_type() == AstNode::kForEach ||
                  iteration_stmt->node_type() == AstNode::kForEachWithVar ) {
        ProcessForIn( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->node_type() == AstNode::kWhile ) {
        ProcessWhile( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->node_type() == AstNode::kDoWhile ) {
        ProcessDoWhile( iteration_stmt->CastToStatement()->CastToIteration() , size , count );
      } else if ( iteration_stmt->node_type() == AstNode::kIFStmt ) {
        if ( if_escape_mark == 0 ) {
          if_escape_mark = ManagedHandle::Retain<YieldMark>();
        }
        if_escape_mark = ProcessIFStmt( iteration_stmt->CastToStatement()->CastToIFStmt() , if_escape_mark , size , count );
      } else if ( iteration_stmt->node_type() == AstNode::kSwitchStmt ) {
        ProcessSwitchStmt( iteration_stmt->CastToStatement()->CastToSwitchStmt() , size , count );
      }
      count++;
      ++begin;
    }
    NodeIterator iterator = function_->ChildNodes();
  }


  YieldMark* ProcessIFStmt( IFStmt* node , YieldMark* escape_mark , int size , int count ) {
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
      Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
      Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
      BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
      break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
      exp_stmt->line_number( function_->line_number() );
      then_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
      normal_mark->ReEntrantNode( dynamic_state );
    }

    {
      YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
      Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
      Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
      BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
      break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
      exp_stmt->line_number( function_->line_number() );
      else_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
      abnormal_mark->ReEntrantNode( dynamic_state );
    }
    
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , then_block , else_block );
    if_stmt->line_number( node->line_number() );
    parent->InsertBefore( if_stmt , mark );
    if_stmt->SetYieldFlag();
    
    AstNode* last;
    if ( then_body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = then_body->first_child()->ChildNodes();
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
      Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
      Literal* dynamic_state = 0;
      if ( escape_mark->ReEntrantNode() == 0 ) {
        dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
        escape_mark->ReEntrantNode( dynamic_state );
      } else {
        dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
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
      if ( else_body->node_type() == AstNode::kBlockStmt ) {
        NodeIterator iterator = else_body->first_child()->ChildNodes();
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
      if ( else_body->node_type() != AstNode::kIFStmt ) {
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


  void ProcessSwitchStmt( SwitchStmt* node , int size , int count ) {
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    AstNode* parent = node->ParentNode();
    parent->InsertAfter( mark , node );
    NodeIterator iterator = node->first_child()->ChildNodes();
    AstNode* last = 0;
    while ( iterator.HasNext() ) {
      AstNode* item = iterator.Next();
      if ( !item->first_child()->IsEmpty() ) {
        bool has_break = false;
        bool has_child = false;
        NodeIterator inner = item->first_child()->ChildNodes();
        item->RemoveAllChild();
        while ( inner.HasNext() ) {
          AstNode *statement = inner.Next();
          if ( statement->node_type() != AstNode::kBreakStmt ) {
            if ( statement->node_type() == AstNode::kReturnStmt ) {
              has_break = true;
            }
            if ( statement->node_type() == AstNode::kBlockStmt ) {
              NodeIterator block_iterator = statement->first_child()->ChildNodes();
              while ( block_iterator.HasNext() ) {
                AstNode* item = block_iterator.Next();
                if ( item->node_type() != AstNode::kBreakStmt ) {
                  if ( item->node_type() == AstNode::kReturnStmt ) {
                    has_break = true;
                  }
                  if ( !last ) {
                    parent->InsertBefore( item , mark );
                    last = item;
                    has_child = true;
                  } else {
                    parent->InsertAfter( item , last );
                    last = item;
                    has_child = true;
                  }
                } else {
                  has_break = true;
                }
              }
            } else {
              if ( !last ) {
                parent->InsertBefore( statement , mark );
                last = statement;
                has_child = true;
              } else {
                parent->InsertAfter( statement , last );
                last = statement;
                has_child = true;
              }
            }
          } else {
            has_break = true;
          }
        }
        Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                     Token::JS_IDENTIFIER , item->line_number() , Literal::kIdentifier );
        Literal* zero = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , node->line_number() , Literal::kNumeric );
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , zero );
        ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
        BreakStmt* stmt = ManagedHandle::Retain<BreakStmt>();
        stmt->AddChild( ManagedHandle::Retain<Empty>() );
        NodeList* list = AstUtils::CreateNodeList( 2 , exp_stmt , stmt );
        item->AddChild( list );
        YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
        state_mark->ReEntrantNode( zero );
        state_mark->SetNoStateInjection();
        if ( !has_child && has_break ) {
          BreakStmt* stmt = ManagedHandle::Retain<BreakStmt>();
          stmt->AddChild( ManagedHandle::Retain<Empty>() );
          stmt->SetYieldFlag();
          if ( last ) {
            parent->InsertAfter( stmt , last );
          } else {
            parent->InsertBefore( stmt , mark );
          }
        }
        if ( has_break ) {
          Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                       Token::JS_IDENTIFIER , item->line_number() , Literal::kIdentifier );
          Literal* cloned = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , node->line_number() , Literal::kNumeric );
          AssignmentExp* assign;
          if (  mark->ReEntrantNode() == 0 ) {
            assign = AstUtils::CreateAssignment( '=' , state , cloned );
            mark->ReEntrantNode( cloned );
          } else {
            cloned->Symbol( mark->ReEntrantNode()->Symbol() );
            assign = AstUtils::CreateAssignment( '=' , state , cloned );
          }
          ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
          if ( last ) {
            if ( has_child ) {
              parent->InsertBefore( exp_stmt , last );
            } else {
              parent->InsertAfter( exp_stmt , last );
            }
          } else {
            parent->InsertBefore( exp_stmt , mark );
          }
        }
        if ( last ) {
          if ( has_child ) {
            parent->InsertBefore( state_mark , last );
          } else {
            parent->InsertAfter( state_mark , last );
          }
        } else {
          parent->InsertBefore( state_mark , mark );
        }
        
        if ( last ) {
          last->CastToStatement()->SetYieldFlag();
        }
      }
    }
    BreakStmt* stmt = ManagedHandle::Retain<BreakStmt>();
    stmt->AddChild( ManagedHandle::Retain<Empty>() );
    node->SetYieldFlag( false );
    stmt->SetYieldFlag( true );
    parent->InsertAfter( stmt , node );
    if ( !mark->ReEntrantNode() ) {
      parent->RemoveChild( mark );
    }
  }
  
  void ProcessDoWhile( IterationStmt* node , int size , int count ) {
    if ( node->PreviousSibling() ) {
      node->PreviousSibling()->CastToStatement()->SetYieldFlag();
    }
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* cond = node->Exp();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
    ExYieldStateNode* ex_node = ProcessDynamicState( cond );
    ex_node->line_number( node->line_number() );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( state_mark , mark );
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->first_child()->ChildNodes();
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
      parent->InsertBefore( body->first_child() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }

  
  void ProcessWhile( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* cond = node->Exp();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
    state_mark->SetAdjust( 1 );
    ExYieldStateNode* ex_node = ProcessDynamicState( cond );
    ex_node->line_number( node->line_number() );
    IFStmt* if_stmt = CreateEscapeState( cond , ex_node );
    if_stmt->line_number( node->line_number() );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( if_stmt , mark );
    parent->InsertBefore( state_mark , if_stmt );
    if_stmt->SetYieldFlag();
    
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->first_child()->ChildNodes();
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
      parent->InsertBefore( body->first_child() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }

  
  void ProcessFor( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->ParentNode();
    YieldMark* mark = ManagedHandle::Retain<YieldMark>();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->ParentNode()->RemoveChild( node );
    AstNode* exp = node->Exp();
    AstNode* cond = exp->first_child()->NextSibling();
    AstNode* counter = cond->NextSibling();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    if ( node->node_type() == AstNode::kForWithVar ) {
      if ( !exp->first_child()->IsEmpty() ) {
        VariableStmt* stmt = AstUtils::CreateVarStmt( exp->first_child()->CastToNodeList() );
        stmt->line_number( node->line_number() );
        parent->InsertBefore( stmt , mark );
      }
    }
    if ( !cond->IsEmpty() ) {
      YieldMark* state_mark = ManagedHandle::Retain<YieldMark>();
      state_mark->SetAdjust( 1 );
      ExYieldStateNode* ex_node = ProcessDynamicState( cond );
      ex_node->line_number( node->line_number() );
      IFStmt* if_stmt = CreateEscapeState( cond , ex_node );
      if_stmt->line_number( node->line_number() );
      state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
      parent->InsertAfter( ex_node , mark );
      parent->InsertBefore( if_stmt , mark );
      parent->InsertBefore( state_mark , if_stmt );
      if_stmt->SetYieldFlag();
    }
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( counter );
    parent->InsertAfter( stmt , mark );
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->first_child()->ChildNodes();
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
      parent->InsertBefore( body->first_child() , mark );
    }
    mark->ParentNode()->RemoveChild( mark );
  }


  void ProcessForIn( IterationStmt* node , int size , int count ) {
    AstNode* exp = node->Exp();
    VisitorInfo* visitor_info = info_->visitor_info();
    Literal* tmp_node = AstUtils::CreateTmpNode( visitor_info->tmp_index() );
    tmp_node->ValueType( Literal::kVariable );
    tmp_node->AddChild( ManagedHandle::Retain<Empty>() );
    AstNode* index_exp = exp->first_child();
    AstNode* target_exp = index_exp->NextSibling();
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForInWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->line_number( node->line_number() );
    list->AddChild( tmp_node );
    list->AddChild( target_exp );
    iter->Exp( list );
    Literal* array_lhs = AstUtils::CreateTmpNode( visitor_info->tmp_index() );
    Literal* array = ManagedHandle::Retain( new Literal( Literal::kArray ) );
    Literal* tmp_array = AstUtils::CreateVarInitiliser( array_lhs->Symbol() , array );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( tmp_array );
    function_->InsertBefore( var_stmt );
    Literal* push = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kPush ),
                                                Token::JS_PROPERTY , 0 , Literal::kProperty );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    Literal* name = tmp_node->Clone()->CastToLiteral();
    name->ValueType( Literal::kIdentifier );
    arg->AddChild( name );
    CallExp* push_call = AstUtils::CreateNormalAccessor( push , arg );
    CallExp* push_accessor = AstUtils::CreateDotAccessor( array_lhs->Clone() , push_call );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( push_accessor );
    stmt->line_number( function_->line_number() );
    iter->AddChild( stmt );
    node->ParentNode()->InsertBefore( iter , node );
    TransformForIn( node , array_lhs->Clone()->CastToLiteral() , size , count );
  }


  void TransformForIn( IterationStmt* node , Literal* array , int size , int count ) {
    VisitorInfo* visitor_info = info_->visitor_info();
    AstNode* exp = node->Exp();
    AstNode* index_exp = exp->first_child();
    Literal* tmp_node = AstUtils::CreateTmpNode( visitor_info->tmp_index() );
    Literal* zero = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    Literal* index = AstUtils::CreateVarInitiliser( tmp_node->Symbol() , zero );
    Literal* length = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLength ),
                                                  Token::JS_PROPERTY , 0 , Literal::kProperty );
    CallExp* length_accessor = AstUtils::CreateDotAccessor( array , length );
    Literal* var_length = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLength ),
                                                  Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* len_cache = AstUtils::CreateVarInitiliser( var_length->Symbol() , length_accessor );
    NodeList* var_list = AstUtils::CreateNodeList( 2 , index , len_cache );
    function_->SetVariable( index );
    function_->SetVariable( len_cache );
    Literal* index_name = AstUtils::CreateNameNode( index->Symbol()->GetToken(),
                                                      Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* len_name = AstUtils::CreateNameNode( len_cache->Symbol()->GetToken(),
                                                    Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    CompareExp* cmp = ManagedHandle::Retain( new CompareExp( '<' , index_name , len_name ) );
    UnaryExp* unary = AstUtils::CreateUnaryExp( Token::JS_INCREMENT , index_name->Clone() );
    
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = AstUtils::CreateNodeList( 3 , var_list , cmp , unary );
    iter->line_number( node->line_number() );
    iter->Exp( list );
    AstNode* index_stmt;
    if ( index_exp->CastToLiteral()->ValueType() == Literal::kVariable ) {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() );
      index_exp->RemoveAllChild();
      index_exp->AddChild( accessor );
      index_stmt = AstUtils::CreateVarStmt( index_exp );
    } else {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , index_exp , accessor );
      index_stmt = AstUtils::CreateExpStmt( assign );
    }
    
    AstNode* maybeBlock = node->first_child();
    if ( maybeBlock->node_type() == AstNode::kBlockStmt ) {
      maybeBlock->first_child()->InsertBefore( index_stmt );
      iter->AddChild( maybeBlock );
    } else {
      BlockStmt* block = AstUtils::CreateBlockStmt( 2 , index_stmt , maybeBlock );
      iter->AddChild( block );
    }
    node->ParentNode()->ReplaceChild( node , iter );
    ProcessFor( iter , size , count );
  }
  

  IFStmt* CreateEscapeState( AstNode* cond , ExYieldStateNode *ex_node ) {
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
    Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign );
    exp_stmt->line_number( function_->line_number() );
    

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( cond );
    exp->Paren();
    UnaryExp *not_exp = AstUtils::CreateUnaryExp( '!' , exp );
    break_stmt->line_number( function_->line_number() );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    BlockStmt* if_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
    IFStmt *if_stmt = AstUtils::CreateIFStmt( not_exp , if_block , ManagedHandle::Retain<Empty>() );
    if_stmt->line_number( function_->line_number() );
    ex_node->EscapePtr( dynamic_state );
    return if_stmt;
  }

  ExpressionStmt* CreateStateAssignment( const char* state ) {
    Literal* state_node = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* state_val = AstUtils::CreateNameNode( state , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state_node , state_val );
    return AstUtils::CreateExpStmt( assign );
  }

  ExYieldStateNode* ProcessDynamicState( AstNode* cond ) {
    ExpressionStmt* exp_stmt = CreateStateAssignment( "0" );
    exp_stmt->line_number( function_->line_number() );
    
    ExpressionStmt* next_stmt = CreateStateAssignment( "0" );
    next_stmt->line_number( function_->line_number() );

    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->line_number( 0 );
    break_stmt->AddChild( ManagedHandle::Retain<Empty>() );
    
    BlockStmt* else_block = AstUtils::CreateBlockStmt( 1 , next_stmt );
    BlockStmt* if_block = AstUtils::CreateBlockStmt( 2 , exp_stmt , break_stmt );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , if_block , else_block );
    if_stmt->line_number( function_->line_number() );
    ExYieldStateNode* ex_node = ManagedHandle::Retain<ExYieldStateNode>();
    ex_node->LoopBackPtr( exp_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->Right()->CastToLiteral() );
    ex_node->NextPtr( next_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->Right()->CastToLiteral() );
    ex_node->IfStmtPtr( if_stmt );
    return ex_node;
  }
  
  
  CaseClause* CreateCaseClause( long line , bool is_error = false ) {
    clause_ = ManagedHandle::Retain<CaseClause>();
    clause_body_ = ManagedHandle::Retain<StatementList>();
    clause_->AddChild( clause_body_ );
    clause_->line_number( function_->line_number() );
    if ( !is_error ) {
      Literal* state = CreateCurrentState( line );
      clause_->Exp( state );
    } else {
      Literal* error = AstUtils::CreateNameNode( "-1" , Token::JS_IDENTIFIER , 0 , Literal::kNumeric );
      clause_->Exp( error );
    }
    return clause_;
  }

  Literal* CreateCurrentState( long line ) {
    char tmp_state_exp[10];
    sprintf( tmp_state_exp , "%d" , state_ );
    Literal* state_exp = AstUtils::CreateNameNode( tmp_state_exp , Token::JS_NUMERIC_LITERAL,
                                                     line , Literal::kNumeric );
    return state_exp;
  }

  ExpressionStmt* CreateNextState( long line ) {
    Literal* yield_state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                       Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    char tmp_state_str[10];
    sprintf( tmp_state_str , "%d" , state_ + 1 );
    Literal* state = AstUtils::CreateNameNode( tmp_state_str , Token::JS_NUMERIC_LITERAL,
                                                 line , Literal::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , yield_state->Clone() , state );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
    stmt->line_number( line );
    return stmt;
  }

  void SetState( long line ) {
    if ( is_state_injection_ ) {
      if ( !iterator_.HasNext() ) {
        state_ = -2;
        clause_body_->InsertBefore( CreateNextState( line ) );
      } else {
        clause_body_->InsertBefore( CreateNextState( line ) );
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
  
  void ProcessStmtInYield( AstNode* yield_stmt ) {
    function_->RemoveChild( yield_stmt );
    if ( yield_stmt->node_type() == AstNode::kReturnStmt && !no_state_injection_ ) {
      is_state_injection_ = true;
    }
    if ( yield_stmt->node_type() == AstNode::kYieldMark ) {
      YieldMark* yield_mark = yield_stmt->CastToStatement()->CastToYieldMark();
      if ( yield_mark->GetNoStateInjection() ) {
        no_state_injection_ = true;
        is_state_injection_ = false;
      }
      char state[10];
      int state_num = ( iterator_.HasNext() )? yield_mark->Adjust( state_ ) : -1;
      sprintf( state , "%d" , state_num );
      yield_mark->ReEntrantNode()->Symbol()->SetToken( state );
      //mark_list_.push_back( yield_stmt->CastToStatement()->CastToYieldMark() );
    } else if ( yield_stmt->node_type() == AstNode::kExYieldStateNode ) {
      ExYieldStateNode* ex_node = yield_stmt->CastToStatement()->CastToYieldState();
      char back[10];
      sprintf( back ,"%d" , ( state_ - 1 ) );
      char next[10];
      int next_state;
      Literal* esc = ex_node->EscapePtr();
      SetState( yield_stmt->line_number() );
      sprintf( next ,"%d" , ( ( state_ < 0 )? -1 : state_ ) );
      if ( esc ) {
        esc->Symbol()->SetToken( next );
      }
      ex_node->NextPtr()->Symbol()->SetToken( next );
      clause_body_->AddChild( ex_node->IfStmtPtr() );
      is_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause( function_->line_number() );
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
      SetState( yield_stmt->line_number() );
      clause_body_->AddChild( yield_stmt );
      is_state_injection_ = false;
      no_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause( function_->line_number() );
      }
    } else {
      clause_body_->AddChild( yield_stmt );
    }
  }
  
  int state_;
  bool is_state_injection_;
  bool no_state_injection_;
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
      function( function ) , body( body ) , switch_stmt( ManagedHandle::Retain<SwitchStmt>() ),
      info( info ) {}
  
  void ProcessGenerator() {
    Literal* yield_state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                       Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    switch_stmt_->line_number( function_->line_number() );
    switch_stmt_->Exp( yield_state );
    switch_stmt_->AddChild( body_ );
    ProcessReturn();
  }
  
 private :

  void CreateStateLoop( Function* fn ) {
    NodeList *generator_arg = ManagedHandle::Retain<NodeList>();
    Literal* one_exp = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    Literal* is_send = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSendFlag ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* is_safe = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSafeFlag ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
    stmt_list->AddChild( switch_stmt_ );
    BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
    block->AddChild( stmt_list );
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( one_exp );
    iter->line_number( function_->line_number() );
    iter->Exp( exp );
    iter->AddChild( block );
    generator_arg->AddChild( is_send );
    generator_arg->AddChild( is_safe );
    fn->Argv( generator_arg );
    if ( function_->GetTryCatch().size() > 0 ) {
      TryStmt* stmt = ManagedHandle::Retain<TryStmt>();
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      stmt->Catch( CreateCatchHandler() );
      stmt->Finally( CreateFinallyHandler() );
      AstNode* node = iter->first_child()->first_child();
      iter->RemoveAllChild();
      block->AddChild( node );
      stmt->AddChild( block );
      iter->AddChild( stmt );
    }
    fn->AddChild( iter );
  }


  BlockStmt* CreateExceptionReturnValueCheckStmt_ ( CallExp* call_handler ) {
    Literal* cache = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() );
    AstNode* return_value = cache->Clone();
    cache->ValueType( Literal::kVariable );
    cache->AddChild( call_handler );
    VariableStmt* value_stmt = AstUtils::CreateVarStmt( cache );
    ReturnStmt* return_value_stmt = AstUtils::CreateReturnStmt( return_value );
    BlockStmt* blk = AstUtils::CreateBlockStmt( 1 , return_value_stmt );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ) , Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    CompareExp* is_defined = ManagedHandle::Retain( new CompareExp( Token::JS_NOT_EQ , return_value->Clone() , undefined ) );
    IFStmt* is_return = AstUtils::CreateIFStmt( is_defined , blk , ManagedHandle::Retain<Empty>() );
    BlockStmt* check_return = AstUtils::CreateBlockStmt( 2 , value_stmt , is_return );
    return check_return;
  }
  
  Literal* CreateCatchHandler() {
    Literal* catches = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kException ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    BlockStmt* catch_block = ManagedHandle::Retain<BlockStmt>();
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCatchCache ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* args = ManagedHandle::Retain<NodeList>();
    args->AddChild( catches->Clone() );
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args );

    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt( call_handler );
    
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    Literal* thrower = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThrowException ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
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

  AstNode* CreateFinallyHandler() {
    BlockStmt* finally_block = ManagedHandle::Retain<BlockStmt>();
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* args = ManagedHandle::Retain<NodeList>();
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args );
    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt( call_handler );
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    if_stmt->Exp( handler->Clone() );
    if_stmt->Then( check_return );
    if_stmt->Else( ManagedHandle::Retain<Empty>() );
    StatementList *finally_stmt_list = ManagedHandle::Retain<StatementList>();
    finally_stmt_list->AddChild( if_stmt );
    finally_block->AddChild( finally_stmt_list );
    return finally_block;
  }
  
  IFStmt* CreateNewBornCheckStmt() {
    IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
    Literal* is_send = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSendFlag ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* is_new_born = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kIsNewBorn ),
                                                       Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* false_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFalse ),
                                                    Token::JS_IDENTIFIER, function_->line_number(),
                                                    Literal::kIdentifier , Literal::kIdentifier );
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
    Literal* arguments = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kArguments ),
                                                     Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* one = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    CallExp* array_accessor = AstUtils::CreateArrayAccessor( arguments , one );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                     Token::JS_NUMERIC_LITERAL, function_->line_number(),
                                                     Literal::kIdentifier );
    CompareExp* undef_check = ManagedHandle::Retain( new CompareExp( Token::JS_NOT_EQ , array_accessor , undefined ) );
    CompareExp* comp = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , is_send->Clone() , is_new_born ) );
    CompareExp* comp2 = ManagedHandle::Retain( new CompareExp( Token::JS_LOGICAL_AND , comp , undef_check ) );
    BlockStmt* else_block = ManagedHandle::Retain<BlockStmt>();
    StatementList* else_list = ManagedHandle::Retain<StatementList>();
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kExceptionHandler ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* message = AstUtils::CreateNameNode( "'attempt to send to newborn generator.'" , Token::JS_STRING_LITERAL , function_->line_number() , Literal::kString );
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

  Literal* ObjectInitialiser( Literal* generator , bool is_send ) {
    Literal* name;
    Literal* boolean;
    if ( !is_send ) {
      name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldNext ),
                                                  Token::JS_PROPERTY , function_->line_number(),
                                                  Literal::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kTrue ),
                                                    Token::JS_IDENTIFIER , function_->line_number(),
                                                    Literal::kIdentifier );
    } else {
      name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSend ),
                                                  Token::JS_PROPERTY , function_->line_number(),
                                                  Literal::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFalse ),
                                                       Token::JS_IDENTIFIER , function_->line_number(),
                                                       Literal::kIdentifier );
    }
    Literal* bind_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kBind ),
                                                    Token::JS_PROPERTY , function_->line_number(),
                                                    Literal::kProperty );
    Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , function_->line_number(),
                                                    Literal::kIdentifier );
    
    CallExp* dot = AstUtils::CreateDotAccessor( generator->Clone() , bind_sym );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    arg->AddChild( this_sym );
    arg->AddChild( boolean );
    CallExp* call = AstUtils::CreateNormalAccessor( dot , arg );
    name->AddChild( call );
    return name;
  }

  Function* CloseInitialiser() {
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* error_state = AstUtils::CreateNameNode( "-1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , error_state );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
    Function* close_fn = ManagedHandle::Retain<Function>();
    close_fn->Name( ManagedHandle::Retain<Empty>() );
    close_fn->Argv( ManagedHandle::Retain<NodeList>() );
    close_fn->AddChild( stmt );
    if ( function_->GetTryCatch().size() > 0 ) {
      Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                                  Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
      CallExp* exp = AstUtils::CreateNormalAccessor( name , ManagedHandle::Retain<NodeList>() );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
      IFStmt* if_stmt = AstUtils::CreateIFStmt( name->Clone() , stmt , ManagedHandle::Retain<Empty>() );
      close_fn->AddChild( if_stmt );
    }
    return close_fn;
  }
  
  void GeneratorInitialiser( Function* fn ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    CreateStateLoop( fn );
    fn->InsertBefore( CreateNewBornCheckStmt() );
    Literal* generator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGenerator ),
                                                     Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier , true );
    Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* generator_init = AstUtils::CreateVarInitiliser( generator->Symbol() , fn );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( generator_init );
    function_->AddChild( var_stmt );
    Literal* create_generator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateGenerator ),
                                                            Token::JS_PROPERTY , function_->line_number() , Literal::kIdentifier );
    NodeList* args = AstUtils::CreateNodeList( 3 , generator->Clone() , CloseInitialiser() , this_sym );
    CallExp* create_generator_call = AstUtils::CreateNormalAccessor( create_generator , args );
    CallExp* runtime = AstUtils::CreateRuntimeMod( create_generator_call );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( runtime );
    function_->AddChild( ret );
  }
  
  void ProcessReturn() {
    Function* fn = ManagedHandle::Retain<Function>();
    fn->Name( ManagedHandle::Retain<Empty>() );
    GeneratorInitialiser( fn );
  }
  
  Function* function_;
  NodeList* body_;
  SwitchStmt *switch_stmt_;
  ProcessorInfo* info_;
  
};


void FunctionProcessor::ProcessYield() {
  YieldHelper helper( function_ , info_ );
  helper.ProcessYield();
  NodeList* body = helper.GetBody();
  GeneratorHelper ge_helper( function_ , body , info_ );
  ge_helper.ProcessGenerator();
}

}
