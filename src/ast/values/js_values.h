#ifndef mocha_js_values_h_
#define mocha_js_values_h_

#include <vector>
#include <utils/pool/managed.h>
#include <utils/pool/managed_handle.h>
#include <utils/hash/hash_map/hash_map.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast_foward_decl.h>

#define FACTORY( name ) static inline name* New() { return ManagedHandle::Retain( new name() ); }
#define CLONE( name ) JSValue* Clone()
namespace mocha {

class JSValue : public Managed {
 public :
  enum {
    kJSObject,
    kJSArray,
    kJSFunction,
    kNoStatic,
    kJSLiteral
  };
  ~JSValue(){}
  int type() { return type_; }
  const char* name() { return name_; }
  virtual bool Decidable() { return false; }
  void ref( AstNode* ast ) { ref_ = ast; }
  AstNode* ref() { return ref_; }
  virtual CLONE( JSValue ) = 0;
 protected :
  JSValue( int type , const char* name ) : Managed(),
      type_( type ) , name_( name ){}
 private :
  JSValue(){}
  int type_;
  const char* name_;
  AstNode* ref_;
};

typedef HashMap<const char*,JSValue*> JSPropertyList;
typedef JSPropertyList::EntryIterator JSPropertyIterator;
typedef JSPropertyList::HashEntry JSPropertyEntry;

class JSObject : public JSValue {
 public :
  FACTORY( JSObject );
  inline void property( const char* key , JSValue* node ) { properties_.Insert( key , node ); }
  inline JSValue* property( const char* key ) { return Find( key ); }
  inline JSPropertyIterator Properties() { return properties_.Entries(); }
  virtual bool Decidable() { return false; }
  CLONE(JSObject);
 protected :
  JSObject() : JSValue( JSValue::kJSObject , "JSObject" ){}
  JSObject( int type , const char* name ) : JSValue( type , name ){}
                                            
 private :
  inline JSValue* Find( const char* key ) {
    JSPropertyEntry ent = properties_.Find( key );
    return ( ent.IsEmpty() )? 0 : ent.Value();
  }
  JSPropertyList properties_;
};


class JSArray : public JSObject {
  typedef std::vector<JSValue*> JSArrayElements;
 public :
  FACTORY( JSArray );
  inline void element( JSValue* val ) {
    elements_.push_back( val );
  }
  inline JSValue* element( int index ) const { return elements_.at( index ); }
  inline int Size() { return elements_.size(); }
  CLONE(JSArray);
 private :
  JSArray() : JSObject( kJSArray , "JSArray" ){}
  JSArrayElements elements_;
};



class JSFunction : public JSObject {
 public :
  inline static JSFunction* New( AstNode* name ) { return ManagedHandle::Retain( new JSFunction( name ) ); }
  ~JSFunction(){}
#define FLAGS( flg , index ) ( flg )? flgs_.Set( index ) : flgs_.UnSet( index )
  inline bool this_accessor() { return flgs_.At( 0 ); };
  inline void this_accessor( bool flg ) { FLAGS( flg , 0 ); };
  inline bool prototype_accessor() { return flgs_.At( 1 ); };
  inline void prototype_accessor( bool flg ) { FLAGS( flg , 1 ); };
  inline bool call_as_constructor() { return flgs_.At( 2 ); };
  inline void call_as_constructor( bool flg ) { FLAGS( flg , 2 ); };
  inline bool inlinable() { return flgs_.At( 3 ); };
  inline void inlinable( bool flg ) { FLAGS( flg , 3 ); };
  inline bool decl() { return flgs_.At( 4 ); };
  inline void decl( bool flg ) { FLAGS( flg , 4 ); };
  inline AstNode* name();
#undef FLAGS
  CLONE(JSFunction);
 private :
  JSFunction( AstNode* name ) : JSObject( kJSFunction , "JSFunction" ) , name_( 0 ){}
  BitVector8 flgs_;
  AstNode* name_;
};

class NoStatic : public JSObject {
 public :
  FACTORY( NoStatic );
  NoStatic() : JSObject( JSValue::kNoStatic , "NoStatic" ){}
  ~NoStatic(){}
  bool Decidable() { return false; }
};

class JSLiteral : public JSValue {
 public :
  inline static JSLiteral* New( ValueNode* value ) { return ManagedHandle::Retain( new JSLiteral( value ) ); }
  ~JSLiteral(){}
  ValueNode* value() { return value_; }
  CLONE( Literal );
 private :
  JSLiteral( ValueNode* value ) : JSValue( kJSLiteral , "JSLiteral" ) , value_( value ){}
  ValueNode* value_;
};

}


#undef FACTORY
#undef CLONE
#endif
