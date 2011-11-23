#include "codewriter.h"
#include "grammar.tab.hh"
#include "js_token.h"

namespace mocha {

#define TOKEN yy::ParserImplementation::token

void EraseIndent( std::string& indent , size_t size ) {
  int length = indent.size();
  if ( indent.size() > 0 && length - size >= 0 ) {
    indent.erase( length - size , length );
  }
}

class CodeWriter::WriterBase {
 public :
  virtual ~WriterBase(){}
  virtual void Write( const char* code , std::string& buffer ) = 0;
  virtual void WriteOp( int op , int type , std::string& buffer ) = 0;
};

class PrettyPrinter : public CodeWriter::WriterBase {
 public :
  PrettyPrinter( bool is_line ) : is_line_( is_line ) , last_op_( 0 ) {}
  void Write( const char* code , std::string& buffer ) {
    buffer += code;
  }
  void WriteOp( int op , int state , std::string& buffer ) {
    switch ( state ) {
      case CodeWriter::kFunctionBeginBrace :
        buffer += " {\n";
        indent_ += default_indent_;
        buffer += indent_.c_str();
        break;

      case CodeWriter::kSwitchEndBrace :
        {
          EraseIndent( indent_ , 4 );
          char tmp[500];
          sprintf( tmp , "\n%s}" , indent_.c_str() );
          buffer += tmp;
        }
        break;
        
      case CodeWriter::kBlockEndBrace : //Fall Through
      case CodeWriter::kFunctionEndBrace :
        EraseIndent( indent_ , 2 );
        char tmp[500];
        if ( last_op_ != ';' ) {
          sprintf( tmp , "\n%s}" , indent_.c_str() );
          buffer += tmp;
        } else {
          EraseIndent( buffer , 2 );
          buffer += '}';
        }
        break;

      case CodeWriter::kBlockBeginBrace :
        buffer += "{\n";
        indent_ += default_indent_;
        buffer += indent_.c_str();
        break;

      case CodeWriter::kArgs :
        if ( op == '{' ) {
          buffer += " {\n";
          indent_ += default_indent_;
          buffer += indent_.c_str();
        } else if ( '}' ) {
          EraseIndent( indent_ , 2 );
          char tmp[500];
          if ( last_op_ != ';' ) {
            sprintf( tmp , "\n%s}" , indent_.c_str() );
            buffer += tmp;
          } else {
            EraseIndent( buffer , 2 );
            buffer += '}';
          }
        } else {
          goto COMMON;
        }
        break;

      default :
      COMMON :
        CommonOperandWriter_( op , state , buffer );
    }
    last_op_ = op;
  }
 private :

