#ifndef mocha_virtual_directory_h_
#define mocha_virtual_directory_h_

#include <string>
#include "handle.h"
#include "thread.h"

namespace mocha {
class VirtualDirectory {
 public :
  static VirtualDirectory* GetInstance();
  void Chdir( const char* path );
  StrHandle GetCurrentDir();
  StrHandle GetRealPath( const char* path );
 private :
  inline VirtualDirectory(){};
  inline ~VirtualDirectory(){};
  static void Destructor_( void* ptr );
  
  std::string current_dir_;
  static ThreadLocalStorageKey local_key_;
  static Mutex mutex_;
};
}

#endif
