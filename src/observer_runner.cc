#include "observer_runner.h"
#include "xml_observer.h"

namespace mocha {
void ObserverRunner::Run() {
  XMLObserver observer;
  observer.Run();
}
}
