#ifndef AstType_h
#define AstType_h

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <utility>
#include <list>
#include "define.h"
#include "ivisitor.h"
#include "managed.h"

//Macro that declare Accept virtual member function.
//Function Accept call each Ast visitro function that
//named ast name + Fn.
#define DECL_ACCEPT(name)                               \
  inline virtual void Accept ( IVisitor* visitor ) {  \
    (*visitor)( this );                                 \
  }

//Macro that declare setter member function.
//Setter function declare as 1st arguments name,
//2nd arguments define arguments types and
//3rd arguments define data member.
#define DECL_SET(name,arg_type,var_name )               \
  inline void name ( arg_type args ) { var_name=args; }

//Macro that declare setter member function for std::list.
//Usage is almost same DECL_SET.
#define DECL_SET_LIST(name,arg_type,var_name)                       \
  inline void name ( arg_type args ) { var_name.push_back(args); }

//Macro that declare getter member function.
//Getter function declare as 1st arguments name,
//2nd arguments define return types and
//3rd arguments define data member.
#define DECL_GET(name,ret_type,var_name)                \
  inline JPM_PURE ret_type name () { return var_name; }

//Macro that declare const getter function.
//Usage is almost same DEC_GET.
#define DECL_CONST_GET(name,ret_type,var_name)                  \
  inline JPM_CONST ret_type name () const { return var_name; }

//Macro that declare getter and setter member function
//in one time.
//Setter and getter function declare as 1st arguments name,
//2nd arguments define arguments and return types and
//3rd arguments define data member.
#define DECL_GET_SET(name , type , var_name )   \
  DECL_SET(name,type,var_name);                 \
  DECL_GET(name,type,var_name)

//Macro that declare getter and setter member function for std::list.
//Usage is almost same DECL_GET_SET.
#define DECL_GET_SET_LIST(name , type , var_name )  \
  DECL_SET_LIST(name,type,var_name);                \
  DECL_GET(name,std::list<type>&,var_name)

//Macro that declare class that inherit base class.
//1st arguments define class name and,
//2nd arguments define base class name.
#define EXTENDS(name,ext) class name : public ext
//Macro that declare class that inherit class AstTypeBase.
#define EXTENDS_BASE(name) EXTENDS(name,AstTypeBase)

