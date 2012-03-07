
#ifndef mocha_file_io_h_
#define mocha_file_io_h_
#include <useconfig.h>

#include <stdio.h>
#include <string>
#include <mocha/roaster/file_system/file_io.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/misc/char_allocator.h>

#define RAW_IO_BUF_SIZE 1000

namespace mocha {
namespace filesystem {
class Stat;
class FileIO;
class File {
 public :
  typedef enum {
    kUpdate,
    kCreate
  } DateType;
  File();
  File(int fd, const char* path, unsigned int openType, Stat *fstat, bool isNeedLock);
  File(const File& file);
  ~File();
  File& operator = (const File& file);
  int descriptor() const {return fd_;}
  void Close();
  SharedCStr GetFileContents();
  void GetFileContents(std::string* str);
  int Write(const char* buf);
  bool IsValidFile() const;
  SharedStr GetDate(DateType type = kUpdate);
  long int size() const;
  const char* filename() const { return path_.c_str(); };
 private :
  inline char* Allocate(size_t size);
  inline char* Reallocate(char* buffer, size_t size); 
  int fd_;
  bool is_locked_;
  bool opened_;
  unsigned int open_type_;
  std::string path_;
  Stat *fstat_;
};

class FileIO {
  friend class File;
 public :
  enum {
    P_ReadOnly = 1,
    P_ReadWrite = 2
  };
  static SharedPtr<File> Open(const char* path, const char* mode, int access = 0);
  static bool IsExist(const char* path);
  static int CreateFile(const char* filename, int access = 0);
 private:
  inline static void GetPermiss(unsigned int *permiss, int access);
  FileIO(){};
  FileIO(const FileIO& io) {};
  ~FileIO(){};
  static Mutex mutex_;
  static Mutex close_mutex_;
  static int flags_[];
  static int permission_[];
  enum OpenType {
    Binary = 0,
    ReadOnly = 1,
    WriteOnly = 2,
    ReadWrite = 3,
    Create = 4,
    Append = 5,
    Text = 6,
    New = 7
  };
};
}
}
#endif

