#ifndef mocha_test_run_h_
#define mocha_test_run_h_
#include <string.h>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/utils/compilation_result.h>
#include <mocha/bootstrap/runners/phantom_runner.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/directory.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/misc/file_writer.h>
namespace mocha {namespace compiler_test {

void RunJS(const char* dir);
class TestCallback : public FileWriter{
 public :
  TestCallback(int size) :
      size_(size), is_end_(false), current_(0) {}
  ~TestCallback(){}
  void operator() (CompilationResultHandle result) {
    platform::ScopedLock lock(mutex_);
    WriteResult(result);
    if (Atomic::Increment(&current_) == size_) {
      is_end_ = true;
    }
    const ErrorMap *map = &(result->error_map());
    if (map->size() > 0) {
      ErrorMap::const_iterator iterator;
      for (iterator = map->begin(); iterator != map->end(); ++iterator) {
        std::string buf;
        iterator->second->SetRawError(&buf);
        if (buf.size() > 0) {
          errors_ += "---error---filename => ";
          errors_ += iterator->first.c_str();
          errors_ += "---\n";
          errors_ += buf.c_str();
          errors_ += "-------------------------------------------------------------------\n\n";
        }
      }
    }
  }
  bool IsEnd() { return is_end_; }
  void PrintError() {
    if (errors_.size() > 0) {
      fprintf(stderr, "%s\n", errors_.c_str());
    }
  }
 private :
  static platform::Mutex mutex_;
  int size_;
  bool is_end_;
  std::string errors_;
  AtomicWord current_;
};

platform::Mutex TestCallback::mutex_;

std::string GetPath(const char* path) {
  platform::fs::Path fs_path(Bootstrap::GetSelfPath());
  std::string result = fs_path.directory();
  result += '/';
  result += path;
  return result;
}

void* ThreadRunner(void* args) {
  const char* path = reinterpret_cast<std::string*>(args)->c_str();
  PhantomRunner::Run(path);
  return 0;
}

void RunJS(const char* dir) {
  platform::fs::Directory directory(dir);
  platform::fs::Directory::const_iterator iterator = directory.Entries(true);
  std::string args;
  while (iterator != directory.end()) {
    const platform::fs::DirEntry* entry = *iterator;
    const char* fullpath = entry->GetFullPath();
    if (strstr(fullpath, "-cmp.js") != NULL) {
      args += fullpath;
      args += " ";
    }
    ++iterator;
  }
  platform::Thread thread;
  thread.Create(ThreadRunner, &args);
  thread.Join();
}

void RunTest(bool is_debug, bool is_pretty, bool is_compress, const char* dir) {
  platform::fs::Directory directory(CURRENT_DIR"/test/js");
  platform::fs::Directory::const_iterator iterator = directory.Entries(true);
  Roaster roaster;
  CompilationInfoHandleList list;
  while (iterator != directory.end()) {
    const platform::fs::DirEntry* entry = *iterator;
    const char* fullpath = entry->GetFullPath();
    if (strstr(fullpath, "-cmp.js") == NULL && strstr(fullpath, ".js") != NULL) {
      FileInfoMap::UnsafeSet(fullpath);
      FileInfo* resource = FileInfoMap::UnsafeGet(fullpath);
      CompilationInfoHandle info = resource->compilation_info();
      resource->SetDeploy(dir);
      if (is_debug) {
        info->SetDebug();
      }
      if (is_pretty) {
        info->SetPrettyPrint();
      }
      if (is_compress) {
        info->SetCompress();
      }
      list.push_back(info);
    }
    ++iterator;
  }
  TestCallback* callback = new TestCallback(list.size());
  AsyncCallbackHandle handle(callback);
  roaster.CompileFilesAsync(list, false, handle);
}

void RunTest() {
  RunTest(true, true, false, CURRENT_DIR"/test/js/out/devel");
  fprintf(stderr, "------------------end devel test------------------\n");
  RunTest(false, false, true, CURRENT_DIR"/test/js/out/compressed");
  fprintf(stderr, "------------------end compress test------------------\n");
  char *ret = getenv("PHANTOM_INSTALL_DIR");
  if (!ret) {
    printf("%s\n", ret);
    free(ret);
  } else {
    printf("phantomjs not installed\n");
  }
  RunJS(CURRENT_DIR"/test/js/out");
}

}}
#endif
