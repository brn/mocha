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
#line 1 "grammar.yy"

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
#line 314 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 315 "grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 325 "grammar.yy"
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
#line 333 "grammar.yy"
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
#line 346 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    scope->Insert ( (yysemantic_stack_[(3) - (2)].ident) );
    scope = scope->Enter ();
    (yyval.ident) = (yysemantic_stack_[(3) - (2)].ident);
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 353 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(9) - (4)].ident) ) );
    fn->Argv ( (yysemantic_stack_[(9) - (5)].ast) );
    fn->Body ( (yysemantic_stack_[(9) - (8)].ast) );
    fn->FnScope ( scope );
    scope = scope->Escape ();
    (yyval.fn) = fn;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 366 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(3) - (2)].ast) );
    fn->Body ( (yysemantic_stack_[(3) - (3)].ast) );
    fn->FnScope ( scope );
    (yyval.fn) = fn;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 376 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (3)].ast); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 381 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 389 "grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 395 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].farg)->Args ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 400 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    //scope->Insert ( ident );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 410 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 418 "grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 424 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].farg)->Args ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.farg) = (yysemantic_stack_[(2) - (1)].farg);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 429 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(2) - (2)].info)->getValue() ) );
    //scope->Insert ( ident );
    (yysemantic_stack_[(2) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(2) - (1)].farg);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 438 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 439 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 444 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 450 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 457 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 459 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 466 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 468 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 474 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 476 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 482 "grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 484 "grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 491 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 496 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 501 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 506 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 511 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 516 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 521 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 526 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 531 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 536 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 541 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 546 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 551 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 556 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 564 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 570 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 579 "grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 585 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 594 "grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 598 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 604 "grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 608 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 617 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 623 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 631 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 637 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 645 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 653 "grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 662 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 670 "grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 679 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 680 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 685 "grammar.yy"
    { tracer->SetState( ParserTracer::kObjectLiteralEnd ); }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 685 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (3)].dsto); }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 691 "grammar.yy"
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

  case 66:

/* Line 690 of lalr1.cc  */
#line 701 "grammar.yy"
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

  case 67:

/* Line 690 of lalr1.cc  */
#line 713 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(5) - (5)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( ident );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 723 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( 0 );
    mem->Right( ident );
    (yysemantic_stack_[(3) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(3) - (1)].dsto);
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 734 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 738 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 742 "grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 747 "grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 756 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 765 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 775 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 776 "grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(8) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(8) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 785 "grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 794 "grammar.yy"
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

  case 79:

/* Line 690 of lalr1.cc  */
#line 805 "grammar.yy"
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

  case 80:

/* Line 690 of lalr1.cc  */
#line 817 "grammar.yy"
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

  case 81:

/* Line 690 of lalr1.cc  */
#line 827 "grammar.yy"
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

  case 82:

/* Line 690 of lalr1.cc  */
#line 840 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 841 "grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 852 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 853 "grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 864 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 865 "grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yysemantic_stack_[(4) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 876 "grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 887 "grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 898 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 902 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 911 "grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 917 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 925 "grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 936 "grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 946 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    scope->InsertLabel ( ident );
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 957 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 958 "grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 968 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 976 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 984 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 996 "grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1006 "grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1016 "grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1020 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1021 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1025 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1030 "grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1031 "grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1035 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1036 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1038 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1042 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1046 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1060 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1064 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1079 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1080 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1081 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1083 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1091 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1097 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1103 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1112 "grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1118 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1131 "grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1138 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1142 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1149 "grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1155 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1163 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1171 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1178 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1188 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1192 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1196 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1201 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1209 "grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1217 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1219 "grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1227 "grammar.yy"
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

  case 149:

