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
#line 310 "src/grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 311 "src/grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 321 "src/grammar.yy"
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
#line 329 "src/grammar.yy"
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
#line 342 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kFunction );
    scope->Insert ( (yysemantic_stack_[(3) - (2)].ident) );
    scope = scope->Enter ();
    (yyval.ident) = (yysemantic_stack_[(3) - (2)].ident);
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 349 "src/grammar.yy"
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
#line 361 "src/grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    //scope->Insert ( ident );
    FormalParameter *arg = ManagedHandle::Retain <FormalParameter>();
    arg->Args ( ident );
    (yyval.farg) = arg;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 369 "src/grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 375 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].farg)->Args ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 380 "src/grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    //scope->Insert ( ident );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( ident );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 389 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 390 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 395 "src/grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 401 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 408 "src/grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 410 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 417 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 419 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 425 "src/grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 427 "src/grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 434 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 439 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 444 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 449 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 454 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 459 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 464 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 469 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 474 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 479 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 484 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 489 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 494 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 499 "src/grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 507 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 513 "src/grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 522 "src/grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 528 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 537 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 541 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 547 "src/grammar.yy"
    {
    EXPECT_TERMINATOR;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 551 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(4) - (2)].varsList)->Terminate();
    (yyval.varsList) = (yysemantic_stack_[(4) - (2)].varsList);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 560 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 566 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 574 "src/grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 580 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 588 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 596 "src/grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 605 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    scope->Insert ( ident );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 613 "src/grammar.yy"
    {
    DestructuringAssignment* dsta = ManagedHandle::Retain( new DestructuringAssignment( (yysemantic_stack_[(2) - (1)].ast) ) );
    dsta->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = dsta;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 622 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 623 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 628 "src/grammar.yy"
    { tracer->SetState( ParserTracer::kObjectLiteralEnd ); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 628 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (3)].dsto); }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 634 "src/grammar.yy"
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

  case 57:

/* Line 690 of lalr1.cc  */
#line 644 "src/grammar.yy"
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

  case 58:

/* Line 690 of lalr1.cc  */
#line 656 "src/grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(5) - (5)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( ident );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 666 "src/grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( 0 );
    mem->Right( ident );
    (yysemantic_stack_[(3) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(3) - (1)].dsto);
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 677 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 681 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 685 "src/grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 690 "src/grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 699 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 708 "src/grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 718 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 719 "src/grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(8) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(8) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 728 "src/grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 737 "src/grammar.yy"
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

  case 70:

/* Line 690 of lalr1.cc  */
#line 748 "src/grammar.yy"
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

  case 71:

/* Line 690 of lalr1.cc  */
#line 760 "src/grammar.yy"
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

  case 72:

/* Line 690 of lalr1.cc  */
#line 770 "src/grammar.yy"
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

  case 73:

