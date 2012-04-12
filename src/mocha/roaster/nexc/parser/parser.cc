#include <assert.h>
#include <vector>
#include <sstream>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/parser/parser.h>
#include <mocha/roaster/nexc/scanner/token_stream.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>

namespace mocha {

static const char use_strict[] = { "use strict" };
static const char literals[] = { "'identifier', 'String', 'Number', 'Boolean', 'this', 'RegExp'" };
#define RETURN_FLG 0
#define YIELD_FLG 1
//Shortcut for syntax error reporter.
#define SYNTAX_ERROR(msg) {                           \
    std::stringstream st;                               \
    st << msg;                                          \
    reporter_->ReportSyntaxError(st.str().c_str());   \
  }

//Check error occured or not.
//If error occured, immediate return an argument value.
#define CHECK_ERROR(name) {                     \
    if (reporter_->Error()) {                 \
      return name;                              \
    }                                           \
  }

//Debug flag.
//#define PARSER_DEBUG 1

//Print parser move to fp.
#ifdef PARSER_DEBUG

#define ENTER(mode)                                                     \
  fflush(stdout);                                                       \
  indent_+=' ';                                                         \
  fprintf(stdout, "%snext token = %s enter %s %d\n", indent_.c_str(),TokenConverter(Seek()).cstr(),#mode, depth_); \
  depth_++

#define END(mode)                                                       \
  fflush(stdout);                                                       \
  fprintf(stdout, "%snext token = %s end %s %d\n", indent_.c_str(),TokenConverter(Seek()).cstr(),#mode, depth_); \
  depth_--;                                                             \
  indent_.erase(0,1)

#else
#define ENTER(mode)
#define END(mode)
#endif

/**
 * @param {int} type
 * @returns bool
 * Check current token type is END_TOKEN or END_OF_INPUT.
 */
bool IsEnd(int type) {
  return type == Token::END_TOKEN || type == Token::END_OF_INPUT;
}

/**
 * @param {int} type
 * @returns bool
 * Callback function for ParseStatementList_.
 * Match block like structure.
 */
bool BlockBodyMatcher(int type) {
  return type != '}';
}

/**
 * @param {int} type
 * @returns bool
 * Callback function for ParseStatementList_.
 * Match case clause body.
 */
bool CaseBodyMatcher(int type) {
  return type != '}' && type != Token::JS_CASE && type != Token::JS_DEFAULT;
}

/**
 * @param {int} type
 * @returns bool
 * Check the type is a valid object literal property name.
 */
bool IsValidPropertyName(int type, TokenInfo* info) {
  return type == Token::JS_IDENTIFIER ||
      type == Token::JS_STRING_LITERAL ||
      type == Token::JS_NUMERIC_LITERAL ||
      JsToken::IsReserved(info->token());
}

/**
 * @param {int} type
 * @returns bool
 * Check the type is a valid object literal member.
 */
bool IsValidProperty(int type) {
  return type == Literal::kString ||
      type == Literal::kNumeric ||
      type == Literal::kIdentifier ||
      type == Literal::kProperty;
}


void Parser::ParseEventListener::operator()(CompilationEvent* event) {
  DEBUG_LOG(Log, "Nexc enter parse phase");
  ParserConnector* connector = event->parser_connector();
  ErrorReporter* reporter = event->error_reporter();
  const char* pathname = event->fullpath();
  Parser parser(connector, reporter, pathname);
  event->set_ast(parser.Parse());
  DEBUG_LOG(Log, "Nexc end parse phase");
  event->NotifyForKey(Nexc::kTransformAst);
}


/**
 * @param {AstNode} args
 * @param {AstNode} list
 * Arrow function expression with formal parameter is parsed as expression at first.
 * So we convert an arrow function expression's formal parameter list to a valid formal parameter list.
 */
NodeList* Parser::FormalParameterConvertor(AstNode *args) {
  NodeIterator iterator = args->ChildNodes();
  NodeList* result = new(pool()) NodeList;
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    result->AddChild(item);
    Expression* maybe_exp = item->CastToExpression();
    Literal* maybe_ident = item->CastToLiteral();
    CallExp* maybe_member = maybe_exp->CastToCallExp();
    ObjectLikeLiteral* maybe_dst = item->CastToExpression()->CastToObjectLikeLiteral();
    ArrayLikeLiteral* maybe_dst_array = item->CastToExpression()->CastToArrayLikeLiteral();
    //process ...rest parameter
    if (!maybe_ident &&
         !maybe_dst &&
         !maybe_dst_array &&
         !maybe_member &&
         item->node_type() != Literal::kAssignmentExp) {
      SYNTAX_ERROR("malformed formal parameter list\\nin file "
                    << filename_ << " at line " << Seek(-1)->line_number());
      return result;
    } else if (maybe_dst || maybe_dst_array) {
      if (!item->CastToExpression()->IsValidLhs()) {
        SYNTAX_ERROR("malformed formal parameter list\\nin file "
                      << filename_ << " at line " << Seek(-1)->line_number());
        return result;
      }
    } else if (maybe_ident) {
      if (maybe_ident->value_type() == Literal::kSpread) {
        maybe_ident->set_value_type(Literal::kRest);
      }
    } else if (item->node_type() == Literal::kAssignmentExp) {
      AssignmentExp* assign = item->CastToExpression()->CastToAssigment();
      AstNode* left = assign->left_value();
      maybe_ident = left->CastToLiteral();
      maybe_dst = left->CastToExpression()->CastToObjectLikeLiteral();
      maybe_dst_array = left->CastToExpression()->CastToArrayLikeLiteral();
      if (!maybe_ident &&
           !maybe_dst &&
           !maybe_dst_array) {
        SYNTAX_ERROR("malformed formal parameter list\\nin file "
                      << filename_ << " at line " << Seek(-1)->line_number());
        return result;
      }
    } else if (maybe_member) {
      AstNode* callable = maybe_member->callable();
      while (callable->node_type() == AstNode::kCallExp) {
        callable = callable->CastToExpression()->CastToCallExp()->callable();
      }
      Literal* literal = callable->CastToLiteral();
      if (!literal && literal->value_type() != Literal::kThis &&
           literal->value_type() != Literal::kPrivate) {
        SYNTAX_ERROR("malformed formal parameter list\\nin file "
                      << filename_ << " at line " << Seek(-1)->line_number());
        return result;
      }
    }
  }
  return result;
}


class Parser::StateStack {
 public :
  typedef enum {
    kClassDecl,
    kParseBegin,
    kFinally,
    kFunction,
    kModule
  } ParserState;
  typedef std::vector<ParserState> StateArray;
  void Push(ParserState state) { stack_.push_back(state); }
  void Pop() { stack_.pop_back(); }
  bool Has(ParserState state) {
    StateArray::iterator begin = stack_.begin();
    StateArray::iterator end = stack_.end();
    while (begin != end) {
      if (state == (*begin)) {
        return true;
      }
      ++begin;
    }
    return false;
  }
 private :
  StateArray stack_;
};

Parser::Parser(ParserConnector* connector, ErrorReporter* reporter, const char* filename)
    : filename_(filename),
      depth_(0),
      pool_(memory::Pool::Local()),
      builder_(AstBuilder::Local()),
      connector_(connector),
      reporter_(reporter),
      state_stack_(new StateStack){}
Parser::~Parser(){}


//The entrance for parser.
//We return the FileRoot node not AstRoot.
FileRoot* Parser::Parse() {
  FileRoot* root = new(pool()) FileRoot(filename_);
  root->Append(ParseProgram());
  builder()->FindDirectivePrologue(root, root);
  /**
   * The finally data structure image.
   * ---------------FileRoot------------
   * |                                                                                                                                                                   |                                                                                                                      |                                                                                                                        |
   * statement statement statement statement
   */
  return root;
}

//Report illegal end of input.
void Parser::IllegalEnd(const char* expect, int64_t line) {
  SYNTAX_ERROR("parse error got unexpected end of input expect "
                << expect << "\\nin file " << filename_ << " at line " << line);
}


void Parser::ParseTerminator() {
  TokenInfo *token = Seek();
  int type = token->type();
  if (type == ';' || type == '}' || IsEnd(type) || token->linebreak_before()) {
    if (type == ';') {
      Advance();
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " expect ';' or 'line break'\\nin file "
                  << filename_ << " at line " << token->line_number());
  }
}

//Begining of parse.
AstNode* Parser::ParseProgram() {
  ENTER(Program);
  /*
   *program
   * : source_elements
   */
  AstNode* list = ParseSourceElements();
  END(Program);
  return list;
}


//ParseSourceElements_ is only called by ParseProgram.
//If this function is called,
//this function search until got END_TOKEN or END_OF_INPUT.
//This function is only called once in each parse time.
AstNode* Parser::ParseSourceElements() {
  ENTER(SourceElements);
  /*
   *source_elements
   *: source_element
   *| source_elements source_element
   */
  //Check once flag.
  assert(state_stack_->Has(StateStack::kParseBegin) == false);
  state_stack_->Push(StateStack::kParseBegin);
  TokenInfo* token;
  NodeList* list = new(pool()) NodeList;
  while ((token = Seek()) && token != 0 && token->type() != Token::END_TOKEN && token->type() != Token::END_OF_INPUT) {
    AstNode* statement = ParseSourceElement();
    CHECK_ERROR(statement);
    list->AddChild(statement);
  }
  END(SourceElements);
  /**
   * The finally data structure image.
   * ---------------NodeList------------
   * |                                                                                                                                                                   |                                                                                                                      |                                                                                                                        |
   * statement statement statement statement
   */
  return list;
}

AstNode* Parser::ParseSourceElement() {
  ENTER(SourceElement);
  /*
   * [bison/yacc compat syntax]
   * source_element
   * : statement
   * | class_declaration
   * | function_declaration
   * | const_declaration
   * ;
   */
  TokenInfo* info = Advance();
  AstNode* result = 0;//init after;
  if (info == 0 || info->type() == Token::END_TOKEN || info->type() == Token::END_OF_INPUT) {
    return new(pool()) Empty;
  }
  /*
   * The declaration of class,function and const or let is declarable only in
   * the block statement body or function body or global.
   */
  switch (info->type()) {
    case Token::JS_CLASS :{
      result = ParseClassDecl(false);
      ExpressionStmt* stmt = new(pool()) ExpressionStmt(info->line_number());
      stmt->AddChild(result);
      result = stmt;
    }
      break;
                                                                                                
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl(false);
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      if (fn->name() == 0 || fn->name()->IsEmpty()) {
        SYNTAX_ERROR("Invalid function declaration in file "
                     << filename_ << " at line " << fn->line_number());
        return fn;
      }
      fn->MarkAsDeclaration();
    }
      break;

      //Now the const decaration is parsable, but not create block scope,
      //because block scoping overhead are heavy for the current javascript.
    case Token::JS_CONST : {
      info = Seek();
      //check syntax for const class decl.
      if (info->type() == Token::JS_CLASS) {
        Advance();
        result = ParseClassDecl(true);
        CHECK_ERROR(result);
      } else {
        TokenInfo* function_signature = Seek(2);
        //check syntax for const function.
        if (function_signature->type() == '(' || function_signature->type() == Token::JS_FUNCTION_GLYPH ||
             function_signature->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
          result = ParseFunctionDecl(true);
          CHECK_ERROR(result);
          Function* fn = result->CastToExpression()->CastToFunction();
          fn->MarkAsConstDeclaration();
        } else {
          result = ParseVariableStatement();
          CHECK_ERROR(result);
          result->first_child()->CastToExpression()->CastToVariableDeclarationList()->MarkAsConstDeclaration();
        }
      }
      break;
    }
      //Now the let statement is parsable, but not create block scope,
      //same reasons with above const declaration.
    case Token::JS_LET :
      result = ParseLetExpressionOrLetStatement();
      CHECK_ERROR(result);
      break;
                                                                                                                                
    default :
      Undo();
      result = ParseStatement();
      CHECK_ERROR(result);
  }
  END(SourceElement);
  return result;
}

//Parse the statement list,
//like the block statement body or the function body.
AstNode* Parser::ParseStatementList(StatementListMatcher matcher, const char* expect) {
  /**
   * [bison/yacc compat syntax]
   * statement_list
   * : statement
   * | statement_list statement
   * ;
   */
  ENTER(StatementList);
  TokenInfo* token = Seek();
  StatementList* list = new(pool()) StatementList;
  while (matcher(token->type())) {
    AstNode* statement = ParseSourceElement();
    CHECK_ERROR(statement);
    list->AddChild(statement);
    token = Seek();
    if (IsEnd(token->type())) {
      SYNTAX_ERROR("parse error unexpected end of input expect "
                    << expect
                    << " in file " << filename_ << " at line " << token->line_number());
      return list;
    }
  }
  END(StatementList);
  /**
   * The finally data structure image.
   * ---------------StatementList--------------
   * |                                                                                                                                                                   |                                                                                                                                                                                      |                                                                                                                                                                                       |
   * statement statement                                                                statement statement
   */
  return list;
}


