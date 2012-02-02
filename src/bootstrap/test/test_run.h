#ifndef mocha_test_run_h_
#define mocha_test_run_h_
#include <compiler/compiler.h>
#include <compiler/utils/compiler_facade.h>
#include <utils/file_system/file_system.h>
#include <bootstrap/bootstrap.h>
#include <utils/smart_pointer/ref_count/handle.h>
namespace mocha {namespace compiler_test {

std::string GetPath( const char* path ) {
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( Bootstrap::GetSelfPath() );
  std::string result = path_info->GetDirPath().Get();
  result += '/';
  result += path;
  return result;
}



void RunTest() {
  std::string expression_test = FileSystem::NormalizePath( GetPath( "../../src/bootstrap/test/js/expression_test.js" ).c_str() ).Get();
  std::string for_test = FileSystem::NormalizePath( GetPath( "../../src/bootstrap/test/js/for_test.js" ).c_str() ).Get();
  std::string while_test = FileSystem::NormalizePath( GetPath( "../../src/bootstrap/test/js/while_test.js" ).c_str() ).Get();
  std::string function_test = FileSystem::NormalizePath( GetPath( "../../src/bootstrap/test/js/function_test.js" ).c_str() ).Get();
  CompilerFacade facade;
  fprintf( stderr , "@@@@@ expression test begin.\n" );
  facade.AddCompileList( expression_test.c_str() , false );
  fprintf( stderr , "@@@@@ for test begin.\n" );
  facade.AddCompileList( for_test.c_str() , false );
  fprintf( stderr , "@@@@@ while test begin.\n" );
  facade.AddCompileList( while_test.c_str() , false );
  fprintf( stderr , "@@@@@ function test begin.\n" );
  facade.AddCompileList( function_test.c_str() , false );
  facade.Compile();/*
  CompilerFacade::Compile( expression_test.c_str() , true );
  CompilerFacade::Compile( for_test.c_str()  , true);
  CompilerFacade::Compile( while_test.c_str() , true );
  CompilerFacade::Compile( function_test.c_str() , true );*/
}

}}
#endif
