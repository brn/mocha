#include <string.h>
#include <vector>
#include <windows.h>
#include <mocha/roaster/platform/fs/directory-inl.h>
#include <mocha/roaster/platform/fs/stat.h>
namespace mocha {
namespace platform {
namespace fs {
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
      entry = Find(&ffdata, &h_find, next, next_dir.c_str(), is_recursive, is_level, pool);
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
    entry = new(pool_) DirEntry(ffdata.cFileName, dirpath_);
    Find(&ffdata, &h_find, entry, dirpath_, recursive, &pool_);
    return const_iterator(entry);
  }
}
}
}
}
