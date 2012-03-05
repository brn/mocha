#ifndef mocha_js_error_reporter_h_
#define mocha_js_error_reporter_h_
#include <string>
#include <list>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
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

}

#endif
