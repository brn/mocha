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
  binary->Line( connector->GetLineNumber() );                           \
  _4 = binary;                                                          \

#define COMPARE_ACTION(type,_1,_3,_4)                                   \
  CompareExp* compare = ManagedHandle::Retain( new CompareExp( type , _1 , _3 ) ); \
  compare->Line( connector->GetLineNumber() );                           \
  _4 = compare;                                                         \

  Empty* GetEmptyNode() {
    return ManagedHandle::Retain<Empty>();
  }
  


/* Line 293 of lalr1.cc  */
#line 74 "grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 83 "grammar.tab.cc"

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
#line 169 "grammar.tab.cc"

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
#line 334 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 335 "grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 349 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
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
#line 366 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
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
#line 382 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    fn->Name( (yysemantic_stack_[(8) - (2)].ast) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 391 "grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 405 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].node_list) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 414 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 423 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].node_list) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 433 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 443 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(5) - (2)].node_list) );
    fn->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    fn->FunctionType( Function::kShorten );
    (yyval.function) = fn;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 453 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(5) - (2)].node_list) );
    fn->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    fn->FunctionType( Function::kShorten );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 464 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    fn->FunctionType( Function::kShorten );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 475 "grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    fn->FunctionType( Function::kShorten );
    (yyval.function) = fn;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 489 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 509 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 525 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].ast) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 536 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 546 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(4) - (3)].ast)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 556 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( connector->GetLineNumber() );
    value->Node( (yysemantic_stack_[(3) - (3)].ast) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 571 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 588 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 597 "grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 598 "grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 603 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 611 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 621 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 629 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 638 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 640 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 649 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 651 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 660 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 662 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 668 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 670 "grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 678 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 680 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 685 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 693 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 697 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 702 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 707 "grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 711 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 716 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 721 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 726 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 731 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 736 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 741 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 746 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 751 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 756 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 761 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 766 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 774 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 781 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 792 "grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 805 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(3) - (2)].value_node) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 812 "grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].function) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 823 "grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 831 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 842 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 850 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 858 "grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 869 "grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 879 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 885 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 892 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 900 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].ast) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 911 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 919 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 929 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 935 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 943 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 951 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 961 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 969 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 980 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 984 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 991 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    if ( (yysemantic_stack_[(3) - (2)].opt) ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    value->Line( connector->GetLineNumber() );
    (yyval.ast) = value;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1001 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1008 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->AddChild( (yysemantic_stack_[(5) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(5) - (2)].node_list)->Line() );
    if ( (yysemantic_stack_[(5) - (4)].opt) ) {
      value->AddChild( GetEmptyNode() );
    }
    (yyval.ast) = value;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1021 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    list->Line( (yysemantic_stack_[(2) - (2)].info)->GetLineNumber() );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1033 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1043 "grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(4) - (4)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1064 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->Append( (yysemantic_stack_[(4) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    list->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    list->AddChild( node );
    (yyval.node_list) = list;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1085 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( node );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1097 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1107 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1117 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1125 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1135 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1139 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1143 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1148 "grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(2) - (1)].expression)->Line() );
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1158 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1167 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1179 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1187 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1195 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kFor ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(9) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(9) - (5)].ast) );
    list->AddChild( (yysemantic_stack_[(9) - (7)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(9) - (9)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1207 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(10) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(10) - (4)].node_list) );
    list->AddChild( (yysemantic_stack_[(10) - (6)].ast) );
    list->AddChild( (yysemantic_stack_[(10) - (8)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(10) - (10)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1219 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(7) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(7) - (5)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1230 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForInWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(8) - (4)].value_node) );
    list->AddChild( (yysemantic_stack_[(8) - (6)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(8) - (8)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1242 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(8) - (4)].ast) );
    list->AddChild( (yysemantic_stack_[(8) - (6)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(8) - (8)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1253 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForEachWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(9) - (5)].value_node) );
    list->AddChild( (yysemantic_stack_[(9) - (7)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(9) - (9)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1267 "grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1277 "grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1287 "grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1297 "grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1308 "grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1319 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1346 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1357 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1368 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (1)].info) );
    value->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    LabelledStmt *label = ManagedHandle::Retain<LabelledStmt>();
    label->AddChild( value );
    label->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.labelled_stmt) = label;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1391 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1400 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1409 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1421 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1432 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1439 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1440 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1444 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1445 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1449 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1450 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1454 "grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1459 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1460 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1462 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1469 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1476 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1486 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1496 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1503 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1513 "grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1520 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1527 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1528 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1530 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1538 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    if ( (yysemantic_stack_[(3) - (2)].opt) ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    value->Line( connector->GetLineNumber() );
    (yyval.ast) = value;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1548 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1555 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->AddChild( (yysemantic_stack_[(5) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(5) - (2)].node_list)->Line() );
    if ( (yysemantic_stack_[(5) - (4)].opt) ) {
      value->AddChild( GetEmptyNode() );
    }
    (yyval.ast) = value;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1565 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1576 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1586 "grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1603 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1611 "grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1618 "grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1627 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1638 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    value->Node( (yysemantic_stack_[(3) - (2)].ast) );
    if ( !(yysemantic_stack_[(3) - (2)].ast)->IsEmpty() ) {
      value->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    } else {
      value->Line( connector->GetLineNumber() );
    }
    (yyval.ast) = value;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1652 "grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1656 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1672 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1682 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1689 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1696 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1706 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1710 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(4) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(4) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Line( (yysemantic_stack_[(4) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(4) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(4) - (3)].expression) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1727 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (1)].ast) )->Depth() + 1;
    }
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(3) - (1)].ast) );
    exp->Args( value );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1742 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (2)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (2)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNew ) );
    exp->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    exp->Callable( (yysemantic_stack_[(3) - (2)].ast) );
    exp->Args( (yysemantic_stack_[(3) - (3)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1757 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1759 "grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1769 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(2) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(2) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(2) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(2) - (2)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1782 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(2) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(2) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kNormal ) );
    exp->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(2) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(2) - (2)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(4) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(4) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kBracket ) );
    exp->Line( (yysemantic_stack_[(4) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(4) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(4) - (3)].expression) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1808 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (1)].ast) )->Depth() + 1;
    }
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kDot ) );
    exp->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(3) - (1)].ast) );
    exp->Args( value );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1825 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1826 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1831 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1837 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1843 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1848 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1855 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1856 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1861 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1865 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1872 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1881 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1883 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1897 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1911 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1918 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1925 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1932 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1939 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1948 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1950 "grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1958 "grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1964 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1966 "grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1970 "grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1976 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1978 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1982 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1992 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1994 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1998 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2002 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2006 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2010 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2020 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2022 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2026 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2030 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2034 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2038 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2044 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2046 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2050 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2054 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2064 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2066 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2070 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2074 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2078 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2084 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2086 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2092 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2094 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2100 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2102 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2108 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2110 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2116 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2118 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2124 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2126 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2132 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2134 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2140 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2142 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2148 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2150 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2156 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2158 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2164 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2166 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2174 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2176 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2185 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2189 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2199 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2203 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2213 "grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2214 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2215 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2216 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2217 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2218 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2219 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2220 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2221 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2222 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2223 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2224 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2229 "grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2236 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2244 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2251 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2258 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2259 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2263 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2264 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2268 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2269 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2273 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2274 "grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3518 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -357;
  const short int
  ParserImplementation::yypact_[] =
  {
      -357,    76,   813,  -357,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1552,  1552,  1626,    35,   -52,     7,   -52,   908,
      68,  -357,   -12,     0,   -29,    78,  -357,  -357,  -357,  1552,
    -357,    86,  -357,  1552,  -357,   -42,   170,   106,   114,  -357,
     -46,    23,   200,    53,   -52,   519,  -357,  -357,  -357,  -357,
     813,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    74,  -357,
     185,   512,  -357,  -357,   156,   151,   270,   312,   285,   125,
     154,   157,   195,   303,  -357,  -357,    18,  -357,   -52,  -357,
      32,   278,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,    38,    74,  -357,  -357,     8,   186,  1098,  -357,   -48,
      35,   -28,   150,    19,  -357,    83,  -357,  -357,   -48,   170,
     113,   146,   158,    83,  -357,   -48,  1372,   191,   193,   198,
     908,  1552,   249,   -48,  1552,    18,   617,    47,    19,  1552,
    1552,  1552,  1003,  -357,  1003,  -357,    83,    26,    83,   227,
      19,   908,   -29,   161,   182,  -357,  -357,   715,   223,    22,
     194,  -357,  1282,  1552,   206,  -357,  1552,   243,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  -357,
    -357,  -357,  -357,  -357,  -357,    35,    -8,  -357,   199,   282,
    -357,  -357,  -357,  -357,    27,    59,   200,  1552,  -357,  -357,
     224,    24,   248,   170,  -357,  -357,  -357,   319,   343,   193,
    -357,   233,   197,   270,   342,   311,   372,   374,   376,   378,
     335,  -357,  -357,   393,   266,  1576,   200,   200,  -357,    40,
    -357,    41,  -357,   358,   -42,   337,  -357,  -357,    42,    43,
    -357,  -357,   276,  1003,  -357,  -357,   279,  -357,   169,   264,
    -357,    83,    44,  -357,    83,  -357,  -357,  -357,  -357,  -357,
      32,  -357,  1552,   332,  -357,  -357,    48,  -357,    29,  -357,
      31,  -357,  -357,  -357,  -357,  -357,   156,   156,   151,   151,
     151,   270,   270,   270,   270,   270,   270,   312,   312,   312,
     312,   285,   125,   154,   157,   280,   195,  -357,  1190,  1626,
     364,  -357,   365,  -357,    35,  -357,  -357,  -357,  -357,   411,
     287,  -357,   214,   286,   234,  -357,  1552,   283,    25,   390,
     283,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
     233,   412,   313,   314,   908,   310,   385,  -357,  -357,   908,
     908,  -357,  -357,  -357,    83,   386,  -357,    83,    87,   187,
    -357,   227,   908,  -357,   336,  -357,  -357,  1462,  -357,  -357,
    -357,  1552,  -357,  -357,   415,  1626,  1552,   166,   339,   224,
     338,  -357,  -357,  -357,    50,  1552,  -357,  -357,   233,  1552,
    1552,  -357,    51,   512,  -357,   270,   270,   270,   270,   270,
     342,   342,   342,   342,   311,   372,   374,   376,   340,   378,
    -357,   333,   442,  1552,   345,   347,   407,   422,  -357,   350,
    -357,  -357,  -357,  -357,  -357,  1003,  -357,  1003,  -357,  -357,
    -357,  1552,  -357,  -357,  -357,  1552,   451,    52,  -357,  -357,
    -357,  1003,   236,   -48,  -357,  -357,   348,    55,   908,  1552,
    1552,  1552,    57,  1003,  1003,   908,  1552,   422,  -357,    54,
     -42,   353,   354,  -357,    72,  1552,  -357,   359,  -357,  -357,
    -357,  1552,   908,  -357,  -357,   360,    95,   908,   361,   362,
    -357,    15,  -357,   357,  -357,   422,  -357,  -357,  -357,  -357,
      98,  -357,   366,  -357,   908,   908,  -357,  -357,  -357,   908,
     908,   367,  -357,   908,  -357,  -357,   908,  -357,  -357,  -357,
    -357
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,    36,     0,    36,     0,
       0,   143,     0,    36,   145,     0,   141,   138,   140,   283,
     139,     0,   144,     0,   142,     0,     0,     0,     0,   288,
       0,     0,     0,     0,    36,     0,   287,    31,   172,     7,
       3,    26,    30,    38,    42,    41,    39,    40,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    53,
      55,    56,   146,   136,   137,   171,   147,   148,   176,   188,
     189,   190,   193,   203,   207,   210,   214,   227,   237,   241,
     245,   249,   253,   257,   261,   277,     0,    98,    36,   145,
     164,   190,   199,   200,   202,   201,   194,   195,   196,   198,
     197,     0,   176,   177,   156,     0,   286,     0,    37,     0,
     285,   130,     0,     0,    72,     0,    80,    81,     0,     0,
       0,     0,     0,   130,    61,     0,   281,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    15,    24,    14,   130,     0,   130,     0,
       0,     0,   145,   138,   139,    57,    62,     0,     0,     0,
       0,    27,     0,     0,     0,   178,     0,     0,   179,   273,
     270,   272,   271,   276,   275,   266,   268,   267,   274,   269,
     192,   191,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     168,   170,   169,   149,   175,   285,     0,   151,     0,   161,
     157,   150,   154,   111,     0,     0,    34,     0,   131,    76,
      90,     0,     0,     0,    65,    77,   110,     0,     0,     0,
      60,     0,   190,   221,   232,   239,   243,   247,   251,   255,
     259,   263,   279,   282,     0,     0,    34,    34,   121,     0,
     112,     0,   122,     0,     0,   123,   124,    64,     0,     0,
      16,    33,     0,    25,    28,    32,     0,    17,     0,     0,
      18,   130,     0,    68,     0,    66,    59,    58,    63,   163,
       0,   165,     0,     0,   182,   185,     0,   184,     0,   174,
       0,   181,   262,   204,   205,   206,   208,   209,   213,   212,
     211,   216,   215,   219,   220,   217,   218,   231,   229,   228,
     230,   238,   242,   246,   250,     0,   254,   278,     0,     0,
       0,   153,     0,   158,   285,    83,    85,    82,    86,    35,
       0,    96,     0,     0,     0,    73,     0,   132,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,     0,     0,     0,   127,   125,     0,
       0,     9,    29,    11,   130,     0,    21,   130,     0,     0,
      70,     0,     0,    71,     0,   166,    23,     0,   183,   173,
     180,     0,   152,   155,     0,     0,     0,     0,     0,    94,
       0,    89,    91,    92,     0,     0,   133,    78,     0,   283,
       0,    79,     0,   190,   264,   223,   222,   226,   224,   225,
     236,   234,   233,   235,   240,   244,   248,   252,     0,   256,
     280,     0,     0,     0,     0,     0,   101,   134,   114,     0,
     103,   113,    19,    22,    20,    24,    12,    24,    13,    69,
      67,     0,   187,   186,   258,     0,     0,     0,    87,    84,
      88,    24,     0,     0,    97,    75,     0,     0,     0,     0,
     283,     0,     0,    24,    24,     0,     0,   135,   117,     0,
       0,     0,     0,   167,     0,     0,   162,     0,    93,    95,
     102,   283,     0,   106,   260,     0,     0,     0,     0,     0,
     100,     0,   118,     0,   115,   134,   126,     8,    10,   159,
       0,     5,     0,   107,     0,     0,   108,     4,     6,   128,
     128,     0,   160,     0,   104,   109,   129,   119,   120,   116,
     105
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -357,  -357,  -357,   172,  -357,  -357,   -40,   453,  -357,    91,
    -145,  -357,  -357,   449,   217,   112,    70,    -2,  -139,  -357,
     -33,  -357,  -357,  -156,  -357,  -357,  -357,   100,    77,  -357,
      -4,  -349,   -37,  -357,  -357,  -357,  -357,  -117,   143,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
       9,  -357,  -357,  -357,  -357,  -357,   229,   -35,  -144,  -357,
     -18,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -119,   494,   497,  -357,    -3,  -357,
      60,  -357,    85,   188,   145,    84,   164,    33,   300,   141,
     301,   155,   315,   153,   316,   159,   318,   160,  -357,  -357,
    -357,  -357,  -111,  -326,   455,    -9,  -357,  -357,  -356,  -113,
     -86
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   281,    48,    49,   153,   349,   396,   305,
     282,    50,   283,    51,   284,   350,   139,   166,    53,    54,
      55,    56,    57,   167,    58,    59,   292,   293,   123,   358,
     124,   359,   125,   126,   234,   127,   241,   238,   426,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   458,   497,
     498,   525,    69,    70,    71,   275,   276,   547,   239,   427,
     499,    72,    73,    74,    75,    76,   115,   116,   228,   229,
     343,    77,   168,   169,   170,    78,    79,    80,   175,   306,
      81,    82,    83,    84,    85,    86,    87,   254,    88,   255,
      89,   256,    90,   257,    91,   258,    92,   259,    93,   260,
      94,   261,    95,   262,   362,    96,   263,   264,   143,   117,
      97
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -171;
  const short int
  ParserImplementation::yytable_[] =
  {
        52,   155,   147,   242,   111,   158,   232,   235,   245,   286,
     219,   225,   287,   285,   290,   285,   135,   130,   218,   236,
     142,   218,   243,   451,   145,   300,   118,   352,   428,   288,
     344,   452,   218,   233,   218,   136,   434,   244,   114,   339,
     280,   218,   246,   218,   218,   218,   218,   401,    52,   250,
     448,   407,   450,   218,   218,   218,   120,   270,   218,   272,
     218,   307,   277,    39,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   486,   295,   218,     3,   178,   138,   485,
     151,   226,   312,   152,    46,   121,   119,   146,   128,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   218,   484,
     159,   218,   120,   273,   140,   335,   237,   337,   120,   224,
     220,   137,   338,   148,   161,   340,   523,   120,   274,   221,
     160,   172,   294,   173,   174,   141,   351,   131,   222,    39,
      39,   133,   269,   144,   515,   271,   122,   346,   268,   227,
     278,   279,   289,   132,   285,   212,   133,   400,   539,   151,
      46,    46,   154,   149,   301,   532,   353,   429,   345,   296,
     409,   150,   410,   514,   308,   298,   223,   310,   384,   385,
     389,   390,   402,   213,    47,   214,   408,   403,   483,   488,
     506,   404,   122,   512,   524,   517,   197,   198,   122,   230,
     347,   405,   134,   194,   195,   196,   252,   122,   348,   158,
     529,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   215,   151,   360,   120,   465,   237,   120,   120,
     253,   247,    47,   535,   248,   361,   542,   413,   240,   158,
     158,   417,   172,   420,   176,   177,   249,   221,   265,   355,
     266,   387,   190,   191,   478,   267,   222,   394,   133,   120,
     462,   397,   218,   464,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   120,   101,   156,   313,
     314,   315,   120,   120,   309,   120,   321,   322,   323,   324,
     325,   326,   419,   395,  -170,   122,   473,   479,   122,   122,
     474,   221,   199,   200,   201,   291,   208,   209,   210,   211,
     222,   357,   422,   151,   508,  -169,   467,   423,   216,   217,
     501,   311,   502,   190,   191,   381,   285,   302,   285,   122,
     341,   192,   368,   369,   370,   371,   507,   202,   203,   204,
     205,   206,   285,   360,   318,   319,   320,   424,   518,   519,
     376,   377,   432,   299,   285,   285,   122,  -168,   466,   468,
     503,   342,   122,   122,   294,   122,   356,   363,   364,   365,
     142,   366,   327,   328,   329,   330,   398,   399,   382,   383,
     480,   354,   456,   546,   546,   316,   317,   460,   461,   207,
     236,   360,   372,   373,   374,   375,   378,   510,   379,   414,
     470,   440,   441,   442,   443,   386,   391,   477,   274,   393,
     406,   415,   416,   411,   288,   418,   421,   425,   430,   367,
     142,   487,   433,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   433,   101,   433,   457,
     453,   454,   455,   475,   492,   509,   253,   435,   436,   437,
     438,   439,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   459,   463,   490,   504,   526,   481,   471,
     491,   482,   495,   489,   493,   476,   494,   496,   500,   505,
     511,   142,   516,   527,   528,   433,   513,   521,   534,   531,
     540,   537,   538,   520,   543,   157,   530,   549,   472,   171,
     392,   469,   142,   431,   388,   548,   522,   541,   112,   253,
     533,   113,   331,   444,   332,   536,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   446,   445,   333,
       0,   334,   544,   545,   447,   336,   193,   449,     0,     0,
       0,   550,     0,     0,   298,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     4,     5,     0,   190,   191,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,   253,     0,     0,     0,     0,   129,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    98,     0,     0,   162,    25,     0,
       0,     0,     0,     0,     0,    26,   163,     0,     0,     0,
       0,    28,    29,     0,     0,   164,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,     0,   192,     0,    45,   165,
       0,    46,     4,     5,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   129,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,    98,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,     0,     0,     0,    45,   165,     0,    46,
       4,     5,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   129,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
      98,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,   297,     0,    46,     4,     5,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       0,     0,    45,     4,     5,    46,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   129,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,    98,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    44,     0,     0,     0,    45,     4,     5,
      46,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,    45,     4,     5,    46,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,   100,     0,   231,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,   100,
       0,   412,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     4,     5,     0,
     304,   100,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,   251,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,   100,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     4,     5,     0,
       0,   100,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    13,    14,    15,     0,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,    21,     0,     0,    30,     0,
       0,    98,    32,     0,    99,     0,    34,     0,     0,     0,
       0,     0,    26,    27,    40,    41,     0,    42,    28,     0,
       0,     0,    30,    13,    14,    15,    32,     0,     0,     0,
      34,   100,   380,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    98,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,    41,    35,   122,    13,    42,   117,   120,   125,   154,
      96,     3,   156,   152,   158,   154,    20,    19,     3,    47,
      29,     3,     3,   379,    33,     3,    78,     3,     3,     3,
       3,   380,     3,   119,     3,    47,   362,   123,     3,    47,
     151,     3,   128,     3,     3,     3,     3,     3,    50,   135,
     376,     3,   378,     3,     3,     3,    49,   143,     3,   145,
       3,   172,   148,   111,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   429,   160,     3,     0,    80,    78,   428,
     126,    73,   193,   129,   132,    78,    16,   129,    18,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     3,   425,
      47,     3,    49,    56,   133,   216,   134,   218,    49,   112,
      78,   123,   225,    36,    44,   123,    62,    49,    71,    87,
      43,    47,   159,    49,    50,    47,   237,    59,    96,   111,
     111,    78,   141,    47,   490,   144,   129,    78,   140,   131,
     149,   150,   116,    75,   283,    20,    78,   291,   133,   126,
     132,   132,   129,    47,   132,   511,   132,   132,   131,   161,
     131,    47,   131,   489,   173,   167,   128,   176,   128,   128,
     128,   128,   128,    19,     2,    18,   128,   294,   128,   128,
     128,   300,   129,   128,   130,   128,    35,    36,   129,     3,
     131,   302,    20,    37,    38,    39,   136,   129,   235,   236,
     128,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    17,   126,   251,    49,   129,   134,    49,    49,
     136,   108,    50,   128,    78,    28,   128,   338,    78,   266,
     267,   344,    47,   352,    49,    50,    78,    87,    47,   243,
      47,   274,    45,    46,    78,    47,    96,    78,    78,    49,
     394,   288,     3,   397,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    49,   217,    78,   194,
     195,   196,    49,    49,    78,    49,   202,   203,   204,   205,
     206,   207,    78,   124,   133,   129,   407,   131,   129,   129,
     411,    87,    32,    33,    34,    78,    21,    22,    23,    24,
      96,    78,    78,   126,    78,   133,   129,   354,    15,    16,
     465,    78,   467,    45,    46,   265,   465,   133,   467,   129,
     131,   134,    21,    22,    23,    24,   481,    25,    26,    27,
      28,    29,   481,   380,   199,   200,   201,   356,   493,   494,
      15,    16,   361,   130,   493,   494,   129,   133,   398,   399,
     471,    79,   129,   129,   401,   129,    47,    25,    26,    27,
     379,    29,   208,   209,   210,   211,   112,   113,   266,   267,
     417,   133,   384,   539,   540,   197,   198,   389,   390,    77,
      47,   428,    20,    19,    18,    17,     3,   483,   132,   339,
     402,   368,   369,   370,   371,    47,   130,   416,    71,   130,
      78,    47,    47,   133,     3,   128,   130,   134,    28,    77,
     429,   430,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   129,
      28,   128,   128,    28,   453,   482,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,    78,    78,   132,   475,   500,   129,   133,
      28,   133,    65,   133,   129,   415,   129,    55,   128,    28,
     132,   490,   491,   130,   130,   425,   488,   496,   128,   130,
     133,   130,   130,   495,   128,    42,   505,   130,   407,    50,
     283,   401,   511,   360,   275,   540,   497,   525,    14,   425,
     512,    14,   212,   372,   213,   517,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   374,   373,   214,
      -1,   215,   534,   535,   375,   217,    81,   377,    -1,    -1,
      -1,   543,    -1,    -1,   546,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    35,    36,    -1,    45,    46,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,   489,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,
     111,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,   134,    -1,   129,   130,
      -1,   132,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,
      -1,   104,   105,   106,    -1,   108,   109,    -1,   111,   112,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    -1,    -1,   129,   130,    -1,   132,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,
     105,   106,    -1,   108,   109,    -1,   111,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,   130,    -1,   132,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      67,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,   106,
      -1,   108,   109,    -1,   111,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      -1,    -1,   129,    35,    36,   132,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,
      -1,    73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,
      -1,    -1,   104,   105,   106,    -1,   108,   109,    -1,   111,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,   129,    35,    36,
     132,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,   106,
      -1,   108,   109,    -1,   111,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    35,    36,   132,    -1,    -1,    40,    41,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   129,
      -1,   131,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    35,    36,    -1,
     128,   129,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,   129,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    35,    36,    -1,
      -1,   129,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    47,    48,    49,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    69,    -1,    -1,    96,    -1,
      -1,    75,   100,    -1,    78,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    86,    87,   112,   113,    -1,   115,    92,    -1,
      -1,    -1,    96,    47,    48,    49,   100,    -1,    -1,    -1,
     104,   129,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,   115,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129
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
     146,   148,   152,   153,   154,   155,   156,   157,   159,   160,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   187,
     188,   189,   196,   197,   198,   199,   200,   206,   210,   211,
     212,   215,   216,   217,   218,   219,   220,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   240,   245,    75,    78,
     129,   215,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   240,   210,   211,     3,   201,   202,   244,    78,   151,
      49,    78,   129,   163,   165,   167,   168,   170,   151,    59,
     152,    59,    75,    78,   138,   165,    47,   123,    78,   151,
     133,    47,   240,   243,    47,   240,   129,   155,   163,    47,
      47,   126,   129,   141,   129,   141,    78,   142,   167,    47,
     163,   151,    78,    87,    96,   130,   152,   158,   207,   208,
     209,   148,    47,    49,    50,   213,    49,    50,   213,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      45,    46,   134,   239,    37,    38,    39,    35,    36,    32,
      33,    34,    25,    26,    27,    28,    29,    77,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   245,
      78,    87,    96,   128,   213,     3,    73,   131,   203,   204,
       3,   131,   237,   245,   169,   244,    47,   134,   172,   193,
      78,   171,   209,     3,   245,   172,   245,   108,    78,    78,
     245,   106,   215,   220,   222,   224,   226,   228,   230,   232,
     234,   236,   238,   241,   242,    47,    47,    47,   152,   240,
     245,   240,   245,    56,    71,   190,   191,   245,   240,   240,
     237,   138,   145,   147,   149,   153,   145,   193,     3,   116,
     193,    78,   161,   162,   167,   245,   152,   130,   152,   130,
       3,   132,   133,   124,   128,   144,   214,   237,   240,    78,
     240,    78,   237,   217,   217,   217,   218,   218,   219,   219,
     219,   220,   220,   220,   220,   220,   220,   221,   221,   221,
     221,   223,   225,   227,   229,   237,   231,   237,   244,    47,
     123,   131,    79,   205,     3,   131,    78,   131,   167,   142,
     150,   237,     3,   132,   133,   165,    47,    78,   164,   166,
     167,    28,   239,    25,    26,    27,    29,    77,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   132,
     106,   215,   150,   150,   128,   128,    47,   155,   191,   128,
     128,   130,   149,   130,    78,   124,   143,   167,   112,   113,
     193,     3,   128,   172,   209,   237,    78,     3,   128,   131,
     131,   133,   131,   237,   215,    47,    47,   244,   128,    78,
     209,   130,    78,   167,   240,   134,   173,   194,     3,   132,
      28,   173,   240,   215,   238,   220,   220,   220,   220,   220,
     222,   222,   222,   222,   224,   226,   228,   230,   238,   232,
     238,   243,   166,    28,   128,   128,   152,   129,   183,    78,
     152,   152,   193,    78,   193,   129,   141,   129,   141,   162,
     152,   133,   144,   237,   237,    28,   215,   240,    78,   131,
     167,   129,   133,   128,   238,   166,   243,   240,   128,   133,
     132,    28,   240,   129,   129,    65,    55,   184,   185,   195,
     128,   145,   145,   237,   240,    28,   128,   145,    78,   167,
     245,   132,   128,   152,   238,   243,   240,   128,   145,   145,
     152,   240,   185,    62,   130,   186,   155,   130,   130,   128,
     240,   130,   243,   152,   128,   128,   152,   130,   130,   133,
     133,   195,   128,   128,   152,   152,   158,   192,   192,   130,
     152
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
     140,   140,   140,   140,   140,   140,   141,   142,   142,   142,
     142,   142,   143,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   155,   156,
     157,   157,   158,   158,   159,   159,   159,   160,   161,   161,
     162,   162,   163,   163,   164,   164,   165,   165,   166,   166,
     167,   167,   168,   168,   168,   169,   169,   169,   169,   170,
     171,   171,   171,   171,   171,   171,   172,   173,   174,   175,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     178,   179,   180,   181,   182,   183,   183,   184,   184,   185,
     186,   187,   188,   189,   189,   189,   190,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   196,   196,
     196,   197,   198,   198,   199,   199,   199,   199,   199,   199,
     200,   200,   200,   200,   201,   201,   202,   202,   203,   204,
     204,   205,   205,   206,   207,   207,   208,   208,   209,   209,
     209,   210,   210,   210,   210,   210,   211,   211,   212,   212,
     212,   212,   213,   213,   214,   214,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   218,   218,   218,   218,   219,   219,   219,
     220,   220,   220,   220,   221,   221,   221,   221,   221,   221,
     221,   222,   222,   222,   222,   222,   222,   223,   223,   223,
     223,   223,   224,   224,   224,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   241,
     241,   242,   242,   243,   243,   244,   244,   245,   245
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     8,     8,     8,     1,     7,     4,
       7,     4,     5,     5,     2,     2,     2,     2,     2,     4,
       4,     3,     2,     2,     0,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     2,     1,     2,     3,     3,     3,     5,     1,     3,
       2,     2,     1,     3,     1,     3,     2,     2,     2,     2,
       1,     1,     3,     3,     5,     2,     2,     4,     4,     4,
       1,     3,     3,     5,     3,     5,     2,     2,     1,     2,
       7,     5,     7,     5,     9,    10,     7,     8,     8,     9,
       3,     3,     3,     5,     5,     3,     5,     1,     2,     4,
       3,     3,     3,     3,     3,     4,     5,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     5,     4,     2,     4,     1,     2,     2,     6,
       7,     0,     4,     3,     0,     2,     3,     5,     1,     1,
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
  "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "')'", "'{'", "'}'", "']'",
  "';'", "':'", "'='", "$accept", "program", "$@1", "function_declaration",
  "function_expression", "arrow_function_expression",
  "shorten_function_body", "formal_parameter_list",
  "formal_parameter_rest", "arguments_spread", "function_body",
  "source_elements", "source_elements_for_function", "source_element",
  "source_element_for_function", "formal_parameter_list__opt",
  "identifier__opt", "statement", "statement_with_block",
  "statement_no_block", "block", "module_block", "export_statement",
  "statement_list", "variable_statement", "let_statement",
  "let_assignment_list", "let_assignment_expression",
  "variable_declaration_list", "variable_declaration_list_no_in",
  "variable_declaration", "variable_declaration_no_in",
  "destructuring_assignment_left_hand_side", "array_left_hand_side",
  "array_left_hand_side_list", "object_left_hand_side",
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
       136,     0,    -1,    -1,   137,   146,    -1,    75,    78,    47,
     150,   128,   129,   145,   130,    -1,    59,    78,    47,   150,
     128,   129,   145,   130,    -1,    75,   151,    47,   150,   128,
     129,   145,   130,    -1,   140,    -1,   115,   142,   116,   112,
     129,   145,   130,    -1,   112,   129,   145,   130,    -1,   115,
     142,   116,   113,   129,   145,   130,    -1,   113,   129,   145,
     130,    -1,   115,   142,   116,   112,   141,    -1,   115,   142,
     116,   113,   141,    -1,   113,   141,    -1,   112,   141,    -1,
     126,   237,    -1,    78,   193,    -1,   167,   193,    -1,   142,
       3,    78,   193,    -1,   142,     3,   167,   193,    -1,   142,
       3,   143,    -1,   124,    78,    -1,   124,    78,    -1,    -1,
     147,    -1,   148,    -1,   146,   148,    -1,   149,    -1,   147,
     149,    -1,   152,    -1,   138,    -1,   153,    -1,   138,    -1,
      -1,   142,    -1,    -1,    78,    -1,   153,    -1,   156,    -1,
     157,    -1,   155,    -1,   154,    -1,   159,    -1,   160,    -1,
     174,    -1,   175,    -1,   176,    -1,   177,    -1,   178,    -1,
     179,    -1,   180,    -1,   181,    -1,   187,    -1,   182,    -1,
     188,    -1,   189,    -1,   129,   130,    -1,   129,   158,   130,
      -1,   125,   151,   152,    -1,    67,   165,   245,    -1,    67,
     138,    -1,   152,    -1,   158,   152,    -1,   106,   163,   245,
      -1,    59,   163,   245,    -1,   122,   163,   245,    -1,   122,
      47,   161,   128,   152,    -1,   162,    -1,   161,     3,   162,
      -1,    78,   193,    -1,   167,   172,    -1,   165,    -1,   163,
       3,   165,    -1,   166,    -1,   164,     3,   166,    -1,    78,
     193,    -1,   167,   172,    -1,    78,   194,    -1,   167,   173,
      -1,   168,    -1,   170,    -1,    49,   244,   131,    -1,    49,
     169,   131,    -1,    49,   169,     3,   244,   131,    -1,   244,
      78,    -1,   244,   167,    -1,   169,     3,   244,    78,    -1,
     169,     3,   244,   167,    -1,   129,   171,   132,   130,    -1,
      78,    -1,   209,   133,    78,    -1,   209,   133,   167,    -1,
     171,     3,   209,   133,    78,    -1,   171,     3,    78,    -1,
     171,     3,   209,   133,   167,    -1,   134,   237,    -1,   134,
     238,    -1,   245,    -1,   240,   245,    -1,    79,    47,   240,
     128,   152,    65,   152,    -1,    79,    47,   240,   128,   152,
      -1,    63,   152,   108,    47,   240,   128,   245,    -1,   108,
      47,   240,   128,   152,    -1,    73,    47,   242,   132,   243,
     132,   243,   128,   152,    -1,    73,    47,   106,   164,   132,
     243,   132,   243,   128,   152,    -1,    73,    47,   215,    28,
     240,   128,   152,    -1,    73,    47,   106,   166,    28,   240,
     128,   152,    -1,    73,   123,    47,   215,    28,   240,   128,
     152,    -1,    73,   123,    47,   106,   166,    28,   240,   128,
     152,    -1,    60,   151,   245,    -1,    53,   151,   245,    -1,
      93,   243,   245,    -1,   109,    47,   240,   128,   152,    -1,
      98,    47,   240,   128,   183,    -1,   129,   195,   130,    -1,
     129,   195,   186,   195,   130,    -1,   185,    -1,   184,   185,
      -1,    55,   240,   133,   192,    -1,    62,   133,   192,    -1,
      78,   133,   152,    -1,   101,   240,   245,    -1,   105,   155,
     190,    -1,   105,   155,   191,    -1,   105,   155,   190,   191,
      -1,    56,    47,    78,   128,   155,    -1,    71,   155,    -1,
      -1,   158,    -1,    -1,   172,    -1,    -1,   173,    -1,    -1,
     184,    -1,   197,    -1,   198,    -1,    87,    -1,    96,    -1,
      92,    -1,    86,    -1,   104,    -1,    69,    -1,   100,    -1,
      78,    -1,   196,    -1,   200,    -1,   206,    -1,    47,   240,
     128,    -1,    49,   244,   131,    -1,    49,   201,   131,    -1,
      49,   201,     3,   244,   131,    -1,    49,   201,   203,   131,
      -1,   244,   237,    -1,   201,     3,   244,   237,    -1,     3,
      -1,   202,     3,    -1,   204,   205,    -1,    73,    47,   215,
      28,   240,   128,    -1,    73,   123,    47,   215,    28,   240,
     128,    -1,    -1,    79,    47,   240,   128,    -1,   129,   207,
     130,    -1,    -1,   208,   132,    -1,   209,   133,   237,    -1,
     208,     3,   209,   133,   237,    -1,    78,    -1,    96,    -1,
      87,    -1,   199,    -1,   139,    -1,   210,    49,   240,   131,
      -1,   210,    50,    78,    -1,    48,   210,   213,    -1,   210,
      -1,    48,   211,    -1,   210,   213,    -1,   212,   213,    -1,
     212,    49,   240,   131,    -1,   212,    50,    78,    -1,    47,
     128,    -1,    47,   214,   128,    -1,   237,    -1,   144,    -1,
     214,     3,   237,    -1,   214,     3,   144,    -1,   211,    -1,
     212,    -1,   215,    -1,   215,    46,    -1,   215,    45,    -1,
     216,    -1,    42,   217,    -1,    43,   217,    -1,    44,   217,
      -1,    46,   217,    -1,    45,   217,    -1,    35,   217,    -1,
      36,   217,    -1,    41,   217,    -1,    40,   217,    -1,   217,
      -1,   218,    37,   217,    -1,   218,    38,   217,    -1,   218,
      39,   217,    -1,   218,    -1,   219,    35,   218,    -1,   219,
      36,   218,    -1,   219,    -1,   220,    34,   219,    -1,   220,
      33,   219,    -1,   220,    32,   219,    -1,   220,    -1,   221,
      26,   220,    -1,   221,    25,   220,    -1,   221,    29,   220,
      -1,   221,    77,   220,    -1,   221,    27,   220,    -1,   221,
      28,   220,    -1,   220,    -1,   222,    26,   220,    -1,   222,
      25,   220,    -1,   222,    29,   220,    -1,   222,    77,   220,
      -1,   222,    27,   220,    -1,   221,    -1,   223,    23,   221,
      -1,   223,    22,   221,    -1,   223,    24,   221,    -1,   223,
      21,   221,    -1,   222,    -1,   224,    23,   222,    -1,   224,
      22,   222,    -1,   224,    24,   222,    -1,   224,    21,   222,
      -1,   223,    -1,   225,    20,   223,    -1,   224,    -1,   226,
      20,   224,    -1,   225,    -1,   227,    19,   225,    -1,   226,
      -1,   228,    19,   226,    -1,   227,    -1,   229,    18,   227,
      -1,   228,    -1,   230,    18,   228,    -1,   229,    -1,   231,
      17,   229,    -1,   230,    -1,   232,    17,   230,    -1,   231,
      -1,   233,    16,   231,    -1,   232,    -1,   234,    16,   232,
      -1,   233,    -1,   233,    15,   237,   133,   237,    -1,   234,
      -1,   234,    15,   238,   133,   238,    -1,   235,    -1,   215,
     239,   237,    -1,   236,    -1,   215,   239,   238,    -1,   134,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   237,    -1,   240,     3,   237,    -1,   238,
      -1,   241,     3,   238,    -1,    -1,   241,    -1,    -1,   240,
      -1,    -1,   202,    -1,   132,    -1,   111,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,    16,    25,    34,    36,    44,
      49,    57,    62,    68,    74,    77,    80,    83,    86,    89,
      94,    99,   103,   106,   109,   110,   112,   114,   117,   119,
     122,   124,   126,   128,   130,   131,   133,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   154,   156,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   177,   181,
     185,   189,   192,   194,   197,   201,   205,   209,   215,   217,
     221,   224,   227,   229,   233,   235,   239,   242,   245,   248,
     251,   253,   255,   259,   263,   269,   272,   275,   280,   285,
     290,   292,   296,   300,   306,   310,   316,   319,   322,   324,
     327,   335,   341,   349,   355,   365,   376,   384,   393,   402,
     412,   416,   420,   424,   430,   436,   440,   446,   448,   451,
     456,   460,   464,   468,   472,   476,   481,   487,   490,   491,
     493,   494,   496,   497,   499,   500,   502,   504,   506,   508,
     510,   512,   514,   516,   518,   520,   522,   524,   526,   528,
     532,   536,   540,   546,   551,   554,   559,   561,   564,   567,
     574,   582,   583,   588,   592,   593,   596,   600,   606,   608,
     610,   612,   614,   616,   621,   625,   629,   631,   634,   637,
     640,   645,   649,   652,   656,   658,   660,   664,   668,   670,
     672,   674,   677,   680,   682,   685,   688,   691,   694,   697,
     700,   703,   706,   709,   711,   715,   719,   723,   725,   729,
     733,   735,   739,   743,   747,   749,   753,   757,   761,   765,
     769,   773,   775,   779,   783,   787,   791,   795,   797,   801,
     805,   809,   813,   815,   819,   823,   827,   831,   833,   837,
     839,   843,   845,   849,   851,   855,   857,   861,   863,   867,
     869,   873,   875,   879,   881,   885,   887,   891,   893,   899,
     901,   907,   909,   913,   915,   919,   921,   923,   925,   927,
     929,   931,   933,   935,   937,   939,   941,   943,   945,   949,
     951,   955,   956,   958,   959,   961,   962,   964,   966
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   334,   334,   334,   348,   365,   381,   391,   404,   413,
     422,   432,   442,   452,   463,   474,   488,   508,   524,   535,
     545,   555,   570,   587,   597,   598,   602,   610,   620,   628,
     638,   639,   649,   650,   660,   661,   668,   669,   678,   679,
     684,   692,   697,   701,   706,   710,   715,   720,   725,   730,
     735,   740,   745,   750,   755,   760,   765,   773,   780,   791,
     804,   811,   822,   830,   841,   849,   857,   868,   878,   884,
     891,   899,   910,   918,   928,   934,   942,   950,   960,   968,
     979,   983,   990,  1000,  1007,  1020,  1032,  1042,  1052,  1063,
    1074,  1084,  1096,  1106,  1116,  1124,  1135,  1139,  1143,  1147,
    1157,  1166,  1178,  1186,  1194,  1206,  1218,  1229,  1241,  1252,
    1266,  1276,  1286,  1296,  1307,  1318,  1322,  1331,  1337,  1345,
    1356,  1367,  1380,  1390,  1399,  1408,  1420,  1431,  1439,  1440,
    1444,  1445,  1449,  1450,  1454,  1455,  1459,  1460,  1461,  1468,
    1475,  1485,  1495,  1502,  1512,  1519,  1526,  1527,  1528,  1529,
    1537,  1547,  1554,  1564,  1575,  1585,  1596,  1597,  1602,  1610,
    1617,  1627,  1628,  1637,  1652,  1655,  1662,  1671,  1681,  1688,
    1695,  1705,  1709,  1713,  1726,  1741,  1757,  1758,  1768,  1781,
    1794,  1807,  1825,  1826,  1830,  1836,  1842,  1847,  1855,  1856,
    1860,  1864,  1871,  1881,  1882,  1889,  1896,  1903,  1910,  1917,
    1924,  1931,  1938,  1948,  1949,  1953,  1957,  1964,  1965,  1969,
    1976,  1977,  1981,  1985,  1992,  1993,  1997,  2001,  2005,  2009,
    2013,  2020,  2021,  2025,  2029,  2033,  2037,  2044,  2045,  2049,
    2053,  2057,  2064,  2065,  2069,  2073,  2077,  2084,  2085,  2092,
    2093,  2100,  2101,  2108,  2109,  2116,  2117,  2124,  2125,  2132,
    2133,  2140,  2141,  2148,  2149,  2156,  2157,  2164,  2165,  2174,
    2175,  2184,  2188,  2198,  2202,  2213,  2214,  2215,  2216,  2217,
    2218,  2219,  2220,  2221,  2222,  2223,  2224,  2228,  2235,  2243,
    2250,  2258,  2259,  2263,  2264,  2268,  2269,  2273,  2274
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
  const int ParserImplementation::yylast_ = 1755;
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
#line 4826 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2277 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


