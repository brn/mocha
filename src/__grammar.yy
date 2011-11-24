%{
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include "token_info.h"
#include "parser_tracer.h"
#include "parser_connector.h"
#include "ast_type.h"
#include "ast_visitor.h"
#include "yylex.h"
#include "handle.h"
#include "compiler.h"
#include "managed_handle.h"
#include "file_system.h"
#include "virtual_directory.h"
  using namespace std;
  using namespace mocha;

#define TREE_REDUCE(type,_1,_2,_3,_4)                               \
  Tree *tmp = _3->CastToTree ();                                    \
  type *ret = ManagedHandle::Retain ( new type ( _2 , _1, _3 ) );     \
  if ( AstUtil::IsValidAst<Tree> ( tmp ) ) {                        \
    if ( !AstUtil::IsValidAst<type> ( tmp->CastTo##type () ) ) {    \
      ret->Prior ( Tree::kRight );                                  \
    }                                                               \
  } else if ( _1->IsPrimary () ) {                                  \
    ret->Prior ( Tree::kLeft );                                     \
  } else if ( _3->IsPrimary ()  ) {                                 \
    ret->Prior ( Tree::kRight );                                    \
  }                                                                 \
  _4 = ret

#define EXPECT_TERMINATOR
  %}

%code requires {
#include "ast_type.h"
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
  const mocha::TokenInfo *info;
  mocha::AstTree *ast_tree;
  mocha::AstTypeBase* ast;
  mocha::StmtList* stmtlist;
  mocha::Function *fn;
  mocha::FormalParameter *farg;
  mocha::VariableDeclaration *vars;
  mocha::VariableDeclarationList *varsList;
  mocha::CaseClauses *ccs;
  mocha::CaseClause *cc;
  mocha::DefaultClause *dc;
  mocha::ArrayLiteral *array;
  mocha::ElementList *elem;
  mocha::ObjectLiteral *obj;
  mocha::ObjectMember *mem;
  mocha::Arguments *args;
  mocha::Expression *exp;
  mocha::ExpressionStmt *exp_stmt;
  mocha::Block *blk;
  mocha::Empty *empty;
  mocha::Iteration *it;
  mocha::IFStmt* if_stmt;
  mocha::Continue* continue_stmt;
  mocha::Break* break_stmt;
  mocha::Return* return_stmt;
  mocha::With *with_stmt;
  mocha::Label *label_stmt;
  mocha::Switch *switch_stmt;
  mocha::Throw *throw_stmt;
  mocha::Try *try_stmt;
  mocha::SourceBlock *source_block;
  mocha::Constant::ConstantType consts;
  mocha::PropertyName *property;
  mocha::DestructuringAssignment *dsta;
  mocha::DestructuringArray* dstarr;
  mocha::DestructuringObjectMember* dstom;
  mocha::DestructuringObject *dsto;
  mocha::ElementLHS* elhs;
  mocha::ArrayComprehensions *array_comp;
  mocha::Module *module;
  mocha::ExportStmt *exports;
  mocha::LetStmt *let;
  mocha::ArrayComprehensions *array_cmp;
  bool opt;
  const char* ident;
  int num;
  long int line;
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
%token <info> JS_DARRAY_BEGIN
%token <info> JS_DARRAY_END
%token <info> JS_DOBJECT_BEGIN
%token <info> JS_DOBJECT_END
%token <info> JS_FORMAL_PARAMETER_IDENT
%token <info> JS_LET
%token <info> JS_EACH
%token <info> JS_PARAMETER_REST
%token <info> JS_MODULE
%token <info> JS_SHORTER_FUNCTION_BLOCK_BEGIN
%token <info> JS_SHORTER_FUNCTION_BLOCK_END

%type <ast> program
%type <fn> function_declaration
%type <fn> function_expression
%type <farg> formal_parameter_list
%type <ast> formal_parameter_list__opt
%type <ast> function_body
%type <ast_tree> source_elements
%type <source_block> source_element
%type <ident> identifier__opt
%type <source_block> statement
%type <empty> empty_statement
%type <blk> block
%type <stmtlist> statement_list
%type <varsList> variable_statement
%type <varsList> variable_declaration_list
%type <varsList> variable_declaration_list_no_in
%type <ast> variable_declaration
%type <ast> variable_declaration_no_in
%type <dsta> destructuring_assignment_left_hand_side
%type <ast> object_left_hand_side
%type <dsto> object_member_left_hand_side_list 
%type <ast> initialiser
%type <ast> initialiser_no_in
%type <exp_stmt> expression_statement
%type <if_stmt> if_statement
%type <it> iteration_statement
%type <continue_stmt> continue_statement
%type <break_stmt> break_statement
%type <return_stmt> return_statement
%type <with_stmt> with_statement
%type <switch_stmt> switch_statement
%type <ast> case_block
%type <ccs> case_clauses
%type <cc> case_clause
%type <dc> default_clause
%type <label_stmt> labelled_statement
%type <throw_stmt> throw_statement
%type <try_stmt> try_statement
%type <ast> catch
%type <ast> finally
%type <stmtlist> statement_list__opt
%type <ast> initialiser__opt
%type <ast> initialiser_no_in__opt
%type <ccs> case_clauses__opt
%type <ast> literal
%type <ast> null_literal
%type <ast> boolean_literal
%type <ast> primary_expression
%type <array> array_literal
%type <elem> element_list
%type <obj> object_literal
%type <ast> property_name_and_value_list__opt
%type <mem> property_name_and_value_list
%type <property> property_name
%type <ast> member_expression
%type <ast> new_expression
%type <ast> call_expression
%type <args> arguments
%type <args> argument_list
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
%type <consts> assignment_operator
%type <exp> expression
%type <exp> expression_no_in
%type <exp> expression_no_in__opt
%type <exp> expression__opt
%type <opt> elision__opt
%type <fn> arrow_function_expression
%type <ast> function_body_expression
%type <elhs> array_left_hand_element_list
%type <dstarr> array_left_hand_side
%type <ast> formal_parameter_rest
%type <ast> arguments_spread
%type <let> let_statement
%type <args> let_assignment_list
%type <ast> let_assignment_expression
%type <module> module_block
%type <exports> export_statement
%type <array_cmp> array_comprehensions
%type <ast> array_comprehension_iteration
%type <ast> array_comprehension_if__opt
%%

program
: {yydebug_ = 0;} source_elements
  {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( $2 );
    ast_root->Tree ( root );
  }
;

/*
 *In case of
 *function Example () {...}
 */
function_declaration
: JS_FUNCTION JS_FUNCTION_IDENTIFIER JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain ( new Function ( $2->getValue() ) );
    fn->Argv ( $4 );
    fn->Body ( $7 );
    $$ = fn;
  }

/*
 *In case of
 *const Example () { ... }
 *ES6 proporsal.
 */
| JS_CONST JS_FORMAL_PARAMETER_IDENT JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain ( new Function ( $2->getValue() ) );
    fn->Const( true );
    fn->Argv ( $4 );
    fn->Body ( $7 );
    $$ = fn;
  }