//Parse statement.
AstNode* Parser::ParseStatement() {
  ENTER(Statement);
  /*
   *statement_no_block
   *: block
   *| module_block
   *| export_statement
   *| variable_statement
   *| empty_statement
   *| if_statement
   *| iteration_statement
   *| continue_statement
   *| break_statement
   *| return_statement
   *| with_statement
   *| labelled_statement
   *| switch_statement
   *| throw_statement
   *| try_statement
   *| import_statement
   *| version_statement
   *| function_declaration
   *| exportable_denifinition
   *| debugger_statement
   *| expression_statement
   *;
   */
  TokenInfo* token = Advance();
  AstNode* result;
  switch (token->type()) {
    case '{' :
      result = ParseBlockStatement();
      break;
                                                                                                
    case Token::JS_MODULE :
      result = ParseModuleStatement();
      break;
                                                                                                
    case Token::JS_EXPORT :
      result = ParseExportStatement();
      break;

    case Token::JS_VAR :
      result = ParseVariableStatement();
      break;
                                                                                                
    case ';' :
      result = new(pool()) Empty;
      break;
                                                                                                
    case Token::JS_IF :
      result = ParseIFStatement(false);
      break;
                                                                                                
    case Token::JS_FOR :
      result = ParseForStatement(false);
      break;
                                                                                                
    case Token::JS_WHILE :
      result = ParseWhileStatement();
      break;
                                                                                                
    case Token::JS_DO :
      result = ParseDoWhileStatement(false);
      break;
                                                                                                
    case Token::JS_CONTINUE :
      result = ParseContinueStatement();
      break;
                                                                                                
    case Token::JS_BREAK :
      result = ParseBreakStatement();
      break;
                                                                                                
    case Token::JS_RETURN :
      result = ParseReturnStatement();
      break;
                                                                                                
    case Token::JS_WITH :
      result = ParseWithStatement();
      break;
                                                                                                
    case Token::JS_SWITCH :
      result = ParseSwitchStatement();
      break;
                                                                                                
    case Token::JS_THROW :
      result = ParseThrowStatement();
      break;
                                                                                                
    case Token::JS_TRY :
      result = ParseTryStatement();
      break;
                                                                                                
    case Token::JS_IMPORT :
      result = ParseImportStatement();
      break;

      //a mocha special keyword not harmony.
    case Token::JS_ASSERT :
      result = ParseAssertStatement();
      break;

    case Token::MOCHA_INCLUDE :
      result = ParseIncludeStatement();
      break;

      //a mocha special keyword not harmony.
    case Token::MOCHA_VERSIONOF :
      result = ParseVersionStatement();
      break;
                                                                                                
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl(false);
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      if (fn->name() == 0 || fn->name()->IsEmpty()) {
        SYNTAX_ERROR("Invalid function declaration in file "
                     << filename_ << " at line " << fn->line_number());
        return fn;
      }
      fn->MarkAsDeclaration();
    }
      break;
                                                                                                
    case Token::JS_DEBUGGER :
      result = ParseDebuggerStatement(token);
      break;

      //The exportable definition is only acceptable in class declaration,
      //but private accessor is allowed in any place.
    case Token::JS_PRIVATE :
    case Token::JS_PUBLIC :
    case Token::JS_STATIC : {
      TokenInfo *token = Seek();
      if (token->type() == '.' || token->type() == '[') {
        //private accessor.
        result = CheckLabellOrExpressionStatement();
      } else {
        result = ParseClassMemberStatement();
      }
    }
      break;
                                                                                                
    default : {
      if (token->type() == Token::JS_IDENTIFIER) {
        TokenInfo* ident = token;
        TokenInfo* token = Seek(2);
        //Check trait declaration.
        //The trait keyword is not treated as the reserved word.
        if (strcmp(ident->token(), SymbolList::symbol(SymbolList::kTrait)) == 0 && token->type() == '{') {
          result = ParseTrait();
          CHECK_ERROR(result);
          Trait* trait = result->CastToExpression()->CastToTrait();
          if (trait->name() == 0 || trait->name()->IsEmpty()) {
            SYNTAX_ERROR("Invalid trait declaration in file "
                         << filename_ << " at line " << trait->line_number());
            return result;
          }
          trait->MarkAsDeclaration();
          break;
        }
      }
      result = CheckLabellOrExpressionStatement();
      CHECK_ERROR(result);
      //If shorten function expression is parsed as expression,
      //we mark as function declaration.
      if (result->node_type() == AstNode::kExpressionStmt) {
        Expression* exp = result->first_child()->CastToExpression();
        if (!exp->IsParenthesis() && exp->child_length() == 1) {
          AstNode* item = exp->first_child();
          if (item->node_type() == AstNode::kFunction) {
            Function* fn = item->CastToExpression()->CastToFunction();
            if (fn->name() == 0 || fn->name()->IsEmpty()) {
              SYNTAX_ERROR("Invalid function declaration in file "
                           << filename_ << " at line " << fn->line_number());
              return fn;
            }
            fn->MarkAsDeclaration();
            result = item;
          }
        } else if (!exp->IsParenthesis() && exp->child_length() > 1) {
          if (exp->first_child()->node_type() == AstNode::kFunction) {
            SYNTAX_ERROR("illegal trailing comma after function declaration.\\nIn file"
                          << filename_ << " at line " << exp->line_number());
          }
        }
      }
    }
  }
  CHECK_ERROR(result);
  END(Statement);
  return result;
}

AstNode* Parser::ParseBlockStatement() {
  ENTER(BlockStatement);
  /*
   * [bison/yacc compat syntax]
   * block
   * : '{' '}'
   * | '{' statement_list '}'
   */
  TokenInfo* token = Seek();
  BlockStmt* block = new(pool()) BlockStmt(token->line_number());
  //Check block statement has body or not.
  //If block body is empty -> {}, set Empty node to block body.
  if (token->type() != '}') {
    while (1) {
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR(statement);
      block->AddChild(statement);
      token = Seek();
      if (token->type() == '}') {
        Advance();
        break;
      } else if (IsEnd(token->type())) {
        IllegalEnd("'}'", token->line_number());
        END(BlockStatementError);
        return block;
      }
    }
  } else {
    Advance();
  }
  END(BlockStatement);
  /**
   * The finally data structure image.
   * --------------BlockStmt------------
   * |                                                                                                                                                                   |                                                                                                                      |                                                                                                                        |
   * statement statement statement statement
   */
  return block;
}


//Parse module statement.
AstNode* Parser::ParseModuleStatement() {
  ENTER(ModuleStatement);
  /*
   * [bison/yacc compat syntax]
   * module_statement
   * : JS_MODULE identifier__opt statement
   * ;
   */
  TokenInfo* token = Seek();
  AstNode* name = 0;//init after.
  if (token->type() == Token::JS_IDENTIFIER) {
    name = ParseLiteral(false);
    CHECK_ERROR(new(pool()) Empty);
  } else {
    name = new(pool()) Empty;
  }
  ModuleStmt* module_stmt = new(pool()) ModuleStmt(name, token->line_number());
  AstNode* statement = ParseSourceElement();
  module_stmt->AddChild(statement);
  END(ModuleStatement);
  /**
   * The finally data structure image.
   * ModuleStmt--name
   * |                                                                                                                                                                   |
   * |                                   Literal or Empty
   * |
   * statement
   */
  return module_stmt;
}

//Parse export statement.
AstNode* Parser::ParseExportStatement() {
  ENTER(ExportStatement);
  /*
   * [bison/yacc compat syntax]
   * export_statement
   * : JS_EXPORT exportable_definition
   */
  TokenInfo* token = Seek(-1);
  ExportStmt* export_stmt = new(pool()) ExportStmt(token->line_number());
  AstNode* exportable = ParseExportableDefinition();
  CHECK_ERROR(export_stmt);
  export_stmt->AddChild(exportable);
  END(ExportStatement);
  /**
   * The finally data structure image.
   * ExportStmt
   * |
   * function or class or variable decl or const decl
   */
  return export_stmt;
}

//Parse import statement.
AstNode* Parser::ParseImportStatement() {
  ENTER(ImportStatement);
  /*
   * [bison/yacc compat syntax]
   * import_statement
   * : JS_IMPORT JS_IDENTIFIER JS_FROM import_expression terminator
   */
  TokenInfo* token = Seek();
  int expression_type;
  AstNode* exp;
  if (token->type() == Token::JS_IDENTIFIER) {
    exp = ParseLiteral(true);
    CHECK_ERROR(exp);
    expression_type = ImportStmt::kVar;
  } else if (token->type() == '{' || token->type() == '[') {
    //import statement allow destructuring assignment.
    exp = ParseDestructuringLeftHandSide();
    CHECK_ERROR(exp);
    expression_type = ImportStmt::kDst;
  }
  TokenInfo* from = Advance();
  const char* ident = from->token();
  //from keyword is not treated as the reserved word,
  //so we check that an identifier is the valid from keyword or not.
  if (from->type() == Token::JS_IDENTIFIER &&
       strlen(ident) > 0 &&
       strcmp(ident, SymbolList::symbol(SymbolList::kFrom)) == 0) {
    AstNode* from_exp = ParseImportExpression();
    CHECK_ERROR(from_exp);
    Literal* maybe_file = from_exp->first_child()->CastToLiteral();
    int from_type;
    //The import statement could accept the filename or the module name.
    if (maybe_file && maybe_file->value_type() == Literal::kString) {
      from_type = ImportStmt::kFile;
    } else {
      from_type = ImportStmt::kModule;
    }
    ImportStmt* stmt = new(pool()) ImportStmt(expression_type, from_type, token->line_number());
    CHECK_ERROR(stmt);
    stmt->set_expression(exp);
    stmt->set_from(from_exp);
    ParseTerminator();
    CHECK_ERROR(stmt);
    END(ImportStatement);
    /**
     * The finally data structure image.
     * ImportStmt---------expression
     *                                                                                                                                   |                                                                                                                                                                                      |
     *                                                                                                                                   | identifier or destructuring
     *                                                                                                                                   |
     *                                                                                                                                   |-----------from
     *                                                                                                                                                                                                                                                                                                                                                                  |
     *                                                                                                                                                                  string literal or call exp
     */
    return stmt;
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(from).cstr()
                  << " after 'import' expect 'from'\\nin file "
                  << filename_ << " at line " << from->line_number());
    END(ImportStatementError);
    return new(pool()) Empty();
  }
}

//Parse import expression.
//import ... from <here>
AstNode* Parser::ParseImportExpression() {
  ENTER(ImportExpression);
  TokenInfo* token = Seek();
  NodeList* list = new(pool()) NodeList();
  //In case of filename.
  if (token->type() == Token::JS_STRING_LITERAL) {
    AstNode* literal = ParseLiteral(false);
    CHECK_ERROR(literal);
    list->AddChild(literal);
  } else if (token->type() == Token::JS_IDENTIFIER) {
    //In case of module name.
    AstNode* literal = ParseLiteral(true);
    CHECK_ERROR(literal);
    list->AddChild(literal);
  }
  token = Seek();
  while (1) {
    if (token->type() == '.' || token->type() == '[') {
      AstNode* literal = ParseLiteral(true);
      CHECK_ERROR(literal);
      list->AddChild(literal);
      token = Seek();
    } else {
      break;
    }
  }
  END(ImportExpression);
  return list;
}

//Parse debugger statement.
AstNode* Parser::ParseDebuggerStatement(TokenInfo* token) {
  ENTER(DebuggerStatement);
  Literal* value = new(pool()) Literal(Literal::kIdentifier, token->line_number());
  value->set_value(token);
  Expression* exp = new(pool()) Expression(token->line_number());
  ExpressionStmt* stmt = new(pool()) ExpressionStmt(token->line_number());
  stmt->AddChild(exp);
  exp->AddChild(value);
  END(DebuggerStatement);
  return stmt;
}

//Parse version statement
AstNode* Parser::ParseVersionStatement() {
  /**
   * [bison/yacc compat syntax]
   * version_statement
   * : MOCHA_VERSIONOF '(' JS_IDENTIFIER ')' statement
   * ;
   */
  ENTER(VersionStatement);
  TokenInfo* token = Advance();
  if (token->type() == '(') {
    token = Advance();
    if (token->type() == Token::JS_IDENTIFIER) {
      VersionStmt* stmt = new(pool()) VersionStmt(token, token->line_number());
      token = Advance();
      if (token->type() == ')') {
        token = Seek();
        if (token->type() == '{') {
          Advance();
          AstNode* statement = ParseStatementList(BlockBodyMatcher, "}");
          CHECK_ERROR(stmt);
          stmt->AddChild(statement);
          Advance();
          END(VersionStatement);
          /**
           * The finally data structure image.
           * VersionStmt
           *                                             |
           *            statement
           */
          return stmt;
        } else {
          AstNode* statement = ParseStatement();
          CHECK_ERROR(stmt);
          stmt->AddChild(statement);
          END(VersionStatement);
          return stmt;
        }
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'version statement' expect 'identifier' \\nin file "
                    << filename_ << " at line " << token->line_number());
      END(VersionStatementError);
      return new(pool()) Empty;
    }
  }
  SYNTAX_ERROR("parse error got unexpected token "
                << TokenConverter(token).cstr()
                << " in 'version statement' expect ')' \\nin file "
                << filename_ << " at line " << token->line_number());
  END(VersionStatementError);
  return new(pool()) Empty;
}

//Parse assert statement
AstNode* Parser::ParseAssertStatement() {
  /**
   * [bison/yacc compat syntax]
   * mocha_assert_statement
   * : MOCHA_ASSERT '(' assignment_expression ',' assignment_expression ')'
   */
  ENTER(AssertStatement);
  TokenInfo *token = Seek();
  int64_t line = token->line_number();
  if (token->type() == '(') {
    token = Advance();
    AstNode* expect = ParseAssignmentExpression(false);
    CHECK_ERROR(expect);
    token = Advance();
    if (token->type() == ',') {
      AstNode* exp = ParseAssignmentExpression(false);
      token = Advance();
      if (token->type() == ')') {
        ParseTerminator();
        CHECK_ERROR(exp);
        AssertStmt* stmt = new(pool()) AssertStmt(line);
        stmt->AddChild(expect);
        stmt->AddChild(exp);
        /**
         * The finally data structure image.
         *                                                       AssertStmt
         *                                                                                                                       |
         * assignment expression
         *                                                                                                                       |
         * assignment expression
         */
        return stmt;
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " 'in assert statement' expect ')'\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(AssertStatementError);
        return expect;
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " 'in assert statement', second arguments must be a 'expression'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(AssertStatementError);
      return expect;
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " 'in assert statement' expect '('\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(AssertStatementError);
    return new(pool()) Empty;
  }
}

//Parse assert statement
AstNode* Parser::ParseIncludeStatement() {
  /**
   * [bison/yacc compat syntax]
   * mocha_assert_statement
   * : MOCHA_INCLUDE '(' JS_STRING_LITERAL ')'
   */
  ENTER(AssertStatement);
  TokenInfo *token = Seek();
  int64_t line = token->line_number();
  if (token->type() == Token::JS_STRING_LITERAL) {
    AstNode* expect = ParseLiteral(false);
    CHECK_ERROR(expect);
    ParseTerminator();
    std::string path = expect->CastToLiteral()->value()->token();
    if (path.size() > 1) {
      path.erase(0, 1);
      path.erase(path.size() - 1, 1);
    }
    return new (pool()) IncludeStmt(path.c_str(), line);
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " 'in include directive' expect 'string literal'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(IncludeStatementError);
    return new(pool()) Empty;
  }
}

//Parse variable statement
AstNode* Parser::ParseVariableStatement() {
  ENTER(VariableStatement);
  /*
   * [bison/yacc compat bnf syntax]
   * variable_statement
   * : JS_VAR variable_declaration_list terminator
   * | JS_CONST variable_declaration_list terminator
   * | JS_LET variable_declaration_list terminator
   * ;
   */
  TokenInfo* token = Seek(-1);
  VariableStmt* stmt = new(pool()) VariableStmt(token->line_number());
  AstNode* list = ParseVariableDecl(false);
  CHECK_ERROR(stmt);
  token = Seek();
  if (token->type() == ';') {
    Advance();
  }
  stmt->AddChild(list);
  END(VariableStatement);
  /**
   * The finally data structure image.
   *                                            - VariableStmt-
   *                                            |                                                        |                                                                                      |
   * literal literal literal
   */
  return stmt;
}

//Parse variable declaration.
AstNode* Parser::ParseVariableDecl(bool is_noin) {
  ENTER(VariableDecl);
  /*
   * [bison/yacc compat bnf syntax]
   * variable_declaration
   * : JS_IDENTIFIER initialiser__opt
   * | destructuring_assignment_left_hand_side initialiser__opt
   * ;
   *
   * variable_declaration_no_in
   * : JS_IDENTIFIER initialiser_no_in__opt
   * | destructuring_assignment_left_hand_side initialiser_no_in__opt
   * ;
   */
  TokenInfo* maybe_assign_op = Seek(2);
  VariableDeclarationList* list = new(pool()) VariableDeclarationList(maybe_assign_op->line_number());
  TokenInfo* next = Seek();
  //Get all declarations.
  //Like var x, y = 200, z;
  while (1) {
    AstNode* var_left_hand;
    bool is_destructuring = false;
    if (next->type() == '{' || next->type() == '[') {
      //Treat harmony destructuring.
      var_left_hand = ParseDestructuringLeftHandSide();
      CHECK_ERROR(list);
      is_destructuring = true;
      maybe_assign_op = Seek();
    } else if (next->type() == Token::JS_IDENTIFIER) {
      //Normal idneifier.
      var_left_hand = ParseLiteral(false);
      CHECK_ERROR(var_left_hand);
      var_left_hand->CastToLiteral()->set_value_type(Literal::kVariable);
      CHECK_ERROR(list);
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(next).cstr()
                    << " in 'variable statement' expect 'variable name' or 'destructuring assignment'\\nin file "
                    << filename_ << " at line " << next->line_number());
      END(VariableDeclError);
      return new(pool()) Empty();
    }
    /*
     * We check result of Seek(2) is assignment operator or not.
     * If that is assignment operator, we treat next token list as expression,
     * if not, that is treated as just declaration.
     */
    if (maybe_assign_op->type() == '=') {
      Advance();
      AstNode* assignment_exp = ParseAssignmentExpression(is_noin);
      CHECK_ERROR(list);
      var_left_hand->AddChild(assignment_exp);
      list->AddChild(var_left_hand);
    } else {
      var_left_hand->AddChild(new(pool()) Empty);
      list->AddChild(var_left_hand);
    }
    next = Seek();
    /*
     * If next token type is semicolon or line break, declarations are end,
     * if next token type is comma, declaration is continue after,
     * if not, it's error.
     */
    if (next->type() != ',') {
      break;
    } else {
      Advance();
    }
    maybe_assign_op = Seek(2);
    next = Seek();
  }
  END(VariableDecl);
  return list;
}


AstNode* Parser::ParseLetExpressionOrLetStatement() {
  TokenInfo* token = Seek();
  if (token->type() == '(') {
    Advance();
    AstNode* exp_list = ParseLetExpressionExp();
    CHECK_ERROR(exp_list);
    Advance();
    token = Seek();
    Function* fn = new(pool()) Function(token->line_number());
    fn->set_name(new(pool()) Empty);
    AstNode* list = exp_list->first_child();
    AstNode* args = list->next_sibling();
    NodeList* valid_formal = FormalParameterConvertor(list);
    CHECK_ERROR(valid_formal);
    fn->set_argv(valid_formal);
    if (token->type() == '{') {
      Advance();
      AstNode* node = ParseStatementList(BlockBodyMatcher, "'}'");
      Advance();
      CHECK_ERROR(node);
      fn->Append(node);
    } else {
      AstNode* node = ParseSourceElement();
      CHECK_ERROR(node);
      fn->AddChild(node);
    }
    Literal* call_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCall),
                                                  Token::JS_IDENTIFIER, token->line_number(), Literal::kProperty);
    Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                  Token::JS_THIS, token->line_number(), Literal::kThis);
    Expression* fn_exp = new(pool()) Expression(fn->line_number());
    fn_exp->AddChild(fn);
    fn_exp->MarkParenthesis();
    args->InsertBefore(this_sym);
    CallExp* dot_accessor = builder()->CreateDotAccessor(fn_exp, call_sym, fn->line_number());
    /**
     * return anonymouse function call
     * (function (<let expression>) {
     *   ...
     * }).call(this, <args>);
     */
    return builder()->CreateExpStmt(builder()->CreateNormalAccessor(dot_accessor, args, fn->line_number()), fn->line_number());
  } else {
    return ParseVariableStatement();
  }
}


