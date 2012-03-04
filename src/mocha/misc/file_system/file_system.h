
#ifndef mocha_file_system_h_
#define mocha_file_system_h_
#include <useconfig.h>
#include <mocha/misc/file_system/pwd.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {
class PathInfo {
 public :
  PathInfo( const char* path );
  inline StrSharedPtr GetDirPath() { return dir_; }
  inline StrSharedPtr GetFileName() { return filepath_; }
  inline StrSharedPtr GetFileIdentifier() { return raw_path_; }
 private :
  const char* GetDirectoryFromPath_( const char* path );
  const char* GetFileNameFromPath_( const char* );
  StrSharedPtr filepath_;
  StrSharedPtr dir_;
  StrSharedPtr raw_path_;
};

class FileSystem {
 public :
  static StrSharedPtr pwd ();
  static SharedPtr<PathInfo> GetPathInfo( const char* path );
  static StrSharedPtr NormalizePath( const char* path );
  static void Chdir ( const char* path );
  static bool Chmod( const char* pass , int permiss );
  static StrSharedPtr GetModuleKey( const char* base , const char* );
  static void SetModuleDir( const char* path );
  inline static const char* GetModuleDir(){ return module_dir_.c_str(); }
  static StrSharedPtr GetUserHomeDir();
  static StrSharedPtr GetAbsolutePath( const char* path );
  static bool Mkdir( const char* path , int permiss );
 private :
  static std::string module_dir_;
};

}

#endif

