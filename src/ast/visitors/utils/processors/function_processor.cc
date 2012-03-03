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
    function_( function ) , info_( info ), formal_parameter_( function->argv() ),
    default_parameter_( NodeList::New() ) {
  argc_ = formal_parameter_->child_length();
}

FunctionProcessor::~FunctionProcessor() {}

void FunctionProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->visitor_info();
  Statement* tmp_statement = Statement::New();
  visitor_info->set_current_statement( tmp_statement );
  visitor_info->set_function( function_ );
  ProcessFormalParameter();
  bool is_rest = visitor_info->rest_injection();
  visitor_info->set_rest_injection( false );
  VariableStmt* dsta_stmt = 0;
  VariableStmt* rest_stmt = 0;
  if ( tmp_statement->IsContainDestructuring() ) {
    NodeList *list = DstaProcessor::CreateDstaExtractedVarStmt( tmp_statement , info_ );
    VariableDeclarationList* decl_list = VariableDeclarationList::New( function_->line_number() );
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
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( iterator.Next() , function_->line_number() );
      function_->InsertBefore( stmt );
    }
  }
}

bool IsDestructuring( AstNode* node ) {
  if ( node->node_type() == AstNode::kArrayLikeLiteral || node->node_type() == AstNode::kObjectLikeLiteral ) {
    return true;
  } else {
    if ( node->node_type() == AstNode::kAssignmentExp ) {
      return AstUtils::IsDestructringLeftHandSide( node->CastToExpression()->CastToAssigment()->left_value() );
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
        Literal* value = DstaProcessor::ProcessNode( node , info_ );
        if ( has_default_parameter ) {
          AstNode* arg = value->Clone();
          AssignmentExp* assign = AssignmentExp::New( '=' , arg , maybe_initialiser->right_value()->Clone() , function_->line_number() );
          value->parent_node()->ReplaceChild( value , assign );
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
  CompareExp* logical_or = CompareExp::New( Token::JS_LOGICAL_OR , arg , default_value , function_->line_number() );
  AssignmentExp* exp = AstUtils::CreateAssignment( '=', initialiser , logical_or , value->line_number() );
  default_parameter_->InsertBefore( exp );
}


void FunctionProcessor::ProcessDefaultParameter( AssignmentExp *exp ) {
  Literal* arg = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , function_->line_number() );
  exp->parent_node()->ReplaceChild( exp , arg );
  CompareExp* logical_or = CompareExp::New( Token::JS_LOGICAL_OR , arg->Clone() , exp->right_value() , function_->line_number() );
  AssignmentExp* ret = AstUtils::CreateAssignment( '=', exp->left_value()->Clone() , logical_or , function_->line_number() );
  default_parameter_->InsertBefore( ret );
  ret->Accept( info_->visitor() );
}


void FunctionProcessor::ProcessPropertyParameter( CallExp *exp ) {
  Literal* arg = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , function_->line_number() );
  exp->parent_node()->ReplaceChild( exp , arg );
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
      Literal* initialiser = AstUtils::CreateVarInitiliser( tmp_name->value() , this_sym , function_->line_number() );
      AstNode* statement = function_->parent_node();
      while ( !statement->CastToStatement() &&
              statement->node_type() != AstNode::kFileRoot ||
              statement->node_type() != AstNode::kCase ) {
        if ( statement->HasParent() ) {
          statement = statement->parent_node();
        } else {
          break;
        }
      }
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarDeclList( function_->line_number() , 1 , initialiser ) , function_->line_number() );
      statement->InsertBefore( var_stmt , function_ );
      function_->set_replaced_this( tmp_name );
    } else {
      Statement* mark = Statement::New();
      Literal* bind_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kBind ),
                                                    Token::JS_IDENTIFIER , function_->line_number() , Literal::kProperty );
      Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
      NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
      CallExp* bind_call = AstUtils::CreateNormalAccessor( bind_sym , arg , function_->line_number() );
      AstNode* parent = function_->parent_node();
      parent->ReplaceChild( function_ , mark );
      CallExp* binding_function = AstUtils::CreateDotAccessor( function_ , bind_call , function_->line_number() );
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
  VariableDeclarationList* decl_list = VariableDeclarationList::New( function_->line_number() );
  decl_list->AddChild( var_node );
  return AstUtils::CreateVarStmt( decl_list , function_->line_number() );
}


