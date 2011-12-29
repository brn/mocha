#ifndef mocha_yield_processor_h_
#define mocha_yield_processor_h_
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class YieldProcessor {
 public :
  YieldProcessor( YieldExp* exp , ProcessorInfo* info );
  ~YieldProcessor();
  void ProcessNode();
 private :
  AstNode* exp_;
  ProcessorInfo* info_;
};
}

#endif
