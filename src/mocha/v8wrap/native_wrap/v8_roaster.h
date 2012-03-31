#ifndef mocha_v8wrap_v8_roaster_h_
#define mocha_v8wrap_v8_roaster_h_
#include <mocha/roaster/misc/class_traits/static.h>
namespace mocha {
#define DECL_METHOD(name) static v8::Handle<v8::Value> name(const v8::Arguments& args)
#define DECL_DIPOSER static void Dispose(v8::Persistent<v8::Value> handle, void* ptr);
#define INIT_DECL static void Init(v8::Handle<v8::Object> object)
class V8Roaster : private Static{
 public :
  DECL_METHOD(New);
  DECL_METHOD(Compile);
  DECL_METHOD(CompileFile);
  DECL_METHOD(CompileFileAsync);
};
}
#undef DECL_METHOD
#undef DECL_DIPOSER
#undef INIT_DECL
#endif
