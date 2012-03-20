/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
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
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <mocha/roaster/platform/utils/utils.h>
namespace mocha {namespace platform {

int VSNPrintf(char* buffer, int size, const char* format, va_list args) {
  return vsnprintf(buffer, size, format, args);
}

int VSNPrintf(wchar_t* buffer, int size, const wchar_t* format, va_list args) {
  return vswprintf(buffer, size, format, args);
}

template <typename T>
T* AllocBuffer(const T* format, va_list args) {
  int n;
  int size = 100;     /* Guess we need no more than 100 bytes. */
  T *buffer;
  T *np;
  buffer = static_cast<T*>(malloc(size));
  assert(buffer != NULL);
  while (1) {
    /* Try to print in the allocated space. */
    n = VSNPrintf(buffer, size, format, args);
    /* If that worked, return the string. */
    if (n > -1 && n < size) {
      return buffer;
    }
    /* Else try again with more space. */
    if (n > -1) {
      size = n+1;
    } else {
      size *= 2;
    }
    if ((np = static_cast<T*>(realloc(buffer, size))) == NULL) {
      free(buffer);
      assert(false);
    } else {
      buffer = np;
    }
  }
}

void Strerror(std::string* buf, int err) {
  char buffer[95];
  strerror_r(err, buffer, 95);
  buf->assign(buffer);
}

void Printf(const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* buffer = AllocBuffer<char>(format, args);
  if (buffer != NULL) {
    fprintf(stdout, "%s", buffer);
    free(buffer);
  }
  va_end(args);
}

void WPrintf(const wchar_t* format, ...) {
  va_list args;
  va_start(args, format);
  wchar_t* buffer = AllocBuffer<wchar_t>(format, args);
  if (buffer != NULL) {
    fwprintf(stdout, L"%s", buffer);
    free(buffer);
  }
  va_end(args);
}

void SPrintf(std::string* buf, const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* buffer = AllocBuffer<char>(format, args);
  if (buffer != NULL) {
    buf->assign(buffer);
    free(buffer);
  }
  va_end(args);
}

FILE* FOpen(const char* filename, const char* mode) {
  FILE* fp = fopen(filename, mode);
  return fp;
}

void FClose(FILE* fp) {
  fclose(fp);
}
}}
