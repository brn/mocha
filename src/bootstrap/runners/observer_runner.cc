#include <bootstrap/runners/observer_runner.h>
#include <utils/file_watcher/observer/xml_observer.h>
#include <utils/class_traits/static.h>

namespace mocha {

class ObserverHolder : private Static {
 public :
  static XMLObserver* GetObserver() { return observer_; }
  static void SetObserver( XMLObserver* observer ) { observer_ = observer;is_inited_ = true; }
  static bool IsInited() { return is_inited_; }
 private :
  static bool is_inited_;
  static XMLObserver* observer_;
};

XMLObserver* ObserverHolder::observer_;
bool ObserverHolder::is_inited_ = false;

ObserverRunner::ObserverRunner( Options* options ) : ICommandLineRunner( options ) {}

void ObserverRunner::Run() {
  XMLObserver* observer;
  if ( !ObserverHolder::IsInited() ) {
    observer = new XMLObserver();
    ObserverHolder::SetObserver( observer );
  } else {
    observer = ObserverHolder::GetObserver();
  }
  if ( !options_->IsStopObserving() ) {
    observer->Run();
  } else {
    Exit();
  }
}


void ObserverRunner::Exit() {
  ObserverHolder::GetObserver()->Exit();
}

}
