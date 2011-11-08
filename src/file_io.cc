
#include "file_io.h"

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef HAVE_IO_H
#include <io.h>
#endif

#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif

#ifdef HAVE_SYS_LOCKING_H
#include <sys/locking.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <string>
#include "handle.h"
#include "stat.h"
#include "setting.h"
#include "char_allocator.h"

#define SET_FLAG( flags , num )                         \
  flags = ( ( (flags) | FileIO::Flags [ (num) ] ) );    \

#define SET_PERMISS( flag , num )                               \
  flag = ( ( (flag) | FileIO::Permission [ ( num ) ] ) );       \


#ifdef HAVE_WRITE
#define WRITE_STREAM( fd , str , count ) ::write ( fd , buf , count )  
#elif HAVE__WRITE
#define WRITE_STREAM( fd , str , count ) ::_write ( fd , buf , count )
#endif

#ifdef HAVE_OPEN
#define OPEN_STREAM( fd , mode , access ) ::open ( fd , mode ,access )
#elif HAVE__OPEN
#define OPEN_STREAM( fd , mode , access ) ::_open ( fd , mode , access )
#endif

#ifdef HAVE_READ
#define READ_STREAM( fd , buf , size ) ::read ( fd , buf , size )
#elif HAVE__READ
#define READ_STREAM( fd , buf , size ) ::_read ( fd , buf , size )
#endif

#ifdef HAVE_CLOSE
#define CLOSE_STREAM( fd ) ::close ( fd )
#elif HAVE__CLOSE
#define CLOSE_STREAM( fd ) ::_close ( fd )  
#endif

#ifdef HAVE_CREAT
#define CREATE_FILE( path , permiss ) ::creat ( path , permiss )
#elif HAVE__CREAT
#define CREATE_FILE( path , permiss ) ::_creat ( path , permiss )
#endif


#ifdef HAVE_FLOCK
#define LOCK_FILE( fd , type ) ::flock ( fd , type )  
#elif HAVE__LOCKING
#define LOCK_FILE( fd , type ) ::_locking ( fd , type , 1 )
#endif

#ifdef _WIN32
#define EN_LOCK _LK_LOCK
#define UN_LOCK _LK_UNLCK
#else
#define EN_LOCK LOCK_EX
#define UN_LOCK LOCK_UN
#define O_TEXT 0
#define O_BINARY 0
#endif

using namespace mocha;
using namespace std;

#define REPORT_ERROR( message ) Setting::GetInstance()->LogError( "in %s %s\n",  __func__ , message )

#define ENSURE_WRITABLE                                         \
  if ( openType == FileIO::ReadOnly ) {                         \
    REPORT_ERROR( "Can not write to read only stream." );       \
  }

#define ENSURE_STREAM_OPENED                     \
  if ( fd < 0 ) {                               \
    REPORT_ERROR( "Stream is not opened." );    \
  }

inline char* File::Allocate ( size_t size ) {
  return reinterpret_cast<char*> ( malloc ( size ) );
}

inline char* File::Reallocate ( char* buffer , size_t size ) {
  return reinterpret_cast<char*> ( realloc ( buffer , size ) );
}

File::File () :
    fd (0),
    fstat (0),
    isLocked (false),
    opened ( false ),
    openType (0){}

File::File ( int fd , const char *path , unsigned int openType , Stat *fstat , bool isNeedLock ) :
    fd ( fd ), fstat ( fstat ), opened ( true ), openType ( openType ){
  
  isLocked = isNeedLock;

  if ( isNeedLock == true ) {
    LOCK_FILE ( fd , EN_LOCK );
  }
  path_ = path;

};

File::File ( const File& file ) {
  fd = file.fd;
  openType = file.openType;
  fstat = file.fstat;
}

File::~File () {
  if ( opened ) {
    this->Close ();
    delete fstat;
  }
};
	
File& File::operator = ( const File& file ) {
  fd = file.fd;
  openType = file.openType;
  fstat = file.fstat;
  return *this;
}

void File::Close () {
  if ( isLocked == true ) {
    LOCK_FILE ( fd , UN_LOCK );
  }
  CLOSE_STREAM ( fd );
  FileIO::FdList::iterator it = FileIO::fd_list_.find( fd );
  if ( it != FileIO::fd_list_.end() ) {
    FileIO::fd_list_.erase( it );
  }
};

CStrHandle File::GetFileContents () {
  ENSURE_STREAM_OPENED;
  char* buffer = Allocate ( sizeof ( char ) * RAW_IO_BUF_SIZE );
  char tmp [ RAW_IO_BUF_SIZE ];
  int chSize = sizeof ( char );
  int size = chSize * RAW_IO_BUF_SIZE;
  int readSize = 0;
  int currentSize = 0;

  while ( ( readSize = READ_STREAM ( fd , tmp , size - chSize ) ) > 0 ) {
    if ( currentSize > 0 ) {
      buffer = Reallocate ( buffer , ( currentSize + readSize + chSize ) );
    }
    tmp [ readSize ] = '\0';
    strcpy ( buffer + currentSize , tmp );
    currentSize += readSize;
  }
  return CStrHandle( buffer );
}

