#ifndef mocha_processor_factory_h_
#define mocha_processor_factory_h_

namespace mocha {
class AstVisitor;
class Scope;
class VisitorInfo;

class ProcessorFactory;
class FactoryInfo {
  friend class ProcessorFactory;
 public :
  FactoryInfo( visitor , scope , info );
 private :
  AstVisitor *visitor_;
  Scope *scope_;
  VisitorInfo *info_;
};

class ProcessorFactory : private Static {
 public :
  template <typename T>
  static T* Create( FactoryInfo *info ) {
    return T::GetInstance( info->visitor_ , info->scope_ , info->info_ , info );
  }
 private :
  AstVisitor *visitor_;
  Scope *scope_;
  VisitorInfo *info_;
};
}

#endif
