#include <assert.h>
#include <vector>
#include <sstream>
#include <ast/ast.h>
#include <compiler/utils/error_reporter.h>
#include <compiler/parser/parser.h>
#include <compiler/scanner/token_stream.h>
#include <compiler/tokens/js_token.h>
#include <utils/pool/managed_handle.h>

namespace mocha {

static const char use_strict[] = { "use strict" };
static const char import_from[] = { "from" };
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
 * Convert an arrow function expression's formal parameter list to a valid formal parameter list.
 */
void FormalParameterConvertor( AstNode *args , AstNode* list ) {
  NodeIterator iterator = args->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    ValueNode* maybe_dst_or_spread = item->CastToValue();
    if ( maybe_dst_or_spread ) {
      int type = maybe_dst_or_spread->ValueType();
      if ( type == ValueNode::kObject || type == ValueNode::kArray ) {
        type = ( type == ValueNode::kArray )? ValueNode::kDstArray : ValueNode::kDst;
        AstNode* target = maybe_dst_or_spread->Node();
        maybe_dst_or_spread->ValueType( type );
        if ( !target ) {
          DstaRewriter( maybe_dst_or_spread->FirstChild() );
        } else {
          DstaRewriter( target );
        }
        ValueNode* dst = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
        dst->Line( maybe_dst_or_spread->Line() );
        dst->Node( maybe_dst_or_spread );
        list->AddChild( dst );
        continue;
      } else if ( type == ValueNode::kSpread ) {
        maybe_dst_or_spread->ValueType( ValueNode::kRest );
      }
    } else if ( item->NodeType() == ValueNode::kAssignmentExp ) {
      AssignmentExp* exp = item->CastToExpression()->CastToAssigment();
      ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
      ValueNode* symbol = exp->Left()->CastToValue();
      if ( symbol ) {
        value->Symbol( symbol->Symbol() );
        value->AddChild( exp->Right() );
        item = value;
      } else {
        printf( "Error!!\n" );
      }
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
  FileRoot* root = ManagedHandle::Retain<FileRoot>();
  root->FileName( filename_ );
  root->Append( ParseProgram_() );
  return root;
}

//Report illegal end of input.
void Parser::IllegalEnd_( const char* expect , long line ) {
  SYNTAX_ERROR( "parse error got unexpected end of input expect "
                << expect << "\\nin file " << filename_ << " at line " << line );
}


void Parser::ParseTerminator_() {
  TokenInfo *token = Seek_();
  int type = token->GetType();
  if ( type == ';' || type == '}' || IsEnd( type ) || token->HasLineBreakBefore() ) {
    if ( type == ';' ) {
      Advance_();
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " expect ';' or 'line break'\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
  }
}

//Begining of parse.
AstNode* Parser::ParseProgram_() {
  ENTER(Program);
  /*
   *program
   * : source_elements
   */
  AstNode* list = ParseSourceElements_();
  END(Program);
  return list;
}


//ParseSourceElements_ is only called by ParseProgram.
//If this function is called,
//this function search until got END_TOKEN or END_OF_INPUT.
//This function is only called once in each parse time.
AstNode* Parser::ParseSourceElements_() {
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
  NodeList* list = ManagedHandle::Retain<NodeList>();
  while ( ( type = Seek_() ) && type != 0 && ( type->GetType() != Token::END_TOKEN || type->GetType() != Token::END_OF_INPUT ) ) {
    AstNode* statement = ParseSourceElement_();
    /*//check "use strict" prologue directive.
    if ( statement->NodeType() == AstNode::kExpressionStmt ) {
      if ( !( statement->FirstChild()->CastToExpression()->IsParen() ) )
      NodeIterator iterator = statement->Find( AstNode::kValueNode );
      if ( iterator.Length() == 1 ) {
        ValueNode* maybeString = iterator.Next()->CastToValue()->GetToken();
        if ( maybeString->ValueType() == ValueNode::kString ) {
          if ( strlen( maybeString->GetToken() ) > 0 && strcmp( maybeString->GetToken() , use_strict ) ) {
            env_->DirectivePrologue();
          }
        }
      }
      }*/
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

AstNode* Parser::ParseSourceElement_() {
  ENTER(SourceElement);
  /*
   *source_element
   * : statement
   */
  TokenInfo* info = Advance_();
  AstNode* result = 0;//init after;
  if ( info == 0 || info->GetType() == Token::END_TOKEN || info->GetType() == Token::END_OF_INPUT ) {
    return ManagedHandle::Retain<Empty>();
  }
  switch ( info->GetType() ) {
    case Token::JS_CLASS :{
      result = ParseClassDecl_( false );
      ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
      stmt->AddChild( result );
      result = stmt;
    }
      break;
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl_( false );
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      fn->Decl();
    }
      break;
      
    case Token::JS_CONST : {
      info = Seek_();
      int type = info->GetType();
      //check syntax for const class decl.
      if ( type == Token::JS_CLASS ) {
        Advance_();
        result = ParseClassDecl_( true );
      } else {
        TokenInfo* function_signature = Seek_( 2 );
        int type = function_signature->GetType();
        //check syntax for const function.
        if ( type == '(' || type == Token::JS_FUNCTION_GLYPH ||
             type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
          result = ParseFunctionDecl_( true );
          CHECK_ERROR(result);
          Function* fn = result->CastToExpression()->CastToFunction();
          fn->Decl();
        } else {
          result = ParseVariableStatement_();
        }
      }
      break;
    }
    case Token::JS_LET :
        result = ParseLetDeclOrLetStatement_();
    default :
      Undo_();
      result = ParseStatement_();
  }
  END(SourceElement);
  return result;
}


AstNode* Parser::ParseStatementList_( StatementListMatcher matcher , const char* expect ) {
  ENTER( StatementList );
  TokenInfo* token = Seek_();
  int type = token->GetType();
  StatementList* list = ManagedHandle::Retain<StatementList>();
  while ( matcher( type ) ) {
    AstNode* statement = ParseSourceElement_();
    CHECK_ERROR( statement );
    list->AddChild( statement );
    token = Seek_();
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


AstNode* Parser::ParseStatement_() {
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
   *| expression_statement
   *;
   */
  TokenInfo* info = Advance_();
  AstNode* result;
  switch ( info->GetType() ) {
    case '{' :
      result = ParseBlockStatement_();
      break;
      
    case Token::JS_MODULE :
      result = ParseModuleStatement_();
      break;
      
    case Token::JS_EXPORT :
      result = ParseExportStatement_();
      break;
      
    case Token::JS_VAR :
    case Token::JS_LET :
    case Token::JS_CONST :
      result = ParseVariableStatement_();
      break;
      
    case ';' :
      result = ManagedHandle::Retain<Empty>();
      break;
      
    case Token::JS_IF :
      result = ParseIFStatement_( false );
      break;
      
    case Token::JS_FOR :
      result = ParseForStatement_( false );
      break;
      
    case Token::JS_WHILE :
      result = ParseWhileStatement_();
      break;
      
    case Token::JS_DO :
      result = ParseDoWhileStatement_();
      break;
      
    case Token::JS_CONTINUE :
      result = ParseContinueStatement_();
      break;
      
    case Token::JS_BREAK :
      result = ParseBreakStatement_();
      break;
      
    case Token::JS_RETURN :
      result = ParseReturnStatement_();
      break;
      
    case Token::JS_WITH :
      result = ParseWithStatement_();
      break;
      
    case Token::JS_SWITCH :
      result = ParseSwitchStatement_();
      break;
      
    case Token::JS_THROW :
      result = ParseThrowStatement_();
      break;
      
    case Token::JS_TRY :
      result = ParseTryStatement_();
      break;
      
    case Token::JS_IMPORT :
      result = ParseImportStatement_();
      break;

    case Token::JS_ASSERT :
      result = ParseAssertStatement_();
      break;
      
    case Token::MOCHA_VERSIONOF :
      result = ParseVersionStatement_();
      break;
      
    case Token::JS_FUNCTION : {
      result = ParseFunctionDecl_( false );
      CHECK_ERROR(result);
      Function* fn = result->CastToExpression()->CastToFunction();
      fn->Decl();
    }
      break;
      
    case Token::JS_DEBUGGER :
      result = ParseDebuggerStatement_( info );
      break;

    case Token::JS_PRIVATE :
    case Token::JS_PUBLIC :
    case Token::JS_STATIC : {
      TokenInfo *token = Seek_();
      int type = token->GetType();
      if ( type == '.' || type == '[' ) {
        result = CheckLabellOrExpressionStatement_();
      } else {
        result = ParseClassMemberStatement_();
      }
    }
      break;
      
    default : {
      result = CheckLabellOrExpressionStatement_();
      CHECK_ERROR(result);;
      if ( result->NodeType() == AstNode::kExpressionStmt ) {
        Expression* exp = result->FirstChild()->CastToExpression();
        if ( exp->ChildLength() > 0 ) {
          NodeIterator iterator = exp->ChildNodes();
          while ( iterator.HasNext() ) {
            AstNode* item = iterator.Next();
            if ( item->NodeType() == AstNode::kFunction ) {
              item->CastToExpression()->CastToFunction()->Decl();
            }
          }
        }
      }
    }
  }
  CHECK_ERROR(result);
  //result->Line( info->GetLineNumber() );
  END(Statement);
  return result;
}

AstNode* Parser::ParseBlockStatement_() {
  ENTER(BlockStatement);
  /*
   *block
   *: '{' '}'
   *| '{' statement_list '}'
   */
  BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
  StatementList* list = ManagedHandle::Retain<StatementList>();
  TokenInfo* info = Seek_();
  int type = info->GetType();
  //Check block statement has body or not.
  //If block body is empty -> {}, set Empty node to block body.
  if ( type != '}' ) {
    while ( 1 ) {
      AstNode* statement = ParseSourceElement_();
      CHECK_ERROR( statement );
      list->AddChild( statement );
      info = Seek_();
      type = info->GetType();
      if ( type == '}' ) {
        Advance_();
        break;
      } else if ( IsEnd( type ) ) {
        IllegalEnd_( "'}'" , info->GetLineNumber() );
        END(BlockStatementError);
        return block;
      }
    }
    block->AddChild( list );
  } else {
    Advance_();
    block->AddChild( ManagedHandle::Retain<Empty>() );
  }
  END(BlockStatement);
  return block;
}

AstNode* Parser::ParseModuleStatement_() {
  ENTER(ModuleStatement);
  /*
   *module_statement
   *: JS_MODULE identifier__opt statement
   *;
   */
  ModuleStmt* module_stmt = ManagedHandle::Retain<ModuleStmt>();
  TokenInfo* info = Seek_();
  int type = info->GetType();
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* name = ParseLiteral_();
    CHECK_ERROR(module_stmt);
    module_stmt->Name( name );
  } else {
    module_stmt->Name( ManagedHandle::Retain<Empty>() );
  }
  AstNode* statement = ParseSourceElement_();
  module_stmt->Line( info->GetLineNumber() );
  module_stmt->AddChild( statement );
  END(ModuleStatement);
  return module_stmt;
}

AstNode* Parser::ParseExportStatement_() {
  ENTER(ExportStatement);
  /*
   *export_statement
   *: JS_EXPORT exportable_definition
   */
  ExportStmt* export_stmt = ManagedHandle::Retain<ExportStmt>();
  AstNode* exportable = ParseExportableDefinition_();
  CHECK_ERROR( export_stmt );
  export_stmt->Line( exportable->Line() );
  export_stmt->AddChild( exportable );
  END(ExportStatement);
  return export_stmt;
}

AstNode* Parser::ParseImportStatement_() {
  ENTER(ImportStatement);
  /*
   *import_statement
   *: JS_IMPORT JS_IDENTIFIER JS_FROM import_expression terminator
   */
  TokenInfo* val = Seek_();
  int type;
  AstNode* exp;
  if ( val->GetType() == Token::JS_IDENTIFIER ) {
    exp = ParseLiteral_();
    type = ImportStmt::kVar;
  } else if ( val->GetType() == '{' || val->GetType() == '[' ) {
    exp = ParseDestructuringLeftHandSide_();
    type = ImportStmt::kDst;
  }
  TokenInfo* r_from = Advance_();
  TokenConverter cnv( r_from );
  if ( r_from->GetType() == Token::JS_IDENTIFIER &&
       strlen( static_cast<const char*>( cnv ) ) > 0 &&
       strcmp( static_cast<const char*>( cnv ) , import_from ) == 0 ) {
    AstNode* from_exp = ParseImportExpression_();
    ValueNode* maybe_file = from_exp->FirstChild()->CastToValue();
    int from_type;
    if ( maybe_file && maybe_file->ValueType() == ValueNode::kString ) {
      from_type = ImportStmt::kFile;
    } else {
      from_type = ImportStmt::kModule;
    }
    ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( type , from_type ) );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    stmt->From( from_exp );
    ParseTerminator_();
    CHECK_ERROR( stmt );
    END(ImportStatement);
    return stmt;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( r_from )
                  << " after 'import' expect 'from'\\nin file "
                  << filename_ << " at line " << r_from->GetLineNumber() );
    END(ImportStatementError);
    return ManagedHandle::Retain<Empty>();
  }
}

AstNode* Parser::ParseImportExpression_() {
  ENTER(ImportExpression);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  NodeList* list = ManagedHandle::Retain<NodeList>();
  if ( type == Token::JS_STRING_LITERAL ) {
    AstNode* literal = ParseLiteral_();
    CHECK_ERROR(literal);
    list->AddChild( literal );
  } else if ( type == Token::JS_IDENTIFIER ) {
    AstNode* literal = ParseLiteral_();
    CHECK_ERROR( literal );
    list->AddChild( literal );
  }
  token = Seek_();
  type = token->GetType();
  while ( 1 ) {
    if ( type == '.' || type == '[' ) {
      AstNode* literal = ParseLiteral_();
      CHECK_ERROR(literal);
      list->AddChild( literal );
      token = Seek_();
      type = token->GetType();
    } else {
      break;
    }
  }
  END(ImportExpression);
  return list;
}

AstNode* Parser::ParseDebuggerStatement_( TokenInfo* token ) {
  ENTER(DebuggerStatement);
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  value->Symbol( token );
  Expression* exp = ManagedHandle::Retain<Expression>();
  ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
  stmt->AddChild( exp );
  exp->AddChild( value );
  END(DebuggerStatement);
  return stmt;
}

AstNode* Parser::ParseVersionStatement_() {
  ENTER(VersionStatement);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  if ( type == '(' ) {
    token = Advance_();
    type = token->GetType();
    if ( type == Token::JS_IDENTIFIER ) {
      VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( token ) );
      token = Advance_();
      type = token->GetType();
      if ( type == ')' ) {
        stmt->Line( token->GetLineNumber() );
        token = Seek_();
        type = token->GetType();
        if ( type == '{' ) {
          Advance_();
          AstNode* statement = ParseStatementList_( BlockBodyMatcher , "}" );
          CHECK_ERROR( stmt );
          stmt->AddChild( statement );
          Advance_();
          END(VersionStatement);
          return stmt;
        } else {
          AstNode* statement = ParseStatement_();
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
      return ManagedHandle::Retain<Empty>();
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'version statement' expect ')' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(VersionStatementError);
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::ParseAssertStatement_() {
  ENTER(AssertStatement);
  TokenInfo *token = Seek_();
  int type = token->GetType();
  long line = token->GetLineNumber();
  if ( type == '(' ) {
    token = Advance_();
    type = token->GetType();
    AstNode* expect = ParseAssignmentExpression_( false );
    CHECK_ERROR( expect );
    token = Advance_();
    type = token->GetType();
    if ( type == ',' ) {
      AstNode* exp = ParseAssignmentExpression_( false );
      token = Advance_();
      type = token->GetType();
      if ( type == ')' ) {
        ParseTerminator_();
        CHECK_ERROR( exp );
        AssertStmt* stmt = ManagedHandle::Retain<AssertStmt>();
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
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::ParseVariableStatement_() {
  ENTER(VariableStatement);
  /*
   * [bison/yacc compat bnf syntax]
   * variable_statement
   * : JS_VAR variable_declaration_list terminator
   * | JS_CONST variable_declaration_list terminator
   * | JS_LET variable_declaration_list terminator
   * ;
   */
  TokenInfo* token = Seek_( -1 );
  VariableStmt* stmt = ManagedHandle::Retain<VariableStmt>();
  stmt->Line( token->GetLineNumber() );
  AstNode* list = ParseVariableDecl_( false );
  CHECK_ERROR(stmt);
  token = Seek_();
  int type = token->GetType();
  if ( type == ';' ) {
    Advance_();
  }
  stmt->Append( list );
  END(VariableStatement);
  return stmt;
}

AstNode* Parser::ParseVariableDecl_( bool is_noin ) {
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
  TokenInfo* maybe_assign_op = Seek_( 2 );
  int type = maybe_assign_op->GetType();
  NodeList* list = ManagedHandle::Retain<NodeList>();
  TokenInfo* next = Seek_();
  int next_type = next->GetType();
  //Get all declarations.
  //Like var x , y = 200 , z;
  while ( 1 ) {
    AstNode* var_left_hand;
    bool is_destructuring = false;
    if ( next_type == '{' || next_type == '[' ) {
      //Treat harmony destructuring.
      var_left_hand = ParseDestructuringLeftHandSide_();
      ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
      value->Node( var_left_hand );
      value->Line( var_left_hand->Line() );
      var_left_hand = value;
      CHECK_ERROR( list );
      is_destructuring = true;
      maybe_assign_op = Seek_();
      type = maybe_assign_op->GetType();
    } else if ( next_type == Token::JS_IDENTIFIER ) {
      //Normal idneifier.
      var_left_hand = ParseLiteral_();
      CHECK_ERROR( var_left_hand );
      var_left_hand->CastToValue()->ValueType( ValueNode::kVariable );
      CHECK_ERROR( list );
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( next )
                    << " in 'variable statement' expect 'variable name' or 'destructuring assignment'\\nin file "
                    << filename_ << " at line " << next->GetLineNumber() );
      END(VariableDeclError);
      return ManagedHandle::Retain<Empty>();
    }
    /*
     * We check result of Seek_( 2 ) is assignment operator or not.
     * If that is assignment operator, we treat next token list as expression,
     * if not, that is treated as just declaration.
     */
    if ( maybe_assign_op->GetType() == '=' ) {
      Advance_();
      AstNode* assignment_exp = ParseAssignmentExpression_( is_noin );
      CHECK_ERROR( list );
      var_left_hand->AddChild( assignment_exp );
      list->AddChild( var_left_hand );
    } else {
      var_left_hand->AddChild( ManagedHandle::Retain<Empty>() );
      list->AddChild( var_left_hand );
    }
    next = Seek_();
    next_type = next->GetType();
    /*
     * If next token type is semicolon or line break, declarations are end,
     * if next token type is comma, declaration is continue after,
     * if not, it's error.
     */
    if ( next_type != ',' ) {
      break;
    } else {
      Advance_();
    }
    maybe_assign_op = Seek_( 2 );
    next = Seek_();
    next_type = next->GetType();
  }
  END(VariableDecl);
  return list;
}

AstNode* Parser::ParseDestructuringLeftHandSide_() {
  ENTER(DestructuringLeftHandSide);
  /*
   * [bison/yacc compat bnf syntax]
   * destructuring_assignment_left_hand_side
   * : array_left_hand_side
   * | object_left_hand_side
   * ;
   */
  TokenInfo* token = Advance_();
  int type = token->GetType();
  if ( type == '[' ) {
    END(DestructuringLeftHandSide);
    return ParseArrayPattern_();
    //We expect error checking is already finished.
  } else {
    END(DestructuringLeftHandSide);
    return ParseObjectPattern_();
  }
}


AstNode* Parser::ParseArrayPattern_() {
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
  TokenInfo* token = Seek_();
  int type = token->GetType();
  ValueNode* destructuring = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
  destructuring->Line( token->GetLineNumber() );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  while ( 1 ) {
    //Check bracket count.
    if ( type == '[' || type == '{' ) {
      AstNode* elem = ParseDestructuringLeftHandSide_();
      CHECK_ERROR(list);
      list->AddChild( elem );
      token = Seek_();
      type = token->GetType();
      if ( type == ',' ) {
        Advance_();
      }
    } else if ( type == ']' ) {
      Advance_();
      break;
    } else {
      if ( type == ',' ) {
        list->AddChild( ManagedHandle::Retain<Empty>() );
        Advance_();
        token = Seek_();
        type = token->GetType();
        if ( type == ']' ) {
          list->AddChild( ManagedHandle::Retain<Empty>() );
          Advance_();
          break;
        }
      } else if ( type == Token::JS_IDENTIFIER ) {
        AstNode* value = ParseLiteral_();
        CHECK_ERROR( list );
        list->AddChild( value );
        token = Seek_();
        type = token->GetType();
        if ( type == ',' ) {
          Advance_();
        }
      } else if ( type == Token::JS_PARAMETER_REST ) {
        token = Advance_( 2 );
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          ValueNode* rest = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
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
    token = Seek_();
    type = token->GetType();
  }
  destructuring->AddChild( list );
  END(ArrayPattern);
  return destructuring;
}

AstNode* Parser::ParseObjectPattern_() {
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
  TokenInfo* token = Seek_();
  int type = token->GetType();
  int maybe_colon = Seek_( 2 )->GetType();
  ValueNode* destructuring = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
  destructuring->Line( token->GetLineNumber() );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  while ( 1 ) {
    if ( maybe_colon == '}' ) {
      ParseObjectPatternElement_( type , token , list );
      Advance_();
      break;
    } else if ( maybe_colon == ',' ) {
      ParseObjectPatternElement_( type , token , list );
      Advance_();
    } else if ( maybe_colon == ':' ) {
      AstNode* node = ParseLiteral_();
      Advance_();
      token = Seek_();
      type = token->GetType();
      if ( type == '[' || type == '{' ) {
        AstNode* elem = ParseDestructuringLeftHandSide_();
        CHECK_ERROR( elem );
        node->AddChild( elem );
      } else {
        ParseObjectPatternElement_( type , token , node );
      }
      CHECK_ERROR( list );
      list->AddChild( node );
      token = Advance_();
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
    token = Seek_();
    type = token->GetType();
    maybe_colon = Seek_( 2 )->GetType();
  }
  destructuring->Node( list );
  END(ObjectPattern);
  return destructuring;
}


AstNode* Parser::ParseObjectPatternElement_( int type , TokenInfo* token , AstNode* list ) {
  ENTER(ObjectPatternElement);
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* node = ParseLiteral_();
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
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::CheckLabellOrExpressionStatement_() {
  ENTER(LabellOrExpressionStatement);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  Undo_();
  if ( type == ':' ) {
    AstNode* stmt = ParseLabelledStatement_();
    CHECK_ERROR(stmt);
    stmt->Line( token->GetLineNumber() );
    END(LabellOrExpressionStatement);
    return stmt;
  } else {
    AstNode* ret = ParseExpression_( false );
    CHECK_ERROR( ret );
    ret->Line( token->GetLineNumber() );
    ParseTerminator_();
    CHECK_ERROR( ret );
    ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( ret );
    END(LabellOrExpressionStatement);
    return stmt;
  }
}


AstNode* Parser::ParseIFStatement_( bool is_comprehensions ) {
  ENTER(IFStatement);
  /*
   * [bison/yacc compat syntax]
   * if_statement
   * : JS_IF '(' expression ')' statement JS_ELSE statement 
   * | JS_IF '(' expression ')' statement
   * | JS_IF_OPT expression statement
   * ;
   */
  TokenInfo *token = Advance_();
  int type = token->GetType();
  IFStmt* if_stmt = ManagedHandle::Retain<IFStmt>();
  if_stmt->Line( token->GetLineNumber() );
  if ( type == '(' ) {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR( if_stmt );
    if_stmt->Exp( exp );
    token = Advance_();
    type = token->GetType();
    if ( type == ')' ) {
      if ( !is_comprehensions ) {
        AstNode* stmt = ParseSourceElement_();
        CHECK_ERROR( stmt );
        if_stmt->Then( stmt );
        token = Seek_();
        type = token->GetType();
        if ( type == Token::JS_ELSE ) {
          Advance_();
          AstNode* stmt = ParseSourceElement_();
          CHECK_ERROR( stmt )
          if_stmt->Else( stmt );
        } else {
          if_stmt->Else( ManagedHandle::Retain<Empty>() );
        }
      } else {
        if_stmt->Then( ManagedHandle::Retain<Empty>() );
        if_stmt->Else( ManagedHandle::Retain<Empty>() );
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


AstNode* Parser::ParseDoWhileStatement_() {
  ENTER(DoWhileStatement);
  long line = Seek_( -1 )->GetLineNumber();
  AstNode* statement = ParseSourceElement_();
  CHECK_ERROR( statement );
  TokenInfo* token = Advance_();
  int type = token->GetType();
  if ( type == Token::JS_WHILE ) {
    TokenInfo* token = Advance_();
    int type = token->GetType();
    if ( type == '(' ) {
      AstNode* node = ParseExpression_( false );
      CHECK_ERROR( statement );
      token = Advance_();
      type = token->GetType();
      if ( type == ')' ) {
        IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( IterationStmt::kDoWhile ) );
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
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
      }
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'do while statement conditional expression' expect '(' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(DoWhileStatementError);
      return ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'do while statement conditional expression' expect 'while' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(DoWhileStatementError);
    return ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
  }
}

AstNode* Parser::ParseWhileStatement_() {
  ENTER(WhileStatement);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  long line = token->GetLineNumber();
  if ( type == '(' ) {
    AstNode* node = ParseExpression_( false );
    CHECK_ERROR( node );
    token = Advance_();
    type = token->GetType();
    if ( type == ')' ) {
      IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
      iter->Line( line );
      iter->Exp( node );
      AstNode* statement = ParseSourceElement_();
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
      return ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'while statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(WhileStatementError);
    return ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
  }
}

AstNode* Parser::ParseForStatement_( bool is_comprehensions ) {
  ENTER(ForStatement);
  TokenInfo *token = Advance_();
  int type = token->GetType();
  long line = token->GetLineNumber();
  bool is_each = false;
  NodeList *exp_list = ManagedHandle::Retain<NodeList>();
  IterationStmt* iter_stmt = 0;
  if ( type == Token::JS_EACH ) {
    is_each = true;
    token = Advance_();
    type = token->GetType();
  }
  if ( type == '(' ) {
    int next_type = Seek_()->GetType();
    bool is_var_decl = false;
    int var_decl_len = 0;
    if ( next_type == Token::JS_VAR ) {
      is_var_decl = true;
      if ( is_comprehensions ) {
        SYNTAX_ERROR( "parse error in 'array comprehensions for expression' could not has variable declaration"
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
      } else {
        Advance_();
        AstNode* var_decl = ParseVariableDecl_( true );
        CHECK_ERROR( var_decl );
        exp_list->AddChild( var_decl );
        var_decl_len = var_decl->ChildLength();
      }
    } else if ( next_type != ';' ) {
      AstNode* exp = ParseExpression_( true );
      CHECK_ERROR( exp );
      exp_list->AddChild( exp );
    } else {
      exp_list->AddChild( ManagedHandle::Retain<Empty>() );
    }
    token = Advance_();
    type = token->GetType();
    if ( type == ';' && is_each == false ) {
      if ( is_comprehensions ) {
        SYNTAX_ERROR( "parse error in 'array comprehensions' allowed 'for in statement' or 'for of statement'"
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
      }
      int iter_type = ( is_var_decl )? IterationStmt::kForWithVar : IterationStmt::kFor;
      iter_stmt = ManagedHandle::Retain( new IterationStmt( iter_type ) );
      iter_stmt->Line( line );
      ParseForStatementCondition_( exp_list );
      CHECK_ERROR( iter_stmt );
    } else if ( type == Token::JS_IN ) {
      if ( var_decl_len > 1 ) {
        SYNTAX_ERROR( "parse error 'for in statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
      }
      if ( is_var_decl ) {
        AstNode* initialiser = exp_list->FirstChild()->FirstChild();
        exp_list->ReplaceChild( exp_list->FirstChild() , initialiser );
      }
      if ( is_each == false ) {
        int iter_type = ( is_var_decl )? IterationStmt::kForInWithVar : IterationStmt::kForIn;
        iter_stmt = ManagedHandle::Retain( new IterationStmt( iter_type ) );
        iter_stmt->Line( line );
      } else {
        int iter_type = ( is_var_decl )? IterationStmt::kForEachWithVar : IterationStmt::kForEach;
        iter_stmt = ManagedHandle::Retain( new IterationStmt( iter_type ) );
        iter_stmt->Line( line );
      }
      ParseForInStatementCondition_( exp_list );
      CHECK_ERROR( iter_stmt );
    } else if ( type == Token::JS_IDENTIFIER && strcmp( TokenConverter( token ) , "of" ) == 0 ) {
      if ( var_decl_len > 1 ) {
        SYNTAX_ERROR( "parse error 'for of statement' could has only one variable declaration."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
      }
      if ( is_var_decl ) {
        AstNode* initialiser = exp_list->FirstChild()->FirstChild();
        exp_list->ReplaceChild( exp_list->FirstChild() , initialiser );
      }
      if ( is_each == false ) {
        int iter_type = ( is_var_decl )? IterationStmt::kForOfWithVar : IterationStmt::kForOf;
        iter_stmt = ManagedHandle::Retain( new IterationStmt( iter_type ) );
        iter_stmt->Line( line );
      } else {
        SYNTAX_ERROR( "parse error 'for of statement' can not has 'each'."
                      "\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END(ForStatementError);
        return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
      }
      ParseForInStatementCondition_( exp_list );
      CHECK_ERROR( iter_stmt );
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'for statement conditional expression' expect 'in' , 'of' or ';' \\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(ForStatementError);
      return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'for statement conditional expression' expect '(' \\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(ForStatementError);
    return ManagedHandle::Retain( new IterationStmt( IterationStmt::kFor ) );
  }
  if ( !is_comprehensions ) {
    AstNode* body = ParseSourceElement_();
    CHECK_ERROR( iter_stmt );
    iter_stmt->AddChild( body );
  } else {
    iter_stmt->AddChild( ManagedHandle::Retain<Empty>() );
  }
  iter_stmt->Exp( exp_list );
  END(ForStatement);
  return iter_stmt;
}


void Parser::ParseForStatementCondition_( NodeList* list ) {
  ENTER(ForStatementCondition);
  if ( Seek_()->GetType() == ';' ) {
    list->AddChild( ManagedHandle::Retain<Empty>() );
  } else {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR();
    list->AddChild( exp );
  }
  TokenInfo* token = Advance_();
  int type = token->GetType();
  if ( type == ';' ) {
    if ( Seek_()->GetType() == ')' ) {
      list->AddChild( ManagedHandle::Retain<Empty>() );
    } else {
      AstNode* exp = ParseExpression_( false );
      CHECK_ERROR()
      list->AddChild( exp );
    }
    token = Advance_();
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


void Parser::ParseForInStatementCondition_( NodeList* list ) {
  ENTER(ForInStatementCondition);
  AstNode* target_exp = ParseExpression_( false );
  CHECK_ERROR();
  TokenInfo* token = Advance_();
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


AstNode* Parser::ParseContinueStatement_() {
  ENTER(ContinueStatement);
  TokenInfo *token = Seek_();
  int type = token->GetType();
  ContinueStmt* stmt = ManagedHandle::Retain<ContinueStmt>();
  stmt->Line( Seek_( -1 )->GetLineNumber() );
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* identifier = ParseLiteral_();
    CHECK_ERROR( stmt );
    stmt->AddChild( identifier );
  }
  ParseTerminator_();
  CHECK_ERROR( stmt );
  stmt->AddChild( ManagedHandle::Retain<Empty>() );
  END(ContinueStatement);
  return stmt;
}


AstNode* Parser::ParseBreakStatement_() {
  ENTER(BreakStatement);
  TokenInfo *token = Seek_();
  int type = token->GetType();
  BreakStmt* stmt = ManagedHandle::Retain<BreakStmt>();
  stmt->Line( Seek_( -1 )->GetLineNumber() );
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* identifier = ParseLiteral_();
    CHECK_ERROR( stmt );
    stmt->AddChild( identifier );
  }
  ParseTerminator_();
  CHECK_ERROR( stmt );
  stmt->AddChild( ManagedHandle::Retain<Empty>() );
  END(BreakStatement);
  return stmt;
}

AstNode* Parser::ParseReturnStatement_() {
  ENTER(ReturnStatement);
  if ( !state_stack_->Has( StateStack::kFunction ) ) {
    SYNTAX_ERROR( "return statement only allowed in 'function'\\nin file "
                  << filename_ << " at line " << Seek_( -1 )->GetLineNumber() );
    END(ReturnStatement);
    return ManagedHandle::Retain<Empty>();
  }
  bits_.Set( RETURN_FLG );
  TokenInfo *token = Seek_();
  int type = token->GetType();
  ReturnStmt* stmt = ManagedHandle::Retain<ReturnStmt>();
  stmt->Line( Seek_( -1 )->GetLineNumber() );
  if ( type == ';' || type == '}' || token->HasLineBreakBefore() ) {
    stmt->AddChild( ManagedHandle::Retain<Empty>() );
  } else {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR( stmt );
    stmt->AddChild( exp );
    ParseTerminator_();
    CHECK_ERROR( exp );
  }
  END(ReturnStatement);
  return stmt;
}


AstNode* Parser::ParseWithStatement_() {
  ENTER(WithStatement);
  TokenInfo *token = Advance_();
  int type = token->GetType();
  WithStmt* stmt = ManagedHandle::Retain<WithStmt>();
  stmt->Line( Seek_( -1 )->GetLineNumber() );
  if ( type == '(' ) {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    token = Advance_();
    type = token->GetType();
    if ( type == ')' ) {
      AstNode* statement = ParseSourceElement_();
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


AstNode* Parser::ParseSwitchStatement_() {
  ENTER(SwitchStatement);
  TokenInfo *token = Advance_();
  int type = token->GetType();
  SwitchStmt* stmt = ManagedHandle::Retain<SwitchStmt>();
  if ( type == '(' ) {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR( stmt );
    stmt->Exp( exp );
    token = Advance_();
    type = token->GetType();
    if ( type == ')' ) {
      AstNode* case_block = ParseCaseClauses_();
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

AstNode* Parser::ParseCaseClauses_() {
  ENTER(CaseClauses);
  TokenInfo *token = Advance_();
  int type = token->GetType();
  NodeList *list = ManagedHandle::Retain<NodeList>();
  if ( type == '{' ) {
    while ( type != '}' ) {
      token = Advance_();
      type = token->GetType();
      bool is_default = type == Token::JS_DEFAULT;
      if ( type == Token::JS_CASE || is_default ) {
        CaseClause* clause;
        if ( !is_default ) {
          clause = ManagedHandle::Retain<CaseClause>();
          AstNode* exp = ParseExpression_( false );
          CHECK_ERROR( clause );
          clause->Exp( exp );
        } else {
          clause = ManagedHandle::Retain<CaseClause>();
          clause->Exp( ManagedHandle::Retain<Empty>() );
        }
        clause->Line( token->GetLineNumber() );
        token = Advance_();
        type = token->GetType();
        if ( type == ':' ) {
          token = Seek_();
          type = token->GetType();
          if ( type == Token::JS_CASE ) {
            clause->AddChild( ManagedHandle::Retain<Empty>() );
            list->AddChild( clause );
          } else {
            AstNode* statement_list = ParseStatementList_( CaseBodyMatcher , "'case','default' or '}'" );
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
      token = Seek_();
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
  Advance_();
  END(CaseClause);
  return list;
}


AstNode* Parser::ParseLabelledStatement_() {
  ENTER(LabelledStatement);
  AstNode* ident = ParseLiteral_();
  CHECK_ERROR( ident )
  Advance_();
  AstNode* statement = ParseSourceElement_();
  LabelledStmt* stmt = ManagedHandle::Retain<LabelledStmt>();
  CHECK_ERROR( stmt );
  stmt->AddChild( ident );
  stmt->AddChild( statement);
  END(LabelledStatement);
  return stmt;
}

AstNode* Parser::ParseThrowStatement_() {
  ENTER(ThrowStatement);
  TokenInfo* token = Seek_( -1 );
  ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
  throw_stmt->Line( token->GetLineNumber() );
  AstNode* exp = ParseExpression_( false );
  CHECK_ERROR( throw_stmt );
  throw_stmt->Exp( exp );
  ParseTerminator_();
  CHECK_ERROR( exp );
  END(ThrowStatement);
  return throw_stmt;
}


AstNode* Parser::ParseTryStatement_() {
  ENTER(TryStatement);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  TryStmt *stmt = ManagedHandle::Retain<TryStmt>();
  if ( type == '{' ) {
    Advance_();
    AstNode* block = ParseBlockStatement_();
    CHECK_ERROR( stmt );
    stmt->AddChild( block );
    token = Seek_();
    type = token->GetType();
    if ( type == Token::JS_CATCH ) {
      AstNode* catch_block = ParseCatchBlock_();
      CHECK_ERROR( stmt );
      stmt->Catch( catch_block );
      token = Seek_();
      type = token->GetType();
    } else {
      stmt->Catch( ManagedHandle::Retain<Empty>() );
    }
    if ( type == Token::JS_FINALLY ) {
      Advance_();
      AstNode* finally_block = ParseFinallyBlock_();
      CHECK_ERROR( stmt );
      stmt->Finally( finally_block );
    } else {
      stmt->Finally( ManagedHandle::Retain<Empty>() );
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

AstNode* Parser::ParseCatchBlock_() {
  ENTER(CatchBlock);
  TokenInfo *token = Advance_( 2 );
  int type = token->GetType();
  if ( type == '(' ) {
    AstNode* ident = ParseLiteral_();
    CHECK_ERROR( ident );
    token = Advance_();
    type = token->GetType();
    if ( type == ')' ) {
      token = Seek_();
      type = token->GetType();
      if ( type != '{' ) {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'catch block' expect '{'\\nin file"
                      << filename_ << " at line " << token->GetLineNumber() );
      } else {
        Advance_();
        AstNode* block = ParseBlockStatement_();
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
  return ManagedHandle::Retain<Empty>();
}


AstNode* Parser::ParseFinallyBlock_() {
  ENTER(FinallyBlock);
  TokenInfo *token = Advance_();
  int type = token->GetType();
  if ( type == '{' ) {
    state_stack_->Push( StateStack::kFinally );
    AstNode* block = ParseBlockStatement_();
    state_stack_->Pop();
    END(FinallyBlock);
    return block;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'finally block' expect '{'\\nin file"
                  << filename_ << " at line " << token->GetLineNumber() );
    END(FinallyBlockError);
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::ParseClassDecl_( bool is_const ) {
  ENTER(ClassDecl);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  AstNode* name;
  AstNode* inherit;
  state_stack_->Push( StateStack::kClassDecl );
  if ( type == Token::JS_IDENTIFIER ) {
    name = ParseLiteral_();
    CHECK_ERROR( name );
  } else {
    name = ManagedHandle::Retain<Empty>();
  }
  token = Seek_();
  type = token->GetType();
  if ( type == Token::JS_EXTENDS ||
       ( type == Token::JS_IDENTIFIER ||
         strcmp( token->GetToken() , "prototype" ) == 0 ) ) {
    inherit = ParseInheritDecl_();
    CHECK_ERROR( inherit );
  } else {
    inherit = ManagedHandle::Retain<Empty>();
  }
  Class *cls = ManagedHandle::Retain( new Class( inherit , is_const ) );
  cls->Name( name );
  token = Advance_();
  type = token->GetType();
  if ( type == '{' ) {
    AstNode* body = ParseClassBody_();
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


AstNode* Parser::ParseInheritDecl_() {
  ENTER(InheritDecl);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  ClassExpandar* expandar;
  if ( type == Token::JS_EXTENDS ) {
    expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kExtends ) );
  } else {
    expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kPrototype ) );
  }
  AstNode* member = ParseMemberExpression_();
  CHECK_ERROR( member );
  expandar->Line( token->GetLineNumber() );
  expandar->AddChild( member );
  END(InheritDecl);
  return expandar;
}


AstNode* Parser::ParseClassBody_() {
  ENTER(ClassBody);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  if ( type == '}' ) {
    Advance_();
    END(ClassBody);
    return ManagedHandle::Retain<Empty>();
  } else {
    ClassProperties* list = ManagedHandle::Retain<ClassProperties>();
    while ( type != '}' ) {
      ClassMember* mem = ParseClassMember_();
      CHECK_ERROR( mem );
      switch ( mem->Attr() ) {
        case ClassMember::kPrivate :
          list->Private( mem );
          break;
          
        case ClassMember::kPublic :
          list->Public( mem );
          break;

        case ClassMember::kStatic :
          list->Static( mem );
          break;

        case ClassMember::kPrototype :
          list->Prototype( mem );
          break;

        case ClassMember::kConstructor :
          list->Constructor( mem );
          break;
      }
      token = Seek_();
      type = token->GetType();
    }
    Advance_();
    END(ClassBody);
    return list;
  }
}

AstNode* Parser::ParseClassMemberStatement_() {
  TokenInfo* token = Seek_( -1 );
  int type = token->GetType();
  if ( state_stack_->Has( StateStack::kClassDecl ) ) {
    ClassMember::MemberAttr member_type = ( type == Token::JS_PUBLIC )?
        ClassMember::kPublic : ( type == Token::JS_STATIC )?
        ClassMember::kStatic : ClassMember::kPrivate;
    AstNode* node = ParseExportableDefinition_();
    CHECK_ERROR( node );
    ClassMember* member = ManagedHandle::Retain( new ClassMember( member_type ) );
    member->AddChild( node );
    return member;
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << TokenConverter( token )
                  << " in 'member expression' expect '.' or '['\\nin file "
                  << filename_ << " at line " << token->GetLineNumber() );
    END(MemberExpressionError);
    return ManagedHandle::Retain<Empty>();
  }
}

ClassMember* Parser::ParseClassMember_() {
  ENTER(ClassMember);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  ClassMember::MemberAttr member_type;
  AstNode* exp;
  if ( type == Token::JS_IDENTIFIER && strcmp( token->GetToken() , "constructor" ) == 0 ) {
    exp = ParseFunctionDecl_( false );
    CHECK_ERROR(ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) ));
    exp->CastToExpression()->CastToFunction()->Decl();
    member_type = ClassMember::kConstructor;
  } else if ( type == Token::JS_STATIC ) {
    Advance_();
    exp = ParseExportableDefinition_();
    member_type = ClassMember::kStatic;
  } else if ( type == Token::JS_PRIVATE ) {
    Advance_();
    exp = ParseExportableDefinition_();
    member_type = ClassMember::kPrivate;
  } else if ( type == Token::JS_PUBLIC ) {
    Advance_();
    exp = ParseExportableDefinition_();
    member_type = ClassMember::kPublic;
  } else {
    exp = ParseExportableDefinition_();
    if ( exp->NodeType() == AstNode::kClassMember ) {
      return reinterpret_cast<ClassMember*>( exp );
    }
    member_type = ClassMember::kPrototype;
  }
  ClassMember* member = ManagedHandle::Retain( new ClassMember( member_type ) );
  member->AddChild( exp );
  END(ClassMember);
  return member;
}


AstNode* Parser::ParseExportableDefinition_() {
  ENTER(ExportableDefinition);
  TokenInfo *token = Seek_();
  int type = token->GetType();
  if ( type == Token::JS_IDENTIFIER || type == '{' || type == '[' ) {
    token = Seek_( 2 );
    type = token->GetType();
    if ( type == '(' ) {
      END(ExportableDefinition);
      return ParseFunctionDecl_( false );
    } else {
      AstNode* ret = ParseVariableDecl_( false );
      CHECK_ERROR( ret );
      ParseTerminator_();
      CHECK_ERROR( ret );
      END(ExportableDefinition);
      return ret;
    }
  } else {
    if ( type == Token::JS_CONST ) {
      token = Seek_( 2 );
      type = token->GetType();
      if ( type == Token::JS_CLASS ) {
        END(ExportableDefinition);
        return ParseClassDecl_( true );
      } else if ( type == '(' || type == Token::JS_FUNCTION_GLYPH ||
                  type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
        Advance_();
        END(ExportableDefinition);
        return ParseFunctionDecl_( true );
      } else {
        Advance_();
        AstNode* ret = ParseVariableDecl_( false );
        CHECK_ERROR( ret );
        ParseTerminator_();
        CHECK_ERROR( ret );
        END(ExportableDefinition);
        ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
        value->Line( token->GetLineNumber() );
        value->Node( ret );
        return value;
      }
    } else if ( type == Token::JS_GET ) {
      AstNode* fn = ParseFunctionDecl_( false );
      CHECK_ERROR( fn );
      fn->CastToExpression()->CastToFunction()->Attr( Function::kGet );
      END(ExportableDefinition);
      return fn;
    } else if ( type == Token::JS_SET ) {
      AstNode* fn = ParseFunctionDecl_( false );
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
      return ManagedHandle::Retain<Empty>();
    }
  }
}


AstNode* Parser::ParseExpression_( bool is_noin ) {
  ENTER(Expression);
  Expression* exp = ManagedHandle::Retain<Expression>();
  AstNode* assignment = ParseAssignmentExpression_( is_noin );
  CHECK_ERROR( exp );
  exp->AddChild( assignment );
  TokenInfo* token = Seek_();
  int type = token->GetType();
  assignment->Line( token->GetLineNumber() );
  if ( type == ',' ) {
    Advance_();
    while ( 1 ) {
      AstNode* assignment = ParseAssignmentExpression_( is_noin );
      CHECK_ERROR( exp );
      exp->AddChild( assignment );
      token = Seek_();
      type = token->GetType();
      if ( type == ',' ) {
        token = Advance_();
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

AstNode* Parser::ParseAssignmentExpression_( bool is_noin ) {
  ENTER(AssignmentExpression);
  AstNode* exp = ParseYieldExpression_( is_noin );
  CHECK_ERROR( exp );
  TokenInfo *token = Seek_();
  int type = token->GetType();
  exp->Line( token->GetLineNumber() );
  if ( IsAssignmentOp( type ) ) {
    Advance_();
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
    if ( 1/*exp->LeftHandSide()*/ ) {
      AstNode* rhs = ParseAssignmentExpression_( is_noin );
      CHECK_ERROR( rhs );
      AssignmentExp* assign_exp = ManagedHandle::Retain( new AssignmentExp( type , exp , rhs ) );
      assign_exp->Line( exp->Line() );
      return assign_exp;
    } else {
      SYNTAX_ERROR( "parse error invalid left hand side expression in 'assignment expression'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(AssignmentExpressionError);
      return ManagedHandle::Retain<Empty>();
    }
  }
  END(AssignmentExpression);
  return exp;
}

AstNode* Parser::ParseYieldExpression_( bool is_noin ) {
  ENTER(YieldExpression);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  if ( type == Token::JS_YIELD ) {
    if ( state_stack_->Has( StateStack::kFinally ) ) {
      SYNTAX_ERROR( "yield statement not allowed in 'finally block'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(YieldExpressionError);
      return ManagedHandle::Retain<Empty>();
    }
    if ( !state_stack_->Has( StateStack::kFunction ) ) {
      SYNTAX_ERROR( "yield statement only allowed in 'function'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(YieldExpressionError);
      return ManagedHandle::Retain<Empty>();
    }
    bits_.Set( YIELD_FLG );
    Advance_();
    token = Seek_();
    type = token->GetType();
    if ( token->HasLineBreakAfter() || type == ';' || type == '}' ) {
      if ( type == ';' ) {
        Advance_();
      }
      YieldExp* exp = ManagedHandle::Retain<YieldExp>();
      exp->AddChild( ManagedHandle::Retain<Empty>() );
      exp->Line( token->GetLineNumber() );
      END(YieldExpression);
      return exp;
    } else {
      YieldExp* exp = ManagedHandle::Retain<YieldExp>();
      exp->Line( token->GetLineNumber() );
      AstNode* assignment = ParseAssignmentExpression_( false );
      CHECK_ERROR( exp );
      exp->AddChild( assignment );
      END(YieldExpression);
      return exp;
    }
  } else {
    END(YieldExpression);
    return ParseConditional_( is_noin );
  }
}

AstNode* Parser::ParseConditional_( bool is_noin ) {
  ENTER(Conditional);
  AstNode* exp = ParseBinaryExpression_( is_noin );
  CHECK_ERROR( exp );
  TokenInfo* token = Seek_();
  int type = token->GetType();
  if ( type == '?' ) {
    Advance_();
    AstNode* left = ParseAssignmentExpression_( is_noin );
    CHECK_ERROR( exp );
    token = Seek_();
    type = token->GetType();
    if ( type == ':' ) {
      Advance_();
      AstNode* right = ParseAssignmentExpression_( is_noin );
      CHECK_ERROR( exp );
      ConditionalExp* cond = ManagedHandle::Retain( new ConditionalExp( exp , left , right ) );
      END(Conditional);
      return cond;
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'conditional expression' expect ':'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(ConditionalError);
      return ManagedHandle::Retain<Empty>();
    }
  } else {
    END(Conditional);
    return exp;
  }
}


AstNode* Parser::ParseBinaryExpression_( bool is_noin ) {
  ENTER(BinaryExpression);
  AstNode* last = 0;
  AstNode* first = 0;
  AstNode* lhs = ParseUnaryExpression_();
  CHECK_ERROR( lhs );
  while ( 1 ) {
    TokenInfo* token = Seek_();
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
        Advance_();
        AstNode* rhs = ParseUnaryExpression_();
        CHECK_ERROR( rhs );
        if ( last == 0 ) {
          exp = ManagedHandle::Retain( new CompareExp( type , lhs , rhs ) );
          first = exp;
        } else {
          exp = ManagedHandle::Retain( new CompareExp( type , last , rhs ) );
        }
        last = exp;
      }
        break;

      case Token::JS_IN : {
        if ( !is_noin ) {
          Advance_();
          AstNode* rhs = ParseUnaryExpression_();
          CHECK_ERROR( rhs );
          if ( last == 0 ) {
            exp = ManagedHandle::Retain( new CompareExp( type , lhs , rhs ) );
            first = exp;
          } else {
            exp = ManagedHandle::Retain( new CompareExp( type , last , rhs ) );
          }
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
        Advance_();
        AstNode* rhs = ParseUnaryExpression_();
        CHECK_ERROR( rhs );
        if ( last == 0 ) {
          exp = ManagedHandle::Retain( new BinaryExp( type , lhs , rhs ) );
          first = exp;
        } else {
          exp = ManagedHandle::Retain( new BinaryExp( type , last , rhs ) );
        }
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


AstNode* Parser::ParseUnaryExpression_() {
  ENTER(UnaryExpression);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  if ( IsUnaryOp( type ) ) {
    Advance_();
    AstNode* post_exp = ParseUnaryExpression_();
    CHECK_ERROR( post_exp );
    UnaryExp* unary = ManagedHandle::Retain( new UnaryExp( type ) );
    unary->Line( token->GetLineNumber() );
    unary->Exp( post_exp );
    END(UnaryExpression);
    return unary;
  } else {
    END(UnaryExpression);
    return ParsePostfixExpression_();
  }
}


AstNode* Parser::ParsePostfixExpression_() {
  ENTER(PostfixExpression);
  AstNode* lhs = ParseLeftHandSideExpression_();
  CHECK_ERROR( lhs );
  TokenInfo *token = Seek_();
  int type = token->GetType();
  if ( !token->HasLineBreakBefore() && ( type == Token::JS_INCREMENT || type == Token::JS_DECREMENT ) ) {
    PostfixExp* post = ManagedHandle::Retain( new PostfixExp( type ) );
    post->Line( token->GetLineNumber() );
    post->Exp( lhs );
    Advance_();
    END(PostfixExpression);
    return post;
  }
  END(PostfixExpression);
  return lhs;
}


AstNode* Parser::ParseLeftHandSideExpression_() {
  ENTER(LeftHandSideExpression);
  TokenInfo *token = Seek_();
  int type = token->GetType();
  AstNode* node;
  if ( type == Token::JS_NEW ) {
    node = ParseNewExpression_();
  } else {
    node = ParseCallExpression_();
  }
  END(LeftHandSide);
  return node;
}

NewExp* Parser::ParseNewExpression_() {
  ENTER(NewExpression);
  Advance_();
  TokenInfo* token = Seek_();
  int type = token->GetType();
  NewExp* exp = ManagedHandle::Retain<NewExp>();
  NewExp* first = exp;
  while ( type == Token::JS_NEW ) {
    Advance_();
    NewExp *next = ManagedHandle::Retain<NewExp>();
    exp->AddChild( next );
    exp = next;
    token = Seek_();
    type = token->GetType();
  }
  AstNode* member = ParseCallExpression_();
  CHECK_ERROR( exp );
  exp->AddChild( member );
  END(NewExpression);
  return first;
}

AstNode* Parser::ParseCallExpression_() {
  ENTER(CallExpression);
  AstNode* member = ParseMemberExpression_();
  CHECK_ERROR( member );
  TokenInfo* token = Seek_();
  int type = token->GetType();
  if ( type == '(' ) {
    Advance_();
    AstNode* arguments = ParseArguments_();
    CHECK_ERROR( arguments );
    token = Advance_();
    type = token->GetType();
    if ( type != ')' ) {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << TokenConverter( token )
                    << " in 'call expression' expect ')'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
    token = Seek_();
    type = token->GetType();
    bool is_function_decl = ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT );
    ValueNode* symbol = member->CastToValue();
    if ( symbol && symbol->ValueType() == ValueNode::kIdentifier && is_function_decl ) {
      Advance_();
      AstNode* fn = ParseArrowFunctionExpression_( member , arguments , type );
      CHECK_ERROR(fn);
      END(ParseCallExpression_);
      return fn;
    } else if ( is_function_decl ) {
      SYNTAX_ERROR( "parse error arrow function expression name must be 'identifier'\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
    }
    int depth = 0;
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Callable( member );
    exp->Args( arguments );
    exp->Depth( depth );
    token = Seek_();
    type = token->GetType();
    if ( type == '.' || type == '[' || type == '(' ) {
      if ( type != '(' ) {
        exp = ParseEachMember_( type , true , exp );
      }
      token = Seek_();
      type = token->GetType();
      while ( 1 ) {
        depth++;
        CallExp* ret = 0;
        if ( type != '(' ) {
          ret = ParseEachMember_( type , false , exp );
        } else if ( type == '(' ) {
          Advance_();
          AstNode* arguments = ParseArguments_();
          CHECK_ERROR( arguments );
          token = Advance_();
          type = token->GetType();
          if ( type != ')' ) {
            SYNTAX_ERROR( "parse error got unexpected token "
                          << TokenConverter( token )
                          << " in 'call expression' expect ')'\\nin file "
                          << filename_ << " at line " << token->GetLineNumber() );
            END( CallExpressionError );
            return exp;
          }
          ret = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
          ret->Callable( exp );
          if ( arguments->ChildLength() == 0 ) {
            ret->Args( ManagedHandle::Retain<Empty>() );
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
        token = Seek_();
        type = token->GetType();
      }
      END(CallExpression);
      return exp;
    } else if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance_();
      END(CallExpression);
      return ParseArrowFunctionExpression_( member , arguments , type );
    } else {
      END(CallExpression);
      return exp;
    }
  } else {
    END(CallExpression);
    return member;
  }
}


AstNode* Parser::ParseArguments_() {
  ENTER(Arguments);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  NodeList* list = ManagedHandle::Retain<NodeList>();
  if ( type != ')' ) {
    while ( type != ')' ) {
      if ( type == Token::JS_PARAMETER_REST ) {
        Advance_();
        token = Seek_();
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          AstNode* value = ParseLiteral_();
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
        AstNode* exp = ParseAssignmentExpression_( false );
        CHECK_ERROR( list );
        list->AddChild( exp );
      }
      token = Seek_();
      type = token->GetType();
      if ( type == ',' ) {
        Advance_();
        token = Seek_();
        type = token->GetType();
      }
    }
    END(Arguments);
    return list;
  } else {
    END(Arguments);
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::ParseMemberExpression_() {
  ENTER(MemberExpression);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  CallExp* exp;
  int depth = 0;
  if ( type == Token::JS_PRIVATE ) {
    TokenInfo* pr_sym = token;
    int type_cache = type;
    token = Seek_( 2 );
    type = token->GetType();
    ValueNode* private_literal = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    private_literal->Symbol( pr_sym );
    exp = ManagedHandle::Retain( new CallExp( CallExp::kPrivate ) );
    Advance_( 2 );
    AstNode *primary = ParsePrimaryExpression_();
    CHECK_ERROR( primary );
    if ( primary->CastToValue() && primary->CastToValue()->ValueType() == ValueNode::kIdentifier ) {
      primary->CastToValue()->ValueType( ValueNode::kProperty );
    }
    exp->Callable( private_literal );
    exp->Args( primary );
    exp->Depth( depth );
    token = Seek_();
    type = token->GetType();
    if ( type != '.' && type != '[' ) {
      END(MemberExpression);
      return exp;
    }
  } else {
    AstNode *primary = ParsePrimaryExpression_();
    CHECK_ERROR( primary );
    token = Seek_();
    type = token->GetType();
    if ( type != '.' && type != '[' ) {
      END(MemberExpression);
      return primary;
    }
    int call_type = ( type == '.' )? CallExp::kDot : CallExp::kBracket;
    exp = ManagedHandle::Retain( new CallExp( call_type ) );
    exp->Callable( primary );
    exp->Depth( depth );
    ParseEachMember_( type , true , exp );
    token = Seek_();
    type = token->GetType();
  }
  CallExp* first = exp;
  while ( 1 ) {
    depth++;
    CallExp* ret = ParseEachMember_( type , false , exp );
    if ( ret == 0 ) {
      END(MemberExpression);
      return exp;
    } else {
      exp = ret;
    }
    exp->Depth( depth );
    token = Seek_();
    type = token->GetType();
  }
  END(MemberExpression);
  return exp;
}


AstNode* Parser::ParseBracketMember_() {
  ENTER(BracketMember);
  Advance_();
  AstNode* node = ParseExpression_( false );
  CHECK_ERROR( node );
  TokenInfo* token = Advance_();
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


AstNode* Parser::ParseDotMember_( bool *is_extend ) {
  ENTER(DotMember);
  TokenInfo* token = Seek_();
  int next = token->GetType();
  int extend_type = Seek_( 2 )->GetType();
  if ( extend_type == '{' ) {
    *is_extend = true;
    Advance_( 2 );
    AstNode* node = ParseObjectLiteral_();
    CHECK_ERROR( node );
    return node;
  } else {
    Advance_();
    AstNode* node = ParseLiteral_();
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


CallExp* Parser::ParseEachMember_( int type , bool is_first , CallExp* exp ) {
  ENTER(EachMember);
  if ( type == '[' ) {
    AstNode* node = ParseBracketMember_();
    CHECK_ERROR( exp );
    if ( is_first ) {
      if ( exp->CallType() == CallExp::kNormal ) {
        CallExp* accessor = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
        accessor->Callable( exp );
        accessor->Args( node );
        return accessor;
      } else {
        exp->Args( node );
        END(EachMember);
        return exp;
      }
    } else {
      CallExp* accessor = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
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
    AstNode* node = ParseDotMember_( &is_extend );
    CHECK_ERROR( exp );
    if ( is_first ) {
      if ( exp->CallType() == CallExp::kNormal ) {
        int type = ( is_extend )? CallExp::kExtend : CallExp::kDot;
        CallExp* accessor = ManagedHandle::Retain( new CallExp( type ) );
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
      CallExp* accessor = ManagedHandle::Retain( new CallExp( type ) );
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


AstNode* Parser::ParsePrimaryExpression_() {
  ENTER(PrimaryExpression);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  TokenInfo* function_signature = Seek_();
  int fn_signature_type = function_signature->GetType();
  if ( type == Token::JS_FUNCTION ) {
    AstNode* fn = ParseFunctionDecl_( false );
    CHECK_ERROR( fn );
    //fn->LeftHandSide();
    END(MemberExpression);
    return fn;
  } else if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    AstNode* fn = ParseArrowFunctionExpression_( type );
    CHECK_ERROR( fn );
    //fn->LeftHandSide();
    END(MemberExpression);
    return fn;
  } else if ( type == Token::JS_IDENTIFIER && ( fn_signature_type == Token::JS_FUNCTION_GLYPH ||
                                                fn_signature_type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) ) {
    Undo_();
    END(MemberExpression);
    return ParseFunctionDecl_( false );
  } else if ( type == '{' ) {
    END(PrimaryExpression);
    return ParseObjectLiteral_();
  } else if ( type == '[' ) {
    END(PrimaryExpression);
    return ParseArrayLiteral_();
  } else if ( type == '(' ) {
    AstNode* exp = ParseExpression_( false );
    CHECK_ERROR( exp );
    token = Seek_();
    type = token->GetType();
    if ( type == ')' ) {
      Advance_();
      token = Seek_();
      type = token->GetType();
      Expression *expression = exp->CastToExpression();
      expression->Paren();
    } else {
      SYNTAX_ERROR( "parse error unmatched parensis\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      return exp;
    }
    if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance_();
      END(PrimaryExpression);
      return ParseArrowFunctionExpression_( exp , type );
    } else {
      END(PrimaryExpression);
      return exp;
    }
  } else if ( type == Token::JS_FUNCTION_GLYPH ||
              type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    AstNode* fn = ParseArrowFunctionExpression_( type );
    END(PrimaryExpression);
    return fn;
  } else {
    Undo_();
    END(PrimaryExpression);
    return ParseLiteral_();
  }
}


AstNode* Parser::ParseObjectLiteral_() {
  ENTER(ObjectLiteral);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  int maybe_colon = Seek_( 2 )->GetType();
  ValueNode* object = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
  object->Line( token->GetLineNumber() );
  if ( type != '}' ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    while ( 1 ) {
      if ( maybe_colon == '}' ) {
        AstNode* node = ParseObjectElement_( type , token , list );
        CHECK_ERROR( node );
        node->AddChild( node->Clone() );
        break;
      } else if ( maybe_colon == ',' ) {
        AstNode* node = ParseObjectElement_( type , token , list );
        CHECK_ERROR(list);
        node->AddChild( node->Clone() );
        token = Seek_();
        type = token->GetType();
      } else if ( maybe_colon == ':' ) {
        AstNode* node = ParseLiteral_();
        CHECK_ERROR( node );
        Advance_();
        token = Seek_();
        type = token->GetType();
        AstNode* assign;
        if ( type == '{' ) {
          Advance_();
          assign = ParseObjectLiteral_();
        } else {
          assign = ParseAssignmentExpression_( false );
        }
        CHECK_ERROR( assign );
        node->AddChild( assign );
        list->AddChild( node );
        token = Seek_();
        type = token->GetType();
      } else if ( type == '[' ) {
        AstNode* node = ParseObjectElement_( type , token , list );
        CHECK_ERROR( node );
        token = Advance_();
        type = token->GetType();
        if ( type == ':' ) {
          AstNode* assign;
          token = Seek_();
          type = token->GetType();
          if ( type == '{' ) {
            Advance_();
            assign = ParseObjectLiteral_();
          } else {
            assign = ParseAssignmentExpression_( false );
          }
          CHECK_ERROR(assign);
          node->AddChild( assign );
          list->AddChild( node );
          token = Seek_();
          type = token->GetType();
        }
      } else if ( maybe_colon == '(' || maybe_colon == Token::JS_FUNCTION_GLYPH ||
                  maybe_colon == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
        AstNode* fn = ParseFunctionDecl_( false );
        CHECK_ERROR( fn );
        ValueNode* val = fn->CastToExpression()->CastToFunction()->Name()->Clone()->CastToValue();
        val->AddChild( fn );
        list->AddChild( val );
        token = Seek_();
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
        Advance_();
      } else if ( type == '}' ) {
        Advance_();
        break;
      }
      token = Seek_();
      type = token->GetType();
      maybe_colon = Seek_( 2 )->GetType();
    }
    object->Node( list );
  } else {
    Advance_();
    object->Node( ManagedHandle::Retain<Empty>() );
  }
  END(ObjectLiteral);
  return object;  
}



AstNode* Parser::ParseObjectElement_( int type , TokenInfo* token , AstNode* list ) {
  ENTER(ObjectElement);
  if ( IsValidPropertyName( type ) ) {
    AstNode* node = ParseLiteral_();
    CHECK_ERROR( node );
    Advance_();
    list->AddChild( node );
    END(ObjectElement);
    return node;
  } else if ( type == '[' ) {
    Advance_();
    AstNode* node = ParseAssignmentExpression_( true );
    TokenInfo* token = Seek_();
    int next = token->GetType();
    if ( next != ']' ) {
      SYNTAX_ERROR( "in 'object literal private property' expect ']' but got " << TokenConverter( token )
                    << "\\nin file " << filename_ << " at line " << token->GetLineNumber() );
      END( ObjectElementError );
      return node;
    } else {
      Advance_();
      ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kPrivateProperty ) );
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
    return ManagedHandle::Retain<Empty>();
  }
}


AstNode* Parser::ParseArrayLiteral_() {
  ENTER(ArrayLiteral);
  ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  TokenInfo* token = Seek_();
  int type = token->GetType();
  val->Line( token->GetLineNumber() );
  int count = 0;
  if ( type == ']' ) {
    Advance_();
    END(ArrayLiteral);
    return val;
  } else {
    while ( 1 ) {
      if ( type == ',' ) {
        list->AddChild( ManagedHandle::Retain<Empty>() );
        int last_type = Seek_( -1 )->GetType();
        token = Advance_();
        type = token->GetType();
        if ( type == ']' ) {
          Advance_();
          if ( last_type == '[' ) {
            list->AddChild( ManagedHandle::Retain<Empty>() );
          }
          break;
        }
      } else if ( type == Token::JS_PARAMETER_REST ) {
        token = Advance_( 2 );
        type = token->GetType();
        if ( type == Token::JS_IDENTIFIER ) {
          ValueNode* rest = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
          rest->Line( token->GetLineNumber() );
          rest->Symbol( token );
          list->AddChild( rest );
          token = Seek_();
          type = token->GetType();
          if ( type == ']' ) {
            Advance_();
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
        AstNode* node = ParseAssignmentExpression_( false );
        CHECK_ERROR( node );
        list->AddChild( node );
        token = Seek_();
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
          AstNode* node = ParseArrayComprehensions_();
          CHECK_ERROR( node );
          list->AddChild( node );
          token = Seek_();
          type = token->GetType();
          if ( type != ']' ) {
            SYNTAX_ERROR( "parse error got unexpected token "
                          << TokenConverter( token )
                          << " in 'array comprehensions expect' ']'\\nin file "
                          << filename_ << " at line " << token->GetLineNumber() );
            END(ArrayLiteralError);
            return val;
          }
          val->Append( node );
          val->ValueType( ValueNode::kArrayComp );
          END(ArrayLiteral);
          return val;
        } else if ( type == ',' ) {
          Advance_();
          token = Seek_();
          type = token->GetType();
        } else if ( type == ']' ) {
          Advance_();
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


AstNode* Parser::ParseLiteral_() {
  ENTER(Literal);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  int value_type = 0;
  switch ( type ) {
    case Token::JS_THIS :
      value_type = ValueNode::kThis;
      break;

    case Token::JS_IDENTIFIER :
      value_type = ValueNode::kIdentifier;
      break;

    case Token::JS_TRUE :
      value_type = ValueNode::kTrue;
      break;

    case Token::JS_FALSE :
      value_type = ValueNode::kFalse;
      break;

    case Token::JS_NUMERIC_LITERAL :
      value_type = ValueNode::kNumeric;
      break;

    case Token::JS_STRING_LITERAL :
      value_type = ValueNode::kString;
      break;

    case Token::JS_REGEXP_LITERAL :
      value_type = ValueNode::kRegExp;
      break;

    case Token::JS_K_NULL :
      value_type = ValueNode::kNull;
      break;

    default : {
      SYNTAX_ERROR( "parse error got unexpected token '"
                    << TokenConverter( token )
                    << "' expect " << literals << "\\nin file "
                    << filename_ << " at line " << token->GetLineNumber() );
      END(LiteralError);
      return ManagedHandle::Retain<Empty>();
    }
  }
  //assert( value_type != 0 );
  ValueNode* value = ManagedHandle::Retain( new ValueNode( value_type ) );
  value->Line( token->GetLineNumber() );
  value->Symbol( token );
  END(Literal);
  return value;
}


bool IsValidFormalParameter( int type ) {
  return type == Token::JS_IDENTIFIER || type == '{' || type == '[' || type == Token::JS_THIS || type == Token::JS_PRIVATE;
}


AstNode* Parser::ParseFunctionDecl_( bool is_const ) {
  ENTER(FunctionDecl);
  TokenInfo* token = Seek_();
  int type = token->GetType();
  Function* fn = ManagedHandle::Retain<Function>();
  if ( type == Token::JS_IDENTIFIER ) {
    AstNode* name = ParseLiteral_();
    CHECK_ERROR( name );
    fn->Name( name );
    token = Seek_();
    type = token->GetType();
  } else {
    fn->Name( ManagedHandle::Retain<Empty>() );
  }
  
  if ( type == '(' ) {
    Advance_();
    token = Seek_();
    type = token->GetType();
    if ( type != ')' ) {
      AstNode* list = ParseFormalParameter_();
      fn->Argv( list );
      token = Advance_( 2 );
      type = token->GetType();
    } else {
      fn->Argv( ManagedHandle::Retain<Empty>() );
      token = Advance_( 2 );
      type = token->GetType();
    }
  } else {
    fn->Argv( ManagedHandle::Retain<Empty>() );
    token = Seek_();
    type = token->GetType();
    if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      Advance_();
    }
  }

  if ( type == Token::JS_FUNCTION_GLYPH || type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      fn->ContextType( Function::kThis );
    }
    token = Seek_();
    type = token->GetType();
    if ( type == '{' ) {
      Advance_();
      state_stack_->Push( StateStack::kFunction );
      bool has_return = bits_.At( RETURN_FLG );
      bool has_yield = bits_.At( YIELD_FLG );
      bits_.UnSet( RETURN_FLG );
      bits_.UnSet( YIELD_FLG );
      AstNode* body = ParseStatementList_( BlockBodyMatcher , "}" );
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
      Advance_();
      return fn;
    } else {
      AstNode* node = ParseAssignmentExpression_( false );
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
      AstNode* body = ParseStatementList_( BlockBodyMatcher , "}" );
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
      Advance_();
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


AstNode* Parser::ParseFormalParameter_() {
  ENTER( FormalParameter );
  TokenInfo* token = Seek_();
  int type = token->GetType();
  NodeList* list = ManagedHandle::Retain<NodeList>();
  while ( type != ')' && !IsEnd( type ) ) {
    if ( IsValidFormalParameter( type ) ) {
      AstNode* node;
      if( type == '{' || type == '[' ){
        node = ParseDestructuringLeftHandSide_();
        CHECK_ERROR(node);
        node->Line( token->GetLineNumber() );
        ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
        value->Node( node );
        token = Seek_();
        type = token->GetType();
        if ( type == '=' ) {
          AstNode* exp = ParseAssignmentExpression_( false );
          CHECK_ERROR(exp);
          value->AddChild( exp );
        } else {
          value->AddChild( ManagedHandle::Retain<Empty>() );
        }
        node = value;
      } else {
        node = ParseAssignmentExpression_( false );
        CHECK_ERROR( node );
        node->Line( token->GetLineNumber() );
        AssignmentExp* exp = node->CastToExpression()->CastToAssigment();
        if ( exp ) {
          ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
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
      token = Seek_();
      type = token->GetType();
      if ( type != ')' && type != ',' ) {
        SYNTAX_ERROR( "parse error got unexpected token "
                      << TokenConverter( token )
                      << " in 'formal parameter' expect ')' or ','\\nin file "
                      << filename_ << " at line " << token->GetLineNumber() );
        END( FormalParameterError );
        return list;
      } else if ( type == ',' ) {
        Advance_();
      } else if ( type == ')' ) {
        break;
      }
      token = Seek_();
      type = token->GetType();
    } else if ( type == Token::JS_PARAMETER_REST ) {
      Advance_();
      token = Seek_();
      type = token->GetType();
      if ( type == Token::JS_IDENTIFIER ) {
        AstNode* value = ParseLiteral_();
        CHECK_ERROR( value );
        value->Line( token->GetLineNumber() );
        value->CastToValue()->ValueType( ValueNode::kRest );
        token = Seek_();
        type = token->GetType();
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
        token = Advance_();
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


AstNode* Parser::ParseArrowFunctionExpression_( AstNode* exp , int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = ManagedHandle::Retain<Function>();
  if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    fn->ContextType( Function::kThis );
  }
  NodeList* list = ManagedHandle::Retain<NodeList>();
  FormalParameterConvertor( exp , list );
  fn->Argv( list );
  fn->Name( ManagedHandle::Retain<Empty>() );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody_( fn );
}

AstNode* Parser::ParseArrowFunctionExpression_( AstNode* member , AstNode* args , int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = ManagedHandle::Retain<Function>();
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
  NodeList* list = ManagedHandle::Retain<NodeList>();
  FormalParameterConvertor( args , list );
  fn->Argv( list );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody_( fn );
}

AstNode* Parser::ParseArrowFunctionExpression_( int type ) {
  ENTER(ArrowFunctionExpression);
  Function* fn = ManagedHandle::Retain<Function>();
  if ( type == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
    fn->ContextType( Function::kThis );
  }
  fn->Argv( ManagedHandle::Retain<Empty>() );
  fn->Name( ManagedHandle::Retain<Empty>() );
  END( ArrowFunctionExpression );
  return ParseArrowFunctionBody_( fn );
}

AstNode* Parser::ParseArrowFunctionBody_( Function* fn ) {
  ENTER(ArrowFunctionBody);
  TokenInfo* token = Seek_();
  int token_type = token->GetType();
  if ( token_type == '{' ) {
    Advance_();
    state_stack_->Push( StateStack::kFunction );
    bool has_return = bits_.At( RETURN_FLG );
    bool has_yield = bits_.At( YIELD_FLG );
    bits_.UnSet( RETURN_FLG );
    bits_.UnSet( YIELD_FLG );
    AstNode* list = ParseStatementList_( BlockBodyMatcher , "}" );
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
    Advance_();
  } else {
    AstNode* node = ParseAssignmentExpression_( false );
    CHECK_ERROR( node );
    fn->AddChild( node );
    fn->FunctionType( Function::kShorten );
  }
  END( ArrowFunctionBody );
  return fn;
}


AstNode* Parser::ParseArrayComprehensions_() {
  ENTER(ArrayComprehensions);
  TokenInfo* token = Advance_();
  int type = token->GetType();
  NodeList *list = ManagedHandle::Retain<NodeList>();
  while ( type == Token::JS_FOR ) {
    AstNode* node = ParseForStatement_( true );
    CHECK_ERROR( node );
    list->AddChild( node );
    token = Advance_();
    type = token->GetType();
  }
  if ( type == Token::JS_IF ) {
    AstNode* if_stmt = ParseIFStatement_( true );
    CHECK_ERROR( if_stmt );
    list->AddChild( if_stmt );
  } else {
    Undo_();
  }
  END( ArrayComprehensions );
  return list;
}
}
