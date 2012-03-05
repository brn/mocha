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

#ifndef mocha_compiler_h_
#define mocha_compiler_h_
#include <useconfig.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/utils/compiler_facade.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/roaster.h>
namespace mocha {
class ExternalAst;
typedef SharedPtr<ErrorReporter> ErrorHandler;
typedef std::pair<const char*,ErrorHandler> ErrorHandlerPair;
typedef roastlib::unordered_map<std::string,ErrorHandler> ErrorMap;
typedef SharedPtr<ErrorMap> ErrorMapHandle;

/**
 * @class
 * Compiler of javascript for web front end develop.
 * Compiler class is made as thread safe and,
 * created only one instance per thread.
 * This class called by MochaMain.
 * @see MochaMain::CompileStart_
 */
class Compiler : private Uncopyable {
 public :

  /**
   * @constructor
   * @example
   * Compiler compiler("example.js");
   * compiler.Compile(); //Created example-cmp.js
   * @description
   * Compiler instance could create only Caompiler::CreateInstance.
   */
  Compiler (const char* filename,  FinishDelegator* callback);
  Compiler (CompilationInfoHandle);
  Compiler (CompilationInfoHandle, AsyncCallback);
  ~Compiler();
  
  /**
   * @public
   * Start compile.
   */
  void Compile ();

  /**
   * @public
   * @param {const char*} -> a path of module.
   * @example
   * var ExampleMod = require("./ExampleMod").ExampleMod;
   * @description
   * Load module file that the arguments of require function.
   * A path of module is determine that file is module or normal js file.
   * If path begin with './' or '../', that file is treat as normal js file,
   * if path is only '<filename>', that file is treat as module.
   * This rule borrow from node.js.
   */
  SharedStr Load (const char* filename);

  void CatchException(const char* filename, ErrorHandler handle);
  AstReserver GetAst(CompilationInfoHandle);
  SharedPtr<ExternalAst> GetAst(ErrorReporter* reporter, SharedPtr<PathInfo> info, bool is_runtime);
  /**
   * @public
   * @returns {SharedPtr<PathInfo>}
   * Get PathInfo of main file path.
   */
  SharedPtr<PathInfo> GetMainPathInfo();
 private :

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

};

}

#endif
