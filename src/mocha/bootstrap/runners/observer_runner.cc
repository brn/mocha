#include <mocha/bootstrap/runners/observer_runner.h>
#include <mocha/misc/file_watcher/observer/xml_observer.h>
#include <mocha/roaster/misc/class_traits/static.h>

namespace mocha {

XMLObserver* GetObserver() {
  static XMLObserver observer;
  return &observer;
}

ObserverRunner::ObserverRunner(Options* options) : ICommandLineRunner(options) {}

void ObserverRunner::Run() {
  if (!options_->IsStopObserving()) {
    GetObserver()->Run();
  } else {
    Exit();
  }
}


void ObserverRunner::Exit() {
  GetObserver()->Exit();
}

}
