#ifndef mocha_iteration_processor_h_
#define mocha_iteration_processor_h_
#include <mocha/roaster/ast/visitors/utils/processors/processor.h>
#include <utils/class_traits/static.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class IterationProcessor : public Processor {
 public :
  static void ProcessForNode(IterationStmt* ast_node, ProcessorInfo* info);
  static void ProcessForInNode(IterationStmt* ast_node, ProcessorInfo* info, bool is_regist = true);
  static void ProcessForOfNode(IterationStmt* ast_node, ProcessorInfo* info);
  static void ProcessForEachNode(IterationStmt* ast_node, ProcessorInfo* info);
  static void ProcessWhileNode(IterationStmt* ast_node, ProcessorInfo* info);
 private :
  static void InsertBlock(IterationStmt* ast_node);
};
}

#endif
