
#ifndef mocha_file_system_h_
#define mocha_file_system_h_
#include <useconfig.h>
#include <utils/file_system/pwd.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/file_watcher/file_watcher.h>

namespace mocha {
class PathInfo {
 public :
  PathInfo( const char* path );
  inline StrHandle GetDirPath() { return dir_; }
  inline StrHandle GetFileName() { return filepath_; }
  inline StrHandle GetFileIdentifier() { return raw_path_; }
 private :
  const char* GetDirectoryFromPath_( const char* path );
  const char* GetFileNameFromPath_( const char* );
  StrHandle filepath_;
  StrHandle dir_;
  StrHandle raw_path_;
};

class FileSystem {
 public :
  static StrHandle pwd ();
  static Handle<PathInfo> GetPathInfo( const char* path );
  static StrHandle NormalizePath( const char* path );
  static void Chdir ( const char* path );
  static bool Chmod( const char* pass , int permiss );
  static StrHandle GetModuleKey( const char* );
  static void SetModuleDir( const char* path );
  inline static const char* GetModuleDir(){ return module_dir_.c_str(); }
  static StrHandle GetUserHomeDir();
  static StrHandle GetAbsolutePath( const char* path );
  static bool Mkdir( const char* path , int permiss );
 private :
  static std::string module_dir_;
};

}

#endif

