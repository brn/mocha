#ifndef mocha_codegen_visitor_h_
#define mocha_codegen_visitor_h_

#include <string>
#include <vector>
#include "ast_foward_decl.h"
#include "scoped_ptr.h"
#include "ivisitor.h"
#include "options.h"

namespace mocha {
class CodeWriter;
class CodegenVisitor : public IVisitor {
 public :
  CodegenVisitor( Options* option );
  ~CodegenVisitor(){};
#include "visitor_decl.h"
  inline void Write( const char* code ) { buffer_ += code; }
  inline const char* GetCode() { return buffer_.c_str(); }
 private :
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
  void CreateDstAssignment_( const char* name );
  void BeginState_( int state );
  void EndLastState_();
  int CurrentState_();
  bool MatchState_( int state );

  int tmp_index_;
  bool is_line_;
  std::vector<int> state_;
  std::vector<std::string> dst_code_;
  std::vector<std::string> dst_accessor_;
  std::string buffer_;
  std::string tmp_ref_;
  ScopedPtr<CodeWriter> writer_;
  FileRoot* current_root_;
};
}

#endif
