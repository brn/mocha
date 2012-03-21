#include <string>
#include <gtest/gtest.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/nexc/loader/loader.h>
#include <mocha/roaster/nexc/scanner/source_stream.h>
#include <mocha/roaster/nexc/scanner/scanner.h>
#include <mocha/roaster/nexc/binding/parser_connector.h>
#include <mocha/roaster/nexc/parser/parser.h>
const char kPath[] = {CURRENT_DIR"/src/test/js/262/lib/prototype.js"};
namespace mocha {
class TestCallback {
 public :
  void operator()(IOEvent* e) {
    ScopedPtr<memory::Pool> handle(memory::Pool::Local());
    SourceStream* stream = SourceStream::New(e->data(), e->path(), "UTF-8", handle.Get());
    ErrorReporter reporter;
    Scanner* scanner = Scanner::New(stream, &reporter, kPath);
    ParserConnector* connector = new(handle.Get()) ParserConnector(scanner, &reporter);
    Parser parser(connector, &reporter, "prototype.js");
    FileRoot* root = parser.Parse();
  }
};
}
TEST(ScannerTest, ScanTest) {
  mocha::Loader loader;
  loader.AddListener(mocha::Loader::kComplete, mocha::TestCallback());
  loader.LoadFile(kPath);
}
