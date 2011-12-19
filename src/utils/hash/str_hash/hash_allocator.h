#ifndef mocha_hash_allocator_h_
#define mocha_hash_allocator_h_

namespace mocha {
template <typename T>
class EntryAllocator{
  static T* Allocate( size_t size );
  static T* ReAllocate( size_t size );
};
}

#endif