;


function_expression
: JS_FUNCTION identifier__opt JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END '{' function_body '}'
  {
    Function *fn = ManagedHandle::Retain ( new Function ( $2 ) );
    fn->Argv ( $4 );
    fn->Body ( $7 );
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
: JS_PARAM_BEGIN formal_parameter_list JS_PARAM_END function_body_expression
  {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( $2 );
    fn->Body ( $4 );
    $$ = fn;
  }
| function_body_expression
  {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( $1 );
    $$ = fn;
  }
;

/*
 *[->|=>] [{] body [}]
 */
function_body_expression
: JS_FUNCTION_GLYPH JS_SHORTER_FUNCTION_BLOCK_BEGIN function_body JS_SHORTER_FUNCTION_BLOCK_END { $$ = $3; }
| JS_FUNCTION_GLYPH_WITH_CONTEXT JS_SHORTER_FUNCTION_BLOCK_BEGIN  function_body JS_SHORTER_FUNCTION_BLOCK_END { $$ = $3; }
| JS_FUNCTION_GLYPH source_element { $$ = $2; }
| JS_FUNCTION_GLYPH_WITH_CONTEXT source_element { $$ = $2; }
;

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
: JS_FORMAL_PARAMETER_IDENT initialiser__opt
  {
    Identifier* ident = ManagedHandle::Retain( new Identifier( $1->getValue() ) );
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( ident , $2 ) );
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( set );
    $$ = arg;
  }

/*
 *function Example({x,y,z}){...}
 *function Example([x,y,z]){...}
 *ES6 proporsal destructuring parameter.
 */
| destructuring_assignment_left_hand_side initialiser__opt
  {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( $1 , $2 ) );
    arg->Args ( set );
    $$ = arg;
  }

| formal_parameter_list ',' destructuring_assignment_left_hand_side initialiser__opt
  {
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( $3 , $4 ) );
    $1->Args ( set );
    $$ = $1;
  }
| formal_parameter_list ',' JS_FORMAL_PARAMETER_IDENT initialiser__opt
  {
    Identifier* ident = ManagedHandle::Retain( new Identifier( $3->getValue() ) );
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( ident , $4 ) );
    $1->Args ( set );
    $$ = $1;
  }

| formal_parameter_list ',' formal_parameter_rest
  {
    Empty* empty = ManagedHandle::Retain<Empty>();
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( $3 , empty ) );
    $1->Args ( set );
    $$ = $1;
  }
;

/*
 *function Example(x,...y){...}
 *ES6 proporsal rest parameter.
 */
formal_parameter_rest
: JS_PARAMETER_REST JS_FORMAL_PARAMETER_IDENT
  {
    FormalParameterRest* rest = ManagedHandle::Retain( new FormalParameterRest( $2->getValue() ) );
    $$ = rest;
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
    Spread* spread = ManagedHandle::Retain( new Spread( $2->getValue() ) );
    $$ = spread;
  }
;

function_body
: { $$ = ManagedHandle::Retain<Empty> (); }
| source_elements { $$ = $1; }
;

source_elements
: source_element
  {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( $1 );
    $$ = ret;
  }
| source_elements source_element
  {
    $1->List ( $2 );
    $$ = $1;
  }
;