void File::GetFileContents( std::string& str ) {
  ENSURE_STREAM_OPENED;
  char tmp [ RAW_IO_BUF_SIZE ];
  int chSize = sizeof ( char );
  int size = chSize * RAW_IO_BUF_SIZE;
  int readSize = 0;
  
  while ( ( readSize = READ_STREAM ( fd , tmp , size - chSize ) ) > 0 ) {
    tmp [ readSize ] = '\0';
    str += tmp;
  }
}

const char* File::GetFileName () {
  return path_.c_str ();
}

int File::Write ( const char* buf ) {
  ENSURE_STREAM_OPENED;
  ENSURE_WRITABLE;

  int size = strlen ( buf );
  int after;
  char* dat = const_cast<char*> ( buf );
  while ( 1 ) {
    if ( ( after = size - WRITE_STREAM ( fd , dat , size ) ) == 0 ) {
      break;
    }else{
      dat = dat + ( size - after );
      size = after;
    }
  }
  return 0;
};

int File::ReadSync ( char *buf , size_t size ) {
  ENSURE_STREAM_OPENED;
  return READ_STREAM ( fd , buf , size );
};

bool File::IsSuccess () {
  return ( fd == -1 )? false : true;
}

StrHandle File::GetDate ( DateType type ) {
  string str;
  if ( type == kUpdate ) {
    str = fstat->MTime();
  } else if ( type == kCreate ) {
    str = fstat->CTime();
  }
  char* ret = utils::CharAlloc( str.c_str() );
  return StrHandle( ret );
}

long int File::GetSize () {
  return fstat->Size();
}

inline void FileIO::GetPermiss ( unsigned int *permiss , int access ) {
  if ( access == 3 ) {
    SET_PERMISS ( *permiss , 1 )
        SET_PERMISS ( *permiss , 2 );
  }else{
    SET_PERMISS ( *permiss , access );
  }
}

Handle<File> FileIO::Open ( const char* path , const char* mode , int access ) {
  int flag = 0;
  int flagNum = strlen ( mode );
  bool isNeedLock = false;
  unsigned int readType = 0;
  unsigned int isText = 0;
  unsigned int permiss = 0;
  Stat *fstat_ = new Stat( path );

  SET_FLAG ( flag , Create );

  for ( int i = 0; i < flagNum; i++ ) {
    switch ( mode [ i ] ) {
      case 'b' :
        SET_FLAG( flag , Binary );
        break;
      case 'r':
        if ( readType == WriteOnly ) {
          readType = ReadWrite;
        }else{
          readType = ReadOnly;
        }
        break;
      case 'w' :
        if ( readType == ReadOnly ) {
          readType = ReadWrite;
        }else{
          readType = WriteOnly;
        }
        isNeedLock = true;
        break;
      case 'a' :
        SET_FLAG ( flag , Append );
        break;
      case 't' :
        isText = 1;
        break;
      case 'n' :
        SET_FLAG ( flag , New );
        break;
    }
  }


  SET_FLAG ( flag , readType );
		
  if ( isText == 1 ) {
    SET_FLAG ( flag , Text );
  }else{
    SET_FLAG ( flag , Binary );
  }

  GetPermiss ( &permiss , access );
  int fd = OPEN_STREAM ( path , flag , permiss );
  FileIO::fd_list_[fd] = fd;
  Handle<File> file_ (  new File ( fd , path , readType , fstat_ , isNeedLock ) );
  return file_;
};

int FileIO::CreateFile ( const char* filename , int access ) {
  unsigned int permiss = 0;
  GetPermiss ( &permiss , access );
  return CREATE_FILE ( filename , permiss );
}

bool FileIO::IsExist ( const char* path ) { 
  Stat fs( path );
  return fs.IsExist();
}

void FileIO::CloseAll() {
  MutexLock lock( close_mutex_ );
  FdList::iterator begin = fd_list_.begin(),end = fd_list_.end();
  while ( begin != end ) {
    CLOSE_STREAM( (*begin).second );
    ++begin;
  }
  fd_list_.clear();
}

int FileIO::Flags[] = {
  O_BINARY,
  O_RDONLY,
  O_WRONLY,
  O_RDWR,
  O_CREAT,
  O_APPEND,
  O_TEXT,
  O_TRUNC
};

int FileIO::Permission[] = {
  0,
  S_IREAD,
  S_IWRITE
};

Mutex FileIO::mutex_;
Mutex FileIO::close_mutex_;
FileIO::FdList FileIO::fd_list_;
