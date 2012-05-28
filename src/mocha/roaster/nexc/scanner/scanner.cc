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
#include <string.h>
#include <string>
#include <sstream>
#ifndef PACKING_RUNTIME
#include <unicode/ucnv.h>
#endif
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/scanner/scanner.h>
#include <mocha/roaster/nexc/scanner/token_stream.h>
#include <mocha/roaster/nexc/scanner/source_stream.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/binding/parser_connector.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
namespace mocha {

#define FLAG_LB 0
#define FLAG_REST 1
#define FLAG_NUMERIC 2
#define FLAG_REGEXP 3

static const char* kUnicodeMap[] = {"", "\\x0", "\\x", "\\u0", "\\u"};
static const int kByteOrderMark[2] = {0xFFFE, 0xFEFF};
#ifndef PACKING_RUNTIME
void EscapeUnicode(const icu::UnicodeString& ustr, std::string* buffer) {
  std::string buf;
  for (int i = 0,len = ustr.length(); i < len; i++) {
    int32_t val = ustr.char32At(i);
    if (val > 127 || val < 0) {
      std::string result;
      os::SPrintf(&buf, "%x", val);
      os::SPrintf(&result, "%s%s", kUnicodeMap[buf.size()], buf.c_str());
      buffer->append(result);
    } else {
      os::SPrintf(&buf, "%c", val);
      buffer->append(buf);
    }
    buf.clear();
  }
}
#endif
void Scanner::ScannerEventListener::operator()(CompilationEvent* e) {
  const char* source = e->source();
  memory::Pool* pool = e->pool();
  SourceStream* stream = SourceStream::New(source, e->charset(), pool);
  ErrorReporter* reporter = e->error_reporter();
  const char* filename = e->filename();
  Scanner* scanner = Scanner::New(stream, reporter, filename);
  ParserConnector* connector = new(pool) ParserConnector(scanner, e, reporter);
  e->set_parser_connector(connector);
  e->NotifyForKey(Nexc::kParse);
}

class Scanner::InternalScanner : public memory::Allocated {
 public :
  InternalScanner(SourceStream* source, ErrorReporter* reporter, const char* filename) :
      line_(1),
      filename_(filename),
      token_stream_(TokenStream::New(memory::Pool::Local())),
      source_stream_(source),
      reporter_(reporter) {
    flags_.Set(FLAG_REGEXP);
    flags_.Set(FLAG_NUMERIC);
  }

  /**
   * @public
   * Collect token and push into the token queue.
   */
  inline void CollectToken() {
    while (!IsEof()) {
      Skip();
      if (flags_.At(FLAG_LB)) {
        TokenInfo* info = token_stream_->last();
        if (info) {
          info->set_linebreak_after();
        }
        flags_.UnSet(FLAG_LB);
      }
      int ch = Advance();
      if (IsIdentStart(ch, true)) {
        //identifier
        CaseIdent(ch);
      } else if (isdigit(ch)) {
        //numeric begin with 0...9
        CaseDigit(ch);
      } else if (flags_.At(FLAG_NUMERIC) && ch == '.') {
        //numeric begin with '.'
        //treat as float.
        CaseDigitBeginWithDot(ch);
      } else if (IsSingleOperator(ch)) {
        //operator that is not continue after operator. Like { } [ ]
        token_stream_->Append("", ch, line_);
      } else if (IsNotSingleOperator(ch)) {
        //operator like + - =
        CaseNotSingleOperator(ch);
      } else if (ch != 0 && ch != Token::END_OF_INPUT){
        std::stringstream st;
        st << "Illegal token '"
           << ch << "' in " << filename_ << " at : " << line_;
        reporter_->ReportSyntaxError(st.str().c_str());
      }
      SetRegExpAfter();
      SetNumericAfter();
    }
    TokenInfo* last = token_stream_->last();
    if (last) {
      last->set_linebreak_after();
    }
    //Sentinel.
    token_stream_->Append("", Token::END_TOKEN, 0);
  }

  inline TokenStream* GetStream() {
    return token_stream_;
  }
                                
 private :

