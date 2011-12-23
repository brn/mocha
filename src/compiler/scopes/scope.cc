#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <compiler/scopes/scope.h>
#include <compiler/tokens/token_info.h>
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/scope/scoped_list.h>

namespace mocha {

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

void InnerScope::Insert ( TokenInfo* info ) {
  const char* ident = info->GetToken();
  SymbolTable::HashEntry entry = table_.Find( ident );
  if ( entry.IsEmpty() ) {
    table_.Insert( ident , info );
  }
}

void InnerScope::Ref ( TokenInfo* info ) {
  const char* ident = info->GetToken();
  SymbolTable::HashEntry entry = reference_table_.Find( ident );
  if ( entry.IsEmpty() ) {
    reference_table_.Insert( ident , info );
  }
}

TokenInfo* InnerScope::Find ( TokenInfo* info ) {
  const char* ident = info->GetToken();
  SymbolTable::HashEntry entry = table_.Find( ident );
  if ( !entry.IsEmpty() ) {
    return entry.Value();
  } else {
    if ( up_ ) {
      return up_->Find( info );
    }
    return 0;
  }
}

void InnerScope::Rename() {
  std::list<InnerScope*>::iterator begin = children_.begin(),end = children_.end();
  while ( begin != end ) {
    (*begin)->Rename();
    ++begin;
  }
  HashMap<const char*,int> used_map;
  if ( reference_table_.Size() > 0 ) {
    SymbolTable::EntryIterator ref_iterator = reference_table_.Entries();
    while ( ref_iterator.HasNext() ) {
      SymbolTable::HashEntry entry = ref_iterator.Next();
      printf( "reference name = %s is there %d\n" , entry.Key().c_str() ,  table_.Find( entry.Key() ).IsEmpty() );
      if ( table_.Find( entry.Key() ).IsEmpty() ) {
        InnerScope* parent = up_;
        TokenInfo* info = entry.Value();
        const char* renamed = renamer_handle_->GetContractionName();
        while ( !used_table_.Find( renamed ).IsEmpty() ) {
          renamed = renamer_handle_->GetContractionName();
        }
        info->Rename( renamed );
        used_table_.Insert( renamed , 1 );
        while ( parent ) {
          SymbolTable::HashEntry parent_entry = parent->table_.Find( entry.Key() );
          if ( !parent_entry.IsEmpty() ) {
            parent_entry.Value()->Rename( renamed );
            parent->used_table_.Insert( renamed , 1 );
            break;
          } else {
            parent->used_table_.Insert( renamed , 1 );
          }
          parent = parent->up_;
        }
      }
    }
  }
  
  SymbolTable::EntryIterator var_iterator = table_.Entries();
  while ( var_iterator.HasNext() ) {
    SymbolTable::HashEntry entry = var_iterator.Next();
    TokenInfo* info = entry.Value();
    if ( !info->IsRenamed() ) {
      const char* renamed = renamer_handle_->GetContractionName();
      printf( "base name = %s , contraction = %s\n" , entry.Key().c_str() , renamed );
      while ( !used_table_.Find( renamed ).IsEmpty() ) {
        renamed = renamer_handle_->GetContractionName();
        printf( "rename base name = %s , contraction = %s\n" , entry.Key().c_str() , renamed );
      }
      info->Rename( renamed );
    } else {
      printf( "replaced base name = %s , contraction = %s\n" , entry.Key().c_str() , entry.Value()->GetAnotherName() );
    }
  }
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

void Scope::Insert ( TokenInfo* info ) {
  current_->Insert( info );
}

InnerScope* Scope::Current() {
  return current_;
}

void Scope::Ref ( TokenInfo* info ) {
  current_->Ref( info );
}

TokenInfo* Scope::Find ( TokenInfo* info ) {
  return current_->Find( info );
}

void Scope::Rename() {
  head_->Rename();
}

}
