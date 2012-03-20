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
#if defined DEBUG
#ifdef __GNUC__
#define ASSERT(expect, result)                  \
  if ((expect) != (result)) {fprintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function %s\n", #result, #expect, __FILE__, __LINE__, __PRETTY_FUNCTION__);abort();}
#elif defined __func__
#define ASSERT(expect, result) if ((expect) != (result)){fprintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function %s\n", #result, #expect, __FILE__, __LINE__, __func__);abort();}
#elif defined __FUNC__
#define ASSERT(expect, result) if ((expect) != (result)){fprintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n in function \n", #result, #expect, __FILE__, __LINE__, __FUNC__);abort();}
#else
#define ASSERT(expect, result) if ((expect) != (result)){fprintf(stderr, "assertion failed -> %s == %s\n in file %s at line %d\n", #result, #expect, __FILE__, __LINE__);abort();}
#endif
#elif defined NDEBUG
#define ASSERT(expect, result)
#endif

#endif
