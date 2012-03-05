#ifndef mocha_platform_win_h_
#define mocha_platform_win_h_
#include <windows.h>
#include <useconfig.h>

#ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
#endif

#ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
#endif

#ifdef HAVE_STRUCT_STAT
#define STAT struct stat
#elif HAVE_STRUCT__STAT
#define STAT struct _stat;
#endif

namespace mocha {
typedef HANDLE Thread_t;
typedef DWORD ThreadAttr_t;
typedef HANDLE Mutex_t;
typedef LPSECURITY_ATTRIBUTES MutexAttr_t;
typedef DWORD ThreadLocalStorageKey_t;
typedef DWORD ThreadLocalStorageOnce_t;
typedef unsigned ThreadId;
}
#endif
