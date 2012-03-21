/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_platform_fs_directory_directory_h
#define mocha_platform_fs_directory_directory_h
#include <string>
#include <sstream>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace os {
namespace fs {
class DirEntry : public memory::Allocated {
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
  static void chdir(const char* path);
  static void chmod(const char* path, int permiss);
 private :
  const char* dirpath_;
  memory::Pool pool_;
};
}
}}
#endif
