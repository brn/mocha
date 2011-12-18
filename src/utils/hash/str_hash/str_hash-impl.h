#ifndef mocha_str_hash_impl_h_
#define mocha_str_hash_impl_h_

namespace mocha {

inline uint64_t GetStrHashVal( const char *s ) {
  uint64_t ret = 1;
  int len = strlen( s );
  len = ( len > 10 )? 10 : len;
  for ( int i = 0; i < len; i++) {
    int val = ( s[i] > 0 )? s[i] : -1 * s[i];
    ret = ret + val * 3;
  }
  return GetHash( ret );
}

template <typename Value>
inline StrHash<Value>::StrHash(){}

template <typename Value>
inline StrHash<Value>::~StrHash(){}

template <typename Value>
inline void StrHash<Value>::Insert( const char* key , Value value ) {
  uint64_t hash = GetStrHashVal( key );
  list_.Insert( key , value , hash );
}

template <typename Value>
inline HashEntry<std::string , Value>* StrHash<Value>::Find( const char* key ) {
  uint64_t hash = GetStrHashVal( key );
  return list_.Find( key , hash );
}

template <typename Value>
inline int StrHash<Value>::Size() {
  return list_.Size();
}

}

#endif
