#include <string.h>
#include <boost/unordered_map.hpp>
#include <mocha/roaster/utils/compiler_facade.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/observer/file_observer.h>
#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/options/setting.h>

namespace mocha {

class FileObserver::FileUpdater : public IUpdater {
  friend class FileObserver;
 public :
  void Update( watch_traits::Modify* trait ) {
    const char* filename = trait->filename;
    if ( mutex_list_.find( filename ) != mutex_list_.end() ) {
      Mutex* mutex = mutex_list_[ filename ].Get();
      MutexLock lock( (*mutex) );
      Thread thread;
      const char* name = filename;
      char* hname = new char[ strlen( name ) + 1 ];
      strcpy( hname , name );
      if ( !thread.Create ( CompilerFacade::ExternalThreadRunner , hname ) ) {
        fprintf ( stderr,"thread create fail." );
      }
      thread.Join();
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
  typedef boost::unordered_map<std::string,SharedPtr<Mutex> > List;
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
