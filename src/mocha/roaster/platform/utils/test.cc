#include <gtest/gtest.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/compiler/events/io_event/io_event.h>
TEST(PlatformUtilsTest, PrintfTest) {
  const char* tmp = "ok!";
  mocha::platform::Printf("test print %s\n", tmp);
}

TEST(PlatformUtilsTest, SPrintfTest) {
  std::string buf;
  const char* tmp = "ok!";
  int one = 1;
  mocha::platform::SPrintf(&buf, "test sprint %s", tmp);
  ASSERT_EQ(0, strcmp(buf.c_str(), "test sprint ok!"));
  mocha::platform::SPrintf(&buf, "test sprint %d", one);
  ASSERT_EQ(0, strcmp(buf.c_str(), "test sprint 1"));
}

TEST(PlatformUtilsTest, FOpenTest) {
  FILE* fp;
  std::string buf;
  if ((fp = mocha::platform::FOpen(CURRENT_DIR"/src/mocha/roaster/platform/utils/utils.h", "rb")) != NULL) {
    return SUCCEED();
  } else {
    mocha::platform::Strerror(&buf, K_ERRNO);
    fprintf(stderr, "%s\n", buf.c_str());
    FAIL();
  }
}

