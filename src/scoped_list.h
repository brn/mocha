#ifndef mocha_scoped_list_h_
#define mocha_scoped_list_h_
#include <list>
#include <utility>
#include "uncopyable.h"
#include "ptr_release.h"
namespace mocha {

template<typename T>
class PtrContainer;

template <typename T>
class ScopedList : private Uncopyable {
 public :
  typedef void ( *ReleaseCallback )( T* ptr );
  inline ScopedList () {}
  ~ScopedList () {
    typename List_::iterator begin = list_.begin ();
    typename List_::iterator end = list_.end ();
    while ( begin != end ) {
      delete (*begin);
      ++begin;
    }
  }
  inline T* Retain ( T* ptr, ReleaseCallback callback = ptr_release::Release<T> ) {
    list_.push_back ( new PtrContainer<T>( ptr , callback ) );
    return ptr;
  }
  inline T* Retain ( ReleaseCallback callback = ptr_release::Release<T> ) {
    T* ptr = new T ();
    list_.push_back ( new PtrContainer<T>( ptr , callback ) );
    return ptr;
  }
 private :
  inline static void* operator new ( size_t size );
  inline static void* operator new [] ( size_t size );
  inline static void operator delete ( void* ptr );
  inline static void operator delete [] ( void* ptr );
  typedef std::list<PtrContainer<T>* > List_;
  List_ list_;
};

template<typename T>
class PtrContainer {
 public :
  PtrContainer( T* ptr , typename ScopedList<T>::ReleaseCallback callback ) : ptr_( ptr ) , callback_( callback ){}
  ~PtrContainer() { callback_( ptr_ ); }
 private :
  T* ptr_;
  typename ScopedList<T>::ReleaseCallback callback_;
};

}
#endif
