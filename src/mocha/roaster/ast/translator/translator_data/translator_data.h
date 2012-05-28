/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_ast_visitors_visitor_info_h_
#define mocha_ast_visitors_visitor_info_h_
#include <string>
#include <list>
#include <vector>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
namespace mocha {
class CompilationEvent;
class ClassProcessor;
class AstBuilder;
class CompilationInfo;
typedef std::list<ClassProcessor*> ClassList;
typedef std::vector<ModuleStmt*> ModuleList;
class TranslatorData : private Uncopyable {
 public :
  typedef std::pair<AstNode*, AstNode*> AstPair;
  typedef std::list<AstPair> PrivateNameList;
  TranslatorData(bool is_runtime, CompilationEvent* e, DstaExtractedExpressions* dsta_exp);
  ~TranslatorData(){};
  int tmp_index() { int ret = tmp_index_;tmp_index_++;return ret; };
  const char* main_file_path() const { return event_->mainfile_path(); };
  const char* filename() const { return event_->filename(); };
  const char* relative_path() const { return relative_path_.c_str(); }
  CompilationEvent* compilation_event() const { return event_; };
  void set_rest_expression(TokenInfo* info) { rest_exp_ = info; }
  TokenInfo* rest_expression() const { return rest_exp_; }
  void set_current_statement(Statement* stmt) { current_stmt_ = stmt; }
  Statement* current_statement() const { return current_stmt_; }
  CompilationInfo* compilation_info() {return event_->compilation_info();}
  void set_dsta_injection(bool is) { (is)? bit_vector_.Set(0) : bit_vector_.UnSet(0); }
  bool dsta_injection() { return bit_vector_[ 0 ]; }
  void set_rest_injection(bool is) { (is)? bit_vector_.Set(1) : bit_vector_.UnSet(1); }
  bool rest_injection() { return bit_vector_[ 1 ]; }
  bool runtime() const { return bit_vector_.At(2); }
  bool IsInModules() const { return modules_.size() > 0; }
  void EscapeModule() {
    modules_.pop_back();
  }
  void EnterModule(ModuleStmt* stmt) {
    modules_.push_back(stmt);
  }
  ModuleList* modules() {return &modules_;}
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
  FileRoot* file_root() {return file_root_;}
  void set_root(FileRoot* root) {file_root_ = root;}
 private :
  
  int tmp_index_;
  int object_depth_;
  int16_t is_in_class_;
  int16_t is_in_module_;
  std::string relative_path_;
  ModuleList modules_;
  PrivateNameList private_names_;
  BitVector8 bit_vector_;
  DstaExtractedExpressions* dsta_exp_;
  TokenInfo* rest_exp_;
  CompilationEvent* event_;
  Statement* current_stmt_;
  Function* current_fn_;
  FileRoot* file_root_;
  ClassProcessor* current_class_;
  ClassList class_list_;
  AstBuilder* builder_;
};
}

#endif
