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
#include <mocha/roaster/ast/seriarization/unpacker.h>
#include <mocha/roaster/ast/seriarization/byte.h>
#ifndef PACKING_RUNTIME
#include <mocha/roaster/nexc/runtime/runtime.h>
#endif
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/nexc/loader/loader.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/nexc/nexc.h>
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
      os::FClose(fp);
      IOEvent *e = new(&pool_) IOEvent(path, &st);
      NotifyForKey(kComplete, e);
    } else {
      os::FClose(fp);
      HandleError(path, kFOpenError);
    }
  } else if (stat.IsDir()){
    HandleError(path, kNotAFile);
  } else {
    HandleError(path, kNotFound);
  }
}

bool Loader::LoadFile(const char* path, std::string* buf) {
  ASSERT(true, strlen(path) > 0);
  os::fs::Stat stat(path);
  if (stat.IsExist() && !stat.IsDir()) {
    FILE* fp = os::FOpen(path, "rb");
    //Check is file exist.
    if (fp != NULL) {
      std::stringstream st;
      ReadNormalFile(fp, &st);
      os::FClose(fp);
      buf->assign(st.str());
      return true;
    } else {
      os::FClose(fp);
      GetError(kFOpenError, path, buf);
    }
  } else if (stat.IsDir()){
    GetError(kNotAFile, path, buf);
  } else {
    GetError(kNotFound, path, buf);
  }
  return false;
}

bool Loader::IsRuntime(const char* path) {
#ifndef PACKING_RUNTIME
  return (strcmp(path, "runtime") == 0)? false : JSRuntime::Has(path);
#else
  return strcmp(path, "runtime") == 0;
#endif
}

int Loader::GetError(int type, const char* path, std::string* buf) {
  int error_type = 0;
  ASSERT(true, (type == kFOpenError || type == kNotAFile || type == kNotFound));
  if (type == kFOpenError) {
    error_type = IOEvent::kError;
    os::Strerror(buf, K_ERRNO);
  } else if (type == kNotAFile) {
    error_type = IOEvent::kNotAFile;
    os::SPrintf(buf, "%s is a directory.", path);
  } else if (type == kNotFound) {
    error_type = IOEvent::kNotFound;
    os::SPrintf(buf, "%s No such file.", path);
  }
  return error_type;
}

void Loader::HandleError(const char* path, int type) {
  std::string buf;
  int error_type = GetError(type, path, &buf);
  IOEvent *e = new(&pool_) IOEvent(path, buf.c_str(), error_type);
  NotifyForKey(kError, e);
}

void Loader::ReadNormalFile(FILE* fp, std::stringstream* st) {
  int read = 0;
  char tmp[128];
  while ((read = fread(tmp, sizeof(char), 127, fp))) {
    tmp[read] = '\0';
    (*st) << tmp;
    if (read < (BUF_SIZE - 1)) {
      break;
    }
    tmp[0] = '\0';
  }
}

void Loader::Initialize() {
#ifndef PACKING_RUNTIME
  JSRuntime::Initialize();
#endif
}

void Include(Nexc* nexc, const Included& include, CompilationEvent* e) {
  for (Included::const_iterator it = include.begin(); it != include.end(); ++it) {
    std::string mod_key;
    std::string filename_buf;
    nexc->ImportFile(&mod_key, &filename_buf, it->c_str(), e);
  }
}

AstNode* Loader::GetRuntime(const char* name, memory::Pool* pool, Nexc* nexc, CompilationEvent* e) {
#ifndef PACKING_RUNTIME
  DEBUG_LOG(Info, "Load runtime : %s", name);
  std::pair<int32_t*, int> packed = JSRuntime::Get(name);
  ByteOrder b_order(true);
  UnPacker unpacker(packed.first, packed.second, &b_order, pool);
  AstNode* ret = unpacker.Unpack();
  if (unpacker.HasInclude()) {
    Include(nexc, unpacker.included(), e);
  }
  return ret;
#else
  return 0;
#endif
}

const char Loader::kComplete[] = {"Loader<Complete>"};
const char Loader::kError[] = {"Loader<Error>"};

}
