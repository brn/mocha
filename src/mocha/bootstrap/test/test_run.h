#ifndef mocha_test_run_h_
#define mocha_test_run_h_
#include <string.h>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/nexl/compilation_result/compilation_result.h>
#include <mocha/bootstrap/runners/phantom_runner.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/directory/directory.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/misc/file_writer.h>
namespace mocha {namespace compiler_test {

void RunJS(const char* dir);

std::string GetPath(const char* path) {
  os::fs::Path fs_path(Bootstrap::GetSelfPath());
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
  os::fs::Directory directory(dir);
  os::fs::Directory::const_iterator iterator = directory.Entries(true);
  std::string args;
  while (iterator != directory.end()) {
    const os::fs::DirEntry* entry = *iterator;
    const char* fullpath = entry->GetFullPath();
    if (strstr(fullpath, "-cmp.js") != NULL) {
      args += fullpath;
      args += " ";
    }
    ++iterator;
  }
  os::Thread thread;
  thread.Create(ThreadRunner, &args);
  thread.Join();
}

class Callback {
 public :
  Callback() : count_(0){}
  void operator()(CompilationResult* result) {
    os::ScopedLock lock(mutex_);
    ++count_;
    if (result->error()->Error()) {
      std::string buf;
      const ErrorReporter* reporter = result->error();
      reporter->SetRawError(&buf);
      DEBUG_LOG(Info, "syntax error %s", buf.c_str());
    } else {
      FileWriter()(result);
    }
    if (count_ == max) {
      is_end = true;
    }
  }
  static int max;
  static bool is_end;
 private :
  int count_;
  static os::Mutex mutex_;
};

int Callback::max = 0;
bool Callback::is_end = false;
os::Mutex Callback::mutex_;

void RunTest(bool is_debug, bool is_pretty, bool is_compress, const char* dir) {
  os::fs::Directory directory(CURRENT_DIR"/test/js");
  os::fs::Directory::const_iterator iterator = directory.Entries(true);
  Callback callback;
  while (iterator != directory.end()) {
    const os::fs::DirEntry* entry = *iterator;
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
      Roaster roaster;
      roaster.CompileFileAsync(fullpath, "UTF-8", info.Get(), callback);
      Callback::max++;
    }
    ++iterator;
  }
  while (!Callback::is_end) {}
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
