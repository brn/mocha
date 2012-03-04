#ifndef mocha_file_watcher_inotify_impl_cc_
#define mocha_file_watcher_inotify_impl_cc_
#include <sys/inotify.h>
#include <vector>
#include <mocha/misc/file_watcher/file_watcher.h>
#include <mocha/roaster/smart_pointer/common/ptr_handle.h>
#include <mocha/roaster/lib/unordered_map.h>

#define SETTINGS Setting::GetInstance()
namespace mocha {

#define GET_MASK(mask) ( type & mask ) == mask
#define ITERATOR(type,name1,name2) name1 = type.begin(),name2 = type.end()
#define ITERATOR_LOOP(name1,name2) while ( name1 != name2 )
#define ITERATOR_NEXT(name) ++name
#define GET(it) (*it)

////////////////////////////////////////////////
// Case have Inotify. To many case it's linux //
////////////////////////////////////////////////
namespace inotify_helper_ {

typedef unsigned long InotifyMask;
/**
 * @private
 * @return {int} -> file descriptor
 * Open inotify fd.
 */
int OpenInotifyFD_() {
  int fd = inotify_init();
  if ( fd < 0 ) {
    fprintf( stderr ,"inotify_init fail.\n"  );
    //SETTINGS->LogError( "inotify_init fail." );
  }
  return fd;
}

InotifyMask GetWatchType( int type ) {
  InotifyMask mask = 0;
  if ( GET_MASK( FileWatcher::kAccess ) ) {
    mask |= IN_ACCESS;
  }
  if ( GET_MASK( FileWatcher::kModify ) ) {
    mask |= IN_CLOSE_WRITE;
  }
  if ( GET_MASK( FileWatcher::kAttrib ) ) {
    mask |= IN_ATTRIB;
  }
  if ( GET_MASK( FileWatcher::kOpen ) ) {
    mask |= IN_OPEN;
  }
  if ( GET_MASK( FileWatcher::kClose ) ) {
    mask |= IN_CLOSE;
  }
  if ( GET_MASK( FileWatcher::kMoveSelf ) ) {
    mask |= IN_MOVE_SELF;
  }
  if ( GET_MASK( FileWatcher::kMovedFrom ) ) {
    mask |= IN_MOVED_FROM;
  }
  if ( GET_MASK( FileWatcher::kMovedTo ) ) {
    mask |= IN_MOVED_TO;
  }
  if ( GET_MASK( FileWatcher::kDeleteSelf ) ) {
    mask |= IN_DELETE_SELF;
  }
  if ( GET_MASK( FileWatcher::kDelete ) ) {
    mask |= IN_DELETE;
  }
  if ( GET_MASK( FileWatcher::kCreate ) ) {
    mask |= IN_CREATE;
  }
  if ( GET_MASK( FileWatcher::kAdd ) ) {
    mask |= IN_MASK_ADD;
  }
  return mask;
}

}

class WatcherContainer {
 public :
  WatcherContainer( const char* path , IUpdater *updater , int type , int wd ) :
      filename_( path ) , type_( type ) , wd_( wd ) , updater_( updater ){};
  inline const char* GetFileName() const { return filename_.c_str(); }
  inline int GetType() const { return type_; }
  inline int GetWatchDescriptor() const { return wd_; }
  inline IUpdater* GetUpdater() const { return updater_; }
 private :
  std::string filename_;
  int type_;
  int wd_;
  IUpdater* updater_;
};


class FileWatcher::PtrImpl {
 public :
  PtrImpl() :
      fd_( inotify_helper_::OpenInotifyFD_() ) , is_watch_( true ) , is_end_( false ) , is_call_back_( false ) {}
  ~PtrImpl () {
    if ( is_end_ ) {
      is_end_ = true;
    }
    ::close(fd_);
    array_.clear();
  }
  void AddWatch( const char* path , IUpdater* updater , int type ) {
    Stat stat( path );
    if ( stat.IsExist() ) {
      inotify_helper_::InotifyMask mask = inotify_helper_::GetWatchType( type );
      int wd = inotify_add_watch( fd_ , path , mask );
      Regist_( path , updater , type , wd );
      if ( wd < 0 ) {
        fprintf( stderr , "Can not add watch for %s with event mask %ld." , path , mask );
        //      SETTINGS->LogFatal( "Can not add watch for %s with event mask %ld." , path , mask );
      }
    }
  }

  void UnWatch( const char* path ) {
    WatchList::iterator iterator;
    for ( iterator = watch_list_.begin(); iterator != watch_list_.end(); ++iterator ) {
      if ( strcmp( iterator->second->GetFileName() , path ) == 0 ) {
        inotify_rm_watch(fd_, iterator->second->GetWatchDescriptor());
        watch_list_.erase(iterator->second->GetWatchDescriptor());
        break;
      }
    }
  }

