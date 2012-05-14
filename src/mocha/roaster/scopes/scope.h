/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_roaster_scopes_scope_h_
#define mocha_roaster_scopes_scope_h_
#include <vector>
#include <utility>
#include <string>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/memory/pool.h>

namespace mocha {
class TokenInfo;
class CompressedNameAllocator;
class AstNode;
class TokenInfo;
class ScopeRegistry;
class JsToken;
typedef std::pair<TokenInfo*, AstNode*> SymbolEntry;
class Scope : public memory::Allocated {
  friend class ScopeRegistry;
  typedef std::vector<Scope*> ChildrenScope;
 public :
  typedef std::pair<std::string,TokenInfo*> RefEntry;
  typedef std::pair<const char*,SymbolEntry> TableEntry;
  typedef std::pair<const char*,const char*> RenamedEntry;
  typedef roastlib::unordered_map<std::string,SymbolEntry> SymbolTable;
  typedef roastlib::unordered_map<std::string,TokenInfo*> RefTable;
  typedef roastlib::unordered_map<std::string,TokenInfo*> UsedTable;
  typedef roastlib::unordered_map<std::string,std::string> RenamedTable;
  typedef SymbolTable::iterator SymbolIterator;
  typedef RefTable::iterator RefIterator;
  typedef UsedTable::iterator UsedIterator;
  typedef RenamedTable::iterator RenamedIterator;
  ~Scope();
  void Insert (TokenInfo* info, AstNode* ast_node);
  void ScopeRename(TokenInfo* info);
  const char* FindRenamed(TokenInfo* info);
  Scope* parent() { return parent_; }
  SymbolEntry Find (TokenInfo* info);
  void Ref(TokenInfo* info);
  void Rename();
  bool IsGlobal() const;
  bool IsFirstScope() const;
  
 private :
  Scope();
  void DoRename();
  void SetReferece();
  void RenameDeclaration();
  void FindRenamedReferenceEntry();
  void RenameReference(RefIterator entry);
  ChildrenScope children_;
  Scope* head_;
  Scope* parent_;
  ScopedPtr<CompressedNameAllocator> name_allocator_handle_;
  SymbolTable table_;
  RefTable reference_table_;
  UsedTable used_table_;
  UsedTable renamed_table_;
  RenamedTable scope_renamed_table_;
};

class ScopeRegistry {
 public :
  ScopeRegistry(memory::Pool* pool);
  ScopeRegistry();
  ~ScopeRegistry();
  Scope* Assign();
  Scope* Return();
  Scope* Current();
  void Rename();
  bool IsGlobal() const;
 private:
  memory::Pool* pool() { return pool_; }
  Scope* head_;
  Scope* current_;
  memory::Pool* pool_;
};

}

#endif