  /**
   * @private
   * Check char is unicode's byte order mark or not.
   */
  bool IsByteOrderMark(char data) {
    return (data == kByteOrderMark[0] || data == kByteOrderMark[1]);
  }
                                
  /**
   * @private
   * Check source end or not.
   */
  inline bool IsEof() {
    return source_stream_->Seek(1) == Token::END_OF_INPUT || source_stream_->Seek(1) == 0;
  }


  inline int Seek(int len) {
    return source_stream_->Seek(len);
  }

  /**
   * @private
   * Get next char form source.
   */
  inline int Advance(int len = 1) {
    if (IsEof()) {
      return 0;
    } else {
      return source_stream_->Advance(len);
    }
  }

  /**
   * @private
   * Decrement source index.
   */
  inline void Undo(int len = 1) {
    source_stream_->Undo(len);
  }
                                
  /**
   * @private
   * Skip all comment, unicode's byte order mark, whitespace and linebreak.
   */
  void Skip() {
    int ch = Seek(1);
    int next = Seek(2);
    bool isbreak = IsBreak(ch);
    //Check that token is whitespace or line break.
    if (IsWhiteSpace(ch) || IsByteOrderMark(ch) || isbreak) {
      Advance();
      //Add line number.
      if (isbreak) {
        flags_.Set(FLAG_LB);
        line_++;
      }
      isbreak = false;
      Skip ();
    } else if (ch == '/' && next == '*') {
      Advance(2);
      //Process multiline comment.
      SkipMultiLineComment ();
      //Check is whitespace or singleline comment continue.
      Skip();
    } else if (ch == '/' && next == '/') {
      Advance(2);
      //Process single line comment.
      SkipComment();
      //Check is whitespace or multiline comment continue.
      Skip();
    }
  }

  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check is whitespace or not.
   */
  inline bool IsWhiteSpace(int ch) {
    if (ch == ' ' ||
        ch == '\t'||
        ch == '\r') {
      return true;
    } else {
      return false;
    }
  }

  /**
   * @private
   * @param {char}
   * @return {bool}
   * Check is line break or not.
   */
  inline bool IsBreak(int ch) {
    if (ch == '\n') {
      return true;
    }
    return false;
  }

  /**
   * @private
   * cosume token while multiline comment block is continue.
   */
  inline void SkipMultiLineComment() {
    int ch;
    while (!IsEof()) {
      ch = Advance();
      int next = Advance();
      //End of multiline comment.
      if (ch == '*' && next == '/') {
        return;
      } else {
        if (ch == '\n') {
          line_++;
          flags_.Set(FLAG_LB);
        }
        Undo();
      }
    }
  }

  /**
   * @private
   * Consume token while single line comment is continue.
   */
  inline void SkipComment() {
    int ch;
    while (!IsEof()) {
      ch = Advance();
      if (ch == '\n') {
        line_++;
        flags_.Set(FLAG_LB);
        return;
      }                                  
    }
  }
                                
  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check is identifier token start or not.
   */
  inline bool IsIdentStart(int ch, bool is_begin) {
    int next = Seek(1);
    if (isalpha(ch) || 
        ch == '_' || 
        ch == '$' ||
        //treat special token.
        ch == '@') {
      return true;
    } else if (is_begin && ch == '\\' && next == 'u') {
      return true;
    } else {
      return false;
    }
  }


  /**
   * @private
   * @param {char}
   * Collect identifier.
   */
  inline void CaseIdent(int ch) {
    token_str_ = ch;
    int next = Seek(1);
    while (IsIdentStart(next, false) || isdigit(next)) {
      Advance();
      token_str_ += next;
      next = Seek(1);
    }
    PushBack(token_str_.c_str());
  }


  /**
   * @private
   * @param {char}
   * In case of numeric literal.
   */
  inline void CaseDigit(int ch) {
    token_str_ = ch;
    int next = tolower(Seek(1));
    if (next == '.') {
      Advance();
      CaseDigitFloat(next);
    } else if (next == 'x' && ch == '0') {
      Advance();
      CaseDigitHex(next);
    } else if (isdigit (next) || next == 'e') {
      Advance();
      CaseDigitNumber(next);
    }
    PushBack(token_str_.c_str(), Token::JS_NUMERIC_LITERAL);
  }


