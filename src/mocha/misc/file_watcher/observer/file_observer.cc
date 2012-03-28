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

class FileObserver::FileUpdater : public IUpdater {
  friend class FileObserver;
 public :
  void Update(watch_traits::Modify* trait) {
    const char* filename = trait->filename;
    if (mutex_list_.find(filename) != mutex_list_.end()) {
      os::Mutex* mutex = mutex_list_[ filename ].Get();
      os::ScopedLock lock((*mutex));
      if (!UpdateDepends(filename)) {
        FileInfo* resource = FileInfoMap::SafeGet(filename);
        if (resource) {
          Roaster roaster;
          roaster.CompileFileAsync(filename, resource->GetInputCharset(), resource->compilation_info().Get(), FileWriter());
        }
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
    const FileObserver::DependsMap& map = FileObserver::depends_map();
    typedef FileObserver::DependsMap DM;
    if (map.find(filename) != map.end()) {
      std::pair<DM::const_iterator, DM::const_iterator> it = map.equal_range(filename);
      for (DM::const_iterator iterator = it.first; iterator != it.second; ++iterator) {
        FileInfo* resource = FileInfoMap::SafeGet(iterator->second.c_str());
        if (resource) {
          Roaster roaster;
          roaster.CompileFileAsync(iterator->second.c_str(), resource->GetInputCharset(), resource->compilation_info().Get(), FileWriter());
        }
      }
      return true;
    } else {
      return false;
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
    CompilationInfo info;
    Nexc nexc(&info);
    nexc.CompileFile(filename, file_info->GetInputCharset());
    typedef Nexc::Dependencies ND;
    const ND& dependencies = nexc.GetDepends();
    for (ND::const_iterator it = dependencies.begin(); it != dependencies.end(); ++it) {
      map_.insert(std::pair<const char*,const char*>(it->c_str(), filename));
      SharedPtr<os::Mutex> handle(new os::Mutex());
      file_updater_->mutex_list_[filename] = handle;
      file_watcher_.AddWatch(it->c_str(), file_updater_.Get(), FileWatcher::kModify);
    }
    SharedPtr<os::Mutex> handle(new os::Mutex());
    file_updater_->mutex_list_[filename] = handle;
    file_watcher_.AddWatch(filename, file_updater_.Get(), FileWatcher::kModify);
  }
}
FileObserver::DependsMap FileObserver::map_;
}
