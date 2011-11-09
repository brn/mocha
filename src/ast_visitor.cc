#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include "scope.h"
#include "ast_type.h"
#include "ast_visitor.h"
#include "ast_state.h"
#include "codegen.h"

using namespace std;
using namespace mocha;

#define VISITOR_IMPL(type) void AstVisitor::operator () ( type* ast_node )

#define ACCEPT( ast )                           \
  if ( ast != 0 )                               \
    ast->Accept(this)

#define ACCEPT_ITER(iter)                       \
  if ( (*iter) != 0 )                           \
    (*iter)->Accept(this)

#define WRITE(str)                              \
  if ( str != 0 &&                              \
       strlen (str) > 0 ) {                     \
    codegen_->Write ( str );                    \
  }

#define PRINT_NODE_NAME                                         \
  printf( "%s|__%s\n" , indent_.c_str() , ast_node->GetName() )

#define WRITE_TOSTRING(num,fmt)                 \
  char str [ 100 ];                             \
  sprintf ( str , fmt , num );                  \
  if ( str != 0 &&                              \
       strlen (str) > 0 ) {                     \
    codegen_->Write ( &str[0] );                \
  }

#define WRITE_LINE(ast)                           \
  if ( ( state_->State () == AstState::None ||    \
         state_->State () == AstState::Block ) && \
       ast->LineNumber () > 0 ){                  \
    codegen_->WriteLine ( ast->LineNumber () );   \
  }

#define VOLATILE "__volatile__"
#define FUNCTION "function "
#define INDENT "  "

AstVisitor::AstVisitor ( Scope* scope,
                         Codegen* codegen,
                         const char* modulename,
                         const char* filename ) :
    module_name_ ( modulename ),
    filename_ ( filename ),
    scope_ ( scope ),
    codegen_ ( codegen ),
    state_ ( new AstState () ) {
  
  if ( strcmp ( module_name_ , "main" ) == 0 ) {
    state_->DeclMain ();
  }
  
};

#define IS_STATE(ast_state,type) ast_state->Is( AstState::type )

#define IS_COND_EXP( ast_state )                                         \
  ( IS_STATE(ast_state,kIfCond) || IS_STATE(ast_state,kDoCond) ||       \
    IS_STATE(ast_state,kWhileCond) || IS_STATE(ast_state,AstState::kForCond) || \
    IS_STATE(ast_state,kWithParent) || IS_STATE(ast_state,kSwitchCond) || \
    IS_STATE(ast_state,kCaseCond) )? true : false

#define IS_VALUE_EXP( ast_state )\
  ( IS_STATE(ast_state,kReturn) || IS_STATE(ast_state,kThrow) )? true : false

#define IS_CALL( ast_state )                    \
  ( IS_STATE(ast_state,kCallAccessor) || IS_STATE(ast_state,kNewCallAccessor) )? true : false

AstVisitor::~AstVisitor () {
  delete state_;
}

typedef AstTypeBase* Base;
typedef list<AstTypeBase*> BaseList;
typedef list<AstTypeBase*>::iterator BaseIter;
typedef list<pair<const char* , AstTypeBase*> > BaseMap;
typedef list<pair<const char* , AstTypeBase*> >::iterator BaseMapIter;


void AstVisitor::setScope ( Scope* scope ){};

void AstVisitor::BeginClosure () {
  if ( strlen(module_name_) > 0 &&
       !state_->IsMain () ) {
    WRITE("var ");
    WRITE(module_name_);
    WRITE("=");
  }
  WRITE("(function () {");
  if ( !state_->IsMain () ) {
    WRITE("var exports={};");
  }
}

void AstVisitor::EndClosure () {
  if ( state_->IsMain () ) {
    const char* main_fn_name = state_->GetMainFunctionName ();
    if ( main_fn_name == 0 ) {
      WRITE( "throw new Error('Undefined reference to the Function::main in module main.')" );
    } else {
      WRITE(main_fn_name);
      WRITE("();");
    }
    WRITE("})();");
  } else {
    WRITE("return exports;})();");
  }
}

