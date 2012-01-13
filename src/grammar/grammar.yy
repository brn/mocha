%{
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <compiler/compiler.h>
#include <compiler/tokens/token_info.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/binding/parser_connector.h>
#include <compiler/binding/yylex.h>
#include <ast/ast.h>
#include <ast/visitors/ast_transformer.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/pool/managed_handle.h>

  using namespace std;
  using namespace mocha;
#define BINARY_ACTION(type,_1,_3,_4)                                 \
  BinaryExp* binary = ManagedHandle::Retain( new BinaryExp( type , _1 , _3 ) ); \
  binary->Line( connector->GetLineNumber() );                           \
  _4 = binary;                                                          \

#define COMPARE_ACTION(type,_1,_3,_4)                                   \
  CompareExp* compare = ManagedHandle::Retain( new CompareExp( type , _1 , _3 ) ); \
  compare->Line( connector->GetLineNumber() );                           \
  _4 = compare;                                                         \

  Empty* GetEmptyNode() {
    return ManagedHandle::Retain<Empty>();
  }
  
%}

%code requires {
#include <ast/ast.h>
  namespace mocha {
  class Compiler;
  class AstTypeBase;
  class ParserConnector;
  class ParserTracer;
  class TokenInfo;
  class Scope;
  }
#define YYDEBUG 1
}

%union{
  mocha::TokenInfo *info;
  mocha::AstNode *ast;
  mocha::FileRoot *file_root;
  mocha::Statement *statement;
  mocha::StatementList* statement_list;
  mocha::Expression *expression;
  mocha::ValueNode *value_node;
  mocha::CaseClause *case_clause;
  mocha::NodeList* node_list;
  mocha::BlockStmt* block;
  mocha::ModuleStmt *module_stmt;
  mocha::ExportStmt* export_stmt;
  mocha::VariableStmt *variable_stmt;
  mocha::LetStmt *let_stmt;
  mocha::ExpressionStmt *expression_stmt;
  mocha::IFStmt *if_stmt;
  mocha::IterationStmt *iteration_stmt;
  mocha::ContinueStmt *continue_stmt;
  mocha::ReturnStmt *return_stmt;
  mocha::BreakStmt *break_stmt;
  mocha::WithStmt *with_stmt;
  mocha::LabelledStmt *labelled_stmt;
  mocha::SwitchStmt *switch_stmt;
  mocha::ThrowStmt *throw_stmt;
  mocha::TryStmt *try_stmt;
  mocha::Function *function;
  mocha::CallExp *call_exp;
  mocha::NewExp *new_exp;
  mocha::PostfixExp *postfix;
  mocha::UnaryExp *unary_exp;
  mocha::BinaryExp *binary_exp;
  mocha::CompareExp *compare_exp;
  mocha::ConditionalExp *conditional;
  mocha::AssignmentExp *assignment;
  mocha::Class* cls;
  mocha::ClassProperties* prop;
  mocha::YieldExp* yield_exp;
  bool opt;
  int num;
} 

// Bison
%error-verbose
%defines
%language "c++"
%skeleton "lalr1.cc"
%define "parser_class_name" "ParserImplementation"
%parse-param { mocha::Compiler* compiler }
%parse-param { mocha::ParserConnector* connector }
%parse-param { mocha::ParserTracer *tracer }
%parse-param { mocha::AstRoot* ast_root}
%lex-param	 { mocha::ParserConnector* connector }
%lex-param {int yystate}
%expect 60
%left ','
%right JS_ADD_LET JS_AND_LET JS_DIV_LET JS_MOD_LET JS_MUL_LET JS_NOT_LET JS_OR_LET JS_SHIFT_LEFT_LET JS_SHIFT_RIGHT_LET JS_SUB_LET JS_U_SHIFT_RIGHT_LET
%right '?'
%right JS_LOGICAL_OR
%left JS_LOGICAL_AND
%left '|'
%left '^'
%left '&'
%left JS_EQ JS_EQUAL JS_NOT_EQUAL JS_NOT_EQ
%left '>' '<' JS_GREATER_EQUAL JS_LESS_EQUAL JS_IN JS_INSTANCEOF
%left JS_SHIFT_LEFT JS_SHIFT_RIGHT JS_U_SHIFT_RIGHT JS_U_SHIFT_LEFT
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' JS_INCREMENT JS_DECREMENT JS_TYPEOF JS_VOID JS_DELETE
%left '(' JS_NEW
%left '[' '.'
%left BRACKET

%token <info> JS_ABSTRACT
%token <info> JS_ADD_LET
%token <info> JS_AND_LET
%token <info> JS_BOOLEAN
%token <info> JS_BREAK
%token <info> JS_BYTE
%token <info> JS_CASE
%token <info> JS_CATCH
%token <info> JS_CHAR
%token <info> JS_CLASS
%token <info> JS_CONST
%token <info> JS_CONTINUE
%token <info> JS_DEBUGGER
%token <info> JS_DECREMENT
%token <info> JS_DEFAULT
%token <info> JS_DELETE
%token <info> JS_DIV_LET
%token <info> JS_DO
%token <info> JS_DOUBLE
%token <info> JS_ELSE
%token <info> JS_ENUM
%token <info> JS_EQ
%token <info> JS_EQUAL
%token <info> JS_EXPORT
%token <info> JS_EXTENDS
%token <info> JS_FALSE
%token <info> JS_FINAL
%token <info> JS_FINALLY
%token <info> JS_FLOAT
%token <info> JS_FOR
%token <info> JS_COMP_FOR
%token <info> JS_FUNCTION
%token <info> JS_GOTO
%token <info> JS_GRATER_EQUAL
%token <info> JS_IDENTIFIER
%token <info> JS_IF
%token <info> JS_IF_OPT
%token <info> JS_IMPLEMENTS
%token <info> JS_IMPORT
%token <info> JS_IN
%token <info> JS_INCREMENT
%token <info> JS_INSTANCEOF
%token <info> JS_INT
%token <info> JS_INTERFACE
%token <info> JS_LESS_EQUAL
%token <info> JS_LOGICAL_AND
%token <info> JS_LOGICAL_OR
%token <info> JS_LONG
%token <info> JS_MOD_LET
%token <info> JS_MUL_LET
%token <info> JS_NATIVE
%token <info> JS_NEW
%token <info> JS_NOT_EQ
%token <info> JS_NOT_EQUAL
%token <info> JS_NOT_LET
%token <info> JS_K_NULL
%token <info> JS_NUMERIC_LITERAL
%token <info> JS_OR_LET
%token <info> JS_PRIVATE
%token <info> JS_PACKAGE_RESERVED
%token <info> JS_PROTECTED
%token <info> JS_PUBLIC
%token <info> JS_REGEXP_LITERAL
%token <info> JS_RETURN
%token <info> JS_SHIFT_LEFT
%token <info> JS_SHIFT_LEFT_LET
%token <info> JS_SHIFT_RIGHT
%token <info> JS_SHIFT_RIGHT_LET
%token <info> JS_SHORT
%token <info> JS_STATIC
%token <info> JS_STRING_LITERAL
%token <info> JS_SUB_LET
%token <info> JS_SUPER
%token <info> JS_SWITCH
%token <info> JS_SYNCHRONIZED
%token <info> JS_THIS
%token <info> JS_THROW
%token <info> JS_THROWS
%token <info> JS_TRANSIENT
%token <info> JS_TRUE
%token <info> JS_TRY
%token <info> JS_TYPEOF
%token <info> JS_U_SHIFT_RIGHT
%token <info> JS_U_SHIFT_RIGHT_LET
%token <info> JS_VAR
%token <info> JS_VOID
%token <info> JS_VOLATILE
%token <info> JS_WHILE
%token <info> JS_WITH
%token <info> JS_TERMINATE
%token <line> JS_LINE_BREAK
%token <info> JS_FUNCTION_GLYPH
%token <info> JS_FUNCTION_GLYPH_WITH_CONTEXT
%token <info> JS_FUNCTION_IDENTIFIER
%token <info> JS_PARAM_BEGIN
%token <info> JS_PARAM_END
%token <info> JS_DOBJECT_BEGIN
%token <info> JS_DOBJECT_END
%token <info> JS_FORMAL_PARAMETER_IDENT
%token <info> JS_LET
%token <info> JS_EACH
%token <info> JS_PARAMETER_REST
%token <info> JS_MODULE
%token <info> JS_EXP_CLOSURE_BEGIN 
%token <info> JS_EXP_CLOSURE_END
%token <info> JS_FROM
%token <info> JS_DSTA_BEGIN
%token <info> JS_DSTO_BEGIN
%token <info> JS_DSTA_END
%token <info> JS_DSTO_END
%token <info> JS_CONSTRUCTOR
%token <info> JS_GET
%token <info> JS_SET
%token <info> JS_PROTOTYPE
%token <info> MOCHA_VERSIONOF
%token <info> JS_PROPERTY
%token <info> JS_YIELD
%token <info> JS_YIELD_SENTINEL
%token <info> EX_TOKEN_YIELD
%token <info> MOCHA_PRAGMA

