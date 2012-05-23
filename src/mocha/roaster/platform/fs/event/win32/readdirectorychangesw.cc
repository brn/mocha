#include <windows.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/win32/readdirectorychangesw.h>

namespace mocha {namespace os { namespace fs {

class FSWatcherAsync {
 public :
  FSWatcherAsync(iocp)
      : iocp_handle_(iocp){}
  ~FSWatcherAsync(){}
  void Run() {
    FSEventContainer* fs_event_container;
    LPOVERLAPPED pol = NULL;
    DWORD cbNumberOfBytesTransferred = 0;
    ULONG uCompletionKey;
    BOOL bRet;
    DWORD filter = 
        FILE_NOTIFY_CHANGE_FILE_NAME   |
        FILE_NOTIFY_CHANGE_DIR_NAME    |
        FILE_NOTIFY_CHANGE_ATTRIBUTES  |
        FILE_NOTIFY_CHANGE_SIZE        |
        FILE_NOTIFY_CHANGE_LAST_WRITE;  
    while (!is_exit_) { 
      bRet = GetQueuedCompletionStatus (
          iocp_handle_, 
          &cbNumberOfBytesTransferred, 
          &uCompletionKey, 
          &pol, 
          INFINITE );
      if ( !bRet ) {
        // Error
      }
      fs_event_container = reinterpret_cast<FSEventContainer*>(CONTAINING_RECORD(pol, FSEventContainer, ol));
      ReadDirectoryChangesW(hDir,
                            pBuf,
                            bufsiz,
                            TRUE,
                            filter,
                            NULL,
                            &olp,
                            NULL);
    }
  };
  void Exit(){};
  bool IsRunning() const {}
 private :
  HANDLE iocp_handle_;
};

void* FSWatcher::ThreadRunner(void* param) {
  FSWatcherAsync* async = reinterpret_cast<FSWatcherAsync*>(param);
  async->Run();
  return NULL;
}

typedef std::pair<const char*, int> DirPair;
typedef std::pair<const char*, FSEvent*> FSEventPair;

FSWatcher::FSWatcher()
    : async_(new FSWatcherAsync(CreateIoCompletionPort(
      INVALID_HANDLE_VALUE,
      NULL,
      NULL,
      1))){}
FSWatcher::~FSWatcher(){}
void FSWatcher::AddWatch(const char* path){
  Path path_info(path);
  const char* dir = path_info->directory();
  Stat stat(dir);
  if (stat.IsExist() && stat.IsDir()) {
    DirectoryMap::iterator it = dir_map_.find(dir);
    if (it == dir_map_.end()) {
      dir_map_.inser(DirPair(dir, 0));
    } else {
      dir_map_.inser(DirPair(dir, (it->second + 1)));
    }
    FileMap::iterator find_file = file_map_.find(path);
    if (find_file == file_map_.end()) {
      FSEvent* e = new(&pool_) FSEvent(path, this);
      file_map_.insert(FSEventPair(path, e));
    }
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* dir = path_info->directory();
  DirectoryMap::iterator it = dir_map_.find(dir);
  if (it != dir_map_.end()) {
    int ref = (it->second - 1);
    if (ref == 0) {
      dir_map_.erase(it);
    } else {
      dir_map_.inser(dir, ref);
    }
  }
  FileMap::iterator find_file = file_map_.find(path);
  if (find_file != file_map_.end()) {
    file_map_.erase(find_file);
  }
}

void FSWatcher::Run() {
  
}

void FSWatcher::Exit(){}

bool FSWatcher::IsRunning() const {}

const char FSWatcher::kModified[] = {"Modified<ReadDirectoryChangesW>"};
const char FSWatcher::kUpdate[] = {"Update<ReadDirectoryChangesW>"};
const char FSWatcher::kDelete[] = {"Delete<ReadDirectoryChangesW>"};
}}}