VISITOR_IMPL(AstTree) {
  std::list<SourceBlock*> list = ast_node->List ();
  std::list<SourceBlock*>::iterator it = list.begin ();
  std::list<SourceBlock*>::iterator end = list.end ();
  PRINT_NODE_NAME;
  while ( it != end ) {
    SourceBlock* source_block = (*it);
    switch ( source_block->Type () ) {
      case SourceBlock::kBlock :
        printf ( "%sBlock Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kVariableDeclarationList :
        printf ( "%sVariableDeclarationList Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kExpression :
        printf ( "%sExpression Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kIFStmt :
        printf ( "%sIFStmt Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kIteration :
        printf ( "%sIteration Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kContinue :
        printf ( "%sContinue Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kBreak :
        printf ( "%sBreak Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kReturn :
        printf ( "%sReturn Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kWith :
        printf ( "%sWith Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kLabel :
        printf ( "%sLabel Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kSwitch :
        printf ( "%sSwitch Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kThrow :
        printf ( "%sThrow Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kTry :
        printf ( "%sTry Block\n" , indent_.c_str() );
        break;
      case SourceBlock::kFunction :
        printf ( "%sFunction Block\n" , indent_.c_str() );
        break;
    }
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    it++;
    indent_ = last;
  }
}

VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  //Constant::ConstantType op = ast_node->Operand();
  /*if ( op == Constatn::Sub || op == Constant::Add ) {
    if ( state_->Is( AstState::kUnaryAddOrSub ) ) {
      tracer->SyntaxError( ast_node->GetLineNumber() , "INCREMENT or DECREMENT is not allowed before INCREMENT or DECREMENT." );
      throw std::runtime_error("");
    }
    state_->State( AstState::kUnaryAddOrSub );
    ACCEPT(unary->Left());
    state_->Pop();
  } else if ( IS_STATE( state_ , kUnaryAddOrSub ) ) {  
    tracer->SyntaxError( unary->GetLineNumber() , "INCREMENT or DECREMENT is not allowed before unary expression." );
    throw std::runtime_error("");
  } else {
  *///current_state_->State( AstState::kUnary );
  std::string last = indent_;
  indent_ += INDENT;
    ACCEPT(ast_node->Left());
    indent_ = last;
    //current_state_->Pop();
    //}
}

VISITOR_IMPL(ArrayAccessor) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  //state_->State( AstState::kArrayAccessor );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kArrayAccessExp );
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(DotAccessor) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kMemberAccess );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kMemberAccess );
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(NewCallAccessor) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kNewCall );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
}

VISITOR_IMPL(NewAccessor) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kNewCall );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
}


VISITOR_IMPL(CallAccessor) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kCallAccessor );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();

  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kPostFix );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(MultiplicativeExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kMultiPlicative );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(AdditiveExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kAdditive );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(ShiftExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kShiftExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(RelationalExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kRelationalExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(EqualityExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kEquality );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(BitwiseANDExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kBitwiseANDExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(BitwiseXORExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kBitwiseXORExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(BitwiseORExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kBitwiseORExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(LogicalANDExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kLogicalANDExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(LogicalORExp) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  //state_->State( AstState::kLogicalORExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( left );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( right );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Exp ();
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( exp ) );
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kConditionalCondExp );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kConditionalLeftExp );
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kConditionalRightExp );
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Assign) {
  PRINT_NODE_NAME;
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  //state_->State( AstState::kAssignLeftSide );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(left);
  indent_ = last;
  //state_->Pop();
  
  //state_->State( AstState::kAssignRightSide );
  indent_ += INDENT;
  ACCEPT(right);
  indent_ = last;
  //state_->Pop();
}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  Base args = ast_node->Argv ();
  const char* ident = ast_node->Ident ();
  Base body = ast_node->Body ();
  scope_ = ast_node->FnScope ();
  /*Node* function_node = ManagedHandle::Retain( new Node( ident , Node::kFunction ) );
  function_node->AddScope( scope_ );
  //Is inner Function decl?
  if ( state_->Match( AstState::kFunction ) ) {
    //Set inner Function to parent.
    current_node_->Scope()->GetFunctionNode()->SetAttr( Scope::kInnerFunctionDecl );
  }

  current_node_->Next( function_node );
  current_node_ = function_node;
  */
  //state_->State( AstState::kFormalParameter );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(args);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstStaet::kFunctionBody );
  indent_ += INDENT;
  ACCEPT(body);
  indent_ = last;
  scope_ = scope_->Escape ();
  //state_->Pop ();
};


VISITOR_IMPL(FormalParameter){
  PRINT_NODE_NAME;
  if ( ast_node->Argc () > 0 ) {
    list<AstTypeBase*> args = ast_node->Args ();
    list<AstTypeBase*>::iterator it = args.begin ();
    list<AstTypeBase*>::iterator end = args.end ();
    while ( it != end ) {
      //Set arguments to indexed array and hash map.
      ACCEPT_ITER(it);
      //Node* node = ManagedHandle::Retain( new Node( ident , Node::kArgs ) );
      //current_node_->Next( node );
      //current_node_ = node;
      ++it;
    }
  }
}


VISITOR_IMPL(VariableDeclaration){
  PRINT_NODE_NAME;
  Base ast = ast_node->Value ();
  const char* name = ast_node->Name ();
  /*Node* node;

  if ( value->IsEmpty() ) {
    node = ManagedHandle::Retain( new Node( name , Node::kDecl ) );
  } else {
    node = ManagedHandle::Retain( new Node( name , Node::kInitialiser ) );
  }

  current_node_->Next( node );
  current_node_ = node;
  */
  //state_->State( AstState::kDecl );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(ast_node->Value());
  indent_ = last;
  //state_->Pop();
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  BaseIter it = ast_node->List ().begin ();
  BaseIter end = ast_node->List ().end ();
  while ( it != end ) {
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    indent_ = last;
    it++;
  }
}

VISITOR_IMPL(StmtList) {
  PRINT_NODE_NAME;
  BaseList l = ast_node->List ();
  BaseIter it = l.begin ();
  BaseIter end = l.end ();
  while ( it != end ) {
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    indent_ = last;
    it++;
  }
}


VISITOR_IMPL(ArrayLiteral){
  PRINT_NODE_NAME;
  //state_->State( AstState::kArrayLiteral );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(ast_node->Value());
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(ObjectLiteral){
  PRINT_NODE_NAME;
  //state_->State( kObjectLiteral );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(ast_node->Value());
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(ElementList){
  PRINT_NODE_NAME;
  BaseList list = ast_node->Value ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();  
  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
  }
}


VISITOR_IMPL(ObjectMember){
  PRINT_NODE_NAME;
  ObjectMember::MemberList m = ast_node->Value ();
  ObjectMember::MemberList::iterator it = m.begin ();
  ObjectMember::MemberList::iterator end = m.end ();
  while ( it != end ) {
    //state_->State( AstState::kPropertyName );
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT((*it).first);
    indent_ = last;
    //state_->Pop();
    
    //state_->State( AstState::kPropertyValue );
    indent_ += INDENT;
    ACCEPT((*it).second);
    indent_ = last;
    //state_->Pop();
    it++;
  }
}


VISITOR_IMPL(Arguments){
  PRINT_NODE_NAME;
  //state_->State( AstState::kArguments );
  BaseList list = ast_node->Value ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();

  while ( it != end ) {
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    indent_ = last;
    it++;
  }
  //state_->Pop();
}

VISITOR_IMPL(Block) {
  PRINT_NODE_NAME;
  Base value = ast_node->Value();
  //state_->State ( AstState::Block );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( value );
  indent_ = last;
  //state_->Pop ();
};


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  Expression* exp = ast_node->Exp();
  assert( AstUtil::IsValidAst( exp ) );

  //Set current state to Expression statement.
  //state_->State( AstState::kExpressionStmt );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( exp );
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Expression){
  PRINT_NODE_NAME;
  BaseList list = ast_node->List ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();
  bool isparen = ast_node->Paren ();
  
  /*if ( isparen ) {
    state_->State( AstState::kPriorExpression );
  } else {
    state_->State( AstState::kExpression );
    }*/
  while ( it != end ) {
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    indent_ = last;
    it++;
  }
  //state_->Pop();
}


VISITOR_IMPL(IFStmt){
  PRINT_NODE_NAME;

  Base then_exp = ast_node->Then();
  Base block_body = ast_node->Body();
  Base else_block = ast_node->Else();

  //state_->State( AstState::kIfCond );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(then_exp);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kIfBody );
  indent_ += INDENT;
  ACCEPT(block_body);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kElse );
  indent_ += INDENT;
  ACCEPT(else_block);
  indent_ = last;
  //state_->Pop();
}



VISITOR_IMPL(DoWhile) {
  PRINT_NODE_NAME;
  Base body_block = ast_node->Body();
  Base cond_exp = ast_node->Condition();

  //state_->State( AstState::kDoWhileBlock );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(body_block);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kDoWhileCond );
  indent_ += INDENT;
  ACCEPT(cond_exp);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(While) {
  PRINT_NODE_NAME;
  Base cond_exp = ast_node->Condition();
  Base body_block = ast_node->Body();
  
  //state_->State( AstState::kWhileCond );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(cond_exp);
  indent_ = last;
  //state_->Pop();
  
  //state_->State( AstState::kWhileBlock );
  indent_ += INDENT;
  ACCEPT( body_block );
  indent_ = last;
  //state_->Pop();
}

VISITOR_IMPL(For) {
  PRINT_NODE_NAME;
  Base index_exp = ast_node->Index();
  Base cond_exp = ast_node->Condition();
  Base incr_exp = ast_node->Increment();
  Base body_block = ast_node->Body();
  
  
  //state_->State( AstState::kForIndex );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( index_exp );
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kForCondition );
  indent_ += INDENT;
  ACCEPT( cond_exp );
  indent_ = last;
  //state_->Pop();

  //current_stae_->State( AstState::kForIncr );
  indent_ += INDENT;
  ACCEPT( incr_exp );
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kForBody );
  indent_ += INDENT;
  ACCEPT(body_block);
  indent_ = last;
  //state_->Pop ();
}

VISITOR_IMPL(ForIn) {
  PRINT_NODE_NAME;
  Base item_exp = ast_node->Item();
  Base target_exp = ast_node->Target();
  Base body_block = ast_node->Body();
  
  //state_->State( AstState::kForInItem );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( item_exp );
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kForInTarget );
  indent_ += INDENT;
  ACCEPT( target_exp );
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kForInBody );
  indent_ += INDENT;
  ACCEPT(body_block);
  indent_ = last;
  //state_->Pop ();
}


