#ifndef mocha_js_error_reporter_h_
#define mocha_js_error_reporter_h_
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