%type <ast> program
%type <function> function_declaration
%type <function> function_expression
%type <node_list> formal_parameter_list
%type <node_list> formal_parameter_list_with_rest
%type <ast> formal_parameter_rest__opt
%type <ast> formal_parameter_list__opt
%type <node_list> function_body
%type <node_list> constructor_function_body
%type <ast> shorten_function_body
%type <node_list> source_elements
%type <ast> source_element
%type <node_list> source_elements_for_constructor
%type <ast> source_element_for_constructor
%type <node_list> source_elements_for_function
%type <ast> source_element_for_function
%type <ast> identifier__opt
%type <ast> statement
%type <ast> statement_no_block
%type <ast> statement_with_block
%type <ast> empty_statement
%type <block> block
%type <ast> statement_list
%type <variable_stmt> variable_statement
%type <node_list> variable_declaration_list
%type <node_list> variable_declaration_list_no_in
%type <value_node> variable_declaration
%type <value_node> variable_declaration_no_in
%type <value_node> destructuring_assignment_left_hand_side
%type <value_node> object_left_hand_side
%type <node_list> object_member_left_hand_side_list 
%type <ast> initialiser
%type <ast> initialiser_no_in
%type <expression_stmt> expression_statement
%type <if_stmt> if_statement
%type <iteration_stmt> iteration_statement
%type <continue_stmt> continue_statement
%type <break_stmt> break_statement
%type <return_stmt> return_statement
%type <with_stmt> with_statement
%type <switch_stmt> switch_statement
%type <ast> case_block
%type <node_list> case_clauses
%type <case_clause> case_clause
%type <case_clause> default_clause
%type <labelled_stmt> labelled_statement
%type <throw_stmt> throw_statement
%type <try_stmt> try_statement
%type <ast> catch
%type <ast> finally
%type <ast> statement_list__opt
%type <ast> initialiser__opt
%type <ast> initialiser_no_in__opt
%type <node_list> case_clauses__opt
%type <ast> literal
%type <ast> null_literal
%type <ast> boolean_literal
%type <ast> primary_expression
%type <ast> array_literal
%type <node_list> element_list
%type <value_node> array_left_hand_side
%type <node_list> array_left_hand_side_list
%type <ast> object_literal
%type <ast> property_name_and_value_list__opt
%type <ast> property_name_and_value_list
%type <value_node> property_name
%type <ast> member_expression
%type <ast> new_expression
%type <ast> call_expression
%type <ast> arguments
%type <node_list> argument_list
%type <ast> left_hand_side_expression
%type <ast> postfix_expression
%type <ast> unary_expression
%type <ast> multiplicative_expression
%type <ast> additive_expression
%type <ast> shift_expression
%type <ast> relational_expression
%type <ast> relational_expression_no_in
%type <ast> equality_expression
%type <ast> equality_expression_no_in
%type <ast> bitwise_and_expression
%type <ast> bitwise_and_expression_no_in
%type <ast> bitwise_xor_expression
%type <ast> bitwise_xor_expression_no_in
%type <ast> bitwise_or_expression
%type <ast> bitwise_or_expression_no_in
%type <ast> logical_and_expression
%type <ast> logical_and_expression_no_in
%type <ast> logical_or_expression
%type <ast> logical_or_expression_no_in
%type <ast> conditional_expression
%type <ast> conditional_expression_no_in
%type <ast> assignment_expression
%type <ast> assignment_expression_no_in
%type <num> assignment_operator
%type <expression> expression
%type <expression> expression_no_in
%type <ast> expression_no_in__opt
%type <ast> expression__opt
%type <opt> elision__opt
%type <function> arrow_function_expression
%type <ast> formal_parameter_rest
%type <ast> arguments_spread
%type <let_stmt> let_statement
%type <ast> let_assignment_list
%type <ast> let_assignment_expression
%type <module_stmt> module_block
%type <export_stmt> export_statement
%type <ast> array_comprehensions
%type <ast> array_comprehension_iteration
%type <ast> array_comprehension_if__opt
%type <ast> import_statement
%type <ast> import_expression
%type <cls> class_initialiser
%type <opt> class_adjective__opt
%type <ast> inherit_declaration__opt
%type <info> inherit_declaration
%type <ast> class_body__opt
%type <ast> class_body
%type <prop> class_element_list
%type <ast> class_element
%type <ast> constructor_definition
%type <ast> prototype_property_definition
%type <ast> class_property_definition
%type <ast> instance_property_definition
%type <ast> private_property_definition
%type <ast> exportable_definition
%type <ast> version_statement
%type <ast> yield_expression
%type <ast> yield_expression_no_in
%type <ast> pragma_statement
%%

program
: source_elements
  {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( $1 );
    ast_root->InsertBefore( root );
  }
;


version_statement
: MOCHA_VERSIONOF '(' JS_IDENTIFIER ')' '{' statement_list__opt '}'
  {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( $3 ) );
    stmt->Line( $1->GetLineNumber() );
    stmt->AddChild( $6 );
    $$ = stmt;
  }
;

/*
 *In case of
 *function Example () {...}
 */
function_declaration
: JS_FUNCTION JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $2 );
    fn->Name( value );
    fn->Argv ( $4 );
    fn->Append( $7 );
    $$ = fn;
  }

/*
 *In case of
 *const Example () { ... }
 *ES6 proporsal.
 */
| JS_CONST JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $2 );
    fn->Name( value );
    fn->Const();
    fn->Argv ( $4 );
    fn->Append( $7 );
    $$ = fn;
  }
;


function_expression
: JS_FUNCTION identifier__opt '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( $2 );
    fn->Argv ( $4 );
    fn->Append( $7 );
    $$ = fn;
  }
| arrow_function_expression { $$ = $1; }
;

/*
 *In case of
 *( x , y )[->|=>]{...} or
 *( x , y )[->|=>]... or
 *[->|=>]{...} or
 *[->|=>]...
 *Shorthand of function keyword
 *ES6 proporsal.
 */
arrow_function_expression
: JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END JS_FUNCTION_GLYPH '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( $2 );
    fn->Append( $6 );
    $$ = fn;
  }
| JS_FUNCTION_GLYPH '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( $3 );
    $$ = fn;
  }
| JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END JS_FUNCTION_GLYPH_WITH_CONTEXT '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( $2 );
    fn->Append( $6 );
    fn->ContextType( Function::kThis );
    $$ = fn;
  }
| JS_FUNCTION_GLYPH_WITH_CONTEXT '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( $3 );
    fn->ContextType( Function::kThis );
    $$ = fn;
  }
| JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END JS_FUNCTION_GLYPH shorten_function_body
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( $2 );
    fn->AddChild( $5 );
    fn->FunctionType( Function::kShorten );
    $$ = fn;
  }
| JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END JS_FUNCTION_GLYPH_WITH_CONTEXT shorten_function_body
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( $2 );
    fn->AddChild( $5 );
    fn->FunctionType( Function::kShorten );
    fn->ContextType( Function::kThis );
    $$ = fn;
  }
| JS_FUNCTION_GLYPH_WITH_CONTEXT shorten_function_body
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->AddChild( $2 );
    fn->FunctionType( Function::kShorten );
    fn->ContextType( Function::kThis );
    $$ = fn;
  }
| JS_FUNCTION_GLYPH shorten_function_body
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->AddChild( $2 );
    fn->FunctionType( Function::kShorten );
    $$ = fn;
  }
;


shorten_function_body
: JS_EXP_CLOSURE_BEGIN assignment_expression
  {
    $$ = $2;
  }
;

/*
 *[->|=>] [{] body [}]
 */

formal_parameter_list_with_rest
: formal_parameter_list { $$ = $1; }
| formal_parameter_rest
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| formal_parameter_list ',' formal_parameter_rest__opt
  {
    if ( !$3->IsEmpty() ) {
      $1->AddChild( $3 );
    }
    $$ = $1;
  }

/*
 *Arguments
 */
formal_parameter_list
/*
 *function Example( x , y = 200 ){...}
 *Normal formal parameter and
 *ES6 default parameter.
 *ES6 proporsal.
 */
