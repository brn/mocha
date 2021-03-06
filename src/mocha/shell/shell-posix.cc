#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <locale>
#include <mocha/shell/shell.h>
#include <mocha/roaster/platform/utils/utils.h>
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
static char kPrompt[] = {'>', '>', ' '};


Shell* Shell::Initialize(Action& action) {
  auto flag = init_.load(std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_acquire);
  if (flag == 0) {
    std::atomic_thread_fence(std::memory_order_release);
    init_.store(1, std::memory_order_relaxed);
    shell_ = new Shell(action);
  }
  return shell_;
}

Shell* Shell::GetInstance() {
  return shell_;
}

Shell::Shell(Action& action)
    : action_(action){
  setlocale(LC_ALL, "");
  printf("mocha es-next-compiler(stand-alone)");
  printf("\nusage -> run 'help'\n");
  history_ = history_init();
  history(history_, &event_,  H_SETSIZE, 50);
  InitShell();
  atexit(Destruct);
}

Shell::~Shell() {
  ResetShell();
  history_end(history_);
}

void Shell::Destruct() {
  delete shell_;
}

void Shell::Read() {
  int read;
  while(1) {
    const wchar_t* val = el_wgets(line_, &read);
    if (val != NULL) {
      std::wstring input = val;
      if (read == -1) {
        break;
      }
      if (input.size() > 0) {
        input.erase(input.size() - 1, 1);
        if (input.size() > 0) {
          int size = input.size() * sizeof(wchar_t) + 1;
          char* mbs = new char[size];
          wcstombs(mbs, input.c_str(), size);
          if (input.size() > 0) {
            input_ = mbs;
            history(history_, &event_, H_ENTER, input_.c_str());
            if (input_.size() > 0) {
              if(CallAction()) {
                delete []mbs;
                break;
              }
            }
          }
          delete []mbs;
        }
      }
      input_.clear();
    }
  }
}

char* prompt(EditLine*) {
  return kPrompt;
}

void Shell::InitShell() {
  line_ = el_init("mocha", stdin, stdout, stderr);
  el_set(line_, EL_PROMPT, prompt);
  el_set(line_, EL_EDITOR, "emacs");
  el_set(line_, EL_HIST, history, history_);
}

void Shell::ResetShell() {
  el_end(line_);
}

void Shell::Print(const char* str) {
  printf("%s", str);
}

void Shell::SafePrint(const char* str) {
  os::ScopedLock lock(mutex_);
  Print(str);
}

void Shell::Print(char ch) {
  printf("%c", ch);
}

void Shell::SafePrint(char ch) {
  os::ScopedLock lock(mutex_);
  Print(ch);
}


bool Shell::CallAction() {
  ResetShell();
  int ret = action_(input_);
  InitShell();
  return ret;
}

void Shell::Break(bool) {
  printf("\n");
}

void Shell::SafeBreak(bool) {
  os::ScopedLock lock(mutex_);
  Break(false);
}

os::Mutex Shell::mutex_;
Shell* Shell::shell_;
std::atomic<int> Shell::init_;

}
