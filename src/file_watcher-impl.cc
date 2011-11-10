#ifndef mocha_file_watcher_win_impl_cc_
#define mocha_file_watcher_win_impl_cc_
#include "useconfig.h"
#ifdef HAVE_WINDOWS_H
#include <windows.h>
#define sleep(time) Sleep(time##000)
#endif
#include <stdio.h>
#include <boost/unordered_map.hpp>
#include "file_system.h"
#include "file_watcher.h"
#include "stat.h"
#define SETTINGS Setting::GetInstance()
#define GET_MASK(mask) ( type & mask ) == mask
#define ITERATOR(name) begin = name.begin(),end = name.end();

namespace mocha {


class WatcherContainer {
 public :
  WatcherContainer( const char* path , IUpdater* updater , int type ) :
      type_( type ) , filename_( path ) , updater_( updater ) {
    Stat stat( path );
    date_ = stat.MTime();
  }
  inline const char* GetDate() { return date_.c_str(); }
  inline void SetDate( const char* date ) { date_ = date; }
  inline const char* GetFileName() { return filename_.c_str(); }
  inline IUpdater* GetUpdater() { return updater_; }
 private :
  int type_;
  std::string filename_;
  std::string date_;
  IUpdater *updater_;
};

class FileWatcher::PtrImpl {
 public :
  inline PtrImpl() : is_stop_( false ) , is_end_( false ) {}
  inline ~PtrImpl(){
    is_stop_ = true;
    is_end_ = true;
    watch_list_.clear();
  }

  inline void AddWatch( const char* path , IUpdater *updater , int type ) {
    Regist_( path , updater , type );
  }

  inline void UnWatch( const char* path ) {
    WatchList::iterator find = watch_list_.find( path );
    if ( find != watch_list_.end() ) {
      UnWatch_( find );
    }
  }

  inline void UnWatchAll() {
    WatchList::iterator ITERATOR(watch_list_);
    while ( begin != end ) {
      UnWatch_( begin );
      ++begin;
    }
  }

  inline void Stop() {
    is_stop_ = true;
  }

  inline void Start() {
    ProcessNotification_();
  }

  inline void End() {
    is_end_ = true;
  }

 private :
  typedef std::string FileEntry;
  typedef Handle<WatcherContainer> WatcherHandle;
  typedef boost::unordered_map<FileEntry, WatcherHandle> WatchList;

  inline void Regist_( const char* path , IUpdater *updater , int type ) {
    Stat stat( path );
    if ( stat.IsExist() ) {
      AddToWatchList_( path , updater , type );
    }
  }

  inline void AddToWatchList_( const char* path , IUpdater *updater , int type ) {
    WatcherHandle watcher_handle( new WatcherContainer( path ,  updater , type ) );
    watch_list_[ path ] = watcher_handle;
  }

  inline void ProcessNotification_() {
    while ( !is_end_ ) {
      if ( !is_stop_ && watch_list_.size() > 0 ) {
        WatchFile_();
      }
      sleep(1);
    }
  }


  void WatchFile_() {
    WatchList::iterator ITERATOR(watch_list_);
    while ( begin != end ) {
      WatcherContainer* container = (*begin).second.Get();
      const char* filename = container->GetFileName();
      const char* date = container->GetDate();
      Stat stat( filename );
      if ( stat.IsExist() ) {
        const char* last_date = stat.MTime();
        if ( strcmp( date , last_date ) != 0 ) {
          container->SetDate( last_date );
          watch_traits::Modify modify( filename );
          container->GetUpdater()->Update( &modify );
        }
      } else {
        watch_traits::DeleteSelf missing( filename );
        container->GetUpdater()->Update( &missing );
      }
      ++begin;
    }
  }

  inline void UnWatch_( WatchList::iterator& it ) { watch_list_.erase( it ); }

  bool is_stop_;
  bool is_end_;
  WatchList watch_list_;
};

}

#endif
