#include <string.h>
#include <mocha/misc/char_allocator.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/platform/fs/fs.h>

namespace mocha {namespace platform {
namespace fs {
VirtualDirectory* platform::fs::VirtualDirectory::GetInstance() {
  platform::fs::VirtualDirectory* instance = reinterpret_cast<platform::fs::VirtualDirectory*>(platform::ThreadLocalStorage::Get(&local_key_));
  if (instance == NULL) {
    instance = new platform::fs::VirtualDirectory;
    platform::ThreadLocalStorage::Set(&local_key_, instance);
  }
  return instance;
}

void VirtualDirectory::Chdir(const char* path) {
  platform::fs::Path path_info(path);
  current_dir_ = path_info.absolute_path();
}

SharedStr VirtualDirectory::GetCurrentDir() {
  char* ret = new char[ (current_dir_.size() + 1) ];
  strcpy(ret, current_dir_.c_str());
  SharedStr handle(ret);
  return handle;
}

SharedStr VirtualDirectory::GetRealPath(const char* path) {
  std::string tmp = current_dir_;
  tmp += '/';
  tmp += path;
  platform::fs::Path path_info(tmp.c_str());
  char* ret = utils::CharAlloc(path_info.absolute_path());
  return SharedStr(ret);
}

void VirtualDirectory::SetModuleKey(const char* path) {
  module_key_ = path;
}

const char* VirtualDirectory::GetModuleKey() {
  return module_key_.c_str();
}

void VirtualDirectory::Destructor_(void* ptr) {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>(ptr);
  delete instance;
}

platform::ThreadLocalStorageKey VirtualDirectory::local_key_(VirtualDirectory::Destructor_);
platform::Mutex VirtualDirectory::mutex_;
}
}}
