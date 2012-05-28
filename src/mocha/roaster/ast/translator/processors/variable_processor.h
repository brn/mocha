#ifndef mocha_variable_processor_h_
#define mocha_variable_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
namespace mocha {
class IVisitor;
class Scope;
class TranslatorData;
class ProcessorInfo;
class VariableProcessor : public Processor {
 public :
  static void ProcessVarList(AstNode* ast_node, ProcessorInfo* info);
  static void ProcessVarInitialiser(Literal* ast_node, ProcessorInfo* info);
};
}

#endif
