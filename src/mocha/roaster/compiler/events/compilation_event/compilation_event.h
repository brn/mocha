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
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class CompilationInfo;
class CompilationEvent : public memory::Allocated {
 public :
  CompilationEvent(CompilationInfo* info, ErrorReporter* reporter,
                   Notificator* notificator, memory::Pool* pool);
  ~CompilationEvent(){}
  const CompilationInfo* compilation_info() const { return compilation_info_;}
  const char* source() const {return source_.c_str();}
  const char* path() const {return path_.c_str();}
  const charl* filename() const {return filename_.c_str();}
  memory::Pool* pool() {return pool_;}
  ErrorReporter* error_reporter() {return error_reporter_;}
  Notificator* notificator() {return notificator_;}
  ParserConnector* parser_connector() {return parser_connector_;}
  FileRoot* ast() {return ast_;}
  void set_source(std::stringstream* stream) {source_ = stream.str();}
  void set_path(const char* path) {path_ = path;}
  void set_filename(const char* filename) {filename_ = filename;}
  void set_ast(FileRoot* root) {ast_ = root;}
  class EventKey : private Static {
   public :
    static const char kScan[];
    static const char kParse[];
    static const char kTransform[];
  };
 private :
  std::string path_;
  std::string filename_;
  std::string char* source_;
  CompilationInfo* compilation_info_;
  ErrorReporter* reporter_;
  Notificator* notificator_;
  memory::Pool* pool_;
  ParserConnector* parser_connector_;
  FileRoot* ast_;
};

}

#endif
