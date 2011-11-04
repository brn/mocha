
#include "internal.h"
#include "handle.h"
#include "scope.h"
#include "codegen.h"
#include "file_io.h"
#include "parser_tracer.h"
#include "parser_connector.h"
#include "ast_type.h"
#include "ast_visitor.h"
#include "scanner.h"
#include "file_system.h"
#include "compiler.h"
#include "codegen_visitor.h"
#include "setting.h"
#include "virtual_directory.h"

namespace mocha {

#define FILE_EXIST file_exist_ = true
#define FILE_NOT_EXIST file_exist_ = false
#define OPEN_ERROR                                                      \
  error_ = "try{throw new SyntaxError(\"";                              \
  error_ += path_info_->GetFileIdentifier();                            \
  error_ += " No such file or directory";                               \
  error_ += "\")}catch(e){throw new Error(e);};";                       \
  codegen_->Write ( &error_ [ 0 ] )

#define SYNTAX_ERROR                                                    \
  std::string str;                                                      \
  char line [100];                                                      \
  sprintf ( line , "%ld" , tracer.GetErrorLine () );                   \
  str = "try{throw new SyntaxError( \"";                                \
  str += tracer.GetErrorMessage ();                                    \
  str += " in file ";                                                   \
  str += file_->getFileName ();                                         \
  str += " line : ";                                                    \
  str += line;                                                          \
  str += "\" )}catch(e){throw new Error(e);};"; \
  codegen_->Write ( &str [ 0 ] )

Internal::Internal ( Handle<PathInfo> path_info ,
                          Compiler* compiler,
                          Scope *scope,
                          CodegenVisitor *codegen,
                          AstRoot* ast_root ) :
  file_exist_ ( false ),
  compiler_ ( compiler ),
  scope_ ( scope ),
  codegen_ ( codegen ),
  ast_root_( ast_root ),
  path_info_( path_info )
{}

void Internal::Parse ( ErrorLevel level ) {
  LoadFile_ ();
  if ( file_exist_ || level == kNofatal ) {
    if ( file_exist_ ) {
      ParseStart_ ();
    } else {
      Setting::GetInstance()->LogError( "%s No such file or directory.\n",
                                        file_->getFileName() );
    }
  } else {
    Setting::GetInstance()->LogFatal( "%s No such file or directory.\n",
                                      file_->getFileName() );
  }
}

inline void Internal::LoadFile_ () {
  std::string tmp = path_info_->GetDirPath();
  tmp += "/";
  tmp += path_info_->GetFileName();
  const char* path = tmp.c_str();
  printf ( "path is %s\n" , path );
  printf("%s\n",path_info_->GetDirPath());
  printf("%s\n",path_info_->GetFileName());
  //Check is file exist.
  if ( mocha::FileIO::isExist ( path ) ) {
    file_ = mocha::FileIO::Open ( path , "r" );
    //Set bool to true.
    FILE_EXIST;
  } else {
    //Write error message to result.
    OPEN_ERROR;
    //Set bool to false.
    FILE_NOT_EXIST;
  }
}

inline void Internal::ParseStart_ () {
  mocha::CStrHandle handle = file_->getFileContents ();
  printf("%s\n" , file_->getDate().get());
  mocha::ParserTracer tracer( path_info_->GetFileIdentifier() );
  mocha::Scanner scanner ( handle.get () , &tracer );
  mocha::ParserConnector parser ( compiler_,
                                &scanner,
                                &tracer,
                                ast_root_,
                                scope_ );
  scope_ = scope_->GetGlobal ();
  parser.ParseStart ();
  
  /**mocha::AstVisitor visitor ( scope_,
                            codegen_,
                            tracer.GetModuleName (),
                            filename_.c_str () );
  **/
  if ( !tracer.IsSyntaxError () ) {
    //ast_root->Accept ( &visitor );
  } else {
    SYNTAX_ERROR;
    printf( "%s\n",file_->getFileName() );
    Setting::GetInstance()->Log( "syntax error found in file %s.",
                                 file_->getFileName() );
  }
}

}
