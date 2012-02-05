#ifndef mocha_codegen_visitor_h_
#define mocha_codegen_visitor_h_

#include <string>
#include <vector>
#include <ast/ast_foward_decl.h>
#include <ast/visitors/ivisitor.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <options/options.h>
#include <ast/visitors/utils/codegenerator_utils.h>

namespace mocha {
class CodeWriter;
class NodeIterator;
class InnerScope;
class CompileInfo;
class CodegenVisitor : public IVisitor {
 public :
  CodegenVisitor( CompileInfo* info );
  CodegenVisitor( bool is_pretty_print , bool is_debug );
  ~CodegenVisitor(){};
#include <ast/visitors/visitor_decl.h>
  inline void Write( const char* code ) { stream_->Write( code ); }
  inline const char* GetCode() { return stream_->Get()->GetData(); }
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
  void PrototypeMemberProccessor( NodeIterator& iterator , AstNode* name_node , bool is_private );
  void StaticMemberProccessor( NodeIterator& iterator , AstNode* node );
  void BeginState_( int state );
  void EndLastState_();
  int CurrentState_();
  bool MatchState_( int state );

  int tmp_index_;
  int depth_;
  bool is_line_;
  bool has_rest_;
  std::vector<int> state_;
  std::string rest_ref_;
  std::string rest_name_;
  InnerScope* scope_;
  CodeBuffer default_buffer_;
  ScopedPtr<CodeStream> stream_;
  ScopedPtr<CodeWriter> writer_;
  FileRoot* current_root_;
  Class* current_class_;
};
}

#endif
