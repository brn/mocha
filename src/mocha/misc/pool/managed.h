#ifndef mocha_managed_h_
#define mocha_managed_h_
namespace mocha {
class PtrCollector;
class ManagedHandle;
class Managed {
  friend class PtrCollector;
  friend class ManagedHandle;
 public :
  inline Managed () : is_retained_ ( false ), id_ ( 0 ), next_ ( 0 ), prev_ ( 0 ) {}
  inline virtual ~Managed () {};
 private :
  typedef void ( *ReleaseCallback ) ( Managed* ptr );
  inline void Release_ () { destructor_ ( this ); }
  inline void Retain_ ( bool is = true ) { is_retained_ = is; }
  inline bool Retained_ () { return is_retained_; }
  bool is_retained_;
  int id_;
  Managed* next_;
  Managed* prev_;
  ReleaseCallback destructor_;
};
}
#endif
