#include <gtest/gtest.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/roaster.h>
namespace mocha {
class TestFunc {
 public :
  void operator()(CompilationResult* result) {
    Logging::GetInstance()->Info("compiled\nwith source\[\n%s\n]", result->source());
  }
};

}
TEST(TranslatorTest, Test1) {
  mocha::Logging::Initialize(stdout);
  mocha::Roaster roaster;
  mocha::TestFunc fn;
  mocha::CompilationInfo info;
  info.SetPrettyPrint();
  mocha::CompilationResultHandle handle =
      roaster.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js", "UTF-8", &info);
  fn(handle.Get());
}


