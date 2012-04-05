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
#include <string.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
namespace mocha {

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

template <const char* info_type>
void FPrintWithTime(FILE* fp, const std::string& str) {
  time_t time;
  tm date;
  std::string tmp;
  os::Time(&time);
  os::LocalTime(&date, &time);
  os::Asctime(&tmp, &date);
  tmp.erase(tmp.size() - 1, tmp.size());
  os::FPrintf(fp , "%s: %s %s\n", tmp.c_str(), info_type, str.c_str());
}

FILE* Rotate(const char* path, const char* mode, FILE* fp) {
  os::fs::Stat stat(path);
  if (stat.Size() > 524288) {
    std::string buf;
    time_t time;
    tm date;
    os::Time(&time);
    os::LocalTime(&date, &time);
    os::SPrintf(&buf, "%s-%d%d%d%d", path, date.tm_year + 1900, date.tm_mon, date.tm_mday, date.tm_hour);
    os::fs::mv(path, buf.c_str());
    os::FClose(fp);
    return FileOpen(path, mode);
  }
  return fp;
}

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

Logging::Logging(const char* filename, const char* mode)
    : is_own_(true) {
  fp_ = FileOpen(filename, mode);
  fp_ = Rotate(filename, mode, fp_);
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

const char Logging::kLog[] = {"[Log]"};
const char Logging::kInfo[] = {"[Info]"};
const char Logging::kFatal[] = {"[Fatal]"};
const char Logging::kWarn[] = {"[Warn]"};

void Logging::Log(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  FPrintWithTime<kLog>(fp_, buf);
}

void Logging::Fatal(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  FPrintWithTime<kFatal>(fp_, buf);
}

void Logging::Warn(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  FPrintWithTime<kWarn>(fp_, buf);
}

void Logging::Info(const char* format, ...) {
  va_list args;
  va_start(args, format);
  std::string buf;
  os::VSPrintf(&buf, format, args);
  FPrintWithTime<kInfo>(fp_, buf);
}

bool Logging::initialized_ = false;
os::Mutex Logging::mutex_;
ScopedPtr<Logging> Logging::logging_;
}
