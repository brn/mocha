
#if defined __GNUC__ || HAVE_PTHREAD
#include <mocha/roaster/misc/thread/platform_linux.h>
#elif defined _WIN32
#include <mocha/roaster/misc/thread/platform_win.h>
#endif

