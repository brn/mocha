
#ifndef mocha_file_system_h_
#define mocha_file_system_h_
#include <useconfig.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/file_system/pwd.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {
namespace filesystem {
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
  static const char* current_directory();
  static const char* home_directory();
  const char* GetModuleDir(){ return module_dir_.c_str(); }
 private :
  std::string raw_;
  std::string fullpath_;
  std::string filename_;
  std::string directory_;
  static std::string current_dir_;
  static std::string user_home_;
  static std::string current_path_;
  static std::string module_dir_;
  static Mutex mutex_;
};
void chdir (const char* path);
bool chmod(const char* pass, int permiss);
SharedStr GetModuleKey(const char* base, const char*);
void SetModuleDir(const char* path);
}
}

#include <mocha/roaster/file_system/stat.h>
#include <mocha/roaster/file_system/virtual_directory.h>
#include <mocha/roaster/file_system/directory.h>
#include <mocha/roaster/file_system/mkdir.h>

#endif

