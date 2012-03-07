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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <boost/unordered_map.hpp>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/internal.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/runtime/runtime.h>
#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/utils/compilation_result.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/file_system/file_io.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/file_system/virtual_directory.h>
#include <mocha/roaster/file_system/stat.h>
#include <mocha/misc/xml/xml_reader.h>
#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/ast/visitors/symbol_collector.h>
#include <mocha/roaster/ast/visitors/optimizer_visitor.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/ast/builder/ast_builder.h>

///////////////////////////////////////////////////
// class Compiler::PtrImpl implementation begin. //
///////////////////////////////////////////////////
namespace mocha {

/**
 *@class
 *Implementation of pimpl idiom.
 */
class Compiler::PtrImpl {
  friend class Compiler;
 public :
  PtrImpl(Compiler* compiler, CompilationInfoHandle info_handle) :
      compiler_(compiler),compilation_info_(info_handle),
      pool_(memory::Pool::Local()), builder_(AstBuilder::Local()),
      scope_registry_(new ScopeRegistry(memory::Pool::Local())) {
    error_map_(new ErrorMap);
    if (compilation_info_->IsFile()) {
      path_(new filesystem::Path(compilation_info()->string()));
      SetPath(path_->absolute_path());
      main_file_path_ = path_->absolute_path();
    } else {
      main_file_path_ = "anonymous";
    }
    codegen_(new CodegenVisitor(main_file_path_.c_str(), info_handle.Get(), compiler));
  }

  ~PtrImpl(){}

  inline CompilationResultHandle Compile() {
    //Change direcotry to main js path.
    if (path_->HasAbsolutePath() && compilation_info()->IsFile()) {
      filesystem::VirtualDirectory::GetInstance()->Chdir(path_->directory());
    }
    ast_root_.AddChild(Compiler::runtime("runtime", pool_.Get()));
    CallInternal(main_file_path_.c_str(), Internal::kFatal, false);
    OptimizerVisitor opt_visitor(compilation_info_.Get());
    SymbolCollector visitor(scope_registry_.Get(), compilation_info_.Get()->Debug());
    ast_root_.Accept(&visitor);
    ast_root_.Accept(&opt_visitor);
    if (compilation_info_->Compress()) {
      scope_registry_->Rename();
    }
    ast_root_.Accept(codegen_.Get());
    return CompilationResultHandle(new CompilationResult(path_->absolute_path(), codegen_, error_map_));
  }

  inline SharedPtr<filesystem::Path> Load(const char* filename) {
    bool is_runtime = false;
    //Create javascript path from filename.
    //It's like this,
    //"./example" -> "<current absolute path>/example.js" or
    //"exampleModule" -> "<setted absolute module dir path> or <default absolute module path>/exampleModule.js"
    SharedPtr<filesystem::Path> js_path = CompilerUtils::CreateJsPath(filename, main_file_path_.c_str(), compilation_info()->lib_directories(), &is_runtime);
    //Check is module already loaded or not.
    if (IsAlreadyLoaded_(js_path->absolute_path())) {
      //Set loaded file to hash.
      SetPath(js_path->absolute_path());
      if(is_runtime) {
        ast_root_.AddChild(Compiler::runtime(js_path->filename(), pool_.Get()));
        return js_path;
      }
      //Change current directory to loaded js file directory.
      SharedPtr<filesystem::Path> path_handle = CompilerUtils::ChangeDir(js_path->absolute_path());
      CallInternal(path_handle->absolute_path(), Internal::kNofatal, false);
    }
    return js_path;
  }


  inline AstReserver GetAst() {
    return ReserveAst(false);
  }

  const CompilationInfo* compilation_info() const { return compilation_info_.Get(); }
  const char* mainfile_path() const { return main_file_path_.c_str(); }
  const filesystem::Path* path() const { return path_.Get(); }
 private :
  /**
   *@private
   *@param {const char*} -> Path of loaded file.
   *@return {bool} -> Path was already loaded or not.
   *Check duplicate entry.
   *If loaded file is already loaded, return false.
   */
  inline bool IsAlreadyLoaded_(const char* path) { return loaded_path_.find(path) == loaded_path_.end(); }

