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
  entry_size_++;
}

template <typename Key , typename Value>
void HashBucket::Find( Key key , int hash ) {
  return SearchPosition_( key , value , hash );
}

template <typename Key , typename Value>
void HashBucket::Remove( Key key , uint32_t hash ) {
  HashEntry<T> *entry = SearchPosition_( key , value , hash );
  entry->Empty();
  entry_size_--;
}

template<typename T>
inline HashEntry<T>* HashBucket::SearchPosition_( Key key , uint32_t hash ) {
  hash = hash % MOCHA_HASH_BUCKET_SIZE;
  HashEntry<T> *entry = &entry_[ hash ];
  if ( entry->IsEmpty() ) {
    return entry;
  } else if ( entry->key == key ) {
    return entry;
  } else {
    while ( entry->key != key ) {
      hash = Rehash_( hash );
      entry = &entry_[ hash ];
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

};

#endif
