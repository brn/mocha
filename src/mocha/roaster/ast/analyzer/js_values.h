#ifndef mocha_analyzer_js_values_h_
#define mocha_analyzer_js_values_h_
#include <vector>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
class JSNumber;
class JSString;
class JSBoolean;
class JSRegExp;
class JSUndefined;
class JSNull;
class JSNaN;
class JSFunction;
class JSArray;
class AstNode;

class Properties {
  typedef std::pair<const char*, JSValue*> PropertyPair;
  typedef roastlib::unordered_map<std::string, JSValue*> Properties;
 public :
  Properties(){}
  ~Properties(){}
  void AddProperty(JSProperty* prop, JSValue* value) {
    properties_.insert(PropertyPair(prop->node()->value()->token, value));
  }
  JSValue* FindProperty(const char* val) {
    Properties::iterator it = properties_.find(val);
    if (it != properties_.end()) {
      return it->second;
    }
    return NULL;
  }
 private :
  Properties properties_;
};

class JSValue : public memory::Allocated {
 public :
  enum {
    kNumber,
    kString,
    kBoolean,
    kRegExp,
    kNull,
    kUndefined,
    kNaN,
    kFunction,
    kArray,
    kObject
  };
  JSValue(int type) : type_(type) {};
  int type() const {return type_;}
  virtual JSNumber* CastToNumber() {return NULL;}
  virtual JSString* CastToString() {return NULL;}
  virtual JSBoolean* CastToBoolean() {return NULL;}
  virtual JSRegExp* CastToRegExp() {return NULL;}
  virtual JSUndefined* CastToUndefined() {return NULL;}
  virtual JSNull* CastToNull() {return NULL;}
  virtual JSNaN* CastToNaNl() {return NULL;}
  virtual JSFunction* CastToFunction() {return NULL;}
  virtual JSArray* CastToArray() {return NULL;}
  virtual const char* ToString() {return "";}
 private :
  int type_;
};

class JSNumber : public JSValue {
 public :
  JSNumber(double value, AstNode* node)
      : JSValue(JSValue::kNumber),
        value_(value),
        node_(node){}
  double value() const {return value_;}
  JSNumber* CastToNumber() {return this;}
  const char* ToString() {return node_->CastToLiteral()->value()->token();}
 private :
  double value_;
  AstNode* node_;
};

class JSString : public JSValue {
 public :
  JSString(const char* value, AstNode* node)
      : JSValue(JSValue::kString),
        value_(value),
        node_(node){}
  const char* value() const {return value_;}
  JSString* CastToString() {return this;}
  const char* ToString() {return node_->CastToLiteral()->value()->token();}
 private :
  const char* value_;
  AstNode* node_;
};

class JSBoolean : public JSValue {
 public :
  JSBoolean(bool value, AstNode* node)
      : JSValue(JSValue::kBoolean),
        value_(value),
        node_(node){}
  bool value() const {return value_;}
  JSBoolean* CastToBoolean() {return this;}
  const char* ToString() {return node_->CastToLiteral()->value()->token();}
 private :
  bool value_;
  AstNode* node_;
};

class JSRegExp : public JSValue {
 public :
  JSRegExp(const char* value, AstNode* node)
      : JSValue(JSValue::kRegExp),
        value_(value),
        node_(node){}
  const char* value() const {return value_;}
  JSRegExp* CastToRegExp() {return this;}
  const char* ToString() {return node_->CastToLiteral()->value()->token();}
 private :
  const char* value_;
  AstNode* node_;
};

class JSUndefined : public JSValue {
 public :
  JSUndefined()
      : JSValue(JSValue::kUndefined){}
  JSUndefined* CastToUndefined() {return this;}
  const char* ToString() {return "undefined";}
};

class JSNull : public JSValue {
 public :
  JSNull()
      : JSValue(JSValue::kNull){}
  JSNull* CastToNull() {return this;}
  const char* ToString() {return "null";}
};

class JSNaN : public JSValue {
 public :
  JSNaN()
      : JSValue(JSValue::kNull){}
  JSNaN* CastToNaNl() {return this;}
  const char* ToString() {return "NaN";}
};

class JSFunction : public JSValue, public Properties {
 public :
  JSFunction(const char* name, AstNode* body)
      : JSValue(JSValue::kFunction),
        name_(name),
        body_(body){}
  JSFunction* CastToFunction() {return this;}
  const char* name() const {return name_;}
  AstNode* body() {return body_;}
  const char* ToString() {
    str_.clear();
    CompilationInfo info;
    info->SetPrettyPrint();
    CodegenVisitor visitor(&info);
    body->Accept(&visitor);
    str_ = visitor.GetCode();
    return str_.c_str();
  }
 private :
  const char* name_;
  std::string str_;
  AstNode* body_;
};

class JSArray : public JSValue, public Properties {
 public :
  typedef std::vector<AstNode*> Array;
  JSArray(AstNode* node)
      : JSValue(JSValue::kArray),
        node_(node){}
  JSArray* CastToArray() {return this;}
  int size() const {return array_.size();}
  void Add(AstNode* elem) {array_.push_back(elem);}
  AstNode* Get(size_t index) {return (index >= array_.size())? NULL : array_.at(index);}
  Array* data() {return &array_;}
  const char* ToString() {
    str_.clear();
    Array::iterator it = array_.begin();
    for (; it != array_.end(); ++it) {
      str_ += (*it)->ToString();
      str_ += ',';
    }
    if (!str_.empty()) {
      str_.erase(str_.size() - 1, 1);
    }
    return str_.c_str();
  }
 private :
  std::string str_;
  Array array_;
  AstNode* node_;
};

class JSObject : public JSValue {
 public :
  typedef std::pair<JSProperty*, JSValue*> JSValuePair
  typedef std::pair<std::string, JSValuePair> ValuePair;
  typedef roastlib::unordered_map<std::string, JSValuePair> Values;
  JSObject(AstNode* node)
      : JSValue(JSValue::kObject),
        node_(node){}
  JSObject* CastToObject() {return this;}
  void Add(JSProperty* prop, JSValue* node) {map_.insert(ValuePair(prop->value()->token(), JSValuePair(prop, node)));}
  JSValuePair Get(const char* name) {
    Values::iterator find = map_.find(name);
    if (find != map_.end()) {
      return find->second;
    }
    return JSValuePair(NULL, NULL);
  }
  Values* data() {return &map_;}
  const char* ToString() {
    return "[object Object]";
  }
 private :
  Values map_;
  AstNode* node_;
};

class JSSymbol : public JSValue {
 public :
  JSSymbol(AstNode* node)
      : JSValue(JSValue::kSymbol),
        node_(node){}
  AstNode* node() {return node_;}
 private :
  AstNode* node_;
};

class JSProperty : public JSValue {
 public :
  JSProperty(AstNode* node)
      : JSValue(JSValue::kProperty),
        node_(node),
        parent_(NULL){}
  AstNode* node() {return node_;}
  void set_parent(JSObject* object) {parent_ = object;}
  JSObject* parent() {return parent_;}
 private :
  AstNode* node_;
  JSObject* parent_;
};

class JSThis : public JSValue {
 public :
  JSThis(AstNode* node)
      : JSValue(JSValue::kThis),
        node_(node){}
  AstNode* node() {return node_;}
 private :
  AstNode* node_;
};

class NotConstant : public JSValue {
 public :
  NotConstant()
      : JSValue(JSValue::kNotConstant){}
};
}

#endif