AstNode* Parser::ParseLetExpressionExp() {
  TokenInfo* token = Seek();
  NodeList* list = new(pool()) NodeList;
  NodeList* args = new(pool()) NodeList;
  while (1) {
    AstNode* node = ParseAssignmentExpression(false);
    CHECK_ERROR(node);
    AssignmentExp *assign = node->CastToExpression()->CastToAssigment();
    if (assign) {
      list->AddChild(assign->left_value());
      args->AddChild(assign->right_value());
    } else {
      list->AddChild(node);
      args->AddChild(builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                Token::JS_IDENTIFIER, token->line_number(), Literal::kIdentifier));
    }
    token = Seek();
    if (token->type() != ',') {
      break;
    }
    Advance();
    token = Seek();
  }
  return builder()->CreateNodeList(2, list, args);
}


//Parse destructuring assignment
AstNode* Parser::ParseDestructuringLeftHandSide() {
  ENTER(DestructuringLeftHandSide);
  /*
   * [bison/yacc compat bnf syntax]
   * destructuring_assignment_left_hand_side
   * : array_left_hand_side
   * | object_left_hand_side
   * ;
   */
  TokenInfo* token = Advance();
  if (token->type() == '[') {
    END(DestructuringLeftHandSide);
    return ParseArrayPattern();
    //We expect error checking is already finished.
  } else {
    END(DestructuringLeftHandSide);
    return ParseObjectPattern();
  }
}


//Parse destructuring assignment array pattern.
AstNode* Parser::ParseArrayPattern() {
  ENTER(ArrayPattern);
  /*
   * [bison/yacc compat syntax]
   * array_left_hand_side
   * : '[' elision__opt ']'
   * | '[' array_left_hand_side_list ']'
   * | '[' ',' elision__opt ']'
   * ;
   *
   * array_left_hand_side_list
   * : elision__opt JS_IDENTIFIER
   * | elision__opt formal_parameter_rest
   * | elision__opt destructuring_assignment_left_hand_side
   * | array_left_hand_side_list ',' elision__opt JS_IDENTIFIER
   * | array_left_hand_side_list ',' elision__opt formal_parameter_rest
   * | array_left_hand_side_list ',' elision__opt destructuring_assignment_left_hand_side
   * ;
   */
  TokenInfo* token = Seek();
  ArrayLikeLiteral* destructuring = new(pool()) ArrayLikeLiteral(token->line_number());
  destructuring->MarkAsLhs();
  while (1) {
    if (token->type() == '[' || token->type() == '{') {
      AstNode* elem = ParseDestructuringLeftHandSide();
      CHECK_ERROR(elem);
      destructuring->set_element(elem);
      token = Seek();
      if (token->type() == ',') {
        Advance();
      }
    } else if (token->type() == ']') {
      Advance();
      break;
    } else {
      if (token->type() == ',') {
        destructuring->set_element(new(pool()) Empty);
        Advance();
        token = Seek();
        if (token->type() == ']') {
          destructuring->set_element(new(pool()) Empty);
          Advance();
          break;
        }
      } else if (token->type() == Token::JS_IDENTIFIER) {
        AstNode* value = ParseLiteral(false);
        CHECK_ERROR(destructuring);
        destructuring->set_element(value);
        token = Seek();
        if (token->type() == ',') {
          Advance();
        }
      } else if (token->type() == Token::JS_PARAMETER_REST) {
        token = Advance(2);
        if (token->type() == Token::JS_IDENTIFIER) {
          Literal* rest = new(pool()) Literal(Literal::kRest, token->line_number());
          rest->set_value(token);
          destructuring->set_element(rest);
        } else {
          SYNTAX_ERROR("parse error got undexpected token "
                        << TokenConverter(token).cstr()
                        << ". In 'destructuring assignment parameter rest expect 'identifier'\\nin file "
                        << filename_ << " at line "
                        << token->line_number());
          break;
        }
      } else {
        //In destructuring assignemtn, if array pattern used,
        //it's element is only allowed JS_IDENTIFIER or JS_REST.
        SYNTAX_ERROR("parse error got undexpected token "
                      << TokenConverter(token).cstr()
                      << ". In 'destructuring assignment array pattern' "
                      "element is only allowed 'identifier' or 'parameter rest'.\\nin file '"
                      << filename_ << " at line "
                      << token->line_number());
        break;
      }
    }
    token = Seek();
  }
  END(ArrayPattern);
  /**
   * The finally data structure image.
   *                                            ArrayLikeLiteral
   *                                                                                                                                            |
   *            literal or destructuring 
   */
  return destructuring;
}

//Parse destructuring assignment object pattern
AstNode* Parser::ParseObjectPattern() {
  ENTER(ObjectPattern);
  /*
   * [bison/yacc compat syntax]
   * object_member_left_hand_side_list
   * :  JS_IDENTIFIER
   * | property_name ':' JS_IDENTIFIER
   * | property_name ':' destructuring_assignment_left_hand_side
   * | object_member_left_hand_side_list ',' property_name ':' JS_IDENTIFIER
   * | object_member_left_hand_side_list ',' JS_IDENTIFIER
   * | object_member_left_hand_side_list ',' property_name ':' destructuring_assignment_left_hand
   * ;
   */
  TokenInfo* token = Seek();
  int maybe_colon = Seek(2)->type();
  ObjectLikeLiteral* destructuring = new(pool()) ObjectLikeLiteral(token->line_number());
  destructuring->MarkAsLhs();
  while (1) {
    if (maybe_colon == '}') {
      ParseObjectPatternElement(token->type(), token, destructuring);
      CHECK_ERROR(destructuring);
      Advance();
      break;
    } else if (maybe_colon == ',') {
      ParseObjectPatternElement(token->type(), token, destructuring);
      CHECK_ERROR(destructuring);
      Advance();
    } else if (maybe_colon == ':') {
      AstNode* node = ParseLiteral(true);
      CHECK_ERROR(destructuring);
      Advance();
      token = Seek();
      if (token->type() == '[' || token->type() == '{') {
        AstNode* elem = ParseDestructuringLeftHandSide();
        CHECK_ERROR(elem);
        node->AddChild(elem);
      } else {
        ParseObjectPatternElement(token->type(), token, destructuring);
        CHECK_ERROR(destructuring);
        AstNode* last = destructuring->elements()->last_child();
        destructuring->elements()->RemoveChild(last);
        node->AddChild(last);
      }
      destructuring->set_element(node);
      token = Advance();
      if (token->type() == '}') {
        break;
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << ". In 'destructuring assignment object pattern'"
                    " member only allowed normal '{ property_name : idenfier }' or '{ identifier }'\\nin file "
                    << filename_ << " at line " << token->line_number());
    }
    token = Seek();
    maybe_colon = Seek(2)->type();
  }
  END(ObjectPattern);
  return destructuring;
}

//Parse destructuring assignment object patter's each element.
AstNode* Parser::ParseObjectPatternElement(int type, TokenInfo* token, ObjectLikeLiteral* object) {
  ENTER(ObjectPatternElement);
  if (type == Token::JS_IDENTIFIER) {
    AstNode* node = ParseLiteral(true);
    CHECK_ERROR(node);
    object->set_element(node);
    END(ObjectPatternElement);
    return node;
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << ". In 'destructuring assignment object pattern'"
                  " member only allowed normal '{ property_name : idenfier }' or '{ identifier }'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(ObjectPatternElementError);
    return new(pool()) Empty;
  }
}

//Parse labelled statement or expression statement.
AstNode* Parser::CheckLabellOrExpressionStatement() {
  /**
   * [bison/yacc compat syntax]
   * labelled_statement
   * : JS_IDENTIFIER ':' statement
   * ;
   *
   * expression_statement
   * : expression
   * ;
   */
  ENTER(LabellOrExpressionStatement);
  TokenInfo* token = Seek();
  Undo();
  //In case of labelled statement.
  if (token->type() == ':') {
    AstNode* stmt = ParseLabelledStatement();
    CHECK_ERROR(stmt);
    END(LabellOrExpressionStatement);
    return stmt;
  } else {
    AstNode* ret = ParseExpression(false);
    CHECK_ERROR(ret);
    ParseTerminator();
    CHECK_ERROR(ret);
    ExpressionStmt* stmt = new(pool()) ExpressionStmt(token->line_number());
    stmt->AddChild(ret);
    END(LabellOrExpressionStatement);
    return stmt;
  }
}

//Parse if statement
AstNode* Parser::ParseIFStatement(bool is_comprehensions) {
  ENTER(IFStatement);
  /*
   * [bison/yacc compat syntax]
   * if_statement
   * : JS_IF '(' expression ')' statement JS_ELSE statement 
   * | JS_IF '(' expression ')' statement
   * | JS_IF_OPT expression statement
   * ;
   */
  TokenInfo *token = Advance();
  IFStmt* if_stmt = new(pool()) IFStmt(token->line_number());
  if (token->type() == '(') {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(if_stmt);
    if_stmt->set_condition(exp);
    token = Advance();
    if (token->type() == ')') {
      if (!is_comprehensions) {
        AstNode* stmt = ParseSourceElement();
        CHECK_ERROR(stmt);
        if_stmt->set_then_statement(stmt);
        token = Seek();
        if (token->type() == Token::JS_ELSE) {
          Advance();
          AstNode* stmt = ParseSourceElement();
          CHECK_ERROR(stmt)
              if_stmt->set_else_statement(stmt);
        } else {
          if_stmt->set_else_statement(new(pool()) Empty);
        }
      } else {
        if_stmt->set_then_statement(new(pool()) Empty);
        if_stmt->set_else_statement(new(pool()) Empty);
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'if statement conditional expression end' expect ')' \\nin file "
                    << filename_ << " at line " << token->line_number());
      END(IFStatementError);
      return if_stmt;
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'if statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->line_number());
    END(IFStatementError);
    return if_stmt;
  }
  END(IFStatement);
                                
  return if_stmt;
}

//Parse do while statement.
AstNode* Parser::ParseDoWhileStatement(bool is_expression) {
  /**
   * [bison/yacc compat syntax]
   * iteration_statement
   * : JS_DO statement JS_WHILE '(' expressio ')' terminator
   * ;
   *
   * do_expression
   * | JS_DO statement
   */
  ENTER(DoWhileStatement);
  int64_t line = Seek(-1)->line_number();
  AstNode* statement = ParseSourceElement();
  CHECK_ERROR(statement);
  TokenInfo* token = Seek();
  if (token->type() == Token::JS_WHILE && !is_expression) {
    token = Advance(2);
    if (token->type() == '(') {
      AstNode* node = ParseExpression(false);
      CHECK_ERROR(statement);
      token = Advance();
      if (token->type() == ')') {
        IterationStmt* iter = new(pool()) IterationStmt(IterationStmt::kDoWhile, line);
        iter->set_expression(node);
        iter->AddChild(statement);
        END(DoWhileStatement);
        return iter;
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'while statement conditional expression' expect ')' \\nin file "
                      << filename_ << " at line " << token->line_number());
        END(DoWhileStatementError);
        return new(pool()) IterationStmt(IterationStmt::kWhile, line);
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'do while statement conditional expression' expect '(' \\nin file "
                    << filename_ << " at line " << token->line_number());
      END(DoWhileStatementError);
      return new(pool()) IterationStmt(IterationStmt::kWhile, line);
    }
  } else {
    //do expression.
    token = Seek();
    Function* fn = new(pool()) Function(line);
    fn->set_name(new(pool()) Empty);
    if (statement->node_type() == AstNode::kBlockStmt) {
      fn->Append(statement);
    } else {
      fn->AddChild(statement);
    }
    AstNode* node = fn->last_child();
    if (node) {
      if (node->CastToExpression() || node->node_type() == AstNode::kExpressionStmt) {
        ReturnStmt* stmt = 0;//init after
        if (node->node_type() == AstNode::kExpressionStmt) {
          stmt = builder()->CreateReturnStmt(node->first_child(), node->line_number());
        } else {
          stmt = builder()->CreateReturnStmt(node, node->line_number());
        }
        fn->ReplaceChild(node, stmt);
      }
    }
    fn->set_argv(new(pool()) Empty);
    ExpressionStmt* ret_stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, fn->line_number());
    return (is_expression)? ret_stmt->first_child() : ret_stmt;
  }
}


