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

#ifndef mocha_ast_ast_h_
#define mocha_ast_ast_h_
#include <stdio.h>
#include <string>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/misc/class_traits/unallocatable.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
#include <mocha/roaster/nexc/tokens/token_info.h>

namespace mocha {
#define NVI_ACCEPTOR_DECL virtual void NVIAccept_(IVisitor*)
#define CALL_ACCEPTOR(name) void NVIAccept_(IVisitor* visitor){visitor->Visit##name(this);}
#define SET(num) flags_.Set(num)
#define HAS(num) flags_.At(num)
#define CLONE virtual AstNode* Clone(memory::Pool* pool);
class JSValue;
/**
 * @class
 * Iterator of node lists.
 */
class NodeIterator{
 public :
  NodeIterator() : node_(0){}
  explicit NodeIterator(AstNode* node) : node_(node){}
  ~NodeIterator(){}
  NodeIterator(const NodeIterator& iterator) {
    node_ = iterator.node_;
  }
  const NodeIterator& operator =(const NodeIterator& iterator) {
    node_ = iterator.node_;
    return (*this);
  }
  /**
   * @param {bool}
   * @returns {AstNode*}
   * Check current node is 0 or not.
   */
  bool HasNext() const { return (node_ != 0)? true : false; }

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
  AstNode* Item() const { return node_; };
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
  explicit ReverseNodeIterator(AstNode* node) : node_(node){}
  ~ReverseNodeIterator(){}
  bool HasNext() const { return (node_ != 0)? true : false; }
  AstNode* Next();
  AstNode* Item() const { return node_; };
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
class AstNode : public memory::Allocated {
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
    kSourceStmt,
    kIncludeStmt,
    kExpression,
    kVariableDeclarationList,
    kLiteral,
    kCase,
    kNodeList,
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
    kArrayLikeLiteral,
    kObjectLikeLiteral,
    kGeneratorExpression,
    kDstaTree,
    kDstaExtractedExpressions,
    kUndefined
  };

  virtual ~AstNode(){};

  /**
   * @returns {bool}
   * Return that this node has parent ast node or not.
   */
  bool HasParent() const { return parent_ != 0; };

  /**
   * @returns {AstNode*}
   * Return parent ast node.
   * If a parent node is empty, return 0;
   */
  AstNode* parent_node() { return parent_; };

  /**
   * @param {AstNode*} node
   * Set a parent node of this node.
   */
  void set_parent_node(AstNode* node) { parent_ = node; }

  /**
   * @returns {AstNode*}
   * Return a first child of this node.
   * If child nodes are empty, return 0;
   */
  AstNode* first_child() { return first_child_; };

  /**
   * @returns {AstNode*}
   * Return a last child of this node.
   * If child nodes are empty, return 0.
   * If child nodes length is less than 2,
   * return a first child node.
   */
  AstNode* last_child() { return last_child_; };

  /**
   * @returns {AstNode*}
   * Return next sibling node,
   * If the next sibling is empty, return 0.
   */
  AstNode* next_sibling() { return next_sibling_; };

  /**
   * @returns {AstNode*}
   * Return prev sibling node,
   * If the prev sibling is empty, return 0.
   */
  AstNode* previous_sibling() { return prev_sibling_; };

  /**
   * @returns {bool}
   * Check that the next sibling node is there.
   */
  bool HasNext() const { return next_sibling_ != 0; }

  /**
   * @returns {bool}
   * Check that the prev sibling node is there.
   */
  bool HasPrev() const { return prev_sibling_ != 0; }

  /**
   * @returns {bool}
   * Check this node has children or not.
   */
  bool HasChild() const { return first_child_ != 0; }

  /**
   * @param {AstNode*}
   * Insert a node to next sibling of this node.
   */
  void After(AstNode* node) { next_sibling_ = node; if (node) node->prev_sibling_ = this; };

  /**
   * @param {AstNode*}
   * Insert a node to previous sibling of this node.
   */
  void Before(AstNode* node) { prev_sibling_ = node; if (node) node->next_sibling_ = this; };

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
  void Append(AstNode* node);

  /**
   * @returns {NodeIterator}
   * Get a iterator of the child nodes.
   * This function returns is values by value of NodeIterator.
   */
  NodeIterator ChildNodes() { return NodeIterator(first_child_); }

  /**
   * @returns {ReverseNodeIterator}
   * Get a ReverseNodeIterator of the child nodes.
   */
  ReverseNodeIterator ReverseChildNodes() { return ReverseNodeIterator(last_child_); }

  /**
   * @param {AstNode*}
   * Add child.
   */
  void AddChild(AstNode* node);

  /**
   * @params {AstNode*}
   * Insert child to the front of child nodes.
   * The node that passed as arguments is assign to the first child.
   */
  void InsertBefore(AstNode* node);

  /**
   * @param {AstNode*} insert
   * @param {AstNode*} target
   * Insert a new child node before the old node.
   */
  void InsertBefore(AstNode* insert, AstNode* target);

  /**
   * @param {AstNode*} insert
   * @param {AstNode*} target
   * Insert a new child node after the old node.
   */
  void InsertAfter(AstNode* insert, AstNode* target);

  /**
   * @param {AstNode*}
   * Remove a node that passed as arguments from the child nodes.
   */
  virtual void RemoveChild(AstNode* node);

  /**
   * Remove all child nodes.
   * In fact, this function is not delete child node,
   * but set parent_ property of all child nodes to 0 and,
   * set self properties (first_child_, last_child_ and child_length_) to 0.
   */
  virtual void RemoveAllChild();

  /**
   * @param {AstNode*}
   * Replace this node with the node that passed as arguments.
   */
  void ReplaceWith(AstNode* node);

  /**
   * @param {AstNode*}
   * Replace the old_node with new_node in childnodes.
   */
  virtual void ReplaceChild(AstNode* old_node, AstNode* new_node);

  /**
   * @returns {int}
   * Get the size of child nodes.
   */
  int child_length() const { return child_length_; }

  /**
   * @returns {int}
   * Get real type of the node.
   */
  int node_type() const { return type_; }

