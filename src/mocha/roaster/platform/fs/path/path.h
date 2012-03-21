/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_platform_fs_h_
#define mocha_platform_fs_h_
#include <string>
#include <mocha/roaster/platform/thread/thread.h>
namespace mocha {namespace os {
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
  static Mutex mutex_;
};
}
}}
#endif

