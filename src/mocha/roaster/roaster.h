#ifndef mocha_roaster_roaster_h_
#define mocha_roaster_roaster_h_
#include <vector>
#include <utility>
#include <mocha/roaster/misc/io/file_io.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/utils/compile_result.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/lib/function.h>
namespace mocha {
typedef SharedPtr<CompilationInfo> CompilationInfoHandle;
typedef SharedPtr<CompilationResult> CompilationResultHandle;
typedef roastlib::function<void (CompilationResultHandle)> AsyncCallback;
typedef std::vector<CompilationInfoHandle> CompilationInfoHandleList;
typedef SharedPtr<ExternalAst> AstReserver;
class Roaster {
 public :
  static void Initialize();
  Roaster();
  ~Roaster(){}
  void CompileFile(CompilationInfoHandle);
  const char* Compile(CompilationInfoHandle);
  void CompileFiles(CompilationInfoHandleList&);
  void CompileAsync(CompilationInfoHandle, bool, AsyncCallback);
  void CompileFileAsync(CompilationInfoHandle, bool, AsyncCallback);
  void CompileFilesAsync(CompilationInfoHandleList&, bool, AsyncCallback);
  AstReserver GetAstFromFile(CompilationInfoHandle);
  AstReserver GetAst(CompilationInfoHandle);
};
}

#endif