/* Line 690 of lalr1.cc  */
#line 1271 "grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1277 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1282 "grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1290 "grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1291 "grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1296 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1302 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1309 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1310 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1315 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1319 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1324 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1331 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1343 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1348 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1358 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1363 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1368 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1373 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1380 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1382 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1386 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1390 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1396 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1398 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1402 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1408 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1410 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1414 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1418 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1424 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1426 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1430 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1434 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1438 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1442 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1446 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1452 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1454 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1458 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1462 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1466 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1470 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1476 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1478 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1482 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1486 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1490 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1496 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1498 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1502 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1506 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1510 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1516 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1518 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1524 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1532 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1534 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1540 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1542 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1548 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1550 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1556 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1558 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1564 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1566 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1572 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1574 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1580 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1582 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1588 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1590 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1596 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1598 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1608 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1630 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1634 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1643 "grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1644 "grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1645 "grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1646 "grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1647 "grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1648 "grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1649 "grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1650 "grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1651 "grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1652 "grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1653 "grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1658 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1664 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1672 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1678 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1685 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1686 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1690 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1691 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1695 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1696 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1700 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1701 "grammar.yy"
    {(yyval.num) = ';';tracer->SetLineBreakFlag ( false );}
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1702 "grammar.yy"
    {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1707 "grammar.yy"
    {yyclearin;yyerrok;}
    break;



/* Line 690 of lalr1.cc  */
#line 2936 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -369;
  const short int
  ParserImplementation::yypact_[] =
  {
      -369,    13,  1025,  -369,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,  1335,   356,    14,   -54,   -14,   -54,  1105,
    -369,    23,   -44,   -55,    26,  -369,  -369,  -369,  1335,  -369,
      66,  -369,  1335,  -369,   -13,   -14,    75,    81,  -369,    -8,
     782,  -369,  -369,  -369,  -369,   462,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,    10,  -369,
     172,   271,  -369,  -369,   150,    72,   195,    59,    73,   110,
      71,   114,   117,   169,  -369,  -369,    37,  -369,   145,   -54,
    -369,    16,   185,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,    31,    10,  -369,  -369,     0,   136,   622,  -369,
    -369,    41,  -369,   187,  -369,    41,  -369,  -369,  -369,   111,
    1185,   131,   176,  1105,  1335,   222,  -369,  1335,   222,   863,
      -3,   187,  1335,  1335,   123,    15,  -369,   152,   155,   -55,
     148,   151,  -369,  -369,   944,   154,   265,   157,  -369,  1260,
    1335,   193,  -369,  1335,   194,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,  1335,  1335,  1335,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,    14,  -369,  -369,  -369,  -369,   -96,  1335,
    -369,  -369,   138,   -14,   -96,  -369,   -96,   227,    -5,   244,
     195,   144,   153,   266,   272,   275,   277,   223,  -369,  -369,
     293,   179,  -369,  -369,  -369,    35,   -96,    36,   -96,   251,
     -13,   228,  -369,   -96,    39,    40,    22,  -369,  -369,   186,
    -369,  -369,  -369,  -369,    16,  1335,  -369,    43,  -369,     5,
    -369,     7,  -369,  -369,  -369,  -369,  -369,   150,   150,    72,
      72,    72,   195,   195,   195,   195,   195,   195,    59,    59,
      59,    59,    73,   110,    71,   114,   188,   117,  -369,   183,
     702,  -369,  -369,   189,     8,   191,  -369,  -369,  -369,  1335,
     192,     9,   274,   192,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,    54,    54,  1105,  -369,   197,  -369,   226,
    -369,  -369,  -369,  1105,  1105,  -369,  -369,   462,   196,  -369,
    1335,  -369,  -369,  -369,  1335,  -369,  -369,  -369,   140,  -369,
     231,    44,  1335,  -369,  -369,    -5,  1335,  1335,  -369,    46,
     271,  -369,   195,   195,   195,   195,   195,   144,   144,   144,
     144,   153,   266,   272,   275,   202,   277,  -369,   201,  -369,
     310,   207,  -369,   210,   259,   292,  -369,   236,  -369,  -369,
     235,   462,  1335,  -369,  -369,   189,   246,  -369,  -369,  -369,
    -369,   233,    47,  1105,  1335,  1335,   238,   249,  1105,  1335,
     292,  -369,   -53,   -13,  -369,  -369,   283,   -96,  1335,  1105,
    -369,  -369,   252,   462,   462,  -369,     2,  -369,   248,  -369,
     292,  -369,  -369,  -369,   253,  -369,  1105,   254,   255,   542,
     542,   256,  1105,  -369,  -369,  -369,   542,  -369,  -369,  -369,
    -369
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,   257,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,    29,     0,    29,   257,
     119,     0,    29,   121,     0,   117,   114,   116,   251,   115,
       0,   120,     0,   118,     0,     0,     0,     0,   256,    27,
     257,   255,    24,   142,     8,     3,    21,    23,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    42,    41,
      43,    44,   122,   112,   113,   141,   123,   124,   146,   156,
     157,   158,   161,   171,   175,   178,   182,   195,   205,   209,
     213,   217,   221,   225,   229,   245,   257,    71,     0,    29,
     121,   134,   158,   167,   168,   170,   169,   162,   163,   164,
     166,   165,     0,   146,   147,   131,     0,   254,     0,    30,
      84,   106,    63,    51,    53,     0,    62,    61,    82,     0,
     249,     0,     0,   257,     0,   252,    86,     0,    97,   257,
       0,    49,     0,     0,    11,     0,    28,     0,    12,   121,
     114,   115,    45,    47,   257,     0,   135,     0,    22,     0,
       0,     0,   148,     0,     0,   149,   241,   238,   240,   239,
     244,   243,   234,   236,   235,   242,   237,   160,   159,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,   258,   138,   140,
     139,   125,   145,   253,   127,   132,   126,   129,   257,     0,
     107,    57,     0,     0,   257,    58,   257,     0,     0,   158,
     189,   200,   207,   211,   215,   219,   223,   227,   231,   247,
     250,     0,     4,     6,    96,     0,   257,     0,   257,     0,
       0,    99,   100,   257,     0,     0,     0,    18,    17,     0,
       9,    46,    48,   133,     0,     0,   152,     0,   154,     0,
     144,     0,   151,   230,   172,   173,   174,   176,   177,   181,
     180,   179,   184,   183,   187,   188,   185,   186,   199,   197,
     196,   198,   206,   210,   214,   218,     0,   222,   246,     0,
       0,    85,    69,    65,     0,     0,    54,    52,    83,     0,
     108,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,    25,   257,    87,     0,    98,     0,
     103,   101,    50,   257,   257,    14,    13,    19,     0,   136,
       0,   153,   143,   150,     0,   259,   128,   130,     0,    64,
       0,     0,     0,   109,    59,     0,   251,     0,    60,     0,
     158,   232,   191,   190,   194,   192,   193,   204,   202,   201,
     203,   208,   212,   216,   220,     0,   224,   248,     0,    11,
      26,     0,    12,     0,    74,   110,    89,     0,    77,    88,
       0,    20,     0,   155,   226,    68,     0,    66,    75,    70,
      56,     0,     0,   257,     0,   251,     0,     0,   257,     0,
     111,    92,     0,     0,    10,   137,     0,   257,   251,   257,
      80,   228,     0,    19,    19,    73,     0,    93,     0,    90,
     110,   102,    67,    76,     0,    81,   257,     0,     0,   104,
     104,     0,   257,    78,     5,     7,   105,    94,    95,    91,
      79
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,   328,
    -369,  -368,   366,   -43,    49,  -369,    98,   -19,   -27,  -180,
    -369,  -369,  -369,   340,  -369,   163,    24,    -2,  -369,  -369,
    -369,   262,    77,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,   -32,  -369,
    -369,  -369,  -369,  -369,  -369,   141,   -59,  -369,  -369,   -47,
    -369,  -369,  -369,  -369,    19,  -369,  -369,  -369,  -369,  -369,
    -206,   371,   373,  -369,   -51,  -369,    20,  -369,    70,    87,
      69,   175,   -24,  -131,   203,    76,   200,    78,   204,    79,
     206,    83,   205,    82,  -369,  -369,  -369,  -369,  -104,  -254,
     336,   -12,  -369,  -369,  -239,   208,   -71,  -369,  -369
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    42,   323,    43,   324,    44,   250,   380,
     136,   390,   391,    46,   381,   137,   122,    47,    48,   144,
      49,   243,   214,   113,   301,   114,   302,   115,   116,   212,
     294,   210,   353,    50,    51,    52,    53,   417,    54,   216,
      55,   208,    56,   236,    57,    58,   386,   410,   411,   430,
      59,    60,   238,    61,   241,   242,   447,   211,   354,   412,
      62,    63,    64,    65,    66,   106,   107,    67,   145,   146,
     147,    68,    69,    70,   152,   257,    71,    72,    73,    74,
      75,    76,    77,   221,    78,   222,    79,   223,    80,   224,
      81,   225,    82,   226,    83,   227,    84,   228,    85,   229,
     305,    86,   230,   231,   126,   108,    87,    88,   289
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -258;
  const short int
  ParserImplementation::yytable_[] =
  {
       119,   102,   148,   203,   207,   195,   295,   130,   195,   428,
     195,   348,   355,     3,    38,   196,   125,   105,   246,   155,
     128,   143,    41,   109,    92,    92,    92,    92,    92,    92,
      92,    92,    92,   121,   195,    15,   117,   138,   195,   195,
     195,    15,   195,   195,    15,   258,   340,   195,   338,   195,
     195,   361,   202,   239,   117,   437,   438,   149,   117,   150,
     151,   123,   429,   111,    15,   375,   263,   377,   240,   134,
     120,    15,   300,   124,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   378,   179,   180,   181,   182,   183,   286,
     190,   288,   247,   198,   185,   186,   187,   188,   399,   335,
     112,   129,   199,    15,   234,   292,   112,   174,   175,   112,
     143,   200,   235,   127,   110,   237,   118,   401,   439,   204,
     244,   245,   132,   349,   342,   252,   343,   356,   133,   112,
     189,   379,   191,   248,   192,   184,   112,   291,   259,   205,
     219,   261,   396,   297,   201,   298,   197,    38,   325,   327,
     421,   339,   333,   334,   117,    41,   341,   398,   209,   403,
     419,   278,   279,   280,   281,   326,   422,   328,   112,   306,
     307,   308,   332,   309,   311,   312,   313,   314,   232,   434,
     367,   368,   369,   370,   193,   194,   347,   171,   172,   173,
     213,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,   330,    92,   293,   303,   395,   217,   149,
     310,   153,   154,   233,   199,   195,   199,   176,   177,   178,
     167,   168,   117,   200,   -15,   200,   393,   117,   319,   320,
     394,   264,   265,   266,   336,   269,   270,   271,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   446,
     446,   267,   268,   249,  -140,   117,   -16,  -139,   254,   253,
     260,   262,   304,   255,   299,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   315,   351,   415,   167,
     168,   316,   359,   317,   318,   220,   321,   322,   329,   240,
     337,   345,   357,   387,   344,  -138,   384,   350,   397,   352,
     125,   385,   392,   246,   388,   389,   167,   168,   404,   405,
     406,   382,   382,   407,   408,   360,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,   360,
      92,   360,   117,   117,   125,   402,   433,   409,   148,   413,
     414,   418,   423,   303,   272,   273,   274,   275,   276,   277,
     432,   169,   416,   424,   440,   436,   442,   135,    45,   444,
     445,   449,   360,   383,   117,   131,   296,   215,   427,   400,
     358,   448,   331,   441,   420,   103,   431,   104,   169,   425,
     283,   371,   282,   125,   372,   284,   373,   426,   285,   287,
     435,   374,   376,    13,    14,    15,   125,   170,     0,     0,
       0,   290,     0,     0,     0,     0,     0,   443,     0,     0,
     143,   143,     0,   450,   360,    20,     0,   252,     0,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,  -257,     0,     0,     0,     0,    39,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   362,   363,   364,   365,   366,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,   220,     0,     0,
       0,    20,     0,     0,     0,    21,    22,     0,     0,    23,
      24,     0,     0,  -257,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     0,    40,     4,     5,   220,
      41,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    89,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     0,    40,     4,     5,     0,
      41,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    89,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    91,     4,     5,     0,
       0,   206,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    89,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    91,     4,     5,     0,
       0,   346,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    89,     0,     0,   139,
      24,     0,     0,     0,     0,     0,     0,    25,   140,     0,
       0,     0,     0,    27,    28,     0,     0,   141,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     0,    40,   142,     4,     5,
      41,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    89,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,     0,    40,   142,     4,
       5,    41,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    89,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,     0,     0,    33,    34,    35,
       0,    36,    37,     0,    38,     0,    39,     0,    40,   251,
       4,     5,    41,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,    22,
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,     0,    40,
       4,     5,     0,    41,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,    89,
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,     0,    40,
       4,     5,     0,    41,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,     0,     0,     0,
      29,     0,     0,     0,    31,     0,     0,     0,    33,     0,
     218,     0,     0,     0,     0,     4,     5,    39,     0,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    89,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,     0,     0,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       4,     5,    39,   256,    91,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,     0,     0,     0,
      29,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,    91
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    13,    45,     3,   108,     3,   212,    34,     3,    62,
       3,     3,     3,     0,   110,    86,    28,     3,     3,    70,
      32,    40,   118,    77,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    77,     3,    49,    17,    39,     3,     3,
       3,    49,     3,     3,    49,   149,     3,     3,   254,     3,
       3,   305,   103,    56,    35,   423,   424,    47,    39,    49,
      50,   116,   115,    77,    49,   319,   170,   321,    71,    77,
      47,    49,    77,    47,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   322,    25,    26,    27,    28,    29,   193,
      19,   195,    77,    77,    21,    22,    23,    24,   352,    77,
     114,   114,    86,    49,   123,   209,   114,    35,    36,   114,
     129,    95,   124,    47,    16,   127,    18,   356,   116,   119,
     132,   133,    47,   115,   119,   144,   119,   118,    47,   114,
      20,    77,    18,   135,    17,    76,   114,   208,   150,     3,
     120,   153,   348,   214,   113,   216,     1,   110,   113,   113,
     404,   255,   113,   113,   135,   118,   113,   113,   117,   113,
     113,   185,   186,   187,   188,   236,   405,   238,   114,    25,
      26,    27,   243,    29,    21,    22,    23,    24,    47,   418,
     311,   312,   313,   314,    15,    16,   290,    37,    38,    39,
       3,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   240,   194,    77,   218,    77,   107,    47,
      76,    49,    50,    47,    86,     3,    86,    32,    33,    34,
      45,    46,   213,    95,   111,    95,   340,   218,    15,    16,
     344,   171,   172,   173,   246,   176,   177,   178,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   439,
     440,   174,   175,   111,   116,   246,   111,   116,     3,   115,
      77,    77,    28,   116,    47,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    20,   299,   392,    45,
      46,    19,   304,    18,    17,   120,     3,   118,    47,    71,
     114,   118,    28,    77,   116,   116,   325,   116,    77,   117,
     322,   114,   116,     3,   333,   334,    45,    46,   116,   118,
     113,   323,   324,   113,    65,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   323,   324,   356,   357,   417,    55,   391,   113,
     115,   118,   114,   355,   179,   180,   181,   182,   183,   184,
      77,   117,   116,   114,   116,   113,   113,    39,     2,   115,
     115,   115,   352,   324,   355,    35,   213,   115,   410,   355,
     303,   440,   241,   430,   403,    14,   413,    14,   117,   408,
     190,   315,   189,   405,   316,   191,   317,   409,   192,   194,
     419,   318,   320,    47,    48,    49,   418,    71,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
     439,   440,    -1,   442,   404,    69,    -1,   446,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,   112,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,   352,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,     1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,   107,
     108,    -1,   110,    -1,   112,    -1,   114,    35,    36,   404,
     118,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,   107,
     108,    -1,   110,    -1,   112,    -1,   114,    35,    36,    -1,
     118,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,    35,    36,    -1,
      -1,   119,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,    35,    36,    -1,
      -1,   119,    40,    41,    42,    43,    44,    45,    46,    47,
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
     107,   108,    -1,   110,    -1,   112,    -1,   114,   115,    35,
      36,   118,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,   105,
      -1,   107,   108,    -1,   110,    -1,   112,    -1,   114,   115,
      35,    36,   118,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
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
      35,    36,    -1,   118,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    35,    36,   112,    -1,   114,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,   112,   113,   114,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114
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
     114,   118,   123,   125,   127,   132,   133,   137,   138,   140,
     153,   154,   155,   156,   158,   160,   162,   164,   165,   170,
     171,   173,   180,   181,   182,   183,   184,   187,   191,   192,
     193,   196,   197,   198,   199,   200,   201,   202,   204,   206,
     208,   210,   212,   214,   216,   218,   221,   226,   227,    74,
      77,   114,   196,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   221,   191,   192,     3,   185,   186,   225,    77,
     136,    77,   114,   143,   145,   147,   148,   184,   136,   137,
      47,    77,   136,   116,    47,   221,   224,    47,   221,   114,
     138,   143,    47,    47,    77,   129,   130,   135,   147,    77,
      86,    95,   115,   137,   139,   188,   189,   190,   133,    47,
      49,    50,   194,    49,    50,   194,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   117,
     220,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    76,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   226,     1,    77,    86,
      95,   113,   194,     3,   119,     3,   119,   218,   161,   117,
     151,   177,   149,     3,   142,   151,   159,   107,   105,   196,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     222,   223,    47,    47,   137,   221,   163,   221,   172,    56,
      71,   174,   175,   141,   221,   221,     3,    77,   147,   111,
     128,   115,   137,   115,     3,   116,   113,   195,   218,   221,
      77,   221,    77,   218,   198,   198,   198,   199,   199,   200,
     200,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   204,   206,   208,   210,   218,   212,   218,   228,
     225,   226,   218,    77,   150,   190,   145,   226,   226,    47,
      77,   144,   146,   147,    28,   220,    25,    26,    27,    29,
      76,    21,    22,    23,    24,    20,    19,    18,    17,    15,
      16,     3,   118,   124,   126,   113,   226,   113,   226,    47,
     138,   175,   226,   113,   113,    77,   147,   114,   190,   218,
       3,   113,   119,   119,   116,   118,   119,   218,     3,   115,
     116,   221,   117,   152,   178,     3,   118,    28,   152,   221,
     196,   219,   201,   201,   201,   201,   201,   203,   203,   203,
     203,   205,   207,   209,   211,   219,   213,   219,   224,    77,
     129,   134,   147,   134,   137,   114,   166,    77,   137,   137,
     131,   132,   116,   218,   218,    77,   190,    77,   113,   219,
     146,   224,   221,   113,   116,   118,   113,   113,    65,    55,
     167,   168,   179,   113,   115,   218,   116,   157,   118,   113,
     137,   219,   224,   114,   114,   137,   221,   168,    62,   115,
     169,   138,    77,   226,   224,   137,   113,   131,   131,   116,
     116,   179,   113,   137,   115,   115,   139,   176,   176,   115,
     137
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
         0,   120,   122,   121,   124,   123,   126,   125,   125,   127,
     128,   129,   129,   129,   129,   130,   130,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   139,   139,   141,
     140,   142,   140,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   149,   148,   150,   150,   150,   150,   151,
     152,   153,   154,   155,   155,   157,   156,   156,   156,   156,
     156,   156,   159,   158,   161,   160,   163,   162,   164,   165,
     166,   166,   167,   167,   168,   169,   170,   172,   171,   173,
     173,   173,   174,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   180,   180,   181,   182,   182,
     183,   183,   183,   183,   183,   183,   184,   184,   184,   185,
     185,   186,   186,   187,   188,   188,   189,   189,   190,   190,
     190,   191,   191,   191,   191,   191,   192,   192,   193,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     197,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   199,   199,   199,   199,   200,   200,   200,   201,   201,
     201,   201,   202,   202,   202,   202,   202,   202,   202,   203,
     203,   203,   203,   203,   203,   204,   204,   204,   204,   204,
     205,   205,   205,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   226,   226,   227,   228,   226
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     0,     9,     0,     9,     1,     3,
       4,     1,     1,     3,     3,     1,     1,     2,     2,     0,
       1,     1,     2,     1,     1,     0,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     0,
       4,     0,     4,     1,     3,     1,     3,     2,     2,     2,
       2,     1,     1,     0,     4,     1,     3,     5,     3,     2,
       2,     1,     2,     7,     5,     0,     8,     5,     9,    10,
       7,     8,     0,     4,     0,     4,     0,     4,     5,     5,
       3,     5,     1,     2,     4,     3,     3,     0,     4,     3,
       3,     4,     5,     2,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     5,     2,
       4,     1,     2,     3,     0,     1,     3,     5,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     2,     2,     2,
       4,     3,     2,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     5,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     0,
       1,     0,     1,     0,     1,     1,     1,     0,     0,     4
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
  "arrow_function_expression", "function_body_expression",
  "formal_parameter_list", "formal_parameter_list_no_sep", "function_body",
  "source_elements", "source_element", "formal_parameter_list__opt",
  "formal_parameter_list__opt_no_sep", "identifier__opt", "statement",
  "block", "statement_list", "variable_statement", "$@4", "$@5",
  "variable_declaration_list", "variable_declaration_list_no_in",
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
       121,     0,    -1,    -1,   122,   132,    -1,    -1,    74,    77,
      47,   124,   134,   113,   114,   131,   115,    -1,    -1,    74,
     136,    47,   126,   134,   113,   114,   131,   115,    -1,   127,
      -1,   112,   135,   128,    -1,   111,   114,   131,   115,    -1,
      77,    -1,   147,    -1,   129,     3,   147,    -1,   129,     3,
      77,    -1,    77,    -1,   147,    -1,   129,   147,    -1,   129,
      77,    -1,    -1,   132,    -1,   133,    -1,   132,   133,    -1,
     137,    -1,   123,    -1,    -1,   129,    -1,    -1,   130,    -1,
      -1,    77,    -1,   138,    -1,   140,    -1,   153,    -1,   154,
      -1,   155,    -1,   156,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,    -1,   170,    -1,   165,    -1,   171,    -1,   173,
      -1,   114,   115,    -1,   114,   139,   115,    -1,   137,    -1,
     139,   137,    -1,    -1,   105,   143,   141,   226,    -1,    -1,
      59,   143,   142,   226,    -1,   145,    -1,   143,     3,   145,
      -1,   146,    -1,   144,     3,   146,    -1,    77,   177,    -1,
     147,   151,    -1,    77,   178,    -1,   147,   152,    -1,   184,
      -1,   148,    -1,    -1,   114,   149,   150,   115,    -1,    77,
      -1,   190,   116,    77,    -1,   150,     3,   190,   116,    77,
      -1,   150,     3,    77,    -1,   117,   218,    -1,   117,   219,
      -1,   226,    -1,   221,   226,    -1,    78,    47,   221,   113,
     137,    65,   137,    -1,    78,    47,   221,   113,   137,    -1,
      -1,    63,   137,   107,    47,   221,   113,   157,   226,    -1,
     107,    47,   221,   113,   137,    -1,    73,    47,   223,   118,
     224,   118,   224,   113,   137,    -1,    73,    47,   105,   144,
     118,   224,   118,   224,   113,   137,    -1,    73,    47,   196,
      28,   221,   113,   137,    -1,    73,    47,   105,   146,    28,
     221,   113,   137,    -1,    -1,    60,   136,   159,   226,    -1,
      -1,    53,   136,   161,   226,    -1,    -1,    92,   224,   163,
     226,    -1,   108,    47,   221,   113,   137,    -1,    97,    47,
     221,   113,   166,    -1,   114,   179,   115,    -1,   114,   179,
     169,   179,   115,    -1,   168,    -1,   167,   168,    -1,    55,
     221,   116,   176,    -1,    62,   116,   176,    -1,    77,   116,
     137,    -1,    -1,   100,   221,   172,   226,    -1,   104,   138,
     174,    -1,   104,   138,   175,    -1,   104,   138,   174,   175,
      -1,    56,    47,    77,   113,   138,    -1,    71,   138,    -1,
      -1,   139,    -1,    -1,   151,    -1,    -1,   152,    -1,    -1,
     167,    -1,   181,    -1,   182,    -1,    86,    -1,    95,    -1,
      91,    -1,    85,    -1,   103,    -1,    69,    -1,    99,    -1,
      77,    -1,   180,    -1,   184,    -1,   187,    -1,    47,   221,
     113,    -1,    49,   225,   119,    -1,    49,   185,   119,    -1,
      49,   185,     3,   225,   119,    -1,   225,   218,    -1,   185,
       3,   225,   218,    -1,     3,    -1,   186,     3,    -1,   114,
     188,   115,    -1,    -1,   189,    -1,   190,   116,   218,    -1,
     189,     3,   190,   116,   218,    -1,    77,    -1,    95,    -1,
      86,    -1,   183,    -1,   125,    -1,   191,    49,   221,   119,
      -1,   191,    50,    77,    -1,    48,   191,   194,    -1,   191,
      -1,    48,   192,    -1,   191,   194,    -1,   193,   194,    -1,
     193,    49,   221,   119,    -1,   193,    50,    77,    -1,    47,
     113,    -1,    47,   195,   113,    -1,   218,    -1,   195,     3,
     218,    -1,   192,    -1,   193,    -1,   196,    -1,   196,    46,
      -1,   196,    45,    -1,   197,    -1,    42,   198,    -1,    43,
     198,    -1,    44,   198,    -1,    46,   198,    -1,    45,   198,
      -1,    35,   198,    -1,    36,   198,    -1,    41,   198,    -1,
      40,   198,    -1,   198,    -1,   199,    37,   198,    -1,   199,
      38,   198,    -1,   199,    39,   198,    -1,   199,    -1,   200,
      35,   199,    -1,   200,    36,   199,    -1,   200,    -1,   201,
      34,   200,    -1,   201,    33,   200,    -1,   201,    32,   200,
      -1,   201,    -1,   202,    26,   201,    -1,   202,    25,   201,
      -1,   202,    29,   201,    -1,   202,    76,   201,    -1,   202,
      27,   201,    -1,   202,    28,   201,    -1,   201,    -1,   203,
      26,   201,    -1,   203,    25,   201,    -1,   203,    29,   201,
      -1,   203,    76,   201,    -1,   203,    27,   201,    -1,   202,
      -1,   204,    23,   202,    -1,   204,    22,   202,    -1,   204,
      24,   202,    -1,   204,    21,   202,    -1,   203,    -1,   205,
      23,   203,    -1,   205,    22,   203,    -1,   205,    24,   203,
      -1,   205,    21,   203,    -1,   204,    -1,   206,    20,   204,
      -1,   205,    -1,   207,    20,   205,    -1,   206,    -1,   208,
      19,   206,    -1,   207,    -1,   209,    19,   207,    -1,   208,
      -1,   210,    18,   208,    -1,   209,    -1,   211,    18,   209,
      -1,   210,    -1,   212,    17,   210,    -1,   211,    -1,   213,
      17,   211,    -1,   212,    -1,   214,    16,   212,    -1,   213,
      -1,   215,    16,   213,    -1,   214,    -1,   214,    15,   218,
     116,   218,    -1,   215,    -1,   215,    15,   219,   116,   219,
      -1,   216,    -1,   196,   220,   218,    -1,   217,    -1,   196,
     220,   219,    -1,   117,    -1,    10,    -1,    12,    -1,    11,
      -1,    14,    -1,     5,    -1,     7,    -1,     6,    -1,     4,
      -1,    13,    -1,     9,    -1,     8,    -1,   218,    -1,   221,
       3,   218,    -1,   219,    -1,   222,     3,   219,    -1,    -1,
     222,    -1,    -1,   221,    -1,    -1,   186,    -1,   118,    -1,
     110,    -1,    -1,    -1,   227,     1,   228,   118,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    18,    19,    29,    31,
      35,    40,    42,    44,    48,    52,    54,    56,    59,    62,
      63,    65,    67,    70,    72,    74,    75,    77,    78,    80,
      81,    83,    85,    87,    89,    91,    93,    95,    97,    99,
     101,   103,   105,   107,   109,   111,   114,   118,   120,   123,
     124,   129,   130,   135,   137,   141,   143,   147,   150,   153,
     156,   159,   161,   163,   164,   169,   171,   175,   181,   185,
     188,   191,   193,   196,   204,   210,   211,   220,   226,   236,
     247,   255,   264,   265,   270,   271,   276,   277,   282,   288,
     294,   298,   304,   306,   309,   314,   318,   322,   323,   328,
     332,   336,   341,   347,   350,   351,   353,   354,   356,   357,
     359,   360,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   384,   386,   388,   392,   396,   400,   406,
     409,   414,   416,   419,   423,   424,   426,   430,   436,   438,
     440,   442,   444,   446,   451,   455,   459,   461,   464,   467,
     470,   475,   479,   482,   486,   488,   492,   494,   496,   498,
     501,   504,   506,   509,   512,   515,   518,   521,   524,   527,
     530,   533,   535,   539,   543,   547,   549,   553,   557,   559,
     563,   567,   571,   573,   577,   581,   585,   589,   593,   597,
     599,   603,   607,   611,   615,   619,   621,   625,   629,   633,
     637,   639,   643,   647,   651,   655,   657,   661,   663,   667,
     669,   673,   675,   679,   681,   685,   687,   691,   693,   697,
     699,   703,   705,   709,   711,   715,   717,   723,   725,   731,
     733,   737,   739,   743,   745,   747,   749,   751,   753,   755,
     757,   759,   761,   763,   765,   767,   769,   773,   775,   779,
     780,   782,   783,   785,   786,   788,   790,   792,   793,   794
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   314,   314,   314,   325,   324,   346,   345,   361,   365,
     376,   380,   388,   394,   399,   409,   417,   423,   428,   438,
     439,   443,   449,   457,   458,   466,   467,   474,   475,   482,
     483,   490,   495,   500,   505,   510,   515,   520,   525,   530,
     535,   540,   545,   550,   555,   563,   569,   578,   584,   594,
     593,   604,   603,   616,   622,   630,   636,   644,   652,   661,
     669,   679,   680,   685,   685,   690,   700,   712,   722,   734,
     738,   742,   746,   755,   764,   775,   775,   784,   793,   804,
     816,   826,   840,   840,   852,   852,   864,   864,   875,   886,
     897,   901,   910,   916,   924,   935,   945,   957,   957,   967,
     975,   983,   995,  1005,  1015,  1016,  1020,  1021,  1025,  1026,
    1030,  1031,  1035,  1036,  1037,  1041,  1045,  1052,  1059,  1063,
    1070,  1074,  1079,  1080,  1081,  1082,  1090,  1096,  1102,  1111,
    1117,  1125,  1126,  1130,  1138,  1141,  1148,  1154,  1162,  1170,
    1177,  1187,  1191,  1195,  1200,  1208,  1217,  1218,  1226,  1270,
    1276,  1281,  1290,  1291,  1295,  1301,  1309,  1310,  1314,  1318,
    1323,  1331,  1332,  1337,  1342,  1347,  1352,  1357,  1362,  1367,
    1372,  1380,  1381,  1385,  1389,  1396,  1397,  1401,  1408,  1409,
    1413,  1417,  1424,  1425,  1429,  1433,  1437,  1441,  1445,  1452,
    1453,  1457,  1461,  1465,  1469,  1476,  1477,  1481,  1485,  1489,
    1496,  1497,  1501,  1505,  1509,  1516,  1517,  1524,  1525,  1532,
    1533,  1540,  1541,  1548,  1549,  1556,  1557,  1564,  1565,  1572,
    1573,  1580,  1581,  1588,  1589,  1596,  1597,  1606,  1607,  1616,
    1620,  1629,  1633,  1642,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,  1651,  1652,  1653,  1657,  1663,  1671,  1677,  1685,
    1686,  1690,  1691,  1695,  1696,  1700,  1701,  1702,  1707,  1702
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
  const int ParserImplementation::yylast_ = 1449;
  const int ParserImplementation::yynnts_ = 109;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 120;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 350;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4109 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 1710 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}


