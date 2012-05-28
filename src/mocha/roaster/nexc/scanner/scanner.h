/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
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
#ifndef mocha_roaster_nexc_scanner_scanner_h_
#define mocha_roaster_nexc_scanner_scanner_h_
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
class ErrorReporter;
class SourceStream;
class TokenInfo;
class TokenStream;
class JsToken;
class CompilationEvent;
class Scanner : public memory::Allocated {
 public :
  static Scanner* New(SourceStream* source, ErrorReporter *reporter, const char* filename);
  class ScannerEventListener {
   public :
    void operator()(CompilationEvent* event);
  };
  ~Scanner();
  TokenInfo* Advance(int index = 1);
  TokenInfo* Undo(int index = 1);
  TokenInfo* Seek(int index);
  static TokenInfo* kEmpty;
 private :
  Scanner(SourceStream* source, ErrorReporter *reporter, const char* filename);
  void CreateTokenStream();
  
  class InternalScanner;
  InternalScanner* scanner_;
  TokenStream* token_stream_;
  ErrorReporter* reporter_;
};
}

#endif
