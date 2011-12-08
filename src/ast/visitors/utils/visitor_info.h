#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_

#include <ast/ast_foward_decl.h>

namespace mocha {
class Scope;
class Compiler;
class VisitorInfo {
 public :
  VisitorInfo( Scope* scope , Compiler *compiler ,
               DstaExtractedExpressions* dsta_exp , const char* module_name , const char* file_name );
  ~VisitorInfo(){};
  inline int GetTmpIndex() { int ret = tmp_index_;tmp_index_++;return ret; };
  inline const char* GetModuleName() { return module_name_; };
  inline const char* GetFileName() { return file_name_; };
  inline Scope* GetScope() { return scope_; };
  inline Compiler* GetCompiler() { return compiler_; };
  inline void SetDstaInjection( bool is ) { is_dst_injection_ = is; }
  inline bool IsDstaInjection() { return is_dst_injection_; }
  inline DstaExtractedExpressions* GetDstaExtr() { return dsta_exp_; }
  inline void SetCurrentStmt( AstNode* stmt ) { current_stmt_ = stmt; }
  inline AstNode* GetCurrentStmt() { return current_stmt_; }
 private :
  int tmp_index_;
  bool is_dst_injection_;
  const char* module_name_;
  const char* file_name_;
  DstaExtractedExpressions* dsta_exp_;
  Scope *scope_;
  Compiler *compiler_;
  AstNode* current_stmt_;
};
}

#endif