source_element
: statement { $$ = $1; }
| function_declaration
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
;

formal_parameter_list__opt
: { $$ = ManagedHandle::Retain<Empty> (); }
| formal_parameter_list
  {
    $$ = $1;
  }
;

identifier__opt
: { $$ = ""; }
| JS_IDENTIFIER
  {
    $$ = $1->getValue ();
  }
;

statement
: block
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| module_block
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| export_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| variable_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| let_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| empty_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| expression_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| if_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| iteration_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| continue_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| break_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| return_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| with_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| labelled_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| switch_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| throw_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
| try_statement
  { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( $1 ) );
    $$ = blocks;
  }
;

block
: '{' '}'
  {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    $$ = block;
  }
| '{' statement_list '}'
  {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( $2 );
    $$ = block;
  }
;


module_block
: JS_MODULE JS_IDENTIFIER statement terminator
  {
    Module* module = ManagedHandle::Retain( new Module( $2->getValue() ) );
    module->Body( $3 );
  }
;


export_statement
: JS_EXPORT variable_statement
  {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( $2 );
  }
| JS_EXPORT function_declaration
  {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( $2 );
  }
;


statement_list
: statement
  {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( $1 );
    $$ = ret;
  }
| statement_list statement
  {
    $1->List ( $2 );
    $$ = $1;
  }
;


variable_statement
: JS_VAR variable_declaration_list terminator
  {
    $2->LineNumber ( $1->getLineNumber () );
    $2->Terminate();
    $2->Type( VariableDeclarationList::kNormal );
    $$ = $2;
  }
| JS_CONST variable_declaration_list terminator
  {
    $2->LineNumber ( $1->getLineNumber () );
    $2->Terminate();
    $2->Type( VariableDeclarationList::kConst );
    $$ = $2;
  }
| JS_LET variable_declaration_list terminator
  {
    $2->LineNumber ( $1->getLineNumber () );
    $2->Terminate();
    $2->Type( VariableDeclarationList::kLet );
    $$ = $2;
  }
;

let_statement
: JS_LET '(' let_assignment_list ')' statement
  {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Exp( $3 );
    let->Body( $5 );
    $$ = let;
  }

let_assignment_list
: let_assignment_expression
  {
    Arguments* arg = ManagedHandle::Retain<Arguments>();
    arg->Value( $1 );
    $$ = arg;
  }
| let_assignment_list ',' let_assignment_expression
  {
    $1->Value( $3 );
    $$ = $1;
  }

let_assignment_expression
: JS_IDENTIFIER initialiser__opt
  {
    Identifier* ident = ManagedHandle::Retain( new Identifier( $1->getValue() ) );
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , ident , $2 ) );
    $$ = assign;
  }
| destructuring_assignment_left_hand_side initialiser
  {
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , $1 , $2 ) );
    $$ = assign;
  }
; 

variable_declaration_list
: variable_declaration 
  {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( $1 );
    $$ = ret;
  }
| variable_declaration_list ',' variable_declaration
  {
    $1->List ( $3 );
    $$ = $1;
  }
;

variable_declaration_list_no_in
: variable_declaration_no_in
  {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( $1 );
    $$ = ret;
  }
| variable_declaration_list_no_in ',' variable_declaration_no_in
  {
    $1->List ( $3 );
    $$ = $1;
  }
;

variable_declaration
: JS_FORMAL_PARAMETER_IDENT initialiser__opt
  {
    const char* ident = $1->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( $2 );
    $$ = var;
  }
| destructuring_assignment_left_hand_side initialiser
  {
    $1->Data( $1 );
    $1->Value( $2 );
    $$ = $1;
  }
;

variable_declaration_no_in
: JS_FORMAL_PARAMETER_IDENT initialiser_no_in__opt
  {
    const char* ident = $1->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( $2 );
    $$ = var;
  }
| destructuring_assignment_left_hand_side initialiser_no_in
  {
    $1->Value( $2 );
    $$ = $1;
  }
;
 

destructuring_assignment_left_hand_side
: array_left_hand_side
  {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( $1 );
    $$ = dsta;
  }
| object_left_hand_side
  {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( $1 );
    $$ = dsta;
  }
;


array_left_hand_side
: JS_DARRAY_BEGIN elision__opt JS_DARRAY_END
  {
    DestructuringArray *ret = ManagedHandle::Retain<DestructuringArray>();
    ElementLHS* els = ManagedHandle::Retain<ElementLHS>();
    ret->Value ( els );
    $$ = ret;
  }
| JS_DARRAY_BEGIN array_left_hand_element_list JS_DARRAY_END
  {
    DestructuringArray *ret = ManagedHandle::Retain<DestructuringArray>();
    ret->Value ( $2 );
    $$ = ret;
  }
| JS_DARRAY_BEGIN array_left_hand_element_list ',' elision__opt JS_DARRAY_END
  {
    DestructuringArray *ret = ManagedHandle::Retain<DestructuringArray>();
    ret->Value ( $2 );
    $$ = ret;
  }
;

