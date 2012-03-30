#ifndef mocha_v8wrap_init_h_
#define mocha_v8wrap_init_h_
#include <v8.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/misc/atomic.h>
namespace mocha {
class V8Init {
 public :
  static V8Init* GetInstance();
  ~V8Init(){}
  v8::Handle<v8::ObjectTemplate> global() {return global_;}
  v8::Handle<v8::Value> Run(const char* source);
  void Print(v8::Handle<v8::Value> value);
  template <typename T>
  void Extension();
  v8::Persistent<v8::Context> context() {return context_;}
  template <typename T>
  static T* GetInternal(const v8::Handle<v8::Object> handle);
  static void HandleException(v8::TryCatch *try_catch);
 private :
  V8Init();
  void Initialize();
  static v8::Handle<v8::Value> DoRun(const char* source, const char* name = NULL);
  static v8::Handle<v8::Value> Compile(const v8::Arguments& args);
  void SetHelper(v8::Handle<v8::Object> object);
  v8::HandleScope handle_scope_;
  v8::Handle<v8::ObjectTemplate> global_;
  v8::Persistent<v8::Context> context_;
  v8::Handle<v8::Function> function_;
  v8::Handle<v8::Object> exports_;
  v8::Handle<v8::Object> guard_;
  static AtomicWord atomic_;
  static ScopedPtr<V8Init> instance_;
  static os::Mutex mutex_;
};
}
#include <mocha/v8wrap/init-inl.h>
#endif
