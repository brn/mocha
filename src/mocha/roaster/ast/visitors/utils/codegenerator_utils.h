#ifndef mocha_codegenerator_utils_h_
#define mocha_codegenerator_utils_h_
#include <string>
#include <list>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/ast/ast_foward_decl.h>


namespace mocha {

class CodeBuffer : private Uncopyable {
 public :
  CodeBuffer(){};
  ~CodeBuffer(){};
  inline void Write(const char* str) { buffer_ += str; }
  inline void Write(char str) { buffer_ += str; }
  inline void Write(const std::string& str) { buffer_ += str; }
  inline const char* GetData() const { return buffer_.c_str(); }
  inline void Clear() { buffer_.clear(); }
  inline void Erase(size_t beg, size_t end) { buffer_.erase(beg, end); }
  inline size_t Size() { return buffer_.size(); }
  inline const std::string& Get() const { return buffer_; }
 private :
  std::string buffer_;
};


class CodeStream : private Uncopyable {
 public :
  CodeStream(CodeBuffer* buffer) : buffer_(buffer){};
  ~CodeStream(){};
  inline void Write(const char* str) { buffer_->Write(str); }
  inline void Write(char str) { buffer_->Write(str); }
  inline void Write(const std::string& str) { buffer_->Write(str); }
  inline void Erase(size_t beg, size_t end) { buffer_->Erase(beg, end); }
  inline size_t Size() { return buffer_->Size(); }
  inline const CodeBuffer* Get() { return buffer_; }
 private :
  CodeBuffer* buffer_;
};

}

#endif
