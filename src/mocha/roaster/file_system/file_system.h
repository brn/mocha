
#ifndef mocha_file_system_h_
#define mocha_file_system_h_
#include <useconfig.h>
#include <mocha/roaster/file_system/pwd.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {
class FileSystem {
 public :
  class Path {
   public :
    Path(const char* path);
    ~Path(){}
    const char* raw_path() const { return raw_.c_str(); }
    const char* absolute_path() const { return fullpath_.c_str(); }
    const char* filename() const { return filename_.c_str(); }
    const char* directory() const { return directory_.c_str(); }
    bool HasFilename() const { return !filename_.empty(); }
    bool HasDirectory() const { return !directory_.empty(); }
    bool HasAbsolutePath() const { return !fullpath_.empty(); }
   private :
    std::string raw_;
    std::string fullpath_;
    std::string filename_;
    std::string directory_;
  };
  static const char* current_directory();
  static void chdir ( const char* path );
  static bool chmod( const char* pass , int permiss );
  static bool mkdir( const char* path , int permiss );
  static const char* home_directory();
  static SharedStr GetModuleKey( const char* base , const char* );
  static void SetModuleDir( const char* path );
  inline static const char* GetModuleDir(){ return module_dir_.c_str(); }
 private :
  static std::string user_home_;
  static std::string current_path_;
  static std::string module_dir_;
};

}

#endif