array_left_hand_element_list
: elision__opt JS_FORMAL_PARAMETER_IDENT
  {
    ElementLHS *ret = ManagedHandle::Retain<ElementLHS> ();
    if ( $1 ) {
      ret->List( ManagedHandle::Retain<Empty>() );
    }
    Identifier* ident = ManagedHandle::Retain( new Identifier( $2->getValue() ) );
    ret->List( ident );
    $$ = ret;
  }
| elision__opt destructuring_assignment_left_hand_side
  {
    ElementLHS *ret = ManagedHandle::Retain<ElementLHS> ();
    if ( $1 ) {
      ret->List( ManagedHandle::Retain<Empty>() );
    }
    ret->List( $2 );
    $$ = ret;
  }
| array_left_hand_element_list ',' elision__opt JS_FORMAL_PARAMETER_IDENT
  {
    if ( $3 ) {
      $1->List( ManagedHandle::Retain<Empty>() );
    }
    Identifier* ident = ManagedHandle::Retain( new Identifier( $4->getValue() ) );
    $1->List( ident );
    $$ = $1;
  }
| array_left_hand_element_list ',' elision__opt destructuring_assignment_left_hand_side
  {
    if ( $3 ) {
      $1->List( ManagedHandle::Retain<Empty>() );
    }
    $1->List( $4 );
    $$ = $1;
  }
| array_left_hand_element_list ',' elision__opt formal_parameter_rest
  {
    if ( $3 ) {
      $1->List( ManagedHandle::Retain<Empty>() );
    }
    $1->List( $4 );
    $$ = $1;
  }
;

object_left_hand_side
: JS_DOBJECT_BEGIN object_member_left_hand_side_list JS_DOBJECT_END { $$ = $2; }
;


object_member_left_hand_side_list
:  JS_FORMAL_PARAMETER_IDENT
  {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( $1->getValue() ) );
    mem->Left( ident );
    mem->Right( ident );
    dsto->List( mem );
    $$ = dsto;
  }
| property_name ':' JS_FORMAL_PARAMETER_IDENT
  {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( $3->getValue() ) );
    mem->Left( $1 );
    mem->Right( ident );
    dsto->List( mem );
    $$ = dsto;
  }

| property_name ':' destructuring_assignment_left_hand_side
  {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    mem->Left( $1 );
    mem->Right( $3 );
    dsto->List( mem );
    $$ = dsto;
  }
  
| object_member_left_hand_side_list ',' property_name ':' JS_FORMAL_PARAMETER_IDENT
  {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( $5->getValue() ) );
    mem->Left( $3 );
    mem->Right( ident );
    $1->List( mem );
    $$ = $1;
  }

| object_member_left_hand_side_list ',' JS_FORMAL_PARAMETER_IDENT
  {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( $3->getValue() ) );
    mem->Left( ident );
    mem->Right( ident );
    $1->List( mem );
    $$ = $1;
  }
