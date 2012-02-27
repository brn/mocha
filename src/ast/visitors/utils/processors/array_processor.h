#ifndef mocha_array_processor_h_
#define mocha_array_processor_h_

namespace mocha {

class ArrayProcessor : private Static {
 public :
  ProcessNode( ArrayLikeLiteral* literal , ProcessorInfo* info );
 private :
  ProcessTuple( ArrayLikeLiteral* literal , ProcessorInfo* info );
};

}

#endif
