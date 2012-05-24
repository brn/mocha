#ifndef mocha_roaster_fs_event_macos_fsevent_fd_handle_h_
#define mocha_roaster_fs_event_macos_fsevent_fd_handle_h_

namespace mocha {namespace os { namespace fs {

class FSEventHandle {
 public :
  FSEventHandle(const char* path);
  ~FSEventHandle();
  int fd() const {return fd_;}
  void Close();
 private :
  int fd_;
};

}}}

#endif
