#ifndef mocha_call_processor_h_
#define mocha_call_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
namespace mocha {
class ProcessorInfo;
class CallProcessor : public Processor{
 public :
  CallProcessor(CallExp* ast_node, ProcessorInfo* info)
      : Processor(), ast_node_(ast_node), info_(info){};
  ~CallProcessor(){}
  void ProcessPrivateAccessor();
  void ProcessFnCall();
  void ProcessExtendAccessor();
 private :
  void CallSuper (CallExp* ast_node_, bool direct_call);
  CallExp* ast_node_;
  ProcessorInfo* info_;
};

}

#endif
