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
    {printf( "%s\n" , (yysemantic_stack_[(2) - (1)].info)->getValue() );
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(2) - (1)].info)->getValue() ) );
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( ident , (yysemantic_stack_[(2) - (2)].ast) ) );
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    arg->Args ( set );
    (yyval.farg) = arg;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 475 "grammar.yy"
    {
    FormalParameter *arg = ManagedHandle::Retain<FormalParameter>();
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( (yysemantic_stack_[(2) - (1)].dsta) , (yysemantic_stack_[(2) - (2)].ast) ) );
    arg->Args ( set );
    (yyval.farg) = arg;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 483 "grammar.yy"
    {printf( "%s\n" , (yysemantic_stack_[(4) - (3)].info)->getValue() );
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(4) - (3)].info)->getValue() ) );
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( ident , (yysemantic_stack_[(4) - (4)].ast) ) );
    (yysemantic_stack_[(4) - (1)].farg)->Args ( set );
    (yyval.farg) = (yysemantic_stack_[(4) - (1)].farg);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 491 "grammar.yy"
    {
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( (yysemantic_stack_[(4) - (3)].dsta) , (yysemantic_stack_[(4) - (4)].ast) ) );
    (yysemantic_stack_[(4) - (1)].farg)->Args ( set );
    (yyval.farg) = (yysemantic_stack_[(4) - (1)].farg);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 498 "grammar.yy"
    {
    Empty* empty = ManagedHandle::Retain<Empty>();
    FormalParameterSet* set = ManagedHandle::Retain( new FormalParameterSet( (yysemantic_stack_[(3) - (3)].ast) , empty ) );
    (yysemantic_stack_[(3) - (1)].farg)->Args ( set );
    (yyval.farg) = (yysemantic_stack_[(3) - (1)].farg);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 512 "grammar.yy"
    {
    FormalParameterRest* rest = ManagedHandle::Retain( new FormalParameterRest( (yysemantic_stack_[(2) - (2)].info)->getValue() ) );
    (yyval.ast) = rest;
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 527 "grammar.yy"
    {
    Spread* spread = ManagedHandle::Retain( new Spread( (yysemantic_stack_[(2) - (2)].info)->getValue() ) );
    (yyval.ast) = spread;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 534 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 535 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast_tree); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 540 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->AddBlock ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 546 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->AddBlock ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 554 "grammar.yy"
    {
    AstTree *ret = ManagedHandle::Retain<AstTree> ();
    ret->AddBlock ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.ast_tree) = ret;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 560 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast_tree)->AddBlock ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.ast_tree) = (yysemantic_stack_[(2) - (1)].ast_tree);
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 567 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 569 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 576 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 578 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].fn) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 585 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty> (); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 587 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].farg);
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 593 "grammar.yy"
    { (yyval.ident) = ""; }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 595 "grammar.yy"
    {
    (yyval.ident) = (yysemantic_stack_[(1) - (1)].info)->getValue ();
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 601 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 603 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].module) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 608 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exports) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 616 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].blk) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 620 "grammar.yy"
    { (yyval.source_block) = (yysemantic_stack_[(1) - (1)].source_block); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 625 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].varsList) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 630 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].let) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 635 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].empty) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 640 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].exp_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 645 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].if_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 650 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].it) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 655 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].continue_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 660 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].break_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 665 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].return_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 670 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].with_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 675 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].label_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 680 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].switch_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 685 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].throw_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 690 "grammar.yy"
    { 
    SourceBlock *blocks = ManagedHandle::Retain( new SourceBlock ( (yysemantic_stack_[(1) - (1)].try_stmt) ) );
    (yyval.source_block) = blocks;
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 698 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.blk) = block;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 704 "grammar.yy"
    {
    Block *block = ManagedHandle::Retain<Block> ();
    block->Value ( (yysemantic_stack_[(3) - (2)].stmtlist) );
    (yyval.blk) = block;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 714 "grammar.yy"
    {
    Module* module = ManagedHandle::Retain( new Module( (yysemantic_stack_[(3) - (2)].info)->getValue() ) );
    module->Body( (yysemantic_stack_[(3) - (3)].source_block) );
    (yyval.module) = module;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 724 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( (yysemantic_stack_[(2) - (2)].varsList) );
    (yyval.exports) = exports;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 730 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Value( (yysemantic_stack_[(2) - (2)].fn) );
    (yyval.exports) = exports;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 740 "grammar.yy"
    {
    StmtList *ret = ManagedHandle::Retain<StmtList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].source_block) );
    (yyval.stmtlist) = ret;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 746 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].stmtlist)->List ( (yysemantic_stack_[(2) - (2)].source_block) );
    (yyval.stmtlist) = (yysemantic_stack_[(2) - (1)].stmtlist);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 755 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kNormal );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 762 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kConst );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 769 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].varsList)->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    (yysemantic_stack_[(3) - (2)].varsList)->Terminate();
    (yysemantic_stack_[(3) - (2)].varsList)->Type( VariableDeclarationList::kLet );
    (yyval.varsList) = (yysemantic_stack_[(3) - (2)].varsList);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 779 "grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Exp( (yysemantic_stack_[(5) - (3)].args) );
    let->Body( (yysemantic_stack_[(5) - (5)].source_block) );
    (yyval.let) = let;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 788 "grammar.yy"
    {
    Arguments* arg = ManagedHandle::Retain<Arguments>();
    arg->Value( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = arg;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 794 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 801 "grammar.yy"
    {
    Identifier* ident = ManagedHandle::Retain( new Identifier( (yysemantic_stack_[(2) - (1)].info)->getValue() ) );
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , ident , (yysemantic_stack_[(2) - (2)].ast) ) );
    (yyval.ast) = assign;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 807 "grammar.yy"
    {
    Assign *assign = ManagedHandle::Retain ( new Assign( Constant::kAssign , (yysemantic_stack_[(2) - (1)].dsta) , (yysemantic_stack_[(2) - (2)].ast) ) );
    (yyval.ast) = assign;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 815 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 821 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 829 "grammar.yy"
    {
    VariableDeclarationList *ret = ManagedHandle::Retain<VariableDeclarationList> ();
    ret->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.varsList) = ret;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 835 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].varsList)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.varsList) = (yysemantic_stack_[(3) - (1)].varsList);
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 843 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 850 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].dsta)->Data( (yysemantic_stack_[(2) - (1)].dsta) );
    (yysemantic_stack_[(2) - (1)].dsta)->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].dsta);
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 859 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(2) - (1)].info)->getValue ();
    VariableDeclaration *var = ManagedHandle::Retain ( new VariableDeclaration ( ident ) );
    var->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = var;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 866 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].dsta)->Value( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].dsta);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 875 "grammar.yy"
    {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( (yysemantic_stack_[(1) - (1)].array) );
    (yyval.dsta) = dsta;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 881 "grammar.yy"
    {
    DestructuringAssignment *dsta = ManagedHandle::Retain<DestructuringAssignment>();
    dsta->Data( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.dsta) = dsta;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 959 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].dsto); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 965 "grammar.yy"
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
#line 975 "grammar.yy"
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
#line 986 "grammar.yy"
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
#line 996 "grammar.yy"
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
#line 1006 "grammar.yy"
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
#line 1015 "grammar.yy"
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
#line 1026 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1030 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar.yy"
    { (yyval.empty) = ManagedHandle::Retain<Empty> (); }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1039 "grammar.yy"
    {
    ExpressionStmt *exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->Exp( (yysemantic_stack_[(2) - (1)].exp) );
    (yyval.exp_stmt) = exp_stmt;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar.yy"
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
#line 1057 "grammar.yy"
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
#line 1068 "grammar.yy"
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
#line 1077 "grammar.yy"
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
#line 1086 "grammar.yy"
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
#line 1097 "grammar.yy"
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
#line 1109 "grammar.yy"
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
#line 1119 "grammar.yy"
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
#line 1131 "grammar.yy"
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
#line 1141 "grammar.yy"
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
#line 1154 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1155 "grammar.yy"
    {
    Continue *ret = ManagedHandle::Retain ( new Continue ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.continue_stmt) = ret;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1163 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1164 "grammar.yy"
    {
    Break *ret = ManagedHandle::Retain ( new Break ( (yysemantic_stack_[(4) - (2)].ident) ) );
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    (yyval.break_stmt) = ret;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1173 "grammar.yy"
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
#line 1184 "grammar.yy"
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
#line 1195 "grammar.yy"
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
#line 1206 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ccs);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1210 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (3)].dc) );
    (yysemantic_stack_[(5) - (2)].ccs)->List ( (yysemantic_stack_[(5) - (4)].ccs) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ccs);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1219 "grammar.yy"
    { 
    CaseClauses *ret = ManagedHandle::Retain<CaseClauses>();
    ret->List ( (yysemantic_stack_[(1) - (1)].cc) );
    (yyval.ccs) = ret;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1225 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ccs)->List ( (yysemantic_stack_[(2) - (2)].cc) );
    (yyval.ccs) = (yysemantic_stack_[(2) - (1)].ccs);
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1233 "grammar.yy"
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
#line 1244 "grammar.yy"
    {
    DefaultClause *ret = ManagedHandle::Retain<DefaultClause> ();
    ret->LineNumber ( (yysemantic_stack_[(3) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(3) - (3)].stmtlist) );
    (yyval.dc) = ret;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1254 "grammar.yy"
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
#line 1264 "grammar.yy"
    {EXPECT_TERMINATOR;}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1265 "grammar.yy"
    {
    Throw *ret = ManagedHandle::Retain<Throw> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Expression ( (yysemantic_stack_[(4) - (2)].exp) );
    (yyval.throw_stmt) = ret;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1275 "grammar.yy"
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
#line 1283 "grammar.yy"
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
#line 1291 "grammar.yy"
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
#line 1303 "grammar.yy"
    {
    Catch *ret = ManagedHandle::Retain ( new Catch ( (yysemantic_stack_[(5) - (3)].info)->getValue () ) );
    ret->LineNumber ( (yysemantic_stack_[(5) - (1)].info)->getLineNumber () );
    ret->Body ( (yysemantic_stack_[(5) - (5)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1313 "grammar.yy"
    {
    Finally *ret = ManagedHandle::Retain<Finally> ();
    ret->LineNumber ( (yysemantic_stack_[(2) - (1)].info)->getLineNumber () );
    ret->Block ( (yysemantic_stack_[(2) - (2)].blk) );
    (yyval.ast) = ret;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1322 "grammar.yy"
    { (yyval.stmtlist) = ManagedHandle::Retain<StmtList> (); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar.yy"
    { (yyval.stmtlist) = (yysemantic_stack_[(1) - (1)].stmtlist); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1327 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1328 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1337 "grammar.yy"
    { (yyval.ccs) = ManagedHandle::Retain<CaseClauses> (); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar.yy"
    { (yyval.ccs) = (yysemantic_stack_[(1) - (1)].ccs); }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1342 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1343 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1345 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new NumberLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1349 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new StringLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new RegExpLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1360 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<NullLiteral> ();
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1367 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1371 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new BooleanLiteral ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1378 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<This> ();
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1382 "grammar.yy"
    {
    //scope->Update ( $1->getValue () );
    (yyval.ast) = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(1) - (1)].info)->getValue () ) );
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1386 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1387 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].array); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1388 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].obj); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1390 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].exp)->Paren ( true );
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].exp);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1398 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( ManagedHandle::Retain<Empty> () );
    (yyval.array) = ret;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1404 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(3) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1410 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    ret->Value ( (yysemantic_stack_[(5) - (2)].elem) );
    (yyval.array) = ret;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1416 "grammar.yy"
    {
    ArrayLiteral *ret = ManagedHandle::Retain<ArrayLiteral> ();
    (yysemantic_stack_[(4) - (3)].array_cmp)->Exp( (yysemantic_stack_[(4) - (2)].elem) );
    ret->Value ( (yysemantic_stack_[(4) - (3)].array_cmp) );
    (yyval.array) = ret;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1426 "grammar.yy"
    {
    ElementList *ret = ManagedHandle::Retain<ElementList> ();
    ret->Value ( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.elem) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1432 "grammar.yy"
    {
    (yysemantic_stack_[(4) - (1)].elem)->Value ( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.elem) = (yysemantic_stack_[(4) - (1)].elem);
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1446 "grammar.yy"
    {
    ArrayComprehensions* comp = ManagedHandle::Retain<ArrayComprehensions>();
    comp->Iteration( (yysemantic_stack_[(2) - (1)].ast) );
    comp->OptIf( (yysemantic_stack_[(2) - (2)].ast) );
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar.yy"
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
#line 1464 "grammar.yy"
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
#line 1475 "grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1477 "grammar.yy"
    {
    IFStmt *ret = ManagedHandle::Retain<IFStmt> ();
    ret->LineNumber ( (yysemantic_stack_[(4) - (1)].info)->getLineNumber () );
    ret->Then ( (yysemantic_stack_[(4) - (3)].exp) );
    (yyval.ast) = ret;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1487 "grammar.yy"
    {
    ObjectLiteral *ret = ManagedHandle::Retain ( new ObjectLiteral ( (yysemantic_stack_[(3) - (2)].ast) ) );
    (yyval.obj) = ret;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1494 "grammar.yy"
    { 
    (yyval.ast) = ManagedHandle::Retain<Empty>();
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1498 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].mem);
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1505 "grammar.yy"
    {
    ObjectMember *ret = ManagedHandle::Retain<ObjectMember> ();
    ret->Value ( (yysemantic_stack_[(3) - (1)].property) , (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.mem) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1511 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].mem)->Value ( (yysemantic_stack_[(5) - (3)].property) , (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.mem) = (yysemantic_stack_[(5) - (1)].mem);
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1519 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    //Scope::InsertGlobalSymbol ( ident );
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1532 "grammar.yy"
    {
    const char* ident = (yysemantic_stack_[(1) - (1)].info)->getValue ();
    PropertyName* property = ManagedHandle::Retain ( new PropertyName ( ident ) );
    (yyval.property) = property;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1541 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1545 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].fn);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1554 "grammar.yy"
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
#line 1562 "grammar.yy"
    {
    NewCallAccessor* ret = ManagedHandle::Retain ( new NewCallAccessor ( Constant::kNew , (yysemantic_stack_[(3) - (2)].ast) , (yysemantic_stack_[(3) - (3)].args) ) );
    (yyval.ast) = ret;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1569 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1571 "grammar.yy"
    {
    NewAccessor* ret = ManagedHandle::Retain ( new NewAccessor ( Constant::kNew , (yysemantic_stack_[(2) - (2)].ast) , ManagedHandle::Retain<Empty>() ) );
    (yyval.ast) = ret;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1579 "grammar.yy"
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
#line 1622 "grammar.yy"
    {
    CallAccessor* ret = ManagedHandle::Retain ( new CallAccessor ( Constant::kCall , (yysemantic_stack_[(2) - (1)].ast) , (yysemantic_stack_[(2) - (2)].args) ) );
    (yyval.ast) = ret;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1627 "grammar.yy"
    {
    ArrayAccessor* ret = ManagedHandle::Retain ( new ArrayAccessor ( Constant::kBracket , (yysemantic_stack_[(4) - (1)].ast) , (yysemantic_stack_[(4) - (3)].exp) ) );
    (yyval.ast) = ret;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1632 "grammar.yy"
    {
    Identifier *lit = ManagedHandle::Retain ( new Identifier ( (yysemantic_stack_[(3) - (3)].info)->getValue () ) );
    DotAccessor* ret = ManagedHandle::Retain ( new DotAccessor ( Constant::kDot , (yysemantic_stack_[(3) - (1)].ast) , lit ) );
    (yyval.ast) = ret;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1640 "grammar.yy"
    { (yyval.args) = ManagedHandle::Retain<Arguments> (); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1641 "grammar.yy"
    { (yyval.args) = (yysemantic_stack_[(3) - (2)].args); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1646 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1652 "grammar.yy"
    {
    Arguments *ret = ManagedHandle::Retain<Arguments> ();
    ret->Value ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.args) = ret;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1658 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].args)->Value ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.args) = (yysemantic_stack_[(3) - (1)].args);
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1670 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1671 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1676 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1680 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kAdd , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1685 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( Constant::kSub , (yysemantic_stack_[(2) - (1)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1692 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kDelete , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1699 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kVoid , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1704 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kTypeof , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1709 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kAdd , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kSub , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1719 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kPlus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1724 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kMinus , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1729 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNOR , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1734 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( Constant::kNot , (yysemantic_stack_[(2) - (2)].ast), ManagedHandle::Retain<Empty> () ) );
    (yyval.ast) = ret;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1741 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMul,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1747 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kDiv,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1751 "grammar.yy"
    {
    TREE_REDUCE(MultiplicativeExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kMod,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1757 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1759 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1763 "grammar.yy"
    {
    TREE_REDUCE(AdditiveExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kPlus,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1769 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1771 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftLeft,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1775 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1779 "grammar.yy"
    {
    TREE_REDUCE(ShiftExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kUShiftRight,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1785 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1787 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1791 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1799 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1803 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1807 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kIn,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1813 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1815 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLess,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1819 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreater,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1823 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLessEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1827 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kGreaterEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1831 "grammar.yy"
    {
    TREE_REDUCE(RelationalExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kInstanceof,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1837 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1839 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1843 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1847 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1851 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1857 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1859 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1863 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1867 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1871 "grammar.yy"
    {
    TREE_REDUCE(EqualityExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kNotEq,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1877 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1879 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1885 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1887 "grammar.yy"
    {
    TREE_REDUCE(BitwiseANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1893 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1895 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1901 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1903 "grammar.yy"
    {
    TREE_REDUCE(BitwiseXORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kXOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1909 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1911 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1917 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1919 "grammar.yy"
    {
    TREE_REDUCE(BitwiseORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1925 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1927 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1933 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1935 "grammar.yy"
    {
    TREE_REDUCE(LogicalANDExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalAND,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1941 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1943 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1949 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1951 "grammar.yy"
    {
    TREE_REDUCE(LogicalORExp,(yysemantic_stack_[(3) - (1)].ast),Constant::kLogicalOR,(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1957 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1959 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1967 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1969 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Prior ( Tree::kExp );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1978 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1982 "grammar.yy"
    {
    Assign *ret = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1991 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1995 "grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain ( new Assign ( (yysemantic_stack_[(3) - (2)].consts) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2003 "grammar.yy"
    { (yyval.consts) = Constant::kAssign; }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2004 "grammar.yy"
    { (yyval.consts) = Constant::kMulLet; }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2005 "grammar.yy"
    { (yyval.consts) = Constant::kDivLet; }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2006 "grammar.yy"
    { (yyval.consts) = Constant::kModLet; }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2007 "grammar.yy"
    { (yyval.consts) = Constant::kAddLet; }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2008 "grammar.yy"
    { (yyval.consts) = Constant::kSubLet; }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2009 "grammar.yy"
    { (yyval.consts) = Constant::kLShiftLet; }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2010 "grammar.yy"
    { (yyval.consts) = Constant::kRShiftLet; }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2011 "grammar.yy"
    { (yyval.consts) = Constant::kURShiftLet; }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2012 "grammar.yy"
    { (yyval.consts) = Constant::kANDLet; }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2013 "grammar.yy"
    { (yyval.consts) = Constant::kNotLet; }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar.yy"
    { (yyval.consts) = Constant::kORLet; }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2019 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2025 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2033 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->List ( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.exp) = exp;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2039 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].exp)->List ( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.exp) = (yysemantic_stack_[(3) - (1)].exp);
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2046 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2047 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2051 "grammar.yy"
    { (yyval.exp) = ManagedHandle::Retain<Expression> (); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2052 "grammar.yy"
    { (yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2056 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2057 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2061 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2062 "grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3209 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -351;
  const short int
  ParserImplementation::yypact_[] =
  {
      -351,    64,   851,  -351,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1664,   115,    45,    22,    45,   946,
     220,  -351,   -22,    49,    67,    94,  -351,  -351,  -351,  1590,
    -351,   130,  -351,  1590,  -351,   120,    26,   139,   213,  -351,
     133,   -12,   199,   198,   193,   554,  -351,  -351,  -351,  -351,
     851,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,   140,  -351,
     148,   197,  -351,  -351,   175,   125,   241,    80,   299,   258,
     264,   268,   272,    75,  -351,  -351,     9,  -351,    45,  -351,
      15,   208,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,    35,   140,  -351,  -351,     3,   289,  1136,  -351,  -351,
     -23,    16,    10,  -351,   161,  -351,  -351,  -351,    26,   188,
     225,    26,  -351,  -351,  1410,   251,   269,   278,   946,  1590,
     326,   -39,  1590,   326,   659,    -6,   161,    10,  1590,  1590,
     851,  1041,   851,   161,    14,   161,   212,    10,   946,    67,
     201,   206,  -351,  -351,   755,   209,   340,   214,  -351,  1320,
    1590,   267,  -351,  1590,   271,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  -351,  -351,  -351,  -351,
    -351,  -351,   115,    -7,  -351,   216,   274,  -351,  -351,  -351,
     -39,   199,  1590,  -351,  -351,   222,    12,   228,    26,  -351,
    -351,   -39,   304,   269,   215,   565,   241,   275,   343,   337,
     350,   352,   355,   242,  -351,  -351,   370,   259,  1614,   199,
     199,  -351,    36,  -351,    38,   -39,   347,   120,   325,  -351,
    -351,    40,    41,   276,   277,   851,  -351,  -351,   292,   296,
     294,  -351,   122,   168,  -351,   161,    44,  -351,   161,  -351,
    -351,  -351,  -351,  -351,    15,  1590,   327,  -351,  -351,    46,
    -351,    18,  -351,    34,  -351,  -351,  -351,  -351,  -351,   175,
     175,   125,   125,   125,   241,   241,   241,   241,   241,   241,
      80,    80,    80,    80,   299,   258,   264,   268,   287,   272,
    -351,  1228,  1664,   378,  -351,   379,  -351,  -351,   424,   300,
    -351,    37,  -351,   219,  -351,  -351,  1590,   297,    13,   401,
     297,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
     215,   405,   306,   307,   946,   308,  -351,   358,  -351,  -351,
     946,   946,  -351,  -351,  -351,  -351,   161,   360,  -351,   161,
      65,   311,  -351,   212,   946,  -351,   309,  -351,  -351,  1500,
    -351,  -351,  -351,  1590,  -351,  -351,   414,  1664,  1590,   315,
     222,   313,  -351,  -351,    48,  1590,  -351,  -351,   215,  1590,
    1590,  -351,    50,   197,  -351,   241,   241,   241,   241,   241,
     275,   275,   275,   275,   343,   337,   350,   352,   316,   355,
    -351,   317,   419,  1590,   320,   321,   387,   399,  -351,   329,
    -351,  -351,  -351,  -351,  -351,  1041,   851,   851,  -351,  -351,
    1590,  -351,  -351,  -351,  1590,   430,    51,   851,   221,   -39,
    -351,  -351,   330,    52,   946,  1590,  1590,  1590,    54,   851,
     851,   946,  1590,   399,  -351,   -17,   120,   332,   331,   333,
    -351,    55,  1590,  -351,   338,  -351,  -351,  -351,  1590,   946,
    -351,  -351,   339,    57,   946,   342,   344,  -351,    20,  -351,
     328,  -351,   399,  -351,  -351,  -351,  -351,  -351,    60,  -351,
     341,  -351,   946,   946,  -351,  -351,  -351,   946,   946,   345,
    -351,   946,  -351,  -351,   946,  -351,  -351,  -351,  -351
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
       0,     0,    58,    57,   274,     0,     0,     0,     0,     0,
     277,     0,     0,   114,     0,     0,   123,     0,     0,     0,
      21,     0,    21,   123,     0,   123,     0,     0,     0,   138,
     131,   132,    54,    59,     0,     0,   158,     0,    24,     0,
       0,     0,   171,     0,     0,   172,   266,   263,   265,   264,
     269,   268,   259,   261,   260,   267,   262,   185,   184,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,   161,   163,   162,
     142,   168,   278,     0,   144,     0,   154,   150,   143,   147,
       0,    31,     0,   124,    73,    80,     0,     0,     0,    62,
      74,     0,     0,     0,     0,   183,   214,   225,   232,   236,
     240,   244,   248,   252,   256,   272,   275,     0,     0,    31,
      31,   113,     0,   104,     0,     0,     0,     0,   116,   117,
      61,     0,     0,    28,     0,     0,    22,    25,    35,     0,
       0,    14,     0,     0,    15,   123,     0,    65,     0,    63,
      56,    55,    60,   156,     0,     0,     0,   175,   178,     0,
     177,     0,   167,     0,   174,   255,   197,   198,   199,   201,
     202,   206,   205,   204,   209,   208,   212,   213,   210,   211,
     224,   222,   221,   223,   231,   235,   239,   243,     0,   247,
     271,     0,     0,     0,   146,     0,   151,   103,    32,     0,
      86,     0,    79,     0,    70,   101,     0,   125,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,     0,     0,     0,   115,     0,   120,   118,
       0,     0,     9,    26,    13,    11,   123,     0,    18,   123,
       0,     0,    67,     0,     0,    68,     0,   159,    20,     0,
     176,   166,   173,     0,   145,   148,     0,     0,     0,     0,
      84,     0,    81,    82,     0,     0,   126,    75,     0,   276,
       0,    76,     0,   183,   257,   216,   215,   219,   217,   218,
     229,   227,   226,   228,   233,   237,   241,   245,     0,   249,
     273,     0,     0,     0,     0,     0,    91,   127,   106,     0,
      93,   105,    16,    19,    17,     0,    21,    21,    66,    64,
       0,   180,   179,   251,     0,     0,     0,    21,     0,     0,
      87,    72,     0,     0,     0,     0,   276,     0,     0,    21,
      21,     0,     0,   128,   109,     0,     0,     0,     0,     0,
     160,     0,     0,   155,     0,    83,    85,    92,   276,     0,
      96,   253,     0,     0,     0,     0,     0,    90,     0,   110,
       0,   107,   127,   119,    12,     8,    10,   152,     0,     5,
       0,    97,     0,     0,    98,     4,     6,   121,   121,     0,
     153,     0,    94,    99,   122,   111,   112,   108,    95
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -351,  -351,  -351,    72,  -351,  -351,   428,  -351,    77,  -148,
     471,  -351,   -36,   202,    58,   234,   -19,  -143,  -140,   -30,
    -351,  -351,  -222,   458,  -351,  -351,    86,    23,  -351,   244,
    -322,    28,  -351,  -351,  -121,   134,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,     0,
    -351,  -351,  -351,  -351,  -351,  -351,   218,   -38,  -145,  -351,
     -21,  -351,  -351,  -351,  -351,    25,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -101,   474,   475,  -351,   -24,  -351,
      24,  -351,    74,   117,   -99,   200,   205,    56,   283,   132,
     285,   135,   286,   136,   290,   141,   291,   143,  -351,  -351,
    -351,  -351,   -40,  -279,   420,   -11,  -351,  -351,  -350,   295,
     -95
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   273,    48,    49,   338,   388,   298,   274,
     275,   276,    51,   277,   339,   137,    52,    53,    54,    55,
      56,    57,   164,    58,    59,   286,   287,   122,   348,   123,
     349,   124,   125,   236,   233,   416,    60,    61,    62,    63,
      64,   241,    65,   230,    66,    67,    68,   448,   483,   484,
     512,    69,    70,   265,    71,   268,   269,   535,   234,   417,
     485,    72,    73,    74,    75,    76,   115,   116,   225,   226,
     336,    77,   165,   166,   167,    78,    79,    80,   172,   299,
      81,    82,    83,    84,    85,    86,    87,   247,    88,   248,
      89,   249,    90,   250,    91,   251,    92,   252,    93,   253,
      94,   254,    95,   255,   352,    96,   256,   257,   141,   117,
      97
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -164;
  const short int
  ParserImplementation::yytable_[] =
  {
       129,   216,   111,   240,   280,   145,   222,   278,   281,   278,
     284,   279,   215,   238,   168,   341,   418,   282,   140,   441,
     237,   215,   143,   215,   231,   134,   163,   239,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   215,   215,   215,
     332,   215,   126,   215,   215,   510,   263,   393,   442,   399,
     266,   215,   270,   215,   215,   215,   175,   215,   215,   147,
     215,   126,   289,   215,     3,   267,   157,   126,   126,   472,
     155,    15,    39,   424,    47,    15,   223,   229,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   438,   221,   440,
     213,   214,   132,   217,   235,    46,   471,   311,   312,   313,
     120,   135,   218,   218,   146,   199,   200,   201,   202,   203,
     232,   219,   219,   511,   151,   410,   333,   152,   114,   261,
      39,    39,    47,   118,   218,   163,   502,   136,   262,   300,
     283,   264,   278,   219,   224,   337,   470,   271,   272,   290,
     392,   139,   342,    46,    46,   292,   345,   419,   520,   401,
     305,   121,   527,   126,   157,   121,   126,   204,   245,   301,
     194,   195,   303,   220,   374,   402,   375,   395,   380,   381,
     376,    15,   394,   328,   400,   330,   469,   142,   474,   493,
     499,   126,   504,   517,   288,   523,   148,   169,   530,   170,
     171,   455,   340,   396,   456,   169,   501,   173,   174,   138,
     386,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   191,   192,   193,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   378,   101,   168,
     411,   452,   187,   188,   454,   156,   387,    15,    15,   144,
     119,   121,   127,   187,   188,   397,   126,   366,   367,   155,
     149,    15,   150,   126,    15,   306,   307,   308,    15,   126,
      15,   158,   350,   196,   197,   198,   146,   153,   209,    17,
     390,   391,   371,   210,   126,   126,   211,   155,   155,   212,
     285,   405,   227,   347,   232,   130,   242,   412,   258,   495,
     353,   354,   355,   243,   356,   534,   534,   126,   488,   489,
     389,   309,   310,   278,   278,   487,   259,   372,   373,   494,
     205,   206,   207,   208,   278,   260,    36,   121,   121,   215,
     189,   505,   506,  -163,   246,   414,   278,   278,  -162,   293,
     422,   121,   131,   294,   121,   302,   295,   334,   121,   304,
     121,   346,   357,   335,  -161,   446,   406,   362,   140,   462,
     343,   450,   451,   463,   358,   359,   360,   361,   126,   363,
     364,   413,   365,   368,   497,   459,   423,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     423,   101,   423,   369,   377,   126,   267,   466,   350,   314,
     315,   316,   317,   318,   319,   398,   -30,   382,   140,   473,
     320,   321,   322,   323,   430,   431,   432,   433,   126,   403,
     490,   288,   -29,   384,   385,   407,   408,   282,   409,   420,
     415,   465,   478,   443,   444,   445,   449,   447,   453,   423,
     457,   460,   464,   126,   467,   468,   350,   477,   475,   479,
     480,   476,   481,   491,   482,   500,   513,   486,   492,   514,
     528,   515,   507,   516,   498,   140,   503,   522,   519,   531,
     154,   508,   525,    50,   526,   537,   461,   383,   133,   458,
     521,   518,   344,   509,   421,   524,   379,   140,   112,   113,
     536,   529,   324,   126,   434,   325,   496,   326,   435,   423,
     436,   190,   327,   532,   533,   329,   437,     0,   163,   163,
     439,     0,   538,     0,     0,   292,     0,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   425,   426,   427,   428,   429,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,   351,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,     0,     0,
     187,   188,     0,   128,    18,   246,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,    98,
       0,     0,   159,    25,     0,     0,     0,     0,     0,     0,
      26,   160,     0,     0,     0,     0,    28,    29,     0,     0,
     161,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,   246,    43,     0,     0,    44,
       0,     0,     0,    45,   162,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     4,     5,     0,     0,   189,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   128,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    98,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,   162,
       4,     5,     0,    46,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   128,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
      98,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,   291,     4,     5,     0,    46,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,    23,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     4,     5,     0,     0,    46,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   128,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,    98,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     4,     5,     0,     0,
      46,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     128,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,    98,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
     100,     4,     5,     0,     0,    46,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    98,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,   100,     0,   228,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,   100,     0,   404,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     4,     5,     0,   297,   100,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,   244,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,   100,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     4,     5,     0,     0,   100,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,    13,    14,    15,     0,    98,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,     0,    28,    21,     0,     0,    30,     0,     0,    98,
      32,     0,    99,     0,    34,     0,     0,     0,     0,     0,
      26,    27,    40,    41,     0,    42,    28,     0,     0,     0,
      30,    13,    14,    15,    32,     0,     0,     0,    34,   100,
     370,     0,     0,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,    21,     0,     0,     0,     0,     0,    98,
       0,     0,    99,   100,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    28,     0,     0,     0,
      30,     0,     0,     0,    32,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
        19,    96,    13,   124,   152,    35,     3,   150,   153,   152,
     155,   151,     3,     3,    50,     3,     3,     3,    29,   369,
     121,     3,    33,     3,    47,    47,    45,   122,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     3,     3,     3,
      47,     3,    17,     3,     3,    62,   141,     3,   370,     3,
      56,     3,   147,     3,     3,     3,    80,     3,     3,    36,
       3,    36,   157,     3,     0,    71,    43,    42,    43,   419,
      42,    49,   111,   352,     2,    49,    73,   117,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   366,   112,   368,
      15,    16,    20,    78,    78,   134,   418,   196,   197,   198,
      78,   123,    87,    87,    78,    25,    26,    27,    28,    29,
     133,    96,    96,   130,   126,    78,   123,   129,     3,   138,
     111,   111,    50,    78,    87,   144,   476,    78,   139,   169,
     116,   142,   275,    96,   131,   230,   415,   148,   149,   158,
     285,    47,   130,   134,   134,   164,   241,   134,   498,   131,
     190,   129,   132,   128,   131,   129,   131,    77,   134,   170,
      35,    36,   173,   128,   128,   131,   128,   288,   128,   128,
     265,    49,   128,   213,   128,   215,   128,    47,   128,   128,
     128,   156,   128,   128,   156,   128,    47,    47,   128,    49,
      50,   126,   232,   294,   129,    47,   475,    49,    50,   132,
      78,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    37,    38,    39,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   267,   214,   275,
     341,   386,    45,    46,   389,    47,   124,    49,    49,   129,
      16,   129,    18,    45,    46,   295,   231,    15,    16,   231,
      47,    49,   129,   238,    49,   191,   192,   193,    49,   244,
      49,    78,   244,    32,    33,    34,    78,    78,    20,    59,
     112,   113,   258,    19,   259,   260,    18,   259,   260,    17,
      78,   331,     3,    78,   133,    75,   108,    78,    47,    78,
      25,    26,    27,    78,    29,   527,   528,   282,   456,   457,
     282,   194,   195,   456,   457,   455,    47,   259,   260,   467,
      21,    22,    23,    24,   467,    47,   106,   129,   129,     3,
     133,   479,   480,   132,   134,   346,   479,   480,   132,   130,
     351,   129,   122,     3,   129,    78,   132,   131,   129,    78,
     129,    47,    77,    79,   132,   374,   332,    20,   369,   399,
     132,   380,   381,   403,    21,    22,    23,    24,   343,    19,
      18,   343,    17,     3,   469,   394,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   134,    47,   370,    71,   408,   370,   199,
     200,   201,   202,   203,   204,    78,   130,   130,   419,   420,
     205,   206,   207,   208,   358,   359,   360,   361,   393,   132,
     460,   393,   130,   127,   130,    47,    47,     3,   128,    28,
     133,   407,   443,    28,   128,   128,    78,   129,    78,   415,
     129,   132,    28,   418,   129,   132,   418,    28,   132,   129,
     129,   134,    65,   464,    55,   474,   486,   128,    28,   127,
     132,   130,   481,   130,   134,   476,   477,   128,   130,   128,
      42,   482,   130,     2,   130,   130,   399,   275,    20,   393,
     499,   492,   238,   483,   350,   504,   268,   498,    14,    14,
     528,   512,   209,   468,   362,   210,   468,   211,   363,   475,
     364,    81,   212,   522,   523,   214,   365,    -1,   527,   528,
     367,    -1,   531,    -1,    -1,   534,    -1,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    28,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      45,    46,    -1,    59,    60,   415,    -1,    63,    -1,    -1,
      -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,
     106,    -1,   108,   109,    -1,   111,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,   475,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,   130,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   133,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,
     111,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,   130,
      35,    36,    -1,   134,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,
     105,   106,    -1,   108,   109,    -1,   111,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,   130,    35,    36,    -1,   134,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    67,    -1,
      69,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    98,
      -1,   100,   101,    -1,    -1,   104,   105,   106,    -1,   108,
     109,    -1,   111,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    35,    36,    -1,    -1,   134,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,
      -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,
      -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,
     104,   105,   106,    -1,   108,   109,    -1,   111,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    35,    36,    -1,    -1,
     134,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    98,
      -1,   100,   101,    -1,    -1,   104,   105,   106,    -1,   108,
     109,    -1,   111,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    35,    36,    -1,    -1,   134,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,   129,    -1,   131,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,   129,    -1,   131,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    35,    36,    -1,   128,   129,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   129,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    35,    36,    -1,    -1,   129,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    47,    48,    49,    -1,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    69,    -1,    -1,    96,    -1,    -1,    75,
     100,    -1,    78,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      86,    87,   112,   113,    -1,   115,    92,    -1,    -1,    -1,
      96,    47,    48,    49,   100,    -1,    -1,    -1,   104,   129,
     106,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129
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
     112,   113,   115,   122,   125,   129,   134,   138,   139,   140,
     145,   147,   151,   152,   153,   154,   155,   156,   158,   159,
     171,   172,   173,   174,   175,   177,   179,   180,   181,   186,
     187,   189,   196,   197,   198,   199,   200,   206,   210,   211,
     212,   215,   216,   217,   218,   219,   220,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   240,   245,    75,    78,
     129,   215,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   240,   210,   211,     3,   201,   202,   244,    78,   150,
      78,   129,   162,   164,   166,   167,   200,   150,    59,   151,
      75,   122,   138,   158,    47,   123,    78,   150,   132,    47,
     240,   243,    47,   240,   129,   154,    78,   162,    47,    47,
     129,   126,   129,    78,   141,   166,    47,   162,    78,    78,
      87,    96,   130,   151,   157,   207,   208,   209,   147,    47,
      49,    50,   213,    49,    50,   213,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   133,
     239,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    77,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   245,    78,    87,    96,
     128,   213,     3,    73,   131,   203,   204,     3,   131,   237,
     178,    47,   133,   169,   193,    78,   168,   209,     3,   245,
     169,   176,   108,    78,   106,   215,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   241,   242,    47,    47,
      47,   151,   240,   245,   240,   188,    56,    71,   190,   191,
     245,   240,   240,   138,   144,   145,   146,   148,   152,   153,
     144,   193,     3,   116,   193,    78,   160,   161,   166,   245,
     151,   130,   151,   130,     3,   132,   124,   128,   143,   214,
     237,   240,    78,   240,    78,   237,   217,   217,   217,   218,
     218,   219,   219,   219,   220,   220,   220,   220,   220,   220,
     221,   221,   221,   221,   223,   225,   227,   229,   237,   231,
     237,   244,    47,   123,   131,    79,   205,   245,   141,   149,
     237,     3,   130,   132,   164,   245,    47,    78,   163,   165,
     166,    28,   239,    25,    26,    27,    29,    77,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   134,
     106,   215,   149,   149,   128,   128,   245,    47,   154,   191,
     128,   128,   130,   148,   127,   130,    78,   124,   142,   166,
     112,   113,   193,     3,   128,   169,   209,   237,    78,     3,
     128,   131,   131,   132,   131,   237,   215,    47,    47,   128,
      78,   209,    78,   166,   240,   133,   170,   194,     3,   134,
      28,   170,   240,   215,   238,   220,   220,   220,   220,   220,
     222,   222,   222,   222,   224,   226,   228,   230,   238,   232,
     238,   243,   165,    28,   128,   128,   151,   129,   182,    78,
     151,   151,   193,    78,   193,   126,   129,   129,   161,   151,
     132,   143,   237,   237,    28,   215,   240,   129,   132,   128,
     238,   165,   243,   240,   128,   132,   134,    28,   240,   129,
     129,    65,    55,   183,   184,   195,   128,   153,   144,   144,
     237,   240,    28,   128,   144,    78,   166,   245,   134,   128,
     151,   238,   243,   240,   128,   144,   144,   151,   240,   184,
      62,   130,   185,   154,   127,   130,   130,   128,   240,   130,
     243,   151,   128,   128,   151,   130,   130,   132,   132,   195,
     128,   128,   151,   151,   157,   192,   192,   130,   151
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
     125,    93,    58,    61,    59
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
       1,     1,     1,     1,     2,     3,     3,     2,     2,     1,
       2,     3,     3,     3,     5,     1,     3,     2,     2,     1,
       3,     1,     3,     2,     2,     2,     2,     1,     1,     3,
       1,     3,     3,     5,     3,     5,     2,     2,     1,     2,
       7,     5,     7,     5,     9,    10,     7,     8,     8,     9,
       0,     4,     0,     4,     3,     5,     5,     3,     5,     1,
       2,     4,     3,     3,     0,     4,     3,     3,     4,     5,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     4,     2,     4,     1,
       2,     2,     6,     7,     0,     4,     3,     0,     1,     3,
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
  "':'", "'='", "';'", "$accept", "program", "$@1", "function_declaration",
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
     157,   130,    -1,   125,    78,   151,    -1,    67,   158,    -1,
      67,   138,    -1,   151,    -1,   157,   151,    -1,   106,   162,
     245,    -1,    59,   162,   245,    -1,   122,   162,   245,    -1,
     122,    47,   160,   128,   151,    -1,   161,    -1,   160,     3,
     161,    -1,    78,   193,    -1,   166,   169,    -1,   164,    -1,
     162,     3,   164,    -1,   165,    -1,   163,     3,   165,    -1,
      78,   193,    -1,   166,   169,    -1,    78,   194,    -1,   166,
     170,    -1,   200,    -1,   167,    -1,   129,   168,   130,    -1,
      78,    -1,   209,   132,    78,    -1,   209,   132,   166,    -1,
     168,     3,   209,   132,    78,    -1,   168,     3,    78,    -1,
     168,     3,   209,   132,   166,    -1,   133,   237,    -1,   133,
     238,    -1,   245,    -1,   240,   245,    -1,    79,    47,   240,
     128,   151,    65,   151,    -1,    79,    47,   240,   128,   151,
      -1,    63,   151,   108,    47,   240,   128,   245,    -1,   108,
      47,   240,   128,   151,    -1,    73,    47,   242,   134,   243,
     134,   243,   128,   151,    -1,    73,    47,   106,   163,   134,
     243,   134,   243,   128,   151,    -1,    73,    47,   215,    28,
     240,   128,   151,    -1,    73,    47,   106,   165,    28,   240,
     128,   151,    -1,    73,   123,    47,   215,    28,   240,   128,
     151,    -1,    73,   123,    47,   106,   165,    28,   240,   128,
     151,    -1,    -1,    60,   150,   176,   245,    -1,    -1,    53,
     150,   178,   245,    -1,    93,   243,   245,    -1,   109,    47,
     240,   128,   151,    -1,    98,    47,   240,   128,   182,    -1,
     129,   195,   130,    -1,   129,   195,   185,   195,   130,    -1,
     184,    -1,   183,   184,    -1,    55,   240,   132,   192,    -1,
      62,   132,   192,    -1,    78,   132,   151,    -1,    -1,   101,
     240,   188,   245,    -1,   105,   154,   190,    -1,   105,   154,
     191,    -1,   105,   154,   190,   191,    -1,    56,    47,    78,
     128,   154,    -1,    71,   154,    -1,    -1,   157,    -1,    -1,
     169,    -1,    -1,   170,    -1,    -1,   183,    -1,   197,    -1,
     198,    -1,    87,    -1,    96,    -1,    92,    -1,    86,    -1,
     104,    -1,    69,    -1,   100,    -1,    78,    -1,   196,    -1,
     200,    -1,   206,    -1,    47,   240,   128,    -1,    49,   244,
     131,    -1,    49,   201,   131,    -1,    49,   201,     3,   244,
     131,    -1,    49,   201,   203,   131,    -1,   244,   237,    -1,
     201,     3,   244,   237,    -1,     3,    -1,   202,     3,    -1,
     204,   205,    -1,    73,    47,   215,    28,   240,   128,    -1,
      73,   123,    47,   215,    28,   240,   128,    -1,    -1,    79,
      47,   240,   128,    -1,   129,   207,   130,    -1,    -1,   208,
      -1,   209,   132,   237,    -1,   208,     3,   209,   132,   237,
      -1,    78,    -1,    96,    -1,    87,    -1,   199,    -1,   139,
      -1,   210,    49,   240,   131,    -1,   210,    50,    78,    -1,
      48,   210,   213,    -1,   210,    -1,    48,   211,    -1,   210,
     213,    -1,   212,   213,    -1,   212,    49,   240,   131,    -1,
     212,    50,    78,    -1,    47,   128,    -1,    47,   214,   128,
      -1,   237,    -1,   143,    -1,   214,     3,   237,    -1,   214,
       3,   143,    -1,   211,    -1,   212,    -1,   215,    -1,   215,
      46,    -1,   215,    45,    -1,   216,    -1,    42,   217,    -1,
      43,   217,    -1,    44,   217,    -1,    46,   217,    -1,    45,
     217,    -1,    35,   217,    -1,    36,   217,    -1,    41,   217,
      -1,    40,   217,    -1,   217,    -1,   218,    37,   217,    -1,
     218,    38,   217,    -1,   218,    39,   217,    -1,   218,    -1,
     219,    35,   218,    -1,   219,    36,   218,    -1,   219,    -1,
     220,    34,   219,    -1,   220,    33,   219,    -1,   220,    32,
     219,    -1,   220,    -1,   221,    26,   220,    -1,   221,    25,
     220,    -1,   221,    29,   220,    -1,   221,    77,   220,    -1,
     221,    27,   220,    -1,   221,    28,   220,    -1,   220,    -1,
     222,    26,   220,    -1,   222,    25,   220,    -1,   222,    29,
     220,    -1,   222,    77,   220,    -1,   222,    27,   220,    -1,
     221,    -1,   223,    23,   221,    -1,   223,    22,   221,    -1,
     223,    24,   221,    -1,   223,    21,   221,    -1,   222,    -1,
     224,    23,   222,    -1,   224,    22,   222,    -1,   224,    24,
     222,    -1,   224,    21,   222,    -1,   223,    -1,   225,    20,
     223,    -1,   224,    -1,   226,    20,   224,    -1,   225,    -1,
     227,    19,   225,    -1,   226,    -1,   228,    19,   226,    -1,
     227,    -1,   229,    18,   227,    -1,   228,    -1,   230,    18,
     228,    -1,   229,    -1,   231,    17,   229,    -1,   230,    -1,
     232,    17,   230,    -1,   231,    -1,   233,    16,   231,    -1,
     232,    -1,   234,    16,   232,    -1,   233,    -1,   233,    15,
     237,   132,   237,    -1,   234,    -1,   234,    15,   238,   132,
     238,    -1,   235,    -1,   215,   239,   237,    -1,   236,    -1,
     215,   239,   238,    -1,   133,    -1,    10,    -1,    12,    -1,
      11,    -1,    14,    -1,     5,    -1,     7,    -1,     6,    -1,
       4,    -1,    13,    -1,     9,    -1,     8,    -1,   237,    -1,
     240,     3,   237,    -1,   238,    -1,   241,     3,   238,    -1,
      -1,   241,    -1,    -1,   240,    -1,    -1,   202,    -1,   134,
      -1,   111,    -1
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
     158,   160,   162,   164,   166,   169,   173,   177,   180,   183,
     185,   188,   192,   196,   200,   206,   208,   212,   215,   218,
     220,   224,   226,   230,   233,   236,   239,   242,   244,   246,
     250,   252,   256,   260,   266,   270,   276,   279,   282,   284,
     287,   295,   301,   309,   315,   325,   336,   344,   353,   362,
     372,   373,   378,   379,   384,   388,   394,   400,   404,   410,
     412,   415,   420,   424,   428,   429,   434,   438,   442,   447,
     453,   456,   457,   459,   460,   462,   463,   465,   466,   468,
     470,   472,   474,   476,   478,   480,   482,   484,   486,   488,
     490,   492,   494,   498,   502,   506,   512,   517,   520,   525,
     527,   530,   533,   540,   548,   549,   554,   558,   559,   561,
     565,   571,   573,   575,   577,   579,   581,   586,   590,   594,
     596,   599,   602,   605,   610,   614,   617,   621,   623,   625,
     629,   633,   635,   637,   639,   642,   645,   647,   650,   653,
     656,   659,   662,   665,   668,   671,   674,   676,   680,   684,
     688,   690,   694,   698,   700,   704,   708,   712,   714,   718,
     722,   726,   730,   734,   738,   740,   744,   748,   752,   756,
     760,   762,   766,   770,   774,   778,   780,   784,   788,   792,
     796,   798,   802,   804,   808,   810,   814,   816,   820,   822,
     826,   828,   832,   834,   838,   840,   844,   846,   850,   852,
     856,   858,   864,   866,   872,   874,   878,   880,   884,   886,
     888,   890,   892,   894,   896,   898,   900,   902,   904,   906,
     908,   910,   914,   916,   920,   921,   923,   924,   926,   927,
     929,   931
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   346,   346,   346,   359,   372,   384,   392,   405,   412,
     418,   425,   431,   438,   460,   474,   482,   490,   497,   511,
     526,   534,   535,   539,   545,   553,   559,   567,   568,   576,
     577,   585,   586,   593,   594,   601,   602,   607,   615,   620,
     624,   629,   634,   639,   644,   649,   654,   659,   664,   669,
     674,   679,   684,   689,   697,   703,   713,   723,   729,   739,
     745,   754,   761,   768,   778,   787,   793,   800,   806,   814,
     820,   828,   834,   842,   849,   858,   865,   874,   880,   959,
     964,   974,   985,   995,  1005,  1014,  1026,  1030,  1034,  1038,
    1047,  1056,  1067,  1076,  1085,  1096,  1108,  1118,  1130,  1140,
    1154,  1154,  1163,  1163,  1172,  1183,  1194,  1205,  1209,  1218,
    1224,  1232,  1243,  1253,  1264,  1264,  1274,  1282,  1290,  1302,
    1312,  1322,  1323,  1327,  1328,  1332,  1333,  1337,  1338,  1342,
    1343,  1344,  1348,  1352,  1359,  1366,  1370,  1377,  1381,  1386,
    1387,  1388,  1389,  1397,  1403,  1409,  1415,  1425,  1431,  1439,
    1440,  1445,  1454,  1463,  1475,  1476,  1486,  1494,  1497,  1504,
    1510,  1518,  1525,  1531,  1540,  1544,  1548,  1553,  1561,  1569,
    1570,  1578,  1621,  1626,  1631,  1640,  1641,  1645,  1651,  1657,
    1662,  1670,  1671,  1675,  1679,  1684,  1692,  1693,  1698,  1703,
    1708,  1713,  1718,  1723,  1728,  1733,  1741,  1742,  1746,  1750,
    1757,  1758,  1762,  1769,  1770,  1774,  1778,  1785,  1786,  1790,
    1794,  1798,  1802,  1806,  1813,  1814,  1818,  1822,  1826,  1830,
    1837,  1838,  1842,  1846,  1850,  1857,  1858,  1862,  1866,  1870,
    1877,  1878,  1885,  1886,  1893,  1894,  1901,  1902,  1909,  1910,
    1917,  1918,  1925,  1926,  1933,  1934,  1941,  1942,  1949,  1950,
    1957,  1958,  1967,  1968,  1977,  1981,  1990,  1994,  2003,  2004,
    2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,
    2018,  2024,  2032,  2038,  2046,  2047,  2051,  2052,  2056,  2057,
    2061,  2062
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
       2,     2,     2,     2,     2,     2,     2,     2,   132,   134,
      26,   133,    25,    15,     2,     2,     2,     2,     2,     2,
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
  const int ParserImplementation::yylast_ = 1793;
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
#line 4514 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2065 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


