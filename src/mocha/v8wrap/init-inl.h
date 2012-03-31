#ifndef mocha_v8wrap_init_inl_h_
#define mocha_v8wrap_init_inl_h_
namespace mocha {
template<typename T>
void V8Init::Extension() {
  T::Init(native_);
}

template <typename T>
T* V8Init::GetInternal(const v8::Handle<v8::Object> handle) {
  void* pThis = v8::Handle<v8::External>::Cast(handle->GetInternalField(0))->Value();
  return static_cast<T*>(pThis);
}

}
#endif
