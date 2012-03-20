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
#ifndef mocha_compiler_loader_loader_h_
#define mocha_compiler_loader_loader_h_
#include <stdio.h>
#include <string>
#include <sstream>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/compiler/events/io_event/io_event.h>
namespace mocha {
class Loader : public Notificator<IOEvent*> {
 public :
  Loader();
  ~Loader();
  void LoadFile(const char* path);
  static const char kComplete[];
  static const char kError[];
 private :
  enum {
    kFOpenError,
    kNotAFile,
    kNotFound
  };
  void ReadNormalFile(FILE* fp, std::stringstream *st);
  void HandleError(const char* path, int type);
  memory::Pool pool_;
};
}
#endif