: JS_IDENTIFIER initialiser__opt
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $1->GetLineNumber() );
    value->AddChild( $2 );
    value->Symbol( $1 );
    list->AddChild( value );
    $$ = list;
  }

/*
 *function Example({x,y,z}){...}
 *function Example([x,y,z]){...}
 *ES6 proporsal destructuring parameter.
 */
| destructuring_assignment_left_hand_side initialiser__opt
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( $2 );
    value->Node( $1 );
    list->AddChild( value );
    $$ = list;
  }

| formal_parameter_list ',' JS_IDENTIFIER initialiser__opt
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $3->GetLineNumber() );
    value->AddChild( $4 );
    value->Symbol( $3 );
    $1->AddChild( value );
    $$ = $1;
  }

| formal_parameter_list ',' destructuring_assignment_left_hand_side initialiser__opt
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( $4 );
    value->Node( $3 );
    $1->AddChild( value );
    $$ = $1;
  }
;


formal_parameter_rest__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| formal_parameter_rest { $$ = $1; }



/*
 *function Example(x,...y){...}
 *ES6 proporsal rest parameter.
 */
formal_parameter_rest
: JS_PARAMETER_REST JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $2 );
    $$ = value;
  }
;

/*
 *var arr = [0,2,3];
 *var Example = function( x, y , z ){console.log(x,y,z);}
 *Example(...arr);
 *=>0,2,3;
 *ES6 proporsal spread arguments.
 */
arguments_spread
: JS_PARAMETER_REST JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $2 );
    $$ = value;
  }
;

constructor_function_body
: { $$ = ManagedHandle::Retain<NodeList>(); }
| source_elements_for_constructor { $$ = $1; }
;

function_body
: { $$ = ManagedHandle::Retain<NodeList>(); }
| source_elements_for_function { $$ = $1; }
;

source_elements
: source_element
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !$1->IsEmpty() ) {
      list->AddChild( $1 );
    }
    $$ = list;
  }
| source_elements source_element
  {
    if ( !$2->IsEmpty() ) {
      $1->AddChild( $2 );
    }
    $$ = $1;
  }
;


source_elements_for_constructor
: source_element_for_constructor
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !$1->IsEmpty() ) {
      list->AddChild( $1 );
    }
    $$ = list;
  }
| source_elements_for_constructor source_element_for_constructor
  {
    if ( !$2->IsEmpty() ) {
      $1->AddChild( $2 );
    }
    $$ = $1;
  }
;


source_elements_for_function
: source_element_for_function
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !$1->IsEmpty() ) {
      list->AddChild( $1 );
    }
    $$ = list;
  }
| source_elements_for_function source_element_for_function
  {
    if ( !$2->IsEmpty() ) {
      $1->AddChild( $2 );
    }
    $$ = $1;
  }
;

source_element
: statement { $$ = $1; }
;


source_element_for_constructor
: statement_with_block { $$ = $1; }
| instance_property_definition { $$ = $1; }
| private_property_definition { $$ = $1; }
;


source_element_for_function
: statement_with_block { $$ = $1; }
;

formal_parameter_list__opt
: { $$ = GetEmptyNode(); }
| formal_parameter_list_with_rest
  {
    $$ = $1;
  }
;

identifier__opt
: { $$ = GetEmptyNode(); }
| JS_IDENTIFIER
  {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $1 );
    $$ = value;
  }
;

statement
: statement_with_block { $$ = $1; }
| module_block
  {
    
    $$ = $1;
  }
| export_statement
  {
    
    $$ = $1;
  }
;

statement_with_block
: block
  {
    
    $$ = $1;
  }
| statement_no_block { $$ = $1; }
;

statement_no_block
: variable_statement
  {
    
    $$ = $1;
  }
| pragma_statement { $$ = $1; }
| function_declaration
  { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( $1->Line() );
    stmt->AddChild( $1 );
    $$ = stmt;
  }
| let_statement
  { 
    $$ = $1;
  }
| empty_statement
  {
    
    $$ = $1;
  }
| expression_statement
  {
    
    $$ = $1;
  }
| if_statement
  {
    
    $$ = $1;
  }
| iteration_statement
  {
    
    $$ = $1;
  }
| continue_statement
  {

    $$ = $1;
  }
| break_statement
  {

    $$ = $1;
  }
| return_statement
  {

    $$ = $1;
  }
| with_statement
  {

    $$ = $1;
  }
| labelled_statement
  {

    $$ = $1;
  }
| switch_statement
  {

    $$ = $1;
  }
| throw_statement
  {

    $$ = $1;
  }
| try_statement
  {

    $$ = $1;
  }
| import_statement
  {
    $$ = $1;
  }
| version_statement
  {
    $$ = $1;
  }
;

block
: '{' '}'
  {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    $$ = block;
  }
| '{' statement_list '}'
  {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( $2->Line() );
    block->AddChild( $2 );
    $$ = block;
  }
;


pragma_statement
: MOCHA_PRAGMA '(' JS_IDENTIFIER ')' statement
  {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    val->Symbol( $3 );
    PragmaStmt* prg_stmt = ManagedHandle::Retain<PragmaStmt>();
    prg_stmt->Op( val );
    prg_stmt->AddChild( $5 );
    $$ = prg_stmt;
  }
;


module_block
: JS_MODULE identifier__opt statement
  {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( $1->GetLineNumber() );
    module->Name( $2 );

    module->AddChild( $3 );
    $$ = module;
  }
;


export_statement
: JS_EXPORT exportable_definition
  {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( $1->GetLineNumber() );
    exports->AddChild( $2 );
    $$ = exports;
  }

;


import_statement
: JS_IMPORT JS_IDENTIFIER JS_FROM import_expression terminator
{
  ValueNode* node = $4->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  value->Symbol( $2 );
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kVar , type ) );
  stmt->Exp( value );
  stmt->From( $4 );
  stmt->Line( $1->GetLineNumber() );
  $$ = stmt;
}
| JS_IMPORT destructuring_assignment_left_hand_side JS_FROM import_expression terminator
{
  ValueNode* node = $4->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kDst , type ) );
  stmt->Exp( $2 );
  stmt->From( $4 );
  stmt->Line( $1->GetLineNumber() );
  $$ = stmt;
}
| JS_IMPORT JS_STRING_LITERAL JS_FROM import_expression terminator
{
  ValueNode* node = $4->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  value->Symbol( $2 );
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kAll , type ) );
  stmt->Exp( value );
  stmt->From( $4 );
  stmt->Line( $1->GetLineNumber() );
  $$ = stmt;
}
;

import_expression
: JS_STRING_LITERAL
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( $1 );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    $$ = list;
  }
| JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $1 );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    $$ = list;
  }
| import_expression '.' JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $3 );
    $1->AddChild( value );
    $$ = $1;
  }
;

statement_list
: statement
  {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !$1->IsEmpty() ) {
      list->AddChild( $1 );
    }
    $$ = list;
  }
| statement_list statement
  {
    if ( !$2->IsEmpty() ) {
      $1->AddChild( $2 );
    }
    $$ = $1;
  }
;


variable_statement
: JS_VAR variable_declaration_list terminator
  {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( $1->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( $2 );
    $$ = var;
  }
| JS_CONST variable_declaration_list terminator
  {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( $1->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( $2 );
    $$ = var;
  }
| JS_LET variable_declaration_list terminator
  {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( $1->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( $2 );
    $$ = var;
  }
;

let_statement
: JS_LET '(' let_assignment_list ')' statement
  {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( $1->GetLineNumber() );
    let->Exp( $3 );
    let->AddChild( $5 );
    $$ = let;
  }

let_assignment_list
: let_assignment_expression
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| let_assignment_list ',' let_assignment_expression
  {
    $1->AddChild( $3 );
    $$ = $1;
  }

let_assignment_expression
: JS_IDENTIFIER initialiser__opt
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    value->AddChild( $2 );
    $$ = value;
  }
| destructuring_assignment_left_hand_side initialiser
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( $1->Line() );
    value->Node( $1 );
    value->AddChild( $2 );
    $$ = value;
  }
; 

variable_declaration_list
: variable_declaration 
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !$1->IsEmpty() ) {
      list->AddChild( $1 );
    }
    $$ = list;
  }
| variable_declaration_list ',' variable_declaration
  {
    if ( !$3->IsEmpty() ) {
      $1->AddChild( $3 );
    }
    $$ = $1;
  }
;

variable_declaration_list_no_in
: variable_declaration_no_in
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| variable_declaration_list_no_in ',' variable_declaration_no_in
  {
    $1->AddChild( $3 );
    $$ = $1;
  }
