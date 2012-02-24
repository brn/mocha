/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

#ifndef mocha_ast_h_
#define mocha_ast_h_
#include <stdio.h>
#include <string>
#include <utils/pool/managed.h>
#include <utils/pool/managed_handle.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
#include <ast/values/js_values.h>
#include <ast/visitors/analyzer.h>

namespace mocha {
#define NVI_ACCEPTOR_DECL void NVIAccept_( IVisitor* visitor )
#define NVI_ACCEPT_WITH_RETURN_DECL JSValue* NVIAcceptWithReturn( Analyzer* analyzer )
#define CALL_ACCEPTOR(name) inline NVI_ACCEPTOR_DECL{visitor->Visit##name( this );}
#define CALL_ACCEPTOR_WITH_RETURN(name) inline NVI_ACCEPT_WITH_RETURN_DECL{ return analyzer->Analyze##name( this );}
/**
 * @class
 * Iterator of node lists.
 */
class NodeIterator{
 public :
  inline NodeIterator() : node_( 0 ){}
  inline explicit NodeIterator( AstNode* node ) : node_( node ){}
  inline ~NodeIterator(){}
  inline NodeIterator( const NodeIterator& iterator ) {
    node_ = iterator.node_;
  }
  inline const NodeIterator& operator =( const NodeIterator& iterator ) {
    node_ = iterator.node_;
    return (*this);
  }
  /**
   * @param {bool}
   * @returns {AstNode*}
   * Check current node is 0 or not.
   */
  inline bool HasNext() const { return ( node_ != 0 )? true : false; }

  /**
   * @returns {AstNode*}
   * Return the current node,
   * and update it with it's next sibling.
   */
  AstNode* Next();

  /**
   * @return {AstNode*}
   * Just get the current node.
   */
  inline AstNode* Item() const { return node_; };
 private :
  AstNode* node_;
};

/**
 * @class
 * Reverse iterator of node lists.
 * All method's behaviour are the same as above NodeIterator,
 * except function Next behave as towards to previous sibling.
 */
class ReverseNodeIterator{
 public :
  inline ReverseNodeIterator( AstNode* node ) : node_( node ){}
  inline ~ReverseNodeIterator(){}
  inline bool HasNext() const { return ( node_ != 0 )? true : false; }
  AstNode* Next();
  inline AstNode* Item() const { return node_; };
 private :
  AstNode* node_;
};



/**
 * @class
 * Base class of Ast.
 * This class based on W3C DOM.
 * WARNING
 * You must set empty node to 'Empty' class ptr,
 * if you not, you got sigenv where access to empty node.
 */
class AstNode : public Managed {
  friend class AstNodeList;
 public :
  //Definition of all node type.
  enum {
    kBase,
    kEmpty,
    kAstRoot,
    kFileRoot,
    kStatement,
    kStatementList,
    kVersionStmt,
    kAssertStmt,
    kExpression,
    kValueNode,
    kCase,
    kNodeList,
    kPragmaStmt,
    kBlockStmt,
    kModuleStmt,
    kExportStmt,
    kImportStmt,
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
    kForOf,
    kForOfWithVar,
    kWhile,
    kDoWhile,
    kTrait,
    kTraitMember,
    kMixinMember,
    kClass,
    kClassProperties,
    kClassExpandar,
    kClassMember,
    kFunction,
    kCallExp,
    kProperty,
    kNewExp,
    kYieldExp,
    kYieldMark,
    kExYieldStateNode,
    kPostfixExp,
    kUnaryExp,
    kBinaryExp,
    kCompareExp,
    kConditionalExp,
    kAssignmentExp,
    kPropertyArray,
    kPropertyMap,
    kDstaTree,
    kDstaExtractedExpressions
  };
  AstNode( int type , const char* name );
  virtual inline ~AstNode(){};

  /**
   * @returns {bool}
   * Return that this node has parent ast node or not. 
   */
  inline bool HasParent() const { return parent_ != 0; };

  /**
   * @returns {AstNode*}
   * Return parent ast node.
   * If a parent node is empty, return 0;
   */
  inline AstNode* ParentNode() const { return parent_; };

  /**
   * @param {AstNode*} node
   * Set a parent node of this node.
   */
  inline void ParentNode( AstNode* node ) { parent_ = node; }

  /**
   * @returns {AstNode*}
   * Return a first child of this node.
   * If child nodes are empty, return 0;
   */
  inline AstNode* FirstChild() const { return first_child_; };

  /**
   * @returns {AstNode*}
   * Return a last child of this node.
   * If child nodes are empty, return 0.
   * If child nodes length is less than 2,
   * return a first child node.
   */
  inline AstNode* LastChild() const { return last_child_; };

  /**
   * @returns {AstNode*}
   * Return next sibling node,
   * If the next sibling is empty, return 0.
   */
  inline AstNode* NextSibling() const { return next_sibling_; };

  /**
   * @returns {AstNode*}
   * Return prev sibling node,
   * If the prev sibling is empty, return 0.
   */
  inline AstNode* PreviousSibling() const { return prev_sibling_; };

  /**
   * @returns {bool}
   * Check that the next sibling node is there.
   */
  inline bool HasNext() const { return next_sibling_ != 0; }

  /**
   * @returns {bool}
   * Check that the prev sibling node is there.
   */
  inline bool HasPrev() const { return prev_sibling_ != 0; }

  /**
   * @returns {bool}
   * Check this node has children or not.
   */
  inline bool HasChild() const { return first_child_ != 0; }

  /**
   * @param {AstNode*}
   * Insert a node to next sibling of this node. 
   */
  inline void After( AstNode* node ) { next_sibling_ = node; if ( node ) node->prev_sibling_ = this; };

  /**
   * @param {AstNode*}
   * Insert a node to previous sibling of this node. 
   */
  inline void Before( AstNode* node ) { prev_sibling_ = node; if ( node ) node->next_sibling_ = this; };

  /**
   * @param {AstNode*}
   * Add the child nodes of arguments node to this node directry.
   *
   * NodeList           NodeList
   * |      |       +   |      |
   * child  child       child  child
   *                |
   *             NodeList
   *              __|______________
   *             |     |     |     |
   *             child child child child
   */
  void Append( AstNode* node );

  /**
   * @returns {NodeIterator}
   * Get a iterator of the child nodes.
   * This function returns is values by value of NodeIterator.
   */
  inline NodeIterator ChildNodes() { return NodeIterator( first_child_ ); }

