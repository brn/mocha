#ifndef mocha_str_hash_h_
#define mocha_str_hash_h_
#include <string.h>
#include <string>
#include <utils/int_types.h>
#include <utils/hash/hash_bucket.h>

namespace mocha {
template <typename Value>
class StrHash {
 public :
  inline StrHash();
  inline ~StrHash();
  inline void Insert( const char* key , Value value );
  inline HashEntry<std::string,Value>* Find( const char* key );
  inline int Size();
 private :
  HashBucket<std::string,Value> list_;
};
}

#include <utils/hash/str_hash/str_hash-impl.h>

#endif
