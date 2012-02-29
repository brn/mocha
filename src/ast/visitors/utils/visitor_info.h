#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_
#include <string>
#include <list>
#include <utility>
#include <utils/int_types.h>
#include <compiler/utils/compile_info.h>
#include <compiler/tokens/token_info.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/class_traits/uncopyable.h>
#include <utils/xml/versions.h>
#include <ast/ast_foward_decl.h>
#include <utils/bits.h>

namespace mocha {
class ScopeRegistry;
class Compiler;
class ClassProcessor;
typedef std::list<ClassProcessor*> ClassList;
class VisitorInfo : private Uncopyable{
 public :
  typedef std::pair<AstNode* , AstNode*> AstPair;
  typedef std::list<AstPair> PrivateNameList;
  VisitorInfo( bool is_runtime , ScopeRegistry* scope_registry , Compiler *compiler ,
               DstaExtractedExpressions* dsta_exp , const char* main_file_path , const char* file_name );
  ~VisitorInfo(){};
  inline int tmp_index() { int ret = tmp_index_;tmp_index_++;return ret; };
  inline const char* main_file_path() const { return main_file_path_; };
  inline const char* filename() const { return file_name_; };
  inline const char* relative_path() const { return relative_path_.c_str(); }
  inline ScopeRegistry* scope_registry() const { return scope_registry_; };
  inline Compiler* compiler() const { return compiler_; };
  inline void set_rest_expression( TokenInfo* info ) { rest_exp_ = info; }
  inline TokenInfo* rest_expression() const { return rest_exp_; }
  inline void set_current_statement( Statement* stmt ) { current_stmt_ = stmt; }
  inline Statement* current_statement() const { return current_stmt_; }

  inline void set_dsta_injection( bool is ) { ( is )? bit_vector_.Set( 0 ) : bit_vector_.UnSet( 0 ); }
  inline bool dsta_injection() { return bit_vector_[ 0 ]; }
  inline void set_rest_injection( bool is ) { ( is )? bit_vector_.Set( 1 ) : bit_vector_.UnSet( 1 ); }
  inline bool rest_injection() { return bit_vector_[ 1 ]; }
  
  inline bool runtime() const { return bit_vector_[ 2 ]; }
  inline bool HasVersion( const char* ver ) { return compile_info_->HasVersion( ver ); }
  inline bool IsInModules() const { return is_in_module_ > 0; }
  inline void EscapeModuel() { is_in_module_--;}
  inline void EnterModuel() { is_in_module_++ ;}
  inline void EnterClass() { is_in_class_++; }
  inline void EscapeClass() { is_in_class_--; }
  inline bool IsInClass() const { return is_in_class_ > 0; }
  inline bool IsInPrivate() const { return bit_vector_[ 3 ]; }
  inline void EnterPrivate() { bit_vector_.Set( 3 ); }
  inline void EscapePrivate() { bit_vector_.UnSet( 3 ); }
  inline void AddClass( ClassProcessor* proc ) { class_list_.push_back( proc ); }
  inline void set_function( Function* fn ) { current_fn_ = fn; }
  inline Function* function() const { return current_fn_; }
  inline void set_private_property_list( AstPair private_name ) { private_names_.push_back( private_name ); }
  inline const PrivateNameList& private_property_list() const { return private_names_; }
  inline void EnterObject() { object_depth_++; }
  inline void EscapeObject() { object_depth_--; }
  inline bool IsInObject() const { return object_depth_ > 0; }
  inline const ClassList& GetClassList() { return class_list_; }
  inline void SetClass( ClassProcessor* proc ) { current_class_ = proc; }
  inline ClassProcessor* GetClass() const { return current_class_; }
 private :
  int tmp_index_;
  int object_depth_;
  int16_t is_in_class_;
  int16_t is_in_module_;
  const char* main_file_path_;
  const char* file_name_;
  std::string relative_path_;
  PrivateNameList private_names_;
  BitVector8 bit_vector_;
  CompileInfo* compile_info_;
  DstaExtractedExpressions* dsta_exp_;
  TokenInfo* rest_exp_;
  ScopeRegistry *scope_registry_;
  Compiler *compiler_;
  Statement* current_stmt_;
  Function* current_fn_;
  ClassProcessor* current_class_;
  ClassList class_list_;
};
}

#endif
