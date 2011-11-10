/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
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


/* First part of user declarations.  */

/* Line 293 of lalr1.cc  */
#line 1 "src/grammar.yy"

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
#include "scope.h"
#include "compiler.h"
#include "managed_handle.h"
#include "file_system.h"
#include "virtual_directory.h"
  using namespace std;
  using namespace mocha;

#define YYDEBUG 1
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
  

/* Line 293 of lalr1.cc  */
#line 78 "grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 87 "grammar.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {

/* Line 382 of lalr1.cc  */
#line 173 "grammar.tab.cc"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ParserImplementation::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  ParserImplementation::ParserImplementation (mocha::Compiler* compiler_yyarg, mocha::ParserConnector* connector_yyarg, mocha::ParserTracer *tracer_yyarg, mocha::AstRoot* ast_root_yyarg, mocha::Scope* scope_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      compiler (compiler_yyarg),
      connector (connector_yyarg),
      tracer (tracer_yyarg),
      ast_root (ast_root_yyarg),
      scope (scope_yyarg)
  {
  }

  ParserImplementation::~ParserImplementation ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  ParserImplementation::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  ParserImplementation::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  ParserImplementation::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  ParserImplementation::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ParserImplementation::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ParserImplementation::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ParserImplementation::debug_level_type
  ParserImplementation::debug_level () const
  {
    return yydebug_;
  }

  void
  ParserImplementation::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  ParserImplementation::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  ParserImplementation::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ParserImplementation::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, connector);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 690 of lalr1.cc  */
