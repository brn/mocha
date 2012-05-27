#include <stdio.h>
#include <string.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/fs_watcher.h>
#include <mocha/roaster/log/logging.h>
using namespace mocha::os::fs;
void print(FSEvent* e) {
  printf("Modify %s\n", e->filename());
  e->watcher()->Exit();
}
void print2(FSEvent* e) {
  printf("Update %s\n", e->filename());
  e->watcher()->Exit();
}

int main() {
  mocha::Logging::Initialize(stdout);
  FSWatcher watcher;
  watcher.AddWatch("C:/Users/brn/github/mocha/src/mocha/roaster/nexc/parser/parser.cc");
  watcher.AddWatch("C:/Users/brn/github/mocha/src/mocha/roaster/platform/fs/event/win32/ut.cc");
  watcher.AddListener(FSWatcher::kModify, print);
  watcher.AddListener(FSWatcher::kUpdate, print2);
  watcher.Run();
  return 0;
}