  /**
   *@private
   *@param {const char*} -> Path of loaded file.
   *Set loaded file to duplicate entry.
   */
  inline void SetPath(const char* path) { loaded_path_.insert(std::pair<const char*, int>(path, 1)); }

  inline void CallInternal(const char* path, Internal::ErrorLevel error_level, bool is_runtime) {
    Internal internal(path, compiler_, codegen_.Get(), scope_registry_.Get(), is_runtime ,&ast_root_, pool_.Get());
    internal.Parse(error_level);
  }

  inline AstReserver ReserveAst(bool is_runtime) {
    AstReserver external_ast = ExternalAst::Create();
    AstRoot root;
    std::string str;
    if (compilation_info_->IsFile()) {
      str = path()->absolute_path();
    } else {
      str = compilation_info_->string();
    }
    Internal internal(str.c_str(), compiler_, codegen_.Get(), scope_registry_.Get(), is_runtime, &root, pool_.Get());
    internal.GetAst(Internal::kFatal);
    external_ast->GetRoot()->AddChild(root.first_child()->Clone(external_ast->pool()));
    return external_ast;
  }

  inline void BuildRuntime(const char* name, bool is_main_runtime) {
    typedef std::pair<const char*,AstReserver> RuntimeAstPair;
    AstReserver reserver = ReserveAst(is_main_runtime);
    compiler_->runtime_map_.insert(RuntimeAstPair(name, reserver));
  }

  inline int LoadedFileCount() const {
    return loaded_path_.size();
  }

  std::string main_file_path_;
  ErrorMapHandle error_map_;
  roastlib::unordered_map<std::string,int> loaded_path_;
  Compiler *compiler_;
  AstRoot ast_root_;
  CompilationInfoHandle compilation_info_;
  ScopedPtr<memory::Pool> pool_;
  ScopedPtr<AstBuilder> builder_;
  ScopedPtr<ScopeRegistry> scope_registry_;
  SharedPtr<CodegenVisitor> codegen_;
  ScopedPtr<filesystem::Path> path_;
  static Mutex mutex_;
};

Mutex Compiler::PtrImpl::mutex_;


//////////////////////////////////////////
// class Compiler implementation begin. //
//////////////////////////////////////////

Compiler::Compiler (CompilationInfoHandle info_handle)
    : implementation_ (new PtrImpl(this, info_handle)) {
}

Compiler::~Compiler(){}
CompilationResultHandle Compiler::Compile () {
  return implementation_->Compile();
}

void Compiler::CatchException(const char* filename, ErrorHandler handler) {
  implementation_->error_map_->insert(ErrorHandlerPair(filename, handler));
}

AstReserver Compiler::GetAst() {
  return implementation_->GetAst();
}

SharedPtr<filesystem::Path> Compiler::Load (const char* filename) {
  return implementation_->Load(filename);
}
int Compiler::LoadedFileCount() const { return implementation_->LoadedFileCount(); }
const CompilationInfo* Compiler::compilation_info() const { return implementation_->compilation_info(); }
const char* Compiler::mainfile_path() const { return implementation_->mainfile_path(); }
const filesystem::Path* Compiler::path() const { return implementation_->path(); }
void Compiler::BuildRuntime() {
  MutexLock lock(mutex_);
  runtime::Runtime::BuildSource();
  const runtime::Runtime::RuntimeMap& map = runtime::Runtime::runtime_map();
  runtime::Runtime::RuntimeMap::const_iterator it = map.begin();
  for (;it != map.end();++it) {
    CompilationInfoHandle handle(new CompilationInfo(it->second));
    Compiler compiler(handle);
    bool is_main = false;
    if (strcmp(it->first.c_str(), "runtime") == 0) {
      is_main = true;
    }
    compiler.implementation_->BuildRuntime(it->first.c_str(), is_main);
  }
}

AstNode* Compiler::runtime(const char* name, memory::Pool* pool) {
  RuntimeAstMap::iterator it = runtime_map_.find(name);
  if (it != runtime_map_.end()) {
    return it->second->GetRoot()->first_child()->Clone(pool);
  }
  return 0;
}

bool Compiler::IsRuntime(const char* name) {
  MutexLock lock(mutex_);
  return runtime_map_.find(name) != runtime_map_.end();
}
Mutex Compiler::mutex_;
Compiler::RuntimeAstMap Compiler::runtime_map_;
} //namespace mocha
