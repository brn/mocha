#ifndef mocha_external_resource_h_
#define mocha_external_resource_h_
#include <vector>
#include <string>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/misc/thread/thread.h>
namespace mocha {
namespace memory {
class Pool;
}
class CompilationInfo;
class Resource {
 public :
  typedef std::vector<std::string> ModuleList;
  Resource(const char* fileanme);
  ~Resource();
  void SetInputCharset(const char* charset);
  const char* GetInputCharset();
  void SetOutputCharset(const char* charset);
  const char* GetOutputCharset();
  void SetDeploy(const char* name);
  const char* GetDeploy();
  void SetDeployName(const char* name);
  SharedStr GetDeployName(const char* name);
  void SetModule(const char* path);
  const ModuleList& GetModuleList();
  CompilationInfo* GetCompilationInfo();
  SharedStr GetCmpPath_(const char* path);
  bool IsFile() const;
  void set_file();
  CompilationInfoHandle compilation_info();
 private :
  bool is_file_;
  std::string input_charset_;
  std::string output_charset_;
  std::string deploy_;
  std::string deployname_;
  ModuleList modulelist_;
  CompilationInfoHandle info_;
};

class ExternalResource : private Static {
  typedef std::pair<const char*,SharedPtr<Resource> > ResourcePair;
  typedef roastlib::unordered_map<std::string, SharedPtr<Resource> > ResourceMap;
 public :
  static void UnsafeSet(const char* filename);
  static Resource* UnsafeGet(const char* filename);
  static void SafeSet(const char* filename);
  static Resource* SafeGet(const char* filename);
  static FileRoot* SafeGetRuntime(memory::Pool* pool);
 private :
  static Mutex mutex_;
  static ResourceMap resources_;
};

}

#endif
