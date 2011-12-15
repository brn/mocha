#ifndef mocha_utils_h_
#define mocha_utils_h_
#include <utils/int_types.h>
#include <utils/static_assert.h>
#include <assert.h>

namespace mocha {
template <typename T,int bit_bands>
class BitVector {
 public :
  inline BitVector() : set_( 0 ){}
  inline ~BitVector(){}
  inline void Set( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ |= ( 1 << val );
  }
  inline void UnSet( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ &= ( ( 1 << val ) ^ ( 1 << val ) );
  }
  inline void Reverse( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ ^= ( 1 << val );
  }
  inline bool At( int val ) {
    assert( bit_bands >= val );
    T tmp = ( 1 << val );
    return ( set_ & tmp ) == tmp;
  }
  inline bool operator[] ( int val ) {
    return At( val );
  }
 private :
  STATIC_ASSERT(bit_bands > 0);
  T set_;
};


template <typename T,int bit_bands,size_t Size>
class FixedBitStack {
 public  :
  typedef BitVector<T,bit_bands> FixedBitVector;
  FixedBitStack() : current_( 0 ){};
  ~FixedBitStack(){}
  inline const FixedBitVector& First() const { return vector_[0]; }
  inline const FixedBitVector& Last() const { return vector_[Size - 1]; }
  inline const FixedBitVector& At( int index ) const { return vector_[index]; }
  inline void Push( int val ) { vector_[ current_ ].Set( val );current_++; }
  inline void Pop( int val ) {
    vector_[ current_ ].UnSet( val );
    if ( current_ > 0 ) {
      current_--;
    }
  }
  inline bool AtFrom( int index ) {
    return vector_[ ( ( current_ > 0 )? current_ - 1 : current_ ) ].At( index );
  }

  inline bool operator[] ( int index ) {
    return AtFrom( index );
  }
  
 private :
  int current_;
  FixedBitVector vector_[Size];
};


typedef BitVector<uint8_t,8>  BitVector8;
typedef BitVector<uint16_t,16> BitVector16;
typedef BitVector<uint32_t,32> BitVector32;
typedef BitVector<uint64_t,64> BitVector64;

template <size_t Size>
class FixedBitStack8 : public FixedBitStack<uint8_t,8,Size>{};

template <size_t Size>
class FixedBitStack16 : public FixedBitStack<uint16_t,16,Size>{};

template <size_t Size>
class FixedBitStack32 : public FixedBitStack<uint32_t,32,Size>{};

template <size_t Size>
class FixedBitStack64 : public FixedBitStack<uint64_t,64,Size>{};

}

#endif