;

variable_declaration
: JS_IDENTIFIER initialiser__opt
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( $1->GetLineNumber() );
    node->Symbol( $1 );
    node->AddChild( $2 );
    $$ = node;
  }
| destructuring_assignment_left_hand_side initialiser__opt
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( $1->Line() );
    node->Node( $1 );
    node->AddChild( $2 );
    $$ = node;
  }
;

variable_declaration_no_in
: JS_IDENTIFIER initialiser_no_in__opt
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( $1->GetLineNumber() );
    node->Symbol( $1 );
    node->AddChild( $2 );
    $$ = node;
  }
| destructuring_assignment_left_hand_side initialiser_no_in__opt
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( $1->Line() );
    node->Node( $1 );
    node->AddChild( $2 );
    $$ = node;
  }
;


destructuring_assignment_left_hand_side
: array_left_hand_side
  {
    $$ = $1;
  }
| object_left_hand_side
  {
    $$ = $1;
  }
;

array_left_hand_side
: JS_DSTA_BEGIN elision__opt JS_DSTA_END
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    if ( $2 ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    value->Line( connector->GetLineNumber() );
    $$ = value;
  }
| JS_DSTA_BEGIN array_left_hand_side_list JS_DSTA_END
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( $2->Line() );
    value->AddChild( $2 );
    $$ = value;
  }
| JS_DSTA_BEGIN array_left_hand_side_list ',' elision__opt JS_DSTA_END
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->AddChild( $2 );
    value->Line( $2->Line() );
    if ( $4 ) {
      value->AddChild( GetEmptyNode() );
    }
    $$ = value;
  }
;

array_left_hand_side_list
: elision__opt JS_IDENTIFIER
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( $1 ) {
      list->AddChild( GetEmptyNode() );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $2 );
    list->Line( $2->GetLineNumber() );
    list->AddChild( value );
    $$ = list;
  }
| elision__opt formal_parameter_rest
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( $1 ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( $2 );
    $$ = list;
  }
| elision__opt destructuring_assignment_left_hand_side
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( $1 ) {
      list->AddChild( GetEmptyNode() );
    }
    list->Line( $2->Line() );
    list->AddChild( $2 );
    $$ = list;
  }
| array_left_hand_side_list ',' elision__opt JS_IDENTIFIER
  {
    if ( $3 ) {
      $1->AddChild( GetEmptyNode() );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $4->GetLineNumber() );
    value->Symbol( $4 );
    $1->AddChild( value );
    $$ = $1;
  }
| array_left_hand_side_list ',' elision__opt formal_parameter_rest
  {
    if ( $3 ) {
      $1->AddChild( GetEmptyNode() );
    }
    $1->AddChild( $4 );
    $$ = $1;
  }
| array_left_hand_side_list ',' elision__opt destructuring_assignment_left_hand_side
  {
    if ( $3 ) {
      $1->AddChild( GetEmptyNode() );
    }
    $1->AddChild( $4 );
    $$ = $1;
  }
;

object_left_hand_side
: JS_DSTO_BEGIN object_member_left_hand_side_list JS_DSTO_END
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( $2->Line() );
    value->Node( $2 );
    $$ = value;
  }
;


object_member_left_hand_side_list
:  JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( $1 );
    list->Line( $1->GetLineNumber() );
    list->AddChild( node );
    $$ = list;
  }
| property_name ':' JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( $3 );
    $1->AddChild( node );
    node->Line( $3->GetLineNumber() );
    list->Line( $1->Line() );
    list->AddChild( $1 );
    $$ = list;
  }

| property_name ':' destructuring_assignment_left_hand_side
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    $1->AddChild( $3 );
    list->Line( $1->Line() );
    list->AddChild( $1 );
    $$ = list;
  }
  
| object_member_left_hand_side_list ',' property_name ':' JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    $1->AddChild( $3 );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( $5->GetLineNumber() );
    node->Symbol( $5 );
    $3->AddChild( node );
    $$ = $1;
  }

| object_member_left_hand_side_list ',' JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( $3->GetLineNumber() );
    node->Symbol( $3 );
    $1->AddChild( node );
    $$ = $1;
  }
| object_member_left_hand_side_list ',' property_name ':' destructuring_assignment_left_hand_side
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    $1->AddChild( $3 );
    $3->AddChild( $5 );
    $$ = $1;
  }
;


initialiser
: '=' assignment_expression { $$ = $2; }
;

initialiser_no_in
: '=' assignment_expression_no_in { $$ = $2; }
;

empty_statement
: terminator { $$ = GetEmptyNode(); }
;

expression_statement
: expression terminator
  {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( $1->Line() );
    if ( $1->FirstChild()->NodeType() == AstNode::kClass ) {
      Class* cls = reinterpret_cast<Class*>( $1->FirstChild() );
      cls->Decl( true );
    }
    stmt->AddChild( $1 );
    $$ = stmt;
  }
;

if_statement
: JS_IF '(' expression ')' statement JS_ELSE statement 
  {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( $1->GetLineNumber() );
    stmt->Exp( $3 );
    stmt->Then( $5 );
    stmt->Else( $7 );
    $$ = stmt;
  }
| JS_IF '(' expression ')' statement
  {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( $1->GetLineNumber() );
    stmt->Exp( $3 );
    stmt->Then( $5 );
    stmt->Else( GetEmptyNode() );
    $$ = stmt;
  }
| JS_IF_OPT expression statement
  {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( $1->GetLineNumber() );
    stmt->Exp( $2 );
    stmt->Then( $3 );
    stmt->Else( GetEmptyNode() );
    $$ = stmt;
  }
;

iteration_statement
: JS_DO statement JS_WHILE
  { tracer->AllowExpression( true ); }
  '(' expression
  { tracer->AllowExpression( false ); } ')' terminator
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( $1->GetLineNumber() );
    iter->Exp( $6 );
    iter->AddChild( $2 );
    $$ = iter;
  }
| JS_WHILE
  { tracer->AllowExpression( true ); }
  '(' expression  { tracer->AllowExpression( false ); } ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( $1->GetLineNumber() );
    iter->Exp( $4 );
    iter->AddChild( $7 );
    $$ = iter;
  }
| JS_FOR '(' ')' statement
  {
    std::string error_msg = "Parse error. For loop condition must be non empty expression. for( <here> ){...}";
    error( yylloc , error_msg );
    YYABORT;
  }
| JS_FOR '(' expression_no_in__opt { tracer->AllowExpression( true ); } ';' expression__opt ';' expression__opt
  { tracer->AllowExpression( false ); } ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kFor ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $3 );
    list->AddChild( $6 );
    list->AddChild( $8 );
    iter->Exp( list );
    iter->AddChild( $11 );
    $$ = iter;
  }
| JS_FOR '(' JS_VAR variable_declaration_list_no_in { tracer->AllowExpression( true ); } ';' expression__opt ';' expression__opt
  { tracer->AllowExpression( false ); } ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $4 );
    list->AddChild( $7 );
    list->AddChild( $9 );
    iter->Exp( list );
    iter->AddChild( $12 );
    $$ = iter;
  }
| JS_FOR '(' left_hand_side_expression JS_IN expression ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $3 );
    list->AddChild( $5 );
    iter->Exp( list );
    iter->AddChild( $7 );
    $$ = iter;
  }
| JS_FOR '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForInWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $4 );
    list->AddChild( $6 );
    iter->Exp( list );
    iter->AddChild( $8 );
    $$ = iter;
  }

| JS_FOR '(' left_hand_side_expression JS_IDENTIFIER expression ')'
  {
    if ( strcmp( $4->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "parse error unexpected ";
      error_msg += $4->GetToken();
      error_msg += " expected of.";
      error( yylloc , error_msg );
    }
  }
  statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForOf ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $3 );
    list->AddChild( $5 );
    iter->Exp( list );
    iter->AddChild( $8 );
    $$ = iter;
  }
| JS_FOR '(' JS_VAR variable_declaration_no_in JS_IDENTIFIER expression ')'
  {
    if ( strcmp( $5->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "Parse error, unexpected ";
      error_msg += $5->GetToken();
      error_msg += ". mismatched for loop condition separator. Expect 'in','of' or ';'.";
      error( yylloc , error_msg );
    }
  }
  statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForOfWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $4 );
    list->AddChild( $6 );
    iter->Exp( list );
    iter->AddChild( $9 );
    $$ = iter;
  }

| JS_FOR JS_EACH '(' left_hand_side_expression JS_IN expression ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $4 );
    list->AddChild( $6 );
    iter->Exp( list );
    iter->AddChild( $8 );
    $$ = iter;
  }
