#ifndef mocha_roaster_roaster_h_
#define mocha_roaster_roaster_h_
#include <vector>
#include <utility>
#include <mocha/roaster/misc/atomic.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/file_system/file_io.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/utils/compilation_result.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
namespace mocha {
typedef SharedPtr<CompilationInfo> CompilationInfoHandle;
typedef SharedPtr<CompilationResult> CompilationResultHandle;
typedef std::vector<CompilationResultHandle> CompilationResultList;
typedef SharedPtr<CompilationResultList> CompilationResultHandleList;
typedef std::vector<CompilationInfoHandle> CompilationInfoHandleList;
typedef SharedPtr<ExternalAst> AstReserver;
class AsyncCallback {
 public :
  AsyncCallback(){}
  virtual ~AsyncCallback(){}
  AsyncCallback(const AsyncCallback&){}
  virtual void operator()(CompilationResultHandle handle){}
};
typedef SharedPtr<AsyncCallback> AsyncCallbackHandle;
class Roaster {
 public :
  Roaster();
  ~Roaster(){}
  CompilationResultHandle CompileFile(CompilationInfoHandle);
  CompilationResultHandle Compile(CompilationInfoHandle);
  CompilationResultHandleList CompileFiles(CompilationInfoHandleList&);
  void CompileAsync(CompilationInfoHandle, bool, AsyncCallbackHandle);
  void CompileFileAsync(CompilationInfoHandle, bool, AsyncCallbackHandle);
  void CompileFilesAsync(CompilationInfoHandleList&, bool, AsyncCallbackHandle);
  AstReserver GetAstFromFile(CompilationInfoHandle);
  AstReserver GetAst(CompilationInfoHandle);
 private :
  static void Initialize();
  static AtomicWord entered_;
};
}

#endif
