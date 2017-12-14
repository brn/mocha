#ifndef mocha_shell_h_
#define mocha_shell_h_
#include <termios.h>
#include <histedit.h>
#include <string>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
typedef std::string ConsoleInput;
class Action {
 public :
  virtual bool operator()(ConsoleInput){return true;}
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
  bool CallAction();
  static void Destruct();
  Action& action_;
  ConsoleInput input_;
  EditLine* line_;
  History* history_;
  HistEvent event_;
  static os::Mutex mutex_;
  static Shell* shell_;
  static std::atomic<int> init_;
};
}

#endif
