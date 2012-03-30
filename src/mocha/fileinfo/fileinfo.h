#ifndef mocha_external_resource_h_
#define mocha_external_resource_h_
#include <vector>
#include <string>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/platform/thread/thread.h>
namespace mocha {
namespace memory {
class Pool;
}
class CompilationInfo;
typedef SharedPtr<CompilationInfo> CompilationInfoHandle;
class FileInfo {
 public :
  typedef std::vector<std::string> ModuleList;
  FileInfo(const char* fileanme);
  ~FileInfo();
  void SetInputCharset(const char* charset);
  const char* GetInputCharset() const;
  void SetOutputCharset(const char* charset);
  const char* GetOutputCharset() const;
  void SetDeploy(const char* name);
  const char* GetDeploy() const;
  void SetDeployName(const char* name);
  const char* GetDeployName() const;
  void SetModule(const char* path);
  const ModuleList& GetModuleList() const;
  SharedPtr<CompilationInfo> compilation_info();
 private :
  std::string input_charset_;
  std::string output_charset_;
  std::string deploy_;
  std::string deployname_;
  ModuleList modulelist_;
  SharedPtr<CompilationInfo> info_;
};

class FileInfoMap : private Static {
  typedef std::pair<const char*,SharedPtr<FileInfo> > FileInfoPair;
  typedef roastlib::unordered_map<std::string, SharedPtr<FileInfo> > FileInfoHandleMap;
 public :
  static void UnsafeSet(const char* filename);
  static FileInfo* UnsafeGet(const char* filename);
  static void SafeSet(const char* filename);
  static FileInfo* SafeGet(const char* filename);
  static void UnsafeRemove(const char* filename);
  static void SafeRemove(const char* filename);
  static void Reset();
 private :
  static os::Mutex mutex_;
  static FileInfoHandleMap resources_;
};

}

#endif
