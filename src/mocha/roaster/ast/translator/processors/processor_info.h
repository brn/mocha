#ifndef mocha_processor_factory_h_
#define mocha_processor_factory_h_

#include <mocha/roaster/misc/class_traits/static.h>

namespace mocha {
class IVisitor;
class ScopeRegistry;
class TranslatorData;

class ProcessorInfo {
 public :
  ProcessorInfo(IVisitor* visitor, TranslatorData* data)
      : visitor_(visitor),
        data_(data){};
  inline IVisitor* visitor() const { return visitor_; }
  inline TranslatorData* translator_data() const { return data_; }
 private :
  IVisitor *visitor_;
  TranslatorData *data_;
};

}

#endif
