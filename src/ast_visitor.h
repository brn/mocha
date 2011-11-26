
#ifndef AstVisitor_h
#define AstVisitor_h

#include <string>
#include "useconfig.h"
#include "ivisitor.h"
#include "scoped_list.h"

namespace mocha{
  
class Scope;
class Codegen;
class AstState;
class ParserTracer;
class Compiler;

class AstVisitor : public IVisitor {
 public :
    
  AstVisitor ( Scope* scope,
               Compiler* compiler,
               const char* modulename,
               const char* filename );
  ~AstVisitor ();

#include "visitor_decl.h"
  
 private:
  inline void GetTmpVar_( char* buf ) { sprintf( buf , "__tmp__%d" , tmp_index_ );tmp_index_++;  }
  void ImportProccessor_( ImportStmt *node );
  int tmp_index_;
  const char* symbol;
  const char* module_name_;
  const char* filename_;
  ScopedStrList char_handle_;
  Scope* scope_;
  Scope* global_;
  Compiler* compiler_;
  ParserTracer* tracer_;
};

}

#endif

