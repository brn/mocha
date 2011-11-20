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
#include "ast.h"
#include "ast_visitor.h"
#include "yylex.h"
#include "handle.h"
#include "compiler.h"
#include "managed_handle.h"

  using namespace std;
  using namespace mocha;

#define BINARY_ACTION(type,_1,_3,_4)                                 \
  BinaryExp* binary = ManagedHandle::Retain( new BinaryExp( type , _1 , _3 ) ); \
  _4 = binary;                                                          \

#define COMPARE_ACTION(type,_1,_3,_4)                                   \
  CompareExp* compare = ManagedHandle::Retain( new CompareExp( type , _1 , _3 ) ); \
  _4 = compare;                                                         \

  Empty* GetEmptyNode() {
    static Empty empty;
    return &empty;
  }
  


/* Line 293 of lalr1.cc  */
#line 73 "grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 82 "grammar.tab.cc"

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
#line 168 "grammar.tab.cc"

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
#line 330 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 331 "grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->AddChild( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 345 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(8) - (2)].info) );
    fn->Name( value );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 361 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(8) - (2)].info) );
    fn->Name( value );
    fn->Const();
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 376 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( (yysemantic_stack_[(8) - (2)].ast) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 384 "grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 398 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].node_list) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 406 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 414 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].node_list) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 422 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 430 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].node_list) );
    fn->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.function) = fn;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 438 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.function) = fn;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 462 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 477 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].ast) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 487 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 496 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 505 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Node( (yysemantic_stack_[(3) - (3)].ast) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 519 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 535 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 543 "grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 544 "grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 549 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 555 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 563 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 569 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 576 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 578 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 586 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 588 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 596 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 598 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 604 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 606 "grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 614 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 616 "grammar.yy"
    {
    printf("module block \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 621 "grammar.yy"
    {
    printf("export statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 629 "grammar.yy"
    {
    printf("block statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 633 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 638 "grammar.yy"
    {
    printf("var statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 643 "grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 647 "grammar.yy"
    {
    printf("empty statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 652 "grammar.yy"
    {
    printf("exp statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 657 "grammar.yy"
    {
    printf("if statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 662 "grammar.yy"
    {
    printf("iter statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 667 "grammar.yy"
    {
    printf("cont statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 672 "grammar.yy"
    {
    printf("break statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 677 "grammar.yy"
    {
    printf("return statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 682 "grammar.yy"
    {
    printf("with statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 687 "grammar.yy"
    {
    printf("label statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 692 "grammar.yy"
    {
    printf("switch statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 697 "grammar.yy"
    {
    printf("throw statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 702 "grammar.yy"
    {
    printf("try statement \n");
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 710 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 716 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) ); 
    (yyval.block) = block;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 726 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (2)].info) );
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Name( value );
    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 739 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->AddChild( (yysemantic_stack_[(3) - (2)].value_node) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 745 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->AddChild( (yysemantic_stack_[(2) - (2)].function) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 755 "grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 763 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 772 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 779 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 786 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 796 "grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 805 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 811 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 818 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 825 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Node( (yysemantic_stack_[(2) - (1)].ast) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 835 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 843 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 853 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 859 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 867 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 874 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 884 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 891 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 902 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 906 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 913 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list)->FirstChild() );
    (yyval.value_node) = value;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 923 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    list->AddChild( node );
    (yyval.node_list) = list;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 931 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( node );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 941 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(3) - (3)].ast) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( node );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 951 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 960 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 967 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 976 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 980 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 984 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 989 "grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 998 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1005 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1022 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1029 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kFor ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(9) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(9) - (5)].ast) );
    list->AddChild( (yysemantic_stack_[(9) - (7)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(9) - (9)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1040 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(10) - (4)].node_list) );
    list->AddChild( (yysemantic_stack_[(10) - (6)].ast) );
    list->AddChild( (yysemantic_stack_[(10) - (8)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(10) - (10)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1051 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(7) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(7) - (5)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1061 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForInWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(8) - (4)].value_node) );
    list->AddChild( (yysemantic_stack_[(8) - (6)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(8) - (8)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1072 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(8) - (4)].ast) );
    list->AddChild( (yysemantic_stack_[(8) - (6)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(8) - (8)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1082 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEachWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(9) - (5)].value_node) );
    list->AddChild( (yysemantic_stack_[(9) - (7)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(9) - (9)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1095 "grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1104 "grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1113 "grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1122 "grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1132 "grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1142 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1146 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].ast)->After( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (3)].case_clause)->After( (yysemantic_stack_[(5) - (4)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].ast);
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1155 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].case_clause);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1161 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1169 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1179 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1189 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (1)].info) );
    LabelledStmt *label = ManagedHandle::Retain<LabelledStmt>();
    label->AddChild( value );
    label->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.labelled_stmt) = label;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1201 "grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1210 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1218 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1226 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1237 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1246 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1252 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1253 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1257 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1258 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1262 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1263 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1267 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1268 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1272 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1273 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1275 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1281 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1287 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1296 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1305 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1311 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1320 "grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1326 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1331 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1335 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1343 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    if ( (yysemantic_stack_[(3) - (2)].opt) ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    (yyval.ast) = value;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1352 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1358 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->AddChild( (yysemantic_stack_[(5) - (2)].node_list) );
    if ( (yysemantic_stack_[(5) - (4)].opt) ) {
      value->AddChild( GetEmptyNode() );
    }
    (yyval.ast) = value;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1367 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1377 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1386 "grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1403 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1411 "grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1418 "grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1427 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1429 "grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1438 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    value->Node( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1446 "grammar.yy"
    { 
    (yyval.ast) = GetEmptyNode();
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1450 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1457 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1465 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1474 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1480 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1486 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1495 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1499 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1503 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(4) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(4) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Callable( (yysemantic_stack_[(4) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(4) - (3)].expression) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1515 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (1)].ast) )->Depth() + 1;
    }
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Callable( (yysemantic_stack_[(3) - (1)].ast) );
    exp->Args( value );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1529 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (2)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (2)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNew ) );
    exp->Callable( (yysemantic_stack_[(3) - (2)].ast) );
    exp->Args( (yysemantic_stack_[(3) - (3)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1543 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1545 "grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1554 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(2) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(2) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Callable( (yysemantic_stack_[(2) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(2) - (2)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1566 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(2) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(2) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Callable( (yysemantic_stack_[(2) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(2) - (2)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1578 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(4) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(4) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Callable( (yysemantic_stack_[(4) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(4) - (3)].expression) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1590 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (1)].ast) )->Depth() + 1;
    }
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Callable( (yysemantic_stack_[(3) - (1)].ast) );
    exp->Args( value );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1607 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1612 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1618 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1624 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1636 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1637 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1646 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1652 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1660 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1662 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1668 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1674 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1680 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1686 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1692 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1698 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1704 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1710 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1718 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1720 "grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1724 "grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1728 "grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1734 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1736 "grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1740 "grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1746 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1748 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1752 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1756 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1762 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1764 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1768 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1772 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1776 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1780 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1784 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1790 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1792 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1796 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1800 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1804 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1808 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1814 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1816 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1820 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1824 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1828 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1834 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1836 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1840 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1844 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1848 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1854 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1856 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1862 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1864 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1870 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1872 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1878 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1880 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1886 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1888 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1894 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1902 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1910 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1912 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1918 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1920 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1926 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1928 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1936 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1943 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1945 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1953 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1957 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1966 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1970 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    (yyval.ast) = ret;
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1979 "grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1980 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1981 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1982 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1983 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 1984 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1985 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1987 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1988 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1989 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1995 "grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2001 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2009 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2015 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2022 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2023 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2027 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2028 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2032 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2033 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2037 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2038 "grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3246 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -316;
  const short int
  ParserImplementation::yypact_[] =
  {
      -316,    53,  1005,  -316,  1643,  1643,  1643,  1643,  1643,  1643,
    1643,  1643,  1643,  1643,   539,    56,    37,    75,    37,  1097,
     162,  -316,   -26,    51,     0,   108,  -316,  -316,  -316,  1643,
    -316,   110,  -316,  1643,  -316,    87,    76,   113,   141,  -316,
      90,    -8,   161,    64,    66,   729,  -316,  -316,  -316,  -316,
    1005,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,   237,  -316,
     299,   163,  -316,  -316,   335,   214,    13,   254,   207,   171,
     184,   218,   221,   181,  -316,  -316,    19,  -316,    37,  -316,
     216,   253,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    -316,    31,   237,  -316,  -316,     7,   238,   532,  -316,    27,
     -11,   248,    34,  -316,   142,  -316,  -316,    27,    76,   135,
     210,   217,   142,  -316,    27,  1463,   230,   264,   266,  1097,
    1643,   298,    27,  1643,    19,   821,   127,    34,  1643,  1643,
    1189,  1281,  1189,   142,    36,   142,   168,    34,  1097,     0,
     190,   211,  -316,  -316,   913,   202,   336,   232,  -316,  1373,
    1643,   272,  -316,  1643,   297,  -316,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,
    1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,
    1643,  1643,  1643,  1643,  1643,  1643,  -316,  -316,  -316,  -316,
    -316,  -316,    56,    -7,  -316,   236,   310,  -316,  -316,  -316,
    -316,   161,  1643,  -316,  -316,   274,    20,   275,    76,  -316,
    -316,  -316,   349,   357,   264,  -316,   198,    82,    13,   292,
     333,   388,   410,   412,   415,   367,  -316,  -316,   431,   304,
     411,   161,   161,  -316,    38,  -316,    52,  -316,   389,    87,
     366,  -316,  -316,    58,    59,  -316,   308,  1189,  -316,  -316,
     312,   311,  -316,    65,   273,  -316,   142,    71,  -316,   142,
    -316,  -316,  -316,  -316,  -316,   216,  1643,   362,  -316,  -316,
      72,  -316,    12,  -316,    15,  -316,  -316,  -316,  -316,  -316,
     335,   335,   214,   214,   214,    13,    13,    13,    13,    13,
      13,   254,   254,   254,   254,   207,   171,   184,   218,   313,
     221,  -316,   634,   539,   395,  -316,   396,  -316,   441,   318,
    -316,   255,   317,   224,  -316,  1643,   315,    48,   421,   315,
    1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,
    1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,  1643,   198,
     422,   324,   327,  1097,   328,   378,  -316,  -316,  1097,  1097,
    -316,  -316,  -316,  -316,   142,   383,  -316,   142,    -3,   334,
    -316,   168,  1097,  -316,   330,  -316,  -316,  1553,  -316,  -316,
    -316,  1643,  -316,  -316,   436,   539,  1643,   339,   274,   337,
    -316,  -316,  -316,    73,  1643,  -316,  -316,   198,  1643,  1643,
    -316,    74,   163,  -316,    13,    13,    13,    13,    13,   292,
     292,   292,   292,   333,   388,   410,   412,   338,   415,  -316,
     342,   447,  1643,   347,   348,   416,   428,  -316,   356,  -316,
    -316,  -316,  -316,  -316,  1281,  1189,  1189,  -316,  -316,  1643,
    -316,  -316,  -316,  1643,   457,    78,  1189,   229,    27,  -316,
    -316,   359,    96,  1097,  1643,  1643,  1643,    97,  1189,  1189,
    1097,  1643,   428,  -316,   -18,    87,   360,   361,   363,  -316,
     104,  1643,  -316,   364,  -316,  -316,  -316,  1643,  1097,  -316,
    -316,   371,   105,  1097,   365,   370,  -316,    16,  -316,   372,
    -316,   428,  -316,  -316,  -316,  -316,  -316,   106,  -316,   374,
    -316,  1097,  1097,  -316,  -316,  -316,  1097,  1097,   375,  -316,
    1097,  -316,  -316,  1097,  -316,  -316,  -316,  -316
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,    33,     0,    33,     0,
       0,   133,     0,    33,   135,     0,   131,   128,   130,   273,
     129,     0,   134,     0,   132,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,     0,   277,    28,   162,     7,
       3,    23,    27,    35,    39,    38,    36,    37,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    51,    50,
      52,    53,   136,   126,   127,   161,   137,   138,   166,   178,
     179,   180,   183,   193,   197,   200,   204,   217,   227,   231,
     235,   239,   243,   247,   251,   267,     0,    88,    33,   135,
     154,   180,   189,   190,   192,   191,   184,   185,   186,   188,
     187,     0,   166,   167,   146,     0,   276,     0,    34,     0,
     120,     0,     0,    69,     0,    78,    77,     0,     0,     0,
       0,     0,   120,    58,     0,   271,     0,     0,     0,     0,
       0,   274,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    21,   120,     0,   120,     0,     0,     0,   135,
     128,   129,    54,    59,     0,     0,   155,     0,    24,     0,
       0,     0,   168,     0,     0,   169,   263,   260,   262,   261,
     266,   265,   256,   258,   257,   264,   259,   182,   181,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,   158,   160,   159,
     139,   165,   275,     0,   141,     0,   151,   147,   140,   144,
     101,    31,     0,   121,    73,    80,     0,     0,     0,    62,
      74,   100,     0,     0,     0,    57,     0,   180,   211,   222,
     229,   233,   237,   241,   245,   249,   253,   269,   272,     0,
       0,    31,    31,   111,     0,   102,     0,   112,     0,     0,
     113,   114,    61,     0,     0,    30,     0,    22,    25,    29,
       0,     0,    14,     0,     0,    15,   120,     0,    65,     0,
      63,    56,    55,    60,   153,     0,     0,     0,   172,   175,
       0,   174,     0,   164,     0,   171,   252,   194,   195,   196,
     198,   199,   203,   202,   201,   206,   205,   209,   210,   207,
     208,   221,   219,   218,   220,   228,   232,   236,   240,     0,
     244,   268,     0,     0,     0,   143,     0,   148,    32,     0,
      86,     0,     0,     0,    70,     0,   122,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,   117,   115,     0,     0,
       9,    26,    13,    11,   120,     0,    18,   120,     0,     0,
      67,     0,     0,    68,     0,   156,    20,     0,   173,   163,
     170,     0,   142,   145,     0,     0,     0,     0,    84,     0,
      79,    81,    82,     0,     0,   123,    75,     0,   273,     0,
      76,     0,   180,   254,   213,   212,   216,   214,   215,   226,
     224,   223,   225,   230,   234,   238,   242,     0,   246,   270,
       0,     0,     0,     0,     0,    91,   124,   104,     0,    93,
     103,    16,    19,    17,     0,    21,    21,    66,    64,     0,
     177,   176,   248,     0,     0,     0,    21,     0,     0,    87,
      72,     0,     0,     0,     0,   273,     0,     0,    21,    21,
       0,     0,   125,   107,     0,     0,     0,     0,     0,   157,
       0,     0,   152,     0,    83,    85,    92,   273,     0,    96,
     250,     0,     0,     0,     0,     0,    90,     0,   108,     0,
     105,   124,   116,    12,     8,    10,   149,     0,     5,     0,
      97,     0,     0,    98,     4,     6,   118,   118,     0,   150,
       0,    94,    99,   119,   109,   110,   106,    95
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -316,  -316,  -316,   290,  -316,  -316,   450,  -316,   109,  -150,
    -316,  -316,   458,   233,   126,    67,    -2,  -141,  -145,   -34,
    -316,  -316,  -135,  -316,  -316,  -316,   118,     6,  -316,   -12,
    -315,   -39,  -316,  -316,  -111,   164,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,    30,  -316,  -316,
    -316,  -316,  -316,   244,    -6,  -139,  -316,     5,  -316,  -316,
    -316,  -316,    62,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    -316,  -114,   504,   508,  -316,   -28,  -316,    60,  -316,    21,
     200,   183,   199,   155,     8,   316,   166,   320,   170,   322,
     172,   325,   174,   329,   173,  -316,  -316,  -316,  -316,  -112,
    -232,   455,    -9,  -316,  -316,  -312,   319,   -84
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   275,    48,    49,   338,   386,   299,   276,
      50,   277,    51,   278,   339,   138,   163,    53,    54,    55,
      56,    57,   164,    58,    59,   287,   288,   122,   347,   123,
     348,   124,   125,   236,   233,   415,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   447,   482,   483,   511,    69,
      70,    71,   270,   271,   534,   234,   416,   484,    72,    73,
      74,    75,    76,   115,   116,   225,   226,   337,    77,   165,
     166,   167,    78,    79,    80,   172,   300,    81,    82,    83,
      84,    85,    86,    87,   249,    88,   250,    89,   251,    90,
     252,    91,   253,    92,   254,    93,   255,    94,   256,    95,
     257,   351,    96,   258,   259,   142,   117,    97
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -161;
  const short int
  ParserImplementation::yytable_[] =
  {
        52,   146,   281,   155,   111,   229,   280,   237,   134,   279,
     222,   279,   216,   240,   282,   215,   285,   129,   215,   215,
     141,   135,   215,   341,   144,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   215,   230,   231,   238,   239,   283,
     333,   215,   147,   241,   509,   196,   197,   198,    52,   157,
     245,   417,   175,     3,   441,   215,   440,   301,   265,   114,
     267,   215,   215,   272,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   290,   391,   397,   215,   215,   306,   126,
     223,   215,   126,   119,   221,   127,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   136,   126,   215,
     215,   329,   470,   331,   126,   126,   471,   215,   215,   215,
     350,   156,   510,    15,    15,   118,   334,   289,   151,   423,
     340,   152,   232,   454,    15,    15,   455,   187,   188,   137,
      39,   264,   139,   437,   266,   439,   279,   263,    39,   273,
     274,   224,   132,   384,   158,    39,   399,   390,   526,   400,
      46,   342,   284,   120,   132,   140,   291,   143,    46,   220,
     148,   302,   293,   501,   304,    46,   373,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   393,   418,
     374,   394,   469,   268,   395,   519,   378,   379,   149,   385,
     126,   209,   155,   121,   121,   247,   213,   214,   269,   392,
     398,   468,   473,   210,   121,   121,   492,   349,   187,   188,
      15,    15,   307,   308,   309,   189,   145,    15,   126,   150,
     403,   130,   155,   155,   498,   503,   344,   409,   205,   206,
     207,   208,   516,   522,   529,   376,   211,   131,   212,   153,
     132,   227,   500,   242,   387,   451,   286,    15,   453,   194,
     195,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,    15,   101,   232,   346,   260,    15,   199,
     200,   201,   202,   203,   169,   461,   170,   171,   243,   462,
     121,   121,    47,   126,   217,   244,   189,   121,   187,   188,
     126,   215,   411,   218,   412,   487,   488,   494,   126,   486,
     133,   261,   219,   262,   279,   279,   493,   352,   353,   354,
     370,   355,  -160,   126,   126,   279,   235,   121,   504,   505,
     349,   204,   294,   408,   248,   218,   413,   279,   279,   295,
      47,   421,   218,  -159,   219,   126,   169,   489,   173,   174,
     303,   219,   289,   121,   357,   358,   359,   360,   121,   141,
     321,   322,   323,   324,   296,   429,   430,   431,   432,   356,
     335,   445,   191,   192,   193,   305,   449,   450,   349,   312,
     313,   314,   365,   366,   496,   388,   389,   371,   372,   336,
     458,   533,   533,   404,   310,   311,   345,   465,   315,   316,
     317,   318,   319,   320,   231,   126,  -158,   343,   361,   141,
     472,   422,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   422,   101,   422,   495,   362,
     363,   126,   364,   477,   367,   368,   375,   269,   380,   382,
     396,   383,   405,   406,   283,   401,   407,   410,   414,   419,
     442,   512,   443,   126,   490,   444,   448,   446,    13,    14,
      15,   452,   459,   456,   463,   464,   141,   502,   466,   467,
     474,   499,   507,   475,   422,   476,   478,   479,   506,   126,
      21,   480,   517,   481,   485,   491,    98,   513,   141,    99,
     497,   514,   154,   515,   518,   524,   520,    26,    27,   521,
     525,   523,   530,    28,   527,   536,   460,    30,   168,   457,
     381,    32,   508,   420,   377,    34,   528,   369,   112,   531,
     532,   535,   113,    40,    41,   325,    42,   433,   537,   126,
     326,   293,   434,   327,   422,   435,   190,   328,   436,   438,
     100,   332,     0,   330,     0,     0,     0,     0,     0,     0,
     248,   424,   425,   426,   427,   428,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,    98,    21,     0,
      99,     0,     0,   248,    98,     0,     0,    99,    26,    27,
       0,     0,     0,     0,    28,    26,    27,     0,    30,     0,
       0,    28,    32,     0,     0,    30,    34,     0,     0,    32,
       0,     0,     0,    34,    40,    41,     0,    42,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,   228,     0,   100,     4,
       5,     0,     0,   248,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    28,     0,     0,     0,
      30,     0,     0,     0,    32,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     4,     5,     0,     0,   402,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   128,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    98,     0,     0,   159,    25,     0,
       0,     0,     0,     0,     0,    26,   160,     0,     0,     0,
       0,    28,    29,     0,     0,   161,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     4,     5,    45,   162,
      46,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     128,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,    98,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     4,     5,
      45,   162,    46,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   128,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    98,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       4,     5,    45,   292,    46,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
      23,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     4,     5,    45,     0,    46,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   128,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,    98,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,     0,     4,     5,    45,     0,    46,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     4,     5,    45,     0,
      46,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     128,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,    98,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     4,     5,
     100,     0,    46,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     4,     5,
       0,   298,   100,     6,     7,     8,     9,    10,    11,    12,
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
       0,     0,     0,     0,     0,     0,     0,   297,     4,     5,
       0,     0,   100,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,    35,   152,    42,    13,   117,   151,   121,    20,   150,
       3,   152,    96,   124,   153,     3,   155,    19,     3,     3,
      29,    47,     3,     3,    33,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,   119,    47,     3,   122,     3,
      47,     3,    36,   127,    62,    32,    33,    34,    50,    43,
     134,     3,    80,     0,   369,     3,   368,   169,   142,     3,
     144,     3,     3,   147,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   157,     3,     3,     3,     3,   190,    17,
      73,     3,    20,    16,   112,    18,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   123,    36,     3,
       3,   213,   417,   215,    42,    43,   418,     3,     3,     3,
      28,    47,   130,    49,    49,    78,   123,   156,   126,   351,
     232,   129,   133,   126,    49,    49,   129,    45,    46,    78,
     111,   140,   132,   365,   143,   367,   277,   139,   111,   148,
     149,   134,    78,    78,    78,   111,   134,   286,   132,   134,
     131,   131,   116,    78,    78,    47,   158,    47,   131,   128,
      47,   170,   164,   475,   173,   131,   128,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   289,   131,
     128,   295,   414,    56,   296,   497,   128,   128,    47,   124,
     128,    20,   231,   129,   129,   135,    15,    16,    71,   128,
     128,   128,   128,    19,   129,   129,   128,   246,    45,    46,
      49,    49,   191,   192,   193,   133,   129,    49,   156,   129,
     332,    59,   261,   262,   128,   128,   238,   341,    21,    22,
      23,    24,   128,   128,   128,   269,    18,    75,    17,    78,
      78,     3,   474,   108,   283,   384,    78,    49,   387,    35,
      36,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    49,   214,   133,    78,    47,    49,    25,
      26,    27,    28,    29,    47,   397,    49,    50,    78,   401,
     129,   129,     2,   231,    78,    78,   133,   129,    45,    46,
     238,     3,    78,    87,   343,   455,   456,    78,   246,   454,
      20,    47,    96,    47,   455,   456,   466,    25,    26,    27,
     260,    29,   132,   261,   262,   466,    78,   129,   478,   479,
     369,    77,   130,    78,   135,    87,   345,   478,   479,     3,
      50,   350,    87,   132,    96,   283,    47,   459,    49,    50,
      78,    96,   391,   129,    21,    22,    23,    24,   129,   368,
     205,   206,   207,   208,   132,   357,   358,   359,   360,    77,
     134,   373,    37,    38,    39,    78,   378,   379,   417,   196,
     197,   198,    15,    16,   468,   112,   113,   261,   262,    79,
     392,   526,   527,   333,   194,   195,    47,   406,   199,   200,
     201,   202,   203,   204,    47,   343,   132,   132,    20,   418,
     419,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   467,    19,
      18,   369,    17,   442,     3,   131,    47,    71,   130,   127,
      78,   130,    47,    47,     3,   132,   128,   130,   133,    28,
      28,   485,   128,   391,   463,   128,    78,   129,    47,    48,
      49,    78,   132,   129,    28,   405,   475,   476,   129,   132,
     132,   473,   481,   131,   414,    28,   129,   129,   480,   417,
      69,    65,   491,    55,   128,    28,    75,   127,   497,    78,
     131,   130,    42,   130,   130,   130,   498,    86,    87,   128,
     130,   503,   128,    92,   132,   130,   397,    96,    50,   391,
     277,   100,   482,   349,   270,   104,   511,   106,    14,   521,
     522,   527,    14,   112,   113,   209,   115,   361,   530,   467,
     210,   533,   362,   211,   474,   363,    81,   212,   364,   366,
     129,   222,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    69,    -1,
      78,    -1,    -1,   414,    75,    -1,    -1,    78,    86,    87,
      -1,    -1,    -1,    -1,    92,    86,    87,    -1,    96,    -1,
      -1,    92,   100,    -1,    -1,    96,   104,    -1,    -1,   100,
      -1,    -1,    -1,   104,   112,   113,    -1,   115,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   134,    -1,   129,    35,
      36,    -1,    -1,   474,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    35,    36,    -1,    -1,   134,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,
     111,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    35,    36,   129,   130,
     131,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    67,    -1,
      69,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    98,
      -1,   100,   101,    -1,    -1,   104,   105,   106,    -1,   108,
     109,    -1,   111,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    35,    36,
     129,   130,   131,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      67,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,   106,
      -1,   108,   109,    -1,   111,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      35,    36,   129,   130,   131,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,
     105,   106,    -1,   108,   109,    -1,   111,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    35,    36,   129,    -1,   131,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,
      -1,   104,   105,   106,    -1,   108,   109,    -1,   111,   112,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    35,    36,   129,    -1,   131,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,
     111,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    35,    36,   129,    -1,
     131,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    98,
      -1,   100,   101,    -1,    -1,   104,   105,   106,    -1,   108,
     109,    -1,   111,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    35,    36,
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
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129
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
     112,   113,   115,   122,   125,   129,   131,   138,   139,   140,
     145,   147,   151,   152,   153,   154,   155,   156,   158,   159,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   184,
     185,   186,   193,   194,   195,   196,   197,   203,   207,   208,
     209,   212,   213,   214,   215,   216,   217,   218,   220,   222,
     224,   226,   228,   230,   232,   234,   237,   242,    75,    78,
     129,   212,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   237,   207,   208,     3,   198,   199,   241,    78,   150,
      78,   129,   162,   164,   166,   167,   197,   150,    59,   151,
      59,    75,    78,   138,   164,    47,   123,    78,   150,   132,
      47,   237,   240,    47,   237,   129,   154,   162,    47,    47,
     129,   126,   129,    78,   141,   166,    47,   162,    78,    78,
      87,    96,   130,   151,   157,   204,   205,   206,   147,    47,
      49,    50,   210,    49,    50,   210,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   133,
     236,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    77,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   242,    78,    87,    96,
     128,   210,     3,    73,   134,   200,   201,     3,   134,   234,
     242,    47,   133,   169,   190,    78,   168,   206,     3,   242,
     169,   242,   108,    78,    78,   242,   106,   212,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   238,   239,
      47,    47,    47,   151,   237,   242,   237,   242,    56,    71,
     187,   188,   242,   237,   237,   138,   144,   146,   148,   152,
     153,   144,   190,     3,   116,   190,    78,   160,   161,   166,
     242,   151,   130,   151,   130,     3,   132,   124,   128,   143,
     211,   234,   237,    78,   237,    78,   234,   214,   214,   214,
     215,   215,   216,   216,   216,   217,   217,   217,   217,   217,
     217,   218,   218,   218,   218,   220,   222,   224,   226,   234,
     228,   234,   241,    47,   123,   134,    79,   202,   141,   149,
     234,     3,   131,   132,   164,    47,    78,   163,   165,   166,
      28,   236,    25,    26,    27,    29,    77,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   131,   106,
     212,   149,   149,   128,   128,    47,   154,   188,   128,   128,
     130,   148,   127,   130,    78,   124,   142,   166,   112,   113,
     190,     3,   128,   169,   206,   234,    78,     3,   128,   134,
     134,   132,   134,   234,   212,    47,    47,   128,    78,   206,
     130,    78,   166,   237,   133,   170,   191,     3,   131,    28,
     170,   237,   212,   235,   217,   217,   217,   217,   217,   219,
     219,   219,   219,   221,   223,   225,   227,   235,   229,   235,
     240,   165,    28,   128,   128,   151,   129,   180,    78,   151,
     151,   190,    78,   190,   126,   129,   129,   161,   151,   132,
     143,   234,   234,    28,   212,   237,   129,   132,   128,   235,
     165,   240,   237,   128,   132,   131,    28,   237,   129,   129,
      65,    55,   181,   182,   192,   128,   153,   144,   144,   234,
     237,    28,   128,   144,    78,   166,   242,   131,   128,   151,
     235,   240,   237,   128,   144,   144,   151,   237,   182,    62,
     130,   183,   154,   127,   130,   130,   128,   237,   130,   240,
     151,   128,   128,   151,   130,   130,   132,   132,   192,   128,
     128,   151,   151,   157,   189,   189,   130,   151
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
     125,    59,    58,    61,    93
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
     175,   176,   177,   178,   179,   180,   180,   181,   181,   182,
     183,   184,   185,   186,   186,   186,   187,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   193,   193,
     193,   194,   195,   195,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   197,   198,   198,   199,   199,   200,   201,
     201,   202,   202,   203,   204,   204,   205,   205,   206,   206,
     206,   207,   207,   207,   207,   207,   208,   208,   209,   209,
     209,   209,   210,   210,   211,   211,   211,   211,   212,   212,
     213,   213,   213,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   215,   215,   215,   215,   216,   216,   216,
     217,   217,   217,   217,   218,   218,   218,   218,   218,   218,
     218,   219,   219,   219,   219,   219,   219,   220,   220,   220,
     220,   220,   221,   221,   221,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   226,   226,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   241,   241,   242,   242
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
       3,     3,     3,     5,     5,     3,     5,     1,     2,     4,
       3,     3,     3,     3,     3,     4,     5,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     5,     4,     2,     4,     1,     2,     2,     6,
       7,     0,     4,     3,     0,     1,     3,     5,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     2,     2,     2,
       4,     3,     2,     3,     1,     1,     3,     3,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       5,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     0,     1,     0,     1,     0,     1,     1,     1
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
  "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "')'", "'{'", "'}'", "';'",
  "':'", "'='", "']'", "$accept", "program", "$@1", "function_declaration",
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
  "iteration_statement", "continue_statement", "break_statement",
  "return_statement", "with_statement", "switch_statement", "case_block",
  "case_clauses", "case_clause", "default_clause", "labelled_statement",
  "throw_statement", "try_statement", "catch", "finally",
  "statement_list__opt", "initialiser__opt", "initialiser_no_in__opt",
  "case_clauses__opt", "literal", "null_literal", "boolean_literal",
  "primary_expression", "array_literal", "element_list", "elision",
  "array_comprehensions", "array_comprehension_iteration",
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
     113,   126,   153,   127,    -1,    78,   190,    -1,   166,   190,
      -1,   141,     3,    78,   190,    -1,   141,     3,   166,   190,
      -1,   141,     3,   142,    -1,   124,    78,    -1,   124,    78,
      -1,    -1,   146,    -1,   147,    -1,   145,   147,    -1,   148,
      -1,   146,   148,    -1,   151,    -1,   138,    -1,   152,    -1,
     138,    -1,    -1,   141,    -1,    -1,    78,    -1,   152,    -1,
     155,    -1,   156,    -1,   154,    -1,   153,    -1,   158,    -1,
     159,    -1,   171,    -1,   172,    -1,   173,    -1,   174,    -1,
     175,    -1,   176,    -1,   177,    -1,   178,    -1,   184,    -1,
     179,    -1,   185,    -1,   186,    -1,   129,   130,    -1,   129,
     157,   130,    -1,   125,    78,   151,    -1,    67,   164,   242,
      -1,    67,   138,    -1,   151,    -1,   157,   151,    -1,   106,
     162,   242,    -1,    59,   162,   242,    -1,   122,   162,   242,
      -1,   122,    47,   160,   128,   151,    -1,   161,    -1,   160,
       3,   161,    -1,    78,   190,    -1,   166,   169,    -1,   164,
      -1,   162,     3,   164,    -1,   165,    -1,   163,     3,   165,
      -1,    78,   190,    -1,   166,   169,    -1,    78,   191,    -1,
     166,   170,    -1,   197,    -1,   167,    -1,   129,   168,   131,
     130,    -1,    78,    -1,   206,   132,    78,    -1,   206,   132,
     166,    -1,   168,     3,   206,   132,    78,    -1,   168,     3,
      78,    -1,   168,     3,   206,   132,   166,    -1,   133,   234,
      -1,   133,   235,    -1,   242,    -1,   237,   242,    -1,    79,
      47,   237,   128,   151,    65,   151,    -1,    79,    47,   237,
     128,   151,    -1,    63,   151,   108,    47,   237,   128,   242,
      -1,   108,    47,   237,   128,   151,    -1,    73,    47,   239,
     131,   240,   131,   240,   128,   151,    -1,    73,    47,   106,
     163,   131,   240,   131,   240,   128,   151,    -1,    73,    47,
     212,    28,   237,   128,   151,    -1,    73,    47,   106,   165,
      28,   237,   128,   151,    -1,    73,   123,    47,   212,    28,
     237,   128,   151,    -1,    73,   123,    47,   106,   165,    28,
     237,   128,   151,    -1,    60,   150,   242,    -1,    53,   150,
     242,    -1,    93,   240,   242,    -1,   109,    47,   237,   128,
     151,    -1,    98,    47,   237,   128,   180,    -1,   129,   192,
     130,    -1,   129,   192,   183,   192,   130,    -1,   182,    -1,
     181,   182,    -1,    55,   237,   132,   189,    -1,    62,   132,
     189,    -1,    78,   132,   151,    -1,   101,   237,   242,    -1,
     105,   154,   187,    -1,   105,   154,   188,    -1,   105,   154,
     187,   188,    -1,    56,    47,    78,   128,   154,    -1,    71,
     154,    -1,    -1,   157,    -1,    -1,   169,    -1,    -1,   170,
      -1,    -1,   181,    -1,   194,    -1,   195,    -1,    87,    -1,
      96,    -1,    92,    -1,    86,    -1,   104,    -1,    69,    -1,
     100,    -1,    78,    -1,   193,    -1,   197,    -1,   203,    -1,
      47,   237,   128,    -1,    49,   241,   134,    -1,    49,   198,
     134,    -1,    49,   198,     3,   241,   134,    -1,    49,   198,
     200,   134,    -1,   241,   234,    -1,   198,     3,   241,   234,
      -1,     3,    -1,   199,     3,    -1,   201,   202,    -1,    73,
      47,   212,    28,   237,   128,    -1,    73,   123,    47,   212,
      28,   237,   128,    -1,    -1,    79,    47,   237,   128,    -1,
     129,   204,   130,    -1,    -1,   205,    -1,   206,   132,   234,
      -1,   205,     3,   206,   132,   234,    -1,    78,    -1,    96,
      -1,    87,    -1,   196,    -1,   139,    -1,   207,    49,   237,
     134,    -1,   207,    50,    78,    -1,    48,   207,   210,    -1,
     207,    -1,    48,   208,    -1,   207,   210,    -1,   209,   210,
      -1,   209,    49,   237,   134,    -1,   209,    50,    78,    -1,
      47,   128,    -1,    47,   211,   128,    -1,   234,    -1,   143,
      -1,   211,     3,   234,    -1,   211,     3,   143,    -1,   208,
      -1,   209,    -1,   212,    -1,   212,    46,    -1,   212,    45,
      -1,   213,    -1,    42,   214,    -1,    43,   214,    -1,    44,
     214,    -1,    46,   214,    -1,    45,   214,    -1,    35,   214,
      -1,    36,   214,    -1,    41,   214,    -1,    40,   214,    -1,
     214,    -1,   215,    37,   214,    -1,   215,    38,   214,    -1,
     215,    39,   214,    -1,   215,    -1,   216,    35,   215,    -1,
     216,    36,   215,    -1,   216,    -1,   217,    34,   216,    -1,
     217,    33,   216,    -1,   217,    32,   216,    -1,   217,    -1,
     218,    26,   217,    -1,   218,    25,   217,    -1,   218,    29,
     217,    -1,   218,    77,   217,    -1,   218,    27,   217,    -1,
     218,    28,   217,    -1,   217,    -1,   219,    26,   217,    -1,
     219,    25,   217,    -1,   219,    29,   217,    -1,   219,    77,
     217,    -1,   219,    27,   217,    -1,   218,    -1,   220,    23,
     218,    -1,   220,    22,   218,    -1,   220,    24,   218,    -1,
     220,    21,   218,    -1,   219,    -1,   221,    23,   219,    -1,
     221,    22,   219,    -1,   221,    24,   219,    -1,   221,    21,
     219,    -1,   220,    -1,   222,    20,   220,    -1,   221,    -1,
     223,    20,   221,    -1,   222,    -1,   224,    19,   222,    -1,
     223,    -1,   225,    19,   223,    -1,   224,    -1,   226,    18,
     224,    -1,   225,    -1,   227,    18,   225,    -1,   226,    -1,
     228,    17,   226,    -1,   227,    -1,   229,    17,   227,    -1,
     228,    -1,   230,    16,   228,    -1,   229,    -1,   231,    16,
     229,    -1,   230,    -1,   230,    15,   234,   132,   234,    -1,
     231,    -1,   231,    15,   235,   132,   235,    -1,   232,    -1,
     212,   236,   234,    -1,   233,    -1,   212,   236,   235,    -1,
     133,    -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,
       5,    -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,
       9,    -1,     8,    -1,   234,    -1,   237,     3,   234,    -1,
     235,    -1,   238,     3,   235,    -1,    -1,   238,    -1,    -1,
     237,    -1,    -1,   199,    -1,   131,    -1,   111,    -1
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
     374,   378,   382,   386,   392,   398,   402,   408,   410,   413,
     418,   422,   426,   430,   434,   438,   443,   449,   452,   453,
     455,   456,   458,   459,   461,   462,   464,   466,   468,   470,
     472,   474,   476,   478,   480,   482,   484,   486,   488,   490,
     494,   498,   502,   508,   513,   516,   521,   523,   526,   529,
     536,   544,   545,   550,   554,   555,   557,   561,   567,   569,
     571,   573,   575,   577,   582,   586,   590,   592,   595,   598,
     601,   606,   610,   613,   617,   619,   621,   625,   629,   631,
     633,   635,   638,   641,   643,   646,   649,   652,   655,   658,
     661,   664,   667,   670,   672,   676,   680,   684,   686,   690,
     694,   696,   700,   704,   708,   710,   714,   718,   722,   726,
     730,   734,   736,   740,   744,   748,   752,   756,   758,   762,
     766,   770,   774,   776,   780,   784,   788,   792,   794,   798,
     800,   804,   806,   810,   812,   816,   818,   822,   824,   828,
     830,   834,   836,   840,   842,   846,   848,   852,   854,   860,
     862,   868,   870,   874,   876,   880,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   900,   902,   904,   906,   910,
     912,   916,   917,   919,   920,   922,   923,   925,   927
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   330,   330,   330,   344,   360,   375,   384,   397,   405,
     413,   421,   429,   437,   461,   476,   486,   495,   504,   518,
     534,   543,   544,   548,   554,   562,   568,   576,   577,   586,
     587,   596,   597,   604,   605,   614,   615,   620,   628,   633,
     637,   642,   646,   651,   656,   661,   666,   671,   676,   681,
     686,   691,   696,   701,   709,   715,   725,   738,   744,   754,
     762,   771,   778,   785,   795,   804,   810,   817,   824,   834,
     842,   852,   858,   866,   873,   883,   890,   901,   905,   912,
     922,   930,   940,   950,   959,   966,   976,   980,   984,   988,
     997,  1004,  1014,  1021,  1028,  1039,  1050,  1060,  1071,  1081,
    1094,  1103,  1112,  1121,  1131,  1141,  1145,  1154,  1160,  1168,
    1178,  1188,  1200,  1209,  1217,  1225,  1236,  1245,  1252,  1253,
    1257,  1258,  1262,  1263,  1267,  1268,  1272,  1273,  1274,  1280,
    1286,  1295,  1304,  1310,  1319,  1325,  1331,  1332,  1333,  1334,
    1342,  1351,  1357,  1366,  1376,  1385,  1396,  1397,  1402,  1410,
    1417,  1427,  1428,  1437,  1446,  1449,  1456,  1464,  1473,  1479,
    1485,  1494,  1498,  1502,  1514,  1528,  1543,  1544,  1553,  1565,
    1577,  1589,  1606,  1607,  1611,  1617,  1623,  1628,  1636,  1637,
    1641,  1645,  1651,  1660,  1661,  1667,  1673,  1679,  1685,  1691,
    1697,  1703,  1709,  1718,  1719,  1723,  1727,  1734,  1735,  1739,
    1746,  1747,  1751,  1755,  1762,  1763,  1767,  1771,  1775,  1779,
    1783,  1790,  1791,  1795,  1799,  1803,  1807,  1814,  1815,  1819,
    1823,  1827,  1834,  1835,  1839,  1843,  1847,  1854,  1855,  1862,
    1863,  1870,  1871,  1878,  1879,  1886,  1887,  1894,  1895,  1902,
    1903,  1910,  1911,  1918,  1919,  1926,  1927,  1934,  1935,  1943,
    1944,  1952,  1956,  1965,  1969,  1979,  1980,  1981,  1982,  1983,
    1984,  1985,  1986,  1987,  1988,  1989,  1990,  1994,  2000,  2008,
    2014,  2022,  2023,  2027,  2028,  2032,  2033,  2037,  2038
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
       2,     2,     2,     2,     2,     2,     2,     2,   132,   131,
      26,   133,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   134,    19,     2,     2,     2,     2,     2,
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
  const int ParserImplementation::yylast_ = 1772;
  const int ParserImplementation::yynnts_ = 108;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 135;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 365;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4540 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2041 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


