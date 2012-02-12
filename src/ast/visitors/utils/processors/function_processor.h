#ifndef mocha_funtion_processor_h_
#define mocha_funtion_processor_h_
#include <utils/class_traits/uncopyable.h>
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class FunctionProcessor : private Uncopyable{
 public :
  FunctionProcessor( Function *ast_node , ProcessorInfo* info );
  ~FunctionProcessor();
  void ProcessNode();
 private :
  void ProcessFormalParameter_();
  void ProcessDefaultParameter_( ValueNode* value );
  void ProcessDefaultParameter_( AssignmentExp* exp );
  void ProcessPropertyParameter_( CallExp* exp );
  void ProcessBody_();
  void ProcessYield_();
  VariableStmt* ProcessRestParameter_();
  int argc_;
  Function* function_;
  ProcessorInfo* info_;
  Statement* stmt_;
  AstNode* formal_parameter_;
  AstNode* default_parameter_;
};

}

#endif