  void CommonOperandWriter_( int op , int state , std::string& buffer ) {
    switch ( op ) {
      case ';' :
        if ( state == CodeWriter::kFor ) {
          buffer += ";";
        } else if ( state == CodeWriter::kVarsEnd ) {
          buffer += ";\n";
          EraseIndent( indent_ , 4 );
          buffer += indent_.c_str();
        } else {
          buffer += ";\n";
          buffer += indent_.c_str();
        }
        break;

      case ':' :
        if ( state == CodeWriter::kCase ) {
          indent_ += default_indent_;
          buffer += " :";
          buffer += '\n';
          buffer += indent_.c_str();
        } else {
          buffer += " : ";
        }
        break;
        
      case ',' :
        if ( state == CodeWriter::kVarsComma ) {
          buffer += ",\n";
          buffer += indent_.c_str();
        } else {
          buffer += " , ";
        }
        break;

      case '.' :
        buffer += '.';
        break;

      case ')' :
        if ( last_op_ == '}' ) {
          buffer += ')';
        } else {
          buffer += " )";
        }
        break;

      case '(' :
        buffer += "( ";
        break;
        
      case '{' :
        buffer += "{\n";
        indent_ += default_indent_;
        buffer += indent_.c_str();
        break;

      case '}' :
        EraseIndent( indent_ , 2 );
        buffer += '\n';
        buffer += indent_;
        if ( state == CodeWriter::kElseBlockEnd ) {
          buffer += "}\n";
        } else {
          buffer += "};\n";
        }
        buffer += indent_;
        break;
        
      case TOKEN::JS_NEW :
        if ( state == CodeWriter::kNewNoArgsBegin ) {
          buffer += "(new ";
        } else {
          buffer += "new ";
        }
        break;

      case TOKEN::JS_BREAK :
        buffer += "break";
        break;
        
      case TOKEN::JS_INSTANCEOF :
        buffer += " instanceof ";
        break;

      case TOKEN::JS_IN :
        buffer += " in ";
        break;

      case TOKEN::JS_TYPEOF :
        buffer += "typeof ";
        break;

      case TOKEN::JS_VOID :
        buffer += "void ";
        break;

      case TOKEN::JS_CASE :
        if ( last_op_ != '{' ) {
          EraseIndent( buffer , 2 );
          EraseIndent( indent_ , 2 );
        }
        buffer += "case ";
        break;

      case TOKEN::JS_CATCH :
        buffer += " catch";
        break;

      case TOKEN::JS_CONTINUE :
        buffer += "continue ";
        break;

      case TOKEN::JS_DEFAULT :
        if ( last_op_ != '{' ) {
          EraseIndent( buffer , 2 );
          EraseIndent( indent_ , 2 );
        }
        buffer += "default";
        break;

      case TOKEN::JS_DELETE :
        buffer += "delete ";
        break;

      case TOKEN::JS_DO :
        buffer += "do ";
        break;

      case TOKEN::JS_ELSE :
        buffer += " else ";
        break;

      case TOKEN::JS_FINALLY :
        buffer += " finally ";
        break;

      case TOKEN::JS_FOR :
        buffer += "for ";
        break;

      case TOKEN::JS_FUNCTION :
        buffer += "function ";
        break;

      case TOKEN::JS_RETURN :
        buffer += "return ";
        break;
        
      case TOKEN::JS_IF :
        buffer += "if ";
        break;

      case TOKEN::JS_TRY :
        buffer += "try ";
        break;

      case TOKEN::JS_WITH :
        buffer += "with ";
        break;

      case TOKEN::JS_SWITCH :
        buffer += "switch ";
        break;

      case TOKEN::JS_THROW :
        buffer += "throw ";
        break;
        
      case TOKEN::JS_WHILE :
        buffer += "while ";
        break;

      case TOKEN::JS_VAR :
        buffer += "var ";
        indent_ += ( state == CodeWriter::kFor )? "" : "    ";
        break;
        
      default :
        if ( op > 200 ) {
          char tmp[500];
          sprintf( tmp , " %s " , JsToken::GetOperatorFromNumber( op ) );
          buffer += tmp;
        } else {
          char tmp[500];
          if ( op == '=' ) {
            sprintf( tmp , " %c " , op );
          } else {
            sprintf( tmp , "%c" , op );
          }
          buffer += tmp;
        }
    }
  }

  bool is_line_;
  int last_op_;
  static const char default_indent_[];
  std::string indent_;
};


class CompressWriter : public CodeWriter::WriterBase {
 public :
  CompressWriter( bool is_line ) : is_line_( is_line ){}
  void Write( const char* code , std::string& buffer ) {
    buffer += code;
  }
  void WriteOp( int op , int state , std::string& buffer ) {
    CommonOperandWriter_( op , state , buffer );
  }
 private :

