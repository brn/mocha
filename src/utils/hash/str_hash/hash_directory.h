#ifndef mocha_hash_directory_h_
#define mocha_hash_directory_h_
#include <utils/smart_pointer/scope/scoped_ptr.h>
namespace mocha {

class DirEntryList;

class HashDirectory {
 public :
  HashDirectory();
  ~HashDirectory();
  void Extend();
  void Insert( void* entry );
  void Find( uint32_t hash );
  int UsingBits();
  int Size();
  int BitCategory();
  void Increase();
 private :
  int used_bit_category_;
  ScopedPtr<DirEntryList> list_;
};

}

#endif