class YieldHelper : private Uncopyable {
 public :
  YieldHelper( Function* function , ProcessorInfo* info ) :
      state_( 0 ), is_state_injection_( false ), no_state_injection_( false ),
      function_( function ) , info_( info ),
      clause_( CreateCaseClause( state_ ) ),
      body_( NodeList::New() ){}

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
      mark->ReEntrantNode()->value()->set_token( state );
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
    Empty* empty = Empty::New();
    CallExp* exp = AstUtils::CreateNormalAccessor( handler , empty , function_->line_number() );
    CallExp* runtime = AstUtils::CreateRuntimeMod( exp , function_->line_number() );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime , function_->line_number() );
    Literal* is_safe = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSafeFlag ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( undefined , function_->line_number() );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( is_safe , ret , stmt , function_->line_number() );
    CreateCaseClause( 0 , true );
    clause_->AddChild( if_stmt );
    body_->AddChild( clause_ );
  }

  VariableStmt* CreateClearCacheStmt( const char* symbol ) {
    Literal* cache = AstUtils::CreateNameNode( symbol , Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* clear_cache = AstUtils::CreateVarInitiliser( cache->value() , undefined , function_->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( function_->line_number() , 1 , clear_cache );
    VariableStmt* clear_cache_stmt = AstUtils::CreateVarStmt( decl_list , function_->line_number() );
    function_->set_variable_list( clear_cache );
    return clear_cache_stmt;
  }
  
  void ProcessTryCatch() {
    const Function::TryCatchList &list = function_->try_catch_list();
    if ( list.size() > 0 ) {
      Function::TryCatchList::const_iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        TryStmt* stmt = (*begin);
        bool has_finally = ( !stmt->finally_block()->IsEmpty() );
        ExpressionStmt* catch_stmt = ProcessCatch( stmt );
        VariableStmt* clear_catch_stmt = CreateClearCacheStmt( SymbolList::symbol( SymbolList::kCatchCache ) );
        ExpressionStmt* finally_stmt = 0;
        VariableStmt* clear_finally_stmt = 0;
        if ( has_finally ) {
          finally_stmt = ProcessFinally( stmt );
          clear_finally_stmt = CreateClearCacheStmt( SymbolList::symbol( SymbolList::kFinallyCache ) );
          clear_finally_stmt->MarkAsSplitableStatement();
        } else {
          clear_catch_stmt->MarkAsSplitableStatement();
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
    NodeIterator iterator = stmt->first_child()->ChildNodes();
    AstNode* last = 0;
    AstNode* first = 0;
    while ( iterator.HasNext() ) {
      if ( !last ) {
        first = last = iterator.Next();
        stmt->parent_node()->InsertBefore( last , stmt );
      } else {
        AstNode* item = iterator.Next();
        stmt->parent_node()->InsertAfter( item , last );
        last = item;
      }
    }
    stmt->parent_node()->InsertAfter( clear_catch_stmt , stmt );
    stmt->parent_node()->InsertBefore( catch_stmt , ( first )? first : stmt );
    if ( has_finally ) {
      stmt->parent_node()->InsertAfter( clear_finally_stmt , clear_catch_stmt );
      stmt->parent_node()->InsertAfter( finally_stmt , catch_stmt );
    }
    stmt->parent_node()->RemoveChild( stmt );
  }
  
  ExpressionStmt* ProcessFinally( TryStmt* stmt ) {
    AstNode* block = stmt->finally_block();
    NodeList* arg = NodeList::New();
    AstNode* block_body = block->first_child();
    Function* fn = AstUtils::CreateFunctionDecl( Empty::New() , arg , block_body , stmt->line_number() );
    Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                              Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn , stmt->line_number() );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign , stmt->line_number() );
    return ret;
  }

  ExpressionStmt* ProcessCatch( TryStmt* stmt ) {
    Literal* block = stmt->catch_block()->CastToLiteral();
    NodeList* arg = NodeList::New();
    AstNode* block_body = block->first_child()->first_child();
    Literal* arg_name = block->Clone()->CastToLiteral();
    arg_name->RemoveAllChild();
    arg->AddChild( arg_name );
    Function* fn = AstUtils::CreateFunctionDecl( Empty::New() , arg , block_body , stmt->line_number() );
    Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCatchCache ),
                                              Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , name , fn , stmt->line_number() );
    YieldMark* mark = YieldMark::New();
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                               Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* pseudo_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , state , pseudo_state , stmt->line_number() );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( exp , stmt->line_number() );
    mark->ReEntrantNode( pseudo_state );
    fn->InsertBefore( exp_stmt );
    stmt->parent_node()->InsertAfter( mark , stmt );
    ExpressionStmt* ret = AstUtils::CreateExpStmt( assign , stmt->line_number() );
    return ret;
  }
  
  void ProcessVarDecl() {
    const Function::VariableList &list = function_->variable_list();
    if ( list.size() > 0 ) {
      TransformVarDecl( list );
      Function::VariableList::const_iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        Literal* value = (*begin);
        if ( value->parent_node() && value->parent_node()->parent_node() &&
             value->parent_node()->parent_node()->parent_node() ) {
          value->parent_node()->parent_node()->parent_node()->RemoveChild( value->parent_node()->parent_node() );
        }
        ++begin;
      }
    }
    function_->InsertBefore( CreateStateInitialiser() );
    function_->InsertBefore( CreateResultInitialiser() );
    function_->InsertBefore( CreateNewBornCheckFlag() );
  }

  void TransformVarDecl( const Function::VariableList& list ) {
    Function::VariableList::const_iterator begin = list.begin(),end = list.end();
    while ( begin != end ) {
      Literal* value = (*begin);
      Literal* ident = Literal::New( Literal::kIdentifier , function_->line_number() );
      ident->set_value( value->value() );
      ident->AddChild( Empty::New() );
      if ( !value->first_child()->IsEmpty() ) {
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , ident , value->first_child()->Clone() , value->line_number() );
        ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign , value->line_number() );
        fprintf( stderr , "%s %s\n" , value->value()->token() , info_->visitor_info()->filename() );
        if ( value->parent_node()->parent_node()->CastToStatement()->IsSplitable() ) {
          stmt->MarkAsSplitableStatement();
        }
        value->parent_node()->parent_node()->parent_node()->InsertBefore( stmt , value->parent_node()->parent_node() );
      }
      Literal* var = Literal::New( Literal::kVariable , value->line_number() );
      var->set_value( value->value() );
      var->AddChild( Empty::New() );
      VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( value->line_number() , 1 , var );
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( decl_list , value->line_number() );
      function_->InsertBefore( var_stmt );
      ++begin;
    }
  }

  VariableStmt* CreateStateInitialiser() {
    TokenInfo* state = TokenInfo::New( SymbolList::symbol( SymbolList::kYieldState ),
                                       Token::JS_IDENTIFIER , function_->line_number() );
    Literal* begin_state = AstUtils::CreateNameNode( "0" ,Token::JS_NUMERIC_LITERAL,
                                                     function_->line_number() , Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( state , begin_state , function_->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( function_->line_number() , 1 , value );
    return AstUtils::CreateVarStmt( decl_list , function_->line_number() );
  }

  VariableStmt* CreateResultInitialiser() {
    TokenInfo* result = TokenInfo::New( SymbolList::symbol( SymbolList::kYieldResult ),
                                        Token::JS_IDENTIFIER , function_->line_number() );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                   Token::JS_IDENTIFIER, function_->line_number(),
                                                   Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( result , undefined , function_->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( function_->line_number() , 1 , value );
    return AstUtils::CreateVarStmt( decl_list , value->line_number() );
  }


  VariableStmt* CreateNewBornCheckFlag() {
    TokenInfo* result = TokenInfo::New( SymbolList::symbol( SymbolList::kIsNewBorn ),
                                        Token::JS_IDENTIFIER , function_->line_number() );
    Literal* true_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kTrue ),
                                                  Token::JS_IDENTIFIER, function_->line_number(),
                                                  Literal::kIdentifier );
    Literal* value = AstUtils::CreateVarInitiliser( result , true_sym , function_->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( function_->line_number() , 1 , value );
    return AstUtils::CreateVarStmt( decl_list , function_->line_number() );
  }
  
  void ProcessIteration() {
    typedef Function::StmtList::const_reverse_iterator Iterator;
    Iterator begin = function_->statement_list().rbegin(),end = function_->statement_list().rend();
    int count = 0;
    int size = function_->statement_list().size();
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
          if_escape_mark = YieldMark::New();
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
    AstNode* parent = node->parent_node();
    YieldMark* mark = YieldMark::New();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->parent_node()->RemoveChild( node );
    AstNode* cond = node->condition();
    AstNode* then_body = node->then_statement();
    AstNode* else_body = node->else_statement();
    AstNode* current = 0;//init after.
    BlockStmt* then_block;
    BlockStmt* else_block;
    
    YieldMark* normal_mark = YieldMark::New();
    YieldMark* abnormal_mark = YieldMark::New();
    {
      Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
      Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state , node->line_number() );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
      BreakStmt *break_stmt = BreakStmt::New( node->line_number() );
      break_stmt->AddChild( Empty::New() );
      then_block = AstUtils::CreateBlockStmt( node->line_number() , 2 , exp_stmt , break_stmt );
      normal_mark->ReEntrantNode( dynamic_state );
    }

    {
      YieldMark* state_mark = YieldMark::New();
      Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                 Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
      Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state , node->line_number() );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
      BreakStmt *break_stmt = BreakStmt::New( node->line_number());
      break_stmt->AddChild( Empty::New() );
      else_block = AstUtils::CreateBlockStmt( node->line_number() , 2 , exp_stmt , break_stmt );
      abnormal_mark->ReEntrantNode( dynamic_state );
    }
    
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , then_block , else_block , node->line_number() );
    parent->InsertBefore( if_stmt , mark );
    if_stmt->MarkAsSplitableStatement();
    
    AstNode* last;
    if ( then_body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = then_body->ChildNodes();
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
    last->parent_node()->InsertBefore( normal_mark , last );
    last->CastToStatement()->MarkAsSplitableStatement();
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
        dynamic_state->set_value( escape_mark->ReEntrantNode()->value() );
      }
      
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state , node->line_number() );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
      last->parent_node()->InsertAfter( exp_stmt , last );
      BreakStmt *break_stmt = BreakStmt::New( node->line_number() );
      break_stmt->AddChild( Empty::New() );
      last->parent_node()->InsertAfter( break_stmt , exp_stmt );
      break_stmt->MarkAsSplitableStatement();
      embed_ptr = current = break_stmt;
    }

    if ( !else_body->IsEmpty() ) {
      if ( else_body->node_type() == AstNode::kBlockStmt ) {
        NodeIterator iterator = else_body->ChildNodes();
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
      last->parent_node()->InsertBefore( abnormal_mark , last );
      if ( else_body->node_type() != AstNode::kIFStmt ) {
        last->parent_node()->InsertAfter( escape_mark , last );
        escape_mark = 0;
      }
    } else {
      last->parent_node()->InsertAfter( abnormal_mark , last );
      last->parent_node()->InsertAfter( escape_mark , abnormal_mark );
      escape_mark->SetAdjust( 1 );
      escape_mark = 0;
    }
    
    if ( !last->IsEmpty() ) {
      printf( "%s\n" , last->name() );
      last->CastToStatement()->MarkAsSplitableStatement();
    }
    
    mark->parent_node()->RemoveChild( mark );
    return escape_mark;
  }


  void ProcessSwitchStmt( SwitchStmt* node , int size , int count ) {
    YieldMark* mark = YieldMark::New();
    AstNode* parent = node->parent_node();
    parent->InsertAfter( mark , node );
    NodeIterator iterator = node->ChildNodes();
    AstNode* last = 0;
    while ( iterator.HasNext() ) {
      AstNode* item = iterator.Next();
      if ( !item->first_child()->IsEmpty() ) {
        bool has_break = false;
        bool has_child = false;
        NodeIterator inner = item->ChildNodes();
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
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , zero , node->line_number() );
        ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
        BreakStmt* stmt = BreakStmt::New( item->line_number() );
        stmt->AddChild( Empty::New() );
        NodeList* list = AstUtils::CreateNodeList( 2 , exp_stmt , stmt );
        item->AddChild( list );
        YieldMark* state_mark = YieldMark::New();
        state_mark->ReEntrantNode( zero );
        state_mark->SetNoStateInjection();
        if ( !has_child && has_break ) {
          BreakStmt* stmt = BreakStmt::New( item->line_number() );
          stmt->AddChild( Empty::New() );
          stmt->MarkAsSplitableStatement();
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
            assign = AstUtils::CreateAssignment( '=' , state , cloned , node->line_number() );
            mark->ReEntrantNode( cloned );
          } else {
            cloned->set_value( mark->ReEntrantNode()->value() );
            assign = AstUtils::CreateAssignment( '=' , state , cloned , node->line_number() );
          }
          ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
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
          last->CastToStatement()->MarkAsSplitableStatement();
        }
      }
    }
    BreakStmt* stmt = BreakStmt::New( node->line_number() );
    stmt->AddChild( Empty::New() );
    stmt->MarkAsSplitableStatement();
    parent->InsertAfter( stmt , node );
    if ( !mark->ReEntrantNode() ) {
      parent->RemoveChild( mark );
    }
  }
  
  void ProcessDoWhile( IterationStmt* node , int size , int count ) {
    if ( node->previous_sibling() ) {
      node->previous_sibling()->CastToStatement()->MarkAsSplitableStatement();
    }
    AstNode* parent = node->parent_node();
    YieldMark* mark = YieldMark::New();
    parent->InsertBefore( mark , node );
    node->parent_node()->RemoveChild( node );
    AstNode* cond = node->expression();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = YieldMark::New();
    ExYieldStateNode* ex_node = ProcessDynamicState( cond );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( state_mark , mark );
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->ChildNodes();
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
    mark->parent_node()->RemoveChild( mark );
  }

  
  void ProcessWhile( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->parent_node();
    YieldMark* mark = YieldMark::New();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->parent_node()->RemoveChild( node );
    AstNode* cond = node->expression();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    
    YieldMark* state_mark = YieldMark::New();
    state_mark->SetAdjust( 1 );
    ExYieldStateNode* ex_node = ProcessDynamicState( cond );
    IFStmt* if_stmt = CreateEscapeState( cond , ex_node );
    state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
    parent->InsertAfter( ex_node , mark );
    parent->InsertBefore( if_stmt , mark );
    parent->InsertBefore( state_mark , if_stmt );
    if_stmt->MarkAsSplitableStatement();
    
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->ChildNodes();
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
    mark->parent_node()->RemoveChild( mark );
  }

  
  void ProcessFor( IterationStmt* node , int size , int count ) {
    AstNode* parent = node->parent_node();
    YieldMark* mark = YieldMark::New();
    mark->SetAdjust( 1 );
    parent->InsertBefore( mark , node );
    node->parent_node()->RemoveChild( node );
    AstNode* exp = node->expression();
    AstNode* cond = exp->first_child()->next_sibling();
    AstNode* counter = cond->next_sibling();
    AstNode* body = node->first_child();
    AstNode* current = 0;//init after.
    if ( node->node_type() == AstNode::kForWithVar ) {
      if ( !exp->first_child()->IsEmpty() ) {
        VariableDeclarationList* decl_list = VariableDeclarationList::New( node->line_number() );
        decl_list->Append( exp->first_child() );
        VariableStmt* stmt = AstUtils::CreateVarStmt( decl_list , node->line_number() );
        parent->InsertBefore( stmt , mark );
      }
    }
    if ( !cond->IsEmpty() ) {
      YieldMark* state_mark = YieldMark::New();
      state_mark->SetAdjust( 1 );
      ExYieldStateNode* ex_node = ProcessDynamicState( cond );
      IFStmt* if_stmt = CreateEscapeState( cond , ex_node );
      state_mark->ReEntrantNode( ex_node->LoopBackPtr() );
      parent->InsertAfter( ex_node , mark );
      parent->InsertBefore( if_stmt , mark );
      parent->InsertBefore( state_mark , if_stmt );
      if_stmt->MarkAsSplitableStatement();
    }
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( counter , node->line_number() );
    parent->InsertAfter( stmt , mark );
    if ( body->node_type() == AstNode::kBlockStmt ) {
      NodeIterator iterator = body->ChildNodes();
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
    mark->parent_node()->RemoveChild( mark );
  }


  void ProcessForIn( IterationStmt* node , int size , int count ) {
    AstNode* exp = node->expression();
    VisitorInfo* visitor_info = info_->visitor_info();
    Literal* tmp_node = AstUtils::CreateTmpNode( visitor_info->tmp_index() , node->line_number() );
    tmp_node->set_value_type( Literal::kVariable );
    tmp_node->AddChild( Empty::New() );
    AstNode* index_exp = exp->first_child();
    AstNode* target_exp = index_exp->next_sibling();
    IterationStmt* iter = IterationStmt::New( AstNode::kForInWithVar , node->line_number() );
    NodeList* list = NodeList::New();
    list->AddChild( tmp_node );
    list->AddChild( target_exp );
    iter->set_expression( list );
    Literal* array_lhs = AstUtils::CreateTmpNode( visitor_info->tmp_index() , node->line_number() );
    ArrayLikeLiteral* array = ArrayLikeLiteral::New( node->line_number() );
    Literal* tmp_array = AstUtils::CreateVarInitiliser( array_lhs->value() , array , node->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( node->line_number() , 1 , tmp_array );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( decl_list , node->line_number() );
    function_->InsertBefore( var_stmt );
    Literal* push = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kPush ),
                                              Token::JS_IDENTIFIER , 0 , Literal::kProperty );
    NodeList* arg = NodeList::New();
    Literal* name = tmp_node->Clone()->CastToLiteral();
    name->set_value_type( Literal::kIdentifier );
    arg->AddChild( name );
    CallExp* push_call = AstUtils::CreateNormalAccessor( push , arg , node->line_number() );
    CallExp* push_accessor = AstUtils::CreateDotAccessor( array_lhs->Clone() , push_call , node->line_number() );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( push_accessor , node->line_number() );
    iter->AddChild( stmt );
    node->parent_node()->InsertBefore( iter , node );
    TransformForIn( node , array_lhs->Clone()->CastToLiteral() , size , count );
  }


  void TransformForIn( IterationStmt* node , Literal* array , int size , int count ) {
    VisitorInfo* visitor_info = info_->visitor_info();
    AstNode* exp = node->expression();
    AstNode* index_exp = exp->first_child();
    Literal* tmp_node = AstUtils::CreateTmpNode( visitor_info->tmp_index() , node->line_number() );
    Literal* zero = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , node->line_number() , Literal::kNumeric );
    Literal* index = AstUtils::CreateVarInitiliser( tmp_node->value() , zero , node->line_number() );
    Literal* length = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLength ),
                                                Token::JS_IDENTIFIER , node->line_number() , Literal::kProperty );
    CallExp* length_accessor = AstUtils::CreateDotAccessor( array , length , node->line_number() );
    Literal* var_length = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kLength ),
                                                    Token::JS_IDENTIFIER , node->line_number() , Literal::kIdentifier );
    Literal* len_cache = AstUtils::CreateVarInitiliser( var_length->value() , length_accessor , node->line_number() );
    NodeList* var_list = AstUtils::CreateNodeList( 2 , index , len_cache );
    function_->set_variable_list( index );
    function_->set_variable_list( len_cache );
    Literal* index_name = AstUtils::CreateNameNode( index->value()->token(),
                                                    Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* len_name = AstUtils::CreateNameNode( len_cache->value()->token(),
                                                  Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    CompareExp* cmp = CompareExp::New( '<' , index_name , len_name , node->line_number() );
    UnaryExp* unary = AstUtils::CreateUnaryExp( Token::JS_INCREMENT , index_name->Clone() , node->line_number() );
    
    IterationStmt* iter = IterationStmt::New( AstNode::kForWithVar , node->line_number() );
    NodeList* list = AstUtils::CreateNodeList( 3 , var_list , cmp , unary );
    iter->set_expression( list );
    AstNode* index_stmt;
    if ( index_exp->CastToLiteral()->value_type() == Literal::kVariable ) {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() , node->line_number() );
      index_exp->RemoveAllChild();
      index_exp->AddChild( accessor );
      VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( node->line_number() , 1 , index_exp );
      index_stmt = AstUtils::CreateVarStmt( decl_list , node->line_number() );
    } else {
      CallExp* accessor = AstUtils::CreateArrayAccessor( array->Clone() , index_name->Clone() , node->line_number() );
      AssignmentExp* assign = AstUtils::CreateAssignment( '=' , index_exp , accessor , node->line_number() );
      index_stmt = AstUtils::CreateExpStmt( assign , node->line_number() );
    }
    
    AstNode* maybeBlock = node->first_child();
    if ( maybeBlock->node_type() == AstNode::kBlockStmt ) {
      maybeBlock->first_child()->InsertBefore( index_stmt );
      iter->Append( maybeBlock );
    } else {
      BlockStmt* block = AstUtils::CreateBlockStmt( node->line_number() , 2 , index_stmt , maybeBlock );
      iter->AddChild( block );
    }
    node->parent_node()->ReplaceChild( node , iter );
    ProcessFor( iter , size , count );
  }
  

  IFStmt* CreateEscapeState( AstNode* cond , ExYieldStateNode *ex_node ) {
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                               Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    
    Literal* dynamic_state = AstUtils::CreateNameNode( "0" , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , dynamic_state , cond->line_number() );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( assign , cond->line_number() );

    BreakStmt *break_stmt = BreakStmt::New( cond->line_number() );
    Expression *exp = Expression::New( cond->line_number() );
    exp->AddChild( cond );
    exp->MarkParenthesis();
    UnaryExp *not_exp = AstUtils::CreateUnaryExp( '!' , exp , cond->line_number() );
    break_stmt->AddChild( Empty::New() );
    
    BlockStmt* if_block = AstUtils::CreateBlockStmt( cond->line_number() , 2 , exp_stmt , break_stmt );
    IFStmt *if_stmt = AstUtils::CreateIFStmt( not_exp , if_block , Empty::New() , cond->line_number() );
    ex_node->EscapePtr( dynamic_state );
    return if_stmt;
  }

  ExpressionStmt* CreateStateAssignment( const char* state ) {
    Literal* state_node = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                    Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* state_val = AstUtils::CreateNameNode( state , Token::JS_NUMERIC_LITERAL , 0 , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state_node , state_val , 0 );
    return AstUtils::CreateExpStmt( assign , 0 );
  }

  ExYieldStateNode* ProcessDynamicState( AstNode* cond ) {
    ExpressionStmt* exp_stmt = CreateStateAssignment( "0" );
    ExpressionStmt* next_stmt = CreateStateAssignment( "0" );
    BreakStmt *break_stmt = BreakStmt::New( cond->line_number() );
    break_stmt->AddChild( Empty::New() );
    
    BlockStmt* else_block = AstUtils::CreateBlockStmt( cond->line_number() , 1 , next_stmt );
    BlockStmt* if_block = AstUtils::CreateBlockStmt( cond->line_number() , 2 , exp_stmt , break_stmt );
    IFStmt* if_stmt = AstUtils::CreateIFStmt( cond , if_block , else_block , cond->line_number() );
    ExYieldStateNode* ex_node = ExYieldStateNode::New();
    ex_node->LoopBackPtr( exp_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->right_value()->CastToLiteral() );
    ex_node->NextPtr( next_stmt->first_child()->first_child()->CastToExpression()->CastToAssigment()->right_value()->CastToLiteral() );
    ex_node->IfStmtPtr( if_stmt );
    return ex_node;
  }
  
  
  CaseClause* CreateCaseClause( long line , bool is_error = false ) {
    clause_ = CaseClause::New( line );
    if ( !is_error ) {
      Literal* state = CreateCurrentState( line );
      clause_->set_expression( state );
    } else {
      Literal* error = AstUtils::CreateNameNode( "-1" , Token::JS_IDENTIFIER , 0 , Literal::kNumeric );
      clause_->set_expression( error );
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

  ExpressionStmt* CreateNextState( int64_t line ) {
    Literal* yield_state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                     Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    char tmp_state_str[10];
    sprintf( tmp_state_str , "%d" , state_ + 1 );
    Literal* state = AstUtils::CreateNameNode( tmp_state_str , Token::JS_NUMERIC_LITERAL,
                                               line , Literal::kNumeric );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , yield_state->Clone() , state , line );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp , line );
    return stmt;
  }

  void SetState( int64_t line ) {
    if ( is_state_injection_ ) {
      if ( !iterator_.HasNext() ) {
        state_ = -2;
        clause_->InsertBefore( CreateNextState( line ) );
      } else {
        clause_->InsertBefore( CreateNextState( line ) );
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
      yield_mark->ReEntrantNode()->value()->set_token( state );
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
        esc->value()->set_token( next );
      }
      ex_node->NextPtr()->value()->set_token( next );
      clause_->AddChild( ex_node->IfStmtPtr() );
      is_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause( function_->line_number() );
      }
    } else if ( yield_stmt->CastToStatement() && yield_stmt->CastToStatement()->IsSplitable() ) {
      std::list<YieldMark*>::iterator begin = mark_list_.begin(),end = mark_list_.end();
      while ( begin != end ) {
        YieldMark* mark = (*begin);
        char state[10];
        int state_num = ( iterator_.HasNext() )? mark->Adjust( state_ ) : -1;
        sprintf( state , "%d" , state_num );
        mark->ReEntrantNode()->value()->set_token( state );
        ++begin;
      }
      mark_list_.clear();
      SetState( yield_stmt->line_number() );
      clause_->AddChild( yield_stmt );
      is_state_injection_ = false;
      no_state_injection_ = false;
      body_->AddChild( clause_ );
      if ( iterator_.HasNext() ) {
        CreateCaseClause( function_->line_number() );
      }
    } else {
      clause_->AddChild( yield_stmt );
    }
  }
  
  int state_;
  bool is_state_injection_;
  bool no_state_injection_;
  Function* function_;
  ProcessorInfo* info_;
  CaseClause* clause_;
  NodeList* body_;
  NodeIterator iterator_;
  std::list<YieldMark*> mark_list_;
};


