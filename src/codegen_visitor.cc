#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include "ast_type.h"
#include "codegen_visitor.h"

using namespace std;
using namespace mocha;

#define VISITOR_IMPL(type) void CodegenVisitor::operator () ( type* ast_node )

#define ACCEPT( ast )                           \
  if ( ast != 0 )                               \
    ast->Accept(this)

#define ACCEPT_ITER(iter)                       \
  if ( (*iter) != 0 )                           \
    (*iter)->Accept(this)

#define WRITE(str)                              \
    Write_ ( str );                             \

#define WRITE_ITER(iter)                        \
  {const char* ret = (*iter);                   \
  if ( ret != 0 &&                              \
       strlen (ret) > 0 ) {                     \
    Write_ ( ret );                             \
  }}

#define WRITE_LINE(ast)                           \
  if ( ast->LineNumber () > 0 ){                  \
    WriteLine ( ast->LineNumber () );             \
  }

#define INDENT "  "
#define BREAK result_ += '\n'
#define INDENT result_ += indent_
#define ADD_INDENT indent_ += indent_spaces_
#define ADD_INDENT_OF(str) indent_ += str
#define SPACE result_ += ' '
#define REM_INDENT(num) indent_.erase( indent_.size() - num , indent_.size() )

typedef AstTypeBase* Base;
typedef list<AstTypeBase*> BaseList;
typedef list<AstTypeBase*>::iterator BaseIter;
typedef list<pair<const char* , AstTypeBase*> > BaseMap;
typedef list<pair<const char* , AstTypeBase*> >::iterator BaseMapIter;


CodegenVisitor::CodegenVisitor () {
  WRITE("(function(){");
  BREAK;
  ADD_INDENT;
  INDENT;
  WRITE("var __global_exports = {};");
  BREAK;
  INDENT;
}

VISITOR_IMPL( AstRoot ) {
  std::list<AstTypeBase*>::iterator begin = ast_node->Tree().begin();
  std::list<AstTypeBase*>::iterator end = ast_node->Tree().end();
  while ( begin != end ) {
    (*begin)->Accept ( this );
    ++begin;
  }
  result_.erase( result_.size() - 2 , result_.size() );
  WRITE("})();");
}

VISITOR_IMPL( RootBlock ) {
  ACCEPT( ast_node->Root() );
}


VISITOR_IMPL(AstTree) {
  std::list<SourceBlock*> list = ast_node->List ();
  std::list<SourceBlock*>::iterator it = list.begin ();
  std::list<SourceBlock*>::iterator end = list.end ();
  
  while ( it != end ) {
    ACCEPT_ITER(it);
    BREAK;
    INDENT;
    it++;
  }
}

VISITOR_IMPL(UnaryExp) {  
  Constant::ConstantType op = ast_node->Operand();
  WRITE(Constant::GetConstant( op ));
  ACCEPT(ast_node->Left());
}

VISITOR_IMPL(ArrayAccessor) {  
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  ACCEPT(left);
  WRITE("[");
  ACCEPT(right);
  WRITE("]");
}


VISITOR_IMPL(DotAccessor) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  ACCEPT(left);
  WRITE(".");
  ACCEPT(right);
}


VISITOR_IMPL(NewCallAccessor) {
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  Arguments *arg = reinterpret_cast<Arguments*>( right );
  int size = arg->Value().size();
  if ( size == 0 ) {
    WRITE('(');
  }
  WRITE("new ");
  ACCEPT(left);
  if ( size == 0 ) {
    WRITE(')');
  } else {
    WRITE("(");
    ACCEPT(right);
    WRITE(")");
  }
}

VISITOR_IMPL(NewAccessor) {
  Base left = ast_node->Left ();
  Base right = ast_node->Right ();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  WRITE("new ");
  ACCEPT(left);
  ACCEPT(right);
}


VISITOR_IMPL(CallAccessor) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  ACCEPT(left);
  WRITE("(");
  ACCEPT(right);
  WRITE(")");
}


VISITOR_IMPL(PostfixExp) {
  Base left = ast_node->Left();
  assert( AstUtil::IsValidAst( left ) );
  ACCEPT( left );
  WRITE(Constant::GetConstant( ast_node->Operand() ));
}


