#include <useconfig.h>
#ifdef HAVE_PTHREAD
#include <mocha/roaster/misc/thread/thread-pthread-impl.h>
#elif HAVE_WINDOWS_H
#include <mocha/roaster/misc/thread/thread-win-impl.h>
#endif


