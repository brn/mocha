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
#include <string.h>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/directory/directory-inl.h>

namespace mocha {namespace os {namespace fs {
Directory::Directory(const char* path) : dirpath_(path){};
Directory::~Directory(){}

class DirFinder {
  typedef std::vector<std::string> SubDirList;
 public :
  DirFinder(const char* path, bool recursive, DIR* dir, memory::Pool* pool) :
      path_(path),
      recursive_(recursive),
      dir_(dir),
      first_(0),
      current_(0),
      pool_(pool){};
  
  inline DirEntry* GetFirst() { return first_; }
  inline DirEntry* Find() {
    SubDirList sub;
    while (1) {
      int ret = readdir_r(dir_, &entry_, &result_);
      if (ret != 0) {
        break;
      }
      if (result_ == NULL) {
        break;
      }
      if (strcmp(result_->d_name, ".") == 0 || strcmp(result_->d_name, "..") == 0) {
        continue;
      }
      std::stringstream st;
      st << path_ << "/"
         << result_->d_name;
      std::string fullpath = st.str();
      Stat stat(fullpath.c_str());
      bool is_dir = false;
      if (stat.IsDir()) {
        if (recursive_) {
          sub.push_back(fullpath);
        }
        is_dir = true;
      }
      DirEntry* entry = new(pool_) DirEntry(result_->d_name, path_, is_dir);
      if (first_ == 0) {
        first_ = entry;
      } else {
        current_->SetNext(entry);
      }
      current_ = entry;
    }
    closedir(dir_);
    FindSubDir(sub);
    return current_;
  }
  
 private :
  void FindSubDir(const SubDirList& sub) {
    SubDirList::const_iterator begin = sub.begin(),end = sub.end();
    while (begin != end) {
      const char* path = (*begin).c_str();
      DIR* dir = opendir(path);
      if (dir == NULL) {
        continue;
      } else {
        DirFinder finder(path, recursive_, dir, pool_);
        DirEntry* last = finder.Find();
        if (first_) {
          current_->SetNext(finder.GetFirst());
          current_ = (last)? last : current_;
        } else {
          first_ = finder.GetFirst();
          current_ = last;
        }
      }
      ++begin;
    }
  }
  const char* path_;
  bool recursive_;
  DIR* dir_;
  dirent entry_;
  dirent *result_;
  DirEntry* first_;
  DirEntry* current_;
  memory::Pool *pool_;
};

Directory::const_iterator Directory::Entries(bool recursive) {
  DIR* dir = opendir(dirpath_.c_str());
  if (dir == NULL) {
    return const_iterator(0);
  }
  DirFinder finder(dirpath_.c_str(), recursive, dir, &pool_);
  finder.Find();
  return const_iterator(finder.GetFirst());
}

void Directory::chdir(const char* path) {
  ::chdir(path);
}

void Directory::chmod(const char* path, int permiss) {
  ::chmod(path, permiss);
}
}}}

