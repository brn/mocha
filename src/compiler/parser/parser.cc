#include <compiler/parser/parser.h>

namespace mocha {

const char use_strict[] = { "use strict" };
const char import_from[] = { "from" };

TokenInfo* Advance( ParserConnector* connector ) {
  return connector->InvokeScanner( true );
}

TokenInfo* CurToken( ParserConnector* connector ) {
  return connector->InvokeScanner( false );
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
  while ( ( type = Advance( connector_ ) ) && type->GetType() != Token::END ) {
    AstNode* statement = ParseSourceElement();
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
  TokenInfo* info = CurToken( connector_ );
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
  TokenInfo* info = CurToken( connector );
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
  bool has_statement_list = false;
  while ( ( info = Advance( connector ) ) && info->GetType() != '}' ) {
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
  TokenInfo* r_module = CurToken( connector_ );
  if ( r_module->GetType() == Token::JS_MODULE ) {
    ModuleStmt* module_stmt = ManagedHandle::Retain<ModuleStmt>();
    TokenInfo* info = Advance( connector_ );
    if ( info->GetType() == Token::JS_IDENTIFIER ) {
      Advance( connector_ );
      module_stmt->Name( info );
    } else {
      module_stmt->Name( ManagedHandle::Retain<Empty>() );
    }
    AstNode* statement = ParseStatement_();
    module_stmt->Line( r_module->GetLineNumber() );
    module_stmt->AddChild( statement );
    return module_stmt;
  }
}

AstNode* Parser::ParseExportStatement_() {
  /*
   *export_statement
   *: JS_EXPORT exportable_definition
   */
  TokenInfo* r_export = CurToken( connector_ );
  if ( r_export->GetType() == Token::JS_EXPORT ) {
    ExportStmt* export_stmt = ManagedHandle::Retain<ExportStmt>();
    export_stmt->Line( r_export->GetLineNumber() );
    AstNode* exportable = ParseExportableDefinition_();
    export_stmt->AddChild( exportable );
    return module_stmt;
  }
}

AstNode* Parser::ParseImportStatement_() {
  /*
   *import_statement
   *: JS_IMPORT JS_IDENTIFIER JS_FROM import_expression terminator
   */
  TokenInfo* r_import = CurToken( connector_ );
  if ( r_import->GetType() == Token::JS_IMPORT ) {
    ImportStmt* stmt = ManagedHandle::Retain<ImportStmt>();
    TokenInfo* val = Advance( connector_ );
    if ( val->GetType() == Token::JS_IDENTIFIER ) {
      AstNode* identifier = ParseLiteral_();
      stmt->Exp( identifier );
    } else if ( val->GetType() == '{' || val->GetType() == '[' ) {
      AstNode* destructuring = ParseDestructuringLeftHandSide_();
      stmt->Exp( destructuring );
    }
    TokenInfo* r_from = Advance( connector_ );
    if ( r_from->GetType() == Token::JS_IDENTIFIER &&
         strlen( r_from->GetToken() ) > 0 && strcmp( r_from , import_from ) ) {
      ValueNode* exp = ParseImportExpression_();
      if ( CurToken( connector_ )->GetType() == Token::JS_LINE_BREAK ||
           CurToken( connector_ )->GetType() == ';' ) {
        
      }
    }
  }
}

}
