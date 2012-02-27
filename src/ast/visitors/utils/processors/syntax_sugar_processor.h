#ifndef mocha_syntax_sugar_processor_h_
#define mocha_syntax_sugar_processor_h_
#include <ast/ast_foward_decl.h>
#include <utils/class_traits/static.h>
namespace mocha {
class SyntaxSugarProcessor : private Static {
 public :
  void ProcessArrayComprehensions( ArrayLikeLiteral* literal );
  void ProcessGeneratorExpression( GeneratorExpression* generator );
};
}

#endif
