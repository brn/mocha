#include <gtest/gtest.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/compiler/loader/loader.h>
const char path[] = {CURRENT_DIR"/src/mocha/roaster/compiler/loader/loader.h"};
class TestCPLitener {
 public :
  TestCPLitener(int* state)
      : state_(state){}
  TestCPLitener(const TestCPLitener& listener) {
    state_ = listener.state_;
  }
  void operator()(mocha::IOEvent* e) {
    ASSERT_EQ(0, strcmp(e->path(), path));
    (*state_) = 1;
  }
 private :
  int* state_;
};

class TestERLitener {
 public :
  TestERLitener(int* state)
      : state_(state){}
  TestERLitener(const TestERLitener& listener) {
    state_ = listener.state_;
  }
  void operator()(mocha::IOEvent* e) {    
    (*state_) = -1;
  }
 private :
  int *state_;
};

class TestNotFoundLitener {
 public :
  TestNotFoundLitener(int* state)
      : state_(state){}
  TestNotFoundLitener(const TestNotFoundLitener& listener) {
    state_ = listener.state_;
  }
  void operator()(mocha::IOEvent* e) {
    ASSERT_EQ(mocha::IOEvent::kNotFound, e->error_type());
    (*state_) = -1;
  }
 private :
  int *state_;
};

class TestNotAFileLitener {
 public :
  TestNotAFileLitener(int* state)
      : state_(state){}
  TestNotAFileLitener(const TestNotAFileLitener& listener) {
    state_ = listener.state_;
  }
  void operator()(mocha::IOEvent* e) {
    ASSERT_EQ(mocha::IOEvent::kNotAFile, e->error_type());
    (*state_) = -1;
  }
 private :
  int *state_;
};

TEST(LoaderTest, LoadTest) {
  mocha::Loader loader;
  int state = 0;
  loader.AddListener(mocha::Loader::kComplete, TestCPLitener(&state));
  loader.AddListener(mocha::Loader::kError, TestERLitener(&state));
  loader.LoadFile(path);
  if (state != 1) {
    FAIL();
  }
}

TEST(LoaderTest, LoadNotAFileTest) {
  mocha::Loader loader;
  int state = 0;
  loader.AddListener(mocha::Loader::kComplete, TestCPLitener(&state));
  loader.AddListener(mocha::Loader::kError, TestNotAFileLitener(&state));
  loader.LoadFile(CURRENT_DIR"/src");
  if (state != -1) {
    FAIL();
  }
}

TEST(LoaderTest, LoadNoSuchFileTest) {
  mocha::Loader loader;
  int state = 0;
  loader.AddListener(mocha::Loader::kComplete, TestCPLitener(&state));
  loader.AddListener(mocha::Loader::kError, TestNotFoundLitener(&state));
  loader.LoadFile(CURRENT_DIR"/src/aaaa");
  if (state != -1) {
    FAIL();
  }
}
