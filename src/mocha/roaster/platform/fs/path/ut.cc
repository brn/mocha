#include <gtest/gtest.h>
#include <string.h>
#include <mocha/roaster/platform/fs/path/path.h>

TEST(PathTest, CheckPathUtil) {
  mocha::os::fs::Path path(CURRENT_DIR"/src/mocha/main.cc");
  ASSERT_EQ(true, (strcmp(path.filename(), "main.cc") == 0));
  ASSERT_EQ(true, (strcmp(path.directory(), CURRENT_DIR"/src/mocha") == 0));
  ASSERT_EQ(true, (strcmp(path.absolute_path(), CURRENT_DIR"/src/mocha/main.cc") == 0));
}

TEST(PathTest, CheckWinPathUtil) {
  mocha::os::fs::Path path(CURRENT_DIR"\\src\\mocha\\main.cc");
  ASSERT_EQ(true, (strcmp(path.filename(), "main.cc") == 0));
  ASSERT_EQ(true, (strcmp(path.directory(), CURRENT_DIR"/src/mocha") == 0));
  ASSERT_EQ(true, (strcmp(path.absolute_path(), CURRENT_DIR"/src/mocha/main.cc") == 0));
}
