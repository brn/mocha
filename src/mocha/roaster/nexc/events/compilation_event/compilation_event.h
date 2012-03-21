/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_roaster_compiler_compilation_event_h_
#define mocha_roaster_compiler_compilation_event_h_
#include <string>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class Nexc;
class ErrorReporter;
class ParserConnector;
class FileRoot;
class CompilationEvent : public memory::Allocated {
 public :
  CompilationEvent(Nexc* nexc, ErrorReporter* reporter, memory::Pool* pool)
      : nexc_(nexc),
        error_reporter_(reporter),
        pool_(pool){}
  ~CompilationEvent(){}
  const char* source() const {return source_.c_str();}
  const char* path() const {return path_.c_str();}
  const char* filename() const {return filename_.c_str();}
  const char* charset() const {return charset_.c_str();}
  memory::Pool* pool() {return pool_;}
  ErrorReporter* error_reporter() {return error_reporter_;}
  ParserConnector* parser_connector() {return parser_connector_;}
  FileRoot* ast() {return ast_;}
  void set_source(const char* source) {source_ = source;}
  void set_path(const char* path) {path_ = path;}
  void set_filename(const char* filename) {filename_ = filename;}
  void set_ast(FileRoot* root) {ast_ = root;}
  void set_charset(const char* charset) {charset_ = charset;}
  void set_parser_connector(ParserConnector* connector) {parser_connector_ = connector;}
  void NotifyForKey(const char* key) {nexc_->NotifyForKey(key, this);}
 private :
  std::string path_;
  std::string filename_;
  std::string source_;
  std::string charset_;
  Nexc* nexc_;
  ErrorReporter* error_reporter_;
  memory::Pool* pool_;
  ParserConnector* parser_connector_;
  FileRoot* ast_;
};

}

#endif
