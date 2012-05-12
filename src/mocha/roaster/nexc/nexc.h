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
#ifndef mocha_roaster_compiler_compiler_h_
#define mocha_roaster_compiler_compiler_h_
#include <vector>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
namespace os {namespace fs{
class Path;
class VirtualDirectory;
}}
class IOEvent;
class CompilationEvent;
class CompilationInfo;
class ErrorReporter;
class AstBuilder;
class AstRoot;
class AstNode;
class FileRoot;
class Nexc : public Notificator<CompilationEvent*>{
  typedef std::pair<std::string, bool> GuardPair;
  typedef roastlib::unordered_map<std::string, bool> ImportGuard;
  typedef std::pair<std::string, FileRoot*> AstPair;
  typedef roastlib::unordered_map<std::string, FileRoot*> AstList;
 public :
  typedef std::vector<std::string> Dependencies;
  typedef SharedPtr<Dependencies> DepsHandle;
  Nexc(CompilationInfo* info);
  ~Nexc(){};
  void CompileFile(const char* filename, const char* charset = NULL);
  void Compile(const char* source, const char* charset = NULL);
#ifdef PACKING_RUNTIME
  typedef std::vector<std::pair<const char*, AstRoot*> > Results;
  void SetResult(CompilationEvent* e);
  static void PackFile(const Results& results);
  void Pack(const char* filename, bool runtime);
#endif
  AstRoot* GetResult();
  const DepsHandle GetDepends() const;
  SharedPtr<ErrorReporter> Errors() {return reporter_;}
  void ImportFile(std::string* buf, std::string* filename_buf, const char* path, CompilationEvent* e);
  void IncludeFile(std::string* buf, const char* path, CompilationEvent* e);
  void set_current_directory(const char* path);
  FileRoot* ast(const char* name);
  static const char kScan[];
  static const char kParse[];
  static const char kTransformAst[];
  static const char kCompilationSucessed[];
  static const char kCompilationFailed[];
  static const char kFatal[];
  static const char kFail[];
 private :
  void Initialize();
  void AbortHandler(CompilationEvent* e);
  void FailHandler(CompilationEvent* e);
  bool CheckGuard(const char* path);
  void Success(CompilationEvent* e);
  void SearchModule(const char* path, std::string* buf);
  void CombineLibs(CompilationEvent* e);
  void AddRuntime(CompilationEvent* e);
  template <int type, const char* name>
  void AddEachRuntime(CompilationEvent* e, AstNode* root, memory::Pool* pool);
  CompilationEvent* CreateEvent(const os::fs::Path& path_info, const char* charset);
  AstRoot* root_;
  AtomicWord token_initialized_;
  CompilationInfo* compilation_info_;
  ImportGuard guard_;
  AstList ast_list_;
  DepsHandle deps_;
  SharedPtr<ErrorReporter> reporter_;
  SharedPtr<memory::Pool> pool_;
  ScopedPtr<os::fs::VirtualDirectory> virtual_directory_;
  ScopedPtr<AstBuilder> builder_;
};
}
#endif
