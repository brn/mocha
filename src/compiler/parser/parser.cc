#include <assert.h>
#include <vector>
#include <sstream>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <compiler/utils/error_reporter.h>
#include <compiler/parser/parser.h>
#include <compiler/scanner/token_stream.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <utils/pool/managed_handle.h>

namespace mocha {

static const char use_strict[] = { "use strict" };
static const char literals[] = { "'identifier', 'String', 'Number', 'Boolean', 'this', 'RegExp'" };
#define RETURN_FLG 0
#define YIELD_FLG 1
//Shortcut for syntax error reporter.
#define SYNTAX_ERROR( msg ) {\
  std::stringstream st;      \
  st << msg;                 \
  reporter_->ReportSyntaxError( st.str().c_str() );     \
}

//Check error occured or not.
//If error occured, immediate return an argument value.
#define CHECK_ERROR(name) {\
  if ( reporter_->Error() ) {                   \
    return name;                                \
  }                                             \
}

//Debug flag.
//#define PARSER_DEBUG 1

//Print parser move to stderr.
#ifdef PARSER_DEBUG
#define ENTER(mode) fflush(stdout);indent_+=' ';fprintf( stdout , "%snext token = %s enter %s\n" , indent_.c_str(),static_cast<const char*>( TokenConverter( Seek_() ) ),#mode )
#define END(mode) fflush(stdout);fprintf( stdout , "%snext token = %s end %s\n" , indent_.c_str(),static_cast<const char*>( TokenConverter( Seek_() ) ),#mode );indent_.erase(0,1)
#else
#define ENTER(mode)
#define END(mode)
#endif

/**
 * @param {int} type
 * @returns bool
 * Check current token type is END_TOKEN or END_OF_INPUT.
 */
bool IsEnd( int type ) {
  return type == Token::END_TOKEN || type == Token::END_OF_INPUT;
}

/**
 * @param {int} type
 * @returns bool
 * Callback function for ParseStatementList_.
 * Match block like structure.
 */
bool BlockBodyMatcher( int type ) {
  return type != '}';
}

/**
 * @param {int} type
 * @returns bool
 * Callback function for ParseStatementList_.
 * Match case clause body.
 */
bool CaseBodyMatcher( int type ) {
  return type != '}' && type != Token::JS_CASE && type != Token::JS_DEFAULT;
}

/**
 * @param {int} type
 * @returns bool
 * Check the type is a valid object literal property name.
 */
bool IsValidPropertyName( int type ) {
  return type == Token::JS_IDENTIFIER ||
      type == Token::JS_STRING_LITERAL ||
      type == Token::JS_NUMERIC_LITERAL;
}

/**
 * @param {int} type
 * @returns bool
 * Check the type is a valid object literal member.
 */
bool IsValidProperty( int type ) {
  return type == ValueNode::kString ||
      type == ValueNode::kNumeric ||
      type == ValueNode::kIdentifier ||
      type == ValueNode::kProperty;
}

/**
 * @param {int} type
 * @returns bool
 * Rewrite the object literal and the array literal to a valid destructuring assignment.
 */
void DstaRewriter( AstNode *dst ) {
  //We treat destructuring assignment in formal parameter of arrow function expression
  //as an object literal or an array literal,
  //so that are need to rewrite to destructuring assignment.
  NodeIterator iterator = dst->ChildNodes();
  ValueNode* parent = dst->ParentNode()->CastToValue();
  while ( iterator.HasNext() ) {
    AstNode* node = iterator.Next();
    ValueNode* value = node->CastToValue();
    if ( value ) {
      int type = value->ValueType();
      if ( type == ValueNode::kArray ) {
        //array literal.
        value->ValueType( ValueNode::kDstArray );
        DstaRewriter( value->FirstChild() );
      } else if ( type == ValueNode::kObject ) {
        //object literal.
        value->ValueType( ValueNode::kDst );
        AstNode* target = value->Node();
        DstaRewriter( target );
      } else if ( parent && IsValidProperty( type ) && parent->ValueType() == ValueNode::kDst ) {
        //object literal property name.
        //like { foo : bar } or { foo : { foo : bar } }
        DstaRewriter( value );
      }
    }
  }
}


/**
 * @param {AstNode} args
 * @param {AstNode} list
 * Arrow function expression with formal parameter is parsed as expression at first.
 * So we convert an arrow function expression's formal parameter list to a valid formal parameter list.
 */
void FormalParameterConvertor( AstNode *args , AstNode* list ) {
  NodeIterator iterator = args->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    ValueNode* maybe_dst_or_spread = item->CastToValue();
    //process ...rest parameter
    if ( maybe_dst_or_spread ) {
      int type = maybe_dst_or_spread->ValueType();
      //Array or Object literal is convert to destructuring assignment.
      if ( type == ValueNode::kObject || type == ValueNode::kArray ) {
        type = ( type == ValueNode::kArray )? ValueNode::kDstArray : ValueNode::kDst;
        AstNode* target = maybe_dst_or_spread->Node();
        maybe_dst_or_spread->ValueType( type );
        if ( !target ) {
          DstaRewriter( maybe_dst_or_spread->FirstChild() );
        } else {
          DstaRewriter( target );
        }
        ValueNode* dst = ValueNode::New( ValueNode::kDst );
        dst->Line( maybe_dst_or_spread->Line() );
        dst->Node( maybe_dst_or_spread );
        list->AddChild( dst );
        continue;
      } else if ( type == ValueNode::kSpread ) {
        //The spread convert to rest parameter.
        maybe_dst_or_spread->ValueType( ValueNode::kRest );
      } else if ( type == ValueNode::kDst ||
                  type == ValueNode::kDstArray ) {
        ValueNode* dst = ValueNode::New( ValueNode::kDst );
        dst->Line( item->Line() );
        dst->Node( item );
        item = dst;
      }
    } else if ( item->NodeType() == ValueNode::kAssignmentExp ) {
      //The assigment expression is convert to the default parameter.
      AssignmentExp* exp = item->CastToExpression()->CastToAssigment();
      AstNode* left = exp->Left();
      if ( left->CastToValue() ) {
        ValueNode* maybe_dst = left->CastToValue();
        if ( maybe_dst->ValueType() == ValueNode::kDst ||
             maybe_dst->ValueType() == ValueNode::kDstArray ) {
          ValueNode* dst = ValueNode::New( ValueNode::kDst );
          dst->Line( maybe_dst->Line() );
          dst->Node( maybe_dst );
          list->AddChild( dst );
          continue;
        }
      }
      left->AddChild( exp->Right() );
      item = left;
    }
    list->AddChild( item );
  }
}

void AssignmentDstaConvertor( AstNode* exp ) {
  ValueNode* dsta = exp->CastToValue();
  if ( dsta ) {
    int type = dsta->ValueType();
    if ( type == ValueNode::kObject || type == ValueNode::kArray ) {
      if ( type == ValueNode::kArray ) {
        dsta->ValueType( ValueNode::kDstArray );
        DstaRewriter( dsta->FirstChild() );
      } else {
        dsta->ValueType( ValueNode::kDst );
        DstaRewriter( dsta->Node() );
      }
    }
  }
}

class Parser::StateStack {
 public :
  typedef enum {
    kClassDecl,
    kParseBegin,
    kFinally,
    kFunction
  } ParserState;
  typedef std::vector<ParserState> StateArray;
  void Push( ParserState state ) { stack_.push_back( state ); }
  void Pop() { stack_.pop_back(); }
  bool Has( ParserState state ) {
    StateArray::iterator begin = stack_.begin();
    StateArray::iterator end = stack_.end();
    while ( begin != end ) {
      if ( state == (*begin) ) {
        return true;
      }
      ++begin;
    }
    return false;
  }
 private :
  StateArray stack_;
};

Parser::Parser( ParserConnector* connector , ErrorReporter* reporter , const char* filename )
    : filename_( filename ) , state_stack_( new StateStack ) , connector_( connector ) , reporter_( reporter ) {}
Parser::~Parser() {}


//The entrance for parser.
//We return the FileRoot node not AstRoot.
FileRoot* Parser::Parse() {
  FileRoot* root = FileRoot::New();
  root->FileName( filename_ );
  root->Append( ParseProgram() );
  AstUtils::FindDirectivePrologue( root , root );
  return root;
}

//Report illegal end of input.
void Parser::IllegalEnd( const char* expect , long line ) {
  SYNTAX_ERROR( "parse error got unexpected end of input expect "
                << expect << "\\nin file " << filename_ << " at line " << line );
}


