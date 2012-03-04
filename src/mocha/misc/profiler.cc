#include <assert.h>
#include <sys/time.h>
#include <mocha/misc/profiler.h>

namespace mocha {

double GetTimeOfDaySec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

void Profiler::Begin() {
  is_begin_ = true;
  begin_ = GetTimeOfDaySec();
}


double Profiler::End() {
  assert( is_begin_ );
  double end = GetTimeOfDaySec() - begin_;
  if ( fp_ ) {
    fprintf( fp_ , "profile %s end. all process time => %f ms.\n" , name_ , end );
  }
  return end;
}

}