| object_member_left_hand_side_list ',' property_name ':' destructuring_assignment_left_hand_side
  {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    mem->Left( $3 );
    mem->Right( $5 );
    $1->List( mem );
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
: terminator { $$ = ManagedHandle::Retain<Empty> (); }
;

expression_statement
: expression terminator
  {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( $1 );
    $$ = exp_stmt;
  }
;

if_statement
: JS_IF '(' expression ')' statement JS_ELSE statement 
  {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Then ( $3 );
    ret->Body ( $5 );
    ret->Else ( $7 );
    $$ = ret;
  }
| JS_IF '(' expression ')' statement
  {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Then ( $3 );
    ret->Body ( $5 );
    $$ = ret;
  }
;

iteration_statement
: JS_DO statement JS_WHILE '(' expression ')' {EXPECT_TERMINATOR;} terminator
  {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $2 );
    ret->Condition ( $5 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_WHILE '(' expression ')' statement
  {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Condition ( $3 );
    ret->Body ( $5 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR '(' expression_no_in__opt ';' expression__opt ';' expression__opt ')' statement
  {
    For *ret = ManagedHandle::Retain<For> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Index ( $3 );
    ret->Condition ( $5 );
    ret->Increment ( $7 );
    ret->Body ( $9 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR '(' JS_VAR variable_declaration_list_no_in ';' expression__opt ';' expression__opt ')' statement
  {
    For *ret = ManagedHandle::Retain<For> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Index ( $4 );
    ret->Condition ( $6 );
    ret->Increment ( $8 );
    ret->Body ( $10 );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR '(' left_hand_side_expression JS_IN expression ')' statement
  {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $3 );
    ret->Target ( $5 );
    ret->Body ( $7 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
  {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $4 );
    ret->Target ( $6 );
    ret->Body ( $8 );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }

| JS_FOR JS_EACH '(' left_hand_side_expression JS_IN expression ')' statement
  {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $4 );
    ret->Target ( $6 );
    ret->Body ( $8 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR JS_EACH '(' JS_VAR variable_declaration_no_in JS_IN expression ')' statement
  {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $5 );
    ret->Target ( $7 );
    ret->Body ( $9 );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
;

continue_statement
: JS_CONTINUE identifier__opt {EXPECT_TERMINATOR;} terminator
  {
    Continue *ret = ManagedHandle::Retain ( new Continue ( $2 ) );
    ret->LineNumber ( $1->getLineNumber () );
    $$ = ret;
  }
;

break_statement
: JS_BREAK identifier__opt {EXPECT_TERMINATOR;} terminator
  {
    Break *ret = ManagedHandle::Retain ( new Break ( $2 ) );
    ret->LineNumber ( $1->getLineNumber () );
    $$ = ret;
  }
;

return_statement
: JS_RETURN expression__opt terminator
  {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Expression ( $2 );
    $2->Terminate ();
    $$ = ret;
  }
;

with_statement
: JS_WITH '(' expression ')' statement
  {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Expression ( $3 );
    ret->Body ( $5 );
    $$ = ret;
  }
;

switch_statement
: JS_SWITCH '(' expression ')' case_block
  {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Expression ( $3 );
    ret->CaseBlock ( $5 );
    $$ = ret;
  }
;

case_block
: '{' case_clauses__opt '}'
  {
    $$ = $2;
  }
| '{' case_clauses__opt default_clause case_clauses__opt '}'
  {
    $2->List ( $3 );
    $2->List ( $4 );
    $$ = $2;
  }
;

case_clauses
: case_clause
  { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( $1 );
    $$ = ret;
  }
| case_clauses case_clause
  {
    $1->List ( $2 );
    $$ = $1;
  }
;

case_clause
: JS_CASE expression ':' statement_list__opt
  {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Expression ( $2 );
    ret->Body ( $4 );
    $$ = ret;
  }
;

default_clause
: JS_DEFAULT ':' statement_list__opt
  {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $3 );
    $$ = ret;
  }
;

labelled_statement
: JS_IDENTIFIER ':' statement
  {
    const char* ident = $1->getValue ();
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $3 );
    $$ = ret;
  }
;

throw_statement
: JS_THROW expression {EXPECT_TERMINATOR;} terminator
  {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Expression ( $2 );
    $$ = ret;
  }
;

try_statement
: JS_TRY block catch
  {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $2 );
    ret->CatchBody ( $3 );
    $$ = ret;
  }
| JS_TRY block finally
  {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $2 );
    ret->FinallyBody ( $3 );
    $$ = ret;
  }
| JS_TRY block catch finally
  {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $2 );
    ret->CatchBody ( $3 );
    ret->FinallyBody ( $4 );
    $$ = ret;
  }
;

catch
: JS_CATCH '(' JS_IDENTIFIER ')' block
  {
    Catch *ret = ManagedHandle::Retain ( new Catch ( $3->getValue () ) );
    ret->LineNumber ( $1->getLineNumber () );
    ret->Body ( $5 );
    $$ = ret;
  }
;

finally
: JS_FINALLY block
  {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Block ( $2 );
    $$ = ret;
  }
;

statement_list__opt
: { $$ = ManagedHandle::Retain<StmtList> (); }
| statement_list { $$ = $1; }
;

initialiser__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| initialiser { $$ = $1; }
;

initialiser_no_in__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| initialiser_no_in { $$ = $1; }
;

case_clauses__opt
: { $$ = ManagedHandle::Retain<CaseClauses> (); }
| case_clauses { $$ = $1; }
;

literal
: null_literal { $$ = $1; }
| boolean_literal { $$ = $1; }
| JS_NUMERIC_LITERAL
  {
    $$ = ManagedHandle::Retain ( new NumberLiteral ( $1->getValue () ) );
  }
| JS_STRING_LITERAL
  {
    $$ = ManagedHandle::Retain ( new StringLiteral ( $1->getValue () ) );
  }
| JS_REGEXP_LITERAL
  {
    $$ = ManagedHandle::Retain ( new RegExpLiteral ( $1->getValue () ) );
  }
;

null_literal
: JS_K_NULL
  {
    $$ = ManagedHandle::Retain<NullLiteral> ();
  }
;

boolean_literal
: JS_TRUE
  {
    $$ = ManagedHandle::Retain ( new BooleanLiteral ( $1->getValue () ) );
  }
| JS_FALSE
  {
    $$ = ManagedHandle::Retain ( new BooleanLiteral ( $1->getValue () ) );
  }
;

primary_expression
: JS_THIS 
  { 
    $$ = ManagedHandle::Retain<This> ();
  }
| JS_IDENTIFIER
  {
    //scope->Update ( $1->getValue () );
    $$ = ManagedHandle::Retain ( new Identifier ( $1->getValue () ) );
  }
| literal { $$ = $1; }
| array_literal { $$ = $1; }
| object_literal { $$ = $1; }
| '(' expression ')' 
  {
    $2->Paren ( true );
    $$ = $2;
  }
;

array_literal
: '[' elision__opt ']'
  {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    $$ = ret;
  }
| '[' element_list ']'
  {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( $2 );
    $$ = ret;
  }
| '[' element_list ',' elision__opt ']'
  {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( $2 );
    $$ = ret;
  }
| '[' element_list array_comprehensions ']'
  {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    $3->Exp( $2 );
    ret->Value ( $3 );
    $$ = ret;
  }
;

element_list
: elision__opt assignment_expression
  {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( $2 );
    $$ = ret;
  }
| element_list ',' elision__opt assignment_expression
  {
    $1->Value ( $4 );
    $$ = $1;
  }
;

elision
: ','
| elision ','
;


array_comprehensions
: array_comprehension_iteration array_comprehension_if__opt
  {
    ArrayComprehensions* comp = ManagedHandle::Retain<ArrayComprehensions>();
    comp->Iteration( $1 );
    comp->OptIf( $2 );
  }
;

array_comprehension_iteration
: JS_FOR '(' left_hand_side_expression JS_IN expression ')'
  {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $3 );
    ret->Target ( $5 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
| JS_FOR JS_EACH '(' left_hand_side_expression JS_IN expression ')'
  {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Item ( $4 );
    ret->Target ( $6 );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    $$ = it;
  }
;

array_comprehension_if__opt
: { $$ = ManagedHandle::Retain<Empty>(); }
| JS_IF '(' expression ')'
  {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( $1->getLineNumber () );
    ret->Then ( $3 );
    $$ = ret;
  }
;

object_literal
: '{' property_name_and_value_list__opt '}' 
  {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( $2 ) );
    $$ = ret;
  }
;

property_name_and_value_list__opt
: { 
    $$ = ManagedHandle::Retain<Empty>();
  }
| property_name_and_value_list
  {
    $$ = $1;
  }
;

property_name_and_value_list
: property_name ':' assignment_expression
  {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( $1 , $3 );
    $$ = ret;
  }
| property_name_and_value_list ',' property_name ':' assignment_expression
  {
    $1->Value ( $3 , $5 );
    $$ = $1;
  }
;

property_name
: JS_IDENTIFIER
  {
    const char* ident = $1->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    $$ = property;
  }
| JS_STRING_LITERAL
  {
    const char* ident = $1->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    $$ = property;
  }
| JS_NUMERIC_LITERAL
  {
    const char* ident = $1->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    $$ = property;
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
| member_expression '[' expression ']'
  {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , $1 , $3 ) );
    $$ = ret;
  }
| member_expression '.' JS_IDENTIFIER
  {
    const char* ident = $3->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , $1 , lit ) );
    $$ = ret;
  }
