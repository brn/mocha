#ifndef mocha_hash_bucket_h_
#define mocha_hash_bucket_h_

namespace mocha {

class Bucket {
 public :
  Bucket();
  ~Bucket();
  void* Entry();
  void Entry( void* );
  int BitCategory();
  void Increase();
  bool IsEmpty();
 private :
  int used_bit_category_;
  void* entry_;
};

}

#endif
