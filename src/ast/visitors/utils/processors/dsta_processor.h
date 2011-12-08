#ifndef mocha_dsta_processor_h_
#define mocha_dsta_processor_h_

#include <ast/ast_foward_decl.h>

namespace mocha {

class VisitorInfo;

class DstaProcessor {
 public :
  inline DstaProcessor( VisitorInfo* visitor_info ) : visitor_info_( visitor_info ) {};
  inline ~DstaProcessor(){};
  void ProcessNode( ValueNode* ast_node );
  NodeList* CreateDstaExtractedVarStmt();
  NodeList* CreateDstaExtractedAssignment();
 private :
  void ArrayProcessor_( ValueNode* ast_node , DstaTree* tree , int depth );
  void ObjectProcessor_( ValueNode* ast_node , DstaTree* tree , int depth );
  void MemberProcessor_( ValueNode* ast_node , DstaTree* tree );
  VisitorInfo* visitor_info_;
};

}

#endif
