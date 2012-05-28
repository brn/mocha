#ifndef mocha_funtion_processor_h_
#define mocha_funtion_processor_h_
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class FunctionProcessor : public Processor {
 public :
  FunctionProcessor(Function *ast_node, ProcessorInfo* info);
  ~FunctionProcessor();
  void ProcessNode();
 private :
  bool IsDestructuring(AstNode* node);
  void ProcessFormalParameter();
  void ProcessDefaultParameter(Literal* value);
  void ProcessDefaultParameter(AssignmentExp* exp);
  void ProcessPropertyParameter(CallExp* exp);
  void ProcessBody();
  void ProcessYield();
  void ProcessRestParameter(AstNode* node);
  int argc_;
  Function* function_;
  ProcessorInfo* info_;
  AstNode* formal_parameter_;
  AstNode* default_parameter_;
};

}

#endif