  /**
   * @param {IVisitor}
   * Function that accept visitor.
   * This function call private virtual NVIAcceptor_.
   */
  void Accept(IVisitor* visitor) { NVIAccept_(visitor); };

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
  virtual Literal* CastToLiteral() { return 0; };
  virtual DstaTree* CastToDstaTree() { return 0; }
  virtual NodeList* CastToNodeList() { return 0; }
  virtual CaseClause* CastToCaseClause() {return 0;}
  virtual FileRoot* CastToFileRoot() {return 0;}

  /**
   * Print the real node name of this node.
   */
  void PrintNodeName() const { printf("%s\n", name_); }

  /**
   * @returns {long}
   * Get line number.
   */
  int64_t line_number() const { return line_; }

  /**
   * @returns {const char*}
   * Get the real name of this node.
   */
  const char* node_name() const { return name_; }

  /**
   * @returns {AstNode*}
   * Clone node.
   */
  virtual AstNode* Clone(memory::Pool*) {return 0;};

  /**
   * @returns {bool}
   * Check this node is Empty or not.
   */
  virtual bool IsEmpty() const { return false; }
 protected :
  AstNode(int type, const char* name, int64_t line);
 private :
  NVI_ACCEPTOR_DECL{};
  int type_;
  int child_length_;
  int64_t line_;
  const char* name_;
  AstNode* parent_;
  AstNode* first_child_;
  AstNode* last_child_;
  AstNode* next_sibling_;
  AstNode* prev_sibling_;
};


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
  NodeList() : AstNode(AstNode::kNodeList, "NodeList", 0){}
  ~NodeList(){}
  NodeList* CastToNodeList() { return this; }
  CLONE;
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
  Empty() : AstNode(AstNode::kEmpty, "Empty", 0){}
  /**
   * @param {bool}
   * Only this node that IsEmpty method return true.
   */
  virtual bool IsEmpty() const { return true; }
  CLONE;
 private :
  void NVIAccept_(IVisitor*){}
};

/**
 * @class
 * Root node of abstract syntax tree,
 * in normaly, each syntax tree has this node only one in the top of tree.
 */
class AstRoot : public AstNode {
 public :
  AstRoot() : AstNode(AstNode::kAstRoot, "AstRoot", 0) ,scope_(0){}
  ~AstRoot(){};
  /**
   * @param {InnerScope*}
   * Global closure scope.
   */
  void set_scope(Scope* scope) { scope_ = scope; }
  /**
   * @retunrs {InnerScope*}
   * Return global closure scope.
   */
  Scope* scope() const { return scope_; }
  CLONE;
 private :
  Scope* scope_;
  CALL_ACCEPTOR(AstRoot);
};


/**
 * @class
 * Root block of file.
 */
class FileRoot : public AstNode {
  typedef std::pair<const char*, ModuleStmt*> ModulePair;
 public :
  typedef roastlib::unordered_map<std::string, ModuleStmt*> Modules;
  FileRoot(const char* filename) :
      AstNode(AstNode::kFileRoot, "FileRoot", 0), filename_(filename) {}
  ~FileRoot(){};
  /**
   * @returns {const char*}
   * Get file name.
   */
  const char* filename() const { return filename_.c_str(); }
  bool runtime() const { return HAS(0); }
  void set_runtime() { SET(0); }
  bool IsStrict() const { return HAS(1); }
  void MarkAsStrict() { SET(1); }
  void SetModule(const char* name, ModuleStmt* node) {
    modules_.insert(ModulePair(name, node));
  }
  ModuleStmt* FindModule(const char* name) {
    Modules::iterator it = modules_.find(name);
    if (it != modules_.end()) {
      return it->second;
    }
    return NULL;
  }
  void set_scope(Scope* scope){ scope_ = scope; };
  Scope* scope() const { return scope_; };
  const Modules& modules() {return modules_;}
  int module_size() {return modules_.size();}
  virtual FileRoot* CastToFileRoot() {return this;}
  CLONE;
 private :
  BitVector8 flags_;
  std::string filename_;
  Modules modules_;
  Scope* scope_;
  CALL_ACCEPTOR(FileRoot);
};


/**
 * @class
 * Statement block.
 * Basically this class is not used.
 */
class Statement : public AstNode {
 public :
  Statement() : AstNode(AstNode::kStatement, "Statement", 0), destructuring_node_(0){}
  virtual ~Statement() {};
  /**
   * @returns {Statement*}
   * Cast to statement.
   */
  Statement* CastToStatement() { return this; }

  virtual IterationStmt* CastToIteration() { return 0; }
  virtual ExYieldStateNode* CastToYieldState() { return 0; }
  virtual YieldMark* CastToYieldMark() { return 0; }
  virtual IFStmt* CastToIFStmt() { return 0; }
  virtual SwitchStmt* CastToSwitchStmt() { return 0; }
  virtual WithStmt* CastToWithStmt() {return 0;}
  virtual LabelledStmt* CastToLabelledStmt() {return 0;}
  virtual ThrowStmt* CastToThrowStmt() {return 0;}
  virtual TryStmt* CastToTryStmt() {return 0;}
  /**
   * @param {DstaExtractedExpression} tree
   * Set destructuring assignment tree.
   */
  void set_destructuring(DstaExtractedExpressions* tree) {
    destructuring_node_ = tree;
    SET(0);
  }
  /**
   * @returns {bool}
   * Check this node's children include destructuring assignment node.
   */
  bool IsContainDestructuring() const { return HAS(0); }

  /**
   * @returns {DstaExtractedExpression}
   * Get destructuring assignment node.
   */
  DstaExtractedExpressions* destructuring_node() const { return destructuring_node_; }

  void ContainYield() { SET(1); }
  bool IsContainYield() const { return HAS(1); }
  void MarkAsSplitableStatement() { SET(2); }
  bool IsSplitable() const { return HAS(2); }
  bool IsNeedDestructuringTmpRef() const { return HAS(3); }
  void NeedTmpRef() { SET(3); }
  void set_autoreturn() {SET(4);}
  bool autoreturn() const {return HAS(4);}
  /**
   * Set 0 to all destructuring assignment block.
   */
  void ResetDsta();
 protected :
  Statement(int type, const char* name, int64_t line) : AstNode(type, name, line), destructuring_node_(0) {};

