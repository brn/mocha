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


#ifndef Scanner_h
#define Scanner_h

#include <string>
#include "uncopyable.h"
#include "scanner_state.h"
#include "define.h"

namespace mocha {
  
class BaseTokenizer;
class ParserTracer;
class ParserData;
  
/**
 *@class
 *Tokenize input file.
 *Called by bison.
 *@extends Uncopyable
 */
class Scanner : private Uncopyable {
  
 public:
  /**
   *@constructor
   *@param {const char*} source
   */
  explicit Scanner ( const char* source , ParserTracer* tracer );

  /**
   *@destructor
   */
  ~Scanner();
    
  /**
   *@public
   *@returns {char*}
   *@description
   *Tokenize a token.
   */
  char* GetToken ();
    
  /**
   *@public
   *@returns {long int}
   *@description
   *Get current line number.
   */
  inline long JPM_CONST int GetLineNumber () const {

    return line_;

  }
    
  /**
   *@public
   *@returns {int}
   *@description
   *Get current token type.
   */
  int GetType () const {

    return type_;

  }
    
 private:
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct operator.
   */
  inline JPM_CONST bool IsOperator_ ( char ch ) const;
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Decide is ident start.
   */
  inline JPM_CONST bool IsIdentStart_ ( char ch ) const;
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct white space.
   */
  inline JPM_CONST bool IsWhiteSpace_ ( char ch ) const;
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct line break.
   */
  inline JPM_CONST bool IsBreak_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct close symbol like } , ).
   */
  inline JPM_CONST bool IsClose_ ( char ch ) const;
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct operator that not operator continue.
   */
  inline JPM_CONST bool IsSingleOperator_ ( char ch ) const;
    
  /**
   *@private
   *@param {char} ch
   *@returns {bool}
   *@description
   *Distinct operator that continuable operator after.
   */
  inline JPM_CONST bool IsNotSingleOperator_ ( char ch ) const;
    
  /**
   *@private
   *@returns {bool}
   *@description
   *Distinct end of stream.
   */
  inline JPM_PURE bool IsEof_ () const;
    
  /**
   *@private
   *@description
   *Skip comment , whitespace and line break.
   */
  inline void Skip_ ();
    
  /**
   *@private
   *@description
   *Return is RegExp continuable or not. 
   */
  inline void SetRegExpAfter_ ();
    
  /**
   *@private
   *@description
   *Return is Number continuable or not. 
   */
  inline void SetNumericAfter_ ();
    
  /**
   *@private
   *@description
   *Get a char from source_ 
   */
  inline char GetChar_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Rollback n char in souce_. 
   */
  inline void BackChar_ ( int len = 1 );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Skip multiline comment. 
   */
  inline void SkipMultiLineComment_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Skip single line comment. 
   */
  inline void SkipComment_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process ident.
   */
  inline void CaseIdent_ ( char ch );

  /**
   *@private
   *@param {char} ch
   *@description
   *Process digit.
   */
  inline void CaseDigit_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Called in CaseDigit_ process float.
   */
  inline void CaseDigitFloat_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Called in CaseDigit_ process Hex.
   */
  inline void CaseDigitHex_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Called in CaseDigit_ process Number.
   */
  inline void CaseDigitNumber_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Called in CaseDigit_ process dot begin float.
   */
  inline void CaseDigitBeginWithDot_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process operators that usable with double or triple .
   */
  inline void CaseNotSingleOperator_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process string literal.
   */
  inline void CaseStringLiteral_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process equalities expression.
   */
  inline void CaseEqualities_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process plus operator or minus operator.
   */
  inline void CaseAddAndSub_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process RegExp literal.
   */
  inline void CaseRegExpLiteral_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Called in CaseRegExpLiteral_ process RegExp flag.
   */
  inline void CaseRegExpFlag_ ( char ch );

  /**
   *@private
   *@param {char} ch
   *@description
   *Process unary operator.
   */
  inline void CaseUnary_ ();
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process logical condition operator or bit operator.
   */
  inline void CaseLogical_ ( char ch );
    
  /**
   *@private
   *@param {char} ch
   *@description
   *Process right shift operators.
   */
  inline void CaseShiftRight_ ();

  //! Current state.
  ScannerState state_;
    
  //! Token buffer.
  STR tokenStack_;
  STR tmp_stack_;
  STR source_;
  int index_;
  int max_;
  long int line_;
  //! return LINE_BREAK token or not.
  bool isLt_;
  bool end_of_block_;
  bool use_tmp_;
  int type_;
  int tmp_type_;
  ParserTracer* tracer_;
};
}

#endif

