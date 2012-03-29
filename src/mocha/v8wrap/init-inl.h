#ifndef mocha_v8wrap_init_inl_h_
#define mocha_v8wrap_init_inl_h_
namespace mocha {
template<typename T>
void V8Init::Extension() {
  T::New(exports_);
}
}
#endif
