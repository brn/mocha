#ifndef mocha_virtual_directory_h_
#define mocha_virtual_directory_h_

#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/thread/thread.h>

namespace mocha {namespace os {
namespace fs {
class VirtualDirectory {
 public :
  static VirtualDirectory* GetInstance();
  void set_current_directory(const char* path);
  const char* current_directory() const;
 private :
  inline VirtualDirectory(){};
  inline ~VirtualDirectory(){};
  static void Destructor(void* ptr);  
  std::string current_dir_;
  static ThreadLocalStorageKey local_key_;
  static Mutex mutex_;
};
}
}}
#endif
