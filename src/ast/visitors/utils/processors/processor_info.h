#ifndef mocha_processor_factory_h_
#define mocha_processor_factory_h_

#include <utils/class_traits/static.h>

namespace mocha {
class IVisitor;
class Scope;
class VisitorInfo;

class ProcessorInfo {
 public :
  ProcessorInfo( IVisitor* visitor , Scope* scope , VisitorInfo* info ) :
      visitor_( visitor ), scope_( scope ) , info_( info ){};
  inline IVisitor* GetVisitor() { return visitor_; }
  inline Scope* GetScope() { return scope_; }
  inline VisitorInfo* GetInfo() { return info_; }
 private :
  IVisitor *visitor_;
  Scope *scope_;
  VisitorInfo *info_;
};

}

#endif