  /**
   * @private
   * @param {char}
   * Case float.
   */
  inline void CaseDigitFloat(int ch) {
    token_str_ += ch;
    bool hasIndex = false;
    int next;
    char last = 0;
                                                                
    while ((next = Seek(1))) {
      next = tolower(next);
      
      if (isdigit (next)) {
        Advance();
        token_str_ += next;
        last = next;
        hasIndex = false;
      } else if ((next == 'e' && !hasIndex) &&
                 last != 'e') {
        Advance();
        token_str_ += next;
        last = next;
        hasIndex = true;
      } else if ((next == '+' || next == '-') && last == 'e') {
        Advance();
        token_str_ += next;
        last = next;
        hasIndex = false;
      } else {
        break;
      }
    }
  }


  inline bool IsHex(int ch) {
    if (isdigit(ch) ||
        ch == 'a' ||
        ch == 'b' ||
        ch == 'c' ||
        ch == 'd' ||
        ch == 'e' ||
        ch == 'f')            {
      return true;
    }
    return false;
  }


  inline void CaseDigitHex(int ch) {

    int next;
    token_str_ += ch;
    Advance();
    while ((next = Seek(1))) {
      next = tolower (next);
      if (IsHex(next)) {
        Advance();
        token_str_ += next;
      } else if (isdigit(next)) {
        Advance();
        token_str_ += next;
      } else {
        break;
      }
    }
  }


  inline void CaseDigitNumber(int ch) {
    token_str_ += ch;
    bool hasIndex = (ch == 'e')? true : false;
    char last = ch;
    int next;
    while ((next = Seek(1))) {
      next = tolower (next);
                                                                
      if (isdigit (next)) {
        Advance();
        token_str_ += next;
        last = next;
      } else if (next == '.') {
        Advance();
        token_str_ += next;
        return CaseDigitFloat(Advance());
      } else if (next == 'e' &&
                 !hasIndex &&
                 last != 'e') {
        Advance();
        token_str_ += next;
        last = next;
      } else if ((next == '+' || next == '-') &&
                 last == 'e') {
        Advance();
        token_str_ += next;
        last = next;
      } else {
        break;
      }
    }
  }


  inline void CaseDigitBeginWithDot(int ch) {
    token_str_ = ch;
    bool hasIndex = false;
    char last;
    int next;
    int index = 0;
                                
    while ((next = Seek(1))) {
      if (isdigit (next)) {
        Advance();
        token_str_ += next;
        last = next;
      } else if (next == '.' && index == 0) {
        if (Seek(2) == '.') {
          Advance(2);
          token_str_ += "..";
          PushBack(token_str_.c_str(), Token::JS_PARAMETER_REST);
          return;
        } else {
          Advance();
          std::string buf;
          os::SPrintf(&buf, "Illegal token %c in %s at : %ll", Seek(1), filename_, line_);
          reporter_->ReportSyntaxError(buf.c_str());
          break;
        }
      } else if (next == 'e' &&
                 !hasIndex &&
                 last != 'e') {
        Advance();
        token_str_ += next;
        last = next;
      } else if ((next == '+' || next == '-') &&
                 last == 'e') {
        Advance();
        token_str_ += next;
        last = next;
      } else {
        break;
      }
      index++;
    }
    PushBack(token_str_.c_str(), Token::JS_NUMERIC_LITERAL);
  }
                                
                                
  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Distinct parameter char is operators that is continue after operator. 
   */
  inline bool IsSingleOperator(int ch) {
    if (ch == '(' || ch == ')' ||
        ch == '{' || ch == '}' ||
        ch == '[' || ch == ']' ||
        ch == '~' || ch == ',' ||
        ch == '.' || ch == ':' ||
        ch == ';' || ch == '?' ||
        ch == '#') {
      int next = Seek(1);
      int next_after_ = Seek(2);
      if (ch == '.' && next == ch && next_after_ == ch) {
        flags_.Set(FLAG_REST);
        return false;
      }
      return true;
    }
    return false;
  }
                                

  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check operator like + = -
   */
  inline bool IsNotSingleOperator(int ch) {
    if (!IsSingleOperator(ch) && 
        ((ch > 32 && ch < 48) ||
         (ch > 57 && ch < 65) ||
         (ch > 90 && ch < 97) ||
         (ch > 122 && ch < 127) ||
         flags_.At(FLAG_REST)) &&
        ch != 35 && ch != 127 && ch != 96 &&
        !isalpha (ch)) {
      return true;
    } else {
      return false;
    }
  }


