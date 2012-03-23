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
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/loader/loader.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
#include <mocha/roaster/nexc/parser/parser.h>
#include <mocha/roaster/nexc/scanner/scanner.h>
namespace mocha {
class LoadCompleteListener {
 public :
  LoadCompleteListener(Nexc* nexc, CompilationEvent* e)
      : compiler_(nexc),
        event_(e){}
  ~LoadCompleteListener(){}
  LoadCompleteListener(const LoadCompleteListener& listener) {
    compiler_ = listener.compiler_;
    event_ = listener.event_;
  }
  void operator()(IOEvent* e) {
    event_->set_source(e->data());
    compiler_->NotifyForKey(Nexc::kScan, event_);
  }
 private :
  Nexc* compiler_;
  CompilationEvent* event_;
};

class LoadErrorListener {
 public :
  LoadErrorListener(Nexc* nexc, CompilationEvent* e, bool fatal)
      : fatal_(fatal),
        compiler_(nexc),
        event_(e){}
  ~LoadErrorListener(){}
  LoadErrorListener(const LoadErrorListener& listener) {
    fatal_ = listener.fatal_;
    compiler_ = listener.compiler_;
    event_ = listener.event_;
  }
  void operator()(IOEvent* e) {
    event_->error_reporter()->ReportSysError(e->data());
    if (fatal_) {
      compiler_->NotifyForKey(Nexc::kFatal, event_);
    } else {
      compiler_->NotifyForKey(Nexc::kFail, event_);
    }
  }
 private :
  bool fatal_;
  Nexc* compiler_;
  CompilationEvent* event_;
};

Nexc::Nexc(CompilationInfo* info)
    : compilation_info_(info),
      virtual_directory_(os::fs::VirtualDirectory::GetInstance()),
      reporter_(new ErrorReporter),
      pool_(memory::Pool::Local()) {
  Initialize();
}


void Nexc::CompileFile(const char* filename, const char* charset) {
  os::fs::Path path_info(filename);
  CompilationEvent* event = CreateEvent(path_info, charset);
  DEBUG_LOG(Info, "Nexc::CompileFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
  virtual_directory_->set_current_directory(path_info.directory());
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
  loader.AddListener(Loader::kError, LoadErrorListener(this, event, true));
  loader.LoadFile(filename);
}


void Nexc::Compile(const char* source, const char* charset) {
  std::string cwd = os::fs::Path::current_directory();
  cwd += "/anonymous.js";
  os::fs::Path path_info(cwd.c_str());
  virtual_directory_->set_current_directory(path_info.directory());
  DEBUG_LOG(Info, "Nexc::Compile\nwith source\n[\n%s\n]", source);
  CompilationEvent* event = CreateEvent(path_info, charset);
  event->set_source(source);
  NotifyForKey(kScan, event);
}


void Nexc::ImportFile(CompilationEvent* e) {
  if (CheckGuard(e->absolute_path())) {
    guard_.insert(GuardPair(ab, true));
    virtual_directory_->set_current_directory(e->path());
    Loader loader;
    loader.AddListener(Loader::kComplete, LoadCompleteListener(this, e));
    loader.AddListener(Loader::kError, LoadErrorListener(this, e, true));
    loader.LoadFile(e->fullpath());
  }
}

bool Nexc::CheckGuard(const char* path) {
  if (guard_.find(ab) == guard_.end()) {
    guard_.insert(GuardPair(path, 1));
    return true;
  }
  return false;
}

void Nexc::Initialize() {
  AddListener(kScan, Scanner::ScannerEventListener());
  AddListener(kParse, Parser::ParseEventListener());
  AddListener(kImport, Bind(&ImportFile, this));
  //AddListener(kTransformAst, TransformEventLitener());
}

void Nexc::Abort(IOEvent* e) {
}

CompilationEvent* Nexc::CreateEvent(const os::fs::Path& path_info, const char* charset) {
  CompilationEvent* event = new(pool_.Get()) CompilationEvent(this, reporter_.Get(), pool_.Get());
  event->set_compilation_info(compilation_info_);
  event->set_charset(charset);
  event->set_mainfile_path(path_info.absolute_path());
  event->set_path(path_info.directory());
  event->set_filename(path_info.filename());
  event->set_fullpath(path_info.absolute_path());
  return event;
}

const char Nexc::kScan[] = {"Nexc<Scan>"};
const char Nexc::kParse[] = {"Nexc<Parse>"};
const char Nexc::kTransformAst[] = {"Nexc<TransformAst>"};
const char Nexc::kFatal[] = {"Nexc<Fatal>"};
const char Nexc::kFail[] = {"Nexc<Fail>"};
const char Nexc::kImport[] = {"Nexc<Import>"};
}
