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
  

/* Line 293 of lalr1.cc  */
#line 76 "grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 85 "grammar.tab.cc"

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
#line 171 "grammar.tab.cc"

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
  ParserImplementation::ParserImplementation (mocha::Compiler* compiler_yyarg, mocha::ParserConnector* connector_yyarg, mocha::ParserTracer *tracer_yyarg, mocha::AstRoot* ast_root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      compiler (compiler_yyarg),
      connector (connector_yyarg),
      tracer (tracer_yyarg),
      ast_root (ast_root_yyarg)
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
	yychar = yylex (&yylval, connector, yystate);
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
#line 346 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 347 "grammar.yy"
    {
    RootBlock* root = ManagedHandle::Retain( new RootBlock( tracer->GetPath() ) );
    root->Root( (yysemantic_stack_[(2) - (2)].ast_tree) );
    ast_root->Tree ( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 360 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(8) - (2)].info)->getValue() ) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Body ( (yysemantic_stack_[(8) - (7)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 373 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(8) - (2)].info)->getValue() ) );
    fn->Const( true );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Body ( (yysemantic_stack_[(8) - (7)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 385 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( (yysemantic_stack_[(8) - (2)].ident) ) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Body ( (yysemantic_stack_[(8) - (7)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 392 "grammar.yy"
    { (yyval.fn) = (yysemantic_stack_[(1) - (1)].fn); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 406 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(7) - (2)].farg) );
    fn->Body ( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 413 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 419 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(7) - (2)].farg) );
    fn->Body ( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 426 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.fn) = fn;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 432 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Argv ( (yysemantic_stack_[(7) - (2)].farg) );
    fn->Body ( (yysemantic_stack_[(7) - (6)].source_block) );
    (yyval.fn) = fn;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 439 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain ( new Function ( 0 ) );
    fn->Body ( (yysemantic_stack_[(4) - (3)].source_block) );
    (yyval.fn) = fn;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 461 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(2) - (1)].info)->getValue() ) );
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( ident , (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 474 "grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( (yysemantic_stack_[(2) - (1)].dsta) , (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.farg) = arg;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 481 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(4) - (3)].info)->getValue() ) );
    (yysemantic_stack_[(4) - (1)].farg)->Args ( ident , (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.farg) = (yysemantic_stack_[(4) - (1)].farg);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 488 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].farg)->Args ( (yysemantic_stack_[(4) - (3)].dsta) , (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.farg) = (yysemantic_stack_[(4) - (1)].farg);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 494 "grammar.yy"
    {
    Empty* empty = ManagedHandle::Retain<Empty>();
    (yysemantic_stack_[(3) - (1)].farg)->Args ( (yysemantic_stack_[(3) - (3)].ast) , empty );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 507 "grammar.yy"
    {
    FormalParameterRest* rest = ManagedHandle::Retain( new FormalParameterRest( (yysemantic_stack_[(2) - (2)].info)->getValue() ) );
    (yyval.ast) = rest;
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 522 "grammar.yy"
    {
    Spread* spread = ManagedHandle::Retain( new Spread( (yysemantic_stack_[(2) - (2)].info)->getValue() ) );
    (yyval.ast) = spread;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 529 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 530 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 535 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->AddBlock ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 541 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->AddBlock ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 549 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->AddBlock ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 555 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->AddBlock ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 562 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 564 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 571 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 573 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 580 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 582 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 588 "grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 590 "grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 596 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 598 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].module) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 603 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exports) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 611 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 615 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 620 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 625 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].let) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 630 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 635 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 640 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 645 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 650 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 655 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 660 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 665 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 670 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 675 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 680 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 685 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 693 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 699 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 709 "grammar.yy"
    {
    Module* module = ManagedHandle::Retain( new Module( (yysemantic_stack_[(3) - (2)].info)->getValue() ) );
    module->Body( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.module) = module;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 719 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.exports) = exports;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 725 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( (yysemantic_stack_[(2) - (2)].fn) );
    (yyval.exports) = exports;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 735 "grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 741 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 750 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kNormal );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 757 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kConst );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 764 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kLet );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 774 "grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Exp( (yysemantic_stack_[(5) - (3)].args) );
    let->Body( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.let) = let;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 783 "grammar.yy"
    {
    Arguments* arg = ManagedHandle::Retain<Arguments>();
    arg->Value( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = arg;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 789 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 796 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(2) - (1)].info)->getValue() ) );
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , ident , (yysemantic_stack_[(2) - (2)].ast) ) );
    (yyval.ast) = assign;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 802 "grammar.yy"
    {
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , (yysemantic_stack_[(2) - (1)].dsta) , (yysemantic_stack_[(2) - (2)].ast) ) );
    (yyval.ast) = assign;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 810 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 816 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 824 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 830 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 838 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 845 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].dsta)->Data( (yysemantic_stack_[(2) - (1)].dsta) );
    (yysemantic_stack_[(2) - (1)].dsta)->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].dsta);
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 854 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 861 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].dsta)->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].dsta);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 870 "grammar.yy"
    {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( (yysemantic_stack_[(1) - (1)].array) );
    (yyval.dsta) = dsta;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 876 "grammar.yy"
    {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.dsta) = dsta;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 954 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(4) - (2)].dsto); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 960 "grammar.yy"
    {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(1) - (1)].info)->getValue() ) );
    mem->Left( ident );
    mem->Right( ident );
    dsto->List( mem );
    (yyval.dsto) = dsto;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 970 "grammar.yy"
    {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(3) - (1)].property) );
    mem->Right( ident );
    dsto->List( mem );
    (yyval.dsto) = dsto;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 981 "grammar.yy"
    {
    DestructuringObject* dsto = ManagedHandle::Retain<DestructuringObject>();
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    mem->Left( (yysemantic_stack_[(3) - (1)].property) );
    mem->Right( (yysemantic_stack_[(3) - (3)].dsta) );
    dsto->List( mem );
    (yyval.dsto) = dsto;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 991 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(5) - (5)].info)->getValue() ) );
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( ident );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1001 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(3) - (3)].info)->getValue() ) );
    mem->Left( ident );
    mem->Right( ident );
    (yysemantic_stack_[(3) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(3) - (1)].dsto);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1010 "grammar.yy"
    {
    DestructuringObjectMember* mem = ManagedHandle::Retain<DestructuringObjectMember>();
    mem->Left( (yysemantic_stack_[(5) - (3)].property) );
    mem->Right( (yysemantic_stack_[(5) - (5)].dsta) );
    (yysemantic_stack_[(5) - (1)].dsto)->List( mem );
    (yyval.dsto) = (yysemantic_stack_[(5) - (1)].dsto);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1021 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1025 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1029 "grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1043 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(7) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(7) - (5)].source_block) );
    ret->Else ( (yysemantic_stack_[(7) - (7)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1052 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.if_stmt) = ret;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1063 "grammar.yy"
    {
    DoWhile *ret = ManagedHandle::Retain<DoWhile> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(7) - (2)].source_block) );
    ret->Condition ( (yysemantic_stack_[(7) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1072 "grammar.yy"
    {
    While *ret = ManagedHandle::Retain<While> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Condition ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1081 "grammar.yy"
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

  case 95:

/* Line 690 of lalr1.cc  */
#line 1092 "grammar.yy"
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

  case 96:

/* Line 690 of lalr1.cc  */
#line 1104 "grammar.yy"
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

  case 97:

/* Line 690 of lalr1.cc  */
#line 1114 "grammar.yy"
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

  case 98:

/* Line 690 of lalr1.cc  */
#line 1126 "grammar.yy"
    {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( (yysemantic_stack_[(8) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(8) - (4)].ast) );
    ret->Target ( (yysemantic_stack_[(8) - (6)].exp) );
    ret->Body ( (yysemantic_stack_[(8) - (8)].source_block) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1136 "grammar.yy"
    {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( (yysemantic_stack_[(9) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(9) - (5)].ast) );
    ret->Target ( (yysemantic_stack_[(9) - (7)].exp) );
    ret->Body ( (yysemantic_stack_[(9) - (9)].source_block) );
    ret->VariableDecl ( true );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.it) = it;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1149 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1150 "grammar.yy"
    {
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1158 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1159 "grammar.yy"
    {
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1168 "grammar.yy"
    {
    Return *ret = ManagedHandle::Retain<Return> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(3) - (2)].exp) );
    (yysemantic_stack_[(3) - (2)].exp)->Terminate ();
    (yyval.return_stmt) = ret;
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1179 "grammar.yy"
    {
    With *ret = ManagedHandle::Retain<With> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->Body ( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.with_stmt) = ret;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1190 "grammar.yy"
    {
    Switch *ret = ManagedHandle::Retain<Switch> ();
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(5) - (3)].exp) );
    ret->CaseBlock ( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = ret;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1201 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1205 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1214 "grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1220 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1228 "grammar.yy"
    {
    CaseClause *ret = ManagedHandle::Retain<CaseClause> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    ret->Body ( (yysemantic_stack_[(4) - (4)].stmtlist) );
    (yyval.cc) = ret;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1239 "grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1249 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (1)].info)->getValue ();
    Label *ret = ManagedHandle::Retain ( new Label ( ident ) );
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.label_stmt) = ret;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1259 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1260 "grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1270 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1278 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (2)].blk) );
    ret->FinallyBody ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1286 "grammar.yy"
    {
    Try *ret = ManagedHandle::Retain<Try> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(4) - (2)].blk) );
    ret->CatchBody ( (yysemantic_stack_[(4) - (3)].ast) );
    ret->FinallyBody ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = ret;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1298 "grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1308 "grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1317 "grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1318 "grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1322 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1327 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1328 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1337 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1340 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1344 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1348 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1355 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1362 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1366 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1373 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1377 "grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1382 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1383 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1385 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1393 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1399 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1405 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1411 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    (yysemantic_stack_[(4) - (3)].array_cmp)->Exp( (yysemantic_stack_[(4) - (2)].elem) );
    ret->Value ( (yysemantic_stack_[(4) - (3)].array_cmp) );
    (yyval.array) = ret;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1421 "grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1427 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1441 "grammar.yy"
    {
    ArrayComprehensions* comp = ManagedHandle::Retain<ArrayComprehensions>();
    comp->Iteration( (yysemantic_stack_[(2) - (1)].ast) );
    comp->OptIf( (yysemantic_stack_[(2) - (2)].ast) );
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1450 "grammar.yy"
    {
    ForIn *ret = ManagedHandle::Retain<ForIn> ();
    ret->LineNumber ( (yysemantic_stack_[(6) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(6) - (3)].ast) );
    ret->Target ( (yysemantic_stack_[(6) - (5)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.ast) = it;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1459 "grammar.yy"
    {
    ForEach *ret = ManagedHandle::Retain<ForEach> ();
    ret->LineNumber ( (yysemantic_stack_[(7) - (1)].info)->getLineNumber () );
    ret->Item ( (yysemantic_stack_[(7) - (4)].ast) );
    ret->Target ( (yysemantic_stack_[(7) - (6)].exp) );
    Iteration *it = ManagedHandle::Retain( new Iteration ( ret ) );
    (yyval.ast) = it;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1470 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1472 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(4) - (3)].exp) );
    (yyval.ast) = ret;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1482 "grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(4) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1489 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1493 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1500 "grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1506 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1514 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1521 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1527 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1536 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1540 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1544 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(3) - (3)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName *lit = ManagedHandle::Retain ( new PropertyName ( ident ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1557 "grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1564 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1566 "grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1574 "grammar.yy"
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
    }
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1622 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1627 "grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1635 "grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1636 "grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1641 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1647 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1653 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1658 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1665 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1666 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1671 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1675 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1680 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1687 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1689 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1699 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1704 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1709 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1719 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1724 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1729 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1736 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1738 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1742 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1746 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1752 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1754 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1758 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1764 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1766 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1770 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1774 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1780 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1782 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1786 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1790 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1794 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1798 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1802 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1808 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1810 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1814 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1818 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1826 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1832 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1834 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1838 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1842 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1846 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1852 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1854 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1858 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1862 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1866 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1872 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1874 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1880 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1888 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1898 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1906 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1912 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1920 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1922 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1928 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1930 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1936 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1938 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1944 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1946 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1952 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1964 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1973 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1977 "grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1998 "grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1999 "grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2000 "grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2001 "grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2002 "grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2003 "grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2004 "grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2005 "grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2006 "grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2007 "grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2008 "grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2009 "grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2020 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2028 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2034 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2041 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2042 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2046 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2047 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2051 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2052 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2056 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2057 "grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3204 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -348;
  const short int
  ParserImplementation::yypact_[] =
  {
      -348,    67,   824,  -348,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1570,    60,     1,    70,     1,   919,
     202,  -348,    -6,    21,   -42,    57,  -348,  -348,  -348,  1563,
    -348,    76,  -348,  1563,  -348,    22,    85,   121,   134,  -348,
      71,    -2,   200,    28,    80,   524,  -348,  -348,  -348,  -348,
     824,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,    53,  -348,
     147,   198,  -348,  -348,   244,    79,   222,   271,   282,   167,
     233,   241,   245,   177,  -348,  -348,    10,  -348,     1,  -348,
      20,   228,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,    12,    53,  -348,  -348,     5,   268,  1109,  -348,  -348,
     -22,   180,    11,  -348,   152,  -348,  -348,  -348,    85,   225,
     236,   247,   152,  -348,   -37,  1383,   289,   300,   314,   919,
    1563,   341,   -37,  1563,   341,   628,    37,    11,  1563,  1563,
     824,  1014,   824,   152,    14,   152,   201,    11,   919,   -42,
     242,   243,  -348,  -348,   726,   246,   394,   266,  -348,  1293,
    1563,   324,  -348,  1563,   325,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  -348,  -348,  -348,  -348,
    -348,  -348,    60,    -5,  -348,   273,   326,  -348,  -348,  -348,
     -37,   200,  1563,  -348,  -348,   274,    18,   275,    85,  -348,
    -348,   -37,   359,   362,   300,  -348,   214,   533,   222,    84,
     297,   390,   392,   396,   401,   231,  -348,  -348,   416,   290,
     368,   200,   200,  -348,    13,  -348,    44,   -37,   376,    22,
     354,  -348,  -348,    45,    46,   296,   298,   824,  -348,  -348,
     299,   303,   301,  -348,    23,   211,  -348,   152,    47,  -348,
     152,  -348,  -348,  -348,  -348,   302,    20,  1563,   349,  -348,
    -348,    48,  -348,    35,  -348,    36,  -348,  -348,  -348,  -348,
    -348,   244,   244,    79,    79,    79,   222,   222,   222,   222,
     222,   222,   271,   271,   271,   271,   282,   167,   233,   241,
     305,   245,  -348,  1201,  1570,   386,  -348,   387,  -348,  -348,
     436,   312,  -348,   206,   311,   216,  -348,  -348,  1563,   308,
      24,   417,   308,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,   214,   419,   321,   322,   919,   323,  -348,   375,
    -348,  -348,   919,   919,  -348,  -348,  -348,  -348,   152,   378,
    -348,   152,    72,   329,  -348,   201,   919,  -348,  -348,   330,
    -348,  -348,  1473,  -348,  -348,  -348,  1563,  -348,  -348,   434,
    1570,  1563,   336,   274,   334,  -348,  -348,  -348,    49,  1563,
    -348,  -348,   214,  1563,  1563,  -348,    50,   198,  -348,   222,
     222,   222,   222,   222,    84,    84,    84,    84,   297,   390,
     392,   396,   338,   401,  -348,   344,   445,  1563,   348,   350,
     413,   427,  -348,   358,  -348,  -348,  -348,  -348,  -348,  1014,
     824,   824,  -348,  -348,  1563,  -348,  -348,  -348,  1563,   459,
      52,   824,   217,   -37,  -348,  -348,   356,    55,   919,  1563,
    1563,  1563,    56,   824,   824,   919,  1563,   427,  -348,   -34,
      22,   363,   364,   365,  -348,    58,  1563,  -348,   366,  -348,
    -348,  -348,  1563,   919,  -348,  -348,   371,    61,   919,   370,
     372,  -348,     2,  -348,   360,  -348,   427,  -348,  -348,  -348,
    -348,  -348,    63,  -348,   377,  -348,   919,   919,  -348,  -348,
    -348,   919,   919,   373,  -348,   919,  -348,  -348,   919,  -348,
    -348,  -348,  -348
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,    33,     0,    33,     0,
       0,   136,     0,    33,   138,     0,   134,   131,   133,   276,
     132,     0,   137,     0,   135,     0,     0,     0,     0,   281,
       0,     0,     0,     0,     0,     0,   280,    28,   165,     7,
       3,    23,    27,    35,    39,    38,    36,    37,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    51,    50,
      52,    53,   139,   129,   130,   164,   140,   141,   169,   181,
     182,   183,   186,   196,   200,   203,   207,   220,   230,   234,
     238,   242,   246,   250,   254,   270,     0,    88,    33,   138,
     157,   183,   192,   193,   195,   194,   187,   188,   189,   191,
     190,     0,   169,   170,   149,     0,   279,     0,    34,   102,
     123,     0,     0,    69,     0,    78,    77,   100,     0,     0,
       0,     0,   123,    58,     0,   274,     0,     0,     0,     0,
       0,   277,     0,     0,   114,     0,     0,     0,     0,     0,
      21,     0,    21,   123,     0,   123,     0,     0,     0,   138,
     131,   132,    54,    59,     0,     0,   158,     0,    24,     0,
       0,     0,   171,     0,     0,   172,   266,   263,   265,   264,
     269,   268,   259,   261,   260,   267,   262,   185,   184,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,   161,   163,   162,
     142,   168,   278,     0,   144,     0,   154,   150,   143,   147,
       0,    31,     0,   124,    73,    80,     0,     0,     0,    62,
      74,     0,     0,     0,     0,    57,     0,   183,   214,   225,
     232,   236,   240,   244,   248,   252,   256,   272,   275,     0,
       0,    31,    31,   113,     0,   104,     0,     0,     0,     0,
     116,   117,    61,     0,     0,    28,     0,     0,    22,    25,
      35,     0,     0,    14,     0,     0,    15,   123,     0,    65,
       0,    63,    56,    55,    60,     0,     0,     0,     0,   175,
     178,     0,   177,     0,   167,     0,   174,   255,   197,   198,
     199,   201,   202,   206,   205,   204,   209,   208,   212,   213,
     210,   211,   224,   222,   221,   223,   231,   235,   239,   243,
       0,   247,   271,     0,     0,     0,   146,     0,   151,   103,
      32,     0,    86,     0,     0,     0,    70,   101,     0,   125,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,     0,     0,     0,   115,     0,
     120,   118,     0,     0,     9,    26,    13,    11,   123,     0,
      18,   123,     0,     0,    67,     0,     0,    68,   156,     0,
     159,    20,     0,   176,   166,   173,     0,   145,   148,     0,
       0,     0,     0,    84,     0,    79,    81,    82,     0,     0,
     126,    75,     0,   276,     0,    76,     0,   183,   257,   216,
     215,   219,   217,   218,   229,   227,   226,   228,   233,   237,
     241,   245,     0,   249,   273,     0,     0,     0,     0,     0,
      91,   127,   106,     0,    93,   105,    16,    19,    17,     0,
      21,    21,    66,    64,     0,   180,   179,   251,     0,     0,
       0,    21,     0,     0,    87,    72,     0,     0,     0,     0,
     276,     0,     0,    21,    21,     0,     0,   128,   109,     0,
       0,     0,     0,     0,   160,     0,     0,   155,     0,    83,
      85,    92,   276,     0,    96,   253,     0,     0,     0,     0,
       0,    90,     0,   110,     0,   107,   127,   119,    12,     8,
      10,   152,     0,     5,     0,    97,     0,     0,    98,     4,
       6,   121,   121,     0,   153,     0,    94,    99,   122,   111,
     112,   108,    95
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -348,  -348,  -348,   129,  -348,  -348,   450,  -348,   104,  -145,
     507,  -348,   -39,   234,    66,   197,   -19,  -149,  -142,   -29,
    -348,  -348,  -191,  -348,  -348,  -348,   115,    54,  -348,     3,
    -328,    29,  -348,  -348,  -120,   162,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,    30,
    -348,  -348,  -348,  -348,  -348,  -348,   248,   -17,  -143,  -348,
      32,  -348,  -348,  -348,  -348,    26,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -101,   535,   536,  -348,   -20,  -348,
      25,  -348,    77,   178,   111,   166,   144,    -7,   342,   188,
     343,   189,   345,   191,   346,   195,   361,   186,  -348,  -348,
    -348,  -348,   -44,  -314,   482,   -11,  -348,  -348,  -347,   352,
     -77
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   275,    48,    49,   340,   390,   300,   276,
     277,   278,    51,   279,   341,   138,    52,    53,    54,    55,
      56,    57,   164,    58,    59,   288,   289,   122,   350,   123,
     351,   124,   125,   236,   233,   420,    60,    61,    62,    63,
      64,   241,    65,   230,    66,    67,    68,   452,   487,   488,
     516,    69,    70,   267,    71,   270,   271,   539,   234,   421,
     489,    72,    73,    74,    75,    76,   115,   116,   225,   226,
     338,    77,   165,   166,   167,    78,    79,    80,   172,   301,
      81,    82,    83,    84,    85,    86,    87,   249,    88,   250,
      89,   251,    90,   252,    91,   253,    92,   254,    93,   255,
      94,   256,    95,   257,   354,    96,   258,   259,   142,   117,
      97
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -164;
  const short int
  ParserImplementation::yytable_[] =
  {
       129,   280,   111,   280,   240,   215,   146,   282,   222,   281,
     283,   168,   286,   215,   238,   215,   215,   284,   141,   216,
     237,   343,   144,   134,   445,   231,   163,   422,   514,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   215,   215,
     428,   135,   334,   126,   446,   239,   126,   215,   215,   215,
     395,   402,   215,   215,   442,   215,   444,   245,   215,   215,
     175,   215,   126,   114,   215,   265,   215,     3,   126,   126,
     272,   155,    15,   229,    39,   156,   476,    15,   223,   118,
     291,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     147,   139,   221,   268,   475,    46,   515,   157,   217,   137,
     169,   388,   170,   171,   140,   474,   132,   218,   269,   355,
     356,   357,   232,   358,   194,   195,   219,   136,   335,    15,
     263,    39,    39,   143,   151,   302,   163,   152,   280,   264,
     285,    47,   266,   506,    15,   531,   224,   273,   274,   292,
     220,   376,    46,    46,   394,   294,   307,   389,   120,   133,
     344,   145,   121,   339,   126,   524,   423,   121,   158,   303,
     247,   359,   305,   132,   347,   505,   404,   405,   148,   330,
     397,   332,   377,   382,   383,   396,   403,   473,   478,    47,
     497,   149,   126,   503,   508,   290,   521,   209,   342,   527,
     378,   534,   213,   214,   169,   399,   173,   174,   459,   121,
     150,   460,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   119,   121,   127,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   168,   101,
     380,   346,   414,   187,   188,   456,   368,   369,   458,    15,
      15,    15,   210,   400,   196,   197,   198,   126,   235,   211,
     155,   130,   212,    15,   126,    15,    15,   218,   308,   309,
     310,   227,   126,   187,   188,   352,   219,   131,   153,   287,
     132,   191,   192,   193,   413,   373,   232,   126,   126,   408,
     155,   155,   349,   218,   416,   499,   199,   200,   201,   202,
     203,   248,   219,   205,   206,   207,   208,   313,   314,   315,
     126,   280,   280,   391,   243,   492,   493,   491,   360,   361,
     362,   363,   280,   392,   393,   244,   498,   374,   375,   121,
     121,   121,   189,   242,   280,   280,   260,   418,   509,   510,
     538,   538,   426,   121,   215,   121,   121,   261,   204,   322,
     323,   324,   325,   434,   435,   436,   437,   450,   466,   409,
     141,   262,   467,   454,   455,   316,   317,   318,   319,   320,
     321,   126,   311,   312,   417,  -163,  -162,   463,   295,   427,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   427,   101,   427,   501,   296,   126,   297,
     470,   352,   304,   306,   336,   337,   348,  -161,   345,   231,
     364,   365,   141,   477,   366,    13,    14,    15,   367,   370,
     494,   126,   371,   379,   290,   269,   -30,   401,   384,   -29,
     386,   387,   398,   410,   411,   469,   482,    21,   406,   284,
     412,   415,   419,    98,   427,   424,    99,   447,   126,   448,
     449,   352,   451,   453,    26,    27,   457,   495,   461,   504,
      28,   517,   468,   464,    30,   471,   511,   472,    32,   141,
     507,   479,    34,   481,   372,   512,   480,   483,   485,   484,
      40,    41,   486,    42,   525,   522,   490,   496,   502,   528,
     518,   141,   154,   532,   519,   520,   523,   100,   126,   526,
     529,   500,   530,   541,   427,   535,   465,   536,   537,    50,
     462,   385,   163,   163,   425,   540,   542,   513,   381,   294,
     248,   429,   430,   431,   432,   433,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   533,   112,
     113,   326,   438,   327,   439,   443,   328,   440,   329,     4,
       5,   353,   441,   190,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   333,   331,     0,    16,   187,   188,
       0,     0,     0,   128,    18,   248,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,    98,
       0,     0,   159,    25,     0,     0,     0,     0,     0,     0,
      26,   160,     0,     0,     0,     0,    28,    29,     0,     0,
     161,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,   248,    43,     0,     0,    44,
       0,     0,     0,    45,   162,     0,    46,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,   189,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   128,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,    98,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    44,     0,     0,     0,    45,   162,     0,
      46,     4,     5,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   128,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,    98,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,   293,     0,    46,     4,
       5,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,    23,
       0,     0,    24,    25,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     4,     5,    46,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   128,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    98,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     4,
       5,    46,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   128,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,     0,    98,
       0,     0,    24,    25,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,   100,     4,     5,    46,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,   100,     0,
     228,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,    98,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
     100,     0,   407,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,   298,     4,     5,
       0,   299,   100,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,   246,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,   100,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,   298,     4,     5,
       0,     0,   100,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,    21,
       0,    99,     0,     0,     0,    98,     0,     0,    99,    26,
      27,     0,     0,     0,     0,    28,    26,    27,     0,    30,
       0,     0,    28,    32,     0,     0,    30,    34,     0,     0,
      32,     0,     0,     0,    34,    40,    41,     0,    42,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,   100
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,   150,    13,   152,   124,     3,    35,   152,     3,   151,
     153,    50,   155,     3,     3,     3,     3,     3,    29,    96,
     121,     3,    33,    20,   371,    47,    45,     3,    62,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
     354,    47,    47,    17,   372,   122,    20,     3,     3,     3,
       3,     3,     3,     3,   368,     3,   370,   134,     3,     3,
      80,     3,    36,     3,     3,   142,     3,     0,    42,    43,
     147,    42,    49,   117,   111,    47,   423,    49,    73,    78,
     157,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      36,   133,   112,    56,   422,   132,   130,    43,    78,    78,
      47,    78,    49,    50,    47,   419,    78,    87,    71,    25,
      26,    27,   134,    29,    35,    36,    96,   123,   123,    49,
     139,   111,   111,    47,   126,   169,   145,   129,   277,   140,
     116,     2,   143,   480,    49,   133,   131,   148,   149,   158,
     128,   128,   132,   132,   287,   164,   190,   124,    78,    20,
     132,   129,   129,   230,   128,   502,   132,   129,    78,   170,
     135,    77,   173,    78,   241,   479,   131,   131,    47,   213,
     290,   215,   128,   128,   128,   128,   128,   128,   128,    50,
     128,    47,   156,   128,   128,   156,   128,    20,   232,   128,
     267,   128,    15,    16,    47,   296,    49,    50,   126,   129,
     129,   129,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,   129,    18,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   277,   214,
     269,   238,   343,    45,    46,   388,    15,    16,   391,    49,
      49,    49,    19,   297,    32,    33,    34,   231,    78,    18,
     231,    59,    17,    49,   238,    49,    49,    87,   191,   192,
     193,     3,   246,    45,    46,   246,    96,    75,    78,    78,
      78,    37,    38,    39,    78,   260,   134,   261,   262,   333,
     261,   262,    78,    87,    78,    78,    25,    26,    27,    28,
      29,   135,    96,    21,    22,    23,    24,   196,   197,   198,
     284,   460,   461,   284,    78,   460,   461,   459,    21,    22,
      23,    24,   471,   112,   113,    78,   471,   261,   262,   129,
     129,   129,   134,   108,   483,   484,    47,   348,   483,   484,
     531,   532,   353,   129,     3,   129,   129,    47,    77,   205,
     206,   207,   208,   360,   361,   362,   363,   376,   402,   334,
     371,    47,   406,   382,   383,   199,   200,   201,   202,   203,
     204,   345,   194,   195,   345,   133,   133,   396,   132,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   473,     3,   372,   133,
     411,   372,    78,    78,   131,    79,    47,   133,   133,    47,
      20,    19,   423,   424,    18,    47,    48,    49,    17,     3,
     464,   395,   132,    47,   395,    71,   130,    78,   130,   130,
     127,   130,   130,    47,    47,   410,   447,    69,   133,     3,
     128,   130,   134,    75,   419,    28,    78,    28,   422,   128,
     128,   422,   129,    78,    86,    87,    78,   468,   129,   478,
      92,   490,    28,   133,    96,   129,   485,   133,   100,   480,
     481,   133,   104,    28,   106,   486,   132,   129,    65,   129,
     112,   113,    55,   115,   503,   496,   128,    28,   132,   508,
     127,   502,    42,   133,   130,   130,   130,   129,   472,   128,
     130,   472,   130,   130,   479,   128,   402,   526,   527,     2,
     395,   277,   531,   532,   352,   532,   535,   487,   270,   538,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   516,    14,
      14,   209,   364,   210,   365,   369,   211,   366,   212,    35,
      36,    28,   367,    81,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   222,   214,    -1,    53,    45,    46,
      -1,    -1,    -1,    59,    60,   419,    -1,    63,    -1,    -1,
      -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,
     106,    -1,   108,   109,    -1,   111,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,   479,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,   130,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,   134,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,
      -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,
      -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,   111,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,   129,   130,    -1,
     132,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,
      -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,
      -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,
     104,   105,   106,    -1,   108,   109,    -1,   111,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,   130,    -1,   132,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,
     106,    -1,   108,   109,    -1,   111,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,    35,    36,   132,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,
     111,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,    35,
      36,   132,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,
     106,    -1,   108,   109,    -1,   111,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    35,    36,   132,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   129,    -1,
     131,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
     129,    -1,   131,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    35,    36,
      -1,   128,   129,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,   129,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    35,    36,
      -1,    -1,   129,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    69,
      -1,    78,    -1,    -1,    -1,    75,    -1,    -1,    78,    86,
      87,    -1,    -1,    -1,    -1,    92,    86,    87,    -1,    96,
      -1,    -1,    92,   100,    -1,    -1,    96,   104,    -1,    -1,
     100,    -1,    -1,    -1,   104,   112,   113,    -1,   115,    -1,
      -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   129
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ParserImplementation::yystos_[] =
  {
         0,   136,   137,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    53,    59,    60,    63,
      67,    69,    73,    75,    78,    79,    86,    87,    92,    93,
      96,    98,   100,   101,   104,   105,   106,   108,   109,   111,
     112,   113,   115,   122,   125,   129,   132,   138,   139,   140,
     145,   147,   151,   152,   153,   154,   155,   156,   158,   159,
     171,   172,   173,   174,   175,   177,   179,   180,   181,   186,
     187,   189,   196,   197,   198,   199,   200,   206,   210,   211,
     212,   215,   216,   217,   218,   219,   220,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   240,   245,    75,    78,
     129,   215,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   240,   210,   211,     3,   201,   202,   244,    78,   150,
      78,   129,   162,   164,   166,   167,   200,   150,    59,   151,
      59,    75,    78,   138,   164,    47,   123,    78,   150,   133,
      47,   240,   243,    47,   240,   129,   154,   162,    47,    47,
     129,   126,   129,    78,   141,   166,    47,   162,    78,    78,
      87,    96,   130,   151,   157,   207,   208,   209,   147,    47,
      49,    50,   213,    49,    50,   213,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   134,
     239,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    77,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   245,    78,    87,    96,
     128,   213,     3,    73,   131,   203,   204,     3,   131,   237,
     178,    47,   134,   169,   193,    78,   168,   209,     3,   245,
     169,   176,   108,    78,    78,   245,   106,   215,   220,   222,
     224,   226,   228,   230,   232,   234,   236,   238,   241,   242,
      47,    47,    47,   151,   240,   245,   240,   188,    56,    71,
     190,   191,   245,   240,   240,   138,   144,   145,   146,   148,
     152,   153,   144,   193,     3,   116,   193,    78,   160,   161,
     166,   245,   151,   130,   151,   132,     3,   133,   124,   128,
     143,   214,   237,   240,    78,   240,    78,   237,   217,   217,
     217,   218,   218,   219,   219,   219,   220,   220,   220,   220,
     220,   220,   221,   221,   221,   221,   223,   225,   227,   229,
     237,   231,   237,   244,    47,   123,   131,    79,   205,   245,
     141,   149,   237,     3,   132,   133,   164,   245,    47,    78,
     163,   165,   166,    28,   239,    25,    26,    27,    29,    77,
      21,    22,    23,    24,    20,    19,    18,    17,    15,    16,
       3,   132,   106,   215,   149,   149,   128,   128,   245,    47,
     154,   191,   128,   128,   130,   148,   127,   130,    78,   124,
     142,   166,   112,   113,   193,     3,   128,   169,   130,   209,
     237,    78,     3,   128,   131,   131,   133,   131,   237,   215,
      47,    47,   128,    78,   209,   130,    78,   166,   240,   134,
     170,   194,     3,   132,    28,   170,   240,   215,   238,   220,
     220,   220,   220,   220,   222,   222,   222,   222,   224,   226,
     228,   230,   238,   232,   238,   243,   165,    28,   128,   128,
     151,   129,   182,    78,   151,   151,   193,    78,   193,   126,
     129,   129,   161,   151,   133,   143,   237,   237,    28,   215,
     240,   129,   133,   128,   238,   165,   243,   240,   128,   133,
     132,    28,   240,   129,   129,    65,    55,   183,   184,   195,
     128,   153,   144,   144,   237,   240,    28,   128,   144,    78,
     166,   245,   132,   128,   151,   238,   243,   240,   128,   144,
     144,   151,   240,   184,    62,   130,   185,   154,   127,   130,
     130,   128,   240,   130,   243,   151,   128,   128,   151,   130,
     130,   133,   133,   195,   128,   128,   151,   151,   157,   192,
     192,   130,   151
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
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,    41,   123,
     125,    93,    59,    58,    61
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ParserImplementation::yyr1_[] =
  {
         0,   135,   137,   136,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   141,   141,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   155,   156,   156,   157,
     157,   158,   158,   158,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   166,   166,   167,
     168,   168,   168,   168,   168,   168,   169,   170,   171,   172,
     173,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     176,   175,   178,   177,   179,   180,   181,   182,   182,   183,
     183,   184,   185,   186,   188,   187,   189,   189,   189,   190,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   196,   196,   196,   197,   198,   198,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   201,   201,   202,
     202,   203,   204,   204,   205,   205,   206,   207,   207,   208,
     208,   209,   209,   209,   210,   210,   210,   210,   210,   211,
     211,   212,   212,   212,   212,   213,   213,   214,   214,   214,
     214,   215,   215,   216,   216,   216,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   218,   218,   218,   218,
     219,   219,   219,   220,   220,   220,   220,   221,   221,   221,
     221,   221,   221,   221,   222,   222,   222,   222,   222,   222,
     223,   223,   223,   223,   223,   224,   224,   224,   224,   224,
     225,   225,   226,   226,   227,   227,   228,   228,   229,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   234,   234,
     235,   235,   236,   236,   237,   237,   238,   238,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     240,   240,   241,   241,   242,   242,   243,   243,   244,   244,
     245,   245
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     8,     8,     8,     1,     7,     4,
       7,     4,     7,     4,     2,     2,     4,     4,     3,     2,
       2,     0,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     3,     2,     1,
       2,     3,     3,     3,     5,     1,     3,     2,     2,     1,
       3,     1,     3,     2,     2,     2,     2,     1,     1,     4,
       1,     3,     3,     5,     3,     5,     2,     2,     1,     2,
       7,     5,     7,     5,     9,    10,     7,     8,     8,     9,
       0,     4,     0,     4,     3,     5,     5,     3,     5,     1,
       2,     4,     3,     3,     0,     4,     3,     3,     4,     5,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     4,     2,     4,     1,
       2,     2,     6,     7,     0,     4,     4,     0,     1,     3,
       5,     1,     1,     1,     1,     1,     4,     3,     3,     1,
       2,     2,     2,     4,     3,     2,     3,     1,     1,     3,
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
       1,     1
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
  "JS_FLOAT", "JS_FOR", "JS_COMP_FOR", "JS_FUNCTION", "JS_GOTO",
  "JS_GRATER_EQUAL", "JS_IDENTIFIER", "JS_IF", "JS_IMPLEMENTS",
  "JS_IMPORT", "JS_INT", "JS_INTERFACE", "JS_LONG", "JS_NATIVE",
  "JS_K_NULL", "JS_NUMERIC_LITERAL", "JS_PRIVATE", "JS_PACKAGE_RESERVED",
  "JS_PROTECTED", "JS_PUBLIC", "JS_REGEXP_LITERAL", "JS_RETURN",
  "JS_SHORT", "JS_STATIC", "JS_STRING_LITERAL", "JS_SUPER", "JS_SWITCH",
  "JS_SYNCHRONIZED", "JS_THIS", "JS_THROW", "JS_THROWS", "JS_TRANSIENT",
  "JS_TRUE", "JS_TRY", "JS_VAR", "JS_VOLATILE", "JS_WHILE", "JS_WITH",
  "JS_TERMINATE", "JS_LINE_BREAK", "JS_FUNCTION_GLYPH",
  "JS_FUNCTION_GLYPH_WITH_CONTEXT", "JS_FUNCTION_IDENTIFIER",
  "JS_PARAM_BEGIN", "JS_PARAM_END", "JS_DSTA_BEGIN", "JS_DSTA_END",
  "JS_DOBJECT_BEGIN", "JS_DOBJECT_END", "JS_FORMAL_PARAMETER_IDENT",
  "JS_LET", "JS_EACH", "JS_PARAMETER_REST", "JS_MODULE",
  "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "')'", "'{'", "'}'", "']'",
  "';'", "':'", "'='", "$accept", "program", "$@1", "function_declaration",
  "function_expression", "arrow_function_expression",
  "formal_parameter_list", "formal_parameter_rest", "arguments_spread",
  "function_body", "source_elements", "source_elements_for_function",
  "source_element", "source_element_for_function",
  "formal_parameter_list__opt", "identifier__opt", "statement",
  "statement_with_block", "statement_no_block", "block", "module_block",
  "export_statement", "statement_list", "variable_statement",
  "let_statement", "let_assignment_list", "let_assignment_expression",
  "variable_declaration_list", "variable_declaration_list_no_in",
  "variable_declaration", "variable_declaration_no_in",
  "destructuring_assignment_left_hand_side", "object_left_hand_side",
  "object_member_left_hand_side_list", "initialiser", "initialiser_no_in",
  "empty_statement", "expression_statement", "if_statement",
  "iteration_statement", "continue_statement", "$@2", "break_statement",
  "$@3", "return_statement", "with_statement", "switch_statement",
  "case_block", "case_clauses", "case_clause", "default_clause",
  "labelled_statement", "throw_statement", "$@4", "try_statement", "catch",
  "finally", "statement_list__opt", "initialiser__opt",
  "initialiser_no_in__opt", "case_clauses__opt", "literal", "null_literal",
  "boolean_literal", "primary_expression", "array_literal", "element_list",
  "elision", "array_comprehensions", "array_comprehension_iteration",
  "array_comprehension_if__opt", "object_literal",
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
  "expression_no_in__opt", "expression__opt", "elision__opt", "terminator", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       136,     0,    -1,    -1,   137,   145,    -1,    75,    78,    47,
     149,   128,   129,   144,   130,    -1,    59,    78,    47,   149,
     128,   129,   144,   130,    -1,    75,   150,    47,   149,   128,
     129,   144,   130,    -1,   140,    -1,   115,   141,   116,   112,
     129,   144,   130,    -1,   112,   129,   144,   130,    -1,   115,
     141,   116,   113,   129,   144,   130,    -1,   113,   129,   144,
     130,    -1,   115,   141,   116,   112,   126,   153,   127,    -1,
     113,   126,   153,   127,    -1,    78,   193,    -1,   166,   193,
      -1,   141,     3,    78,   193,    -1,   141,     3,   166,   193,
      -1,   141,     3,   142,    -1,   124,    78,    -1,   124,    78,
      -1,    -1,   146,    -1,   147,    -1,   145,   147,    -1,   148,
      -1,   145,   148,    -1,   151,    -1,   138,    -1,   152,    -1,
     138,    -1,    -1,   141,    -1,    -1,    78,    -1,   152,    -1,
     155,    -1,   156,    -1,   154,    -1,   153,    -1,   158,    -1,
     159,    -1,   171,    -1,   172,    -1,   173,    -1,   174,    -1,
     175,    -1,   177,    -1,   179,    -1,   180,    -1,   186,    -1,
     181,    -1,   187,    -1,   189,    -1,   129,   130,    -1,   129,
     157,   130,    -1,   125,    78,   151,    -1,    67,   164,   245,
      -1,    67,   138,    -1,   151,    -1,   157,   151,    -1,   106,
     162,   245,    -1,    59,   162,   245,    -1,   122,   162,   245,
      -1,   122,    47,   160,   128,   151,    -1,   161,    -1,   160,
       3,   161,    -1,    78,   193,    -1,   166,   169,    -1,   164,
      -1,   162,     3,   164,    -1,   165,    -1,   163,     3,   165,
      -1,    78,   193,    -1,   166,   169,    -1,    78,   194,    -1,
     166,   170,    -1,   200,    -1,   167,    -1,   129,   168,   132,
     130,    -1,    78,    -1,   209,   133,    78,    -1,   209,   133,
     166,    -1,   168,     3,   209,   133,    78,    -1,   168,     3,
      78,    -1,   168,     3,   209,   133,   166,    -1,   134,   237,
      -1,   134,   238,    -1,   245,    -1,   240,   245,    -1,    79,
      47,   240,   128,   151,    65,   151,    -1,    79,    47,   240,
     128,   151,    -1,    63,   151,   108,    47,   240,   128,   245,
      -1,   108,    47,   240,   128,   151,    -1,    73,    47,   242,
     132,   243,   132,   243,   128,   151,    -1,    73,    47,   106,
     163,   132,   243,   132,   243,   128,   151,    -1,    73,    47,
     215,    28,   240,   128,   151,    -1,    73,    47,   106,   165,
      28,   240,   128,   151,    -1,    73,   123,    47,   215,    28,
     240,   128,   151,    -1,    73,   123,    47,   106,   165,    28,
     240,   128,   151,    -1,    -1,    60,   150,   176,   245,    -1,
      -1,    53,   150,   178,   245,    -1,    93,   243,   245,    -1,
     109,    47,   240,   128,   151,    -1,    98,    47,   240,   128,
     182,    -1,   129,   195,   130,    -1,   129,   195,   185,   195,
     130,    -1,   184,    -1,   183,   184,    -1,    55,   240,   133,
     192,    -1,    62,   133,   192,    -1,    78,   133,   151,    -1,
      -1,   101,   240,   188,   245,    -1,   105,   154,   190,    -1,
     105,   154,   191,    -1,   105,   154,   190,   191,    -1,    56,
      47,    78,   128,   154,    -1,    71,   154,    -1,    -1,   157,
      -1,    -1,   169,    -1,    -1,   170,    -1,    -1,   183,    -1,
     197,    -1,   198,    -1,    87,    -1,    96,    -1,    92,    -1,
      86,    -1,   104,    -1,    69,    -1,   100,    -1,    78,    -1,
     196,    -1,   200,    -1,   206,    -1,    47,   240,   128,    -1,
      49,   244,   131,    -1,    49,   201,   131,    -1,    49,   201,
       3,   244,   131,    -1,    49,   201,   203,   131,    -1,   244,
     237,    -1,   201,     3,   244,   237,    -1,     3,    -1,   202,
       3,    -1,   204,   205,    -1,    73,    47,   215,    28,   240,
     128,    -1,    73,   123,    47,   215,    28,   240,   128,    -1,
      -1,    79,    47,   240,   128,    -1,   129,   207,   132,   130,
      -1,    -1,   208,    -1,   209,   133,   237,    -1,   208,     3,
     209,   133,   237,    -1,    78,    -1,    96,    -1,    87,    -1,
     199,    -1,   139,    -1,   210,    49,   240,   131,    -1,   210,
      50,    78,    -1,    48,   210,   213,    -1,   210,    -1,    48,
     211,    -1,   210,   213,    -1,   212,   213,    -1,   212,    49,
     240,   131,    -1,   212,    50,    78,    -1,    47,   128,    -1,
      47,   214,   128,    -1,   237,    -1,   143,    -1,   214,     3,
     237,    -1,   214,     3,   143,    -1,   211,    -1,   212,    -1,
     215,    -1,   215,    46,    -1,   215,    45,    -1,   216,    -1,
      42,   217,    -1,    43,   217,    -1,    44,   217,    -1,    46,
     217,    -1,    45,   217,    -1,    35,   217,    -1,    36,   217,
      -1,    41,   217,    -1,    40,   217,    -1,   217,    -1,   218,
      37,   217,    -1,   218,    38,   217,    -1,   218,    39,   217,
      -1,   218,    -1,   219,    35,   218,    -1,   219,    36,   218,
      -1,   219,    -1,   220,    34,   219,    -1,   220,    33,   219,
      -1,   220,    32,   219,    -1,   220,    -1,   221,    26,   220,
      -1,   221,    25,   220,    -1,   221,    29,   220,    -1,   221,
      77,   220,    -1,   221,    27,   220,    -1,   221,    28,   220,
      -1,   220,    -1,   222,    26,   220,    -1,   222,    25,   220,
      -1,   222,    29,   220,    -1,   222,    77,   220,    -1,   222,
      27,   220,    -1,   221,    -1,   223,    23,   221,    -1,   223,
      22,   221,    -1,   223,    24,   221,    -1,   223,    21,   221,
      -1,   222,    -1,   224,    23,   222,    -1,   224,    22,   222,
      -1,   224,    24,   222,    -1,   224,    21,   222,    -1,   223,
      -1,   225,    20,   223,    -1,   224,    -1,   226,    20,   224,
      -1,   225,    -1,   227,    19,   225,    -1,   226,    -1,   228,
      19,   226,    -1,   227,    -1,   229,    18,   227,    -1,   228,
      -1,   230,    18,   228,    -1,   229,    -1,   231,    17,   229,
      -1,   230,    -1,   232,    17,   230,    -1,   231,    -1,   233,
      16,   231,    -1,   232,    -1,   234,    16,   232,    -1,   233,
      -1,   233,    15,   237,   133,   237,    -1,   234,    -1,   234,
      15,   238,   133,   238,    -1,   235,    -1,   215,   239,   237,
      -1,   236,    -1,   215,   239,   238,    -1,   134,    -1,    10,
      -1,    12,    -1,    11,    -1,    14,    -1,     5,    -1,     7,
      -1,     6,    -1,     4,    -1,    13,    -1,     9,    -1,     8,
      -1,   237,    -1,   240,     3,   237,    -1,   238,    -1,   241,
       3,   238,    -1,    -1,   241,    -1,    -1,   240,    -1,    -1,
     202,    -1,   132,    -1,   111,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,    16,    25,    34,    36,    44,
      49,    57,    62,    70,    75,    78,    81,    86,    91,    95,
      98,   101,   102,   104,   106,   109,   111,   114,   116,   118,
     120,   122,   123,   125,   126,   128,   130,   132,   134,   136,
     138,   140,   142,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   169,   173,   177,   181,   184,
     186,   189,   193,   197,   201,   207,   209,   213,   216,   219,
     221,   225,   227,   231,   234,   237,   240,   243,   245,   247,
     252,   254,   258,   262,   268,   272,   278,   281,   284,   286,
     289,   297,   303,   311,   317,   327,   338,   346,   355,   364,
     374,   375,   380,   381,   386,   390,   396,   402,   406,   412,
     414,   417,   422,   426,   430,   431,   436,   440,   444,   449,
     455,   458,   459,   461,   462,   464,   465,   467,   468,   470,
     472,   474,   476,   478,   480,   482,   484,   486,   488,   490,
     492,   494,   496,   500,   504,   508,   514,   519,   522,   527,
     529,   532,   535,   542,   550,   551,   556,   561,   562,   564,
     568,   574,   576,   578,   580,   582,   584,   589,   593,   597,
     599,   602,   605,   608,   613,   617,   620,   624,   626,   628,
     632,   636,   638,   640,   642,   645,   648,   650,   653,   656,
     659,   662,   665,   668,   671,   674,   677,   679,   683,   687,
     691,   693,   697,   701,   703,   707,   711,   715,   717,   721,
     725,   729,   733,   737,   741,   743,   747,   751,   755,   759,
     763,   765,   769,   773,   777,   781,   783,   787,   791,   795,
     799,   801,   805,   807,   811,   813,   817,   819,   823,   825,
     829,   831,   835,   837,   841,   843,   847,   849,   853,   855,
     859,   861,   867,   869,   875,   877,   881,   883,   887,   889,
     891,   893,   895,   897,   899,   901,   903,   905,   907,   909,
     911,   913,   917,   919,   923,   924,   926,   927,   929,   930,
     932,   934
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   346,   346,   346,   359,   372,   384,   392,   405,   412,
     418,   425,   431,   438,   460,   473,   480,   487,   493,   506,
     521,   529,   530,   534,   540,   548,   554,   562,   563,   571,
     572,   580,   581,   588,   589,   596,   597,   602,   610,   615,
     619,   624,   629,   634,   639,   644,   649,   654,   659,   664,
     669,   674,   679,   684,   692,   698,   708,   718,   724,   734,
     740,   749,   756,   763,   773,   782,   788,   795,   801,   809,
     815,   823,   829,   837,   844,   853,   860,   869,   875,   954,
     959,   969,   980,   990,  1000,  1009,  1021,  1025,  1029,  1033,
    1042,  1051,  1062,  1071,  1080,  1091,  1103,  1113,  1125,  1135,
    1149,  1149,  1158,  1158,  1167,  1178,  1189,  1200,  1204,  1213,
    1219,  1227,  1238,  1248,  1259,  1259,  1269,  1277,  1285,  1297,
    1307,  1317,  1318,  1322,  1323,  1327,  1328,  1332,  1333,  1337,
    1338,  1339,  1343,  1347,  1354,  1361,  1365,  1372,  1376,  1381,
    1382,  1383,  1384,  1392,  1398,  1404,  1410,  1420,  1426,  1434,
    1435,  1440,  1449,  1458,  1470,  1471,  1481,  1489,  1492,  1499,
    1505,  1513,  1520,  1526,  1535,  1539,  1543,  1548,  1556,  1564,
    1565,  1573,  1616,  1621,  1626,  1635,  1636,  1640,  1646,  1652,
    1657,  1665,  1666,  1670,  1674,  1679,  1687,  1688,  1693,  1698,
    1703,  1708,  1713,  1718,  1723,  1728,  1736,  1737,  1741,  1745,
    1752,  1753,  1757,  1764,  1765,  1769,  1773,  1780,  1781,  1785,
    1789,  1793,  1797,  1801,  1808,  1809,  1813,  1817,  1821,  1825,
    1832,  1833,  1837,  1841,  1845,  1852,  1853,  1857,  1861,  1865,
    1872,  1873,  1880,  1881,  1888,  1889,  1896,  1897,  1904,  1905,
    1912,  1913,  1920,  1921,  1928,  1929,  1936,  1937,  1944,  1945,
    1952,  1953,  1962,  1963,  1972,  1976,  1985,  1989,  1998,  1999,
    2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,
    2013,  2019,  2027,  2033,  2041,  2042,  2046,  2047,  2051,  2052,
    2056,  2057
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
      47,   128,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   133,   132,
      26,   134,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   131,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   129,    18,   130,    41,     2,     2,     2,
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
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 1699;
  const int ParserImplementation::yynnts_ = 111;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 135;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 365;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4492 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2060 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


