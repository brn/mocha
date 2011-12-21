#ifndef mocha_hash_entry_impl_h_
#define mocha_hash_entry_impl_h_

namespace mocha {

template <typename Key_t , typename Value_t>
Entry<Key_t,Value_t>::Entry( Key_t& key , Value_t& value , uint64_t hash ) :
    hash_( hash ) , key_( key ) , value_( value ) {}

template <typename Key_t , typename Value_t>
Entry<Key_t,Value_t>::Entry() : hash_( 0 ){}

template <typename Key_t , typename Value_t>
Entry<Key_t,Value_t>::~Entry(){};

template <typename Key_t , typename Value_t>
inline const Key_t& Entry<Key_t,Value_t>::Key() const { return key_; }

template <typename Key_t , typename Value_t>
inline const Value_t& Entry<Key_t,Value_t>::Value() const { return value_; }

template <typename Key_t , typename Value_t>
inline const uint64_t& Entry<Key_t,Value_t>::Hash() const { return hash_; }

template <typename Key_t , typename Value_t>
inline bool Entry<Key_t,Value_t>::IsEmpty() const {
  return hash_ == 0;
}


}

#endif
