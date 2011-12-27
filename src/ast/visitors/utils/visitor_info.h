#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_
#include <utils/int_types.h>
#include <list>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/class_traits/uncopyable.h>
#include <utils/xml/versions.h>
#include <ast/ast_foward_decl.h>
#include <utils/bits.h>

namespace mocha {
class Scope;
class Compiler;
class ClassProcessor;
typedef std::list<ClassProcessor*> ClassList;
class VisitorInfo : private Uncopyable{
 public :
  VisitorInfo( bool is_runtime , Scope* scope , Compiler *compiler ,
               DstaExtractedExpressions* dsta_exp , const char* main_file_path , const char* file_name );
  ~VisitorInfo(){};
  inline int GetTmpIndex() { int ret = tmp_index_;tmp_index_++;return ret; };
  inline const char* GetMainPath() { return main_file_path_; };
  inline const char* GetFileName() { return file_name_; };
  inline Scope* GetScope() { return scope_; };
  inline Compiler* GetCompiler() { return compiler_; };
  inline void SetDstaInjection( bool is ) { ( is )? bit_vector_.Set( 0 ) : bit_vector_.UnSet( 0 ); }
  inline bool IsDstaInjection() { return bit_vector_[ 0 ]; }
  inline void SetRestInjection( bool is ) { ( is )? bit_vector_.Set( 1 ) : bit_vector_.UnSet( 1 ); }
  inline bool IsRestInjection() { return bit_vector_[ 1 ]; }
  inline DstaExtractedExpressions* GetDstaExtr() { return dsta_exp_; }
  inline void SetRestExp( TokenInfo* info ) { rest_exp_ = info; }
  inline TokenInfo* GetRestExp() { return rest_exp_; }
  inline void SetCurrentStmt( Statement* stmt ) { current_stmt_ = stmt; }
  inline Statement* GetCurrentStmt() { return current_stmt_; }
  inline bool IsRuntime() { return bit_vector_[ 2 ]; }
  inline bool HasVersion( const char* ver ) {
    if ( version_ ) {
      return version_->Get( ver );
    }
    return false;
  }
  inline bool IsInModules() { return is_in_module_ > 0; }
  inline void EscapeModuel() { is_in_module_--;}
  inline void EnterModuel() { is_in_module_++ ;}
  inline void EnterClass() { is_in_class_++; }
  inline void EscapeClass() { is_in_class_--; }
  inline bool IsInClass() { return is_in_class_ > 0; }
  inline bool IsInPrivate() { return bit_vector_[ 3 ]; }
  inline void EnterPrivate() { bit_vector_.Set( 3 ); }
  inline void EscapePrivate() { bit_vector_.UnSet( 3 ); }
  inline void AddClass( ClassProcessor* proc ) { class_list_.push_back( proc ); }
  inline void SetFunction( Function* fn ) { current_fn_ = fn; }
  inline Function* GetFunction() { return current_fn_; }
  inline const ClassList& GetClassList() { return class_list_; }
 private :
  int tmp_index_;
  int16_t is_in_class_;
  int16_t is_in_module_;
  const char* main_file_path_;
  const char* file_name_;
  BitVector8 bit_vector_;
  Version* version_;
  DstaExtractedExpressions* dsta_exp_;
  TokenInfo* rest_exp_;
  Scope *scope_;
  Compiler *compiler_;
  Statement* current_stmt_;
  Function* current_fn_;
  ClassList class_list_;
};
}

#endif
