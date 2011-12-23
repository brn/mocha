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
  void Insert( void* entry , uint32_t hash );
  void* Find( uint32_t hash );
  int Size();
  int BitCategory();
 private :
  ScopedPtr<DirEntryList> list_;
};

}

#endif
