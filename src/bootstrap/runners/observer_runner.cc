#include <bootstrap/runners/observer_runner.h>
#include <utils/file_watcher/observer/xml_observer.h>
#include <bootstrap/interactions/interaction.h>

namespace mocha {
void ObserverRunner::Run() {
  XMLObserver observer;
  observer.Run();
  Interaction::Begin();
}
}
