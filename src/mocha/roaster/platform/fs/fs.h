#ifndef mocha_platform_fs_h_
#define mocha_platform_fs_h_
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {namespace platform {
namespace fs {
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
  static const char* relative_path(const char* base, const char* dest, std::string* buf);
 private :
  std::string raw_;
  std::string fullpath_;
  std::string filename_;
  std::string directory_;
  static std::string current_dir_;
  static std::string user_home_;
  static std::string current_path_;
  static platform::Mutex mutex_;
};
void chdir (const char* path);
bool chmod(const char* pass, int permiss);
}
}}
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/platform/fs/directory.h>
#include <mocha/roaster/platform/fs/mkdir.h>

#endif