  inline void CaseNotSingleOperator(int ch) {
    token_str_ = ch;
                                                                
    switch (ch) {
      case '.' :
        {
          if (flags_.At(FLAG_REST)) {
            token_str_ += Advance();
            token_str_ += Advance();
            PushBack(Token::JS_PARAMETER_REST);
            flags_.UnSet(FLAG_REST);
          }
        }
        break;
                                                                                                                                
      case '"' :
      case '\'' :
        {
          CaseStringLiteral(ch);
        }
        break;
                                                                                                                                
      case '=' :
      case '!' :
        {
          CaseEqualitiesORFunGlyph();
        }
        break;
                                                                                                                                
      case '-' :
      case '+' :
        {
          CaseAddAndSubORFunGlyph(ch);
        }
        break;
                                                                                                                                
      case '/' :
      case '*' :
      case '%' :
        {
          if (ch == '/' &&
              flags_.At(FLAG_REGEXP)) {
            CaseRegExpLiteral();
          } else {
            CaseUnary();
          }
        }
        break;
                                                                                                                                
      case '|' :
      case '&' :
      case '^' :
      case '<' :
        {
          CaseLogical(ch);
        }
        break;
                                                                                                                                
      case '>' :
        {
          CaseShiftRight();
        }
        break;
    }
  }

                                
  inline void CaseStringLiteral(int ch) {
    int next = Seek(1);
    int next_after_ = Seek(2);
    bool escaped = false;

    if (next == ch && next_after_ == ch) {
      Advance(2);
      while ((next = Advance())) {
        if (next == '\n') {
          line_++;
        } else if (next != '\r') {
          token_str_ += next;
        }
        int next_after = Advance();
        int next_after_after = Advance();
        if (next == ch && next_after == ch && next_after_after == ch) {
          break;
        } else {
          Undo(2);
        }
      }
    } else {
      if (next == ch) {
        token_str_ += ch;
        Advance();
      } else {
        while ((next = Advance())) {
          if (!escaped && next == '\\') {
            escaped = true;
          } else {
            escaped = false;
          }
          token_str_ += next;
          next = Seek(1);
          if (!escaped && next == '\n') {
            break;
          }
          if (!escaped && next == ch) {
            token_str_ += next;
            Advance();
            break;
          }
        }
      }
    }
#ifndef PACKING_RUNTIME
    const icu::UnicodeString ustr(token_str_.c_str(), token_str_.size(), "utf8");
    token_str_.clear();
    EscapeUnicode(ustr, &token_str_);
#endif
    PushBack(token_str_.c_str(), Token::JS_STRING_LITERAL);
  }


  inline void CaseEqualitiesORFunGlyph() {
    int next = Seek(1);
    if (next == '=') {
      Advance();
      token_str_ += next;
      next = Seek(1);
      if (next == '=') {
        Advance();
        token_str_ += next;
      }
    } else if (next == '>') {
      Advance();
      token_str_ += next;
    }
    PushBack(JsToken::GetType(token_str_.c_str (), true));
  }


                                
  inline void CaseAddAndSubORFunGlyph(int ch) {
    int next = Seek(1);
    if (next == ch || next == '=') {
      Advance();
      token_str_ += next;
    } else if (ch == '-' && next == '>') {
      Advance();
      token_str_ += next;
    }
    PushBack(JsToken::GetType (token_str_.c_str (), true));
  }
                                
                                
  inline void CaseRegExpLiteral() {
    bool isescaped = false;
    bool ischar_class = false;
    int next;                                                            
    while ((next = Advance())) {
      if (!isescaped &&
          next == '\\') {
        isescaped = true;
        token_str_ += next;
      } else if (!isescaped &&
                 next == '[') {
        ischar_class = true;
        isescaped = false;
        token_str_ += next;
      } else if (!isescaped &&
                 ischar_class &&
                 next == ']') {
        ischar_class = false;
        token_str_ += next;
      } else if (!isescaped &&
                 !ischar_class &&
                 next == '/') {
        CaseRegExpFlag(next);
        break;
      } else {
        isescaped = false;
        token_str_ += next;
      }
    }
  }
                                
