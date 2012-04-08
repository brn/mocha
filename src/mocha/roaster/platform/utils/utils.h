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
#ifndef mocha_platfrom_utils_utils_h_
#define mocha_platfrom_utils_utils_h_
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <errno.h>
#ifdef PLATFORM_POSIX
#define K_ERRNO errno
#elif defined PLATFORM_WIN32
#define K_ERRNO _doserrno
#endif
namespace mocha {namespace os {
void Strerror(std::string* buf, int err);
void Printf(const char* format, ...);
void SPrintf(std::string*, const char* format, ...);
void VSPrintf(std::string* buf, const char* format, va_list args);
void VFPrintf(FILE* fp, const char* format, ...);
void FPrintf(FILE* fp, const char* format, ...);
FILE* FOpen(const char* filename, const char* mode);
void FClose(FILE* fp);
void GetEnv(std::string *buf, const char* env);
bool Sleep(int nano_time);
int Utime(const char* path);
time_t Time(time_t* time);
int Asctime(std::string* buf, tm* tm);
int LocalTime(tm* t, time_t* time);
void OnExit(void(*callback)());
void GetLastError(std::string* buf);
FILE* POpen(const char* name, const char* mode);
void PClose(FILE* fp);
}}

#endif
