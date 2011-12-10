#ifnedf mocha_iteration_processor_h_
#define mocha_iteration_processor_h_

#include <utils/class_traits/uncopyable.h>
#include <utils/thread/thread.h>
#include <ast/ast_foward_decl.h>
#include <ast/visitors/utils/processors/processor_util.h>

namespace mocha : public ProcessorBase {
class AstVisitor;
class Scope;
class VisitorInfo;
class FactoryInfo;
class IterationProcessor {
 public :
  static IterationProcessor* GetInstance( AstVisitor* , Scope* , VisitorInfo* , FactoryInfo* );
  ~IterationProcessor();
  void ProcessForNode( IterationStmt* ast_node );
  void ProcessForInNode( IterationStmt* ast_node );
  void ProcessForEachNode( IterationStmt* ast_node );
  void ProcessWhileNode( IterationStmt* ast_node );
  void ProcessDoWhileNode( IterationStmt* ast_node );
 private :
  IterationProcessor( AstVisitor* visitor , Scope* scope , VisitorInfo* info );

  static ThreadLocalStorageKey local_key_;
  static Mutex mutex_;
  AstVisitor* visitor_;
  Scope* scope_;
  VisitorInfo* visitor_info_;
  FactoryInfo* factory_info_;
};
}

#endif
