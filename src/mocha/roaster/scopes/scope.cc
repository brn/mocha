#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/smart_pointer/scope/scoped_list.h>

namespace mocha {

static SymbolEntry& GetEmpty() {
  static SymbolEntry table(static_cast<TokenInfo*>(0), static_cast<AstNode*>(0));
  return table;
}

class CompressedNameAllocator {
 public :
  CompressedNameAllocator() : size_ (0) {
    for (int i = 0; i < 15; i++) {
      indexes_[ i ] = 0;
    }
  }
  ~CompressedNameAllocator() {}
                                
  const char* GetContractionName() {
    if (size_ == 0) {
      return SingleName();
    } else {
      return MultiName();
    }
  }

  void ResetWordIndex() {
    size_ = 0;
    for (int i = 0,len = size_ + 1; i < len; i++) {
      indexes_[ i ] = 0;
    }
  }
 private :
  inline const char* CreateChar(const std::string& str) {
    char *ret = char_handle_.Retain (new char [ str.size() + 1 ]);
    strcpy (ret, str.c_str());
    return ret;
  }

  const char* SingleName() {
    std::string tmp;
    tmp += table_ [ indexes_[ size_ ] ];
    const char* ret = CreateChar(tmp);
    indexes_[ size_ ]++;
    if (indexes_[ size_ ] > kMax) {
      indexes_[ size_ ] = 1;
      size_++;
      indexes_[ size_ ] = 1;
    }
    return ret;
  }
                                
  const char* MultiName() {
    std::string tmp;
    SetMultiName(tmp);
    const char* ret = CreateChar(tmp);

    if (indexes_[ 1 ] == kMaxAfter) {
      indexes_[ 0 ]++;

      if (indexes_[ 0 ] > kMax) {
        for (int i = 0,len = size_ + 1; i < len; i++) {
          indexes_[ i ] = 0;
        }
        size_++;
      }
    }
    return ret;
  }
                                
  void SetMultiName(std::string& tmp) {
    for (int i = 0,len = size_ + 1; i < len; i++) {
      tmp += table_ [ indexes_[ i ] ];
      if (i == 0) {
        if (((i < size_ && indexes_[ i + 1 ] == kMaxAfter) || i == size_) &&
             indexes_[ i ] < kMax) {
          indexes_[ i ]++;
        }
      } else {
        if (((i < size_ && indexes_[ i + 1 ] == kMaxAfter) || i == size_) &&
             indexes_[ i ] < kMaxAfter) {
          indexes_[ i ]++;
        }
      }
    }
  }
                                
