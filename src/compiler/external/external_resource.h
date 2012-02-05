#ifndef mocha_external_resource_h_
#define mocha_external_resource_h_
#include <vector>
#include <string>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/hash/hash_map/hash_map.h>
#include <utils/class_traits/static.h>
#include <utils/thread/thread.h>
namespace mocha {
class CompileInfo;
class Resources {
 public :
  typedef std::vector<std::string> ModuleList;
  Resources();
  ~Resources();
  void SetInputCharset( const char* charset );
  const char* GetInputCharset();
  void SetOutputCharset( const char* charset );
  const char* GetOutputCharset();
  void SetDeploy( const char* name );
  const char* GetDeploy();
  void SetDeployName( const char* name );
  StrHandle GetDeployName( const char* name );
  void SetModule( const char* path );
  const ModuleList& GetModuleList();
  CompileInfo* GetCompileInfo();
  StrHandle GetCmpPath_( const char* path );
 private :
  std::string input_charset_;
  std::string output_charset_;
  std::string deploy_;
  std::string deployname_;
  ModuleList modulelist_;
  CompileInfo* info_;
};

class ExternalResource : private Static {
  typedef HashMap<const char*, Handle<Resources> > ResourceMap;
 public :
  static void UnsafeSet( const char* filename );
  static Resources* UnsafeGet( const char* filename );
  static void SafeSet( const char* filename );
  static Resources* SafeGet( const char* filename );
 private :
  static Mutex mutex_;
  static ResourceMap resources_;
};

}

#endif
