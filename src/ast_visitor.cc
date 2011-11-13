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
#include "managed_handle.h"

namespace mocha {

#define ITERATOR(name) begin=name.begin(),end=name.end()

#define VISITOR_IMPL(type) void AstVisitor::operator () ( type* ast_node )

#define ACCEPT( ast )                           \
  if ( ast != 0 )                               \
    ast->Accept(this)

#define ACCEPT_ITER(iter)                       \
  if ( (*iter) != 0 )                           \
    (*iter)->Accept(this)


#define PRINT_NODE_NAME                                         \
  printf( "%s|__%s\n" , indent_.c_str() , ast_node->GetName() )



AstVisitor::AstVisitor ( Scope* scope,
                         const char* modulename,
                         const char* filename ) :
    tmp_index_(0),
    module_name_ ( modulename ),
    filename_ ( filename ),
    scope_ ( scope ) {};

AstVisitor::~AstVisitor () {}

VISITOR_IMPL( AstRoot ) {
  AstTypeBase* root = ast_node->Tree().back();
  root->Accept(this);
}

VISITOR_IMPL( RootBlock ) {
  ACCEPT( ast_node->Root() );
}

VISITOR_IMPL(AstTree) {
  SourceBlock* source_block = ast_node->Head()->Next();
  root_block_ = source_block;
  current_block_ = source_block;
  PRINT_NODE_NAME;
  while ( 1 ) {
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
      case SourceBlock::kModule :
        printf ( "%sModule Block\n" , indent_.c_str() );
        break;
    }
    ACCEPT(current_block_);
    if ( current_block_->HasNext() ) {
      current_block_ = current_block_->Next();
    } else {
      break;
    }
  }

  source_block = ast_node->Head();
  while ( 1 ) {
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
      case SourceBlock::kModule :
        printf ( "%sModule Block\n" , indent_.c_str() );
        break;
        
    }
    current_block_ = source_block;
    if ( source_block->HasNext() ) {
      source_block = source_block->Next();
    } else {
      break;
    }
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

  ACCEPT(ast_node->Left());

    //current_state_->Pop();
    //}
}

VISITOR_IMPL(ArrayAccessor) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left ();
  AstTypeBase* right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);

  ACCEPT(right);

}


VISITOR_IMPL(DotAccessor) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);

  ACCEPT(right);

}


VISITOR_IMPL(NewCallAccessor) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left ();
  AstTypeBase* right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);

  ACCEPT(right);
}

VISITOR_IMPL(NewAccessor) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left ();
  AstTypeBase* right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);

  ACCEPT(right);

}


