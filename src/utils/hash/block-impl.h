#ifndef mocha_hash_block_impl_h_
#define mocha_hash_block_impl_h_
#include <assert.h>

namespace mocha {

template <typename Block_t , typename Key_t , typename Value_t , size_t size>
Block::Block(){}

template <typename Block_t , typename Key_t , typename Value_t , size_t size>
Block::~Block(){}

template <typename Block_t , typename Key_t , typename Value_t , size_t size>
Entry* Block::At( size_t size ) {
  return &node_[ size ];
}

}

#endif
