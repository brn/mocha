#ifndef mocha_iteration_processor_h_
#define mocha_iteration_processor_h_

#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>


namespace mocha {
class ProcessorInfo;
class IterationProcessor : private Static {
 public :
  static void ProcessForNode( IterationStmt* ast_node , ProcessorInfo* info );
  static void ProcessForInNode( IterationStmt* ast_node , ProcessorInfo* info , bool is_regist = false );
  static void ProcessForOfNode( IterationStmt* ast_node , ProcessorInfo* info );
  static void ProcessForEachNode( IterationStmt* ast_node , ProcessorInfo* info );
  static void ProcessWhileNode( IterationStmt* ast_node , ProcessorInfo* info );
 private :
};
}

#endif
