#include "useconfig.h"
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_SYS_INOTIFY_H
#define INTFY 1
#endif

#include "setting.h"
#include "handle.h"
#include "stat.h"

#ifdef INTFY
#include "file_watcher-inotify-impl.cc"
#else
#include "file_watcher-impl.cc"
#endif

namespace mocha {

FileWatcher::FileWatcher() :
    implementation_( new PtrImpl() ) {}

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

}
