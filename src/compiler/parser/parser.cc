#include <compiler/parser/parser.h>

namespace mocha {

const char use_strict[] = { "use strict" };
const char import_from[] = { "from" };

#define SYNTAX_ERROR( msg ) {\
  std::stringstream st;      \
  st << msg;                 \
  reporter_->ReportSyntaxError( st.str().c_str )        \
}

#define RECOVERY {                                                      \
    int type = 0;                                                       \
    while ( ( type = Advance_()->GetType() ) &&                         \
            ( type != ';' || type != Token::JS_LINE_BREAK ||            \
              type != Token::END || type != Token::END_OF_INPUT ) ){}   \
  }

Parser::Parser( ParserConnector* connector , ParserInfo* info , ParserEnv* env )
    : connector_( connector ) , info_( info ) , env_( env ) {}
Parser::~Parser() {}

AstRoot* Parser::ParseProgram_() {
  /*
   *program
   * : source_elements
   */
  NodeList* list = ManagedHandle::Retain<NodeList>();
  ParseSourceElement_( list );
}

void Parser::ParseSourceElements_( NodeList* list ) {
  /*
   *source_elements
   *: source_element
   *| source_elements source_element
   */
  TokenInfo* type;
  while ( ( type = Seek_( 1 ) ) && type->GetType() != Token::END || type->GetType() != Token::END_OF_INPUT ) {
    AstNode* statement = ParseSourceElement_();
    //check "use strict" prologue directive.
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
    }
    list->AddChild( statement );
  }
}

AstNode* Parser::ParseSourceElement_() {
  /*
   *source_element
   * : statement
   */
  TokenInfo* info = Advance_();
  AstNode* result = 0;//init after;
  switch ( info->GetType() ) {
    case Token::kClass :
      result = ParseClassDecl_();
      break;
    case Token::kFunction :
      result = ParseFunctionDecl_();
      break;
    case Token::kConst :
      result = ParseVariableDecl_();
      break;
    case Token::kLet :
        result = ParseLetDeclOrLetStatement_();
    default :
      result = ParseStatement_();
  }
  return result;
}

AstNode* Parser::ParseStatement_() {
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
  TokenInfo* info = Seek_( -1 );
  switch ( info->GetType() ) {
    case '{' :
      return ParseBlockStatement_();
      
    case Token::JS_MODULE :
      return ParseModuleStatement_();
      
    case Token::JS_EXPORT :
      return ParseExportStatement_();
      
    case Token::JS_VAR :
    case Token::JS_LET :
    case Token::JS_CONST :
      return ParseVariableStatement_();
      
    case ';' :
    case Token::JS_LINE_BREAK :
      return ManagedHandle::Retain<Empty>();
      
    case Token::JS_IF :
      return ParseIFStatement_();
      
    case Token::JS_FOR :
      return ParseForStatement_();
      
    case Token::JS_WHILE :
      return ParseWhileStatement_();
      
    case Token::JS_DO :
      return ParseDoWhileStatement_();
      
    case Token::JS_CONTINUE :
      return ParseContinueStatement_();
      
    case Token::JS_BREAK :
      return ParseBreakStatement_();
      
    case Token::JS_RETURN :
      return ParseReturnStatement_();
      
    case Token::JS_WITH :
      return ParseWithStatement_();
      
    case Token::JS_SWITCH :
      return ParseSwitchStatement_();
      
    case Token::JS_THROW :
      return ParseThrowStatement_();
      
    case Token::JS_TRY :
      return ParseTryStatement_();
      
    case Token::JS_IMPORT :
      return ParseImportStatement_();
      
    case Token::MOCHA_VERSIONOF :
      return ParseVersionStatement_();
      
    case Token::JS_FUNCTION :
      return ParseFunctionDecl_();
      
    case Token::JS_DEBUGGER :
      return ParseDebuggerStatement_();
      
    default :
      return CheckLabellOrExpressionStatement_();
  }
}

