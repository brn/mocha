#ifdef HAVE_PTHREAD
#include <mocha/misc/thread/thread-pthread-impl.cc>
#elif HAVE_WINDOWS_H
#include <mocha/misc/thread/thread-win-impl.cc>
#endif


