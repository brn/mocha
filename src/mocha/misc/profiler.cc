#include <assert.h>
#include <mocha/misc/profiler.h>

namespace mocha {

double Profiler::GetTimeOfDaySec() {
#ifdef _WIN32
  QueryPerformanceFrequency(&freq_pc_);
  QueryPerformanceCounter(&start_pc_);
  return 0;
#else
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
#endif
}

void Profiler::Begin() {
  is_begin_ = true;
#ifndef _WIN32
  begin_ = GetTimeOfDaySec();
#else
  GetTimeOfDaySec();
#endif
}


double Profiler::End() {
  assert(is_begin_);
#ifdef _WIN32
  LARGE_INTEGER end_pc;
  QueryPerformanceCounter(&end_pc);
  double end = (end_pc.QuadPart - start_pc_.QuadPart) / static_cast<double>(freq_pc_.QuadPart);
#else
  double end = GetTimeOfDaySec() - begin_;
#endif
  if (fp_) {
    fprintf(fp_, "profile %s end. all process time => %f ms.\n", name_, end);
  }
  return end;
}

}
