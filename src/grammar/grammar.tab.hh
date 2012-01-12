/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 282 of lalr1.cc  */
#line 34 "grammar/grammar.yy"

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



/* Line 282 of lalr1.cc  */
#line 58 "grammar/grammar.tab.hh"


#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


namespace yy {

/* Line 282 of lalr1.cc  */
#line 88 "grammar/grammar.tab.hh"

  /// A Bison parser.
  class ParserImplementation
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 282 of lalr1.cc  */
#line 47 "grammar/grammar.yy"

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



/* Line 282 of lalr1.cc  */
#line 145 "grammar/grammar.tab.hh"
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     JS_U_SHIFT_RIGHT_LET = 258,
     JS_SUB_LET = 259,
     JS_SHIFT_RIGHT_LET = 260,
     JS_SHIFT_LEFT_LET = 261,
     JS_OR_LET = 262,
     JS_NOT_LET = 263,
     JS_MUL_LET = 264,
     JS_MOD_LET = 265,
     JS_DIV_LET = 266,
     JS_AND_LET = 267,
     JS_ADD_LET = 268,
     JS_LOGICAL_OR = 269,
     JS_LOGICAL_AND = 270,
     JS_NOT_EQ = 271,
     JS_NOT_EQUAL = 272,
     JS_EQUAL = 273,
     JS_EQ = 274,
     JS_INSTANCEOF = 275,
     JS_IN = 276,
     JS_LESS_EQUAL = 277,
     JS_GREATER_EQUAL = 278,
     JS_U_SHIFT_LEFT = 279,
     JS_U_SHIFT_RIGHT = 280,
     JS_SHIFT_RIGHT = 281,
     JS_SHIFT_LEFT = 282,
     JS_DELETE = 283,
     JS_VOID = 284,
     JS_TYPEOF = 285,
     JS_DECREMENT = 286,
     JS_INCREMENT = 287,
     JS_NEW = 288,
     BRACKET = 289,
     JS_ABSTRACT = 290,
     JS_BOOLEAN = 291,
     JS_BREAK = 292,
     JS_BYTE = 293,
     JS_CASE = 294,
     JS_CATCH = 295,
     JS_CHAR = 296,
     JS_CLASS = 297,
     JS_CONST = 298,
     JS_CONTINUE = 299,
     JS_DEBUGGER = 300,
     JS_DEFAULT = 301,
     JS_DO = 302,
     JS_DOUBLE = 303,
     JS_ELSE = 304,
     JS_ENUM = 305,
     JS_EXPORT = 306,
     JS_EXTENDS = 307,
     JS_FALSE = 308,
     JS_FINAL = 309,
     JS_FINALLY = 310,
     JS_FLOAT = 311,
     JS_FOR = 312,
     JS_COMP_FOR = 313,
     JS_FUNCTION = 314,
     JS_GOTO = 315,
     JS_GRATER_EQUAL = 316,
     JS_IDENTIFIER = 317,
     JS_IF = 318,
     JS_IF_OPT = 319,
     JS_IMPLEMENTS = 320,
     JS_IMPORT = 321,
     JS_INT = 322,
     JS_INTERFACE = 323,
     JS_LONG = 324,
     JS_NATIVE = 325,
     JS_K_NULL = 326,
     JS_NUMERIC_LITERAL = 327,
     JS_PRIVATE = 328,
     JS_PACKAGE_RESERVED = 329,
     JS_PROTECTED = 330,
     JS_PUBLIC = 331,
     JS_REGEXP_LITERAL = 332,
     JS_RETURN = 333,
     JS_SHORT = 334,
     JS_STATIC = 335,
     JS_STRING_LITERAL = 336,
     JS_SUPER = 337,
     JS_SWITCH = 338,
     JS_SYNCHRONIZED = 339,
     JS_THIS = 340,
     JS_THROW = 341,
     JS_THROWS = 342,
     JS_TRANSIENT = 343,
     JS_TRUE = 344,
     JS_TRY = 345,
     JS_VAR = 346,
     JS_VOLATILE = 347,
     JS_WHILE = 348,
     JS_WITH = 349,
     JS_TERMINATE = 350,
     JS_LINE_BREAK = 351,
     JS_FUNCTION_GLYPH = 352,
     JS_FUNCTION_GLYPH_WITH_CONTEXT = 353,
     JS_FUNCTION_IDENTIFIER = 354,
     JS_PARAM_BEGIN = 355,
     JS_PARAM_END = 356,
     JS_DOBJECT_BEGIN = 357,
     JS_DOBJECT_END = 358,
     JS_FORMAL_PARAMETER_IDENT = 359,
     JS_LET = 360,
     JS_EACH = 361,
     JS_PARAMETER_REST = 362,
     JS_MODULE = 363,
     JS_EXP_CLOSURE_BEGIN = 364,
     JS_EXP_CLOSURE_END = 365,
     JS_FROM = 366,
     JS_DSTA_BEGIN = 367,
     JS_DSTO_BEGIN = 368,
     JS_DSTA_END = 369,
     JS_DSTO_END = 370,
     JS_CONSTRUCTOR = 371,
     JS_GET = 372,
     JS_SET = 373,
     JS_PROTOTYPE = 374,
     MOCHA_VERSIONOF = 375,
     JS_PROPERTY = 376,
     JS_YIELD = 377,
     JS_YIELD_SENTINEL = 378,
     EX_TOKEN_YIELD = 379
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    ParserImplementation (mocha::Compiler* compiler_yyarg, mocha::ParserConnector* connector_yyarg, mocha::ParserTracer *tracer_yyarg, mocha::AstRoot* ast_root_yyarg);
    virtual ~ParserImplementation ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default reduction number.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned short int yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const short int yytable_[];
    static const short int yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned short int yystos_[];

    /// For a rule, its LHS.
    static const unsigned short int yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef short int rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* User arguments.  */
    mocha::Compiler* compiler;
    mocha::ParserConnector* connector;
    mocha::ParserTracer *tracer;
    mocha::AstRoot* ast_root;
  };

} // yy

/* Line 282 of lalr1.cc  */
#line 461 "grammar/grammar.tab.hh"



#endif /* ! defined PARSER_HEADER_H */
