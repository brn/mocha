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
#ifndef mocha_roaster_utils_error_reporter_h_
#define mocha_roaster_utils_error_reporter_h_
#include <string>
#include <list>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
class ErrorReporter : private Uncopyable {
  typedef std::list<std::string> ErrorList;
 public :
  ErrorReporter();
  ~ErrorReporter();
  void ReportSyntaxError(const char* error);
  void ReportSysError(const char* error);
  bool Error() const { return error_num_ > 0; };
  void SetError(std::string *buf) const;
  void SetRawError(std::string *buf) const;
 private :
  int error_num_;
  ErrorList buffer_;
  ErrorList raw_list_;
};
typedef SharedPtr<ErrorReporter> ErrorHandler;
typedef std::pair<const char*,ErrorHandler> ErrorHandlerPair;
typedef roastlib::unordered_map<std::string,ErrorHandler> ErrorMap;
typedef SharedPtr<ErrorMap> ErrorMapHandle;
}

#endif
