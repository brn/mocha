#ifndef mocha_roaster_fs_event_fs_event_handle_h_
#define mocha_roaster_fs_event_fs_event_handle_h_
#ifdef PLATFORM_MACOS
#include <mocha/roaster/platform/fs/event/macos/fs_handle.h>
#elif defined PLATFORM_WIN32
#include <mocha/roaster/platform/fs/event/win32/fs_handle.h>
#endif
#endif
