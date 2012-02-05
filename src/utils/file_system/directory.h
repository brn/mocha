#ifndef mocha_directory_h
#define mocha_directory_h
#include <string>
#include <utils/smart_pointer/scope/scoped_list.h>
namespace mocha {
class DirectoryIterator;
class DirEntry{
  friend class DirectoryIterator;
  friend class Directory;
 public :
  DirEntry( const char* path , const char* dir ) : name_( path ) , dir_( dir ) , next_( 0 ){
    full_path_ = dir;
    full_path_ += "/";
    full_path_ += path;
  }
  ~DirEntry(){};
  const char* GetName() const { return name_.c_str(); };
  const char* GetFullPath() const { return full_path_.c_str(); };
  const char* GetDirName() const { return dir_.c_str(); };
  void SetNext( DirEntry* ent ) { next_ = ent; };
 private :
  DirEntry() : next_( 0 ){}
  std::string name_;
  std::string dir_;
  std::string full_path_;
  const DirEntry* next_;
};

class DirectoryIterator {
 public :
  DirectoryIterator( const DirEntry* entry );
  ~DirectoryIterator();
  DirectoryIterator( const DirectoryIterator& );
  const DirectoryIterator& operator = ( const DirectoryIterator& );
  bool HasNext();
  const DirEntry* Next();
 private :
  const DirEntry* entry_;
};

class Directory {
 public :
  Directory( const char* path );
  ~Directory();
  DirectoryIterator GetFileList( bool is_recursive , bool show_level );
  //const DirEntry FindFile( const char* file_name );
 private :
  const char* dirpath_;
  ScopedList<DirEntry> scoped_entry_;
};

}

#endif
