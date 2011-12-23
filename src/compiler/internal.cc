
#include <string.h>
#include <compiler/internal.h>
#include <compiler/scopes/scope.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/binding/parser_connector.h>
#include <compiler/compiler.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/io/file_io.h>
#include <utils/file_system/file_system.h>
#include <utils/file_system/virtual_directory.h>
#include <ast/ast.h>
#include <ast/visitors/ast_visitor.h>
#include <ast/visitors/codegen_visitor.h>
#include <options/setting.h>

namespace mocha {

#define FILE_EXIST file_exist_ = true
#define FILE_NOT_EXIST file_exist_ = false
  

Internal::Internal ( const char* main_file_path,
                     bool is_runtime,
                     Handle<PathInfo> path_info ,
                     Compiler* compiler,
                     Scope *scope,
                     CodegenVisitor *codegen,
                     AstRoot* ast_root ) :

    main_file_path_( main_file_path ),
    is_runtime_( is_runtime ),
    file_exist_ ( false ),
    compiler_ ( compiler ),
    scope_ ( scope ),
    ast_root_( ast_root ),
    codegen_ ( codegen ),
    path_info_( path_info ){}

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



inline void Internal::ParseStart_ () {
  std::string buf;
  file_->GetFileContents( buf );
  AstRoot root;
  mocha::ParserTracer tracer( path_info_->GetFileIdentifier().Get() );
  mocha::ParserConnector parser ( compiler_,
                                  &tracer,
                                  &root,
                                  buf );
  parser.ParseStart ();
  
  mocha::AstVisitor visitor ( is_runtime_ , scope_ , compiler_,
                              main_file_path_ , file_->GetFileName() );
  
  if ( !tracer.IsSyntaxError () ) {
    root.Accept ( &visitor );
    ast_root_->AddChild( root.FirstChild() );
  } else {
    printf( "Error occured.\n" );
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
  printf( "%s\n" , tmp );
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
  printf( "%s\n" , tmp );
}

}
