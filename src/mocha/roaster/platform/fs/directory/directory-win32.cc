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
#include <windows.h>
#include <io.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/directory/directory-inl.h>
namespace mocha {namespace os {namespace fs {
Directory::Directory(const char* path) : dirpath_(path){};
Directory::~Directory(){}

DirEntry* Find(WIN32_FIND_DATA* ffdata_,
               HANDLE *h_find, DirEntry* entry,
               const char* current,
               bool recursive,
               memory::Pool *pool) {
  typedef std::vector<std::string> SubDirList;
  SubDirList sub;
  WIN32_FIND_DATA ffdata;
  while (FindNextFile(*h_find, &ffdata)) {
    if (h_find == INVALID_HANDLE_VALUE) {
      break;
    }
    if (strcmp(ffdata.cFileName, ".") == 0 || strcmp(ffdata.cFileName, "..") == 0) {
      continue;
    }
    if (ffdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      if (recursive) {
        std::string dir = ffdata.cFileName;
        sub.push_back(dir);
      }
    } else {
      DirEntry* next = new(pool) DirEntry(ffdata.cFileName, current);
      entry->SetNext(next);
      entry = next;
    }
  }
  FindClose(*h_find);
  SubDirList::iterator begin = sub.begin(),end = sub.end();
  while (begin != end) {
    WIN32_FIND_DATA ffdata;
    HANDLE h_find;
    std::stringstream st;
    st << current << '/'
       << (*begin).c_str();
    std::string next_dir = st.str();
    st << "/*";
    std::string tmp = st.str();
    h_find = FindFirstFile(tmp.c_str(), &ffdata);
    if (h_find != INVALID_HANDLE_VALUE) {
      DirEntry* next = new(pool) DirEntry(ffdata.cFileName, current);
      entry->SetNext(next);
      entry = Find(&ffdata, &h_find, next, next_dir.c_str(), recursive, pool);
    }
    ++begin;
  }
  return entry;
}


Directory::const_iterator Directory::Entries(bool recursive) {
  WIN32_FIND_DATA ffdata;
  HANDLE h_find;
  std::stringstream st;
  st << dirpath_;
  st << "/*";
  std::string tmp = st.str();
  h_find = FindFirstFile(tmp.c_str(), &ffdata);
  if (h_find == INVALID_HANDLE_VALUE) {
    return const_iterator(0);
  } else {
    DirEntry* entry;
    entry = new(&pool_) DirEntry(ffdata.cFileName, dirpath_);
    Find(&ffdata, &h_find, entry, dirpath_, recursive, &pool_);
    return const_iterator(entry);
  }
}

void Directory::chdir(const char* path) {
  SetCurrentDirectory(path);
}

void Directory::chmod(const char* path, int permiss) {
  _chmod(path,permiss);
}

}}}
