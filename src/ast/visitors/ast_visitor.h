
#ifndef AstVisitor_h
#define AstVisitor_h

#include <string>
#include <useconfig.h>
#include <ast/visitors/ivisitor.h>
#include <utils/smart_pointer/scope/scoped_list.h>

namespace mocha{
  
class Scope;
class Codegen;
class AstState;
class ParserTracer;
class Compiler;

class AstVisitor : public IVisitor {
 public :
    
  AstVisitor ( Scope* scope,
               Compiler* compiler,
               const char* modulename,
               const char* filename );
  ~AstVisitor ();

#include <ast/visitors/visitor_decl.h>
  
 private:
  inline void GetTmpVar_( char* buf ) { sprintf( buf , "__tmp__%d" , tmp_index_ );tmp_index_++;  }
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
  void DstProcessor_( ValueNode* ast_node );
  void DstArrayProccessor_( ValueNode* ast_node , int depth );
  void DstObjectProcessor_( ValueNode* ast_node , int depth );
  void DstMemberProccessor_( ValueNode* ast_node );
  int tmp_index_;
  const char* symbol;
  const char* module_name_;
  const char* filename_;
  ScopedStrList char_handle_;
  Scope* scope_;
  Scope* global_;
  Compiler* compiler_;
  ParserTracer* tracer_;
};

}

#endif

