/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <boost/unordered_map.hpp>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/internal.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/utils/compile_result.h>
#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/external/external_ast.h>
#include <utils/io/file_io.h>
#include <utils/pool/managed_handle.h>
#include <utils/file_system/file_system.h>
#include <utils/file_system/stat.h>
#include <utils/xml/xml_reader.h>
#include <utils/xml/xml_setting_info.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/ast/visitors/symbol_collector.h>
#include <mocha/roaster/ast/visitors/optimizer_visitor.h>
#include <options/setting.h>


///////////////////////////////////////////////////
// class Compiler::PtrImpl implementation begin. //
///////////////////////////////////////////////////
namespace mocha {

/**
 *@class
 *Implementation of pimpl idiom.
 */
class Compiler::PtrImpl {
  friend class Compiler;
 public :
                                
  PtrImpl( Compiler* compiler , const char* main_file_path , FinishDelegator* callback ) :
      compiler_( compiler ),
      main_file_path_( main_file_path ),
      codegen_( new CodegenVisitor( main_file_path_.c_str() , ExternalResource::SafeGet( main_file_path )->GetCompileInfo() ) ),
      callback_( callback ){
    SetPath_( main_file_path );
    //Change direcotry to main js path.
    path_info_ = CompilerUtils::ChangeDir( main_file_path );
    Setting::GetInstance()->Log( "file %s compile start." , main_file_path );
    error_map_( new ErrorMap );
  }

  inline void Compile() {
    //LoadRuntime_();
    ast_root_.AddChild( ExternalResource::SafeGetRuntime() );
    CallInternal_( path_info_ , Internal::kFatal , false );
    OptimizerVisitor opt_visitor( ExternalResource::SafeGet( main_file_path_.c_str() )->GetCompileInfo() );
    SymbolCollector visitor( &scope_registry_ , ExternalResource::SafeGet( main_file_path_.c_str() )->GetCompileInfo()->Debug() );
    ast_root_.Accept( &visitor );
    ast_root_.Accept( &opt_visitor );
    if ( ExternalResource::SafeGet( main_file_path_.c_str() )->GetCompileInfo()->Compress() ) {
      scope_registry_.Rename();
    }
    ast_root_.Accept( codegen_.Get() );
    Write_( codegen_->GetCode() );
    callback_->Delegate( Handle<CompileResult>( new CompileResult( main_file_path_.c_str() , codegen_ , error_map_ ) ) );
    return;
  }

  inline StrHandle Load( const char* filename ) {
    //Create javascript path from filename.
    //It's like this,
    //"./example" -> "<current absolute path>/example.js" or
    //"exampleModule" -> "<setted absolute module dir path> or <default absolute module path>/exampleModule.js"
    StrHandle js_path = CompilerUtils::CreateJsPath( filename , main_file_path_.c_str() );

    //Check is module already loaded or not.
    if ( IsAlreadyLoaded_( js_path.Get() ) ) {
      //Change current directory to loaded js file directory.
      Handle<PathInfo> path_info = CompilerUtils::ChangeDir( js_path.Get() );
      //Set loaded file to hash.
      SetPath_( js_path.Get() );
      CallInternal_( path_info , Internal::kNofatal , false );
    }
    return js_path;
  }


  inline Handle<ExternalAst> GetAst( ErrorReporter *handler , Handle<PathInfo> path_info , bool is_runtime ) {
    Handle<ExternalAst> external_ast = ExternalAst::Create();
    Internal internal( main_file_path_.c_str() , is_runtime ,
                       path_info , compiler_ , &scope_registry_ , codegen_.Get() , external_ast->GetRoot() );
    internal.GetAst( Internal::kFatal , handler );
    return external_ast;
  }
                                
