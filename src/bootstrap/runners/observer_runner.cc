#include <bootstrap/runners/observer_runner.h>
#include <utils/file_watcher/observer/xml_observer.h>

namespace mocha {

class ObserverRunner::PtrImpl {
public :
  XMLObserver* observer;
};

ObserverRunner::ObserverRunner( Options* options ) : ICommandLineRunner( options ) , pimpl_( new PtrImpl ) {}

void ObserverRunner::Run() {
  pimpl_->observer = new XMLObserver();
  if ( !options_->IsStopObserving() ) {
    pimpl_->observer->Run();
  } else {
    Exit();
  }
}


void ObserverRunner::Exit() {
  pimpl_->observer->Exit();
}

}