//Parse while statement
AstNode* Parser::ParseWhileStatement() {
  /**
   * [bison/yacc compat syntax]
   * iteration_statement
   * : JS_WHILE '(' expression ')' statement
   * ;
   */
  ENTER(WhileStatement);
  TokenInfo* token = Advance();
  int64_t line = token->line_number();
  if (token->type() == '(') {
    AstNode* node = ParseExpression(false);
    CHECK_ERROR(node);
    token = Advance();
    if (token->type() == ')') {
      IterationStmt* iter = new(pool()) IterationStmt(IterationStmt::kWhile, line);
      iter->set_expression(node);
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR(iter);
      iter->AddChild(statement);
      END(WhileStatement);
      return iter;
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'while statement conditional expression' expect ')' \\nin file "
                    << filename_ << " at line " << token->line_number());
      END(WhileStatementError);
      return new(pool()) IterationStmt(IterationStmt::kWhile, line);
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'while statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->line_number());
    END(WhileStatementError);
    return new(pool()) IterationStmt(IterationStmt::kWhile, line);
  }
}


//Parse for statement
//In this method, the for statement includes for_in_statement,
//for_of_statement and array_comprehensions_iteration.
AstNode* Parser::ParseForStatement(bool is_comprehensions) {
  /**
   * [bison/yacc compat syntax]
   * iteration_statement
   * : JS_FOR '(' JS_VAR variable_declaration_list_no_in ';' expression__opt ';' expression__opt) statement
   * | JS_FOR '(' expression_no_in__opt ';' expression__opt ';' expression__opt ')' statement 
   * | JS_FOR '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
   * | JS_FOR '(' left_hand_side_expression JS_IN expression ')' statement
   * | JS_FOR '(' JS_VAR variable_declaration_no_in JS_IDENTIFIER expression ')' statement
   * | JS_FOR '(' left_hand_side_expression JS_IDENTIFIER expression ')' statement
   * | JS_FOR JS_EACH '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
   * | JS_FOR JS_EACH '(' left_hand_side_expression JS_IN expression ')' statement
   * ;
   *
   * array_comprehensions
   * : array_comprehension_iteration
   * | array_comprehensions array_comprehension_iteration
   * ;
   *
   * array_comprehension_iteration
   * : JS_FOR '(' left_hand_side_expression JS_IDENTIFIER expression ')'
   * ;
   */
  ENTER(ForStatement);
  TokenInfo *token = Advance();
  int64_t line = token->line_number();
  bool is_each = false;
  NodeList *exp_list = new(pool()) NodeList;
  IterationStmt* iter_stmt = 0;
  if (token->type() == Token::JS_EACH) {
    is_each = true;
    token = Advance();
  }
  if (token->type() == '(') {
    int next_type = Seek()->type();
    bool is_var_decl = false;
    int var_decl_len = 0;
    if (next_type == Token::JS_VAR) {
      is_var_decl = true;
      //The array comprehension for expression could not have variable declaration.
      if (is_comprehensions) {
        SYNTAX_ERROR("parse error in 'array comprehensions for expression' could not has variable declaration"
                      "\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(ForStatementError);
        return new(pool()) IterationStmt(IterationStmt::kFor, line);
      } else {
        Advance();
        AstNode* var_decl = ParseVariableDecl(true);
        CHECK_ERROR(var_decl);
        exp_list->AddChild(var_decl);
        var_decl_len = var_decl->child_length();
      }
    } else if (next_type != ';') {
      AstNode* exp = ParseExpression(true);
      CHECK_ERROR(exp);
      if (exp->first_child()->node_type() == AstNode::kLiteral && is_comprehensions) {
        AstNode* first = exp->first_child();
        if (first->child_length() == 0) {
          first->AddChild(new(pool()) Empty);
        }
        first->CastToLiteral()->set_value_type(Literal::kVariable);
        exp_list->AddChild(first);
      } else {
        //Empty first for statement condition expression.
        exp_list->AddChild(exp);
      }
    } else {
      exp_list->AddChild(new(pool()) Empty);
    }
    token = Advance();
    if (next_type == ';' || (token->type() == ';' && is_each == false)) {
      //In case of normal for statement.
      if (is_comprehensions) {
        SYNTAX_ERROR("parse error in 'array comprehensions' allowed 'for in statement' or 'for of statement'"
                      "\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(ForStatementError);
        return new(pool()) IterationStmt(IterationStmt::kFor, line);
      }
      int iter_type = (is_var_decl)? IterationStmt::kForWithVar : IterationStmt::kFor;
      iter_stmt = new(pool()) IterationStmt(iter_type, line);
      ParseForStatementCondition(exp_list);
      CHECK_ERROR(iter_stmt);
    } else if (token->type() == Token::JS_IN) {
      //In case of for in statement.
      if (var_decl_len > 1) {
        SYNTAX_ERROR("parse error 'for in statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(ForStatementError);
        return new(pool()) IterationStmt(IterationStmt::kFor, line);
      }
      if (is_var_decl) {
        AstNode* initialiser = exp_list->first_child()->first_child();
        exp_list->ReplaceChild(exp_list->first_child(), initialiser);
      }
      if (is_each == false) {
        int iter_type = (is_var_decl || is_comprehensions)? IterationStmt::kForInWithVar : IterationStmt::kForIn;
        iter_stmt = new(pool()) IterationStmt(iter_type, line);
      } else {
        int iter_type = (is_var_decl || is_comprehensions)? IterationStmt::kForEachWithVar : IterationStmt::kForEach;
        iter_stmt = new(pool()) IterationStmt(iter_type, line);
      }
      ParseForInStatementCondition(exp_list);
      CHECK_ERROR(iter_stmt);
    } else if (token->type() == Token::JS_IDENTIFIER &&
                strcmp(TokenConverter(token).cstr(), SymbolList::symbol(SymbolList::kOf)) == 0) {
      //For of statement's 'of' keyword is treated as identifier not reserved word,
      //so we check token is valid 'of' identifier or not.
      if (var_decl_len > 1) {
        SYNTAX_ERROR("parse error 'for of statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(ForStatementError);
        return new(pool()) IterationStmt(IterationStmt::kFor, line);
      }
      if (is_var_decl) {
        AstNode* initialiser = exp_list->first_child()->first_child();
        exp_list->ReplaceChild(exp_list->first_child(), initialiser);
      }
      if (is_each == false) {
        int iter_type = (is_var_decl || is_comprehensions)? IterationStmt::kForOfWithVar : IterationStmt::kForOf;
        iter_stmt = new(pool()) IterationStmt(iter_type, line);
      } else {
        SYNTAX_ERROR("parse error 'for of statement' can not has 'each'."
                      "\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(ForStatementError);
        return new(pool()) IterationStmt(IterationStmt::kFor, line);
      }
      ParseForInStatementCondition(exp_list);
      CHECK_ERROR(iter_stmt);
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'for statement conditional expression' expect 'in', 'of' or ';' \\nin file "
                    << filename_ << " at line " << token->line_number());
      END(ForStatementError);
      return new(pool()) IterationStmt(IterationStmt::kFor, line);
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'for statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->line_number());
    END(ForStatementError);
    return new(pool()) IterationStmt(IterationStmt::kFor, line);
  }
  if (!is_comprehensions) {
    AstNode* body = ParseStatement();
    CHECK_ERROR(iter_stmt);
    iter_stmt->AddChild(body);
  }
  iter_stmt->set_expression(exp_list);
  END(ForStatement);
  return iter_stmt;
}


//Parse for statement condition expression.
void Parser::ParseForStatementCondition(NodeList* list) {
  ENTER(ForStatementCondition);
  if (Seek()->type() == ';') {
    list->AddChild(new(pool()) Empty);
  } else {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(;);
    list->AddChild(exp);
  }
  TokenInfo* token = Advance();
  if (token->type() == ';') {
    if (Seek()->type() == ')') {
      list->AddChild(new(pool()) Empty);
    } else {
      AstNode* exp = ParseExpression(false);
      CHECK_ERROR(;)
          list->AddChild(exp);
    }
    token = Advance();
    if (token->type() != ')') {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'for statement condition end' expect ')' \\nin file "
                    << filename_ << " at line " << token->line_number());
    }
  }
  END(ForStatementCondition);
}


//Parse for in statement condition expression.
void Parser::ParseForInStatementCondition(NodeList* list) {
  ENTER(ForInStatementCondition);
  AstNode* target_exp = ParseExpression(false);
  CHECK_ERROR(;);
  TokenInfo* token = Advance();
  list->AddChild(target_exp);
  if (token->type() != ')') {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'for in statement condition end' expect ')' \\nin file "
                  << filename_ << " at line " << token->line_number());
  }
  END(ForInStatementCondition);
}


//Parse continue statement.
AstNode* Parser::ParseContinueStatement() {
  /**
   * [bison/yacc compat syntax]
   * continue_statement
   * : JS_CONTINUE identifier__opt terminator
   */
  ENTER(ContinueStatement);
  TokenInfo *token = Seek();
  ContinueStmt* stmt = new(pool()) ContinueStmt(Seek(-1)->line_number());
  if (token->type() == Token::JS_IDENTIFIER) {
    AstNode* identifier = ParseLiteral(false);
    CHECK_ERROR(stmt);
    stmt->AddChild(identifier);
  }
  ParseTerminator();
  CHECK_ERROR(stmt);
  stmt->AddChild(new(pool()) Empty);
  END(ContinueStatement);
  return stmt;
}


//Parse break statement.
AstNode* Parser::ParseBreakStatement() {
  /**
   * [bison/yacc compat syntax]
   * : JS_BREAK identifier__opt terminator
   * ;
   */
  ENTER(BreakStatement);
  TokenInfo *token = Seek();
  BreakStmt* stmt = new(pool()) BreakStmt(Seek(-1)->line_number());
  if (token->type() == Token::JS_IDENTIFIER) {
    AstNode* identifier = ParseLiteral(false);
    CHECK_ERROR(stmt);
    stmt->AddChild(identifier);
  }
  ParseTerminator();
  CHECK_ERROR(stmt);
  stmt->AddChild(new(pool()) Empty);
  END(BreakStatement);
  return stmt;
}

//Parse return statement.
AstNode* Parser::ParseReturnStatement() {
  /**
   * [bison/yacc compat syntax]
   * return_statement
   * : JS_RETURN expression__opt terminator
   * ;
   */
  ENTER(ReturnStatement);
  if (!state_stack_->Has(StateStack::kFunction)) {
    SYNTAX_ERROR("return statement only allowed in 'function'\\nin file "
                  << filename_ << " at line " << Seek(-1)->line_number());
    END(ReturnStatement);
    return new(pool()) Empty;
  }
  bits_.Set(RETURN_FLG);
  TokenInfo *token = Seek();
  ReturnStmt* stmt = new(pool()) ReturnStmt(token->line_number());
  if (token->type() == ';' || token->type() == '}' || token->linebreak_before()) {
    stmt->AddChild(new(pool()) Empty);
  } else {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(stmt);
    stmt->AddChild(exp);
    ParseTerminator();
    CHECK_ERROR(exp);
  }
  END(ReturnStatement);
  return stmt;
}


//Parse with statement.
AstNode* Parser::ParseWithStatement() {
  /**
   * [bison/yacc compat syntax]
   * with_statement
   * : JS_WITH '(' expression ')' statement
   */
  ENTER(WithStatement);
  TokenInfo *token = Advance();
  WithStmt* stmt = new(pool()) WithStmt(Seek(-1)->line_number());
  if (token->type() == '(') {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(stmt);
    stmt->set_expression(exp);
    token = Advance();
    if (token->type() == ')') {
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR(stmt);
      stmt->AddChild(statement);
    } else {
      SYNTAX_ERROR("parse error unmatched paren"
                    " in 'with statement expression'\\nin file"
                    << filename_ << " at line " << token->line_number());
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'with statement expression' expect '('\\nin file"
                  << filename_ << " at line " << token->line_number());
  }
  END(WithStatement);
  return stmt;
}


//Parse switch statement.
AstNode* Parser::ParseSwitchStatement() {
  /**
   * [bison/yacc compat syntax]
   * switch_statement
   * : JS_SWITCH '(' expression ')' case_block
   * ;
   */
  ENTER(SwitchStatement);
  TokenInfo *token = Advance();
  SwitchStmt* stmt = new(pool()) SwitchStmt(token->line_number());
  if (token->type() == '(') {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(stmt);
    stmt->set_expression(exp);
    token = Advance();
    if (token->type() == ')') {
      AstNode* case_block = ParseCaseClauses();
      CHECK_ERROR(stmt);
      stmt->Append(case_block);
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'switch statement expression' expect ')'\\nin file"
                    << filename_ << " at line " << token->line_number());
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'switch statement expression' expect '('\\nin file"
                  << filename_ << " at line " << token->line_number());
  }
  END(SwitchStatement);
  return stmt;
}


//Parse case clauses
AstNode* Parser::ParseCaseClauses() {
  /**
   * [bison/yacc compat syntax]
   * case_clauses
   * : case_clause
   * | case_clauses case_clause
   * ;
   *
   * case_clause
   * : JS_CASE expression ':' statement_list__opt
   * ;
   *
   * default_clause
   * : JS_DEFAULT ':' statement_list__opt
   * ;
   */
  ENTER(CaseClauses);
  TokenInfo *token = Advance();
  NodeList *list = new(pool()) NodeList;
  if (token->type() == '{') {
    while (token->type() != '}') {
      token = Advance();
      bool is_default = token->type() == Token::JS_DEFAULT;
      if (token->type() == Token::JS_CASE || is_default) {
        CaseClause* clause = 0;//init after.
        if (!is_default) {
          clause = new(pool()) CaseClause(token->line_number());
          AstNode* exp = ParseExpression(false);
          CHECK_ERROR(clause);
          clause->set_expression(exp);
        } else {
          clause = new(pool()) CaseClause(token->line_number());
          clause->set_expression(new(pool()) Empty);
        }
        token = Advance();
        if (token->type() == ':') {
          token = Seek();
          if (token->type() == Token::JS_CASE) {
            clause->AddChild(new(pool()) Empty);
            list->AddChild(clause);
          } else {
            AstNode* statement_list = ParseStatementList(CaseBodyMatcher, "'case','default' or '}'");
            CHECK_ERROR(clause);
            clause->Append(statement_list);
            list->AddChild(clause);
          }
        } else {
          SYNTAX_ERROR("parse error got unexpected token "
                        << TokenConverter(token).cstr()
                        << " in 'switch statement case expression' expect ':'\\nin file"
                        << filename_ << " at line " << token->line_number());
          END(SwitchStatementError);
          return list;
        }
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'switch statement case block' expect 'case'\\nin file"
                      << filename_ << " at line " << token->line_number());
        END(SwitchStatementError);
        return list;
      }
      token = Seek();
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'switch statement case block' expect '{'\\nin file"
                  << filename_ << " at line " << token->line_number());
    END(SwitchStatementError);
    return list;
  }
  Advance();
  END(CaseClause);
  return list;
}


//Parse labelled statement
AstNode* Parser::ParseLabelledStatement() {
  /**
   * [bison/yacc compat syntax]
   * labelled_statement
   * : JS_IDENTIFIER ':' statement
   * ;
   */
  ENTER(LabelledStatement);
  TokenInfo* token = Seek(-1);
  AstNode* ident = ParseLiteral(false);
  CHECK_ERROR(ident)
      Advance();
  AstNode* statement = ParseStatement();
  CHECK_ERROR(statement);
  LabelledStmt* stmt = new(pool()) LabelledStmt(token->line_number());
  CHECK_ERROR(stmt);
  stmt->AddChild(ident);
  stmt->AddChild(statement);
  END(LabelledStatement);
  return stmt;
}


//Parse throw statement
AstNode* Parser::ParseThrowStatement() {
  /**
   * [bison/yacc compat syntax]
   * throw_statement
   * : JS_THROW expression terminator
   * ;
   */
  ENTER(ThrowStatement);
  TokenInfo* token = Seek(-1);
  ThrowStmt* throw_stmt = new(pool()) ThrowStmt(token->line_number());
  AstNode* exp = ParseExpression(false);
  CHECK_ERROR(throw_stmt);
  throw_stmt->set_expression(exp);
  ParseTerminator();
  CHECK_ERROR(exp);
  END(ThrowStatement);
  return throw_stmt;
}


//Parse try statement
AstNode* Parser::ParseTryStatement() {
  /**
   * [bison/yacc compat syntax]
   * try_statement
   * : JS_TRY block catch
   * | JS_TRY block finally
   * | JS_TRY block catch finally
   * ;
   */
  ENTER(TryStatement);
  TokenInfo* token = Seek();
  TryStmt *stmt = new(pool()) TryStmt(token->line_number());
  if (token->type() == '{') {
    Advance();
    AstNode* block = ParseBlockStatement();
    CHECK_ERROR(stmt);
    stmt->AddChild(block);
    token = Seek();
    if (token->type() == Token::JS_CATCH) {
      AstNode* catch_block = ParseCatchBlock();
      CHECK_ERROR(stmt);
      stmt->set_catch_block(catch_block);
      token = Seek();
    } else {
      stmt->set_catch_block(new(pool()) Empty);
    }
    if (token->type() == Token::JS_FINALLY) {
      Advance();
      AstNode* finally_block = ParseFinallyBlock();
      CHECK_ERROR(stmt);
      stmt->set_finally_block(finally_block);
    } else {
      stmt->set_finally_block(new(pool()) Empty);
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'try statement' expect '{'\\nin file"
                  << filename_ << " at line " << token->line_number());
  }
  END(TryStatement);
  return stmt;
}

//Parse catch block
AstNode* Parser::ParseCatchBlock() {
  ENTER(CatchBlock);
  TokenInfo *token = Advance(2);
  if (token->type() == '(') {
    AstNode* ident = ParseLiteral(false);
    CHECK_ERROR(ident);
    token = Advance();
    if (token->type() == ')') {
      token = Seek();
      if (token->type() != '{') {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'catch block' expect '{'\\nin file"
                      << filename_ << " at line " << token->line_number());
      } else {
        Advance();
        AstNode* block = ParseBlockStatement();
        CHECK_ERROR(ident);
        ident->AddChild(block);
        END(CatchBlock);
        return ident;
      }
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'catch block' expect ')'\\nin file"
                    << filename_ << " at line " << token->line_number());
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'catch block' expect '('\\nin file"
                  << filename_ << " at line " << token->line_number());
  }
  END(CatchBlockError);
  return new(pool()) Empty;
}