//begin mocha
namespace mocha{

//begin AstUtil
namespace AstUtil {
/**
 *@public
 *@param {T}
 *Template function.
 *Check is that passed object is valid pointer.
 *Arguments must be result of cast member function of AstTypeBase.
 */
template <typename T>
bool IsValidAst ( T* ast ) {
  //Check is cast success.
  return ( ast != 0 );
};
}

/**
 *@class
 *Manage operand string.
 */
class Constant {
 public :
  typedef enum {
    kPlus = 1,
    kMinus = 2,
    kMul = 3,
    kDiv = 4,
    kMod = 5,
    kOR = 6,
    kXOR = 7,
    kAND = 8,
    kLess = 9,
    kGreater = 10,
    kLessEq = 11,
    kGreaterEq = 12,
    kShiftLeft = 13,
    kShiftRight = 14,
    kUShiftRight = 15,
    kNotEq = 16,
    kEq = 17,
    kAssign = 18,
    kAddLet = 19,
    kSubLet = 20,
    kMulLet = 21,
    kDivLet = 22,
    kModLet = 23,
    kLShiftLet = 24,
    kRShiftLet = 25,
    kURShiftLet = 26,
    kANDLet = 27,
    kNotLet = 28,
    kORLet = 29,
    kNOR = 30,
    kAdd = 31,
    kSub = 32,
    kDelete = 33,
    kVoid = 34,
    kTypeof = 35,
    kNot = 36,
    kInstanceof = 37,
    kIn = 38,
    kLogicalAND = 39,
    kLogicalOR = 40,
    kCall = 41,
    kBracket = 42,
    kDot = 43,
    kNew = 44
  } ConstantType;
  /**
   *@public
   *@static
   *@param {}
   *@returns {const char*}
   *Get operand from anonymous enum.
   */
  static inline const char* GetConstant ( ConstantType type ) { return &constants_ [ ( type - 1 ) ][0]; }
 private :
  static const char constants_[][15];
};

#define FORWARD_DECL(name) class name
FORWARD_DECL(AstVisitor);
FORWARD_DECL(Scope);
FORWARD_DECL(Block);
FORWARD_DECL(VariableDeclarationList);
FORWARD_DECL(Expression);
FORWARD_DECL(ExpressionStmt);
FORWARD_DECL(IFStmt);
FORWARD_DECL(Iteration);
FORWARD_DECL(Continue);
FORWARD_DECL(Break);
FORWARD_DECL(Return);
FORWARD_DECL(With);
FORWARD_DECL(Label);
FORWARD_DECL(Switch);
FORWARD_DECL(Throw);
FORWARD_DECL(Try);
FORWARD_DECL(Empty);
FORWARD_DECL(Function);
FORWARD_DECL(For);
FORWARD_DECL(ForIn);
FORWARD_DECL(While);
FORWARD_DECL(DoWhile);
FORWARD_DECL(ArrayAccessor);
FORWARD_DECL(DotAccessor);
FORWARD_DECL(NewCallAccessor);
FORWARD_DECL(NewAccessor);
FORWARD_DECL(CallAccessor);
FORWARD_DECL(PostfixExp);
FORWARD_DECL(UnaryExp);
FORWARD_DECL(MultiplicativeExp);
FORWARD_DECL(AdditiveExp);
FORWARD_DECL(ShiftExp);
FORWARD_DECL(RelationalExp);
FORWARD_DECL(EqualityExp);
FORWARD_DECL(BitwiseANDExp);
FORWARD_DECL(BitwiseXORExp);
FORWARD_DECL(BitwiseORExp);
FORWARD_DECL(LogicalANDExp);
FORWARD_DECL(LogicalORExp);
FORWARD_DECL(ConditionalExp);
FORWARD_DECL(Assign);
FORWARD_DECL(NumberLiteral);
FORWARD_DECL(This);
FORWARD_DECL(StringLiteral);
FORWARD_DECL(NullLiteral);
FORWARD_DECL(RegExpLiteral);
FORWARD_DECL(BooleanLiteral);
FORWARD_DECL(UndefinedLiteral);
FORWARD_DECL(Identifier);
FORWARD_DECL(PropertyName);
#undef FORWARD_DECL

class AstVisitor;
class Scope;
class Tree;
  
class AstTypeBase : public Managed {
 public :
  AstTypeBase ();
  explicit AstTypeBase ( const char* name );
  explicit AstTypeBase ( long int line );
  explicit AstTypeBase ( long int line , const char* name );
  inline virtual ~AstTypeBase (){};
    
