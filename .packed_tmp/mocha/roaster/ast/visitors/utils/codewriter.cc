#include <iostream>
#include <sstream>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/utils/codewriter.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/memory/pool.h>

namespace mocha {

#define TOKEN yy::ParserImplementation::token

void EraseIndent(std::string& indent, int size) {
  int length = indent.size();
  if (indent.size() > 0 && length - size >= 0) {
    indent.erase(length - size, length);
  }
}

void EraseIndent(CodeStream* indent, int size) {
  int length = indent->Size();
  if (length > 0 && length - size >= 0) {
    indent->Erase(length - size, length);
  }
}

class CodeWriter::WriterBase {
 public :
  virtual ~WriterBase(){}
  virtual void Write(const char* code, CodeStream* stream) = 0;
  virtual void WriteOp(int op, int type, CodeStream* stream) = 0;
};

class PrettyPrinter : public CodeWriter::WriterBase {
 public :
  PrettyPrinter(bool is_line) : is_line_(is_line), last_op_(0), last_state_(0) {}
  void Write(const char* code, CodeStream* stream) {
    stream->Write(code);
  }
  void WriteOp(int op, int state, CodeStream* stream) {
    switch (state) {
      case CodeWriter::kFunctionBeginBrace :
        stream->Write(" {\n");
        indent_ += default_indent_;
        stream->Write(indent_.c_str());
        break;

      case CodeWriter::kSwitchEndBrace :
        {
          EraseIndent(indent_, 4);
          std::stringstream st;
          st << '\n' << indent_.c_str() << '}';
          stream->Write(st);
        }
        break;
                                
      case CodeWriter::kBlockEndBrace : //Fall Through
      case CodeWriter::kFunctionEndBrace :
        EraseIndent(indent_, 2);
        if (last_op_ != ';') {
          std::stringstream st;
          st << '\n' << indent_.c_str() << '}';
          stream->Write(st);
        } else {
          EraseIndent(stream, 2);
          stream->Write('}');
        }
        break;

      case CodeWriter::kBlockBeginBrace :
        stream->Write("{\n");
        indent_ += default_indent_;
        stream->Write(indent_.c_str());
        break;

      case CodeWriter::kArgs :
        if (op == '{') {
          stream->Write(" {\n");
          indent_ += default_indent_;
          stream->Write(indent_.c_str());
        } else if ('}') {
          EraseIndent(indent_, 2);
          if (last_op_ != ';') {
            std::stringstream st;
            st << '\n' << indent_.c_str() << '}';
            stream->Write(st);
          } else {
            EraseIndent(stream, 2);
            stream->Write('}');
          }
        } else {
          goto COMMON;
        }
        break;

      default :
      COMMON :
        CommonOperandWriter_(op, state, stream);
    }
    last_op_ = op;
  }
 private :

