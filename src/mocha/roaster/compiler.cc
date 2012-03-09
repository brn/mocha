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
#include <sstream>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/internal.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/runtime/runtime.h>
#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/utils/compilation_result.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/platform/fs/stat.h>
#include <mocha/xml/xml_reader.h>
#include <mocha/xml/xml_setting_info.h>
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
typedef roastlib::unordered_map<std::string,std::string> ModuleMap;
typedef std::pair<const char*,const char*> ModuleKV;

/**
 *@class
 *Implementation of pimpl idiom.
 */
class Compiler::PtrImpl {
 public :

  PtrImpl(CompilationInfoHandle info_handle)
      : module_key_(new ModuleMap),
        compilation_info_(info_handle),
        pool_(memory::Pool::Local()),
        builder_(AstBuilder::Local()),
        scope_registry_(new ScopeRegistry(memory::Pool::Local())),
        error_map_(new ErrorMap){}

  ~PtrImpl(){}

  inline void Initialize(Compiler* compiler) {
    compiler_ = compiler;
    if (compilation_info_->IsFile()) {
      path_(new platform::fs::Path(compilation_info()->string()));
      SetPath(path_->absolute_path());
      main_file_path_ = path_->absolute_path();
    } else {
      main_file_path_ = "anonymous";
    }
    codegen_(new CodegenVisitor(main_file_path_.c_str(), compilation_info_.Get(), compiler));
  }

  inline CompilationResultHandle Compile() {
    //Change direcotry to main js path.
    if (path_->HasAbsolutePath() && compilation_info()->IsFile()) {
      platform::fs::VirtualDirectory::GetInstance()->Chdir(path_->directory());
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

  inline SharedPtr<platform::fs::Path> Load(const char* filename, bool* is_runtime_module) {
    bool is_runtime = false;
    //Create javascript path from filename.
    //It's like this,
    //"./example" -> "<current absolute path>/example.js" or
    //"exampleModule" -> "<setted absolute module dir path> or <default absolute module path>/exampleModule.js"
    SharedPtr<platform::fs::Path> js_path = CompilerUtils::CreateJsPath(filename, main_file_path_.c_str(), compilation_info()->lib_directories(), &is_runtime);
    //Check is module already loaded or not.
    if (IsAlreadyLoaded_(js_path->absolute_path())) {
      //Set loaded file to hash.
      SetPath(js_path->absolute_path());
      if(is_runtime) {
        ast_root_.AddChild(Compiler::runtime(filename, pool_.Get()));
        (*is_runtime_module) = true;
        return js_path;
      }
      //Change current directory to loaded js file directory.
      SharedPtr<platform::fs::Path> path_handle = CompilerUtils::ChangeDir(js_path->absolute_path());
      CallInternal(path_handle->absolute_path(), Internal::kNofatal, false);
    }
    return js_path;
  }


  inline AstReserver GetAst() {
    return ReserveAst(false);
  }

  const CompilationInfo* compilation_info() const {
    return compilation_info_.Get();
  }

  const char* mainfile_path() const {
    return main_file_path_.c_str();
  }

  const platform::fs::Path* path() const {
    return path_.Get();
  }
  
  inline void BuildRuntime(const char* name, bool is_main_runtime) {
    typedef std::pair<const char*,AstReserver> RuntimeAstPair;
    AstReserver reserver = ReserveAst(is_main_runtime);
    compiler_->runtime_map_.insert(RuntimeAstPair(name, reserver));
  }

  const ErrorMap* error_map() const {
    return error_map_.Get();
  }

  void set_error(const char* filename, ErrorHandler handler) {
    error_map_->insert(ErrorHandlerPair(filename, handler));
  }

  inline std::string ModuleKey(const char* path) const {
    ModuleMap::const_iterator it = module_key_->find(path);
    if (it == module_key_->end()) {
      if (Compiler::IsRuntime(path)) {
        std::string ret(path);
		ret += ";0";
		return ret;
      }
      return std::string("anonymous");
    } else {
      return it->second;
    }
  }

  inline void SetModuleKey(const char* name) {
    std::stringstream st;
    if (!(Compiler::IsRuntime(name))) {
      platform::fs::Path path(name);
      st << path.filename();
    } else {
      st << name;
    }
    st << ';' << loaded_path_.size();
    std::string value = st.str();
    module_key_->insert(ModuleKV(name, value.c_str()));
  }
  
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

  std::string main_file_path_;
  ErrorMapHandle error_map_;
  roastlib::unordered_map<std::string,int> loaded_path_;
  ScopedPtr<ModuleMap> module_key_;
  Compiler *compiler_;
  AstRoot ast_root_;
  CompilationInfoHandle compilation_info_;
  ScopedPtr<memory::Pool> pool_;
  ScopedPtr<AstBuilder> builder_;
  ScopedPtr<ScopeRegistry> scope_registry_;
  SharedPtr<CodegenVisitor> codegen_;
  ScopedPtr<platform::fs::Path> path_;
};


//////////////////////////////////////////
// class Compiler implementation begin. //
//////////////////////////////////////////

Compiler::Compiler(CompilationInfoHandle info_handle) : implementation_(new PtrImpl(info_handle)) {
  implementation_->Initialize(this);
}

Compiler::~Compiler(){}
CompilationResultHandle Compiler::Compile () {
  return implementation_->Compile();
}

void Compiler::CatchException(const char* filename, ErrorHandler handler) {
  implementation_->set_error(filename, handler);
}

AstReserver Compiler::GetAst() {
  return implementation_->GetAst();
}

SharedPtr<platform::fs::Path> Compiler::Load (const char* filename, bool* is_runtime_module) {
  return implementation_->Load(filename, is_runtime_module);
}

std::string Compiler::ModuleKey(const char* path) const {
  return implementation_->ModuleKey(path);
}

const CompilationInfo* Compiler::compilation_info() const {
  return implementation_->compilation_info();
}

const char* Compiler::mainfile_path() const {
  return implementation_->mainfile_path();
}

const platform::fs::Path* Compiler::path() const {
  return implementation_->path();
}

void Compiler::BuildRuntime() {
  platform::ScopedLock lock(mutex_);
  runtime::Runtime::BuildSource();
  const runtime::Runtime::RuntimeMap& map = runtime::Runtime::runtime_map();
  runtime::Runtime::RuntimeMap::const_iterator it = map.begin();
  for (;it != map.end();++it) {
    const char* name = it->first.c_str();
    CompilationInfoHandle handle(new CompilationInfo(it->second));
    handle->set_optional_identifier(name);
    Compiler compiler(handle);
    bool is_main = false;
    if (strcmp(name, "runtime") == 0) {
      is_main = true;
    }
    compiler.implementation_->BuildRuntime(name, is_main);
  }
}

void Compiler::SetModuleKey(const char* name) {
  implementation_->SetModuleKey(name);
}

AstNode* Compiler::runtime(const char* name, memory::Pool* pool) {
  RuntimeAstMap::iterator it = runtime_map_.find(name);
  if (it != runtime_map_.end()) {
    AstReserver reserver = it->second;
    return reserver->GetRoot()->first_child()->Clone(pool);
  }
  return 0;
}

bool Compiler::IsRuntime (const char* name) {
  RuntimeAstMap::iterator it = runtime_map_.find(name);
  return it != runtime_map_.end();
}
platform::Mutex Compiler::mutex_;
Compiler::RuntimeAstMap Compiler::runtime_map_;
} //namespace mocha
