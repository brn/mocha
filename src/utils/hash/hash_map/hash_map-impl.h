#ifndef mocha_str_hash_impl_h_
#define mocha_str_hash_impl_h_
#include <utils/hash/hash_fn.h>
#include <utils/int_types.h>
#undef GET_16BITS
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define GET_16BITS(d) (*((const uint16_t *) (d)))
#endif

#if !defined (GET_16BITS)
#define GET_16BITS(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

namespace mocha {

inline Hash_t SuperFastHash ( const char * data, int len ) {
  Hash_t hash = len, tmp;
  int rem;

  if (len <= 0 || data == NULL) return 0;

  rem = len & 3;
  len >>= 2;

  /* Main loop */
  for (;len > 0; len--) {
    hash  += GET_16BITS (data);
    tmp    = (GET_16BITS (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }

  /* Handle end cases */
  switch (rem) {
    case 3: hash += GET_16BITS (data);
      hash ^= hash << 16;
      hash ^= data[sizeof (uint16_t)] << 18;
      hash += hash >> 11;
      break;
    case 2: hash += GET_16BITS (data);
      hash ^= hash << 11;
      hash += hash >> 17;
      break;
    case 1: hash += *data;
      hash ^= hash << 10;
      hash += hash >> 1;
  }

  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;

  return hash;
}

#undef GET_16BITS

template <typename Key , typename Value>
inline HashMap<Key,Value>::HashMap(){}

template <typename Key , typename Value>
inline HashMap<Key,Value>::~HashMap(){}

template <typename Key , typename Value>
inline void HashMap<Key,Value>::Insert( const Key& key , Value value ) {
  Hash_t hash = key.ToHash();
  table_.Insert( key , value , hash );
}

template <typename Key , typename Value>
inline void HashMap<Key,Value>::Remove( const Key& key ) {
  Hash_t hash = key.ToHash();
  table_.Remove( key , hash );
}

template <typename Key , typename Value>
inline void HashMap<Key,Value>::RemoveAll() {
  table_.RemoveAll();
}

template <typename Key , typename Value>
inline typename HashMap<Key,Value>::HashEntry HashMap<Key,Value>::Find( const Key& key ) {
  Hash_t hash = key.ToHash();
  return table_.Find( key , hash );
}


template <typename Value>
inline HashMap<const char*,Value>::HashMap(){}

template <typename Value>
inline HashMap<const char*,Value>::~HashMap(){}

template <typename Value>
inline void HashMap<const char*,Value>::Insert( const char* key , Value value ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  std::string key_arg = key;
  table_.Insert( key_arg , value , hash );
}

template <typename Value>
inline void HashMap<const char*,Value>::Insert( const std::string& key , Value value ) {
  Hash_t hash = SuperFastHash( key.c_str() , key.size() );
  table_.Insert( key , value , hash );
}

template <typename Value>
inline void HashMap<const char*,Value>::Remove( const char* key ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  std::string key_arg = key;
  table_.Remove( key_arg , hash );
}

template <typename Value>
inline void HashMap<const char*,Value>::RemoveAll() {
  table_.RemoveAll();
}

template <typename Value>
inline void HashMap<const char*,Value>::Remove( const std::string& key ) {
  Hash_t hash = SuperFastHash( key.c_str() , key.size() );
  table_.Remove( key , hash );
}

template <typename Value>
inline typename HashMap<const char*,Value>::HashEntry HashMap<const char*,Value>::Find( const char* key ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  return table_.Find( key , hash );
}

template <typename Value>
inline typename HashMap<const char*,Value>::HashEntry HashMap<const char*,Value>::Find( const std::string& key ) {
  Hash_t hash = SuperFastHash( key.c_str() , key.size() );
  return table_.Find( key , hash );
}

template <typename Value>
inline int HashMap<const char*,Value>::Size() const {
  return table_.Size();
}

template <typename Value>
inline typename HashMap<const char*,Value>::EntryIterator HashMap<const char*,Value>::Entries() const {
  return table_.Entries();
}


template <typename Value>
inline HashMap<int,Value>::HashMap(){}

template <typename Value>
inline HashMap<int,Value>::~HashMap(){}

template <typename Value>
inline void HashMap<int,Value>::Insert( int key , Value value ) {
  Hash_t hash = hash::IntegerHash64( key );
  table_.Insert( key , value , hash );
}

template <typename Value>
inline void HashMap<int,Value>::Remove( int key ) {
  Hash_t hash = hash::IntegerHash64( key );
  table_.Remove( key , hash );
}

template <typename Value>
inline void HashMap<int,Value>::RemoveAll() {
  table_.RemoveAll();
}

template <typename Value>
inline typename HashMap<int,Value>::HashEntry HashMap<int,Value>::Find( int key ) {
  Hash_t hash = hash::IntegerHash64( key );
  return table_.Find( key , hash );
}

template <typename Value>
inline int HashMap<int,Value>::Size() const {
  return table_.Size();
}

template <typename Value>
inline typename HashMap<int,Value>::EntryIterator HashMap<int,Value>::Entries() const {
  return table_.Entries();
}

}

#endif
