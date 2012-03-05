#include <useconfig.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_SYS_INOTIFY_H
#define INTFY 1
#endif

#include <mocha/options/setting.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/file_system/stat.h>

#ifdef INTFY
#include <mocha/misc/file_watcher/file_watcher-inotify-impl.cc>
#else
#include <mocha/misc/file_watcher/file_watcher-impl.cc>
#endif

namespace mocha {

FileWatcher::FileWatcher() :
    implementation_( new PtrImpl() ) {}

FileWatcher::~FileWatcher() {
  delete implementation_;
}

void FileWatcher::AddWatch( const char* path , IUpdater* updater , int type ) {
  implementation_->AddWatch( path , updater , type );
}

void FileWatcher::UnWatch( const char* path ) {
  implementation_->UnWatch( path );
}

void FileWatcher::UnWatchAll() {
  implementation_->UnWatchAll();
}

void FileWatcher::Stop() {
  implementation_->Stop();
}

void FileWatcher::Start() {
  implementation_->Start();
}

void FileWatcher::Exit( EndCallBack fn , void* arg ) {
  implementation_->End( fn , arg );
  //implementation_->UnWatchAll();
}

void FileWatcher::Exit() {
  implementation_->End();
  //implementation_->UnWatchAll();
}

}