| JS_NEW member_expression arguments
  {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , $2 , $3 ) );
    $$ = ret;
  }
;

new_expression
: member_expression { $$ = $1; }
| JS_NEW new_expression
  {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , $2 , ManagedHandle::Retain<Empty>() ) );
    $$ = ret;
  }
;

call_expression
: member_expression arguments
  {
    ConstantLiteral *literal = $1->CastToLiteral();
    Identifier *ident;
    if ( AstUtil::IsValidAst( literal ) ) {
      ident = literal->CastToIdentifier();
      if ( AstUtil::IsValidAst( ident ) ) {
        const char* value = ident->Value();
        if ( value && strcmp( value , "require" ) == 0 ) {
          std::list<AstTypeBase*>::iterator begin = $2->Value().begin();
          if ( begin == $2->Value().end() ) {
            goto NORMAL_FN_CALL;
          }
          ConstantLiteral *literal = (*begin)->CastToLiteral();
          if ( AstUtil::IsValidAst( literal ) && AstUtil::IsValidAst( literal->CastToStringLiteral() ) ) {
            std::string js_path = literal->CastToStringLiteral()->Value();
            js_path.erase( 0 , 1 );
            js_path.erase( js_path.size() - 1 , js_path.size() );
            StrHandle current = VirtualDirectory::GetInstance()->GetCurrentDir();
            compiler->Load ( js_path.c_str() );
            VirtualDirectory::GetInstance()->Chdir( current.Get() );
            std::string mkey = "\"";
            mkey += VirtualDirectory::GetInstance()->GetModuleKey();
            mkey += "\"";
            StringLiteral* key = ManagedHandle::Retain( new StringLiteral( mkey.c_str() ) );
            Identifier *accessor = ManagedHandle::Retain( new Identifier( "__global_exports" ) );
            ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , accessor , key ) );
            $$ = ret;
          } else {
            goto NORMAL_FN_CALL;
          }
        } else {
          goto NORMAL_FN_CALL;
        }
      } else {
        goto NORMAL_FN_CALL;
      }
    } else {
   NORMAL_FN_CALL :
      CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , $1 , $2 ) );
      $$ = ret;
    }
  }
| call_expression arguments
  {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , $1 , $2 ) );
    $$ = ret;
  }
| call_expression '[' expression ']'
  {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , $1 , $3 ) );
    $$ = ret;
  }
| call_expression '.' JS_IDENTIFIER
  {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( $3->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , $1 , lit ) );
    $$ = ret;
  }
;

arguments
: '(' ')' { $$ = ManagedHandle::Retain<Arguments> (); }
| '(' argument_list ')' { $$ = $2; }
;

argument_list
: assignment_expression
  {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( $1 );
    $$ = ret;
  }
| arguments_spread
  {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( $1 );
    $$ = ret;
  }
| argument_list ',' assignment_expression
  {
    $1->Value ( $3 );
    $$ = $1;
  }
| argument_list ',' arguments_spread
  {
    $1->Value ( $3 );
    $$ = $1;
  }
;

left_hand_side_expression
: new_expression { $$ = $1; }
| call_expression { $$ = $1; }
;

