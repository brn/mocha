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
#line 301 "src/grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 302 "src/grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 312 "src/grammar.yy"
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
#line 320 "src/grammar.yy"
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
#line 333 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    scope->Insert ( (yysemantic_stack_[(3) - (2)].ident) );
    scope = scope->Enter ();
    (yyval.ident) = (yysemantic_stack_[(3) - (2)].ident);
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 340 "src/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(9) - (4)].ident) ) );
    fn->Argv ( (yysemantic_stack_[(9) - (5)].ast) );
    fn->Body ( (yysemantic_stack_[(9) - (8)].ast) );
    fn->FnScope ( scope );
    scope = scope->Escape ();
    (yyval.fn) = fn;
  }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 352 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 360 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //scope->Insert ( ident );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 369 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 370 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 375 "src/grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 381 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 388 "src/grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 390 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 397 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 399 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 405 "src/grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 407 "src/grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 414 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 419 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 424 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 429 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 434 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 439 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 444 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 449 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 454 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 459 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 464 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 469 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 474 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 479 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 487 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 493 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 502 "src/grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 508 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 517 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 521 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 527 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 531 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 540 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].vars) );
    (yyval.varsList) = ret;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 546 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].vars) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 554 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].vars) );
    (yyval.varsList) = ret;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 560 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].vars) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 568 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.vars) = var;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 579 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.vars) = var;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 615 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 619 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 623 "src/grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 628 "src/grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 637 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 646 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 656 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 657 "src/grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(8) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(8) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 666 "src/grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 675 "src/grammar.yy"
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

  case 58:

/* Line 690 of lalr1.cc  */
#line 686 "src/grammar.yy"
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

  case 59:

/* Line 690 of lalr1.cc  */
#line 698 "src/grammar.yy"
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

  case 60:

/* Line 690 of lalr1.cc  */
#line 708 "src/grammar.yy"
    {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(8) - (4)].vars) );
    ret->Target ( (yysemantic_stack_[(8) - (6)].exp) );
    ret->Body ( (yysemantic_stack_[(8) - (8)].source_block) );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 721 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 722 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 733 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 734 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 745 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 746 "src/grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yysemantic_stack_[(4) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 757 "src/grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 768 "src/grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 779 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 783 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 792 "src/grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 798 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 806 "src/grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 817 "src/grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 827 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    scope->InsertLabel ( ident );
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 838 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 839 "src/grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 849 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 857 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 865 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 877 "src/grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 887 "src/grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 896 "src/grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 897 "src/grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 901 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 902 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 906 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 907 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 911 "src/grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 912 "src/grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 916 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 917 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 919 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 923 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 927 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 934 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 941 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 945 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 952 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 956 "src/grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 960 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 961 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 962 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 964 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 972 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 978 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 984 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 993 "src/grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 999 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1012 "src/grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1019 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1023 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1030 "src/grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1036 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1044 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1052 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1059 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1069 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1073 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1077 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1082 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1090 "src/grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1098 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1100 "src/grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1108 "src/grammar.yy"
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

  case 128:

