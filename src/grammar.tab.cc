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
#line 332 "grammar.yy"
    {yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 333 "grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 347 "grammar.yy"
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
#line 364 "grammar.yy"
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
#line 380 "grammar.yy"
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
#line 389 "grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 403 "grammar.yy"
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
#line 412 "grammar.yy"
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
#line 421 "grammar.yy"
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
#line 431 "grammar.yy"
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
#line 441 "grammar.yy"
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
#line 451 "grammar.yy"
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
#line 462 "grammar.yy"
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
#line 473 "grammar.yy"
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
#line 487 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 507 "grammar.yy"
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
#line 523 "grammar.yy"
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
#line 534 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 544 "grammar.yy"
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
#line 554 "grammar.yy"
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
#line 569 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 586 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 595 "grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 596 "grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 601 "grammar.yy"
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
#line 609 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 619 "grammar.yy"
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
#line 627 "grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 636 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 638 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 647 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 649 "grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 658 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 660 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 666 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 668 "grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 676 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 678 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 683 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 691 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 695 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 700 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 705 "grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 709 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 714 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 719 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 724 "grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 729 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 734 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 739 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 744 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 749 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 754 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 759 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 764 "grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 772 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 779 "grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 790 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (2)].info) );
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( value );

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
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    value->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 987 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 994 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->Append( (yysemantic_stack_[(4) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1005 "grammar.yy"
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

  case 84:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar.yy"
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

  case 85:

/* Line 690 of lalr1.cc  */
#line 1027 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(3) - (3)].ast) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( node );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1039 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1049 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1057 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1067 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1080 "grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(2) - (1)].expression)->Line() );
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1090 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1099 "grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1111 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1119 "grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1127 "grammar.yy"
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

  case 98:

/* Line 690 of lalr1.cc  */
#line 1139 "grammar.yy"
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

  case 99:

/* Line 690 of lalr1.cc  */
#line 1151 "grammar.yy"
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

  case 100:

/* Line 690 of lalr1.cc  */
#line 1162 "grammar.yy"
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

  case 101:

/* Line 690 of lalr1.cc  */
#line 1174 "grammar.yy"
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

  case 102:

/* Line 690 of lalr1.cc  */
#line 1185 "grammar.yy"
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

  case 103:

/* Line 690 of lalr1.cc  */
#line 1199 "grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1209 "grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1219 "grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1229 "grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1240 "grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1251 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1255 "grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1264 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1270 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1278 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1289 "grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1300 "grammar.yy"
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

  case 115:

/* Line 690 of lalr1.cc  */
#line 1313 "grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1341 "grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1364 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1371 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1372 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1376 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1377 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1382 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1386 "grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1387 "grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1391 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1392 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1394 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1401 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1408 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1418 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1428 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1435 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1445 "grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1452 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1458 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1459 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1460 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1462 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1470 "grammar.yy"
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

  case 144:

/* Line 690 of lalr1.cc  */
#line 1480 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1487 "grammar.yy"
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

  case 146:

/* Line 690 of lalr1.cc  */
#line 1497 "grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1508 "grammar.yy"
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

  case 148:

/* Line 690 of lalr1.cc  */
#line 1518 "grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1535 "grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1543 "grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1550 "grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1559 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1561 "grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1570 "grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1584 "grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1588 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1595 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1604 "grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1614 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1628 "grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1638 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1646 "grammar.yy"
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

  case 167:

/* Line 690 of lalr1.cc  */
#line 1659 "grammar.yy"
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

  case 168:

/* Line 690 of lalr1.cc  */
#line 1674 "grammar.yy"
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

  case 169:

/* Line 690 of lalr1.cc  */
#line 1689 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1691 "grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1701 "grammar.yy"
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

  case 172:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar.yy"
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

  case 173:

/* Line 690 of lalr1.cc  */
#line 1727 "grammar.yy"
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
#line 1740 "grammar.yy"
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
#line 1757 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1758 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1763 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1769 "grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1775 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1780 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1787 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1788 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1793 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1797 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1804 "grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1813 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1815 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1829 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1836 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1843 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1850 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1857 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1864 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1871 "grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1880 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1886 "grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1898 "grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1902 "grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1908 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1910 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1918 "grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1926 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1930 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1938 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1942 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1946 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1952 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1958 "grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1966 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1970 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1976 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1978 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1982 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1996 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1998 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2002 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2006 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2010 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2016 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2018 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2024 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2026 "grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2032 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2034 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2040 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2042 "grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2048 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2050 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2056 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2064 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2066 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2072 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2074 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2080 "grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2082 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2088 "grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2090 "grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2096 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2098 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2106 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2108 "grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2117 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2121 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2131 "grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2135 "grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2145 "grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2146 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2147 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2148 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2149 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2150 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2151 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2152 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2153 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2154 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2155 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2156 "grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2161 "grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2168 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2176 "grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2183 "grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2190 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2191 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2195 "grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2196 "grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2200 "grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2201 "grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2205 "grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2206 "grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3423 "grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -344;
  const short int
  ParserImplementation::yypact_[] =
  {
      -344,    39,   973,  -344,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1593,    47,   -17,    79,   -17,  1065,
     173,  -344,    -6,    -5,   -27,    77,  -344,  -344,  -344,  1519,
    -344,    95,  -344,  1519,  -344,    30,   113,   120,   126,  -344,
     -47,     3,   153,    71,   110,   697,  -344,  -344,  -344,  -344,
     973,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,   167,  -344,
     243,    80,  -344,  -344,   261,   292,   339,   286,   346,   107,
     160,   176,   182,    84,  -344,  -344,    19,  -344,   -17,  -344,
     114,   232,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,    15,   167,  -344,  -344,    10,   206,   507,  -344,   -73,
     -18,   128,    22,  -344,    88,  -344,  -344,   -73,   113,   115,
     148,   155,    88,  -344,   -73,  1339,   189,   194,   196,  1065,
    1519,   244,   -73,  1519,    19,   789,    45,    22,  1519,  1519,
    1519,  1157,  -344,  1157,  -344,    88,     7,    88,   162,    22,
    1065,   -27,   118,   151,  -344,  -344,   881,   150,    20,   172,
    -344,  1249,  1519,   238,  -344,  1519,   240,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  -344,  -344,
    -344,  -344,  -344,  -344,    47,    29,  -344,   111,   227,  -344,
    -344,  -344,  -344,   153,  1519,  -344,  -344,   191,    23,   199,
     113,  -344,  -344,  -344,   274,   298,   194,  -344,   197,   500,
     339,   327,   354,   329,   328,   337,   341,   318,  -344,  -344,
     388,   266,  1543,   153,   153,  -344,    32,  -344,    33,  -344,
     351,    30,   330,  -344,  -344,    37,    40,  -344,  -344,   270,
    1157,  -344,  -344,   272,  -344,    96,   228,  -344,    88,    41,
    -344,    88,  -344,  -344,  -344,  -344,  -344,   114,  -344,  1519,
     325,  -344,  -344,    42,  -344,    12,  -344,    13,  -344,  -344,
    -344,  -344,  -344,   261,   261,   292,   292,   292,   339,   339,
     339,   339,   339,   339,   286,   286,   286,   286,   346,   107,
     160,   176,   273,   182,  -344,   602,  1593,   359,  -344,   361,
    -344,   406,   282,  -344,   242,   283,   203,  -344,  1519,   299,
      24,   403,   299,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,   197,   408,   334,   335,  1065,   336,   378,  -344,
    -344,  1065,  1065,  -344,  -344,  -344,    88,   386,  -344,    88,
      64,    78,  -344,   162,  1065,  -344,   340,  -344,  -344,  1429,
    -344,  -344,  -344,  1519,  -344,  -344,   438,  1593,  1519,   342,
     191,   345,  -344,  -344,  -344,    43,  1519,  -344,  -344,   197,
    1519,  1519,  -344,    44,    80,  -344,   339,   339,   339,   339,
     339,   327,   327,   327,   327,   354,   329,   328,   337,   347,
     341,  -344,   352,   440,  1519,   344,   349,   417,   430,  -344,
     358,  -344,  -344,  -344,  -344,  -344,  1157,  -344,  1157,  -344,
    -344,  -344,  1519,  -344,  -344,  -344,  1519,   459,    48,  1157,
     230,   -73,  -344,  -344,   357,    49,  1065,  1519,  1519,  1519,
      50,  1157,  1157,  1065,  1519,   430,  -344,   -32,    30,   362,
     363,  -344,    52,  1519,  -344,   364,  -344,  -344,  -344,  1519,
    1065,  -344,  -344,   367,    53,  1065,   366,   370,  -344,    16,
    -344,   365,  -344,   430,  -344,  -344,  -344,  -344,    57,  -344,
     373,  -344,  1065,  1065,  -344,  -344,  -344,  1065,  1065,   372,
    -344,  1065,  -344,  -344,  1065,  -344,  -344,  -344,  -344
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,    36,     0,    36,     0,
       0,   136,     0,    36,   138,     0,   134,   131,   133,   276,
     132,     0,   137,     0,   135,     0,     0,     0,     0,   281,
       0,     0,     0,     0,     0,     0,   280,    31,   165,     7,
       3,    26,    30,    38,    42,    41,    39,    40,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    53,
      55,    56,   139,   129,   130,   164,   140,   141,   169,   181,
     182,   183,   186,   196,   200,   203,   207,   220,   230,   234,
     238,   242,   246,   250,   254,   270,     0,    91,    36,   138,
     157,   183,   192,   193,   195,   194,   187,   188,   189,   191,
     190,     0,   169,   170,   149,     0,   279,     0,    37,     0,
     123,     0,     0,    72,     0,    81,    80,     0,     0,     0,
       0,     0,   123,    61,     0,   274,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    15,    24,    14,   123,     0,   123,     0,     0,
       0,   138,   131,   132,    57,    62,     0,     0,     0,     0,
      27,     0,     0,     0,   171,     0,     0,   172,   266,   263,
     265,   264,   269,   268,   259,   261,   260,   267,   262,   185,
     184,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,   161,
     163,   162,   142,   168,   278,     0,   144,     0,   154,   150,
     143,   147,   104,    34,     0,   124,    76,    83,     0,     0,
       0,    65,    77,   103,     0,     0,     0,    60,     0,   183,
     214,   225,   232,   236,   240,   244,   248,   252,   256,   272,
     275,     0,     0,    34,    34,   114,     0,   105,     0,   115,
       0,     0,   116,   117,    64,     0,     0,    16,    33,     0,
      25,    28,    32,     0,    17,     0,     0,    18,   123,     0,
      68,     0,    66,    59,    58,    63,   156,     0,   158,     0,
       0,   175,   178,     0,   177,     0,   167,     0,   174,   255,
     197,   198,   199,   201,   202,   206,   205,   204,   209,   208,
     212,   213,   210,   211,   224,   222,   221,   223,   231,   235,
     239,   243,     0,   247,   271,     0,     0,     0,   146,     0,
     151,    35,     0,    89,     0,     0,     0,    73,     0,   125,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,   120,
     118,     0,     0,     9,    29,    11,   123,     0,    21,   123,
       0,     0,    70,     0,     0,    71,     0,   159,    23,     0,
     176,   166,   173,     0,   145,   148,     0,     0,     0,     0,
      87,     0,    82,    84,    85,     0,     0,   126,    78,     0,
     276,     0,    79,     0,   183,   257,   216,   215,   219,   217,
     218,   229,   227,   226,   228,   233,   237,   241,   245,     0,
     249,   273,     0,     0,     0,     0,     0,    94,   127,   107,
       0,    96,   106,    19,    22,    20,    24,    12,    24,    13,
      69,    67,     0,   180,   179,   251,     0,     0,     0,    24,
       0,     0,    90,    75,     0,     0,     0,     0,   276,     0,
       0,    24,    24,     0,     0,   128,   110,     0,     0,     0,
       0,   160,     0,     0,   155,     0,    86,    88,    95,   276,
       0,    99,   253,     0,     0,     0,     0,     0,    93,     0,
     111,     0,   108,   127,   119,     8,    10,   152,     0,     5,
       0,   100,     0,     0,   101,     4,     6,   121,   121,     0,
     153,     0,    97,   102,   122,   112,   113,   109,    98
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -344,  -344,  -344,   185,  -344,  -344,   -40,   447,  -344,    92,
    -121,  -344,  -344,   465,   236,   101,   168,    -2,  -139,  -344,
     -33,  -344,  -344,  -146,  -344,  -344,  -344,   124,    59,  -344,
     -11,  -339,   -36,  -344,  -344,  -116,   166,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,    34,  -344,
    -344,  -344,  -344,  -344,   250,    -4,  -152,  -344,    14,  -344,
    -344,  -344,  -344,    61,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -114,   509,   511,  -344,   -49,  -344,    60,  -344,
     102,   188,   195,    83,   180,    98,   315,   169,   322,   165,
     323,   174,   321,   171,   343,   170,  -344,  -344,  -344,  -344,
     -96,  -172,   460,    -9,  -344,  -344,  -343,   320,   -85
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   278,    48,    49,   152,   341,   388,   302,
     279,    50,   280,    51,   281,   342,   138,   165,    53,    54,
      55,    56,    57,   166,    58,    59,   289,   290,   122,   350,
     123,   351,   124,   125,   238,   235,   417,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   449,   485,   486,   513,
      69,    70,    71,   272,   273,   535,   236,   418,   487,    72,
      73,    74,    75,    76,   115,   116,   227,   228,   340,    77,
     167,   168,   169,    78,    79,    80,   174,   303,    81,    82,
      83,    84,    85,    86,    87,   251,    88,   252,    89,   253,
      90,   254,    91,   255,    92,   256,    93,   257,    94,   258,
      95,   259,   354,    96,   260,   261,   142,   117,    97
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -164;
  const short int
  ParserImplementation::yytable_[] =
  {
        52,   154,   146,   284,   111,   287,   157,   239,   242,   134,
     285,   218,   282,   224,   282,   217,   217,   129,   217,   217,
     141,   231,   217,   297,   144,   240,   344,   419,   442,   233,
     511,   177,   283,   443,   232,   217,   217,   241,    39,     3,
     217,   135,   243,   217,   393,   399,   217,   217,    52,   247,
     114,   217,   217,   217,   277,   217,   217,   267,    46,   269,
     217,   118,   274,   223,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   137,   292,   304,   336,   474,   126,   150,
     473,   126,   151,   225,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   147,   309,   126,   512,   215,
     216,   270,   159,   126,   126,   139,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   234,   271,   136,   158,   332,
      15,   334,   291,   286,   140,   189,   190,   211,    15,   150,
      39,   266,   153,    39,   268,   503,   392,   265,   343,   275,
     276,   282,   143,   222,   226,    15,   401,   402,   527,   132,
      46,   298,   337,    46,   345,   420,   520,   120,   293,   145,
     376,   377,    15,   305,   295,   381,   307,   148,   382,   394,
     400,   471,   476,   149,   386,   395,   494,   500,   505,   212,
     517,   523,   425,   396,   119,   530,   127,    47,   160,   126,
     150,   132,   219,   456,   213,   249,   439,   157,   441,   214,
     121,   220,    15,   397,   150,   133,   237,   458,   121,   229,
     221,    15,   352,   191,   171,   220,   172,   173,   250,   126,
     387,   234,    15,   244,   221,   121,   245,   157,   157,   347,
     411,   155,   130,   246,   453,    47,   262,   455,   379,   405,
     288,   263,   121,   264,   472,   338,    15,   217,   131,   389,
    -163,   132,    15,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   349,   101,   189,   190,    15,
     296,   413,   121,  -162,   318,   319,   320,   321,   322,   323,
     171,   121,   175,   176,   126,   310,   311,   312,   193,   194,
     195,   126,   121,   464,   299,   502,   339,   465,   496,   126,
     414,   201,   202,   203,   204,   205,   306,   282,   308,   282,
     410,   348,   373,  -161,   126,   126,   121,   196,   197,   220,
     282,   346,   121,   368,   369,   489,   352,   490,   221,   415,
     390,   391,   282,   282,   423,   233,   126,   365,   495,   364,
     457,   459,   355,   356,   357,   366,   358,   291,   367,   121,
     506,   507,   141,   206,   374,   375,   491,   207,   208,   209,
     210,   198,   199,   200,   447,   360,   361,   362,   363,   451,
     452,   534,   534,   352,   313,   314,   498,   324,   325,   326,
     327,   370,   461,   315,   316,   317,   406,   371,   378,   468,
     383,   271,   385,   398,   359,   403,   407,   126,   408,   285,
     409,   141,   475,   412,   424,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   424,   101,
     424,   421,   416,   126,   497,   480,   444,   250,   426,   427,
     428,   429,   430,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   126,   514,   450,   492,   431,   432,
     433,   434,   445,   446,   454,   448,   466,   467,   479,   141,
     504,   469,   462,   481,   501,   509,   424,   470,   482,   477,
     126,   508,   483,   478,   518,   484,   488,   493,   499,   156,
     141,   463,   515,   516,   519,   522,   525,   528,   521,   250,
     526,   531,   537,   524,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   170,   384,   460,   422,   510,
     532,   533,   380,   112,   536,   113,   328,   529,   353,   538,
     436,   126,   295,   435,   329,   331,   330,   424,   438,   440,
     437,   192,     4,     5,   335,   189,   190,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,   333,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,    98,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,     0,   100,     4,     5,     0,
       0,   230,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     4,     5,     0,     0,   404,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   128,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,    98,     0,     0,   161,    25,     0,     0,     0,
       0,     0,     0,    26,   162,     0,     0,     0,     0,    28,
      29,     0,     0,   163,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,     0,     4,     5,    45,   164,    46,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   128,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    98,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     4,     5,    45,   164,
      46,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     128,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,    98,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     4,     5,
      45,   294,    46,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       4,     5,    45,     0,    46,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   128,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
      98,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     4,     5,    45,     0,    46,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,     0,    23,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     4,     5,    45,     0,    46,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     4,     5,     0,   301,   100,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,   248,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,   100,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     4,     5,     0,     0,   100,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      13,    14,    15,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    21,     0,     0,    30,     0,     0,    98,    32,
       0,    99,     0,    34,     0,     0,     0,     0,     0,    26,
      27,    40,    41,     0,    42,    28,     0,     0,     0,    30,
      13,    14,    15,    32,     0,     0,     0,    34,   100,   372,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,    21,     0,     0,     0,     0,     0,    98,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,    26,
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
         2,    41,    35,   155,    13,   157,    42,   121,   124,    20,
       3,    96,   151,     3,   153,     3,     3,    19,     3,     3,
      29,   117,     3,     3,    33,     3,     3,     3,   371,    47,
      62,    80,   153,   372,   119,     3,     3,   122,   111,     0,
       3,    47,   127,     3,     3,     3,     3,     3,    50,   134,
       3,     3,     3,     3,   150,     3,     3,   142,   131,   144,
       3,    78,   147,   112,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    78,   159,   171,    47,   420,    17,   126,
     419,    20,   129,    73,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    36,   192,    36,   130,    15,
      16,    56,    43,    42,    43,   132,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   133,    71,   123,    47,   215,
      49,   217,   158,   116,    47,    45,    46,    20,    49,   126,
     111,   140,   129,   111,   143,   478,   288,   139,   234,   148,
     149,   280,    47,   128,   134,    49,   134,   134,   132,    78,
     131,   131,   123,   131,   131,   131,   499,    78,   160,   129,
     128,   128,    49,   172,   166,   128,   175,    47,   128,   128,
     128,   128,   128,    47,    78,   291,   128,   128,   128,    19,
     128,   128,   354,   297,    16,   128,    18,     2,    78,   128,
     126,    78,    78,   129,    18,   135,   368,   233,   370,    17,
     129,    87,    49,   299,   126,    20,    78,   129,   129,     3,
      96,    49,   248,   133,    47,    87,    49,    50,   135,   158,
     124,   133,    49,   108,    96,   129,    78,   263,   264,   240,
     344,    78,    59,    78,   386,    50,    47,   389,   271,   335,
      78,    47,   129,    47,   416,   134,    49,     3,    75,   285,
     132,    78,    49,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    78,   216,    45,    46,    49,
     130,    78,   129,   132,   201,   202,   203,   204,   205,   206,
      47,   129,    49,    50,   233,   193,   194,   195,    37,    38,
      39,   240,   129,   399,   132,   477,    79,   403,    78,   248,
     346,    25,    26,    27,    28,    29,    78,   456,    78,   458,
      78,    47,   262,   132,   263,   264,   129,    35,    36,    87,
     469,   132,   129,    15,    16,   456,   372,   458,    96,   348,
     112,   113,   481,   482,   353,    47,   285,    19,   469,    20,
     390,   391,    25,    26,    27,    18,    29,   393,    17,   129,
     481,   482,   371,    77,   263,   264,   462,    21,    22,    23,
      24,    32,    33,    34,   376,    21,    22,    23,    24,   381,
     382,   527,   528,   419,   196,   197,   471,   207,   208,   209,
     210,     3,   394,   198,   199,   200,   336,   131,    47,   408,
     130,    71,   130,    78,    77,   132,    47,   346,    47,     3,
     128,   420,   421,   130,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,    28,   133,   372,   470,   444,    28,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   393,   488,    78,   466,   360,   361,
     362,   363,   128,   128,    78,   129,    28,   407,    28,   478,
     479,   129,   132,   129,   476,   484,   416,   132,   129,   132,
     419,   483,    65,   131,   493,    55,   128,    28,   131,    42,
     499,   399,   130,   130,   130,   128,   130,   132,   500,   416,
     130,   128,   130,   505,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    50,   280,   393,   352,   485,
     522,   523,   272,    14,   528,    14,   211,   513,    28,   531,
     365,   470,   534,   364,   212,   214,   213,   477,   367,   369,
     366,    81,    35,    36,   224,    45,    46,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,   216,
     477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    -1,   129,    35,    36,    -1,
      -1,   134,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    35,    36,    -1,    -1,   134,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,
      -1,   104,   105,   106,    -1,   108,   109,    -1,   111,   112,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    35,    36,   129,   130,   131,    40,
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
      35,    36,   129,    -1,   131,    40,    41,    42,    43,    44,
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
      63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,    -1,
      -1,   104,   105,   106,    -1,   108,   109,    -1,   111,   112,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    35,    36,   129,    -1,   131,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    35,    36,    -1,   128,   129,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   129,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    35,    36,    -1,    -1,   129,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      47,    48,    49,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    69,    -1,    -1,    96,    -1,    -1,    75,   100,
      -1,    78,    -1,   104,    -1,    -1,    -1,    -1,    -1,    86,
      87,   112,   113,    -1,   115,    92,    -1,    -1,    -1,    96,
      47,    48,    49,   100,    -1,    -1,    -1,   104,   129,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,   129,    -1,    -1,    -1,    -1,    -1,    -1,    86,
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
     146,   148,   152,   153,   154,   155,   156,   157,   159,   160,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   185,
     186,   187,   194,   195,   196,   197,   198,   204,   208,   209,
     210,   213,   214,   215,   216,   217,   218,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   238,   243,    75,    78,
     129,   213,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   238,   208,   209,     3,   199,   200,   242,    78,   151,
      78,   129,   163,   165,   167,   168,   198,   151,    59,   152,
      59,    75,    78,   138,   165,    47,   123,    78,   151,   132,
      47,   238,   241,    47,   238,   129,   155,   163,    47,    47,
     126,   129,   141,   129,   141,    78,   142,   167,    47,   163,
      78,    78,    87,    96,   130,   152,   158,   205,   206,   207,
     148,    47,    49,    50,   211,    49,    50,   211,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    45,
      46,   133,   237,    37,    38,    39,    35,    36,    32,    33,
      34,    25,    26,    27,    28,    29,    77,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   243,    78,
      87,    96,   128,   211,     3,    73,   134,   201,   202,     3,
     134,   235,   243,    47,   133,   170,   191,    78,   169,   207,
       3,   243,   170,   243,   108,    78,    78,   243,   106,   213,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     239,   240,    47,    47,    47,   152,   238,   243,   238,   243,
      56,    71,   188,   189,   243,   238,   238,   235,   138,   145,
     147,   149,   153,   145,   191,     3,   116,   191,    78,   161,
     162,   167,   243,   152,   130,   152,   130,     3,   131,   132,
     124,   128,   144,   212,   235,   238,    78,   238,    78,   235,
     215,   215,   215,   216,   216,   217,   217,   217,   218,   218,
     218,   218,   218,   218,   219,   219,   219,   219,   221,   223,
     225,   227,   235,   229,   235,   242,    47,   123,   134,    79,
     203,   142,   150,   235,     3,   131,   132,   165,    47,    78,
     164,   166,   167,    28,   237,    25,    26,    27,    29,    77,
      21,    22,    23,    24,    20,    19,    18,    17,    15,    16,
       3,   131,   106,   213,   150,   150,   128,   128,    47,   155,
     189,   128,   128,   130,   149,   130,    78,   124,   143,   167,
     112,   113,   191,     3,   128,   170,   207,   235,    78,     3,
     128,   134,   134,   132,   134,   235,   213,    47,    47,   128,
      78,   207,   130,    78,   167,   238,   133,   171,   192,     3,
     131,    28,   171,   238,   213,   236,   218,   218,   218,   218,
     218,   220,   220,   220,   220,   222,   224,   226,   228,   236,
     230,   236,   241,   166,    28,   128,   128,   152,   129,   181,
      78,   152,   152,   191,    78,   191,   129,   141,   129,   141,
     162,   152,   132,   144,   235,   235,    28,   213,   238,   129,
     132,   128,   236,   166,   241,   238,   128,   132,   131,    28,
     238,   129,   129,    65,    55,   182,   183,   193,   128,   145,
     145,   235,   238,    28,   128,   145,    78,   167,   243,   131,
     128,   152,   236,   241,   238,   128,   145,   145,   152,   238,
     183,    62,   130,   184,   155,   130,   130,   128,   238,   130,
     241,   152,   128,   128,   152,   130,   130,   132,   132,   193,
     128,   128,   152,   152,   158,   190,   190,   130,   152
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
     140,   140,   140,   140,   140,   140,   141,   142,   142,   142,
     142,   142,   143,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   155,   156,
     157,   157,   158,   158,   159,   159,   159,   160,   161,   161,
     162,   162,   163,   163,   164,   164,   165,   165,   166,   166,
     167,   167,   168,   169,   169,   169,   169,   169,   169,   170,
     171,   172,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   176,   177,   178,   179,   180,   181,   181,
     182,   182,   183,   184,   185,   186,   187,   187,   187,   188,
     189,   190,   190,   191,   191,   192,   192,   193,   193,   194,
     194,   194,   194,   194,   195,   196,   196,   197,   197,   197,
     197,   197,   197,   198,   198,   198,   198,   199,   199,   200,
     200,   201,   202,   202,   203,   203,   204,   205,   205,   206,
     206,   207,   207,   207,   208,   208,   208,   208,   208,   209,
     209,   210,   210,   210,   210,   211,   211,   212,   212,   212,
     212,   213,   213,   214,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   216,   216,   216,   216,
     217,   217,   217,   218,   218,   218,   218,   219,   219,   219,
     219,   219,   219,   219,   220,   220,   220,   220,   220,   220,
     221,   221,   221,   221,   221,   222,   222,   222,   222,   222,
     223,   223,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   232,   232,
     233,   233,   234,   234,   235,   235,   236,   236,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     238,   238,   239,   239,   240,   240,   241,   241,   242,   242,
     243,   243
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
       1,     1,     4,     1,     3,     3,     5,     3,     5,     2,
       2,     1,     2,     7,     5,     7,     5,     9,    10,     7,
       8,     8,     9,     3,     3,     3,     5,     5,     3,     5,
       1,     2,     4,     3,     3,     3,     3,     3,     4,     5,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     4,     2,     4,     1,
       2,     2,     6,     7,     0,     4,     3,     0,     2,     3,
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
  "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "')'", "'{'", "'}'", "';'",
  "':'", "'='", "']'", "$accept", "program", "$@1", "function_declaration",
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
       136,     0,    -1,    -1,   137,   146,    -1,    75,    78,    47,
     150,   128,   129,   145,   130,    -1,    59,    78,    47,   150,
     128,   129,   145,   130,    -1,    75,   151,    47,   150,   128,
     129,   145,   130,    -1,   140,    -1,   115,   142,   116,   112,
     129,   145,   130,    -1,   112,   129,   145,   130,    -1,   115,
     142,   116,   113,   129,   145,   130,    -1,   113,   129,   145,
     130,    -1,   115,   142,   116,   112,   141,    -1,   115,   142,
     116,   113,   141,    -1,   113,   141,    -1,   112,   141,    -1,
     126,   235,    -1,    78,   191,    -1,   167,   191,    -1,   142,
       3,    78,   191,    -1,   142,     3,   167,   191,    -1,   142,
       3,   143,    -1,   124,    78,    -1,   124,    78,    -1,    -1,
     147,    -1,   148,    -1,   146,   148,    -1,   149,    -1,   147,
     149,    -1,   152,    -1,   138,    -1,   153,    -1,   138,    -1,
      -1,   142,    -1,    -1,    78,    -1,   153,    -1,   156,    -1,
     157,    -1,   155,    -1,   154,    -1,   159,    -1,   160,    -1,
     172,    -1,   173,    -1,   174,    -1,   175,    -1,   176,    -1,
     177,    -1,   178,    -1,   179,    -1,   185,    -1,   180,    -1,
     186,    -1,   187,    -1,   129,   130,    -1,   129,   158,   130,
      -1,   125,    78,   152,    -1,    67,   165,   243,    -1,    67,
     138,    -1,   152,    -1,   158,   152,    -1,   106,   163,   243,
      -1,    59,   163,   243,    -1,   122,   163,   243,    -1,   122,
      47,   161,   128,   152,    -1,   162,    -1,   161,     3,   162,
      -1,    78,   191,    -1,   167,   170,    -1,   165,    -1,   163,
       3,   165,    -1,   166,    -1,   164,     3,   166,    -1,    78,
     191,    -1,   167,   170,    -1,    78,   192,    -1,   167,   171,
      -1,   198,    -1,   168,    -1,   129,   169,   131,   130,    -1,
      78,    -1,   207,   132,    78,    -1,   207,   132,   167,    -1,
     169,     3,   207,   132,    78,    -1,   169,     3,    78,    -1,
     169,     3,   207,   132,   167,    -1,   133,   235,    -1,   133,
     236,    -1,   243,    -1,   238,   243,    -1,    79,    47,   238,
     128,   152,    65,   152,    -1,    79,    47,   238,   128,   152,
      -1,    63,   152,   108,    47,   238,   128,   243,    -1,   108,
      47,   238,   128,   152,    -1,    73,    47,   240,   131,   241,
     131,   241,   128,   152,    -1,    73,    47,   106,   164,   131,
     241,   131,   241,   128,   152,    -1,    73,    47,   213,    28,
     238,   128,   152,    -1,    73,    47,   106,   166,    28,   238,
     128,   152,    -1,    73,   123,    47,   213,    28,   238,   128,
     152,    -1,    73,   123,    47,   106,   166,    28,   238,   128,
     152,    -1,    60,   151,   243,    -1,    53,   151,   243,    -1,
      93,   241,   243,    -1,   109,    47,   238,   128,   152,    -1,
      98,    47,   238,   128,   181,    -1,   129,   193,   130,    -1,
     129,   193,   184,   193,   130,    -1,   183,    -1,   182,   183,
      -1,    55,   238,   132,   190,    -1,    62,   132,   190,    -1,
      78,   132,   152,    -1,   101,   238,   243,    -1,   105,   155,
     188,    -1,   105,   155,   189,    -1,   105,   155,   188,   189,
      -1,    56,    47,    78,   128,   155,    -1,    71,   155,    -1,
      -1,   158,    -1,    -1,   170,    -1,    -1,   171,    -1,    -1,
     182,    -1,   195,    -1,   196,    -1,    87,    -1,    96,    -1,
      92,    -1,    86,    -1,   104,    -1,    69,    -1,   100,    -1,
      78,    -1,   194,    -1,   198,    -1,   204,    -1,    47,   238,
     128,    -1,    49,   242,   134,    -1,    49,   199,   134,    -1,
      49,   199,     3,   242,   134,    -1,    49,   199,   201,   134,
      -1,   242,   235,    -1,   199,     3,   242,   235,    -1,     3,
      -1,   200,     3,    -1,   202,   203,    -1,    73,    47,   213,
      28,   238,   128,    -1,    73,   123,    47,   213,    28,   238,
     128,    -1,    -1,    79,    47,   238,   128,    -1,   129,   205,
     130,    -1,    -1,   206,   131,    -1,   207,   132,   235,    -1,
     206,     3,   207,   132,   235,    -1,    78,    -1,    96,    -1,
      87,    -1,   197,    -1,   139,    -1,   208,    49,   238,   134,
      -1,   208,    50,    78,    -1,    48,   208,   211,    -1,   208,
      -1,    48,   209,    -1,   208,   211,    -1,   210,   211,    -1,
     210,    49,   238,   134,    -1,   210,    50,    78,    -1,    47,
     128,    -1,    47,   212,   128,    -1,   235,    -1,   144,    -1,
     212,     3,   235,    -1,   212,     3,   144,    -1,   209,    -1,
     210,    -1,   213,    -1,   213,    46,    -1,   213,    45,    -1,
     214,    -1,    42,   215,    -1,    43,   215,    -1,    44,   215,
      -1,    46,   215,    -1,    45,   215,    -1,    35,   215,    -1,
      36,   215,    -1,    41,   215,    -1,    40,   215,    -1,   215,
      -1,   216,    37,   215,    -1,   216,    38,   215,    -1,   216,
      39,   215,    -1,   216,    -1,   217,    35,   216,    -1,   217,
      36,   216,    -1,   217,    -1,   218,    34,   217,    -1,   218,
      33,   217,    -1,   218,    32,   217,    -1,   218,    -1,   219,
      26,   218,    -1,   219,    25,   218,    -1,   219,    29,   218,
      -1,   219,    77,   218,    -1,   219,    27,   218,    -1,   219,
      28,   218,    -1,   218,    -1,   220,    26,   218,    -1,   220,
      25,   218,    -1,   220,    29,   218,    -1,   220,    77,   218,
      -1,   220,    27,   218,    -1,   219,    -1,   221,    23,   219,
      -1,   221,    22,   219,    -1,   221,    24,   219,    -1,   221,
      21,   219,    -1,   220,    -1,   222,    23,   220,    -1,   222,
      22,   220,    -1,   222,    24,   220,    -1,   222,    21,   220,
      -1,   221,    -1,   223,    20,   221,    -1,   222,    -1,   224,
      20,   222,    -1,   223,    -1,   225,    19,   223,    -1,   224,
      -1,   226,    19,   224,    -1,   225,    -1,   227,    18,   225,
      -1,   226,    -1,   228,    18,   226,    -1,   227,    -1,   229,
      17,   227,    -1,   228,    -1,   230,    17,   228,    -1,   229,
      -1,   231,    16,   229,    -1,   230,    -1,   232,    16,   230,
      -1,   231,    -1,   231,    15,   235,   132,   235,    -1,   232,
      -1,   232,    15,   236,   132,   236,    -1,   233,    -1,   213,
     237,   235,    -1,   234,    -1,   213,   237,   236,    -1,   133,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   235,    -1,   238,     3,   235,    -1,   236,
      -1,   239,     3,   236,    -1,    -1,   239,    -1,    -1,   238,
      -1,    -1,   200,    -1,   131,    -1,   111,    -1
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
     251,   253,   255,   260,   262,   266,   270,   276,   280,   286,
     289,   292,   294,   297,   305,   311,   319,   325,   335,   346,
     354,   363,   372,   382,   386,   390,   394,   400,   406,   410,
     416,   418,   421,   426,   430,   434,   438,   442,   446,   451,
     457,   460,   461,   463,   464,   466,   467,   469,   470,   472,
     474,   476,   478,   480,   482,   484,   486,   488,   490,   492,
     494,   496,   498,   502,   506,   510,   516,   521,   524,   529,
     531,   534,   537,   544,   552,   553,   558,   562,   563,   566,
     570,   576,   578,   580,   582,   584,   586,   591,   595,   599,
     601,   604,   607,   610,   615,   619,   622,   626,   628,   630,
     634,   638,   640,   642,   644,   647,   650,   652,   655,   658,
     661,   664,   667,   670,   673,   676,   679,   681,   685,   689,
     693,   695,   699,   703,   705,   709,   713,   717,   719,   723,
     727,   731,   735,   739,   743,   745,   749,   753,   757,   761,
     765,   767,   771,   775,   779,   783,   785,   789,   793,   797,
     801,   803,   807,   809,   813,   815,   819,   821,   825,   827,
     831,   833,   837,   839,   843,   845,   849,   851,   855,   857,
     861,   863,   869,   871,   877,   879,   883,   885,   889,   891,
     893,   895,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   919,   921,   925,   926,   928,   929,   931,   932,
     934,   936
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   332,   332,   332,   346,   363,   379,   389,   402,   411,
     420,   430,   440,   450,   461,   472,   486,   506,   522,   533,
     543,   553,   568,   585,   595,   596,   600,   608,   618,   626,
     636,   637,   647,   648,   658,   659,   666,   667,   676,   677,
     682,   690,   695,   699,   704,   708,   713,   718,   723,   728,
     733,   738,   743,   748,   753,   758,   763,   771,   778,   789,
     804,   811,   822,   830,   841,   849,   857,   868,   878,   884,
     891,   899,   910,   918,   928,   934,   942,   950,   960,   968,
     979,   986,   993,  1004,  1014,  1026,  1038,  1048,  1056,  1067,
    1071,  1075,  1079,  1089,  1098,  1110,  1118,  1126,  1138,  1150,
    1161,  1173,  1184,  1198,  1208,  1218,  1228,  1239,  1250,  1254,
    1263,  1269,  1277,  1288,  1299,  1312,  1322,  1331,  1340,  1352,
    1363,  1371,  1372,  1376,  1377,  1381,  1382,  1386,  1387,  1391,
    1392,  1393,  1400,  1407,  1417,  1427,  1434,  1444,  1451,  1458,
    1459,  1460,  1461,  1469,  1479,  1486,  1496,  1507,  1517,  1528,
    1529,  1534,  1542,  1549,  1559,  1560,  1569,  1584,  1587,  1594,
    1603,  1613,  1620,  1627,  1637,  1641,  1645,  1658,  1673,  1689,
    1690,  1700,  1713,  1726,  1739,  1757,  1758,  1762,  1768,  1774,
    1779,  1787,  1788,  1792,  1796,  1803,  1813,  1814,  1821,  1828,
    1835,  1842,  1849,  1856,  1863,  1870,  1880,  1881,  1885,  1889,
    1896,  1897,  1901,  1908,  1909,  1913,  1917,  1924,  1925,  1929,
    1933,  1937,  1941,  1945,  1952,  1953,  1957,  1961,  1965,  1969,
    1976,  1977,  1981,  1985,  1989,  1996,  1997,  2001,  2005,  2009,
    2016,  2017,  2024,  2025,  2032,  2033,  2040,  2041,  2048,  2049,
    2056,  2057,  2064,  2065,  2072,  2073,  2080,  2081,  2088,  2089,
    2096,  2097,  2106,  2107,  2116,  2120,  2130,  2134,  2145,  2146,
    2147,  2148,  2149,  2150,  2151,  2152,  2153,  2154,  2155,  2156,
    2160,  2167,  2175,  2182,  2190,  2191,  2195,  2196,  2200,  2201,
    2205,  2206
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
  const int ParserImplementation::yylast_ = 1722;
  const int ParserImplementation::yynnts_ = 109;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 135;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 365;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4713 "grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2209 "grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


