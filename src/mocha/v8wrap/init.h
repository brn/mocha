#ifndef mocha_v8wrap_init_h_
#define mocha_v8wrap_init_h_
#include <v8.h>
namespace mocha {
class V8Init {
 public :
  V8Init();
  ~V8Init(){}
  v8::Handle<v8::ObjectTemplate> global() {return global_;}
  v8::Handle<v8::Value> Run(const char* source);
  template <typename T>
  void Extension();
 private :
  void Initialize();
  static v8::Handle<v8::Value> DoRun(const char* source, const char* name = NULL);
  static v8::Handle<v8::Value> Compile(const v8::Arguments& args);
  void SetHelper(v8::Handle<v8::Object> object);
  v8::HandleScope handle_scope_;
  v8::Handle<v8::ObjectTemplate> global_;
  v8::Persistent<v8::Context> context_;
  v8::Handle<v8::Function> function_;
  v8::Handle<v8::Object> exports_;
};
}
#include <mocha/v8wrap/init-inl.h>
#endif
