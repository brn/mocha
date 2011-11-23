#ifndef mocha_pretty_printer_h_
#define mocha_pretty_printer_h_

#include <string>
#include "ast_foward_decl.h"

namespace mocha {
class CodeWriter {
 public :
  enum {
    kNone = 0,
    kFunctionBeginBrace,
    kFunctionEndBrace,
    kSwitchEndBrace,
    kBlockBeginBrace,
    kBlockEndBrace,
    kArgs,
    kFor,
    kVarsComma,
    kVarsEnd,
    kParenExp,
    kCase,
    kNewNoArgsBegin,
    kNewNoArgsEnd,
    kElseBlockEnd
  };
  CodeWriter( bool is_pretty_print , bool is_line );
  ~CodeWriter();
  void Write( const char* code , std::string& buffer );
  void WriteOp( int op , int state , std::string& buffer );
  void InsertDebugSymbol( std::string& buffer );
  void InitializeFileName( const char* file , std::string& buffer );
  void SetFileName( std::string& buffer );
  void SetLine( long line ,  std::string& buffer );
  void ModuleBeginProccessor( const char* key , const char* name , std::string& buffer );
  void ModuleEndProccessor( std::string& buffer );
  class WriterBase;
 private :
  bool is_pretty_print_;
  bool is_line_;
  WriterBase* base_;
};
}

#endif
