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
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/utime.h>
#include <windows.h>
#include <mocha/roaster/platform/utils/utils.h>
namespace mocha {namespace os {
int VAArgs(const char* format, va_list args) {
  return _vscprintf(format, args) + 1;
}

void Strerror(std::string* buf, int err) {
  char buffer[95];
  if (strerror_s(buffer, err) == 0) {
    buf->assign(buffer);
  } else {
    buf->assign("Strerror error.");
  }
}

void Printf(const char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf_s(format, args);
  va_end(args);
}

void SPrintf(std::string* buf, const char* format, ...) {
  va_list args;
  va_start(args, format);
  int len = VAArgs(format, args);
  char* buffer = static_cast<char*>(malloc(len * sizeof(char)));
  assert(buffer != NULL);
  vsprintf_s(buffer, len, format, args);
  buf->assign(buffer);
  free(buffer);
  va_end(args);
}

void VSPrintf(std::string* buf, const char* format, va_list args) {
  int len = VAArgs(format, args);
  char* buffer = static_cast<char*>(malloc(len * sizeof(char)));
  assert(buffer != NULL);
  vsprintf_s(buffer, len, format, args);
  buf->assign(buffer);
  free(buffer);
}


void VFPrintf(FILE* fp, const char* format, va_list arg) {
  vfprintf_s(fp, format, arg);
}

void FPrintf(FILE* fp, const char* format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf_s(fp, format, args);
  va_end(args);
}

FILE* FOpen(const char* filename, const char* mode) {
  FILE* fp;
  K_ERRNO = fopen_s(&fp, filename, mode);
  if (K_ERRNO != 0) {
    fp = NULL;
  }
  return fp;
}

void FClose(FILE* fp) {
  fclose(fp);
}

void GetEnv(std::string* buf, const char* env) {
  size_t size = 0;
  char buffer[1];
  getenv_s(&size, buffer, 1, env);
  char* tmp = new char[size + 1];
  getenv_s(&size, tmp, size, env);
  buf->assign(tmp);
  delete[] tmp;
}

bool Sleep(int nano_time) {
  ::Sleep(nano_time);
  return true;
}

int Utime(const char* path) {
  K_ERRNO = _utime(path, NULL);
  return K_ERRNO;
}
}}
