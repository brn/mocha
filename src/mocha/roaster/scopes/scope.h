
#ifndef mocha_scope_h_
#define mocha_scope_h_

#include <useconfig.h>

#include <list>
#include <vector>
#include <utility>
#include <string>
#include <define.h>
#include <utils/pool/managed.h>
#include <utils/hash/hash_map/hash_map.h>
#include <mocha/roaster/lib/scoped_ptr.h>
#include <mocha/roaster/lib/unordered_map.h>

namespace mocha {

class TokenInfo;
class CompressedNameAllocator;
class AstNode;
class TokenInfo;
class ScopeRegistry;

typedef std::pair<TokenInfo* , AstNode*> SymbolEntry;
class Scope : public Managed {
  friend class ScopeRegistry;
  typedef std::vector<Scope*> ChildrenScope;
 public :
  typedef std::pair<std::string,TokenInfo*> RefEntry;
  typedef std::pair<const char*,SymbolEntry> TableEntry;
  typedef roastlib::unordered_map<std::string,SymbolEntry> SymbolTable;
  typedef roastlib::unordered_map<std::string,TokenInfo*> RefTable;
  typedef roastlib::unordered_map<std::string,TokenInfo*> UsedTable;
  typedef SymbolTable::iterator SymbolIterator;
  typedef RefTable::iterator RefIterator;
  typedef UsedTable::iterator UsedIterator;
  ~Scope();
  void Insert ( TokenInfo* info , AstNode* ast_node );
  void InsertAlias( TokenInfo* info , AstNode* ast_node );
  Scope* parent() { return parent_; }
  SymbolEntry FindAlias( TokenInfo* info );
  SymbolEntry Find ( TokenInfo* info );
  void Ref( TokenInfo* info );
  void Rename();
  bool IsGlobal() const;
  
 private :
  Scope();
  void DoRename();
  void SetReferece();
  void RenameDeclaration();
  void FindRenamedReferenceEntry();
  void RenameReference( RefIterator entry );
  
  ChildrenScope children_;
  Scope* head_;
  Scope* parent_;
  roastlib::scoped_ptr<CompressedNameAllocator> name_allocator_handle_;
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

