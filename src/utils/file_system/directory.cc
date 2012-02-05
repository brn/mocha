#include <string.h>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <dirent.h>
#endif

#include <utils/file_system/directory.h>
#include <utils/file_system/stat.h>

namespace mocha {

DirectoryIterator::DirectoryIterator( const DirEntry* entry ) : entry_( entry ){}
DirectoryIterator::~DirectoryIterator() {}

DirectoryIterator::DirectoryIterator( const DirectoryIterator& iterator ) {
  entry_ = iterator.entry_;
}

const DirectoryIterator& DirectoryIterator::operator = ( const DirectoryIterator& iterator ) {
  entry_ = iterator.entry_;
  return (*this);
}

bool DirectoryIterator::HasNext() {
  return entry_ != 0;
}

const DirEntry* DirectoryIterator::Next() {
  const DirEntry* entry = entry_;
  entry_ = entry_->next_;
  return entry;
}

Directory::Directory( const char* path ) : dirpath_( path ){};
Directory::~Directory(){}

#ifdef _WIN32

DirEntry* Find( WIN32_FIND_DATA* ffdata,
                HANDLE *h_find, DirEntry* entry,
                const char* current,
                bool is_recursive,
                bool is_level,
                ScopedList<DirEntry> *scoped_list ) {
  typedef std::vector<std::string> SubDirList;
  SubDirList sub;
  while ( FindNextFile( h_find, &ffdata ) ) {
    if ( h_find == INVALID_HANDLE_VALUE ) {
      break;
    }
    if ( !is_level && ( strcmp( ffdata.cFileName , "." ) == 0 || strcmp( ffdata.cFileName , ".." ) == 0 ) ) {
      continue;
    }
    if ( ffdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) {
      if ( is_recurusive ) {
        std::string dir = ffdata.cFileName;
        sub.push_back( dir );
      }
    } else {
      DirEntry* next = scoped_list->Retain( new DirEntry( ffdata->cFileName , current ) );
      entry->SetNext( next );
      entry = next;
    }
  }
  FindClose( h_find );
  SubDirList::iterator begin = sub.begin(),end = sub.end();
  while ( begin != end ) {
    WIN32_FIND_DATA ffdata;
    HANDLE h_find;
    if ( h_find != INVALID_HANDLE_VALUE ) {
      h_find = FindFirstFile( (*begin).c_str(), &ffdata );
      DirEntry* next = scoped_list->Retain( new DirEntry( ffdata.cFileName , current ) );
      entry->SetNext( next );
      entry = Find( ffdata , h_find , next , current , is_recursive , is_level );
    }
    ++begin;
  }
  return entry;
}


DirectoryIterator GetFileList( bool is_recursive , bool show_level ) {
  WIN32_FIND_DATA ffdata;
  HANDLE h_find;
  h_find = FindFirstFile( dirpath_, &ffdata );
  if ( h_find == INVALID_HANDLE_VALUE ) {
    return DirectoryIterator( 0 );
  } else {
    DirEntry* entry;
    entry = scoped_list_.Retain( new DirEntry( ffdata.cFileName , dirpath_ ) );
    Find( &ffdata , &h_find , entry , dirpath_ , is_recursive , show_level );
    return DirectoryIterator( entry );
  }
}

#else

class DirFinder {
  typedef std::vector<std::string> SubDirList;
 public :
  DirFinder( const char* path , DIR* dir , ScopedList<DirEntry> *scoped_list ) :
      path_( path ) , dir_( dir ) , first_( 0 ) , current_( 0 ) , scoped_list_( scoped_list ){};
  inline DirEntry* GetFirst() { return first_; }
  inline DirEntry* Find() {
    SubDirList sub;
    while ( 1 ) {
      int ret = readdir_r( dir_ , &entry_ , &result_ );
      if ( ret != 0 ) {
        break;
      }
      if ( result_ == NULL ) {
        break;
      }
      if ( !show_level_ && ( strcmp( result_->d_name , "." ) == 0 || strcmp( result_->d_name , ".." ) == 0 ) ) {
        continue;
      }
      std::string fullpath = path_;
      fullpath += "/";
      fullpath += result_->d_name;
      Stat stat( fullpath.c_str() );
      if ( stat.IsDir() ) {
        if ( is_recursive_ ) {
          sub.push_back( fullpath );
        }
      } else {
        DirEntry* entry = scoped_list_->Retain( new DirEntry( result_->d_name , path_ ) );
        if ( first_ == 0 ) {
          first_ = entry;
        } else {
          current_->SetNext( entry );
        }
        current_ = entry;
      }
    }
    closedir( dir_ );
    FindSubDir_( sub );
    return current_;
  }
  
 private :
  void FindSubDir_( const SubDirList& sub ) {
    SubDirList::const_iterator begin = sub.begin(),end = sub.end();
    while ( begin != end ) {
      const char* path = (*begin).c_str();
      DIR* dir = opendir( path );
      if ( dir == NULL ) {
        continue;
      } else {
        DirFinder finder( path , dir , scoped_list_ );
        DirEntry* last = finder.Find();
        if ( first_ ) {
          current_->SetNext( finder.GetFirst() );
          current_ = ( last )? last : current_;
        } else {
          first_ = finder.GetFirst();
          current_ = last;
        }
      }
      ++begin;
    }
  }
  const char* path_;
  bool is_recursive_;
  bool show_level_;
  DIR* dir_;
  dirent entry_;
  dirent *result_;
  DirEntry* first_;
  DirEntry* current_;
  ScopedList<DirEntry> *scoped_list_;
};

DirectoryIterator Directory::GetFileList( bool is_recursive , bool show_level ) {
  DIR* dir = opendir( dirpath_ );
  if ( dir == NULL ) {
    return DirectoryIterator( 0 );
  }
  DirFinder finder( dirpath_ , dir , &scoped_entry_ );
  finder.Find();
  return DirectoryIterator( finder.GetFirst() );
}

#endif

}
