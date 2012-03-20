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
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/mkdir.h>

#ifdef PLATFORM_WIN32
#define HOME "HOMEPATH"
#include <io.h>
#define CHMOD(name,permiss) _chmod(name,permiss)
#define CHDIR(name,permiss) _chdir(name,permiss)
#elif defined PLATFORM_POSIX
#define HOME "HOME"
#define CHMOD(name,permiss) ::chmod(name,permiss)
#define CHDIR(name) ::chdir(name)
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

namespace mocha {
namespace platform {
namespace fs {
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
  char *tmp;
  FULL_PATH(path, tmp);
  if (tmp != NULL) {
    ConvertBackSlash(tmp, buffer);
  } else {
    if (is_success) {
      (*is_success) = false;
    }
    buffer->assign(path);
  }
  free(tmp);
}

void NormalizePath(const char* path, std::string* buffer) {
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
    } else {
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
  NormalizePath(path, &fullpath_);
  GetAbsolutePath(absolute_path(), &fullpath_, &success);
  if (success) {
    GetDirectoryFromPath(absolute_path(), &directory_);
    GetFileNameFromPath(absolute_path(), &filename_);
  } else {
    directory_ = path;
    filename_ = path;
  }
}
  
const char* Path::current_directory() {
  platform::ScopedLock lock(mutex_);
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
  platform::ScopedLock lock(mutex_);
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
    } else if (i >= target_size) {
      std::stringstream st;
      while (i < base_size) {
        st << "../";
        i++;
      }
      std::string ret = st.str();
      buf->append(ret);
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
      std::string ret = st.str();
      buf->append(ret);
    }
    i++;
  }
  buf->c_str();
}


void chdir (const char* path) {
#ifdef PLATFORM_WIN32
  SetCurrentDirectory(path);
#elif defined PLATFORM_POSIX
  CHDIR(path);
#endif
}

bool chmod(const char* path, int permiss) {
  if (FileIO::IsExist(path)) {
    CHMOD(path, permiss);
    return true;
  }
  return false;
}

platform::Mutex Path::mutex_;
}
}}
#undef HOME
