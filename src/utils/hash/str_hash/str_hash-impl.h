#ifndef mocha_str_hash_impl_h_
#define mocha_str_hash_impl_h_
#include <utils/hash/hash_fn.h>
#include <utils/int_types.h>
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
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
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }

  /* Handle end cases */
  switch (rem) {
    case 3: hash += get16bits (data);
      hash ^= hash << 16;
      hash ^= data[sizeof (uint16_t)] << 18;
      hash += hash >> 11;
      break;
    case 2: hash += get16bits (data);
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

#undef get16bits

inline Hash_t GetStrHashVal( const char *s ) {
  Hash_t ret = 1;
  int len = strlen( s );
  len = ( len > 10 )? 10 : len;
  for ( int i = 0; i < len; i++) {
    int val = ( i + 2 ) + ( s[i] > 0 )? s[i] : -1 * s[i];
    ret = ret + val * 3;
  }
  return IntegerHash64( ret );
}

template <typename Value>
inline StrHash<Value>::StrHash(){}

template <typename Value>
inline StrHash<Value>::~StrHash(){}

template <typename Value>
inline void StrHash<Value>::Insert( const char* key , Value value ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  std::string key_arg = key;
  table_.Insert( key_arg , value , hash );
}

template <typename Value>
inline void StrHash<Value>::Remove( const char* key ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  std::string key_arg = key;
  table_.Remove( key_arg , hash );
}

template <typename Value>
inline typename StrHash<Value>::HashEntry StrHash<Value>::Find( const char* key ) {
  Hash_t hash = SuperFastHash( key , strlen( key ) );
  return table_.Find( key , hash );
}

template <typename Value>
inline int StrHash<Value>::Size() {
  return table_.Size();
}

template <typename Value>
inline typename StrHash<Value>::EntryIterator StrHash<Value>::Entries() {
  return table_.Entries();
}

}

#endif
