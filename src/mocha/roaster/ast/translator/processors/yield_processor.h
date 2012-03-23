#ifndef mocha_yield_processor_h_
#define mocha_yield_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
namespace mocha {
class ProcessorInfo;
class YieldProcessor : public Processor {
 public :
  YieldProcessor(YieldExp* exp, ProcessorInfo* info);
  ~YieldProcessor();
  void ProcessNode();
 private :
  void ProcessSend_(AstNode* exp);
  AstNode* exp_;
  ProcessorInfo* info_;
};
}

#endif
