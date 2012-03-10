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
      platform::Mutex* mutex = mutex_list_[ filename ].Get();
      platform::ScopedLock lock((*mutex));
      FileInfo* resource = FileInfoMap::SafeGet(filename);
      if (resource) {
        AsyncCallbackHandle callback(new FileWriter);
        Roaster roaster;
        roaster.CompileFileAsync(resource->compilation_info(), false, callback);
      }
    }
  }
  void Update(watch_traits::DeleteSelf* trait) {
    const char* filename = trait->filename;
    if (mutex_list_.find(filename) != mutex_list_.end()) {
      platform::Mutex* mutex = mutex_list_[ filename ].Get();
      platform::ScopedLock lock((*mutex));
      List::iterator ret = mutex_list_.find(filename);
      if (mutex_list_.end() != ret) {
        mutex_list_.erase(ret);
      }
    }
  }
 private :
  typedef roastlib::unordered_map<std::string,SharedPtr<platform::Mutex> > List;
  List mutex_list_;
};

FileObserver::FileObserver() : file_updater_(new FileUpdater) {}

void FileObserver::Run() {
  Initialize_();
  platform::Thread thread;
  if (!thread.Create(FileObserver::ThreadRunner_, &file_watcher_)) {
    Setting::GetInstance()->LogFatal("in FileObserver::Run thread create fail.");
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
  XMLSettingInfo::IterateFileList<FileObserver>(&FileObserver::RegistFile_, this);
}

void FileObserver::RegistFile_(const char* filename) {
  SharedPtr<platform::Mutex> handle(new platform::Mutex());
  file_updater_->mutex_list_[filename] = handle;
  file_watcher_.AddWatch(filename, file_updater_.Get(), FileWatcher::kModify);
}

}