  int indexes_[15];
  int size_;
  static char table_[];
  enum { kMax = 53,kMaxAfter = 62 };
  ScopedArrayList<char> char_handle_;
};

char CompressedNameAllocator::table_ [] = {
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$0123456789"
};


Scope::Scope()
    : head_(this),
      parent_(0),
      name_allocator_handle_(new CompressedNameAllocator){}
Scope::~Scope() {}

void Scope::Insert (TokenInfo* info, AstNode* ast_node) {
  const char* ident = info->token();
  if (JsToken::IsBuiltin(ident)) {
    return;
  }
  SymbolIterator entry = table_.find(ident);
  if (entry == table_.end()) {
    SymbolEntry entry(info, ast_node);
    table_.insert(TableEntry(ident, entry));
  }
}

void Scope::Ref (TokenInfo* info) {
  const char* ident = info->token();
  if (JsToken::IsBuiltin(ident)) {
    return;
  }
  RefIterator entry = reference_table_.find(ident);
  if (entry == reference_table_.end()) {
    reference_table_.insert(RefEntry(ident, info));
  }
}


SymbolEntry Scope::Find (TokenInfo* info) {
  if (table_.size() > 0) {
    const char* ident = info->token();
    SymbolIterator entry = table_.find(ident);
    if (entry != table_.end()) {
      return entry->second;
    } else {
      if (parent_) {
        return parent_->Find(info);
      }
      return GetEmpty();
    }
  } else {
    if (parent_) {
      return parent_->Find(info);
    } else {
      return GetEmpty();
    }
  }
}

void Scope::ScopeRename(TokenInfo* info) {
  if (JsToken::IsBuiltin(info->token())) {
    return;
  }
  std::string before = info->token();
  std::string after;
  os::SPrintf(&after, "%s_%d", info->token(), reinterpret_cast<const intptr_t>(this));
  info->set_token(after.c_str());
  RenamedIterator entry = scope_renamed_table_.find(before.c_str());
  if (entry == scope_renamed_table_.end()) {
    scope_renamed_table_.insert(RenamedEntry(before.c_str(), after.c_str()));
  }
}

const char* Scope::FindRenamed(TokenInfo* info) {
  if (scope_renamed_table_.size() > 0) {
    const char* ident = info->token();
    RenamedIterator entry = scope_renamed_table_.find(ident);
    if (entry != scope_renamed_table_.end()) {
      return entry->second.c_str();
    } else {
      if (parent_) {
        return parent_->FindRenamed(info);
      }
      return NULL;
    }
  } else {
    if (parent_) {
      return parent_->FindRenamed(info);
    } else {
      return NULL;
    }
  }
}

void Scope::InsertAlias(JSSymbol* symbol, JSValue* value) {
  const char* ident = symbol->node->value()->token();
  alias_table_.insert(AliasPair(ident, JSValuePair(symbol, value)));
}

AliasPair Scope::FindAlias(JSSymbol* symbol) {
  AliasTable::interator find = alias_table_.find(symbol->node()->value()->token());
  if (find != alias_table_.end()) {
    return find->second;
  }
  return AliasPair(NULL, NULL);
}

void Scope::Rename() {
  SetReferece();
  DoRename();
}

void Scope::DoRename() {
  if (reference_table_.size() > 0) {
    FindRenamedReferenceEntry();
  }
  ChildrenScope::iterator begin = children_.begin(),end = children_.end();
  while (begin != end) {
    (*begin)->Rename();
    ++begin;
  }
  RenameDeclaration();
}

void Scope::SetReferece() {
  ChildrenScope::iterator begin = children_.begin(),end = children_.end();
  while (begin != end) {
    (*begin)->SetReferece();
    ++begin;
  }
  Scope* parent = parent_;
  while (parent) {
    RefIterator begin;
    RefIterator end = reference_table_.end();
    for (begin = reference_table_.begin(), end != reference_table_.end(); begin != end; ++begin) {
      parent->reference_table_.insert(RefEntry(begin->first, begin->second));
    }
    parent = parent->parent_;
  }
}

void Scope::RenameDeclaration() {
  SymbolIterator var_iterator;
  for (var_iterator = table_.begin(); var_iterator != table_.end(); ++var_iterator) {
    TokenInfo* info = var_iterator->second.first;
    if (!info->IsCompressed()) {
      const char* renamed = name_allocator_handle_->GetContractionName();
      while (used_table_.find(renamed) != used_table_.end()) {
        renamed = name_allocator_handle_->GetContractionName();
      }
      used_table_.insert(RefEntry(renamed, info));
      renamed_table_.insert(RefEntry(var_iterator->first, var_iterator->second.first));
      info->set_compressed_name(renamed);
    }
  }
}

void Scope::FindRenamedReferenceEntry() {
  RefIterator ref_iterator;
  for (ref_iterator = reference_table_.begin(); ref_iterator != reference_table_.end(); ++ref_iterator) {
    RenameReference(ref_iterator);
  }
}

void Scope::RenameReference(RefIterator entry) {
  const char* ident = entry->first.c_str();
  TokenInfo* info = entry->second;
  SymbolIterator current_ent = table_.find(ident);
  UsedIterator renamed_ent = renamed_table_.find(ident);
  SymbolEntry symbol_ent = Find(info);
  if (current_ent == table_.end() && renamed_ent == renamed_table_.end()) {
    Scope* parent = parent_;
    if (symbol_ent.first) {
      if (!(symbol_ent.first->IsCompressed())) {
        const char* renamed = name_allocator_handle_->GetContractionName();
        typedef std::vector<UsedTable*> TableArray;
        TableArray table_array;
        table_array.push_back(&used_table_);
        while (parent) {
          SymbolIterator parent_entry = parent->table_.find(ident);
          table_array.push_back(&(parent->used_table_));
          if (parent_entry != parent->table_.end()) {
            bool is_unique = false;
            while (!is_unique) {
              is_unique = true;
              for (int i = 0,len = table_array.size(); i < len; i++) {
                UsedTable* table = table_array.at(i);
                if (table->find(renamed) != table->end()) {
                  is_unique = false;
                }
              }
              if (!is_unique) {
                renamed = name_allocator_handle_->GetContractionName();
              }
            }
            break;
          }
          parent = parent->parent_;
        }
        used_table_.insert(RefEntry(renamed, info));
        renamed_table_.insert(RefEntry(ident, info));
        parent = parent_;
        while (parent) {
          SymbolIterator parent_entry = parent->table_.find(ident);
          if (parent_entry != parent->table_.end()) {
            parent_entry->second.first->set_compressed_name(renamed);
            parent->used_table_.insert(RefEntry(renamed, info));
            parent->renamed_table_.insert(RefEntry(ident, info));
            break;
          } else {
            parent->used_table_.insert(RefEntry(renamed, info));
            parent->renamed_table_.insert(RefEntry(ident, info));
          }
          parent = parent->parent_;
        }
      } else {
        const char* renamed = symbol_ent.first->compressed_name();
        used_table_.insert(RefEntry(renamed, symbol_ent.first));
        renamed_table_.insert(RefEntry(ident, symbol_ent.first));
        while (parent) {
          UsedIterator renamed_entry = parent->renamed_table_.find(ident);
          if (renamed_entry == parent->renamed_table_.end()) {
            parent->used_table_.insert(RefEntry(renamed, symbol_ent.first));
            parent->renamed_table_.insert(RefEntry(ident, symbol_ent.first));
          } else {
            break;
          }
          parent = parent->parent_;
        }
      }
    }
  }
}


bool Scope::IsGlobal() const {
  return head_ == this;
}

bool Scope::IsFirstScope() const {
  return parent_ && parent_->parent_ == 0;
}

ScopeRegistry::ScopeRegistry(memory::Pool* pool)
    : head_(0),
      current_(head_),
      pool_(pool){};

ScopeRegistry::ScopeRegistry()
    : head_(0),
      current_(head_),
      pool_(memory::Pool::Local()){};

ScopeRegistry::~ScopeRegistry () {}

Scope* ScopeRegistry::Assign() {
  Scope* scope = new(pool()) Scope();
  if (head_ == 0) {
    head_ = scope;
    current_ = head_;
  } else {
    if (current_) {
      current_->children_.push_back(scope);
      scope->parent_ = current_;
    }
    scope->head_ = head_;
    current_ = scope;
  }
  return scope;
}

Scope* ScopeRegistry::Return(){
  return (current_ = current_->parent_);
}

Scope* ScopeRegistry::Current() {
  return current_;
}

void ScopeRegistry::Rename() {
  head_->Rename();
}

}
