#include <windows.h>
#include <vector>
#include <string>
#include <locale>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/win32/fs_watcher_win32.h>

namespace mocha {namespace os { namespace fs {
typedef SharedPtr<FSEvent> FSEventHandle;
typedef std::pair<const char*, HandleDataHandle> DirPair;
typedef std::pair<const char*, bool> FSEventPair;
typedef std::pair<const char*, FSEventHandle> FilePair;
typedef roastlib::unordered_map<std::string, FSEventHandle> Files;
#define BUF_SIZE sizeof(FILE_NOTIFY_INFORMATION) * 50
static const int kSync = 1;
static const int kAsync = 2;
static const int kExit = 1;
class HandleData {
 public :
  HandleData(HANDLE fs_event_handle, const char* dir)
      : removed_(false),
        ref_(0),
        fs_event_handle_(fs_event_handle),
        dir_(dir) {}
  ~HandleData() {
    if (fs_event_handle_ != INVALID_HANDLE_VALUE) {
      CloseHandle(fs_event_handle_);
    }
  }
  Files* files() {return &files_;}
  const char* dir() const {return dir_.c_str();}
  HANDLE fs_event_handle() {return fs_event_handle_;}
  int ref() {return ref_;}
  void AddRef() {ref_++;}
  void Release() {ref_--;}
  void set_removed() {removed_ = true;}
  void clear_removed() {removed_ = false;}
  bool removed() const {return removed_;}
  char* buffer() {return buf_;}
  LPOVERLAPPED overlapped() {return &ol_;}
  OVERLAPPED ol_;
 private :
  bool removed_;
  int ref_;
  HANDLE fs_event_handle_;
  char buf_[BUF_SIZE];
  std::string dir_;
  Files files_;
};

static DWORD filter = 
    FILE_NOTIFY_CHANGE_FILE_NAME   |
    FILE_NOTIFY_CHANGE_CREATION |
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

void* FSWatcher::ThreadRunner(void* param) {
  FSWatcher* watcher = reinterpret_cast<FSWatcher*>(param);
  watcher->Start();
  return NULL;
}

FSWatcher::FSWatcher()
    : is_exit_(true),
      run_type_(0) {
  iocp_handle_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 1);
}

FSWatcher::~FSWatcher() {
  RemoveWatch();
  if (iocp_handle_ != INVALID_HANDLE_VALUE) {
    CloseHandle(iocp_handle_);
  }
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
      FSEventHandle file_event_handle(new FSEvent(path_info.absolute_path(), this));
      if (it == dir_map_.end()) {
        HandleDataHandle handle(new HandleData(OpenHandle(dir), dir));
        handle->AddRef();
        handle->files()->insert(FilePair(path_info.absolute_path(), file_event_handle));
        HANDLE event = CreateEvent(NULL, TRUE, FALSE, NULL);
        ResetEvent(event);
        memset(handle->overlapped(), 0, sizeof(*(handle->overlapped())));
        handle->overlapped()->hEvent = event;
        dir_map_.insert(DirPair(dir, handle));
        CreateIoCompletionPort(handle->fs_event_handle(),
                               iocp_handle_, NULL, 1);
        if (!is_exit_) {
          ReadDirectoryChangesW(handle.Get());
        }
      } else {
        it->second->AddRef();
        it->second->files()->insert(FilePair(path_info.absolute_path(), file_event_handle));
      }
    }
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* dir = path_info.directory();
  DirectoryMap::iterator it = dir_map_.find(dir);
  int type = run_type_;
  if (it != dir_map_.end()) {
    if (!is_exit_) {
      Exit();
    }
    Files* files = it->second->files();
    Files::iterator file_it = files->find(path_info.absolute_path());
    if (file_it != files->end()) {
      if (it->second->ref() > 0) {
        it->second->Release();
      }
      files->erase(file_it);
    }
    if (type == kSync) {
      Run();
    } else if (type == kAsync) {
      RunAsync();
    }
  }
}

void FSWatcher::RemoveWatch() {
  Exit();
  dir_map_.clear();
}

void FSWatcher::CreateIOCP() {
  DirectoryMap::iterator it = dir_map_.begin();
  for (; it != dir_map_.end(); ++it) {
    ReadDirectoryChangesW(it->second.Get());
  }
}

void FSWatcher::Run() {
  CreateIOCP();
  run_type_ = kSync;
  Thread t;
  t.Create(ThreadRunner, this);
  t.Join();
}

void FSWatcher::RunAsync() {
  CreateIOCP();
  run_type_ = kAsync;
  Thread t;
  t.Create(ThreadRunner, this);
  t.Detach();
}

void FSWatcher::Exit() {
  is_exit_ = true;
  run_type_ = 0;
  LPOVERLAPPED ol = new OVERLAPPED;
  PostQueuedCompletionStatus(iocp_handle_, 0, kExit, ol);
  ScopedLock lock(mutex_);
}

bool FSWatcher::IsRunning() const {return !is_exit_;}

bool FSWatcher::IsWatched(const char* path) const {
  FileMap::const_iterator find_file = file_map_.find(path);
  return find_file != file_map_.end();
}

void FSWatcher::ReadDirectoryChangesW(HandleData* handle_data) {
  if (!::ReadDirectoryChangesW(handle_data->fs_event_handle(), handle_data->buffer(), BUF_SIZE,
                               TRUE, filter, NULL,
                               handle_data->overlapped(), NULL)) {
    std::string buf;
    os::GetLastError(&buf);
    DEBUG_LOG(Fatal, "%s\n", buf.c_str());
  }
}

void FSWatcher::Start() {
  ScopedLock lock(mutex_);
  is_exit_ = false;
  LPOVERLAPPED pol = NULL;
  DWORD number_of_bytes_transferred = 0;
  ULONG completion_key;
  BOOL success;
  bool unlocked = false;
  while (1) {
    success = GetQueuedCompletionStatus(iocp_handle_,
                                        &number_of_bytes_transferred,
                                        &completion_key,
                                        &pol,
                                        INFINITE);
    if (completion_key == kExit) {
      delete pol;
      break;
    }
    if (success) {
      HandleData* handle_data = reinterpret_cast<HandleData*>(CONTAINING_RECORD(pol, HandleData, ol_));
      if (handle_data->ref() > 0) {
        DWORD ret_size = 0;
        GetOverlappedResult(handle_data->fs_event_handle(), handle_data->overlapped(), &ret_size, FALSE);
        ResetEvent(handle_data->overlapped()->hEvent);
        if (ret_size == 0) {
          WithoutFni(handle_data);
        } else {
          WithFni(handle_data);
        }
      }
    }
  }
}

void FSWatcher::WithoutFni(HandleData* handle_data) {
  Files::iterator it = handle_data->files()->begin();
  for (; it != handle_data->files()->end(); ++it) {
    FSEvent* e = it->second.Get();
    EmitEvent(e, handle_data);
  }
  if (!is_exit_) {
    ::ReadDirectoryChangesW(handle_data->fs_event_handle(), handle_data->buffer(), BUF_SIZE,
                            TRUE, filter, NULL,
                            handle_data->overlapped(), NULL);
  }
}

void FSWatcher::WithFni(HandleData* handle_data) {
  FILE_NOTIFY_INFORMATION *fni = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(handle_data->buffer());
  FILE_NOTIFY_INFORMATION *head = fni;
  while (1) {
    int w_size = fni->FileNameLength;
    if (w_size > 0) {
      int size = w_size + 1;
      fni->FileName[w_size / sizeof(wchar_t)] = 0;
      char* mbs = new char[size];
      wcstombs(mbs, fni->FileName, size);
      std::string fullpath;
      os::SPrintf(&fullpath, "%s/%s", handle_data->dir(), mbs);
      Files::iterator find = handle_data->files()->find(fullpath.c_str());
      if (find != handle_data->files()->end()) {
        FSEvent* e = find->second.Get();
        EmitEvent(e, handle_data);
      }
      delete[] mbs;
    }
    if (fni->NextEntryOffset == 0) {
      break;
    }
    fni = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(reinterpret_cast<unsigned char*>(fni) + fni->NextEntryOffset);
  }
  if (!is_exit_) {
    ::ReadDirectoryChangesW(handle_data->fs_event_handle(), handle_data->buffer(), BUF_SIZE,
                            TRUE, filter, NULL,
                            handle_data->overlapped(), NULL);
  }
}

void FSWatcher::EmitEvent(FSEvent* e, HandleData* handle_data) {
  if (e->IsExist()) {
    if (e->IsModified()) {
      NotifyForKey(kModify, e);
    }
    if (e->IsUpdate()) {
      NotifyForKey(kUpdate, e);
    }
  } else {
    NotifyForKey(kDelete, e);
  }
}

const char FSWatcher::kModify[] = {"Modified<ReadDirectoryChangesW>"};
const char FSWatcher::kUpdate[] = {"Update<ReadDirectoryChangesW>"};
const char FSWatcher::kDelete[] = {"Delete<ReadDirectoryChangesW>"};
}}}