  void UnWatchAll() {
    watch_list_.clear();
  }

  void Stop() {
    is_watch_ = false;
  }

  void End() {
    is_watch_ = false;
    is_end_ = true;
  }

  void End( FileWatcher::EndCallBack fn , void* arg ) {
    fn_ = fn;
    is_call_back_ = true;
    arg_ = arg;
    End();
  }

  void Start() {
    ProcessInotifyEvent_();
  }
  
 private :
  typedef std::vector<SharedPtr<inotify_event> > EventArray;
  typedef std::pair<int,SharedPtr<WatcherContainer> > WatchPair;
  typedef roastlib::unordered_map<int,SharedPtr<WatcherContainer> > WatchList;
  
  void Regist_( const char* path , IUpdater* updater , int type , int wd ) {
    SharedPtr<WatcherContainer> handle( new WatcherContainer( path , updater , type , wd ) );
    watch_list_.insert(WatchPair(wd, handle));
  }
  
  void ProcessInotifyEvent_() {
    while ( !is_end_ ) {
      if ( is_watch_ && watch_list_.size() > 0 ) {
        if ( CheckEvent_() ) {
          int read_event = ReadInotifyEvents_();
          if ( read_event > 0 ) {
            ProcessEvent_();
          }
        }
      } else {
        sleep(1);
      }
    }
    if ( is_call_back_ ) {
      fn_( arg_ );
    }
  }


  int CheckEvent_() {
    fd_set rfds;
    timeval waitval;
    waitval.tv_sec  = 0;
    waitval.tv_usec = 500;
    FD_ZERO(&rfds);
    FD_SET( fd_ , &rfds );
    return ::select( FD_SETSIZE , &rfds , NULL , NULL , &waitval );
  }


  int ReadInotifyEvents_() {
    array_.clear();
    char buffer[ 16384 ];
    size_t buffer_i = 0;
    inotify_event *pevent;
    size_t read_size;
    size_t event_size;
    size_t q_event_size;
    int count = 0;
    read_size = ::read( fd_ , buffer , 16384 );
    if ( read_size <= 0 ) {
      return 0;
    }
    while ( buffer_i < read_size ) {
      pevent = reinterpret_cast<inotify_event*>( &buffer[buffer_i] );
      event_size = offsetof( inotify_event , name ) + pevent->len;
      q_event_size = offsetof( inotify_event , name ) + pevent->len;
      inotify_event* ret = new inotify_event;
      memcpy( ret , pevent , event_size );
      SharedPtr<inotify_event> handle( ret );
      array_.push_back( handle );
      buffer_i += event_size;
      count++;
    }
    return count;
  }

  
  void ProcessEvent_() {
    EventArray::iterator ITERATOR(array_,begin,end);
    ITERATOR_LOOP( begin , end ) {
      inotify_event *cont = (*begin).Get();
      int wd = cont->wd;
      WatchList::iterator find = watch_list_.find( wd );
      if ( find != watch_list_.end() && !(GET(begin)->mask & IN_ISDIR) ) {
        SwitchEvents_( ( GET(begin)->mask & ( IN_ALL_EVENTS | IN_UNMOUNT | IN_Q_OVERFLOW | IN_IGNORED ) ) , find->second.Get() );
      }
      ++begin;
    }
  }

#define UPDATE(name) {                                          \
    watch_traits::name inst_( container->GetFileName() );       \
    container->GetUpdater()->Update(&inst_);                    \
  }                                                             \
    break

#define UNWATCH                                 \
  UnWatch(container->GetFileName());            \
  break
  
  void SwitchEvents_( inotify_helper_::InotifyMask mask , WatcherContainer* container ) {
    switch ( mask ) {
      case IN_ACCESS :
        UPDATE(Access);
      case IN_CLOSE_WRITE :
        UPDATE(Modify);
      case IN_ATTRIB :
        UPDATE(Attrib);
      case IN_OPEN :
        UPDATE(Open);
      case IN_CLOSE :
        UPDATE(Close);
      case IN_IGNORED :
        UNWATCH;
      case IN_MOVED_FROM :
        UPDATE(MoveFrom);
      case IN_MOVED_TO :
        UPDATE(MoveTo);
      case IN_MOVE_SELF :
        UPDATE(MoveSelf);
      case IN_DELETE_SELF :
        UPDATE(DeleteSelf);
      case IN_DELETE :
        UPDATE(Delete);
      case IN_CREATE :
        UPDATE(Create);
    }
  }
#undef UPDATE
  
  int fd_;
  bool is_watch_;
  bool is_end_;
  bool is_call_back_;
  void* arg_;
  FileWatcher::EndCallBack fn_;
  WatchList watch_list_;
  EventArray array_;
  IUpdater* updater_;
};

}
#endif
