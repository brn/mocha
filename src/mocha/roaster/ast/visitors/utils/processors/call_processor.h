#ifndef mocha_call_processor_h_
#define mocha_call_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class CallProcessor : private Static{
 public :
  static void ProcessPrivateAccessor( CallExp* ast_node , ProcessorInfo* info );
  static void ProcessFnCall( CallExp* ast_node , ProcessorInfo* info );
  static void ProcessExtendAccessor( CallExp* ast_node , ProcessorInfo* info );
};

}

#endif
