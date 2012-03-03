#ifndef mocha_funtion_processor_h_
#define mocha_funtion_processor_h_
#include <utils/class_traits/uncopyable.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class FunctionProcessor : private Uncopyable{
 public :
  FunctionProcessor( Function *ast_node , ProcessorInfo* info );
  ~FunctionProcessor();
  void ProcessNode();
 private :
  void ProcessFormalParameter();
  void ProcessDefaultParameter( Literal* value );
  void ProcessDefaultParameter( AssignmentExp* exp );
  void ProcessPropertyParameter( CallExp* exp );
  void ProcessBody();
  void ProcessYield();
  VariableStmt* ProcessRestParameter();
  int argc_;
  Function* function_;
  ProcessorInfo* info_;
  AstNode* formal_parameter_;
  AstNode* default_parameter_;
};

}

#endif