  void CommonOperandWriter_(int op, int state, CodeStream *stream) {
    switch (op) {
      case ';' :
        if (state == CodeWriter::kFor) {
          stream->Write(";");
        } else if (state == CodeWriter::kVarsEnd) {
          stream->Write(";\n");
          EraseIndent(indent_, 4);
          stream->Write(indent_.c_str());
        } else {
          stream->Write(";\n");
          stream->Write(indent_.c_str());
        }
        break;

      case '\n' :
        stream->Write("\n");
        stream->Write(indent_.c_str());
        break;
                                
      case ':' :
        if (state == CodeWriter::kCase) {
          indent_ += default_indent_;
          stream->Write(" :");
          stream->Write('\n');
          stream->Write(indent_.c_str());
        } else {
          stream->Write(" : ");
        }
        break;
                                
      case ',' :
        if (state == CodeWriter::kVarsComma) {
          stream->Write(",\n");
          stream->Write(indent_.c_str());
        } else {
          stream->Write(", ");
        }
        break;

      case '.' :
        stream->Write('.');
        break;

      case ')' :
        if (last_op_ == '}') {
          stream->Write(')');
        } else {
          stream->Write(")");
        }
        break;

      case '(' :
        stream->Write("(");
        break;
                                
      case '{' :
        stream->Write("{\n");
        indent_ += default_indent_;
        stream->Write(indent_.c_str());
        break;

      case '}' :
        EraseIndent(indent_, 2);
        if (state == CodeWriter::kElseBlockEnd) {
          EraseIndent(stream, 2);
          stream->Write("}");
        } else {
          stream->Write('\n');
          stream->Write(indent_);
          stream->Write("};\n");
        }
        break;
                                
      case Token::JS_NEW :
        if (state == CodeWriter::kNewNoArgsBegin) {
          stream->Write("(new ");
        } else {
          stream->Write("new ");
        }
        break;

      case Token::JS_BREAK :
        stream->Write("break");
        break;
                                
      case Token::JS_INSTANCEOF :
        stream->Write(" instanceof ");
        break;

      case Token::JS_IN :
        stream->Write(" in ");
        break;

      case Token::JS_TYPEOF :
        stream->Write("typeof ");
        break;

      case Token::JS_VOID :
        stream->Write("void ");
        break;

      case Token::JS_CASE :
        if (last_op_ != '{') {
          EraseIndent(stream, 2);
          EraseIndent(indent_, 2);
        }
        stream->Write("case ");
        break;

      case Token::JS_CATCH :
        stream->Write(" catch");
        break;

      case Token::JS_CONTINUE :
        stream->Write("continue ");
        break;

      case Token::JS_DEFAULT :
        if (last_op_ != '{') {
          EraseIndent(stream, 2);
          EraseIndent(indent_, 2);
        }
        stream->Write("default");
        break;

      case Token::JS_DELETE :
        stream->Write("delete ");
        break;

      case Token::JS_DO :
        stream->Write("do ");
        break;

      case Token::JS_ELSE :
        stream->Write(" else ");
        break;

      case Token::JS_FINALLY :
        stream->Write(" finally ");
        break;

      case Token::JS_FOR :
        stream->Write("for ");
        break;

      case Token::JS_FUNCTION :
        stream->Write("function ");
        break;

      case Token::JS_RETURN :
        stream->Write("return ");
        break;
                                
      case Token::JS_IF :
        stream->Write("if ");
        break;

      case Token::JS_TRY :
        stream->Write("try ");
        break;

      case Token::JS_WITH :
        stream->Write("with ");
        break;

      case Token::JS_SWITCH :
        stream->Write("switch ");
        break;

      case Token::JS_THROW :
        stream->Write("throw ");
        break;
                                
      case Token::JS_WHILE :
        stream->Write("while ");
        break;

      case Token::JS_VAR :
        stream->Write("var ");
        indent_ += (state == CodeWriter::kFor)? "" : "    ";
        break;
                                
      default :
        std::stringstream st;
        if (op > 127) {
          st << ' ' << JsToken::GetTokenFromNumber(op) << ' ';
          stream->Write(st);
        } else {
          if (op == '=') {
            st << ' ' << static_cast<char>(op) << ' ';
          } else {
            st << static_cast<char>(op);
          }
          stream->Write(st);
        }
    }
  }

  bool is_line_;
  int last_op_;
  int last_state_;
  static const char default_indent_[];
  std::string indent_;
};


class CompressWriter : public CodeWriter::WriterBase {
 public :
  CompressWriter(bool is_line) : is_line_(is_line), last_op_(0), last_2_op_(0), last_state_(0), last_2_state_(0){}
  void Write(const char* code, CodeStream* stream) {
    stream->Write(code);
  }
  void WriteOp(int op, int state, CodeStream* stream) {
    if (op != '\n') {
      if (last_2_state_ == CodeWriter::kBlockEndBrace && last_op_ == ';') {
        if (op == Token::JS_ELSE) {
          stream->Erase(stream->Size() - 1, stream->Size());
        }
      }
      CommonOperandWriter_(op, state, stream);
      last_2_op_ = last_op_;
      last_op_ = op;
      last_2_state_ = last_state_;
      last_state_ = state;
    } else {
      last_2_op_ = last_op_;
      last_op_ = op;
      last_2_state_ = last_state_;
      last_state_ = state;
    }
  }
 private :

