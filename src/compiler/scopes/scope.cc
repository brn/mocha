#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <compiler/scopes/scope.h>
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/scope/scoped_list.h>

using namespace mocha;
using namespace std;

struct Scope::NameIndex {
  NameIndex () : size_ ( 0 ) {
    for ( int i = 0; i < 15; i++ ) {
      indexes_[ i ] = 0;
    }
  }
  ~NameIndex () {}
  
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
  typedef boost::unordered_map<const char*,int> ContractionTable;
  inline const char* CreateChar_ ( const string& str ) {
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

char Scope::NameIndex::table_ [] = {
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$0123456789"
};


struct Scope::ThreadValue {
  Scope::HashList property_table;
  Scope::NameIndex name_index;
};

void Scope::ThreadValueDestructor ( void* ptr ) {
  Scope::ThreadValue* thread_value = reinterpret_cast<Scope::ThreadValue*>( ptr );
  delete thread_value;
}

Scope::Scope () :
    Managed (),
    head_ ( this ),
    up_ ( 0 ),
    name_index_handle_ ( new NameIndex () )
{
  if ( GetValue_ () == NULL ) {
    Scope::ThreadValue *value_ = new Scope::ThreadValue ();
    ThreadLocalStorage::Set ( &key_ , value_ );
  }
};

Scope::~Scope () {}

Scope* Scope::Enter () {
  Scope* scope = ManagedHandle::Retain<Scope> ();
  PushBack_ ( scope );
  scope->up_ = this;
  scope->head_ = head_;
  return scope;
}

void Scope::Insert ( const char* ident ) { Insert_ ( ident , ident_table_ [ Scope::kSymbol ] ); }
void Scope::InsertLabel ( const char* ident ) { Insert_ ( ident ,  ident_table_ [ Scope::kLabel ] ); }
void Scope::Update ( const char* ident ) { Update_ ( ident ); }
SymbolSet* Scope::Find ( const char* ident ) { return Find_ ( ident , Scope::kSymbol ); }
SymbolSet* Scope::FindLabel ( const char* ident ) { return Find_ ( ident , Scope::kLabel ); }
bool Scope::IsGlobal () { return ( up_ == 0 ); }
Scope* Scope::GetGlobal () { return head_; }

SymbolSet* Scope::Find_ ( const char* ident , SearchType search_type ) {
  int len = strlen ( ident );
  if ( len > 0 ) {
    Pair* ret = SearchWithParentScope_ ( ident , search_type );
    if ( ret == 0 ) { return &empty_set_; }
    return ret->second;
  } else {
    return &empty_set_;
  }
}

inline void Scope::Insert_ ( const char* ident , HashList& list , bool force , const char* shorten_name ) {
  int len = strlen ( ident );
  if ( len > 0 ) {
    HashList::iterator is_find = SearchCurrentScope_ ( ident , list );
    if ( is_find == list.end () || force ) {
      const char* shorten;
      if ( force ) {
        shorten = shorten_name;
      } else {
        shorten = name_index_handle_->GetContractionName ();
        while ( ident_table_[kUsed].end () != ident_table_[kUsed].find ( shorten ) ) {
          shorten = name_index_handle_->GetContractionName ();
        }
      }
      SymbolSet* symbol_set = ManagedHandle::Retain ( new SymbolSet ( ident , shorten ) );
      ident_table_[ kUsed ].insert ( Pair( shorten , symbol_set ) );
      list.insert ( std::pair<const char* , SymbolSet*> ( ident , symbol_set ) );
    }
  }
}

inline void Scope::Update_ ( const char* ident ) {
  Scope* scope = this;
  const char* shorten = name_index_handle_->GetContractionName ();
  while ( scope ) {
    if ( scope->UpdateEachScope_ ( ident , shorten ) ) {
      break;
    }
    scope = scope->up_;
  } 
}

inline bool Scope::UpdateEachScope_ ( const char* ident , const char* shorten ) {
  HashList::iterator find = SearchCurrentScope_ ( ident , ident_table_ [ kSymbol ] );
  if ( find != ident_table_[kSymbol].end () ) {
    if ( strcmp((&(*find).first[0]) , ident ) != 0 ) {
      Insert_ ( ident , ident_table_[kSymbol] , true , shorten );
      return false;
    } else {
      return true;
    }
  }
  Insert_ ( ident , ident_table_[kSymbol] , true , shorten );
  return false;
}

const Scope::HashList::iterator& Scope::SearchCurrentScope_ ( const char* ident , HashList& list ) {
  return list.find ( ident );
}

inline Scope::Pair* Scope::SearchWithParentScope_ ( const char* key , SearchType search_type ) {
  Scope::HashList::iterator it;
  int index = static_cast<int>( search_type );
  HashList& current_list = ident_table_ [ index ];
  if ( strlen ( key ) > 0 ) {
    if ( ( it = SearchCurrentScope_ ( key , current_list ) ) != current_list.end () ) {
      return &(*it);
    } else {
      Scope *u_ = up_;
      while ( u_ != 0 ) {
        HashList& list = u_->ident_table_ [ index ];
        if ( ( it = u_->SearchCurrentScope_ ( key , list ) ) != list.end () ) {
          return &(*it);
        } else {
          u_ = u_->Escape ();
        }
      }
      return 0;
    }
  }
  return 0;
}

inline void Scope::PushBack_ ( Scope* scope ) {
  scopeList_.push_back ( scope );
}

Scope::ThreadValue* Scope::GetValue_ () {
  Scope::ThreadValue* val = reinterpret_cast<Scope::ThreadValue*> ( ThreadLocalStorage::Get ( &key_ ) );
  return val;
}

void Scope::EnsureScopeCreated_ ( Scope::ThreadValue* val ) {
  if ( val == NULL ) {
    std::runtime_error( "static Scope method called before Scope created." );
  }
}

void Scope::InsertGlobalSymbol ( const char* ident ) {
  MutexLock mutex_lock( mutex_ );
  Scope::ThreadValue* value = GetValue_ ();
  EnsureScopeCreated_ ( value );
  HashList::iterator find = value->property_table.find ( ident );
  if ( find == value->property_table.end () && strlen(ident) > 0 ) {
    SymbolSet* symbol_set = ManagedHandle::Retain (
        new SymbolSet ( ident , value->name_index.GetContractionName () ) );
    value->property_table.insert ( Scope::Pair ( ident , symbol_set ) );
  }
}

SymbolSet* Scope::GetGlobalSymbol ( const char* ident ) {
  MutexLock mutex_lock( mutex_ );
  Scope::ThreadValue* value = GetValue_ ();
  EnsureScopeCreated_ ( value );
  HashList::iterator find = value->property_table.find ( ident );
  if ( find != value->property_table.end () ) {
    printf ( "get !!!!!!!!!!!!!!!!!!!!!!!!!%s %d \n" , ident , (*find).second->IsEmpty() );
    return (*find).second;
  } else {
    return &empty_set_;
  }
}

SymbolSet Scope::empty_set_;
Mutex Scope::mutex_;
ThreadLocalStorageKey Scope::key_ ( Scope::ThreadValueDestructor );