VISITOR_IMPL(CallAccessor) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);

  ACCEPT(right);

}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(MultiplicativeExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(AdditiveExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(ShiftExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(RelationalExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(EqualityExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(BitwiseANDExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(BitwiseXORExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(BitwiseORExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );
}


VISITOR_IMPL(LogicalANDExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(LogicalORExp) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );

  ACCEPT( right );

}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  AstTypeBase* exp = ast_node->Exp ();
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( exp ) );
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT(exp);
  
  ACCEPT(left);
  
  ACCEPT(right);
  
}


VISITOR_IMPL(Assign) {
  PRINT_NODE_NAME;
  AstTypeBase* left = ast_node->Left();
  AstTypeBase* right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT(left);
  ACCEPT(right);
}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  AstTypeBase* args = ast_node->Argv ();
  const char* ident = ast_node->Ident ();
  AstTypeBase* body = ast_node->Body ();
  ACCEPT(args);
  ACCEPT(body);
};


VISITOR_IMPL(FormalParameter){
  PRINT_NODE_NAME;
  if ( ast_node->Argc () > 0 ) {
    std::list<FormalParameterSet*> args = ast_node->Args ();
    std::list<FormalParameterSet*>::iterator ITERATOR(args);
    while ( begin != end ) {
      //Set arguments to indexed array and hash map.
      ACCEPT(((*begin)->Param()));
      //Node* node = ManagedHandle::Retain( new Node( ident , Node::kArgs ) );
      //current_node_->Next( node );
      //current_node_ = node;
      ++begin;
    }
  }
}


VISITOR_IMPL(VariableDeclaration){
  PRINT_NODE_NAME;
  AstTypeBase* ast = ast_node->Value ();
  const char* name = ast_node->Name ();
  ACCEPT(ast_node->Value());
}

VISITOR_IMPL(VariableDeclarationList) {
  PRINT_NODE_NAME;
  AstList::iterator ITERATOR( ast_node->List());
  while ( begin != end ) {
    ACCEPT_ITER(begin);
    ++begin;
  }
}

VISITOR_IMPL(StmtList) {
  PRINT_NODE_NAME;
  AstList list = ast_node->List ();
  AstList::iterator ITERATOR(list);
  while ( begin != end ) {
    ACCEPT_ITER(begin);
    ++begin;
  }
}


VISITOR_IMPL(ArrayLiteral){
  PRINT_NODE_NAME;
  ACCEPT(ast_node->Value());
}


VISITOR_IMPL(ObjectLiteral){
  PRINT_NODE_NAME;
  ACCEPT(ast_node->Value());
}


VISITOR_IMPL(ElementList){
  PRINT_NODE_NAME;
  AstList list = ast_node->Value ();
  AstList::iterator ITERATOR(list);
  while ( begin != end ) {
    ACCEPT_ITER(begin);
    begin++;
  }
}


VISITOR_IMPL(ObjectMember){
  PRINT_NODE_NAME;
  ObjectMember::MemberList member_list = ast_node->Value ();
  ObjectMember::MemberList::iterator ITERATOR( member_list );
  while ( begin != end ) {
    ACCEPT((*begin).first);
    ACCEPT((*begin).second);
    begin++;
  }
}


VISITOR_IMPL(Arguments){
  PRINT_NODE_NAME;
  //state_->State( AstState::kArguments );
  AstList list = ast_node->Value ();
  AstList::iterator ITERATOR(list);

  while ( begin != end ) {
    ACCEPT_ITER(begin);
    ++begin;
  }
}

VISITOR_IMPL(Block) {
  PRINT_NODE_NAME;
  AstTypeBase *value = ast_node->Value();
  ACCEPT( value );  
};


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  Expression* exp = ast_node->Exp();
  assert( AstUtil::IsValidAst( exp ) );
  ACCEPT( exp );
}


VISITOR_IMPL(Expression){
  PRINT_NODE_NAME;
  AstList list = ast_node->List ();
  AstList::iterator ITERATOR(list);
  bool isparen = ast_node->Paren ();
  
  /*if ( isparen ) {
    state_->State( AstState::kPriorExpression );
  } else {
    state_->State( AstState::kExpression );
    }*/
  while ( begin != end ) {
    ACCEPT_ITER(begin);
    begin++;
  }
  //state_->Pop();
}


VISITOR_IMPL(IFStmt){
  PRINT_NODE_NAME;

  AstTypeBase *then_exp = ast_node->Then();
  AstTypeBase *block_body = ast_node->Body();
  AstTypeBase *else_block = ast_node->Else();
  
  ACCEPT(then_exp);
  ACCEPT(block_body);
  ACCEPT(else_block);
  
}



VISITOR_IMPL(DoWhile) {
  PRINT_NODE_NAME;
  AstTypeBase *body_block = ast_node->Body();
  AstTypeBase *cond_exp = ast_node->Condition();
  
  ACCEPT(body_block);
  ACCEPT(cond_exp);
  
}


VISITOR_IMPL(While) {
  PRINT_NODE_NAME;
  AstTypeBase *cond_exp = ast_node->Condition();
  AstTypeBase *body_block = ast_node->Body();
  
  ACCEPT(cond_exp);
  ACCEPT( body_block );
}

VISITOR_IMPL(For) {
  PRINT_NODE_NAME;
  AstTypeBase* index_exp = ast_node->Index();
  AstTypeBase* cond_exp = ast_node->Condition();
  AstTypeBase* incr_exp = ast_node->Increment();
  AstTypeBase* body_block = ast_node->Body();
  
  ACCEPT( index_exp );
  ACCEPT( cond_exp );
  ACCEPT( incr_exp );
  ACCEPT(body_block);
}

VISITOR_IMPL(ForIn) {
  PRINT_NODE_NAME;
  AstTypeBase* item_exp = ast_node->Item();
  AstTypeBase* target_exp = ast_node->Target();
  AstTypeBase* body_block = ast_node->Body();
  ACCEPT( item_exp );
  ACCEPT( target_exp );
  ACCEPT(body_block);
}


VISITOR_IMPL(Continue) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL(Break) {
  PRINT_NODE_NAME;
}


VISITOR_IMPL(Return) {
  PRINT_NODE_NAME;
  AstTypeBase *exp = ast_node->Expression();
  ACCEPT(exp);
}

VISITOR_IMPL(With) {
  PRINT_NODE_NAME;
  AstTypeBase *exp = ast_node->Expression();
  AstTypeBase *body = ast_node->Body();
  ACCEPT(exp);
  ACCEPT(body);
}


VISITOR_IMPL(Switch) {
  PRINT_NODE_NAME;
  AstTypeBase *exp = ast_node->Expression();
  AstTypeBase *case_block = ast_node->CaseBlock();
  ACCEPT(exp);
  ACCEPT(case_block);
}

VISITOR_IMPL(CaseClauses) {
  PRINT_NODE_NAME;
  AstList list = ast_node->List ();
  AstList::iterator ITERATOR(list);
  while ( begin != end ) {
    ACCEPT_ITER(begin);
    ++begin;
  }
}

VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  AstTypeBase *exp = ast_node->Expression();
  AstTypeBase *body = ast_node->Body();
  ACCEPT(exp);
  ACCEPT(body);
}