VISITOR_IMPL(MultiplicativeExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  ACCEPT( left );
  SPACE;
  WRITE(Constant::GetConstant(ast_node->Operand()));
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(AdditiveExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE(Constant::GetConstant( ast_node->Operand() ));
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(ShiftExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE(Constant::GetConstant( ast_node->Operand() ));
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(RelationalExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(EqualityExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(BitwiseANDExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );
  SPACE; 
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(BitwiseXORExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(BitwiseORExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(LogicalANDExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(LogicalORExp) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  
  ACCEPT( left );
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT( right );
}


VISITOR_IMPL(ConditionalExp) {
  Base exp = ast_node->Exp ();
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( exp ) );
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );
  ACCEPT(exp);
  WRITE("?");
  SPACE;
  ACCEPT(left);
  SPACE;
  WRITE(":");
  SPACE;
  ACCEPT(right);
}


VISITOR_IMPL(Assign) {
  Base left = ast_node->Left();
  Base right = ast_node->Right();
  assert( AstUtil::IsValidAst( left ) );
  assert( AstUtil::IsValidAst( right ) );

  ACCEPT(left);
  SPACE;
  WRITE( Constant::GetConstant( ast_node->Operand() ) );
  SPACE;
  ACCEPT(right);
}

VISITOR_IMPL(Function){
  Base args = ast_node->Argv ();
  const char* ident = ast_node->Ident ();
  Base body = ast_node->Body ();
  if ( ident ) {
    WRITE("function ");
  } else {
    WRITE("function");
    SPACE;
  }
  WRITE(ident);
  WRITE('(');
  ACCEPT(args);
  WRITE(')');
  SPACE;
  WRITE('{');
  BREAK;
  ADD_INDENT;
  INDENT;
  ACCEPT(body);
  REM_INDENT(2);
  result_.erase( result_.size() - 2 , result_.size() );
  WRITE('}');
};


VISITOR_IMPL(FormalParameter){
  if ( ast_node->Argc () > 0 ) {
    list<const char*> args = ast_node->Args ();
    list<const char*>::iterator it = args.begin ();
    list<const char*>::iterator end = args.end ();
    while ( it != end ) {
      //Set arguments to indexed array and hash map.
      WRITE_ITER(it);
      ++it;
      if ( it != end ) {
        WRITE(',');
        SPACE;
      }
    }
  }
}


VISITOR_IMPL(VariableDeclaration){
  Base ast = ast_node->Value ();
  const char* name = ast_node->Name ();
  Base value = ast_node->Value();
  WRITE(name);
  if ( !value->IsEmptyNode() ) {
    SPACE;
    WRITE('=');
    SPACE;
    ACCEPT(ast_node->Value());
  }
}

VISITOR_IMPL(VariableDeclarationList) {
  BaseIter it = ast_node->List ().begin ();
  BaseIter end = ast_node->List ().end ();
  WRITE("var ");
  ADD_INDENT_OF("    ");
  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
    if ( it != end ) {
      WRITE(',');
      if ( State_() != kForCond ) {
        BREAK;
        INDENT;
      }
    }
  }
  if ( ast_node->IsTerminate() || State_() == kForCond ) {
    REM_INDENT(4);
    if ( State_() != kForCond ) {
      WRITE(';');
    }
  }
}

VISITOR_IMPL(StmtList) {
  BaseList l = ast_node->List ();
  BaseIter it = l.begin ();
  BaseIter end = l.end ();
  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
    if ( it != end ) {
      BREAK;
      INDENT;
    }
  }
}


VISITOR_IMPL(ArrayLiteral){
  WRITE('[');
  SPACE;
  ACCEPT(ast_node->Value());
  SPACE;
  WRITE(']');
}


VISITOR_IMPL(ObjectLiteral){
  WRITE('{');
  ACCEPT(ast_node->Value());
  WRITE('}');
}


VISITOR_IMPL(ElementList){
  BaseList list = ast_node->Value ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();  
  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
    if ( it != end ) {
      WRITE( ',' );
      SPACE;
    }
  }
}


VISITOR_IMPL(ObjectMember){
  ObjectMember::MemberList m = ast_node->Value ();
  ObjectMember::MemberList::iterator it = m.begin ();
  ObjectMember::MemberList::iterator end = m.end ();
  ADD_INDENT;
  while ( it != end ) {
    BREAK;
    INDENT;
    ACCEPT((*it).first);
    SPACE;
    WRITE(':');
    SPACE;
    ACCEPT((*it).second);
    ++it;
    if ( it != end ) {
      WRITE(',');
    } else {
      REM_INDENT(2);
      BREAK;
      INDENT;
    }
  }
}


VISITOR_IMPL(Arguments){
  BaseList list = ast_node->Value ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();

  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
    if ( it != end ) {
      WRITE( ',' );
      SPACE;
    }
  }
}

VISITOR_IMPL(Block) {
  Base value = ast_node->Value();
  SPACE;
  WRITE('{');
  BREAK;
  ADD_INDENT;
  INDENT;
  ACCEPT( value );
  BREAK;
  REM_INDENT(2);
  INDENT;
  WRITE('}');
};


VISITOR_IMPL(ExpressionStmt) {
  Expression* exp = ast_node->Exp();
  assert( AstUtil::IsValidAst( exp ) );
  ACCEPT( exp );
  WRITE(';');
}


VISITOR_IMPL(Expression){
  BaseList list = ast_node->List ();
  BaseIter it = list.begin ();
  BaseIter end = list.end ();
  bool isparen = ast_node->Paren ();
  
  if ( isparen ) {
    WRITE( '(' );
  }
  while ( it != end ) {
    
    ACCEPT_ITER(it);
    it++;
    if ( it != end ) {
      WRITE(',');
      SPACE;
    }
  }
  if ( isparen ) {
    WRITE( ')' );
  }
}


VISITOR_IMPL(IFStmt){
  Base then_exp = ast_node->Then();
  Base block_body = ast_node->Body();
  Base else_block = ast_node->Else();

  WRITE( "if" );
  SPACE;
  WRITE( '(' );
  ACCEPT(then_exp);
  WRITE( ')' );
  SourceBlock* body = reinterpret_cast<SourceBlock*>( block_body );
  if ( body->Type() != SourceBlock::kBlock ) {
    BREAK;
    ADD_INDENT;
    INDENT;
    ACCEPT(block_body);
    result_.erase( result_.size() - 2 , result_.size() );
  } else {
    ACCEPT(block_body);
  }
  
  if ( AstUtil::IsValidAst( else_block ) ) {
    SPACE;
    State_( kElse );
    SourceBlock* block = reinterpret_cast<SourceBlock*>( else_block );
    if ( block->Type() != SourceBlock::kBlock && block->Type() != SourceBlock::kIFStmt ) {
      WRITE( "else" );
      BREAK;
      ADD_INDENT;
      INDENT;
      ACCEPT(else_block);
      REM_INDENT(2);
    } else if ( block->Type() == SourceBlock::kIFStmt ) {
      WRITE( "else " );
      ACCEPT(else_block);
    } else {
      WRITE( "else" );
      ACCEPT(else_block);
    }
    State_( kNone );
  }
}



VISITOR_IMPL(DoWhile) {
  Base body_block = ast_node->Body();
  Base cond_exp = ast_node->Condition();

  WRITE( "do" );
  ACCEPT(body_block);
  WRITE( "while" );
  SPACE;
  WRITE( '(' );
  ACCEPT(cond_exp);
  WRITE( ')' );
  WRITE( ';' );
}


VISITOR_IMPL(While) {
  Base cond_exp = ast_node->Condition();
  Base body_block = ast_node->Body();

  WRITE( "while" );
  SPACE;
  WRITE( '(' );
  ACCEPT(cond_exp);
  WRITE( ')' );
  ACCEPT( body_block );
}

VISITOR_IMPL(For) {
  Base index_exp = ast_node->Index();
  Base cond_exp = ast_node->Condition();
  Base incr_exp = ast_node->Increment();
  Base body_block = ast_node->Body();
  
  WRITE( "for" );
  SPACE;
  WRITE( '(' );
  State_( kForCond );
  ACCEPT( index_exp );
  State_( kNone );
  WRITE( ';' );
  SPACE;

  ACCEPT( cond_exp );
  WRITE( ';' );
  SPACE;

  ACCEPT( incr_exp );
  WRITE( ')' );
  ACCEPT(body_block);
}

VISITOR_IMPL(ForIn) {
  Base item_exp = ast_node->Item();
  Base target_exp = ast_node->Target();
  Base body_block = ast_node->Body();

  WRITE( "for" );
  SPACE;
  WRITE( '(' );
  State_( kForCond );
  ACCEPT( item_exp );
  State_( kNone );
  WRITE( " in " );
  ACCEPT( target_exp );
  WRITE( ')' )
  ACCEPT(body_block);
}


VISITOR_IMPL(Continue) {
  const char* ident = ast_node->Ident();
  bool has_ident = ident && strlen( ident ) > 0;
  if ( has_ident ) {
    WRITE( "continue " );
  } else {
    WRITE( "continue;" );
  }
  WRITE(ident);
  if ( has_ident ) {
    WRITE(';');
  }
}

VISITOR_IMPL(Break) {
  const char* ident = ast_node->Ident();
  bool has_ident = ident && strlen( ident ) > 0;
  if ( has_ident ) {
    WRITE( "break " );
  } else {
    WRITE( "break;" );
  }
  WRITE(ident);
  if ( has_ident ) {
    WRITE( ';' );
  }
}


VISITOR_IMPL(Return) {
  Base exp = ast_node->Expression();
  if ( exp->IsEmptyNode() ) {
    WRITE( "return" );
  } else {
    WRITE( "return " );
  }
  ACCEPT(exp);
  WRITE( ';' );
}

VISITOR_IMPL(With) {
  Base exp = ast_node->Expression();
  Base body = ast_node->Body();

  WRITE( "with" );
  SPACE;
  WRITE( '(' );
  ACCEPT(exp);
  WRITE( ')' );
  ACCEPT(body);
}


VISITOR_IMPL(Switch) {
  Base exp = ast_node->Expression();
  Base case_block = ast_node->CaseBlock();

  WRITE( "switch" );
  SPACE;
  WRITE( '(' );
  ACCEPT(exp);
  WRITE( ')' );
  ACCEPT(case_block);
}

VISITOR_IMPL(CaseClauses) {
  BaseList list = ast_node->List ();
  BaseIter it = list.begin();
  BaseIter end = list.end ();
  SPACE;
  WRITE( '{' );
  BREAK;
  ADD_INDENT;
  INDENT;
  while ( it != end ) {
    ACCEPT_ITER(it);
    it++;
  }
  REM_INDENT(2);
  BREAK;
  INDENT;
  WRITE('}');
}

VISITOR_IMPL(CaseClause) {
  Base exp = ast_node->Expression();
  Base body = ast_node->Body();

  WRITE( "case " );
  ACCEPT(exp);
  SPACE;
  WRITE( ':' );
  BREAK;
  StmtList* list = reinterpret_cast<StmtList*>( body );
  if ( list->List().begin() != list->List().end() ) {
    ADD_INDENT;
    INDENT;
    ACCEPT(body);
    REM_INDENT(2);
  } else {
    INDENT;
  }
}



VISITOR_IMPL(DefaultClause) {
  Base body = ast_node->Body();

  WRITE( "default" );
  SPACE;
  WRITE( ':' );
  BREAK;
  ADD_INDENT;
  INDENT;
  ACCEPT(body);
  REM_INDENT(2);
}

VISITOR_IMPL(Label) {
  const char* ident = ast_node->Ident();
  Base stmt = ast_node->Body();

  WRITE( ident );
  SPACE;
  WRITE( ':' );
  SPACE;
  ACCEPT(stmt);
}


VISITOR_IMPL(Throw) {
  Base exp = ast_node->Expression();
  WRITE( "throw " );
  ACCEPT(exp);
  WRITE( ';' );
}


VISITOR_IMPL(Try) {
  Base try_body = ast_node->Body();
  Base catch_body = ast_node->CatchBody ();
  Base finally_body = ast_node->FinallyBody ();

  WRITE("try");
  SPACE;
  ACCEPT( try_body );
  if ( AstUtil::IsValidAst( catch_body ) ) {
    ACCEPT( catch_body );
  }
  if ( AstUtil::IsValidAst( finally_body ) ) {
    ACCEPT( finally_body );
  }
}



VISITOR_IMPL(Catch){
  const char* ident = ast_node->Ident();
  Base body_block = ast_node->Body();
  WRITE( "catch" );
  SPACE;
  WRITE( '(' );
  WRITE( ident );
  WRITE( ')' );
  ACCEPT(body_block);
}


VISITOR_IMPL(Finally) {
  WRITE( "finally " );
  ACCEPT(ast_node->Block());
}


VISITOR_IMPL(ConstantLiteral) {
  This* this_literal = ast_node->CastToThis ();
  StringLiteral* string_literal = ast_node->CastToStringLiteral ();
  BooleanLiteral* boolean_literal = ast_node->CastToBooleanLiteral ();
  RegExpLiteral* regexp_literal = ast_node->CastToRegExpLiteral ();
  NullLiteral* null_literal = ast_node->CastToNullLiteral ();
  UndefinedLiteral* undefined_literal = ast_node->CastToUndefinedLiteral ();
  Identifier* ident_literal = ast_node->CastToIdentifier ();
  PropertyName* property_name = ast_node->CastToPropertyName ();
  WRITE( ast_node->Value () );
  /**
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
    WRITE(ident_literal->Value());
  } else if ( AstUtil::IsValidAst( property_name ) ) {
    WRITE(property_name->Value());
  } else {
    WRITE( ast_node->Value () );
    }**/
}

void CodegenVisitor::Write_( const char* str ) {
  if ( str && strlen( str ) > 0 ) {
    result_ += str;
  }
}

void CodegenVisitor::Write_( char str ) {
  result_ += str;
}

const char CodegenVisitor::indent_spaces_[] = { "  " };
