#include <windows.h>
#include <vector>
#include <string>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/win32/fs_handle.h>
#include <mocha/roaster/platform/fs/event/win32/readdirectorychangesw.h>

namespace mocha {namespace os { namespace fs {
typedef std::pair<const char*, FSEventContainer*> DirPair;
typedef std::pair<const char*, bool> FSEventPair;
typedef std::vector<FSEvent*> Files;
struct FSEventContainer {
  int ref;
  HANDLE fs_event_handle;
  Files* files;
  OVERLAPPED ol;
};
static int bufsiz = 4096;
static std::vector<unsigned char> buf(bufsiz);
static DWORD filter = 
        FILE_NOTIFY_CHANGE_FILE_NAME   |
        FILE_NOTIFY_CHANGE_DIR_NAME    |
        FILE_NOTIFY_CHANGE_ATTRIBUTES  |
        FILE_NOTIFY_CHANGE_SIZE        |
        FILE_NOTIFY_CHANGE_LAST_WRITE;
HANDLE OpenHandle(const char* path) {
  HANDLE handle = CreateFile(path, FILE_LIST_DIRECTORY,
                             FILE_SHARE_READ | FILE_SHARE_DELETE |
                             FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
                             FILE_FLAG_NO_BUFFERING | FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);
  if (handle == INVALID_HANDLE_VALUE) {
    DEBUG_LOG(Fatal, "Handle is invalid in FSEventHandle::FSEventHandle %s\n", path);
  }
  return handle;
}
class FSWatcherAsync {
  friend class FSWatcher;
 public :
  FSWatcherAsync(HANDLE iocp, FSWatcher* fs_watcher)
      : is_exit_(true),
        iocp_handle_(iocp),
        fs_watcher_(fs_watcher){}
  ~FSWatcherAsync(){}
  void Run() {
    is_exit_ = false;
    FSEventContainer* fs_event_container;
    LPOVERLAPPED pol = NULL;
    DWORD cbNumberOfBytesTransferred = 0;
    ULONG uCompletionKey;
    BOOL bRet;
    
    while (!is_exit_) {
      bRet = GetQueuedCompletionStatus(iocp_handle_, 
                                       &cbNumberOfBytesTransferred, 
                                       &uCompletionKey, 
                                       &pol, 
                                       2000);
      if ( !bRet ) {
        // Error
      } else {
        fs_event_container = reinterpret_cast<FSEventContainer*>(CONTAINING_RECORD(pol, FSEventContainer, ol));
        Files::iterator it = fs_event_container->files->begin();
        for (; it != fs_event_container->files->end(); ++it) {
          FSEvent* e = (*it);
          if (e->IsExist()) {
            if (e->IsModified()) {
              fs_watcher_->NotifyForKey(fs_watcher_->kModify, e);
            }
            if (e->IsUpdate()) {
              fs_watcher_->NotifyForKey(fs_watcher_->kUpdate, e);
            }
          } else {
            fs_watcher_->NotifyForKey(fs_watcher_->kDelete, e);
          }
        }
        fs_watcher_->ReadDirectoryChangesW(&buf[0], bufsiz, filter);
      }
    }
  };
 private :
  bool is_exit_;
  HANDLE iocp_handle_;
  FSWatcher* fs_watcher_;
};

void* FSWatcher::ThreadRunner(void* param) {
  FSWatcherAsync* async = reinterpret_cast<FSWatcherAsync*>(param);
  async->Run();
  return NULL;
}

FSWatcher::FSWatcher() {
  async_ = new FSWatcherAsync(CreateIoCompletionPort(INVALID_HANDLE_VALUE,
                                                     NULL,
                                                     NULL,
                                                     1), this);
}

FSWatcher::~FSWatcher() {
}

void FSWatcher::AddWatch(const char* path){
  Path path_info(path);
  const char* dir = path_info.directory();
  Stat stat(dir);
  Stat file_stat(path_info.absolute_path());
  if (stat.IsExist() && stat.IsDir() &&
      file_stat.IsExist() && file_stat.IsReg()) {
    FileMap::iterator find_file = file_map_.find(path);
    if (find_file == file_map_.end()) {
      file_map_.insert(FSEventPair(path_info.absolute_path(), true));
      DirectoryMap::iterator it = dir_map_.find(dir);
      FSEvent* file_event = new(&pool_) FSEvent(path_info.absolute_path(), this);
      if (it == dir_map_.end()) {
        FSEventContainer* container = pool_.Alloc<FSEventContainer>(sizeof(FSEventContainer));
        container->ref = 0;
        container->files = new Files;
        container->files->push_back(file_event);
        container->fs_event_handle = OpenHandle(dir);
        memset(&(container->ol), 0, sizeof(container->ol));
        dir_map_.insert(DirPair(dir, container));
      } else {
        it->second->ref++;
        it->second->files->push_back(file_event);
      }
    }
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* dir = path_info.directory();
  DirectoryMap::iterator it = dir_map_.find(dir);
  if (it != dir_map_.end()) {
    it->second->ref--;
    if (it->second->ref == 0) {
      dir_map_.erase(it);
    }
  }
  FileMap::iterator find_file = file_map_.find(path);
  if (find_file != file_map_.end()) {
    file_map_.erase(find_file);
  }
}

void FSWatcher::CreateIOCP() {
  DirectoryMap::iterator it = dir_map_.begin();
  for (; it != dir_map_.end(); ++it) {
    CreateIoCompletionPort(it->second->fs_event_handle,
                           async_->iocp_handle_, NULL, 1);
    
    if (!::ReadDirectoryChangesW(it->second->fs_event_handle, &buf[0], bufsiz,
                                 TRUE, filter, NULL,
                                 &(it->second->ol), NULL)) {
      std::string buf;
      os::GetLastError(&buf);
      DEBUG_LOG(Fatal, "%s\n", buf.c_str());
    }
  }
}

void FSWatcher::Run() {
  CreateIOCP();
  Thread t;
  t.Create(ThreadRunner, async_);
  t.Join();
}

void FSWatcher::RunAsync() {
  CreateIOCP();
  Thread t;
  t.Create(ThreadRunner, async_);
  t.Detach();
}

void FSWatcher::Exit() {
  async_->is_exit_ = true;
}

bool FSWatcher::IsRunning() const {return !async_->is_exit_;}

void FSWatcher::ReadDirectoryChangesW(void* buf, int size, int filter) {
  DirectoryMap::iterator it = dir_map_.begin();
  for (; it != dir_map_.end(); ++it) {
    ::ReadDirectoryChangesW(it->second->fs_event_handle, buf, size,
                          TRUE, filter, NULL,
                          &(it->second->ol), NULL);
  }
}

const char FSWatcher::kModify[] = {"Modified<ReadDirectoryChangesW>"};
const char FSWatcher::kUpdate[] = {"Update<ReadDirectoryChangesW>"};
const char FSWatcher::kDelete[] = {"Delete<ReadDirectoryChangesW>"};
}}}