  void CommonOperandWriter_( int op , int state , std::string& buffer ) {
    switch ( op ) {
      case TOKEN::JS_NEW :
        if ( state == CodeWriter::kNewNoArgsBegin ) {
          buffer += "(new ";
        } else {
          buffer += "new ";
        }
        break;

      case TOKEN::JS_INSTANCEOF :
        buffer += " instanceof ";
        break;

      case TOKEN::JS_IN :
        buffer += " in ";
        break;

      case TOKEN::JS_TYPEOF :
        buffer += "typeof ";
        break;

      case TOKEN::JS_VOID :
        buffer += "void ";
        break;

      case TOKEN::JS_CASE :
        buffer += "case ";
        break;

      case TOKEN::JS_CATCH :
        buffer += "catch";
        break;

      case TOKEN::JS_CONTINUE :
        buffer += "continue ";
        break;

      case TOKEN::JS_DEFAULT :
        buffer += "default ";
        break;

      case TOKEN::JS_DELETE :
        buffer += "delete ";
        break;

      case TOKEN::JS_DO :
        buffer += "do";
        break;

      case TOKEN::JS_ELSE :
        buffer += "else";
        break;

      case TOKEN::JS_FINALLY :
        buffer += "finally";
        break;

      case TOKEN::JS_FOR :
        buffer += "for";
        break;

      case TOKEN::JS_FUNCTION :
        buffer += "function";
        break;

      case TOKEN::JS_IF :
        buffer += "if";
        break;

      case TOKEN::JS_TRY :
        buffer += "try";
        break;

      case TOKEN::JS_WITH :
        buffer += "with";
        break;

      case TOKEN::JS_WHILE :
        buffer += "while";
        break;

      case TOKEN::JS_VAR :
        buffer += "var";
        break;
        
      default :
        if ( op > 300 ) {
          char tmp[500];
          sprintf( tmp , "%s" , JsToken::GetOperatorFromNumber( op ) );
          buffer += tmp;
        } else {
          char tmp[500];
          sprintf( tmp , "%c" , op );
          buffer += tmp;
        }
    }
  }
 private :
  bool is_line_;
};

const char PrettyPrinter::default_indent_[] = {"  "};

CodeWriter::CodeWriter( bool is_pretty_print , bool is_line ) :
    is_pretty_print_( is_pretty_print ) , is_line_( is_line ) {
  if ( is_pretty_print ) {
    base_ = new PrettyPrinter( is_line );
  } else {
    base_ = new CompressWriter( is_line );
  }
}
CodeWriter::~CodeWriter() {
  delete base_;
}

void CodeWriter::InsertDebugSymbol( std::string& buffer ) {
  if ( is_line_ ) {
    buffer += "var __FILE__ = ''";
    base_->WriteOp( ';' , 0 , buffer );
    buffer += "var __LINE__ = 0";
    base_->WriteOp( ';' , 0 , buffer );
    buffer += "window.onerror=function( err ){try{"
        "throw new SyntaxError(err + ' in ' +  __FILE__ + ' at : ' + __LINE__ )"
        "}catch(e){"
        "  throw new Error(e);"
        "}}";
    base_->WriteOp( ';' , 0 , buffer );
  }
}

void CodeWriter::InitializeFileName( const char* file , std::string& buffer ) {
  if ( is_line_ ) {
    buffer += "var __backup__";
    base_->WriteOp( '=' , 0 , buffer );
    buffer += '"';
    buffer += file;
    buffer += '"';
    base_->WriteOp( ';' , 0 , buffer );
  }
}

void CodeWriter::SetFileName( std::string& buffer ) {
  if ( is_line_ ) {
    buffer += "__FILE__";
    base_->WriteOp( '=' , 0 , buffer );
    buffer += "__backup__";
    base_->WriteOp( ';' , 0 , buffer );
  }
}

void CodeWriter::SetLine( long line , std::string& buffer ) {
  if ( is_line_ ) {
    char tmp[50];
    sprintf( tmp , "%ld" , line );
    buffer += "__LINE__";
    base_->WriteOp( '=' , 0 , buffer );
    buffer += tmp;
    base_->WriteOp( ';' , 0 , buffer );
  }
}

void CodeWriter::Write( const char* code , std::string& buffer ) {
  base_->Write( code , buffer );
}

void CodeWriter::WriteOp( int op, int state , std::string& buffer ) {
  base_->WriteOp( op , state , buffer );
}

void CodeWriter::ModuleBeginProccessor( const char* key , const char* name , std::string& buffer ) {
  if ( is_pretty_print_ ) {
    char tmp_buf[ 500 ];
    char key_buf[ 500 ];
    sprintf( key_buf , "__global_export__[%s] = {}" , key );
    buffer += key_buf;
    base_->WriteOp( ';' , 0 , buffer );
    sprintf( tmp_buf , "__global_export__[%s]['%s'] = (function ()" , key , name );
    buffer += tmp_buf;
    base_->WriteOp( '{', kFunctionBeginBrace , buffer );
    buffer += "var __export__ = {}";
    base_->WriteOp( ';' , 0 , buffer );
  } else {
    char tmp_buf[ 500 ];
    char key_buf[ 500 ];
    sprintf( key_buf , "__global_export__[%s]={};" , key );
    buffer += key_buf;
    sprintf( tmp_buf , "__global_export__[%s]['%s']=(function(){", key , name );
    buffer += tmp_buf;
    buffer += "var __export__={};";
  }
}

void CodeWriter::ModuleEndProccessor( std::string& buffer ) {
  if ( is_pretty_print_ ) {
    buffer += "return __export__";
    base_->WriteOp( ';' , 0 , buffer );
    base_->WriteOp( '}' , kArgs , buffer );
    buffer += ")()";
    base_->WriteOp( ';' , 0 , buffer );
  } else {
    buffer += "return __export__;";
    buffer += "})();";
  }
}

}
