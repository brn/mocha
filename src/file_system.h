
#ifndef FileSystem_h
#define FileSystem_h
#include "useconfig.h"
#include "pwd.h"
#include "handle.h"
#include "file_watcher.h"

namespace mocha {

class PathInfo {
 public :
  PathInfo( const char* filepath , const char* dir , const char* raw_path ) :
      filepath_( filepath ), dir_( dir ), raw_path_( raw_path ){}
  inline const char* GetDirPath() { return dir_.Get(); }
  inline const char* GetFileName() { return filepath_.Get(); }
  inline const char* GetFileIdentifier() { return raw_path_.Get(); }
 private :
  ScopedStr filepath_;
  ScopedStr dir_;
  ScopedStr raw_path_;
};

class FileSystem {

 public :
  static StrHandle pwd ();
  static Handle<PathInfo> GetPathInfo( const char* path );
  static StrHandle NormalizePath( const char* path );
  static void Chdir ( const char* path );
  static bool Chmod( const char* pass , int permiss );
  static void SetModuleDir( const char* path );
  inline static const char* GetModuleDir(){ return module_dir_.c_str(); }
  static StrHandle GetUserHomeDir();
  static StrHandle GetAbsolutePath( const char* path );
  static bool Mkdir( const char* path , int permiss );
 private :
  static std::string module_dir_;
  static const char* GetDirectoryFromPath_( const char* path );
  static const char* GetFileNameFromPath_( const char* );
};

}

#endif