 private :
  NVI_ACCEPTOR_DECL{};
  BitVector8 flags_;
  DstaExtractedExpressions *destructuring_node_;
};

/**
 * @class
 * Statement list.
 * This class behave like the NodeList.
 */
class StatementList : public AstNode {
 public :
  StatementList()
      : AstNode(AstNode::kStatementList, "StatementList", 0),
        auto_return_(false){}
  ~StatementList(){}
  void set_autoreturn() {auto_return_ = true;}
  bool autoreturn() {return auto_return_;}
  CLONE;
 private :
  bool auto_return_;
  CALL_ACCEPTOR(StatementList);
};


#define NAME_PARAMETER(name) AstNode::k##name, #name


class YieldMark : public Statement {
 public :
  YieldMark() : Statement(NAME_PARAMETER(YieldMark), 0), adjustment_(0), is_state_injection_(false), state_(0){}
  ~YieldMark() {}
  void ReEntrantNode(Literal* val){ state_ = val; }
  Literal* ReEntrantNode() const { return state_; }
  YieldMark* CastToYieldMark() { return this; }
  int Adjust(int val) { return val + adjustment_; }
  void SetAdjust(int val) { adjustment_ = val; }
  void SetNoStateInjection() { is_state_injection_ = true; }
  bool GetNoStateInjection() const { return is_state_injection_; }
 private :
  int adjustment_;
  bool is_state_injection_;
  Literal* state_;
};


class ExYieldStateNode : public Statement {
 public :
  ExYieldStateNode() :
      Statement(NAME_PARAMETER(ExYieldStateNode), 0), loopback_ptr_(0),
      next_ptr_(0), escape_ptr_(0), if_stmt_ptr_(0) {}
  ~ExYieldStateNode(){};
  ExYieldStateNode* CastToYieldState() { return this; }
  void EscapePtr(Literal* ptr) { escape_ptr_ = ptr; }
  Literal* EscapePtr() { return escape_ptr_; }
  void LoopBackPtr(Literal* ptr) { loopback_ptr_ = ptr; }
  Literal* LoopBackPtr() { return loopback_ptr_; }
  void NextPtr(Literal* ptr) { next_ptr_ = ptr; }
  Literal* NextPtr() { return next_ptr_; }
  void IfStmtPtr(IFStmt* ptr) { if_stmt_ptr_ = ptr; }
  IFStmt* IfStmtPtr() { return if_stmt_ptr_; }
 private :
  Literal* loopback_ptr_;
  Literal* next_ptr_;
  Literal* escape_ptr_;
  IFStmt* if_stmt_ptr_;
};

/**
 * @class
 * Block statement node.
 */
class BlockStmt : public Statement {
 public :
  explicit BlockStmt(int64_t line) : Statement(NAME_PARAMETER(BlockStmt), line){};
  ~BlockStmt() {};
  CLONE;
 private :
  CALL_ACCEPTOR(BlockStmt);
};


/**
 * @class
 * Module statement node.
 */
class ModuleStmt : public Statement {
  typedef std::pair<const char*, Literal*> Pair;
  typedef std::pair<const char*, ModuleStmt*> ModulePair;
 public :
  typedef roastlib::unordered_map<std::string, Literal*> Exports;
  typedef roastlib::unordered_map<std::string, ModuleStmt*> Modules;
  enum {
    kBlock,
    kAssign
  };
  ModuleStmt(AstNode* name, int module_type, int64_t line) :
      Statement(NAME_PARAMETER(ModuleStmt), line),
      type_(module_type),
      root_(false),
      name_(name){};
  ~ModuleStmt() {};
  int module_type() const {return type_;}
  /**
   * @returns {AstNode*}
   * Get module name.
   */
  AstNode* name() const { return name_; }
  void MarkAsRoot() {root_ = true;}
  bool IsRoot() {return root_;}
  void SetModule(const char* name, ModuleStmt* stmt) {
    modules_.insert(ModulePair(name, stmt));
  }
  void SetExports(Literal* lit);
  ModuleStmt* FindModule(const char* name) {
    Modules::iterator it = modules_.find(name);
    if (it != modules_.end()) {
      return it->second;
    }
    return NULL;
  }
  Literal* FindExports(const char* name) {
    Exports::iterator it = exports_.find(name);
    if (it != exports_.end()) {
      return it->second;
    }
    return NULL;
  }
  const Modules& modules() {return modules_;}
  const Exports& exports() {return exports_;}
  CLONE;
 private :
  int type_;
  bool root_;
  AstNode* name_;
  Modules modules_;
  Exports exports_;
  CALL_ACCEPTOR(ModuleStmt);
};


/**
 * @class
 * Export statement node.
 */
class ExportStmt : public Statement {
 public :
  explicit ExportStmt(int64_t line) : Statement(NAME_PARAMETER(ExportStmt), line){};
  ~ExportStmt() {};
  CLONE;
 private :
  CALL_ACCEPTOR(ExportStmt);
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
    kAll,
    kAs
  };
  ImportStmt(int expression_type, int module_type, int64_t line) :
      Statement(NAME_PARAMETER(ImportStmt), line),
      expression_type_(expression_type),
      module_type_(module_type),
      expression_(0),
      from_(0),
      module_key_(0),
      filename_(0){}
  ~ImportStmt(){};

  /**
   * @param {AstNode*} exp
   * Set the expression node.
   * import <...> form <...>
   *          |
   *         this
   */
  void set_expression(AstNode* exp) { expression_ = exp;exp->set_parent_node(this); }

  /**
   * @returns {AstNode*}
   * Get the expression node.
   */
  AstNode* expression() const { return expression_; }

  /**
   * @param {AstNode*} exp
   * Set the expression node that continue after from keyword.
   * import <...> form <...>
   *                     |
   *                    this
   */
  void set_from(AstNode* from) { from_ = from;from->set_parent_node(this); }

  /**
   * @param {AstNode*}
   * Get from after expression.
   */
  AstNode* from() const { return from_; }

  /**
   * @param {TokenInfo*} key
   * Set the module load key,
   * this key used in compiled javascript.
   */
  void set_module_key(TokenInfo* key) { module_key_ = key; }

  /**
   * @returns {TokenInfo*}
   * Get module key.
   */
  TokenInfo* module_key() const { return module_key_; }

  void set_filename(TokenInfo* name) {filename_ = name;}
  TokenInfo* filename() {return filename_;}
  
  //Type getter.
  int expression_type() const { return expression_type_; }
  int module_type() const { return module_type_; }
  void virtual ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :

  int expression_type_;
  int module_type_;
  AstNode* expression_;
  AstNode* from_;
  TokenInfo* module_key_;
  TokenInfo* filename_;
  CALL_ACCEPTOR(ImportStmt);
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
  VariableStmt(int64_t line) : Statement(NAME_PARAMETER(VariableStmt), line){};
  ~VariableStmt(){};
  CLONE;
 private :
  CALL_ACCEPTOR(VariableStmt);
};


