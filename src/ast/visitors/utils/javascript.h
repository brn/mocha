#ifndef mocha_javascript_h_
#define mocha_javascript_h_

#define COMMON_PARAMETER CodegenVisitor* visitor , GeneratorUtil* util , GeneratorState* state
#define COMMON_PROP CodegenVisitor* visitor_; GeneratorUtil* util_; GeneratorState* state_
#define COMMON_INITILISER CodegenVisitor* visitor_( visitor ), GeneratorUtil* util_( util ), GeneratorState* state_( state )

namespace mocha {

class CodegenVisitor;
class GeneratorUtil;
class GeneratorState;

namespace javascript {

class AnonymousScopeProcessor : private Uncopyable {
 public :
  AnonymousScopeProcessor( COMMON_PARAMETER ) : COMMON_INITILISER {};
  ~AnonymousScopeProcessor(){};
  void OpenScope();
  void CloseScope();
 private :
  COMMON_PROP;
};


class BlockProcessor {
 public :
  BlockProcessor( COMMON_PARAMETER ) : COMMON_INITILISER {};
  ~BlockProcessor(){};
  void OpenBlock();
  void CloseBlock();
 private :
  COMMON_PROP;
};


class ModuleProcessor {
 public :
  ModuleProcessor( COMMON_PARAMETER ) : COMMON_INITILISER {};
  ~ModuleProcessor(){}
  void AnonymousModule( Injection injection );
  void NamedModule();
 private :
  COMMON_PROP;
};


class ExportProcessor {
 public :
  ExportProcessor( COMMON_PARAMETER ) : COMMON_INITILISER {};
  ~ExportProcessor(){}
  void Process();
 private :
  COMMON_PROP;
};


class Prologue {
 public :
  Prologue( COMMON_PARAMETER ) : COMMON_INITILISER {};
  ~Prlogue(){};
  void Process( AstNode* node );
 private :
  COMMON_PROP;
};

}

}
#undef COMMON_PARAMETER
#undef COMMON_INITILISER
#undef COMMON_PROP
#endif
