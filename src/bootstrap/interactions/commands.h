#ifndef mocha_commands_h_
#define mocha_commands_h_

namespace mocha {
class Commands {
 public :
  inline Commands() : is_observe_running_( false ) {};
  inline ~Commands() {}
  void Exec( const char* buf );
  bool IsObserving() { return is_observe_running_; }
 private :
  bool is_observe_running_;
};
}

#endif
