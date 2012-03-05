#ifdef HAVE_PTHREAD
#include <mocha/misc/thread/thread-pthread-impl.h>
#elif HAVE_WINDOWS_H
#include <mocha/misc/thread/thread-win-impl.h>
#endif