AstNode* Parser::ParseFinallyBlock() {
  ENTER(FinallyBlock);
  TokenInfo *token = Advance();
  if (token->type() == '{') {
    state_stack_->Push(StateStack::kFinally);
    AstNode* block = ParseBlockStatement();
    state_stack_->Pop();
    END(FinallyBlock);
    return block;
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'finally block' expect '{'\\nin file"
                  << filename_ << " at line " << token->line_number());
    END(FinallyBlockError);
    return new(pool()) Empty;
  }
}


AstNode* Parser::ParseTrait() {
  ENTER(Trait);
  TokenInfo* token = Seek();
  Trait* trait = new(pool()) Trait(token->line_number());
  if (token->type() == Token::JS_IDENTIFIER) {
    AstNode* literal = ParseLiteral(false);
    CHECK_ERROR(literal);
    trait->set_name(literal);
    token = Seek();
  } else {
    trait->set_name(new(pool()) Empty);
  }
  if (token->type() == '{') {
    ParseTraitBody(trait);
    CHECK_ERROR(trait);
    Advance();
    return trait;
  } else {
    SYNTAX_ERROR("got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'TraitDeclaration' expect '{'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(TraitError);
    return trait;
  }
  END(Trait);
}


void Parser::ParseTraitBody(Trait* trait) {
  Advance();
  TokenInfo* token = Seek();
  while (1) {
    if (token->type() == Token::JS_IDENTIFIER) {
      if (strcmp(token->token(), "requires") == 0) {
        Advance();
        while (1) {
          AstNode* ret = ParseLiteral(false);
          CHECK_ERROR(;);
          Literal* val = ret->CastToLiteral();
          val->set_value_type(Literal::kProperty);
          token = Seek();
          trait->set_require(ret);
          if (token->type() == ',') {
            Advance();
          } else {
            ParseTerminator();
            CHECK_ERROR(;);
            break;
          }
        }
      } else if (strcmp(token->token(), "mixin") == 0) {
        Advance();
        AstNode* mixin = ParseMixin();
        CHECK_ERROR(;);
        trait->set_mixin(mixin);
      } else {
        AstNode* ret = ParseFunctionDecl(false);
        CHECK_ERROR(;);
        ParseTerminator();
        CHECK_ERROR(;);
        TraitMember *member = new(pool()) TraitMember(TraitMember::kPrivate, ret, token->line_number());
        trait->set_member(member);
      }
    } else if (token->type() == Token::JS_PUBLIC) {
      Advance();
      AstNode* ret = ParseFunctionDecl(false);
      CHECK_ERROR(;);
      ParseTerminator();
      CHECK_ERROR(;);
      TraitMember *member = new(pool()) TraitMember(TraitMember::kPublic, ret, token->line_number());
      trait->set_member(member);
    } else if (token->type() == Token::JS_PRIVATE) {
      Advance();
      AstNode* ret = ParseFunctionDecl(false);
      CHECK_ERROR(;);
      ParseTerminator();
      CHECK_ERROR(;);
      TraitMember *member = new(pool()) TraitMember(TraitMember::kPrivate, ret, token->line_number());
      trait->set_member(member);
    } else {
      SYNTAX_ERROR("got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'trait declaration'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(TraitBodyError);
      return;
    }
    token = Seek();
    if (token->type() == '}') {
      break;
    }
  }
}


AstNode* Parser::ParseMixin() {
  AstNode* literal = ParseLiteral(false);
  CHECK_ERROR(literal);
  MixinMember* mixin = new(pool()) MixinMember(Seek(-1)->line_number());
  mixin->set_name(literal);
  TokenInfo* token = Seek();
  while (1) {
    if (token->type() == Token::JS_WITH) {
      Advance();
      AstNode* before = ParseLiteral(false);
      CHECK_ERROR(before);
      Literal* val = before->CastToLiteral();
      val->set_value_type(Literal::kProperty);
      token = Seek();
      if (token->type() == Token::JS_IDENTIFIER &&
           strcmp(token->token(), "as") == 0) {
        Advance();
        AstNode* after = ParseLiteral(false);
        CHECK_ERROR(after);
        Literal* after_val = after->CastToLiteral();
        after_val->set_value_type(Literal::kProperty);
        NodeList* list = new(pool()) NodeList;
        list->AddChild(before);
        list->AddChild(after);
        mixin->set_rename_list(list);
        token = Seek();
        if (token->type() == ',') {
          Advance();
          token = Seek();
        } else {
          ParseTerminator();
          CHECK_ERROR(mixin);
          break;
        }
      } else {
        SYNTAX_ERROR("got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'mixin declaration' expect 'as'\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(MixinError);
        return mixin;
      }
    } else if (token->type() == Token::JS_IDENTIFIER &&
                strcmp(token->token(), "without") == 0) {
      Advance();
      AstNode* remove = ParseLiteral(false);
      CHECK_ERROR(remove);
      remove->CastToLiteral()->set_value_type(Literal::kProperty);
      mixin->set_remove_list(remove);
      token = Seek();
      if (token->type() == ',') {
        Advance();
        token = Seek();
      } else {
        ParseTerminator();
        CHECK_ERROR(remove);
        break;
      }
    } else {
      break;
    }
  }
  return mixin;
}


AstNode* Parser::ParseClassDecl(bool is_const) {
  ENTER(ClassDecl);
  TokenInfo* token = Seek();
  AstNode* name;
  AstNode* inherit;
  state_stack_->Push(StateStack::kClassDecl);
  if (token->type() == Token::JS_IDENTIFIER) {
    name = ParseLiteral(false);
    CHECK_ERROR(name);
  } else {
    name = new(pool()) Empty;
  }
  token = Seek();
  if (token->type() == Token::JS_EXTENDS ||
       (token->type() == Token::JS_IDENTIFIER ||
         strcmp(token->token(), "prototype") == 0)) {
    inherit = ParseInheritDecl();
    CHECK_ERROR(inherit);
  } else {
    inherit = new(pool()) Empty;
  }
  Class *cls = new(pool()) Class(inherit, token->line_number());
  if (is_const) {
    cls->MarkAsConstDeclaration();
  }
  cls->set_name(name);
  token = Advance();
  if (token->type() == '{') {
    AstNode* body = ParseClassBody();
    CHECK_ERROR(cls);
    cls->set_body(body);
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'class declaration' expect '{'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(ClassDecl);
    state_stack_->Pop();
    return cls;
  }
  END(ClassDecl);
  state_stack_->Pop();
  return cls;
}


AstNode* Parser::ParseInheritDecl() {
  ENTER(InheritDecl);
  TokenInfo* token = Advance();
  ClassExpandar* expandar;
  if (token->type() == Token::JS_EXTENDS) {
    expandar = new(pool()) ClassExpandar(ClassExpandar::kExtends, token->line_number());
  } else {
    expandar = new(pool()) ClassExpandar(ClassExpandar::kPrototype, token->line_number());
  }
  AstNode* member = ParseMemberExpression();
  CHECK_ERROR(member);
  expandar->AddChild(member);
  END(InheritDecl);
  return expandar;
}


AstNode* Parser::ParseClassBody() {
  ENTER(ClassBody);
  TokenInfo* token = Seek();
  if (token->type() == '}') {
    Advance();
    END(ClassBody);
    return new(pool()) Empty;
  } else {
    ClassProperties* list = new(pool()) ClassProperties(token->line_number());
    while (token->type() != '}') {
      ClassMember* mem = ParseClassMember();
      CHECK_ERROR(mem);
      switch (mem->attribute()) {
        case ClassMember::kPrivate :
          list->set_private_member(mem);
          break;
                                                                                                                                                                
        case ClassMember::kPublic :
          list->set_public_member(mem);
          break;

        case ClassMember::kPublicStatic :
          list->set_public_static_member(mem);
          break;

        case ClassMember::kPrivateStatic :
          list->set_private_static_member(mem);
          break;

        case ClassMember::kPrototype :
          list->set_prototype_member(mem);
          break;

        case ClassMember::kConstructor :
          list->set_constructor(mem);
          break;

        case ClassMember::kMixin :
          list->set_mixin_member(mem->first_child());
          break;
      }
      token = Seek();
    }
    Advance();
    END(ClassBody);
    return list;
  }
}

AstNode* Parser::ParseClassMemberStatement() {
  TokenInfo* token = Seek(-1);
  if (state_stack_->Has(StateStack::kClassDecl)) {
    ClassMember::MemberAttr member_type;
    if (token->type() == Token::JS_PUBLIC) {
      member_type = ClassMember::kPublic;
    } else if (token->type() == Token::JS_PRIVATE) {
      member_type = ClassMember::kPrivate;
    }
    AstNode* node = ParseExportableDefinition();
    CHECK_ERROR(node);
    ClassMember* member = new(pool()) ClassMember(member_type, token->line_number());
    member->AddChild(node);
    return member;
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'member expression' expect '.' or '['\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(MemberExpressionError);
    return new(pool()) Empty;
  }
}

ClassMember* Parser::ParseClassMember() {
  ENTER(ClassMember);
  TokenInfo* token = Seek();
  ClassMember::MemberAttr member_type;
  AstNode* exp;
  if (token->type() == Token::JS_IDENTIFIER && strcmp(token->token(), "constructor") == 0) {
    exp = ParseFunctionDecl(false);
    CHECK_ERROR(new(pool()) ClassMember(ClassMember::kConstructor, token->line_number()));
    ParseTerminator();
    CHECK_ERROR(new(pool()) ClassMember(ClassMember::kConstructor, token->line_number()));
    Function* fn = exp->CastToExpression()->CastToFunction();
    if (fn->name() == 0 || fn->name()->IsEmpty()) {
      SYNTAX_ERROR("Invalid member declaration in file "
                   << filename_ << " at line " << fn->line_number());
      return new(pool()) ClassMember(ClassMember::kConstructor, token->line_number());
    }
    fn->MarkAsDeclaration();
    member_type = ClassMember::kConstructor;
  } else if (token->type() == Token::JS_STATIC) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPublicStatic;
  } else if (token->type() == Token::JS_PRIVATE) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPrivate;
  } else if (token->type() == Token::JS_PUBLIC) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPublic;
  } else if (token->type() == Token::JS_IDENTIFIER &&
              strcmp(token->token(), "mixin") == 0) {
    Advance();
    exp = ParseMixin();
    CHECK_ERROR(new(pool()) ClassMember(ClassMember::kMixin, token->line_number()));
    ParseTerminator();
    CHECK_ERROR(new(pool()) ClassMember(ClassMember::kMixin, token->line_number()));
    member_type = ClassMember::kMixin;
  } else {
    exp = ParseExportableDefinition();
    if (exp->node_type() == AstNode::kClassMember) {
      return reinterpret_cast<ClassMember*>(exp);
    }
    member_type = ClassMember::kPrototype;
  }
  ClassMember* member = new(pool()) ClassMember(member_type, token->line_number());
  member->AddChild(exp);
  END(ClassMember);
  return member;
}


