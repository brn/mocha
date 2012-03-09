#ifndef mocha_directory_h
#define mocha_directory_h
#include <string>
#include <sstream>
#include <mocha/roaster/smart_pointer/scope/scoped_list.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace platform {
namespace fs {
class DirEntry : public memory::Allocated {
  friend class DirectoryIterator;
  friend class Directory;
 public :
  DirEntry(const char* path, const char* dir) : name_(path), dir_(dir), next_(0){
    full_path_ = dir;
    full_path_ += "/";
    full_path_ += path;
  }
  ~DirEntry(){};
  const char* GetName() const { return name_.c_str(); };
  const char* GetFullPath() const { return full_path_.c_str(); };
  const char* GetDirName() const { return dir_.c_str(); };
  void SetNext(DirEntry* ent) { next_ = ent; };
 private :
  DirEntry() : next_(0){}
  std::string name_;
  std::string dir_;
  std::string full_path_;
  const DirEntry* next_;
};

class Directory {
 public :
  class const_iterator : public std::iterator<std::forward_iterator_tag, const DirEntry*> {
   public :
    explicit const_iterator(const DirEntry*);
    const_iterator(const const_iterator&);
    ~const_iterator();
    const const_iterator& operator = (const const_iterator&);
    const DirEntry* operator*() const;
    const_iterator& operator ++();
    bool operator !=(const const_iterator&) const;
   private :
    const DirEntry* entry_;
  };
  Directory(const char* path);
  ~Directory();
  const_iterator Entries(bool recursive);
  const_iterator end() const { return const_iterator(0);};
 private :
  const char* dirpath_;
  memory::Pool pool_;
};
}
}}
#endif
