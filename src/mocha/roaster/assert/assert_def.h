/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

#ifndef mocha_roaster_assert_assert_h_
#define mocha_roaster_assert_assert_h_
#include <stdio.h>
#include <stdlib.h>
#include <mocha/roaster/platform/utils/utils.h>
#if defined DEBUG
#if defined __GNUC__

#define ASSERT(expect, result)                                          \
  if ((expect) != (result)) {os::FPrintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function %s\n", #result, #expect, __FILE__, __LINE__, __PRETTY_FUNCTION__);abort();}
#define FATAL(msg) os::FPrintf(stderr, "Fatal error occured, so process no longer exist.\nin file %s at line %d\n in function %s\n%s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, msg);abort();

#elif defined __func__

#define ASSERT(expect, result) if ((expect) != (result)){os::FPrintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function %s\n", #result, #expect, __FILE__, __LINE__, __func__);abort();}
#define FATAL(msg) os::FPrintf(stderr, "Fatal error occured, so process no longer exist.\nin file %s at line %d\n in function %s\n%s\n", __FILE__, __LINE__, __func__, msg);abort();

#elif defined __FUNC__

#define ASSERT(expect, result) if ((expect) != (result)){os::FPrintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function \n", #result, #expect, __FILE__, __LINE__, __FUNC__);abort();}
#define FATAL(msg) os::FPrintf(stderr, "Fatal error occured, so process no longer exist.\nin file %s at line %d\n in function %s\n%s\n", __FILE__, __LINE__, __FUNC__, msg);abort();

#else
#define ASSERT(expect, result) if ((expect) != (result)){os::FPrintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n", #result, #expect, __FILE__, __LINE__);abort();}
#define FATAL(msg) os::FPrintf(stderr, "Fatal error occured, so process no longer exist.\nin file %s at line %d\n%s\n", __FILE__, __LINE__, msg);abort();
#endif

#elif defined NDEBUG
#define ASSERT(expect, result)
#define FATAL(msg)
#endif

#endif
