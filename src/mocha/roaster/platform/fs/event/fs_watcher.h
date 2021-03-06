#ifndef mocha_roaster_fs_event_macos_fsevent_fs_watcher_h_
#define mocha_roaster_fs_event_macos_fsevent_fs_watcher_h_
#ifdef PLATFORM_MACOS
#include <mocha/roaster/platform/fs/event/macos/fs_watcher_macos.h>
#elif defined PLATFORM_WIN32
#include <mocha/roaster/platform/fs/event/win32/fs_watcher_win32.h>
#elif defined PLATFORM_POSIX
#include <mocha/roaster/platform/fs/event/linux/fs_watcher_linux.h>
#endif
#endif
