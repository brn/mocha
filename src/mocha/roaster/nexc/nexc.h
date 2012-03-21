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
#ifndef mocha_roaster_compiler_compiler_h_
#define mocha_roaster_compiler_compiler_h_
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/notificator/notificator.h>
namespace mocha {
class IOEvent;
class CompilationEvent;
class ErrorReporter;
class Nexc : public Notificator<CompilationEvent*>{
 public :
  Nexc();
  ~Nexc(){};
  void CompileFile(const char* filename, const char* charset = NULL);
  void Compile(const char* source, const char* charset = NULL);
  CompilationEvent* event() {return event_;}
  static const char kParse[];
  static const char kTransformAst[];
  static const char kFatal[];
  static const char kFail[];
  static const char kImport[];
 private :
  void Initialize();
  void ImportFile(const char* filename);
  void Abort(IOEvent* e);
  CompilationEvent* event_;
  SharedPtr<ErrorReporter> reporter_;
  SharedPtr<memory::Pool> pool_;
};
}
#endif
