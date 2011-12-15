#ifndef mocha_hash_bucket_h_
#define mocha_hash_bucket_h_
#define MOCHA_HASH_BUCKET_SIZE 1000
namespace mocha {
class HashEntry;
template <typename Key , typename Value>
class HashBucket {
 public :
  HashBucket();
  ~HashBucket();
  void Insert( Key key , Value value , uint32_t hash );
  HashEntry* Find( Key key , uint32_t hash );
  void Remove( Key key , uint32_t hash );
  int Size() { return entry_size_; };
 private :
  int entry_size_;
  void SearchPosition_( Key key , uint32_t hash );
  int Rehash_( uint32_t hash );
  HashEntry<T> entry_[ MOCHA_HASH_BUCKET_SIZE ];
};

}

#include <utils/hash/hash_bucket-impl.h>

#endif
