#ifndef mocha_hash_dir_entry_list_h_
#define mocha_hash_dir_entry_list_h_

namespace mocha {

class DirEntryList {
 public :
  DirEntryList();
  ~DirEntryList();
  void Extend();
  DirEntry* At( int num );
 private :
  struct DirEntry {
    Bucket* becket_ptr_;
  };
  DirEntry* entries_;
};

}

#endif
