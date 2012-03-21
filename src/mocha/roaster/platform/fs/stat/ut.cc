#include <gtest/gtest.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

TEST(StatTest, Exist) {
  mocha::os::fs::Stat stat(CURRENT_DIR"/src");
  if (!(stat.IsExist())) {
    FAIL();
  }
  if (!(stat.IsDir())) {
    FAIL();
  }
}

TEST(StatTest, NotExist) {
  mocha::os::fs::Stat stat("foobar");
  if (stat.IsExist()) {
    FAIL();
  }
}
