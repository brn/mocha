#include <string.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/notificator/notificator.h>
class Event {
 public :
  Event() : type_("test event"){}
  ~Event(){}
  const char* type() const {return type_;}
 private :
  const char* type_;
};

class TestListener1 {
 public :
  void operator()(Event e) {
    ASSERT_EQ(0, strcmp(e.type(), "test event"));
  }
};

class TestListener2 {
 public :
  void operator()(Event e) {
    ASSERT_EQ(0, strcmp(e.type(), "test event"));
  }
};


class TestListener3 {
 public :
  void operator()(Event e) {
    ASSERT_EQ(0, strcmp(e.type(), "test event"));
  }
};


class TestListener4 {
 public :
  void operator()(Event e) {
    ASSERT_EQ(0, strcmp(e.type(), "test event"));
  }
};


class TestMemListener {
 public :
  void Reciever(Event e) {
    ASSERT_EQ(0, strcmp(e.type(), "test event"));
  }
};

void Testfn1(Event e) {
  ASSERT_EQ(0, strcmp(e.type(), "test event"));
}

void Testfn2(Event e) {
  ASSERT_EQ(0, strcmp(e.type(), "test event"));
}


TEST(NotificatorTest, FunctorTest) {
  mocha::Logging::Initialize(stdout);
  mocha::Notificator<Event> notificator;
  TestListener1 t;
  notificator.AddListener("TestListener", &t);
  notificator.AddListener("TestListener", TestListener2());
  notificator.AddListener("TestListener", TestListener3());
  notificator.NotifyForKey("TestListener", Event());
  notificator.NotifyAll(Event());
}

TEST(NotificatorTest, FunctionPtrTest) {
  mocha::Notificator<Event> notificator;
  notificator.AddListener("TestListener", Testfn1);
  notificator.AddListener("TestListener", Testfn2);
  notificator.NotifyForKey("TestListenerFn", Event());
  notificator.NotifyAll(Event());
}

TEST(NotificatorTest, MemberFunctionPtrTest) {
  mocha::Notificator<Event> notificator;
  TestMemListener mem;
  notificator.AddListener("TestListener", mocha::Notificator<Event>::Bind(&TestMemListener::Reciever, &mem));
  notificator.NotifyForKey("TestListener", Event());
  notificator.NotifyAll(Event());
}


TEST(NotificatorTest, TooManyListenerTest) {
  mocha::Notificator<Event> notificator;
  for (int i = 0; i < 10000; i++) {
    char tmp[100];
    sprintf(tmp , "TestListener%d", i);
    notificator.AddListener(tmp, TestListener4());
    notificator.AddListener("TestListener", TestListener4());
  }
  notificator.NotifyForKey("TestListener", Event());
  notificator.NotifyAll(Event());
}