  /**
   * @returns {ReverseNodeIterator}
   * Get a ReverseNodeIterator of the child nodes.
   */
  inline ReverseNodeIterator ReverseChildNodes() { return ReverseNodeIterator( last_child_ ); }

  /**
   * @param {AstNode*}
   * Add child.
   */
  void AddChild( AstNode* node );

  /**
   * @params {AstNode*}
   * Insert child to the front of child nodes.
   * The node that passed as arguments is assign to the first child.
   */
  void InsertBefore( AstNode* node );

  /**
   * @param {AstNode*} insert
   * @param {AstNode*} target
   * Insert a new child node before the old node.
   */
  void InsertBefore( AstNode* insert , AstNode* target );

  /**
   * @param {AstNode*} insert
   * @param {AstNode*} target
   * Insert a new child node after the old node.
   */
  void InsertAfter( AstNode* insert , AstNode* target );

  /**
   * @param {AstNode*}
   * Remove a node that passed as arguments from the child nodes.
   */
  virtual void RemoveChild( AstNode* node );

  /**
   * Remove all child nodes.
   * In fact, this function is not delete child node,
   * but set parent_ property of all child nodes to 0 and,
   * set self properties ( first_child_ , last_child_ and child_length_ ) to 0.
   */
  virtual void RemoveAllChild();

  /**
   * @param {AstNode*}
   * Replace this node with the node that passed as arguments. 
   */
  void ReplaceWith( AstNode* node );

  /**
   * @param {AstNode*}
   * Replace the old_node with new_node in childnodes.
   */
  virtual void ReplaceChild( AstNode* old_node , AstNode* new_node );

  /**
   * @returns {int}
   * Get the size of child nodes.
   */
  inline int ChildLength() const { return child_length_; }

  /**
   * @returns {int}
   * Get real type of the node.
   */
  inline int NodeType() const { return type_; }

  /**
   * @param {IVisitor}
   * Function that accept visitor.
   * This function call private virtual NVIAcceptor_.
   */
  inline void Accept( IVisitor* visitor ) { NVIAccept_( visitor ); };

  /**
   * @param {Statemet*}
   * Cast to statement.
   * Return 0 by default.
   */
  virtual Statement* CastToStatement() { return 0; };

  /**
   * @param {Expression*}
   * Cast to Expression.
   * Return 0 by default.
   */
  virtual Expression* CastToExpression() { return 0; };
  virtual ValueNode* CastToValue() { return 0; };
  virtual DstaTree* CastToDstaTree() { return 0; }
  virtual NodeList* CastToNodeList() { return 0; }
  
  /**
   * Print the real node name of this node.
   */
  inline void PrintNodeName() const { printf( "%s\n" , name_ ); }

  /**
   * @param {long}
   * Set line number.
   */
  inline void Line( long line ) { line_ = line; }

  /**
   * @returns {long}
   * Get line number.
   */
  inline long Line() const { return line_; }

  /**
   * @returns {const char*}
   * Get the real name of this node.
   */
  inline const char* GetName() const { return name_; }

  /**
   * @returns {AstNode*}
   * Clone node.
   */
  inline virtual AstNode* Clone() {return 0;};

  /**
   * @returns {bool}
   * Check this node is Empty or not.
   */
  virtual inline bool IsEmpty() const { return false; }

 private :
  inline virtual NVI_ACCEPTOR_DECL{};
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

#define CLONE( name ) AstNode* Clone();
#define FACTORY( name ) static inline name* New() { return ManagedHandle::Retain<name>(); }


/**
 * @class
 * This class is utility ast,
 * this node has not definition of usage,
 * but has proper perporse,
 * that is to band node collections.
 * So you can use this node, anywhere you want to band nodes.
 */
class NodeList : public AstNode {
 public :
  FACTORY( NodeList );
  inline NodeList() : AstNode( AstNode::kNodeList , "NodeList" ){}
  inline ~NodeList(){}
  NodeList* CastToNodeList() { return this; }
  CLONE( NodeList );
 private :
  CALL_ACCEPTOR(NodeList);
};


/**
 * @class
 * Sentinel node.
 * You must set empty slots of each node to this node.
 */
class Empty : public AstNode {
 public :
  FACTORY( Empty );
  Empty() : AstNode( AstNode::kEmpty , "Empty" ){}
  /**
   * @param {bool}
   * Only this node that IsEmpty method return true.
   */
  inline bool IsEmpty() const { return true; }
  CLONE( Empty );
 private :
  inline void NVIAccept_( IVisitor* visitor ){}
};

/**
 * @class
 * Root node of abstract syntax tree,
 * in normaly, each syntax tree has this node only one in the top of tree.
 */
class AstRoot : public AstNode {
 public :
  FACTORY( AstRoot );
  inline AstRoot() : AstNode( AstNode::kAstRoot , "AstRoot" ) {}
  inline ~AstRoot(){};
  /**
   * @param {InnerScope*}
   * Global closure scope.
   */
  inline void SetScope( InnerScope* scope ) { scope_ = scope; }
  /**
   * @retunrs {InnerScope*}
   * Return global closure scope.
   */
  inline InnerScope* GetScope() const { return scope_; }
  CLONE( AstRoot );
 private :
  InnerScope* scope_;
  CALL_ACCEPTOR(AstRoot);
};


/**
 * @class
 * Root block of file.
 */
class FileRoot : public AstNode {
 public :
  FACTORY( FileRoot );
  inline FileRoot() : AstNode( AstNode::kFileRoot , "FileRoot" ) ,is_file_root_( false ) , has_directive_( false ) {}
  inline ~FileRoot(){};
  /**
   * @param {const char*}
   * Set current file name.
   */
  inline void FileName( const char* filepath ) { filepath_ = filepath; }
  /**
   * @returns {const char*}
   * Get file name.
   */
  inline const char* FileName() const { return filepath_.c_str(); }
  bool IsRuntime() { return is_file_root_; }
  void SetFileRoot() { is_file_root_ = true; }
  void SetStrict() { has_directive_ = true; }
  bool HasStrict() { return has_directive_; }
  CLONE( FileRoot );
 private :
  bool is_file_root_;
  bool has_directive_;
  std::string filepath_;
  CALL_ACCEPTOR( FileRoot );
};


/**
 * @class
 * Statement block.
 * Basically this class is not used.
 */
class Statement : public AstNode {
 public :
  FACTORY( Statement );
  inline Statement() : AstNode( AstNode::kStatement , "Statement" ),
                       has_dsta_( false ) , has_yield_( false ) , dsta_exp_( 0 ){}
  inline Statement( int type , const char* name ) :
      AstNode( type , name ) , has_dsta_( false ) , has_yield_( false ) , dsta_exp_( 0 ) {};
  virtual inline ~Statement() {};

