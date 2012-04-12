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
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/directory/directory-inl.h>
namespace mocha {namespace os {namespace fs {
Directory::Directory(const char* path) : dirpath_(path){};
Directory::~Directory(){}
typedef std::vector<std::string> SubDirList;
DirEntry* Get(WIN32_FIND_DATA* ffdata, SubDirList *sub, const char* current, memory::Pool* pool, bool recursive) {
  bool is_dir = false;
  if (ffdata->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
    if (recursive) {
      std::string dir = ffdata->cFileName;
      sub->push_back(dir);
    }
    is_dir = true;
  }
  return new(pool) DirEntry(ffdata->cFileName, current, is_dir);
}

DirEntry* Find(DirEntry* entry,
               const char* current,
               bool recursive,
               memory::Pool *pool) {
  bool initial = entry == 0;
  DirEntry* first = entry;
  SubDirList sub;
  WIN32_FIND_DATA ffdata;
  HANDLE h_find;
  std::string buf;
  os::SPrintf(&buf, "%s/*", current);
  h_find = FindFirstFile(buf.c_str(), &ffdata);
  if (h_find == INVALID_HANDLE_VALUE) {
    FATAL("fail FindFirstFile.");
  }
  if (strcmp(ffdata.cFileName, ".") != 0 && strcmp(ffdata.cFileName, "..") != 0) {
    DirEntry* ent = Get(&ffdata, &sub, current, pool, recursive);
    if (entry != 0) {
      entry->SetNext(ent);
    }
    entry = ent;
  }
  while (FindNextFile(h_find, &ffdata)) {
    if (h_find == INVALID_HANDLE_VALUE) {
      break;
    }
    if (strcmp(ffdata.cFileName, ".") == 0 || strcmp(ffdata.cFileName, "..") == 0) {
      continue;
    }
    DirEntry* ent = Get(&ffdata, &sub, current, pool, recursive);
    if (entry != 0) {
      entry->SetNext(ent);
    } else {
      first = ent;
    }
    entry = ent;
  }
  FindClose(h_find);
  SubDirList::iterator begin = sub.begin(),end = sub.end();
  while (begin != end) {
    std::string next_dir;
    os::SPrintf(&next_dir, "%s/%s", current, begin->c_str());
    DirEntry* tmp = Find(entry, next_dir.c_str(), recursive, pool);
	if (tmp != 0 && tmp != entry) {
       entry = tmp;
	}
    ++begin;
  }
  return (initial)? first : entry;
}


Directory::const_iterator Directory::Entries(bool recursive) {
  DirEntry* entry = Find(0, dirpath_.c_str(), recursive, &pool_);
  return const_iterator(entry);
}

void Directory::chdir(const char* path) {
  SetCurrentDirectory(path);
}

void Directory::chmod(const char* path, int permiss) {
  _chmod(path,permiss);
}

}}}
