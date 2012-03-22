#ifndef mocha_processor_factory_h_
#define mocha_processor_factory_h_

#include <mocha/roaster/misc/class_traits/static.h>

namespace mocha {
class IVisitor;
class ScopeRegistry;
class TranslatorData;

class ProcessorInfo {
 public :
  ProcessorInfo(IVisitor* visitor, ScopeRegistry* scope_registry, TranslatorData* info) :
      visitor_(visitor), scope_registry_(scope_registry), info_(info){};
  inline IVisitor* visitor() const { return visitor_; }
  inline ScopeRegistry* scope_registry() const { return scope_registry_; }
  inline TranslatorData* translator_data() const { return info_; }
 private :
  IVisitor *visitor_;
  ScopeRegistry *scope_registry_;
  TranslatorData *info_;
};

}

#endif
