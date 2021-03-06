#include <gtest/gtest.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/nexc/nexc.h>

TEST(NexcTest, NexcLoadFileTest) {
  mocha::CompilationInfo info;
  mocha::Nexc nexc(&info);
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js");
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js");
}
