#infdef mocha_variable_processor_h_
#define mocha_variable_processor_h_
#include <ast/ast_foward_decl.h>
#include <ast/visitors/utils/processors/processor_util.h>

namespace mocha {
class AstVisitor;
class Scope;
class VisitorInfo;
class FactoryInfo;
class VariableProcessor : public ProcessorBase {
 public :
  VariableProcessor( AstVisitor* visitor , Scope* scope , VisitorInfo* info , FactoryInfo* f_info );
  ~VariableProcessor(){}
  void ProcessVarList( AstNode* ast_node );
  void ProcessVarInitialiser( AstNode* ast_node );
 private :
  AstVisitor *visitor_;
  Scope *scope_;
  VisitorInfo *visitor_info_;
  FactoryInfo *factory_info_;
};
}

#endif
