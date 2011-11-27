#ifdef HAVE_PTHREAD
#include <utils/thread/thread-pthread-impl.cc>
#elif HAVE_WINDOWS_H
#include <utils/thread/thread-win-impl.cc>
#endif


