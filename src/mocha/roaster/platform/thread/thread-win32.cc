#include <stdio.h>
#include <stdlib.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/platform/thread/thread.h>

namespace mocha {
namespace os {

struct ParamsForWinThread {
  void* arg;
  Thread::pThreadStartFunc fn;
  HANDLE thread_handle;
};

const int kDetach = 0;
const int kExit = 1;
const int kCanceled = 2;
#define DETACH 0x00000001
#define EXIT 0x00000002
#define CANCELED 0x00000004

static unsigned __stdcall ThreadStartFuncWin (void* param) {
  ParamsForWinThread* params = reinterpret_cast<ParamsForWinThread*>(param);
  params->fn(params->arg);
  CloseHandle(params->thread_handle);
  delete params;
  return 0;
}

Thread::Thread(){}
bool Thread::Create(pThreadStartFunc fn, void* param) {
  ParamsForWinThread *params_for_win = new ParamsForWinThread;
  params_for_win->arg = param;
  params_for_win->fn = fn;
  params_for_win->thread_handle = thread_t_ = reinterpret_cast<HANDLE>(
      _beginthreadex(NULL, 0, ThreadStartFuncWin, params_for_win, 0, &thread_id_));
  return true;
}

bool Thread::Join() {
  if (!flags_.At(kDetach)) {
    WaitForSingleObject(thread_t_, INFINITE);
    return true;
  }
  return false;
}

int Thread::Detach() {
  flags_.Set(kDetach);
  return 1;
}

void Thread::Exit() {
  unsigned ret = 0;
  flags_.Set(kExit);
  _endthreadex(ret);
  CloseHandle(thread_t_);
}

void Thread::Cancel() {
  flags_.Set(kCanceled);
  LPDWORD ret = 0;
  GetExitCodeThread(thread_t_, ret);
  TerminateThread(thread_t_, *ret);
}

bool Thread::IsJoinable() {
  return !flags_.At(kDetach) && !flags_.At(kExit) && !flags_.At(kCanceled);
}


Mutex::Mutex(){InitializeCriticalSection(&critical_section_);}
Mutex::~Mutex() { DeleteCriticalSection(&critical_section_); }

ScopedLock::ScopedLock(Mutex& mutex) : mutex_(&mutex), unlocked_(false) {
  EnterCriticalSection(&(mutex_->critical_section_));
}

ScopedLock::~ScopedLock() {
  Unlock();
}

void ScopedLock::Unlock() {
  if (!unlocked_) {
    unlocked_ = true;
    LeaveCriticalSection(&(mutex_->critical_section_));
  }
}

ThreadLocalStorageKey::ThreadLocalStorageKey(ThreadLocalStorageKey::Destructor destructor)
    : destructor_(destructor), has_fn_(true), is_free_(false), key_(TlsAlloc()){}


ThreadLocalStorageKey::ThreadLocalStorageKey()
    : has_fn_(false), is_free_(false), key_(TlsAlloc()){}

ThreadLocalStorageKey::~ThreadLocalStorageKey() {Free();}
void ThreadLocalStorageKey::Free() {
  ScopedLock lock(mutex_);
  if (!is_free_) {
    if (has_fn_) {
      destructor_(TlsGetValue(key_));
    }
    TlsFree(key_);
  }
}

void ThreadLocalStorageKey::DeleteKey() {
  Free();
}

}
}
#undef DETACH
#undef EXIT
#undef CANCELED

