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
#ifndef mocha_options_h_
#define mocha_options_h_

#include <string.h>
#include <string>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/platform/utils/utils.h>

namespace mocha {
class OptionsState;
class Options {
 public :
  Options();
  ~Options(){}
  void Parse(int argc, char** argv);
  bool IsConfigSpecified() const {return flags_.At(1);};
  bool IsCompileOnly() const {return flags_.At(0);};
  bool IsDependencieCheckOnly() const {return flags_.At(2);};
  bool HasErrors() const {return errors_ > 0;}
  void PrintError() const {os::Printf("%s\n", error_.c_str());}
  const char* error() const {return error_.c_str();}
  const char* file_path() const {return file_path_.c_str();}
  const char* config_path() const {return config_path_.c_str();}
 private :
  void Analyze(const char* arg);
  void ParseCommand(const char* arg);
  void ParseArguments(const char* arg);
  int errors_;
  BitVector16 flags_;
  std::string error_;
  std::string config_path_;
  std::string file_path_;
  ScopedPtr<OptionsState> state_;
};

}

#endif //mocha_options_h_
