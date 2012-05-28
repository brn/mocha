#ifndef mocha_refcount_impl_h_
#define mocha_refcount_impl_h_

namespace mocha {

template <typename T>
inline RefCount<T>::RefCount (T *target) :
    RefCountBase (1), ptr_handle_ (new PtrHandle<T> (target)) {};

template <typename T>
template <typename Deleter>
inline RefCount<T>::RefCount (T *target, Deleter deleter ) :
    RefCountBase (1), ptr_handle_ (new PtrHandleDeleter<T,Deleter>(target, deleter)) {};

template <typename T>
inline RefCount<T>::RefCount (PtrHandleBase* base) : 
    RefCountBase (1), ptr_handle_ (base) {};

template <typename T>
inline RefCount<T>::~RefCount () {
  if (ptr_handle_ != 0) {
    //destruct pointer.
    ptr_handle_->Dispose();
    delete ptr_handle_;
    ptr_handle_ = 0;
  }
};
}

#endif
