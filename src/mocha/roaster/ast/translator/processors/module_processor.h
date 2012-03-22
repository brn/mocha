#ifndef mocha_module_processor_h_
#define mocha_module_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor.h>
namespace mocha {
class ProcessorInfo;
class ModuleProcessor : public Processor {
 public :
  ModuleProcessor(ModuleStmt* stmt, ProcessorInfo* info);
  ~ModuleProcessor() {}
  void ProcessNode();
 private :
  void ProcessAnonymousModule_(ExpressionStmt* an_stmt_node, AstNode* name, bool is_runtime);
  ExpressionStmt* ProcessBody_(AstNode* body, Function* fn_node, AstNode* name);
  void Finish_(AstNode* name, Function* fn_node);
  ModuleStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif
