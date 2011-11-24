/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
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
#include "compiler.h"
#include "internal.h"
#include "codegen.h"
#include "scope.h"
#include "handle.h"
#include "file_io.h"
#include "managed_handle.h"
#include "ast.h"
#include "codegen_visitor.h"
#include "file_system.h"
#include "xml_reader.h"
#include "compiler_utils.h"
#include "setting.h"
#include "xml_setting_info.h"


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

  PtrImpl( Compiler* compiler , const char* main_file_path ) :
      compiler_( compiler ) , codegen_( new CodegenVisitor( XMLSettingInfo::GetCompileOption( main_file_path ) ) ) {
    main_file_path_ = main_file_path;
    SetPath_( main_file_path );
    //Change direcotry to main js path.
    path_info_ = CompilerUtils::ChangeDir( main_file_path );
    Setting::GetInstance()->Log( "file %s compile start." , main_file_path );
  }

  inline void Compile() {
    CallInternal_( path_info_ , Internal::kFatal );
    ast_root_.Accept( codegen_.Get() );
    Write_ ( codegen_->GetCode() );
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
      CallInternal_( path_info , Internal::kNofatal );
    }
    return js_path;
  }

  
  inline void Write_ ( const char* script ) {
    //Current directory -> main js file path.
    //Get file name of main js file.
    char tmp[ 1000 ];
    sprintf( tmp , "%s/%s" , path_info_->GetDirPath().Get() , path_info_->GetFileName().Get() );

    //Get deploy path of -cmp.js file.
    StrHandle handle = XMLSettingInfo::GetDeployPath( tmp );
    
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


  
  inline void CallInternal_( Handle<PathInfo> path_info , Internal::ErrorLevel error_level ) {
    Internal internal ( path_info , compiler_ , &scope_ , codegen_.Get() , &ast_root_ );
    internal.Parse ( error_level );
  }

  
  std::string main_file_path_;
  boost::unordered_map<std::string,int> loaded_path_;
  Compiler *compiler_;
  Scope scope_;
  AstRoot ast_root_;
  Handle<PathInfo> path_info_;
  ScopedPtr<CodegenVisitor> codegen_;
};



//////////////////////////////////////////
// class Compiler implementation begin. //
//////////////////////////////////////////

Compiler* Compiler::CreateInstance( const char* filename ) {
  //Get thread local instance.
  Compiler* instance = reinterpret_cast<Compiler*>( ThreadLocalStorage::Get( &local_key_ ) );

  if ( instance == NULL ) {
    //Get lock.
    MutexLock lock( mutex_ );
    instance = new Compiler( filename );

    //Set Instance to tsd.
    ThreadLocalStorage::Set( &local_key_ , instance );
    lock.Unlock();
  }
  return instance;
}

Compiler::Compiler ( const char* filename ) :
    implementation_ ( new PtrImpl( this , filename ) ) {}


void Compiler::Compile () {
  mocha::ManagedScope managed_scope;
  implementation_->Compile();
}

Handle<PathInfo> Compiler::GetMainPathInfo () {
  return implementation_->path_info_;
}

void Compiler::Destructor_( void* ptr ) {
  Compiler *compiler = reinterpret_cast<Compiler*>( ptr );
  delete compiler;
}


StrHandle Compiler::Load ( const char* filename ) {
  return implementation_->Load( filename );
}

ThreadLocalStorageKey Compiler::local_key_( Compiler::Destructor_ );

Mutex Compiler::mutex_;

} //namespace mocha