  /**
   * @returns {Statement*}
   * Cast to statement.
   */
  inline Statement* CastToStatement() { return this; }

  virtual inline IterationStmt* CastToIteration() { return 0; }
  virtual inline ExYieldStateNode* CastToYieldState() { return 0; }
  virtual inline YieldMark* CastToYieldMark() { return 0; }
  virtual inline IFStmt* CastToIFStmt() { return 0; }
  virtual inline SwitchStmt* CastToSwitchStmt() { return 0; }
  /**
   * @param {DstaExtractedExpression} tree
   * Set destructuring assignment tree.
   */
  inline void SetDsta( DstaExtractedExpressions* tree ) {
    dsta_exp_ = tree;
    has_dsta_ = true;
  }

  inline void SetYieldFlag() { has_yield_ = true; }
  inline void SetYieldFlag( bool is ) { has_yield_ = is; }

  inline bool GetYieldFlag() { return has_yield_; }
  
  /**
   * @returns {bool}
   * Check this node's children include destructuring assignment node. 
   */
  inline bool HasDsta() { return has_dsta_; }

  /**
   * @returns {DstaExtractedExpression}
   * Get destructuring assignment node.
   */
  inline DstaExtractedExpressions* GetDsta() { return dsta_exp_; }

  /**
   * Set 0 to all destructuring assignment block.
   */
  inline void ResetDsta();
 private :
  virtual NVI_ACCEPTOR_DECL{};
  bool has_dsta_;
  bool has_yield_;
  DstaExtractedExpressions *dsta_exp_;
};


/**
 * @class
 * Statement list.
 * This class behave like the NodeList.
 */
class StatementList : public AstNode {
 public :
  FACTORY( StatementList );
  inline StatementList() : AstNode( AstNode::kStatementList , "StatementList" ){}
  inline ~StatementList(){}
  CLONE( StatementList );
 private :
  CALL_ACCEPTOR(StatementList);
};


#define NAME_PARAMETER(name) AstNode::k##name , #name


class YieldMark : public Statement {
 public :
  FACTORY( YieldMark );
  YieldMark() : Statement( NAME_PARAMETER( YieldMark ) ) , adjustment_( 0 ) , is_state_injection_( false ), state_( 0 ){}
  ~YieldMark() {}
  inline void ReEntrantNode( ValueNode* val ){ state_ = val; }
  inline ValueNode* ReEntrantNode(){ return state_; }
  inline YieldMark* CastToYieldMark() { return this; }
  inline int Adjust( int val ) { return val + adjustment_; }
  inline void SetAdjust( int val ) { adjustment_ = val; }
  inline void SetNoStateInjection() { is_state_injection_ = true; }
  inline bool GetNoStateInjection() { return is_state_injection_; }
 private :
  int adjustment_;
  bool is_state_injection_;
  ValueNode* state_;
};


class ExYieldStateNode : public Statement {
 public :
  FACTORY( ExYieldStateNode );
  inline ExYieldStateNode() :
      Statement( NAME_PARAMETER( ExYieldStateNode ) ) , loopback_ptr_( 0 ),
      next_ptr_( 0 ) , escape_ptr_( 0 ) , if_stmt_ptr_( 0 ) {}
  inline ~ExYieldStateNode(){};
  inline ExYieldStateNode* CastToYieldState() { return this; }
  inline void EscapePtr( ValueNode* ptr ) { escape_ptr_ = ptr; }
  inline ValueNode* EscapePtr() { return escape_ptr_; }
  inline void LoopBackPtr( ValueNode* ptr ) { loopback_ptr_ = ptr; }
  inline ValueNode* LoopBackPtr() { return loopback_ptr_; }
  inline void NextPtr( ValueNode* ptr ) { next_ptr_ = ptr; }
  inline ValueNode* NextPtr() { return next_ptr_; }
  inline void IfStmtPtr( IFStmt* ptr ) { if_stmt_ptr_ = ptr; }
  inline IFStmt* IfStmtPtr() { return if_stmt_ptr_; }
 private :
  ValueNode* loopback_ptr_;
  ValueNode* next_ptr_;
  ValueNode* escape_ptr_;
  IFStmt* if_stmt_ptr_;
};


/**
 * @class
 * Pragma statement node.
 */
class PragmaStmt : public Statement {
 public :
  PragmaStmt() : Statement( NAME_PARAMETER(PragmaStmt) ) , op_( 0 ){}
  ~PragmaStmt(){};
  inline void Op( ValueNode* op );
  inline const char* Op();
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE(PragmaStmt);
 private :
  AstNode* op_;
  CALL_ACCEPTOR( PragmaStmt );
};

/**
 * @class
 * Block statement node.
 */
class BlockStmt : public Statement {
 public :
  FACTORY( BlockStmt );
  inline BlockStmt() : Statement( NAME_PARAMETER(BlockStmt) ){};
  inline ~BlockStmt() {};
  CLONE( BlockStmt );
 private :
  CALL_ACCEPTOR( BlockStmt );
};


/**
 * @class
 * Module statement node.
 */
class ModuleStmt : public Statement {
 public :
  FACTORY( ModuleStmt );
  inline ModuleStmt() : Statement( NAME_PARAMETER(ModuleStmt) ) , name_( 0 ){};
  inline ~ModuleStmt() {};

  /**
   * @param {AstNode*} name
   * Set module name.
   */
  inline void Name( AstNode* name ) { name_ = name; }

  /**
   * @returns {AstNode*}
   * Get module name.
   */
  inline AstNode* Name() const { return name_; }
  CLONE(ModuleStmt);
 private :
  AstNode* name_;
  CALL_ACCEPTOR( ModuleStmt );
};


/**
 * @class
 * Export statement node.
 */
class ExportStmt : public Statement {
 public :
  FACTORY( ExportStmt );
  inline ExportStmt() : Statement( NAME_PARAMETER(ExportStmt) ){};
  inline ~ExportStmt() {};
  CLONE(ExportStmt);
 private :
  CALL_ACCEPTOR( ExportStmt );
};


/**
 * @class
 * Import statement node.
 */
class ImportStmt : public Statement {
 public :
  //Import target type.
  enum {
    kFile,
    kModule
  };
  //Left hand side type.
  enum {
    kVar,
    kDst,
    kAll
  };
  static inline ImportStmt* New( int var_type , int mod_type ) {
    return ManagedHandle::Retain( new ImportStmt( var_type , mod_type ) );
  }
  inline ImportStmt( int var_type , int mod_type ) :
      Statement( NAME_PARAMETER( ImportStmt ) ),
      var_type_( var_type ) , mod_type_( mod_type ) , exp_( 0 ) , from_( 0 ),key_( 0 ){}
  inline ~ImportStmt(){};

