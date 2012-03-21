#include <gtest/gtest.h>
#include <mocha/roaster/nexc/nexc.h>

TEST(NexcTest, NexcLoadFileTest) {
  mocha::Nexc nexc;
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js");
  nexc.CompileFile(CURRENT_DIR"/src/test/js/harmony/for_of_test.js");
}
