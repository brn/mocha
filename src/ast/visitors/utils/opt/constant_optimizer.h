#ifndef mocha_constant_optimizer_h_
#define mocha_constant_optimizer_h_
#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>
namespace mocha {

class ConstantOptimizer : private Static {
 public :
  static bool CheckOperatorAssoc( int left , int right );
  static bool IsOptimizable( AstNode* left , AstNode* right , int op );
  static AstNode* Optimize( AstNode* left , AstNode* right , int op );
};

}

#endif