class GeneratorHelper : private Uncopyable {
 public :

  GeneratorHelper( Function* function , NodeList* body , ProcessorInfo* info ) :
      function_( function ) , body_( body ) , switch_stmt_( SwitchStmt::New( function->line_number() ) ),
      info_( info ) {}
  
  void ProcessGenerator() {
    Literal* yield_state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                                     Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    switch_stmt_->set_expression( yield_state );
    switch_stmt_->AddChild( body_ );
    ProcessReturn();
  }
  
 private :

  void CreateStateLoop( Function* fn ) {
    NodeList *generator_arg = NodeList::New();
    Literal* one_exp = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    Literal* is_send = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSendFlag ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* is_safe = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSafeFlag ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    StatementList* stmt_list = StatementList::New();
    stmt_list->AddChild( switch_stmt_ );
    BlockStmt* block = BlockStmt::New( function_->line_number() );
    block->AddChild( stmt_list );
    IterationStmt* iter = IterationStmt::New( AstNode::kWhile , fn->line_number() );
    Expression* exp = Expression::New( fn->line_number() );
    exp->AddChild( one_exp );
    iter->set_expression( exp );
    iter->AddChild( block );
    generator_arg->AddChild( is_send );
    generator_arg->AddChild( is_safe );
    fn->set_argv( generator_arg );
    if ( function_->try_catch_list().size() > 0 ) {
      TryStmt* stmt = TryStmt::New( function_->line_number() );
      BlockStmt* block = BlockStmt::New( function_->line_number() );
      stmt->set_catch_block( CreateCatchHandler() );
      stmt->set_finally_block( CreateFinallyHandler() );
      AstNode* node = iter->first_child()->first_child();
      iter->RemoveAllChild();
      block->AddChild( node );
      stmt->AddChild( block );
      iter->AddChild( stmt );
    }
    fn->AddChild( iter );
  }


