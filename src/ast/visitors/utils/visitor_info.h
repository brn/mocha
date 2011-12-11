#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_
#include <stdint.h>
#include <list>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/class_traits/uncopyable.h>
#include <utils/xml/versions.h>
#include <ast/ast_foward_decl.h>

namespace mocha {
class Scope;
class Compiler;
class ClassProcessor;
typedef std::list<ClassProcessor*> ClassList;
class VisitorInfo : private Uncopyable{
 public :
  VisitorInfo( Scope* scope , Compiler *compiler ,
               DstaExtractedExpressions* dsta_exp , const char* main_file_path , const char* file_name );
  ~VisitorInfo(){};
  inline int GetTmpIndex() { int ret = tmp_index_;tmp_index_++;return ret; };
  inline const char* GetMainPath() { return main_file_path_; };
  inline const char* GetFileName() { return file_name_; };
  inline Scope* GetScope() { return scope_; };
  inline Compiler* GetCompiler() { return compiler_; };
  inline void SetDstaInjection( bool is ) { is_dst_injection_ = is; }
  inline bool IsDstaInjection() { return is_dst_injection_; }
  inline void SetRestInjection( bool is ) { is_rest_injection_ = is; }
  inline bool IsRestInjection() { return is_rest_injection_; }
  inline DstaExtractedExpressions* GetDstaExtr() { return dsta_exp_; }
  inline void SetRestExp( TokenInfo* info ) { rest_exp_ = info; }
  inline TokenInfo* GetRestExp() { return rest_exp_; }
  inline void SetCurrentStmt( Statement* stmt ) { current_stmt_ = stmt; }
  inline Statement* GetCurrentStmt() { return current_stmt_; }
  inline bool HasVersion( const char* ver ) {
    if ( version_ ) {
      return version_->Get( ver );
    }
    return false;
  }
  inline bool IsInModules() { return is_in_module_ > 1; }
  inline void EscapeModuel() { if ( is_in_module_ > 1 ){ is_in_module_ >>= 1; } }
  inline void EnterModuel() { is_in_module_ <<= 1; }
  inline void AddClass( ClassProcessor* proc ) { class_list_.push_back( proc ); }
  inline const ClassList& GetClassList() { return class_list_; }
 private :
  int tmp_index_;
  bool is_dst_injection_;
  bool is_rest_injection_;
  int64_t is_in_module_;
  const char* main_file_path_;
  const char* file_name_;
  Version* version_;
  DstaExtractedExpressions* dsta_exp_;
  TokenInfo* rest_exp_;
  Scope *scope_;
  Compiler *compiler_;
  Statement* current_stmt_;
  ClassList class_list_;
};
}

#endif
