#ifndef mocha_js_values_h_
#define mocha_js_values_h_

#include <vector>
#include <utils/pool/managed.h>
#include <utils/pool/managed_shared_ptr.h>
#include <utils/hash/hash_map/hash_map.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/ast/ast_foward_decl.h>

#define FACTORY(name) static inline name* New() { return ManagedHandle::Retain(new name()); }
#define CLONE(name) JSValue* Clone()
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
  virtual JSObject* CastToJSObject() { return 0; }
  virtual NoStatic* CastToNoStatic() { return 0; }
  virtual ~JSValue(){}
  int type() { return type_; }
  const char* name() { return name_; }
  virtual bool Decidable() { return false; }
  void ref(AstNode* ast) { ref_ = ast; }
  AstNode* ref() { return ref_; }
  virtual CLONE(JSValue) = 0;
  JSValue* ParentNode() { return parent_; }
  void ParentNode(JSValue* value) { parent_ = value; }
 protected :
  JSValue(int type, const char* name) :
      Managed(), type_(type), name_(name), ref_(0), parent_(0){}
 private :
  JSValue(){}
  int type_;
  const char* name_;
  AstNode* ref_;
  JSValue* parent_;
};

typedef HashMap<const char*,JSValue*> JSPropertyList;
typedef JSPropertyList::EntryIterator JSPropertyIterator;
typedef JSPropertyList::HashEntry JSPropertyEntry;

class JSObject : public JSValue {
 public :
  FACTORY(JSObject);
  virtual ~JSObject(){}
  inline void property(const char* key, JSValue* node) { node->ParentNode(this);properties_.Insert(key, node); }
  inline JSValue* property(const char* key) { return Find(key); }
  inline JSPropertyIterator Properties() { return properties_.Entries(); }
  virtual bool Decidable() { return false; }
  JSObject* CastToJSObject() { return this; }
  virtual JSArray* CastToJSArray() { return 0; }
  virtual JSFunction* CastToJSFunction() { return 0; }
  virtual JSLiteral* CastToJSArray() { return 0; }
  CLONE(JSObject);
 protected :
  JSObject() : JSValue(JSValue::kJSObject, "JSObject"){}
  JSObject(int type, const char* name) : JSValue(type, name){}

 private :
  inline JSValue* Find(const char* key) {
    JSPropertyEntry ent = properties_.Find(key);
    return (ent.IsEmpty())? 0 : ent.Value();
  }
  JSPropertyList properties_;
};


class JSArray : public JSObject {
  typedef std::vector<JSValue*> JSArrayElements;
 public :
  FACTORY(JSArray);
  inline void element(JSValue* val) {
    val->ParentNode(this);
    elements_.push_back(val);
  }
  inline JSValue* element(int index) const { return elements_.at(index); }
  inline int Size() { return elements_.size(); }
  JSArray* CastToJSArray() { return this; }
  CLONE(JSArray);
 private :
  JSArray() : JSObject(kJSArray, "JSArray"){}
  JSArrayElements elements_;
};



class JSFunction : public JSObject {
 public :
  inline static JSFunction* New(AstNode* name) { return ManagedHandle::Retain(new JSFunction(name)); }
  ~JSFunction(){}
#define FLAGS(flg, index) (flg)? flgs_.Set(index) : flgs_.UnSet(index)
  inline bool this_accessor() { return flgs_.At(0); };
  inline void this_accessor(bool flg) { FLAGS(flg, 0); };
  inline bool prototype_accessor() { return flgs_.At(1); };
  inline void prototype_accessor(bool flg) { FLAGS(flg, 1); };
  inline bool call_as_constructor() { return flgs_.At(2); };
  inline void call_as_constructor(bool flg) { FLAGS(flg, 2); };
  inline bool inlinable() { return flgs_.At(3); };
  inline void inlinable(bool flg) { FLAGS(flg, 3); };
  inline bool decl() { return flgs_.At(4); };
  inline void decl(bool flg) { FLAGS(flg, 4); };
  inline AstNode* name();
  virtual JSFunction* CastToJSFunction() { return this; }
#undef FLAGS
  CLONE(JSFunction);
 private :
  JSFunction(AstNode* name) : JSObject(kJSFunction, "JSFunction"), name_(0){}
  BitVector8 flgs_;
  AstNode* name_;
};


class NoStatic : public JSObject {
 public :
  FACTORY(NoStatic);
  NoStatic() : JSObject(JSValue::kNoStatic, "NoStatic"){}
  ~NoStatic(){}
  NoStatic* CastToNoStatic() { return this; }
  bool Decidable() { return false; }
};


class JSLiteral : public JSValue {
 public :
  inline static JSLiteral* New(int type, ValueNode* value) { return ManagedHandle::Retain(new JSLiteral(type, value)); }
  ~JSLiteral(){}
  ValueNode* value() { return value_; }
  virtual JSLiteral* CastToJSLiteral() { return this; }
  inline int type(){ return type_; }
  CLONE(Literal);
 private :
  JSLiteral(int type, ValueNode* value) : JSValue(kJSLiteral, "JSLiteral"), type_(type), value_(value){}
  int type_;
  ValueNode* value_;
};

}


#undef FACTORY
#undef CLONE
#endif
