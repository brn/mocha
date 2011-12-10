#ifndef mocha_dsta_processor_h_
#define mocha_dsta_processor_h_

#include <utils/class_traits/uncopyable.h>
#include <ast/ast_foward_decl.h>
#include <ast/visitors/utils/processors/processor_util.h>

namespace mocha {

class VisitorInfo;
class Scope;
class AstVisitor;
class FactoryInfo;
class DstaProcessor : public ProcessorBase {
 public :
  static DstaProcessor* GetInstance( AstVisitor* , Scope* , VisitorInfo* , FactoryInfo* );
  inline ~DstaProcessor(){};
  void ProcessNode( ValueNode* ast_node );
  NodeList* CreateDstaExtractedVarStmt();
  NodeList* CreateDstaExtractedAssignment();
  VariableStmt* CreateTmpVarDecl();
 private :
  DstaProcessor( AstVisitor* , Scope*, VisitorInfo* ,FactoryInfo* );
  
  void ArrayProcessor_( ValueNode* ast_node , DstaTree* tree , int depth );
  void ObjectProcessor_( ValueNode* ast_node , DstaTree* tree , int depth );
  void MemberProcessor_( ValueNode* ast_node , DstaTree* tree );

  AstVisitor *visitor_;
  Scope *scope_;
  VisitorInfo *visitor_info_;
  FactoryInfo *factory_info_;
};

}

#endif