/* Line 690 of lalr1.cc  */
#line 1152 "src/grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1158 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1163 "src/grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1171 "src/grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1172 "src/grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1177 "src/grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1183 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1190 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1191 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1196 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1200 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1205 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1212 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1214 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1219 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1224 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1229 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1234 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1239 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1244 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1249 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1254 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1261 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1263 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1267 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1271 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1277 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1279 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1283 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1289 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1291 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1295 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1299 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1305 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1307 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1311 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1315 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1319 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1323 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1327 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1333 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1335 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1339 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1343 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1347 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1351 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1357 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1359 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1363 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1367 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1371 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1377 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1379 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1383 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1387 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1391 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1397 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1399 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1405 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1407 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1413 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1415 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1421 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1423 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1429 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1431 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1437 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1439 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1445 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1447 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1453 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1455 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1461 "src/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1463 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1469 "src/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1471 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1477 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1479 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1487 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1489 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1498 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1502 "src/grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1510 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1514 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1520 "src/grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1521 "src/grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1522 "src/grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1523 "src/grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1524 "src/grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1525 "src/grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1526 "src/grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1527 "src/grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1528 "src/grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1529 "src/grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1530 "src/grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1531 "src/grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1536 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1542 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1550 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1556 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1563 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1564 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1568 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1569 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1578 "src/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1579 "src/grammar.yy"
    {(yyval.num) = ';';tracer->SetLineBreakFlag ( false );}
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1580 "src/grammar.yy"
    {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1585 "src/grammar.yy"
    {yyclearin;yyerrok;}
    break;



/* Line 690 of lalr1.cc  */
#line 2710 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -234;
  const short int
  ParserImplementation::yypact_[] =
  {
      -234,    19,   792,  -234,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,  1186,  1186,  1186,   174,    85,    30,    69,    30,   870,
    -234,    39,    73,    18,    79,  -234,  -234,  -234,  1186,  -234,
      92,  -234,  1186,  -234,    32,    69,   111,   128,  -234,   555,
    -234,  -234,  -234,   399,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,    28,  -234,    56,    50,
    -234,  -234,   187,    83,   195,    55,   146,   133,   157,   177,
     179,   121,  -234,  -234,    13,  -234,   218,    30,  -234,    15,
     110,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
      14,    28,  -234,  -234,    20,   228,   948,  -234,  -234,   116,
     230,  -234,  -234,   131,  1098,   192,   193,   870,  1186,   238,
    -234,  1186,   238,   634,    23,   230,  1186,  1186,    18,   127,
     129,  -234,  -234,   713,   134,   242,   135,  -234,  1113,  1186,
     172,  -234,  1186,   175,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  1186,
    1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,  1186,  1186,  1186,  1186,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,    85,  -234,  -234,  -234,  -234,    -8,  1186,  -234,
    -234,    69,    -8,    -8,   206,   178,    22,   195,    64,   158,
     234,   237,   239,   241,   149,  -234,  -234,   258,   145,  -234,
    -234,  -234,    34,    -8,    36,    -8,   216,    32,   196,  -234,
      -8,    48,    49,  -234,  -234,  -234,    15,  1186,  -234,    62,
    -234,    21,  -234,    35,  -234,  -234,  -234,  -234,  -234,   187,
     187,    83,    83,    83,   195,   195,   195,   195,   195,   195,
      55,    55,    55,    55,   146,   133,   157,   177,   151,   179,
    -234,   147,  1023,  -234,  -234,  -234,  -234,  -234,  1186,   154,
      11,   243,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,   197,   197,   870,  -234,   164,  -234,   201,  -234,  -234,
    -234,   870,   870,   165,  -234,  1186,  -234,  -234,  -234,  1186,
    -234,  -234,  -234,    63,  1186,  -234,  -234,   178,  1186,  1186,
      66,    50,  -234,   195,   195,   195,   195,   195,    64,    64,
      64,    64,   158,   234,   237,   239,   166,   241,  -234,   162,
    -234,   279,   176,   180,   220,   233,  -234,   183,  -234,  -234,
    1186,  -234,  -234,  -234,  -234,  -234,   181,    67,   870,  1186,
    1186,   212,   171,   184,   870,  1186,   233,  -234,   -37,    32,
    -234,    -8,  1186,   870,  -234,  -234,   186,  -234,   399,   399,
    -234,    12,  -234,   191,  -234,   233,  -234,  -234,   198,  -234,
     870,   182,   399,   194,   477,   477,   199,   870,  -234,  -234,
    -234,   477,  -234,  -234,  -234,  -234
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  ParserImplementation::yydefact_[] =
  {
         2,     0,   236,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,    18,     0,    18,   236,
      98,     0,    18,   100,     0,    96,    93,    95,   230,    94,
       0,    99,     0,    97,     0,     0,     0,     0,   235,   236,
     234,    15,   121,     3,    12,    14,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    31,    30,    32,    33,
     101,    91,    92,   120,   102,   103,   125,   135,   136,   137,
     140,   150,   154,   157,   161,   174,   184,   188,   192,   196,
     200,   204,   208,   224,   236,    50,     0,    18,   100,   113,
     137,   146,   147,   149,   148,   141,   142,   143,   145,   144,
       0,   125,   126,   110,     0,   233,     0,    19,    63,    85,
      40,    42,    61,     0,   228,     0,     0,   236,     0,   231,
      65,     0,    76,   236,     0,    38,     0,     0,   100,    93,
      94,    34,    36,   236,     0,   114,     0,    13,     0,     0,
       0,   127,     0,     0,   128,   220,   217,   219,   218,   223,
     222,   213,   215,   214,   221,   216,   139,   138,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,   237,   117,   119,   118,
     104,   124,   232,   106,   111,   105,   108,   236,     0,    86,
      46,     0,   236,   236,     0,     0,   137,   168,   179,   186,
     190,   194,   198,   202,   206,   210,   226,   229,     0,     4,
       6,    75,     0,   236,     0,   236,     0,     0,    78,    79,
     236,     0,     0,    35,    37,   112,     0,     0,   131,     0,
     133,     0,   123,     0,   130,   209,   151,   152,   153,   155,
     156,   160,   159,   158,   163,   162,   166,   167,   164,   165,
     178,   176,   175,   177,   185,   189,   193,   197,     0,   201,
     225,     0,     0,    64,    48,    43,    41,    62,     0,    87,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,    16,    16,   236,    66,     0,    77,     0,    82,    80,
      39,   236,   236,     0,   115,     0,   132,   122,   129,     0,
     238,   107,   109,     0,     0,    88,    47,     0,   230,     0,
       0,   137,   211,   170,   169,   173,   171,   172,   183,   181,
     180,   182,   187,   191,   195,   199,     0,   203,   227,     0,
       8,    17,     0,     0,    53,    89,    68,     0,    56,    67,
       0,   134,   205,    54,    49,    45,     0,     0,   236,     0,
     230,     0,     0,     0,   236,     0,    90,    71,     0,     0,
     116,   236,   230,   236,    59,   207,     0,     9,    10,    10,
      52,     0,    72,     0,    69,    89,    81,    55,     0,    60,
     236,     0,    11,     0,    83,    83,     0,   236,    57,     5,
       7,    84,    73,    74,    70,    58
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,   -81,   308,
     -39,    38,   106,   -19,   -33,  -233,  -234,  -234,  -234,   276,
    -234,   112,   -13,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
     -61,  -234,  -234,  -234,  -234,  -234,  -234,    88,   -88,  -234,
    -234,   -58,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,   102,   325,   327,  -234,   -28,  -234,    37,  -234,
       1,    29,    70,   132,     9,  -101,   167,    51,   163,    53,
     168,    57,   169,    47,   170,    58,  -234,  -234,  -234,  -234,
     -85,  -212,   282,   -10,  -234,  -234,  -228,   185,   -82,  -234,
    -234
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    41,   301,    42,   302,   351,   401,   402,
      44,   352,   116,    45,    46,   133,    47,   230,   202,   110,
     280,   111,   281,   199,   325,    48,    49,    50,    51,   381,
      52,   203,    53,   197,    54,   223,    55,    56,   356,   376,
     377,   395,    57,    58,   225,    59,   228,   229,   412,   200,
     326,   378,    60,    61,    62,    63,    64,   104,   105,    65,
     134,   135,   136,    66,    67,    68,   141,   239,    69,    70,
      71,    72,    73,    74,    75,   208,    76,   209,    77,   210,
      78,   211,    79,   212,    80,   213,    81,   214,    82,   215,
      83,   216,   283,    84,   217,   218,   120,   106,    85,    86,
     271
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -237;
  const short int
  ParserImplementation::yytable_[] =
  {
       113,   124,   185,   100,   137,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   327,   184,   184,   184,   119,     3,
     132,   196,   122,   192,   184,   393,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   184,   184,   184,
     144,    90,    90,    90,    90,    90,    90,    90,    90,    90,
     282,   184,   184,   240,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   315,   184,   156,   157,   184,
     184,   332,   349,   191,   245,   138,   394,   139,   140,   226,
     168,   169,   170,   171,   172,   346,   114,   348,   103,   284,
     285,   286,   187,   287,   227,   156,   157,   268,   221,   270,
     366,   188,    38,   138,   132,   142,   143,   107,   222,    40,
     189,   224,   364,   274,   234,   273,   231,   232,   163,   164,
     276,   277,   108,    38,   112,   190,   118,   404,   328,   241,
      40,   173,   243,   117,   193,   317,   182,   183,   158,   121,
     288,   304,   386,   306,   123,   303,   109,   305,   310,   318,
     115,   206,   314,   178,   398,   156,   157,   385,   126,   311,
     312,   246,   247,   248,   297,   298,   158,   174,   175,   176,
     177,   411,   411,   316,   363,   127,   179,   368,   383,   289,
     290,   291,   292,   260,   261,   262,   263,   322,   338,   339,
     340,   341,   249,   250,   308,   180,   181,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,   186,
      90,    13,    14,    15,   160,   161,   162,   165,   166,   167,
     361,   194,   198,   201,   362,   251,   252,   253,   204,   219,
     220,   184,  -119,    20,  -118,   236,   207,   235,    87,   242,
     237,    88,   244,   278,   293,   279,   294,   295,   296,    25,
      26,   299,   300,   307,   320,    27,   319,   227,   323,    29,
     324,   329,   330,    31,   350,   380,   355,    33,   357,   370,
     360,   369,   371,   388,   354,   374,    89,   372,   375,   387,
     119,   373,   358,   359,   379,   409,   389,   400,   382,   397,
     254,   255,   256,   257,   258,   259,   405,   410,   403,   407,
      43,   125,   414,   275,   365,   392,   309,   413,   119,   367,
     331,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,   331,    90,   331,   406,   313,   101,
     353,   102,   265,   345,   342,   264,   396,   343,   266,   384,
     267,   159,   344,   269,     0,   390,   347,     0,     0,     0,
     119,   331,     0,   137,   399,   391,     0,     0,     0,     0,
       0,     0,   119,     0,     0,     0,     0,   272,     0,     0,
       0,   408,     0,     0,     0,   132,   132,     0,   415,     0,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
    -236,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,     0,     0,     0,   207,   333,   334,   335,   336,
     337,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,     0,     0,     4,     5,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,   207,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    20,     0,
       0,     0,    21,    22,     0,     0,    23,    24,  -236,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
       0,   207,    33,    34,    35,     0,    36,    37,     0,    38,
       0,    39,     4,     5,     0,     0,    40,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      21,    87,     0,     0,    23,    24,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,     0,     0,
      33,    34,    35,     0,    36,    37,     0,    38,     0,    39,
       4,     5,     0,     0,    40,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,    87,
       0,     0,   128,    24,     0,     0,     0,     0,     0,     0,
      25,   129,     0,     0,     0,     0,    27,    28,     0,     0,
     130,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,   131,     4,
       5,     0,    40,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    87,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,     0,     0,    33,    34,    35,
       0,    36,    37,     0,    38,     0,    39,   131,     4,     5,
       0,    40,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    87,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,   233,     4,     5,     0,
      40,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    22,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,     4,     5,     0,     0,    40,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,    20,
       0,     0,     0,    21,    87,     0,     0,    23,    24,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,     0,     0,    33,    34,    35,     0,    36,    37,     0,
      38,     0,    39,     4,     5,     0,     0,    40,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     4,     5,
      89,     0,   195,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    87,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     4,     5,    89,     0,   321,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     4,     5,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
       0,     0,    20,    25,    26,     0,     0,    87,     0,    27,
      88,     0,     0,    29,     0,     0,     0,    31,    25,    26,
       0,    33,     0,   205,    27,     0,     0,     0,    29,     0,
      89,     0,    31,     0,     0,     0,    33,     0,     0,     0,
       0,     4,     5,     0,   238,    89,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      87,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,    89
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    34,    84,    13,    43,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,     3,     3,     3,    28,     0,
      39,   106,    32,     3,     3,    62,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     3,     3,     3,
      68,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      28,     3,     3,   138,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     3,     3,    45,    46,     3,
       3,   283,   300,   101,   159,    47,   113,    49,    50,    56,
      25,    26,    27,    28,    29,   297,    47,   299,     3,    25,
      26,    27,    77,    29,    71,    45,    46,   182,   117,   184,
     328,    86,   110,    47,   123,    49,    50,    77,   118,   117,
      95,   121,   324,   198,   133,   197,   126,   127,    35,    36,
     202,   203,    16,   110,    18,   111,    47,   115,   117,   139,
     117,    76,   142,   115,   114,   114,    15,    16,   116,    47,
      76,   223,   370,   225,   112,   111,    77,   111,   230,   114,
      77,   114,   237,    20,   382,    45,    46,   369,    47,   111,
     111,   160,   161,   162,    15,    16,   116,    21,    22,    23,
      24,   404,   405,   111,   111,    47,    19,   111,   111,    21,
      22,    23,    24,   174,   175,   176,   177,   272,   289,   290,
     291,   292,   163,   164,   227,    18,    17,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     1,
     183,    47,    48,    49,    37,    38,    39,    32,    33,    34,
     315,     3,   116,     3,   319,   165,   166,   167,   107,    47,
      47,     3,   115,    69,   115,     3,   114,   113,    74,    77,
     115,    77,    77,    47,    20,    77,    19,    18,    17,    85,
      86,     3,   117,    47,   117,    91,   115,    71,   278,    95,
     116,    28,   282,    99,    77,   360,   112,   103,    77,   117,
     115,   115,     3,   112,   303,    65,   112,   111,    55,    77,
     300,   111,   311,   312,   111,   113,   112,   111,   117,   381,
     168,   169,   170,   171,   172,   173,   115,   113,   389,   111,
       2,    35,   113,   201,   327,   376,   228,   405,   328,   329,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   395,   236,    14,
     302,    14,   179,   296,   293,   178,   379,   294,   180,   368,
     181,    69,   295,   183,    -1,   374,   298,    -1,    -1,    -1,
     370,   324,    -1,   402,   383,   375,    -1,    -1,    -1,    -1,
      -1,    -1,   382,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,   400,    -1,    -1,    -1,   404,   405,    -1,   407,    -1,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,   324,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    78,     1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      91,    92,    -1,    -1,    95,    -1,    97,    -1,    99,   100,
      -1,   369,   103,   104,   105,    -1,   107,   108,    -1,   110,
      -1,   112,    35,    36,    -1,    -1,   117,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    91,    92,
      -1,    -1,    95,    -1,    97,    -1,    99,   100,    -1,    -1,
     103,   104,   105,    -1,   107,   108,    -1,   110,    -1,   112,
      35,    36,    -1,    -1,   117,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,
     105,    -1,   107,   108,    -1,   110,    -1,   112,   113,    35,
      36,    -1,   117,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,   105,
      -1,   107,   108,    -1,   110,    -1,   112,   113,    35,    36,
      -1,   117,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,
      97,    -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,
     107,   108,    -1,   110,    -1,   112,   113,    35,    36,    -1,
     117,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,   107,
     108,    -1,   110,    -1,   112,    35,    36,    -1,    -1,   117,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    73,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    91,    92,    -1,    -1,    95,    -1,    97,    -1,    99,
     100,    -1,    -1,   103,   104,   105,    -1,   107,   108,    -1,
     110,    -1,   112,    35,    36,    -1,    -1,   117,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
     112,    -1,   114,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,   112,    -1,   114,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    85,    86,    -1,    -1,    74,    -1,    91,
      77,    -1,    -1,    95,    -1,    -1,    -1,    99,    85,    86,
      -1,   103,    -1,   105,    91,    -1,    -1,    -1,    95,    -1,
     112,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    35,    36,    -1,   111,   112,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ParserImplementation::yystos_[] =
  {
         0,   119,   120,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    53,    59,    60,    63,
      69,    73,    74,    77,    78,    85,    86,    91,    92,    95,
      97,    99,   100,   103,   104,   105,   107,   108,   110,   112,
     117,   121,   123,   127,   128,   131,   132,   134,   143,   144,
     145,   146,   148,   150,   152,   154,   155,   160,   161,   163,
     170,   171,   172,   173,   174,   177,   181,   182,   183,   186,
     187,   188,   189,   190,   191,   192,   194,   196,   198,   200,
     202,   204,   206,   208,   211,   216,   217,    74,    77,   112,
     186,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     211,   181,   182,     3,   175,   176,   215,    77,   130,    77,
     137,   139,   130,   131,    47,    77,   130,   115,    47,   211,
     214,    47,   211,   112,   132,   137,    47,    47,    77,    86,
      95,   113,   131,   133,   178,   179,   180,   128,    47,    49,
      50,   184,    49,    50,   184,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    45,    46,   116,   210,
      37,    38,    39,    35,    36,    32,    33,    34,    25,    26,
      27,    28,    29,    76,    21,    22,    23,    24,    20,    19,
      18,    17,    15,    16,     3,   216,     1,    77,    86,    95,
     111,   184,     3,   114,     3,   114,   208,   151,   116,   141,
     167,     3,   136,   149,   107,   105,   186,   191,   193,   195,
     197,   199,   201,   203,   205,   207,   209,   212,   213,    47,
      47,   131,   211,   153,   211,   162,    56,    71,   164,   165,
     135,   211,   211,   113,   131,   113,     3,   115,   111,   185,
     208,   211,    77,   211,    77,   208,   188,   188,   188,   189,
     189,   190,   190,   190,   191,   191,   191,   191,   191,   191,
     192,   192,   192,   192,   194,   196,   198,   200,   208,   202,
     208,   218,   215,   216,   208,   139,   216,   216,    47,    77,
     138,   140,    28,   210,    25,    26,    27,    29,    76,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     117,   122,   124,   111,   216,   111,   216,    47,   132,   165,
     216,   111,   111,   180,   208,     3,   111,   114,   114,   115,
     117,   114,   208,   211,   116,   142,   168,     3,   117,    28,
     211,   186,   209,   191,   191,   191,   191,   191,   193,   193,
     193,   193,   195,   197,   199,   201,   209,   203,   209,   214,
      77,   125,   129,   129,   131,   112,   156,    77,   131,   131,
     115,   208,   208,   111,   209,   140,   214,   211,   111,   115,
     117,     3,   111,   111,    65,    55,   157,   158,   169,   111,
     208,   147,   117,   111,   131,   209,   214,    77,   112,   112,
     131,   211,   158,    62,   113,   159,   132,   216,   214,   131,
     111,   126,   127,   126,   115,   115,   169,   111,   131,   113,
     113,   133,   166,   166,   113,   131
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
     348,    41,   123,   125,    93,    58,    61,    59
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ParserImplementation::yyr1_[] =
  {
         0,   118,   120,   119,   122,   121,   124,   123,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   135,   134,
     136,   134,   137,   137,   138,   138,   139,   140,   141,   142,
     143,   144,   145,   145,   147,   146,   146,   146,   146,   146,
     146,   149,   148,   151,   150,   153,   152,   154,   155,   156,
     156,   157,   157,   158,   159,   160,   162,   161,   163,   163,
     163,   164,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   170,   170,   170,   171,   172,   172,   173,
     173,   173,   173,   173,   173,   174,   174,   174,   175,   175,
     176,   176,   177,   178,   178,   179,   179,   180,   180,   180,
     181,   181,   181,   181,   181,   182,   182,   183,   183,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     189,   189,   189,   189,   190,   190,   190,   191,   191,   191,
     191,   192,   192,   192,   192,   192,   192,   192,   193,   193,
     193,   193,   193,   193,   194,   194,   194,   194,   194,   195,
     195,   195,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   215,   215,   216,   216,   217,   218,   216
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     0,     9,     0,     9,     1,     3,
       0,     1,     1,     2,     1,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     2,     0,     4,
       0,     4,     1,     3,     1,     3,     2,     2,     2,     2,
       1,     2,     7,     5,     0,     8,     5,     9,    10,     7,
       8,     0,     4,     0,     4,     0,     4,     5,     5,     3,
       5,     1,     2,     4,     3,     3,     0,     4,     3,     3,
       4,     5,     2,     0,     1,     0,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     5,     2,     4,
       1,     2,     3,     0,     1,     3,     5,     1,     1,     1,
       1,     1,     4,     3,     3,     1,     2,     2,     2,     4,
       3,     2,     3,     1,     3,     1,     1,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     0,     1,
       0,     1,     0,     1,     1,     1,     0,     0,     4
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
  "JS_TERMINATE", "JS_LINE_BREAK", "')'", "'{'", "'}'", "']'", "':'",
  "'='", "';'", "$accept", "program", "$@1", "function_declaration", "@2",
  "function_expression", "@3", "formal_parameter_list", "function_body",
  "source_elements", "source_element", "formal_parameter_list__opt",
  "identifier__opt", "statement", "block", "statement_list",
  "variable_statement", "$@4", "$@5", "variable_declaration_list",
  "variable_declaration_list_no_in", "variable_declaration",
  "variable_declaration_no_in", "initialiser", "initialiser_no_in",
  "empty_statement", "expression_statement", "if_statement",
  "iteration_statement", "$@6", "continue_statement", "$@7",
  "break_statement", "$@8", "return_statement", "$@9", "with_statement",
  "switch_statement", "case_block", "case_clauses", "case_clause",
  "default_clause", "labelled_statement", "throw_statement", "$@10",
  "try_statement", "catch", "finally", "statement_list__opt",
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
  "$@11", "$@12", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       119,     0,    -1,    -1,   120,   127,    -1,    -1,    74,    77,
      47,   122,   129,   111,   112,   126,   113,    -1,    -1,    74,
     130,    47,   124,   129,   111,   112,   126,   113,    -1,    77,
      -1,   125,     3,    77,    -1,    -1,   127,    -1,   128,    -1,
     127,   128,    -1,   131,    -1,   121,    -1,    -1,   125,    -1,
      -1,    77,    -1,   132,    -1,   134,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   148,    -1,   150,    -1,   152,
      -1,   154,    -1,   160,    -1,   155,    -1,   161,    -1,   163,
      -1,   112,   113,    -1,   112,   133,   113,    -1,   131,    -1,
     133,   131,    -1,    -1,   105,   137,   135,   216,    -1,    -1,
      59,   137,   136,   216,    -1,   139,    -1,   137,     3,   139,
      -1,   140,    -1,   138,     3,   140,    -1,    77,   167,    -1,
      77,   168,    -1,   116,   208,    -1,   116,   209,    -1,   216,
      -1,   211,   216,    -1,    78,    47,   211,   111,   131,    65,
     131,    -1,    78,    47,   211,   111,   131,    -1,    -1,    63,
     131,   107,    47,   211,   111,   147,   216,    -1,   107,    47,
     211,   111,   131,    -1,    73,    47,   213,   117,   214,   117,
     214,   111,   131,    -1,    73,    47,   105,   138,   117,   214,
     117,   214,   111,   131,    -1,    73,    47,   186,    28,   211,
     111,   131,    -1,    73,    47,   105,   140,    28,   211,   111,
     131,    -1,    -1,    60,   130,   149,   216,    -1,    -1,    53,
     130,   151,   216,    -1,    -1,    92,   214,   153,   216,    -1,
     108,    47,   211,   111,   131,    -1,    97,    47,   211,   111,
     156,    -1,   112,   169,   113,    -1,   112,   169,   159,   169,
     113,    -1,   158,    -1,   157,   158,    -1,    55,   211,   115,
     166,    -1,    62,   115,   166,    -1,    77,   115,   131,    -1,
      -1,   100,   211,   162,   216,    -1,   104,   132,   164,    -1,
     104,   132,   165,    -1,   104,   132,   164,   165,    -1,    56,
      47,    77,   111,   132,    -1,    71,   132,    -1,    -1,   133,
      -1,    -1,   141,    -1,    -1,   142,    -1,    -1,   157,    -1,
     171,    -1,   172,    -1,    86,    -1,    95,    -1,    91,    -1,
      85,    -1,   103,    -1,    69,    -1,    99,    -1,    77,    -1,
     170,    -1,   174,    -1,   177,    -1,    47,   211,   111,    -1,
      49,   215,   114,    -1,    49,   175,   114,    -1,    49,   175,
       3,   215,   114,    -1,   215,   208,    -1,   175,     3,   215,
     208,    -1,     3,    -1,   176,     3,    -1,   112,   178,   113,
      -1,    -1,   179,    -1,   180,   115,   208,    -1,   179,     3,
     180,   115,   208,    -1,    77,    -1,    95,    -1,    86,    -1,
     173,    -1,   123,    -1,   181,    49,   211,   114,    -1,   181,
      50,    77,    -1,    48,   181,   184,    -1,   181,    -1,    48,
     182,    -1,   181,   184,    -1,   183,   184,    -1,   183,    49,
     211,   114,    -1,   183,    50,    77,    -1,    47,   111,    -1,
      47,   185,   111,    -1,   208,    -1,   185,     3,   208,    -1,
     182,    -1,   183,    -1,   186,    -1,   186,    46,    -1,   186,
      45,    -1,   187,    -1,    42,   188,    -1,    43,   188,    -1,
      44,   188,    -1,    46,   188,    -1,    45,   188,    -1,    35,
     188,    -1,    36,   188,    -1,    41,   188,    -1,    40,   188,
      -1,   188,    -1,   189,    37,   188,    -1,   189,    38,   188,
      -1,   189,    39,   188,    -1,   189,    -1,   190,    35,   189,
      -1,   190,    36,   189,    -1,   190,    -1,   191,    34,   190,
      -1,   191,    33,   190,    -1,   191,    32,   190,    -1,   191,
      -1,   192,    26,   191,    -1,   192,    25,   191,    -1,   192,
      29,   191,    -1,   192,    76,   191,    -1,   192,    27,   191,
      -1,   192,    28,   191,    -1,   191,    -1,   193,    26,   191,
      -1,   193,    25,   191,    -1,   193,    29,   191,    -1,   193,
      76,   191,    -1,   193,    27,   191,    -1,   192,    -1,   194,
      23,   192,    -1,   194,    22,   192,    -1,   194,    24,   192,
      -1,   194,    21,   192,    -1,   193,    -1,   195,    23,   193,
      -1,   195,    22,   193,    -1,   195,    24,   193,    -1,   195,
      21,   193,    -1,   194,    -1,   196,    20,   194,    -1,   195,
      -1,   197,    20,   195,    -1,   196,    -1,   198,    19,   196,
      -1,   197,    -1,   199,    19,   197,    -1,   198,    -1,   200,
      18,   198,    -1,   199,    -1,   201,    18,   199,    -1,   200,
      -1,   202,    17,   200,    -1,   201,    -1,   203,    17,   201,
      -1,   202,    -1,   204,    16,   202,    -1,   203,    -1,   205,
      16,   203,    -1,   204,    -1,   204,    15,   208,   115,   208,
      -1,   205,    -1,   205,    15,   209,   115,   209,    -1,   206,
      -1,   186,   210,   208,    -1,   207,    -1,   186,   210,   209,
      -1,   116,    -1,    10,    -1,    12,    -1,    11,    -1,    14,
      -1,     5,    -1,     7,    -1,     6,    -1,     4,    -1,    13,
      -1,     9,    -1,     8,    -1,   208,    -1,   211,     3,   208,
      -1,   209,    -1,   212,     3,   209,    -1,    -1,   212,    -1,
      -1,   211,    -1,    -1,   176,    -1,   117,    -1,   110,    -1,
      -1,    -1,   217,     1,   218,   117,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    18,    19,    29,    31,
      35,    36,    38,    40,    43,    45,    47,    48,    50,    51,
      53,    55,    57,    59,    61,    63,    65,    67,    69,    71,
      73,    75,    77,    79,    81,    84,    88,    90,    93,    94,
      99,   100,   105,   107,   111,   113,   117,   120,   123,   126,
     129,   131,   134,   142,   148,   149,   158,   164,   174,   185,
     193,   202,   203,   208,   209,   214,   215,   220,   226,   232,
     236,   242,   244,   247,   252,   256,   260,   261,   266,   270,
     274,   279,   285,   288,   289,   291,   292,   294,   295,   297,
     298,   300,   302,   304,   306,   308,   310,   312,   314,   316,
     318,   320,   322,   324,   326,   330,   334,   338,   344,   347,
     352,   354,   357,   361,   362,   364,   368,   374,   376,   378,
     380,   382,   384,   389,   393,   397,   399,   402,   405,   408,
     413,   417,   420,   424,   426,   430,   432,   434,   436,   439,
     442,   444,   447,   450,   453,   456,   459,   462,   465,   468,
     471,   473,   477,   481,   485,   487,   491,   495,   497,   501,
     505,   509,   511,   515,   519,   523,   527,   531,   535,   537,
     541,   545,   549,   553,   557,   559,   563,   567,   571,   575,
     577,   581,   585,   589,   593,   595,   599,   601,   605,   607,
     611,   613,   617,   619,   623,   625,   629,   631,   635,   637,
     641,   643,   647,   649,   653,   655,   661,   663,   669,   671,
     675,   677,   681,   683,   685,   687,   689,   691,   693,   695,
     697,   699,   701,   703,   705,   707,   711,   713,   717,   718,
     720,   721,   723,   724,   726,   728,   730,   731,   732
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   301,   301,   301,   312,   311,   333,   332,   351,   359,
     369,   370,   374,   380,   388,   389,   397,   398,   405,   406,
     413,   418,   423,   428,   433,   438,   443,   448,   453,   458,
     463,   468,   473,   478,   486,   492,   501,   507,   517,   516,
     527,   526,   539,   545,   553,   559,   567,   578,   615,   619,
     623,   627,   636,   645,   656,   656,   665,   674,   685,   697,
     707,   721,   721,   733,   733,   745,   745,   756,   767,   778,
     782,   791,   797,   805,   816,   826,   838,   838,   848,   856,
     864,   876,   886,   896,   897,   901,   902,   906,   907,   911,
     912,   916,   917,   918,   922,   926,   933,   940,   944,   951,
     955,   960,   961,   962,   963,   971,   977,   983,   992,   998,
    1006,  1007,  1011,  1019,  1022,  1029,  1035,  1043,  1051,  1058,
    1068,  1072,  1076,  1081,  1089,  1098,  1099,  1107,  1151,  1157,
    1162,  1171,  1172,  1176,  1182,  1190,  1191,  1195,  1199,  1204,
    1212,  1213,  1218,  1223,  1228,  1233,  1238,  1243,  1248,  1253,
    1261,  1262,  1266,  1270,  1277,  1278,  1282,  1289,  1290,  1294,
    1298,  1305,  1306,  1310,  1314,  1318,  1322,  1326,  1333,  1334,
    1338,  1342,  1346,  1350,  1357,  1358,  1362,  1366,  1370,  1377,
    1378,  1382,  1386,  1390,  1397,  1398,  1405,  1406,  1413,  1414,
    1421,  1422,  1429,  1430,  1437,  1438,  1445,  1446,  1453,  1454,
    1461,  1462,  1469,  1470,  1477,  1478,  1487,  1488,  1497,  1501,
    1509,  1513,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1535,  1541,  1549,  1555,  1563,  1564,
    1568,  1569,  1572,  1574,  1578,  1579,  1580,  1585,  1580
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
      47,   111,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   115,   117,
      26,   116,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   114,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,    18,   113,    41,     2,     2,     2,
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
     102,   103,   104,   105,   106,   107,   108,   109,   110
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 1298;
  const int ParserImplementation::yynnts_ = 101;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 118;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 348;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 3822 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 1588 "src/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}


