#ifndef mocha_scoped_list_impl_h_
#define mocha_scoped_list_impl_h_

namespace mocha {
template <typename T>
inline ScopedList<T>::ScopedList(){}

template <typename T>
ScopedList<T>::~ScopedList () {}

template <typename T>
template <typename Class, typename Deleter>
inline T* ScopedList<T>::Retain (Class* ptr, Deleter deleter) {
  return RegistToList_(SharedPtr<Class>(ptr, deleter), ptr);
}

template <typename T>
template <typename Deleter>
inline T* ScopedList<T>::Retain (Deleter deleter) {
  T* ptr = new T ();
  return Retain(ptr, deleter);
}


template <typename T>
template <typename Class>
inline T* ScopedList<T>::Retain(Class* ptr) {
  return RegistToList_(SharedPtr<Class>(ptr), ptr);
}

template <typename T>
template <typename Class>
inline T* ScopedList<T>::Retain() {
  Class* ptr = new Class ();
  return Retain(ptr);
}

template <typename T>
inline T* ScopedList<T>::RegistToList_(SharedPtr<T> handle, T* ptr) {
    list_.push_back (handle);
    return ptr;
}

template <typename T>
inline ScopedArrayList<T>::ScopedArrayList() : ScopedList<T>(){}

template <typename T>
template <typename Class>
inline T* ScopedArrayList<T>::Retain(Class* ptr) {
  return ScopedList<T>::Retain(ptr, PtrDeleter<Class>::DeleteArray);
}


template <typename T>
inline ScopedAllocaterList<T>::ScopedAllocaterList() : ScopedList<T>(){}

template <typename T>
template <typename Class>
inline T* ScopedAllocaterList<T>::Retain(Class* ptr) {
  return ScopedList<T>::Retain(ptr, PtrDeleter<Class>::Free);
}

}

#endif