| JS_FOR JS_EACH '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
  {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEachWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( $1->GetLineNumber() );
    list->AddChild( $5 );
    list->AddChild( $7 );
    iter->Exp( list );
    iter->AddChild( $9 );
    $$ = iter;
  }
;

continue_statement
: JS_CONTINUE identifier__opt terminator
  {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( $1->GetLineNumber() );
    cont->AddChild( $2 );
    $$ = cont;
  }
;

break_statement
: JS_BREAK identifier__opt terminator
  {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( $1->GetLineNumber() );
    break_stmt->AddChild( $2 );
    $$ = break_stmt;
  }
;

return_statement
: JS_RETURN expression__opt terminator
  {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( $1->GetLineNumber() );
    ret->AddChild( $2 );
    $$ = ret;
  }
;

with_statement
: JS_WITH '(' expression ')' statement
  {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( $1->GetLineNumber() );
    with_stmt->Exp( $3 );
    with_stmt->AddChild( $5 );
    $$ = with_stmt;
  }
;

switch_statement
: JS_SWITCH '(' expression ')' case_block
  {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( $1->GetLineNumber() );
    switch_stmt->Exp( $3 );
    switch_stmt->AddChild( $5 );
    $$ = switch_stmt;
  }
;

case_block
: '{' case_clauses__opt '}'
  {
    $$ = $2;
  }
| '{' case_clauses__opt default_clause case_clauses__opt '}'
  {
    $2->AddChild( $3 );
    $2->Append( $4 );    
    $$ = $2;
  }
;

case_clauses
: case_clause
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| case_clauses case_clause
  {
    $1->AddChild( $2 );
    $$ = $1;
  }
;

case_clause
: JS_CASE expression ':' statement_list__opt
  {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( $1->GetLineNumber() );
    clause->Exp( $2 );
    clause->AddChild( $4 );
    $$ = clause;
  }
;

default_clause
: JS_DEFAULT ':' statement_list__opt
  {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( $1->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( $3 );
    $$ = clause;
  }
;

labelled_statement
: JS_IDENTIFIER ':' statement
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $1 );
    value->Line( $1->GetLineNumber() );
    LabelledStmt *label = ManagedHandle::Retain<LabelledStmt>();
    label->AddChild( value );
    label->AddChild( $3 );
    $$ = label;
  }
;

throw_statement
: JS_THROW expression terminator
  {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( $1->GetLineNumber() );
    throw_stmt->Exp( $2 );
    $$ = throw_stmt;
  }
;

try_statement
: JS_TRY block catch
  {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( $1->GetLineNumber() );
    try_stmt->AddChild( $2 );
    try_stmt->Catch( $3 );
    try_stmt->Finally( GetEmptyNode() );
    $$ = try_stmt;
  }
| JS_TRY block finally
  {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( $1->GetLineNumber() );
    try_stmt->AddChild( $2 );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( $3 );
    $$ = try_stmt;
  }
| JS_TRY block catch finally
  {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( $1->GetLineNumber() );
    try_stmt->AddChild( $2 );
    try_stmt->Catch( $3 );
    try_stmt->Finally( $4 );
    $$ = try_stmt;
  }
;

catch
: JS_CATCH '(' JS_IDENTIFIER ')' block
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $3 );
    value->AddChild( $5 );
    $$ = value;
  }
;

finally
: JS_FINALLY block
  {
    $2->Line( $1->GetLineNumber() );
    $$ = $2;
  }
;

statement_list__opt
: { $$ = GetEmptyNode(); }
| statement_list { $$ = $1; }
;

initialiser__opt
: { $$ = GetEmptyNode(); }
| initialiser { $$ = $1; }
;

initialiser_no_in__opt
: { $$ = GetEmptyNode(); }
| initialiser_no_in { $$ = $1; }
;

case_clauses__opt
: { $$ = ManagedHandle::Retain<NodeList>(); }
| case_clauses { $$ = $1; }
;

literal
: null_literal { $$ = $1; }
| boolean_literal { $$ = $1; }
| JS_NUMERIC_LITERAL
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
| JS_STRING_LITERAL
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
| JS_REGEXP_LITERAL
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
;

null_literal
: JS_K_NULL
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
;

boolean_literal
: JS_TRUE
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
| JS_FALSE
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
;

primary_expression
: JS_THIS 
  { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
| JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $1->GetLineNumber() );
    value->Symbol( $1 );
    $$ = value;
  }
| literal { $$ = $1; }
| array_literal { $$ = $1; }
| object_literal { $$ = $1; }
| '(' expression ')' 
  {
    $2->Paren ();
    $$ = $2;
  }
;

array_literal
: '[' elision__opt ']'
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    if ( $2 ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    value->Line( connector->GetLineNumber() );
    $$ = value;
  }
| '[' element_list ']'
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( $2->Line() );
    value->AddChild( $2 );
    $$ = value;
  }
| '[' element_list ',' elision__opt ']'
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->AddChild( $2 );
    value->Line( $2->Line() );
    if ( $4 ) {
      value->AddChild( GetEmptyNode() );
    }
    $$ = value;
  }
| '[' element_list ';' array_comprehensions array_comprehension_if__opt ']'
  {
    if ( !$5->IsEmpty() ) {
      $4->AddChild( $5 );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->Node( $2 );
    value->AddChild( $4 );
    value->Line( $2->Line() );
    $$ = value;
  }
;

element_list
: elision__opt assignment_expression
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( $1 ) {
      list->AddChild( GetEmptyNode() );
    }
    list->Line( $2->Line() );
    list->AddChild( $2 );
    $$ = list;
  }
| element_list ',' elision__opt assignment_expression
  {
    if ( $3 ) {
      $1->AddChild( GetEmptyNode() );
    }
    $1->AddChild( $4 );
    $$ = $1;
  }
;

elision
: ',' 
| elision ','
;


array_comprehensions
: array_comprehension_iteration
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| array_comprehensions array_comprehension_iteration
  {
    $1->AddChild( $2 );
    $$ = $1;
  }
;

array_comprehension_iteration
: JS_FOR '(' left_hand_side_expression JS_IDENTIFIER expression ')'
  {
    IterationStmt *for_of = ManagedHandle::Retain( new IterationStmt( AstNode::kForOf ) );
    for_of->Exp( $3 );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $3 );
    list->AddChild( $5 );
    for_of->Exp( list );
    $$ = for_of;
  }
;

array_comprehension_if__opt
: { $$ = GetEmptyNode(); }
| JS_IF '(' expression ')'
  {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( $3 );
    $$ = if_stmt;
  }
;

object_literal
: '{' property_name_and_value_list__opt '}' 
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    value->Node( $2 );
    if ( !$2->IsEmpty() ) {
      value->Line( $2->Line() );
    } else {
      value->Line( connector->GetLineNumber() );
    }
    $$ = value;
  }
;

property_name_and_value_list__opt
: '@'
{
  $$ = GetEmptyNode();
}
| '@' property_name_and_value_list ';'
  {
    $$ = $2;
  }
| '@' property_name_and_value_list
  {
    $$ = $2;
  }
;

property_name_and_value_list
: property_name ':' assignment_expression
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    list->Line( $1->Line() );
    $1->AddChild( $3 );
    $$ = list;
  }
| JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    val->Symbol( $1 );
    val->Line( $1->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    child->ValueType( ValueNode::kIdentifier );
    val->AddChild( child );
    list->AddChild( val );
    $$ = list;
  }
| JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    value->Symbol( $1 );
    ValueNode* name = value->Clone()->CastToValue();
    fn->Name( name );
    fn->Argv ( $3 );
    fn->Append( $6 );
    value->AddChild( fn );
    list->AddChild( value );
    $$ = list;
  }
| property_name_and_value_list ',' property_name ':' assignment_expression
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    $1->AddChild( $3 );
    $3->AddChild( $5 );
    $$ = $1;
  }
| property_name_and_value_list ',' JS_IDENTIFIER
  {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    val->Symbol( $3 );
    val->Line( $3->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    child->ValueType( ValueNode::kIdentifier );
    val->AddChild( child );
    $1->AddChild( val );
    $$ = $1;
  }
| property_name_and_value_list ',' JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->Line() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $3 );
    ValueNode* name = value->Clone()->CastToValue();
    fn->Name( name );
    fn->Argv ( $5 );
    fn->Append( $8 );
    value->AddChild( fn );
    $1->AddChild( value );
    $$ = $1;
  }
;