VISITOR_IMPL(DefaultClause) {
  PRINT_NODE_NAME;
  AstTypeBase *body = ast_node->Body();
  ACCEPT(body);
}

VISITOR_IMPL(Label) {
  PRINT_NODE_NAME;
  AstTypeBase *stmt = ast_node->Body();
  ACCEPT(stmt);
}


VISITOR_IMPL(Throw) {
  PRINT_NODE_NAME;
  AstTypeBase *exp = ast_node->Expression();
  ACCEPT(exp);
}


VISITOR_IMPL(Try) {
  PRINT_NODE_NAME;
  AstTypeBase *try_body = ast_node->Body();
  AstTypeBase *catch_body = ast_node->CatchBody ();
  AstTypeBase *finally_body = ast_node->FinallyBody ();
  ACCEPT( try_body );
  ACCEPT( catch_body );
  ACCEPT( finally_body );
}



VISITOR_IMPL(Catch){
  PRINT_NODE_NAME;
  AstTypeBase *body_block = ast_node->Body();
  ACCEPT(body_block);
}


VISITOR_IMPL(Finally) {
  PRINT_NODE_NAME;
  AstTypeBase *block = ast_node->Block();
  ACCEPT(block);
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



VISITOR_IMPL(LetStmt) {
}

VISITOR_IMPL(ArrayComprehensions) {
}

VISITOR_IMPL(FormalParameterRest) {
}

VISITOR_IMPL(Spread) {
}

VISITOR_IMPL(ForEach) {
}

VISITOR_IMPL(Module) {
  VariableDeclarationList *vars = ManagedHandle::Retain<VariableDeclarationList>();
  ExpressionStmt *exp = CreateModule_( ast_node->Body() );
  VariableDeclaration *var = CreateVariableDecl_( ast_node->Name() , exp->Exp() );
  printf( "%s\n" , var->Name() );
  vars->List( var );
  ReplaceBlock_<VariableDeclarationList>( current_block_ , vars );
}

VISITOR_IMPL(ExportStmt) {
  ExpressionStmt* stmt = CreateExport_( ast_node->Value() );
  ReplaceBlock_<ExpressionStmt>( current_block_ , stmt );
}

VISITOR_IMPL( DestructuringAssignment ) {
  CreateDstAssignment_( ast_node , ast_node->Value() );
}

ExpressionStmt* AstVisitor::CreateModule_( AstTypeBase* body ) {
  Block *blk = body->CastToBlock();
  if ( AstUtil::IsValidAst( blk ) ) {
    StmtList* stmt_list = blk->Value()->CastToStmtList();
    if ( AstUtil::IsValidAst( stmt_list ) ) {
      VariableDeclarationList *vars = ManagedHandle::Retain<VariableDeclarationList>();
      VariableDeclaration* var = ManagedHandle::Retain( new VariableDeclaration( "__export__" ) );
      ObjectMember* member = ManagedHandle::Retain<ObjectMember>();
      ObjectLiteral* literal = ManagedHandle::Retain( new ObjectLiteral( member ) );
      vars->List( var );
      var->Value( literal );
      AstList list = stmt_list->List();
      list.push_front( vars );
      return CreateAnonymousFunctionCall_( stmt_list );
    }
  } else {
    StmtList* stmt_list = ManagedHandle::Retain<StmtList>();
    VariableDeclarationList *vars = ManagedHandle::Retain<VariableDeclarationList>();
    VariableDeclaration* var = ManagedHandle::Retain( new VariableDeclaration( "__export__" ) );
    ObjectMember* member = ManagedHandle::Retain<ObjectMember>();
    ObjectLiteral* literal = ManagedHandle::Retain( new ObjectLiteral( member ) );
    vars->List( var );
    var->Value( literal );
    stmt_list->List( vars );
    stmt_list->List( body );
    return CreateAnonymousFunctionCall_( stmt_list );
  }
  
}

ExpressionStmt* AstVisitor::CreateAnonymousFunctionCall_( AstTypeBase* body ) {
  ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
  Expression *exp = ManagedHandle::Retain<Expression>();
  Expression *ret = ManagedHandle::Retain<Expression>();
  Function *fn = ManagedHandle::Retain( new Function( "" ) );
  Block *blk = body->CastToBlock();
  if ( AstUtil::IsValidAst( blk ) ) {
    body = blk->Value();
  }
  fn->Body( body );
  fn->Argv( ManagedHandle::Retain<Empty>() );
  exp->List( fn );
  exp->Paren();
  ret->Paren();
  CallAccessor* call = ManagedHandle::Retain( new CallAccessor( Constant::kCall , exp , ManagedHandle::Retain<Empty>() ) );
  ret->List( call );
  stmt->Exp( ret );
  return stmt;
}

ExpressionStmt* AstVisitor::CreateExport_( AstTypeBase* ast_node ) {
  Identifier* exports = ManagedHandle::Retain( new Identifier( "__export__" ) );
  VariableDeclaration *var = ast_node->CastToVariableDecl();
  Function* fn = ast_node->CastToFunction();
  Identifier* name;
  if ( AstUtil::IsValidAst( var ) ) {
    name = ManagedHandle::Retain( new Identifier( var->Name() ) );
  } else if ( AstUtil::IsValidAst( fn ) ) {
    name = ManagedHandle::Retain( new Identifier( fn->Ident() ) );
  }
  DotAccessor* accessor = ManagedHandle::Retain( new DotAccessor( Constant::kDot , exports , name ) );
  ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
  Expression* exp = ManagedHandle::Retain<Expression>();
  Assign* assign = ManagedHandle::Retain( new Assign( Constant::kAssign , accessor , var->Value() ) );
  exp->List( assign );
  stmt->Exp( exp );
  return stmt;
}


template <typename T>
void AstVisitor::InsertBlock_( SourceBlock* rep_block , T* node , int type ) {
  SourceBlock* block = ManagedHandle::Retain( new SourceBlock( node ) );
  if ( type == kPrev ) {
    if ( rep_block->HasPrev() ) {
      rep_block->Prev()->Next( block );
    }
    rep_block->Prev( block );
    block->Next( rep_block );
    current_block_ = block;
  } else if ( type == kNext ) {
    if ( rep_block->HasNext() ) {
      rep_block->Next()->Prev( block );
    }
    rep_block->Next( block );
    block->Prev( rep_block );
    current_block_ = block;
  }
}


template <typename T>
void AstVisitor::ReplaceBlock_( SourceBlock* rep_block , T* node , int type ) {
  InsertBlock_<T>( rep_block , node , type );
  if ( type == kPrev ) {
    current_block_->Next( rep_block->Next() );
    if ( rep_block->HasNext() ) {
      rep_block->Next()->Prev( current_block_ );
    }
    rep_block->Prev( 0 );
  } else if ( type == kNext ) {
    current_block_->Prev( rep_block->Prev() );
    if ( rep_block->HasPrev() ) {
      rep_block->Prev()->Next( current_block_ );
    }
    rep_block->Next( 0 );
  }
}


VariableDeclaration* AstVisitor::CreateVariableDecl_( const char* ident , AstTypeBase* opt_val ) {
  VariableDeclaration* var = ManagedHandle::Retain( new VariableDeclaration( ident ) );
  if ( AstUtil::IsValidAst( opt_val ) ) {
    var->Value( opt_val );
  } else {
    var->Value( ManagedHandle::Retain<Empty>() );
  }
  return var;
}


ArrayAccessor* AstVisitor::CreateArrayAccessor_( AstTypeBase* exp , AstTypeBase* access ) {
  return ManagedHandle::Retain( new ArrayAccessor( Constant::kBracket , exp , access ) );
}

NumberLiteral* AstVisitor::CreateNumberLiteral_( int num ) {
  char tmp[ 500 ];
  sprintf( tmp , "%d" , num );
  NumberLiteral* num_lit = ManagedHandle::Retain( new NumberLiteral( tmp ) );
  return num_lit;
}


void AstVisitor::CreateRecrusivDstAccessor_( AstTypeBase* node_base , AstTypeBase* exp , VariableDeclarationList *vars ) {
  DestructuringArray* array = node_base->CastToDstArray();
  DestructuringObject* object = node_base->CastToDstObject();
  if ( AstUtil::IsValidAst( array ) ) {
    AstList list = array->Value()->List();
    AstList::iterator ITERATOR( list );
    int count = 0;
    ArrayAccessor* result;
    while ( begin != end ) {
      NumberLiteral* num_lit = CreateNumberLiteral_( count );
      ArrayAccessor* array_accessor = CreateArrayAccessor_( exp , num_lit );
      CreateRecrusivDstAccessor_( (*begin) , array_accessor , vars );
      ConstantLiteral* literal = (*begin)->CastToLiteral();
      if ( AstUtil::IsValidAst( literal ) ) {
        Identifier* name = literal->CastToIdentifier();
        if ( AstUtil::IsValidAst( name ) ) {
          VariableDeclaration* decl = CreateVariableDecl_( name->Value() , array_accessor );
          vars->List( decl );
        }
      }
      count++;
      ++begin;
    }
  } else if ( AstUtil::IsValidAst( object ) ) {
    DstoMemList list = object->List();
    DstoMemList::iterator ITERATOR( list );
    while ( begin != end ) {
      ArrayAccessor* array_accessor = CreateArrayAccessor_( exp , (*begin)->Left() );
      CreateRecrusivDstAccessor_( (*begin) , array_accessor , vars );
      ConstantLiteral* literal = (*begin)->Right()->CastToLiteral();
      if ( AstUtil::IsValidAst( literal ) ) {
        Identifier* name = literal->CastToIdentifier();
        if ( AstUtil::IsValidAst( name ) ) {
          VariableDeclaration* decl = CreateVariableDecl_( name->Value() , array_accessor );
          vars->List( decl );
        }
      }
      ++begin;
    }
  }
}

void AstVisitor::CreateDstAssignment_( AstTypeBase* ast , AstTypeBase* value ) {
  VariableDeclarationList* vars = ManagedHandle::Retain<VariableDeclarationList>();
  VariableDeclaration* tmp_ref = CreateVariableDecl_( CreateTmpIdent_() , value );
  Identifier* name = ManagedHandle::Retain( new Identifier( tmp_ref->Name() ) );
  vars->List( tmp_ref );

  CreateRecrusivDstAccessor_( ast , name , vars );
  InsertBlock_<VariableDeclarationList>( current_block_ , vars );
}

const char* AstVisitor::CreateTmpIdent_() {
  char tmp[100];
  sprintf( tmp , "__tmp__%d" , tmp_index_ );
  tmp_index_++;
  char* ret = new char[ strlen( tmp ) + 1 ];
  strcpy( ret , tmp );
  char_handle_.Retain( ret );
  return ret;
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

}
