#ifndef mocha_roaster_roaster_impl_h_
#define mocha_roaster_roaster_impl_h_
#include <string.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexl/nexl.h>
#include <mocha/roaster/notificator/notificator.h>
namespace mocha {
class Roaster::ThreadArgs : public Notificator<CompilationResult*> {
 public :
  ThreadArgs(const char* source_or_file, const char* chs, CompilationInfo* hd, bool file)
      : is_file(file),
        source_or_filename(source_or_file),
        info(hd) {
    if (chs) {
      charset = new char[strlen(chs) + 1];
      strcpy(charset, chs);
    } else {
      charset = NULL;
    }
  }
  ~ThreadArgs() {
    delete [] charset;
  }
  bool is_file;
  std::string source_or_filename;
  char* charset;
  CompilationInfo* info;
  static const char kComplete[];
};

template <typename T>
void Roaster::CompileAsync(const char* source, const char* charset, CompilationInfo* info, T callback, bool is_join) {
  ThreadArgs* args = new ThreadArgs(source, charset, info, false);
  args->AddListener(ThreadArgs::kComplete, callback);
  AsyncRunner(args, is_join);
}

template <typename T>
void Roaster::CompileFileAsync(const char* source, const char* charset, CompilationInfo* info, T callback, bool is_join) {
  ThreadArgs* args = new ThreadArgs(source, charset, info, true);
  args->AddListener(ThreadArgs::kComplete, callback);
  AsyncRunner(args, is_join);
}
}
#endif