AstNode* Parser::ParseExportableDefinition() {
  ENTER(ExportableDefinition);
  TokenInfo *token = Seek();
  if (token->type() == Token::JS_IDENTIFIER || token->type() == '{' || token->type() == '[') {
    token = Seek(2);
    if (token->type() == '(' || token->type() == Token::JS_FUNCTION_GLYPH ||
         token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      END(ExportableDefinition);
      AstNode* ret = ParseFunctionDecl(false);
      CHECK_ERROR(ret);
      ParseTerminator();
      CHECK_ERROR(ret);
      return ret;
    } else {
      AstNode* ret = ParseVariableDecl(false);
      CHECK_ERROR(ret);
      ParseTerminator();
      CHECK_ERROR(ret);
      END(ExportableDefinition);
      return ret;
    }
  } else if (token->type() == Token::JS_CLASS) {
    Advance();
    AstNode* class_exp = ParseClassDecl(false);
    CHECK_ERROR(class_exp);
    END(ExportableDefinition);
    return class_exp;
  } else {
    if (token->type() == Token::JS_CONST) {
      token = Seek(2);
      if (token->type() == Token::JS_CLASS) {
        END(ExportableDefinition);
        return ParseClassDecl(true);
      } else if (token->type() == '(' || token->type() == Token::JS_FUNCTION_GLYPH ||
                  token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
        Advance();
        END(ExportableDefinition);
        AstNode* ret = ParseFunctionDecl(true);
        CHECK_ERROR(ret);
        ParseTerminator();
        CHECK_ERROR(ret);
        ret->CastToExpression()->CastToFunction()->MarkAsConstDeclaration();
        return ret;
      } else {
        Advance();
        AstNode* ret = ParseVariableDecl(false);
        CHECK_ERROR(ret);
        ParseTerminator();
        CHECK_ERROR(ret);
        END(ExportableDefinition);
        ret->CastToExpression()->CastToVariableDeclarationList()->MarkAsConstDeclaration();
        return ret;
      }
    } else if (token->type() == Token::JS_GET) {
      AstNode* fn = ParseFunctionDecl(false);
      CHECK_ERROR(fn);
      fn->CastToExpression()->CastToFunction()->set_attribute(Function::kGet);
      END(ExportableDefinition);
      return fn;
    } else if (token->type() == Token::JS_SET) {
      AstNode* fn = ParseFunctionDecl(false);
      CHECK_ERROR(fn);
      fn->CastToExpression()->CastToFunction()->set_attribute(Function::kSet);
      END(ExportableDefinition);
      return fn;
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'exportable definition' expect 'identifier','const','get' or 'set'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(ExportableDefinitionError);
      return new(pool()) Empty;
    }
  }
}


AstNode* Parser::ParseExpression(bool is_noin) {
  ENTER(Expression);
  Expression* exp = new(pool()) Expression(Seek()->line_number());
  AstNode* assignment = ParseAssignmentExpression(is_noin);
  CHECK_ERROR(exp);
  exp->AddChild(assignment);
  TokenInfo* token = Seek();
  if (token->type() == ',') {
    Advance();
    while (1) {
      AstNode* assignment = ParseAssignmentExpression(is_noin);
      CHECK_ERROR(exp);
      exp->AddChild(assignment);
      token = Seek();
      if (token->type() == ',') {
        token = Advance();
      } else {
        break;
      }
    }
  }
  END(Expression);
  return exp;
}

bool IsAssignmentOp(int type) {
  return type == '=' || type == Token::JS_MUL_LET ||
      type == Token::JS_DIV_LET || type == Token::JS_MOD_LET ||
      type == Token::JS_ADD_LET || type == Token::JS_SUB_LET ||
      type == Token::JS_SHIFT_LEFT_LET || type == Token::JS_SHIFT_RIGHT_LET ||
      type == Token::JS_U_SHIFT_RIGHT_LET || type == Token::JS_AND_LET ||
      type == Token::JS_NOT_LET || type == Token::JS_OR_LET;
}