/**
 * @class
 * Let statement node.
 * This class is node used. 2011/12/28
 */
class LetStmt : public Statement {
 public :
  LetStmt(AstNode* exp, int64_t line) :
      Statement(NAME_PARAMETER(LetStmt), line), expression_(exp) {
    expression_->set_parent_node(this);
  }
  ~LetStmt(){}
  AstNode* expression() const { return expression_; }
  CLONE;
 private :
  AstNode* expression_;
  CALL_ACCEPTOR(LetStmt);
};


/**
 * @class
 * Expression statement node.
 */
class ExpressionStmt : public Statement {
 public :
  ExpressionStmt(int64_t line) : Statement(AstNode::kExpressionStmt, "ExpressionStmt", line) {};
  ~ExpressionStmt(){};
  CLONE;
 private :
  CALL_ACCEPTOR(ExpressionStmt);
};


/**
 * @class
 * If statement node.
 */
class IFStmt : public Statement {
 public :
  explicit IFStmt(int64_t line) :
      Statement(NAME_PARAMETER(IFStmt), line), condition_(0), then_statement_(0), else_statement_(0){};
  ~IFStmt(){};
  IFStmt* CastToIFStmt() { return this; }
  /**
   * @param {AstNode*} exp
   * Set expression node.
   * if (<...>) { ...
   *        |
   *       this
   */
  void set_condition(AstNode* exp) { condition_ = exp;exp->set_parent_node(this); }

