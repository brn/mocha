#include <string.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/consts/consts.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

Resource::Resource(const char* filename) : is_file_(true), info_(new CompilationInfo(filename)){}

Resource::~Resource() {}

void Resource::SetInputCharset(const char* charset) {
  input_charset_ = charset;
}

const char* Resource::GetInputCharset() {
  if (input_charset_.empty()) {
    return Consts::kDefaultInputCharset;
  } else {
    return input_charset_.c_str();
  }
}

void Resource::SetOutputCharset(const char* charset) {
  output_charset_ = charset;
}

const char* Resource::GetOutputCharset() {
  if (output_charset_.empty()) {
    return Consts::kDefaultOutputCharset;
  } else {
    return output_charset_.c_str();
  }
}

void Resource::SetDeploy(const char* name) {
  deploy_ = name;
}

const char* Resource::GetDeploy() {
  if (deploy_.empty()) {
    return 0;
  } else {
    return deploy_.c_str();
  }
}

void Resource::SetDeployName(const char* name) {
  deployname_ = name;
}

SharedStr Resource::GetCmpPath_(const char* path) {
  std::string tmp = path;
  if (!deployname_.empty()) {
    char *ret = new char[ deployname_.size() + 1 ];
    strcpy(ret, deployname_.c_str());
    return SharedStr(ret);
  } else {
    int pos = tmp.find_last_of('.', tmp.size() - 1);
    tmp.replace(pos, 1, "-cmp.");
    char* result = new char[ tmp.size() + 1 ];
    strcpy(result, tmp.c_str());
    return SharedStr(result);
  }
}

SharedStr Resource::GetDeployName(const char* filename) {
  if (deploy_.empty()) {
    return GetCmpPath_(filename);
  } else {
    if (!deployname_.empty()) {
      const char* ret = deploy_.c_str();
      filesystem::mkdir(ret, 0777);
      filesystem::Path path_info(filename);
      char tmp[ 1000 ];
      sprintf(tmp, "%s/%s", ret, GetCmpPath_(path_info.filename()).Get());
      char* result = new char[ strlen(tmp) + 1 ];
      strcpy(result, tmp);
      return SharedStr(result);
    } else {
      return GetCmpPath_(filename);
    }
  }
}

void Resource::SetModule(const char* path) {
  std::string ret = path;
  modulelist_.push_back(ret);
}


const Resource::ModuleList& Resource::GetModuleList() {
  return modulelist_;
}


bool Resource::IsFile() const { return is_file_; }
void Resource::set_file() { is_file_ = true; }

CompilationInfoHandle Resource::compilation_info() {
  return info_;
}

void ExternalResource::UnsafeSet(const char* filename) {
  SharedPtr<Resource> handle(new Resource(filename));
  resources_.insert(ResourcePair(filename, handle));
}

void ExternalResource::SafeSet(const char* filename) {
  MutexLock lock(mutex_);
  SharedPtr<Resource> handle(new Resource(filename));
  resources_.insert(ResourcePair(filename, handle));
}

Resource* ExternalResource::UnsafeGet(const char* filename) {
  ResourceMap::iterator entry = resources_.find(filename);
  if (entry != resources_.end()) {
    return entry->second.Get();
  }
  return 0;
}

Resource* ExternalResource::SafeGet(const char* filename) {
  MutexLock lock(mutex_);
  ResourceMap::iterator entry = resources_.find(filename);
  if (entry != resources_.end()) {
    return entry->second.Get();
  }
  return 0;
}

FileRoot* ExternalResource::SafeGetRuntime(memory::Pool* pool) {
  MutexLock lock(mutex_);
  return Setting::GetInstance()->GetRuntime(pool);
}

Mutex ExternalResource::mutex_;
ExternalResource::ResourceMap ExternalResource::resources_;

}