VISITOR_IMPL(Continue) {
  PRINT_NODE_NAME;
  //Base ident = ast_node->Ident();
  /*Node* continue_node = ManagedHandle::Retain( new Node( "continue" , Node::kContinue ) );
  current_node_->Next( continue_node );
  current_node_ = continue_node;
*/
  //state_->State( AstState::kContinue );
  //ACCEPT(ident);
  //state_->Pop();
}

VISITOR_IMPL(Break) {
  PRINT_NODE_NAME;
  //Base ident = ast_node->Ident();
  /*Node* break_node = ManagedHandle( new Node( "break" , Node::kBreak ) );
  current_node_->Next( break_node );
  current_node_ = break_node;
  */
  //state_->State( AstState::kBreak );
  //ACCEPT(ident);
  //state_->Pop();
}


VISITOR_IMPL(Return) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Expression();
  /*Node* return_node = ManagedHandle( new Node( "return" , Node::kReturn ) );
  current_node_->Next( return_node );
  current_node_ = return_node;
  */
  //state_->State( AstState::kReturn );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();
}

VISITOR_IMPL(With) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Expression();
  Base body = ast_node->Body();
  /*Node* with_node = ManagedHandle::Retain( new Node( "with" , Node::kWith ) );

  current_node_->Next( with_node );
  current_node_ = with_node;
  */
  //state_->State( AstState::kWithParent );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();
  
  //state_->State( AstState::WithBody );
  indent_ += INDENT;
  ACCEPT(body);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Switch) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Expression();
  Base case_block = ast_node->CaseBlock();
  //Node* switch_node = ManagedHandle::Retain( new Node( "switch" , Node::kSwitch ) );
  //current_node_->Next( switch_node );
  //current_node_ = switch_node;
  
  //state_->State( AstState::kSwitchCond );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();
  indent_ += INDENT;
  ACCEPT(case_block);
  indent_ = last;
}

