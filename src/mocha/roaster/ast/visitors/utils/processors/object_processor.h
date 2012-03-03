#ifndef mocha_object_processor_h_
#define mocha_object_processor_h_
#include <utils/class_traits/uncopyable.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class ObjectProccessor : private Uncopyable {
 public :
  ObjectProccessor( ObjectLikeLiteral* literal , ProcessorInfo* info );
  ~ObjectProccessor(){}
  void ProcessNode();
 private :
  void ProcessPrivateProperty( Literal *name );
  void ProcessRecord();
  ObjectLikeLiteral* literal_;
  ProcessorInfo* info_;
};

}

#endif
