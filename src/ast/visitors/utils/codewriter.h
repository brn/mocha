#ifndef mocha_pretty_printer_h_
#define mocha_pretty_printer_h_

#include <string>
#include <ast/ast_foward_decl.h>
#include <ast/visitors/utils/codegenerator_utils.h>

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
    kElseBlockEnd,
    kNamedModule,
    kAnonymousModule,
    kExpSp,
  };
  CodeWriter( bool is_pretty_print , bool is_line );
  ~CodeWriter();
  void Write( const char* code , CodeStream* stream_ );
  void WriteOp( int op , int state , CodeStream* stream_ );
  void InsertDebugSymbol( CodeStream* stream_ );
  void InitializeFileName( const char* file , CodeStream* stream_ );
  void SetFileName( CodeStream* stream_ );
  void SetLine( long line , CodeStream* stream_ );
  void ModuleBeginProccessor( const char* key , const char* name , CodeStream* stream_ );
  void AnonymousModuleBeginProccessor( const char* key , CodeStream* stream_ );
  void ModuleEndProccessor( CodeStream* stream_ );
  void AnonymousModuleEndProccessor( CodeStream* stream_ );
  class WriterBase;
 private :
  bool is_pretty_print_;
  bool is_line_;
  WriterBase* base_;
};
}

#endif
