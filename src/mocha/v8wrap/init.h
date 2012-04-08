#ifndef mocha_v8wrap_init_h_
#define mocha_v8wrap_init_h_
#include <v8.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/misc/atomic.h>
namespace mocha {
class V8Init {
 public :
  static V8Init* GetInstance();
  ~V8Init();
  v8::Handle<v8::Value> RunInConfigContext(const char* source);
  v8::Handle<v8::Value> RunInGlobalContext(const char* source);
  v8::Persistent<v8::Context> context() {return context_;}
  v8::Persistent<v8::Object> natives() {return native_;}
  bool IsInvalidValue(v8::Handle<v8::Value> value);
  bool IsExitStatus(v8::Handle<v8::Value> value);
  void Print(v8::Handle<v8::Value> value);
  static void IdleNotification();
#ifdef NDEBUG
#define REGIST_PERSISTENT(holder,id) Regist(holder)
  template <typename T>
  v8::Persistent<T> Regist(v8::Persistent<T> holder);
  template <typename T>
  v8::Persistent<T> Regist(v8::Handle<T> obj);
#else
#define REGIST_PERSISTENT(holder,id) Regist(holder, id)
  template <typename T>
  v8::Persistent<T> Regist(v8::Persistent<T> holder, const char* id);
  template <typename T>
  v8::Persistent<T> Regist(v8::Handle<T> obj, const char* id);
#endif
  template <typename T>
  void Extension();
  template <typename T>
  static T* GetInternal(const v8::Handle<v8::Object> handle);
  template <typename T, int index>
  static T* GetInternalPtr(const v8::Handle<v8::Object> handle);
  static void HandleException(v8::TryCatch *try_catch);
  static void Destruct();
 private :
  V8Init();
  void Initialize();
  static v8::Handle<v8::Value> DoRun(const char* source, const char* name = NULL);
  static v8::Handle<v8::Value> Compile(const v8::Arguments& args);
  template <typename T>
  class PersistentDisposer;
  void SetHelper(v8::Handle<v8::Object> object);
  v8::Persistent<v8::Object> config_global_;
  v8::Persistent<v8::Context> context_;
  v8::Persistent<v8::Function> function_;
  v8::Persistent<v8::Function> compile_;
  v8::Persistent<v8::Object> native_;
  memory::Pool pool_;
  static os::ThreadLocalStorageKey key_;
};
}
#include <mocha/v8wrap/init-inl.h>
#endif
