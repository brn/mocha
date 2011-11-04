
#ifndef mocha_io_h_
#define mocha_io_h_
#include "useconfig.h"

#include <stdio.h>
#include <string>
#include <boost/unordered_map.hpp>
#include "handle.h"
#include "thread.h"

#define RAW_IO_BUF_SIZE 1000

namespace mocha {
class Stat;
class FileIO;

class File {
 private :

  int fd;
  Stat *fstat;
  bool isLocked;
  bool opened;

  unsigned int openType;

  inline char* allocate ( size_t size );

  inline char* reallocate ( char* buffer , size_t size );
    
  std::string path_;

 public :
  typedef enum {
    kUpdate,
    kCreate
  } DateType;
  File ();
  File ( int fd , const char* path , unsigned int openType , Stat *fstat , bool isNeedLock );
  File ( const File& file );
  ~File ();
  File& operator = ( const File& file );

  void close ();

  CStrHandle getFileContents ();

  int write ( const char* buf );

  int readSync ( char *buf , size_t size );

  bool isSuccess ();

  StrHandle getDate ( DateType type = kUpdate );

  long int getSize ();

  const char* getFileName ();

};

class FileIO {

  friend class File;
    
 private:

  static Mutex mutex_;
  static Mutex close_mutex_;
  static int Flags[];
  static int Permission[];

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
    
  inline static void getPermiss ( unsigned int *permiss , int access );

  FileIO () {};
  FileIO ( const FileIO& io ) {};
  ~FileIO () {};
  typedef boost::unordered_map<int,int> FdList;
  static FdList fd_list_;  
 public :
    
  enum {
    P_ReadOnly = 1,
    P_ReadWrite = 2
  };
  
  static Handle<File> Open ( const char* path , const char* mode , int access = 0 );
  
  static bool isExist ( const char* path );

  static int CreateFile ( const char* filename , int access = 0 );
  static void CloseAll();
};

}

#endif

