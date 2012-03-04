#ifndef mocha_external_resource_h_
#define mocha_external_resource_h_
#include <vector>
#include <string>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <utils/smart_pointer/ref_count/shared_ptr.h>
#include <utils/class_traits/static.h>
#include <utils/thread/thread.h>
namespace mocha {
namespace memory {
class Pool;
}
class CompileInfo;
class Resources {
 public :
  typedef std::vector<std::string> ModuleList;
  Resources();
  ~Resources();
  void SetInputCharset(const char* charset);
  const char* GetInputCharset();
  void SetOutputCharset(const char* charset);
  const char* GetOutputCharset();
  void SetDeploy(const char* name);
  const char* GetDeploy();
  void SetDeployName(const char* name);
  StrSharedPtr GetDeployName(const char* name);
  void SetModule(const char* path);
  const ModuleList& GetModuleList();
  CompileInfo* GetCompileInfo();
  StrSharedPtr GetCmpPath_(const char* path);
 private :
  std::string input_charset_;
  std::string output_charset_;
  std::string deploy_;
  std::string deployname_;
  ModuleList modulelist_;
  CompileInfo* info_;
};

class ExternalResource : private Static {
  typedef std::pair<const char*,SharedPtr<Resources> > ResourcePair;
  typedef roastlib::unordered_map<std::string, SharedPtr<Resources> > ResourceMap;
 public :
  static void UnsafeSet(const char* filename);
  static Resources* UnsafeGet(const char* filename);
  static void SafeSet(const char* filename);
  static Resources* SafeGet(const char* filename);
  static FileRoot* SafeGetRuntime(memory::Pool* pool);
 private :
  static Mutex mutex_;
  static ResourceMap resources_;
};

}

#endif
