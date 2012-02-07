
#ifndef mocha_scope_h_
#define mocha_scope_h_

#include <useconfig.h>

#include <list>
#include <utility>
#include <string>
#include <define.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/pool/managed.h>
#include <utils/hash/hash_map/hash_map.h>


namespace mocha {

class TokenInfo;
class Renamer;
class AstNode;
typedef std::pair<TokenInfo* , AstNode*> SymbolEntry;
class InnerScope : public Managed {
 public :
  typedef HashMap<const char*,SymbolEntry> SymbolTable;
  typedef HashMap<const char*,TokenInfo*> RefTable;
  typedef HashMap<const char*,int> UsedTable;
  InnerScope();
  ~InnerScope();

  InnerScope* Enter();
  InnerScope* Escape();
  void Insert ( TokenInfo* info , AstNode* ast_node );
  SymbolEntry Find ( TokenInfo* info );
  SymbolEntry& FindAlias( TokenInfo* info );
  void Ref( TokenInfo* info );
  void Rename();
  bool IsGlobal() const;
  
 private :
  std::list<InnerScope*> children_;
  InnerScope* head_;
  InnerScope* up_;
  ScopedPtr<Renamer> renamer_handle_;
  SymbolTable table_;
  SymbolTable alias_table_;
  RefTable reference_table_;
  UsedTable used_table_;
};

class Scope {
 public :
  Scope ();
  ~Scope ();
  InnerScope* Escape();
  InnerScope* Enter();
  InnerScope* Current();
  void Insert ( TokenInfo* info , AstNode* ast_node );
  void Ref( TokenInfo* info );
  SymbolEntry Find ( TokenInfo* info );
  SymbolEntry& FindAlias( TokenInfo* info );
  void Rename();
  bool IsGlobal() const;
 private:
  InnerScope* head_;
  InnerScope* current_;
};

}

#endif

