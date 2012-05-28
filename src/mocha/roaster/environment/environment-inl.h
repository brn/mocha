#ifndef mocha_roaster_environment_inl_h_
#define mocha_roaster_environment_inl_h_
namespace mocha {
class ThreadCallbackAdapterBase {
 public :
  virtual ~ThreadCallbackAdapterBase(){}
  virtual void Invoke() = 0;
};

template <typename Callback>
class ThreadCallbackAdapter : public ThreadCallbackAdapterBase {
 public :
  explicit ThreadCallbackAdapter(Callback callback)
      : callback_(callback){}
  ~ThreadCallbackAdapter(){}
  virtual void Invoke() {
    Dereferrence<Callback>::Get(callback_)();
  }
 private :
  Callback callback_;
};

void* Environment::ThreadRunner(void* arg) {
  ThreadCallbackAdapterBase* callback = static_cast<ThreadCallbackAdapterBase*>(arg);
  callback->Invoke();
  delete callback;
  return 0;
}

void Environment::SetThreadType(os::Thread* thread, bool is_async) {
  if (is_async) {
    thread->Detach();
  } else {
    thread->Join();
  }
}

template <typename Listener>
void Environment::Create(Listener listener, bool is_async) {
  os::Thread thread;
  ThreadCallbackAdapter<Listener>* adapter = new ThreadCallbackAdapter<Listener>(listener);
  if (!thread.Create(ThreadRunner, adapter)) {
    FATAL("cant create thread in Environment::Create");
  } else {
    SetThreadType(&thread, is_async);
  }
}
}

#endif
