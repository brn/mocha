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
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#ifdef PLATFORM_WIN32
#include <windows.h>
#elif defined PLATFORM_POSIX
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#endif
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

#ifdef PLATFORM_WIN32
#define HOME "HOMEPATH"
#elif defined PLATFORM_POSIX
#define HOME "HOME"
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 10000
#else
#undef MAXPATHLEN
#define MAXPATHLEN 10000
#endif

#ifdef PLATFORM_POSIX
#define FULL_PATH(path, tmp) tmp = realpath(path, NULL)
#elif defined PLATFORM_WIN32
#define FULL_PATH(path, tmp) tmp = _fullpath(NULL, path, 0)
#endif

namespace mocha {namespace os {namespace fs {
void GetDirectoryFromPath(const char* path, std::string* buffer) {
  int index = strlen(path);
  bool is_slashed = false;
  buffer->assign(path);
  while (index--) {
    if (is_slashed) {
      break;
    }
    if (path[ index ] == '/') {
      is_slashed = true;
    }
  }
  buffer->erase(index + 1, buffer->size());
}

void GetFileNameFromPath(const char* path, std::string* buffer) {
  int len = strlen(path);
  if (path[len - 1] == '/') {
    return;
  }
  const char* ptr = strrchr(path, '/');
  if (ptr) {
    buffer->assign((ptr + 1));
  } else {
    buffer->assign(path);
  }
}

void ConvertBackSlash(const char* path, std::string* buffer) {
  buffer->assign(path);
  size_t index = 0;
  while ((index = buffer->find("\\", 0)) != std::string::npos) {
    buffer->assign(buffer->replace(index, 1, "/"));
  }
}

void GetAbsolutePath(const char* path, std::string* buffer, bool* is_success = 0) {
  if (strcmp(path, "/") == 0) {
    buffer->assign(path);
    return;
  }
  char *tmp;
  FULL_PATH(path, tmp);
  if (tmp != NULL) {
    ConvertBackSlash(tmp, buffer);
    free(tmp);
  } else {
    if (is_success) {
      (*is_success) = false;
    }
    buffer->assign(path);
  }
}

void Path::NormalizePath(const char* path, std::string* buffer) {
  int size = strlen(path);
  ConvertBackSlash(path, buffer);
  while (1) {
    size_t pos = buffer->find("../", 0);
    if (pos == std::string::npos) {
      size_t pos = buffer->find("./", 0);
      if (pos != std::string::npos) {
        buffer->erase(pos, 2);
      } else {
        size_t pos = buffer->find("//", 0);
        if (pos != std::string::npos) {
          buffer->erase(pos, 1);
        } else {
          break;
        }
      }
    } else if (pos){
      int count = 0;
      int matched = 0;
      int spos = pos;
      int ssize = size;
      bool has_ch = false;
      while (spos < ssize && spos > -1) {
        if (buffer->at(spos) == '/') {
          if (matched == 1 && has_ch) {
            break;
          }
          matched = 1;
        }
        if (buffer->at(spos) != '.' && buffer->at(spos) != '/') {
          has_ch = true;
        }
        spos--;
        count++;
      }
      if (spos < 0) {
        spos = 0;
      }
      buffer->erase(spos, count + 2);
    }
  }
  if (buffer->at(buffer->size() - 1) == '/') {
    buffer->erase(buffer->size() - 1, buffer->size());
  }
}

Path::Path(const char* path) {
  raw_ = path;
  bool success = true;
  fullpath_ = path;
  GetAbsolutePath(absolute_path(), &fullpath_, &success);
  if (fullpath_.size() > 0 && fullpath_.size() > 1 && fullpath_.at(fullpath_.size() - 1) == '/') {
    fullpath_.erase(fullpath_.size() - 1, 1);
  }
  if (success) {
    Stat stat(fullpath_.c_str());
    if (!stat.IsDir()) {
      GetDirectoryFromPath(absolute_path(), &directory_);
      GetFileNameFromPath(absolute_path(), &filename_);
    } else {
      directory_ = fullpath_;
      filename_ = "";
    }
  } else {
    directory_ = path;
    filename_ = path;
  }
}
  
const char* Path::current_directory() {
  os::ScopedLock lock(mutex_);
  current_dir_.clear();
#define GW_BUF_SIZE 1000
#ifdef PLATFORM_WIN32
    char tmp[GW_BUF_SIZE];
    DWORD isSuccess = GetCurrentDirectory(sizeof(tmp), tmp);
    if (!isSuccess) {
      fprintf(stderr, "GetCwd fail.");
    }
    ConvertBackSlash(tmp, &current_dir_);
#elif defined PLATFORM_POSIX
    char tmp[GW_BUF_SIZE];
    char* dir = getcwd(tmp, sizeof (tmp));
    if (!dir) {
      fprintf(stderr, "GetCwd fail.");
    };
    current_dir_ = dir;
#endif
    return current_dir_.c_str();
}


const char* Path::home_directory() {
  os::ScopedLock lock(mutex_);
#ifdef PLATFORM_WIN32
  const char* drive = getenv("HOMEDRIVE");
  const char* home = getenv(HOME);
  if (home && drive) {
    user_home_ = drive;
    user_home_ += '/';
    user_home_ += home;
    GetAbsolutePath(user_home_.c_str(), &user_home_);
    return user_home_.c_str();
  }
  return 0;
#elif defined PLATFORM_POSIX
  const char* home = getenv(HOME);
  if (home) {
    user_home_ = home;
    user_home_.c_str();
    return user_home_.c_str();
  }
  return 0;
#endif
}

std::string Path::current_dir_;
std::string Path::user_home_;
typedef std::vector<std::string> PathArray;

void GetPathArray(const char* path, PathArray *array) {
  int len = strlen(path);
  std::string tmp = path;
  std::string slash = "/";
  std::string str;
  if (path[ len - 1 ] != '/') {
    tmp += '/';
  }
  const char* raw = tmp.c_str();
  int i = 0;
  while (raw[ i ]) {
    if (raw[ i ] == '/') {
      if (i == 0) {
        array->push_back(slash);
      } else {
        array->push_back(str);
      }
      str.clear();
    } else {
      str += raw[i];
    }
    i++;
  }
}

const char* fs::Path::relative_path(const char* base, const char* path, std::string* buf) {
  if (strcmp(base, path) == 0) {
    return base;
  }
  PathArray base_array;
  PathArray target_array;
  GetPathArray(base, &base_array);
  GetPathArray(path, &target_array);
  int i = 0;
  int base_size = base_array.size();
  int target_size = target_array.size();
  while ((i < base_size) || (i < target_size)) {
    if (i >= base_size) {
      buf->append(target_array.at(i));
      buf->append("/");
    } else if (i >= target_size) {
      std::stringstream st;
      while (i < base_size) {
        st << "../";
        i++;
      }
      buf->append(st.str());
    } else if (base_array.at(i).compare(target_array.at(i)) != 0) {
      std::stringstream st;
      while (i < base_size) {
        st << "../";
        base_array.pop_back();
        base_size = base_array.size();
      }
      while (i < target_size) {
        st << target_array[ i ];
        st << "/";
        i++;
      }
      buf->append(st.str());
    }
    i++;
  }
  if (buf->size() > 1 && buf->at(buf->size() - 1) == '/') {
    buf->erase(buf->size() - 1, 1);
  }
  return buf->c_str();
}

os::Mutex Path::mutex_;
}}}

