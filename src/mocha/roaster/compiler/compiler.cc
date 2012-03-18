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
namespace roaster {

struct FileTag{};
struct SourceTag{};

template<typename T>
class TokenizePhase : public IEventListener {
  TokenizePhase();
  ~TokenizePhase(){}
  virtual void Recieve(CompilationEvent* e){assert(false);}
  virtual const char* key() {return "Tokenizer";}
};

template<>
class TokenizePhase<FileTag> : public IEventListener {
  TokenizePhase();
  ~TokenizePhase(){}
  virtual void Recieve(CompilationEvent* e) {
    std::string buf;
    FileHandle file = e->file();
    file->GetFileContents(&buf);
    const char* filename = file->filename();
    const char* path = e->path();
    CompilationInfo* info = e->compilation_info();
    ErrorReporter* reporter* e->error_reporter();
    SourceStream *source_stream = SourceStream::New(buf.c_str(), path, info);
    Scanner *scanner = Scanner::New(source_stream, reporter, filename);
    ParserConnector* connector = ParserConnector::New(scanner, source_stream);
    e->set_connector(connector);
    e->notificator()->NotifyForKey("BuildAst", e);
  }
  virtual const char* key() {return "TokenizePhase<File>";}
};

template<>
class TokenizePhase<SourceTag> : public IEventListener {
  TokenizePhase();
  ~TokenizePhase(){}
  virtual void Recieve(CompilationEvent* e) {
    const char* filename = "anonymouse";
    std::string path = platform::fs::Path::Getcwd();
    CompilationInfo* info = e->compilation_info();
    ErrorReporter* reporter* e->error_reporter();
    SourceStream *source_stream = SourceStream::New(e.source(), path.c_str(), info);
    Scanner *scanner = Scanner::New(source_stream, reporter, filename);
    ParserConnector* connector = ParserConnector::New(scanner, source_stream);
    e->set_connector(connector);
    e->notificator()->NotifyForKey("BuildAst", e);
  }
  virtual const char* key() {return "TokenizePhase<Source>";}
};


class ParserPhase : public IEventListener{
 public :
  ParsePhase(){}
  ~ParsePhase(){}
  virtual void Recieve(CompilationEvent* e) {
    Parser parser(&connector, reporter_.Get(), filename);
    FileRoot* root = parser.Parse();
    ErrorReporter reporter* = e->error_reporter();
    if (!reporter->Error()) {
      AstTransformer visitor (is_runtime_, scope_registry_, compiler_, compiler_->mainfile_path(), filename);
      AstRoot tmp_root;
      tmp_root.AddChild(root);
      tmp_root.Accept (&visitor);
      tmp_root.RemoveChild(root);
      e->set_ast(root);
      e->notificator()->NotifyForKey("Compiler<EndBuildPhase>", e);
    } else {
      e->notificator()->NotifyForKey("Compiler<ParseError>", e);
    }
  }
};

Compiler::Compiler(CompilationInfoHandle handle, Notificator<IEventListener,CompilationEventHandle>* notificator)
    : compilation_info_(handle),
      notificator_(notificator),
      parse_phase_(new ParsePhase(handle, notificator)) {
  notificator_->AddListener(this);
}

CompilationResultHandle Compiler::Compile() {
  DoCompile();
}

CompilationResultHandle Compiler::CompileFile(const char* filename) {
  ImportFile(filename);
}

void Compiler::Recieve(CompilationEvent* event) {
  SelectPhase(event->type, event);
}

inline void SelectPhase(CompilationEvent::Phase pahse, CompilationEvent* event) {
  switch (phase) {
    case CompilationEvent::kImport : {
      ImportFile(event->filename());
    }
      break;

    case CompilationEvent::kLoad : {
      LoadFile(event->filename());
    }
      break;
  }
}

inline void Compiler::Open(const char* path, const char* phase) {
  //Check is file exist.
  if (platform::fs::FileIO::IsExist(path)) {
    FileHandle file = platform::fs::FileIO::Open(path, "rb");
    CompilationEventHandle event(new CompilationEvent);
    event->set_file(file);
    notificator_->NotifyForKey(phase, event);
  } else {
    CompilationEventHandle event(new CompilationEvent);
    event->set_path(path);
    notificator_->NotifyForKey("Generator<NotFound>", event);
  }
}

void ImportFile(const char* filename) {
  Open(filename, "ParsePhase");
}

void Compiler::NotifyAddtionalFile(const char* filename, bool* is_runtime_module) {
  FileRoot* root = loader_->LoadAdditionalFile(filename, is_runtime_module);
  linker_->AddAst(root);
}

}
