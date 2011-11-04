#ifndef mocha_observer_h_
#define mocha_observer_h_

#include <list>
#include <boost/unordered_map.hpp>
#include "handle.h"
#include "file_io.h"
#include "thread.h"

namespace mocha {

class Observer{
 public :
  typedef boost::unordered_map<std::string , StrHandle> List;
  typedef std::pair<List&,Observer*> Pair;
  Observer() : is_stop_( false ) {}
  virtual ~Observer() {}
  virtual void Run() = 0;
  virtual void RegistFile( const char* file ) = 0;
  virtual void Stop() { is_stop_ = true; };
  virtual void Erase() { file_list_.clear(); }
 protected :
  static void* Run_( void* arg );
  virtual void Update_( Handle<File> file ) = 0;
  List file_list_;
  bool is_stop_;
};

class ArgsHolder {
 public :
  ArgsHolder ( Observer::List& list , Observer* observer ) : list_( list ), observer_( observer ){}
  Observer::List& GetList() { return list_; }
  Observer* GetObserver() { return observer_; }
 private :
  Observer::List& list_;
  Observer* observer_;
};

}

#endif //mocha_observer_h_
