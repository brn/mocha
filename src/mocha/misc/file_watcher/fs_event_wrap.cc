#ifndef mocha_misc_file_watcher_file_watcher_normal_impl_h_
#define mocha_misc_file_watcher_file_watcher_normal_impl_h_
#include <stdio.h>
#include <string.h>
#include <mocha/misc/file_watcher/file_watcher-normal.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

namespace mocha {

FileWatcher::FileWatcher()
    : is_stop_(false),
      is_end_(false){}

FileWatcher::~FileWatcher() {
  is_stop_ = true;
  is_end_ = true;
  watch_list_.clear();
}

void FileWatcher::AddWatch(const char* path) {
  Regist(path);
}

void FileWatcher::UnWatch(const char* path) {
  WatchList::iterator find = watch_list_.find(path);
  if (find != watch_list_.end()) {
    UnWatchEach(find);
  }
}

void FileWatcher::UnWatchAll() {
  watch_list_.clear();
}

void FileWatcher::Stop() {
  is_stop_ = true;
  watcher_notificator_.NotifyForKey(WatcherEvent::kStopWatch, WatcherEvent(WatcherEvent::kStop));
}

void FileWatcher::Start() {
  ProcessNotification();
}

void FileWatcher::Exit() {
  is_stop_ = true;
  is_end_ = true;
}

void FileWatcher::Regist(const char* path) {
  os::fs::Stat stat(path);
  if (stat.IsExist()) {
    AddToWatchList(path);
  }
}

void FileWatcher::AddToWatchList(const char* path) {
  WatcherContainer watcherContainer(path);
  watch_list_[path] = watcherContainer;
}

void FileWatcher::ProcessNotification() {
  while (!is_end_) {
    if (!is_stop_ && watch_list_.size() > 0) {
      WatchFile();
    }
  }
  watcher_notificator_.NotifyForKey(WatcherEvent::kEndWatch, WatcherEvent(WatcherEvent::kEnd));
}


void FileWatcher::WatchFile() {
  WatchList::iterator begin = watch_list_.begin(),end = watch_list_.end();
  while (begin != end) {
    WatcherContainer* container = &((*begin).second);
    const char* filename = container->GetFileName();
    const char* date = container->GetDate();
    os::fs::Stat stat(filename);
    const char* last_date = stat.MTime();
    if (stat.IsExist()) {
      if (strcmp(date, last_date) != 0) {
        container->SetDate(last_date);
        FileEvent event(filename);
        file_notificator_.NotifyForKey(FileEvent::kModify, event);
      }
    } else {
      FileEvent event(filename);
      file_notificator_.NotifyForKey(FileEvent::kDelete, event);
    }
    ++begin;
  }
}

void FileWatcher::UnWatchEach(WatchList::iterator& it) { watch_list_.erase(it); }
const char FileEvent::kModify[] = {"FileEvent<Modify>"};
const char FileEvent::kDelete[] = {"FileEvent<Delete>"};
const char WatcherEvent::kEndWatch[] = {"WatcherEvent<End>"};
const char WatcherEvent::kStopWatch[] = {"WatcherEvent<Stop>"};

}
#endif
/*
#include "uv.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
static uv_fs_event_t fs_event;
static uv_timer_t timer;

static void create_dir(uv_loop_t* loop, const char* name) {
  int r;
  uv_fs_t req;
  r = uv_fs_mkdir(loop, &req, name, 0755, NULL);
  assert(r == 0 || uv_last_error(loop).code == UV_EEXIST);
  uv_fs_req_cleanup(&req);
}

static void create_file(uv_loop_t* loop, const char* name) {
  int r;
  uv_file file;
  uv_fs_t req;

  r = uv_fs_open(loop, &req, name, O_WRONLY | O_CREAT,
                 S_IWRITE | S_IREAD, NULL);
  assert(r != -1);
  file = r;
  uv_fs_req_cleanup(&req);
  r = uv_fs_close(loop, &req, file, NULL);
  assert(r == 0);
  uv_fs_req_cleanup(&req);
}
static uv_loop_t* loop = uv_default_loop(); 
static long long x = 0;
static void idle_cb(uv_idle_t* idle, int status) {
  x++;
  if (x > 100000) {
    uv_unref(loop);
  }
}

static void close_cb(uv_handle_t*){}

static void fs_event_cb(uv_fs_event_t* handle, const char* filename,
                       int events, int status) {
  printf("%s %d %d\n", handle->filename, events, status);
}

int main() {
uv_fs_t fs_req;

int r;


uv_idle_t idle;
uv_idle_init(uv_default_loop(), &idle);
uv_idle_start(&idle, idle_cb);

char buf[100];
r = uv_fs_event_init(loop, &fs_event, "test.cc", fs_event_cb, 0);
r = uv_fs_event_init(loop, &fs_event, "test_tmp.cc", fs_event_cb, 0);
uv_unref(loop);
uv_run(loop);

r = uv_fs_unlink(loop, &fs_req, "test.cc", NULL);
r = uv_fs_unlink(loop, &fs_req, "test_tmp.cc", NULL);

return 0;
}
*/
