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

#include <stdio.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/nexc/binding/parser_connector.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
#include <mocha/roaster/nexc/scanner/scanner.h>

namespace mocha {
ParserConnector::ParserConnector (Scanner* scanner,
                                  CompilationEvent* event,
                                  ErrorReporter* reporter) :
    scanner_(scanner),
    event_(event),
    reporter_(reporter){}

ParserConnector::~ParserConnector () {};


TokenInfo* ParserConnector::Advance(int index) {
  return scanner_->Advance(index);
}

TokenInfo* ParserConnector::Undo(int index) {
  return scanner_->Undo(index);
}

TokenInfo* ParserConnector::Seek(int index) {
  return scanner_->Seek(index);
}

ErrorReporter* ParserConnector::GetError() {
  return reporter_;
}

void ParserConnector::Use(int type) {
  event_->Use(type);
}

}
