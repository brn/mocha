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
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/binding/parser_connector.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/scanner/scanner.h>
#include <mocha/roaster/scanner/source_stream.h>
#include <mocha/roaster/utils/error_reporter.h>

namespace mocha {
ParserConnector::ParserConnector ( Compiler *compiler,
                                   AstRoot* ast_root,
                                   Scanner* scanner,
                                   SourceStream* stream,
                                   ErrorReporter* reporter ) :
    scanner_( scanner ), stream_( stream ), reporter_( reporter ){}

ParserConnector::~ParserConnector () {};


TokenInfo* ParserConnector::Advance( int index ) {
  return scanner_->Advance( index );
}

TokenInfo* ParserConnector::Undo( int index ) {
  return scanner_->Undo( index );
}

TokenInfo* ParserConnector::Seek( int index ) {
  return scanner_->Seek( index );
}

ErrorReporter* ParserConnector::GetError() {
  return reporter_;
}

}
