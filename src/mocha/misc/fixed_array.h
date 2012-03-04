#ifndef mocha_fixed_array_h_
#define mocha_fixed_array_h_

namespace mocha {

template <typename T>
class FixedArray {
 public :
  FixedArray( size_t size ){}
  ~FixedArray(){}
  T At( index );
 private :
  T* array_;
};

}

#endif
