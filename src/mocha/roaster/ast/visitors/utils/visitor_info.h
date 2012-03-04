#ifndef mocha_visitor_info_h_
#define mocha_visitor_info_h_
#include <string>
#include <list>
#include <utility>
#include <utils/int_types.h>
#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/tokens/token_info.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/class_traits/uncopyable.h>
#include <utils/xml/versions.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <utils/bits.h>

namespace mocha {
class ScopeRegistry;
class Scope;
class Compiler;
class ClassProcessor;
class AstBuilder;
typedef std::list<ClassProcessor*> ClassList;
class VisitorInfo : private Uncopyable{
 public :
  typedef std::pair<AstNode*, AstNode*> AstPair;
  typedef std::list<AstPair> PrivateNameList;
  VisitorInfo(bool is_runtime, ScopeRegistry* scope_registry, Compiler *compiler ,
               DstaExtractedExpressions* dsta_exp, const char* main_file_path, const char* file_name);
  ~VisitorInfo(){};
  int tmp_index() { int ret = tmp_index_;tmp_index_++;return ret; };
  const char* main_file_path() const { return main_file_path_; };
  const char* filename() const { return file_name_; };
  const char* relative_path() const { return relative_path_.c_str(); }
  ScopeRegistry* scope_registry() const { return scope_registry_; };
  Compiler* compiler() const { return compiler_; };
  void set_rest_expression(TokenInfo* info) { rest_exp_ = info; }
  TokenInfo* rest_expression() const { return rest_exp_; }
  void set_current_statement(Statement* stmt) { current_stmt_ = stmt; }
  Statement* current_statement() const { return current_stmt_; }

  void set_dsta_injection(bool is) { (is)? bit_vector_.Set(0) : bit_vector_.UnSet(0); }
  bool dsta_injection() { return bit_vector_[ 0 ]; }
  void set_rest_injection(bool is) { (is)? bit_vector_.Set(1) : bit_vector_.UnSet(1); }
  bool rest_injection() { return bit_vector_[ 1 ]; }

  bool runtime() const { return bit_vector_.At(2); }
  bool HasVersion(const char* ver) { return compile_info_->HasVersion(ver); }
  bool IsInModules() const { return is_in_module_ > 0; }
  void EscapeModuel() { is_in_module_--;}
  void EnterModuel() { is_in_module_++ ;}
  void EnterClass() { is_in_class_++; }
  void EscapeClass() { is_in_class_--; }
  bool IsInClass() const { return is_in_class_ > 0; }
  bool IsInPrivate() const { return bit_vector_[ 3 ]; }
  void EnterPrivate() { bit_vector_.Set(3); }
  void EscapePrivate() { bit_vector_.UnSet(3); }
  void AddClass(ClassProcessor* proc) { class_list_.push_back(proc); }
  void set_function(Function* fn) { current_fn_ = fn; }
  Function* function() const { return current_fn_; }
  void set_private_property_list(AstPair private_name) { private_names_.push_back(private_name); }
  PrivateNameList* private_property_list() { return &private_names_; }
  void EnterObject() { object_depth_++; }
  void EscapeObject() { object_depth_--; }
  bool IsInObject() const { return object_depth_ > 0; }
  const ClassList& GetClassList() { return class_list_; }
  void SetClass(ClassProcessor* proc) { current_class_ = proc; }
  ClassProcessor* GetClass() const { return current_class_; }
  AstBuilder* builder(){ return builder_; }
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
  AstBuilder* builder_;
};
}

#endif
