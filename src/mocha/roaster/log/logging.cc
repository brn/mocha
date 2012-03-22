/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
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
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
namespace mocha {

void Logging::Initialize(const char* path, const char* mode) {
  os::ScopedLock lock(mutex_);
  if (!initialized_) {
    initialized_ = true;
    logging_(new Logging(path, mode));
  }
}

void Logging::Initialize(FILE* fp) {
  os::ScopedLock lock(mutex_);
  if (!initialized_) {
    initialized_ = true;
    logging_(new Logging(fp));
  }
}

Logging* Logging::GetInstance() {
  if (!logging_.IsContainValidPtr()) {
    FATAL("Error[Logging::GetInstance] Logging::GetInstance called before Logging::Initialized called.");
  }
  return logging_.Get();
}

FILE* FileOpen(const char* path, const char* mode) {
  ASSERT(true, strlen(path) > 0);
  FILE* fp = os::FOpen(path, mode);
  //Check is file exist.
  if (fp != NULL) {
    return fp;
  } else {
    os::fs::Stat stat(path);
    if (stat.IsDir()){
      std::string buf;
      os::SPrintf(&buf, "Error[Logging::FileOpen] %s is a directory", path);
      FATAL(buf.c_str());
    } else if (!stat.IsExist()){
      std::string buf;
      os::SPrintf(&buf, "Error[Logging::FileOpen] %s No such file or directory.", path);
      FATAL(buf.c_str());
    } else {
      std::string footprint = "Error[Logging::FileOpen] ";
      std::string buf;
      os::Strerror(&buf, K_ERRNO);
      footprint += buf;
      FATAL(footprint.c_str());
    }
  }
}

Logging::Logging(const char* filename, const char* mode)
    : is_own_(true) {
  fp_ = FileOpen(filename, mode);
}
Logging::Logging(FILE* fp)
    : is_own_(false) {
  fp_ = fp;
}
Logging::~Logging() {
  if (is_own_) {
    fclose(fp_);
  }
}

void Logging::Log(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  os::FPrintf(fp_, "[Log] %s\n", buf.c_str());
}

void Logging::Fatal(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  os::FPrintf(fp_, "[Fatal] %s\n", buf.c_str());
}

void Logging::Warn(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  os::FPrintf(fp_, "[Warn] %s\n", buf.c_str());
}

void Logging::Info(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  os::FPrintf(fp_, "[Info] %s\n", buf.c_str());
}

bool Logging::initialized_ = false;
os::Mutex Logging::mutex_;
ScopedPtr<Logging> Logging::logging_;
}