  /**
   * @returns {AstNode*}
   * Get expression node.
   */
  AstNode* condition() const { return condition_; }
  void set_then_statement(AstNode* node) { then_statement_ = node;node->set_parent_node(this); }
  AstNode* then_statement() const { return then_statement_; }
  void set_else_statement(AstNode* els) { else_statement_ = els;els->set_parent_node(this); }
  AstNode* else_statement() const { return else_statement_; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  AstNode* condition_;
  AstNode* then_statement_;
  AstNode* else_statement_;
  CALL_ACCEPTOR(IFStmt);
};


class IterationStmt : public Statement {
 public :
  IterationStmt(int type, int64_t line) : Statement(type, "IterationStmt", line), expression_(0){};
  ~IterationStmt(){};
  void set_expression(AstNode* exp) { expression_ = exp;exp->set_parent_node(this); }
  AstNode* expression() { return expression_; }
  IterationStmt* CastToIteration() { return this; }
  CLONE;
 private:
  AstNode* expression_;
  CALL_ACCEPTOR(IterationStmt);
};


class ContinueStmt : public Statement {
 public :
  explicit ContinueStmt(int64_t line) : Statement(NAME_PARAMETER(ContinueStmt), line){};
  ~ContinueStmt() {};
  CLONE;
 private :
  CALL_ACCEPTOR(ContinueStmt);
};



class BreakStmt : public Statement {
 public :
  explicit BreakStmt(int64_t line) : Statement(NAME_PARAMETER(BreakStmt), line) {};
  ~BreakStmt() {};
  CLONE;
 private :
  CALL_ACCEPTOR(BreakStmt);
};



class ReturnStmt : public Statement {
 public :
  explicit ReturnStmt(int64_t line) : Statement(NAME_PARAMETER(ReturnStmt), line){};
  ~ReturnStmt() {};
  CLONE;
 private :
  CALL_ACCEPTOR(ReturnStmt);
};


class WithStmt : public Statement {
 public :
  explicit WithStmt(int64_t line) : Statement(NAME_PARAMETER(WithStmt), line), expression_(0){};
  ~WithStmt(){};
  void set_expression(AstNode* node) { expression_ = node;expression_->set_parent_node(this); }
  AstNode* expression() { return expression_; }
  virtual WithStmt* CastToWithStmt() {return this;}
  CLONE;
 private :
  AstNode* expression_;
  CALL_ACCEPTOR(WithStmt);
};


class LabelledStmt : public Statement {
 public :
  explicit LabelledStmt(int64_t line) : Statement(NAME_PARAMETER(LabelledStmt), line){};
  ~LabelledStmt() {};
  virtual LabelledStmt* CastToLabelledStmt() {return this;}
  CLONE;
 private :
  CALL_ACCEPTOR(LabelledStmt);
};



class SwitchStmt : public Statement {
 public :
  explicit SwitchStmt(int64_t line) : Statement(NAME_PARAMETER(SwitchStmt), line), expression_(0){};
  ~SwitchStmt() {};
  void set_expression(AstNode* node) { expression_ = node;expression_->set_parent_node(this); }
  AstNode* expression() { return expression_; }
  SwitchStmt* CastToSwitchStmt() { return this; }
  CLONE;
 private :
  AstNode* expression_;
  CALL_ACCEPTOR(SwitchStmt);
};



class ThrowStmt : public Statement {
 public :
  explicit ThrowStmt(int64_t line) : Statement(NAME_PARAMETER(ThrowStmt), line), expression_(0){};
  ~ThrowStmt(){};
  void set_expression(AstNode* exp) { expression_ = exp;expression_->set_parent_node(this); }
  AstNode* expression() { return expression_; }
  virtual ThrowStmt* CastToThrowStmt() {return this;}
  CLONE;
 private :
  AstNode* expression_;
  CALL_ACCEPTOR(ThrowStmt);
};


class TryStmt : public Statement {
 public :
  explicit TryStmt(int64_t line) : Statement(NAME_PARAMETER(TryStmt), line), catch_block_(0), finally_block_(0){};
  ~TryStmt(){};
  void set_catch_block(AstNode* catch_stmt) { catch_block_ = catch_stmt;catch_stmt->set_parent_node(this); }
  AstNode* catch_block() { return catch_block_; }
  void set_finally_block(AstNode* finally_stmt) { finally_block_ = finally_stmt;finally_stmt->set_parent_node(this); }
  AstNode* finally_block() { return finally_block_; }
  virtual TryStmt* CastToTryStmt() {return this;}
  CLONE;
 private :
  AstNode* catch_block_;
  AstNode* finally_block_;
  CALL_ACCEPTOR(TryStmt);
};

class AssertStmt : public Statement {
 public :
  explicit AssertStmt(int64_t line) : Statement(NAME_PARAMETER(AssertStmt), line){}
  ~AssertStmt(){}
  CLONE;
 private :
  CALL_ACCEPTOR(AssertStmt);
};

class SourceStmt : public Statement {
 public :
  explicit SourceStmt(const char* path, int64_t line)
      : Statement(NAME_PARAMETER(SourceStmt), line),
        path_(path){}
  ~SourceStmt(){}
  const char* filecontents() const {return contents_.c_str();}
  const char* path() const {return path_.c_str();}
  void set_contents(const char* str) {contents_ = str;}
  std::string* data_container() {return &contents_;}
  CLONE;
 private :
  CALL_ACCEPTOR(SourceStmt);
  std::string path_;
  std::string contents_;
};

class IncludeStmt : public Statement {
 public :
  explicit IncludeStmt(const char* name, int64_t line)
      : Statement(NAME_PARAMETER(IncludeStmt), line),
        name_(name){}
  ~IncludeStmt(){}
  const char* path() const {return name_.c_str();}
  CLONE;
 private :
  CALL_ACCEPTOR(IncludeStmt);
  std::string name_;
};

class CaseClause : public AstNode {
 public :
  explicit CaseClause(int64_t line) : AstNode(AstNode::kCase, "CaseClause", line), expression_(0){}
  ~CaseClause(){}
  void set_expression(AstNode* node) { expression_ = node;expression_->set_parent_node(this); }
  AstNode* expression() { return expression_; }
  virtual CaseClause* CastToCaseClause() {return this;}
  CLONE;
 private :
  AstNode* expression_;
  CALL_ACCEPTOR(CaseClause);
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
  explicit Expression(int64_t line) : AstNode(AstNode::kExpression, "Expression", line) {
    flags_.Set(kValidLhsFlg);
  };
  virtual ~Expression(){};
  void MarkParenthesis() { SET(kParenFlg); };
  bool IsParenthesis() const { return HAS(kParenFlg); };
  void UnMarkParenthesis() { flags_.UnSet(kParenFlg); };
  void MarkAsValidLhs() { SET(kValidLhsFlg); }
  void MarkAsInValidLhs() { flags_.UnSet(kValidLhsFlg); }
  bool IsValidLhs() const { return HAS(kValidLhsFlg); }
  void MarkAsLhs() { SET(kLhsFlg); }
  bool IsLhs() const { return HAS(kLhsFlg); }
  void MarkAsUnary() { SET(kUnaryExpFlg); }
  bool IsUnary() const { return HAS(kUnaryExpFlg); }
  Expression* CastToExpression() { return this; }
  virtual AssignmentExp* CastToAssigment() { return 0; }
  virtual CallExp* CastToCallExp() { return 0; }
  virtual Function* CastToFunction() { return 0; }
  virtual Property* CastToProperty() { return 0; }
  virtual Trait* CastToTrait() { return 0; }
  virtual BinaryExp* CastToBinary() { return 0; }
  virtual UnaryExp* CastToUnaryExp() { return 0; }
  virtual TraitMember* CastToTraitMember() { return 0; }
  virtual MixinMember* CastToMixinMember() { return 0; }
  virtual CompareExp* CastToCompareExp() { return 0; }
  virtual ArrayLikeLiteral* CastToArrayLikeLiteral() { return 0; }
  virtual ObjectLikeLiteral* CastToObjectLikeLiteral() { return 0; }
  virtual VariableDeclarationList* CastToVariableDeclarationList() { return 0; }
  virtual PostfixExp* CastToPostfixExp() {return 0;}
  virtual Class* CastToClass() {return 0;}
  CLONE;
 protected :
  Expression(int type, const char* name, int64_t line) : AstNode(type, name, line) {
    flags_.Set(kValidLhsFlg);
  };
 private :
  BitVector8 flags_;
  CALL_ACCEPTOR(Expression);
};


class VariableDeclarationList : public Expression {
 public :
  explicit VariableDeclarationList(int64_t line)
      : Expression(NAME_PARAMETER(VariableDeclarationList), line){}
  ~VariableDeclarationList(){}
  void MarkAsConstDeclaration() { SET(0); }
  void MarkAsLetDeclaration() { SET(1); }
  bool IsDeclaredAsConst() const { return HAS(0); }
  bool IsDeclaredAsLet() const { return HAS(1); }
  virtual VariableDeclarationList* CastToVariableDeclarationList() { return this; }
  CLONE;
 private :
  CALL_ACCEPTOR(VariableDeclarationList);
  BitVector8 flags_;
};


class TraitMember : public Expression {
 public :
  typedef enum {
    kPublic,
    kPrivate
  } TraitAttr;
  TraitMember(TraitAttr type, AstNode* property, int64_t line) : Expression(NAME_PARAMETER(TraitMember), line),
                                                                     attribute_(type), property_(property){}
  ~TraitMember(){}
  AstNode* property() { return property_; };
  TraitAttr attribute() { return attribute_; }
  TraitMember* CastToTraitMember() { return this; }
 private :
  void NVIAccept_(IVisitor*){}
  TraitAttr attribute_;
  AstNode* property_;
};


class MixinMember : public Expression {
 public :
  explicit MixinMember(int64_t line) : Expression(NAME_PARAMETER(MixinMember), line), name_(0){}
  ~MixinMember(){}
  void set_name(AstNode* name) { name_ = name;name->set_parent_node(this); }
  AstNode* name() { return name_; }
  void set_rename_list(AstNode* renamable_member) {
    rename_list_.AddChild(renamable_member);
    renamable_member->set_parent_node(this);
  }
  void set_remove_list(AstNode* removal_member) {
    remove_list_.AddChild(removal_member);
    removal_member->set_parent_node(this);
  }
  NodeList* rename_list() { return &rename_list_; }
  NodeList* remove_list() { return &remove_list_; }
  MixinMember* CastToMixinMember() { return this; }
 private :
  AstNode* name_;
  NodeList remove_list_;
  NodeList rename_list_;
};

class Trait : public Expression {
 public :
  explicit Trait(int64_t line) :
      Expression(NAME_PARAMETER(Trait), line) ,declaration_(false), name_(0){}
  ~Trait(){};
  void set_member(TraitMember* member) {
    if (member->attribute() == TraitMember::kPublic) {
      public_member_.AddChild(member);
    } else {
      private_member_.AddChild(member);
    }
  }
  void set_name(AstNode* value) { name_ = value; }
  AstNode* name() { return name_; }
  void set_require(AstNode* require) { require_member_.AddChild(require); }
  void set_mixin(AstNode* mixin) { mixin_member_.AddChild(mixin); }
  NodeList* public_member() { return &public_member_; }
  NodeList* private_member() { return &private_member_; }
  NodeList* require_member() { return &require_member_; }
  NodeList* mixin_member() { return &mixin_member_; }
  Trait* CastToTrait() { return this; }
  void MarkAsDeclaration() { declaration_ = true; }
  bool IsDeclared() const { return declaration_; }
 private :
  CALL_ACCEPTOR(Trait);
  bool declaration_;
  AstNode* name_;
  NodeList private_member_;
  NodeList public_member_;
  NodeList require_member_;
  NodeList mixin_member_;
};


class Class : public Expression {
 public :
  Class(AstNode* expandar, int64_t line)
      : Expression(NAME_PARAMETER(Class), line),
        name_(0),
        body_(0),
        expandar_(expandar){}
  
