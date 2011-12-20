#ifndef mocha_str_hash_h_
#define mocha_str_hash_h_
#include <string.h>
#include <string>
#include <utils/int_types.h>
#include <utils/hash/hash_table.h>

namespace mocha {
template <typename Value>
class StrHash {
 public :
  typedef const Entry<std::string,Value>* HashEntry;
  inline StrHash();
  inline ~StrHash();
  inline void Insert( const char* key , Value value );
  inline HashEntry Find( const char* key );
  inline int Size();
 private :
  HashTable<std::string,Value> table_;
};
}

#include <utils/hash/str_hash/str_hash-impl.h>

#endif
