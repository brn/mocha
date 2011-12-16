#ifndef mocha_hash_bucket_impl_h_
#define mocha_hash_bucket_impl_h_

namespace mocha {

template <typename Key , typename Value>
HashBucket::HashBucket() : entry_size_( 0 ){}

template <typename Key , typename Value>
HashBucket::~HashBucket(){}

template <typename Key , typename Value>
void HashBucket::Insert( Key key , Value value , uint32_t hash ) {
  HashEntry<T> *entry = SearchPosition_( value , hash );
  entry->key = key;
  entry->value = value;
  entry->hash = hash;
  entry_size_++;
}

template <typename Key , typename Value>
void HashBucket::Find( Key key , int hash ) {
  return SearchPosition_( hash );
}

template <typename Key , typename Value>
void HashBucket::Remove( Key key , uint32_t hash ) {
  HashEntry<T> *entry = SearchPosition_( hash );
  entry->Delete();
  entry_size_--;
}

template<typename T>
inline HashEntry<T>* HashBucket::SearchPosition_( uint32_t hash ) {
  uint32_t tmp_hash = hash % MOCHA_HASH_BUCKET_SIZE;
  HashEntry<T> *entry = &entry_[ tmp_hash ];
  if ( entry->IsEmpty() && entry->hash == hash ) {
    return entry;
  } else if ( entry->hash == hash && entry->hash == hash ) {
    return entry;
  } else {
    while ( entry->hash != hash ) {
      tmp_hash = Rehash_( tmp_hash );
      entry = &entry_[ tmp_hash ];
      if ( entry->IsEmpty() ) {
        return entry;
      }
    }
    return entry;
  }
}

inline uint32_t HashBucket::Rehash_( uint32_t hash ) {
  return GetHash( hash ) % MOCHA_HASH_BUCKET_SIZE;
}

static int HashBucket::BUCKET_SIZE[] = MOCHA_HASH_BUCKET_SIZE;

};

#endif
