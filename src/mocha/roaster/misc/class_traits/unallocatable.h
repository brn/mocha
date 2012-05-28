#ifndef mocha_utils_class_traits_unallocatable_h_
#define mocha_utils_class_traits_unallocatable_h_

namespace mocha {
class UnAllocatable {
 private :
  inline static void* operator new (size_t size);
  inline static void* operator new [] (size_t size);
  inline static void* operator new (size_t size, void*);
  inline static void* operator new [] (size_t size, void*);
};
class UnAllocatableExternal {
 public :
  inline static void operator delete (void* ptr) { ::operator delete(ptr); }
  inline static void operator delete [] (void* ptr) { ::operator delete[](ptr); }
  inline static void operator delete (void* ptr, void* buf) { ::operator delete(ptr, buf); }
  inline static void operator delete [] (void* ptr, void* buf) { ::operator delete[](ptr, buf); }
 protected :
  inline static void* operator new (size_t size) { return ::operator new(size); };
  inline static void* operator new [] (size_t size) { return ::operator new[](size); };
  inline static void* operator new (size_t size, void* buf) { return ::operator new(size, buf); };
  inline static void* operator new [] (size_t size, void* buf)  { return ::operator new[](size, buf); };;
};
}

#endif
