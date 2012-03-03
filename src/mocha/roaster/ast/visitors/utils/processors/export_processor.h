#ifndef mocha_export_processor_h_
#define mocha_export_processor_h_
#include <utils/class_traits/uncopyable.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class ExportProcessor : private Uncopyable {
 public :
  ExportProcessor( ExportStmt* ast_node , ProcessorInfo* info );
  ~ExportProcessor(){};
  void ProcessNode();
 private :
  void ProcessFunction( AstNode* node );
  void ProcessNodeList( AstNode* node );
  AstNode* CreateAssignment( AstNode* node );
  ExportStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif