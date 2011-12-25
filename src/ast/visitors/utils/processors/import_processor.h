#ifndef mocha_import_processor_h_
#define mocha_import_processor_h_
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class ImportProccessor {
 public :
  ImportProccessor( ImportStmt* stmt , ProcessorInfo* info );
  ~ImportProccessor(){};
  void ProcessNode();
 private :
  void LoadModule_();
  ImportStmt* stmt_;
  ProcessorInfo* info_;
};

}

#endif
