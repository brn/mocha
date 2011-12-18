#ifndef mocha_hash_fn_h_
#define mocha_hash_fn_h_
#include <utils/int_types.h>
namespace mocha {

static inline uint64_t GetHash( uint64_t key ) {
  uint64_t hash = key;
  hash = ~hash + (hash << 15);  // hash = (hash << 15) - hash - 1;
  hash = hash ^ (hash >> 12);
  hash = hash + (hash << 2);
  hash = hash ^ (hash >> 4);
  hash = hash * 2057;  // hash = (hash + (hash << 3)) + (hash << 11);
  hash = hash ^ (hash >> 16);
  return hash;
}

}

#endif