AstNode* Parser::ParseAssignmentExpression(bool is_noin) {
  ENTER(AssignmentExpression);
  AstNode* exp = ParseYieldExpression(is_noin);
  CHECK_ERROR(exp);
  TokenInfo *token = Seek();
  if (IsAssignmentOp(token->type())) {
    Advance();
    if (exp->CastToExpression() && exp->CastToExpression()->IsValidLhs()) {
      if (exp->CastToExpression()->IsParenthesis() && exp->child_length() > 0) {
        AstNode* tmp = exp->last_child();
        while (tmp->node_type() == AstNode::kExpression) {
          tmp = tmp->first_child();
          if (tmp->node_type() == AstNode::kExpression && tmp->child_length() > 1) {
            SYNTAX_ERROR("invalid left hand side\\nin file "
                          << filename_ << " at line " << token->line_number());
            END(AssignmentExpressionError);
            return exp;
          }
        }
        if (tmp->node_type() == AstNode::kArrayLikeLiteral ||
             tmp->node_type() == AstNode::kObjectLikeLiteral) {
          exp = tmp;
        }
      }
      exp->CastToExpression()->MarkAsLhs();
      AstNode* rhs = ParseAssignmentExpression(is_noin);
      CHECK_ERROR(rhs);
      AssignmentExp* assign_exp = new(pool()) AssignmentExp(token->type(), exp, rhs, rhs->line_number());
      return assign_exp;
    } else {
      SYNTAX_ERROR("parse error invalid left hand side expression in 'assignment expression'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(AssignmentExpressionError);
      return new(pool()) Empty;
    }
  }
  END(AssignmentExpression);
  return exp;
}

AstNode* Parser::ParseYieldExpression(bool is_noin) {
  ENTER(YieldExpression);
  TokenInfo* token = Seek();
  if (token->type() == Token::JS_YIELD) {
    if (state_stack_->Has(StateStack::kFinally)) {
      SYNTAX_ERROR("yield statement not allowed in 'finally block'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(YieldExpressionError);
      return new(pool()) Empty;
    }
    if (!state_stack_->Has(StateStack::kFunction)) {
      SYNTAX_ERROR("yield statement only allowed in 'function'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(YieldExpressionError);
      return new(pool()) Empty;
    }
    bits_.Set(YIELD_FLG);
    Advance();
    token = Seek();
    if (token->linebreak_after() || token->type() == ';' || token->type() == '}') {
      if (token->type() == ';') {
        Advance();
      }
      YieldExp* exp = new(pool()) YieldExp(token->line_number());
      exp->AddChild(new(pool()) Empty);
      END(YieldExpression);
      return exp;
    } else {
      YieldExp* exp = new(pool()) YieldExp(token->line_number());
      AstNode* assignment = ParseAssignmentExpression(false);
      CHECK_ERROR(exp);
      exp->AddChild(assignment);
      END(YieldExpression);
      return exp;
    }
  } else {
    END(YieldExpression);
    return ParseConditional(is_noin);
  }
}

AstNode* Parser::ParseConditional(bool is_noin) {
  ENTER(Conditional);
  AstNode* exp = ParseBinaryExpression(is_noin);
  CHECK_ERROR(exp);
  TokenInfo* token = Seek();
  if (token->type() == '?') {
    Advance();
    AstNode* left = ParseAssignmentExpression(is_noin);
    CHECK_ERROR(exp);
    token = Seek();
    if (token->type() == ':') {
      Advance();
      AstNode* right = ParseAssignmentExpression(is_noin);
      CHECK_ERROR(exp);
      ConditionalExp* cond = new(pool()) ConditionalExp(exp, left, right, token->line_number());
      END(Conditional);
      cond->MarkAsInValidLhs();
      return cond;
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'conditional expression' expect ':'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(ConditionalError);
      return new(pool()) Empty;
    }
  } else {
    END(Conditional);
    return exp;
  }
}


AstNode* Parser::ParseBinaryExpression(bool is_noin) {
  ENTER(BinaryExpression);
  AstNode* last = 0;
  AstNode* first = 0;
  AstNode* lhs = ParseUnaryExpression();
  AstNode* exp = 0;
  CHECK_ERROR(lhs);
  while (1) {
    TokenInfo* token = Seek();
    switch (token->type()) {
      case Token::JS_LOGICAL_AND :
      case Token::JS_LOGICAL_OR :
      case Token::JS_EQUAL :
      case Token::JS_NOT_EQUAL :
      case Token::JS_EQ :
      case Token::JS_NOT_EQ :
      case Token::JS_LESS_EQUAL :
      case Token::JS_GREATER_EQUAL :
      case Token::JS_INSTANCEOF :
      case '<' :
      case '>' : {
        Advance();
        AstNode* rhs = ParseUnaryExpression();
        CHECK_ERROR(rhs);
        if (last == 0) {
          exp = new(pool()) CompareExp(token->type(), lhs, rhs, token->line_number());
          first = exp;
        } else {
          exp = new(pool()) CompareExp(token->type(), last, rhs, token->line_number());
        }
        exp->CastToExpression()->MarkAsInValidLhs();
        last = exp;
      }
        break;

      case Token::JS_IN : {
        if (!is_noin) {
          Advance();
          AstNode* rhs = ParseUnaryExpression();
          CHECK_ERROR(rhs);
          if (last == 0) {
            exp = new(pool()) CompareExp(token->type(), lhs, rhs, token->line_number());
            first = exp;
          } else {
            exp = new(pool()) CompareExp(token->type(), last, rhs, token->line_number());
          }
          exp->CastToExpression()->MarkAsInValidLhs();
          last = exp;
        } else {
          END(BinaryExpressionNoIn);
          return (first == 0)? lhs : exp;
        }
      }
        break;
                                                                                                                                
      case '|' :
      case '^' :
      case '&' :
      case '+' :
      case '-' :
      case '*' :
      case '/' :
      case '%' :
      case Token::JS_SHIFT_LEFT :
      case Token::JS_SHIFT_RIGHT :
      case Token::JS_U_SHIFT_RIGHT :{
        Advance();
        AstNode* rhs = ParseUnaryExpression();
        CHECK_ERROR(rhs);
        if (last == 0) {
          exp = new(pool()) BinaryExp(token->type(), lhs, rhs, token->line_number());
          first = exp;
        } else {
          exp = new(pool()) BinaryExp(token->type(), last, rhs, token->line_number());
        }
        exp->CastToExpression()->MarkAsInValidLhs();
        last = exp;
      }
        break;
                                                                                                                                
      default :
        END(BinaryExpression);
        return (exp == 0)? lhs : exp;
    }
  }
}



bool IsUnaryOp(int type) {
  return type == Token::JS_DELETE || type == Token::JS_VOID ||
      type == Token::JS_TYPEOF || type == Token::JS_INCREMENT ||
      type == Token::JS_DECREMENT || type == '+' ||
      type == '-' || type == '~' || type == '!';
}


AstNode* Parser::ParseUnaryExpression() {
  ENTER(UnaryExpression);
  TokenInfo* token = Seek();
  if (IsUnaryOp(token->type())) {
    Advance();
    AstNode* post_exp = ParseUnaryExpression();
    CHECK_ERROR(post_exp);
    post_exp->CastToExpression()->MarkAsInValidLhs();
    UnaryExp* unary = new(pool()) UnaryExp(token->type(), post_exp, token->line_number());
    post_exp->CastToExpression()->MarkAsUnary();
    END(UnaryExpression);
    return unary;
  } else {
    END(UnaryExpression);
    return ParsePostfixExpression();
  }
}


AstNode* Parser::ParsePostfixExpression() {
  ENTER(PostfixExpression);
  AstNode* lhs = ParseLeftHandSideExpression();
  CHECK_ERROR(lhs);
  TokenInfo *token = Seek();
  if (!token->linebreak_before() && (token->type() == Token::JS_INCREMENT || token->type() == Token::JS_DECREMENT)) {
    lhs->CastToExpression()->MarkAsInValidLhs();
    PostfixExp* post = new(pool()) PostfixExp(token->type(), lhs, token->line_number());
    Advance();
    END(PostfixExpression);
    return post;
  }
  END(PostfixExpression);
  return lhs;
}


AstNode* Parser::ParseLeftHandSideExpression() {
  ENTER(LeftHandSideExpression);
  TokenInfo *token = Seek();
  AstNode* node;
  if (token->type() == Token::JS_NEW) {
    node = ParseNewExpression();
    node->CastToExpression()->MarkAsInValidLhs();
  } else {
    node = ParseCallExpression();
  }
  END(LeftHandSide);
  return node;
}

NewExp* Parser::ParseNewExpression() {
  ENTER(NewExpression);
  Advance();
  TokenInfo* token = Seek();
  NewExp* exp = new(pool()) NewExp(token->line_number());
  NewExp* first = exp;
  while (token->type() == Token::JS_NEW) {
    Advance();
    NewExp *next = new(pool()) NewExp(token->line_number());
    exp->AddChild(next);
    exp = next;
    token = Seek();
  }
  AstNode* member = ParseCallExpression();
  CHECK_ERROR(exp);
  exp->AddChild(member);
  END(NewExpression);
  return first;
}

AstNode* Parser::ParseCallExpression() {
  ENTER(CallExpression);
  AstNode* member = ParseMemberExpression();
  CHECK_ERROR(member);
  TokenInfo* token = Seek();
  if (token->type() == '(') {
    Advance();
    AstNode* arguments = ParseArguments();
    CHECK_ERROR(arguments);
    token = Advance();
    if (token->type() != ')') {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'call expression' expect ')'\\nin file "
                    << filename_ << " at line " << token->line_number());
    }
    token = Seek();
    bool is_function_decl = (token->type() == Token::JS_FUNCTION_GLYPH || token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT);
    Literal* symbol = member->CastToLiteral();
    if (symbol && symbol->value_type() == Literal::kIdentifier && is_function_decl) {
      Advance();
      AstNode* fn = ParseArrowFunctionExpression(member, arguments, token->type());
      CHECK_ERROR(fn);
      END(ParseCallExpression_);
      return fn;
    } else if (is_function_decl) {
      SYNTAX_ERROR("parse error arrow function expression name must be 'identifier'\\nin file "
                    << filename_ << " at line " << token->line_number());
    }
    CallExp* exp = new(pool()) CallExp(CallExp::kNormal, token->line_number());
    exp->set_callable(member);
    exp->set_args(arguments);
    token = Seek();
    if (token->type() == '.' || token->type() == '[' || token->type() == '(') {
      if (token->type() != '(') {
        exp = ParseEachMember(token->type(), true, exp);
      }
      token = Seek();
      while (1) {
        CallExp* ret = 0;
        if (token->type() != '(') {
          ret = ParseEachMember(token->type(), false, exp);
        } else if (token->type() == '(') {
          Advance();
          AstNode* arguments = ParseArguments();
          CHECK_ERROR(arguments);
          token = Advance();
          if (token->type() != ')') {
            SYNTAX_ERROR("parse error got unexpected token "
                          << TokenConverter(token).cstr()
                          << " in 'call expression' expect ')'\\nin file "
                          << filename_ << " at line " << token->line_number());
            END(CallExpressionError);
            return exp;
          }
          ret = new(pool()) CallExp(CallExp::kNormal, token->line_number());
          ret->set_callable(exp);
          ret->MarkAsInValidLhs();
          if (arguments->child_length() == 0) {
            ret->set_args(new(pool()) Empty);
          } else {
            ret->set_args(arguments);
          }
        }
        if (ret == 0) {
          END(CallExpression);
          return exp;
        } else {
          exp = ret;
        }
        token = Seek();
      }
      END(CallExpression);
      return exp;
    } else if (token->type() == Token::JS_FUNCTION_GLYPH || token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      Advance();
      END(CallExpression);
      return ParseArrowFunctionExpression(member, arguments, token->type());
    } else {
      END(CallExpression);
      exp->CastToExpression()->MarkAsInValidLhs();
      return exp;
    }
  } else {
    END(CallExpression);
    return member;
  }
}


AstNode* Parser::ParseArguments() {
  ENTER(Arguments);
  TokenInfo* token = Seek();
  NodeList* list = new(pool()) NodeList;
  if (token->type() != ')') {
    while (token->type() != ')') {
      if (token->type() == Token::JS_PARAMETER_REST) {
        Advance();
        token = Seek();
        if (token->type() == Token::JS_IDENTIFIER) {
          AstNode* value = ParseLiteral(false);
          CHECK_ERROR(list);
          value->CastToLiteral()->set_value_type(Literal::kSpread);
          list->AddChild(value);
        } else {
          SYNTAX_ERROR("parse error got unexpected token "
                        << TokenConverter(token).cstr()
                        << " in 'formal parameter rest or arguments spread' expect 'identifier'\\nin file "
                        << filename_ << " at line " << token->line_number());
          END(FormalParameterErrror);
          return list;
        }
      } else {
        AstNode* exp = ParseAssignmentExpression(false);
        CHECK_ERROR(list);
        list->AddChild(exp);
      }
      token = Seek();
      if (token->type() == ',') {
        Advance();
        token = Seek();
      }
    }
    END(Arguments);
    return list;
  } else {
    END(Arguments);
    return new(pool()) Empty;
  }
}


AstNode* Parser::ParseMemberExpression() {
  ENTER(MemberExpression);
  TokenInfo* token = Seek();
  CallExp* exp;
  if (token->type() == Token::JS_PRIVATE) {
    TokenInfo* pr_sym = token;
    Literal* private_literal = new(pool()) Literal(Literal::kProperty, token->line_number());
    private_literal->set_value(pr_sym);
    private_literal->MarkAsInValidLhs();
    Advance();
    token = Seek();
    if (token->type() != '.' && token->type() != '[') {
      END(MemberExpression);
      private_literal->set_value_type(Literal::kPrivate);
      return private_literal;
    }
    exp = new(pool()) CallExp(CallExp::kPrivate, token->line_number());
    exp->set_callable(private_literal);
    ParseEachMember(token->type(), true, exp);
    token = Seek();
  } else {
    AstNode *primary = ParsePrimaryExpression();
    CHECK_ERROR(primary);
    token = Seek();
    if (token->type() != '.' && token->type() != '[') {
      END(MemberExpression);
      return primary;
    }
    int call_type = (token->type() == '.')? CallExp::kDot : CallExp::kBracket;
    exp = new(pool()) CallExp(call_type, token->line_number());
    exp->set_callable(primary);
    ParseEachMember(token->type(), true, exp);
    token = Seek();
  }
  while (1) {
    CallExp* ret = ParseEachMember(token->type(), false, exp);
    if (ret == 0) {
      END(MemberExpression);
      return exp;
    } else {
      exp = ret;
    }
    token = Seek();
  }
  END(MemberExpression);
  return exp;
}


AstNode* Parser::ParseBracketMember() {
  ENTER(BracketMember);
  Advance();
  AstNode* node = ParseExpression(false);
  CHECK_ERROR(node);
  TokenInfo* token = Advance();
  if (token->type() != ']') {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'member expression' expect ']'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(BracketMemberError);
    return node;
  }
  END(BracketMember);
  return node;
}


AstNode* Parser::ParseDotMember(bool *is_extend) {
  ENTER(DotMember);
  TokenInfo* token = Seek();
  int extend_type = Seek(2)->type();
  if (extend_type == '{') {
    *is_extend = true;
    Advance(2);
    AstNode* node = ParseObjectLiteral();
    CHECK_ERROR(node);
    return node;
  } else {
    Advance();
    AstNode* node = ParseLiteral(true);
    CHECK_ERROR(node);
    Literal* maybe_ident = node->CastToLiteral();
    if (!maybe_ident || maybe_ident->value_type() != Literal::kIdentifier) {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'member expression' expect 'identifier'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(DotMemberError);
      return node;
    } else if (maybe_ident->value_type() == Literal::kIdentifier) {
      maybe_ident->set_value_type(Literal::kProperty);
    }
    END(DotMember);
    return node;
  }
}


CallExp* Parser::ParseEachMember(int type, bool is_first, CallExp* exp) {
  ENTER(EachMember);
  int64_t line = Seek(-1)->line_number();
  if (type == '[') {
    AstNode* node = ParseBracketMember();
    CHECK_ERROR(exp);
    if (is_first) {
      if (exp->call_type() == CallExp::kNormal) {
        CallExp* accessor = new(pool()) CallExp(CallExp::kBracket, line);
        accessor->set_callable(exp);
        accessor->set_args(node);
        return accessor;
      } else {
        exp->set_args(node);
        END(EachMember);
        return exp;
      }
    } else {
      CallExp* accessor = new(pool()) CallExp(CallExp::kBracket, line);
      accessor->set_callable(exp);
      accessor->set_args(node);
      END(EachMember);
      return accessor;
    }
  } else if (type == '.') {
    bool is_extend = false;
    AstNode* node = ParseDotMember(&is_extend);
    CHECK_ERROR(exp);
    if (is_first) {
      if (exp->call_type() == CallExp::kNormal) {
        int type = (is_extend)? CallExp::kExtend : CallExp::kDot;
        CallExp* accessor = new(pool()) CallExp(type, line);
        accessor->set_callable(exp);
        accessor->set_args(node);
        return accessor;
      } else {
        exp->set_args(node);
        END(EachMember);
        return exp;
      }
    } else {
      int type = (is_extend)? CallExp::kExtend : CallExp::kDot;
      CallExp* accessor = new(pool()) CallExp(type, line);
      accessor->set_callable(exp);
      accessor->set_args(node);
      END(EachMember);
      return accessor;
    }
  } else {
    END(EachMember);
    return 0;
  }
}


AstNode* Parser::ParsePrimaryExpression() {
  ENTER(PrimaryExpression);
  TokenInfo* token = Advance();
  TokenInfo* function_signature = Seek();
  if (token->type() == Token::JS_FUNCTION) {
    AstNode* fn = ParseFunctionDecl(false);
    CHECK_ERROR(fn);
    fn->CastToExpression()->MarkAsInValidLhs();
    END(MemberExpression);
    return fn;
  } else if (token->type() == Token::JS_CLASS) {
    AstNode* class_exp = ParseClassDecl(false);
    CHECK_ERROR(class_exp);
    class_exp->CastToExpression()->MarkAsInValidLhs();
    return class_exp;
  } else if (token->type() == Token::JS_IDENTIFIER && strcmp(token->token(), "trait") == 0 &&
              (Seek()->type()  == '{' || Seek(2)->type() == '{')) {
    AstNode* trait = ParseTrait();
    CHECK_ERROR(trait);
    return trait;
  } else if (token->type() == Token::JS_FUNCTION_GLYPH || token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    AstNode* fn = ParseArrowFunctionExpression(token->type());
    CHECK_ERROR(fn);
    fn->CastToExpression()->MarkAsInValidLhs();
    END(MemberExpression);
    return fn;
  } else if (token->type() == Token::JS_IDENTIFIER && (function_signature->type() == Token::JS_FUNCTION_GLYPH ||
                                                         function_signature->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT)) {
    Undo();
    END(MemberExpression);
    return ParseFunctionDecl(false);
  } else if (token->type() == '{') {
    END(PrimaryExpression);
    return ParseObjectLiteral();
  } else if (token->type() == '[') {
    END(PrimaryExpression);
    return ParseArrayLiteral();
  } else if (token->type() == '(') {
    AstNode* exp = ParseExpression(false);
    CHECK_ERROR(exp);
    if (exp->child_length() > 1) {
      exp->CastToExpression()->MarkAsInValidLhs();
    }
    token = Seek();
    if (token->type() == ')') {
      Advance();
      token = Seek();
      Expression *expression = exp->CastToExpression();
      expression->MarkParenthesis();
    } else if (token->type() == Token::JS_FOR) {
      AstNode* generator = ParseGeneratorExpression(exp);
      CHECK_ERROR(generator);
      token = Advance();
      if (token->type() != ')') {
        SYNTAX_ERROR("unmatched parensis\\nin file "
                      << filename_ << " at line " << token->line_number());
        return generator;
      }
      return generator;
    } else {
      SYNTAX_ERROR("parse error unmatched parensis\\nin file "
                    << filename_ << " at line " << token->line_number());
      return exp;
    }
    if (token->type() == Token::JS_FUNCTION_GLYPH || token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      Advance();
      END(PrimaryExpression);
      AstNode* ret = ParseArrowFunctionExpression(exp, token->type());
      CHECK_ERROR(ret);
      ret->CastToExpression()->MarkAsInValidLhs();
      return ret;
    } else {
      END(PrimaryExpression);
      return exp;
    }
  } else if (token->type() == '#') {
    token = Advance();
    if (token->type() == '[') {
      AstNode* elem = ParseArrayLiteral();
      CHECK_ERROR(elem);
      elem->CastToExpression()->MarkAsInValidLhs();
      elem->CastToExpression()->CastToArrayLikeLiteral()->MarkAsTuple();
      return elem;
    } else if (token->type() == '{') {
      AstNode* elem = ParseObjectLiteral();
      CHECK_ERROR(elem);
      elem->CastToExpression()->MarkAsInValidLhs();
      elem->CastToExpression()->CastToObjectLikeLiteral()->MarkAsRecord();
      return elem;
    } else {
      SYNTAX_ERROR("got unexpected token "
                    << TokenConverter(token).cstr() <<
                    " expect '[' \\nin file "
                    << filename_ << " at line " << token->line_number());
      return new(pool()) Empty;
    }
  } else if (token->type() == Token::JS_FUNCTION_GLYPH ||
              token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    AstNode* fn = ParseArrowFunctionExpression(token->type());
    END(PrimaryExpression);
    fn->CastToExpression()->MarkAsInValidLhs();
    return fn;
  } else if (token->type() == Token::JS_DO) {
    AstNode* ret = ParseDoWhileStatement(true);
    CHECK_ERROR(ret);
    return ret;
  } else {
    Undo();
    END(PrimaryExpression);
    return ParseLiteral(false);
  }
}


AstNode* Parser::ParseGeneratorExpression(AstNode* exp) {
  AstNode* node = ParseArrayComprehensions();
  CHECK_ERROR(node);
  GeneratorExpression* generator = new(pool()) GeneratorExpression(exp, Seek(-1)->line_number());
  generator->AddChild(node);
  return generator;
}


AstNode* Parser::ParseObjectLiteral() {
  ENTER(ObjectLiteral);
  TokenInfo* token = Seek();
  int maybe_colon = Seek(2)->type();
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(token->line_number());
  if (token->type() != '}') {
    while (1) {
      if (maybe_colon == '}') {
        AstNode* node = ParseObjectElement(token->type(), token, object);
        CHECK_ERROR(node);
        node->AddChild(node->Clone(pool()));
        break;
      } else if (maybe_colon == ',') {
        AstNode* node = ParseObjectElement(token->type(), token, object);
        CHECK_ERROR(object);
        node->AddChild(node->Clone(pool()));
        token = Seek();
      } else if (maybe_colon == ':') {
        AstNode* node = ParseLiteral(true);
        CHECK_ERROR(node);
        Literal* prop = node->CastToLiteral();
        if (prop->value_type() == Literal::kIdentifier) {
          prop->set_value_type(Literal::kProperty);
        }
        Advance();
        token = Seek();
        AstNode* assign;
        if (token->type() == '{' || token->type() == '[') {
          assign = ParseAssignmentExpression(false);
        } else {
          assign = ParseAssignmentExpression(false);
          if (assign->CastToLiteral()) {
            Literal* literal = assign->CastToLiteral();
            if (literal->value_type() != Literal::kIdentifier) {
              object->MarkAsInValidLhs();
            }
          } else {
            object->MarkAsInValidLhs();
          }
        }
        CHECK_ERROR(assign);
        node->AddChild(assign);
        object->set_element(node);
        token = Seek();
      } else if (token->type() == '[') {
        AstNode* node = ParseObjectElement(token->type(), token, object);
        CHECK_ERROR(node);
        token = Advance();
        if (token->type() == ':') {
          AstNode* assign;
          token = Seek();
          if (token->type() == '{') {
            Advance();
            assign = ParseObjectLiteral();
          } else {
            assign = ParseAssignmentExpression(false);
          }
          CHECK_ERROR(assign);
          node->AddChild(assign);
          token = Seek();
        }
      } else if (maybe_colon == '(' || maybe_colon == Token::JS_FUNCTION_GLYPH ||
                  maybe_colon == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
        AstNode* fn = ParseFunctionDecl(false);
        CHECK_ERROR(fn);
        Literal* val = fn->CastToExpression()->CastToFunction()->name()->Clone(pool())->CastToLiteral();
        val->set_value_type(Literal::kProperty);
        fn->CastToExpression()->CastToFunction()->set_name(new(pool()) Empty);
        val->AddChild(fn);
        object->set_element(val);
        val->set_value_type(Literal::kProperty);
        token = Seek();
        object->MarkAsInValidLhs();
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << ". In 'object literal'\\n"
                      << filename_ << " at line " << token->line_number());
        END(ObjectLiteralError);
        return object;
      }
      if (token->type() == ',') {
        Advance();
      } else if (token->type() == '}') {
        Advance();
        break;
      }
      token = Seek();
      maybe_colon = Seek(2)->type();
    }
  } else {
    Advance();
  }
  END(ObjectLiteral);
  return object;                                
}



AstNode* Parser::ParseObjectElement(int type, TokenInfo* token, ObjectLikeLiteral* list) {
  ENTER(ObjectElement);
  if (IsValidPropertyName(type, token)) {
    AstNode* node = ParseLiteral(true);
    CHECK_ERROR(node);
    Advance();
    list->set_element(node);
    END(ObjectElement);
    Literal* name = node->CastToLiteral();
    if (name->value_type() == Literal::kIdentifier) {
      name->set_value_type(Literal::kProperty);
    }
    return node;
  } else if (type == '[') {
    Advance();
    AstNode* node = ParseAssignmentExpression(true);
    TokenInfo* token = Seek();
    if (token->type() != ']') {
      SYNTAX_ERROR("in 'object literal private property' expect ']' but got " << TokenConverter(token).cstr()
                    << "\\nin file " << filename_ << " at line " << token->line_number());
      END(ObjectElementError);
      return node;
    } else {
      Advance();
      Literal* value = new(pool()) Literal(Literal::kPrivateProperty, token->line_number());
      value->set_node(node);
      list->set_element(value);
      list->MarkAsInValidLhs();
      return value;
    }
  } else {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << ". In 'object literal'"
                  " member only allowed 'string literal','number' or 'identifier'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(ObjectElementError);
    return new(pool()) Empty;
  }
}


AstNode* Parser::ParseArrayLiteral() {
  ENTER(ArrayLiteral);
  ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(Seek(-1)->line_number());
  TokenInfo* token = Seek();
  int count = 0;
  if (token->type() == ']') {
    Advance();
    END(ArrayLiteral);
    return array;
  } else {
    while (1) {
      if (token->type() == ',') {
        array->set_element(new(pool()) Empty);
        int last_type = Seek(-1)->type();
        token = Advance();
        if (token->type() == ']') {
          if (last_type == '[') {
            array->set_element(new(pool()) Empty);
          }
          break;
        }
      } else if (token->type() == Token::JS_PARAMETER_REST) {
        token = Advance(2);
        if (token->type() == Token::JS_IDENTIFIER) {
          Literal* rest = new(pool()) Literal(Literal::kRest, token->line_number());
          rest->set_value(token);
          array->set_element(rest);
          token = Seek();
          if (token->type() == ']') {
            Advance();
            break;
          }
        } else {
          SYNTAX_ERROR("unexpected token "
                        << TokenConverter(token).cstr()
                        << " expect 'identifier' in 'rest expression'\\nin file "
                        << filename_ << " at line " << token->line_number());
          END(ArrayLiteralError);
          return array;
        }
      } else {
        AstNode* node = ParseAssignmentExpression(false);
        CHECK_ERROR(node);
        array->set_element(node);
        token = Seek();
        if (token->type() == Token::JS_FOR) {
          if (count > 0) {
            SYNTAX_ERROR("parse error got unexpected token "
                          << TokenConverter(token).cstr()
                          << " in 'array comprehensions expect' 'assignment expression'\\nin file "
                          << filename_ << " at line " << token->line_number());
            END(ArrayLiteralError);
            return array;
          }
          AstNode* cmp_node = ParseArrayComprehensions();
          CHECK_ERROR(cmp_node);
          array->elements()->RemoveChild(node);
          NodeList* children = new(pool()) NodeList;
          children->AddChild(node);
          children->AddChild(cmp_node);
          array->set_element(children);
          array->MarkAsComprehensions();
          token = Seek();
          if (token->type() != ']') {
            SYNTAX_ERROR("parse error got unexpected token "
                          << TokenConverter(token).cstr()
                          << " in 'array comprehensions expect' ']'\\nin file "
                          << filename_ << " at line " << token->line_number());
            END(ArrayLiteralError);
            return array;
          } else {
            Advance();
          }
          END(ArrayLiteral);
          return array;
        } else if (token->type() == ',') {
          Advance();
          token = Seek();
        } else if (token->type() == ']') {
          Advance();
          break;
        }
      }
      count++;
    }
  }
  END(ArrayLiteral);
  return array;
}


AstNode* Parser::ParseLiteral(bool reserved_usablity) {
  ENTER(Literal);
  TokenInfo* token = Advance();
  int value_type = 0;
  bool is_invalid_lhs = false;
  switch (token->type()) {
    case Token::JS_NAN :
      value_type = Literal::kNaN;
      is_invalid_lhs = true;
      break;
                                                                                                
    case Token::JS_SUPER :
      value_type = Literal::kSuper;
      is_invalid_lhs = true;
      break;
                                                                                                
    case Token::JS_THIS :
      value_type = Literal::kThis;
      is_invalid_lhs = true;
      break;
                                                                                                
    case Token::JS_IDENTIFIER : {
      value_type = Literal::kIdentifier;
      const char* ident = token->token();
      int len = strlen(ident);
      if (ident[ 0 ] == '@') {
        Literal* this_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                                      Token::JS_THIS, token->line_number(), Literal::kThis);
        if (len > 1) {
          Literal* value = builder()->CreateNameNode(&ident[ 1 ], Token::JS_IDENTIFIER, token->line_number(), Literal::kProperty);
          CallExp* this_accessor = builder()->CreateDotAccessor(this_sym, value, this_sym->line_number());
          return this_accessor;
        } else {
          return this_sym;
        }
      } else if (len > 1 && ident[ 0 ] == '_' && ident[ 1 ] == '@') {
        Literal* private_sym = builder()->CreateNameNode(JsToken::GetTokenFromNumber(Token::JS_PRIVATE),
                                                         Token::JS_PRIVATE, token->line_number(), Literal::kPrivate);
        if (len > 2) {
          Literal* value = builder()->CreateNameNode(&ident[ 2 ], Token::JS_IDENTIFIER, token->line_number(), Literal::kProperty);
          CallExp* private_accessor = new(pool()) CallExp(CallExp::kPrivate, token->line_number());
          private_accessor->set_callable(private_sym);
          private_accessor->set_args(value);
          return private_accessor;
        } else {
          return private_sym;
        }
      }
    }
      break;

    case Token::JS_PARAMETER_REST : {
      token = Seek();
      if (token->type() == Token::JS_IDENTIFIER) {
        AstNode* value = ParseLiteral(false);
        CHECK_ERROR(value);
        value->CastToLiteral()->set_value_type(Literal::kRest);
        return value;
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                     << TokenConverter(token).cstr()
                     << " in 'formal parameter rest' expect 'identifier'\\nin file "
                     << filename_ << " at line " << token->line_number());
        END(FormalParameterErrror);
      }
    }
      break;
      
    case Token::JS_TRUE :
      value_type = Literal::kTrue;
      is_invalid_lhs = true;
      break;

    case Token::JS_FALSE :
      value_type = Literal::kFalse;
      is_invalid_lhs = true;
      break;

    case Token::JS_NUMERIC_LITERAL :
      value_type = Literal::kNumeric;
      is_invalid_lhs = true;
      break;

    case Token::JS_STRING_LITERAL :
      value_type = Literal::kString;
      is_invalid_lhs = true;
      break;

    case Token::JS_REGEXP_LITERAL :
      value_type = Literal::kRegExp;
      is_invalid_lhs = true;
      break;

    case Token::JS_K_NULL :
      value_type = Literal::kNull;
      is_invalid_lhs = true;
      break;

    default : {
      if (reserved_usablity && JsToken::IsReserved(token->token())) {
        value_type = Literal::kIdentifier;
        is_invalid_lhs = true;
      } else {
        SYNTAX_ERROR("parse error got unexpected token '"
                     << TokenConverter(token).cstr()
                     << "' expect " << literals << "\\nin file "
                     << filename_ << " at line " << token->line_number());
        END(LiteralError);
        return new(pool()) Empty;
      }
    }
  }
  Literal* value = new(pool()) Literal(value_type, token->line_number());
  value->set_value(token);
  if (is_invalid_lhs) {
    value->MarkAsInValidLhs();
  }
  END(Literal);
  return value;
}