AstNode* Parser::ParseBlockStatement_() {
  /*
   *block
   *: '{' '}'
   *| '{' statement_list '}'
   */
  BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
  StatementList* list = ManagedHandle::Retain<StatementList>();
  TokenInfo* info = 0;//init after
  //Check block statement has body or not.
  //If block body is empty -> {}, set Empty node to block body.
  bool has_statement_list = false;
  while ( ( info = Advance_() ) && info->GetType() != '}' ) {
    has_statement_list = true;
    AstNode* statement = ParseStatement_();
    list->AddChild( statement );
  }
  if ( !has_statement_list ) {
    block->AddChild( ManagedHandle::Retain<Empty>() );
  } else {
    block->AddChild( list );
  }
  return block;
}

AstNode* Parser::ParseModuleStatement_() {
  /*
   *module_statement
   *: JS_MODULE identifier__opt statement
   *;
   */
  ModuleStmt* module_stmt = ManagedHandle::Retain<ModuleStmt>();
  TokenInfo* info = Seek_( 1 );
  if ( info->GetType() == Token::JS_IDENTIFIER ) {
    connector_->Advance();
    module_stmt->Name( info );
  } else {
    module_stmt->Name( ManagedHandle::Retain<Empty>() );
  }
  AstNode* statement = ParseStatement_();
  module_stmt->Line( info->GetLineNumber() );
  module_stmt->AddChild( statement );
  return module_stmt;
}

AstNode* Parser::ParseExportStatement_() {
  /*
   *export_statement
   *: JS_EXPORT exportable_definition
   */
  ExportStmt* export_stmt = ManagedHandle::Retain<ExportStmt>();
  AstNode* exportable = ParseExportableDefinition_();
  export_stmt->Line( exportable->Line() );
  export_stmt->AddChild( exportable );
  return module_stmt;
}

AstNode* Parser::ParseImportStatement_() {
  /*
   *import_statement
   *: JS_IMPORT JS_IDENTIFIER JS_FROM import_expression terminator
   */
  ImportStmt* stmt = ManagedHandle::Retain<ImportStmt>();
  TokenInfo* val = Seek_();
  if ( val->GetType() == Token::JS_IDENTIFIER ) {
    AstNode* identifier = ParseLiteral_();
    stmt->Exp( identifier );
  } else if ( val->GetType() == '{' || val->GetType() == '[' ) {
    AstNode* destructuring = ParseDestructuringLeftHandSide_();
    stmt->Exp( destructuring );
  }
  TokenInfo* r_from = connector_->Advance();
  if ( r_from->GetType() == Token::JS_IDENTIFIER &&
       strlen( r_from->GetToken() ) > 0 && strcmp( r_from , import_from ) == 0 ) {
    ValueNode* exp = ParseImportExpression_();
    stmt->From( exp );
    TokenInfo* semicolon = connector_->Seek();
    int type = semicolon->GetType();
    if ( type != Token::JS_LINE_BREAK && type != ';' ) {
      SYNTAX_ERROR( "parse error unexpected token "
                    << semicolon->GetToken()
                    << "after 'import statement' expect ';' or 'line break'\nin file "
                    << filename_ << " at line " << semicolon->GetLineNumber() );
      RECOVERY;
    }
  } else {
    SYNTAX_ERROR( "parse error got unexpected token "
                  << r_from->GetToken()
                  << "after 'import' expect 'from'\nin file "
                  << filename_ << " at line " << semicolon->GetLineNumber() );
    RECOVERY;
  }
  return stmt;
}


AstNode* ParseVariableStatement_() {
  /*
   * [bison/yacc compat bnf syntax]
   * variable_statement
   * : JS_VAR variable_declaration_list terminator
   * | JS_CONST variable_declaration_list terminator
   * | JS_LET variable_declaration_list terminator
   * ;
   */
  VariableStmt* stmt = ManagedHandle::Retain<VariableStmt>();
  AstNode* list = ParseVariableDecl_( false );
  stmt->AddChild( list );
  return stmt;
}

