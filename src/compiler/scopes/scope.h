
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
class ScopeRegistry;

typedef std::pair<TokenInfo* , AstNode*> SymbolEntry;
class Scope : public Managed {
  friend class ScopeRegistry;
  typedef ChildrenScopes = std::vector<Scope*>;
 public :
  typedef HashMap<const char*,SymbolEntry> SymbolTable;
  typedef HashMap<const char*,TokenInfo*> RefTable;
  typedef HashMap<const char*,TokenInfo*> UsedTable;
  ~Scope();
  void Insert ( TokenInfo* info , AstNode* ast_node );
  void InsertAlias( TokeInfo* info , AstNode* ast_node );
  SymbolEntry FindAlias( TokenInfo* info );
  SymbolEntry Find ( TokenInfo* info );
  SymbolEntry& FindAlias( TokenInfo* info );
  void Ref( TokenInfo* info );
  void Rename();
  bool IsGlobal() const;
  
 private :
  Scope();
  void DoRename_();
  void SetReferece_();
  void RenameDeclaration_();
  void FindRenamedReferenceEntry_();
  void RenameReference_( RefTable::HashEntry entry );
  
  ChildrenScopes children_;
  Scope* head_;
  Scope* up_;
  ScopedPtr<Renamer> renamer_handle_;
  SymbolTable table_;
  SymbolTable alias_table_;
  RefTable reference_table_;
  UsedTable used_table_;
  UsedTable renamed_table_;
};

class ScopeRegistry {
 public :
  ScopeRegistry ();
  ~ScopeRegistry();
  Scope* Assign();
  Scope* Return();
  Scope* Current();
  void Rename();
  bool IsGlobal() const;
 private:
  Scope* head_;
  Scope* current_;
};

}

#endif