property_name
: JS_IDENTIFIER
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( $1->GetLineNumber() );
    node->Symbol( $1 );
    $$ = node;
  }
| JS_STRING_LITERAL
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( $1->GetLineNumber() );
    node->Symbol( $1 );
    $$ = node;
  }
| JS_NUMERIC_LITERAL
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( $1->GetLineNumber() );
    node->Symbol( $1 );
    $$ = node;
  }
| '[' assignment_expression ']'
  {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kPrivateProperty ) );
    node->Line( $2->Line() );
    node->Node( $2 );
    $$ = node;
  }
;

member_expression
: primary_expression
  {
    $$ = $1;
  }
| function_expression
  {
    $$ = $1;
  }
| class_initialiser
  {
    $1->Decl( false );
    $$ = $1;
  }
| member_expression '[' expression ']'
  {
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( $3 );
    exp->Depth( depth );
    $$ = exp;
  }
| JS_PRIVATE '[' expression ']'
  {
    int depth = 0;
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( $1->GetLineNumber() );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kPrivate ) );
    exp->Line( value->Line() );
    exp->Callable( value );
    exp->Args( $3 );
    exp->Depth( depth );
    $$ = exp;
  }
| JS_PRIVATE '.' JS_IDENTIFIER
  {
    int depth = 0;
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    ValueNode* ident = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    value->Symbol( $1 );
    ident->Symbol( $3 );
    value->Line( $1->GetLineNumber() );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kPrivate ) );
    exp->Line( value->Line() );
    exp->Callable( value );
    exp->Args( ident );
    exp->Depth( depth );
    $$ = exp;
  }
| member_expression '.' JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    value->Symbol( $3 );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( value );
    exp->Depth( depth );
    $$ = exp;
  }
| member_expression '.' object_literal
  {
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kExtend ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( $3 );
    exp->Depth( depth );
    $$ = exp;
  }
| JS_NEW member_expression arguments
  {
    int depth = 0;
    if ( $2->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $2 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNew ) );
    exp->Line( $1->GetLineNumber() );
    exp->Callable( $2 );
    exp->Args( $3 );
    exp->Depth( depth );
    $$ = exp;
  }
;

new_expression
: member_expression { $$ = $1; }
| JS_NEW new_expression
  {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( $1->GetLineNumber() );
    ret->Constructor( $2 );
    $$ = ret;
  }
;

call_expression
: member_expression arguments
  {
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( $2 );
    exp->Depth( depth );
    $$ = exp;
  }
| call_expression arguments
  {
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( $2 );
    exp->Depth( depth );
    $$ = exp;
  }
| call_expression '[' expression ']'
  {
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( $3 );
    exp->Depth( depth );
    $$ = exp;
  }
| call_expression '.' JS_IDENTIFIER
  {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    int depth = 0;
    if ( $1->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( $1 )->Depth() + 1;
    }
    value->Symbol( $3 );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Line( $1->Line() );
    exp->Callable( $1 );
    exp->Args( value );
    exp->Depth( depth );
    $$ = exp;
  }
;

arguments
: '(' ')' { $$ = GetEmptyNode(); }
| '(' argument_list ')' { $$ = $2; }
;

argument_list
: assignment_expression
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| arguments_spread
  {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( $1 );
    $$ = list;
  }
| argument_list ',' assignment_expression
  {
    $1->AddChild( $3 );
    $$ = $1;
  }
| argument_list ',' arguments_spread
  {
    $1->AddChild( $3 );
    $$ = $1;
  }
;

class_initialiser
: class_adjective__opt JS_CLASS identifier__opt inherit_declaration__opt '{' class_body__opt '}'
  {
    Class* cls = ManagedHandle::Retain( new Class( $4 , $1 ) );
    cls->Line( $2->GetLineNumber() );
    cls->Name( $3 );
    cls->Body( $6 );
    $$ = cls;
  }
;


class_adjective__opt
: { $$ = false; }
| JS_CONST { $$ = true; }
;


inherit_declaration__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| inherit_declaration member_expression
  {
    ClassExpandar* expandar;
    if ( $1->GetType() == yy::ParserImplementation::token::JS_PROTOTYPE ) {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kPrototype ) );
    } else {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kExtends ) );
    }
    expandar->Line( $1->GetLineNumber() );
    expandar->AddChild( $2 );
    $$ = expandar;
  }
;


inherit_declaration
: JS_EXTENDS { $$ = $1; }
| JS_PROTOTYPE { $$ = $1; }
;


class_body__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| class_body { $$ = $1; }
;

class_body
: class_element_list { $$ = $1; }
;


class_element_list
: class_element
  {
    ClassProperties* list = ManagedHandle::Retain<ClassProperties>();
    if ( !$1->IsEmpty() ) {
#define TYPE( name )                            \
      case ClassMember::k##name :               \
        list->name( $1 );                       \
        break

      ClassMember* mem = reinterpret_cast<ClassMember*>( $1 );
      switch ( mem->Attr() ) {
        TYPE(Private);
        TYPE(Public);
        TYPE(Static);
        TYPE(Prototype);
        TYPE(Constructor);
      }
#undef TYPE
    }
    $$ = list;
  }
| class_element_list class_element
  {
    if ( !$2->IsEmpty() ) {
#define TYPE( name )                            \
      case ClassMember::k##name :               \
        $1->name( $2 );                         \
        break

      ClassMember* mem = reinterpret_cast<ClassMember*>( $2 );
      switch ( mem->Attr() ) {
        TYPE(Private);
        TYPE(Public);
        TYPE(Static);
        TYPE(Prototype);
        TYPE(Constructor);
      }
#undef TYPE
    }
    $$ = $1;
  }
;


class_element
: constructor_definition
  {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( $1 );
    $$ = member;
  }
| empty_statement { $$ = $1; }
| prototype_property_definition { $$ = $1;}
| class_property_definition { $$ = $1; }
| instance_property_definition { $$ = $1; }
| private_property_definition { $$ = $1; }
;


constructor_definition
: JS_CONSTRUCTOR '(' formal_parameter_list__opt ')' '{' constructor_function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $1 );
    fn->Name( value );
    fn->Argv ( $3 );
    fn->Append( $6 );
    $$ = fn;
  }
;


prototype_property_definition
: exportable_definition terminator
  {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( $1 );
    $$ = member;
  }
;


class_property_definition
: JS_STATIC exportable_definition terminator
  {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( $2 );
    $$ = member;
  }
;


instance_property_definition
: JS_PUBLIC exportable_definition terminator
  {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( $2 );
    $$ = member;
  }
;

private_property_definition
: JS_PRIVATE exportable_definition terminator
  {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( $2 );
    $$ = member;
  }
;


exportable_definition
: variable_declaration_list { $$ = $1; }
| JS_CONST variable_declaration_list
  {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Line( $1->GetLineNumber() );
    val->Node( $2 );
    $$ = val;
  }
| class_initialiser { $$ = $1; }
| JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $1 );
    fn->Name( value );
    fn->Argv ( $3 );
    fn->Append( $6 );
    $$ = fn;
  }
| JS_GET JS_IDENTIFIER '(' ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Attr( Function::kGet );
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $2 );
    fn->Name( value );
    fn->Argv ( ManagedHandle::Retain<Empty>() );
    fn->Append( $6 );
    $$ = fn;
  }
| JS_SET JS_IDENTIFIER '(' formal_parameter_list__opt ')' '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Attr( Function::kSet );
    fn->Line( $1->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( $2 );
    fn->Name( value );
    fn->Argv ( $4 );
    fn->Append( $7 );
    $$ = fn;
  }
;


left_hand_side_expression
: new_expression { $$ = $1; }
| call_expression { $$ = $1; }
| array_left_hand_side { $$ = $1; }
| '(' object_left_hand_side ')' { $$ = $2; }
;

postfix_expression
: left_hand_side_expression
  {
    $$ = $1;
  }
| left_hand_side_expression JS_INCREMENT
  {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( $2->GetType() ) );
    ret->Line( $1->Line() );
    ret->Exp( $1 );
    $$ = ret;
  }
| left_hand_side_expression JS_DECREMENT
  {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( $2->GetType() ) );
    ret->Line( $1->Line() );
    ret->Exp( $1 );
    $$ = ret;
  }
;

unary_expression
: postfix_expression { $$ = $1; }
| JS_DELETE unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( $1->GetType() ) );
    ret->Line( $1->GetLineNumber() );
    ret->Exp( $2 );
    $$ = ret;
  }
| JS_VOID unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( $1->GetType() ) );
    ret->Line( $1->GetLineNumber() );
    ret->Exp( $2 );
    $$ = ret;
  }
