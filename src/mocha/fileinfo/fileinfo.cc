#include <string.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/consts/consts.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

FileInfo::FileInfo(const char* filename)
    : info_(new CompilationInfo){}

FileInfo::~FileInfo() {}

void FileInfo::SetInputCharset(const char* charset) {
  input_charset_ = charset;
}

const char* FileInfo::GetInputCharset() const {
  if (input_charset_.empty()) {
    return Consts::kDefaultInputCharset;
  } else {
    return input_charset_.c_str();
  }
}

void FileInfo::SetOutputCharset(const char* charset) {
  output_charset_ = charset;
}

const char* FileInfo::GetOutputCharset() const {
  if (output_charset_.empty()) {
    return Consts::kDefaultOutputCharset;
  } else {
    return output_charset_.c_str();
  }
}

void FileInfo::SetDeploy(const char* name) {
  deploy_ = name;
}

const char* FileInfo::GetDeploy() const {
  if (deploy_.empty()) {
    return 0;
  } else {
    return deploy_.c_str();
  }
}

void FileInfo::SetDeployName(const char* name) {
  deployname_ = name;
}

const char* FileInfo::GetDeployName() const {
  return (deployname_.empty())? 0 : deployname_.c_str();
}

void FileInfo::SetModule(const char* name) {
  modulelist_.push_back(name);
}


const FileInfo::ModuleList& FileInfo::GetModuleList() const {
  return modulelist_;
}

CompilationInfoHandle FileInfo::compilation_info() {
  return info_;
}

void FileInfoMap::UnsafeSet(const char* filename) {
  SharedPtr<FileInfo> handle(new FileInfo(filename));
  resources_.insert(FileInfoPair(filename, handle));
  handle->compilation_info()->SetLibDirectory(Setting::moduledir());
}

void FileInfoMap::SafeSet(const char* filename) {
  os::ScopedLock lock(mutex_);
  UnsafeSet(filename);
}

FileInfo* FileInfoMap::UnsafeGet(const char* filename) {
  FileInfoHandleMap::iterator entry = resources_.find(filename);
  if (entry != resources_.end()) {
    return entry->second.Get();
  }
  return 0;
}

FileInfo* FileInfoMap::SafeGet(const char* filename) {
  os::ScopedLock lock(mutex_);
  FileInfoHandleMap::iterator entry = resources_.find(std::string(filename));
  if (entry != resources_.end()) {
    return entry->second.Get();
  }
  return 0;
}

void FileInfoMap::UnsafeRemove(const char* filename) {
  FileInfoHandleMap::iterator entry = resources_.find(std::string(filename));
  if (entry != resources_.end()) {
    resources_.erase(entry);
  }
}

void FileInfoMap::SafeRemove(const char* filename) {
  os::ScopedLock lock(mutex_);
  UnsafeRemove(filename);
}

void FileInfoMap::Reset() {
  resources_.clear();
}

os::Mutex FileInfoMap::mutex_;
FileInfoMap::FileInfoHandleMap FileInfoMap::resources_;

}