postfix_expression
: left_hand_side_expression
  {
    $$ = $1;
  }
| left_hand_side_expression JS_INCREMENT
  {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , $1, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| left_hand_side_expression JS_DECREMENT
  {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , $1, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
;

unary_expression
: postfix_expression { $$ = $1; }
| JS_DELETE unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| JS_VOID unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| JS_TYPEOF unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| JS_INCREMENT unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| JS_DECREMENT unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| '+' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| '-' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| '~' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
| '!' unary_expression
  {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , $2, ManagedHandle::Retain<Empty> () ) );
    $$ = ret;
  }
;

multiplicative_expression
: unary_expression { $$ = $1; }
| multiplicative_expression '*' unary_expression
  {
    TREE_REDUCE(MultiplicativeExp,$1,Constant::kMul,$3,$$);
  }
| multiplicative_expression '/' unary_expression
  {
    TREE_REDUCE(MultiplicativeExp,$1,Constant::kDiv,$3,$$);
  }
| multiplicative_expression '%' unary_expression
  {
    TREE_REDUCE(MultiplicativeExp,$1,Constant::kMod,$3,$$);
  }
;

additive_expression
: multiplicative_expression { $$ = $1; }
| additive_expression '+' multiplicative_expression
  {
    TREE_REDUCE(AdditiveExp,$1,Constant::kPlus,$3,$$);
  }
| additive_expression '-' multiplicative_expression
  {
    TREE_REDUCE(AdditiveExp,$1,Constant::kPlus,$3,$$);
  }
;

shift_expression
: additive_expression { $$ = $1; }
| shift_expression JS_SHIFT_LEFT additive_expression
  {
    TREE_REDUCE(ShiftExp,$1,Constant::kShiftLeft,$3,$$);
  }
| shift_expression JS_SHIFT_RIGHT additive_expression
  {
    TREE_REDUCE(ShiftExp,$1,Constant::kShiftRight,$3,$$);
  }
| shift_expression JS_U_SHIFT_RIGHT additive_expression
  {
    TREE_REDUCE(ShiftExp,$1,Constant::kUShiftRight,$3,$$);
  }
;

relational_expression
: shift_expression { $$ = $1; }
| relational_expression '<' shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kLess,$3,$$);
  }
| relational_expression '>' shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kGreater,$3,$$);
  }
| relational_expression JS_LESS_EQUAL shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kLessEq,$3,$$);
  }
| relational_expression JS_GRATER_EQUAL shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kGreaterEq,$3,$$);
  }
| relational_expression JS_INSTANCEOF shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kInstanceof,$3,$$);
  }
| relational_expression JS_IN shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kIn,$3,$$);
  }
;

relational_expression_no_in
: shift_expression { $$ = $1; }
| relational_expression_no_in '<' shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kLess,$3,$$);
  }
| relational_expression_no_in '>' shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kGreater,$3,$$);
  }
| relational_expression_no_in JS_LESS_EQUAL shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kLessEq,$3,$$);
  }
| relational_expression_no_in JS_GRATER_EQUAL shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kGreaterEq,$3,$$);
  }
| relational_expression_no_in JS_INSTANCEOF shift_expression
  {
    TREE_REDUCE(RelationalExp,$1,Constant::kInstanceof,$3,$$);
  }
;

equality_expression
: relational_expression { $$ = $1; }
| equality_expression JS_EQUAL relational_expression
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kEq,$3,$$);
  }
| equality_expression JS_NOT_EQUAL relational_expression
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kNotEq,$3,$$);
  }
| equality_expression JS_EQ relational_expression
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kEq,$3,$$);
  }
| equality_expression JS_NOT_EQ relational_expression
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kNotEq,$3,$$);
  }
;

equality_expression_no_in
: relational_expression_no_in { $$ = $1; }
| equality_expression_no_in JS_EQUAL relational_expression_no_in
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kEq,$3,$$);
  }
| equality_expression_no_in JS_NOT_EQUAL relational_expression_no_in
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kNotEq,$3,$$);
  }
| equality_expression_no_in JS_EQ relational_expression_no_in
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kEq,$3,$$);
  }
| equality_expression_no_in JS_NOT_EQ relational_expression_no_in
  {
    TREE_REDUCE(EqualityExp,$1,Constant::kNotEq,$3,$$);
  }
;

bitwise_and_expression
: equality_expression { $$ = $1; }
| bitwise_and_expression '&' equality_expression
  {
    TREE_REDUCE(BitwiseANDExp,$1,Constant::kAND,$3,$$);
  }
;

bitwise_and_expression_no_in
: equality_expression_no_in { $$ = $1; }
| bitwise_and_expression_no_in '&' equality_expression_no_in
  {
    TREE_REDUCE(BitwiseANDExp,$1,Constant::kAND,$3,$$);
  }
;

bitwise_xor_expression
: bitwise_and_expression { $$ = $1; }
| bitwise_xor_expression '^' bitwise_and_expression
  {
    TREE_REDUCE(BitwiseXORExp,$1,Constant::kXOR,$3,$$);
  }
;

