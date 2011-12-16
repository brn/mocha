#ifndef mocha_hash_bucket_list_h_
#define mocha_hash_bucket_list_h_
#include <list>
namespace mocha {
class HashBucket;
template <typename Key , typename Value>
class HashBucketList {
 public :
  inline HashBucketList();
  inline ~HashBucketList();
  inline void Grow();
  inline int Size() { return bucket_length_; }
  inline void Insert( Key key , Value value , uint32_t hash );
  inline HashEntry<Key,Value>* Find( Key key , uint32_t hash );
  inline void Remove( Key key , uint32_t hash ) { FindOf_( key , hash )->Remove( key , hash ); }
  inline HashBucket* Current() { return bucket_.back(); }
 private :
  inline HashBucket* FindOf_( uint32_t hash );
  int bucket_length_;
  std::list<HashBucket<Key,Value>*> bucket_;
};

}

#include <utils/hash/hash_bucket_list-impl.h>

#endif
