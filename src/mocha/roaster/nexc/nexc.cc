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

/**
 * @class
 * The file load complete event listener functor.
 */
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
    event_->error_reporter()->ReportSyntaxError(e->data());
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
      deps_(new Dependencies),
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
  CombineLibs(event);
  event->set_mainfile_path(path_info.absolute_path());
  DEBUG_LOG(Info, "Nexc::CompileFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
  Loader loader;
  loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
  loader.AddListener(Loader::kError, LoadErrorListener(this, event, true));
  loader.LoadFile(filename);
#ifndef PACKING_RUNTIME
  AddRuntime(event);
  AddBase(event);
#endif
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
    /*CompilationInfo info;
    info.SetPrettyPrint();
    info.UnsetFileScope();
    info.UnsetGlobalScope();
    CodegenVisitor vit(true, false, &info);
    (*it).second->Accept(&vit);
    printf("%s\n", vit.GetCode());*/
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
     << "typedef std::pair<int32_t*, int> RuntimePair;"
     << "typedef roastlib::unordered_map<std::string, RuntimePair> RuntimeMap;\n"
     << "static RuntimeMap map_;\n"
     << "public :\nstatic void Initialize() {\n";
  for (Vars::iterator it = vars.begin(); it != vars.end(); ++it) {
    st << "map_.insert(std::pair<const char*,RuntimePair>(\"" << (*it) << "\", RuntimePair(" << (*it) << ", sizeof(" << (*it) << ") / sizeof( " << (*it) << "[0]))));\n";
  }
  st << "}\nstatic bool Has(const char* filename) {return map_.find(filename) != map_.end();}\n"
     << "static RuntimePair Get(const char* filename) {return map_.find(filename)->second;}\n"
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

void Nexc::Pack(const char* filename, bool runtime) {
  NodeHolder::root = new(pool_.Get()) AstRoot;
  RemoveListener(kCompilationSucessed);
  AddListener(kCompilationSucessed, Bind(&Nexc::SetResult, this));
  os::fs::Path path_info(filename);
  CheckGuard(path_info.absolute_path());
  CompilationEvent* event = CreateEvent(path_info, "UTF-8");
  event->set_mainfile_path(path_info.absolute_path());
  if (runtime) {
    event->set_runtime();
  }
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
  CombineLibs(event);
  event->set_mainfile_path(path_info.absolute_path());
  event->set_source(source);
  NotifyForKey(kScan, event);
#ifndef PACKING_RUNTIME
  AddRuntime(event);
  AddBase(event);
#endif
}

template <int type, const char* name>
void Nexc::AddEachRuntime(CompilationEvent* e, AstNode* root, memory::Pool* pool) {
  if (e->IsUsed(type)) {
    if (CheckGuard(name)) {
      AstNode* runtime = Loader::GetRuntime(name, pool, this, e);
      root->InsertBefore(runtime->first_child());
    }
  }
}

struct RuntimeNames {
  static const char kAssert[];
  static const char kClass[];
  static const char kDebug[];
  static const char kGenerator[];
  static const char kModule[];
  static const char kRecord[];
  static const char kSpread[];
  static const char kTrait[];
  static const char kTuple[];
};

#define DEF_NAMES(prop, value) const char RuntimeNames::k##prop[] = {value}
DEF_NAMES(Assert, "_assert");
DEF_NAMES(Class, "_es_class");
DEF_NAMES(Debug, "_debug");
DEF_NAMES(Generator, "_generator");
DEF_NAMES(Module, "_module");
DEF_NAMES(Record, "_record");
DEF_NAMES(Spread, "_spread");
DEF_NAMES(Trait, "_trait");
DEF_NAMES(Tuple, "_tuple");
#undef DEF_NAMES

void Nexc::AddRuntime(CompilationEvent* e) {
  if (compilation_info_->Runtime()) {
    if (compilation_info_->Debug()) {
      e->Use(CompilationEvent::kDebug);
      e->Use(CompilationEvent::kAssert);
    }
    memory::Pool* pool = pool_.Get();
    AddEachRuntime<CompilationEvent::kAssert, RuntimeNames::kAssert>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kClass, RuntimeNames::kClass>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kDebug, RuntimeNames::kDebug>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kGenerator, RuntimeNames::kGenerator>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kModule, RuntimeNames::kModule>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kRecord, RuntimeNames::kRecord>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kSpread, RuntimeNames::kSpread>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kTrait, RuntimeNames::kTrait>(e, root_, pool);
    AddEachRuntime<CompilationEvent::kTuple, RuntimeNames::kTuple>(e, root_, pool);
  }
}

void Nexc::AddBase(CompilationEvent* e) {
  if (compilation_info_->PrototypeExtensions()) {
    AstNode* proto = Loader::GetRuntime("_prototype", pool_.Get(), this, e);
    root_->InsertBefore(proto->first_child());
  }
  AstNode* root = Loader::GetRuntime("_base", pool_.Get(), this, e);
  root_->InsertBefore(root->first_child());
}

void Nexc::CombineLibs(CompilationEvent* e) {
  const Libs& lib = compilation_info_->libs();
  if (lib.size() > 0) {
    SourceStmt* prev = NULL;
    for (Libs::const_iterator it = lib.begin(); it != lib.end(); ++it) {
      SourceStmt* stmt = new(pool_.Get()) SourceStmt(it->c_str(), 0);
      std::string buf;
      IncludeFile(&buf, stmt->path(), e);
      stmt->set_contents(buf.c_str());
      if (prev == NULL) {
        prev = stmt;
        root_->InsertBefore(stmt);
      } else {
        root_->InsertAfter(stmt, prev);
        prev = stmt;
      }
    }
  }
}

void Nexc::IncludeFile(std::string* buf, const char* path, CompilationEvent* e) {
  if (Loader::IsRuntime(path)) {
    if (CheckGuard(path)) {
      guard_.insert(GuardPair(path, true));
      AstNode* root = Loader::GetRuntime(path, pool_.Get(), this, e);
      root_->Append(root);
      os::SPrintf(buf, "'%s'", path);
    }
  } else {
    SearchModule(path, buf);
    os::fs::Path path_info(buf->c_str());
    buf->clear();
    if (CheckGuard(path_info.absolute_path())) {
      Loader loader;
      if (!loader.LoadFile(path_info.absolute_path(), buf)) {
        ErrorReporter reporter;
        reporter.ReportSyntaxError(buf->c_str());
        buf->clear();
        reporter.SetError(buf);
      } else {
        guard_.insert(GuardPair(path_info.absolute_path(), true));
        deps_->push_back(path_info.absolute_path());
      }
    }
  }
  set_current_directory(e->path());
}

void Nexc::ImportFile(std::string* buf, std::string* filename_buf, const char* path, CompilationEvent* e) {
  if (Loader::IsRuntime(path)) {
    if (CheckGuard(path)) {
      guard_.insert(GuardPair(path, true));
      AstNode* root = Loader::GetRuntime(path, pool_.Get(), this, e);
      root_->Append(root);
      os::SPrintf(buf, "'%s'", path);
#ifndef PACKING_RUNTIME
      AddRuntime(e);
#endif
    }
  } else {
    std::string module_path;
    SearchModule(path, &module_path);
    os::fs::Path path_info(module_path.c_str());
    filename_buf->assign(path_info.absolute_path());
    nexc_utils::ManglingName(buf, path_info.filename(), path_info.directory());
    if (CheckGuard(path_info.absolute_path())) {
      deps_->push_back(path_info.absolute_path());
      DEBUG_LOG(Info, "Nexc::ImportFile\nwith file\n[\n'%s'\n]", path_info.absolute_path());
      CompilationEvent* event = CreateEvent(path_info, e->charset());
      event->set_mainfile_path(e->mainfile_path());
      guard_.insert(GuardPair(path_info.absolute_path(), true));
      Loader loader;
      loader.AddListener(Loader::kComplete, LoadCompleteListener(this, event));
      loader.AddListener(Loader::kError, LoadErrorListener(this, event, false));
      loader.LoadFile(event->fullpath());
#ifndef PACKING_RUNTIME
      AddRuntime(e);
#endif
    }
  }
  set_current_directory(e->path());
}

void Nexc::SearchModule(const char* path, std::string* buf) {
  int len = strlen(path);
  const char* current = virtual_directory_->current_directory();
  if (len > 0) {
    if (path[0] == '.') {
      os::SPrintf(buf, "%s/%s.js", current, path);
    } else {
      const LibDirectories& dir = compilation_info_->lib_directories();
      LibDirectories::const_iterator it = dir.begin();
      for (; it != dir.end(); ++it) {
        os::SPrintf(buf, "%s/%s.js", it->c_str(), path);
        os::fs::Stat stat(buf->c_str());
        if (stat.IsExist() && stat.IsReg()) {
          return;
        }
      }
    }
    os::SPrintf(buf, "%s/%s.js", current, path);
  }
}

void Nexc::set_current_directory(const char* path) {
  virtual_directory_->set_current_directory(path);
}

const Nexc::DepsHandle Nexc::GetDepends() const {
  return deps_;
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
  AddListener(kScan, Scanner::ScannerEventListener());
  AddListener(kParse, Parser::ParseEventListener());
  AddListener(kFail, Bind(&Nexc::FailHandler, this));
  AddListener(kFatal, Bind(&Nexc::AbortHandler, this));
  AddListener(kTransformAst, Translator::TransformEventLitener());
  AddListener(kCompilationSucessed, Bind(&Nexc::Success, this));
}

void Nexc::AbortHandler(CompilationEvent* e) {
  std::string error;
  e->error_reporter()->SetRawError(&error);
  DEBUG_LOG(Fatal, "%s", error.c_str());
}

void Nexc::FailHandler(CompilationEvent* e) {
  std::string error;
  e->error_reporter()->SetRawError(&error);
  DEBUG_LOG(Warn, "%s", error.c_str());
}

void Nexc::Success(CompilationEvent* e) {
  root_->AddChild(e->ast());
  ast_list_.insert(AstPair(e->fullpath(), e->ast()));
}

FileRoot* Nexc::ast(const char* filename) {
  AstList::iterator it = ast_list_.find(filename);
  if (it != ast_list_.end()) {
    return it->second;
  }
  return NULL;
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
