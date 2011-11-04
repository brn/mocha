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

#ifndef Compiler_h
#define Compiler_h

#include "thread.h"
#include "scoped_ptr.h"
#include "compiler_starter.h"

namespace mocha {

/**
 * @class
 * Compiler of javascript for web front end develop.
 * Compiler class is made as thread safe and,
 * created only one instance per thread.
 * This class called by MochaMain.
 * @see MochaMain::CompileStart_
 */
class Compiler {
  friend class CompilerStarter;
 public :

  /**
   * @public
   * Start compile.
   */
  void Compile ();

  /**
   * @public
   * @param {const char*} -> a path of module.
   * @example
   * var ExampleMod = require( "./ExampleMod" ).ExampleMod;
   * @description
   * Load module file that the arguments of require function.
   * A path of module is determine that file is module or normal js file.
   * If path begin with './' or '../', that file is treat as normal js file,
   * if path is only '<filename>', that file is treat as module.
   * This rule borrow from node.js.
   */
  void Load ( const char* filename );
 private :
  
  /**
   * @public
   * Create Compiler's singleton instance.
   * This method callable only class MochaMain.
   */
  static Compiler* CreateInstance( const char* filename );

  /**
   * @private
   * @constructor
   * @example
   * Compiler compiler( "example.js" );
   * compiler.Compile(); //Created example-cmp.js
   * @description
   * Compiler instance could create only Caompiler::CreateInstance.
   */
  Compiler ( const char* filename );
  ~Compiler () {}

  /**
   * @private
   * @param {void*} -> compiler instance.
   * Desctruct signleton instance.
   */
  static void Destructor_( void* ptr );
  
  /**
   * @private
   * @class
   * Internal implementation of pimpl idiom.
   */
  class PtrImpl;

  /**
   * @private
   * Pointer manager of pimpl internal class.
   */
  ScopedPtr<PtrImpl> implementation_;

  /**
   * @private
   * Thread local storage key for get one only instance of per thread.
   */
  static ThreadLocalStorageKey local_key_;
  
  static Mutex mutex_;
  
};

}

#endif
