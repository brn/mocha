#ifndef mocha_commands_analyzer_h_
#define mocha_commands_analyzer_h_
#include <string>
#include <utils/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {
class ICommandLineRunner;
class Options;
class CommandsAnalyzer {
 public :
  CommandsAnalyzer() : state_( 0 ) {}
  ~CommandsAnalyzer(){}
  SharedPtr<ICommandLineRunner> Analyze( const char* buf );
 private :
  enum {
    kS_Begin = 0,
    kS_Error,
    kS_Exit,
    kS_Compile,
    kS_Observe,
    kS_Help,
    kS_List
  };
  void AnalyzeEachToken_( Options* option );
  
  int state_;
  std::string buf_;
};
}

#endif
