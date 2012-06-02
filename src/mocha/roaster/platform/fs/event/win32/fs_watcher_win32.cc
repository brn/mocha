#include <windows.h>
#include <vector>
#include <string>
#include <locale>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/win32/fs_handle.h>
#include <mocha/roaster/platform/fs/event/win32/fs_watcher_win32.h>

namespace mocha {namespace os { namespace fs {

typedef std::pair<const char*, FSEventContainer*> DirPair;
typedef std::pair<const char*, bool> FSEventPair;
typedef std::pair<const char*, FSEvent*> FilePair;
typedef roastlib::unordered_map<std::string, FSEvent*> Files;

class HandleData : public memory::Allocated {
 public :
  HandleData(HANDLE fs_event_handle, const char* dir)
      : ref_(0),
        fs_event_handle_(fs_event_handle),
        dir_(dir){}
  ~HandleData(){}
  Files* files() {return &files_;}
  const char* dir() const {return dir_.c_str();}
  HANDLE fs_event_handle() {return fs_event_handle_;}
  int ref() {return ref_;}
  void AddRef() {ref_++;}
  void Release() {ref_--;}
 private :
  int ref_;
  HANDLE fs_event_handle_;
  std::string dir_;
  Files files_;
};

struct FSEventContainer {
  HandleData* handle_data;
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

void* FSWatcher::ThreadRunner(void* param) {
  FSWatcher* watcher = reinterpret_cast<FSWatcher*>(param);
  watcher->Start();
  return NULL;
}

FSWatcher::FSWatcher()
    : is_exit_(true) {
  iocp_handle_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 1);
}

FSWatcher::~FSWatcher() {}

void FSWatcher::AddWatch(const char* path){
  Path path_info(path);
  const char* dir = path_info.directory();
  Stat stat(dir);
  Stat file_stat(path_info.absolute_path());
  if (stat.IsExist() && stat.IsDir() &&
      file_stat.IsExist() && file_stat.IsReg()) {
    FileMap::iterator find_file = file_map_.find(path);
    if (find_file == file_map_.end()) {
      ScopedLock lock(mutex_);
      file_map_.insert(FSEventPair(path_info.absolute_path(), true));
      DirectoryMap::iterator it = dir_map_.find(dir);
      FSEvent* file_event = new(&pool_) FSEvent(path_info.absolute_path(), this);
      if (it == dir_map_.end()) {
        FSEventContainer* container = pool_.Alloc<FSEventContainer>(sizeof(FSEventContainer));
        container->handle_data = new(&pool_) HandleData(OpenHandle(dir), dir);
        container->handle_data->files()->insert(FilePair(path_info.absolute_path(), file_event));
        HANDLE event = CreateEvent(NULL, TRUE, FALSE, NULL);
        ResetEvent(event);
        memset(&(container->ol), 0, sizeof(container->ol));
        container->ol.hEvent = event;
        dir_map_.insert(DirPair(dir, container));
      } else {
        it->second->handle_data->AddRef();
        it->second->handle_data->files()->insert(FilePair(path_info.absolute_path(), file_event));
      }
    }
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* dir = path_info.directory();
  DirectoryMap::iterator it = dir_map_.find(dir);
  ScopedLock lock(mutex_);
  if (it != dir_map_.end()) {
    it->second->handle_data->Release();
    if (it->second->handle_data->ref() == 0) {
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
    HandleData* handle_data = it->second->handle_data;
    CreateIoCompletionPort(handle_data->fs_event_handle(),
                           iocp_handle_, NULL, 1);
    
    if (!::ReadDirectoryChangesW(handle_data->fs_event_handle(), &buf[0], bufsiz,
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
  t.Create(ThreadRunner, this);
  t.Join();
}

void FSWatcher::RunAsync() {
  CreateIOCP();
  Thread t;
  t.Create(ThreadRunner, this);
  t.Detach();
}

void FSWatcher::Exit() {
  is_exit_ = true;
}

bool FSWatcher::IsRunning() const {return !is_exit_;}

bool FSWatcher::IsWatched(const char* path) const {
  FileMap::const_iterator find_file = file_map_.find(path);
  return find_file != file_map_.end();
}

void FSWatcher::ReadDirectoryChangesW(void* buf, int size, int filter) {
  DirectoryMap::iterator it = dir_map_.begin();
  for (; it != dir_map_.end(); ++it) {
    ::ReadDirectoryChangesW(it->second->handle_data->fs_event_handle(), buf, size,
                            TRUE, filter, NULL,
                            &(it->second->ol), NULL);
  }
}

void FSWatcher::Start() {
  is_exit_ = false;
  FSEventContainer* fs_event_container;
  LPOVERLAPPED pol = NULL;
  DWORD number_of_bytes_transferred = 0;
  ULONG completion_key;
  BOOL success;
  while (!is_exit_) {
    success = GetQueuedCompletionStatus(iocp_handle_,
                                        &number_of_bytes_transferred,
                                        &completion_key,
                                        &pol,
                                        2000);
    if (success) {
      ScopedLock lock(mutex_);
      fs_event_container = reinterpret_cast<FSEventContainer*>(CONTAINING_RECORD(pol, FSEventContainer, ol));
      HandleData* handle_data = fs_event_container->handle_data;
      DWORD ret_size = 0;
      GetOverlappedResult(handle_data->fs_event_handle(), (&fs_event_container->ol), &ret_size, FALSE);
      if (ret_size == 0) {
        WithoutFni(handle_data, fs_event_container);
      } else {
        WithFni(handle_data, fs_event_container);
      }
      ResetEvent(pol->hEvent);
    }
  }
}

void FSWatcher::WithoutFni(HandleData* handle_data, FSEventContainer* fs_event_container) {
  Files::iterator it = handle_data->files()->begin();
  for (; it != handle_data->files()->end(); ++it) {
    FSEvent* e = it->second;
    EmitEvent(e, handle_data, fs_event_container);
  }
}

void FSWatcher::WithFni(HandleData* handle_data, FSEventContainer* fs_event_container) {
  FILE_NOTIFY_INFORMATION *fni = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(&buf[0]);
  while(1) {
    std::wstring filenamew = fni->FileName;
    int size = filenamew.size() * sizeof(wchar_t) + 1;
    char* mbs = new char[size];
    wcstombs(mbs, filenamew.c_str(), size);
    std::string fullpath;
    os::SPrintf(&fullpath, "%s/%s", handle_data->dir(), mbs);
    Files::iterator find = handle_data->files()->find(fullpath.c_str());
    if (find != handle_data->files()->end()) {
      FSEvent* e = find->second;
      EmitEvent(e, handle_data, fs_event_container);
    }
    delete[] mbs;
    if (fni->NextEntryOffset == 0) {
      break;
    }
    fni = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(fni + fni->NextEntryOffset);
  }
}
  
void FSWatcher::EmitEvent(FSEvent* e, HandleData* handle_data, FSEventContainer* fs_event_container) {
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
  ::ReadDirectoryChangesW(handle_data->fs_event_handle(), (&buf[0]), bufsiz,
                          TRUE, filter, NULL,
                          &(fs_event_container->ol), NULL);
}

const char FSWatcher::kModify[] = {"Modified<ReadDirectoryChangesW>"};
const char FSWatcher::kUpdate[] = {"Update<ReadDirectoryChangesW>"};
const char FSWatcher::kDelete[] = {"Delete<ReadDirectoryChangesW>"};
}}}
