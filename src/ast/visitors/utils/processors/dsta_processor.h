#ifndef mocha_dsta_processor_h_
#define mocha_dsta_processor_h_

#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>

namespace mocha {

class ProcessorInfo;
class DstaProcessor : private Static {
 public :
  static void ProcessNode( ValueNode* ast_node , ProcessorInfo* info );
  static NodeList* CreateDstaExtractedVarStmt( Statement* , ProcessorInfo* info );
  static NodeList* CreateDstaExtractedAssignment( Statement* , ProcessorInfo* info );
  static VariableStmt* CreateTmpVarDecl( Statement* , ProcessorInfo* info );
 private :
  static void ArrayProcessor_( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );
  static void ObjectProcessor_( ValueNode* ast_node , DstaTree* tree , int depth , ProcessorInfo* info );
  static void MemberProcessor_( ValueNode* ast_node , DstaTree* tree , ProcessorInfo* info );
};

}

#endif
