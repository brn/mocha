#include <string.h>
#include <mocha/roaster/roaster.h>
#include <mocha/misc/file_writer.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/misc/file_watcher/observer/javascript_observer.h>
#include <mocha/misc/file_watcher/server/watcher_server.h>
#define UNOPTIMIZED_WAIT while (!running_) {volatile int8_t x = 0;}
namespace mocha {

class JavascriptObserver::WatcherCallBack {
 public :
  WatcherCallBack(JavascriptObserver* observer)
      : observer_(observer){}
  void operator()(WatcherEvent) {
    observer_->running_ = false;
  }
 private :
  JavascriptObserver* observer_;
};

class JavascriptObserver::Updater {
 public :
  Updater(JavascriptObserver* observer)
      : observer_(observer){}
  
  void operator()(CompilationResult* result) {
    FileWriter writer;
    writer(result);
    os::ScopedLock lock(mutex_);
    typedef JavascriptObserver::DependsMap DM;
    DM::iterator it = observer_->depends_.begin();
    for (; it != observer_->depends_.end();) {
      Logging::GetInstance()->Log("%s %s\n", it->second.c_str(),result->fullpath());
      if (strcmp(it->second.c_str(),result->fullpath()) == 0) {
        observer_->depends_.erase(it++);
      } else {
        ++it;
      }
    }
    const DepsListHandle deps = result->deps();
    for (DepsList::const_iterator it = deps->begin(); it != deps->end(); ++it) {
      observer_->depends_.insert(std::pair<std::string,std::string>((*it), result->fullpath()));
    }
  }
 private :
  JavascriptObserver* observer_;
  static os::Mutex mutex_;
};

os::Mutex JavascriptObserver::Updater::mutex_;

class JavascriptObserver::DeleteCallback {
 public :
  DeleteCallback(JavascriptObserver* observer)
      : observer_(observer){}
  void operator()(FileEvent e) {
    const char* filename = e.filename();
    JavascriptObserver::MutexMap::iterator it = observer_->mutex_list_.find(filename);
    if (it != observer_->mutex_list_.end()) {
      JavascriptObserver::MutexHandle handle = it->second;
      os::Mutex* mutex = handle.Get();
      os::ScopedLock lock((*mutex));
      observer_->mutex_list_.erase(it);
      JavascriptObserver::DependsMap::iterator it = observer_->depends_.find(filename);
      if (it != observer_->depends_.end()) {
        observer_->depends_.erase(it);
      }
    }
  }
 private :
  JavascriptObserver* observer_;
};

class JavascriptObserver::ModifyCallback {
 public :
  ModifyCallback(JavascriptObserver* observer)
      : observer_(observer){}

  void operator()(FileEvent e) {
    const char* filename = e.filename();
    JavascriptObserver::MutexMap::iterator it = observer_->mutex_list_.find(filename);
    if (it != observer_->mutex_list_.end()) {
      os::Mutex* mutex = it->second.Get();
      os::ScopedLock lock((*mutex));
      UpdateDepends(filename);
      FileInfo* resource = FileInfoMap::SafeGet(filename);
      if (resource) {
        Roaster roaster;
        roaster.CompileFileAsync(filename, resource->GetInputCharset(), resource->compilation_info().Get(), Updater(observer_));
      }
    }
  }
  
