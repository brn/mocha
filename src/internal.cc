
#include <string.h>
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
      Setting::GetInstance()->LogError( "%s/%s No such file or directory.\n",
                                        path_info_->GetDirPath().Get(),
                                        path_info_->GetFileName().Get() );
    }
  } else {
    Setting::GetInstance()->LogFatal( "%s/%s No such file or directory.\n",
                                      path_info_->GetDirPath().Get(),
                                      path_info_->GetFileName().Get() );
  }
}

inline void Internal::LoadFile_ () {
  char path[ 1000 ];
  sprintf( path , "%s/%s",
           path_info_->GetDirPath().Get(),
           path_info_->GetFileName().Get() );
  printf ( "path is %s\n" , path );
  printf("%s\n",path_info_->GetDirPath().Get());
  printf("%s\n",path_info_->GetFileName().Get());
  //Check is file exist.
  if ( mocha::FileIO::IsExist ( path ) ) {
    file_ = mocha::FileIO::Open ( path , "r" );
    //Set bool to true.
    FILE_EXIST;
  } else {
    //Write error message to result.
    OpenError_();
    //Set bool to false.
    FILE_NOT_EXIST;
  }
}



void GetModuleKey( std::string& buf , const char* path , const char* filename ) {
  std::string tmp;
  for ( int i = 0,len = strlen( path ); i < len; i++ ) {
    if ( path[ i ] == '/' ) {
      tmp += "$/";
    }
  }
  tmp += filename;
  buf += tmp;
  VirtualDirectory::GetInstance()->SetModuleKey( tmp.c_str() );
}



inline void Internal::ParseStart_ () {
  std::string buf;
  buf += "__global_exports[\"";
  GetModuleKey( buf , path_info_->GetDirPath().Get(), path_info_->GetFileName().Get() );
  buf += "\"] = ";
  buf += "(function(){var exports={};";
  file_->GetFileContents( buf );
  buf += "return exports;})();";
  printf("%s\n" , file_->GetDate().Get());
  mocha::ParserTracer tracer( path_info_->GetFileIdentifier().Get() );
  mocha::Scanner scanner ( buf.c_str() , &tracer );
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
    SyntaxError_( tracer );
    Setting::GetInstance()->Log( "syntax error found in file %s.",
                                 file_->GetFileName() );
  }
}

inline void Internal::OpenError_() {
  char tmp[ 10000 ];
  sprintf( tmp ,
           "try{\n"
           "  throw new SyntaxError(\"%s No such file or directory\")\n"
           "}catch(e){\n"
           "  throw new Error(e);\n"
           "}\n;" , path_info_->GetFileIdentifier().Get() );
  codegen_->Write ( tmp );
}

inline void Internal::SyntaxError_( const ParserTracer& tracer ) {
  char tmp[ 10000 ];
  sprintf( tmp ,
           "try{\n"
           "  throw new SyntaxError(\"%s in file %s at : %ld\")\n"
           "}catch(e){\n"
           "  throw new Error(e);\n"
           "}\n;",
           tracer.GetErrorMessage(),
           file_->GetFileName(),
           tracer.GetErrorLine () );
  codegen_->Write ( tmp );
}

}