  inline void CaseRegExpFlag(int ch) {
    token_str_ += ch;
    char flag = Seek(1);
    bool has_error = false;
    std::string flag_list;
    BitVector8 flags;
    while (isalpha(flag)) {
      if (flag == 'i' ||
          flag == 'g' ||
          flag == 'm') {
        if (!CheckRegExpFlags(&flags, flag, &flag_list)) {
          has_error = true;
        }
      } else {
        has_error = true;
        flag_list += flag;
      }
      Advance();
      flag = Seek(1);
    }
    if (has_error) {
      std::stringstream st;
      st << "Illegal regular expression flags '"
         << flag_list << "' in " << filename_ << " at : " << line_;
      reporter_->ReportSyntaxError(st.str().c_str());
    } else {
#ifndef PACKING_RUNTIME
      icu::UnicodeString ustr(token_str_.c_str(), token_str_.size(), "utf8");
      token_str_.clear();
      EscapeUnicode(ustr, &token_str_);
#endif
      PushBack(token_str_.c_str(), Token::JS_REGEXP_LITERAL);
    }
  }

                                
  inline bool CheckRegExpFlags(BitVector8 *flags, char flag, std::string *flag_list) {
    if (flag == 'i') {
      return SetRegExpFlags(flags, flag, flag_list, 0);
    } else if (flag == 'g') {
      return SetRegExpFlags(flags, flag, flag_list, 1);
    } else if (flag == 'm') {
      return SetRegExpFlags(flags, flag, flag_list, 2);
    }
    return false;
  }

                                
  inline bool SetRegExpFlags(BitVector8 *flags, char flag, std::string *flag_list, int pos) {
    if (!flags->At(pos)) {
      flags->Set(pos);
      token_str_ += flag;
      (*flag_list) += flag;
      return true;
    } else {
      (*flag_list) += flag;
      return false;
    }
  }

                                
  inline void CaseUnary() {
    int next = Seek(1);
    if (next == '=') {
      Advance();
      token_str_ += next;
    }
    PushBack(JsToken::GetType(token_str_.c_str (), true));
  }


  inline void CaseLogical(int ch) {
    int next = Seek(1);                                
    if (next == ch) {
      Advance();
      token_str_ += next;
      if (ch == '<' && next == '<') {
        next = Seek(1);
        if (next == '=') {
          token_str_ += next;
          Advance();
        }
      }
    } else if ((ch == '|' ||
                ch == '^' ||
                ch == '<' ||
                ch == '&') &&
               next == '=') {
      Advance();
      token_str_ += next;
    }
    PushBack(JsToken::GetType (token_str_.c_str(), true));
  }


  inline void CaseShiftRight() {
    int next = Seek(1);
    if (next == '>') {
      Advance();
      token_str_ += next;
      next = Seek(1);
      if (next == '>') {
        Advance();
        token_str_ += next;
        next = Seek(1);
        if (next == '=') {
          token_str_ += next;
          Advance();
        }
      } else if (next == '=') {
        Advance();
        token_str_ += next;
      }
    } else if (next == '=') {
      Advance();
      token_str_ += next;
    }
    PushBack(JsToken::GetType(token_str_.c_str(), true));
  }


  inline void SetNumericAfter() {
    int type = (token_stream_->size() > 0)? token_stream_->last()->type() : 0;
    if (JsToken::IsBinaryOperatorNoIn(type) ||
        type == '[' ||
        type == '{' ||
        type == '(' ||
        type == '*' ||
        type == '/' ||
        type == '+' ||
        type == '-' ||
        type == '=' ||
        type == '^' ||
        type == '&' ||
        type == '|' ||
        type == ':' ||
        type == ',' ||
        type == ';' ||
        type == '~' ||
        type == '>' ||
        type == '<' ||
        type == '!' ||
        type == Token::JS_RETURN ||
        type == Token::JS_FUNCTION_GLYPH ||
        type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      flags_.Set(FLAG_NUMERIC);
    } else {
      flags_.UnSet(FLAG_NUMERIC);
    }
  }