  Class(int64_t line)
      : Expression(NAME_PARAMETER(Class), line),
        name_(0),
        body_(0),
        expandar_(0){}
  ~Class(){}
  void MarkAsDeclaration() { SET(0); }
  bool IsDeclared() const { return HAS(0); }
  void MarkAsConstDeclaration() { SET(1); }
  bool IsDeclaredAsConst() const { return HAS(1); }
  void set_inner() { SET(2); }
  bool inner() const { return HAS(2); }
  void set_name(AstNode* name) { name_ = name;name_->set_parent_node(this); }
  AstNode* name() { return name_; }
  AstNode* expandar() { return expandar_; }
  void set_body(AstNode* body) {
    body->set_parent_node(this);
    body_ = body;
  }
  AstNode* body() { return body_; }
  Class* CastToClass() {return this;}
  CLONE;
 private :
  CALL_ACCEPTOR(Class);
  BitVector8 flags_;
  AstNode* name_;
  AstNode* body_;
  AstNode* expandar_;
};

class ClassProperties : public AstNode {
 public :
  explicit ClassProperties(int64_t line) : AstNode(NAME_PARAMETER(ClassProperties), line),constructor_(0){};
  ~ClassProperties(){};
  void set_public_member(AstNode* pb) { public_.AddChild(pb); }
  void set_private_member(AstNode* pv) { private_.AddChild(pv); }
  void set_public_static_member(AstNode* st) { public_static_.AddChild(st); }
  void set_private_static_member(AstNode* st) { private_static_.AddChild(st); }
  void set_prototype_member(AstNode* pt) { prototype_.AddChild(pt); }
  void set_mixin_member(AstNode* mi) { mixin_.AddChild(mi); }
  NodeList* public_member() { return &public_; }
  NodeList* private_member() { return &private_; }
  NodeList* public_static_member() { return &public_static_; }
  NodeList* private_static_member() { return &private_static_; }
  NodeList* prototype_member() { return &prototype_; }
  NodeList* mixin_member() { return &mixin_; }
  void set_constructor(AstNode* constructor) { constructor_ = constructor; }
  AstNode* constructor() { return constructor_; }
  CLONE;
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
  ClassExpandar(ExpandAttr attr, int64_t line) : AstNode(NAME_PARAMETER(ClassExpandar), line), attr_(attr){};
  ~ClassExpandar(){};
  ExpandAttr attribute() const { return attr_; }
  CLONE;
 private :
  CALL_ACCEPTOR(ClassExpandar);
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
  ClassMember(MemberAttr attr, int64_t line) : AstNode(NAME_PARAMETER(ClassMember), line), attr_(attr){}
  ~ClassMember(){}
  MemberAttr attribute() const { return attr_; }
  CLONE;
 private :
  CALL_ACCEPTOR(ClassMember);
  MemberAttr attr_;
};


class Function : public Expression {
 public :
  typedef std::vector<AstNode*> StmtList;
  typedef std::vector<Literal*> VariableList;
  typedef std::vector<TryStmt*> TryCatchList;
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
  explicit Function(int64_t line)
      : Expression(NAME_PARAMETER(Function), line),
        fn_type_(kNormal),
        context_(kGlobal),
        name_(0),
        argv_(0),
        replaced_this_(0),
        scope_(0),
        statement_list_(0) {};
  ~Function(){};
  Function* CastToFunction() { return this; }
  void set_name(AstNode* name){ name_ = name; };
  AstNode* name() { return name_; };
  AstNode* argv() { return argv_; };
  void set_argv(AstNode* argv) { argv_ = argv;argv_->set_parent_node(this); };
  int argc() const { return argv_->child_length(); }
  void MarkAsConstDeclaration() { SET(0);SET(1); }
  bool IsDeclaredAsConst() const { return HAS(0); }
  void MarkAsDeclaration() { SET(1); }
  bool IsDeclared() const { return HAS(1); }
  void UnmarkDeclaration() {flags_.UnSet(0),flags_.UnSet(1);}
  int function_type() const { return fn_type_; }
  void set_function_type(int type) { fn_type_ = type; }
  int context_type() const { return context_; }
  void set_context_type(int type) { context_ = type; }
  void set_scope(Scope* scope){ scope_ = scope; };
  Scope* scope() const { return scope_; };
  void MarkAsRoot() { SET(2); }
  bool IsRoot() const { return HAS(2); }
  void MarkAsGenerator() { SET(3); }
  bool IsGenerator() const { return HAS(3); }
  void set_statement_in_generator(AstNode* node) { statement_list_.push_back(node); }
  const StmtList& statement_list() const { return statement_list_; }
  void set_try_catch_list(TryStmt* try_stmt) { try_catch_list_.push_back(try_stmt); }
  const TryCatchList& try_catch_list() const { return try_catch_list_; }
  void set_variable_list(Literal* node) { variable_list_.push_back(node); }
  const VariableList& variable_list() const { return variable_list_; }
  void set_replaced_this(Literal* val) { replaced_this_ = val; }
  Literal* replaced_this() { return replaced_this_; }
  void MarkAsStrict() { SET(4);}
  bool IsStrict() const { return HAS(4); }
  void set_attribute(int type) {
    if (type == kGet) {
      SET(5);
    } else if (type == kSet) {
      SET(6);
    }
  }
  bool attribute(int type) const { return (type == kGet)? HAS(5) : (type == kSet)? HAS(6) : false; }
  void set_autoreturn() {SET(7);}
  bool autoreturn() const {return HAS(7);}
  CLONE;
 private :
  int fn_type_;
  int context_;
  int fn_attr_;
  BitVector8 flags_;
  AstNode* name_;
  AstNode* argv_;
  Literal* replaced_this_;
  Scope* scope_;
  StmtList statement_list_;
  VariableList variable_list_;
  TryCatchList try_catch_list_;
  CALL_ACCEPTOR(Function);
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
  CallExp(int type, int64_t line) :
      Expression(NAME_PARAMETER(CallExp), line), call_type_(type),
      rest_(false), spread_(false), callable_(0), args_(0){};
  ~CallExp() {};
  void set_callable(AstNode* node){ callable_ = node;node->set_parent_node(this); };
  AstNode* callable() { return callable_; };
  void set_args(AstNode* node) { args_ = node;node->set_parent_node(this); };
  AstNode* args() { return args_; };
  int call_type() const { return call_type_; }
  void set_call_type(int type) { call_type_ = type; }
  void set_rest() { rest_ = true; }
  bool rest() const { return rest_; }
  CallExp* CastToCallExp() { return this; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  void set_spread() {spread_ = true;}
  bool spread() const {return spread_;}
  CLONE;
 private :
  int call_type_;
  bool rest_;
  bool spread_;
  AstNode* callable_;
  AstNode* args_;
  CALL_ACCEPTOR(CallExp);
};


class NewExp : public Expression {
 public :
  explicit NewExp(int64_t line) : Expression(NAME_PARAMETER(NewExp), line){};
  ~NewExp(){};
  CLONE;
 private :
  CALL_ACCEPTOR(NewExp);
};

class YieldExp : public Expression {
 public :
  explicit YieldExp(int64_t line) : Expression(NAME_PARAMETER(YieldExp), line){}
  ~YieldExp(){}
  CLONE;
 private :
  CALL_ACCEPTOR(YieldExp);
};


class PostfixExp : public Expression {
 public :
  PostfixExp(int type, AstNode* exp, int64_t line) :
      Expression(NAME_PARAMETER(PostfixExp), line), operand_(type) ,expression_(exp) {
    expression_->set_parent_node(this);
  };
  ~PostfixExp(){};
  int operand() const { return operand_; };
  AstNode* expression() { return expression_; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  virtual PostfixExp* CastToPostfixExp() {return this;}
  CLONE;
 private :
  int operand_;
  AstNode* expression_;
  CALL_ACCEPTOR(PostfixExp);
};


class UnaryExp : public Expression {
 public :
  UnaryExp(int op, AstNode* node, int64_t line) :
      Expression(NAME_PARAMETER(UnaryExp), line), operand_(op), expression_(node){
    expression_->set_parent_node(this);
  };
  ~UnaryExp() {};
  AstNode* expression() { return expression_; }
  int operand() const { return operand_; };
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  UnaryExp* CastToUnaryExp() { return this; }
  CLONE;
 private :
  int operand_;
  AstNode* expression_;
  CALL_ACCEPTOR(UnaryExp);
};


class BinaryExp : public Expression {
 public :
  BinaryExp(int op, AstNode* left, AstNode* right, int64_t line) :
      Expression(NAME_PARAMETER(BinaryExp), line), operand_(op),
      left_value_(left), right_value_(right){
    left_value_->set_parent_node(this);
    right_value_->set_parent_node(this);
  };
  ~BinaryExp() {};
  AstNode* left_value() { return left_value_; };
  AstNode* right_value() { return right_value_; };
  int operand() { return operand_; };
  BinaryExp* CastToBinary() { return this; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  int operand_;
  AstNode* left_value_;
  AstNode* right_value_;
  CALL_ACCEPTOR(BinaryExp);
};


class CompareExp : public Expression {
 public :
  CompareExp(int op, AstNode* left, AstNode* right, int64_t line) :
      Expression(NAME_PARAMETER(CompareExp), line), operand_(op),
      left_value_(left), right_value_(right){
    left->set_parent_node(this);
    right->set_parent_node(this);
  };
  ~CompareExp(){};
  AstNode* left_value() { return left_value_; };
  AstNode* right_value() { return right_value_; };
  int operand() const { return operand_; };
  CompareExp* CastToCompareExp() { return this; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  int operand_;
  AstNode* left_value_;
  AstNode* right_value_;
  CALL_ACCEPTOR(CompareExp);
};


class ConditionalExp : public Expression {
 public :
  ConditionalExp(AstNode* cond, AstNode* case_true, AstNode* case_false, int64_t line) :
      Expression(NAME_PARAMETER(ConditionalExp), line),
      condition_(cond), case_true_(case_true), case_false_(case_false){
    case_true_->set_parent_node(this);
    case_false_->set_parent_node(this);
    condition_->set_parent_node(this);
  };
  ~ConditionalExp(){};
  AstNode* case_true() { return case_true_; };
  AstNode* case_false() { return case_false_; };
  AstNode* condition() { return condition_; };
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  AstNode* condition_;
  AstNode* case_true_;
  AstNode* case_false_;
  CALL_ACCEPTOR(ConditionalExp);
};


class AssignmentExp : public Expression {
 public :
  AssignmentExp(int op, AstNode* left, AstNode* right, int64_t line) :
      Expression(NAME_PARAMETER(AssignmentExp), line),
      operand_(op), left_value_(left), right_value_(right){
    left_value_->set_parent_node(this);
    right_value_->set_parent_node(this);
  };
  AssignmentExp* CastToAssigment() { return this; }
  AstNode* left_value() { return left_value_; };
  AstNode* right_value() { return right_value_; };
  int operand() const { return operand_; };
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  int operand_;
  AstNode* left_value_;
  AstNode* right_value_;
  CALL_ACCEPTOR(AssignmentExp);
};


class Literal : public Expression {
 public :
  enum {
    kNull,
    kTrue,
    kFalse,
    kNumeric,
    kString,
    kRegExp,
    kThis,
    kUndefined,
    kIdentifier,
    kVariable,
    kSpread,
    kRest,
    kProperty,
    kPrivateProperty,
    kPrivate,
    kSuper,
    kGenerator,
    kNaN
  };
  Literal(int type, int64_t line) :
      Expression(AstNode::kLiteral, "Literal", line), value_type_(type), value_(0), node_(0){};
  virtual ~Literal(){};
  void set_value_type(int value_type) { value_type_ = value_type; }
  int value_type() const { return value_type_; };
  Literal* CastToLiteral() { return this; }
  void set_value(TokenInfo* value) { value_ = value; };
  TokenInfo* value() { return value_; };
  void set_node(AstNode* node) { node_ = node;node_->set_parent_node(this); };
  AstNode* node() { return node_; }
  CLONE;
 private :
  int value_type_;
  TokenInfo* value_;
  AstNode* node_;
  CALL_ACCEPTOR(Literal);
};


class ArrayLikeLiteral : public Expression {
 public :
  explicit ArrayLikeLiteral(int64_t line) :
      Expression(NAME_PARAMETER(ArrayLikeLiteral), line){
    elements_.set_parent_node(this);
  }
  ~ArrayLikeLiteral(){}
  void MarkAsTuple() { SET(0); }
  bool IsTuple() const { return HAS(0); }
  void MarkAsComprehensions() { SET(1); }
  bool IsComprehensions() const { return HAS(1); }
  void set_element(AstNode* element) { elements_.AddChild(element); }
  NodeList* elements() { return &elements_; }
  ArrayLikeLiteral* CastToArrayLikeLiteral() { return this; }
  CLONE;
 private :
  CALL_ACCEPTOR(ArrayLikeLiteral);
  NodeList elements_;
  BitVector8 flags_;
};


class ObjectLikeLiteral : public Expression {
 public :
  explicit ObjectLikeLiteral(int64_t line) :
      Expression(NAME_PARAMETER(ObjectLikeLiteral), line){
    elements_.set_parent_node(this);
  }
  ~ObjectLikeLiteral(){}
  void MarkAsRecord() { SET(0); }
  bool IsRecord() const { return HAS(0); }
  NodeList* elements() { return &elements_; }
  void set_element(AstNode* element) { elements_.AddChild(element); }
  ObjectLikeLiteral* CastToObjectLikeLiteral() { return this; }
  CLONE;
 private :
  CALL_ACCEPTOR(ObjectLikeLiteral);
  NodeList elements_;
  BitVector8 flags_;
};


class GeneratorExpression : public Expression {
 public :
  GeneratorExpression(AstNode* expression, int64_t line) :
      Expression(NAME_PARAMETER(GeneratorExpression), line), expression_(expression){
    MarkAsInValidLhs();
  }
  ~GeneratorExpression(){}
  AstNode* expression() const { return expression_; }
  GeneratorExpression* CastToGenerator() { return this; }
  void ReplaceChild(AstNode* old_node, AstNode* new_node);
  CLONE;
 private :
  CALL_ACCEPTOR(GeneratorExpression);
  AstNode* expression_;
};

class VersionStmt : public Statement {
 public :
  VersionStmt(TokenInfo* info, int64_t line) : Statement(NAME_PARAMETER(VersionStmt), line), version_(info){};
  ~VersionStmt() {}
  TokenInfo* version() { return version_; }
  CLONE;
 private :
  CALL_ACCEPTOR(VersionStmt);
  TokenInfo *version_;
};


class DstaTree : public AstNode {
 public :
  DstaTree() : AstNode(NAME_PARAMETER(DstaTree), 0), symbol_(0){};
  ~DstaTree(){};
  void set_symbol(Literal* name_node) { symbol_ = name_node; }
  Literal* symbol() { return symbol_; }
  DstaTree* CastToDstaTree() { return this; }
  CLONE;
 private :
  Literal* symbol_;
};


class DstaExtractedExpressions : public AstNode {
 public :
  DstaExtractedExpressions() : AstNode(NAME_PARAMETER(DstaExtractedExpressions), 0) {};
  ~DstaExtractedExpressions(){}
  NodeList* refs() { return &refs_; }
  void set_refs(Literal* tmp_name_node) { refs_.AddChild(tmp_name_node); }
  CLONE;
 private :
  NodeList refs_;
};


inline void Statement::ResetDsta()  {
  flags_.UnSet(0);
  destructuring_node_->RemoveAllChild();
  destructuring_node_->refs()->RemoveAllChild();
}


}//namespace mocha

#undef NVI_ACCEPTOR_DECL
#undef CALL_ACCEPTOR
#undef NAME_PARAMETER

#endif //mocha_ast_h_
