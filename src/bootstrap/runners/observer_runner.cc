#include <bootstrap/runners/observer_runner.h>
#include <utils/file_watcher/observer/xml_observer.h>

namespace mocha {
void ObserverRunner::Run() {
  XMLObserver observer;
  observer.Run();
}
}
