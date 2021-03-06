
#ifndef mocha_ptr_trais_h_
#define mocha_ptr_trais_h_

namespace mocha {

  /**
   *@class
   *Type traits.
   *Distinct void and other types,
   *becase of reference type of void is cause error.
   */
  template <typename T>
  struct PtrTraits {
    typedef T& types;
  };

  //Specializing for type of void. 
  template <>
  struct PtrTraits<void> {
    typedef void types;
  };

}

#endif

