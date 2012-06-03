#include <fcntl.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include <string.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/fs_watcher.h>
#include <mocha/roaster/platform/fs/rm/rm.h>
#include <mocha/roaster/log/logging.h>
using namespace mocha::os::fs;
namespace mocha {
typedef roastlib::unordered_map<std::string, int> UTTestFiles;
typedef roastlib::unordered_map<std::string, int> UTTestStamp;
static UTTestFiles files;
static UTTestStamp update_stamp;
static UTTestStamp modify_stamp;
static int count = 0;
static int all = 0;
void Init(int begin = 0, int end = 100) {
  for (; begin < end; begin ++) {
    std::string buf;
    os::SPrintf(&buf, CURRENT_DIR"/src/mocha/roaster/platform/fs/event/ut_watched_tmp_%d", begin);
    FILE* fp = os::FOpen(buf.c_str(), "wb");
    DEBUG_LOG(Info, "%s", buf.c_str());
    if (fp != NULL) {
      os::FClose(fp);
      files[buf.c_str()] = 1;
      all++;
    }
  }
}

void CleanUp() {
  UTTestFiles::iterator it = files.begin();
  for (; it != files.end(); ++it) {
    os::fs::rm(it->first.c_str());
  }
}

void Watch(FSWatcher* watcher) {
  UTTestFiles::iterator it = files.begin();
  for (; it != files.end(); ++it) {
    if (!watcher->IsWatched(it->first.c_str())) {
      watcher->AddWatch(it->first.c_str());
    }
  }
}

void UnWatch(FSWatcher* watcher, int num) {
  int i = 0;
  UTTestFiles::iterator it = files.begin();
  for (; it != files.end() && i < num; ++it) {
    if (watcher->IsWatched(it->first.c_str())) {
      watcher->RemoveWatch(it->first.c_str());
    }
    modify_stamp[it->first.c_str()] = 2;
    update_stamp[it->first.c_str()] = 1;
    i++;
  }
  all -= num;
}

void Touch() {
  char str[10] = {"test\n"};
  UTTestFiles::iterator it = files.begin();
  for (; it != files.end(); ++it) {
    DEBUG_LOG(Info, "Now updating %s", it->first.c_str());
    FILE* fp = os::FOpen(it->first.c_str(), "wb");
    fwrite(str, sizeof(char), strlen(str), fp);
    os::FClose(fp);
  }
}

void Check() {
  UTTestFiles::iterator it = files.begin();
  for (; it != files.end(); ++it) {
    UTTestStamp::iterator m_it = modify_stamp.find(it->first.c_str());
    UTTestStamp::iterator u_it = update_stamp.find(it->first.c_str());
    if (m_it != modify_stamp.end()) {
      ASSERT_EQ(true, m_it->second == 2);
    } else {
      FAIL();
    }
    if (u_it != update_stamp.end()) {
      ASSERT_EQ(true, u_it->second == 1);
    } else {
      FAIL();
    }
  }
}

void modify(FSEvent* e) {
  DEBUG_LOG(Info, "modify %s", e->filename());
  modify_stamp[e->filename()] = 2;
  count++;
}
void update(FSEvent* e) {
  DEBUG_LOG(Info, "update %s", e->filename());
  update_stamp[e->filename()] = 1;
}
}

TEST(FSEventTest, FSWatcherNormalTest) {
  using namespace mocha;
  mocha::Logging::Initialize(stdout);
  Init();
  FSWatcher watcher;
  Sleep(1000);
  Watch(&watcher);
  watcher.AddListener(FSWatcher::kModify, modify);
  watcher.AddListener(FSWatcher::kUpdate, update);
  watcher.RunAsync();
  Sleep(1000);
  Touch();
  while (count < all) {Sleep(1000);printf("%d\n", count);}
  Check();
  CleanUp();
  watcher.Exit();
}

TEST(FSEventTest, FSWatcherAddTest) {
  using namespace mocha;
  all = 0;
  count = 0;
  files.clear();
  update_stamp.clear();
  modify_stamp.clear();
  Init(0, 1);
  FSWatcher watcher;
  Sleep(1000);
  Watch(&watcher);
  watcher.AddListener(FSWatcher::kModify, modify);
  watcher.AddListener(FSWatcher::kUpdate, update);
  watcher.RunAsync();
  Sleep(1000);
  Init(1, 2);
  Sleep(1000);
  Watch(&watcher);
  Sleep(1000);
  Touch();
  while (count < all) {Sleep(1000);}
  Check();
  CleanUp();
  watcher.Exit();
}

TEST(FSEventTest, FSWatcherRemoveTest) {
  using namespace mocha;
  mocha::Logging::Initialize(stdout);
  all = 0;
  count = 0;
  files.clear();
  update_stamp.clear();
  modify_stamp.clear();
  Init(0, 2);
  FSWatcher watcher;
  Sleep(1000);
  Watch(&watcher);
  watcher.AddListener(FSWatcher::kModify, modify);
  watcher.AddListener(FSWatcher::kUpdate, update);
  watcher.RunAsync();
  Sleep(1000);
  UnWatch(&watcher, 1);
  Sleep(1000);
  Touch();
  while (count < all) {Sleep(1000);}
  Check();
  CleanUp();
  watcher.Exit();
}

