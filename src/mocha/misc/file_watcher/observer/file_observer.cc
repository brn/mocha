#include <string.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/roaster.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/observer/file_observer.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/options/setting.h>
#include <mocha/misc/file_writer.h>
namespace mocha {

class AsyncCallback {
 public :
  void operator()(CompilationResult* result) {
    FileWriter writer;
    writer(result);
    os::ScopedLock lock(mutex_);
    FileObserver::DependsMap *map = FileObserver::depends_map();
    typedef FileObserver::DependsMap DM;
    DM::iterator it = map->begin();
    for (; it != map->end();) {
      Logging::GetInstance()->Log("%s %s\n", it->second.c_str(),result->fullpath());
      if (strcmp(it->second.c_str(),result->fullpath()) == 0) {
        map->erase(it++);
      } else {
        ++it;
      }
    }
    const DepsListHandle deps = result->deps();
    for (DepsList::const_iterator it = deps->begin(); it != deps->end(); ++it) {
      map->insert(std::pair<std::string,std::string>((*it), result->fullpath()));
    }
  }
 private :
  static os::Mutex mutex_;
};

os::Mutex AsyncCallback::mutex_;

class FileObserver::FileUpdater : public IUpdater {
  friend class FileObserver;
 public :
  void Update(watch_traits::Modify* trait) {
    const char* filename = trait->filename;
    if (mutex_list_.find(filename) != mutex_list_.end()) {
      os::Mutex* mutex = mutex_list_[ filename ].Get();
      os::ScopedLock lock((*mutex));
      UpdateDepends(filename);
      FileInfo* resource = FileInfoMap::SafeGet(filename);
      if (resource) {
        Roaster roaster;
        roaster.CompileFileAsync(filename, resource->GetInputCharset(), resource->compilation_info().Get(), AsyncCallback());
      }
    }
  }
  void Update(watch_traits::DeleteSelf* trait) {
    const char* filename = trait->filename;
    if (mutex_list_.find(filename) != mutex_list_.end()) {
      os::Mutex* mutex = mutex_list_[ filename ].Get();
      os::ScopedLock lock((*mutex));
      List::iterator ret = mutex_list_.find(filename);
      if (mutex_list_.end() != ret) {
        mutex_list_.erase(ret);
      }
    }
  }
 private :
  bool UpdateDepends(const char* filename) {
    FileObserver::DependsMap *map = FileObserver::depends_map();
    typedef FileObserver::DependsMap DM;
    if (map->find(filename) != map->end()) {
      std::pair<DM::const_iterator, DM::const_iterator> it = map->equal_range(filename);
      for (DM::const_iterator iterator = it.first; iterator != it.second; ++iterator) {
        FileInfo* resource = FileInfoMap::SafeGet(iterator->second.c_str());
        DEBUG_LOG(Info, "update depends\nwith file\n[\n%s\n]", iterator->second.c_str());
        if (resource) {
          Roaster roaster;
          roaster.CompileFileAsync(iterator->second.c_str(), resource->GetInputCharset(), resource->compilation_info().Get(), FileWriter());
        }
      }
    }
  }
  typedef roastlib::unordered_map<std::string,SharedPtr<os::Mutex> > List;
  List mutex_list_;
};

FileObserver::FileObserver() : file_updater_(new FileUpdater) {}

void FileObserver::Run() {
  Initialize_();
  os::Thread thread;
  if (!thread.Create(FileObserver::ThreadRunner_, &file_watcher_)) {
  } else {
    thread.Detach();
  }
}

void FileObserver::Exit(FileWatcher::EndCallBack fn, void* arg) {
  file_watcher_.Exit(fn, arg);
}

void* FileObserver::ThreadRunner_ (void* arg) {
  FileWatcher* watcher = reinterpret_cast<FileWatcher*>(arg);
  watcher->Start();
  return 0;
}

void FileObserver::Initialize_() {
  Roaster ro;
  XMLSettingInfo::IterateFileList<FileObserver>(&FileObserver::RegistFile_, this);
}

void FileObserver::RegistFile_(const char* filename) {
  os::fs::Stat stat(filename);
  if (stat.IsExist() && !stat.IsDir()) {
    FileInfo *file_info = FileInfoMap::SafeGet(filename);
    const DepsListHandle handle = Roaster::CheckDepends(filename);
    for (DepsList::const_iterator it = handle->begin(); it != handle->end(); ++it) {
      map_.insert(std::pair<const char*,const char*>(it->c_str(), filename));
      SharedPtr<os::Mutex> handle(new os::Mutex());
      DEBUG_LOG(Log, "DEPENDS %s", it->c_str());
      file_updater_->mutex_list_[filename] = handle;
      file_watcher_.AddWatch(it->c_str(), file_updater_.Get(), FileWatcher::kModify);
    }
    SharedPtr<os::Mutex> mutex_handle(new os::Mutex());
    file_updater_->mutex_list_[filename] = mutex_handle;
    file_watcher_.AddWatch(filename, file_updater_.Get(), FileWatcher::kModify);
  }
}
FileObserver::DependsMap FileObserver::map_;
}
