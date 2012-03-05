#ifndef mocha_utils_h_
#define mocha_utils_h_
#include <mocha/misc/int_types.h>
#include <mocha/roaster/misc/static_assert.h>
#include <assert.h>

namespace mocha {
template <typename T,int bit_bands>
class BitVector {
 public :
  inline BitVector() : set_( 0 ){}
  inline ~BitVector(){}
  inline BitVector( const BitVector& vec ) {
    set_ = vec.set_;
  }
  inline const BitVector<T,bit_bands>& operator = ( const BitVector<T,bit_bands>& vec ) {
    set_ = vec.set_;
    return (*this);
  }
  inline void Set( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ |= ( 1 << val );
  }
  inline void UnSet( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ &= ( ~( 1 << val ) );
  }
  inline void Reverse( int val ) {
    assert( bit_bands >= val && val > -1 );
    set_ ^= ( 1 << val );
  }
  inline bool At( int val ) const {
    assert( bit_bands >= val );
    T tmp = ( 1 << val );
    return ( set_ & tmp ) == tmp;
  }
  inline bool operator[] ( int val ) const {
    return At( val );
  }
 private :
  STATIC_ASSERT(bit_bands > 0);
  T set_;
};


typedef BitVector<uint8_t,8>  BitVector8;
typedef BitVector<uint16_t,16> BitVector16;
typedef BitVector<uint32_t,32> BitVector32;
typedef BitVector<uint64_t,64> BitVector64;

namespace bits {

inline int BitCount8( uint8_t bit ) {
  uint8_t count = ( bit & 0x55 ) + ( ( bit >> 1 ) & 0x55 );
  count = ( count & 0x33 ) + ( ( count >> 2 ) & 0x33 );
  return ( count & 0x0f ) + ( ( count >> 4 ) & 0x0f );
}

inline int BitCount16( uint16_t bit ) {
  uint16_t count = ( bit & 0x5555 ) + ( ( bit >> 1 ) & 0x5555 );
  count = ( count & 0x3333 ) + ( ( count >> 2 ) & 0x3333 );
  count = ( count & 0x0f0f ) + ( ( count >> 4 ) & 0x0f0f );
  return ( count & 0x00ff ) + ( ( count >> 8 ) & 0x00ff );
}

inline int BitCount32( uint32_t bit ) {
  uint32_t count = ( bit & 0x55555555 ) + ( ( bit >> 1 ) & 0x55555555 );
  count = ( count & 0x33333333 ) + ( ( count >> 2 ) & 0x33333333 );
  count = ( count & 0x0f0f0f0f ) + ( ( count >> 4 ) & 0x0f0f0f0f );
  count = ( count & 0x00ff00ff ) + ( ( count >> 8 ) & 0x00ff00ff );
  return ( count & 0x0000ffff ) + ( ( count >> 16 ) & 0x0000ffff );
}


inline int BitCount64( uint64_t bit ) {
  uint64_t count = ( bit & 0x5555555555555555ULL ) + ( ( bit >> 1 ) & 0x5555555555555555ULL );
  count = ( count & 0x3333333333333333ULL ) + ( ( count >> 2 ) & 0x3333333333333333ULL );
  count = ( count & 0x0f0f0f0f0f0f0f0fULL ) + ( ( count >> 4 ) & 0x0f0f0f0f0f0f0f0fULL );
  count = ( count & 0x00ff00ff00ff00ffULL ) + ( ( count >> 8 ) & 0x00ff00ff00ff00ffULL );
  count = ( count & 0x0000ffff0000ffffULL ) + ( ( count >> 16 ) & 0x0000ffff0000ffffULL );
  return static_cast<int>( ( count & 0x00000000ffffffffULL ) + ( ( count >> 32ULL ) & 0x00000000ffffffffULL ) );
}

inline int MSB8bit( uint8_t bit ) {
  if (bit == 0) return 0;
  bit |= ( bit >> 1 );
  bit |= ( bit >> 2 );
  bit |= ( bit >> 4 );
  return BitCount8( bit ) - 1;
}

inline int MSB16bit( uint16_t bit ) {
  if (bit == 0) return 0;
  bit |= ( bit >> 1 );
  bit |= ( bit >> 2 );
  bit |= ( bit >> 4 );
  bit |= ( bit >> 8 );
  return BitCount16( bit ) - 1;
}

inline int MSB32bit( uint32_t bit ) {
  if (bit == 0) return 0;
  bit |= ( bit >> 1 );
  bit |= ( bit >> 2 );
  bit |= ( bit >> 4 );
  bit |= ( bit >> 8 );
  bit |= ( bit >> 16 );
  return BitCount32( bit ) - 1;
}

inline int MSB64( uint64_t bit ) {
  if ( bit == 0 ) return 0;
  bit |= ( bit >> 1 );
  bit |= ( bit >> 2 );
  bit |= ( bit >> 4 );
  bit |= ( bit >> 8 );
  bit |= ( bit >> 16 );
  bit |= ( bit >> 32ULL );
  return BitCount64( bit ) - 1;
}

}

}

#endif
