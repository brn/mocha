#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <mocha/shell/shell.h>
namespace mocha {

const int kEnter = 13;
const int kEsc = 27;
const int kBackSpace = 127;
const int kEmacsRight = 6;
const int kEmacsLeft = 2;
const int kEmacsUp = 16;
const int kEmacsDown = 14;
const int kEmacsDl = 4;
const int kEndOfBuffer = 5;
const int kBeginingOfBuffer = 1;
const int kKeyUp = 65;
const int kKeyDown = 66;
const int kKeyLeft = 67;
const int kKeyRight = 68;
const char kPrompt[] = {">>> "};


Shell* Shell::Initialize(Action& action) {
  if (Atomic::CompareAndSwap(&init_, 0, 1) == 0) {
    init_ = 1;
    shell_(new Shell(action));
    return shell_.Get();
  }
  return 0;
}

Shell* Shell::GetInstance() {
  return shell_.Get();
}

Shell::Shell(Action& action)
    : action_(action){
  setlocale(LC_ALL,"");
  printf("mocha 0.7 (r"MOCHA_REV")");
  printf("\nusage -> run 'help'\n");
  InitShell();
  history_ = history_init();
  history(history_, &event_,  H_SETSIZE, 50);
}

Shell::~Shell() {
  ResetShell();
  history_end(history_);
}


void Shell::Read() {
  char *buf;
  int read;
  while(1) {
    input_ = el_gets(line_, &read);
    if (read == -1) {
      break;
    }
    input_.erase(input_.size() - 1, 1);
    history(history_, &event_, H_ENTER, input_.c_str());
    if(CallAction()) {
      break;
    }
    input_.clear();
  }
}

char* prompt(EditLine* line) {
  return ">> ";
}

void Shell::InitShell() {
  line_ = el_init("mocha", stdin, stdout, stderr);
  el_set(line_, EL_PROMPT, prompt);
  el_set(line_, EL_EDITOR, "emacs");
}

void Shell::ResetShell() {
  el_end(line_);
}

void Shell::Print(const char* str) {
  printf("%s", str);
}

void Shell::SafePrint(const char* str) {
  platform::ScopedLock lock(mutex_);
  Print(str);
}

void Shell::Print(char ch) {
  printf("%c", ch);
}

void Shell::SafePrint(char ch) {
  platform::ScopedLock lock(mutex_);
  Print(ch);
}


bool Shell::CallAction() {
  ResetShell();
  int ret = action_(input_);
  InitShell();
  return ret;
}

void Shell::Break(bool initial) {
  printf("\n");
}

void Shell::SafeBreak(bool initial) {
  platform::ScopedLock lock(mutex_);
  Break(initial);
}

platform::Mutex Shell::mutex_;
ScopedPtr<Shell> Shell::shell_;
AtomicWord Shell::init_;

}