  inline void SetRegExpAfter() {
    int type = (token_stream_->size() > 0)? token_stream_->last()->type() : 0;
    if (JsToken::IsBinaryOperator(type) ||
        type == '}' ||
        type == '|' ||
        type == '{' ||
        type == '^' ||
        type == '[' ||
        type == '?' ||
        type == '=' ||
        type == ';' ||
        type == ':' ||
        type == ',' ||
        type == '(' ||
        type == '&' ||
        type == '!' ||
        type == '+' ||
        type == '-' ||
        type == '/' ||
        type == '%' ||
        type == '*' ||
        type == '~' ||
        type == '>' ||
        type == '<' ||
        type == Token::JS_RETURN ||
        type == Token::JS_FUNCTION_GLYPH ||
        type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      flags_.Set(FLAG_REGEXP);
    } else {
      flags_.UnSet(FLAG_REGEXP);
    }
  }
                                
                                
  /**
   * @private
   * @param {const char*}
   * Get type of token and call DoPushBack_.
   */
  inline void PushBack(const char* ctoken, int opt_type = 0) {
    int type = (opt_type == 0)? JsToken::GetType(ctoken) : opt_type;
    if (type == Token::JS_EACH) {
      if (token_stream_->size() > 0 && token_stream_->last()->type() != Token::JS_FOR) {
        type = Token::JS_IDENTIFIER;
      }
    }
    DoPushBack(ctoken, type);
  }

  /**
   * @private
   * @param {char}
   * Call DoPushBack_ with set type to arguments.
   */
  inline void PushBack(int ch) {
    if (ch == '(' && token_stream_->size() >= 2) {
      TokenInfo* info = token_stream_->Seek(2);
      if (info != Scanner::kEmpty && info->type() == Token::JS_IDENTIFIER) {
        if (info && strcmp(info->token(), "get") == 0) {
          info->set_type(Token::JS_GET);
        } else if (info && strcmp(info->token(), "set") == 0) {
          info->set_type(Token::JS_SET);
        }
      }
    }
    DoPushBack("", ch);
  }

  /**
   * @private
   * @param {const char*}
   * @param {int}
   * Push back a pointer of TokenInfo to token_stream_.
   */
  inline void DoPushBack(const char* ctoken, int type) {
    TokenInfo* info = token_stream_->last();
    token_stream_->Append(ctoken, type, line_);
    if (info && info->linebreak_after()) {
      token_stream_->last()->set_linebreak_befor();
    }
  }

  int64_t line_;
  const char* filename_;
  BitVector8 flags_;
  TokenStream* token_stream_;
  SourceStream* source_stream_;
  std::string token_str_;
  ErrorReporter *reporter_;
};

Scanner* Scanner::New(SourceStream* stream, ErrorReporter* reporter, const char* filename) {
  Scanner* scanner = new(memory::Pool::Local()) Scanner(stream, reporter, filename);
  scanner->CreateTokenStream();
  scanner->token_stream_ = scanner->scanner_->GetStream();
  return scanner;
}

Scanner::Scanner(SourceStream* source, ErrorReporter* reporter, const char* filename)
    : scanner_(new(memory::Pool::Local()) InternalScanner(source, reporter, filename)),
      reporter_(reporter){}
Scanner::~Scanner(){}

TokenInfo* Scanner::Advance(int index) {
  return token_stream_->Advance(index);
}

TokenInfo* Scanner::Undo(int index) {
  return token_stream_->Undo(index);
}

TokenInfo* Scanner::Seek(int index) {
  return token_stream_->Seek(index);
}

void Scanner::CreateTokenStream() {
  scanner_->CollectToken();
}

TokenInfo* Scanner::kEmpty = 0;

}
