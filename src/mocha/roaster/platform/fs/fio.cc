#ifdef PLATFORM_POSIX
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#endif

#ifdef PLATFORM_WIN32
#include <io.h>
#include <windows.h>
#include <sys/locking.h>
#include <time.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <string>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/platform/fs/stat.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/stat.h>
#include <mocha/misc/char_allocator.h>
#include <mocha/options/setting.h>

#define SET_FLAG(flags, num)                            \
  flags = (((flags) | FileIO::flags_[ (num) ]));        \

#define SET_PERMISS(flag, num)                          \
  flag = (((flag) | FileIO::permission_[ (num) ]));     \


#ifdef PLATFORM_POSIX
#define WRITE_STREAM(fd, str, count) ::write (fd, buf, count)  
#elif PLATFORM_WIN32
#define WRITE_STREAM(fd, str, count) ::_write (fd, buf, count)
#endif

#ifdef PLATFORM_POSIX
#define OPEN_STREAM(fd, mode, access) ::open (fd, mode ,access)
#elif PLATFORM_WIN32
#define OPEN_STREAM(fd, mode, access) ::_open (fd, mode, access)
#endif

#ifdef PLATFORM_POSIX
#define READ_STREAM(fd, buf, size) ::read (fd, buf, size)
#elif PLATFORM_WIN32
#define READ_STREAM(fd, buf, size) ::_read (fd, buf, size)
#endif

#ifdef PLATFORM_POSIX
#define CLOSE_STREAM(fd) ::close (fd)
#elif PLATFORM_WIN32
#define CLOSE_STREAM(fd) ::_close (fd)  
#endif

#ifdef PLATFORM_POSIX
#define CREATE_FILE(path, permiss) ::creat (path, permiss)
#elif PLATFORM_WIN32
#define CREATE_FILE(path, permiss) ::_creat (path, permiss)
#endif


#ifdef PLATFORM_POSIX
#define LOCK_FILE(fd, type) ::flock (fd, type)  
#elif PLATFORM_WIN32
#define LOCK_FILE(fd, type) ::_locking (fd, type, 1)
#endif

#ifdef PLATFORM_WIN32
#define EN_LOCK _LK_LOCK
#define UN_LOCK _LK_UNLCK
#elif defined PLATFORM_POSIX
#define EN_LOCK LOCK_EX
#define UN_LOCK LOCK_UN
#define O_TEXT 0
#define O_BINARY 0
#endif
using namespace std;

#define REPORT_ERROR(message)
#define ENSURE_WRITABLE                                 \
  if (open_type_ == FileIO::ReadOnly) {                 \
    REPORT_ERROR("Can not write to read only stream."); \
  }

#define ENSURE_STREAM_OPENED                    \
  if (fd_ < 0) {                                \
    REPORT_ERROR("Stream is not opened.");      \
  }
