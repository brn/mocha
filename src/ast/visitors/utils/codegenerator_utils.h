#ifndef mocha_codegenerator_utils_h_
#define mocha_codegenerator_utils_h_
#include <string>
#include <list>
#include <utils/class_traits/uncopyable.h>
#include <ast/ast_foward_decl.h>


namespace mocha {

class CodeBuffer : private Uncopyable {
 public :
  CodeBuffer(){};
  ~CodeBuffer(){};
  inline void Write( const char* str ) { buffer_ += str; }
  inline void Write( char str ) { buffer_ += str; }
  inline void Write( const std::string& str ) { buffer_ += str; }
  inline const char* GetData() const { return buffer_.c_str(); }
  inline void Clear() { buffer_.clear(); }
  inline void Erase( size_t beg , size_t end ) { buffer_.erase( beg , end ); }
  inline size_t Size() { return buffer_.size(); }
  inline const std::string& Get() const { return buffer_; }
 private :
  std::string buffer_;
};


class CodeStream : private Uncopyable {
 public :
  CodeStream( CodeBuffer* buffer ) {
    buffer_list_.push_back( buffer );
  };
  ~CodeStream(){};
  inline void Write( const char* str ) { buffer_list_.back()->Write( str ); }
  inline void Write( char str ) { buffer_list_.back()->Write( str ); }
  inline void Write( const std::string& str ) { buffer_list_.back()->Write( str ); }
  inline void Erase( size_t beg , size_t end ) { buffer_list_.back()->Erase( beg , end ); }
  inline size_t Size() { return buffer_list_.back()->Size(); }
  inline const CodeBuffer* Get() { return buffer_list_.back(); }
  inline void SwitchBuffer( CodeBuffer *buffer ) {
    buffer_list_.push_back( buffer );
  }
  inline void SwitchBuffer() {
    if ( buffer_list_.size() > 1 ) {
      buffer_list_.pop_back();
    }
  }
 private :
  std::list<CodeBuffer*> buffer_list_;
};

}

#endif
