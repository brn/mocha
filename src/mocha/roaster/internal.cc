#include <sstream>
#include <mocha/roaster/internal.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/binding/parser_connector.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/parser/parser.h>
#include <mocha/roaster/scanner/token_stream.h>
#include <mocha/roaster/scanner/source_stream.h>
#include <mocha/roaster/scanner/scanner.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/ast_transformer.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/options/setting.h>

namespace mocha {

#define FILE_EXIST file_exist_ = true
#define FILE_NOT_EXIST file_exist_ = false
                                

Internal::Internal(const char* path, Compiler* compiler, CodegenVisitor* codegen,
                   ScopeRegistry *scope_registry, bool is_runtime,
                   AstRoot* ast_root, memory::Pool* pool)
    : is_runtime_(is_runtime),
      file_exist_ (false),
      path_(path),
      compiler_(compiler),
      codegen_(codegen),
      scope_registry_(scope_registry),
      ast_root_(ast_root),
      pool_(pool),
      reporter_(new ErrorReporter){}

void Internal::Parse(ErrorLevel level) {
  ParseStart(false,level);
}

void Internal::GetAst(ErrorLevel level) {
  ParseStart(true,level);
}

void Internal::ParseStart(bool is_ast, ErrorLevel level) {
  if (compiler()->compilation_info()->IsFile()) {
    RunAction(is_ast, level);
  } else {
    DoParse(is_ast);
  }
}

void Internal::RunAction(bool is_ast, ErrorLevel level) {
  LoadFile();
  if (exist() || level == kNofatal) {
    if (exist()) {
      return DoParse(is_ast);
    }
  }
  ast_root_->AddChild(new(pool_) Empty);
}

inline void Internal::LoadFile() {
  //Check is file exist.
  if (platform::fs::FileIO::IsExist(path_)) {
    file_ = platform::fs::FileIO::Open(path_, "rb");
    //Set bool to true.
    FILE_EXIST;
  } else {
    //Write error message to result.
    OpenError(path_);
    //Set bool to false.
    FILE_NOT_EXIST;
  }
}


inline void Internal::DoParse(bool is_ast) {
  std::string buf;
  bool is_file = compiler()->compilation_info()->IsFile();
  if (is_file) {
    file()->GetFileContents(&buf);
  } else {
    buf = path_;
  }
  const char* filename = (is_file)? file_->filename()
      : (compiler_->compilation_info()->HasOptionalIdentifier())? compiler_->compilation_info()->optional_identifier() : "anonymous";
  SourceStream *source_stream = SourceStream::New(buf.c_str(), path_, compiler_->compilation_info());
  Scanner *scanner = Scanner::New(source_stream, reporter_.Get(), filename);
  ParserConnector connector(compiler_, ast_root_, scanner, source_stream, reporter_.Get());
  Parser parser(&connector, reporter_.Get(), filename);
  FileRoot* root = parser.Parse();
  AstTransformer visitor (is_runtime_, scope_registry_, compiler_, compiler_->mainfile_path(), filename);
  if (!is_ast) {
    compiler()->CatchException(filename, reporter_);
  }
  if (!reporter_->Error()) {
    AstRoot tmp_root;
    tmp_root.AddChild(root);
    tmp_root.Accept (&visitor);
    ast_root_->AddChild(tmp_root.first_child());
  } else {
    buf.clear();
    reporter_->SetError(&buf);
    if (!is_ast) {
      codegen_->Write(buf.c_str());
    }
    ast_root_->AddChild(new(pool_) Empty);
  }
}

inline void Internal::OpenError(const char* filename) {
  std::stringstream st;
  st << "no such file or directory " << filename;
  std::string tmp = st.str();
  reporter_->ReportSyntaxError(tmp.c_str());
  tmp.clear();
  reporter_->SetError(&tmp);
  codegen_->Write(tmp.c_str());
}


}