#line 312 "src/grammar.yy"
    {yydebug = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 313 "src/grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 323 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    const char* ident = (yysemantic_stack_[(3) - (2)].info)->getValue ();
    scope->Insert ( ident );
    scope = scope->Enter ();
    (yyval.ident) = ident;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 331 "src/grammar.yy"
    {
    tracer->EndState( ParserTracer::kFunction );
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(9) - (4)].ident) ) );
    fn->Argv ( (yysemantic_stack_[(9) - (5)].ast) );
    fn->Body ( (yysemantic_stack_[(9) - (8)].ast) );
    fn->FnScope ( scope );
    scope = scope->Escape ();
    (yyval.fn) = fn;
  }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 344 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    scope->Insert ( (yysemantic_stack_[(3) - (2)].ident) );
    scope = scope->Enter ();
    (yyval.ident) = (yysemantic_stack_[(3) - (2)].ident);
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 351 "src/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(9) - (4)].ident) ) );
    fn->Argv ( (yysemantic_stack_[(9) - (5)].ast) );
    fn->Body ( (yysemantic_stack_[(9) - (8)].ast) );
    fn->FnScope ( scope );
    scope = scope->Escape ();
    (yyval.fn) = fn;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 365 "src/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(8) - (3)].ast) );
    fn->Body ( (yysemantic_stack_[(8) - (7)].ast) );
    fn->FnScope ( scope );
    (yyval.fn) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 376 "src/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( (yysemantic_stack_[(5) - (4)].ast) );
    fn->FnScope ( scope );
    (yyval.fn) = fn;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 386 "src/grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 394 "src/grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 400 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].farg)->Args ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 405 "src/grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    //scope->Insert ( ident );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 414 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 415 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 420 "src/grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 426 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 433 "src/grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 435 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 442 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 444 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 450 "src/grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 452 "src/grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 459 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 464 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 469 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 474 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 479 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 484 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 489 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 494 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 499 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 504 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 509 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 514 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 519 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 524 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 532 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 538 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 547 "src/grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 553 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 562 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 566 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 572 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 576 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 585 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 591 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 599 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 605 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 613 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 621 "src/grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 630 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 638 "src/grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 647 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 648 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 653 "src/grammar.yy"
    { tracer->SetState( ParserTracer::kObjectLiteralEnd ); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 653 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (3)].dsto); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 659 "src/grammar.yy"
    {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    mem->Left( 0 );
    mem->Right( ident );
    dsto->List( mem );
    (yyval.dsto) = dsto;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 669 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(3) - (1)].property) );
    mem->Right( ident );
    dsto->List( mem );
    (yyval.dsto) = dsto;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 681 "src/grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(5) - (5)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( ident );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 691 "src/grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( 0 );
    mem->Right( ident );
    (yysemantic_stack_[(3) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(3) - (1)].dsto);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 702 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 706 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 710 "src/grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 715 "src/grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 724 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 733 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 743 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 744 "src/grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(8) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(8) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 753 "src/grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 762 "src/grammar.yy"
    {
    For *ret = ManagedHandle::Retain<For> ();
    ret->LineNumber ( (yysemantic_stack_[(9) - (1)].info)->getLineNumber () );
    ret->Index ( (yysemantic_stack_[(9) - (3)].exp) );
    ret->Condition ( (yysemantic_stack_[(9) - (5)].exp) );
    ret->Increment ( (yysemantic_stack_[(9) - (7)].exp) );
    ret->Body ( (yysemantic_stack_[(9) - (9)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 773 "src/grammar.yy"
    {
    For *ret = ManagedHandle::Retain<For> ();
    ret->LineNumber ( (yysemantic_stack_[(10) - (1)].info)->getLineNumber () );
    ret->Index ( (yysemantic_stack_[(10) - (4)].varsList) );
    ret->Condition ( (yysemantic_stack_[(10) - (6)].exp) );
    ret->Increment ( (yysemantic_stack_[(10) - (8)].exp) );
    ret->Body ( (yysemantic_stack_[(10) - (10)].source_block) );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 785 "src/grammar.yy"
    {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(7) - (3)].ast) );
    ret->Target ( (yysemantic_stack_[(7) - (5)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (7)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 795 "src/grammar.yy"
    {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(8) - (4)].ast) );
    ret->Target ( (yysemantic_stack_[(8) - (6)].exp) );
    ret->Body ( (yysemantic_stack_[(8) - (8)].source_block) );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 808 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 809 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 820 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 821 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 832 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 833 "src/grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yysemantic_stack_[(4) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 844 "src/grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 855 "src/grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 866 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 870 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 879 "src/grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 885 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 893 "src/grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 904 "src/grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 914 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    scope->InsertLabel ( ident );
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 925 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 926 "src/grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 936 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 944 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 952 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 964 "src/grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 974 "src/grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 983 "src/grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 984 "src/grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 988 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 989 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 993 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 994 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 998 "src/grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 999 "src/grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1003 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1004 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1006 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1010 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1014 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1021 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1028 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1032 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1039 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1043 "src/grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1047 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1048 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1049 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1051 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1059 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1065 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1071 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1080 "src/grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1086 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1099 "src/grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1106 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1110 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1117 "src/grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1123 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1131 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1139 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1146 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1156 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1160 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1164 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1169 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1177 "src/grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1185 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1187 "src/grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1195 "src/grammar.yy"
    {
    ConstantLiteral *literal = (yysemantic_stack_[(2) - (1)].ast)->CastToLiteral();
    Identifier *ident;
    if ( AstUtil::IsValidAst( literal ) ) {
      ident = literal->CastToIdentifier();
      if ( AstUtil::IsValidAst( ident ) ) {
        const char* value = ident->Value();
        if ( value && strcmp( value , "require" ) == 0 ) {
          std::list<AstTypeBase*>::iterator begin = (yysemantic_stack_[(2) - (2)].args)->Value().begin();
          if ( begin == (yysemantic_stack_[(2) - (2)].args)->Value().end() ) {
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
            (yyval.ast) = ret;
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
      CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
      (yyval.ast) = ret;
      tracer->SetState( ParserTracer::kCallExpEnd );
    }
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1239 "src/grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1245 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1250 "src/grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1258 "src/grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1259 "src/grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1264 "src/grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1270 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1277 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1278 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1283 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1287 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1292 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1299 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1301 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1306 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1311 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1316 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1321 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1326 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1331 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1336 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1341 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1348 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1350 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1354 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1358 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1364 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1366 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1370 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1376 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1378 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1382 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1386 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1392 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1394 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1398 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1402 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1406 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1410 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1414 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1420 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1422 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1426 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1430 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1434 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1438 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1444 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1446 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1450 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1454 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1458 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1464 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1466 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1470 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1474 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1478 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1484 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1486 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1492 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1494 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1500 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1502 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1508 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1510 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1516 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1518 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1524 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1526 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1532 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1534 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1540 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1542 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1548 "src/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1550 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1556 "src/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1558 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1564 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1566 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1574 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1576 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1585 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1589 "src/grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1598 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1602 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1610 "src/grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1611 "src/grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1612 "src/grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1613 "src/grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1614 "src/grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1615 "src/grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1616 "src/grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1617 "src/grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1618 "src/grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1619 "src/grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1620 "src/grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1621 "src/grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1626 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1632 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1640 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1646 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1653 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1654 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1658 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1659 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1663 "src/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1664 "src/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1668 "src/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1669 "src/grammar.yy"
    {(yyval.num) = ';';tracer->SetLineBreakFlag ( false );}
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1670 "src/grammar.yy"
    {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1675 "src/grammar.yy"
    {yyclearin;yyerrok;}
    break;



/* Line 690 of lalr1.cc  */
#line 2879 "grammar.tab.cc"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  ParserImplementation::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int ParserImplementation::yypact_ninf_ = -363;
  const short int
  ParserImplementation::yypact_[] =
  {
      -363,     9,   943,  -363,  1253,  1253,  1253,  1253,  1253,  1253,
    1253,  1253,  1253,  1253,  1260,    48,   -16,   -11,   -16,  1023,
    -363,    11,    22,   -51,    55,  -363,  -363,  -363,  1253,  -363,
     109,  -363,  1253,  -363,    -8,   -11,   112,   121,  -363,   -25,
     700,  -363,  -363,  -363,  -363,  -363,   365,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,    60,
    -363,   173,   560,  -363,  -363,   188,    47,   209,   148,    70,
      97,   127,   153,   211,    73,  -363,  -363,     2,  -363,   243,
     -16,  -363,    83,    50,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,     5,    60,  -363,  -363,    12,   242,   540,
    -363,  -363,   129,  -363,   245,  -363,   129,  -363,  -363,  -363,
     142,  1103,   220,   225,  1023,  1253,   283,  -363,  1253,   283,
     781,     1,   245,  1253,  1253,   -10,   174,   -51,   171,   175,
    -363,  -363,   862,   178,   286,   179,  -363,  1178,  1253,   217,
    -363,  1253,   219,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  1253,  1253,
    1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,
    1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,
    1253,  1253,  1253,  1253,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,    48,  -363,  -363,  -363,  -363,   -54,  1253,  -363,  -363,
      84,   -11,   -54,  -363,   -54,   252,    -6,   269,   209,   137,
     163,   280,   282,   284,   288,    99,  -363,  -363,   300,   189,
    -363,  -363,  -363,    29,   -54,    31,   -54,   259,    -8,   238,
    -363,   -54,    37,    39,  -363,   307,   198,  -363,   365,  -363,
    -363,  -363,    83,  1253,  -363,    41,  -363,    14,  -363,    16,
    -363,  -363,  -363,  -363,  -363,   188,   188,    47,    47,    47,
     209,   209,   209,   209,   209,   209,   148,   148,   148,   148,
      70,    97,   127,   153,   200,   211,  -363,   199,   620,  -363,
    -363,   202,     4,   203,  -363,  -363,  -363,  1253,   204,    30,
     292,   204,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,
    1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,  1253,
    1253,   -10,   -10,  1023,  -363,   227,  -363,   265,  -363,  -363,
    -363,  1023,  1023,    20,   234,   232,   365,   236,  -363,  1253,
    -363,  -363,  -363,  1253,  -363,  -363,  -363,   135,  -363,   271,
      42,  1253,  -363,  -363,    -6,  1253,  1253,  -363,    44,   560,
    -363,   209,   209,   209,   209,   209,   137,   137,   137,   137,
     163,   280,   282,   284,   237,   288,  -363,   239,   241,   246,
     285,   301,  -363,   247,  -363,  -363,  -363,  -363,   244,  -363,
    1253,  -363,  -363,   202,   248,  -363,  -363,  -363,  -363,   249,
      45,  1023,  1253,  1253,   251,   254,  1023,  1253,   301,  -363,
     -52,    -8,   365,  -363,   278,   -54,  1253,  1023,  -363,  -363,
     250,   365,   365,  -363,    33,  -363,   253,  -363,   301,  -363,
     256,  -363,  -363,   260,  -363,  1023,   261,   262,   445,   445,
     263,  -363,  1023,  -363,  -363,  -363,   445,  -363,  -363,  -363,
    -363
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  ParserImplementation::yydefact_[] =
  {
         2,     0,   252,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,    24,   252,
     114,     0,    24,   116,     0,   112,   109,   111,   246,   110,
       0,   115,     0,   113,     0,     0,     0,     0,   251,     0,
     252,   250,    21,   137,     8,     9,     3,    18,    20,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    37,
      36,    38,    39,   117,   107,   108,   136,   118,   119,   141,
     151,   152,   153,   156,   166,   170,   173,   177,   190,   200,
     204,   208,   212,   216,   220,   224,   240,   252,    66,     0,
      24,   116,   129,   153,   162,   163,   165,   164,   157,   158,
     159,   161,   160,     0,   141,   142,   126,     0,   249,     0,
      25,    79,   101,    58,    46,    48,     0,    57,    56,    77,
       0,   244,     0,     0,   252,     0,   247,    81,     0,    92,
     252,     0,    44,     0,     0,    22,     0,   116,   109,   110,
      40,    42,   252,     0,   130,     0,    19,     0,     0,     0,
     143,     0,     0,   144,   236,   233,   235,   234,   239,   238,
     229,   231,   230,   237,   232,   155,   154,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,   253,   133,   135,   134,   120,
     140,   248,   122,   127,   121,   124,   252,     0,   102,    52,
       0,     0,   252,    53,   252,     0,     0,   153,   184,   195,
     202,   206,   210,   214,   218,   222,   226,   242,   245,     0,
       4,     6,    91,     0,   252,     0,   252,     0,     0,    94,
      95,   252,     0,     0,    12,    23,     0,    13,    16,    41,
      43,   128,     0,     0,   147,     0,   149,     0,   139,     0,
     146,   225,   167,   168,   169,   171,   172,   176,   175,   174,
     179,   178,   182,   183,   180,   181,   194,   192,   191,   193,
     201,   205,   209,   213,     0,   217,   241,     0,     0,    80,
      64,    60,     0,     0,    49,    47,    78,     0,   103,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,    22,    22,   252,    82,     0,    93,     0,    98,    96,
      45,   252,   252,     0,     0,     0,    17,     0,   131,     0,
     148,   138,   145,     0,   254,   123,   125,     0,    59,     0,
       0,     0,   104,    54,     0,   246,     0,    55,     0,   153,
     227,   186,   185,   189,   187,   188,   199,   197,   196,   198,
     203,   207,   211,   215,     0,   219,   243,     0,     0,     0,
      69,   105,    84,     0,    72,    83,    15,    14,     0,    11,
       0,   150,   221,    63,     0,    61,    70,    65,    51,     0,
       0,   252,     0,   246,     0,     0,   252,     0,   106,    87,
       0,     0,    16,   132,     0,   252,   246,   252,    75,   223,
       0,    16,    16,    68,     0,    88,     0,    85,   105,    97,
       0,    62,    71,     0,    76,   252,     0,     0,    99,    99,
       0,    10,   252,    73,     5,     7,   100,    89,    90,    86,
      74
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -362,   359,   -44,  -141,    36,   -19,   -28,  -220,  -363,  -363,
    -363,   327,  -363,   164,    25,   -86,  -363,  -363,  -363,   258,
      79,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,   -27,  -363,  -363,  -363,
    -363,  -363,  -363,   145,   -50,  -363,  -363,   -43,  -363,  -363,
    -363,  -363,    18,  -363,  -363,  -363,  -363,  -363,  -206,   374,
     376,  -363,   -34,  -363,    19,  -363,    69,    59,    95,   -53,
    -172,   -95,   205,    80,   206,    82,   208,    87,   213,   101,
     207,   104,  -363,  -363,  -363,  -363,  -106,  -219,   343,   -12,
    -363,  -363,  -265,   228,   -69,  -363,  -363
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    42,   321,    43,   322,    44,    45,   245,
     335,   336,    47,   246,   123,    48,    49,   142,    50,   241,
     212,   114,   299,   115,   300,   116,   117,   210,   292,   208,
     352,    51,    52,    53,    54,   415,    55,   214,    56,   206,
      57,   234,    58,    59,   382,   408,   409,   428,    60,    61,
     236,    62,   239,   240,   447,   209,   353,   410,    63,    64,
      65,    66,    67,   107,   108,    68,   143,   144,   145,    69,
      70,    71,   150,   255,    72,    73,    74,    75,    76,    77,
      78,   219,    79,   220,    80,   221,    81,   222,    82,   223,
      83,   224,    84,   225,    85,   226,    86,   227,   303,    87,
     228,   229,   127,   109,    88,    89,   287
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -253;
  const short int
  ParserImplementation::yytable_[] =
  {
       120,   103,   146,   205,   293,   193,   131,   347,   193,     3,
     426,   276,   277,   278,   279,   201,   126,   193,   194,   193,
     129,   141,   135,    93,    93,    93,    93,    93,    93,    93,
      93,    93,   193,   354,   193,   118,   193,   153,    15,    15,
     193,   256,   193,    15,   339,   193,   337,   193,   193,   247,
     430,   106,   111,   118,   119,   377,    38,   237,   121,   436,
     437,   110,   261,   427,    41,   124,   112,   244,   218,    15,
     200,   298,   238,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   172,   173,   360,   284,   136,   286,   191,   192,
     399,   183,   184,   185,   186,   165,   166,   386,   374,   122,
     376,   290,   125,   113,   113,   232,   130,   147,   113,   148,
     149,   141,    38,   233,   317,   318,   235,   187,   199,   348,
      41,   242,   243,   250,   270,   271,   272,   273,   274,   275,
     301,   202,   397,   341,   113,   342,   257,   289,   420,   259,
     217,   394,   323,   295,   325,   296,   188,   338,   355,   438,
     331,   433,   332,   118,   340,   396,   128,   401,   417,   133,
     196,   291,   304,   305,   306,   324,   307,   326,   134,   197,
     197,   189,   330,   177,   178,   179,   180,   181,   198,   198,
     378,   379,   346,   419,   309,   310,   311,   312,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
     328,    93,   393,   308,   366,   367,   368,   369,   446,   446,
     147,   197,   151,   152,   182,   169,   170,   171,   190,   118,
     198,   265,   266,   391,   118,   247,   247,   392,   262,   263,
     264,   174,   175,   176,   195,   203,   207,   387,   211,   215,
     218,   361,   362,   363,   364,   365,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   230,   301,   267,
     268,   269,   231,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   413,   350,   193,  -135,   248,   252,
     358,  -134,   146,   251,   258,   253,   260,   302,   218,   297,
     313,   314,   315,   319,   380,   316,   327,   320,   126,   238,
     333,   334,   384,   385,   165,   166,   343,   344,  -133,   349,
     356,   351,   359,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,   359,    93,   359,   118,
     118,   381,   383,   126,   400,   388,   432,   389,   395,   218,
     406,   118,   390,   402,   404,   431,   407,   403,   412,   405,
     411,    46,   132,   435,   414,   421,  -252,   416,   422,   439,
     359,   441,   118,   442,   213,   294,   444,   445,   449,   398,
     357,   425,   418,   429,   329,   440,   167,   423,   104,   448,
     105,   126,   280,   370,   281,   424,   371,   282,   434,   285,
       4,     5,   372,   283,   126,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   168,   443,   373,    16,   141,
     141,   359,   375,   450,    17,    18,     0,   250,    19,   288,
       0,     0,     0,     0,    20,     0,     0,     0,    21,    22,
       0,     0,    23,    24,     0,     0,  -252,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,     0,    40,
       4,     5,     0,    41,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,    90,
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,     0,    40,
       0,     0,     0,    41,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     4,     5,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,     0,     0,    20,
       0,     0,     0,     0,    90,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,     0,     0,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,    92,     4,     5,     0,     0,   204,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    90,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,     0,     0,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,    92,     4,     5,     0,     0,   345,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,    20,
       0,     0,     0,    21,    90,     0,     0,   137,    24,     0,
       0,     0,     0,     0,     0,    25,   138,     0,     0,     0,
       0,    27,    28,     0,     0,   139,     0,    30,     0,    31,
      32,     0,     0,    33,    34,    35,     0,    36,    37,     0,
      38,     0,    39,     0,    40,   140,     4,     5,    41,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    21,    90,     0,     0,    23,    24,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,     0,     0,    33,    34,    35,     0,    36,    37,
       0,    38,     0,    39,     0,    40,   140,     4,     5,    41,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    90,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     0,    40,   249,     4,     5,
      41,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    22,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,     0,    40,     4,     5,
       0,    41,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    90,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,     0,    40,     4,     5,
       0,    41,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    90,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,   216,     0,
       0,     0,     0,     4,     5,    39,     0,    92,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    90,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     4,     5,
      39,   254,    92,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    90,     0,    20,
      91,     0,     0,     0,    90,     0,     0,    91,    25,    26,
       0,     0,     0,     0,    27,    25,    26,     0,    29,     0,
       0,    27,    31,     0,     0,    29,    33,     0,     0,    31,
       0,     0,     0,    33,     0,    39,     0,    92,     0,     0,
       0,     0,    39,     0,    92
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    13,    46,   109,   210,     3,    34,     3,     3,     0,
      62,   183,   184,   185,   186,     3,    28,     3,    87,     3,
      32,    40,    47,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     3,     3,     3,    17,     3,    71,    49,    49,
       3,   147,     3,    49,     3,     3,   252,     3,     3,   135,
     412,     3,    16,    35,    18,   320,   110,    56,    47,   421,
     422,    77,   168,   115,   118,   116,    77,    77,   121,    49,
     104,    77,    71,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    35,    36,   303,   191,   111,   193,    15,    16,
     355,    21,    22,    23,    24,    45,    46,    77,   317,    77,
     319,   207,    47,   114,   114,   124,   114,    47,   114,    49,
      50,   130,   110,   125,    15,    16,   128,    20,   113,   115,
     118,   133,   134,   142,   177,   178,   179,   180,   181,   182,
     216,   119,   351,   119,   114,   119,   148,   206,   403,   151,
     121,   347,   113,   212,   113,   214,    19,   253,   118,   116,
     113,   416,   113,   135,   113,   113,    47,   113,   113,    47,
      77,    77,    25,    26,    27,   234,    29,   236,    47,    86,
      86,    18,   241,    25,    26,    27,    28,    29,    95,    95,
     321,   322,   288,   402,    21,    22,    23,    24,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     238,   192,    77,    76,   309,   310,   311,   312,   438,   439,
      47,    86,    49,    50,    76,    37,    38,    39,    17,   211,
      95,   172,   173,   339,   216,   321,   322,   343,   169,   170,
     171,    32,    33,    34,     1,     3,   117,   333,     3,   107,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    47,   354,   174,
     175,   176,    47,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   390,   297,     3,   116,   114,     3,
     302,   116,   336,   115,    77,   116,    77,    28,   351,    47,
      20,    19,    18,     3,   323,    17,    47,   118,   320,    71,
       3,   113,   331,   332,    45,    46,   116,   118,   116,   116,
      28,   117,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   321,
     322,   114,    77,   355,   356,   111,   415,   115,    77,   402,
      65,   333,   116,   116,   113,    77,    55,   118,   114,   113,
     113,     2,    35,   113,   116,   114,     1,   118,   114,   116,
     351,   115,   354,   113,   116,   211,   115,   115,   115,   354,
     301,   408,   401,   411,   239,   428,   117,   406,    14,   439,
      14,   403,   187,   313,   188,   407,   314,   189,   417,   192,
      35,    36,   315,   190,   416,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    72,   435,   316,    53,   438,
     439,   402,   318,   442,    59,    60,    -1,   446,    63,   201,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,     1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,
     105,    -1,   107,   108,    -1,   110,    -1,   112,    -1,   114,
      35,    36,    -1,   118,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,
     105,    -1,   107,   108,    -1,   110,    -1,   112,    -1,   114,
      -1,    -1,    -1,   118,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,   114,    35,    36,    -1,    -1,   119,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,   114,    35,    36,    -1,    -1,   119,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    73,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    91,    92,    -1,    -1,    95,    -1,    97,    -1,    99,
     100,    -1,    -1,   103,   104,   105,    -1,   107,   108,    -1,
     110,    -1,   112,    -1,   114,   115,    35,    36,   118,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,    -1,
      99,   100,    -1,    -1,   103,   104,   105,    -1,   107,   108,
      -1,   110,    -1,   112,    -1,   114,   115,    35,    36,   118,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,   107,
     108,    -1,   110,    -1,   112,    -1,   114,   115,    35,    36,
     118,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,
      97,    -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,
     107,   108,    -1,   110,    -1,   112,    -1,   114,    35,    36,
      -1,   118,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,
      97,    -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,
     107,   108,    -1,   110,    -1,   112,    -1,   114,    35,    36,
      -1,   118,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    35,    36,   112,    -1,   114,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
     112,   113,   114,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    69,
      77,    -1,    -1,    -1,    74,    -1,    -1,    77,    85,    86,
      -1,    -1,    -1,    -1,    91,    85,    86,    -1,    95,    -1,
      -1,    91,    99,    -1,    -1,    95,   103,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,   112,    -1,   114,    -1,    -1,
      -1,    -1,   112,    -1,   114
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ParserImplementation::yystos_[] =
  {
         0,   121,   122,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    53,    59,    60,    63,
      69,    73,    74,    77,    78,    85,    86,    91,    92,    95,
      97,    99,   100,   103,   104,   105,   107,   108,   110,   112,
     114,   118,   123,   125,   127,   128,   131,   132,   135,   136,
     138,   151,   152,   153,   154,   156,   158,   160,   162,   163,
     168,   169,   171,   178,   179,   180,   181,   182,   185,   189,
     190,   191,   194,   195,   196,   197,   198,   199,   200,   202,
     204,   206,   208,   210,   212,   214,   216,   219,   224,   225,
      74,    77,   114,   194,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   219,   189,   190,     3,   183,   184,   223,
      77,   134,    77,   114,   141,   143,   145,   146,   182,   134,
     135,    47,    77,   134,   116,    47,   219,   222,    47,   219,
     114,   136,   141,    47,    47,    47,   111,    77,    86,    95,
     115,   135,   137,   186,   187,   188,   132,    47,    49,    50,
     192,    49,    50,   192,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    45,    46,   117,   218,    37,
      38,    39,    35,    36,    32,    33,    34,    25,    26,    27,
      28,    29,    76,    21,    22,    23,    24,    20,    19,    18,
      17,    15,    16,     3,   224,     1,    77,    86,    95,   113,
     192,     3,   119,     3,   119,   216,   159,   117,   149,   175,
     147,     3,   140,   149,   157,   107,   105,   194,   199,   201,
     203,   205,   207,   209,   211,   213,   215,   217,   220,   221,
      47,    47,   135,   219,   161,   219,   170,    56,    71,   172,
     173,   139,   219,   219,    77,   129,   133,   145,   114,   115,
     135,   115,     3,   116,   113,   193,   216,   219,    77,   219,
      77,   216,   196,   196,   196,   197,   197,   198,   198,   198,
     199,   199,   199,   199,   199,   199,   200,   200,   200,   200,
     202,   204,   206,   208,   216,   210,   216,   226,   223,   224,
     216,    77,   148,   188,   143,   224,   224,    47,    77,   142,
     144,   145,    28,   218,    25,    26,    27,    29,    76,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     118,   124,   126,   113,   224,   113,   224,    47,   136,   173,
     224,   113,   113,     3,   113,   130,   131,   188,   216,     3,
     113,   119,   119,   116,   118,   119,   216,     3,   115,   116,
     219,   117,   150,   176,     3,   118,    28,   150,   219,   194,
     217,   199,   199,   199,   199,   199,   201,   201,   201,   201,
     203,   205,   207,   209,   217,   211,   217,   222,   133,   133,
     135,   114,   164,    77,   135,   135,    77,   145,   111,   115,
     116,   216,   216,    77,   188,    77,   113,   217,   144,   222,
     219,   113,   116,   118,   113,   113,    65,    55,   165,   166,
     177,   113,   114,   216,   116,   155,   118,   113,   135,   217,
     222,   114,   114,   135,   219,   166,    62,   115,   167,   136,
     130,    77,   224,   222,   135,   113,   130,   130,   116,   116,
     177,   115,   113,   135,   115,   115,   137,   174,   174,   115,
     135
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  ParserImplementation::yytoken_number_[] =
  {
         0,   256,   257,    44,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,    63,   269,   270,   124,    94,
      38,   271,   272,   273,   274,    62,    60,   275,   276,   277,
     278,   279,   280,   281,   282,    43,    45,    42,    47,    37,
      33,   126,   283,   284,   285,   286,   287,    40,   288,    91,
      46,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,    41,   123,   125,    58,    61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ParserImplementation::yyr1_[] =
  {
         0,   120,   122,   121,   124,   123,   126,   125,   125,   125,
     127,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   139,   138,   140,   138,   141,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   147,   146,
     148,   148,   148,   148,   149,   150,   151,   152,   153,   153,
     155,   154,   154,   154,   154,   154,   154,   157,   156,   159,
     158,   161,   160,   162,   163,   164,   164,   165,   165,   166,
     167,   168,   170,   169,   171,   171,   171,   172,   173,   174,
     174,   175,   175,   176,   176,   177,   177,   178,   178,   178,
     178,   178,   179,   180,   180,   181,   181,   181,   181,   181,
     181,   182,   182,   182,   183,   183,   184,   184,   185,   186,
     186,   187,   187,   188,   188,   188,   189,   189,   189,   189,
     189,   190,   190,   191,   191,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   195,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   197,   197,   197,   197,
     198,   198,   198,   199,   199,   199,   199,   200,   200,   200,
     200,   200,   200,   200,   201,   201,   201,   201,   201,   201,
     202,   202,   202,   202,   202,   203,   203,   203,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   215,   215,   216,   216,   217,   217,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   226,   224
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     0,     9,     0,     9,     1,     1,
       8,     5,     1,     1,     3,     3,     0,     1,     1,     2,
       1,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     2,     0,     4,     0,     4,     1,     3,
       1,     3,     2,     2,     2,     2,     1,     1,     0,     4,
       1,     3,     5,     3,     2,     2,     1,     2,     7,     5,
       0,     8,     5,     9,    10,     7,     8,     0,     4,     0,
       4,     0,     4,     5,     5,     3,     5,     1,     2,     4,
       3,     3,     0,     4,     3,     3,     4,     5,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     5,     2,     4,     1,     2,     3,     0,
       1,     3,     5,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     2,     2,     2,     4,     3,     2,     3,     1,
       3,     1,     1,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     5,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     0,     1,     0,     1,     0,     1,
       1,     1,     0,     0,     4
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const ParserImplementation::yytname_[] =
  {
    "$end", "error", "$undefined", "','", "JS_U_SHIFT_RIGHT_LET",
  "JS_SUB_LET", "JS_SHIFT_RIGHT_LET", "JS_SHIFT_LEFT_LET", "JS_OR_LET",
  "JS_NOT_LET", "JS_MUL_LET", "JS_MOD_LET", "JS_DIV_LET", "JS_AND_LET",
  "JS_ADD_LET", "'?'", "JS_LOGICAL_OR", "JS_LOGICAL_AND", "'|'", "'^'",
  "'&'", "JS_NOT_EQ", "JS_NOT_EQUAL", "JS_EQUAL", "JS_EQ", "'>'", "'<'",
  "JS_INSTANCEOF", "JS_IN", "JS_LESS_EQUAL", "JS_GREATER_EQUAL",
  "JS_U_SHIFT_LEFT", "JS_U_SHIFT_RIGHT", "JS_SHIFT_RIGHT", "JS_SHIFT_LEFT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "JS_DELETE", "JS_VOID",
  "JS_TYPEOF", "JS_DECREMENT", "JS_INCREMENT", "'('", "JS_NEW", "'['",
  "'.'", "JS_ABSTRACT", "JS_BOOLEAN", "JS_BREAK", "JS_BYTE", "JS_CASE",
  "JS_CATCH", "JS_CHAR", "JS_CLASS", "JS_CONST", "JS_CONTINUE",
  "JS_DEBUGGER", "JS_DEFAULT", "JS_DO", "JS_DOUBLE", "JS_ELSE", "JS_ENUM",
  "JS_EXPORT", "JS_EXTENDS", "JS_FALSE", "JS_FINAL", "JS_FINALLY",
  "JS_FLOAT", "JS_FOR", "JS_FUNCTION", "JS_GOTO", "JS_GRATER_EQUAL",
  "JS_IDENTIFIER", "JS_IF", "JS_IMPLEMENTS", "JS_IMPORT", "JS_INT",
  "JS_INTERFACE", "JS_LONG", "JS_NATIVE", "JS_K_NULL",
  "JS_NUMERIC_LITERAL", "JS_PRIVATE", "JS_PACKAGE_RESERVED",
  "JS_PROTECTED", "JS_PUBLIC", "JS_REGEXP_LITERAL", "JS_RETURN",
  "JS_SHORT", "JS_STATIC", "JS_STRING_LITERAL", "JS_SUPER", "JS_SWITCH",
  "JS_SYNCHRONIZED", "JS_THIS", "JS_THROW", "JS_THROWS", "JS_TRANSIENT",
  "JS_TRUE", "JS_TRY", "JS_VAR", "JS_VOLATILE", "JS_WHILE", "JS_WITH",
  "JS_TERMINATE", "JS_LINE_BREAK", "JS_ARROW", "JS_SHORTER_FUNCTION",
  "')'", "'{'", "'}'", "':'", "'='", "';'", "']'", "$accept", "program",
  "$@1", "function_declaration", "@2", "function_expression", "@3",
  "arrow_function_expression", "arrow_function_expression_no_args",
  "formal_parameter_list", "function_body", "source_elements",
  "source_element", "formal_parameter_list__opt", "identifier__opt",
  "statement", "block", "statement_list", "variable_statement", "$@4",
  "$@5", "variable_declaration_list", "variable_declaration_list_no_in",
  "variable_declaration", "variable_declaration_no_in",
  "destructuring_assignment_left_hand_side", "object_left_hand_side",
  "$@6", "object_member_left_hand_side_list", "initialiser",
  "initialiser_no_in", "empty_statement", "expression_statement",
  "if_statement", "iteration_statement", "$@7", "continue_statement",
  "$@8", "break_statement", "$@9", "return_statement", "$@10",
  "with_statement", "switch_statement", "case_block", "case_clauses",
  "case_clause", "default_clause", "labelled_statement", "throw_statement",
  "$@11", "try_statement", "catch", "finally", "statement_list__opt",
  "initialiser__opt", "initialiser_no_in__opt", "case_clauses__opt",
  "literal", "null_literal", "boolean_literal", "primary_expression",
  "array_literal", "element_list", "elision", "object_literal",
  "property_name_and_value_list__opt", "property_name_and_value_list",
  "property_name", "member_expression", "new_expression",
  "call_expression", "arguments", "argument_list",
  "left_hand_side_expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "relational_expression_no_in",
  "equality_expression", "equality_expression_no_in",
  "bitwise_and_expression", "bitwise_and_expression_no_in",
  "bitwise_xor_expression", "bitwise_xor_expression_no_in",
  "bitwise_or_expression", "bitwise_or_expression_no_in",
  "logical_and_expression", "logical_and_expression_no_in",
  "logical_or_expression", "logical_or_expression_no_in",
  "conditional_expression", "conditional_expression_no_in",
  "assignment_expression", "assignment_expression_no_in",
  "assignment_operator", "expression", "expression_no_in",
  "expression_no_in__opt", "expression__opt", "elision__opt", "terminator",
  "$@12", "$@13", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       121,     0,    -1,    -1,   122,   131,    -1,    -1,    74,    77,
      47,   124,   133,   113,   114,   130,   115,    -1,    -1,    74,
     134,    47,   126,   133,   113,   114,   130,   115,    -1,   127,
      -1,   128,    -1,   112,    47,   133,   113,   111,   114,   130,
     115,    -1,   112,   111,   114,   130,   115,    -1,    77,    -1,
     145,    -1,   129,     3,   145,    -1,   129,     3,    77,    -1,
      -1,   131,    -1,   132,    -1,   131,   132,    -1,   135,    -1,
     123,    -1,    -1,   129,    -1,    -1,    77,    -1,   136,    -1,
     138,    -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,
     156,    -1,   158,    -1,   160,    -1,   162,    -1,   168,    -1,
     163,    -1,   169,    -1,   171,    -1,   114,   115,    -1,   114,
     137,   115,    -1,   135,    -1,   137,   135,    -1,    -1,   105,
     141,   139,   224,    -1,    -1,    59,   141,   140,   224,    -1,
     143,    -1,   141,     3,   143,    -1,   144,    -1,   142,     3,
     144,    -1,    77,   175,    -1,   145,   149,    -1,    77,   176,
      -1,   145,   150,    -1,   182,    -1,   146,    -1,    -1,   114,
     147,   148,   115,    -1,    77,    -1,   188,   116,    77,    -1,
     148,     3,   188,   116,    77,    -1,   148,     3,    77,    -1,
     117,   216,    -1,   117,   217,    -1,   224,    -1,   219,   224,
      -1,    78,    47,   219,   113,   135,    65,   135,    -1,    78,
      47,   219,   113,   135,    -1,    -1,    63,   135,   107,    47,
     219,   113,   155,   224,    -1,   107,    47,   219,   113,   135,
      -1,    73,    47,   221,   118,   222,   118,   222,   113,   135,
      -1,    73,    47,   105,   142,   118,   222,   118,   222,   113,
     135,    -1,    73,    47,   194,    28,   219,   113,   135,    -1,
      73,    47,   105,   144,    28,   219,   113,   135,    -1,    -1,
      60,   134,   157,   224,    -1,    -1,    53,   134,   159,   224,
      -1,    -1,    92,   222,   161,   224,    -1,   108,    47,   219,
     113,   135,    -1,    97,    47,   219,   113,   164,    -1,   114,
     177,   115,    -1,   114,   177,   167,   177,   115,    -1,   166,
      -1,   165,   166,    -1,    55,   219,   116,   174,    -1,    62,
     116,   174,    -1,    77,   116,   135,    -1,    -1,   100,   219,
     170,   224,    -1,   104,   136,   172,    -1,   104,   136,   173,
      -1,   104,   136,   172,   173,    -1,    56,    47,    77,   113,
     136,    -1,    71,   136,    -1,    -1,   137,    -1,    -1,   149,
      -1,    -1,   150,    -1,    -1,   165,    -1,   179,    -1,   180,
      -1,    86,    -1,    95,    -1,    91,    -1,    85,    -1,   103,
      -1,    69,    -1,    99,    -1,    77,    -1,   178,    -1,   182,
      -1,   185,    -1,    47,   219,   113,    -1,    49,   223,   119,
      -1,    49,   183,   119,    -1,    49,   183,     3,   223,   119,
      -1,   223,   216,    -1,   183,     3,   223,   216,    -1,     3,
      -1,   184,     3,    -1,   114,   186,   115,    -1,    -1,   187,
      -1,   188,   116,   216,    -1,   187,     3,   188,   116,   216,
      -1,    77,    -1,    95,    -1,    86,    -1,   181,    -1,   125,
      -1,   189,    49,   219,   119,    -1,   189,    50,    77,    -1,
      48,   189,   192,    -1,   189,    -1,    48,   190,    -1,   189,
     192,    -1,   191,   192,    -1,   191,    49,   219,   119,    -1,
     191,    50,    77,    -1,    47,   113,    -1,    47,   193,   113,
      -1,   216,    -1,   193,     3,   216,    -1,   190,    -1,   191,
      -1,   194,    -1,   194,    46,    -1,   194,    45,    -1,   195,
      -1,    42,   196,    -1,    43,   196,    -1,    44,   196,    -1,
      46,   196,    -1,    45,   196,    -1,    35,   196,    -1,    36,
     196,    -1,    41,   196,    -1,    40,   196,    -1,   196,    -1,
     197,    37,   196,    -1,   197,    38,   196,    -1,   197,    39,
     196,    -1,   197,    -1,   198,    35,   197,    -1,   198,    36,
     197,    -1,   198,    -1,   199,    34,   198,    -1,   199,    33,
     198,    -1,   199,    32,   198,    -1,   199,    -1,   200,    26,
     199,    -1,   200,    25,   199,    -1,   200,    29,   199,    -1,
     200,    76,   199,    -1,   200,    27,   199,    -1,   200,    28,
     199,    -1,   199,    -1,   201,    26,   199,    -1,   201,    25,
     199,    -1,   201,    29,   199,    -1,   201,    76,   199,    -1,
     201,    27,   199,    -1,   200,    -1,   202,    23,   200,    -1,
     202,    22,   200,    -1,   202,    24,   200,    -1,   202,    21,
     200,    -1,   201,    -1,   203,    23,   201,    -1,   203,    22,
     201,    -1,   203,    24,   201,    -1,   203,    21,   201,    -1,
     202,    -1,   204,    20,   202,    -1,   203,    -1,   205,    20,
     203,    -1,   204,    -1,   206,    19,   204,    -1,   205,    -1,
     207,    19,   205,    -1,   206,    -1,   208,    18,   206,    -1,
     207,    -1,   209,    18,   207,    -1,   208,    -1,   210,    17,
     208,    -1,   209,    -1,   211,    17,   209,    -1,   210,    -1,
     212,    16,   210,    -1,   211,    -1,   213,    16,   211,    -1,
     212,    -1,   212,    15,   216,   116,   216,    -1,   213,    -1,
     213,    15,   217,   116,   217,    -1,   214,    -1,   194,   218,
     216,    -1,   215,    -1,   194,   218,   217,    -1,   117,    -1,
      10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,    -1,
       7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,    -1,
       8,    -1,   216,    -1,   219,     3,   216,    -1,   217,    -1,
     220,     3,   217,    -1,    -1,   220,    -1,    -1,   219,    -1,
      -1,   184,    -1,   118,    -1,   110,    -1,    -1,    -1,   225,
       1,   226,   118,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    18,    19,    29,    31,
      33,    42,    48,    50,    52,    56,    60,    61,    63,    65,
      68,    70,    72,    73,    75,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   109,   113,   115,   118,   119,   124,   125,   130,   132,
     136,   138,   142,   145,   148,   151,   154,   156,   158,   159,
     164,   166,   170,   176,   180,   183,   186,   188,   191,   199,
     205,   206,   215,   221,   231,   242,   250,   259,   260,   265,
     266,   271,   272,   277,   283,   289,   293,   299,   301,   304,
     309,   313,   317,   318,   323,   327,   331,   336,   342,   345,
     346,   348,   349,   351,   352,   354,   355,   357,   359,   361,
     363,   365,   367,   369,   371,   373,   375,   377,   379,   381,
     383,   387,   391,   395,   401,   404,   409,   411,   414,   418,
     419,   421,   425,   431,   433,   435,   437,   439,   441,   446,
     450,   454,   456,   459,   462,   465,   470,   474,   477,   481,
     483,   487,   489,   491,   493,   496,   499,   501,   504,   507,
     510,   513,   516,   519,   522,   525,   528,   530,   534,   538,
     542,   544,   548,   552,   554,   558,   562,   566,   568,   572,
     576,   580,   584,   588,   592,   594,   598,   602,   606,   610,
     614,   616,   620,   624,   628,   632,   634,   638,   642,   646,
     650,   652,   656,   658,   662,   664,   668,   670,   674,   676,
     680,   682,   686,   688,   692,   694,   698,   700,   704,   706,
     710,   712,   718,   720,   726,   728,   732,   734,   738,   740,
     742,   744,   746,   748,   750,   752,   754,   756,   758,   760,
     762,   764,   768,   770,   774,   775,   777,   778,   780,   781,
     783,   785,   787,   788,   789
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   312,   312,   312,   323,   322,   344,   343,   359,   360,
     364,   375,   385,   393,   399,   404,   414,   415,   419,   425,
     433,   434,   442,   443,   450,   451,   458,   463,   468,   473,
     478,   483,   488,   493,   498,   503,   508,   513,   518,   523,
     531,   537,   546,   552,   562,   561,   572,   571,   584,   590,
     598,   604,   612,   620,   629,   637,   647,   648,   653,   653,
     658,   668,   680,   690,   702,   706,   710,   714,   723,   732,
     743,   743,   752,   761,   772,   784,   794,   808,   808,   820,
     820,   832,   832,   843,   854,   865,   869,   878,   884,   892,
     903,   913,   925,   925,   935,   943,   951,   963,   973,   983,
     984,   988,   989,   993,   994,   998,   999,  1003,  1004,  1005,
    1009,  1013,  1020,  1027,  1031,  1038,  1042,  1047,  1048,  1049,
    1050,  1058,  1064,  1070,  1079,  1085,  1093,  1094,  1098,  1106,
    1109,  1116,  1122,  1130,  1138,  1145,  1155,  1159,  1163,  1168,
    1176,  1185,  1186,  1194,  1238,  1244,  1249,  1258,  1259,  1263,
    1269,  1277,  1278,  1282,  1286,  1291,  1299,  1300,  1305,  1310,
    1315,  1320,  1325,  1330,  1335,  1340,  1348,  1349,  1353,  1357,
    1364,  1365,  1369,  1376,  1377,  1381,  1385,  1392,  1393,  1397,
    1401,  1405,  1409,  1413,  1420,  1421,  1425,  1429,  1433,  1437,
    1444,  1445,  1449,  1453,  1457,  1464,  1465,  1469,  1473,  1477,
    1484,  1485,  1492,  1493,  1500,  1501,  1508,  1509,  1516,  1517,
    1524,  1525,  1532,  1533,  1540,  1541,  1548,  1549,  1556,  1557,
    1564,  1565,  1574,  1575,  1584,  1588,  1597,  1601,  1610,  1611,
    1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,
    1625,  1631,  1639,  1645,  1653,  1654,  1658,  1659,  1663,  1664,
    1668,  1669,  1670,  1675,  1670
  };

  // Print the state stack on the debug stream.
  void
  ParserImplementation::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  ParserImplementation::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  ParserImplementation::token_number_type
  ParserImplementation::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    39,    20,     2,
      47,   113,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   116,   118,
      26,   117,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   119,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,    18,   115,    41,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    16,
      17,    21,    22,    23,    24,    27,    28,    29,    30,    31,
      32,    33,    34,    42,    43,    44,    45,    46,    48,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 1374;
  const int ParserImplementation::yynnts_ = 107;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 120;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 350;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4037 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 1678 "src/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}


