#ifndef mocha_processor_factory_h_
#define mocha_processor_factory_h_

#include <mocha/misc/class_traits/static.h>

namespace mocha {
class IVisitor;
class ScopeRegistry;
class VisitorInfo;

class ProcessorInfo {
 public :
  ProcessorInfo(IVisitor* visitor, ScopeRegistry* scope_registry, VisitorInfo* info) :
      visitor_(visitor), scope_registry_(scope_registry), info_(info){};
  inline IVisitor* visitor() const { return visitor_; }
  inline ScopeRegistry* scope_registry() const { return scope_registry_; }
  inline VisitorInfo* visitor_info() const { return info_; }
 private :
  IVisitor *visitor_;
  ScopeRegistry *scope_registry_;
  VisitorInfo *info_;
};

}

#endif
