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
#include <mocha/misc/int_types.h>
#include <string>
#include <vector>
#include <mocha/shell/shell.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/options/setting.h>

namespace mocha {
class Options {
 public :
    Options() : is_observe_(false){}
  ~Options(){}
  void AnalyzeOption (const char* argv) { DoAnalyzeOption(argv);}
  const char* GetPath () const { return path_.c_str();}
  bool IsCommandLineCompile() { return flags_.At(0); }
  bool IsPrettyPrint() { return flags_.At(1); }
  bool IsDebug() { return flags_.At(2); }
  bool IsPath() { return flags_.At(3); }
  bool IsCompress() { return flags_.At(4); }
  bool IsUnmatch() { return flags_.At(5); }
  void ShowError() {
    printf("%s\n", error_.c_str());
  }
  void StopObserve() {flags_.Set(6);}
  bool IsStopObserving() {return flags_.At(6);}
  bool IsFile() { return flags_.At(7); }
  void Reset() {
    error_.clear();
    path_.clear();
    BitVector16 flag;
    flags_ = flag;
  }
 private :
  void CommandLineCompile() { flags_.Set(0); }
  void DoAnalyzeOption(const char* argv);
  
  void MatchOptions(char arg);

  void UnrecognizedOption(const char* opt);
  
  void OptionNotEnough(const char* opt);
  void PrettyPrint() { flags_.Set(1); }
  void Debug() { flags_.Set(2); }
  void HasPath() { flags_.Set(3); }
  void Compress() { flags_.Set(4); }
  void SetFile() {flags_.Set(7);}
  void Unmatch(const char* op) {
    flags_.Set(5);
    UnrecognizedOption(op);
  }
    bool is_observe_;
  BitVector16 flags_;
  std::string error_;
  std::string path_;
};

}

#endif //mocha_options_h_
