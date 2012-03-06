#ifndef mocha_virtual_directory_h_
#define mocha_virtual_directory_h_

#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/thread/thread.h>

namespace mocha {
namespace filesystem {
class VirtualDirectory {
 public :
  static VirtualDirectory* GetInstance();
  void Chdir( const char* path );
  SharedStr GetCurrentDir();
  SharedStr GetRealPath( const char* path );
  void SetModuleKey( const char* path );
  const char* GetModuleKey();
 private :
  inline VirtualDirectory(){};
  inline ~VirtualDirectory(){};
  static void Destructor_( void* ptr );
  
  std::string current_dir_;
  std::string module_key_;
  static ThreadLocalStorageKey local_key_;
  static Mutex mutex_;
};
}
}
#endif
