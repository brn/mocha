#ifndef mocha_variable_processor_h_
#define mocha_variable_processor_h_
#include <ast/ast_foward_decl.h>
#include <utils/class_traits/static.h>

namespace mocha {
class IVisitor;
class Scope;
class VisitorInfo;
class ProcessorInfo;
class VariableProcessor : private Static {
 public :
  static void ProcessVarList( AstNode* ast_node , ProcessorInfo* info );
  static void ProcessVarInitialiser( Literal* ast_node , ProcessorInfo* info );
};
}

#endif
