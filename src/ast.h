#ifndef mocha_ast_h_
#define mocha_ast_h_
#include <stdio.h>
#include <string>
#include "managed.h"
#include "ast_foward_decl.h"
#include "ivisitor.h"
namespace mocha {


#define NVI_ACCEPTOR_DECL void NVIAccept_( IVisitor* visitor )
#define CALL_ACCEPTOR(name) inline NVI_ACCEPTOR_DECL{visitor->Accept##name( this );}

class NodeIterator{
 public :
  NodeIterator( AstNode* node ) : node_( node ){}
  ~NodeIterator(){}
  bool HasNext() { return ( node_ != 0 )? true : false; }
  AstNode* Next();
  AstNode* Item();
 private :
  AstNode* node_;
};

/**
 * @class
 * Base class of Ast.
 */
class AstNode : public Managed {
  friend class AstNodeList;
 public :
  enum {
    kBase,
    kEmpty,
    kAstRoot,
    kFileRoot,
    kStatement,
    kStatementList,
    kExpression,
    kValueNode,
    kCase,
    kNodeList,
    kBlockStmt,
    kModuleStmt,
    kExportStmt,
    kVariableStmt,
    kLetStmt,
    kExpressionStmt,
    kIFStmt,
    kIterationStmt,
    kContinueStmt,
    kReturnStmt,
    kBreakStmt,
    kWithStmt,
    kLabelledStmt,
    kSwitchStmt,
    kThrowStmt,
    kTryStmt,
    kFor,
    kForIn,
    kForWithVar,
    kForInWithVar,
    kForEach,
    kForEachWithVar,
    kWhile,
    kDoWhile,
    kFunction,
    kCallExp,
    kNewExp,
    kPostfixExp,
    kUnaryExp,
    kBinaryExp,
    kCompareExp,
    kConditionalExp,
    kAssignmentExp
  };
  AstNode( int type , const char* name );
  virtual inline ~AstNode(){};
  inline bool HasParent() { return parent_ != 0; };
  inline AstNode* ParentNode() { return parent_; };
  inline void ParentNode( AstNode* node ) { parent_ = node; }
  inline AstNode* FirstChild() { return first_child_; };
  inline AstNode* LastChild() { return last_child_; };
  inline AstNode* NextSibling() { return next_sibling_; };
  inline AstNode* PreviousSibling() { return prev_sibling_; };
  inline bool HasNext() { return next_sibling_ != 0; }
  inline bool HasPrev() { return prev_sibling_ != 0; }
  inline bool HasChild() { return first_child_ != 0; }
  inline void After( AstNode* node ) { next_sibling_ = node;node->prev_sibling_ = this; };
  inline void Before( AstNode* node ) { prev_sibling_ = node;node->next_sibling_ = this; };
  void Append( NodeList* node );
  inline NodeIterator ChildNodes() { return NodeIterator( first_child_ ); }
  void AddChild( AstNode* node );
  void InsertBefore( AstNode* node );
  void ReplaceWith( AstNode* node );
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  inline int ChildLength() const { return child_length_; }
  inline int NodeType() const { return type_; }
  inline void Accept( IVisitor* visitor ) { NVIAccept_( visitor ); };
  virtual Statement* CastToStatement() { return 0; };
  virtual Expression* CastToExpression() { return 0; };
  virtual ValueNode* CastToValue() { return 0; };
  inline void PrintNodeName() { printf( "%s\n" , name_ ); }
  inline void Line( long line ) { line_ = line; }
  inline long Line() { return line_; }
  inline const char* GetName() { return name_; }
  virtual inline bool IsEmpty(){ return false; }
 private :
  virtual NVI_ACCEPTOR_DECL = 0;
  int type_;
  int child_length_;
  long line_;
  const char* name_;
  AstNode* parent_;
  AstNode* first_child_;
  AstNode* last_child_;
  AstNode* next_sibling_;
  AstNode* prev_sibling_;
};

class NodeList : public AstNode {
 public :
  inline NodeList() : AstNode( AstNode::kNodeList , "NodeList" ){}
  inline ~NodeList(){}
 private :
  inline virtual void NVIAccept_( IVisitor* visitor ) {}
};

class Empty : public AstNode {
 public :
  Empty() : AstNode( AstNode::kEmpty , "Empty" ){}
  inline bool IsEmpty(){ return true; }
 private :
  inline void NVIAccept_( IVisitor* visitor ){}
};

class AstRoot : public AstNode {
 public :
  inline AstRoot() : AstNode( AstNode::kAstRoot , "AstRoot" ) {}
  inline ~AstRoot(){};
 private :
  CALL_ACCEPTOR(AstRoot);
};


/**
 * @class
 * Root block of file.
 */
class FileRoot : public AstNode {
 public :
  inline FileRoot() : AstNode( AstNode::kFileRoot , "FileRoot" ) {}
  inline ~FileRoot(){};
  inline void FileName( const char* filepath ) { filepath_ = filepath; }
  inline const char* FileName() { return filepath_.c_str(); }
 private :
  std::string filepath_;
  CALL_ACCEPTOR( FileRoot );
};


/**
 * @class
 * Statement block.
 */
class Statement : public AstNode {
 public :
  Statement( int type , const char* name ) : AstNode( type , name ) {};
  virtual inline ~Statement() {};
  inline Statement* CastToStatement() { return this; }
 private :
  inline Statement() : AstNode( AstNode::kStatement , "Statement" ){}
  virtual NVI_ACCEPTOR_DECL=0;
};


class StatementList : public AstNode {
 public :
  inline StatementList() : AstNode( AstNode::kStatementList , "StatementList" ){}
  inline ~StatementList(){}
 private :
  CALL_ACCEPTOR(StatementList);
};


#define NAME_PARAMETER(name) AstNode::k##name , #name

class BlockStmt : public Statement {
 public :
  inline BlockStmt() : Statement( NAME_PARAMETER(BlockStmt) ){};
  inline ~BlockStmt() {};
 private :
  CALL_ACCEPTOR( BlockStmt );
};


class ModuleStmt : public Statement {
 public :
  inline ModuleStmt() : Statement( NAME_PARAMETER(ModuleStmt) ){};
  inline ~ModuleStmt() {};
  inline void Name( AstNode* name ) { name_ = name; }
  inline AstNode* Name() const { return name_; }
 private :
  AstNode* name_;
  CALL_ACCEPTOR( ModuleStmt );
};



class ExportStmt : public Statement {
 public :
  inline ExportStmt() : Statement( NAME_PARAMETER(ExportStmt) ){};
  inline ~ExportStmt() {};
 private :
  CALL_ACCEPTOR( ExportStmt );
};



class VariableStmt : public Statement {
 public :
  enum {
    kNormal,
    kConst,
    kLet
  };
  inline VariableStmt() : Statement( NAME_PARAMETER(VariableStmt) ){};
  inline ~VariableStmt(){};
  inline void VarType( int type ){ var_type_ = type; };
  inline int VarType() { return var_type_; };
 private :
  int var_type_;
  CALL_ACCEPTOR( VariableStmt );
};


class LetStmt : public Statement {
 public :
  inline LetStmt() : Statement( NAME_PARAMETER(LetStmt) ) {}
  inline ~LetStmt(){}
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( LetStmt );
};


class ExpressionStmt : public Statement {
 public :
  inline ExpressionStmt() : Statement( AstNode::kExpressionStmt , "ExpressionStmt" ) {};
  inline ~ExpressionStmt(){};
 private :
  CALL_ACCEPTOR( ExpressionStmt );
};


class IFStmt : public Statement {
 public :
  inline IFStmt() : Statement( NAME_PARAMETER(IFStmt) ) , exp_( 0 ){};
  inline ~IFStmt() {};
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
  inline void Then( AstNode* node ) { then_ = node; }
  inline AstNode* Then() { return then_; }
  inline void Else( AstNode* els ) { else_ = els; }
  inline AstNode* Else() { return else_; }
 private :
  AstNode* exp_;
  AstNode* then_;
  AstNode* else_;
  CALL_ACCEPTOR( IFStmt );
};


class IterationStmt : public Statement {
 public :
  inline IterationStmt( int type ) : Statement( type , "IterationStmt" ){};
  inline ~IterationStmt(){};
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
 private:
  AstNode* exp_;
  CALL_ACCEPTOR( IterationStmt );
};


class ContinueStmt : public Statement {
 public :
  inline ContinueStmt() : Statement( NAME_PARAMETER(ContinueStmt) ){};
  inline ~ContinueStmt() {};
 private :
  CALL_ACCEPTOR( ContinueStmt );
};



class BreakStmt : public Statement {
 public :
  inline BreakStmt() : Statement( NAME_PARAMETER(BreakStmt) ) {};
  inline ~BreakStmt() {};
 private :
  CALL_ACCEPTOR( BreakStmt );
};



class ReturnStmt : public Statement {
 public :
  inline ReturnStmt() : Statement( NAME_PARAMETER(ReturnStmt) ){};
  inline ~ReturnStmt() {};
 private :
  CALL_ACCEPTOR( ReturnStmt );
};


class WithStmt : public Statement {
 public :
  inline WithStmt() : Statement( NAME_PARAMETER(WithStmt) ){};
  inline ~WithStmt(){};
  inline void Exp( AstNode* node ) { exp_ = node; }
  inline AstNode* Exp() { return exp_; }
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( WithStmt );
};


class LabelledStmt : public Statement {
 public :
  inline LabelledStmt() : Statement( NAME_PARAMETER(LabelledStmt) ){};
  inline ~LabelledStmt() {};
 private :
  CALL_ACCEPTOR( LabelledStmt );
};



class SwitchStmt : public Statement {
 public :
  inline SwitchStmt() : Statement( NAME_PARAMETER(SwitchStmt) ){};
  inline ~SwitchStmt() {};
  inline void Exp( AstNode* node ) { exp_ = node; }
  inline AstNode* Exp() { return exp_; }
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( SwitchStmt );
};



class ThrowStmt : public Statement {
 public :
  inline ThrowStmt() : Statement( NAME_PARAMETER(ThrowStmt) ){};
  inline ~ThrowStmt(){};
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( ThrowStmt );
};


class TryStmt : public Statement {
 public :
  inline TryStmt() : Statement( NAME_PARAMETER(TryStmt) ){};
  inline ~TryStmt(){};
  inline void Catch( AstNode* catch_stmt ) { catch_ = catch_stmt; }
  inline AstNode* Catch() { return catch_; }
  inline void Finally( AstNode* finally_stmt ) { finally_ = finally_stmt; }
  inline AstNode* Finally() { return finally_; }
 private :
  AstNode* catch_;
  AstNode* finally_;
  CALL_ACCEPTOR( TryStmt );
};

class CaseClause : public AstNode {
 public :
  inline CaseClause() : AstNode( AstNode::kCase , "CaseClause" ){}
  inline ~CaseClause(){}
  inline void Exp( AstNode* node ) { exp_ = node; }
  inline AstNode* Exp() { return exp_; }
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( CaseClause );
};


class Expression : public AstNode {
 public :
  inline Expression() : AstNode( AstNode::kExpression , "Expression" ) , paren_( false ){};
  inline Expression( int type , const char* name = "Expression" ) : AstNode( type , name ) , paren_( false ){};
  virtual inline ~Expression(){};
  inline void Paren() { paren_ = true; };
  inline bool IsParen() { return paren_; };
  inline Expression* CastToExpression() { return this; }
 private :
  bool paren_;
  virtual CALL_ACCEPTOR( Expression );
};


class Function : public Expression {
 public :
  enum {
    kNormal,
    kShorten
  };
  enum {
    kGlobal,
    kThis
  };
  inline Function() : Expression( NAME_PARAMETER( Function ) ),
                      fn_type_( kNormal ) , context_( kGlobal ) , is_const_( false ) , name_( 0 ) , argv_( 0 ){};
  inline ~Function(){};
  inline void Name( AstNode* name ){ name_ = name; };
  inline AstNode* Name(){ return name_; };
  inline AstNode* Argv(){ return argv_; };
  inline void Argv( AstNode* argv ) { argv_ = argv; };
  inline int Argc() const { return argv_->ChildLength(); }
  inline void Const() { is_const_ = true; }
  inline bool IsConst() const { return is_const_; }
  inline int FunctionType() { return fn_type_; }
  inline void FunctionType( int type ) { fn_type_ = type; }
  inline int ContextType() { return context_; }
  inline void ContextType( int type ) { context_ = type; }
 private :
  int fn_type_;
  int context_;
  bool is_const_;
  AstNode* name_;
  AstNode* argv_;
  CALL_ACCEPTOR( Function );
};


class CallExp : public Expression {
 public :
  enum {
    kNormal,
    kBracket,
    kDot,
    kNew
  };
  inline CallExp( int type ) : Expression( NAME_PARAMETER( CallExp ) ) , call_type_( type ) , depth_( 0 ){};
  inline ~CallExp() {};
  inline void Callable( AstNode* node ){ callable_ = node;node->ParentNode( this ); };
  inline AstNode* Callable() { return callable_; };
  inline void Args( AstNode* node ) { args_ = node;node->ParentNode( this ); };
  inline AstNode* Args() { return args_; };
  inline int CallType() { return call_type_; }
  inline void Depth( int depth ) { depth_ = depth; }
  inline int Depth() { return depth_; }
 private :
  int call_type_;
  int depth_;
  AstNode* callable_;
  AstNode* args_;
  CALL_ACCEPTOR( CallExp );
};


class NewExp : public Expression {
 public :
  inline NewExp() : Expression( NAME_PARAMETER( NewExp ) ){};
  inline ~NewExp(){};
  inline void Constructor( AstNode* node ) { constructor_ = node; };
  inline AstNode* Constructor() { return constructor_; };
 private :
  AstNode* constructor_;
  CALL_ACCEPTOR( NewExp );
};



class PostfixExp : public Expression {
 public :
  enum {
    kIncrement,
    kDecrement
  };
  inline PostfixExp( int type ) : Expression( NAME_PARAMETER( PostfixExp ) ) , post_type_( type ){};
  inline ~PostfixExp(){};
  inline int PostType() { return post_type_; };
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
 private :
  int post_type_;
  AstNode* exp_;
  CALL_ACCEPTOR( PostfixExp );
};


class UnaryExp : public Expression {
 public :
  enum {
    kDelete,
    kVoid,
    kTypeof,
    kIncrement,
    kDecrement,
    kPlus,
    kMinus,
    kComp,
    kNot
  };
  inline UnaryExp( int op ) : Expression( NAME_PARAMETER( UnaryExp ) ) , op_( op ){};
  inline ~UnaryExp() {};
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
  inline int Op() { return op_; };
 private :
  int op_;
  AstNode* exp_;
  CALL_ACCEPTOR( UnaryExp );
};


class BinaryExp : public Expression {
 public :
  enum {
    kMul,
    kDiv,
    kMod,
    kPlus,
    kMinus,
    kShiftLeft,
    kShiftRight,
    kUShiftRight,
    kAnd,
    kXor,
    kOr
  };
  inline BinaryExp( int op , AstNode* left , AstNode* right ) : Expression( NAME_PARAMETER( BinaryExp ) ) , op_( op ) , left_( left ) , right_( right ){};
  inline ~BinaryExp() {};
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( BinaryExp );
};


class CompareExp : public Expression {
 public :
  enum {
    kLess,
    kGreater,
    kLessEqual,
    kGreaterEqual,
    kInstanceof,
    kIn,
    kEqual,
    kNotEqual,
    kEq,
    kNotEq,
    kLogicalAND,
    kLogicalOR
  };
  inline CompareExp( int op , AstNode* left , AstNode* right ) : Expression( NAME_PARAMETER( CompareExp ) ) , op_( op ) , left_( left ) , right_( right ){};
  inline ~CompareExp(){};
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( CompareExp );
};


class ConditionalExp : public Expression {
 public :
  inline ConditionalExp( AstNode* cond , AstNode* case_true , AstNode* case_false ) :
      Expression( NAME_PARAMETER( ConditionalExp ) ),
      cond_( cond ) , case_true_( case_true ) , case_false_( case_false ){};
  inline ~ConditionalExp(){};
  inline AstNode* True() { return case_true_; };
  inline AstNode* False() { return case_false_; };
  inline AstNode* Cond() { return cond_; };
 private :
  AstNode* cond_;
  AstNode* case_true_;
  AstNode* case_false_;
  CALL_ACCEPTOR( ConditionalExp );
};



class AssignmentExp : public Expression {
 public :
  inline AssignmentExp( int op , AstNode* left , AstNode* right ) :
      Expression( NAME_PARAMETER( AssignmentExp ) ),
      op_( op ) , left_( left ) , right_( right ){};
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( AssignmentExp );
};



class ValueNode : public AstNode {
 public :
  enum {
    kNull,
    kTrue,
    kFalse,
    kNumeric,
    kString,
    kRegExp,
    kThis,
    kIdentifier,
    kPropertyName,
    kVariable,
    kArray,
    kArrayComp,
    kObject,
    kDst,
    kDstArray,
    kSpread,
    kRest
  };
  inline ValueNode( int type ) : AstNode( AstNode::kValueNode , "ValueNode" ) , value_type_( type ){};
  inline ~ValueNode() {};
  inline int ValueType() const { return value_type_; };
  inline void Symbol( TokenInfo* value ) { value_ = value; };
  inline TokenInfo* Symbol() const { return value_; };
  inline void Node( AstNode* node ) { node_ = node; };
  inline AstNode* Node() const { return node_; };
  inline ValueNode* CastToValue() { return this; }
 private :
  int value_type_;
  union {
    TokenInfo* value_;
    AstNode* node_;
  };
  CALL_ACCEPTOR( ValueNode );
};


}

#undef NVI_ACCEPTOR_DECL
#undef CALL_ACCEPTOR
#undef NAME_PARAMETER

#endif
