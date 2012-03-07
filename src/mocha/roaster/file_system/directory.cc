#include <string.h>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <dirent.h>
#endif

#include <mocha/roaster/file_system/directory.h>
#include <mocha/roaster/file_system/stat.h>

namespace mocha {
namespace filesystem {
DirectoryIterator::DirectoryIterator(const DirEntry* entry) : entry_(entry){}
DirectoryIterator::~DirectoryIterator() {}

DirectoryIterator::DirectoryIterator(const DirectoryIterator& iterator) {
  entry_ = iterator.entry_;
}

const DirectoryIterator& DirectoryIterator::operator = (const DirectoryIterator& iterator) {
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

Directory::Directory(const char* path) : dirpath_(path){};
Directory::~Directory(){}

#ifdef _WIN32

DirEntry* Find(WIN32_FIND_DATA* ffdata_,
                HANDLE *h_find, DirEntry* entry,
                const char* current,
                bool is_recursive,
                bool is_level,
                ScopedList<DirEntry> *scoped_list) {
  typedef std::vector<std::string> SubDirList;
  SubDirList sub;
  WIN32_FIND_DATA ffdata;
  while (FindNextFile(*h_find, &ffdata)) {
    if (h_find == INVALID_HANDLE_VALUE) {
      break;
    }
    if (!is_level && (strcmp(ffdata.cFileName, ".") == 0 || strcmp(ffdata.cFileName, "..") == 0)) {
      continue;
    }
    if (ffdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      if (is_recursive) {
        std::string dir = ffdata.cFileName;
        sub.push_back(dir);
      }
    } else {
      DirEntry* next = scoped_list->Retain(new DirEntry(ffdata.cFileName, current));
      entry->SetNext(next);
      entry = next;
    }
  }
  FindClose(*h_find);
  SubDirList::iterator begin = sub.begin(),end = sub.end();
  while (begin != end) {
    WIN32_FIND_DATA ffdata;
    HANDLE h_find;
	std::string tmp = current;
	tmp += '/';
	tmp += (*begin).c_str();
	std::string next_dir = tmp.c_str();
	tmp += "/*";
    h_find = FindFirstFile(tmp.c_str(), &ffdata);
    if (h_find != INVALID_HANDLE_VALUE) {
      DirEntry* next = scoped_list->Retain(new DirEntry(ffdata.cFileName, current));
      entry->SetNext(next);
      entry = Find(&ffdata, &h_find, next, next_dir.c_str(), is_recursive, is_level, scoped_list);
    }
    ++begin;
  }
  return entry;
}


DirectoryIterator Directory::GetFileList(bool is_recursive, bool show_level) {
  WIN32_FIND_DATA ffdata;
  HANDLE h_find;
  std::string tmp = dirpath_;
  tmp += "/*";
  h_find = FindFirstFile(tmp.c_str(), &ffdata);
  if (h_find == INVALID_HANDLE_VALUE) {
    return DirectoryIterator(0);
  } else {
    DirEntry* entry;
    entry = scoped_entry_.Retain(new DirEntry(ffdata.cFileName, dirpath_));
    Find(&ffdata, &h_find, entry, dirpath_, is_recursive, show_level, &scoped_entry_);
    return DirectoryIterator(entry);
  }
}

#else

class DirFinder {
  typedef std::vector<std::string> SubDirList;
 public :
  DirFinder(const char* path, bool is_recursive, bool show_level, DIR* dir, ScopedList<DirEntry> *scoped_list) :
      path_(path), is_recursive_(is_recursive), show_level_(show_level),
      dir_(dir), first_(0), current_(0), scoped_list_(scoped_list){};
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
      if (!show_level_ && (result_->d_name[0] == '.' || strcmp(result_->d_name, "..") == 0)) {
        continue;
      }
      std::string fullpath = path_;
      fullpath += "/";
      fullpath += result_->d_name;
      Stat stat(fullpath.c_str());
      if (stat.IsDir()) {
        if (is_recursive_) {
          sub.push_back(fullpath);
        }
      } else {
        DirEntry* entry = scoped_list_->Retain(new DirEntry(result_->d_name, path_));
        if (first_ == 0) {
          first_ = entry;
        } else {
          current_->SetNext(entry);
        }
        current_ = entry;
      }
    }
    closedir(dir_);
    FindSubDir_(sub);
    return current_;
  }
  
 private :
  void FindSubDir_(const SubDirList& sub) {
    SubDirList::const_iterator begin = sub.begin(),end = sub.end();
    while (begin != end) {
      const char* path = (*begin).c_str();
      DIR* dir = opendir(path);
      if (dir == NULL) {
        continue;
      } else {
        DirFinder finder(path, is_recursive_, show_level_, dir, scoped_list_);
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
  bool is_recursive_;
  bool show_level_;
  DIR* dir_;
  dirent entry_;
  dirent *result_;
  DirEntry* first_;
  DirEntry* current_;
  ScopedList<DirEntry> *scoped_list_;
};

DirectoryIterator Directory::GetFileList(bool is_recursive, bool show_level) {
  DIR* dir = opendir(dirpath_);
  if (dir == NULL) {
    return DirectoryIterator(0);
  }
  DirFinder finder(dirpath_, is_recursive, show_level, dir, &scoped_entry_);
  finder.Find();
  return DirectoryIterator(finder.GetFirst());
}
#endif

}
}