  void UpdateDepends(const char* filename) {
    typedef JavascriptObserver::DependsMap DM;
    if (observer_->depends_.find(filename) != observer_->depends_.end()) {
      std::pair<DM::const_iterator, DM::const_iterator> it = observer_->depends_.equal_range(filename);
      for (DM::const_iterator iterator = it.first; iterator != it.second; ++iterator) {
        FileInfo* resource = FileInfoMap::SafeGet(iterator->second.c_str());
        DEBUG_LOG(Info, "update depends\nwith file\n[\n%s\n]", iterator->second.c_str());
        if (resource) {
          Roaster roaster;
          roaster.CompileFileAsync(iterator->second.c_str(), resource->GetInputCharset(),
                                   resource->compilation_info().Get(), FileWriter());
        }
      }
    }
  }
 private :
  JavascriptObserver* observer_;
};

JavascriptObserver::JavascriptObserver()
    : running_(false) {}


void JavascriptObserver::AddFileToWatcher(const char* filename, WatcherProxy* proxy) {
  os::fs::Stat stat(filename);
  if (stat.IsExist() && !stat.IsDir()) {
    Roaster ro;
    const DepsListHandle handle = Roaster::CheckDepends(filename);
    for (DepsList::const_iterator it = handle->begin(); it != handle->end(); ++it) {
      depends_.insert(std::pair<const char*,const char*>(it->c_str(), filename));
      MutexHandle handle(new os::Mutex());
      DEBUG_LOG(Log, "DEPENDS %s", it->c_str());
      if (mutex_list_.find(it->c_str()) == mutex_list_.end()) {
        mutex_list_.insert(std::pair<const char*, MutexHandle>(it->c_str(), handle));
        proxy->watcher()->AddWatch(it->c_str());
      }
    }
    MutexHandle mutex_handle(new os::Mutex());
    mutex_list_.insert(std::pair<const char*, MutexHandle>(filename, mutex_handle));
    proxy->watcher()->AddWatch(filename);
  }
}

void JavascriptObserver::Run() {
  if (!running_) {
    WatcherServer* server = WatcherServer::GetInstance();
    server->AddWatcher(server_name_);
    WatcherProxy* proxy = server->GetWatcherProxy(server_name_);
    if (proxy != NULL) {
      proxy->watcher()->AddWatcherEventListener(WatcherEvent::kEndWatch, WatcherCallBack(this));
      proxy->watcher()->AddWatcherEventListener(WatcherEvent::kStopWatch, WatcherCallBack(this));
      proxy->watcher()->AddFileEventListener(FileEvent::kModify, ModifyCallback(this));
      proxy->watcher()->AddFileEventListener(FileEvent::kDelete, DeleteCallback(this));
      FileList::iterator it;
      for (it = file_list_.begin(); it != file_list_.end(); ++it) {
        AddFileToWatcher(it->first.c_str(), proxy);
      }
      running_ = true;
      server->Run(server_name_);
    }
  }
}

void JavascriptObserver::AddFile(const char* filename) {
  if (file_list_.find(filename) == file_list_.end()) {
    file_list_.insert(std::pair<const char*, bool>(filename, true));
  }
}

void JavascriptObserver::RemoveFile(const char* filename) {
  FileList::iterator it = file_list_.find(filename);
  if (it != file_list_.end()) {
    file_list_.erase(it);
  }
}

void JavascriptObserver::Exit() {
  WatcherServer* server = WatcherServer::GetInstance();
  server->AddWatcher(server_name_);
  WatcherProxy* proxy = server->GetWatcherProxy(server_name_);
  if (proxy != NULL) {
    proxy->watcher()->Exit();
    while (running_) {os::Sleep(500);}
    WatcherServer* server = WatcherServer::GetInstance();
    server->RemoveWatcher(server_name_);
    FileInfoMap::Reset();
  }
}

void JavascriptObserver::Stop() {
    WatcherServer* server = WatcherServer::GetInstance();
    server->AddWatcher(server_name_);
    WatcherProxy* proxy = server->GetWatcherProxy(server_name_);
    if (proxy != NULL) {
      proxy->watcher()->Stop();
      while (running_){os::Sleep(1000);}
    }
}

void JavascriptObserver::Resume() {
  if (!running_) {
    WatcherServer* server = WatcherServer::GetInstance();
    WatcherProxy* proxy = server->GetWatcherProxy(server_name_);
    if (proxy != NULL) {
      server->Run(server_name_);
    }
  }
}

const char JavascriptObserver::server_name_[] = {"Observer<Javascript>"};
}
