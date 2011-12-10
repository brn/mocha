#ifndef mocha_processor_util_h_
#define mocha_processor_util_h_
#include <utils/class_traits/uncopyable.h>
#include <utils/thread/thread.h>
namespace mocha{
class AstVisitor;
class Scope;
class VisitorInfo;
class ProcessorBase : private Uncopyable{
 public :
  virtual ~IProcessor();
}

class ProcessorUtil {
 public :
  template <typename T>
  T* GetInstance( AstVisitor* visitor , Scope* scope , VisitorInfo* info ) {
    T* proc = reinterpret_cast<T*>( ThreadLocalStorage::Get( local_key_ ) );
    if ( proc == NULL ) {
      proc = new T( visitor , scope , info );
      ThreadLocalStorage::Set( local_key_ , proc );
    }
    return proc;
  }
 private :
  static void* Destructor_( void* );
  
  static ThreadLocalStorage local_key_;
};
}

#endif
