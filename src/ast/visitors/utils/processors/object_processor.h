#ifndef mocha_object_processor_h_
#define mocha_object_processor_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/utils/processors/processor_info.h>
namespace mocha {

class ObjectProccessor {
 public :
  ObjectProccessor( ObjectLikeLiteral* literal , ProcessorInfo* info );
  ~ObjectProccessor(){}
  void ProcessNode();
 private :
  ObjectLikeLiteral* literal_;
  ProcessorInfo* info_;
};

}

#endif
