#include <fcntl.h>
#include <unistd.h>
#include <mocha/roaster/platform/fs/event/macos/fs_handle.h>

namespace mocha {namespace os { namespace fs {

FSEventHandle::FSEventHandle(const char* path) {
  fd_ = open(path, O_EVTONLY);
}

FSEventHandle::~FSEventHandle() {close(fd_);}
void FSEventHandle::Close() {
  close(fd_);
}
}}}
