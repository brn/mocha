#ifndef mocha_scoped_ptr_h_
#define mocha_scoped_ptr_h_
#include "useconfig.h"
#include "uncopyable.h"
#include "ptr_deleter.h"
#include "ptr_handle.h"
#include "handle.h"

namespace mocha {

template <typename T >
class ScopedPtr : private Uncopyable {
 public :
  typedef void ( *ReleaseCallback ) ( T* ptr );

  template <typename Class , typename Deleter>
  inline ScopedPtr( Class* ptr ,  Deleter deleter );

  template <typename Class>
  inline ScopedPtr( Class* ptr );

  inline ScopedPtr();

  inline ~ScopedPtr();

  template <typename Class , typename Deleter>
  inline void operator () ( Class* ptr , Deleter deleter );

  template <typename Class>
  inline void operator () ( Class* ptr );

  inline T* operator -> ();
  inline const T& operator * () const;
  inline T& operator * ();
  inline T* Get();
  inline Handle<T> ToHandle();
 private :
  inline void LazyInitialize_( PtrHandleBase* base , T* ptr );
  inline T& GetReference_();
  inline void CheckInit_ ( const char* message ) const;
  
  bool is_renounced_;
  T* ptr_;
  PtrHandleBase* handle_;
};

template <typename T>
class ScopedArray : public ScopedPtr<T> {
 public :
  template <typename Class>
  inline ScopedArray( Class* ptr );
  inline ScopedArray();
  template <typename Class>
  inline void operator () ( Class* ptr );
};


template <typename T>
class ScopedAllocater : public ScopedPtr<T> {
 public :
  template <typename Class>
  inline ScopedAllocater( Class* ptr );
  inline ScopedAllocater();
  template <typename Class>
  inline void operator () ( Class* ptr );
};

}

#include "scoped_ptr-impl.h"

namespace mocha {
typedef ScopedArray<const char> ScopedStr;
typedef ScopedArray<const wchar_t> ScopedWStr;
typedef ScopedAllocater<const char> ScopedCStr;
typedef ScopedAllocater<const wchar_t> ScopedWCStr;
}

#endif