  virtual void Accept ( IVisitor* visitor ) = 0;
  virtual bool IsEmptyNode () { return false;}
  inline void Terminate () { is_terminate_ = true; }
  inline bool IsTerminate () const { return is_terminate_; }
  inline JPM_CONST bool virtual IsPrimary () const { return false; }
  inline virtual Tree* CastToTree () { return 0; }
  inline virtual ConstantLiteral* CastToLiteral () { return 0; }
  inline virtual Block* CastToBlock () { return 0; }
  inline virtual JPM_CONST bool IsPrimitive () const { return is_primitive_; }
  void Print () { printf ( "  %s\n" , name_ ); }
  const char* GetName() { return name_; };
  DECL_GET_SET(LineNumber , long int , line_number_);
 protected :
  bool is_primitive_;
 private:
  long int line_number_;
  bool is_terminate_;
  const char* name_;
};

typedef AstTypeBase* pBase;

EXTENDS_BASE(RootBlock) {
public :
  RootBlock( const char* filename ) { filename_ = filename; };
  DECL_ACCEPT( RootBlock );
  DECL_GET_SET( Root , AstTypeBase* , root_ );
  DECL_GET( Path , const char* , &filename_[0] )
private :
  std::string filename_;
  AstTypeBase* root_;
};

EXTENDS_BASE(SourceBlock) {
public :
#define DECL_CONSTRUCTOR(type) explicit SourceBlock ( type* ast )

  DECL_CONSTRUCTOR(Block);
  DECL_CONSTRUCTOR(VariableDeclarationList);
  DECL_CONSTRUCTOR(Expression);
  DECL_CONSTRUCTOR(ExpressionStmt);
  DECL_CONSTRUCTOR(IFStmt);
  DECL_CONSTRUCTOR(Iteration);
  DECL_CONSTRUCTOR(Continue);
  DECL_CONSTRUCTOR(Break);
  DECL_CONSTRUCTOR(Return);
  DECL_CONSTRUCTOR(With);
  DECL_CONSTRUCTOR(Label);
  DECL_CONSTRUCTOR(Switch);
  DECL_CONSTRUCTOR(Throw);
  DECL_CONSTRUCTOR(Try);
  DECL_CONSTRUCTOR(Empty);
  DECL_CONSTRUCTOR(Function);
    
#undef DECL_CONSTRUCTOR
  DECL_CONST_GET( Type , int , type_ );
  enum {
    kBlock,
    kVariableDeclarationList,
    kExpressionStmt,
    kExpression,
    kIFStmt,
    kIteration,
    kContinue,
    kBreak,
    kReturn,
    kWith,
    kLabel,
    kSwitch,
    kThrow,
    kTry,
    kEmpty,
    kFunction
  };
  inline ~SourceBlock (){};
  inline virtual void Accept ( IVisitor* visitor ) { block_->Accept(visitor); }
private:
  AstTypeBase* block_;
  int type_;
};

EXTENDS_BASE(AstRoot) {
public :
  AstRoot ();
  inline ~AstRoot () {};
  DECL_GET_SET_LIST( Tree , AstTypeBase* , tree_ );
  DECL_ACCEPT(AstRoot);

private:
  std::list<AstTypeBase*> tree_;
};
  
  
EXTENDS_BASE(AstTree) {
public :
  AstTree ();
  inline ~AstTree (){};
    
  DECL_GET_SET_LIST( List , SourceBlock* , tree_ );
  DECL_ACCEPT( AstTree );
private:
  std::list<SourceBlock*> tree_;
};
  
EXTENDS_BASE(Empty) {
public :
  Empty ();
  inline ~Empty () {};
  inline JPM_CONST virtual void Accept ( IVisitor* visitor ) {}
  virtual DECL_GET( IsEmptyNode ,bool ,true );
};

  
  
EXTENDS_BASE(Symbol) {
public :
  Symbol ( const char* ident );
  Symbol ();
  inline ~Symbol () {};
  Symbol& operator = ( const Symbol& symbol );
  typedef enum {
    Uninitialized = 0,
    Decl = 1,
    Use = 2
  }  EncountType;  
  DECL_GET(Ident,const char*,ident_);
  DECL_SET(ShortenName,const char*,shorten_name_);
  DECL_GET(ShortenName,const char*,&shorten_name_[0]);
  DECL_GET_SET(Type,EncountType,type_);
  DECL_GET(IsDeclared,bool,is_declared_==1);
  DECL_GET_SET(Value,pBase,value_);
  
  inline void ToPrimitive () { is_primitive_ = true; }
  inline void CancelDeclare () { is_declared_ = 0; }
  inline void Declare () { is_declared_ = 1; }
    
private:
  const char* ident_;
  std::string shorten_name_;
  EncountType type_;
  bool is_declared_;
  pBase value_;
};
  
#define CAST(type,ret) inline virtual type* CastTo##type (){return ret;} 
#define DECL_TREE_CONSTRUCTOR(name,ftype) name ( ftype arg , pBase left , pBase right )



EXTENDS_BASE(Tree) {
public:
  Tree ( Constant::ConstantType op , pBase left , pBase right , const char* type );
  Tree ( pBase exp , pBase left , pBase right , const char* type );
  inline ~Tree () {};
  DECL_GET_SET( Prior , int , prior_ );
  inline virtual Tree* CastToTree () { return this; };
  DECL_GET(Left,AstTypeBase*,left_);
  DECL_GET(Right,AstTypeBase*,right_);
  DECL_GET(Operand,Constant::ConstantType,operand_);
  DECL_GET(Exp,AstTypeBase* , exp_);
  virtual void Accept( IVisitor* visitor ) = 0;
  CAST(ArrayAccessor,0);
  CAST(DotAccessor,0);
  CAST(NewCallAccessor,0);
  CAST(NewAccessor,0);
  CAST(CallAccessor,0);
  CAST(PostfixExp,0);
  CAST(UnaryExp,0);
  CAST(MultiplicativeExp,0);
  CAST(AdditiveExp,0);
  CAST(ShiftExp,0);
  CAST(RelationalExp,0);
  CAST(EqualityExp,0);
  CAST(BitwiseANDExp,0);
  CAST(BitwiseXORExp,0);
  CAST(BitwiseORExp,0);
  CAST(LogicalANDExp,0);
  CAST(LogicalORExp,0);
  CAST(ConditionalExp,0);
  CAST(Assign,0);
  enum {
    kRight = 1,
    kLeft = 2,
    kExp = 3
  };
protected :
  AstTypeBase* left_;
  AstTypeBase* right_;
  union {
    Constant::ConstantType operand_;
    AstTypeBase* exp_;
  };
  int prior_;
};

#define DECL_TREE_EXTENDS_CLASS(name,ftype)     \
  EXTENDS(name,Tree) {                          \
 public :                                       \
    DECL_TREE_CONSTRUCTOR( name , ftype );      \
    DECL_ACCEPT(name);                          \
    CAST(name,this);                            \
  }

DECL_TREE_EXTENDS_CLASS( ArrayAccessor , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( DotAccessor , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( NewCallAccessor , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( NewAccessor , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( CallAccessor , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( PostfixExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( UnaryExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( MultiplicativeExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( AdditiveExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( ShiftExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( RelationalExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( EqualityExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( BitwiseANDExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( BitwiseXORExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( BitwiseORExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( LogicalANDExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( LogicalORExp , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( Assign , Constant::ConstantType );
DECL_TREE_EXTENDS_CLASS( ConditionalExp , pBase );

#undef CAST
#undef DECL_TREE_CONSTRUCTOR
#undef DECL_TREE_EXTENDS_CLASS

EXTENDS_BASE(Function) {
public :
  Function ( const char* ident );
  inline ~Function () {};
    
  DECL_GET_SET( Argv , pBase , argv_ );
  DECL_GET( Ident , const char* , ident_ );
  DECL_GET_SET( Body , pBase , body_ );
  DECL_GET_SET( FnScope , Scope* ,scope_ );
    
  DECL_ACCEPT( Function );
  
private:
  AstTypeBase* argv_;
  const char* ident_;
  AstTypeBase* body_;
  Scope* scope_;

};

EXTENDS_BASE(FormalParameter) {
public :
  FormalParameter ();
  inline ~FormalParameter () {};
    
  inline int Argc () const { return list_.size (); };
  DECL_GET_SET_LIST( Args , const char* , list_ );
  DECL_ACCEPT(FormalParameter);
  
private:
  int argc_;
  std::list<const char*> list_;
};

EXTENDS_BASE(VariableDeclaration) {
public :
  VariableDeclaration ( const char* ident );
  inline ~VariableDeclaration () {};
    
  DECL_GET( Name , const char* , name_ );
  DECL_GET_SET( Value , AstTypeBase* , val_ );
  DECL_ACCEPT(VariableDeclaration);
private:
  const char* name_;
  AstTypeBase* val_;
};

  
EXTENDS_BASE(VariableDeclarationList) {
public:
  VariableDeclarationList ();
  inline ~VariableDeclarationList (){};
    
  DECL_GET_SET_LIST( List , AstTypeBase* , list_ );
  DECL_ACCEPT(VariableDeclarationList);
private:
  std::list<AstTypeBase*> list_;
};

  
  
EXTENDS_BASE(StmtList) {
public:
  StmtList ();
  inline ~StmtList () {};
    
  DECL_GET_SET_LIST( List , AstTypeBase* , list_ );
  DECL_ACCEPT(StmtList);
private:
  std::list<AstTypeBase*> list_;
};



EXTENDS_BASE(Block) {
public:
  Block ();
  inline ~Block () {};
  DECL_GET_SET( Value , AstTypeBase* , value_ );
  DECL_ACCEPT(Block);
  virtual Block* CastToBlock() { return this; }
private:
  AstTypeBase* value_;
};


EXTENDS_BASE(ConstantLiteral) {
public :
  ConstantLiteral ( const char* literal , const char* name ) : AstTypeBase ( name ), literal_ ( literal ) {}
  DECL_GET(Value,const char*,literal_.c_str());
  inline virtual ConstantLiteral* CastToLiteral () { return this; }
  DECL_ACCEPT(ConstantLiteral);
  inline JPM_CONST virtual bool IsPrimary () const { return true; }
#define CAST(name,val) inline virtual name* CastTo##name () { return val; }
  CAST(This,0);
  CAST(BooleanLiteral,0);
  CAST(RegExpLiteral,0);
  CAST(StringLiteral,0);
  CAST(NullLiteral,0);
  CAST(UndefinedLiteral,0);
  CAST(Identifier,0);
  CAST(PropertyName,0);
private :
  std::string literal_;
};

EXTENDS(Identifier,ConstantLiteral) {
public :
  inline Identifier ( const char* literal ) : ConstantLiteral ( literal , "Identifier" ) {}
  inline ~Identifier () {}
  CAST(Identifier,this);
};

EXTENDS(PropertyName,ConstantLiteral) {
public :
  inline PropertyName ( const char* literal ) : ConstantLiteral ( literal , "PropertyName" ) {}
  inline ~PropertyName () {}
  CAST(PropertyName,this);
};

EXTENDS(NumberLiteral,ConstantLiteral) {
public :
  inline NumberLiteral ( const char* literal ) : ConstantLiteral ( literal , "NumberLiteral" ) {}
  inline ~NumberLiteral () {}
  CAST(NumberLiteral,this);
};

EXTENDS(This,ConstantLiteral) {
public :
  inline This () : ConstantLiteral ( "this" , "This" ) {}
  inline ~This () {}
  CAST(This,this);
};


EXTENDS(StringLiteral,ConstantLiteral) {
public :
  inline StringLiteral ( const char* val ) : ConstantLiteral ( val , "StringLiteral" ) {}
  inline ~StringLiteral () {};
  CAST(StringLiteral,this);
};

EXTENDS(BooleanLiteral,ConstantLiteral) {
public :
  inline BooleanLiteral ( const char* val ) : ConstantLiteral ( val , "BooleanLiteral" ) {}
  inline ~BooleanLiteral () {};
  CAST(BooleanLiteral,this);
};

EXTENDS(RegExpLiteral,ConstantLiteral) {
public :
  inline RegExpLiteral ( const char* val ) : ConstantLiteral ( val , "RegExpLiteral" ) {}
  inline ~RegExpLiteral () {};
  CAST(RegExpLiteral,this);
};


EXTENDS(NullLiteral,ConstantLiteral) {
public :
  inline NullLiteral () : ConstantLiteral ( "null" , "NullLiteral" ) {}
  inline ~NullLiteral () {};
  CAST(NullLiteral,this);
};

EXTENDS(UndefinedLiteral,ConstantLiteral) {
public :
  inline UndefinedLiteral () : ConstantLiteral ( "undefined" , "UndefinedLiteral" ) {}
  inline ~UndefinedLiteral () {};
  CAST(UndefinedLiteral,this);
};

EXTENDS_BASE(ObjectLiteral) {
public :
  ObjectLiteral ( AstTypeBase* member );
  inline ~ObjectLiteral () {}
  inline JPM_CONST virtual bool IsPrimary () const { return true; }
  DECL_GET(Value,pBase,member_);
  DECL_ACCEPT(ObjectLiteral);
private :
  pBase member_;
};


EXTENDS_BASE(ArrayLiteral) {
public:
  ArrayLiteral ();
  inline ~ArrayLiteral () {};
  inline JPM_CONST virtual bool IsPrimary () const { return true; }
  DECL_GET_SET( Value , AstTypeBase* , val_ );
  DECL_ACCEPT(ArrayLiteral);
private:
  AstTypeBase* val_;
};


  
EXTENDS_BASE(ElementList) {
public :
  ElementList ();
  inline ~ElementList () {};
    
  DECL_GET_SET_LIST( Value , AstTypeBase* , val_ );
  DECL_ACCEPT(ElementList);
private:
  std::list<AstTypeBase*> val_;
};



EXTENDS_BASE(ObjectMember) {
public :
  typedef std::list<std::pair<PropertyName* , AstTypeBase*> > MemberList;
  ObjectMember ();
  inline ~ObjectMember () {};
    
  inline void Value ( PropertyName* key , AstTypeBase* ast ) {
    list_.push_back ( std::pair<PropertyName* , AstTypeBase*>( key , ast ) );
  }
  DECL_GET( Value , MemberList& , list_ );
  DECL_ACCEPT(ObjectMember);
private:
  MemberList list_;
};



EXTENDS_BASE(Arguments) {
public :
  Arguments ();
  inline ~Arguments () {};
    
  DECL_GET_SET_LIST( Value , AstTypeBase* , list_ );
  DECL_ACCEPT(Arguments);
    
private:
  std::list<AstTypeBase*> list_;
};
  
  
  
EXTENDS_BASE(Expression) {
public :
  typedef std::list<AstTypeBase*>& ExpressionList;
  typedef std::list<AstTypeBase*>::iterator ExpressionIterator;
  Expression ();
  inline ~Expression () {};
  inline JPM_CONST virtual bool IsPrimary () const { return true; }
  DECL_GET_SET_LIST( List , AstTypeBase* , list_ );
  DECL_GET_SET( Paren , bool , paren_ );
    
  DECL_ACCEPT(Expression);
private:
  std::list<AstTypeBase*> list_;
  bool paren_;
};

EXTENDS_BASE(ExpressionStmt) {
public :
  ExpressionStmt ();
  inline ~ExpressionStmt () {};
  DECL_GET_SET( Exp , Expression* , exp_ );
  DECL_ACCEPT(ExpressionStmt);
private:
  Expression* exp_;
};

EXTENDS_BASE(IFStmt) {
public :
  IFStmt ();
  inline ~IFStmt () {};
    
  DECL_GET_SET( Then , AstTypeBase* , then_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_GET_SET( Else , AstTypeBase* , elseb_ );
    
  DECL_ACCEPT(IFStmt);
private :
  AstTypeBase* then_;
  AstTypeBase* body_;
  AstTypeBase* elseb_;
};


  
EXTENDS_BASE(DoWhile) {  
public :
  DoWhile ();
  inline ~DoWhile () {};
    
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_GET_SET( Condition , AstTypeBase* , condition_ );
  DECL_ACCEPT(DoWhile);
private:
  AstTypeBase* body_;
  AstTypeBase* condition_;
};

  
  
EXTENDS_BASE(While) {
public :
  While ();
  inline ~While () {};
    
  DECL_GET_SET( Condition , AstTypeBase* , condition_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );

  DECL_ACCEPT(While);
private :
  AstTypeBase* body_;
  AstTypeBase* condition_;
};

  
EXTENDS_BASE(Iteration) {
public :
#define DECL_CONSTRUCTOR(type) explicit Iteration ( type* ast )
    
  DECL_CONSTRUCTOR(For);
  DECL_CONSTRUCTOR(While);
  DECL_CONSTRUCTOR(ForIn);
  DECL_CONSTRUCTOR(DoWhile);

#undef DECL_CONSTRUCTOR
  inline ~Iteration () {};
  inline virtual void Accept ( IVisitor* visitor ) { ast_->Accept(visitor); }
private:
  AstTypeBase* ast_;
};
  
EXTENDS_BASE(For) {
public :
  For ();
  inline ~For () {};
    
  DECL_GET_SET( Index , AstTypeBase* , index_ );
  DECL_GET_SET( Condition , AstTypeBase* , condition_ );
  DECL_GET_SET( Increment , AstTypeBase* , increment_ );
  DECL_GET_SET( VariableDecl , bool , is_var_decl_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
    
  DECL_ACCEPT(For);
private:
  AstTypeBase* index_;
  AstTypeBase* condition_;
  AstTypeBase* increment_;
  bool is_var_decl_;
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(ForIn) {
public :
  ForIn ();
  inline ~ForIn () {};
    
  DECL_GET_SET( Item , AstTypeBase* , item_ );
  DECL_GET_SET( Target , AstTypeBase* , target_ );
  DECL_GET_SET( VariableDecl , bool , is_var_decl_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
    
  DECL_ACCEPT(ForIn);
private:
  AstTypeBase* item_;
  AstTypeBase* target_;
  AstTypeBase* body_;
  bool is_var_decl_;
};
  
  
  
EXTENDS_BASE(Continue) {
public:
  Continue ( const char* ident );
  inline ~Continue () {};
  DECL_GET( Ident , const char* , ident_ );
  DECL_ACCEPT(Continue);
private :
  const char* ident_;
};
  
  
  
EXTENDS_BASE(Break) {
public:
  Break ( const char* ident );
  inline ~Break () {};
    
  DECL_GET( Ident , const char* , ident_ );
  DECL_ACCEPT(Break);
private :
  const char* ident_;

};

  
  
EXTENDS_BASE(Return) {
public:
  Return ();
  inline ~Return () {};
    
  DECL_GET_SET( Expression , AstTypeBase* , exp_ );
  DECL_ACCEPT(Return);
private :
  AstTypeBase* exp_;
};

  
  
EXTENDS_BASE(With) {
public:
  With ();
  inline ~With () {};
    
  DECL_GET_SET( Expression , AstTypeBase* , exp_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_ACCEPT(With);
private :
  AstTypeBase* exp_;
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(Switch) {
public:
  Switch ();
  inline ~Switch () {};
    
  DECL_GET_SET( Expression , AstTypeBase* , exp_ );
  DECL_GET_SET( CaseBlock , AstTypeBase* , block_ );
  DECL_ACCEPT(Switch);
private :
  AstTypeBase* block_;
  AstTypeBase* exp_;
};
  
  

EXTENDS_BASE(CaseClauses) {

public:
  CaseClauses ();
  inline ~CaseClauses () {};
    
  DECL_GET_SET_LIST( List , AstTypeBase* , list_ );
  DECL_ACCEPT(CaseClauses);
private :
  std::list<AstTypeBase*> list_;
};

  
  
EXTENDS_BASE(CaseClause) {
public:
  CaseClause ();
  inline ~CaseClause () {};
    
  DECL_GET_SET( Expression , AstTypeBase* , exp_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_ACCEPT(CaseClause);
private :
  AstTypeBase* exp_;
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(DefaultClause) {
public :
  DefaultClause ();
  inline ~DefaultClause () {};
    
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_ACCEPT(DefaultClause);
private :
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(Label) {
public:
  Label ( const char* ident );
  inline ~Label () {};
    
  DECL_GET( Ident , const char* , ident_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_ACCEPT(Label);
private :
  const char* ident_;
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(Throw) {
public:
  Throw ();
  inline ~Throw () {};
    
  DECL_GET_SET( Expression , AstTypeBase* , exp_ );
  DECL_ACCEPT(Throw);
private :
  AstTypeBase* exp_;
};

  
  
EXTENDS_BASE(Try) {
public:
  Try ();
  inline ~Try () {};
    
  DECL_GET_SET( Body , AstTypeBase* , body_ );
  DECL_GET_SET( CatchBody , AstTypeBase* , catchbody_ );
  DECL_GET_SET( FinallyBody , AstTypeBase* , finallybody_ );
  DECL_ACCEPT(Try);
private :
  AstTypeBase* body_;
  AstTypeBase* catchbody_;
  AstTypeBase* finallybody_;
};

  
  
EXTENDS_BASE(Catch) {
public:
  Catch ( const char* ident );
  inline ~Catch () {};
    
  DECL_GET( Ident , const char* , ident_ );
  DECL_GET_SET( Body , AstTypeBase* , body_ );    
  DECL_ACCEPT(Catch);
private :
  const char* ident_;
  AstTypeBase* body_;
};
  
  
  
EXTENDS_BASE(Finally) {
public:
  Finally ();
  inline ~Finally () {};
  DECL_GET_SET( Block , AstTypeBase* , body_ );
  DECL_ACCEPT(Finally);
private :
  AstTypeBase* body_;
};

}

#undef DECL_ACCEPT
#undef DECL_SET
#undef DECL_SET_LIST
#undef DECL_GET
#undef DECL_GET_SET
#undef DECL_GET_SET_LIST
#undef EXTENDS_BASE
#undef EXTENDS

#endif

