#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ast/ast.h>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/js_token.h>
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/scope/scoped_list.h>

namespace mocha {

static SymbolEntry& GetEmpty() {
  static SymbolEntry table( 0 , 0 );
  return table;
}

class Renamer {
 public :
  Renamer () : size_ ( 0 ) {
    for ( int i = 0; i < 15; i++ ) {
      indexes_[ i ] = 0;
    }
  }
  ~Renamer () {}
  
  const char* GetContractionName () {
    if ( size_ == 0 ) {
      return SingleName_ ();
    } else {
      return MultiName_ ();
    }
  }

  void ResetWordIndex () {
    size_ = 0;
    for ( int i = 0,len = size_ + 1; i < len; i++ ) {
      indexes_ [ i ] = 0;
    }
  }
 private :
  inline const char* CreateChar_ ( const std::string& str ) {
    char *ret = char_handle_.Retain ( new char [ str.size () + 1 ] );
    strcpy ( ret, str.c_str () );
    return ret;
  }

  const char* SingleName_ () {
    std::string tmp;
    tmp += table_ [ indexes_ [ size_ ] ];
    const char* ret = CreateChar_ ( tmp );
    indexes_ [ size_ ]++;
    if ( indexes_ [ size_ ] > kMax ) {
      indexes_ [ size_ ] = 1;
      size_++;
      indexes_ [ size_ ] = 1;
    }
    return ret;
  }
  
  const char* MultiName_ () {
    std::string tmp;
    SetMultiName_ ( tmp );
    const char* ret = CreateChar_ ( tmp );

    if ( indexes_ [ 1 ] == kMaxAfter ) {
      indexes_ [ 0 ]++;

      if ( indexes_ [ 0 ] > kMax ) {
        for ( int i = 0,len = size_ + 1; i < len; i++ ) {
          indexes_ [ i ] = 0;
        }
        size_++;
      }
    }
    return ret;
  }
  
