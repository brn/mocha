#include <math.h>
#include "ast_type.h"
#include "scope.h"

using namespace mocha;
using namespace std;

const char Constant::constants_[][15] = {
  "+",
  "-",
  "*",
  "/",
  "%",
  "|",
  "^",
  "&",
  "<",
  ">",
  "<=",
  ">=",
  "<<",
  ">>",
  ">>>",
  "!==",
  "===",
  "=",
  "+=",
  "-=",
  "*=",
  "/=",
  "%=",
  "<<=",
  ">>=",
  ">>>=",
  "&=",
  "^=",
  "|=",
  "~",
  "++",
  "--",
  "delete ",
  "void",
  "typeof ",
  "!",
  "instanceof ",
  " in ",
  "&&",
  "||",
  "()",
  "[]",
  ".",
  "new"
};

AstTypeBase::AstTypeBase () :
    Managed () , is_primitive_ ( false ) , line_number_ ( 0 ) , name_ ( "AstTypeBase" ) {};
    
AstTypeBase::AstTypeBase ( const char* name ) :
    Managed () ,is_primitive_ ( false ) ,line_number_ ( 0 ) , name_ ( name ) {}
    
AstTypeBase::AstTypeBase ( long int line ) :
    Managed () ,is_primitive_ ( false ) ,line_number_ ( line ) , name_ ( "AstTypeBase" ){}

AstTypeBase::AstTypeBase ( long int line , const char* name ) :
    Managed () ,is_primitive_ ( false ) ,line_number_ ( line ) , name_ ( name ){}
    

typedef AstTypeBase Base;
AstRoot::AstRoot () : tree_ ( 0 ) {}


///////////////////
// class AstTree //
///////////////////
AstTree::AstTree () :
    Base ( "AstTree" ) , empty_handle_( new Empty() ) , block_handle_( new SourceBlock( empty_handle_.Get() ) ){
  head_ = block_handle_.Get();
  current_ = head_;
};

void AstTree::AddBlock( SourceBlock* block )  {
  block->bprev_ = current_;
  current_->bnext_ = block;
  current_ = block;
}

///////////////////////
// class SourceBlock //
///////////////////////
#define CONSTRUCT(type) SourceBlock::SourceBlock ( type* ast ) : bnext_( 0 ), bprev_( 0 ), block_ ( ast ) , type_ ( k##type ) {}

CONSTRUCT(Block);
CONSTRUCT(VariableDeclarationList);
CONSTRUCT(Expression);
CONSTRUCT(ExpressionStmt);
CONSTRUCT(IFStmt);
CONSTRUCT(Iteration);
CONSTRUCT(Continue);
CONSTRUCT(Break);
CONSTRUCT(Return);
CONSTRUCT(With);
CONSTRUCT(Label);
CONSTRUCT(Switch);
CONSTRUCT(Throw);
CONSTRUCT(Try);
CONSTRUCT(Empty);
CONSTRUCT(Function);
CONSTRUCT(Module);
CONSTRUCT(ExportStmt);
CONSTRUCT(LetStmt);

#undef CONSTRUCT

/////////////////
// class Empty //
/////////////////

Empty::Empty () : Base ( "Empty" ) {};

//////////////////
// class Symbol //
//////////////////

Symbol::Symbol ( const char* ident ) :
    AstTypeBase ( "Symbol" ) , ident_ ( ident ) , type_ ( Symbol::Uninitialized ) , is_declared_ ( 0 ), value_ ( 0 ) {};

Symbol::Symbol () :
    AstTypeBase ( "Symbol" ) , ident_ ( 0 ) , type_ ( Symbol::Uninitialized ) , is_declared_ ( 0 ), value_ ( 0 ) {};

Symbol& Symbol::operator = ( const Symbol& symbol_ ) {
  ident_ = symbol_.ident_;

  if ( !symbol_.shorten_name_.empty () ) {
    shorten_name_ = symbol_.shorten_name_;
  } else {
    shorten_name_.erase ();
  }
  type_ = symbol_.type_;
  is_declared_ = symbol_.is_declared_;
  return (*this);
}

////////////////
// class Tree //
////////////////
Tree::Tree ( Constant::ConstantType op , pBase left , pBase right , const char* type ) :
  Base ( type ) , left_ ( left ), right_ ( right ), operand_ ( op ) , prior_ ( Tree::kLeft ) {};

Tree::Tree ( pBase exp , pBase left , pBase right , const char* type ) :
  Base ( type ) , left_ ( left ), right_ ( right ), exp_ ( exp ) , prior_ ( Tree::kLeft ) {};

