#include <list>
#include <gtest/gtest.h>
#include <mocha/misc/profiler.h>
#include <mocha/roaster/memory/pool.h>

class TestAlloced : public mocha::memory::Allocated {
 public :
  int i;
  long v;
  char x;
  char* m;
};

class TestAllocedNew{
 public :
  int i;
  long v;
  char x;
  char* m;
};

TEST(PoolTest, ComparisonPool) {
  mocha::memory::Pool pool;
  mocha::Profiler prof(stdout, "ComparisonPool");
  prof.Begin();
  for (int i = 0; i < 1000000; i++) {
    TestAlloced* alloced = new(&pool) TestAlloced;
    alloced->i = 0;
  }
  prof.End();
}

TEST(PoolTest, ComparisonNew) {
  mocha::memory::Pool pool;
  std::list<TestAllocedNew*> list;
  mocha::Profiler prof(stdout, "ComparisonNew");
  prof.Begin();
  for (int i = 0; i < 1000000; i++) {
    TestAllocedNew* alloced = new TestAllocedNew;
    alloced->i = 0;
    list.push_back(alloced);
  }
  prof.End();
  std::list<TestAllocedNew*>::iterator it = list.begin();
  for (; it != list.end(); ++it) {
    delete (*it);
  }
}

TEST(PoolTest, ComparisonPoolPrimitive) {
  mocha::memory::Pool pool;
  mocha::Profiler prof(stdout, "ComparisonPoolPrimitive");
  prof.Begin();
  for (int i = 0; i < 10000; i++) {
    char* alloced = pool.Alloc<char>(100);
  }
  prof.End();
}

TEST(PoolTest, ComparisonNewPrimitive) {
  mocha::memory::Pool pool;
  std::list<char*> list;
  mocha::Profiler prof(stdout, "ComparisonNewPrimitive");
  prof.Begin();
  for (int i = 0; i < 10000; i++) {
    char* alloced = new char[100];
    list.push_back(alloced);
  }
  prof.End();
  std::list<char*>::iterator it = list.begin();
  for (; it != list.end(); ++it) {
    delete (*it);
  }
}


