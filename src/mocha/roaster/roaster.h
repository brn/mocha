#ifndef mocha_roaster_roaster_h_
#define mocha_roaster_roaster_h_
#include <vector>
#include <utility>
#include <mocha/roaster/smart_pointer/shared_ptr.h>
#include <mocha/roaster/lib/function.h>
namespace mocha {
class Resource;
class ExternalAst;
class CompilationInfo;
class CompilationResult;
typedef SharedPtr<CompilationInfo> CompilationInfoHandle;
typedef SharedPtr<CompilationResult> CompilationResultHandle;
typedef roastlib::function<void (CompilationResultHandle)> AsyncCallback;
typedef std::vector<CompilationInfoHandle> CompilationInfoHandleList;
typedef SharedPtr<ExternalAst> AstReserver;
class Roaster {
 public :
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
