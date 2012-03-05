#ifndef mocha_scoped_list_h_
#define mocha_scoped_list_h_
#include <list>
#include <utility>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/smart_pointer/common/ptr_deleter.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {

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
  inline T* RegistToList_( SharedPtr<T> handle , T* ptr );
  typedef std::list<SharedPtr<T> > List_;
  List_ list_;
 private :
  inline static void* operator new ( size_t size ){return 0;};
  inline static void* operator new [] ( size_t size ){return 0;};
};

template <typename T>
class ScopedArrayList : public ScopedList<T> {
 public :
  inline ScopedArrayList();
  template <typename Class>
  inline T* Retain( Class* ptr );
};

template <typename T>
class ScopedAllocaterList : public ScopedList<T> {
 public :
  inline ScopedAllocaterList();
  template <typename Class>
  inline T* Retain( Class* ptr );
};

}

#include <mocha/roaster/smart_pointer/scope/scoped_list-impl.h>

namespace mocha {
typedef ScopedArrayList<char> ScopedStrList;
typedef ScopedArrayList<wchar_t> ScopedWStrList;
typedef ScopedAllocaterList<char> ScopedCStrList;
typedef ScopedAllocaterList<wchar_t> ScopedCWStrList;
}

#endif