  /**
   * @param {AstNode*} exp
   * Set the expression node.
   * import <...> form <...>
   *          |
   *         this
   */
  inline void Exp( AstNode* exp ) { exp_ = exp;exp->ParentNode( this ); }

  /**
   * @returns {AstNode*}
   * Get the expression node.
   */
  inline AstNode* Exp() { return exp_; }

  /**
   * @param {AstNode*} exp
   * Set the expression node that continue after from keyword.
   * import <...> form <...>
   *                     |
   *                    this
   */
  inline void From( AstNode* from ) { from_ = from;from->ParentNode( this ); }

  /**
   * @param {AstNode*}
   * Get from after expression.
   */
  inline AstNode* From() { return from_; }

  /**
   * @param {TokenInfo*} key
   * Set the module load key,
   * this key used inner compiled javascript.
   */
  inline void ModKey( TokenInfo* key ) { key_ = key; }

  /**
   * @returns {TokenInfo*}
   * Get module key.
   */
  inline TokenInfo* ModKey() { return key_; }

  //Type getter.
  inline int VarType() { return var_type_; }
  inline int ModType() { return mod_type_; }
  CLONE(ImportStmt);
 private :
  int var_type_;
  int mod_type_;
  AstNode* exp_;
  AstNode* from_;
  TokenInfo* key_;
  CALL_ACCEPTOR( ImportStmt );
};

/**
 * @class
 * Variable statement node.
 */
class VariableStmt : public Statement {
 public :
  //Variable declaration type. 
  enum {
    kNormal,
    kConst,
    kLet
  };
  FACTORY( VariableStmt );
  inline VariableStmt() : Statement( NAME_PARAMETER(VariableStmt) ){};
  inline ~VariableStmt(){};

  /**
   * @param {int} type
   * Set decl type.
   */
  inline void VarType( int type ){ var_type_ = type; };

  /**
   * @returns {int}
   * Get decl type.
   */
  inline int VarType() { return var_type_; };
  CLONE( VariableStmt );
 private :
  int var_type_;
  CALL_ACCEPTOR( VariableStmt );
};


/**
 * @class
 * Let statement node.
 * This class is node used. 2011/12/28
 */
class LetStmt : public Statement {
 public :
  FACTORY( LetStmt );
  inline LetStmt() : Statement( NAME_PARAMETER(LetStmt) ) , exp_( 0 ) {}
  inline ~LetStmt(){}
  inline void Exp( AstNode* exp ) { exp_ = exp; }
  inline AstNode* Exp() { return exp_; }
  CLONE( LetStmt );
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( LetStmt );
};


/**
 * @class
 * Expression statement node.
 */
class ExpressionStmt : public Statement {
 public :
  FACTORY( ExpressionStmt );
  inline ExpressionStmt() : Statement( AstNode::kExpressionStmt , "ExpressionStmt" ) {};
  inline ~ExpressionStmt(){};
  CLONE( ExpressionStmt );
 private :
  CALL_ACCEPTOR( ExpressionStmt );
};


/**
 * @class
 * If statement node.
 */
class IFStmt : public Statement {
 public :
  FACTORY( IFStmt );
  inline IFStmt() : Statement( NAME_PARAMETER(IFStmt) ) , exp_( 0 ) , then_( 0 ), else_( 0 ){};
  inline ~IFStmt() {};
  inline IFStmt* CastToIFStmt() { return this; }
  /**
   * @param {AstNode*} exp
   * Set expression node.
   * if ( <...> ) { ...
   *        |
   *       this
   */
  inline void Exp( AstNode* exp ) { exp_ = exp;exp->ParentNode( this ); }

