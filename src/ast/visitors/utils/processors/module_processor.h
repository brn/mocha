#ifndef mocha_module_processor_h_
#define mocha_module_processor_h_
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class ModuleProcessor {
 public :
  ModuleProcessor( ModuleStmt* stmt , ProcessorInfo* info );
  ~ModuleProcessor() {}
  void ProcessNode();
 private :
  void ProcessAnonymousModule_( ExpressionStmt* an_stmt_node , AstNode* name , bool is_runtime );
  ExpressionStmt* ProcessBody_( AstNode* body , Function* fn_node , AstNode* name );
  void Finish_( AstNode* name , Function* fn_node );
  ModuleStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif
