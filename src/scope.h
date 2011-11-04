
#ifndef Scope_h
#define Scope_h

#include "useconfig.h"

#include <list>
#include <string>

#ifdef HAVE_BOOST_UNORDERED_MAP_HPP
#include <boost/unordered_map.hpp>
#endif

#include "scoped_ptr.h"
#include "managed.h"
#include "define.h"
#include "thread.h"

namespace mocha {

class SymbolInfo;
class Symbol;
class File;

class SymbolSet : public Managed {
 public :
  typedef enum {
    kString,
    kNumber,
    kFunction,
    kArray,
    kObject,
    kRegExp,
    kDocument,
    kWindow,
    kElementNode,
    kTextNode
  } JSType;
  SymbolSet () : Managed () , ident_ ( 0 ), is_empty_ ( true ) {}
  SymbolSet ( const char* ident_ , const char* shorten , bool is_empty = false ) :
      ident_ ( ident_ ) , shorten_ ( shorten ) , is_empty_ ( false ) {}
  inline JPM_CONST const char* GetRawIdent () const { return ident_; };
  inline JPM_CONST const char* GetShortenName () const { return &shorten_ [ 0 ]; };
  inline JPM_CONST bool IsEmpty () const { return is_empty_; }
 private :
  const char* ident_;
  const char* shorten_;
  bool is_empty_;
};


class Scope : public Managed {
 public :
  Scope ();
  virtual ~Scope ();
  Scope* Escape () { return up_; }
  Scope* Enter ();
  void Insert ( const char* ident );
  void InsertLabel ( const char* ident );
  void Update ( const char* );
  SymbolSet* Find ( const char* ident );
  SymbolSet* FindLabel ( const char* ident );
  bool IsGlobal ();
  Scope* GetGlobal ();
  static void InsertGlobalSymbol ( const char* name );
  static SymbolSet* GetGlobalSymbol ( const char* ident );
  static void ThreadValueDestructor ( void* ptr );
 private:
  typedef std::pair<const std::string , SymbolSet*> Pair;
  typedef boost::unordered_map<const std::string , SymbolSet*> HashList;

  typedef enum {
    kSymbol = 0,
    kProperty = 1,
    kLabel = 2,
    kUsed = 3
  } SearchType;
  struct ThreadValue;
  inline void Insert_ ( const char* ident , HashList& list , bool force = false , const char* shorten_name = "void" );
  inline SymbolSet* Find_ ( const char* key , SearchType search_type );
  inline const HashList::iterator& SearchCurrentScope_ ( const char* key , HashList& list );
  inline Pair* SearchWithParentScope_ ( const char* key , SearchType search_type );
  inline void Update_ ( const char* );
  inline bool UpdateEachScope_ ( const char* , const char* );
  inline void PushBack_ ( Scope* scope );
  static ThreadValue* GetValue_ ();
  static void EnsureScopeCreated_ ( ThreadValue* val );
  std::list<Scope*> scopeList_;
  Scope* head_;
  Scope* up_;
  HashList ident_table_ [ 5 ];
  static boost::unordered_map<const char* , SymbolSet*> dom_reserved_word_;
  static boost::unordered_map<const char* , SymbolSet*> js_reserved_word_;
  static boost::unordered_map<const char* , SymbolSet*> property_reserved_word_;
  static SymbolSet empty_set_;
  struct NameIndex;
  ScopedPtr<SymbolSet> symbol_set_handle_;
  ScopedPtr<NameIndex> name_index_handle_;
  static ThreadLocalStorageKey key_;
  static Mutex mutex_;
};

}

#endif