  /**
   * @returns {AstNode*}
   * Get expression node.
   */
  inline AstNode* Exp() { return exp_; }
  inline void Then( AstNode* node ) { then_ = node;node->ParentNode( this ); }
  inline AstNode* Then() { return then_; }
  inline void Else( AstNode* els ) { else_ = els;els->ParentNode( this ); }
  inline AstNode* Else() { return else_; }
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( IFStmt );
 private :
  AstNode* exp_;
  AstNode* then_;
  AstNode* else_;
  CALL_ACCEPTOR( IFStmt );
};


class IterationStmt : public Statement {
 public :
  static inline IterationStmt* New( int type ) { return ManagedHandle::Retain( new IterationStmt( type ) ); }
  inline IterationStmt( int type ) : Statement( type , "IterationStmt" ) , exp_( 0 ){};
  inline ~IterationStmt(){};
  inline void Exp( AstNode* exp ) { exp_ = exp;exp->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  inline IterationStmt* CastToIteration() { return this; }
  CLONE( IterationStmt );
 private:
  AstNode* exp_;
  CALL_ACCEPTOR( IterationStmt );
};


class ContinueStmt : public Statement {
 public :
  FACTORY( ContinueStmt );
  inline ContinueStmt() : Statement( NAME_PARAMETER(ContinueStmt) ){};
  inline ~ContinueStmt() {};
  CLONE( ContinueStmt );
 private :
  CALL_ACCEPTOR( ContinueStmt );
};



class BreakStmt : public Statement {
 public :
  FACTORY( BreakStmt );
  inline BreakStmt() : Statement( NAME_PARAMETER(BreakStmt) ) {};
  inline ~BreakStmt() {};
  CLONE( BreakStmt );
 private :
  CALL_ACCEPTOR( BreakStmt );
};



class ReturnStmt : public Statement {
 public :
  FACTORY( ReturnStmt );
  inline ReturnStmt() : Statement( NAME_PARAMETER(ReturnStmt) ){};
  inline ~ReturnStmt() {};
  CLONE( ReturnStmt );
 private :
  CALL_ACCEPTOR( ReturnStmt );
};


class WithStmt : public Statement {
 public :
  FACTORY( WithStmt );
  inline WithStmt() : Statement( NAME_PARAMETER(WithStmt) ) , exp_( 0 ){};
  inline ~WithStmt(){};
  inline void Exp( AstNode* node ) { exp_ = node;exp_->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  CLONE( WithStmt );
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( WithStmt );
};


class LabelledStmt : public Statement {
 public :
  FACTORY( LabelledStmt );
  inline LabelledStmt() : Statement( NAME_PARAMETER(LabelledStmt) ){};
  inline ~LabelledStmt() {};
  CLONE( LabelledStmt );
 private :
  CALL_ACCEPTOR( LabelledStmt );
};



class SwitchStmt : public Statement {
 public :
  FACTORY( SwitchStmt );
  inline SwitchStmt() : Statement( NAME_PARAMETER(SwitchStmt) ) , exp_( 0 ){};
  inline ~SwitchStmt() {};
  inline void Exp( AstNode* node ) { exp_ = node;exp_->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  inline SwitchStmt* CastToSwitchStmt() { return this; }
  CLONE( SwitchStmt );
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( SwitchStmt );
};



class ThrowStmt : public Statement {
 public :
  FACTORY( ThrowStmt );
  inline ThrowStmt() : Statement( NAME_PARAMETER(ThrowStmt) ) , exp_( 0 ){};
  inline ~ThrowStmt(){};
  inline void Exp( AstNode* exp ) { exp_ = exp;exp_->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  CLONE( ThrowStmt );
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( ThrowStmt );
};


class TryStmt : public Statement {
 public :
  FACTORY( TryStmt );
  inline TryStmt() : Statement( NAME_PARAMETER(TryStmt) ) , catch_( 0 ) , finally_( 0 ){};
  inline ~TryStmt(){};
  inline void Catch( AstNode* catch_stmt ) { catch_ = catch_stmt;catch_stmt->ParentNode( this ); }
  inline AstNode* Catch() { return catch_; }
  inline void Finally( AstNode* finally_stmt ) { finally_ = finally_stmt;finally_stmt->ParentNode( this ); }
  inline AstNode* Finally() { return finally_; }
  CLONE( TryStmt );
 private :
  AstNode* catch_;
  AstNode* finally_;
  CALL_ACCEPTOR( TryStmt );
};

class AssertStmt : public Statement {
 public :
  FACTORY( AssertStmt );
  inline AssertStmt() : Statement( NAME_PARAMETER(AssertStmt) ){}
  inline ~AssertStmt(){}
  CLONE( AssertStmt );
 private :
  CALL_ACCEPTOR( AssertStmt );
};

class CaseClause : public AstNode {
 public :
  FACTORY( CaseClause );
  inline CaseClause() : AstNode( AstNode::kCase , "CaseClause" ) , exp_( 0 ){}
  inline ~CaseClause(){}
  inline void Exp( AstNode* node ) { exp_ = node;exp_->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  CLONE( CaseClause );
 private :
  AstNode* exp_;
  CALL_ACCEPTOR( CaseClause );
};


class Expression : public AstNode {
 private :
  enum {
    kParenFlg,
    kValidLhsFlg,
    kLhsFlg,
    kUnaryExpFlg
  };
 public :
  FACTORY( Expression );
  inline Expression() : AstNode( AstNode::kExpression , "Expression" ) {
    flags_.Set( kValidLhsFlg );
  };
  inline Expression( int type , const char* name = "Expression" ) : AstNode( type , name ) {
    flags_.Set( kValidLhsFlg );
  };
  virtual inline ~Expression(){};
  inline void Paren() { flags_.Set( kParenFlg ); };
  inline bool IsParen() { return flags_.At( kParenFlg );; };
  inline void NoParen() { flags_.UnSet( kParenFlg ); };
  inline bool IsValidLhs() { return flags_.At( kValidLhsFlg ); }
  inline void InValidLhs() { flags_.UnSet( kValidLhsFlg ); }
  inline void ValidLhs() { flags_.Set( kValidLhsFlg ); }
  inline void Lhs() { flags_.Set( kLhsFlg ); }
  inline bool IsLhs() { return flags_.At( kLhsFlg ); }
  inline void Unary() { flags_.Set( kUnaryExpFlg ); }
  inline bool IsUnary() { return flags_.At( kUnaryExpFlg ); }
  inline Expression* CastToExpression() { return this; }
  inline virtual AssignmentExp* CastToAssigment() { return 0; }
  inline virtual CallExp* CastToCallExp() { return 0; }
  inline virtual Function* CastToFunction() { return 0; }
  inline virtual Property* CastToProperty() { return 0; }
  inline virtual Trait* CastToTrait() { return 0; }
  inline virtual BinaryExp* CastToBinary() { return 0; }
  inline virtual UnaryExp* CastToUnaryExp() { return 0; }
  inline virtual TraitMember* CastToTraitMember() { return 0; }
  inline virtual MixinMember* CastToMixinMember() { return 0; }
  inline virtual CompareExp* CastToCompareExp() { return 0; }
  inline JSValue* Analyze( Analyzer* analyzer ) { return NVIAcceptWithReturn( analyzer ); }
  virtual CLONE( Expression );
 private :
  BitVector8 flags_;
  virtual CALL_ACCEPTOR( Expression );
  virtual CALL_ACCEPTOR_WITH_RETURN( Expression );
};


class TraitMember : public Expression {
 public :
  typedef enum {
    kPublic,
    kPrivate
  } TraitAttr;
  static inline TraitMember* New( TraitAttr type , AstNode* property ) {
    return ManagedHandle::Retain( new TraitMember( type , property ) );
  }
  TraitMember( TraitAttr type , AstNode* property ) : Expression( NAME_PARAMETER( TraitMember ) ),
                                                      type_( type ) , property_( property ){}
  ~TraitMember(){}
  AstNode* GetProperty() { return property_; };
  TraitAttr GetAttr() { return type_; }
  inline TraitMember* CastToTraitMember() { return this; }
 private :
  void NVIAccept_( IVisitor* ){}
  TraitAttr type_;
  AstNode* property_;
};


class MixinMember : public Expression {
 public :
  FACTORY( MixinMember );
  MixinMember() : Expression( NAME_PARAMETER( MixinMember ) ) , name_( 0 ){}
  ~MixinMember(){}
  void SetName( AstNode* name ) { name_ = name;name->ParentNode( this ); }
  AstNode* GetName() { return name_; }
  void AddRename( AstNode* rename_list ) {  rename_list_.AddChild( rename_list );rename_list->ParentNode( this ); }
  void AddRemoval( AstNode* removal_member ) {  remove_list_.AddChild( removal_member );removal_member->ParentNode( this ); }
  NodeList* GetRename() { return &rename_list_; }
  NodeList* GetRemoval() { return &remove_list_; }
  inline MixinMember* CastToMixinMember() { return this; }
 private :
  AstNode* name_;
  NodeList remove_list_;
  NodeList rename_list_;
};

class Trait : public Expression {
 public :
  FACTORY( Trait );
  Trait() : Expression( NAME_PARAMETER( Trait ) ) ,is_decl_( false ) , name_( 0 ){}
  ~Trait(){};
  void SetMember( TraitMember* member ) {
    if ( member->GetAttr() == TraitMember::kPublic ) {
      public_member_.AddChild( member );
    } else {
      private_member_.AddChild( member );
    }
  }
  void SetName( AstNode* value ) { name_ = value; }
  AstNode* GetName() { return name_; }
  void SetRequire( AstNode* require ) { require_list_.AddChild( require ); }
  void SetMixin( AstNode* mixin ) { mixin_list_.AddChild( mixin ); }
  NodeList* GetPublic() { return &public_member_; }
  NodeList* GetPrivate() { return &private_member_; }
  NodeList* GetRequireList() { return &require_list_; }
  NodeList* GetMixinList() { return &mixin_list_; }
  inline Trait* CastToTrait() { return this; }
  void Decl() { is_decl_ = true; }
  bool IsDecl() { return is_decl_; }
 private :
  CALL_ACCEPTOR( Trait );
  bool is_decl_;
  AstNode* name_;
  NodeList private_member_;
  NodeList public_member_;
  NodeList require_list_;
  NodeList mixin_list_;
};


class Class : public Expression {
 public :
  static inline Class* New( AstNode* expandar , bool is_const ) {
    return ManagedHandle::Retain( new Class( expandar , is_const ) );
  }
  Class( AstNode* expandar , bool is_const ) :
      Expression( NAME_PARAMETER( Class ) ) , is_const_( is_const ),
      is_decl_( true ) , is_inner_( false ) ,name_( 0 ),body_( 0 ), expandar_( expandar ){}
  Class( Empty* empty ) : Expression( NAME_PARAMETER( Class ) ) , expandar_( empty ){}
  ~Class(){}
  void Decl( bool is ) { is_decl_ = is; }
  bool Decl() { return is_decl_; }
  bool Const() { return is_const_; }
  void Inner( bool is ) { is_inner_ = is; }
  bool Inner() { return is_inner_; }
  void Name( AstNode* name ) { name_ = name; }
  AstNode* Name() { return name_; }
  AstNode* Expandar() { return expandar_; }
  void Body( AstNode* body ) {
    body->ParentNode( this );
    body_ = body;
  }
  AstNode* Body() { return body_; }
  CLONE( Class );
 private :
  CALL_ACCEPTOR( Class );
  bool is_const_;
  bool is_decl_;
  bool is_inner_;
  AstNode* name_;
  AstNode* body_;
  AstNode* expandar_;
};

class ClassProperties : public AstNode {
 public :
  FACTORY( ClassProperties );
  ClassProperties() : AstNode( NAME_PARAMETER( ClassProperties ) ),constructor_( 0 ){};
  ~ClassProperties(){};
  void Public( AstNode* pb ) { public_.AddChild( pb ); }
  void Private( AstNode* pv ) { private_.AddChild( pv ); }
  void PublicStatic( AstNode* st ) { public_static_.AddChild( st ); }
  void PrivateStatic( AstNode* st ) { private_static_.AddChild( st ); }
  void Prototype( AstNode* pt ) { prototype_.AddChild( pt ); }
  void Mixin( AstNode* mi ) { mixin_.AddChild( mi ); }
  AstNode* Public() { return &public_; }
  AstNode* Private() { return &private_; }
  AstNode* PublicStatic() { return &public_static_; }
  AstNode* PrivateStatic() { return &private_static_; }
  AstNode* Prototype() { return &prototype_; }
  AstNode* Mixin() { return &mixin_; }
  void Constructor( AstNode* constructor ) { constructor_ = constructor; }
  AstNode* Constructor() { return constructor_; }
  CLONE( ClassProperties );
 private :
  CALL_ACCEPTOR(ClassProperties);
  NodeList public_;
  NodeList private_;
  NodeList public_static_;
  NodeList private_static_;
  NodeList prototype_;
  NodeList mixin_;
  AstNode* constructor_;
};

class ClassExpandar : public AstNode {
 public :
  typedef enum {
    kExtends,
    kPrototype
  } ExpandAttr;
  static inline ClassExpandar* New( ExpandAttr attr ) { return ManagedHandle::Retain( new ClassExpandar( attr ) ); }
  ClassExpandar( ExpandAttr attr ) : AstNode( NAME_PARAMETER( ClassExpandar ) ) , attr_( attr ){};
  ~ClassExpandar(){};
  ExpandAttr Type() { return attr_; }
  CLONE( ClassExpandar );
 private :
  CALL_ACCEPTOR( ClassExpandar );
  ExpandAttr attr_;
};


class ClassMember : public AstNode {
 public :
  typedef enum {
    kPrivate,
    kPublic,
    kPrototype,
    kPublicStatic,
    kPrivateStatic,
    kConstructor,
    kMixin
  } MemberAttr;
  static inline ClassMember* New( MemberAttr attr ) { return ManagedHandle::Retain( new ClassMember( attr ) ); }
  ClassMember( MemberAttr attr ) : AstNode( NAME_PARAMETER( ClassMember ) ) , attr_( attr ){}
  ~ClassMember(){}
  MemberAttr Attr() { return attr_; }
  CLONE( ClassMember );
 private :
  CALL_ACCEPTOR( ClassMember );
  MemberAttr attr_;
};


class Function : public Expression {
 public :
  typedef std::vector<AstNode*> StmtList;
  typedef std::vector<ValueNode*> VariableList;
  typedef std::vector<TryStmt*> TryList;
  enum {
    kNormal,
    kShorten,
  };
  typedef enum {
    kGet = 1,
    kSet = 2
  } FnAttr;
  enum {
    kGlobal,
    kThis
  };
  FACTORY( Function );
  inline Function() : Expression( NAME_PARAMETER( Function ) ),
                      fn_type_( kNormal ) , context_( kGlobal ) , is_const_( false ),is_decl_( false ),
                      is_root_( false ),
                      has_yield_( false ),has_directive_( false ),
                      name_( 0 ) , argv_( 0 ) , replaced_this_( 0 ) , iteration_list_( 0 ) {};
  inline ~Function(){};
  inline Function* CastToFunction() { return this; }
  inline void Name( AstNode* name ){ name_ = name; };
  inline AstNode* Name(){ return name_; };
  inline AstNode* Argv(){ return argv_; };
  inline void Argv( AstNode* argv ) { argv_ = argv;argv_->ParentNode( this ); };
  inline int Argc() const { return argv_->ChildLength(); }
  inline void Const() { is_const_ = true; }
  inline bool IsConst() const { return is_const_; }
  inline void Decl() { is_decl_ = true; }
  inline bool IsDecl() { return is_decl_; }
  inline void Attr( FnAttr attr ) { fn_attr_ |= attr; }
  inline bool IsAttr( FnAttr attr ) { return ( fn_attr_ & attr ) == attr; }
  inline int FunctionType() { return fn_type_; }
  inline void FunctionType( int type ) { fn_type_ = type; }
  inline int ContextType() { return context_; }
  inline void ContextType( int type ) { context_ = type; }
  inline void SetScope( InnerScope* scope ){ scope_ = scope; };
  inline InnerScope* GetScope(){ return scope_; };
  inline void Root( bool is ) { is_root_ = is; }
  inline bool Root() { return is_root_; }
  inline void SetYieldFlag() { has_yield_ = true; }
  inline bool GetYieldFlag(){ return has_yield_; }
  inline void SetStmtWithYield( AstNode* node ) { iteration_list_.push_back( node ); }
  inline StmtList& GetStmtList() { return iteration_list_; }
  inline void SetTryCatch( TryStmt* try_stmt ) { try_list_.push_back( try_stmt ); }
  inline TryList& GetTryCatch() { return try_list_; }
  inline void SetVariable( ValueNode* node ) { variable_list_.push_back( node ); }
  inline VariableList& GetVariable() { return variable_list_; }
  inline void SetReplacedThis( ValueNode* val ) { replaced_this_ = val; }
  inline ValueNode* GetReplacedThis() { return replaced_this_; }
  inline void SetStrict() { has_directive_ = true;}
  inline bool HasStrict() { return has_directive_; }
  CLONE( Function );
 private :
  int fn_type_;
  int context_;
  int fn_attr_;
  bool is_const_;
  bool is_decl_;
  bool is_root_;
  bool has_yield_;
  bool has_directive_;
  AstNode* name_;
  AstNode* argv_;
  ValueNode* replaced_this_;
  InnerScope* scope_;
  StmtList iteration_list_;
  VariableList variable_list_;
  TryList try_list_;
  CALL_ACCEPTOR( Function );
  CALL_ACCEPTOR_WITH_RETURN( Function );
};


class CallExp : public Expression {
 public :
  enum {
    kNormalAccessor,
    kNormal,
    kBracket,
    kDot,
    kNew,
    kPrivate,
    kExtend
  };
  static inline CallExp* New( int type ) { return ManagedHandle::Retain( new CallExp( type ) ); }
  inline CallExp( int type ) : Expression( NAME_PARAMETER( CallExp ) ) , call_type_( type ) , depth_( 0 ),
                               is_call_( false ) , is_rest_( false ) , callable_( 0 ) , args_( 0 ){};
  inline ~CallExp() {};
  inline void Callable( AstNode* node ){ callable_ = node;node->ParentNode( this ); };
  inline AstNode* Callable() { return callable_; };
  inline void Args( AstNode* node ) { args_ = node;node->ParentNode( this ); };
  inline AstNode* Args() { return args_; };
  inline int CallType() { return call_type_; }
  inline void CallType( int type ) { call_type_ = type; }
  inline void Depth( int depth ) { depth_ = depth; }
  inline int Depth() { return depth_; }
  inline void Rest() { is_rest_ = true; }
  inline bool IsRest() const { return is_rest_; }
  inline CallExp* CastToCallExp() { return this; }
  inline void Call() { is_call_ = true; }
  inline bool IsCall() { return is_call_; }
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE(CallExp);
 private :
  int call_type_;
  int depth_;
  bool is_call_;
  bool is_rest_;
  AstNode* callable_;
  AstNode* args_;
  CALL_ACCEPTOR( CallExp );
  CALL_ACCEPTOR_WITH_RETURN( CallExp );
};


class NewExp : public Expression {
 public :
  FACTORY( NewExp );
  inline NewExp() : Expression( NAME_PARAMETER( NewExp ) ) , constructor_( 0 ){};
  inline ~NewExp(){};
  inline void Constructor( AstNode* node ) { constructor_ = node; };
  inline AstNode* Constructor() { return constructor_; };
  CLONE( NewExp );
 private :
  AstNode* constructor_;
  CALL_ACCEPTOR( NewExp );
  CALL_ACCEPTOR_WITH_RETURN( NewExp );
};

class YieldExp : public Expression {
 public :
  FACTORY( YieldExp );
  inline YieldExp() : Expression( NAME_PARAMETER( YieldExp ) ){}
  inline ~YieldExp(){}
  CLONE( YieldExp );
 private :
  CALL_ACCEPTOR( YieldExp );
};


class PostfixExp : public Expression {
 public :
  enum {
    kIncrement,
    kDecrement
  };
  static inline PostfixExp* New( int type ) { return ManagedHandle::Retain( new PostfixExp( type ) ); }
  inline PostfixExp( int type ) : Expression( NAME_PARAMETER( PostfixExp ) ) , post_type_( type ) , exp_( 0 ){};
  inline ~PostfixExp(){};
  inline int PostType() { return post_type_; };
  inline void Exp( AstNode* exp ) { exp_ = exp;exp->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( PostfixExp );
 private :
  int post_type_;
  AstNode* exp_;
  CALL_ACCEPTOR( PostfixExp );
  CALL_ACCEPTOR_WITH_RETURN( PostfixExp );
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
  static inline UnaryExp* New( int type ) { return ManagedHandle::Retain( new UnaryExp( type ) ); }
  inline UnaryExp( int op ) : Expression( NAME_PARAMETER( UnaryExp ) ) , op_( op ) , exp_( 0 ){};
  inline ~UnaryExp() {};
  inline void Exp( AstNode* exp ) { exp_ = exp;exp->ParentNode( this ); }
  inline AstNode* Exp() { return exp_; }
  inline int Op() { return op_; };
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  inline UnaryExp* CastToUnaryExp() { return this; }
  CLONE( UnaryExp );
 private :
  int op_;
  AstNode* exp_;
  CALL_ACCEPTOR( UnaryExp );
  CALL_ACCEPTOR_WITH_RETURN( UnaryExp );
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
  static inline BinaryExp* New( int type , AstNode* left , AstNode* right ) {
    return ManagedHandle::Retain( new BinaryExp( type , left , right ) );
  }
  inline BinaryExp( int op , AstNode* left , AstNode* right ) : Expression( NAME_PARAMETER( BinaryExp ) ) , op_( op ) , left_( left ) , right_( right ){
    left->ParentNode( this );
    right->ParentNode( this );
  };
  inline ~BinaryExp() {};
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
  inline BinaryExp* CastToBinary() { return this; }
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( BinaryExp );
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( BinaryExp );
  CALL_ACCEPTOR_WITH_RETURN( BinaryExp );
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
  static inline CompareExp* New( int op , AstNode* left , AstNode* right ) {
    return ManagedHandle::Retain( new CompareExp( op , left , right ) );
  }
  inline CompareExp( int op , AstNode* left , AstNode* right ) : Expression( NAME_PARAMETER( CompareExp ) ) , op_( op ) , left_( left ) , right_( right ){
    left->ParentNode( this );
    right->ParentNode( this );
  };
  inline ~CompareExp(){};
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
  inline CompareExp* CastToCompareExp() { return this; }
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( CompareExp );
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( CompareExp );
  CALL_ACCEPTOR_WITH_RETURN( CompareExp );
};


class ConditionalExp : public Expression {
 public :
  static inline ConditionalExp* New( AstNode* cond , AstNode* case_true , AstNode* case_false ) {
    return ManagedHandle::Retain( new ConditionalExp( cond , case_true , case_false ) );
  }
  inline ConditionalExp( AstNode* cond , AstNode* case_true , AstNode* case_false ) :
      Expression( NAME_PARAMETER( ConditionalExp ) ),
      cond_( cond ) , case_true_( case_true ) , case_false_( case_false ){
    case_true->ParentNode( this );
    case_false->ParentNode( this );
    cond->ParentNode( this );
  };
  inline ~ConditionalExp(){};
  inline AstNode* True() { return case_true_; };
  inline AstNode* False() { return case_false_; };
  inline AstNode* Cond() { return cond_; };
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( ConditionalExp );
 private :
  AstNode* cond_;
  AstNode* case_true_;
  AstNode* case_false_;
  CALL_ACCEPTOR( ConditionalExp );
  CALL_ACCEPTOR_WITH_RETURN( ConditionalExp );
};



class AssignmentExp : public Expression {
 public :
  static inline AssignmentExp* New( int op , AstNode* left , AstNode* right ) {
    return ManagedHandle::Retain( new AssignmentExp( op , left , right ) );
  }
  inline AssignmentExp( int op , AstNode* left , AstNode* right ) :
      Expression( NAME_PARAMETER( AssignmentExp ) ),
      op_( op ) , left_( left ) , right_( right ){
    left_->ParentNode( this );
    right_->ParentNode( this );
  };
  inline AssignmentExp* CastToAssigment() { return this; }
  inline AstNode* Left() { return left_; };
  inline AstNode* Right() { return right_; };
  inline int Op() { return op_; };
  void ReplaceChild( AstNode* old_node , AstNode* new_node );
  CLONE( AssignmentExp );
 private :
  int op_;
  AstNode* left_;
  AstNode* right_;
  CALL_ACCEPTOR( AssignmentExp );
  CALL_ACCEPTOR_WITH_RETURN( AssignmentExp );
};



class ValueNode : public Expression {
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
    kConstant,
    kRest,
    kProperty,
    kPrivateProperty,
    kSuper,
    kGenerator,
    kTuple,
    kRecord,
    kNaN
  };
  static inline ValueNode* New( int type ) {
    return ManagedHandle::Retain( new ValueNode( type ) );
  }
  inline ValueNode( int type ) :
      Expression( AstNode::kValueNode , "ValueNode" ) , value_type_( type ) , value_( 0 ) , node_( 0 ){};
  inline ~ValueNode() {};
  inline void ValueType( int value_type ) { value_type_ = value_type; }
  inline int ValueType() const { return value_type_; };
  inline void Symbol( TokenInfo* value ) { value_ = value; };
  inline TokenInfo* Symbol() const { return value_; };
  inline void Node( AstNode* node ) { node_ = node; node->ParentNode( this ); };
  inline AstNode* Node() const { return node_; };
  inline ValueNode* CastToValue() { return this; }
  CLONE( ValueNode );
 private :
  int value_type_;
  TokenInfo* value_;
  AstNode* node_;
  CALL_ACCEPTOR( ValueNode );
  CALL_ACCEPTOR_WITH_RETURN( ValueNode );
};



class DstaTree : public AstNode {
 public :
  FACTORY( DstaTree );
  DstaTree() : AstNode( NAME_PARAMETER( DstaTree ) ) , symbol_( 0 ){};
  ~DstaTree(){};
  void Symbol( ValueNode* name_node ) { symbol_ = name_node; }
  ValueNode* Symbol() { return symbol_; }
  inline DstaTree* CastToDstaTree() { return this; }
  CLONE( DstaTree );
 private :
  ValueNode* symbol_;
};

class VersionStmt : public Statement {
 public :
  static inline VersionStmt* New( TokenInfo* info ) {
    return ManagedHandle::Retain( new VersionStmt( info ) );
  }
  VersionStmt( TokenInfo* info ) : Statement( NAME_PARAMETER( VersionStmt ) ) , ver_( info ){};
  ~VersionStmt() {}
  TokenInfo* Ver() { return ver_; }
  CLONE( VersionStmt );
 private :
  CALL_ACCEPTOR(VersionStmt);
  TokenInfo *ver_;
};

class DstaExtractedExpressions : public AstNode {
 public :
  FACTORY( DstaExtractedExpressions );
  DstaExtractedExpressions() : AstNode( NAME_PARAMETER( DstaExtractedExpressions ) ) {};
  ~DstaExtractedExpressions(){}
  NodeList* Refs() { return &refs_; }
  void Refs( ValueNode* tmp_name_node ) { refs_.AddChild( tmp_name_node ); }
  CLONE( DstaExtractedExpressions );
 private :
  NodeList refs_;
};

void Statement::ResetDsta()  {
  has_dsta_ = false;
  dsta_exp_->RemoveAllChild();
  dsta_exp_->Refs()->RemoveAllChild();
}

const char* PragmaStmt::Op() { return op_->CastToValue()->Symbol()->GetToken(); }
void PragmaStmt::Op( ValueNode* op ) { op_ = op;op->ParentNode( this ); }

}//namespace mocha

#undef NVI_ACCEPT_WITH_RETURN_DECL
#undef NVI_ACCEPTOR_DECL
#undef CALL_ACCEPTOR
#undef CALL_ACCEPTOR_WITH_RETURN
#undef NAME_PARAMETER
#undef FACTORY

#endif //mocha_ast_h_
