#include <string.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/observer/file_observer.h>
#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/options/setting.h>

namespace mocha {

class FileWriter {
 public :
  FileWriter(Resource* resource)
      : resource_(resource){}
  FileWriter(const FileWriter& writer) {
    resource_ = writer.resource_;
  }
  void operator() (CompilationResultHandle result) {
    //Current directory -> main js file path.
    //Get file name of main js file.
    char tmp[ 1000 ];
    if (resource->GetDeploy()) {
      const char* dir = resource->GetDeploy();
      Stat stat(dir);
      if (!stat.IsExist() || !stat.IsDir()) {
        FileSystem::mkdir(dir, 0777);
        FileSystem::chmod(dir, 0777);
      }
      FileSystem::Path path(result->filename());
      sprintf(tmp, "%s/%s", dir, path.filename());
    } else {
      tmp = result->filename();
    }

    //Get deploy path of -cmp.js file.
    SharedStr handle = CreateDeployName(tmp);
                                                                
    SharedPtr<File> ret = FileIO::Open (handle.Get(),
                                        "rwn",
                                        FileIO::P_ReadWrite);
    //Setting::GetInstance()->Log("deploy to %s", handle.Get());
    //Set permission to rw for all.
    FileSystem::chmod(handle.Get(), 0777);
    ret->Write(script);
  }
 private :
  Resource* resource_;
};

class FileObserver::FileUpdater : public IUpdater {
  friend class FileObserver;
 public :
  void Update( watch_traits::Modify* trait ) {
    const char* filename = trait->filename;
    if ( mutex_list_.find( filename ) != mutex_list_.end() ) {
      Mutex* mutex = mutex_list_[ filename ].Get();
      MutexLock lock((*mutex));
      Resource* resource = ExternalResource::SafeGet(filename);
      if (resource) {
        AsyncCallback callback = FileWriter(resource);
        Roaster roaster;
        roaster.CompileAsync(resource->compilation_info(), false, callback);
      }
    }
  }
  void Update( watch_traits::DeleteSelf* trait ) {
    const char* filename = trait->filename;
    if ( mutex_list_.find( filename ) != mutex_list_.end() ) {
      Mutex* mutex = mutex_list_[ filename ].Get();
      MutexLock lock( (*mutex) );
      List::iterator ret = mutex_list_.find( filename );
      if ( mutex_list_.end() != ret ) {
        mutex_list_.erase( ret );
      }
    }
  }
 private :
  typedef roastlib::unordered_map<std::string,SharedPtr<Mutex> > List;
  List mutex_list_;
};

FileObserver::FileObserver() : file_updater_( new FileUpdater ) {}

void FileObserver::Run() {
  Initialize_();
  Thread thread;
  if ( !thread.Create( FileObserver::ThreadRunner_ , &file_watcher_ ) ) {
    Setting::GetInstance()->LogFatal( "in %s thread create fail." , __func__ );
  } else {
    thread.Detach();
  }
}

void FileObserver::Exit( FileWatcher::EndCallBack fn , void* arg ) {
  file_watcher_.Exit( fn , arg );
}

void* FileObserver::ThreadRunner_ ( void* arg ) {
  FileWatcher* watcher = reinterpret_cast<FileWatcher*>( arg );
  watcher->Start();
  return 0;
}

void FileObserver::Initialize_() {
  XMLSettingInfo::IterateFileList<FileObserver>( &FileObserver::RegistFile_ , this );
}

void FileObserver::RegistFile_( const char* filename ) {
  SharedPtr<Mutex> handle( new Mutex() );
  file_updater_->mutex_list_[filename] = handle;
  file_watcher_.AddWatch( filename , file_updater_.Get() , FileWatcher::kModify );
}

}
