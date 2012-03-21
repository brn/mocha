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
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/loader/loader.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
namespace mocha {
class LoadCompleteListener {
 public :
  LoadCompleteListener(Nexc* compiler)
      : compiler_(compiler){}
  ~LoadCompleteListener(){}
  LoadCompleteListener(const LoadCompleteListener& listener) {
    compiler_ = listener.compiler_;
  }
  void operator()(IOEvent* e) {
    compiler_->event()->set_source(e->data());
    compiler_->NotifyForKey(Nexc::kParse, compiler_->event());
  }
 private :
  Nexc* compiler_;
};

class LoadErrorListener {
 public :
  LoadErrorListener(Nexc* nexc, bool fatal)
      : fatal_(fatal),
        compiler_(nexc){}
  ~LoadErrorListener(){}
  LoadErrorListener(const LoadErrorListener& listener) {
    fatal_ = listener.fatal_;
    compiler_ = listener.compiler_;
  }
  void operator()(IOEvent* e) {
    compiler_->event()->error_reporter()->ReportSysError(e->data());
    if (fatal_) {
      compiler_->NotifyForKey(Nexc::kFatal, compiler_->event());
    } else {
      compiler_->NotifyForKey(Nexc::kFail, compiler_->event());
    }
  }
 private :
  bool fatal_;
  Nexc* compiler_;
};


Nexc::Nexc()
    : reporter_(new ErrorReporter),
      pool_(memory::Pool::Local()){
  Initialize();
}

void Nexc::CompileFile(const char* filename, const char* charset) {
  event_->set_charset(charset);
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this));
  loader.AddListener(Loader::kError, LoadErrorListener(this, true));
  loader.LoadFile(filename);
}

void Nexc::Compile(const char* source, const char* charset) {}

void Nexc::Initialize() {
  event_ = new(pool_.Get()) CompilationEvent(this, reporter_.Get(), pool_.Get());
  //AddListener(kParse, Parser::ParseEventListener());
  //AddListener(kTransformAst, TransformEventLitener());
}

void Nexc::Abort(IOEvent* e) {
}

const char Nexc::kParse[] = {"Nexc<Parse>"};
const char Nexc::kTransformAst[] = {"Nexc<TransformAst>"};
const char Nexc::kFatal[] = {"Nexc<Fatal>"};
const char Nexc::kFail[] = {"Nexc<Fail>"};
const char Nexc::kImport[] = {"Nexc<Import>"};
}
