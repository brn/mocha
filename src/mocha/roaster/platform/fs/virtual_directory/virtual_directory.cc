#include <string.h>
#include <mocha/misc/char_allocator.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/platform/fs/fs.h>

namespace mocha {namespace os {
namespace fs {
VirtualDirectory* os::fs::VirtualDirectory::GetInstance() {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>(ThreadLocalStorage::Get(&local_key_));
  if (instance == NULL) {
    instance = new VirtualDirectory;
    os::ThreadLocalStorage::Set(&local_key_, instance);
  }
  return instance;
}

void VirtualDirectory::Chdir(const char* path) {
  Path path_info(path);
  current_dir_ = path_info.absolute_path();
}

SharedStr VirtualDirectory::GetCurrentDir() {
  return current_dir_.c_str());
}

void VirtualDirectory::Destructor(void* ptr) {
  VirtualDirectory* instance = reinterpret_cast<VirtualDirectory*>(ptr);
  delete instance;
}

ThreadLocalStorageKey VirtualDirectory::local_key_(VirtualDirectory::Destructor);
Mutex VirtualDirectory::mutex_;
}
}}