  BlockStmt* CreateExceptionReturnValueCheckStmt( CallExp* call_handler ) {
    Literal* cache = AstUtils::CreateTmpNode( info_->visitor_info()->tmp_index() , call_handler->line_number() );
    AstNode* return_value = cache->Clone();
    cache->set_value_type( Literal::kVariable );
    cache->AddChild( call_handler );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( call_handler->line_number() , 1 , cache );
    VariableStmt* value_stmt = AstUtils::CreateVarStmt( decl_list , call_handler->line_number() );
    ReturnStmt* return_value_stmt = AstUtils::CreateReturnStmt( return_value , call_handler->line_number() );
    BlockStmt* blk = AstUtils::CreateBlockStmt( call_handler->line_number() , 1 , return_value_stmt );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ) , Token::JS_IDENTIFIER , call_handler->line_number() , Literal::kIdentifier );
    CompareExp* is_defined = CompareExp::New( Token::JS_NOT_EQ , return_value->Clone() , undefined , call_handler->line_number() );
    IFStmt* is_return = AstUtils::CreateIFStmt( is_defined , blk , Empty::New() , call_handler->line_number() );
    BlockStmt* check_return = AstUtils::CreateBlockStmt( call_handler->line_number() , 2 , value_stmt , is_return );
    return check_return;
  }
  
  Literal* CreateCatchHandler() {
    Literal* catches = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kException ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    BlockStmt* catch_block = BlockStmt::New( function_->line_number() );
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCatchCache ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* args = NodeList::New();
    args->AddChild( catches->Clone() );
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args , function_->line_number() );

    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt( call_handler );
    
    IFStmt* if_stmt = IFStmt::New( function_->line_number() );
    Literal* thrower = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThrowException ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* list = NodeList::New();
    list->AddChild( catches->Clone() );
    CallExp* throw_call = AstUtils::CreateNormalAccessor( thrower , list , function_->line_number() );
    CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( throw_call , function_->line_number() );
    ExpressionStmt* call_stmt = AstUtils::CreateExpStmt( runtime_accessor , function_->line_number() );
    if_stmt->set_condition( handler->Clone() );
    if_stmt->set_then_statement( check_return );
    if_stmt->set_else_statement( call_stmt );
    StatementList *catch_stmt_list = StatementList::New();
    catch_stmt_list->AddChild( if_stmt );
    catch_block->AddChild( catch_stmt_list );
    catches->AddChild( catch_block );
    return catches;
  }

  AstNode* CreateFinallyHandler() {
    BlockStmt* finally_block = BlockStmt::New( function_->line_number() );
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* args = NodeList::New();
    CallExp* call_handler = AstUtils::CreateNormalAccessor( handler , args , function_->line_number() );
    BlockStmt* check_return = CreateExceptionReturnValueCheckStmt( call_handler );
    IFStmt* if_stmt = IFStmt::New( function_->line_number() );
    if_stmt->set_condition( handler->Clone() );
    if_stmt->set_then_statement( check_return );
    if_stmt->set_else_statement( Empty::New() );
    StatementList *finally_stmt_list = StatementList::New();
    finally_stmt_list->AddChild( if_stmt );
    finally_block->AddChild( finally_stmt_list );
    return finally_block;
  }
  
  IFStmt* CreateNewBornCheckStmt() {
    IFStmt* if_stmt = IFStmt::New( function_->line_number() );
    Literal* is_send = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSendFlag ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* is_new_born = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kIsNewBorn ),
                                                     Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* false_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFalse ),
                                                   Token::JS_IDENTIFIER, function_->line_number(),
                                                   Literal::kIdentifier , Literal::kIdentifier );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , is_new_born , false_sym , function_->line_number() ) , function_->line_number() );
    UnaryExp* not_is_send = UnaryExp::New( '!' , is_send , function_->line_number() );
    if_stmt->set_condition( not_is_send );
    BlockStmt* then_block = BlockStmt::New( function_->line_number() );
    then_block->AddChild( stmt );
    if_stmt->set_then_statement( then_block );
    IFStmt* else_if_stmt = IFStmt::New( function_->line_number() );
    Literal* arguments = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kArguments ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* one = AstUtils::CreateNameNode( "1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    CallExp* array_accessor = AstUtils::CreateArrayAccessor( arguments , one , function_->line_number() );
    Literal* undefined = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kUndefined ),
                                                   Token::JS_NUMERIC_LITERAL, function_->line_number(),
                                                   Literal::kIdentifier );
    CompareExp* undef_check = CompareExp::New( Token::JS_NOT_EQ , array_accessor , undefined , function_->line_number() );
    CompareExp* comp = CompareExp::New( Token::JS_LOGICAL_AND , is_send->Clone() , is_new_born , function_->line_number() );
    CompareExp* comp2 = CompareExp::New( Token::JS_LOGICAL_AND , comp , undef_check , function_->line_number() );
    BlockStmt* else_block = BlockStmt::New( function_->line_number() );
    Literal* handler = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kExceptionHandler ),
                                                 Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* message = AstUtils::CreateNameNode( "'attempt to send to newborn generator.'" , Token::JS_STRING_LITERAL , function_->line_number() , Literal::kString );
    NodeList* handle_list = NodeList::New();
    handle_list->AddChild( message );
    CallExp* handle_exp = AstUtils::CreateNormalAccessor( handler , handle_list , function_->line_number() );
    CallExp* runtime = AstUtils::CreateRuntimeMod( handle_exp , function_->line_number() );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( runtime , function_->line_number() );
    else_if_stmt->set_condition( comp2 );
    else_block->AddChild( exp_stmt );
    else_if_stmt->set_then_statement( else_block );
    else_if_stmt->set_else_statement( Empty::New() );
    if_stmt->set_else_statement( else_if_stmt );
    return if_stmt;
  }

  Literal* ObjectInitialiser( Literal* generator , bool is_send ) {
    Literal* name;
    Literal* boolean;
    if ( !is_send ) {
      name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldNext ),
                                       Token::JS_IDENTIFIER , function_->line_number(),
                                       Literal::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kTrue ),
                                          Token::JS_IDENTIFIER , function_->line_number(),
                                          Literal::kIdentifier );
    } else {
      name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldSend ),
                                       Token::JS_IDENTIFIER , function_->line_number(),
                                       Literal::kProperty );
      boolean = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFalse ),
                                          Token::JS_IDENTIFIER , function_->line_number(),
                                          Literal::kIdentifier );
    }
    Literal* bind_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kBind ),
                                                  Token::JS_IDENTIFIER , function_->line_number(),
                                                  Literal::kProperty );
    Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                  Token::JS_IDENTIFIER , function_->line_number(),
                                                  Literal::kIdentifier );
    
    CallExp* dot = AstUtils::CreateDotAccessor( generator->Clone() , bind_sym , function_->line_number() );
    NodeList* arg = NodeList::New();
    arg->AddChild( this_sym );
    arg->AddChild( boolean );
    CallExp* call = AstUtils::CreateNormalAccessor( dot , arg , function_->line_number() );
    name->AddChild( call );
    return name;
  }

  Function* CloseInitialiser() {
    Literal* state = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kYieldState ),
                                               Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    Literal* error_state = AstUtils::CreateNameNode( "-1" , Token::JS_NUMERIC_LITERAL , function_->line_number() , Literal::kNumeric );
    AssignmentExp* assign = AstUtils::CreateAssignment( '=' , state , error_state , function_->line_number() );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign , function_->line_number() );
    Function* close_fn = Function::New( function_->line_number() );
    close_fn->set_name( Empty::New() );
    close_fn->set_argv( NodeList::New() );
    close_fn->AddChild( stmt );
    if ( function_->try_catch_list().size() > 0 ) {
      Literal* name = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kFinallyCache ),
                                                Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
      CallExp* exp = AstUtils::CreateNormalAccessor( name , NodeList::New() , function_->line_number() );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp , function_->line_number() );
      IFStmt* if_stmt = AstUtils::CreateIFStmt( name->Clone() , stmt , Empty::New() , function_->line_number() );
      close_fn->AddChild( if_stmt );
    }
    return close_fn;
  }
  
  void GeneratorInitialiser( Function* fn ) {
    NodeList* list = NodeList::New();
    CreateStateLoop( fn );
    fn->InsertBefore( CreateNewBornCheckStmt() );
    Literal* generator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGenerator ),
                                                   Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier , true );
    Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                  Token::JS_IDENTIFIER , 0 , Literal::kIdentifier );
    Literal* generator_init = AstUtils::CreateVarInitiliser( generator->value() , fn , function_->line_number() );
    VariableDeclarationList* decl_list = AstUtils::CreateVarDeclList( function_->line_number() , 1 , generator_init );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( decl_list , function_->line_number() );
    function_->AddChild( var_stmt );
    Literal* create_generator = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateGenerator ),
                                                          Token::JS_IDENTIFIER , function_->line_number() , Literal::kIdentifier );
    NodeList* args = AstUtils::CreateNodeList( 3 , generator->Clone() , CloseInitialiser() , this_sym );
    CallExp* create_generator_call = AstUtils::CreateNormalAccessor( create_generator , args , function_->line_number() );
    CallExp* runtime = AstUtils::CreateRuntimeMod( create_generator_call , function_->line_number() );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( runtime , function_->line_number() );
    function_->AddChild( ret );
  }
  
  void ProcessReturn() {
    Function* fn = Function::New( function_->line_number() );
    fn->set_name( Empty::New() );
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
