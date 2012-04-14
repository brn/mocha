#ifndef mocha_import_processor_h_
#define mocha_import_processor_h_
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class ImportProccessor : public Processor{
 public :
  ImportProccessor(ImportStmt* stmt, ProcessorInfo* info);
  ~ImportProccessor(){};
  void ProcessNode();
 private :
  void LoadModule();
  ImportStmt* node() { return stmt_; }
  ProcessorInfo* info() { return info_; }
  template <typename T>
  void MakeVariables(const T& list, AstNode* tmp_node, VariableDeclarationList* vars);
  ImportStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif
