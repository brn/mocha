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
#line 313 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 314 "grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 324 "grammar.yy"
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
#line 332 "grammar.yy"
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
#line 345 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    scope->Insert ( (yysemantic_stack_[(3) - (2)].ident) );
    scope = scope->Enter ();
    (yyval.ident) = (yysemantic_stack_[(3) - (2)].ident);
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 352 "grammar.yy"
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
#line 366 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(5) - (3)].ast) );
    fn->Body ( (yysemantic_stack_[(5) - (5)].ast) );
    fn->FnScope ( scope );
    (yyval.fn) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 377 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( (yysemantic_stack_[(2) - (2)].ast) );
    fn->FnScope ( scope );
    (yyval.fn) = fn;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 386 "grammar.yy"
    { fprintf( stderr , "l need.\n" ); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 386 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(5) - (4)].ast); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 391 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 399 "grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 405 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].farg)->Args ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 410 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    //scope->Insert ( ident );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 419 "grammar.yy"
    { fprintf( stderr , "r need.\n" );(yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 420 "grammar.yy"
    { fprintf( stderr , "r need.\n" );(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 425 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 431 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 438 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 440 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 447 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 449 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 455 "grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 457 "grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 464 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 469 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 474 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 479 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 484 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 489 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 494 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 499 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 504 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 509 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 514 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 519 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 524 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 529 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 537 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 543 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 552 "grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 558 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 567 "grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 571 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 577 "grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 581 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 590 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 596 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 604 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 610 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 618 "grammar.yy"
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
#line 626 "grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 635 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 643 "grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 652 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 653 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 658 "grammar.yy"
    { tracer->SetState( ParserTracer::kObjectLiteralEnd ); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 658 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (3)].dsto); }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 664 "grammar.yy"
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

  case 63:

/* Line 690 of lalr1.cc  */
#line 674 "grammar.yy"
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

  case 64:

/* Line 690 of lalr1.cc  */
#line 686 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(5) - (5)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( ident );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 696 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( 0 );
    mem->Right( ident );
    (yysemantic_stack_[(3) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(3) - (1)].dsto);
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 707 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 711 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 715 "grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 720 "grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 729 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 738 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 748 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 749 "grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(8) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(8) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 758 "grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 767 "grammar.yy"
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

  case 76:

/* Line 690 of lalr1.cc  */
#line 778 "grammar.yy"
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

  case 77:

/* Line 690 of lalr1.cc  */
#line 790 "grammar.yy"
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

  case 78:

/* Line 690 of lalr1.cc  */
#line 800 "grammar.yy"
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

  case 79:

/* Line 690 of lalr1.cc  */
#line 813 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 814 "grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 825 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 826 "grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 837 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 838 "grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yysemantic_stack_[(4) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 849 "grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 860 "grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 871 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 875 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 884 "grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 890 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 898 "grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 909 "grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 919 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    scope->InsertLabel ( ident );
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 930 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 931 "grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 941 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 949 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 957 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 969 "grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 979 "grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 988 "grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 989 "grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 993 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 994 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 998 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 999 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1003 "grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1004 "grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1008 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1009 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1011 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1019 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1033 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1037 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1044 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1052 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1054 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1056 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1064 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1070 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1076 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1085 "grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1091 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1104 "grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1111 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1115 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1122 "grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1128 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1136 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1144 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1151 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1161 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1165 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1169 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1174 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1182 "grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1190 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1192 "grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1200 "grammar.yy"
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

  case 146:

/* Line 690 of lalr1.cc  */
#line 1244 "grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1250 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1255 "grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1263 "grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1264 "grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1269 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1275 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1282 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1283 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1288 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1292 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1297 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1304 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1306 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1311 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1316 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1321 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1326 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1331 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1336 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1341 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1346 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1355 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1359 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1363 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1369 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1371 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1375 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1383 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1387 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1391 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1397 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1399 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1403 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1407 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1411 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1415 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1419 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1425 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1427 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1431 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1435 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1439 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1443 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1449 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1451 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1459 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1463 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1469 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1471 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1475 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1479 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1483 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1489 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1491 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1497 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1499 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1505 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1507 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1513 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1515 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1521 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1523 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1529 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1531 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1537 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1539 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1545 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1547 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1553 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1555 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1561 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1569 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1571 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1579 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1581 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1590 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1594 "grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1603 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1607 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1615 "grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1616 "grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1618 "grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1619 "grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1620 "grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1622 "grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1623 "grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1624 "grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1625 "grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1626 "grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1631 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1637 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1645 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1651 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1658 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1659 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1664 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1668 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1669 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1673 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1674 "grammar.yy"
    {(yyval.num) = ';';tracer->SetLineBreakFlag ( false );}
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1675 "grammar.yy"
    {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1680 "grammar.yy"
    {yyclearin;yyerrok;}
    break;



/* Line 690 of lalr1.cc  */
#line 2893 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -310;
  const short int
  ParserImplementation::yypact_[] =
  {
      -310,    33,   984,  -310,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1294,  1294,  1301,    47,   -66,   -39,   -66,  1064,
    -310,   -33,     7,   -51,    46,  -310,  -310,  -310,  1294,  -310,
      63,  -310,  1294,  -310,   -18,   -39,    65,    89,  -310,   -38,
     741,  -310,  -310,  -310,  -310,  -310,   388,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,    57,
    -310,   166,   270,  -310,  -310,    61,    55,   190,   149,   135,
     140,   143,   192,   229,   102,  -310,  -310,     5,  -310,   231,
     -66,  -310,    -6,   172,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,    29,    57,  -310,  -310,     1,   244,   572,
    -310,  -310,   131,  -310,   246,  -310,   131,  -310,  -310,  -310,
     161,  1144,   222,   224,  1064,  1294,   269,  -310,  1294,   269,
     822,    11,   246,  1294,  1294,   -13,  -310,  -310,   -51,   157,
     171,  -310,  -310,   903,   173,   286,   174,  -310,  1219,  1294,
     216,  -310,  1294,   217,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,    47,  -310,  -310,  -310,  -310,   -31,  1294,  -310,
    -310,    -3,   -39,   -31,  -310,   -31,   245,     0,   583,   190,
     138,   148,   275,   277,   279,   282,   215,  -310,  -310,   297,
     183,  -310,  -310,  -310,    32,   -31,    34,   -31,   255,   -18,
     232,  -310,   -31,    36,    37,  -310,   301,   193,  -310,   194,
    -310,  -310,  -310,    -6,  1294,  -310,    38,  -310,    12,  -310,
      16,  -310,  -310,  -310,  -310,  -310,    61,    61,    55,    55,
      55,   190,   190,   190,   190,   190,   190,   149,   149,   149,
     149,   135,   140,   143,   192,   191,   229,  -310,   199,   661,
    -310,  -310,   195,    28,   196,  -310,  -310,  -310,  1294,   201,
      14,   291,   201,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,   -13,   -13,  1064,  -310,   206,  -310,   233,  -310,
    -310,  -310,  1064,  1064,    20,   210,   388,   225,  -310,  1294,
    -310,  -310,  -310,  1294,  -310,  -310,  -310,     8,  -310,   265,
      40,  1294,  -310,  -310,     0,  1294,  1294,  -310,    41,   270,
    -310,   190,   190,   190,   190,   190,   138,   138,   138,   138,
     148,   275,   277,   279,   236,   282,  -310,   227,   235,   240,
     284,   299,  -310,   242,  -310,  -310,  -310,  -310,  -310,   241,
     388,  1294,  -310,  -310,   195,   243,  -310,  -310,  -310,  -310,
     239,    42,  1064,  1294,  1294,   247,   248,  1064,  1294,   299,
    -310,   -49,   -18,  -310,  -310,   281,   -31,  1294,  1064,  -310,
    -310,   250,   388,   388,  -310,     3,  -310,   249,  -310,   299,
    -310,  -310,  -310,   251,  -310,  1064,   252,   253,   468,   468,
     257,  1064,  -310,  -310,  -310,   468,  -310,  -310,  -310,  -310
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,   254,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    26,     0,    26,   254,
     116,     0,    26,   118,     0,   114,   111,   113,   248,   112,
       0,   117,     0,   115,     0,     0,     0,     0,   253,     0,
     254,   252,    23,   139,     8,     9,     3,    20,    22,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    39,
      38,    40,    41,   119,   109,   110,   138,   120,   121,   143,
     153,   154,   155,   158,   168,   172,   175,   179,   192,   202,
     206,   210,   214,   218,   222,   226,   242,   254,    68,     0,
      26,   118,   131,   155,   164,   165,   167,   166,   159,   160,
     161,   163,   162,     0,   143,   144,   128,     0,   251,     0,
      27,    81,   103,    60,    48,    50,     0,    59,    58,    79,
       0,   246,     0,     0,   254,     0,   249,    83,     0,    94,
     254,     0,    46,     0,     0,    24,    12,    11,   118,   111,
     112,    42,    44,   254,     0,   132,     0,    21,     0,     0,
       0,   145,     0,     0,   146,   238,   235,   237,   236,   241,
     240,   231,   233,   232,   239,   234,   157,   156,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,   255,   135,   137,   136,
     122,   142,   250,   124,   129,   123,   126,   254,     0,   104,
      54,     0,     0,   254,    55,   254,     0,     0,   155,   186,
     197,   204,   208,   212,   216,   220,   224,   228,   244,   247,
       0,     4,     6,    93,     0,   254,     0,   254,     0,     0,
      96,    97,   254,     0,     0,    14,    25,     0,    15,     0,
      43,    45,   130,     0,     0,   149,     0,   151,     0,   141,
       0,   148,   227,   169,   170,   171,   173,   174,   178,   177,
     176,   181,   180,   184,   185,   182,   183,   196,   194,   193,
     195,   203,   207,   211,   215,     0,   219,   243,     0,     0,
      82,    66,    62,     0,     0,    51,    49,    80,     0,   105,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,    24,   254,    84,     0,    95,     0,   100,
      98,    47,   254,   254,     0,     0,    18,     0,   133,     0,
     150,   140,   147,     0,   256,   125,   127,     0,    61,     0,
       0,     0,   106,    56,     0,   248,     0,    57,     0,   155,
     229,   188,   187,   191,   189,   190,   201,   199,   198,   200,
     205,   209,   213,   217,     0,   221,   245,     0,     0,     0,
      71,   107,    86,     0,    74,    85,    17,    16,    10,     0,
      19,     0,   152,   223,    65,     0,    63,    72,    67,    53,
       0,     0,   254,     0,   248,     0,     0,   254,     0,   108,
      89,     0,     0,    13,   134,     0,   254,   248,   254,    77,
     225,     0,    18,    18,    70,     0,    90,     0,    87,   107,
      99,    64,    73,     0,    78,   254,     0,     0,   101,   101,
       0,   254,    75,     5,     7,   102,    91,    92,    88,    76
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,    25,
    -310,  -310,  -187,   364,   -44,   -82,    54,   -19,   -27,  -196,
    -310,  -310,  -310,   335,  -310,   162,    19,   -84,  -310,  -310,
    -310,   259,    74,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,   -32,  -310,
    -310,  -310,  -310,  -310,  -310,   139,   -61,  -310,  -310,   -48,
    -310,  -310,  -310,  -310,    17,  -310,  -310,  -310,  -310,  -310,
    -206,   366,   368,  -310,   -23,  -310,    18,  -310,    49,    71,
      51,   -53,    -5,  -126,   198,    70,   202,    75,   203,    78,
     204,    80,   205,    81,  -310,  -310,  -310,  -310,  -106,  -242,
     329,   -12,  -310,  -310,  -309,   200,   -69,  -310,  -310
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    42,   322,    43,   323,    44,    45,   137,
     249,   246,   389,   390,    47,   247,   123,    48,    49,   143,
      50,   242,   213,   114,   300,   115,   301,   116,   117,   211,
     293,   209,   352,    51,    52,    53,    54,   416,    55,   215,
      56,   207,    57,   235,    58,    59,   382,   409,   410,   429,
      60,    61,   237,    62,   240,   241,   446,   210,   353,   411,
      63,    64,    65,    66,    67,   107,   108,    68,   144,   145,
     146,    69,    70,    71,   151,   256,    72,    73,    74,    75,
      76,    77,    78,   220,    79,   221,    80,   222,    81,   223,
      82,   224,    83,   225,    84,   226,    85,   227,    86,   228,
     304,    87,   229,   230,   127,   109,    88,    89,   288
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -255;
  const short int
  ParserImplementation::yytable_[] =
  {
       120,   103,   147,   206,   202,   294,   194,   131,   194,   135,
      15,   110,   377,   427,   121,   194,   126,   354,   195,   194,
     129,   142,    93,    93,    93,    93,    93,    93,    93,    93,
      93,   347,   194,     3,   118,   194,    15,   194,   112,   194,
     194,   339,   257,   194,   194,   194,   400,   337,   154,    15,
     106,   248,   118,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   360,   262,   245,   124,   428,   238,   219,    15,
     111,   197,   119,   136,   292,   113,   374,   299,   376,    38,
     198,   201,   239,   198,   122,   394,   285,    41,   287,   199,
     173,   174,   199,   125,   198,   421,   130,   386,   170,   171,
     172,   113,   291,   199,   148,   233,   149,   150,   433,   398,
     128,   142,   133,   234,   113,    38,   236,   192,   193,   438,
     203,   243,   244,    41,   251,   271,   272,   273,   274,   275,
     276,   341,   355,   302,   113,   342,   134,   258,   290,   218,
     260,   395,   200,   348,   296,   324,   297,   326,   338,   332,
     333,   340,   118,   397,   402,   418,   184,   185,   186,   187,
     188,   420,   189,   305,   306,   307,   325,   308,   327,   310,
     311,   312,   313,   331,   178,   179,   180,   181,   182,   277,
     278,   279,   280,   346,   366,   367,   368,   369,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
     190,    93,   329,   148,   309,   152,   153,   166,   167,   263,
     264,   265,   175,   176,   177,   183,   268,   269,   270,   118,
     318,   319,   196,   392,   118,   436,   437,   393,   248,   248,
     378,   379,   445,   445,   266,   267,   191,   204,   208,   212,
     387,   219,   361,   362,   363,   364,   365,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   216,   231,
     302,   232,   194,  -137,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   414,   350,  -136,   252,   253,
     254,   358,   298,   259,   261,   314,   315,   316,   219,   317,
     320,   321,   328,   239,   334,   380,   335,   343,   336,   126,
     383,  -135,   349,   384,   385,   166,   167,   344,   351,   356,
     381,   136,   359,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,   359,    93,   359,   118,
     118,   391,   396,   126,   401,   404,   147,   432,   405,   407,
     219,   118,   403,   406,   408,   412,   413,   417,   431,   415,
     388,   422,   423,   435,   441,   439,    46,   443,   444,   359,
     132,   118,   448,   399,   295,   214,   357,   426,   447,   330,
     104,   440,   105,   419,   370,   430,   281,   168,   424,  -254,
     371,   282,   126,   283,   372,   284,   425,   373,   286,   434,
     375,   169,   289,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   442,     0,     0,   142,
     142,   359,   449,     4,     5,     0,   251,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,    21,    22,     0,     0,    23,    24,     0,     0,  -254,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,     0,
       0,    33,    34,    35,     0,    36,    37,     0,    38,     0,
      39,     0,    40,     4,     5,     0,    41,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,    21,    90,     0,     0,    23,    24,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,     0,
       0,    33,    34,    35,     0,    36,    37,     0,    38,     0,
      39,     0,    40,     0,     0,     0,    41,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,   303,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    90,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    92,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     4,     5,     0,     0,
     168,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    92,     4,     5,     0,     0,
     345,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    21,    90,     0,     0,   138,    24,
       0,     0,     0,     0,     0,     0,    25,   139,     0,     0,
       0,     0,    27,    28,     0,     0,   140,     0,    30,     0,
      31,    32,     0,     0,    33,    34,    35,     0,    36,    37,
       0,    38,     0,    39,     0,    40,   141,     4,     5,    41,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    90,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     0,    40,   141,     4,     5,
      41,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    90,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,     0,    40,   250,     4,
       5,    41,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    22,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,     0,     0,    33,    34,    35,
       0,    36,    37,     0,    38,     0,    39,     0,    40,     4,
       5,     0,    41,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    90,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,     0,     0,    33,    34,    35,
       0,    36,    37,     0,    38,     0,    39,     0,    40,     4,
       5,     0,    41,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,     0,     0,     0,    29,
       0,     0,     0,    31,     0,     0,     0,    33,     0,   217,
       0,     0,     0,     0,     4,     5,    39,     0,    92,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    90,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
      27,     0,     0,     0,    29,     0,     0,     0,    31,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     4,
       5,    39,   255,    92,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    90,     0,
      20,    91,     0,     0,     0,    90,     0,     0,    91,    25,
      26,     0,     0,     0,     0,    27,    25,    26,     0,    29,
       0,     0,    27,    31,     0,     0,    29,    33,     0,     0,
      31,     0,     0,     0,    33,     0,    39,     0,    92,     0,
       0,     0,     0,    39,     0,    92
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    13,    46,   109,     3,   211,     3,    34,     3,    47,
      49,    77,   321,    62,    47,     3,    28,     3,    87,     3,
      32,    40,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     3,     3,     0,    17,     3,    49,     3,    77,     3,
       3,     3,   148,     3,     3,     3,   355,   253,    71,    49,
       3,   135,    35,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   304,   169,    77,   116,   115,    56,   121,    49,
      16,    77,    18,   111,    77,   114,   318,    77,   320,   110,
      86,   104,    71,    86,    77,    77,   192,   118,   194,    95,
      35,    36,    95,    47,    86,   404,   114,    77,    37,    38,
      39,   114,   208,    95,    47,   124,    49,    50,   417,   351,
      47,   130,    47,   125,   114,   110,   128,    15,    16,   116,
     119,   133,   134,   118,   143,   178,   179,   180,   181,   182,
     183,   119,   118,   217,   114,   119,    47,   149,   207,   121,
     152,   347,   113,   115,   213,   113,   215,   113,   254,   113,
     113,   113,   135,   113,   113,   113,    21,    22,    23,    24,
      20,   403,    19,    25,    26,    27,   235,    29,   237,    21,
      22,    23,    24,   242,    25,    26,    27,    28,    29,   184,
     185,   186,   187,   289,   310,   311,   312,   313,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      18,   193,   239,    47,    76,    49,    50,    45,    46,   170,
     171,   172,    32,    33,    34,    76,   175,   176,   177,   212,
      15,    16,     1,   339,   217,   422,   423,   343,   322,   323,
     322,   323,   438,   439,   173,   174,    17,     3,   117,     3,
     334,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   107,    47,
     354,    47,     3,   116,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   391,   298,   116,   115,     3,
     116,   303,    47,    77,    77,    20,    19,    18,   351,    17,
       3,   118,    47,    71,     3,   324,   113,   116,   114,   321,
      77,   116,   116,   332,   333,    45,    46,   118,   117,    28,
     114,   111,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   322,
     323,   116,    77,   355,   356,   118,   390,   416,   113,    65,
     403,   334,   116,   113,    55,   113,   115,   118,    77,   116,
     335,   114,   114,   113,   113,   116,     2,   115,   115,   351,
      35,   354,   115,   354,   212,   116,   302,   409,   439,   240,
      14,   429,    14,   402,   314,   412,   188,   117,   407,     1,
     315,   189,   404,   190,   316,   191,   408,   317,   193,   418,
     319,    72,   202,    -1,    -1,   417,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,   438,
     439,   403,   441,    35,    36,    -1,   445,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    73,    74,    -1,    -1,    77,    78,    -1,    -1,     1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    91,
      92,    -1,    -1,    95,    -1,    97,    -1,    99,   100,    -1,
      -1,   103,   104,   105,    -1,   107,   108,    -1,   110,    -1,
     112,    -1,   114,    35,    36,    -1,   118,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    73,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    91,
      92,    -1,    -1,    95,    -1,    97,    -1,    99,   100,    -1,
      -1,   103,   104,   105,    -1,   107,   108,    -1,   110,    -1,
     112,    -1,   114,    -1,    -1,    -1,   118,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    28,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
     117,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,   114,    35,    36,    -1,    -1,
     119,    40,    41,    42,    43,    44,    45,    46,    47,    48,
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
     107,   108,    -1,   110,    -1,   112,    -1,   114,   115,    35,
      36,   118,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,   105,
      -1,   107,   108,    -1,   110,    -1,   112,    -1,   114,    35,
      36,    -1,   118,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,   105,
      -1,   107,   108,    -1,   110,    -1,   112,    -1,   114,    35,
      36,    -1,   118,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    35,    36,   112,    -1,   114,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,   112,   113,   114,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,
      69,    77,    -1,    -1,    -1,    74,    -1,    -1,    77,    85,
      86,    -1,    -1,    -1,    -1,    91,    85,    86,    -1,    95,
      -1,    -1,    91,    99,    -1,    -1,    95,   103,    -1,    -1,
      99,    -1,    -1,    -1,   103,    -1,   112,    -1,   114,    -1,
      -1,    -1,    -1,   112,    -1,   114
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
     114,   118,   123,   125,   127,   128,   133,   134,   137,   138,
     140,   153,   154,   155,   156,   158,   160,   162,   164,   165,
     170,   171,   173,   180,   181,   182,   183,   184,   187,   191,
     192,   193,   196,   197,   198,   199,   200,   201,   202,   204,
     206,   208,   210,   212,   214,   216,   218,   221,   226,   227,
      74,    77,   114,   196,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   221,   191,   192,     3,   185,   186,   225,
      77,   136,    77,   114,   143,   145,   147,   148,   184,   136,
     137,    47,    77,   136,   116,    47,   221,   224,    47,   221,
     114,   138,   143,    47,    47,    47,   111,   129,    77,    86,
      95,   115,   137,   139,   188,   189,   190,   134,    47,    49,
      50,   194,    49,    50,   194,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    45,    46,   117,   220,
      37,    38,    39,    35,    36,    32,    33,    34,    25,    26,
      27,    28,    29,    76,    21,    22,    23,    24,    20,    19,
      18,    17,    15,    16,     3,   226,     1,    77,    86,    95,
     113,   194,     3,   119,     3,   119,   218,   161,   117,   151,
     177,   149,     3,   142,   151,   159,   107,   105,   196,   201,
     203,   205,   207,   209,   211,   213,   215,   217,   219,   222,
     223,    47,    47,   137,   221,   163,   221,   172,    56,    71,
     174,   175,   141,   221,   221,    77,   131,   135,   147,   130,
     115,   137,   115,     3,   116,   113,   195,   218,   221,    77,
     221,    77,   218,   198,   198,   198,   199,   199,   200,   200,
     200,   201,   201,   201,   201,   201,   201,   202,   202,   202,
     202,   204,   206,   208,   210,   218,   212,   218,   228,   225,
     226,   218,    77,   150,   190,   145,   226,   226,    47,    77,
     144,   146,   147,    28,   220,    25,    26,    27,    29,    76,
      21,    22,    23,    24,    20,    19,    18,    17,    15,    16,
       3,   118,   124,   126,   113,   226,   113,   226,    47,   138,
     175,   226,   113,   113,     3,   113,   114,   190,   218,     3,
     113,   119,   119,   116,   118,   119,   218,     3,   115,   116,
     221,   117,   152,   178,     3,   118,    28,   152,   221,   196,
     219,   201,   201,   201,   201,   201,   203,   203,   203,   203,
     205,   207,   209,   211,   219,   213,   219,   224,   135,   135,
     137,   114,   166,    77,   137,   137,    77,   147,   129,   132,
     133,   116,   218,   218,    77,   190,    77,   113,   219,   146,
     224,   221,   113,   116,   118,   113,   113,    65,    55,   167,
     168,   179,   113,   115,   218,   116,   157,   118,   113,   137,
     219,   224,   114,   114,   137,   221,   168,    62,   115,   169,
     138,    77,   226,   224,   137,   113,   132,   132,   116,   116,
     179,   113,   137,   115,   115,   139,   176,   176,   115,   137
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
     127,   128,   130,   129,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   139,   139,   141,   140,   142,   140,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     149,   148,   150,   150,   150,   150,   151,   152,   153,   154,
     155,   155,   157,   156,   156,   156,   156,   156,   156,   159,
     158,   161,   160,   163,   162,   164,   165,   166,   166,   167,
     167,   168,   169,   170,   172,   171,   173,   173,   173,   174,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   180,   180,   180,   181,   182,   182,   183,   183,   183,
     183,   183,   183,   184,   184,   184,   185,   185,   186,   186,
     187,   188,   188,   189,   189,   190,   190,   190,   191,   191,
     191,   191,   191,   192,   192,   193,   193,   193,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   197,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   200,   200,   200,   201,   201,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   203,   203,   203,   203,
     203,   203,   204,   204,   204,   204,   204,   205,   205,   205,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   221,   221,   222,   222,   223,   223,   224,   224,
     225,   225,   226,   226,   227,   228,   226
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     0,     9,     0,     9,     1,     1,
       5,     2,     0,     5,     1,     1,     3,     3,     0,     1,
       1,     2,     1,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     0,     4,     0,     4,
       1,     3,     1,     3,     2,     2,     2,     2,     1,     1,
       0,     4,     1,     3,     5,     3,     2,     2,     1,     2,
       7,     5,     0,     8,     5,     9,    10,     7,     8,     0,
       4,     0,     4,     0,     4,     5,     5,     3,     5,     1,
       2,     4,     3,     3,     0,     4,     3,     3,     4,     5,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     2,     4,     1,     2,
       3,     0,     1,     3,     5,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     2,     2,     2,     4,     3,     2,
       3,     1,     3,     1,     1,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     5,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     0,     1,     0,     1,
       0,     1,     1,     1,     0,     0,     4
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
  "function_body_expression", "$@4", "formal_parameter_list",
  "function_body", "source_elements", "source_element",
  "formal_parameter_list__opt", "identifier__opt", "statement", "block",
  "statement_list", "variable_statement", "$@5", "$@6",
  "variable_declaration_list", "variable_declaration_list_no_in",
  "variable_declaration", "variable_declaration_no_in",
  "destructuring_assignment_left_hand_side", "object_left_hand_side",
  "$@7", "object_member_left_hand_side_list", "initialiser",
  "initialiser_no_in", "empty_statement", "expression_statement",
  "if_statement", "iteration_statement", "$@8", "continue_statement",
  "$@9", "break_statement", "$@10", "return_statement", "$@11",
  "with_statement", "switch_statement", "case_block", "case_clauses",
  "case_clause", "default_clause", "labelled_statement", "throw_statement",
  "$@12", "try_statement", "catch", "finally", "statement_list__opt",
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
  "$@13", "$@14", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       121,     0,    -1,    -1,   122,   133,    -1,    -1,    74,    77,
      47,   124,   135,   113,   114,   132,   115,    -1,    -1,    74,
     136,    47,   126,   135,   113,   114,   132,   115,    -1,   127,
      -1,   128,    -1,   112,    47,   135,   113,   129,    -1,   112,
     129,    -1,    -1,   111,   130,   114,   132,   115,    -1,    77,
      -1,   147,    -1,   131,     3,   147,    -1,   131,     3,    77,
      -1,    -1,   133,    -1,   134,    -1,   133,   134,    -1,   137,
      -1,   123,    -1,    -1,   131,    -1,    -1,    77,    -1,   138,
      -1,   140,    -1,   153,    -1,   154,    -1,   155,    -1,   156,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,    -1,   170,
      -1,   165,    -1,   171,    -1,   173,    -1,   114,   115,    -1,
     114,   139,   115,    -1,   137,    -1,   139,   137,    -1,    -1,
     105,   143,   141,   226,    -1,    -1,    59,   143,   142,   226,
      -1,   145,    -1,   143,     3,   145,    -1,   146,    -1,   144,
       3,   146,    -1,    77,   177,    -1,   147,   151,    -1,    77,
     178,    -1,   147,   152,    -1,   184,    -1,   148,    -1,    -1,
     114,   149,   150,   115,    -1,    77,    -1,   190,   116,    77,
      -1,   150,     3,   190,   116,    77,    -1,   150,     3,    77,
      -1,   117,   218,    -1,   117,   219,    -1,   226,    -1,   221,
     226,    -1,    78,    47,   221,   113,   137,    65,   137,    -1,
      78,    47,   221,   113,   137,    -1,    -1,    63,   137,   107,
      47,   221,   113,   157,   226,    -1,   107,    47,   221,   113,
     137,    -1,    73,    47,   223,   118,   224,   118,   224,   113,
     137,    -1,    73,    47,   105,   144,   118,   224,   118,   224,
     113,   137,    -1,    73,    47,   196,    28,   221,   113,   137,
      -1,    73,    47,   105,   146,    28,   221,   113,   137,    -1,
      -1,    60,   136,   159,   226,    -1,    -1,    53,   136,   161,
     226,    -1,    -1,    92,   224,   163,   226,    -1,   108,    47,
     221,   113,   137,    -1,    97,    47,   221,   113,   166,    -1,
     114,   179,   115,    -1,   114,   179,   169,   179,   115,    -1,
     168,    -1,   167,   168,    -1,    55,   221,   116,   176,    -1,
      62,   116,   176,    -1,    77,   116,   137,    -1,    -1,   100,
     221,   172,   226,    -1,   104,   138,   174,    -1,   104,   138,
     175,    -1,   104,   138,   174,   175,    -1,    56,    47,    77,
     113,   138,    -1,    71,   138,    -1,    -1,   139,    -1,    -1,
     151,    -1,    -1,   152,    -1,    -1,   167,    -1,   181,    -1,
     182,    -1,    86,    -1,    95,    -1,    91,    -1,    85,    -1,
     103,    -1,    69,    -1,    99,    -1,    77,    -1,   180,    -1,
     184,    -1,   187,    -1,    47,   221,   113,    -1,    49,   225,
     119,    -1,    49,   185,   119,    -1,    49,   185,     3,   225,
     119,    -1,   225,   218,    -1,   185,     3,   225,   218,    -1,
       3,    -1,   186,     3,    -1,   114,   188,   115,    -1,    -1,
     189,    -1,   190,   116,   218,    -1,   189,     3,   190,   116,
     218,    -1,    77,    -1,    95,    -1,    86,    -1,   183,    -1,
     125,    -1,   191,    49,   221,   119,    -1,   191,    50,    77,
      -1,    48,   191,   194,    -1,   191,    -1,    48,   192,    -1,
     191,   194,    -1,   193,   194,    -1,   193,    49,   221,   119,
      -1,   193,    50,    77,    -1,    47,   113,    -1,    47,   195,
     113,    -1,   218,    -1,   195,     3,   218,    -1,   192,    -1,
     193,    -1,   196,    -1,   196,    46,    -1,   196,    45,    -1,
     197,    -1,    42,   198,    -1,    43,   198,    -1,    44,   198,
      -1,    46,   198,    -1,    45,   198,    -1,    35,   198,    -1,
      36,   198,    -1,    41,   198,    -1,    40,   198,    -1,   198,
      -1,   199,    37,   198,    -1,   199,    38,   198,    -1,   199,
      39,   198,    -1,   199,    -1,   200,    35,   199,    -1,   200,
      36,   199,    -1,   200,    -1,   201,    34,   200,    -1,   201,
      33,   200,    -1,   201,    32,   200,    -1,   201,    -1,   202,
      26,   201,    -1,   202,    25,   201,    -1,   202,    29,   201,
      -1,   202,    76,   201,    -1,   202,    27,   201,    -1,   202,
      28,   201,    -1,   201,    -1,   203,    26,   201,    -1,   203,
      25,   201,    -1,   203,    29,   201,    -1,   203,    76,   201,
      -1,   203,    27,   201,    -1,   202,    -1,   204,    23,   202,
      -1,   204,    22,   202,    -1,   204,    24,   202,    -1,   204,
      21,   202,    -1,   203,    -1,   205,    23,   203,    -1,   205,
      22,   203,    -1,   205,    24,   203,    -1,   205,    21,   203,
      -1,   204,    -1,   206,    20,   204,    -1,   205,    -1,   207,
      20,   205,    -1,   206,    -1,   208,    19,   206,    -1,   207,
      -1,   209,    19,   207,    -1,   208,    -1,   210,    18,   208,
      -1,   209,    -1,   211,    18,   209,    -1,   210,    -1,   212,
      17,   210,    -1,   211,    -1,   213,    17,   211,    -1,   212,
      -1,   214,    16,   212,    -1,   213,    -1,   215,    16,   213,
      -1,   214,    -1,   214,    15,   218,   116,   218,    -1,   215,
      -1,   215,    15,   219,   116,   219,    -1,   216,    -1,   196,
     220,   218,    -1,   217,    -1,   196,   220,   219,    -1,   117,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   218,    -1,   221,     3,   218,    -1,   219,
      -1,   222,     3,   219,    -1,    -1,   222,    -1,    -1,   221,
      -1,    -1,   186,    -1,   118,    -1,   110,    -1,    -1,    -1,
     227,     1,   228,   118,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    18,    19,    29,    31,
      33,    39,    42,    43,    49,    51,    53,    57,    61,    62,
      64,    66,    69,    71,    73,    74,    76,    77,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   110,   114,   116,   119,   120,   125,   126,
     131,   133,   137,   139,   143,   146,   149,   152,   155,   157,
     159,   160,   165,   167,   171,   177,   181,   184,   187,   189,
     192,   200,   206,   207,   216,   222,   232,   243,   251,   260,
     261,   266,   267,   272,   273,   278,   284,   290,   294,   300,
     302,   305,   310,   314,   318,   319,   324,   328,   332,   337,
     343,   346,   347,   349,   350,   352,   353,   355,   356,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   382,   384,   388,   392,   396,   402,   405,   410,   412,
     415,   419,   420,   422,   426,   432,   434,   436,   438,   440,
     442,   447,   451,   455,   457,   460,   463,   466,   471,   475,
     478,   482,   484,   488,   490,   492,   494,   497,   500,   502,
     505,   508,   511,   514,   517,   520,   523,   526,   529,   531,
     535,   539,   543,   545,   549,   553,   555,   559,   563,   567,
     569,   573,   577,   581,   585,   589,   593,   595,   599,   603,
     607,   611,   615,   617,   621,   625,   629,   633,   635,   639,
     643,   647,   651,   653,   657,   659,   663,   665,   669,   671,
     675,   677,   681,   683,   687,   689,   693,   695,   699,   701,
     705,   707,   711,   713,   719,   721,   727,   729,   733,   735,
     739,   741,   743,   745,   747,   749,   751,   753,   755,   757,
     759,   761,   763,   765,   769,   771,   775,   776,   778,   779,
     781,   782,   784,   786,   788,   789,   790
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   313,   313,   313,   324,   323,   345,   344,   360,   361,
     365,   376,   386,   386,   390,   398,   404,   409,   419,   420,
     424,   430,   438,   439,   447,   448,   455,   456,   463,   468,
     473,   478,   483,   488,   493,   498,   503,   508,   513,   518,
     523,   528,   536,   542,   551,   557,   567,   566,   577,   576,
     589,   595,   603,   609,   617,   625,   634,   642,   652,   653,
     658,   658,   663,   673,   685,   695,   707,   711,   715,   719,
     728,   737,   748,   748,   757,   766,   777,   789,   799,   813,
     813,   825,   825,   837,   837,   848,   859,   870,   874,   883,
     889,   897,   908,   918,   930,   930,   940,   948,   956,   968,
     978,   988,   989,   993,   994,   998,   999,  1003,  1004,  1008,
    1009,  1010,  1014,  1018,  1025,  1032,  1036,  1043,  1047,  1052,
    1053,  1054,  1055,  1063,  1069,  1075,  1084,  1090,  1098,  1099,
    1103,  1111,  1114,  1121,  1127,  1135,  1143,  1150,  1160,  1164,
    1168,  1173,  1181,  1190,  1191,  1199,  1243,  1249,  1254,  1263,
    1264,  1268,  1274,  1282,  1283,  1287,  1291,  1296,  1304,  1305,
    1310,  1315,  1320,  1325,  1330,  1335,  1340,  1345,  1353,  1354,
    1358,  1362,  1369,  1370,  1374,  1381,  1382,  1386,  1390,  1397,
    1398,  1402,  1406,  1410,  1414,  1418,  1425,  1426,  1430,  1434,
    1438,  1442,  1449,  1450,  1454,  1458,  1462,  1469,  1470,  1474,
    1478,  1482,  1489,  1490,  1497,  1498,  1505,  1506,  1513,  1514,
    1521,  1522,  1529,  1530,  1537,  1538,  1545,  1546,  1553,  1554,
    1561,  1562,  1569,  1570,  1579,  1580,  1589,  1593,  1602,  1606,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1630,  1636,  1644,  1650,  1658,  1659,  1663,  1664,
    1668,  1669,  1673,  1674,  1675,  1680,  1675
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
  const int ParserImplementation::yylast_ = 1415;
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
#line 4057 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 1683 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}


