#ifndef mocha_syntax_sugar_processor_h_
#define mocha_syntax_sugar_processor_h_
#include <ast/ast_foward_decl.h>
#include <utils/class_traits/static.h>
namespace mocha {
class ProcessorInfo;
class SyntaxSugarProcessor : private Static {
 public :
  static void ProcessArrayComprehensions( ArrayLikeLiteral* literal, ProcessorInfo* info );
  static void ProcessGeneratorExpression( GeneratorExpression* generator , ProcessorInfo* info );
};
}

#endif