bool IsValidFormalParameter(int type) {
  return type == Token::JS_IDENTIFIER || type == '{' || type == '[' || type == Token::JS_THIS || type == Token::JS_PRIVATE;
}


AstNode* Parser::ParseFunctionDecl(bool is_const) {
  ENTER(FunctionDecl);
  TokenInfo* token = Seek();
  Function* fn = new(pool()) Function(token->line_number());
  if (token->type() == Token::JS_IDENTIFIER) {
    AstNode* name = ParseLiteral(false);
    CHECK_ERROR(name);
    fn->set_name(name);
    token = Seek();
  } else {
    fn->set_name(new(pool()) Empty);
  }
                                
  if (token->type() == '(') {
    Advance();
    token = Seek();
    if (token->type() != ')') {
      AstNode* list = ParseFormalParameter();
      fn->set_argv(list);
      token = Advance(2);
    } else {
      fn->set_argv(new(pool()) Empty);
      token = Advance(2);
    }
  } else {
    fn->set_argv(new(pool()) Empty);
    token = Seek();
    if (token->type() == Token::JS_FUNCTION_GLYPH ||
         token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      Advance();
    }
  }

  if (token->type() == Token::JS_FUNCTION_GLYPH ||
       token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    if (token->type() == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
      fn->set_context_type(Function::kThis);
    }
    token = Seek();
    if (token->type() == '{') {
      Advance();
      state_stack_->Push(StateStack::kFunction);
      bool has_return = bits_.At(RETURN_FLG);
      bool has_yield = bits_.At(YIELD_FLG);
      bits_.UnSet(RETURN_FLG);
      bits_.UnSet(YIELD_FLG);
      AstNode* body = ParseStatementList(BlockBodyMatcher, "}");
      CHECK_ERROR(body);
      builder()->FindDirectivePrologue(body, fn);
      if (bits_.At(RETURN_FLG) && bits_.At(YIELD_FLG)) {
        SYNTAX_ERROR("return statement not allowed in 'generator function'\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(FunctionDeclError);
        return fn;
      }
      if (!has_return) {
        bits_.UnSet(RETURN_FLG);
      }
      if (!has_yield) {
        bits_.UnSet(YIELD_FLG);
      }
      state_stack_->Pop();
      CHECK_ERROR(body);
      fn->Append(body);
      Advance();
      return fn;
    } else {
      AstNode* node = ParseAssignmentExpression(false);
      CHECK_ERROR(node);
      fn->AddChild(node);
      fn->set_function_type(Function::kShorten);
      END(FunctionDecl);
      return fn;
    }
  } else {
    if (token->type() == '{') {
      state_stack_->Push(StateStack::kFunction);
      bool has_return = bits_.At(RETURN_FLG);
      bool has_yield = bits_.At(YIELD_FLG);
      bits_.UnSet(RETURN_FLG);
      bits_.UnSet(YIELD_FLG);
      AstNode* body = ParseStatementList(BlockBodyMatcher, "}");
      CHECK_ERROR(body);
      builder()->FindDirectivePrologue(body, fn);
      if (bits_.At(RETURN_FLG) && bits_.At(YIELD_FLG)) {
        SYNTAX_ERROR("return statement not allowed in 'generator function'\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(FunctionDeclError);
        return fn;
      }
      if (!has_return) {
        bits_.UnSet(RETURN_FLG);
      }
      if (!has_yield) {
        bits_.UnSet(YIELD_FLG);
      }
      state_stack_->Pop();
      CHECK_ERROR(body);
      Advance();
      fn->Append(body);
      END(FunctionDecl);
      return fn;
    } else {
      SYNTAX_ERROR("parse error got unexpected token "
                    << TokenConverter(token).cstr()
                    << " in 'function declaration' expect '{'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(FunctionDeclError);
      return fn;
    }
  }
}


AstNode* Parser::ParseFormalParameter() {
  ENTER(FormalParameter);
  TokenInfo* token = Seek();
  NodeList* list = new(pool()) NodeList;
  while (token->type() != ')' && !IsEnd(token->type())) {
    if (IsValidFormalParameter(token->type())) {
      AstNode* node;
      if(token->type() == '{' || token->type() == '['){
        node = ParseDestructuringLeftHandSide();
        CHECK_ERROR(node);
        token = Seek();
        if (token->type() == '=') {
          AstNode* exp = ParseAssignmentExpression(false);
          CHECK_ERROR(exp);
          AssignmentExp* assign = new(pool()) AssignmentExp('=', node, exp, token->line_number());
          node = assign;
        }
      } else {
        node = ParseAssignmentExpression(false);
        CHECK_ERROR(node);
      }
      CHECK_ERROR(node);
      list->AddChild(node);
      token = Seek();
      if (token->type() != ')' && token->type() != ',') {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'formal parameter' expect ')' or ','\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(FormalParameterError);
        return list;
      } else if (token->type() == ',') {
        Advance();
      } else if (token->type() == ')') {
        break;
      }
      token = Seek();
    } else if (token->type() == Token::JS_PARAMETER_REST) {
      Advance();
      token = Seek();
      if (token->type() == Token::JS_IDENTIFIER) {
        AstNode* value = ParseLiteral(false);
        CHECK_ERROR(value);
        value->CastToLiteral()->set_value_type(Literal::kRest);
        token = Seek();
        list->AddChild(value);
        if (token->type() != ')' && token->type() != ',') {
          SYNTAX_ERROR("parse error got unexpected token "
                        << TokenConverter(token).cstr()
                        << " in 'formal parameter rest' can not continue after any 'formal parameter'\\nin file "
                        << filename_ << " at line " << token->line_number());
          END(FormalParameterError);
          return list;
        } else if (token->type() == ')') {
          break;
        }
        token = Advance();
      } else {
        SYNTAX_ERROR("parse error got unexpected token "
                      << TokenConverter(token).cstr()
                      << " in 'formal parameter rest' expect 'identifier'\\nin file "
                      << filename_ << " at line " << token->line_number());
        END(FormalParameterErrror);
        return list;
      }
    }
  }
  if (IsEnd(token->type())) {
    SYNTAX_ERROR("parse error got unexpected token "
                  << TokenConverter(token).cstr()
                  << " in 'formal parameter' expect ')'\\nin file "
                  << filename_ << " at line " << token->line_number());
    END(FormalParameter);
    return list;
  }
  return list;
}


AstNode* Parser::ParseArrowFunctionExpression(AstNode* exp, int type) {
  ENTER(ArrowFunctionExpression);
  Function* fn = new(pool()) Function(Seek(-1)->line_number());
  if (type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    fn->set_context_type(Function::kThis);
  }
  NodeList* list = FormalParameterConvertor(exp);
  CHECK_ERROR(list);
  fn->set_argv(list);
  fn->set_name(new(pool()) Empty);
  END(ArrowFunctionExpression);
  return ParseArrowFunctionBody(fn);
}

AstNode* Parser::ParseArrowFunctionExpression(AstNode* member, AstNode* args, int type) {
  ENTER(ArrowFunctionExpression);
  Function* fn = new(pool()) Function(Seek(-1)->line_number());
  if (type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    fn->set_context_type(Function::kThis);
  }
  Literal* maybe_ident = member->CastToLiteral();
  if (!maybe_ident || maybe_ident->value_type() != Literal::kIdentifier) {
    SYNTAX_ERROR("parse error illegal function name "
                  "in 'arrow function expression' expect 'identifier'\\nin file"
                  << filename_ << " at line " << member->line_number());
    END(ArrowFunctionExpression);
    return fn;
  }
  fn->set_name(maybe_ident);
  NodeList* list = FormalParameterConvertor(args);
  CHECK_ERROR(list);
  fn->set_argv(list);
  END(ArrowFunctionExpression);
  return ParseArrowFunctionBody(fn);
}

AstNode* Parser::ParseArrowFunctionExpression(int type) {
  ENTER(ArrowFunctionExpression);
  Function* fn = new(pool()) Function(Seek(-1)->line_number());
  if (type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT) {
    fn->set_context_type(Function::kThis);
  }
  fn->set_argv(new(pool()) Empty);
  fn->set_name(new(pool()) Empty);
  END(ArrowFunctionExpression);
  return ParseArrowFunctionBody(fn);
}

AstNode* Parser::ParseArrowFunctionBody(Function* fn) {
  ENTER(ArrowFunctionBody);
  TokenInfo* token = Seek();
  if (token->type() == '{') {
    Advance();
    state_stack_->Push(StateStack::kFunction);
    bool has_return = bits_.At(RETURN_FLG);
    bool has_yield = bits_.At(YIELD_FLG);
    bits_.UnSet(RETURN_FLG);
    bits_.UnSet(YIELD_FLG);
    AstNode* list = ParseStatementList(BlockBodyMatcher, "}");
    CHECK_ERROR(list);
    builder()->FindDirectivePrologue(list, fn);
    if (bits_.At(RETURN_FLG) && bits_.At(YIELD_FLG)) {
      SYNTAX_ERROR("return statement not allowed in 'generator function'\\nin file "
                    << filename_ << " at line " << token->line_number());
      END(FunctionDeclError);
      return fn;
    }
    if (!has_return) {
      bits_.UnSet(RETURN_FLG);
    }
    if (!has_yield) {
      bits_.UnSet(YIELD_FLG);
    }
    state_stack_->Pop();
    CHECK_ERROR(list);
    fn->Append(list);
    Advance();
  } else {
    AstNode* node = ParseAssignmentExpression(false);
    CHECK_ERROR(node);
    fn->AddChild(node);
    fn->set_function_type(Function::kShorten);
  }
  END(ArrowFunctionBody);
  return fn;
}


AstNode* Parser::ParseArrayComprehensions() {
  ENTER(ArrayComprehensions);
  TokenInfo* token = Advance();
  NodeList *list = new(pool()) NodeList;
  while (token->type() == Token::JS_FOR) {
    AstNode* node = ParseForStatement(true);
    CHECK_ERROR(node);
    list->AddChild(node);
    token = Advance();
  }
  if (token->type() == Token::JS_IF) {
    AstNode* if_stmt = ParseIFStatement(true);
    CHECK_ERROR(if_stmt);
    list->AddChild(if_stmt);
  } else {
    Undo();
  }
  END(ArrayComprehensions);
  return list;
}
}
