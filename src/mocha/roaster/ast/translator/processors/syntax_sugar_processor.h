#ifndef mocha_syntax_sugar_processor_h_
#define mocha_syntax_sugar_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor.h>
namespace mocha {
class ProcessorInfo;
class IVisitor;
class SyntaxSugarProcessor : public Processor {
 public :
  static void ProcessArrayComprehensions(ArrayLikeLiteral* literal, ProcessorInfo* info);
  static void ProcessGeneratorExpression(GeneratorExpression* generator, ProcessorInfo* info);
 private :
  static void CreateClosure(AstNode* ast_node, AstNode* body, IVisitor* visitor, int64_t line);
};
}

#endif
