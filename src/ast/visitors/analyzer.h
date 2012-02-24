#ifndef mocha_analyzer_h_
#define mocha_analyzer_h_
#include <ast/ast_foward_decl.h>
namespace mocha {
class JSValue;
#define FOWARD_DECL(name) JSValue* Analyze##name( name* ast_node )

class Analyzer {
 public :
  Analyzer();
  ~Analyzer(){};
  FOWARD_DECL( Expression );
  FOWARD_DECL( AssignmentExp );
  FOWARD_DECL( Function );
  FOWARD_DECL( BinaryExp );
  FOWARD_DECL( CallExp );
  FOWARD_DECL( NewExp );
  FOWARD_DECL( PostfixExp );
  FOWARD_DECL( UnaryExp );
  FOWARD_DECL( CompareExp );
  FOWARD_DECL( ConditionalExp );
  FOWARD_DECL( ValueNode );
};

#undef FOWARD_DECL
}

#endif