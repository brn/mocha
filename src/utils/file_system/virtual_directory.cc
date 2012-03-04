#include <string.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/file_system/file_system.h>

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
  StrSharedPtr handle = FileSystem::NormalizePath( path );
  current_dir_ = handle.Get();
}

StrSharedPtr VirtualDirectory::GetCurrentDir() {
  char* ret = new char[ ( current_dir_.size() + 1 ) ];
  strcpy( ret , current_dir_.c_str() );
  StrSharedPtr handle( ret );
  return handle;
}

StrSharedPtr VirtualDirectory::GetRealPath( const char* path ) {
  std::string tmp = current_dir_;
  tmp += '/';
  tmp += path;
  printf( "before process -> %s\n" , tmp.c_str() );
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
