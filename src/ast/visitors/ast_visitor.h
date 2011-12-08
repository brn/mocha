
#ifndef AstVisitor_h
#define AstVisitor_h

#include <string>
#include <useconfig.h>
#include <ast/visitors/ivisitor.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>

namespace mocha{
  
class Scope;
class Compiler;
class VisitorInfo;
class DstaProcessor;

class AstVisitor : public IVisitor {
 public :
    
  AstVisitor ( Scope* scope,
               Compiler* compiler,
               const char* modulename,
               const char* filename );
  ~AstVisitor ();

#include <ast/visitors/visitor_decl.h>
  
 private:
  void ImportProccessor_( ImportStmt *node );
  void ForProccessor_( IterationStmt* iter );
  void ForInProccessor_( IterationStmt* iter );
  void DoWhileProccessor_( IterationStmt* iter );
  void WhileProccessor_( IterationStmt* iter );
  void VarListProcessor_( AstNode* ast_node );
  void JumpStmt_( AstNode* ast_node , int type );
  void ArrayAccessorProccessor_( CallExp* exp );
  void DotAccessorProccessor_( CallExp* exp );
  void NewCallProccessor_( CallExp* exp );
  void NormalFunctionCall_( CallExp* exp );
  void ArrayProccessor_( ValueNode* ast_node );
  void ObjectProccessor_( ValueNode* ast_node );
  void VarInitialiserProccessor_( ValueNode* ast_node );
  
  ScopedPtr<VisitorInfo> visitor_info_;
  ScopedPtr<DstaProcessor> dsta_proc_;
};

}

#endif