  void CommonOperandWriter_(int op, int state, CodeStream* stream) {
    switch (op) {
      case Token::JS_NEW :
        stream->Write("new ");
        break;

      case Token::JS_BREAK :
        stream->Write("break");
        break;
                                
      case Token::JS_INSTANCEOF :
        stream->Write(" instanceof ");
        break;

      case Token::JS_IN :
        stream->Write(" in ");
        break;

      case Token::JS_TYPEOF :
        stream->Write("typeof ");
        break;

      case Token::JS_VOID :
        stream->Write("void ");
        break;

      case Token::JS_CASE :
        stream->Write("case ");
        break;

      case Token::JS_CATCH :
        stream->Write(" catch");
        break;

      case Token::JS_CONTINUE :
        stream->Write("continue ");
        break;

      case Token::JS_DEFAULT :
        stream->Write("default");
        break;

      case Token::JS_DELETE :
        stream->Write("delete ");
        break;

      case Token::JS_DO :
        stream->Write("do ");
        break;

      case Token::JS_ELSE :
        stream->Write("else ");
        break;

      case Token::JS_FINALLY :
        stream->Write(" finally");
        break;

      case Token::JS_FOR :
        stream->Write("for");
        break;

      case Token::JS_FUNCTION :
        stream->Write("function ");
        break;

      case Token::JS_RETURN :
        stream->Write("return ");
        break;
                                
      case Token::JS_IF :
        stream->Write("if");
        break;

      case Token::JS_TRY :
        stream->Write("try");
        break;

      case Token::JS_WITH :
        stream->Write("with");
        break;

      case Token::JS_SWITCH :
        stream->Write("switch");
        break;

      case Token::JS_THROW :
        stream->Write("throw ");
        break;
                                
      case Token::JS_WHILE :
        stream->Write("while");
        break;

      case Token::JS_VAR :
        stream->Write("var ");
        break;
                                
      default :
        if (op > 127) {
          stream->Write(JsToken::GetTokenFromNumber(op));
        } else {
          stream->Write(op);
        }
    }
  }
 private :
  bool is_line_;
  char last_op_;
  char last_2_op_;
  int last_state_;
  int last_2_state_;
};

const char PrettyPrinter::default_indent_[] = {"  "};

CodeWriter::CodeWriter(bool is_pretty_print, bool is_line) :
    is_pretty_print_(is_pretty_print), is_line_(is_line) {
  if (is_pretty_print) {
    base_ = new PrettyPrinter(is_line);
  } else {
    base_ = new CompressWriter(is_line);
  }
}
CodeWriter::~CodeWriter() {
  delete base_;
}

void CodeWriter::InsertDebugSymbol(CodeStream* stream) {
  if (is_line_) {
    stream->Write("var __LINE__ = 0");
    base_->WriteOp(';', 0, stream);
  }
}

void CodeWriter::InitializeFileName(const char* file, CodeStream* stream) {
  if (is_line_) {
    base_->WriteOp(Token::JS_VAR, 0, stream);
    stream->Write("__FILE__");
    base_->WriteOp('=', 0, stream);
    stream->Write('"');
    stream->Write(file);
    stream->Write('"');
    base_->WriteOp(',', kVarsComma, stream);
    stream->Write("__LINE__");
    base_->WriteOp('=', 0, stream);
    stream->Write("0");
    base_->WriteOp(';', kVarsEnd, stream);
  }
}

void CodeWriter::SetFileName(CodeStream* stream) {
  if (is_line_) {
    stream->Write("__FILE__");
    base_->WriteOp('=', 0, stream);
    stream->Write("__backup__");
    base_->WriteOp(';', 0, stream);
  }
}

void CodeWriter::SetLine(int64_t line, CodeStream* stream, FileRoot* root) {
  if (root && is_line_ && !root->runtime()) {
    std::stringstream st;
    st << line;
    stream->Write("__LINE__");
    base_->WriteOp('=', 0, stream);
    stream->Write(st);
    base_->WriteOp(';', 0, stream);
  }
}

void CodeWriter::Write(const char* code, CodeStream* stream) {
  base_->Write(code, stream);
}

void CodeWriter::WriteOp(int op, int state, CodeStream* stream) {
  base_->WriteOp(op, state, stream);
}

void CodeWriter::DebugBlockBegin(CodeStream* stream) {
  if (is_line_) {
    if (is_pretty_print_) {
      stream->Write("try ");
    } else {
      stream->Write("try");
    }
    base_->WriteOp('{', kBlockBeginBrace, stream);
  }
}


void CodeWriter::DebugBlockEnd(CodeStream* stream, Scope* scope) {
  if (is_line_) {
    if (is_pretty_print_) {
      base_->WriteOp('}', kBlockEndBrace, stream);
      stream->Write(" catch(e)");
      base_->WriteOp('{', kBlockBeginBrace, stream);
    } else {
      stream->Write("}catch(e){");
    }
    if (is_pretty_print_) {
      TokenInfo* runtime = new(memory::Pool::Local()) TokenInfo("Runtime", Token::JS_IDENTIFIER, 0);
      if (scope) {
        SymbolEntry entry = scope->Find(runtime);
        if (entry.first != 0) {
          TokenInfo* info = entry.first;
          stream->Write(info->compressed_name());
        } else {
          stream->Write("Runtime");
        }
      } else {
        stream->Write("Runtime");
      }
      stream->Write(".exceptionHandler(__LINE__, __FILE__, e)");
      base_->WriteOp(';', 0, stream);
      base_->WriteOp('}', kBlockEndBrace, stream);
    } else {
      stream->Write("}catch(e){");
      TokenInfo* runtime = new(memory::Pool::Local()) TokenInfo("Runtime", Token::JS_IDENTIFIER, 0);
      if (scope) {
        SymbolEntry entry = scope->Find(runtime);
        if (entry.first != 0) {
          TokenInfo* info = entry.first;
          stream->Write(info->compressed_name());
        } else {
          stream->Write("Runtime");
        }
      } else {
        stream->Write("Runtime");
      }
      stream->Write(".catchHandler(__LINE__,__FILE__,e);}");
    }
  }
}

}
