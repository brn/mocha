#ifdef HAVE_PTHREAD
#include "thread-pthread-impl.cc"
#elif HAVE_WINDOWS_H
#include "thread-win-impl.cc"
#endif


