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
#ifndef mocha_roaster_log_logging_h_
#define mocha_roaster_log_logging_h_
#include <stdio.h>
#include <stdarg.h>
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
class Logging {
 public :
  static void Initialize(const char* filename, const char* mode="a+");
  static void Initialize(FILE* fp);
  static Logging* GetInstance();
  ~Logging();
  void Log(const char* format, ...);
  void Fatal(const char* format, ...);
  void Warn(const char* format, ...);
  void Info(const char* format, ...);
  static bool IsInitialized() {return initialized_;}
 private :
  Logging(const char* filename, const char* mode);
  Logging(FILE* fp);
  bool is_own_;
  FILE* fp_;
  static const char kLog[];
  static const char kInfo[];
  static const char kFatal[];
  static const char kWarn[];
  static bool initialized_;
  static os::Mutex mutex_;
  static ScopedPtr<Logging> logging_;
};
}

#ifdef DEBUG
#define DEBUG_LOG(type, ...)                    \
  ASSERT(true, Logging::IsInitialized());       \
  Logging::GetInstance()->type(__VA_ARGS__)
#else
#define DEBUG_LOG(type,...)
#endif
  
#endif
