#include <stdio.h>
#include <gtest/gtest.h>
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

TEST(PathTest, kqueueTest) {
  mocha::Logging::Initialize(stdout);
  FSWatcher watcher;
  watcher.AddWatch("/Users/aono_taketoshi/github/mocha/src/mocha/roaster/nexc/parser/parser.cc");
  watcher.AddWatch("/Users/aono_taketoshi/github/mocha/src/mocha/roaster/platform/fs/event/macos/ut.cc");
  watcher.AddListener(FSWatcher::kModifiy, print);
  watcher.AddListener(FSWatcher::kUpdate, print2);
  watcher.Run();
}

