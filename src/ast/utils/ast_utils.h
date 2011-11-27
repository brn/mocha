#ifndef mocha_ast_utils_h_
#define mocha_ast_utils_h_
#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>

namespace mocha {
class AstUtils : private Static {
 public :
  enum {
    kAppend,
    kAdd
  };
  static ValueNode* CreateVariable( TokenInfo* symbol , AstNode* value );
  static CallExp* CreateAnonymousFunctionCall( AstNode* body, int is_append = kAppend );
  static CallExp* CreateDotAccessor( AstNode* name , AstNode* prop );
  static AssignmentExp* CreateAssignment( AstNode* left , AstNode* right );
  static Empty* GetEmptyNode();
};
}

#endif
