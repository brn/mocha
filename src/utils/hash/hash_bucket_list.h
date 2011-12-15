#ifndef mocha_hash_bucket_list_h_
#define mocha_hash_bucket_list_h_

namespace mocha {
class HashBucket;
template <typename T>
class HashBucketList {
 public :
  HashBucketList();
  ~HashBucketList();
  void Glow();
  int Size() { return bucket_length_; }
 private :
  int bucket_length_;
  HashBucket<T> *bucket_;
};

}

#endif
