#ifndef mocha_v8wrap_init_inl_h_
#define mocha_v8wrap_init_inl_h_
namespace mocha {
template <typename T>
class V8Init::PersistentDisposer : public memory::Allocated {
 public :
  PersistentDisposer(v8::Persistent<T> holder)
      : holder_(holder){}
  ~PersistentDisposer() {
    holder_.ClearWeak();
    holder_.Dispose();
    holder_.Clear();
  }
 private :
  v8::Persistent<T> holder_;
};

template<typename T>
void V8Init::Extension() {
  T::Init(native_);
}

template <typename T>
v8::Persistent<T> V8Init::Regist(v8::Persistent<T> holder) {
  new(&pool_) PersistentDisposer<T>(holder);
  return holder;
}

template <typename T>
v8::Persistent<T> V8Init::Regist(v8::Handle<T> obj) {
  v8::Persistent<T> ret = v8::Persistent<T>::New(obj);
  new(&pool_) PersistentDisposer<T>(ret);
  return ret;
}

template <typename T>
T* V8Init::GetInternal(const v8::Handle<v8::Object> handle) {
  void* external = v8::Handle<v8::External>::Cast(handle->GetInternalField(0))->Value();
  return static_cast<T*>(external);
}

template <typename T, int index>
T* V8Init::GetInternalPtr(const v8::Handle<v8::Object> handle) {
  return static_cast<T*>(handle->GetPointerFromInternalField(index));
}

}
#endif
