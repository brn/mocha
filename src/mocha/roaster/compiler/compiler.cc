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
#include <assert.h>
#include <mocha/roaster/compiler/compiler.h>
#include <mocha/roaster/compiler/loader/loader.h>
namespace roaster {

class LoadCompleteListener {
 public :
  LoadCompleteListener(Compiler* compiler)
      : compiler_(compiler){}
  ~LoadCompleteListener(){}
  LoadCompleteListener(const LoadCompleteListener& listener) {
    compiler_ = listener.compiler_;
  }
  void operator()(IOEvent* e) {
    
  }
 private :
  Compiler* compiler_;
};

class LoadErrorListener {
 public :
  LoadCompleteListener(bool fatal)
      : fatal_(fatal),
        compiler_(compiler){}
  ~LoadCompleteListener(){}
  LoadCompleteListener(const LoadErrorListener& listener) {
    fatal_ = listener.fatal_;
    compiler_ = listener.compiler_;
  }
  void operator()(IOEvent* e) {
    
  }
 private :
  bool fatal_
  Compiler* compiler_;
}

Compiler::Compiler() {
  Initialize();
}

void Compiler::CompileFile(const char* filename) {
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this));
  loader.AddListener(Loader::kError, LoadErrorListener(true, this));
}

void Compiler::Compile(const char* source) {}

void Compiler::Initialize() {
  AddListener()
}

const char Compiler::kParse[] = {"Compiler<Parse>"};
const char Compiler::kFatal[] = {"Compiler<Fatal>"};
const char Compiler::kImport[] = {"Compiler<Import>"};
}
