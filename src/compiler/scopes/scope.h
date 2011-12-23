
#ifndef mocha_scope_h_
#define mocha_scope_h_

#include <useconfig.h>

#include <list>
#include <string>
#include <define.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/pool/managed.h>
#include <utils/hash/hash_map/hash_map.h>


namespace mocha {

class TokenInfo;
class Renamer;

class InnerScope : public Managed {
 public :
  typedef HashMap<const char*,TokenInfo*> SymbolTable;
  typedef HashMap<const char*,int> UsedTable;
  InnerScope();
  ~InnerScope();

  InnerScope* Enter();
  InnerScope* Escape();
  void Insert ( TokenInfo* info );
  TokenInfo* Find ( TokenInfo* info );
  void Ref( TokenInfo* info );
  void Rename();
  
 private :
  std::list<InnerScope*> children_;
  InnerScope* head_;
  InnerScope* up_;
  ScopedPtr<Renamer> renamer_handle_;
  SymbolTable table_;
  SymbolTable reference_table_;
  UsedTable used_table_;
};

class Scope {
 public :
  Scope ();
  ~Scope ();
  InnerScope* Escape();
  InnerScope* Enter();
  InnerScope* Current();
  void Insert ( TokenInfo* info );
  void Ref( TokenInfo* info );
  TokenInfo* Find ( TokenInfo* info );
  void Rename();
 private:
  InnerScope* head_;
  InnerScope* current_;
};

}

#endif

