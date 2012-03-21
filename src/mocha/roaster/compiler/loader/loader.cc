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
#include <string.h>
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/compiler/loader/loader.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#define BUF_SIZE 128

namespace mocha {
Loader::Loader(){}
Loader::~Loader(){}
void Loader::LoadFile(const char* path) {
  ASSERT(true, strlen(path) > 0);
  os::fs::Stat stat(path);
  if (stat.IsExist() && !stat.IsDir()) {
    FILE* fp = os::FOpen(path, "rb");
    //Check is file exist.
    if (fp != NULL) {
      std::stringstream st;
      ReadNormalFile(fp, &st);
      IOEvent *e = new(&pool_) IOEvent(path, &st);
      NotifyForKey(kComplete, e);
    } else {
      HandleError(path, kFOpenError);
    }
  } else if (stat.IsDir()){
    HandleError(path, kNotAFile);
  } else {
    HandleError(path, kNotFound);
  }
}

void Loader::HandleError(const char* path, int type) {
  std::string buf;
  int error_type = 0;
  ASSERT(true, (type == kFOpenError || type == kNotAFile || type == kNotFound));
  if (type == kFOpenError) {
    error_type = IOEvent::kError;
    os::Strerror(&buf, K_ERRNO);
  } else if (type == kNotAFile) {
    error_type = IOEvent::kNotAFile;
    os::SPrintf(&buf, "%s is a directory.", path);
  } else if (type == kNotFound) {
    error_type = IOEvent::kNotFound;
    os::SPrintf(&buf, "%s No such file.", path);
  }
  IOEvent *e = new(&pool_) IOEvent(path, buf.c_str(), error_type);
  NotifyForKey(kError, e);
}

void Loader::ReadNormalFile(FILE* fp, std::stringstream* st) {
  int read = 0;
  char tmp[128];
  while ((read = fread(tmp, sizeof(char), 127, fp))) {
    tmp[(BUF_SIZE - 1)] = '\0';
    (*st) << tmp;
    if (read < (BUF_SIZE - 1)) {
      break;
    }
    tmp[0] = '\0';
  }
}

const char Loader::kComplete[] = {"Loader<Complete>"};
const char Loader::kError[] = {"Loader<Error>"};

}