#define EXTENDS_TREE_CONSTRUCTOR(name,type)                             \
  name::name ( type arg1 , pBase arg2 , pBase arg3 ) : Tree ( arg1 , arg2 , arg3 , #name ) {} \

EXTENDS_TREE_CONSTRUCTOR( ArrayAccessor , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( DotAccessor , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( NewCallAccessor , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( NewAccessor , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( CallAccessor , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( PostfixExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( UnaryExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( MultiplicativeExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( AdditiveExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( ShiftExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( RelationalExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( EqualityExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( BitwiseANDExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( BitwiseXORExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( BitwiseORExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( LogicalANDExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( LogicalORExp , Constant::ConstantType );
EXTENDS_TREE_CONSTRUCTOR( ConditionalExp , pBase );
EXTENDS_TREE_CONSTRUCTOR( Assign , Constant::ConstantType );

#undef EXTENDS_TREE_CONSTRUCTOR

////////////////////
// class Function //
////////////////////
Function::Function ( const char* ident ) :
    Base ( "Function" ) , is_const_( false ) , argv_ ( 0 ) , ident_ ( ident ) , body_ ( 0 ), scope_ ( 0 ){};


///////////////////////////
// class FormalParameter //
///////////////////////////
FormalParameter::FormalParameter () : Base ( "FormalParameter" ) , argc_ ( 0 ) {}

///////////////////////////////
// class VariableDeclaration //
///////////////////////////////
VariableDeclaration::VariableDeclaration ( const char* ident ) :
    Base ( "VariableDeclaration" ) , val_ ( 0 ) { name_ = ident; };


///////////////////////////////////
// class VariableDecalrationList //
///////////////////////////////////
VariableDeclarationList::VariableDeclarationList () : Base ( "VariableDeclarationList" ) {};

////////////////////
// class StmtList //
////////////////////
StmtList::StmtList () : Base ( "StmtList" ) {}


////////////////////////
// class ArrayLiteral //
////////////////////////
ArrayLiteral::ArrayLiteral () : Base ( "ArrayLiteral" ) , val_ ( 0 ){}


/////////////////////////
// class ObjectLiteral //
/////////////////////////
ObjectLiteral::ObjectLiteral ( AstTypeBase* member ) : Base ( "ObjectLiteral" ) , member_ ( member ){}


///////////////////////
// class ElementList //
///////////////////////
ElementList::ElementList () : Base ( "ElementList" ) {}


////////////////////////
// class ObjectMember //
////////////////////////
ObjectMember::ObjectMember () : Base ( "ObjectMember" ) {}


/////////////////////
// class Arguments //
/////////////////////
Arguments::Arguments () : Base ( "Arguments" ) {};



//////////////////////
// class Expression //
//////////////////////
ExpressionStmt::ExpressionStmt () : Base ( "ExpressionStmt" ) {}



//////////////////////
// class Expression //
//////////////////////
Expression::Expression () : Base ( "Expression" ) , paren_ ( false ) {}


//////////////////
// class IFStmt //
//////////////////
IFStmt::IFStmt () :
  Base ( "IFStmt" ) , then_ ( 0 ) , body_ ( 0 ) , elseb_ ( 0 ){}


///////////////////
// class DoWhile //
///////////////////
DoWhile::DoWhile () : 
  Base ( "DoWhile" ) , body_ ( 0 ) , condition_ ( 0 ){}


/////////////////
// class While //
/////////////////
While::While () :
  Base ( "While" ) , body_ ( 0 ) , condition_ ( 0 ){}


/////////////////////
// class Iteration //
/////////////////////
#define CONSTRUCT(type) Iteration::Iteration ( type* ast ) : ast_ ( ast ) {}

CONSTRUCT(For);
CONSTRUCT(ForIn);
CONSTRUCT(While);
CONSTRUCT(DoWhile);
CONSTRUCT(ForEach);
#undef CONSTRUCT

///////////////
// class For //
///////////////
For::For () :
  Base ( "For" ) , index_ ( 0 ) , condition_ ( 0 ) , increment_ ( 0 ),
  is_var_decl_ ( false ) , body_ ( 0 ){}


/////////////////
// class ForIn //
/////////////////
ForIn::ForIn () :
  Base ( "ForIn" ) , item_ ( 0 ) , target_ ( 0 ) , body_ ( 0 ),
  is_var_decl_ ( false ) {}


////////////////////
// class Continue //
////////////////////
Continue::Continue ( const char* ident ) : Base ( "Continue" ) , ident_ ( ident ) {}


/////////////////
// class Break //
/////////////////
Break::Break ( const char* ident ) : Base ( "Break" ) , ident_ ( ident ) {}


////////////////////
// class Return   //
////////////////////
Return::Return () : Base ( "Return" ) , exp_ ( 0 ) {}


////////////////
// class With //
////////////////
With::With () : Base ( "With" ) , exp_ ( 0 ), body_ ( 0 ) {}


//////////////////
// class Switch //
//////////////////
Switch::Switch () : Base ( "Switch" ) , block_ ( 0 ) , exp_ ( 0 ){}


/////////////////
// class Block //
/////////////////
Block::Block () : Base ( "Block" ) , value_ ( 0 ) {};


//////////////////////
// class CaseClauses //
//////////////////////
CaseClauses::CaseClauses () : Base ( "CaseClauses" ) {}


//////////////////////
// class CaseClause //
//////////////////////
CaseClause::CaseClause () : Base ( "CaseClause" ) , exp_ ( 0 ), body_ ( 0 ) {}


/////////////////////////
// class DefaultClause //
/////////////////////////
DefaultClause::DefaultClause () : Base ( "DefaultClause" ) , body_ ( 0 ) {}


/////////////////
// class Label //
/////////////////
Label::Label ( const char* ident ) : Base ( "Label" ) , ident_ ( ident ) , body_ ( 0 ) {}


/////////////////
// class Throw //
/////////////////
Throw::Throw () : Base ( "Throw" ) , exp_ ( 0 ) {}


///////////////
// class Try //
///////////////
Try::Try () :
  Base ( "Try" ) , body_ ( 0 ),
  catchbody_ ( 0 ) , finallybody_ ( 0 ) {}


/////////////////
// class Catch //
/////////////////
Catch::Catch ( const char* ident ) : Base ( "Catch" ) , ident_ ( ident ) , body_ ( 0 ) {}


///////////////////
// class Finally //
///////////////////
Finally::Finally () : Base ( "Finally" ) , body_ ( 0 ) {};


