#ifndef mocha_hash_allocator_impl_h_
#define mocha_hash_allocator_impl_h_

namespace mocha {

template <typename T>
T* EntryAllocator::Allocate( size_t size ) {
  T* ptr = reinterpret_cast<T*>( malloc( sizeof( T* ) * size ) );
  if ( ptr == NULL ) {
    return 0;
  }
  return ptr;
}

template <typename T>
T* EntryAllocator::ReAllocate( T* ptr , size_t size ) {
  T* ptr = reinterpret_cast<T*>( realloc( ptr , sizeof( T* ) * size ) );
  if ( ptr == NULL ) {
    return 0;
  }
  return ptr;
}

}

#endif
