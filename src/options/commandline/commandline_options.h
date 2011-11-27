#ifndef mocha_commandline_options_h_
#define mocha_commandline_options_h_
#include <useconfig.h>
#include <options/options.h>

namespace mocha {

class CommandLineOptions {
 public :
  inline static Options* GetInstance () {
    return &instance_;
  }
 private :
  static Options instance_;
};

}

#endif //mocha_commandline_options_h_