namespace mocha {
namespace platform {namespace fs {
inline char* File::Allocate (size_t size) {
  return reinterpret_cast<char*> (malloc (size));
}

inline char* File::Reallocate (char* buffer, size_t size) {
  return reinterpret_cast<char*> (realloc (buffer, size));
}

File::File()
    : fd_(0), is_locked_(false), opened_(false), open_type_(0), fstat_(0){}

File::File(int fd, const char *path, unsigned int open_type, Stat *fstat, bool is_needlock)
    : fd_(fd), is_locked_(is_needlock), opened_(true), open_type_(open_type), path_(path), fstat_(fstat) {
  if (is_needlock == true && IsValidFile()) {
    LOCK_FILE (fd, EN_LOCK);
  }
};

File::File(const File& file) {
  fd_ = file.fd_;
  open_type_ = file.open_type_;
  fstat_ = file.fstat_;
  is_locked_ = file.is_locked_;
  opened_ = file.opened_;
  path_ = file.path_;
}

File::~File() {
  if (opened_ && IsValidFile()) {
    Close();
    delete fstat_;
  }
};
	
File& File::operator = (const File& file) {
  Close();
  delete fstat_;
  fd_ = file.fd_;
  open_type_ = file.open_type_;
  fstat_ = file.fstat_;
  is_locked_ = file.is_locked_;
  opened_ = file.opened_;
  path_ = file.path_;
  return *this;
}

void File::Close() {
  if (is_locked_ == true && IsValidFile()) {
    LOCK_FILE(fd_, UN_LOCK);
  }
  CLOSE_STREAM(fd_);
};

long int File::size() const { return fstat_->Size(); }

void File::GetFileContents(std::string* str) {
  ENSURE_STREAM_OPENED;
  char tmp [ RAW_IO_BUF_SIZE ];
  int char_size = sizeof (char);
  int size = char_size * RAW_IO_BUF_SIZE;
  int read_size = 0;
  while ((read_size = READ_STREAM(fd_, tmp, size - char_size)) > 0) {
    tmp[read_size] = '\0';
    str->append(tmp);
  }
}

int File::Write (const char* buf) {
  ENSURE_STREAM_OPENED;
  ENSURE_WRITABLE;
  int size = strlen (buf);
  int after;
  char* dat = const_cast<char*>(buf);
  while (1) {
    if ((after = size - WRITE_STREAM (fd_, dat, size)) == 0) {
      break;
    }else{
      dat = dat + (size - after);
      size = after;
    }
  }
  return 0;
};

bool File::IsValidFile() const {
  return (fd_ == -1)? false : true;
}

SharedStr File::GetDate(DateType type) {
  string str;
  if (type == kUpdate) {
    str = fstat_->MTime();
  } else if (type == kCreate) {
    str = fstat_->CTime();
  }
  char* ret = utils::CharAlloc(str.c_str());
  return SharedStr(ret);
}

inline void FileIO::GetPermiss (unsigned int *permiss, int access) {
  if (access == 3) {
    SET_PERMISS (*permiss, 1)
        SET_PERMISS (*permiss, 2);
  }else{
    SET_PERMISS (*permiss, access);
  }
}

SharedPtr<File> FileIO::Open (const char* path, const char* mode, int access) {
  int flag = 0;
  int flag_num = strlen (mode);
  bool is_needlock = false;
  unsigned int read_type = 0;
  unsigned int isText = 0;
  unsigned int permiss = 0;
  Stat *fstat = new Stat(path);
  SET_FLAG (flag, Create);
  for (int i = 0; i < flag_num; i++) {
    switch (mode [ i ]) {
      case 'b' :
        SET_FLAG(flag, Binary);
        break;
      case 'r':
        if (read_type == WriteOnly) {
          read_type = ReadWrite;
        }else{
          read_type = ReadOnly;
        }
        break;
      case 'w' :
        if (read_type == ReadOnly) {
          read_type = ReadWrite;
        }else{
          read_type = WriteOnly;
        }
        is_needlock = true;
        break;
      case 'a' :
        SET_FLAG (flag, Append);
        break;
      case 't' :
        isText = 1;
        break;
      case 'n' :
        SET_FLAG (flag, New);
        break;
    }
  }
  SET_FLAG (flag, read_type);		
  if (isText == 1) {
    SET_FLAG (flag, Text);
  }else{
    SET_FLAG (flag, Binary);
  }
  GetPermiss (&permiss, access);
  int fd = OPEN_STREAM(path, flag, permiss);
  SharedPtr<File> file_(new File (fd, path, read_type, fstat, is_needlock));
  return file_;
};

int FileIO::CreateFile(const char* filename, int access) {
  unsigned int permiss = 0;
  GetPermiss (&permiss, access);
  return CREATE_FILE (filename, permiss);
}

bool FileIO::IsExist(const char* path) { 
  Stat fs(path);
  return fs.IsExist();
}

int FileIO::flags_[] = {
  O_BINARY,
  O_RDONLY,
  O_WRONLY,
  O_RDWR,
  O_CREAT,
  O_APPEND,
  O_TEXT,
  O_TRUNC
};

int FileIO::permission_[] = {
  0,
  S_IREAD,
  S_IWRITE
};

platform::Mutex FileIO::mutex_;
platform::Mutex FileIO::close_mutex_;
}
}}


