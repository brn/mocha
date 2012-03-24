#include <gtest/gtest.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/ast/translator/translator.h>

class TestFunc {
 public :
  void operator()(mocha::CompilationEvent* e) {
    mocha::Translator t(false, e);
  }
};

TEST(TranslatorTest, Test1) {
  mocha::Logging::Initialize(stdout);
  mocha::CompilationInfo info;
  mocha::Nexc nexc(&info);
  nexc.AddListener(mocha::Nexc::kTransformAst, TestFunc());
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/class_test.js");
}

