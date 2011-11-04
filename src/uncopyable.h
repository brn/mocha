#ifndef Uncopyable_h
#define Uncopyable_h

namespace mocha{
  class Uncopyable {
  private:
    inline void operator = ( const Uncopyable& ) {};
    inline Uncopyable ( const Uncopyable& ) {};
  public:
    inline Uncopyable () {};
  };
}

#endif
