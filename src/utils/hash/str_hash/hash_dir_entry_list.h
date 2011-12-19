#ifndef mocha_hash_dir_entry_list_h_
#define mocha_hash_dir_entry_list_h_

namespace mocha {

class DirEntryList {
 public :
  DirEntryList();
  ~DirEntryList();
  void Extend();
  DirEntry* At( int num );
  void Insert( void* entry , uint64_t hash );
  void* Find( uint64_t hash );
 private :
  int used_bit_category_;
  int size_;
  struct DirEntry {
    Bucket* becket_ptr_;
  };
  DirEntry* entries_;
};

}

#endif
