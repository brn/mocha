#include <pthread.h>
#include <unistd.h>
#include "useconfig.h"

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
typedef pthread_t Thread_t;
typedef pthread_attr_t ThreadAttr_t;
typedef pthread_mutex_t Mutex_t;
typedef pthread_mutexattr_t MutexAttr_t;
typedef pthread_key_t ThreadLocalStorageKey_t;
typedef pthread_once_t ThreadLocalStorageOnce_t;
typedef pthread_t ThreadId;
}

