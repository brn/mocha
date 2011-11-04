#include <string.h>
#include "virtual_directory.h"
#include "file_system.h"

namespace mocha {

VirtualDirectory* VirtualDirectory::GetInstance() {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>( ThreadLocalStorage::Get( &local_key_ ) );
  if ( instance == NULL ) {
    MutexLock lock( mutex_ );
    instance = new VirtualDirectory;
    ThreadLocalStorage::Set( &local_key_ , instance );
    lock.Unlock();
  }
  return instance;
}

void VirtualDirectory::Chdir( const char* path ) {
  StrHandle handle = FileSystem::NormalizePath( path );
  current_dir_ = handle.get();
}

StrHandle VirtualDirectory::GetCurrentDir() {
  char* ret = new char[ ( current_dir_.size() + 1 ) ];
  strcpy( ret , current_dir_.c_str() );
  StrHandle handle( ret );
  return handle;
}

StrHandle VirtualDirectory::GetRealPath( const char* path ) {
  std::string tmp = current_dir_;
  tmp += '/';
  tmp += path;
  printf( "before process -> %s\n" , tmp.c_str() );
  return FileSystem::NormalizePath( tmp.c_str() );
}

void VirtualDirectory::Destructor_( void* ptr ) {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>( ptr );
  delete instance;
}

ThreadLocalStorageKey VirtualDirectory::local_key_( VirtualDirectory::Destructor_ );
Mutex VirtualDirectory::mutex_;

}