| JS_TYPEOF unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( $1->GetType() ) );
    ret->Line( $1->GetLineNumber() );
    ret->Exp( $2 );
    $$ = ret;
  }
| JS_INCREMENT unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( $1->GetType() ) );
    ret->Line( $1->GetLineNumber() );
    ret->Exp( $2 );
    $$ = ret;
  }
| JS_DECREMENT unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( $1->GetType() ) );
    ret->Line( $1->GetLineNumber() );
    ret->Exp( $2 );
    $$ = ret;
  }
| '+' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( $2->Line() );
    ret->Exp( $2 );
    $$ = ret;
  }
| '-' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( $2->Line() );
    ret->Exp( $2 );
    $$ = ret;
  }
| '~' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( $2->Line() );
    ret->Exp( $2 );
    $$ = ret;
  }
| '!' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( $2->Line() );
    ret->Exp( $2 );
    $$ = ret;
  }
;

multiplicative_expression
: unary_expression { $$ = $1; }
| multiplicative_expression '*' unary_expression
  {
    BINARY_ACTION('*',$1,$3,$$);
  }
| multiplicative_expression '/' unary_expression
  {
    BINARY_ACTION('/',$1,$3,$$);
  }
| multiplicative_expression '%' unary_expression
  {
    BINARY_ACTION('%',$1,$3,$$);
  }
;

additive_expression
: multiplicative_expression { $$ = $1; }
| additive_expression '+' multiplicative_expression
  {
    BINARY_ACTION('+',$1,$3,$$);
  }
| additive_expression '-' multiplicative_expression
  {
    BINARY_ACTION('-',$1,$3,$$);
  }
;

shift_expression
: additive_expression { $$ = $1; }
| shift_expression JS_SHIFT_LEFT additive_expression
  {
    BINARY_ACTION($2->GetType(),$1,$3,$$);
  }
| shift_expression JS_SHIFT_RIGHT additive_expression
  {
    BINARY_ACTION($2->GetType(),$1,$3,$$);
  }
| shift_expression JS_U_SHIFT_RIGHT additive_expression
  {
    BINARY_ACTION($2->GetType(),$1,$3,$$);
  }
;

relational_expression
: shift_expression { $$ = $1; }
| relational_expression '<' shift_expression
  {
    COMPARE_ACTION('<',$1,$3,$$);
  }
| relational_expression '>' shift_expression
  {
    COMPARE_ACTION('>',$1,$3,$$);
  }
| relational_expression JS_LESS_EQUAL shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| relational_expression JS_GRATER_EQUAL shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| relational_expression JS_INSTANCEOF shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| relational_expression JS_IN shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

relational_expression_no_in
: shift_expression { $$ = $1; }
| relational_expression_no_in '<' shift_expression
  {
    COMPARE_ACTION('<',$1,$3,$$);
  }
| relational_expression_no_in '>' shift_expression
  {
    COMPARE_ACTION('>',$1,$3,$$);
  }
| relational_expression_no_in JS_LESS_EQUAL shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| relational_expression_no_in JS_GRATER_EQUAL shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| relational_expression_no_in JS_INSTANCEOF shift_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

equality_expression
: relational_expression { $$ = $1; }
| equality_expression JS_EQUAL relational_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression JS_NOT_EQUAL relational_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression JS_EQ relational_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression JS_NOT_EQ relational_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

equality_expression_no_in
: relational_expression_no_in { $$ = $1; }
| equality_expression_no_in JS_EQUAL relational_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression_no_in JS_NOT_EQUAL relational_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression_no_in JS_EQ relational_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
| equality_expression_no_in JS_NOT_EQ relational_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

bitwise_and_expression
: equality_expression { $$ = $1; }
| bitwise_and_expression '&' equality_expression
  {
    BINARY_ACTION('&',$1,$3,$$);
  }
;

bitwise_and_expression_no_in
: equality_expression_no_in { $$ = $1; }
| bitwise_and_expression_no_in '&' equality_expression_no_in
  {
    BINARY_ACTION('&',$1,$3,$$);
  }
;

bitwise_xor_expression
: bitwise_and_expression { $$ = $1; }
| bitwise_xor_expression '^' bitwise_and_expression
  {
    BINARY_ACTION('^',$1,$3,$$);
  }
;

bitwise_xor_expression_no_in
: bitwise_and_expression_no_in { $$ = $1;}
| bitwise_xor_expression_no_in '^' bitwise_and_expression_no_in
  {
    BINARY_ACTION('^',$1,$3,$$);
  }
;

bitwise_or_expression
: bitwise_xor_expression { $$ = $1; }
| bitwise_or_expression '|' bitwise_xor_expression
  {
    BINARY_ACTION('|',$1,$3,$$);
  }
;

bitwise_or_expression_no_in
: bitwise_xor_expression_no_in { $$ = $1; }
| bitwise_or_expression_no_in '|' bitwise_xor_expression_no_in
  {
    BINARY_ACTION('|',$1,$3,$$);
  }
;

logical_and_expression
: bitwise_or_expression { $$ = $1; }
| logical_and_expression JS_LOGICAL_AND bitwise_or_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

logical_and_expression_no_in
: bitwise_or_expression_no_in { $$ = $1; }
| logical_and_expression_no_in JS_LOGICAL_AND bitwise_or_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

logical_or_expression
: logical_and_expression {$$ = $1; }
| logical_or_expression JS_LOGICAL_OR logical_and_expression
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

logical_or_expression_no_in
: logical_and_expression_no_in { $$ =$1; }
| logical_or_expression_no_in JS_LOGICAL_OR logical_and_expression_no_in
  {
    COMPARE_ACTION($2->GetType(),$1,$3,$$);
  }
;

conditional_expression
: logical_or_expression { $$ = $1; }
| logical_or_expression '?' assignment_expression ':' assignment_expression
  {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( $1 , $3 , $5 ) );
    ret->Line( $1->Line() );
    $$ = ret;
  }
;

conditional_expression_no_in
: logical_or_expression_no_in { $$ = $1; }
| logical_or_expression_no_in '?' assignment_expression_no_in ':' assignment_expression_no_in
  {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( $1 , $3 , $5 ) );
    ret->Line( $1->Line() );
    $$ = ret;
  }
;

yield_expression
: conditional_expression { $$ = $1; }
| JS_YIELD JS_YIELD_SENTINEL
  {
    $$ = ManagedHandle::Retain<YieldExp>();
    $$->Line( $1->GetLineNumber() );
  }
| JS_YIELD assignment_expression
  {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( $1->GetLineNumber() );
    yield_exp->AddChild( $2 );
    $$ = yield_exp;
  }
;

yield_expression_no_in
: conditional_expression_no_in { $$ = $1; }
| JS_YIELD JS_YIELD_SENTINEL
  {
    $$ = ManagedHandle::Retain<YieldExp>();
    $$->Line( $1->GetLineNumber() );
  }
| JS_YIELD assignment_expression_no_in
  {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( $1->GetLineNumber() );
    yield_exp->AddChild( $2 );
    $$ = yield_exp;
  }
;

assignment_expression
: yield_expression
  {
    $$ = $1;
  }
| left_hand_side_expression assignment_operator assignment_expression
  {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( $2 , $1 , $3 ) );
    ret->Line( $1->Line() );
    $$ = ret;
  }
;


assignment_expression_no_in
: yield_expression_no_in
  {
    $$ = $1;
  }
| left_hand_side_expression assignment_operator assignment_expression_no_in
  {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( $2 , $1 , $3 ) );
    ret->Line( $1->Line() );
    $$ = ret;
  }
;



assignment_operator
:  '=' { $$ = '='; }
|  JS_MUL_LET { $$ = $1->GetType(); }
|  JS_DIV_LET { $$ = $1->GetType(); }
|  JS_MOD_LET { $$ = $1->GetType(); }
|  JS_ADD_LET { $$ = $1->GetType(); }
|  JS_SUB_LET { $$ = $1->GetType(); }
|  JS_SHIFT_LEFT_LET { $$ = $1->GetType(); }
|  JS_SHIFT_RIGHT_LET { $$ = $1->GetType(); }
|  JS_U_SHIFT_RIGHT_LET { $$ = $1->GetType(); }
|  JS_AND_LET { $$ = $1->GetType(); }
|  JS_NOT_LET { $$ = $1->GetType(); }
|  JS_OR_LET { $$ = $1->GetType(); }
;

expression
: assignment_expression
  {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( $1->Line() );
    exp->AddChild( $1 );
    $$ = exp;
  }
