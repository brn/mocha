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
#include <mocha/roaster/misc/atomic.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/ast/translator/translator.h>
#include <mocha/roaster/ast/seriarization/packer.h>
#include <mocha/roaster/ast/seriarization/unpacker.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/loader/loader.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
#include <mocha/roaster/nexc/parser/parser.h>
#include <mocha/roaster/nexc/scanner/scanner.h>
#include <mocha/roaster/nexc/utils/utils.h>
#ifndef PACKING_RUNTIME
#endif
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
    compiler_->set_current_directory(event_->path());
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
    : token_initialized_(0),
      compilation_info_(info),
      reporter_(new ErrorReporter),
      pool_(memory::Pool::Local()),
      virtual_directory_(os::fs::VirtualDirectory::Local()),
      builder_(AstBuilder::Local()) {
  Initialize();
}


void Nexc::CompileFile(const char* filename, const char* charset) {
  os::fs::Path path_info(filename);
  CheckGuard(path_info.absolute_path());
  CompilationEvent* event = CreateEvent(path_info, charset);
  event->set_mainfile_path(path_info.absolute_path());
  DEBUG_LOG(Info, "Nexc::CompileFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
  loader.AddListener(Loader::kError, LoadErrorListener(this, event, true));
  loader.LoadFile(filename);
}

#ifdef PACKING_RUNTIME
struct NodeHolder {
  static AstRoot* root;
};
AstRoot* NodeHolder::root;
void Nexc::PackFile(const Results& results) {
  ByteOrder order;
  FILE* fp = os::FOpen(CURRENT_DIR"/src/mocha/roaster/nexc/runtime/runtime.h", "w+");
  std::stringstream st;
  st << "#ifndef mocha_roaster_nexc_runtime_runtime_h_"
     << "\n#include <mocha/roaster/lib/unordered_map.h>\n"
     << "\n#include <mocha/roaster/misc/int_types.h>\n"
     << "namespace mocha {\n";
  typedef std::vector<std::string> Vars;
  Vars vars;
  for (Results::const_iterator it = results.begin(); it != results.end(); ++it) {
    Packed packed;
    Packer packer(&packed, &order);
    (*it).second->Accept(&packer);
    std::string path = (*it).first;
    path.erase(path.size() - 3, 3);
    st << "static int32_t " << path << "[] = {\n";
    for (Packed::iterator it = packed.begin(); it != packed.end();) {
      st << (*it);
      ++it;
      if (it != packed.end()) {
        st << ',';
      }
    }
    st << "};\n";
    vars.push_back(path);
  }
  st << "class JSRuntime {\n"
     << "private :\n"
     << "typedef roastlib::unordered_map<std::string, int*> RuntimeMap;\n"
     << "static RuntimeMap map_;\n"
     << "public :\nstatic void Initialize() {\n";
  for (Vars::iterator it = vars.begin(); it != vars.end(); ++it) {
    st << "map_.insert(std::pair<const char*,int32_t*>(\"" << (*it) << "\", " << (*it) << "));\n";
  }
  st << "}\nstatic bool Has(const char* filename) {return map_.find(filename) != map_.end();}\n"
     << "static int32_t* Get(const char* filename) {return map_.find(filename)->second;}\n"
     << "};JSRuntime::RuntimeMap JSRuntime::map_;\n}\n#endif";
  std::string ret = st.str();
  if (fp != NULL) {
    fputs(ret.c_str(), fp);
    fclose(fp);
  }
}

void Nexc::SetResult(CompilationEvent* e) {
  NodeHolder::root->AddChild(e->ast());
}

AstRoot* Nexc::GetResult() {
  AstNode *tmp = NodeHolder::root->Clone(pool_.Get());
  return reinterpret_cast<AstRoot*>(tmp);
}

void Nexc::Pack(const char* filename) {
  NodeHolder::root = new(pool_.Get()) AstRoot;
  RemoveListener(kCompilationSucessed);
  AddListener(kCompilationSucessed, Bind(&Nexc::SetResult, this));
  os::fs::Path path_info(filename);
  CheckGuard(path_info.absolute_path());
  CompilationEvent* event = CreateEvent(path_info, "UTF-8");
  event->set_mainfile_path(path_info.absolute_path());
  DEBUG_LOG(Info, "Nexc::CompileFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
  loader.AddListener(Loader::kError, LoadErrorListener(this, event, true));
  loader.LoadFile(filename);
}
#else
AstRoot* Nexc::GetResult() {
  return root_;
}
#endif

void Nexc::Compile(const char* source, const char* charset) {
  std::string cwd = os::fs::Path::current_directory();
  cwd += "/anonymous.js";
  os::fs::Path path_info(cwd.c_str());
  DEBUG_LOG(Info, "Nexc::Compile\nwith source\n[\n%s\n]", source);
  CompilationEvent* event = CreateEvent(path_info, charset);
  event->set_mainfile_path(path_info.absolute_path());
  event->set_source(source);
  NotifyForKey(kScan, event);
}


void Nexc::ImportFile(std::string* buf, const char* path, CompilationEvent* e) {
  const char* current = virtual_directory_->current_directory();
  std::string module_path;
  os::SPrintf(&module_path, "%s/%s.js", current, path);
  os::fs::Path path_info(module_path.c_str());
  nexc_utils::ManglingName(buf, path_info.filename(), path_info.directory());
  if (CheckGuard(path_info.absolute_path())) {
    DEBUG_LOG(Info, "Nexc::ImportFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
    CompilationEvent* event = CreateEvent(path_info, e->charset());
    event->set_mainfile_path(e->mainfile_path());
    guard_.insert(GuardPair(path_info.absolute_path(), true));
    Loader loader;
    loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
    loader.AddListener(Loader::kError, LoadErrorListener(this, event, false));
    loader.LoadFile(event->fullpath());
  }
}

void Nexc::set_current_directory(const char* path) {
  virtual_directory_->set_current_directory(path);
}

bool Nexc::CheckGuard(const char* path) {
  if (guard_.find(path) == guard_.end()) {
    guard_.insert(GuardPair(path, 1));
    return true;
  }
  return false;
}

void Nexc::Initialize() {
  AtomicWord ret = Atomic::CompareAndSwap(&token_initialized_, 0, 1);
  if ( ret == 1) {
    return;
  } else {
    token_initialized_ = 1;
    JsToken::Initialize();
    Loader::Initialize();
  }
  root_ = new(pool_.Get()) AstRoot;
#ifndef PACKING_RUNTIME
  AstNode* root = Loader::MainRuntime(pool_.Get());
  root_->AddChild(root);
#endif
  AddListener(kScan, Scanner::ScannerEventListener());
  AddListener(kParse, Parser::ParseEventListener());
  AddListener(kTransformAst, Translator::TransformEventLitener());
  AddListener(kCompilationSucessed, Bind(&Nexc::Success, this));
}

void Nexc::Abort(IOEvent* e) {
}

void Nexc::Success(CompilationEvent* e) {
  root_->AddChild(e->ast());
}


CompilationEvent* Nexc::CreateEvent(const os::fs::Path& path_info, const char* charset) {
  CompilationEvent* event = new(pool_.Get()) CompilationEvent(this, reporter_.Get(), pool_.Get());
  event->set_compilation_info(compilation_info_);
  event->set_path(path_info.directory());
  event->set_charset(charset);
  event->set_filename(path_info.filename());
  event->set_fullpath(path_info.absolute_path());
  return event;
}

const char Nexc::kScan[] = {"Nexc<Scan>"};
const char Nexc::kParse[] = {"Nexc<Parse>"};
const char Nexc::kTransformAst[] = {"Nexc<TransformAst>"};
const char Nexc::kCompilationSucessed[] = {"Nexc<CompilationSucessed>"};
const char Nexc::kCompilationFailed[] = {"Nexc<CompilationFailed>"};
const char Nexc::kFatal[] = {"Nexc<Fatal>"};
const char Nexc::kFail[] = {"Nexc<Fail>"};
}
