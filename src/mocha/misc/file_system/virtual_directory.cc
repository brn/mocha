#include <string.h>
#include <mocha/misc/file_system/virtual_directory.h>
#include <mocha/misc/file_system/file_system.h>

namespace mocha {

VirtualDirectory* VirtualDirectory::GetInstance() {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>( ThreadLocalStorage::Get( &local_key_ ) );
  if ( instance == NULL ) {
    instance = new VirtualDirectory;
    ThreadLocalStorage::Set( &local_key_ , instance );
  }
  return instance;
}

void VirtualDirectory::Chdir( const char* path ) {
  SharedStr handle = FileSystem::NormalizePath( path );
  current_dir_ = handle.Get();
}

SharedStr VirtualDirectory::GetCurrentDir() {
  char* ret = new char[ ( current_dir_.size() + 1 ) ];
  strcpy( ret , current_dir_.c_str() );
  SharedStr handle( ret );
  return handle;
}

SharedStr VirtualDirectory::GetRealPath( const char* path ) {
  std::string tmp = current_dir_;
  tmp += '/';
  tmp += path;
  return FileSystem::NormalizePath( tmp.c_str() );
}

void VirtualDirectory::SetModuleKey( const char* path ) {
  module_key_ = path;
}

const char* VirtualDirectory::GetModuleKey() {
  return module_key_.c_str();
}

void VirtualDirectory::Destructor_( void* ptr ) {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>( ptr );
  delete instance;
}

ThreadLocalStorageKey VirtualDirectory::local_key_( VirtualDirectory::Destructor_ );
Mutex VirtualDirectory::mutex_;

}