VISITOR_IMPL(CaseClauses) {
  PRINT_NODE_NAME;
  BaseList list = ast_node->List ();
  BaseIter it = list.begin();
  BaseIter end = list.end ();

  while ( it != end ) {
    std::string last = indent_;
    indent_ += INDENT;
    ACCEPT_ITER(it);
    indent_ = last;
    it++;
  }
}

VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Expression();
  Base body = ast_node->Body();
  //Node* case_node = ManagedHandle::Retain( new Node( "case" , Node::kCase ) );
  //current_node_->Next( case_node );
  //current_node_ = case_node;
  
  //state_->State( AstState::kCaseCond );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();

  //state_->State( AstState::kCaseBody );
  indent_ += INDENT;
  ACCEPT(body);
  indent_ = last;
  //state_->Pop();
}



VISITOR_IMPL(DefaultClause) {
  PRINT_NODE_NAME;
  Base body = ast_node->Body();
  //Node* default_node = ManagedHandle::Retain( new Node( "default" , Node::kDefault ) );
  //current_node_->Next( default_node );
  //current_node_ = default_node;
  
  //state_->State( AstState::kDefault );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(body);
  indent_ = last;
  //state_->Pop();
}

VISITOR_IMPL(Label) {
  PRINT_NODE_NAME;
  //Base ident = ast_node->Ident();
  Base stmt = ast_node->Body();
  
  //state_->State( AstState::kLabelName );
  //ACCEPT(ident);
  //state_->Pop();
  
  //state_->State( AstState::kLabel );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(stmt);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Throw) {
  PRINT_NODE_NAME;
  Base exp = ast_node->Expression();
  //Node* throw_node = ManagedHandle::Retain( new Node( "throw" , Node::kThrow ) );
  //current_node_->Next( throw_node );
  //current_node_ = throw_node;
  
  //state_->State( AstState::kThrow );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(exp);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Try) {
  PRINT_NODE_NAME;
  Base try_body = ast_node->Body();
  Base catch_body = ast_node->CatchBody ();
  Base finally_body = ast_node->FinallyBody ();
  //Node* try_node = ManagedHandle::Retain( new Node( "try" , Node::kTry ) );
  //current_node_->Next( try_node );
  //current_node_ = try_node;
  
  //state_->State( AstState::kTryBody );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT( try_body );
  indent_ = last;
  //state_->Pop();
  indent_ += INDENT;
  ACCEPT( catch_body );
  indent_ = last;

  indent_ += INDENT;
  ACCEPT( finally_body );
  indent_ = last;
  //state_->Pop();
}



