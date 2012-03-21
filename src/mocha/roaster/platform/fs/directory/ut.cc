#include <string.h>
#include <gtest/gtest.h>
#include <mocha/roaster/platform/fs/directory/directory.h>

TEST(DirectoryTest, find) {
  mocha::os::fs::Directory dir(CURRENT_DIR"/src/mocha/roaster/platform/fs/directory");
  mocha::os::fs::Directory::const_iterator it = dir.Entries(true);
  typedef std::vector<std::string> FindVector;
  FindVector vec;
  while (it != dir.end()) {
    if (strstr((*it)->GetName(), ".h") != NULL || strstr((*it)->GetName(), ".cc") != NULL) {
      ASSERT_EQ(true, (strcmp((*it)->GetName(), "directory.h") == 0 ||
                       strcmp((*it)->GetName(), "directory-inl.h") == 0 ||
                       strcmp((*it)->GetName(), "directory-posix.cc") == 0 ||
                       strcmp((*it)->GetName(), "directory-win32.cc") == 0 ||
                       strcmp((*it)->GetName(), "ut.cc") == 0));
      vec.push_back(std::string((*it)->GetName()));
    }
    ++it;
   }
   if (vec.size() != 5) {
     printf("%d\n", vec.size());
     FAIL();
  }
}
