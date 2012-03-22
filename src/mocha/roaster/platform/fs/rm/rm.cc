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
#include <stdio.h>
#include <mocha/roaster/platform/fs/rm/rm.h>
#include <mocha/roaster/platform/fs/directory/directory.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
namespace mocha { namespace os{ namespace fs {

bool RemoveDir(const char* path) {
  Directory dir(path);
  Directory::const_iterator it = dir.Entries(true);
  while (it != dir.end()) {
    bool ret = (::remove((*it)->GetFullPath()) != -1);
    if (!ret) {
      return ret;
    }
  }
  return ::remove(path);
}

bool rm(const char* path) {
  Stat stat(path);
  if (stat.IsExist()) {
    if (stat.IsDir()) {
      return RemoveDir(path);
    }
    return (::remove(path) != -1);
  } else {
    return false;
  }
}
}}}
