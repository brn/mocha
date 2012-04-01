#ifndef mocha_misc_file_watcher_file_watcher_normal_impl_h_
#define mocha_misc_file_watcher_file_watcher_normal_impl_h_
#include <stdio.h>
#include <string.h>
#include <mocha/misc/file_watcher/file_watcher-normal.h>
#include <mocha/roaster/platform/utils/utils.h>
#ifdef PLATFORM_WIN32
#include <windows.h>
#endif
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
    os::Sleep(1000);
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