void Parser::ParseTerminator() {
  TokenInfo *token = Seek();
  int type = token->GetType();
  if ( type == ';' || type == '}' || IsEnd( type ) || token->HasLineBreakBefore() ) {
    if ( type == ';' ) {
      Advance();
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " expect ';' or 'line break'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
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
  assert( state_stack_->Has( StateStack::kParseBegin ) == false );
  state_stack_->Push( StateStack::kParseBegin );
  TokenInfo* type;
  NodeList* list = NodeList::New();
  while ( ( type = Seek() ) && type != 0 && ( type->GetType() != Token::END_TOKEN || type->GetType() != Token::END_OF_INPUT ) ) {
    AstNode* statement = ParseSourceElement();
    if ( !statement->IsEmpty() ) {
      list->AddChild( statement );
    }
    if ( reporter_->Error() ) {
      return list;
    }
  }
  END(SourceElements);
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
  if ( info == 0 || info->GetType() == Token::END_TOKEN || info->GetType() == Token::END_OF_INPUT ) {
    return Empty::New();
  }
  switch ( info->GetType() ) {
    case Token::JS_CLASS :{
      result = ParseClassDecl( false );
      ExpressionStmt* stmt = ExpressionStmt::New();
      stmt->AddChild( result );
      result = stmt;
    }
      break;
      
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl( false );
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      fn->Decl();
    }
      break;

      //Now the const decaration is parsable, but not create block scope,
      //because block scoping overhead are heavy for the current javascript.
    case Token::JS_CONST : {
      info = Seek();
      int type = info->GetType();
      //check syntax for const class decl.
      if ( type == Token::JS_CLASS ) {
        Advance();
        result = ParseClassDecl( true );
        CHECK_ERROR( result );
      } else {
        TokenInfo* function_signature = Seek( 2 );
        int type = function_signature->GetType();
        //check syntax for const function.
        if ( type == '(' || type == Token::JS_FUNCTION_GLYPH ||
             type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
          result = ParseFunctionDecl( true );
          CHECK_ERROR(result);
          Function* fn = result->CastToExpression()->CastToFunction();
          fn->Decl();
        } else {
          result = ParseVariableStatement();
        }
      }
      break;
    }
      //Now the let statement is parsable, but not create block scope,
      //same reasons with above const declaration.
    case Token::JS_LET :
        result = ParseLetExpressionOrLetStatement();
        CHECK_ERROR( result );
        break;
        
    default :
      Undo();
      result = ParseStatement();
      CHECK_ERROR( result );
  }
  END(SourceElement);
  return result;
}

//Parse the statement list,
//like the block statement body or the function body.
AstNode* Parser::ParseStatementList( StatementListMatcher matcher , const char* expect ) {
  /**
   * [bison/yacc compat syntax]
   * statement_list
   * : statement
   * | statement_list statement
   * ;
   */
  ENTER( StatementList );
  TokenInfo* token = Seek();
  int type = token->GetType();
  StatementList* list = StatementList::New();
  while ( matcher( type ) ) {
    AstNode* statement = ParseSourceElement();
    CHECK_ERROR( statement );
    list->AddChild( statement );
    token = Seek();
    type = token->GetType();
    if ( IsEnd( type ) ) {
      SYNTAX_ERROR( "parse error unexpected end of input expect "
                    << expect
                    << " in file " << filename_ << " at line " << token->GetLineNumber() );
      return list;
    }
  }
  END( StatementList );
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
  TokenInfo* info = Advance();
  AstNode* result;
  switch ( info->GetType() ) {
    case '{' :
      result = ParseBlockStatement();
      break;
      
    case Token::JS_MODULE :
      result = ParseModuleStatement();
      break;
      
    case Token::JS_EXPORT :
      result = ParseExportStatement();
      break;

      //The let and const variable statement is not create block scope.
    case Token::JS_VAR :
    case Token::JS_LET :
    case Token::JS_CONST :
      result = ParseVariableStatement();
      break;
      
    case ';' :
      result = Empty::New();
      break;
      
    case Token::JS_IF :
      result = ParseIFStatement( false );
      break;
      
    case Token::JS_FOR :
      result = ParseForStatement( false );
      break;
      
    case Token::JS_WHILE :
      result = ParseWhileStatement();
      break;
      
    case Token::JS_DO :
      result = ParseDoWhileStatement( false );
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

      //a mocha special keyword not harmony.
    case Token::MOCHA_VERSIONOF :
      result = ParseVersionStatement();
      break;
      
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl( false );
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      fn->Decl();
    }
      break;
      
    case Token::JS_DEBUGGER :
      result = ParseDebuggerStatement( info );
      break;

      //The exportable definition is only acceptable in class declaration,
      //but private accessor is allowed in any place.
    case Token::JS_PRIVATE :
    case Token::JS_PUBLIC :
    case Token::JS_STATIC : {
      TokenInfo *token = Seek();
      int type = token->GetType();
      if ( type == '.' || type == '[' ) {
        //private accessor.
        result = CheckLabellOrExpressionStatement();
      } else {
        result = ParseClassMemberStatement();
      }
    }
      break;
      
    default : {
      int type = info->GetType();
      if ( type == Token::JS_IDENTIFIER ) {
        TokenInfo* token = Seek( 2 );
        type = token->GetType();
        //Check trait declaration.
        //The trait keyword is not treated as the reserved word.
        if ( strcmp( info->GetToken() , SymbolList::GetSymbol( SymbolList::kTrait ) ) == 0 && type == '{' ) {
          result = ParseTrait();
          CHECK_ERROR( result );
          result->CastToExpression()->CastToTrait()->Decl();
          break;
        }
      }
      result = CheckLabellOrExpressionStatement();
      CHECK_ERROR(result);
      //If shorten function expression is parsed as expression,
      //we mark as function declaration.
      if ( result->NodeType() == AstNode::kExpressionStmt ) {
        Expression* exp = result->FirstChild()->CastToExpression();
        if ( !exp->IsParen() && exp->ChildLength() == 1 ) {
          AstNode* item = exp->FirstChild();
          if ( item->NodeType() == AstNode::kFunction ) {
            item->CastToExpression()->CastToFunction()->Decl();
            result = item;
          }
        } else if ( !exp->IsParen() && exp->ChildLength() > 1 ) {
          if ( exp->FirstChild()->NodeType() == AstNode::kFunction ) {
            SYNTAX_ERROR( "illegal trailing comma after function declaration.\\nIn file"
                          << filename_ << " at line " << exp->Line() );
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
  BlockStmt* block = BlockStmt::New();
  StatementList* list = StatementList::New();
  TokenInfo* info = Seek();
  int type = info->GetType();
  //Check block statement has body or not.
  //If block body is empty -> {}, set Empty node to block body.
  if ( type != '}' ) {
    while ( 1 ) {
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR( statement );
      list->AddChild( statement );
      info = Seek();
      type = info->GetType();
      if ( type == '}' ) {
        Advance();
        break;
      } else if ( IsEnd( type ) ) {
        IllegalEnd( "'}'" , info->GetLineNumber() );
        END(BlockStatementError);
        return block;
      }
    }
    block->AddChild( list );
  } else {
    Advance();
    block->AddChild( Empty::New() );
  }
  END(BlockStatement);
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
  ModuleStmt* module_stmt = ModuleStmt::New();
  TokenInfo* info = Seek();
  int type = info->GetType();
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* name = ParseLiteral();
    CHECK_ERROR(module_stmt);
    module_stmt->Name( name );
  } else {
    module_stmt->Name( Empty::New() );
  }
  AstNode* statement = ParseSourceElement();
  module_stmt->Line( info->GetLineNumber() );
  module_stmt->AddChild( statement );
  END(ModuleStatement);
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
  ExportStmt* export_stmt = ExportStmt::New();
  AstNode* exportable = ParseExportableDefinition();
  CHECK_ERROR( export_stmt );
  export_stmt->Line( exportable->Line() );
  export_stmt->AddChild( exportable );
  END(ExportStatement);
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
  TokenInfo* val = Seek();
  int type;
  AstNode* exp;
  if ( val->GetType() == Token::JS_IDENTIFIER ) {
    exp = ParseLiteral();
    CHECK_ERROR( exp );
    type = ImportStmt::kVar;
  } else if ( val->GetType() == '{' || val->GetType() == '[' ) {
    //import statement allow destructuring assignment.
    exp = ParseDestructuringLeftHandSide();
    CHECK_ERROR( exp );
    type = ImportStmt::kDst;
  }
  TokenInfo* r_from = Advance();
  TokenConverter cnv( r_from );
  const char* ident = static_cast<const char*>( cnv );
  //from keyword is not treated as the reserved word,
  //so we check that an identifier is the valid from keyword or not.
  if ( r_from->GetType() == Token::JS_IDENTIFIER &&
       strlen( ident ) > 0 &&
       strcmp( ident , SymbolList::GetSymbol( SymbolList::kFrom ) ) == 0 ) {
    AstNode* from_exp = ParseImportExpression();
    CHECK_ERROR( from_exp );
    ValueNode* maybe_file = from_exp->FirstChild()->CastToValue();
    int from_type;
    //The import statement could accept the filename or the module name.
    if ( maybe_file && maybe_file->ValueType() == ValueNode::kString ) {
      from_type = ImportStmt::kFile;
    } else {
      from_type = ImportStmt::kModule;
    }
    ImportStmt* stmt = ImportStmt::New( type , from_type );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    stmt->From( from_exp );
    ParseTerminator();
    CHECK_ERROR( stmt );
    END(ImportStatement);
    return stmt;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( r_from )
                  << " after 'import' expect 'from'\\nin file "
                  << filename_ << " at line " << r_from->GetLineNumber() );
    END(ImportStatementError);
    return Empty::New();
  }
}

//Parse import expression.
//import ... from <here>
AstNode* Parser::ParseImportExpression() {
  ENTER(ImportExpression);
  TokenInfo* token = Seek();
  int type = token->GetType();
  NodeList* list = NodeList::New();
  //In case of filename.
  if ( type == Token::JS_STRING_LITERAL ) {
    AstNode* literal = ParseLiteral();
    CHECK_ERROR(literal);
    list->AddChild( literal );
  } else if ( type == Token::JS_IDENTIFIER ) {
    //In case of module name.
    AstNode* literal = ParseLiteral();
    CHECK_ERROR( literal );
    list->AddChild( literal );
  }
  token = Seek();
  type = token->GetType();
  while ( 1 ) {
    if ( type == '.' || type == '[' ) {
      AstNode* literal = ParseLiteral();
      CHECK_ERROR(literal);
      list->AddChild( literal );
      token = Seek();
      type = token->GetType();
    } else {
      break;
    }
  }
  END(ImportExpression);
  return list;
}

//Parse debugger statement.
AstNode* Parser::ParseDebuggerStatement( TokenInfo* token ) {
  ENTER(DebuggerStatement);
  ValueNode* value = ValueNode::New( ValueNode::kIdentifier );
  value->Symbol( token );
  Expression* exp = Expression::New();
  ExpressionStmt* stmt = ExpressionStmt::New();
  stmt->AddChild( exp );
  exp->AddChild( value );
  END(DebuggerStatement);
  return stmt;
}

//Parse version statement
AstNode* Parser::ParseVersionStatement() {
  /**
   * [bison/yacc compat syntax]
   * version_statement
   * : MOCHA_VERSIONOF '(' JS_IDENTIFIER ')' block_statement
   * ;
   */
  ENTER(VersionStatement);
  TokenInfo* token = Advance();
  int type = token->GetType();
  if ( type == '(' ) {
    token = Advance();
    type = token->GetType();
    if ( type == Token::JS_IDENTIFIER ) {
      VersionStmt* stmt = VersionStmt::New( token );
      token = Advance();
      type = token->GetType();
      if ( type == ')' ) {
        stmt->Line( token->GetLineNumber() );
        token = Seek();
        type = token->GetType();
        if ( type == '{' ) {
          Advance();
          AstNode* statement = ParseStatementList( BlockBodyMatcher , "}" );
          CHECK_ERROR( stmt );
          stmt->AddChild( statement );
          Advance();
          END(VersionStatement);
          return stmt;
        } else {
          AstNode* statement = ParseStatement();
          CHECK_ERROR( stmt );
          stmt->AddChild( statement );
          END(VersionStatement);
          return stmt;
        }
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'version statement' expect 'identifier' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(VersionStatementError);
      return Empty::New();
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'version statement' expect ')' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(VersionStatementError);
    return Empty::New();
  }
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
  int type = token->GetType();
  long line = token->GetLineNumber();
  if ( type == '(' ) {
    token = Advance();
    type = token->GetType();
    AstNode* expect = ParseAssignmentExpression( false );
    CHECK_ERROR( expect );
    token = Advance();
    type = token->GetType();
    if ( type == ',' ) {
      AstNode* exp = ParseAssignmentExpression( false );
      token = Advance();
      type = token->GetType();
      if ( type == ')' ) {
        ParseTerminator();
        CHECK_ERROR( exp );
        AssertStmt* stmt = AssertStmt::New();
        stmt->Line( line );
        stmt->AddChild( expect );
        stmt->AddChild( exp );
        return stmt;
      } else {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " 'in assert statement' expect ')'\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(AssertStatementError);
        return expect;
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " 'in assert statement', second arguments must be a 'expression'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
      END(AssertStatementError);
      return expect;
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " 'in assert statement' expect '('\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(AssertStatementError);
    return Empty::New();
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
  TokenInfo* token = Seek( -1 );
  VariableStmt* stmt = VariableStmt::New();
  stmt->Line( token->GetLineNumber() );
  AstNode* list = ParseVariableDecl( false );
  CHECK_ERROR(stmt);
  token = Seek();
  int type = token->GetType();
  if ( type == ';' ) {
    Advance();
  }
  stmt->Append( list );
  END(VariableStatement);
  return stmt;
}

//Parse variable declaration.
AstNode* Parser::ParseVariableDecl( bool is_noin ) {
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
  TokenInfo* maybe_assign_op = Seek( 2 );
  int type = maybe_assign_op->GetType();
  NodeList* list = NodeList::New();
  TokenInfo* next = Seek();
  int next_type = next->GetType();
  //Get all declarations.
  //Like var x , y = 200 , z;
  while ( 1 ) {
    AstNode* var_left_hand;
    bool is_destructuring = false;
    if ( next_type == '{' || next_type == '[' ) {
      //Treat harmony destructuring.
      var_left_hand = ParseDestructuringLeftHandSide();
      ValueNode* value = ValueNode::New( ValueNode::kDst );
      value->Node( var_left_hand );
      value->Line( var_left_hand->Line() );
      var_left_hand = value;
      CHECK_ERROR( list );
      is_destructuring = true;
      maybe_assign_op = Seek();
      type = maybe_assign_op->GetType();
    } else if ( next_type == Token::JS_IDENTIFIER ) {
      //Normal idneifier.
      var_left_hand = ParseLiteral();
      CHECK_ERROR( var_left_hand );
      var_left_hand->CastToValue()->ValueType( ValueNode::kVariable );
      CHECK_ERROR( list );
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( next )
                    << " in 'variable statement' expect 'variable name' or 'destructuring assignment'\\nin file "
                    << filename_ << " at line " << next->GetLineNumber() );
      END(VariableDeclError);
      return Empty::New();
    }
    /*
     * We check result of Seek( 2 ) is assignment operator or not.
     * If that is assignment operator, we treat next token list as expression,
     * if not, that is treated as just declaration.
     */
    if ( maybe_assign_op->GetType() == '=' ) {
      Advance();
      AstNode* assignment_exp = ParseAssignmentExpression( is_noin );
      CHECK_ERROR( list );
      var_left_hand->AddChild( assignment_exp );
      list->AddChild( var_left_hand );
    } else {
      var_left_hand->AddChild( Empty::New() );
      list->AddChild( var_left_hand );
    }
    next = Seek();
    next_type = next->GetType();
    /*
     * If next token type is semicolon or line break, declarations are end,
     * if next token type is comma, declaration is continue after,
     * if not, it's error.
     */
    if ( next_type != ',' ) {
      break;
    } else {
      Advance();
    }
    maybe_assign_op = Seek( 2 );
    next = Seek();
    next_type = next->GetType();
  }
  END(VariableDecl);
  return list;
}


AstNode* Parser::ParseLetExpressionOrLetStatement() {
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == '(' ) {
    Advance();
    AstNode* exp_list = ParseLetExpressionExp();
    CHECK_ERROR( exp_list );
    Advance();
    token = Seek();
    type = token->GetType();
    Function* fn = Function::New();
    fn->Name( Empty::New() );
    AstNode* list = exp_list->FirstChild();
    AstNode* args = list->NextSibling();
    NodeList* valid_formal = NodeList::New();
    FormalParameterConvertor( list , valid_formal );
    fn->Argv( valid_formal );
    if ( type == '{' ) {
      Advance();
      AstNode* node = ParseStatementList( BlockBodyMatcher , "'}'" );
      Advance();
      CHECK_ERROR( node );
      fn->Append( node );
    } else {
      AstNode* node = ParseSourceElement();
      CHECK_ERROR( node );
      fn->AddChild( node );
    }
    ValueNode* call_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCall ),
                                                    Token::JS_PROPERTY , token->GetLineNumber() , ValueNode::kProperty );
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_THIS , token->GetLineNumber() , ValueNode::kThis );
    Expression* fn_exp = Expression::New();
    fn_exp->AddChild( fn );
    fn_exp->Paren();
    args->InsertBefore( this_sym );
    CallExp* dot_accessor = AstUtils::CreateDotAccessor( fn_exp , call_sym );
    return AstUtils::CreateExpStmt( AstUtils::CreateNormalAccessor( dot_accessor , args ) );
  } else {
    return ParseVariableStatement();
  }
}


AstNode* Parser::ParseLetExpressionExp() {
  TokenInfo* token = Seek();
  int type = token->GetType();
  NodeList* list = NodeList::New();
  NodeList* args = NodeList::New();
  while ( 1 ) {
    AstNode* node = ParseAssignmentExpression( false );
    CHECK_ERROR( node );
    AssignmentExp *assign = node->CastToExpression()->CastToAssigment();
    if ( assign ) {
      list->AddChild( assign->Left() );
      args->AddChild( assign->Right() );
    } else {
      list->AddChild( node );
      args->AddChild( AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                Token::JS_IDENTIFIER , token->GetLineNumber() , ValueNode::kIdentifier ) );
    }
    token = Seek();
    type = token->GetType();
    if ( type != ',' ) {
      break;
    }
    Advance();
    token = Seek();
    type = token->GetType();
  }
  return AstUtils::CreateNodeList( 2 , list , args );
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
  int type = token->GetType();
  if ( type == '[' ) {
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
  int type = token->GetType();
  ValueNode* destructuring = ValueNode::New( ValueNode::kDstArray );
  destructuring->Line( token->GetLineNumber() );
  NodeList* list = NodeList::New();
  while ( 1 ) {
    //Check bracket count.
    if ( type == '[' || type == '{' ) {
      AstNode* elem = ParseDestructuringLeftHandSide();
      CHECK_ERROR(list);
      list->AddChild( elem );
      token = Seek();
      type = token->GetType();
      if ( type == ',' ) {
        Advance();
      }
    } else if ( type == ']' ) {
      Advance();
      break;
    } else {
      if ( type == ',' ) {
        list->AddChild( Empty::New() );
        Advance();
        token = Seek();
        type = token->GetType();
        if ( type == ']' ) {
          list->AddChild( Empty::New() );
          Advance();
          break;
        }
      } else if ( type == Token::JS_IDENTIFIER ) {
        AstNode* value = ParseLiteral();
        CHECK_ERROR( list );
        list->AddChild( value );
        token = Seek();
        type = token->GetType();
        if ( type == ',' ) {
          Advance();
        }
      } else if ( type == Token::JS_PARAMETER_REST ) {
        token = Advance( 2 );
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          ValueNode* rest = ValueNode::New( ValueNode::kRest );
          rest->Symbol( token );
          rest->Line( token->GetLineNumber() );
          list->AddChild( rest );
        } else {
          SYNTAX_ERROR( "parse error got undexpected token "
                        << TokenConverter( token )
                        << ". In 'destructuring assignment parameter rest expect 'identifier'\\nin file "
                        << filename_ << " at line "
                        << token->GetLineNumber() );
          break;
        }
      } else {
        //In destructuring assignemtn, if array pattern used,
        //it's element is only allowed JS_IDENTIFIER or JS_REST.
        SYNTAX_ERROR( "parse error got undexpected token "
                      << TokenConverter( token )
                      << ". In 'destructuring assignment array pattern' "
                      "element is only allowed 'identifier' or 'parameter rest'.\\nin file '"
                      << filename_ << " at line "
                      << token->GetLineNumber() );
        break;
      }
    }
    token = Seek();
    type = token->GetType();
  }
  destructuring->AddChild( list );
  END(ArrayPattern);
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
  int type = token->GetType();
  int maybe_colon = Seek( 2 )->GetType();
  ValueNode* destructuring = ValueNode::New( ValueNode::kDst );
  destructuring->Line( token->GetLineNumber() );
  NodeList* list = NodeList::New();
  while ( 1 ) {
    if ( maybe_colon == '}' ) {
      ParseObjectPatternElement( type , token , list );
      Advance();
      break;
    } else if ( maybe_colon == ',' ) {
      ParseObjectPatternElement( type , token , list );
      Advance();
    } else if ( maybe_colon == ':' ) {
      AstNode* node = ParseLiteral();
      Advance();
      token = Seek();
      type = token->GetType();
      if ( type == '[' || type == '{' ) {
        AstNode* elem = ParseDestructuringLeftHandSide();
        CHECK_ERROR( elem );
        node->AddChild( elem );
      } else {
        ParseObjectPatternElement( type , token , node );
      }
      CHECK_ERROR( list );
      list->AddChild( node );
      token = Advance();
      type = token->GetType();
      if ( type == '}' ) {
        break;
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << ". In 'destructuring assignment object pattern'"
                    " member only allowed normal '{ property_name : idenfier }' or '{ identifier }'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
    token = Seek();
    type = token->GetType();
    maybe_colon = Seek( 2 )->GetType();
  }
  destructuring->Node( list );
  END(ObjectPattern);
  return destructuring;
}

//Parse destructuring assignment object patter's each element.
AstNode* Parser::ParseObjectPatternElement( int type , TokenInfo* token , AstNode* list ) {
  ENTER(ObjectPatternElement);
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* node = ParseLiteral();
    CHECK_ERROR( node );
    list->AddChild( node );
    END(ObjectPatternElement);
    return node;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << ". In 'destructuring assignment object pattern'"
                  " member only allowed normal '{ property_name : idenfier }' or '{ identifier }'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(ObjectPatternElementError);
    return Empty::New();
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
  int type = token->GetType();
  Undo();
  //In case of labelled statement.
  if ( type == ':' ) {
    AstNode* stmt = ParseLabelledStatement();
    CHECK_ERROR(stmt);
    stmt->Line( token->GetLineNumber() );
    END(LabellOrExpressionStatement);
    return stmt;
  } else {
    AstNode* ret = ParseExpression( false );
    CHECK_ERROR( ret );
    ret->Line( token->GetLineNumber() );
    ParseTerminator();
    CHECK_ERROR( ret );
    ExpressionStmt* stmt = ExpressionStmt::New();
    stmt->AddChild( ret );
    END(LabellOrExpressionStatement);
    return stmt;
  }
}

//Parse if statement
AstNode* Parser::ParseIFStatement( bool is_comprehensions ) {
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
  int type = token->GetType();
  IFStmt* if_stmt = IFStmt::New();
  if_stmt->Line( token->GetLineNumber() );
  if ( type == '(' ) {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR( if_stmt );
    if_stmt->Exp( exp );
    token = Advance();
    type = token->GetType();
    if ( type == ')' ) {
      if ( !is_comprehensions ) {
        AstNode* stmt = ParseSourceElement();
        CHECK_ERROR( stmt );
        if_stmt->Then( stmt );
        token = Seek();
        type = token->GetType();
        if ( type == Token::JS_ELSE ) {
          Advance();
          AstNode* stmt = ParseSourceElement();
          CHECK_ERROR( stmt )
          if_stmt->Else( stmt );
        } else {
          if_stmt->Else( Empty::New() );
        }
      } else {
        if_stmt->Then( Empty::New() );
        if_stmt->Else( Empty::New() );
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'if statement conditional expression end' expect ')' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(IFStatementError);
      return if_stmt;
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'if statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(IFStatementError);
    return if_stmt;
  }
  END(IFStatement);
  return if_stmt;
}

//Parse do while statement.
AstNode* Parser::ParseDoWhileStatement( bool is_expression ) {
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
  long line = Seek( -1 )->GetLineNumber();
  AstNode* statement = ParseSourceElement();
  CHECK_ERROR( statement );
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == Token::JS_WHILE && !is_expression ) {
    TokenInfo* token = Advance( 2 );
    int type = token->GetType();
    if ( type == '(' ) {
      AstNode* node = ParseExpression( false );
      CHECK_ERROR( statement );
      token = Advance();
      type = token->GetType();
      if ( type == ')' ) {
        IterationStmt* iter = IterationStmt::New( IterationStmt::kDoWhile );
        iter->Line( line );
        iter->Exp( node );
        iter->AddChild( statement );
        END(DoWhileStatement);
        return iter;
      } else {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'while statement conditional expression' expect ')' \\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(DoWhileStatementError);
        return IterationStmt::New( IterationStmt::kWhile );
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'do while statement conditional expression' expect '(' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(DoWhileStatementError);
      return IterationStmt::New( IterationStmt::kWhile );
    }
  } else {
    //do expression.
    token = Seek();
    Function* fn = Function::New();
    fn->Name( Empty::New() );
    if ( statement->NodeType() == AstNode::kBlockStmt ) {
      fn->Append( statement->FirstChild() );
    } else {
      fn->AddChild( statement );
    }
    AstNode* node = fn->LastChild();
    if ( node->CastToExpression() || node->NodeType() == AstNode::kExpressionStmt ) {
      ReturnStmt* stmt = 0;//init after
      if ( node->NodeType() == AstNode::kExpressionStmt ) {
        stmt = AstUtils::CreateReturnStmt( node->FirstChild() );
      } else {
        stmt = AstUtils::CreateReturnStmt( node );
      }
      fn->ReplaceChild( node , stmt );
    }
    fn->Argv( Empty::New() );
    ExpressionStmt* ret_stmt = AstUtils::CreateAnonymousFnCall( fn , Empty::New() );
    return ( is_expression )? ret_stmt->FirstChild() : ret_stmt;
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
  int type = token->GetType();
  long line = token->GetLineNumber();
  if ( type == '(' ) {
    AstNode* node = ParseExpression( false );
    CHECK_ERROR( node );
    token = Advance();
    type = token->GetType();
    if ( type == ')' ) {
      IterationStmt* iter = IterationStmt::New( IterationStmt::kWhile );
      iter->Line( line );
      iter->Exp( node );
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR( iter );
      iter->AddChild( statement );
      END(WhileStatement);
      return iter;
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'while statement conditional expression' expect ')' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(WhileStatementError);
      return IterationStmt::New( IterationStmt::kWhile );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'while statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(WhileStatementError);
    return IterationStmt::New( IterationStmt::kWhile );
  }
}


//Parse for statement
//In this method, the for statement includes for_in_statement,
//for_of_statement and array_comprehensions_iteration.
AstNode* Parser::ParseForStatement( bool is_comprehensions ) {
  /**
   * [bison/yacc compat syntax]
   * iteration_statement
   * : JS_FOR '(' JS_VAR variable_declaration_list_no_in ';' expression__opt ';' expression__opt ) statement
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
  int type = token->GetType();
  long line = token->GetLineNumber();
  bool is_each = false;
  NodeList *exp_list = NodeList::New();
  IterationStmt* iter_stmt = 0;
  if ( type == Token::JS_EACH ) {
    is_each = true;
    token = Advance();
    type = token->GetType();
  }
  if ( type == '(' ) {
    int next_type = Seek()->GetType();
    bool is_var_decl = false;
    int var_decl_len = 0;
    if ( next_type == Token::JS_VAR ) {
      is_var_decl = true;
      //The array comprehension for expression could not have variable declaration.
      if ( is_comprehensions ) {
        SYNTAX_ERROR( "parse error in 'array comprehensions for expression' could not has variable declaration"
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return IterationStmt::New( IterationStmt::kFor );
      } else {
        Advance();
        AstNode* var_decl = ParseVariableDecl( true );
        CHECK_ERROR( var_decl );
        exp_list->AddChild( var_decl );
        var_decl_len = var_decl->ChildLength();
      }
    } else if ( next_type != ';' ) {
      AstNode* exp = ParseExpression( true );
      CHECK_ERROR( exp );
      if ( exp->FirstChild()->NodeType() == AstNode::kValueNode && is_comprehensions ) {
        AstNode* first = exp->FirstChild();
        if ( first->ChildLength() == 0 ) {
          first->AddChild( Empty::New() );
        }
        first->CastToValue()->ValueType( ValueNode::kVariable );
        exp_list->AddChild( first );
      } else {
        //Empty first for statement condition expression.
        exp_list->AddChild( exp );
      }
    } else {
      exp_list->AddChild( Empty::New() );
    }
    token = Advance();
    type = token->GetType();
    if ( next_type == ';' || ( type == ';' && is_each == false ) ) {
      //In case of normal for statement.
      if ( is_comprehensions ) {
        SYNTAX_ERROR( "parse error in 'array comprehensions' allowed 'for in statement' or 'for of statement'"
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return IterationStmt::New( IterationStmt::kFor );
      }
      int iter_type = ( is_var_decl )? IterationStmt::kForWithVar : IterationStmt::kFor;
      iter_stmt = IterationStmt::New( iter_type );
      iter_stmt->Line( line );
      ParseForStatementCondition( exp_list );
      CHECK_ERROR( iter_stmt );
    } else if ( type == Token::JS_IN ) {
      //In case of for in statement.
      if ( var_decl_len > 1 ) {
        SYNTAX_ERROR( "parse error 'for in statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return IterationStmt::New( IterationStmt::kFor );
      }
      if ( is_var_decl ) {
        AstNode* initialiser = exp_list->FirstChild()->FirstChild();
        exp_list->ReplaceChild( exp_list->FirstChild() , initialiser );
      }
      if ( is_each == false ) {
        int iter_type = ( is_var_decl || is_comprehensions )? IterationStmt::kForInWithVar : IterationStmt::kForIn;
        iter_stmt = IterationStmt::New( iter_type );
        iter_stmt->Line( line );
      } else {
        int iter_type = ( is_var_decl || is_comprehensions )? IterationStmt::kForEachWithVar : IterationStmt::kForEach;
        iter_stmt = IterationStmt::New( iter_type );
        iter_stmt->Line( line );
      }
      ParseForInStatementCondition( exp_list );
      CHECK_ERROR( iter_stmt );
    } else if ( type == Token::JS_IDENTIFIER &&
                strcmp( TokenConverter( token ) , SymbolList::GetSymbol( SymbolList::kOf ) ) == 0 ) {
      //For of statement's 'of' keyword is treated as identifier not reserved word,
      //so we check token is valid 'of' identifier or not.
      if ( var_decl_len > 1 ) {
        SYNTAX_ERROR( "parse error 'for of statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return IterationStmt::New( IterationStmt::kFor );
      }
      if ( is_var_decl ) {
        AstNode* initialiser = exp_list->FirstChild()->FirstChild();
        exp_list->ReplaceChild( exp_list->FirstChild() , initialiser );
      }
      if ( is_each == false ) {
        int iter_type = ( is_var_decl || is_comprehensions )? IterationStmt::kForOfWithVar : IterationStmt::kForOf;
        iter_stmt = IterationStmt::New( iter_type );
        iter_stmt->Line( line );
      } else {
        SYNTAX_ERROR( "parse error 'for of statement' can not has 'each'."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return IterationStmt::New( IterationStmt::kFor );
      }
      ParseForInStatementCondition( exp_list );
      CHECK_ERROR( iter_stmt );
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'for statement conditional expression' expect 'in' , 'of' or ';' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(ForStatementError);
      return IterationStmt::New( IterationStmt::kFor );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'for statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(ForStatementError);
    return IterationStmt::New( IterationStmt::kFor );
  }
  if ( !is_comprehensions ) {
    AstNode* body = ParseSourceElement();
    CHECK_ERROR( iter_stmt );
    iter_stmt->AddChild( body );
  }
  iter_stmt->Exp( exp_list );
  END(ForStatement);
  return iter_stmt;
}


//Parse for statement condition expression.
void Parser::ParseForStatementCondition( NodeList* list ) {
  ENTER(ForStatementCondition);
  if ( Seek()->GetType() == ';' ) {
    list->AddChild( Empty::New() );
  } else {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR();
    list->AddChild( exp );
  }
  TokenInfo* token = Advance();
  int type = token->GetType();
  if ( type == ';' ) {
    if ( Seek()->GetType() == ')' ) {
      list->AddChild( Empty::New() );
    } else {
      AstNode* exp = ParseExpression( false );
      CHECK_ERROR()
      list->AddChild( exp );
    }
    token = Advance();
    type = token->GetType();
    if ( type != ')' ) {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'for statement condition end' expect ')' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
  }
  END(ForStatementCondition);
}


//Parse for in statement condition expression.
void Parser::ParseForInStatementCondition( NodeList* list ) {
  ENTER(ForInStatementCondition);
  AstNode* target_exp = ParseExpression( false );
  CHECK_ERROR();
  TokenInfo* token = Advance();
  int type = token->GetType();
  list->AddChild( target_exp );
  if ( type != ')' ) {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'for in statement condition end' expect ')' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
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
  int type = token->GetType();
  ContinueStmt* stmt = ContinueStmt::New();
  stmt->Line( Seek( -1 )->GetLineNumber() );
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* identifier = ParseLiteral();
    CHECK_ERROR( stmt );
    stmt->AddChild( identifier );
  }
  ParseTerminator();
  CHECK_ERROR( stmt );
  stmt->AddChild( Empty::New() );
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
  int type = token->GetType();
  BreakStmt* stmt = BreakStmt::New();
  stmt->Line( Seek( -1 )->GetLineNumber() );
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* identifier = ParseLiteral();
    CHECK_ERROR( stmt );
    stmt->AddChild( identifier );
  }
  ParseTerminator();
  CHECK_ERROR( stmt );
  stmt->AddChild( Empty::New() );
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
  if ( !state_stack_->Has( StateStack::kFunction ) ) {
    SYNTAX_ERROR( "return statement only allowed in 'function'\\nin file "
                  << filename_ << " at line " << Seek( -1 )->GetLineNumber() );
    END(ReturnStatement);
    return Empty::New();
  }
  bits_.Set( RETURN_FLG );
  TokenInfo *token = Seek();
  int type = token->GetType();
  ReturnStmt* stmt = ReturnStmt::New();
  stmt->Line( Seek( -1 )->GetLineNumber() );
  if ( type == ';' || type == '}' || token->HasLineBreakBefore() ) {
    stmt->AddChild( Empty::New() );
  } else {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR( stmt );
    stmt->AddChild( exp );
    ParseTerminator();
    CHECK_ERROR( exp );
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
  int type = token->GetType();
  WithStmt* stmt = WithStmt::New();
  stmt->Line( Seek( -1 )->GetLineNumber() );
  if ( type == '(' ) {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    token = Advance();
    type = token->GetType();
    if ( type == ')' ) {
      AstNode* statement = ParseSourceElement();
      CHECK_ERROR( stmt );
      stmt->AddChild( statement );
    } else {
      SYNTAX_ERROR( "parse error unmatched paren"
                    " in 'with statement expression'\\nin file"
                    << filename_ << " at line " << token->GetLineNumber() );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'with statement expression' expect '('\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
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
  int type = token->GetType();
  SwitchStmt* stmt = SwitchStmt::New();
  if ( type == '(' ) {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    token = Advance();
    type = token->GetType();
    if ( type == ')' ) {
      AstNode* case_block = ParseCaseClauses();
      CHECK_ERROR( stmt );
      stmt->AddChild( case_block );
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'switch statement expression' expect ')'\\nin file"
                    << filename_ << " at line " << token->GetLineNumber() );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'switch statement expression' expect '('\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
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
  int type = token->GetType();
  NodeList *list = NodeList::New();
  if ( type == '{' ) {
    while ( type != '}' ) {
      token = Advance();
      type = token->GetType();
      bool is_default = type == Token::JS_DEFAULT;
      if ( type == Token::JS_CASE || is_default ) {
        CaseClause* clause = 0;//init after.
        if ( !is_default ) {
          clause = CaseClause::New();
          AstNode* exp = ParseExpression( false );
          CHECK_ERROR( clause );
          clause->Exp( exp );
        } else {
          clause = CaseClause::New();
          clause->Exp( Empty::New() );
        }
        clause->Line( token->GetLineNumber() );
        token = Advance();
        type = token->GetType();
        if ( type == ':' ) {
          token = Seek();
          type = token->GetType();
          if ( type == Token::JS_CASE ) {
            clause->AddChild( Empty::New() );
            list->AddChild( clause );
          } else {
            AstNode* statement_list = ParseStatementList( CaseBodyMatcher , "'case','default' or '}'" );
            CHECK_ERROR( clause );
            clause->AddChild( statement_list );
            list->AddChild( clause );
          }
        } else {
          SYNTAX_ERROR( "parse error got unexpected token "
                        << TokenConverter( token )
                        << " in 'switch statement case expression' expect ':'\\nin file"
                        << filename_ << " at line " << token->GetLineNumber() );
          END(SwitchStatementError);
          return list;
        }
      } else {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'switch statement case block' expect 'case'\\nin file"
                      << filename_ << " at line " << token->GetLineNumber() );
        END(SwitchStatementError);
        return list;
      }
      token = Seek();
      type = token->GetType();
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'switch statement case block' expect '{'\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
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
  TokenInfo* token = Seek( -1 );
  AstNode* ident = ParseLiteral();
  CHECK_ERROR( ident )
  Advance();
  AstNode* statement = ParseSourceElement();
  CHECK_ERROR( statement );
  LabelledStmt* stmt = LabelledStmt::New();
  CHECK_ERROR( stmt );
  stmt->AddChild( ident );
  stmt->AddChild( statement);
  stmt->Line( token->GetLineNumber() );
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
  TokenInfo* token = Seek( -1 );
  ThrowStmt* throw_stmt = ThrowStmt::New();
  throw_stmt->Line( token->GetLineNumber() );
  AstNode* exp = ParseExpression( false );
  CHECK_ERROR( throw_stmt );
  throw_stmt->Exp( exp );
  throw_stmt->Line( token->GetLineNumber() );
  ParseTerminator();
  CHECK_ERROR( exp );
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
  int type = token->GetType();
  TryStmt *stmt = TryStmt::New();
  stmt->Line( token->GetLineNumber() );
  if ( type == '{' ) {
    Advance();
    AstNode* block = ParseBlockStatement();
    CHECK_ERROR( stmt );
    stmt->AddChild( block );
    token = Seek();
    type = token->GetType();
    if ( type == Token::JS_CATCH ) {
      AstNode* catch_block = ParseCatchBlock();
      CHECK_ERROR( stmt );
      stmt->Catch( catch_block );
      token = Seek();
      type = token->GetType();
    } else {
      stmt->Catch( Empty::New() );
    }
    if ( type == Token::JS_FINALLY ) {
      Advance();
      AstNode* finally_block = ParseFinallyBlock();
      CHECK_ERROR( stmt );
      stmt->Finally( finally_block );
    } else {
      stmt->Finally( Empty::New() );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'try statement' expect '{'\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
  }
  END(TryStatement);
  return stmt;
}

//Parse catch block
AstNode* Parser::ParseCatchBlock() {
  ENTER(CatchBlock);
  TokenInfo *token = Advance( 2 );
  int type = token->GetType();
  if ( type == '(' ) {
    AstNode* ident = ParseLiteral();
    CHECK_ERROR( ident );
    token = Advance();
    type = token->GetType();
    if ( type == ')' ) {
      token = Seek();
      type = token->GetType();
      if ( type != '{' ) {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'catch block' expect '{'\\nin file"
                      << filename_ << " at line " << token->GetLineNumber() );
      } else {
        Advance();
        AstNode* block = ParseBlockStatement();
        CHECK_ERROR( ident );
        ident->AddChild( block );
        END(CatchBlock);
        return ident;
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'catch block' expect ')'\\nin file"
                    << filename_ << " at line " << token->GetLineNumber() );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'catch block' expect '('\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
  }
  END(CatchBlockError);
  return Empty::New();
}


AstNode* Parser::ParseFinallyBlock() {
  ENTER(FinallyBlock);
  TokenInfo *token = Advance();
  int type = token->GetType();
  if ( type == '{' ) {
    state_stack_->Push( StateStack::kFinally );
    AstNode* block = ParseBlockStatement();
    state_stack_->Pop();
    END(FinallyBlock);
    return block;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'finally block' expect '{'\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
    END(FinallyBlockError);
    return Empty::New();
  }
}


AstNode* Parser::ParseTrait() {
  ENTER( Trait );
  TokenInfo* token = Seek();
  int type = token->GetType();
  Trait* trait = Trait::New();
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* literal = ParseLiteral();
    CHECK_ERROR( literal );
    trait->SetName( literal );
    token = Seek();
    type = token->GetType();
  } else {
    trait->SetName( Empty::New() );
  }
  if ( type == '{' ) {
    ParseTraitBody( trait );
    CHECK_ERROR( trait );
    Advance();
    return trait;
  } else {
    SYNTAX_ERROR( "got unexpected token "
                  << TokenConverter( token )
                  << " in 'TraitDeclaration' expect '{'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END( TraitError );
    return trait;
  }
  END( Trait );
}


void Parser::ParseTraitBody( Trait* trait ) {
  Advance();
  TokenInfo* token = Seek();
  int type = token->GetType();
  while ( 1 ) {
    if ( type == Token::JS_IDENTIFIER ) {
      if ( strcmp( token->GetToken() , "requires" ) == 0 ) {
        Advance();
        while ( 1 ) {
          AstNode* ret = ParseLiteral();
          CHECK_ERROR();
          ValueNode* val = ret->CastToValue();
          val->ValueType( ValueNode::kProperty );
          token = Seek();
          type = token->GetType();
          trait->SetRequire( ret );
          if ( type == ',' ) {
            Advance();
          } else {
            ParseTerminator();
            CHECK_ERROR();
            break;
          }
        }
      } else if ( strcmp( token->GetToken() , "mixin" ) == 0 ) {
        Advance();
        AstNode* mixin = ParseMixin();
        CHECK_ERROR();
        trait->SetMixin( mixin );
      } else {
        AstNode* ret = ParseFunctionDecl( false );
        CHECK_ERROR();
        ParseTerminator();
        CHECK_ERROR();
        TraitMember *member = TraitMember::New( TraitMember::kPrivate , ret );
        trait->SetMember( member );
      }
    } else if ( type == Token::JS_PUBLIC ) {
      Advance();
      AstNode* ret = ParseFunctionDecl( false );
      CHECK_ERROR();
      ParseTerminator();
      CHECK_ERROR();
      TraitMember *member = TraitMember::New( TraitMember::kPublic , ret );
      trait->SetMember( member );
    } else if ( type == Token::JS_PRIVATE ) {
      Advance();
      AstNode* ret = ParseFunctionDecl( false );
      CHECK_ERROR();
      ParseTerminator();
      CHECK_ERROR();
      TraitMember *member = TraitMember::New( TraitMember::kPrivate , ret );
      trait->SetMember( member );
    } else {
      SYNTAX_ERROR( "got unexpected token "
                    << TokenConverter( token )
                    << " in 'trait declaration'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(TraitBodyError);
      return;
    }
    token = Seek();
    type = token->GetType();
    if ( type == '}' ) {
      break;
    }
  }
}


AstNode* Parser::ParseMixin() {
  AstNode* literal = ParseLiteral();
  CHECK_ERROR(literal);
  MixinMember* mixin = MixinMember::New();
  mixin->SetName( literal );
  TokenInfo* token = Seek();
  int type = token->GetType();
  while ( 1 ) {
    if ( type == Token::JS_WITH ) {
      Advance();
      AstNode* before = ParseLiteral();
      CHECK_ERROR( before );
      ValueNode* val = before->CastToValue();
      val->ValueType( ValueNode::kProperty );
      token = Seek();
      type = token->GetType();
      if ( type == Token::JS_IDENTIFIER &&
           strcmp( token->GetToken() , "as" ) == 0 ) {
        Advance();
        AstNode* after = ParseLiteral();
        CHECK_ERROR( after );
        ValueNode* after_val = after->CastToValue();
        after_val->ValueType( ValueNode::kProperty );
        NodeList* list = NodeList::New();
        list->AddChild( before );
        list->AddChild( after );
        mixin->AddRename( list );
        token = Seek();
        type = token->GetType();
        if ( type == ',' ) {
          Advance();
          token = Seek();
          type = token->GetType();
        } else {
          ParseTerminator();
          CHECK_ERROR( mixin );
          break;
        }
      } else {
        SYNTAX_ERROR( "got unexpected token "
                      << TokenConverter( token )
                      << " in 'mixin declaration' expect 'as'\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END( MixinError );
        return mixin;
      }
    } else if ( type == Token::JS_IDENTIFIER &&
                strcmp( token->GetToken() , "without" ) == 0 ) {
      Advance();
      AstNode* remove = ParseLiteral();
      CHECK_ERROR( remove );
      remove->CastToValue()->ValueType( ValueNode::kProperty );
      mixin->AddRemoval( remove );
      token = Seek();
      type = token->GetType();
      if ( type == ',' ) {
        Advance();
        token = Seek();
        type = token->GetType();
      } else {
        ParseTerminator();
        CHECK_ERROR( remove );
        break;
      }
    } else {
      break;
    }
  }
  return mixin;
}


AstNode* Parser::ParseClassDecl( bool is_const ) {
  ENTER(ClassDecl);
  TokenInfo* token = Seek();
  int type = token->GetType();
  AstNode* name;
  AstNode* inherit;
  state_stack_->Push( StateStack::kClassDecl );
  if ( type == Token::JS_IDENTIFIER ) {
    name = ParseLiteral();
    CHECK_ERROR( name );
  } else {
    name = Empty::New();
  }
  token = Seek();
  type = token->GetType();
  if ( type == Token::JS_EXTENDS ||
       ( type == Token::JS_IDENTIFIER ||
         strcmp( token->GetToken() , "prototype" ) == 0 ) ) {
    inherit = ParseInheritDecl();
    CHECK_ERROR( inherit );
  } else {
    inherit = Empty::New();
  }
  Class *cls = Class::New( inherit , is_const );
  cls->Name( name );
  token = Advance();
  type = token->GetType();
  if ( type == '{' ) {
    AstNode* body = ParseClassBody();
    CHECK_ERROR( cls );
    cls->Line( token->GetLineNumber() );
    cls->Body( body );
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'class declaration' expect '{'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
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
  int type = token->GetType();
  ClassExpandar* expandar;
  if ( type == Token::JS_EXTENDS ) {
    expandar = ClassExpandar::New( ClassExpandar::kExtends );
  } else {
    expandar = ClassExpandar::New( ClassExpandar::kPrototype );
  }
  AstNode* member = ParseMemberExpression();
  CHECK_ERROR( member );
  expandar->Line( token->GetLineNumber() );
  expandar->AddChild( member );
  END(InheritDecl);
  return expandar;
}


AstNode* Parser::ParseClassBody() {
  ENTER(ClassBody);
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == '}' ) {
    Advance();
    END(ClassBody);
    return Empty::New();
  } else {
    ClassProperties* list = ClassProperties::New();
    while ( type != '}' ) {
      ClassMember* mem = ParseClassMember();
      CHECK_ERROR( mem );
      switch ( mem->Attr() ) {
        case ClassMember::kPrivate :
          list->Private( mem );
          break;
          
        case ClassMember::kPublic :
          list->Public( mem );
          break;

        case ClassMember::kPublicStatic :
          list->PublicStatic( mem );
          break;

        case ClassMember::kPrivateStatic :
          list->PrivateStatic( mem );
          break;

        case ClassMember::kPrototype :
          list->Prototype( mem );
          break;

        case ClassMember::kConstructor :
          list->Constructor( mem );
          break;

        case ClassMember::kMixin :
          list->Mixin( mem->FirstChild() );
          break;
      }
      token = Seek();
      type = token->GetType();
    }
    Advance();
    END(ClassBody);
    return list;
  }
}

AstNode* Parser::ParseClassMemberStatement() {
  TokenInfo* token = Seek( -1 );
  int type = token->GetType();
  if ( state_stack_->Has( StateStack::kClassDecl ) ) {
    ClassMember::MemberAttr member_type;
    if ( type == Token::JS_PUBLIC ) {
      member_type = ClassMember::kPublic;
    } else if ( type == Token::JS_PRIVATE ) {
      member_type = ClassMember::kPrivate;
    }
    AstNode* node = ParseExportableDefinition();
    CHECK_ERROR( node );
    ClassMember* member = ClassMember::New( member_type );
    member->AddChild( node );
    return member;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'member expression' expect '.' or '['\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(MemberExpressionError);
    return Empty::New();
  }
}

ClassMember* Parser::ParseClassMember() {
  ENTER(ClassMember);
  TokenInfo* token = Seek();
  int type = token->GetType();
  ClassMember::MemberAttr member_type;
  AstNode* exp;
  if ( type == Token::JS_IDENTIFIER && strcmp( token->GetToken() , "constructor" ) == 0 ) {
    exp = ParseFunctionDecl( false );
    CHECK_ERROR( ClassMember::New( ClassMember::kConstructor ) );
    ParseTerminator();
    CHECK_ERROR( ClassMember::New( ClassMember::kConstructor ) );
    exp->CastToExpression()->CastToFunction()->Decl();
    member_type = ClassMember::kConstructor;
  } else if ( type == Token::JS_STATIC ) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPublicStatic;
  } else if ( type == Token::JS_PRIVATE ) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPrivate;
  } else if ( type == Token::JS_PUBLIC ) {
    Advance();
    exp = ParseExportableDefinition();
    member_type = ClassMember::kPublic;
  } else if ( type == Token::JS_IDENTIFIER &&
              strcmp( token->GetToken() , "mixin" ) == 0 ) {
    Advance();
    exp = ParseMixin();
    CHECK_ERROR( ClassMember::New( ClassMember::kMixin ) );
    ParseTerminator();
    CHECK_ERROR( ClassMember::New( ClassMember::kMixin ) );
    member_type = ClassMember::kMixin;
  } else {
    exp = ParseExportableDefinition();
    if ( exp->NodeType() == AstNode::kClassMember ) {
      return reinterpret_cast<ClassMember*>( exp );
    }
    member_type = ClassMember::kPrototype;
  }
  ClassMember* member = ClassMember::New( member_type );
  member->AddChild( exp );
  END(ClassMember);
  return member;
}


AstNode* Parser::ParseExportableDefinition() {
  ENTER(ExportableDefinition);
  TokenInfo *token = Seek();
  int type = token->GetType();
  if ( type == Token::JS_IDENTIFIER || type == '{' || type == '[' ) {
    token = Seek( 2 );
    type = token->GetType();
    if ( type == '(' || type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      END(ExportableDefinition);
      AstNode* ret = ParseFunctionDecl( false );
      CHECK_ERROR( ret );
      ParseTerminator();
      CHECK_ERROR( ret );
      return ret;
    } else {
      AstNode* ret = ParseVariableDecl( false );
      CHECK_ERROR( ret );
      ParseTerminator();
      CHECK_ERROR( ret );
      END(ExportableDefinition);
      return ret;
    }
  } else if ( type == Token::JS_CLASS  ) {
    Advance();
    AstNode* class_exp = ParseClassDecl( false );
    CHECK_ERROR( class_exp );
    END( ExportableDefinition );
    return class_exp;
  } else {
    if ( type == Token::JS_CONST ) {
      token = Seek( 2 );
      type = token->GetType();
      if ( type == Token::JS_CLASS ) {
        END(ExportableDefinition);
        return ParseClassDecl( true );
      } else if ( type == '(' || type == Token::JS_FUNCTION_GLYPH ||
                  type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
        Advance();
        END(ExportableDefinition);
        AstNode* ret = ParseFunctionDecl( true );
        CHECK_ERROR( ret );
        ParseTerminator();
        CHECK_ERROR( ret );
        return ret;
      } else {
        Advance();
        AstNode* ret = ParseVariableDecl( false );
        CHECK_ERROR( ret );
        ParseTerminator();
        CHECK_ERROR( ret );
        END(ExportableDefinition);
        ValueNode* value = ValueNode::New( ValueNode::kConstant );
        value->Line( token->GetLineNumber() );
        value->Node( ret );
        return value;
      }
    } else if ( type == Token::JS_GET ) {
      AstNode* fn = ParseFunctionDecl( false );
      CHECK_ERROR( fn );
      fn->CastToExpression()->CastToFunction()->Attr( Function::kGet );
      END(ExportableDefinition);
      return fn;
    } else if ( type == Token::JS_SET ) {
      AstNode* fn = ParseFunctionDecl( false );
      CHECK_ERROR( fn );
      fn->CastToExpression()->CastToFunction()->Attr( Function::kSet );
      END(ExportableDefinition);
      return fn;
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'exportable definition' expect 'identifier','const','get' or 'set'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(ExportableDefinitionError);
      return Empty::New();
    }
  }
}


AstNode* Parser::ParseExpression( bool is_noin ) {
  ENTER(Expression);
  Expression* exp = Expression::New();
  AstNode* assignment = ParseAssignmentExpression( is_noin );
  CHECK_ERROR( exp );
  exp->AddChild( assignment );
  TokenInfo* token = Seek();
  int type = token->GetType();
  assignment->Line( token->GetLineNumber() );
  if ( type == ',' ) {
    Advance();
    while ( 1 ) {
      AstNode* assignment = ParseAssignmentExpression( is_noin );
      CHECK_ERROR( exp );
      exp->AddChild( assignment );
      token = Seek();
      type = token->GetType();
      if ( type == ',' ) {
        token = Advance();
        type = token->GetType();
      } else {
        break;
      }
    }
  }
  END(Expression);
  return exp;
}

bool IsAssignmentOp( int type ) {
  return type == '=' || type == Token::JS_MUL_LET ||
      type == Token::JS_DIV_LET || type == Token::JS_MOD_LET ||
      type == Token::JS_ADD_LET || type == Token::JS_SUB_LET ||
      type == Token::JS_SHIFT_LEFT_LET || type == Token::JS_SHIFT_RIGHT_LET ||
      type == Token::JS_U_SHIFT_RIGHT_LET || type == Token::JS_AND_LET ||
      type == Token::JS_NOT_LET || type == Token::JS_OR_LET;
}

AstNode* Parser::ParseAssignmentExpression( bool is_noin ) {
  ENTER(AssignmentExpression);
  AstNode* exp = ParseYieldExpression( is_noin );
  CHECK_ERROR( exp );
  TokenInfo *token = Seek();
  int type = token->GetType();
  exp->Line( token->GetLineNumber() );
  if ( IsAssignmentOp( type ) ) {
    Advance();
    ValueNode* maybeDst = exp->CastToValue();
    Expression* dsta_object_pattern = exp->CastToExpression();
    if ( maybeDst ) {
      AssignmentDstaConvertor( maybeDst );
    } else if ( dsta_object_pattern && dsta_object_pattern->IsParen() && dsta_object_pattern->ChildLength() > 0 ) {
      AstNode* last = dsta_object_pattern->LastChild();
      maybeDst = last->CastToValue();
      if ( maybeDst && maybeDst->ValueType() == ValueNode::kObject ) {
        AssignmentDstaConvertor( maybeDst );
      }
      exp = maybeDst;
    }
    if ( exp->CastToExpression() && exp->CastToExpression()->IsValidLhs() ) {
      AstNode* rhs = ParseAssignmentExpression( is_noin );
      CHECK_ERROR( rhs );
      AssignmentExp* assign_exp = AssignmentExp::New( type , exp , rhs );
      assign_exp->Line( exp->Line() );
      return assign_exp;
    } else {
      SYNTAX_ERROR( "parse error invalid left hand side expression in 'assignment expression'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(AssignmentExpressionError);
      return Empty::New();
    }
  }
  END(AssignmentExpression);
  return exp;
}

AstNode* Parser::ParseYieldExpression( bool is_noin ) {
  ENTER(YieldExpression);
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == Token::JS_YIELD ) {
    if ( state_stack_->Has( StateStack::kFinally ) ) {
      SYNTAX_ERROR( "yield statement not allowed in 'finally block'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(YieldExpressionError);
      return Empty::New();
    }
    if ( !state_stack_->Has( StateStack::kFunction ) ) {
      SYNTAX_ERROR( "yield statement only allowed in 'function'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(YieldExpressionError);
      return Empty::New();
    }
    bits_.Set( YIELD_FLG );
    Advance();
    token = Seek();
    type = token->GetType();
    if ( token->HasLineBreakAfter() || type == ';' || type == '}' ) {
      if ( type == ';' ) {
        Advance();
      }
      YieldExp* exp = YieldExp::New();
      exp->AddChild( Empty::New() );
      exp->Line( token->GetLineNumber() );
      END(YieldExpression);
      return exp;
    } else {
      YieldExp* exp = YieldExp::New();
      exp->Line( token->GetLineNumber() );
      AstNode* assignment = ParseAssignmentExpression( false );
      CHECK_ERROR( exp );
      exp->AddChild( assignment );
      END(YieldExpression);
      return exp;
    }
  } else {
    END(YieldExpression);
    return ParseConditional( is_noin );
  }
}

AstNode* Parser::ParseConditional( bool is_noin ) {
  ENTER(Conditional);
  AstNode* exp = ParseBinaryExpression( is_noin );
  CHECK_ERROR( exp );
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == '?' ) {
    Advance();
    AstNode* left = ParseAssignmentExpression( is_noin );
    CHECK_ERROR( exp );
    token = Seek();
    type = token->GetType();
    if ( type == ':' ) {
      Advance();
      AstNode* right = ParseAssignmentExpression( is_noin );
      CHECK_ERROR( exp );
      ConditionalExp* cond = ConditionalExp::New( exp , left , right );
      END(Conditional);
      cond->InValidLhs();
      return cond;
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'conditional expression' expect ':'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(ConditionalError);
      return Empty::New();
    }
  } else {
    END(Conditional);
    return exp;
  }
}


AstNode* Parser::ParseBinaryExpression( bool is_noin ) {
  ENTER(BinaryExpression);
  AstNode* last = 0;
  AstNode* first = 0;
  AstNode* lhs = ParseUnaryExpression();
  CHECK_ERROR( lhs );
  while ( 1 ) {
    TokenInfo* token = Seek();
    int type = token->GetType();
    AstNode* exp;
    switch ( type ) {
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
        CHECK_ERROR( rhs );
        if ( last == 0 ) {
          exp = CompareExp::New( type , lhs , rhs );
          first = exp;
        } else {
          exp = CompareExp::New( type , last , rhs );
        }
        exp->CastToExpression()->InValidLhs();
        last = exp;
      }
        break;

      case Token::JS_IN : {
        if ( !is_noin ) {
          Advance();
          AstNode* rhs = ParseUnaryExpression();
          CHECK_ERROR( rhs );
          if ( last == 0 ) {
            exp = CompareExp::New( type , lhs , rhs );
            first = exp;
          } else {
            exp = CompareExp::New( type , last , rhs );
          }
          exp->CastToExpression()->InValidLhs();
          last = exp;
        } else {
          END( BinaryExpressionNoIn );
          return ( first == 0 )? lhs : exp;
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
        CHECK_ERROR( rhs );
        if ( last == 0 ) {
          exp = BinaryExp::New( type , lhs , rhs );
          first = exp;
        } else {
          exp = BinaryExp::New( type , last , rhs );
        }
        exp->CastToExpression()->InValidLhs();
        last = exp;
      }
        break;
        
      default :
        END(BinaryExpression);
        return ( first == 0 )? lhs : exp;
    }
  }
}



bool IsUnaryOp( int type ) {
  return type == Token::JS_DELETE || type == Token::JS_VOID ||
      type == Token::JS_TYPEOF || type == Token::JS_INCREMENT ||
      type == Token::JS_DECREMENT || type == '+' ||
      type == '-' || type == '~' || type == '!';
}


AstNode* Parser::ParseUnaryExpression() {
  ENTER(UnaryExpression);
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( IsUnaryOp( type ) ) {
    Advance();
    AstNode* post_exp = ParseUnaryExpression();
    CHECK_ERROR( post_exp );
    post_exp->CastToExpression()->InValidLhs();
    UnaryExp* unary = UnaryExp::New( type );
    unary->Line( token->GetLineNumber() );
    unary->Exp( post_exp );
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
  CHECK_ERROR( lhs );
  TokenInfo *token = Seek();
  int type = token->GetType();
  if ( !token->HasLineBreakBefore() && ( type == Token::JS_INCREMENT || type == Token::JS_DECREMENT ) ) {
    lhs->CastToExpression()->InValidLhs();
    PostfixExp* post = PostfixExp::New( type );
    post->Line( token->GetLineNumber() );
    post->Exp( lhs );
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
  int type = token->GetType();
  AstNode* node;
  if ( type == Token::JS_NEW ) {
    node = ParseNewExpression();
    node->CastToExpression()->InValidLhs();
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
  int type = token->GetType();
  NewExp* exp = NewExp::New();
  NewExp* first = exp;
  while ( type == Token::JS_NEW ) {
    Advance();
    NewExp *next = NewExp::New();
    exp->AddChild( next );
    exp = next;
    token = Seek();
    type = token->GetType();
  }
  AstNode* member = ParseCallExpression();
  CHECK_ERROR( exp );
  exp->AddChild( member );
  END(NewExpression);
  return first;
}

AstNode* Parser::ParseCallExpression() {
  ENTER(CallExpression);
  AstNode* member = ParseMemberExpression();
  CHECK_ERROR( member );
  TokenInfo* token = Seek();
  int type = token->GetType();
  if ( type == '(' ) {
    Advance();
    AstNode* arguments = ParseArguments();
    CHECK_ERROR( arguments );
    token = Advance();
    type = token->GetType();
    if ( type != ')' ) {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'call expression' expect ')'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
    token = Seek();
    type = token->GetType();
    bool is_function_decl = ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT );
    ValueNode* symbol = member->CastToValue();
    if ( symbol && symbol->ValueType() == ValueNode::kIdentifier && is_function_decl ) {
      Advance();
      AstNode* fn = ParseArrowFunctionExpression( member , arguments , type );
      CHECK_ERROR(fn);
      END(ParseCallExpression_);
      return fn;
    } else if ( is_function_decl ) {
      SYNTAX_ERROR( "parse error arrow function expression name must be 'identifier'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
    int depth = 0;
    CallExp* exp = CallExp::New( CallExp::kNormal );
    exp->Callable( member );
    exp->Args( arguments );
    exp->Depth( depth );
    token = Seek();
    type = token->GetType();
    if ( type == '.' || type == '[' || type == '(' ) {
      if ( type != '(' ) {
        exp = ParseEachMember( type , true , exp );
      }
      token = Seek();
      type = token->GetType();
      while ( 1 ) {
        depth++;
        CallExp* ret = 0;
        if ( type != '(' ) {
          ret = ParseEachMember( type , false , exp );
        } else if ( type == '(' ) {
          Advance();
          AstNode* arguments = ParseArguments();
          CHECK_ERROR( arguments );
          token = Advance();
          type = token->GetType();
          if ( type != ')' ) {
            SYNTAX_ERROR( "parse error got unexpected token "
                          << TokenConverter( token )
                          << " in 'call expression' expect ')'\\nin file "
                          << filename_ << " at line " << token->GetLineNumber() );
            END( CallExpressionError );
            return exp;
          }
          ret = CallExp::New( CallExp::kNormal );
          ret->Callable( exp );
          ret->InValidLhs();
          if ( arguments->ChildLength() == 0 ) {
            ret->Args( Empty::New() );
          } else {
            ret->Args( arguments );
          }
        }
        if ( ret == 0 ) {
          END(CallExpression);
          return exp;
        } else {
          exp = ret;
        }
        exp->Depth( depth );
        token = Seek();
        type = token->GetType();
      }
      END(CallExpression);
      return exp;
    } else if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance();
      END(CallExpression);
      return ParseArrowFunctionExpression( member , arguments , type );
    } else {
      END(CallExpression);
      exp->CastToExpression()->InValidLhs();
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
  int type = token->GetType();
  NodeList* list = NodeList::New();
  if ( type != ')' ) {
    while ( type != ')' ) {
      if ( type == Token::JS_PARAMETER_REST ) {
        Advance();
        token = Seek();
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          AstNode* value = ParseLiteral();
          CHECK_ERROR( list );
          value->CastToValue()->ValueType( ValueNode::kSpread );
          list->AddChild( value );
        } else {
          SYNTAX_ERROR( "parse error got unexpected token "
                        << TokenConverter( token )
                        << " in 'formal parameter rest or arguments spread' expect 'identifier'\\nin file "
                        << filename_ << " at line " << token->GetLineNumber() );
          END( FormalParameterErrror );
          return list;
        }
      } else {
        AstNode* exp = ParseAssignmentExpression( false );
        CHECK_ERROR( list );
        list->AddChild( exp );
      }
      token = Seek();
      type = token->GetType();
      if ( type == ',' ) {
        Advance();
        token = Seek();
        type = token->GetType();
      }
    }
    END(Arguments);
    return list;
  } else {
    END(Arguments);
    return Empty::New();
  }
}


AstNode* Parser::ParseMemberExpression() {
  ENTER(MemberExpression);
  TokenInfo* token = Seek();
  int type = token->GetType();
  CallExp* exp;
  int depth = 0;
  if ( type == Token::JS_PRIVATE ) {
    TokenInfo* pr_sym = token;
    int type_cache = type;
    token = Seek( 2 );
    type = token->GetType();
    ValueNode* private_literal = ValueNode::New( ValueNode::kProperty );
    private_literal->Symbol( pr_sym );
    exp = CallExp::New( CallExp::kPrivate );
    Advance( 2 );
    AstNode *primary = ParsePrimaryExpression();
    CHECK_ERROR( primary );
    if ( primary->CastToValue() && primary->CastToValue()->ValueType() == ValueNode::kIdentifier ) {
      primary->CastToValue()->ValueType( ValueNode::kProperty );
    }
    exp->Callable( private_literal );
    exp->Args( primary );
    exp->Depth( depth );
    token = Seek();
    type = token->GetType();
    if ( type != '.' && type != '[' ) {
      END(MemberExpression);
      return exp;
    }
  } else {
    AstNode *primary = ParsePrimaryExpression();
    CHECK_ERROR( primary );
    token = Seek();
    type = token->GetType();
    if ( type != '.' && type != '[' ) {
      END(MemberExpression);
      return primary;
    }
    int call_type = ( type == '.' )? CallExp::kDot : CallExp::kBracket;
    exp = CallExp::New( call_type );
    exp->Callable( primary );
    exp->Depth( depth );
    ParseEachMember( type , true , exp );
    token = Seek();
    type = token->GetType();
  }
  CallExp* first = exp;
  while ( 1 ) {
    depth++;
    CallExp* ret = ParseEachMember( type , false , exp );
    if ( ret == 0 ) {
      END(MemberExpression);
      return exp;
    } else {
      exp = ret;
    }
    exp->Depth( depth );
    token = Seek();
    type = token->GetType();
  }
  END(MemberExpression);
  return exp;
}


AstNode* Parser::ParseBracketMember() {
  ENTER(BracketMember);
  Advance();
  AstNode* node = ParseExpression( false );
  CHECK_ERROR( node );
  TokenInfo* token = Advance();
  int type = token->GetType();
  if ( type != ']' ) {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'member expression' expect ']'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(BracketMemberError);
    return node;
  }
  END(BracketMember);
  return node;
}


AstNode* Parser::ParseDotMember( bool *is_extend ) {
  ENTER(DotMember);
  TokenInfo* token = Seek();
  int next = token->GetType();
  int extend_type = Seek( 2 )->GetType();
  if ( extend_type == '{' ) {
    *is_extend = true;
    Advance( 2 );
    AstNode* node = ParseObjectLiteral();
    CHECK_ERROR( node );
    return node;
  } else {
    Advance();
    AstNode* node = ParseLiteral();
    CHECK_ERROR( node );
    ValueNode* maybeIdent = node->CastToValue();
    if ( !maybeIdent || maybeIdent->ValueType() != ValueNode::kIdentifier ) {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'member expression' expect 'identifier'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(DotMemberError);
      return node;
    } else if ( maybeIdent->ValueType() == ValueNode::kIdentifier ) {
      maybeIdent->ValueType( ValueNode::kProperty );
    }
    END(DotMember);
    return node;
  }
}


CallExp* Parser::ParseEachMember( int type , bool is_first , CallExp* exp ) {
  ENTER(EachMember);
  if ( type == '[' ) {
    AstNode* node = ParseBracketMember();
    CHECK_ERROR( exp );
    if ( is_first ) {
      if ( exp->CallType() == CallExp::kNormal ) {
        CallExp* accessor = CallExp::New( CallExp::kBracket );
        accessor->Callable( exp );
        accessor->Args( node );
        return accessor;
      } else {
        exp->Args( node );
        END(EachMember);
        return exp;
      }
    } else {
      CallExp* accessor = CallExp::New( CallExp::kBracket );
      if ( exp->CallType() == CallExp::kNormal ) {
        accessor->Callable( exp );
        accessor->Args( node );
      } else {
        accessor->Callable( exp );
        accessor->Args( node );
      }
      END(EachMember);
      return accessor;
    }
  } else if ( type == '.' ) {
    bool is_extend = false;
    AstNode* node = ParseDotMember( &is_extend );
    CHECK_ERROR( exp );
    if ( is_first ) {
      if ( exp->CallType() == CallExp::kNormal ) {
        int type = ( is_extend )? CallExp::kExtend : CallExp::kDot;
        CallExp* accessor = CallExp::New( type );
        accessor->Callable( exp );
        accessor->Args( node );
        return accessor;
      } else {
        exp->Args( node );
        END(EachMember);
        return exp;
      }
    } else {
      int type = ( is_extend )? CallExp::kExtend : CallExp::kDot;
      CallExp* accessor = CallExp::New( type );
      if ( exp->CallType() == CallExp::kNormal ) {
        accessor->Callable( exp );
        accessor->Args( node );
      } else {
        accessor->Callable( exp );
        accessor->Args( node );
      }
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
  int type = token->GetType();
  TokenInfo* function_signature = Seek();
  int fn_signature_type = function_signature->GetType();
  if ( type == Token::JS_FUNCTION ) {
    AstNode* fn = ParseFunctionDecl( false );
    CHECK_ERROR( fn );
    fn->CastToExpression()->InValidLhs();
    END(MemberExpression);
    return fn;
  } else if ( type == Token::JS_CLASS  ) {
    AstNode* class_exp = ParseClassDecl( false );
    CHECK_ERROR( class_exp );
    class_exp->CastToExpression()->InValidLhs();
    return class_exp;
  } else if ( type == Token::JS_IDENTIFIER && strcmp( token->GetToken() , "trait" ) == 0 &&
              ( Seek()->GetType()  == '{' || Seek( 2 )->GetType() == '{' ) ) {
    AstNode* trait = ParseTrait();
    CHECK_ERROR( trait );
    return trait;
  } else if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    AstNode* fn = ParseArrowFunctionExpression( type );
    CHECK_ERROR( fn );
    fn->CastToExpression()->InValidLhs();
    END(MemberExpression);
    return fn;
  } else if ( type == Token::JS_IDENTIFIER && ( fn_signature_type == Token::JS_FUNCTION_GLYPH ||
                                                fn_signature_type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) ) {
    Undo();
    END(MemberExpression);
    return ParseFunctionDecl( false );
  } else if ( type == '{' ) {
    END(PrimaryExpression);
    return ParseObjectLiteral();
  } else if ( type == '[' ) {
    END(PrimaryExpression);
    return ParseArrayLiteral();
  } else if ( type == '(' ) {
    AstNode* exp = ParseExpression( false );
    CHECK_ERROR( exp );
    if ( exp->ChildLength() > 1 ) {
      exp->CastToExpression()->InValidLhs();
    }
    token = Seek();
    type = token->GetType();
    if ( type == ')' ) {
      Advance();
      token = Seek();
      type = token->GetType();
      Expression *expression = exp->CastToExpression();
      expression->Paren();
    } else if ( type == Token::JS_FOR ) {
      AstNode* generator = ParseGeneratorExpression( exp );
      CHECK_ERROR(generator);
      token = Advance();
      type = token->GetType();
      if ( type != ')' ) {
        SYNTAX_ERROR( "unmatched parensis\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        return generator;
      }
      generator->CastToExpression()->InValidLhs();
      return generator;
    } else {
      SYNTAX_ERROR( "parse error unmatched parensis\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      return exp;
    }
    if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance();
      END(PrimaryExpression);
      AstNode* ret = ParseArrowFunctionExpression( exp , type );
      CHECK_ERROR( ret );
      ret->CastToExpression()->InValidLhs();
      return ret;
    } else {
      END(PrimaryExpression);
      return exp;
    }
  } else if ( type == '#' ) {
    token = Advance();
    type = token->GetType();
    if ( type == '[' ) {
      AstNode* elem = ParseArrayLiteral();
      CHECK_ERROR( elem );
      elem->CastToExpression()->InValidLhs();
      elem->CastToValue()->ValueType( ValueNode::kTuple );
      return elem;
    } else if ( type == '{' ) {
      AstNode* elem = ParseObjectLiteral();
      CHECK_ERROR( elem );
      elem->CastToExpression()->InValidLhs();
      elem->CastToValue()->ValueType( ValueNode::kRecord );
      return elem;
    } else {
      SYNTAX_ERROR( "got unexpected token "
                    << TokenConverter( token ) <<
                    " expect '[' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      return Empty::New();
    }
  } else if ( type == Token::JS_FUNCTION_GLYPH ||
              type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    AstNode* fn = ParseArrowFunctionExpression( type );
    END(PrimaryExpression);
    fn->CastToExpression()->InValidLhs();
    return fn;
  } else if ( type == Token::JS_DO ) {
    AstNode* ret = ParseDoWhileStatement( true );
    CHECK_ERROR( ret );
    return ret;
  } else {
    Undo();
    END(PrimaryExpression);
    return ParseLiteral();
  }
}


AstNode* Parser::ParseGeneratorExpression( AstNode* exp ) {
  AstNode* node = ParseArrayComprehensions();
  CHECK_ERROR( node );
  ValueNode* generator = ValueNode::New( ValueNode::kGenerator );
  generator->AddChild( node );
  generator->Node( exp );
  return generator;
}


AstNode* Parser::ParseObjectLiteral() {
  ENTER(ObjectLiteral);
  TokenInfo* token = Seek();
  int type = token->GetType();
  int maybe_colon = Seek( 2 )->GetType();
  ValueNode* object = ValueNode::New( ValueNode::kObject );
  object->Line( token->GetLineNumber() );
  if ( type != '}' ) {
    NodeList* list = NodeList::New();
    while ( 1 ) {
      if ( maybe_colon == '}' ) {
        AstNode* node = ParseObjectElement( type , token , list );
        CHECK_ERROR( node );
        node->AddChild( node->Clone() );
        break;
      } else if ( maybe_colon == ',' ) {
        AstNode* node = ParseObjectElement( type , token , list );
        CHECK_ERROR(list);
        node->AddChild( node->Clone() );
        token = Seek();
        type = token->GetType();
      } else if ( maybe_colon == ':' ) {
        AstNode* node = ParseLiteral();
        CHECK_ERROR( node );
        ValueNode* prop = node->CastToValue();
        if ( prop->ValueType() == ValueNode::kIdentifier ) {
          prop->ValueType( ValueNode::kProperty );
        }
        Advance();
        token = Seek();
        type = token->GetType();
        AstNode* assign;
        if ( type == '{' ) {
          Advance();
          assign = ParseObjectLiteral();
        } else {
          assign = ParseAssignmentExpression( false );
        }
        CHECK_ERROR( assign );
        node->AddChild( assign );
        list->AddChild( node );
        token = Seek();
        type = token->GetType();
      } else if ( type == '[' ) {
        AstNode* node = ParseObjectElement( type , token , list );
        CHECK_ERROR( node );
        token = Advance();
        type = token->GetType();
        if ( type == ':' ) {
          AstNode* assign;
          token = Seek();
          type = token->GetType();
          if ( type == '{' ) {
            Advance();
            assign = ParseObjectLiteral();
          } else {
            assign = ParseAssignmentExpression( false );
          }
          CHECK_ERROR(assign);
          node->AddChild( assign );
          list->AddChild( node );
          token = Seek();
          type = token->GetType();
        }
      } else if ( maybe_colon == '(' || maybe_colon == Token::JS_FUNCTION_GLYPH ||
                  maybe_colon == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
        AstNode* fn = ParseFunctionDecl( false );
        CHECK_ERROR( fn );
        ValueNode* val = fn->CastToExpression()->CastToFunction()->Name()->Clone()->CastToValue();
        val->AddChild( fn );
        list->AddChild( val );
        val->ValueType( ValueNode::kProperty );
        token = Seek();
        type = token->GetType();
      } else {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << ". In 'object literal'\\n"
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ObjectLiteralError);
        return object;
      }
      if ( type == ',' ) {
        Advance();
      } else if ( type == '}' ) {
        Advance();
        break;
      }
      token = Seek();
      type = token->GetType();
      maybe_colon = Seek( 2 )->GetType();
    }
    object->Node( list );
  } else {
    Advance();
    object->Node( Empty::New() );
  }
  END(ObjectLiteral);
  return object;  
}



AstNode* Parser::ParseObjectElement( int type , TokenInfo* token , AstNode* list ) {
  ENTER(ObjectElement);
  if ( IsValidPropertyName( type ) ) {
    AstNode* node = ParseLiteral();
    CHECK_ERROR( node );
    Advance();
    list->AddChild( node );
    END(ObjectElement);
    ValueNode* name = node->CastToValue();
    if ( name->ValueType() == ValueNode::kIdentifier ) {
      name->ValueType( ValueNode::kProperty );
    }
    return node;
  } else if ( type == '[' ) {
    Advance();
    AstNode* node = ParseAssignmentExpression( true );
    TokenInfo* token = Seek();
    int next = token->GetType();
    if ( next != ']' ) {
      SYNTAX_ERROR( "in 'object literal private property' expect ']' but got " << TokenConverter( token )
                    << "\\nin file " << filename_ << " at line " << token->GetLineNumber() );
      END( ObjectElementError );
      return node;
    } else {
      Advance();
      ValueNode* value = ValueNode::New( ValueNode::kPrivateProperty );
      value->Line( token->GetLineNumber() );
      value->Node( node );
      return value;
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << ". In 'object literal'"
                  " member only allowed 'string literal','number' or 'identifier'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(ObjectElementError);
    return Empty::New();
  }
}


AstNode* Parser::ParseArrayLiteral() {
  ENTER(ArrayLiteral);
  ValueNode* val = ValueNode::New( ValueNode::kArray );
  NodeList* list = NodeList::New();
  TokenInfo* token = Seek();
  int type = token->GetType();
  val->Line( token->GetLineNumber() );
  int count = 0;
  if ( type == ']' ) {
    Advance();
    END(ArrayLiteral);
    return val;
  } else {
    while ( 1 ) {
      if ( type == ',' ) {
        list->AddChild( Empty::New() );
        int last_type = Seek( -1 )->GetType();
        token = Advance();
        type = token->GetType();
        if ( type == ']' ) {
          Advance();
          if ( last_type == '[' ) {
            list->AddChild( Empty::New() );
          }
          break;
        }
      } else if ( type == Token::JS_PARAMETER_REST ) {
        token = Advance( 2 );
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          ValueNode* rest = ValueNode::New( ValueNode::kRest );
          rest->Line( token->GetLineNumber() );
          rest->Symbol( token );
          list->AddChild( rest );
          token = Seek();
          type = token->GetType();
          if ( type == ']' ) {
            Advance();
            break;
          }
        } else {
          SYNTAX_ERROR( "unexpected token "
                        << TokenConverter( token )
                        << " expect 'identifier' in 'rest expression'\\nin file "
                        << filename_ << " at line " << token->GetLineNumber() );
          END(ArrayLiteralError);
          return val;
        }
      } else {
        AstNode* node = ParseAssignmentExpression( false );
        CHECK_ERROR( node );
        list->AddChild( node );
        token = Seek();
        type = token->GetType();
        if ( type == Token::JS_FOR ) {
          if ( count > 0 ) {
            SYNTAX_ERROR( "parse error got unexpected token "
                          << TokenConverter( token )
                          << " in 'array comprehensions expect' 'assignment expression'\\nin file "
                          << filename_ << " at line " << token->GetLineNumber() );
            END(ArrayLiteralError);
            return val;
          }
          AstNode* cmp_node = ParseArrayComprehensions();
          CHECK_ERROR( cmp_node );
          list->RemoveChild( node );
          list->AddChild( cmp_node );
          token = Seek();
          type = token->GetType();
          if ( type != ']' ) {
            SYNTAX_ERROR( "parse error got unexpected token "
                          << TokenConverter( token )
                          << " in 'array comprehensions expect' ']'\\nin file "
                          << filename_ << " at line " << token->GetLineNumber() );
            END(ArrayLiteralError);
            return val;
          } else {
            Advance();
          }
          val->Node( node );
          val->AddChild( cmp_node );
          val->ValueType( ValueNode::kArrayComp );
          END(ArrayLiteral);
          return val;
        } else if ( type == ',' ) {
          Advance();
          token = Seek();
          type = token->GetType();
        } else if ( type == ']' ) {
          Advance();
          break;
        }
      }
      count++;
    }
  }
  val->AddChild( list );
  END(ArrayLiteral);
  return val;
}


AstNode* Parser::ParseLiteral() {
  ENTER(Literal);
  TokenInfo* token = Advance();
  int type = token->GetType();
  int value_type = 0;
  bool is_invalid_lhs = false;
  switch ( type ) {
    case Token::JS_NAN :
      value_type = ValueNode::kNaN;
      is_invalid_lhs = true;
      break;
      
    case Token::JS_SUPER :
      value_type = ValueNode::kSuper;
      is_invalid_lhs = true;
      break;
      
    case Token::JS_THIS :
      value_type = ValueNode::kThis;
      is_invalid_lhs = true;
      break;

    case Token::JS_IDENTIFIER : {
      value_type = ValueNode::kIdentifier;
      const char* ident = token->GetToken();
      int len = strlen( ident );
      if ( ident[ 0 ] == '@' ) {
        ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                        Token::JS_THIS , token->GetLineNumber() , ValueNode::kThis );
        if ( len > 1 ) {
          ValueNode* value = AstUtils::CreateNameNode( &ident[ 1 ] , Token::JS_PROPERTY , token->GetLineNumber() , ValueNode::kProperty );
          CallExp* this_accessor = AstUtils::CreateDotAccessor( this_sym , value );
          return this_accessor;
        } else {
          return this_sym;
        }
      } else if ( len > 1 && ident[ 0 ] == '_' && ident[ 1 ] == '@' ) {
        ValueNode* private_sym = AstUtils::CreateNameNode( JsToken::GetTokenFromNumber( Token::JS_PRIVATE ),
                                                           Token::JS_PRIVATE , token->GetLineNumber() , ValueNode::kIdentifier );
        if ( len > 2 ) {
          ValueNode* value = AstUtils::CreateNameNode( &ident[ 2 ] , Token::JS_PROPERTY , token->GetLineNumber() , ValueNode::kProperty );
          CallExp* private_accessor = CallExp::New( CallExp::kPrivate );
          private_accessor->Callable( private_sym );
          private_accessor->Args( value );
          return private_accessor;
        } else {
          return private_sym;
        }
      }
    }
      break;

    case Token::JS_TRUE :
      value_type = ValueNode::kTrue;
      is_invalid_lhs = true;
      break;

    case Token::JS_FALSE :
      value_type = ValueNode::kFalse;
      is_invalid_lhs = true;
      break;

    case Token::JS_NUMERIC_LITERAL :
      value_type = ValueNode::kNumeric;
      is_invalid_lhs = true;
      break;

    case Token::JS_STRING_LITERAL :
      value_type = ValueNode::kString;
      is_invalid_lhs = true;
      break;

    case Token::JS_REGEXP_LITERAL :
      value_type = ValueNode::kRegExp;
      is_invalid_lhs = true;
      break;

    case Token::JS_K_NULL :
      value_type = ValueNode::kNull;
      is_invalid_lhs = true;
      break;

    default : {
      SYNTAX_ERROR( "parse error got unexpected token '"
                    << TokenConverter( token )
                    << "' expect " << literals << "\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(LiteralError);
      return Empty::New();
    }
  }
  //assert( value_type != 0 );
  ValueNode* value = ValueNode::New( value_type );
  value->Line( token->GetLineNumber() );
  value->Symbol( token );
  if ( is_invalid_lhs ) {
    value->InValidLhs();
  }
  END(Literal);
  return value;
}


bool IsValidFormalParameter( int type ) {
  return type == Token::JS_IDENTIFIER || type == '{' || type == '[' || type == Token::JS_THIS || type == Token::JS_PRIVATE;
}


AstNode* Parser::ParseFunctionDecl( bool is_const ) {
  ENTER(FunctionDecl);
  TokenInfo* token = Seek();
  int type = token->GetType();
  Function* fn = Function::New();
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* name = ParseLiteral();
    CHECK_ERROR( name );
    fn->Name( name );
    token = Seek();
    type = token->GetType();
  } else {
    fn->Name( Empty::New() );
  }
  
  if ( type == '(' ) {
    Advance();
    token = Seek();
    type = token->GetType();
    if ( type != ')' ) {
      AstNode* list = ParseFormalParameter();
      fn->Argv( list );
      token = Advance( 2 );
      type = token->GetType();
    } else {
      fn->Argv( Empty::New() );
      token = Advance( 2 );
      type = token->GetType();
    }
  } else {
    fn->Argv( Empty::New() );
    token = Seek();
    type = token->GetType();
    if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance();
    }
  }

  if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      fn->ContextType( Function::kThis );
    }
    token = Seek();
    type = token->GetType();
    if ( type == '{' ) {
      Advance();
      state_stack_->Push( StateStack::kFunction );
      bool has_return = bits_.At( RETURN_FLG );
      bool has_yield = bits_.At( YIELD_FLG );
      bits_.UnSet( RETURN_FLG );
      bits_.UnSet( YIELD_FLG );
      AstNode* body = ParseStatementList( BlockBodyMatcher , "}" );
      CHECK_ERROR( body );
      AstUtils::FindDirectivePrologue( body , fn );
      if ( bits_.At( RETURN_FLG ) && bits_.At( YIELD_FLG ) ) {
        SYNTAX_ERROR( "return statement not allowed in 'generator function'\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(FunctionDeclError);
        return fn;
      }
      if ( !has_return ) {
        bits_.UnSet( RETURN_FLG );
      }
      if ( !has_yield ) {
        bits_.UnSet( YIELD_FLG );
      }
      state_stack_->Pop();
      CHECK_ERROR( body );
      fn->Append( body );
      Advance();
      return fn;
    } else {
      AstNode* node = ParseAssignmentExpression( false );
      CHECK_ERROR( node );
      fn->AddChild( node );
      fn->FunctionType( Function::kShorten );
      END(FunctionDecl);
      return fn;
    }
  } else {
    if ( type == '{' ) {
      state_stack_->Push( StateStack::kFunction );
      bool has_return = bits_.At( RETURN_FLG );
      bool has_yield = bits_.At( YIELD_FLG );
      bits_.UnSet( RETURN_FLG );
      bits_.UnSet( YIELD_FLG );
      AstNode* body = ParseStatementList( BlockBodyMatcher , "}" );
      CHECK_ERROR( body );
      AstUtils::FindDirectivePrologue( body , fn );
      if ( bits_.At( RETURN_FLG ) && bits_.At( YIELD_FLG ) ) {
        SYNTAX_ERROR( "return statement not allowed in 'generator function'\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(FunctionDeclError);
        return fn;
      }
      if ( !has_return ) {
        bits_.UnSet( RETURN_FLG );
      }
      if ( !has_yield ) {
        bits_.UnSet( YIELD_FLG );
      }
      state_stack_->Pop();
      CHECK_ERROR( body );
      Advance();
      fn->Append( body );
      END(FunctionDecl);
      return fn;
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'function declaration' expect '{'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(FunctionDeclError);
      return fn;
    }
  }
}


AstNode* Parser::ParseFormalParameter() {
  ENTER( FormalParameter );
  TokenInfo* token = Seek();
  int type = token->GetType();
  NodeList* list = NodeList::New();
  while ( type != ')' && !IsEnd( type ) ) {
    if ( IsValidFormalParameter( type ) ) {
      AstNode* node;
      if( type == '{' || type == '[' ){
        node = ParseDestructuringLeftHandSide();
        CHECK_ERROR(node);
        node->Line( token->GetLineNumber() );
        ValueNode* value = ValueNode::New( ValueNode::kDst );
        value->Node( node );
        token = Seek();
        type = token->GetType();
        if ( type == '=' ) {
          AstNode* exp = ParseAssignmentExpression( false );
          CHECK_ERROR(exp);
          value->AddChild( exp );
        } else {
          value->AddChild( Empty::New() );
        }
        node = value;
      } else {
        node = ParseAssignmentExpression( false );
        CHECK_ERROR( node );
        node->Line( token->GetLineNumber() );
        AssignmentExp* exp = node->CastToExpression()->CastToAssigment();
        if ( exp ) {
          ValueNode* value = ValueNode::New( ValueNode::kIdentifier );
          ValueNode* symbol = exp->Left()->CastToValue();
          if ( symbol ) {
            value->Symbol( symbol->Symbol() );
            value->AddChild( exp->Right() );
            node = value;
          }
        }
      }
      CHECK_ERROR( node );
      list->AddChild( node );
      token = Seek();
      type = token->GetType();
      if ( type != ')' && type != ',' ) {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'formal parameter' expect ')' or ','\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END( FormalParameterError );
        return list;
      } else if ( type == ',' ) {
        Advance();
      } else if ( type == ')' ) {
        break;
      }
      token = Seek();
      type = token->GetType();
    } else if ( type == Token::JS_PARAMETER_REST ) {
      Advance();
      token = Seek();
      type = token->GetType();
      if ( type == Token::JS_IDENTIFIER ) {
        AstNode* value = ParseLiteral();
        CHECK_ERROR( value );
        value->Line( token->GetLineNumber() );
        value->CastToValue()->ValueType( ValueNode::kRest );
        token = Seek();
        type = token->GetType();
        list->AddChild( value );
        if ( type != ')' && type != ',' ) {
          SYNTAX_ERROR( "parse error got unexpected token "
                        << TokenConverter( token )
                        << " in 'formal parameter rest' can not continue after any 'formal parameter'\\nin file "
                        << filename_ << " at line " << token->GetLineNumber() );
          END( FormalParameterError );
          return list;
        } else if ( type == ')' ) {
          break;
        }
        token = Advance();
        type = token->GetType();
      } else {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'formal parameter rest' expect 'identifier'\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END( FormalParameterErrror );
        return list;
      }
    }
  }
  if ( IsEnd( type ) ) {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'formal parameter' expect ')'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END( FormalParameter );
    return list;
  }
  return list;
}


AstNode* Parser::ParseArrowFunctionExpression( AstNode* exp , int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = Function::New();
  if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    fn->ContextType( Function::kThis );
  }
  NodeList* list = NodeList::New();
  FormalParameterConvertor( exp , list );
  fn->Argv( list );
  fn->Name( Empty::New() );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody( fn );
}

AstNode* Parser::ParseArrowFunctionExpression( AstNode* member , AstNode* args , int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = Function::New();
  if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    fn->ContextType( Function::kThis );
  }
  ValueNode* maybeIdent = member->CastToValue();
  if ( !maybeIdent || maybeIdent->ValueType() != ValueNode::kIdentifier ) {
    SYNTAX_ERROR( "parse error illegal function name "
                  "in 'arrow function expression' expect 'identifier'\\nin file"
                  << filename_ << " at line " << member->Line() );
    END( ArrowFunctionExpression );
    return fn;
  }
  fn->Name( maybeIdent );
  NodeList* list = NodeList::New();
  FormalParameterConvertor( args , list );
  fn->Argv( list );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody( fn );
}

AstNode* Parser::ParseArrowFunctionExpression( int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = Function::New();
  if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    fn->ContextType( Function::kThis );
  }
  fn->Argv( Empty::New() );
  fn->Name( Empty::New() );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody( fn );
}

AstNode* Parser::ParseArrowFunctionBody( Function* fn ) {
  ENTER(ArrowFunctionBody);
  TokenInfo* token = Seek();
  int token_type = token->GetType();
  if ( token_type == '{' ) {
    Advance();
    state_stack_->Push( StateStack::kFunction );
    bool has_return = bits_.At( RETURN_FLG );
    bool has_yield = bits_.At( YIELD_FLG );
    bits_.UnSet( RETURN_FLG );
    bits_.UnSet( YIELD_FLG );
    AstNode* list = ParseStatementList( BlockBodyMatcher , "}" );
    CHECK_ERROR( list );
    AstUtils::FindDirectivePrologue( list , fn );
    if ( bits_.At( RETURN_FLG ) && bits_.At( YIELD_FLG ) ) {
      SYNTAX_ERROR( "return statement not allowed in 'generator function'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(FunctionDeclError);
      return fn;
    }
    if ( !has_return ) {
      bits_.UnSet( RETURN_FLG );
    }
    if ( !has_yield ) {
      bits_.UnSet( YIELD_FLG );
    }
    state_stack_->Pop();
    CHECK_ERROR( list );
    fn->Append( list );
    Advance();
  } else {
    AstNode* node = ParseAssignmentExpression( false );
    CHECK_ERROR( node );
    fn->AddChild( node );
    fn->FunctionType( Function::kShorten );
  }
  END( ArrowFunctionBody );
  return fn;
}


AstNode* Parser::ParseArrayComprehensions() {
  ENTER(ArrayComprehensions);
  TokenInfo* token = Advance();
  int type = token->GetType();
  NodeList *list = NodeList::New();
  while ( type == Token::JS_FOR ) {
    AstNode* node = ParseForStatement( true );
    CHECK_ERROR( node );
    list->AddChild( node );
    token = Advance();
    type = token->GetType();
  }
  if ( type == Token::JS_IF ) {
    AstNode* if_stmt = ParseIFStatement( true );
    CHECK_ERROR( if_stmt );
    list->AddChild( if_stmt );
  } else {
    Undo();
  }
  END( ArrayComprehensions );
  return list;
}
}