  inline void Write_ ( const char* script ) {
    //Current directory -> main js file path.
    //Get file name of main js file.
    char tmp[ 1000 ];
    Resources* res = ExternalResource::SafeGet( main_file_path_.c_str() );
    if ( res->GetDeploy() ) {
      const char* dir = res->GetDeploy();
      Stat stat( dir );
      if ( stat.IsExist() && stat.IsDir() ) {
        sprintf( tmp , "%s/%s" , res->GetDeploy() , path_info_->GetFileName().Get() );
      } else {
        FileSystem::Mkdir( dir , 0777 );
        FileSystem::Chmod( dir , 0777 );
        sprintf( tmp , "%s/%s" , res->GetDeploy() , path_info_->GetFileName().Get() );
      }
    } else {
      sprintf( tmp , "%s/%s" , path_info_->GetDirPath().Get() , path_info_->GetFileName().Get() );
    }

    //Get deploy path of -cmp.js file.
    StrHandle handle = res->GetDeployName( tmp );
                                                                
    Handle<File> ret = FileIO::Open ( handle.Get(),
                                      "rwn",
                                      FileIO::P_ReadWrite );
    Setting::GetInstance()->Log( "deploy to %s" , handle.Get() );
    //Set permission to rw for all.
    FileSystem::Chmod( handle.Get() , 0777 );
    ret->Write ( script );
  }

 private :
  /**
   *@private
   *@param {const char*} -> Path of loaded file.
   *@return {bool} -> Path was already loaded or not.
   *Check duplicate entry.
   *If loaded file is already loaded, return false.
   */
  inline bool IsAlreadyLoaded_( const char* path ) { return loaded_path_.find( path ) == loaded_path_.end(); }

  /**
   *@private
   *@param {const char*} -> Path of loaded file.
   *Set loaded file to duplicate entry.
   */
  inline void SetPath_( const char* path ) { loaded_path_.insert( std::pair<const char* , int>( path , 1 ) ); }


                                
  inline void CallInternal_( Handle<PathInfo> path_info , Internal::ErrorLevel error_level , bool is_runtime ) {
    Internal internal( main_file_path_.c_str() , is_runtime ,
                       path_info , compiler_ , &scope_registry_ , codegen_.Get() , &ast_root_ );
    internal.Parse( error_level );
  }

  inline void LoadRuntime_() {
    Handle<PathInfo> info = CompilerUtils::GetRuntimePathInfo();
    CallInternal_( info , Internal::kFatal , true );
  }

                                
  std::string main_file_path_;
  ErrorMapHandle error_map_;
  boost::unordered_map<std::string,int> loaded_path_;
  Compiler *compiler_;
  AstRoot ast_root_;
  Handle<PathInfo> path_info_;
  Handle<CodegenVisitor> codegen_;
  ScopeRegistry scope_registry_;
  FinishDelegator* callback_;
};



//////////////////////////////////////////
// class Compiler implementation begin. //
//////////////////////////////////////////

Compiler* Compiler::CreateInstance( const char* filename , FinishDelegator* callback ) {
  //MutexLock lock( mutex_ );
  //Get thread local instance.
  Compiler* instance = reinterpret_cast<Compiler*>( ThreadLocalStorage::Get( &local_key_ ) );

  if ( instance == NULL ) {
    instance = new Compiler( filename , callback );
    //Set Instance to tsd.
    ThreadLocalStorage::Set( &local_key_ , instance );
  }
  return instance;
}

Compiler::Compiler ( const char* filename , FinishDelegator* callback ){
  implementation_ ( new PtrImpl( this , filename , callback ) );
}


void Compiler::Compile () {
  ManagedScope managed_scope;
  implementation_->Compile();
}


void Compiler::CatchException( const char* filename , ErrorHandler handler ) {
  MutexLock lock( mutex_ );
  implementation_->error_map_->Insert( filename , handler );
}


Handle<PathInfo> Compiler::GetMainPathInfo () {
  return implementation_->path_info_;
}

void Compiler::Destructor_( void* ptr ) {
  Compiler *compiler = reinterpret_cast<Compiler*>( ptr );
  delete compiler;
}

Handle<ExternalAst> Compiler::GetAst( ErrorReporter *handler , Handle<PathInfo> path_info , bool is_runtime ) {
  return implementation_->GetAst( handler , path_info , is_runtime );
}

StrHandle Compiler::Load ( const char* filename ) {
  return implementation_->Load( filename );
}

ThreadLocalStorageKey Compiler::local_key_( Compiler::Destructor_ );

Mutex Compiler::mutex_;

} //namespace mocha