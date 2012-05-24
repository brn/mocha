#ifndef mocha_roaster_fs_event_win_fs_handle_h_
#define mocha_roaster_fs_event_win_fs_handle_h_
#include <windows.h>
namespace mocha {namespace os { namespace fs {

class FSEventHandle {
 public :
  FSEventHandle(const char* path);
  ~FSEventHandle();
  HANDLE handle() {return handle_;}
  void Close();
 private :
  HANDLE handle_;
};

}}}

#endif
