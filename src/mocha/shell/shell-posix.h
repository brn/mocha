#ifndef mocha_shell_h_
#define mocha_shell_h_
#include <termios.h>
#include <mocha/shell/stream-posix.h>
#include <mocha/roaster/misc/atomic.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {

class Action {
 public :
  virtual bool operator()(ConsoleInput input){return true;}
};

class Shell {
 public :
  ~Shell();
  static Shell* Initialize(Action& action);
  static Shell* GetInstance();
  void Read();
  void Print(const char* str);
  void SafePrint(const char* str);
  void Print(char str);
  void SafePrint(char str);
  void Break(bool initial = true);
  void SafeBreak(bool initial = true);
 private :
  Shell(Action& action);
  void InitShell();
  void ResetShell();
  int Getch();
  bool CallAction();
  bool CheckInput(int ch);
  void SwitchShellAction(int ch);
  Action& action_;
  termios cooked_term_ios_;
  termios raw_term_ios_;
  ScopedPtr<Stream> stream_;
  static platform::Mutex mutex_;
  static ScopedPtr<Shell> shell_;
  static AtomicWord init_;
};
}

#endif
