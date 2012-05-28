#ifndef mocha_misc_string_utils_h_
#define mocha_misc_string_utils_h_
#include <string>
#include <sstream>
#include <mocha/roaster/misc/class_traits/static.h>
namespace mocha {
class StringUtils : private Static {
 public :
  static void Escape(std::stringstream* st, const std::string& str, char quote) {
    bool is_escaped = false;
    for (int i = 0,len = str.size(); i < len; i++) {
      if (str.at(i) == '\n') {
        (*st) << "\\n";
      } else if (str.at(i) == '\\' && !is_escaped) {
        if (i + 1 < len) {
          if (quote == '"' && (str.at(i + 1) == 'u' || str.at(i + 1) == 'x')) {
            (*st) << "\\";
            is_escaped = true;
            continue;
          }
        }
        (*st) << "\\\\";
        is_escaped = true;
      } else if (str.at(i) == quote && !is_escaped) {
        (*st) << '\\';
        (*st) << quote;
      } else if (is_escaped) {
        (*st) << str.at(i);
        is_escaped = false;
      } else {
        (*st) << str.at(i);
      }
    }
  }
};
}

#endif
