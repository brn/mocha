#ifndef mocha_ast_v8_h_
#define mocha_ast_v8_h_

namespace mocha {


class AstForV8 {
 public :
  typedef v8::Handle<v8::Value> JSValue;
  static v8::Handle<v8::Object> Init( AstNode* ast_node , ProcessorInfo* info );
  static JSValue ChildNodes( const v8::Arguments& args );
  static JSValue FirstChild( const v8::Arguments& args );
  static JSValue LastChild( const v8::Arguments& args );
  static JSValue ReplaceChild( const v8::Arguments& args );
  static JSValue ParentNode( const v8::Arguments& args );
  static JSValue NextSibling( const v8::Arguments& args );
  static JSValue PreviousSibling( const v8::Arguments& args );
  static v8::Handle<v8::String> NodeName( const v8::Arguments& args );
  static JSValue NodeType( const v8::Arguments& args );
 private :
  AstNode* ast_;
};

}

#endif
