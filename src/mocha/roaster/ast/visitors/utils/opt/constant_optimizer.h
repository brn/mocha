#ifndef mocha_constant_optimizer_h_
#define mocha_constant_optimizer_h_
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {

class ConstantOptimizer : public Processor {
 public :
  ConstantOptimizer(AstNode* left, AstNode* right, int op)
      : Processor(), op_(op), left_(left), right_(right){};
  static bool CheckOperatorAssoc(int left, int right);
  static bool IsOptimizable(AstNode* left, AstNode* right, int op);
  AstNode* Optimize();
 private :
  int operand() { return op_; }
  AstNode* left() { return left_; }
  AstNode* right() { return right_; }
  int op_;
  AstNode* left_;
  AstNode* right_;
};

}

#endif