VISITOR_IMPL(Catch){
  PRINT_NODE_NAME;
  //Base ident = ast_node->Ident();
  Base body_block = ast_node->Body();
  //Node* catch_node = ManagedHandle::Retain( new Node( "catch" , Node::kCatch ) );
  //current_node_->Next( catch_node );
  //current_node_ = catch_node;
  
  ////state_->State( AstState::kErrorIdent );
  //ACCEPT(ident);
  //state_->Pop();
  
  ////state_->State( AstState::kCatchBody );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(body_block);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(Finally) {
  PRINT_NODE_NAME;
  Base block = ast_node->Block();
  //  Node* finally_block = ManagedHandle::Retain( new Node( "finally" , Node::kFinally ) );

  ////state_->State( AstState::kFinally );
  std::string last = indent_;
  indent_ += INDENT;
  ACCEPT(block);
  indent_ = last;
  //state_->Pop();
}


VISITOR_IMPL(ConstantLiteral) {
  PRINT_NODE_NAME;
  /*This* this_literal = constant->CastToThis ();
  StringLiteral* string_literal = constant->CastToStringLiteral ();
  BooleanLiteral* boolean_literal = constant->CastToBooleanLiteral ();
  RegExpLiteral* regexp_literal = constant->CastToRegExpLiteral ();
  NullLiteral* null_literal = constant->CastToNullLiteral ();
  UndefinedLiteral* undefined_literal = constant->CastToUndefinedLiteral ();
  Identifier* ident_literal = constant->CastToIdentifier ();
  PropertyName* property_name = constant->CastToPropertyName ();
  
  if ( AstUtil::IsValidAst( this_literal ) ) {
    WRITE("this");
  } else if ( AstUtil::IsValidAst( string_literal ) ) {
    WRITE( string_literal->Value() );
  } else if ( AstUtil::IsValidAst( boolean_literal ) ) {
    WRITE( boolean_literal->Value() );
  } else if ( AstUtil::IsValidAst( regexp_literal ) ) {
    WRITE( regexp_literal->Value() );
  } else if ( AstUtil::IsValidAst( null_literal ) ) {
    WRITE( null_literal->Value() );
  } else if ( AstUtil::IsValidAst( undefined_literal ) ) {
    WRITE( undefined_literal->Value() );
  } else if ( AstUtil::IsValidAst( ident_literal ) ) {
    //If function declaration.
    if ( ////state_->State() == AstState::kFunctionName ) {
      node_->SetName( ident_litral->Value() );
    }
    SymbolSet* symbol_set = scope_->Find( ident_literal->Value () );
    if ( !symbol_set->IsEmpty () ) {
      //WRITE(ident_literal->Value());
      WRITE(symbol_set->GetShortenName ());
    } else {
      WRITE(ident_literal->Value());
    }
  } else if ( AstUtil::IsValidAst( property_name ) ) {
    SymbolSet* symbol_set = Scope::GetGlobalSymbol( property_name->Value () );
    if ( !symbol_set->IsEmpty () ) {
      //WRITE(property_name->Value());
      WRITE(symbol_set->GetShortenName ());
    } else {
      WRITE(property_name->Value());
    }
  } else {
    WRITE( constant->Value () );
    }*/
}


/*VISITOR_IMPL(Name) {
SymbolSet* symbol_set = scope_->Find ( ident );
  if ( !symbol_set->IsEmpty () ) {
    //WRITE(ident);
    WRITE(symbol_set->GetShortenName());
  } else {
    WRITE(ident);
    }
}
*/