AstNode* ParseVariableDecl_( bool is_noin ) {
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
  //Get all declarations.
  //Like var x , y = 200 , z;
  while ( type != ';' && type != Token::JS_LINE_BREAK ) {
    TokenInfo* next;
    int next_type = Seek_( 1 )->GetType();
    AstNode* var_left_hand;
    bool is_destructuring = false;
    if ( next_type == '{' || next_type == '[' ) {
      //Treat harmony destructuring.
      var_left_hand = ParseDestructuringLeftHandSide_();
      is_destructuring = true;
    } else if ( next_type == Token::JS_IDENTIFIER ) {
      //Normal idneifier.
      var_left_hand = ParseLiteral_();
    } else {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << next->GetToken()
                    << " in 'variable statement' expect 'variable name' or 'destructuring assignment'\nin file "
                    << filename_ << " at line " << next->GetLineNumber() );
      RECOVERY;
    }
    /*
     * We check result of Seek_( 2 ) is assignment operator or not.
     * If that is assignment operator, we treat next token list as expression,
     * if not, that is treated as just declaration.
     */
    if ( maybe_assign_op->GetType() == '=' ) {
      AstNode* assignment_exp = ParseAssignmentExpression_( is_noin );
      var_left_hand->AddChild( assignment_exp );
      list->AddChild( var_left_hand );
    } else {
      var_left_hand->AddChild( ManagedHandle::Retain<Empty>() );
      list->AddChild( var_left_hand );
    }
    next = Advance();
    next_type = next->GetType();
    /*
     * If next token type is semicolon or line break, declarations are end,
     * if next token type is comma, declaration is continue after,
     * if not, it's error.
     */
    if ( next_type == ';' || next_type == Token::JS_LINE_BREAK ) {
      break;
    } else if ( next_type != ',' ) {
      SYNTAX_ERROR( "parse error got unexpected token "
                    << next->GetToken()
                    << "after 'variable statement' expect ',' or ';' , 'line break'\nin file "
                    << filename_ << " at line " << next->GetLineNumber() );
      RECOVERY;
    }
    maybe_assign_op = Seek_( 2 );
  }
  return list;
}

AstNode* ParseDestructuringLeftHandSide_() {
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
    return ParseArrayPattern_();
    //We expect error checking is already finished.
  } else {
    return ParseObjectPattern_();
  }
}


AstNode* ParseArrayPattern_() {
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
  int brack_count = 1;
  int type = token->GetType();
  ValueNode* destructuring = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
  destructuring->Line( token->GetLineNumber() );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  while ( brack_count > 0 ) {
    //Check bracket count.
    if ( type == '[' ) {
      brack_count++;
    } else if ( type == ']' ) {
      brack_count--;
    } else {
      if ( type == ',' ) {
        list->AddChild( ManagedHandle::Retain<Empty>() );
        Advance_();
      } else if ( type == Token::JS_IDENTIFIER ) {
        AstNode* value = ParseLiteral_();
        list->AddChild( value );
      } else if ( type == Token::JS_REST ) {
        AstNode* rest = ParseParameterRest_();
        list->AddChild( rest );
      } else {
        //In destructuring assignemtn, if array pattern used,
        //it's element is only allowed JS_IDENTIFIER or JS_REST.
        SYNTAX_ERROR( "parse error got undexpected token "
                      << token->GetToken()
                      << " in 'destructuring assignment array pattern' "
                      "element is only allowed 'identifier' or 'parameter rest'.\nin file '"
                      << filename_ << " at line "
                      << token->GetLineNumber() );
        RECOVERY;
        break;
      }
    }
    token = Seek_();
    type = token->GetType();
  }
  destructuring->AddChild( list );
  return destructuring;
}

}
