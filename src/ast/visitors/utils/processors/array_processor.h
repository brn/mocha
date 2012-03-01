#ifndef mocha_array_processor_h_
#define mocha_array_processor_h_
#include <ast/ast_foward_decl.h>
#include <utils/class_traits/static.h>
namespace mocha {
class ProcessorInfo;
class ArrayProcessor : private Static {
 public :
  static void ProcessNode( ArrayLikeLiteral* literal , ProcessorInfo* info );
 private :
  static void ProcessTuple( ArrayLikeLiteral* literal , ProcessorInfo* info );
};

}

#endif
