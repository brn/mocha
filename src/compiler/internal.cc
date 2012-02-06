#include <compiler/internal.h>
#include <compiler/scopes/scope.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/binding/parser_connector.h>
#include <compiler/compiler.h>
#include <compiler/parser/parser.h>
#include <compiler/scanner/token_stream.h>
#include <compiler/scanner/source_stream.h>
#include <compiler/scanner/scanner.h>
#include <compiler/tokens/js_token.h>
#include <compiler/utils/error_reporter.h>
#include <utils/xml/xml_setting_info.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/io/file_io.h>
#include <utils/file_system/file_system.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/pool/managed_handle.h>
#include <ast/ast.h>
#include <ast/visitors/ast_transformer.h>
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

void Internal::GetAst ( ErrorLevel level , ErrorReporter *reporter ) {
  LoadFile_ ();
  if ( file_exist_ || level == kNofatal ) {
    if ( file_exist_ ) {
      GetAst_( reporter );
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
    file_ = mocha::FileIO::Open ( path , "rb" );
    //Set bool to true.
    FILE_EXIST;
  } else {
    //Write error message to result.
    OpenError_();
    //Set bool to false.
    FILE_NOT_EXIST;
  }
}


inline void Internal::GetAst_ ( ErrorReporter *reporter ) {
  std::string buf;
  file_->GetFileContents( buf );
  SourceStream *source_stream = SourceStream::Create( buf.c_str() , main_file_path_ );
  Scanner *scanner = Scanner::Create( source_stream , reporter , file_->GetFileName() );
  ParserConnector connector( compiler_ , ast_root_ , scanner , source_stream , reporter );
  Parser parser( &connector , reporter , file_->GetFileName() );
  FileRoot* root = parser.Parse();
  AstTransformer visitor ( is_runtime_ , scope_ , compiler_,
                           main_file_path_ , file_->GetFileName() );
  if ( !reporter->Error() ) {
    AstRoot tmp_root;
    tmp_root.AddChild( root );
    tmp_root.Accept ( &visitor );
    ast_root_->AddChild( tmp_root.FirstChild() );
  } else {
    std::string error;
    reporter->SetError( &error );
    printf( "%s\n" , error.c_str() );
    ast_root_->AddChild( ManagedHandle::Retain<Empty>() );
  }
}


inline void Internal::ParseStart_ () {
  std::string buf;
  file_->GetFileContents( buf );
  ErrorHandler reporter( new ErrorReporter );
  SourceStream *source_stream = SourceStream::Create( buf.c_str() , main_file_path_ );
  Scanner *scanner = Scanner::Create( source_stream , reporter.Get() , file_->GetFileName() );
  ParserConnector connector( compiler_ , ast_root_ , scanner , source_stream , reporter.Get() );
  Parser parser( &connector , reporter.Get() , file_->GetFileName() );
  FileRoot* root = parser.Parse();
  AstTransformer visitor ( is_runtime_ , scope_ , compiler_,
                           main_file_path_ , file_->GetFileName() );
  compiler_->CatchException( file_->GetFileName() , reporter );
  if ( !reporter->Error() ) {
    AstRoot tmp_root;
    tmp_root.AddChild( root );
    tmp_root.Accept ( &visitor );
    ast_root_->AddChild( tmp_root.FirstChild() );
  } else {
    std::string buf;
    reporter->SetError( &buf );
    fprintf( stderr , "%s\n" , buf.c_str() );
    Setting::GetInstance()->Log( "syntax error found in file %s.",
                                 file_->GetFileName() );
    codegen_->Write ( buf.c_str() );
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
