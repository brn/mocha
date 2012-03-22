#include <gtest/gtest.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/nexc/nexc.h>

TEST(NexcTest, NexcLoadFileTest) {
  mocha::Logging::Initialize(stdout);
  mocha::CompilationInfo info;
  mocha::Nexc nexc(&info);
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js");
}

TEST(NexcTest, NexcCompileTest) {
  mocha::Logging::Initialize(stdout);
  mocha::CompilationInfo info;
  mocha::Nexc nexc(&info);
  nexc.Compile("testFunction->{for (var i = 0;i < 100; i++){yield i;}}");
}
