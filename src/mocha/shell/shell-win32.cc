#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <mocha/shell/shell-win32.h>
#include <mocha/roaster/nexc/scanner/encoding/encoding.h>
namespace mocha {
const char kPrompt[] = {">> "};

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
  setlocale(LC_ALL, "");
  printf("mocha es-next-compiler");
  printf("\nusage -> run 'help'\n");
}

Shell::~Shell() {}

void Shell::Read() {
  while(1) {
    char buffer[6001];
    printf("%s", kPrompt);
    char* str = fgets(buffer, 6000, stdin);
    int len = strlen(str);
    if (len > 1) {
      ConsoleInput input = str;
      input.erase(input.size() - 1, 1);
      if (action_(input)) {
        break;
      }
    }
  }
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

void Shell::Break(bool initial) {
  printf("\n");
}

void Shell::SafeBreak(bool initial) {
  os::ScopedLock lock(mutex_);
  Break(initial);
}

os::Mutex Shell::mutex_;
ScopedPtr<Shell> Shell::shell_;
AtomicWord Shell::init_;

}
