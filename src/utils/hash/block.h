#ifndef mocha_hash_block_h_
#define mocha_hash_block_h_

namespace mocha {

template <typename Block_t , typename Key_t , typename Value_t , size_t size>
class Block {
 public :
  inline Block();
  inline ~Block();
  inline Entry* Item();
  inline Block_t* At( size_t num );
 private :
  Block_t node_[ size ];
  Entry<Key_t,Value_t>* entry_;
};

#include <utils/hash/block-impl.h>

}

#endif