  void SetMultiName_ ( std::string& tmp ) {
    for ( int i = 0,len = size_ + 1; i < len; i++ ) {
      tmp += table_ [ indexes_[ i ] ];
      if ( i == 0 ) {
        if ( ( ( i < size_ && indexes_ [ i + 1 ] == kMaxAfter ) || i == size_ ) &&
             indexes_ [ i ] < kMax ) {
          indexes_ [ i ]++;
        }
      } else {
        if ( ( ( i < size_ && indexes_ [ i + 1 ] == kMaxAfter ) || i == size_ ) &&
             indexes_ [ i ] < kMaxAfter ) {
          indexes_ [ i ]++;
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

char Renamer::table_ [] = {
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$0123456789"
};


InnerScope::InnerScope() : Managed() , head_( this ) , up_( 0 ) , renamer_handle_( new Renamer ){}
InnerScope::~InnerScope() {}

InnerScope* InnerScope::Enter() {
  InnerScope* scope = ManagedHandle::Retain<InnerScope>();
  children_.push_back( scope );
  scope->up_ = this;
  scope->head_ = head_;
  return scope;
}
  
InnerScope* InnerScope::Escape() {
  return up_;
}

void InnerScope::Insert ( TokenInfo* info , AstNode* ast_node ) {
  const char* ident = info->GetToken();
  if ( JsToken::IsBuiltin( ident ) ) {
    return;
  }
  SymbolTable::HashEntry entry = table_.Find( ident );
  printf( "insert %s to %p is empty = %d\n" , ident , this , entry.IsEmpty() );
  if ( entry.IsEmpty() ) {
    SymbolEntry entry( info , ast_node );
    table_.Insert( ident , entry );
  }
}

void InnerScope::Ref ( TokenInfo* info ) {
  const char* ident = info->GetToken();
  RefTable::HashEntry entry = reference_table_.Find( ident );
  if ( entry.IsEmpty() ) {
    reference_table_.Insert( ident , info );
  }
}


SymbolEntry InnerScope::Find ( TokenInfo* info ) {
  if ( table_.Size() > 0 ) {
    const char* ident = info->GetToken();
    SymbolTable::HashEntry entry = table_.Find( ident );
    if ( !entry.IsEmpty() ) {
      return entry.Value();
    } else {
      if ( up_ ) {
        return up_->Find( info );
      }
      return GetEmpty();
    }
  } else {
    if ( up_ ) {
      return up_->Find( info );
    } else {
      return GetEmpty();
    }
  }
}

void InnerScope::Rename() {
  printf( "scope renaming %p %d\n" , this , table_.Size() );
  std::list<InnerScope*>::iterator begin = children_.begin(),end = children_.end();
  while ( begin != end ) {
    (*begin)->Rename();
    ++begin;
  }
  HashMap<const char*,int> used_map;
  if ( reference_table_.Size() > 0 ) {
    RefTable::EntryIterator ref_iterator = reference_table_.Entries();
    while ( ref_iterator.HasNext() ) {
      RefTable::HashEntry entry = ref_iterator.Next();
      printf( "reference name = %s is there %d %p\n" , entry.Key().c_str() ,  table_.Find( entry.Key() ).IsEmpty() , this );
      const char* ident = entry.Key().c_str();
      SymbolTable::HashEntry symbol_ent = table_.Find( ident );
      UsedTable::HashEntry renamed_ent = renamed_table_.Find( ident );
      if ( symbol_ent.IsEmpty() && renamed_ent.IsEmpty() ) {
        InnerScope* parent = up_;
        TokenInfo* info = entry.Value();
        const char* renamed = renamer_handle_->GetContractionName();
        while ( !( used_table_.Find( renamed ).IsEmpty() ) ) {
          renamed = renamer_handle_->GetContractionName();
        }
        while ( parent ) {
          SymbolTable::HashEntry ent = parent->table_.Find( ident );
          if ( ent.IsEmpty() ) {
            if ( parent->up_ ) {
              parent = parent->up_;
            } else {
              goto CURRENT_RENAMING;
            }
          } else {
            TokenInfo* info = ent.Value().first;
            if ( info->IsRenamed() ) {
              used_table_.Insert( info->GetAnotherName() , 1 );
              renamed_table_.Insert( ident , 1 );
              InnerScope* tmp = up_;
              while ( tmp ) {
                if ( tmp->renamed_table_.Find( ident ).IsEmpty() ) {
                  tmp->used_table_.Insert( info->GetAnotherName() , 1 );
                  tmp->renamed_table_.Insert( ident , 1 );
                } else {
                  break;
                }
                tmp = tmp->up_;
              }
              goto CURRENT_RENAMING;
            } else {
              while ( !( parent->used_table_.Find( renamed ).IsEmpty() ) ) {
                renamed = renamer_handle_->GetContractionName();
              }
              parent->used_table_.Insert( renamed , 1 );
              break;
            }
          }
        }
        printf( "reference name = %s contraction = %s %d\n" , ident , renamed , this );
        parent = up_;
        used_table_.Insert( renamed , 1 );
        renamed_table_.Insert( ident , 1 );
        while ( parent ) {
          SymbolTable::HashEntry parent_entry = parent->table_.Find( entry.Key() );
          if ( !parent_entry.IsEmpty() ) {
            parent_entry.Value().first->Rename( renamed );
            parent->used_table_.Insert( renamed , 1 );
            parent->renamed_table_.Insert( ident , 1 );
            break;
          } else {
            parent->used_table_.Insert( renamed , 1 );
            parent->renamed_table_.Insert( ident , 1 );
          }
          parent = parent->up_;
        }
      }
    }
  }

CURRENT_RENAMING :
  SymbolTable::EntryIterator var_iterator = table_.Entries();
  while ( var_iterator.HasNext() ) {
    SymbolTable::HashEntry entry = var_iterator.Next();
    TokenInfo* info = entry.Value().first;
    if ( !info->IsRenamed() ) {
      const char* renamed = renamer_handle_->GetContractionName();
      printf( "base name = %s , contraction = %s %d\n" , entry.Key().c_str() , renamed , this );
      while ( !( used_table_.Find( renamed ).IsEmpty() ) ) {
        renamed = renamer_handle_->GetContractionName();
        printf( "rename base name = %s , contraction = %s\n" , entry.Key().c_str() , renamed );
      }
      info->Rename( renamed );
    } else {
      printf( "replaced base name = %s , contraction = %s %d\n" , entry.Key().c_str() , entry.Value().first->GetAnotherName() , this );
    }
  }
}

bool InnerScope::IsGlobal() const {
  return head_ == this;
}

Scope::Scope () : head_ ( new InnerScope ) , current_( head_ ) {};

Scope::~Scope () {
  delete head_;
}

InnerScope* Scope::Enter () {
  current_ = current_->Enter();
  return current_;
}

InnerScope* Scope::Escape () {
  current_ = current_->Escape();
  return current_;
}

void Scope::Insert ( TokenInfo* info , AstNode* ast_node ) {
  current_->Insert( info , ast_node );
}

InnerScope* Scope::Current() {
  return current_;
}

void Scope::Ref ( TokenInfo* info ) {
  current_->Ref( info );
}

SymbolEntry Scope::Find ( TokenInfo* info ) {
  return current_->Find( info );
}

void Scope::Rename() {
  head_->Rename();
}

bool Scope::IsGlobal() const {
  return current_->IsGlobal();
}

}
