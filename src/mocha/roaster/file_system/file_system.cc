#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/file_system/file_io.h>
#include <useconfig.h>
#include <mocha/roaster/file_system/stat.h>
#include <mocha/roaster/file_system/mkdir.h>
#include <mocha/misc/char_allocator.h>

#ifdef _WIN32
#define HOME "HOMEPATH"
#ifdef HAVE_IO_H
#include <io.h>
#endif
#define CHMOD(name,permiss) _chmod(name,permiss)
#define CHDIR(name,permiss) _chdir(name,permiss)
#else
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

#ifdef HAVE_REALPATH
#define FULL_PATH(path, tmp) tmp = realpath(path, NULL)
#elif HAVE__FULLPATH
#define FULL_PATH(path, tmp) tmp = _fullpath(NULL, path, 0)
#endif

namespace mocha {
namespace filesystem {
void GetDirectoryFromPath(const char* path, std::string* buffer) {
  int index = strlen(path);
  std::string tmp = path;
  bool is_slashed = false;
  while (index--) {
    if (is_slashed) {
      break;
    }
    if (path[ index ] == '/') {
      is_slashed = true;
    }
  }
  tmp.erase(index + 1, tmp.size());
  buffer->assign(tmp.c_str());
}

void GetFileNameFromPath(const char* path, std::string* buffer) {
  std::string tmp;
  int len = strlen(path);
  if (path[len - 1] == '/') {
    return;
  }
  const char* ptr = strrchr(path, '/');
  if (ptr) {
    tmp = (ptr + 1);
  } else {
    tmp = path;
  }
  buffer->assign(tmp.c_str());
}

void ConvertBackSlash(const char* path, std::string* buffer) {
  std::string tmp = path;
  //buffer->assign(path);
  size_t index = 0;
  while ((index = tmp.find("\\", 0)) != std::string::npos) {
    tmp = tmp.replace(index, 1, "/");
  }
  buffer->assign(tmp.c_str());
}

void GetAbsolutePath(const char* path, std::string* buffer) {
  char *tmp;
  FULL_PATH(path, tmp);
  if (tmp != NULL) {
    ConvertBackSlash(tmp, buffer);
  } else {
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
  NormalizePath(path, &fullpath_);
  GetAbsolutePath(absolute_path(), &fullpath_);
  GetDirectoryFromPath(absolute_path(), &directory_);
  GetFileNameFromPath(absolute_path(), &filename_);
}
  
const char* Path::current_directory() {
  MutexLock lock(mutex_);
  current_dir_.clear();
#define GW_BUF_SIZE 1000
#ifdef HAVE_WINDOWS_H
    char tmp[GW_BUF_SIZE];
    DWORD isSuccess = GetCurrentDirectory(sizeof(tmp), tmp);
    if (!isSuccess) {
      fprintf(stderr, "GetCwd fail.");
    }
    ConvertBackSlash(tmp, &current_dir_);
#else
    char tmp[ GW_BUF_SIZE ];
    char* dir = getcwd(tmp, sizeof (tmp));
    if (!dir) {
      fprintf(stderr, "GetCwd fail.");
    };
    current_dir_ = dir;
#endif
    return current_dir_.c_str();
}


const char* Path::home_directory() {
  MutexLock lock(mutex_);
#ifdef _WIN32
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
#else
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

SharedStr GetModuleKey(const char* base, const char* path) {
  if (strcmp(base, path) == 0) {
    return SharedStr(utils::CharAlloc("./"));
  }
  PathArray base_array;
  PathArray target_array;
  GetPathArray(base, &base_array);
  GetPathArray(path, &target_array);
  std::string result;
  int i = 0;
  int base_size = base_array.size();
  int target_size = target_array.size();
  while ((i < base_size) || (i < target_size)) {
    if (i >= base_size) {
      result += target_array.at(i);
    } else if (i >= target_size) {
      std::string tmp;
      while (i < base_size) {
        tmp += "../";
        i++;
      }
      tmp += result;
      return SharedStr(utils::CharAlloc(tmp.c_str()));
    } else if (base_array.at(i).compare(target_array.at(i)) != 0) {
      while (i < base_size) {
        result += "../";
        base_array.pop_back();
        base_size = base_array.size();
      }
      while (i < target_size) {
        result += target_array[ i ];
        result += "/";
        i++;
      }
      return SharedStr(utils::CharAlloc(result.c_str()));
    }
    i++;
  }
  return SharedStr(utils::CharAlloc(result.c_str()));
}

void chdir (const char* path) {
#ifdef _WIN32
  SetCurrentDirectory(path);
#else
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

Mutex Path::mutex_;
}
}
#undef HOME
