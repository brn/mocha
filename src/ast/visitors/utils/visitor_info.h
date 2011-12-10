#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_
#include <utils/smart_pointer/scope/scoped_ptr.h>
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
  inline void SetRestInjection( bool is ) { is_rest_injection_ = is; }
  inline bool IsRestInjection() { return is_rest_injection_; }
  inline DstaExtractedExpressions* GetDstaExtr() { return dsta_exp_; }
  inline void* SetRestExp( TokenInfo* info ) { rest_exp_ = info; }
  inline TokenInfo* GetRestExp() { return rest_exp_; }
  inline void SetCurrentStmt( AstNode* stmt ) { current_stmt_ = stmt; }
  inline AstNode* GetCurrentStmt() { return current_stmt_; }
 private :
  int tmp_index_;
  bool is_dst_injection_;
  bool is_rest_injection_;
  const char* module_name_;
  const char* file_name_;
  DstaExtractedExpressions* dsta_exp_;
  TokenInfo* rest_exp_;
  Scope *scope_;
  Compiler *compiler_;
  Statement* current_stmt_;
};
}

#endif