/* Line 690 of lalr1.cc  */
#line 783 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 784 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 795 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 796 "src/grammar.yy"
    {
    if ( strlen ( (yysemantic_stack_[(4) - (2)].ident) ) > 0 ) {
      scope->InsertLabel ( (yysemantic_stack_[(4) - (2)].ident) );
    }
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 807 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 808 "src/grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yysemantic_stack_[(4) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 819 "src/grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 830 "src/grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 841 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 845 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 854 "src/grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 860 "src/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 868 "src/grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 879 "src/grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 889 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    scope->InsertLabel ( ident );
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 900 "src/grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 901 "src/grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 911 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 919 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 927 "src/grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 939 "src/grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 949 "src/grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 958 "src/grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 959 "src/grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 963 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 964 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 968 "src/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 969 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 973 "src/grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 974 "src/grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 978 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 979 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 981 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 985 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 989 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 996 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1003 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1007 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1014 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1018 "src/grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1022 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1023 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1024 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1026 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1034 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1040 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1046 "src/grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1055 "src/grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1061 "src/grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1074 "src/grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1081 "src/grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1085 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1092 "src/grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1098 "src/grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1106 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1114 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1121 "src/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1131 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1135 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1139 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1144 "src/grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1152 "src/grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1160 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1162 "src/grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1170 "src/grammar.yy"
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

  case 140:

/* Line 690 of lalr1.cc  */
#line 1214 "src/grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
    tracer->SetState( ParserTracer::kCallExpEnd );
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1220 "src/grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1225 "src/grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1233 "src/grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1234 "src/grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1239 "src/grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1245 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1252 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1253 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1258 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1262 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1267 "src/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1274 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1276 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1281 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1286 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1291 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1296 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1301 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1306 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1311 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1316 "src/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1323 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1325 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1329 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1333 "src/grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1339 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1341 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1345 "src/grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1351 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1353 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1357 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1361 "src/grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1367 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1369 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1373 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1377 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1381 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1385 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1389 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1395 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1397 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1401 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1405 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1409 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1413 "src/grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1419 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1421 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1425 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1429 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1433 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1439 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1441 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1445 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1449 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1453 "src/grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1459 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1461 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1467 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1469 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1475 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1477 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1483 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1485 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1491 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1493 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1499 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1501 "src/grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1507 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1509 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1515 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1517 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1523 "src/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1525 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1531 "src/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1533 "src/grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1539 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1541 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1549 "src/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1551 "src/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1560 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1564 "src/grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1573 "src/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1577 "src/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1585 "src/grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1586 "src/grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1587 "src/grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1588 "src/grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1589 "src/grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1590 "src/grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1591 "src/grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1592 "src/grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1593 "src/grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1594 "src/grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1595 "src/grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1596 "src/grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1601 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1607 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1615 "src/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1621 "src/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1628 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1629 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1633 "src/grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1634 "src/grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1638 "src/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1639 "src/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1643 "src/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1644 "src/grammar.yy"
    {(yyval.num) = ';';tracer->SetLineBreakFlag ( false );}
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1645 "src/grammar.yy"
    {
    tracer->SetSemicolonFlag ( true );
    if ( yychar != 0 ) {
      tracer->SetRollBackFlag ( true );
    }
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1650 "src/grammar.yy"
    {yyclearin;yyerrok;}
    break;



/* Line 690 of lalr1.cc  */
#line 2854 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -238;
  const short int
  ParserImplementation::yypact_[] =
  {
      -238,    19,   861,  -238,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,   259,    69,    -8,    22,    -8,   939,
    -238,    -6,    71,   -29,   112,  -238,  -238,  -238,  1105,  -238,
     115,  -238,  1105,  -238,   141,    22,   127,   130,  -238,   624,
    -238,  -238,  -238,   375,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,    51,  -238,    63,    50,
    -238,  -238,    43,   -22,    96,   222,    53,    58,   162,   238,
     246,   225,  -238,  -238,    28,  -238,   273,    -8,  -238,    72,
     199,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
      15,    51,  -238,  -238,     5,   272,   531,  -238,  -238,   168,
    -238,   274,  -238,   168,  -238,  -238,  -238,   177,  1017,   239,
     240,   939,  1105,   282,  -238,  1105,   282,   703,    32,   274,
    1105,  1105,   174,   181,   182,  -238,  -238,   782,   179,   288,
     183,  -238,  1032,  1105,   223,  -238,  1105,   224,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  1105,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,    69,  -238,  -238,  -238,
    -238,  -104,  1105,  -238,  -238,   166,    22,  -104,  -238,  -104,
     258,    48,    38,    96,   253,   133,   314,   316,   319,   324,
     243,  -238,  -238,   339,   230,  -238,  -238,  -238,    29,  -104,
      31,  -104,   296,   141,   276,  -238,  -104,    34,    35,  -238,
    -238,  -238,    72,  1105,  -238,    36,  -238,     6,  -238,     7,
    -238,  -238,  -238,  -238,  -238,    43,    43,   -22,   -22,   -22,
      96,    96,    96,    96,    96,    96,   222,   222,   222,   222,
      53,    58,   162,   238,   234,   246,  -238,   233,   546,  -238,
    -238,   237,     8,   242,  -238,  -238,  -238,  1105,   244,     1,
     325,   244,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,    60,    60,   939,  -238,   245,  -238,   275,  -238,  -238,
    -238,   939,   939,   247,  -238,  1105,  -238,  -238,  -238,  1105,
    -238,  -238,  -238,   178,  -238,   283,    62,  1105,  -238,  -238,
      48,  1105,  1105,  -238,    64,    50,  -238,    96,    96,    96,
      96,    96,   253,   253,   253,   253,   133,   314,   316,   319,
     249,   324,  -238,   248,  -238,   362,   255,  -238,   257,   304,
     317,  -238,   263,  -238,  -238,  1105,  -238,  -238,   237,   261,
    -238,  -238,  -238,  -238,   262,    65,   939,  1105,  1105,    66,
     267,   268,   939,  1105,   317,  -238,   -26,   141,  -238,   307,
    -104,  1105,   939,  -238,  -238,   277,  -238,  -238,   375,   375,
    -238,     2,  -238,   271,  -238,   317,  -238,  -238,  -238,   278,
    -238,   939,   281,   375,   284,   453,   453,   285,   939,  -238,
    -238,  -238,   453,  -238,  -238,  -238,  -238
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  ParserImplementation::yydefact_[] =
  {
         2,     0,   248,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,    20,     0,    20,   248,
     110,     0,    20,   112,     0,   108,   105,   107,   242,   106,
       0,   111,     0,   109,     0,     0,     0,     0,   247,   248,
     246,    17,   133,     3,    14,    16,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    33,    32,    34,    35,
     113,   103,   104,   132,   114,   115,   137,   147,   148,   149,
     152,   162,   166,   169,   173,   186,   196,   200,   204,   208,
     212,   216,   220,   236,   248,    62,     0,    20,   112,   125,
     149,   158,   159,   161,   160,   153,   154,   155,   157,   156,
       0,   137,   138,   122,     0,   245,     0,    21,    75,    97,
      54,    42,    44,     0,    53,    52,    73,     0,   240,     0,
       0,   248,     0,   243,    77,     0,    88,   248,     0,    40,
       0,     0,   112,   105,   106,    36,    38,   248,     0,   126,
       0,    15,     0,     0,     0,   139,     0,     0,   140,   232,
     229,   231,   230,   235,   234,   225,   227,   226,   233,   228,
     151,   150,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
     249,   129,   131,   130,   116,   136,   244,   118,   123,   117,
     120,   248,     0,    98,    48,     0,     0,   248,    49,   248,
       0,     0,   149,   180,   191,   198,   202,   206,   210,   214,
     218,   222,   238,   241,     0,     4,     6,    87,     0,   248,
       0,   248,     0,     0,    90,    91,   248,     0,     0,    37,
      39,   124,     0,     0,   143,     0,   145,     0,   135,     0,
     142,   221,   163,   164,   165,   167,   168,   172,   171,   170,
     175,   174,   178,   179,   176,   177,   190,   188,   187,   189,
     197,   201,   205,   209,     0,   213,   237,     0,     0,    76,
      60,    56,     0,     0,    45,    43,    74,     0,    99,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,    18,    18,   248,    78,     0,    89,     0,    94,    92,
      41,   248,   248,     0,   127,     0,   144,   134,   141,     0,
     250,   119,   121,     0,    55,     0,     0,     0,   100,    50,
       0,   242,     0,    51,     0,   149,   223,   182,   181,   185,
     183,   184,   195,   193,   192,   194,   199,   203,   207,   211,
       0,   215,   239,     0,     8,    19,     0,     9,     0,    65,
     101,    80,     0,    68,    79,     0,   146,   217,    59,     0,
      57,    66,    61,    47,     0,     0,   248,     0,   242,     0,
       0,     0,   248,     0,   102,    83,     0,     0,   128,     0,
     248,   242,   248,    71,   219,     0,    11,    10,    12,    12,
      64,     0,    84,     0,    81,   101,    93,    58,    67,     0,
      72,   248,     0,    13,     0,    95,    95,     0,   248,    69,
       5,     7,    96,    85,    86,    82,    70
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   -23,   393,
     -42,    84,    89,   -19,   -27,  -156,  -238,  -238,  -238,   364,
    -238,   194,    61,  -132,  -238,  -238,  -238,   290,   113,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,    14,  -238,  -238,  -238,  -238,  -238,
    -238,   180,   -14,  -238,  -238,    10,  -238,  -238,  -238,  -238,
      -2,  -238,  -238,  -238,  -238,  -238,  -202,   412,   413,  -238,
     -15,  -238,    18,  -238,   227,   104,     0,   -83,    49,   -34,
     250,   126,   254,   129,   252,   125,   256,   134,   260,   123,
    -238,  -238,  -238,  -238,   -36,   -47,   370,   -11,  -238,  -238,
    -237,   266,   -68,  -238,  -238
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    41,   311,    42,   312,   365,   422,   423,
      44,   366,   120,    45,    46,   137,    47,   236,   207,   111,
     289,   112,   290,   113,   114,   205,   282,   203,   338,    48,
      49,    50,    51,   400,    52,   209,    53,   201,    54,   229,
      55,    56,   371,   394,   395,   415,    57,    58,   231,    59,
     234,   235,   433,   204,   339,   396,    60,    61,    62,    63,
      64,   104,   105,    65,   138,   139,   140,    66,    67,    68,
     145,   245,    69,    70,    71,    72,    73,    74,    75,   214,
      76,   215,    77,   216,    78,   217,    79,   218,    80,   219,
      81,   220,    82,   221,    83,   222,   293,    84,   223,   224,
     124,   106,    85,    86,   277
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -249;
  const short int
  ParserImplementation::yytable_[] =
  {
       117,   141,   100,   283,   340,   188,    38,   128,   196,   188,
     188,   333,    40,   167,   168,   115,   189,   123,   188,     3,
     136,   126,    90,    90,    90,    90,    90,    90,    90,    90,
      90,   188,   188,   115,   188,   213,   413,   188,   188,   325,
     323,   118,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   188,   292,   188,   188,   107,
     200,    15,   103,   363,   178,   179,   180,   181,   182,   291,
     164,   165,   166,   160,   161,   121,   195,   414,   232,   260,
     261,   262,   263,   264,   265,   160,   161,    15,   142,   109,
     143,   144,   227,   233,   384,   108,   246,   116,   136,    15,
     142,   228,   146,   147,   230,    15,   425,   341,   240,   237,
     238,   334,   197,   327,   328,   288,   194,   251,   169,   170,
     171,   379,   247,   279,   110,   249,   212,   364,    38,   285,
     313,   286,   315,   406,    40,   321,   322,   326,   119,   191,
     274,   405,   276,   162,   299,   300,   301,   302,   192,   122,
     110,   314,   125,   316,   419,   162,   280,   193,   320,   257,
     258,   259,   110,   381,   130,   386,   402,   131,   110,   367,
     367,   183,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,   115,    90,   318,   324,   291,   115,
     213,   347,   348,   349,   350,   351,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   266,   267,   268,
     269,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     186,   187,   332,   281,   160,   161,   346,   172,   173,   174,
     175,   176,   192,   127,   213,   378,   184,   407,   307,   308,
     360,   193,   362,   185,   192,   352,   353,   354,   355,   432,
     432,   255,   256,   193,   190,   198,   336,   206,   294,   295,
     296,   344,   297,   202,   210,   188,   225,   226,   121,   376,
     382,   242,   241,   377,   369,  -131,  -130,   243,   177,   123,
     248,   250,   373,   374,   213,   287,    13,    14,    15,   115,
     115,   345,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,   345,    90,   345,    20,   298,
     123,   385,   418,    87,   303,   304,    88,   305,   115,   398,
     404,   306,   309,   317,    25,    26,   310,   233,   329,   330,
      27,  -129,   372,   342,    29,   345,   335,   370,    31,   337,
     380,   375,    33,   387,   388,   389,   390,   403,   391,   392,
     416,    89,   393,   410,   397,   399,  -248,   123,   401,   408,
     409,   141,   411,   420,   417,   426,   424,   115,   421,   428,
     123,   252,   253,   254,   430,    43,   368,   431,   435,   129,
     284,   383,   429,   208,   343,   345,   136,   136,   412,   436,
       4,     5,   434,   240,   319,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   427,   101,   102,    16,   356,
     358,   361,   270,   357,    17,    18,   272,   271,    19,   163,
     359,   273,     0,     0,    20,     0,     0,   275,    21,    22,
       0,     0,    23,    24,  -248,     0,     0,     0,     0,     0,
      25,    26,   278,     0,     0,     0,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,     0,     0,    33,    34,
      35,     0,    36,    37,     0,    38,     0,    39,     4,     5,
       0,    40,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    87,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,     4,     5,     0,    40,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     4,     5,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    87,     0,     0,    88,     0,
       0,     0,     0,     0,     0,    20,    25,    26,     0,     0,
      87,     0,    27,    88,     0,     0,    29,     0,     0,     0,
      31,    25,    26,     0,    33,     0,     0,    27,     0,     0,
       0,    29,     0,    89,     0,    31,     0,     0,   199,    33,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     4,
       5,     0,     0,   331,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    87,     0,
       0,   132,    24,     0,     0,     0,     0,     0,     0,    25,
     133,     0,     0,     0,     0,    27,    28,     0,     0,   134,
       0,    30,     0,    31,    32,     0,     0,    33,    34,    35,
       0,    36,    37,     0,    38,     0,    39,   135,     4,     5,
      40,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    87,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36,    37,     0,    38,     0,    39,   135,     4,     5,    40,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,    87,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,     0,     0,    33,    34,    35,     0,    36,
      37,     0,    38,     0,    39,   239,     4,     5,    40,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    21,    22,     0,     0,    23,    24,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,     0,     0,    33,    34,    35,     0,    36,    37,
       0,    38,     0,    39,     4,     5,     0,    40,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    20,     0,
       0,     0,    21,    87,     0,     0,    23,    24,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
       0,     0,    33,    34,    35,     0,    36,    37,     0,    38,
       0,    39,     4,     5,     0,    40,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    87,     0,     0,    88,     0,     0,     0,     0,     0,
       0,    20,    25,    26,     0,     0,    87,     0,    27,    88,
       0,     0,    29,     0,     0,     0,    31,    25,    26,     0,
      33,     0,   211,    27,     0,     0,     0,    29,     0,    89,
       0,    31,     0,     0,     0,    33,     0,     0,     0,     0,
       4,     5,     0,   244,    89,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    87,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,     0,     0,     0,
      29,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    89
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    43,    13,   205,     3,     3,   110,    34,     3,     3,
       3,     3,   116,    35,    36,    17,    84,    28,     3,     0,
      39,    32,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     3,     3,    35,     3,   118,    62,     3,     3,     3,
     242,    47,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    68,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     3,    28,     3,     3,    77,
     106,    49,     3,   310,    21,    22,    23,    24,    20,   211,
      37,    38,    39,    45,    46,   114,   101,   113,    56,   172,
     173,   174,   175,   176,   177,    45,    46,    49,    47,    77,
      49,    50,   121,    71,   341,    16,   142,    18,   127,    49,
      47,   122,    49,    50,   125,    49,   114,   116,   137,   130,
     131,   113,   117,   117,   117,    77,   111,   163,    32,    33,
      34,   333,   143,   201,   112,   146,   118,    77,   110,   207,
     111,   209,   111,    77,   116,   111,   111,   111,    77,    77,
     186,   388,   188,   115,    21,    22,    23,    24,    86,    47,
     112,   229,    47,   231,   401,   115,   202,    95,   236,   169,
     170,   171,   112,   111,    47,   111,   111,    47,   112,   311,
     312,    19,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   206,   187,   233,   243,   340,   211,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   178,   179,   180,
     181,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      15,    16,   278,    77,    45,    46,   293,    25,    26,    27,
      28,    29,    86,   112,   337,    77,    18,   389,    15,    16,
     307,    95,   309,    17,    86,   299,   300,   301,   302,   425,
     426,   167,   168,    95,     1,     3,   287,     3,    25,    26,
      27,   292,    29,   115,   107,     3,    47,    47,   114,   325,
     337,     3,   113,   329,   313,   114,   114,   114,    76,   310,
      77,    77,   321,   322,   387,    47,    47,    48,    49,   311,
     312,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    69,    76,
     341,   342,   400,    74,    20,    19,    77,    18,   340,   375,
     387,    17,     3,    47,    85,    86,   116,    71,   114,   116,
      91,   114,    77,    28,    95,   337,   114,   112,    99,   115,
      77,   114,   103,   114,   116,     3,   111,   386,   111,    65,
     397,   112,    55,   392,   111,   114,     1,   388,   116,   112,
     112,   423,   393,   402,    77,   114,   409,   389,   111,   111,
     401,   164,   165,   166,   113,     2,   312,   113,   113,    35,
     206,   340,   421,   113,   291,   387,   425,   426,   394,   428,
      35,    36,   426,   432,   234,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   415,    14,    14,    53,   303,
     305,   308,   182,   304,    59,    60,   184,   183,    63,    69,
     306,   185,    -1,    -1,    69,    -1,    -1,   187,    73,    74,
      -1,    -1,    77,    78,     1,    -1,    -1,    -1,    -1,    -1,
      85,    86,   196,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,
     105,    -1,   107,   108,    -1,   110,    -1,   112,    35,    36,
      -1,   116,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,
      97,    -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,
     107,   108,    -1,   110,    -1,   112,    35,    36,    -1,   116,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    85,    86,    -1,    -1,
      74,    -1,    91,    77,    -1,    -1,    95,    -1,    -1,    -1,
      99,    85,    86,    -1,   103,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,   112,    -1,    99,    -1,    -1,   117,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    35,
      36,    -1,    -1,   117,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    -1,    99,   100,    -1,    -1,   103,   104,   105,
      -1,   107,   108,    -1,   110,    -1,   112,   113,    35,    36,
     116,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,
      97,    -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,
     107,   108,    -1,   110,    -1,   112,   113,    35,    36,   116,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    -1,    -1,   103,   104,   105,    -1,   107,
     108,    -1,   110,    -1,   112,   113,    35,    36,   116,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,    -1,
      99,   100,    -1,    -1,   103,   104,   105,    -1,   107,   108,
      -1,   110,    -1,   112,    35,    36,    -1,   116,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      91,    92,    -1,    -1,    95,    -1,    97,    -1,    99,   100,
      -1,    -1,   103,   104,   105,    -1,   107,   108,    -1,   110,
      -1,   112,    35,    36,    -1,   116,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    85,    86,    -1,    -1,    74,    -1,    91,    77,
      -1,    -1,    95,    -1,    -1,    -1,    99,    85,    86,    -1,
     103,    -1,   105,    91,    -1,    -1,    -1,    95,    -1,   112,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      35,    36,    -1,   111,   112,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112
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
     116,   121,   123,   127,   128,   131,   132,   134,   147,   148,
     149,   150,   152,   154,   156,   158,   159,   164,   165,   167,
     174,   175,   176,   177,   178,   181,   185,   186,   187,   190,
     191,   192,   193,   194,   195,   196,   198,   200,   202,   204,
     206,   208,   210,   212,   215,   220,   221,    74,    77,   112,
     190,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     215,   185,   186,     3,   179,   180,   219,    77,   130,    77,
     112,   137,   139,   141,   142,   178,   130,   131,    47,    77,
     130,   114,    47,   215,   218,    47,   215,   112,   132,   137,
      47,    47,    77,    86,    95,   113,   131,   133,   182,   183,
     184,   128,    47,    49,    50,   188,    49,    50,   188,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      45,    46,   115,   214,    37,    38,    39,    35,    36,    32,
      33,    34,    25,    26,    27,    28,    29,    76,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   220,
       1,    77,    86,    95,   111,   188,     3,   117,     3,   117,
     212,   155,   115,   145,   171,   143,     3,   136,   145,   153,
     107,   105,   190,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   216,   217,    47,    47,   131,   215,   157,
     215,   166,    56,    71,   168,   169,   135,   215,   215,   113,
     131,   113,     3,   114,   111,   189,   212,   215,    77,   215,
      77,   212,   192,   192,   192,   193,   193,   194,   194,   194,
     195,   195,   195,   195,   195,   195,   196,   196,   196,   196,
     198,   200,   202,   204,   212,   206,   212,   222,   219,   220,
     212,    77,   144,   184,   139,   220,   220,    47,    77,   138,
     140,   141,    28,   214,    25,    26,    27,    29,    76,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     116,   122,   124,   111,   220,   111,   220,    47,   132,   169,
     220,   111,   111,   184,   212,     3,   111,   117,   117,   114,
     116,   117,   212,     3,   113,   114,   215,   115,   146,   172,
       3,   116,    28,   146,   215,   190,   213,   195,   195,   195,
     195,   195,   197,   197,   197,   197,   199,   201,   203,   205,
     213,   207,   213,   218,    77,   125,   129,   141,   129,   131,
     112,   160,    77,   131,   131,   114,   212,   212,    77,   184,
      77,   111,   213,   140,   218,   215,   111,   114,   116,     3,
     111,   111,    65,    55,   161,   162,   173,   111,   212,   114,
     151,   116,   111,   131,   213,   218,    77,   141,   112,   112,
     131,   215,   162,    62,   113,   163,   132,    77,   220,   218,
     131,   111,   126,   127,   126,   114,   114,   173,   111,   131,
     113,   113,   133,   170,   170,   113,   131
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
     348,    41,   123,   125,    58,    61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ParserImplementation::yyr1_[] =
  {
         0,   118,   120,   119,   122,   121,   124,   123,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   132,   132,   133,   133,
     135,   134,   136,   134,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   143,   142,   144,   144,   144,   144,
     145,   146,   147,   148,   149,   149,   151,   150,   150,   150,
     150,   150,   150,   153,   152,   155,   154,   157,   156,   158,
     159,   160,   160,   161,   161,   162,   163,   164,   166,   165,
     167,   167,   167,   168,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   174,   174,   174,   175,   176,
     176,   177,   177,   177,   177,   177,   177,   178,   178,   178,
     179,   179,   180,   180,   181,   182,   182,   183,   183,   184,
     184,   184,   185,   185,   185,   185,   185,   186,   186,   187,
     187,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   193,   193,   193,   193,   194,   194,   194,   195,
     195,   195,   195,   196,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   197,   197,   197,   198,   198,   198,   198,
     198,   199,   199,   199,   199,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   204,   204,   205,   205,   206,   206,
     207,   207,   208,   208,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   215,   216,   216,
     217,   217,   218,   218,   219,   219,   220,   220,   221,   222,
     220
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     0,     9,     0,     9,     1,     1,
       3,     3,     0,     1,     1,     2,     1,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       0,     4,     0,     4,     1,     3,     1,     3,     2,     2,
       2,     2,     1,     1,     0,     4,     1,     3,     5,     3,
       2,     2,     1,     2,     7,     5,     0,     8,     5,     9,
      10,     7,     8,     0,     4,     0,     4,     0,     4,     5,
       5,     3,     5,     1,     2,     4,     3,     3,     0,     4,
       3,     3,     4,     5,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     5,
       2,     4,     1,     2,     3,     0,     1,     3,     5,     1,
       1,     1,     1,     1,     4,     3,     3,     1,     2,     2,
       2,     4,     3,     2,     3,     1,     3,     1,     1,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     5,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       0,     1,     0,     1,     0,     1,     1,     1,     0,     0,
       4
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
  "JS_TERMINATE", "JS_LINE_BREAK", "')'", "'{'", "'}'", "':'", "'='",
  "';'", "']'", "$accept", "program", "$@1", "function_declaration", "@2",
  "function_expression", "@3", "formal_parameter_list", "function_body",
  "source_elements", "source_element", "formal_parameter_list__opt",
  "identifier__opt", "statement", "block", "statement_list",
  "variable_statement", "$@4", "$@5", "variable_declaration_list",
  "variable_declaration_list_no_in", "variable_declaration",
  "variable_declaration_no_in", "destructuring_assignment_left_hand_side",
  "object_left_hand_side", "$@6", "object_member_left_hand_side_list",
  "initialiser", "initialiser_no_in", "empty_statement",
  "expression_statement", "if_statement", "iteration_statement", "$@7",
  "continue_statement", "$@8", "break_statement", "$@9",
  "return_statement", "$@10", "with_statement", "switch_statement",
  "case_block", "case_clauses", "case_clause", "default_clause",
  "labelled_statement", "throw_statement", "$@11", "try_statement",
  "catch", "finally", "statement_list__opt", "initialiser__opt",
  "initialiser_no_in__opt", "case_clauses__opt", "literal", "null_literal",
  "boolean_literal", "primary_expression", "array_literal", "element_list",
  "elision", "object_literal", "property_name_and_value_list__opt",
  "property_name_and_value_list", "property_name", "member_expression",
  "new_expression", "call_expression", "arguments", "argument_list",
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
       119,     0,    -1,    -1,   120,   127,    -1,    -1,    74,    77,
      47,   122,   129,   111,   112,   126,   113,    -1,    -1,    74,
     130,    47,   124,   129,   111,   112,   126,   113,    -1,    77,
      -1,   141,    -1,   125,     3,   141,    -1,   125,     3,    77,
      -1,    -1,   127,    -1,   128,    -1,   127,   128,    -1,   131,
      -1,   121,    -1,    -1,   125,    -1,    -1,    77,    -1,   132,
      -1,   134,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,   152,    -1,   154,    -1,   156,    -1,   158,    -1,   164,
      -1,   159,    -1,   165,    -1,   167,    -1,   112,   113,    -1,
     112,   133,   113,    -1,   131,    -1,   133,   131,    -1,    -1,
     105,   137,   135,   220,    -1,    -1,    59,   137,   136,   220,
      -1,   139,    -1,   137,     3,   139,    -1,   140,    -1,   138,
       3,   140,    -1,    77,   171,    -1,   141,   145,    -1,    77,
     172,    -1,   141,   146,    -1,   178,    -1,   142,    -1,    -1,
     112,   143,   144,   113,    -1,    77,    -1,   184,   114,    77,
      -1,   144,     3,   184,   114,    77,    -1,   144,     3,    77,
      -1,   115,   212,    -1,   115,   213,    -1,   220,    -1,   215,
     220,    -1,    78,    47,   215,   111,   131,    65,   131,    -1,
      78,    47,   215,   111,   131,    -1,    -1,    63,   131,   107,
      47,   215,   111,   151,   220,    -1,   107,    47,   215,   111,
     131,    -1,    73,    47,   217,   116,   218,   116,   218,   111,
     131,    -1,    73,    47,   105,   138,   116,   218,   116,   218,
     111,   131,    -1,    73,    47,   190,    28,   215,   111,   131,
      -1,    73,    47,   105,   140,    28,   215,   111,   131,    -1,
      -1,    60,   130,   153,   220,    -1,    -1,    53,   130,   155,
     220,    -1,    -1,    92,   218,   157,   220,    -1,   108,    47,
     215,   111,   131,    -1,    97,    47,   215,   111,   160,    -1,
     112,   173,   113,    -1,   112,   173,   163,   173,   113,    -1,
     162,    -1,   161,   162,    -1,    55,   215,   114,   170,    -1,
      62,   114,   170,    -1,    77,   114,   131,    -1,    -1,   100,
     215,   166,   220,    -1,   104,   132,   168,    -1,   104,   132,
     169,    -1,   104,   132,   168,   169,    -1,    56,    47,    77,
     111,   132,    -1,    71,   132,    -1,    -1,   133,    -1,    -1,
     145,    -1,    -1,   146,    -1,    -1,   161,    -1,   175,    -1,
     176,    -1,    86,    -1,    95,    -1,    91,    -1,    85,    -1,
     103,    -1,    69,    -1,    99,    -1,    77,    -1,   174,    -1,
     178,    -1,   181,    -1,    47,   215,   111,    -1,    49,   219,
     117,    -1,    49,   179,   117,    -1,    49,   179,     3,   219,
     117,    -1,   219,   212,    -1,   179,     3,   219,   212,    -1,
       3,    -1,   180,     3,    -1,   112,   182,   113,    -1,    -1,
     183,    -1,   184,   114,   212,    -1,   183,     3,   184,   114,
     212,    -1,    77,    -1,    95,    -1,    86,    -1,   177,    -1,
     123,    -1,   185,    49,   215,   117,    -1,   185,    50,    77,
      -1,    48,   185,   188,    -1,   185,    -1,    48,   186,    -1,
     185,   188,    -1,   187,   188,    -1,   187,    49,   215,   117,
      -1,   187,    50,    77,    -1,    47,   111,    -1,    47,   189,
     111,    -1,   212,    -1,   189,     3,   212,    -1,   186,    -1,
     187,    -1,   190,    -1,   190,    46,    -1,   190,    45,    -1,
     191,    -1,    42,   192,    -1,    43,   192,    -1,    44,   192,
      -1,    46,   192,    -1,    45,   192,    -1,    35,   192,    -1,
      36,   192,    -1,    41,   192,    -1,    40,   192,    -1,   192,
      -1,   193,    37,   192,    -1,   193,    38,   192,    -1,   193,
      39,   192,    -1,   193,    -1,   194,    35,   193,    -1,   194,
      36,   193,    -1,   194,    -1,   195,    34,   194,    -1,   195,
      33,   194,    -1,   195,    32,   194,    -1,   195,    -1,   196,
      26,   195,    -1,   196,    25,   195,    -1,   196,    29,   195,
      -1,   196,    76,   195,    -1,   196,    27,   195,    -1,   196,
      28,   195,    -1,   195,    -1,   197,    26,   195,    -1,   197,
      25,   195,    -1,   197,    29,   195,    -1,   197,    76,   195,
      -1,   197,    27,   195,    -1,   196,    -1,   198,    23,   196,
      -1,   198,    22,   196,    -1,   198,    24,   196,    -1,   198,
      21,   196,    -1,   197,    -1,   199,    23,   197,    -1,   199,
      22,   197,    -1,   199,    24,   197,    -1,   199,    21,   197,
      -1,   198,    -1,   200,    20,   198,    -1,   199,    -1,   201,
      20,   199,    -1,   200,    -1,   202,    19,   200,    -1,   201,
      -1,   203,    19,   201,    -1,   202,    -1,   204,    18,   202,
      -1,   203,    -1,   205,    18,   203,    -1,   204,    -1,   206,
      17,   204,    -1,   205,    -1,   207,    17,   205,    -1,   206,
      -1,   208,    16,   206,    -1,   207,    -1,   209,    16,   207,
      -1,   208,    -1,   208,    15,   212,   114,   212,    -1,   209,
      -1,   209,    15,   213,   114,   213,    -1,   210,    -1,   190,
     214,   212,    -1,   211,    -1,   190,   214,   213,    -1,   115,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   212,    -1,   215,     3,   212,    -1,   213,
      -1,   216,     3,   213,    -1,    -1,   216,    -1,    -1,   215,
      -1,    -1,   180,    -1,   116,    -1,   110,    -1,    -1,    -1,
     221,     1,   222,   116,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    18,    19,    29,    31,
      33,    37,    41,    42,    44,    46,    49,    51,    53,    54,
      56,    57,    59,    61,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    81,    83,    85,    87,    90,    94,    96,
      99,   100,   105,   106,   111,   113,   117,   119,   123,   126,
     129,   132,   135,   137,   139,   140,   145,   147,   151,   157,
     161,   164,   167,   169,   172,   180,   186,   187,   196,   202,
     212,   223,   231,   240,   241,   246,   247,   252,   253,   258,
     264,   270,   274,   280,   282,   285,   290,   294,   298,   299,
     304,   308,   312,   317,   323,   326,   327,   329,   330,   332,
     333,   335,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   354,   356,   358,   360,   362,   364,   368,   372,   376,
     382,   385,   390,   392,   395,   399,   400,   402,   406,   412,
     414,   416,   418,   420,   422,   427,   431,   435,   437,   440,
     443,   446,   451,   455,   458,   462,   464,   468,   470,   472,
     474,   477,   480,   482,   485,   488,   491,   494,   497,   500,
     503,   506,   509,   511,   515,   519,   523,   525,   529,   533,
     535,   539,   543,   547,   549,   553,   557,   561,   565,   569,
     573,   575,   579,   583,   587,   591,   595,   597,   601,   605,
     609,   613,   615,   619,   623,   627,   631,   633,   637,   639,
     643,   645,   649,   651,   655,   657,   661,   663,   667,   669,
     673,   675,   679,   681,   685,   687,   691,   693,   699,   701,
     707,   709,   713,   715,   719,   721,   723,   725,   727,   729,
     731,   733,   735,   737,   739,   741,   743,   745,   749,   751,
     755,   756,   758,   759,   761,   762,   764,   766,   768,   769,
     770
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   310,   310,   310,   321,   320,   342,   341,   360,   368,
     374,   379,   389,   390,   394,   400,   408,   409,   417,   418,
     425,   426,   433,   438,   443,   448,   453,   458,   463,   468,
     473,   478,   483,   488,   493,   498,   506,   512,   521,   527,
     537,   536,   547,   546,   559,   565,   573,   579,   587,   595,
     604,   612,   622,   623,   628,   628,   633,   643,   655,   665,
     677,   681,   685,   689,   698,   707,   718,   718,   727,   736,
     747,   759,   769,   783,   783,   795,   795,   807,   807,   818,
     829,   840,   844,   853,   859,   867,   878,   888,   900,   900,
     910,   918,   926,   938,   948,   958,   959,   963,   964,   968,
     969,   973,   974,   978,   979,   980,   984,   988,   995,  1002,
    1006,  1013,  1017,  1022,  1023,  1024,  1025,  1033,  1039,  1045,
    1054,  1060,  1068,  1069,  1073,  1081,  1084,  1091,  1097,  1105,
    1113,  1120,  1130,  1134,  1138,  1143,  1151,  1160,  1161,  1169,
    1213,  1219,  1224,  1233,  1234,  1238,  1244,  1252,  1253,  1257,
    1261,  1266,  1274,  1275,  1280,  1285,  1290,  1295,  1300,  1305,
    1310,  1315,  1323,  1324,  1328,  1332,  1339,  1340,  1344,  1351,
    1352,  1356,  1360,  1367,  1368,  1372,  1376,  1380,  1384,  1388,
    1395,  1396,  1400,  1404,  1408,  1412,  1419,  1420,  1424,  1428,
    1432,  1439,  1440,  1444,  1448,  1452,  1459,  1460,  1467,  1468,
    1475,  1476,  1483,  1484,  1491,  1492,  1499,  1500,  1507,  1508,
    1515,  1516,  1523,  1524,  1531,  1532,  1539,  1540,  1549,  1550,
    1559,  1563,  1572,  1576,  1585,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,  1595,  1596,  1600,  1606,  1614,  1620,
    1628,  1629,  1633,  1634,  1638,  1639,  1643,  1644,  1645,  1650,
    1645
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
       2,     2,     2,     2,     2,     2,     2,     2,   114,   116,
      26,   115,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   117,    19,     2,     2,     2,     2,     2,
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
  const int ParserImplementation::yylast_ = 1217;
  const int ParserImplementation::yynnts_ = 105;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 118;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 348;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 3969 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 1653 "src/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
	
  bool isSem = tracer->GetSemicolonFlag ();
  bool isline = tracer->GetLineBreakFlag ();
  
  if ( !isSem && !isline ) {
    tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
  }
}


