#include <mocha/roaster/platform/fs/event/macos/fs_handle.h>

namespace mocha {namespace os { namespace fs {

FSEventHandle::FSEventHandle(const char* path) {
  fd_ = open(path, O_EVTONLY);
}

FSEventHandle::~FSEventHandle() {close(fd_);}

}}}
