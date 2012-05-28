#ifndef mocha_module_processor_h_
#define mocha_module_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
namespace mocha {
class ProcessorInfo;
class ModuleProcessor : public Processor {
 public :
  ModuleProcessor(ModuleStmt* stmt, ProcessorInfo* info);
  ~ModuleProcessor() {}
  void ProcessNode();
 private :
  void ProcessModule(AstNode* node, AstNode* name, bool is_runtime);
  AstNode* ProcessBody(AstNode* body, Function* fn_node, AstNode* name);
  AstNode* ProcessAssignment(AstNode* body, AstNode* name);
  void Finish(AstNode* name, AstNode* node);
  ModuleStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif
