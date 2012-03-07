#ifndef mocha_profiler_h_
#define mocha_profiler_h_
#include <stdio.h>
namespace mocha {
class Profiler {
 public :
  Profiler(FILE* fp, const char* name) : name_(name), is_begin_(false),fp_(fp){};
  Profiler() :  name_(0), is_begin_(false), fp_(0){};
  ~Profiler(){};
  void Begin();
  double End();
 private :
  const char* name_;
  bool is_begin_;
  double begin_;
  FILE* fp_;
};
}

#endif
