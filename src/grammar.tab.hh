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

/* Line 35 of lalr1.cc  */
#line 39 "src/grammar.yy"

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



/* Line 35 of lalr1.cc  */
#line 58 "grammar.tab.hh"


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

/* Line 35 of lalr1.cc  */
#line 88 "grammar.tab.hh"

  /// A Bison parser.
  class ParserImplementation
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 52 "src/grammar.yy"

  mocha::TokenInfo *info;
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
  const char* ident;
  int num;
  long int line;



/* Line 35 of lalr1.cc  */
#line 142 "grammar.tab.hh"
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
     U_SHIFT_RIGHT_LET = 258,
     SUB_LET = 259,
     SHIFT_RIGHT_LET = 260,
     SHIFT_LEFT_LET = 261,
     OR_LET = 262,
     NOT_LET = 263,
     MUL_LET = 264,
     MOD_LET = 265,
     DIV_LET = 266,
     AND_LET = 267,
     ADD_LET = 268,
     LOGICAL_OR = 269,
     LOGICAL_AND = 270,
     NOT_EQ = 271,
     NOT_EQUAL = 272,
     EQUAL = 273,
     EQ = 274,
     INSTANCEOF = 275,
     IN = 276,
     LESS_EQUAL = 277,
     GREATER_EQUAL = 278,
     U_SHIFT_LEFT = 279,
     U_SHIFT_RIGHT = 280,
     SHIFT_RIGHT = 281,
     SHIFT_LEFT = 282,
     DELETE = 283,
     VOID = 284,
     TYPEOF = 285,
     DECREMENT = 286,
     INCREMENT = 287,
     NEW = 288,
     ABSTRACT = 289,
     BOOLEAN = 290,
     BREAK = 291,
     BYTE = 292,
     CASE = 293,
     CATCH = 294,
     CHAR = 295,
     CLASS = 296,
     CONST = 297,
     CONTINUE = 298,
     DEBUGGER = 299,
     DEFAULT = 300,
     DO = 301,
     DOUBLE = 302,
     ELSE = 303,
     ENUM = 304,
     EXPORT = 305,
     EXTENDS = 306,
     FALSE = 307,
     FINAL = 308,
     FINALLY = 309,
     FLOAT = 310,
     FOR = 311,
     FUNCTION = 312,
     GOTO = 313,
     GRATER_EQUAL = 314,
     IDENTIFIER = 315,
     IF = 316,
     IMPLEMENTS = 317,
     IMPORT = 318,
     INT = 319,
     INTERFACE = 320,
     LONG = 321,
     NATIVE = 322,
     K_NULL = 323,
     NUMERIC_LITERAL = 324,
     PRIVATE = 325,
     PACKAGE_RESERVED = 326,
     PROTECTED = 327,
     PUBLIC = 328,
     REGEXP_LITERAL = 329,
     RETURN = 330,
     SHORT = 331,
     STATIC = 332,
     STRING_LITERAL = 333,
     SUPER = 334,
     SWITCH = 335,
     SYNCHRONIZED = 336,
     THIS = 337,
     THROW = 338,
     THROWS = 339,
     TRANSIENT = 340,
     TRUE = 341,
     TRY = 342,
     VAR = 343,
     VOLATILE = 344,
     WHILE = 345,
     WITH = 346,
     TERMINATE = 347,
     LINE_BREAK = 348
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    ParserImplementation (mocha::Compiler* compiler_yyarg, mocha::ParserConnector* connector_yyarg, mocha::ParserTracer *tracer_yyarg, mocha::AstRoot* ast_root_yyarg, mocha::Scope* scope_yyarg);
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
    static const unsigned char yydefact_[];

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
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
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
    mocha::Scope* scope;
  };

} // yy

/* Line 35 of lalr1.cc  */
#line 428 "grammar.tab.hh"



#endif /* ! defined PARSER_HEADER_H */
