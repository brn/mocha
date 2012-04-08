#include <mocha/roaster/log/logging.h>
#include <mocha/misc/file_watcher/server/watcher_server.h>

namespace mocha {

template <const char* name>
class WatchEndCallBack {
 public :
  WatchEndCallBack(WatcherServer* server, WatcherProxy* watcher)
      : server_(server),
        watcher_(watcher){}
  ~WatchEndCallBack(){}
  void operator()(WatcherEvent) {
    watcher_->Escape();
    WatcherServerEvent e(watcher_->name());
    server_->NotifyForKey(name, e);
  }
 private :
  WatcherServer* server_;
  WatcherProxy* watcher_;
};

WatcherServer::WatcherServer(){}
void WatcherServer::AddWatcher(const char* watcher_name) {
  if (watchers_.find(watcher_name) == watchers_.end()) {
    os::ScopedLock lock(mutex_);
    ProxyHandle handle(new WatcherProxy(watcher_name));
    handle->watcher()->AddWatcherEventListener(WatcherEvent::kEndWatch, WatchEndCallBack<kEnd>(this, handle.Get()));
    handle->watcher()->AddWatcherEventListener(WatcherEvent::kStopWatch, WatchEndCallBack<kStop>(this, handle.Get()));
    watchers_.insert(std::pair<const char*, ProxyHandle>(watcher_name, handle));
  }
}

void WatcherServer::RemoveWatcher(const char* watcher_name) {
  os::ScopedLock lock(mutex_);
  Watchers::iterator it = watchers_.find(watcher_name);
  if (it != watchers_.end()) {
    watchers_.erase(it);
  }
}

WatcherProxy* WatcherServer::GetWatcherProxy(const char* name) {
  Watchers::iterator it = watchers_.find(name);
  if (it != watchers_.end()) {
    return it->second.Get();
  }
  return NULL;
}

bool WatcherServer::HasWatcher(const char* name) {
  Watchers::iterator it = watchers_.find(name);
  return it != watchers_.end();
}

void WatcherServer::Run(const char* name) {
  Watchers::iterator it = watchers_.find(name);
  if (it != watchers_.end()) {
    it->second->Enter();
    RunThread(it->second->watcher());
  }
}

void* ThreadRunner(void* arg) {
  FileWatcher* watcher = static_cast<FileWatcher*>(arg);
  watcher->Start();
  return 0;
}

void WatcherServer::RunThread(FileWatcher* watcher) {
  os::Thread thread;
  if (!thread.Create(ThreadRunner, watcher)) {
    DEBUG_LOG(Fatal, "thread create failed");
  } else {
    thread.Detach();
  }
}

void WatcherServer::ExitWatcher(const char* name) {
  Watchers::iterator it = watchers_.find(name);
  if (it != watchers_.end()) {
    it->second->Escape();
  }
}

const char WatcherServer::kEnd[] = {"WatcherServer<End>"};
const char WatcherServer::kStop[] = {"WatcherServer<Stop>"};
WatcherServer WatcherServer::instance_;
os::Mutex WatcherServer::mutex_;

}
