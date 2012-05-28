#ifndef mocha_profiler_h_
#define mocha_profiler_h_
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#include <time.h>
#else
#include <sys/time.h>
#endif
namespace mocha {
class Profiler {
 public :
  Profiler(FILE* fp, const char* name) : name_(name), is_begin_(false),fp_(fp){};
  Profiler() :  name_(0), is_begin_(false), fp_(0){};
  ~Profiler(){};
  void Begin();
  double End();
 private :
  double GetTimeOfDaySec();
  const char* name_;
  bool is_begin_;
#ifdef _WIN32
  LARGE_INTEGER start_pc_;
  LARGE_INTEGER freq_pc_;
#else
  double begin_;
#endif
  FILE* fp_;
};
}

#endif