| expression ',' assignment_expression
  {
    $1->AddChild( $3 );
    $$ = $1;
  }
;

expression_no_in
: assignment_expression_no_in
  { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( $1->Line() );
    exp->AddChild( $1 );
    $$ = exp;
  }
| expression_no_in ',' assignment_expression_no_in
  {
    $1->AddChild( $3 );
    $$ = $1;
  }
;

expression_no_in__opt
: { $$ = GetEmptyNode(); }
| expression_no_in { $$ = $1; }
;

expression__opt
: { $$ = GetEmptyNode(); }
| expression { $$ = $1; }
;

elision__opt
: { $$ = false; }
| elision { $$ = true; }
;

terminator
: ';' {$<num>$ = ';';}
| JS_LINE_BREAK {$<num>$ = ';';}
;

%%

void Replace( std::string& msg , const char* find , const char* rep ) {
  size_t pos = 0;
  while ( ( pos = msg.find( find , 0 ) ) != std::string::npos ) {
    msg.replace( pos , strlen( find ) , rep );
  }
}

void yy::ParserImplementation::error (const location_type& loc, const std::string& row_msg ) {
  std::string msg = row_msg;
  Replace( msg , "JS_ADD_LET" , "'+='" );
  Replace( msg , "JS_AND_LET" , "'&='" );
  Replace( msg , "JS_BOOLEAN" , "'boolean'" );
  Replace( msg , "JS_BREAK" , "'break'" );
  Replace( msg , "JS_BYTE" , "'byte'" );
  Replace( msg , "JS_CASE" , "'case'" );
  Replace( msg , "JS_CATCH" , "'catch'" );
  Replace( msg , "JS_CHAR" , "'char'" );
  Replace( msg , "JS_CLASS" , "'class'" );
  Replace( msg , "JS_CONST" , "'const'" );
  Replace( msg , "JS_CONTINUE" , "'continue'" );
  Replace( msg , "JS_DEBUGGER" , "'debugger'" );
  Replace( msg , "JS_DECREMENT" , "'--'" );
  Replace( msg , "JS_DEFAULT" , "'default'" );
  Replace( msg , "JS_DELETE" , "'delete'" );
  Replace( msg , "JS_DIV_LET" , "'/='" );
  Replace( msg , "JS_DO" , "'do'" );
  Replace( msg , "JS_DOUBLE" , "'double'" );
  Replace( msg , "JS_ELSE" , "'else'" );
  Replace( msg , "JS_ENUM" , "'enum'" );
  Replace( msg , "JS_EQ" , "'=='" );
  Replace( msg , "JS_EQUAL" , "'==='" );
  Replace( msg , "JS_EXPORT" , "'export'" );
  Replace( msg , "JS_EXTENDS" , "'extends'" );
  Replace( msg , "JS_FALSE" , "'false'" );
  Replace( msg , "JS_FINAL" , "'final'" );
  Replace( msg , "JS_FINALLY" , "'finally'" );
  Replace( msg , "JS_FLOAT" , "'float'" );
  Replace( msg , "JS_FOR" , "'for'" );
  Replace( msg , "JS_COMP_FOR" , "'for'" );
  Replace( msg , "JS_GOTO" , "'goto'" );
  Replace( msg , "JS_GRATER_EQUAL" , "'>='" );
  Replace( msg , "JS_IDENTIFIER" , "'identifier'" );
  Replace( msg , "JS_IF" , "'if'" );
  Replace( msg , "JS_IF_OPT" , "'if'" );
  Replace( msg , "JS_IMPLEMENTS" , "'implements'" );
  Replace( msg , "JS_IMPORT" , "'import'" );
  Replace( msg , "JS_IN" , "'in'" );
  Replace( msg , "JS_INCREMENT" , "'++'" );
  Replace( msg , "JS_INSTANCEOF" , "'instanceof'" );
  Replace( msg , "JS_INT" , "'int'" );
  Replace( msg , "JS_INTERFACE" , "'interface'" );
  Replace( msg , "JS_LESS_EQUAL" , "'<='" );
  Replace( msg , "JS_LOGICAL_AND" , "'&&'" );
  Replace( msg , "JS_LOGICAL_OR" , "'||'" );
  Replace( msg , "JS_LONG" , "'long'" );
  Replace( msg , "JS_MOD_LET" , "'/='" );
  Replace( msg , "JS_MUL_LET" , "'*='" );
  Replace( msg , "JS_NATIVE" , "'native'" );
  Replace( msg , "JS_NEW" , "'new'" );
  Replace( msg , "JS_NOT_EQ" , "'!='" );
  Replace( msg , "JS_NOT_EQUAL" , "'!=='" );
  Replace( msg , "JS_NOT_LET" , "'^='" );
  Replace( msg , "JS_K_NULL" , "'null'" );
  Replace( msg , "JS_NUMERIC_LITERAL" , "'number literal'" );
  Replace( msg , "JS_OR_LET" , "'|='" );
  Replace( msg , "JS_PRIVATE" , "'private'" );
  Replace( msg , "JS_PACKAGE_RESERVED" , "'package'" );
  Replace( msg , "JS_PROTECTED" , "'protected'" );
  Replace( msg , "JS_PUBLIC" , "'public'" );
  Replace( msg , "JS_REGEXP_LITERAL" , "'regexp literal'");
  Replace( msg , "JS_RETURN" , "'return'" );
  Replace( msg , "JS_SHIFT_LEFT" , "'<<'" );
  Replace( msg , "JS_SHIFT_LEFT_LET" , "'<<='" );
  Replace( msg , "JS_SHIFT_RIGHT" , "'>>'" );
  Replace( msg , "JS_SHIFT_RIGHT_LET" , "'>>='" );
  Replace( msg , "JS_SHORT" , "'short'" );
  Replace( msg , "JS_STATIC" , "'static'" );
  Replace( msg , "JS_STRING_LITERAL" , "'string literal'" );
  Replace( msg , "JS_SUB_LET" , "'=-'" );
  Replace( msg , "JS_SUPER" , "'super'" );
  Replace( msg , "JS_SWITCH" , "'switch'" );
  Replace( msg , "JS_SYNCHRONIZED" , "'synchronized'" );
  Replace( msg , "JS_THIS" , "'this'" );
  Replace( msg , "JS_THROW" , "'throw'" );
  Replace( msg , "JS_THROWS" , "'throws'" );
  Replace( msg , "JS_TRANSIENT" , "'transient'" );
  Replace( msg , "JS_TRUE" , "'try'" );
  Replace( msg , "JS_TRY" , "'try'" );
  Replace( msg , "JS_TYPEOF" , "'typeof'" );
  Replace( msg , "JS_U_SHIFT_RIGHT" , "'>>>'" );
  Replace( msg , "JS_U_SHIFT_RIGHT_LET" , "'>>>='" );
  Replace( msg , "JS_VAR" , "'var'" );
  Replace( msg , "JS_VOID" , "'void'" );
  Replace( msg , "JS_VOLATILE" , "'volatile'" );
  Replace( msg , "JS_WHILE" , "'while'" );
  Replace( msg , "JS_WITH" , "'with'" );
  Replace( msg , "JS_TERMINATE" , "';'" );
  Replace( msg , "JS_FUNCTION_GLYPH_WITH_CONTEXT" , "'=>'" );
  Replace( msg , "JS_FUNCTION_GLYPH" , "'->'" );
  Replace( msg , "JS_FUNCTION" , "'function'" );
  Replace( msg , "JS_PARAM_BEGIN" , "'('" );
  Replace( msg , "JS_PARAM_END" , "')'" );
  Replace( msg , "JS_LET" , "'let'" );
  Replace( msg , "JS_EACH" , "'each'" );
  Replace( msg , "JS_PARAMETER_REST" , "'...'" );
  Replace( msg , "JS_MODULE" , "'module'" );
  Replace( msg , "JS_FROM" , "'from'" );
  Replace( msg , "JS_CONSTRUCTOR" , "'constructor'" );
  Replace( msg , "JS_GET" , "'get'" );
  Replace( msg , "JS_SET" , "'set'" );
  Replace( msg , "JS_DSTA_BEGIN" , "'['" );
  Replace( msg , "JS_DSTO_BEGIN" , "'{'" );
  Replace( msg , "JS_DSTA_END" , "']'" );
  Replace( msg , "JS_DSTO_END" , "'}'" );
  Replace( msg , "MOCHA_PRAGMA" , "'@pragma'" );
  Replace( msg , "MOCHA_VERSIONOF" , "'@version'" );
  tracer->SyntaxError ( connector->GetLineNumber() , msg.c_str() );
}