bitwise_xor_expression_no_in
: bitwise_and_expression_no_in { $$ = $1;}
| bitwise_xor_expression_no_in '^' bitwise_and_expression_no_in
  {
    TREE_REDUCE(BitwiseXORExp,$1,Constant::kXOR,$3,$$);
  }
;

bitwise_or_expression
: bitwise_xor_expression { $$ = $1; }
| bitwise_or_expression '|' bitwise_xor_expression
  {
    TREE_REDUCE(BitwiseORExp,$1,Constant::kOR,$3,$$);
  }
;

bitwise_or_expression_no_in
: bitwise_xor_expression_no_in { $$ = $1; }
| bitwise_or_expression_no_in '|' bitwise_xor_expression_no_in
  {
    TREE_REDUCE(BitwiseORExp,$1,Constant::kOR,$3,$$);
  }
;

logical_and_expression
: bitwise_or_expression { $$ = $1; }
| logical_and_expression JS_LOGICAL_AND bitwise_or_expression
  {
    TREE_REDUCE(LogicalANDExp,$1,Constant::kLogicalAND,$3,$$);
  }
;

logical_and_expression_no_in
: bitwise_or_expression_no_in { $$ = $1; }
| logical_and_expression_no_in JS_LOGICAL_AND bitwise_or_expression_no_in
  {
    TREE_REDUCE(LogicalANDExp,$1,Constant::kLogicalAND,$3,$$);
  }
;

logical_or_expression
: logical_and_expression {$$ = $1; }
| logical_or_expression JS_LOGICAL_OR logical_and_expression
  {
    TREE_REDUCE(LogicalORExp,$1,Constant::kLogicalOR,$3,$$);
  }
;

logical_or_expression_no_in
: logical_and_expression_no_in { $$ =$1; }
| logical_or_expression_no_in JS_LOGICAL_OR logical_and_expression_no_in
  {
    TREE_REDUCE(LogicalORExp,$1,Constant::kLogicalOR,$3,$$);
  }
;

conditional_expression
: logical_or_expression { $$ = $1; }
| logical_or_expression '?' assignment_expression ':' assignment_expression
  {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( $1 , $3 , $5 ) );
    ret->Prior ( Tree::kExp );
    $$ = ret;
  }
;

conditional_expression_no_in
: logical_or_expression_no_in { $$ = $1; }
| logical_or_expression_no_in '?' assignment_expression_no_in ':' assignment_expression_no_in
  {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( $1 , $3 , $5 ) );
    ret->Prior ( Tree::kExp );
    $$ = ret;
  }
;

assignment_expression
: conditional_expression
  {
    $$ = $1;
  }
| left_hand_side_expression assignment_operator assignment_expression
  {
    Assign *ret = ManagedHandle::Retain ( new Assign ( $2 , $1 , $3 ) );
    $$ = ret;
  }
| array_left_hand_side assignment_operator assignment_expression
  {
    Assign *ret = ManagedHandle::Retain ( new Assign ( $2 , $1 , $3 ) );
    $$ = ret;
  }
;


assignment_expression_no_in
: conditional_expression_no_in
  {
    $$ = $1;
  }
| left_hand_side_expression assignment_operator assignment_expression_no_in
  {
    $$ = ManagedHandle::Retain ( new Assign ( $2 , $1 , $3 ) );
  }
;



assignment_operator
:  '=' { $$ = Constant::kAssign; }
|  JS_MUL_LET { $$ = Constant::kMulLet; }
|  JS_DIV_LET { $$ = Constant::kDivLet; }
|  JS_MOD_LET { $$ = Constant::kModLet; }
|  JS_ADD_LET { $$ = Constant::kAddLet; }
|  JS_SUB_LET { $$ = Constant::kSubLet; }
|  JS_SHIFT_LEFT_LET { $$ = Constant::kLShiftLet; }
|  JS_SHIFT_RIGHT_LET { $$ = Constant::kRShiftLet; }
|  JS_U_SHIFT_RIGHT_LET { $$ = Constant::kURShiftLet; }
|  JS_AND_LET { $$ = Constant::kANDLet; }
|  JS_NOT_LET { $$ = Constant::kNotLet; }
|  JS_OR_LET { $$ = Constant::kORLet; }
;

expression
: assignment_expression
  { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( $1 );
    $$ = exp;
  }
| expression ',' assignment_expression
  {
    $1->List ( $3 );
    $$ = $1;
  }
;

expression_no_in
: assignment_expression_no_in
  { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( $1 );
    $$ = exp;
  }
| expression_no_in ',' assignment_expression_no_in
  {
    $1->List ( $3 );
    $$ = $1;
  }
;

expression_no_in__opt
: { $$ = ManagedHandle::Retain<Expression> (); }
| expression_no_in { $$ = $1; }
;

expression__opt
: { $$ = ManagedHandle::Retain<Expression> (); }
| expression { $$ = $1; }
;

elision__opt
: { $$ = false; }
| elision { $$ = true; }
;

terminator
: ';' {$<num>$ = ';';}
| JS_LINE_BREAK {$<num>$ = ';';tracer->SetLineBreakFlag ( false );}
| {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  } error{yyclearin;yyerrok;} ';'
;

%%

void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}
