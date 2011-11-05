#ifndef mocha_scoped_list_h_
#define mocha_scoped_list_h_
#include <list>
#include <utility>
#include "uncopyable.h"
#include "ptr_handle.h"
#include "ptr_deleter.h"

namespace mocha {

template<typename T>
class PtrContainer;

template <typename T>
class ScopedList : private Uncopyable {
 public :
  inline ScopedList ();
  virtual ~ScopedList ();
  
  template <typename Class , typename Deleter>
  inline T* Retain ( Class* ptr, Deleter deleter );
  
  template <typename Deleter>
  inline T* Retain ( Deleter deleter );
  
  template <typename Class>
  inline T* Retain( Class* ptr );
  
  template <typename Class>
  inline T* Retain();
  
 protected :
  inline T* RegistToList_( PtrHandleBase *base , T* ptr );
  inline static void* operator new ( size_t size ){};
  inline static void* operator new [] ( size_t size ){};
  typedef std::list<PtrHandleBase*> List_;
  List_ list_;
};

template <typename T>
class ScopedArrayList : private ScopedList<T> {
 public :
  inline ScopedArrayList();
  template <typename Class>
  inline T* Retain( Class* ptr );
};

template <typename T>
class ScopedAllocaterList : private ScopedList<T> {
 public :
  inline ScopedAllocaterList();
  template <typename Class>
  inline T* Retain( Class* ptr );
};

}

#include "scoped_list-impl.h"

namespace mocha {
typedef ScopedArrayList<const char> ScopedStrList;
typedef ScopedArrayList<const wchar_t> ScopedWStrList;
typedef ScopedAllocaterList<const char> ScopedCStrList;
typedef ScopedAllocaterList<const wchar_t> ScopedCWStrList;
}

#endif
