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
#line 1 "grammar/grammar.yy"

#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <compiler/compiler.h>
#include <compiler/tokens/token_info.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/binding/parser_connector.h>
#include <compiler/binding/yylex.h>
#include <ast/ast.h>
#include <ast/visitors/ast_visitor.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/pool/managed_handle.h>

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
#line 73 "grammar/grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 82 "grammar/grammar.tab.cc"

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
#line 168 "grammar/grammar.tab.cc"

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
#line 341 "grammar/grammar.yy"
    {int yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 342 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 356 "grammar/grammar.yy"
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
#line 373 "grammar/grammar.yy"
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
#line 389 "grammar/grammar.yy"
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
#line 398 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 412 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 421 "grammar/grammar.yy"
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
#line 430 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 440 "grammar/grammar.yy"
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
#line 450 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(5) - (2)].ast) );
    fn->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    fn->FunctionType( Function::kShorten );
    (yyval.function) = fn;
  }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 460 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(5) - (2)].ast) );
    fn->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    fn->FunctionType( Function::kShorten );
    fn->ContextType( Function::kThis );
    (yyval.function) = fn;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 471 "grammar/grammar.yy"
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
#line 482 "grammar/grammar.yy"
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
#line 496 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 506 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 508 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 526 "grammar/grammar.yy"
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

  case 20:

/* Line 690 of lalr1.cc  */
#line 542 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(2) - (1)].value_node)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    list->AddChild( (yysemantic_stack_[(2) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 550 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 560 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(4) - (3)].value_node)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 569 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 570 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 580 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 597 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 606 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 607 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 612 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 620 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 630 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 638 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 647 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 649 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 658 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 660 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 669 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 671 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 677 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 679 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 687 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 689 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 694 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 702 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 706 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 711 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 716 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 720 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 725 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 730 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 735 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 740 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 745 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 750 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 755 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 760 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 765 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 770 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 775 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 780 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 787 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 794 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 805 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 818 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(3) - (2)].value_node) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 825 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].function) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 836 "grammar/grammar.yy"
    {
  ValueNode* node = (yysemantic_stack_[(5) - (4)].ast)->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  value->Symbol( (yysemantic_stack_[(5) - (2)].info) );
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kVar , type ) );
  stmt->Exp( value );
  stmt->From( (yysemantic_stack_[(5) - (4)].ast) );
  stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
  (yyval.ast) = stmt;
}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 853 "grammar/grammar.yy"
    {
  ValueNode* node = (yysemantic_stack_[(5) - (4)].ast)->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kDst , type ) );
  stmt->Exp( (yysemantic_stack_[(5) - (2)].value_node) );
  stmt->From( (yysemantic_stack_[(5) - (4)].ast) );
  stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
  (yyval.ast) = stmt;
}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 868 "grammar/grammar.yy"
    {
  ValueNode* node = (yysemantic_stack_[(5) - (4)].ast)->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
  value->Symbol( (yysemantic_stack_[(5) - (2)].info) );
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kAll , type ) );
  stmt->Exp( value );
  stmt->From( (yysemantic_stack_[(5) - (4)].ast) );
  stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
  (yyval.ast) = stmt;
}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 888 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 896 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 904 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 914 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 922 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 933 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 941 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 949 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 960 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 970 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 976 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 983 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 991 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1002 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1010 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1020 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1042 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1052 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1060 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1082 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    if ( (yysemantic_stack_[(3) - (2)].opt) ) {
      value->AddChild( GetEmptyNode() );
      value->AddChild( GetEmptyNode() );
    }
    value->Line( connector->GetLineNumber() );
    (yyval.value_node) = value;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1092 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1099 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->AddChild( (yysemantic_stack_[(5) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(5) - (2)].node_list)->Line() );
    if ( (yysemantic_stack_[(5) - (4)].opt) ) {
      value->AddChild( GetEmptyNode() );
    }
    (yyval.value_node) = value;
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1112 "grammar/grammar.yy"
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

  case 96:

/* Line 690 of lalr1.cc  */
#line 1124 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->Line( (yysemantic_stack_[(2) - (2)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(2) - (2)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1134 "grammar/grammar.yy"
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

  case 98:

/* Line 690 of lalr1.cc  */
#line 1144 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1155 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1166 "grammar/grammar.yy"
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

  case 101:

/* Line 690 of lalr1.cc  */
#line 1176 "grammar/grammar.yy"
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

  case 102:

/* Line 690 of lalr1.cc  */
#line 1188 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1198 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1208 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1216 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1226 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1230 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1234 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1239 "grammar/grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(2) - (1)].expression)->Line() );
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1249 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1258 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1270 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1278 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1286 "grammar/grammar.yy"
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

  case 115:

/* Line 690 of lalr1.cc  */
#line 1298 "grammar/grammar.yy"
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

  case 116:

/* Line 690 of lalr1.cc  */
#line 1310 "grammar/grammar.yy"
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

  case 117:

/* Line 690 of lalr1.cc  */
#line 1321 "grammar/grammar.yy"
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

  case 118:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar/grammar.yy"
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

  case 119:

/* Line 690 of lalr1.cc  */
#line 1344 "grammar/grammar.yy"
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

  case 120:

/* Line 690 of lalr1.cc  */
#line 1358 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1368 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1378 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1388 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1399 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1410 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1414 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1423 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1429 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1437 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1448 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1459 "grammar/grammar.yy"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1472 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1482 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1491 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1500 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1512 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1523 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1530 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1531 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1535 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1536 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1540 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1541 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1545 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1546 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1550 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1551 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1553 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1560 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1567 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1577 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1587 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1594 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1604 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1611 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1618 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1619 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar/grammar.yy"
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

  case 161:

/* Line 690 of lalr1.cc  */
#line 1639 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1646 "grammar/grammar.yy"
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

  case 163:

/* Line 690 of lalr1.cc  */
#line 1656 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1667 "grammar/grammar.yy"
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

  case 165:

/* Line 690 of lalr1.cc  */
#line 1677 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1702 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1709 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1718 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1720 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1729 "grammar/grammar.yy"
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

  case 174:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1747 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1754 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1763 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1773 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1780 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1787 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1797 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1801 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1805 "grammar/grammar.yy"
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

  case 184:

/* Line 690 of lalr1.cc  */
#line 1818 "grammar/grammar.yy"
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

  case 185:

/* Line 690 of lalr1.cc  */
#line 1833 "grammar/grammar.yy"
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

  case 186:

/* Line 690 of lalr1.cc  */
#line 1848 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1850 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1860 "grammar/grammar.yy"
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

  case 189:

/* Line 690 of lalr1.cc  */
#line 1873 "grammar/grammar.yy"
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

  case 190:

/* Line 690 of lalr1.cc  */
#line 1886 "grammar/grammar.yy"
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

  case 191:

/* Line 690 of lalr1.cc  */
#line 1899 "grammar/grammar.yy"
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

  case 192:

/* Line 690 of lalr1.cc  */
#line 1916 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1917 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1922 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1928 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1939 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1946 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1947 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1948 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1949 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1958 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1965 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1974 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1976 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1983 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1997 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2004 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2011 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2018 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2025 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2032 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2041 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2043 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2047 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2051 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2057 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2059 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2063 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2069 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2071 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2075 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2079 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2085 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2087 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2091 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2095 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2099 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2103 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2107 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2113 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2115 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2119 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2123 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2127 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2131 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2137 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2139 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2143 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2147 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2151 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2157 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2159 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2163 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2167 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2171 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2177 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2179 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2185 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2187 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2193 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2195 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2201 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2203 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2209 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2211 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2217 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2219 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2225 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2227 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2233 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2235 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2241 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2243 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2249 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2251 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2257 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2259 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2267 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2269 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2278 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2282 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2292 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2296 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2306 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2307 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2309 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2310 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2311 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2312 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2313 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2314 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2315 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2316 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2317 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2322 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2329 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2337 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2344 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2351 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2352 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2356 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2357 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2361 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2362 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2366 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2367 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3656 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -383;
  const short int
  ParserImplementation::yypact_[] =
  {
      -383,    66,  1063,  -383,  1645,  1645,  1645,  1645,  1645,  1645,
    1645,  1645,  1645,  1645,  1740,    30,     0,   120,     0,  1162,
     115,  -383,   -16,    17,   -25,    72,   223,  -383,  -383,  -383,
    1645,  -383,    82,  -383,  1645,  -383,   -28,   180,    84,   140,
    -383,    98,   101,   186,    73,     0,    30,   150,   763,  -383,
    -383,  -383,  -383,  1063,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,    76,  -383,   251,   466,  -383,  -383,
     377,   189,   103,   235,   375,   175,   102,   188,   156,   295,
    -383,  -383,    18,  -383,     0,  -383,   239,   195,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,    22,    76,  -383,
    -383,     9,   218,   563,  -383,     4,   -32,    41,  -383,    94,
    -383,  -383,     4,   180,   136,   173,   178,    94,  -383,     4,
    1455,   270,   281,   298,  1162,  1645,   108,   145,   221,   360,
       4,  1645,    18,   863,    20,    41,  1645,  1645,  1645,  1261,
    -383,  1261,  -383,    94,  -383,   368,   260,    94,   225,    41,
    1162,    62,   126,   244,  -383,  -383,    77,   248,   -25,   254,
     257,  -383,  -383,   963,   252,    32,   267,  -383,  1360,  1645,
     315,  -383,  1645,   330,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  1645,
    1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,
    1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,
    1645,  1645,  1645,  1645,  1645,  -383,  -383,  -383,  -383,    30,
      -9,  -383,   289,   352,  -383,  -383,  -383,  -383,   186,  1645,
    -383,  -383,   180,  -383,  -383,  -383,   388,   407,   281,  -383,
     240,   205,   103,    60,   384,   436,   439,   448,   450,   327,
    -383,  -383,   465,   344,  1678,   186,   186,  -383,    24,   -60,
     -60,   -60,  -383,    25,  -383,   437,   -28,   411,  -383,  -383,
      26,    39,  -383,  -383,   355,  1261,  -383,  -383,   356,  -383,
     -30,   243,  -383,    94,    40,  -383,    94,  -383,  -383,    30,
    -383,  -383,  -383,  -383,   303,  -383,   256,  -383,  -383,  -383,
     239,  -383,  1645,   412,  -383,  -383,    42,  -383,    10,  -383,
      13,  -383,  -383,  -383,  -383,  -383,   377,   377,   189,   189,
     189,   103,   103,   103,   103,   103,   103,   235,   235,   235,
     235,   375,   175,   102,   188,   351,   156,  -383,   664,  1733,
     446,  -383,   447,  -383,   364,  -383,  -383,  1645,   361,    33,
     473,   361,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,
    1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,  1645,
    1645,   240,   474,   371,   378,  1162,  -383,  -383,   -10,   -10,
     -10,   374,   430,  -383,  -383,  1162,  1162,  -383,  -383,  -383,
      94,   435,  -383,  -383,    94,   198,   237,  -383,   225,  1162,
    -383,   141,   244,   380,  -383,  -383,   382,  -383,  -383,  1550,
    -383,  -383,  -383,  1645,  -383,  -383,   491,  1733,  1645,   392,
      44,  1645,  -383,  -383,   240,  1645,  1645,  -383,    50,   466,
    -383,   103,   103,   103,   103,   103,    60,    60,    60,    60,
     384,   436,   439,   448,   391,   450,  -383,   390,   500,  1645,
     396,   397,   467,   453,  -383,  -383,  -383,   478,  -383,   403,
    -383,  -383,  -383,  -383,  -383,  1261,  -383,  1261,  -383,  -383,
    -383,  -383,  -383,  -383,   259,  1645,  -383,  -383,  -383,  1645,
     509,    51,  1261,     4,  -383,  -383,   401,    52,  1162,  1645,
    1645,  1645,    53,  1261,  1261,  1162,  -383,  1645,   478,  -383,
     -22,   -28,   405,   406,  -383,  -383,  -383,    57,  1645,  -383,
     408,  -383,  1645,  1162,  -383,  -383,   409,    58,  1162,   413,
     414,  -383,     8,  -383,   410,  -383,   478,  -383,  -383,  -383,
    -383,    61,  -383,   417,  -383,  1162,  1162,  -383,  -383,  -383,
    1162,  1162,   416,  -383,  1162,  -383,  -383,  1162,  -383,  -383,
    -383,  -383
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,    39,     0,    39,     0,
       0,   153,     0,    39,   155,     0,     0,   151,   148,   150,
     295,   149,     0,   154,     0,   152,     0,     0,     0,     0,
     300,     0,     0,    37,     0,    39,   297,     0,     0,   299,
      34,   182,     7,     3,    29,    33,    41,    45,    44,    42,
      43,    60,    46,    47,   200,   201,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    56,    58,    59,   156,   146,
     147,   181,   157,   158,   186,   198,   199,   202,   205,   215,
     219,   222,   226,   239,   249,   253,   257,   261,   265,   269,
     273,   289,     0,   108,    39,   155,   174,   202,   211,   212,
     214,   213,   206,   207,   208,   210,   209,     0,   186,   187,
     166,     0,   298,     0,    40,     0,   140,     0,    82,   140,
      90,    91,     0,     0,     0,     0,     0,   140,    65,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      15,    27,    14,   140,    38,    17,     0,   140,     0,     0,
       0,     0,     0,   100,   180,   179,     0,     0,   155,   148,
     149,    61,    72,     0,     0,     0,     0,    30,     0,     0,
       0,   188,     0,     0,   189,   285,   282,   284,   283,   288,
     287,   278,   280,   279,   286,   281,   204,   203,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   178,   159,   185,   297,
       0,   161,     0,   171,   167,   160,   164,   121,    37,     0,
     141,    86,     0,    75,    87,   120,     0,     0,     0,    64,
       0,   202,   233,   244,   251,   255,   259,   263,   267,   271,
     275,   291,   294,     0,     0,    37,    37,   131,     0,     0,
       0,     0,   122,     0,   132,     0,     0,   133,   134,    74,
       0,     0,    16,    36,     0,    28,    31,    35,     0,    19,
      23,     0,    20,   140,     0,    78,     0,    76,    63,   297,
      93,    95,    92,    96,     0,    99,     0,    62,    73,   173,
       0,   175,     0,     0,   192,   195,     0,   194,     0,   184,
       0,   191,   274,   216,   217,   218,   220,   221,   225,   224,
     223,   228,   227,   231,   232,   229,   230,   243,   241,   240,
     242,   250,   254,   258,   262,     0,   266,   290,     0,     0,
       0,   163,     0,   168,     0,   106,    83,     0,   142,     0,
      84,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,    70,    69,     0,     0,
       0,     0,     0,   137,   135,     0,     0,     9,    32,    11,
     140,     0,    18,    24,   140,     0,     0,    80,     0,     0,
      81,     0,   104,     0,   101,   102,     0,   176,    26,     0,
     193,   183,   190,     0,   162,   165,     0,     0,     0,     0,
       0,     0,   143,    88,     0,   295,     0,    89,     0,   202,
     276,   235,   234,   238,   236,   237,   248,   246,   245,   247,
     252,   256,   260,   264,     0,   268,   292,     0,     0,     0,
       0,     0,   111,     0,    66,    68,    67,   144,   124,     0,
     113,   123,    21,    25,    22,    27,    12,    27,    13,    79,
      77,    97,    94,    98,     0,     0,   197,   196,   270,     0,
       0,     0,    27,     0,   107,    85,     0,     0,     0,     0,
     295,     0,     0,    27,    27,     0,    71,     0,   145,   127,
       0,     0,     0,     0,   103,   105,   177,     0,     0,   172,
       0,   112,   295,     0,   116,   272,     0,     0,     0,     0,
       0,   110,     0,   128,     0,   125,   144,   136,     8,    10,
     169,     0,     5,     0,   117,     0,     0,   118,     4,     6,
     138,   138,     0,   170,     0,   114,   119,   139,   129,   130,
     126,   115
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -383,  -383,  -383,   184,  -383,  -383,   -40,  -383,  -383,  -383,
    -383,   114,  -141,  -383,  -383,   493,   261,   -48,    79,    -2,
    -155,  -383,   -33,  -383,  -383,  -383,   -14,  -149,  -383,  -383,
    -383,   133,    78,  -383,   -13,  -341,   153,    64,  -383,    74,
    -383,   246,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,    37,  -383,  -383,  -383,  -383,  -383,
     272,    -1,  -115,   190,    11,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,  -383,   -17,   549,
     550,  -383,    -4,  -383,    63,  -383,   155,   217,   208,   241,
     194,   142,   338,   187,   340,   183,   343,   191,   346,   192,
     342,   193,  -383,  -383,  -383,  -383,  -100,  -363,   492,   -12,
    -383,  -383,  -382,   -41,   -93
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   293,    51,    52,   160,   164,   165,   412,
     413,   325,   294,    53,   295,    54,   296,   166,   143,   182,
      56,    57,    58,    59,    60,    61,   398,   183,    62,    63,
     304,   305,   127,   369,   128,   370,   129,    64,   171,    65,
     176,   250,   442,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   478,   518,   519,   546,    75,    76,    77,   287,
     288,   568,   251,   443,   520,    78,    79,    80,    81,    82,
     121,   122,   242,   243,   363,    83,   184,   185,   186,    84,
      85,    86,   191,   326,    87,    88,    89,    90,    91,    92,
      93,   263,    94,   264,    95,   265,    96,   266,    97,   267,
      98,   268,    99,   269,   100,   270,   101,   271,   373,   102,
     272,   273,   150,   123,   103
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -181;
  const short int
  ParserImplementation::yytable_[] =
  {
        55,   117,   162,   154,   297,   172,   297,   139,   467,   235,
     450,   234,   239,   234,   254,   248,   234,   134,   149,   396,
     298,   234,   152,   246,   464,   234,   466,   234,   234,   234,
     177,   140,   247,   120,   253,   320,   444,   397,   359,   255,
     473,   544,   234,   418,   252,   429,   259,   234,   299,   410,
     468,    55,   302,   234,   234,   234,   234,   282,   292,   284,
     234,   234,   289,   506,   234,   309,     3,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   307,   285,   504,   124,
     314,   130,   194,   240,   130,   374,   375,   376,   327,   377,
     130,   131,   286,   411,   131,   125,   142,   132,    46,    47,
     131,   130,    40,   505,   249,   153,   141,   130,   130,   332,
     144,   131,   545,   360,   238,   155,    40,   131,   131,   145,
     168,   229,   169,   188,   170,   189,   190,    49,   536,   151,
      40,   156,   355,   278,   357,   215,   216,   217,   378,   283,
     297,    49,   277,   560,   290,   291,   535,   241,   431,   365,
     553,   432,   137,    40,   237,    49,   395,   401,   405,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   308,   321,
     445,   406,   419,   231,   430,   135,   503,   328,    49,   148,
     330,   318,   508,   529,   533,   538,    50,   157,   417,   550,
     556,   136,   310,   563,   137,   228,   167,   130,   358,   126,
     364,    46,    47,   261,   138,   311,   230,   131,   315,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     491,   244,   427,   158,   213,   214,   158,   393,   394,   173,
     249,   159,   130,   372,   161,   279,   130,    50,   174,   366,
     206,   207,   131,    46,    47,   256,   131,   175,    46,    47,
     206,   207,   257,   403,    46,    47,   312,   258,   435,   137,
     218,   219,   220,   221,   222,   163,   399,   400,   421,    46,
      47,   492,   280,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   482,   107,   423,   188,   484,
     192,   193,   146,   426,   303,   474,   475,   476,    46,    47,
     232,   233,   130,   223,    46,    47,   130,   274,   236,   368,
     147,   306,   131,   158,   130,   313,   131,   174,   275,   497,
     297,   485,   297,   498,   131,   424,   175,   392,   524,   130,
     130,   208,   387,   388,   522,   276,   523,   297,   281,   131,
     131,    46,    47,    46,    47,   440,   415,   416,   297,   297,
     448,   530,   158,   234,   130,   333,   334,   335,    46,    47,
     487,   300,   539,   540,   131,   486,   488,   301,   149,  -178,
     130,   262,   422,   316,    46,    47,   319,    46,    47,  -180,
     131,   174,  -179,   472,   329,   526,   224,   225,   226,   227,
     175,   167,   322,   480,   481,   379,   380,   381,   382,   331,
     531,   567,   567,   371,   210,   211,   212,   490,   347,   348,
     349,   350,   436,   338,   339,   340,   501,   361,   167,   167,
     336,   337,   362,   149,   507,   367,   449,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     449,   107,   449,   414,   248,   130,   383,   512,   384,   341,
     342,   343,   344,   345,   346,   131,   385,   386,   389,   425,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   390,   130,   286,   402,   130,   433,   527,   547,   407,
     409,   428,   131,   437,   438,   131,   439,   441,   149,   537,
     500,   446,   469,   470,   449,   542,   534,   477,   130,   479,
     471,   206,   207,   541,   483,   494,   551,   495,   131,   499,
     149,   456,   457,   458,   459,   502,   509,   510,   511,   513,
     514,   554,   516,   515,   517,   521,   557,   528,   532,   548,
     549,   555,   552,   496,   371,   561,   187,   558,   559,   564,
     570,   489,   420,   565,   566,   543,   408,   562,   130,   404,
     569,   447,   571,   118,   119,   318,   351,   461,   131,   352,
     460,   306,   449,   353,   493,   356,   462,   354,   463,   209,
       0,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,     4,     5,
       0,     0,   208,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,   262,   451,   452,   453,   454,   455,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,     0,     0,    21,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,     0,     0,   525,     0,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,     0,   106,     0,     0,     4,
       5,   245,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     104,     0,     0,   105,     0,     0,     0,     0,     0,     0,
     262,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,     0,     0,     0,   106,     4,     5,
       0,     0,   434,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   133,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   104,
       0,     0,   178,    25,     0,    26,     0,     0,     0,     0,
      27,   179,     0,     0,     0,     0,    29,    30,     0,     0,
     180,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,    48,   181,     4,     5,
      49,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   133,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   104,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,    48,   181,     4,     5,
      49,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   133,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   104,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,    48,   317,     4,     5,
      49,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,    23,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,    48,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   133,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,   104,     0,
       0,    24,    25,     0,    26,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    33,    34,     0,     0,    35,    36,    37,
       0,    38,    39,     0,    40,    41,    42,     0,    43,     0,
       0,     0,     0,    44,     0,     0,    45,     0,     0,     0,
      46,    47,     0,     0,     0,    48,     4,     5,     0,    49,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,     0,    23,     0,     0,
      24,    25,     0,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    33,    34,     0,     0,    35,    36,    37,     0,
      38,    39,     0,    40,    41,    42,     0,    43,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,    48,     4,     5,     0,    49,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   104,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,    46,    47,
       4,     5,   324,   106,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   104,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,   260,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,     4,     5,     0,   106,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   104,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,    46,    47,
       4,     5,     0,   106,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   104,     0,     0,   105,    13,    14,    15,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,    21,     0,
      35,     0,     0,     0,   104,     0,     0,   105,    41,    42,
       0,    43,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,    46,    47,    31,     0,     0,   106,    33,
      13,    14,    15,    35,     0,   391,     0,    13,    14,    15,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    46,    47,     0,   104,
      21,   106,   105,     0,     0,     0,   104,     0,     0,   105,
      27,    28,     0,     0,     0,     0,    29,    27,    28,     0,
      31,     0,     0,    29,    33,     0,     0,    31,    35,     0,
       0,    33,     0,     0,     0,    35,    41,    42,     0,    43,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,    46,    47,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,   106
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,    13,    42,    36,   159,    46,   161,    20,   390,   102,
     373,     3,     3,     3,   129,    47,     3,    19,    30,    79,
     161,     3,    34,   123,   387,     3,   389,     3,     3,     3,
      47,    47,   125,     3,   127,     3,     3,    97,    47,   132,
      50,    63,     3,     3,     3,     3,   139,     3,   163,    79,
     391,    53,   167,     3,     3,     3,     3,   150,   158,   152,
       3,     3,   155,   445,     3,     3,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   169,    57,   441,    79,
       3,    17,    86,    74,    20,    25,    26,    27,   188,    29,
      26,    17,    72,   123,    20,    16,    79,    18,   128,   129,
      26,    37,   112,   444,   136,   133,   122,    43,    44,   209,
     135,    37,   134,   122,   118,    37,   112,    43,    44,    47,
      47,    19,    44,    47,    45,    49,    50,   137,   510,    47,
     112,    47,   232,   145,   234,    32,    33,    34,    78,   151,
     295,   137,   144,   135,   156,   157,   509,   138,   138,   249,
     532,   138,    79,   112,   132,   137,   132,   132,   132,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   170,   137,
     137,   132,   132,    17,   132,    60,   132,   189,   137,    26,
     192,   183,   132,   132,   132,   132,     2,    47,   303,   132,
     132,    76,   130,   132,    79,    20,    43,   133,   239,    79,
     248,   128,   129,   140,    20,    79,    18,   133,   131,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      79,     3,   322,   125,    35,    36,   125,   275,   276,    79,
     136,   133,   168,    28,   133,   127,   172,    53,    88,   252,
      45,    46,   168,   128,   129,   109,   172,    97,   128,   129,
      45,    46,    79,   286,   128,   129,   130,    79,   358,    79,
      25,    26,    27,    28,    29,    79,   280,   281,   309,   128,
     129,   130,   127,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   410,   233,   314,    47,   414,
      49,    50,    79,   320,    79,   398,   399,   400,   128,   129,
      15,    16,   248,    78,   128,   129,   252,    47,    79,    79,
      97,   168,   248,   125,   260,   172,   252,    88,    47,   429,
     485,   133,   487,   433,   260,    79,    97,   274,    79,   275,
     276,   136,    15,    16,   485,    47,   487,   502,   127,   275,
     276,   128,   129,   128,   129,   367,   113,   114,   513,   514,
     372,   502,   125,     3,   300,   210,   211,   212,   128,   129,
     133,     3,   513,   514,   300,   415,   416,   117,   390,   135,
     316,   140,    79,   135,   128,   129,   134,   128,   129,   135,
     316,    88,   135,   395,    79,   495,    21,    22,    23,    24,
      97,   248,   135,   405,   406,    21,    22,    23,    24,    79,
     503,   560,   561,   260,    37,    38,    39,   419,   224,   225,
     226,   227,   359,   215,   216,   217,   438,   138,   275,   276,
     213,   214,    80,   445,   446,    47,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   300,    47,   391,    20,   469,    19,   218,
     219,   220,   221,   222,   223,   391,    18,    17,     3,   316,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   137,   418,    72,    47,   421,   135,   499,   521,   134,
     134,    79,   418,    47,    47,   421,   132,   136,   510,   511,
     437,    28,    28,   132,   441,   517,   508,   133,   444,    79,
     132,    45,    46,   515,    79,   135,   528,   135,   444,    28,
     532,   379,   380,   381,   382,   133,   135,   137,    28,   133,
     133,   533,    79,    66,    56,   132,   538,    28,   137,   134,
     134,   132,   134,   429,   391,   135,    53,   134,   134,   132,
     134,   418,   306,   555,   556,   518,   295,   546,   494,   287,
     561,   371,   564,    14,    14,   567,   228,   384,   494,   229,
     383,   418,   509,   230,   421,   233,   385,   231,   386,    87,
      -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    35,    36,
      -1,    -1,   136,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,   494,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,    -1,    -1,    35,
      36,   138,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,   133,    35,    36,
      -1,    -1,   138,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,   134,    35,    36,
     137,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,   134,    35,    36,
     137,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,   134,    35,    36,
     137,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,    35,    36,    -1,
     137,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,   107,
      -1,   109,   110,    -1,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,   133,    35,    36,    -1,   137,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,
     109,   110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,   133,    35,    36,    -1,   137,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      35,    36,   132,   133,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,    35,    36,    -1,   133,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      35,    36,    -1,   133,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    47,    48,    49,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    70,    -1,
     105,    -1,    -1,    -1,    76,    -1,    -1,    79,   113,   114,
      -1,   116,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    -1,   128,   129,    97,    -1,    -1,   133,   101,
      47,    48,    49,   105,    -1,   107,    -1,    47,    48,    49,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,   128,   129,    -1,    76,
      70,   133,    79,    -1,    -1,    -1,    76,    -1,    -1,    79,
      87,    88,    -1,    -1,    -1,    -1,    93,    87,    88,    -1,
      97,    -1,    -1,    93,   101,    -1,    -1,    97,   105,    -1,
      -1,   101,    -1,    -1,    -1,   105,   113,   114,    -1,   116,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   133
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ParserImplementation::yystos_[] =
  {
         0,   140,   141,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    54,    60,    61,    64,
      68,    70,    74,    76,    79,    80,    82,    87,    88,    93,
      94,    97,    99,   101,   102,   105,   106,   107,   109,   110,
     112,   113,   114,   116,   121,   124,   128,   129,   133,   137,
     142,   143,   144,   152,   154,   158,   159,   160,   161,   162,
     163,   164,   167,   168,   176,   178,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   195,   196,   197,   204,   205,
     206,   207,   208,   214,   218,   219,   220,   223,   224,   225,
     226,   227,   228,   229,   231,   233,   235,   237,   239,   241,
     243,   245,   248,   253,    76,    79,   133,   223,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   248,   218,   219,
       3,   209,   210,   252,    79,   157,    79,   171,   173,   175,
     176,   178,   157,    60,   158,    60,    76,    79,   142,   173,
      47,   122,    79,   157,   135,    47,    79,    97,   175,   248,
     251,    47,   248,   133,   161,   171,    47,    47,   125,   133,
     145,   133,   145,    79,   146,   147,   156,   175,    47,   171,
     157,   177,   252,    79,    88,    97,   179,   217,    79,    88,
      97,   134,   158,   166,   215,   216,   217,   154,    47,    49,
      50,   221,    49,    50,   221,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    45,    46,   136,   247,
      37,    38,    39,    35,    36,    32,    33,    34,    25,    26,
      27,    28,    29,    78,    21,    22,    23,    24,    20,    19,
      18,    17,    15,    16,     3,   253,    79,   132,   221,     3,
      74,   138,   211,   212,     3,   138,   245,   253,    47,   136,
     180,   201,     3,   253,   201,   253,   109,    79,    79,   253,
     107,   223,   228,   230,   232,   234,   236,   238,   240,   242,
     244,   246,   249,   250,    47,    47,    47,   158,   248,   127,
     127,   127,   253,   248,   253,    57,    72,   198,   199,   253,
     248,   248,   245,   142,   151,   153,   155,   159,   151,   201,
       3,   117,   201,    79,   169,   170,   175,   253,   158,     3,
     130,    79,   130,   175,     3,   131,   135,   134,   158,   134,
       3,   137,   135,   123,   132,   150,   222,   245,   248,    79,
     248,    79,   245,   225,   225,   225,   226,   226,   227,   227,
     227,   228,   228,   228,   228,   228,   228,   229,   229,   229,
     229,   231,   233,   235,   237,   245,   239,   245,   252,    47,
     122,   138,    80,   213,   156,   245,   173,    47,    79,   172,
     174,   175,    28,   247,    25,    26,    27,    29,    78,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     137,   107,   223,   156,   156,   132,    79,    97,   165,   165,
     165,   132,    47,   161,   199,   132,   132,   134,   155,   134,
      79,   123,   148,   149,   175,   113,   114,   201,     3,   132,
     180,   252,    79,   217,    79,   175,   217,   245,    79,     3,
     132,   138,   138,   135,   138,   245,   223,    47,    47,   132,
     248,   136,   181,   202,     3,   137,    28,   202,   248,   223,
     246,   228,   228,   228,   228,   228,   230,   230,   230,   230,
     232,   234,   236,   238,   246,   240,   246,   251,   174,    28,
     132,   132,   158,    50,   253,   253,   253,   133,   191,    79,
     158,   158,   201,    79,   201,   133,   145,   133,   145,   170,
     158,    79,   130,   175,   135,   135,   150,   245,   245,    28,
     223,   248,   133,   132,   246,   174,   251,   248,   132,   135,
     137,    28,   248,   133,   133,    66,    79,    56,   192,   193,
     203,   132,   151,   151,    79,   175,   245,   248,    28,   132,
     151,   253,   137,   132,   158,   246,   251,   248,   132,   151,
     151,   158,   248,   193,    63,   134,   194,   161,   134,   134,
     132,   248,   134,   251,   158,   132,   132,   158,   134,   134,
     135,   135,   203,   132,   132,   158,   158,   166,   200,   200,
     134,   158
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
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,    41,   123,   125,    58,    61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ParserImplementation::yyr1_[] =
  {
         0,   139,   141,   140,   142,   142,   143,   143,   144,   144,
     144,   144,   144,   144,   144,   144,   145,   146,   146,   147,
     147,   147,   147,   148,   148,   149,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   161,   162,   163,   163,   164,   164,   164,   165,
     165,   165,   166,   166,   167,   167,   167,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   176,   177,   177,   177,   177,   178,
     179,   179,   179,   179,   179,   179,   180,   181,   182,   183,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   187,   188,   189,   190,   191,   191,   192,   192,   193,
     194,   195,   196,   197,   197,   197,   198,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   204,   204,
     204,   205,   206,   206,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   208,   209,   209,   210,   210,   211,   212,
     212,   213,   213,   214,   215,   215,   216,   216,   217,   217,
     217,   218,   218,   218,   218,   218,   219,   219,   220,   220,
     220,   220,   221,   221,   222,   222,   222,   222,   223,   223,
     223,   223,   224,   224,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   226,   226,   226,   226,   227,
     227,   227,   228,   228,   228,   228,   229,   229,   229,   229,
     229,   229,   229,   230,   230,   230,   230,   230,   230,   231,
     231,   231,   231,   231,   232,   232,   232,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   241,   241,   242,   242,   243,
     243,   244,   244,   245,   245,   246,   246,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   248,
     248,   249,   249,   250,   250,   251,   251,   252,   252,   253,
     253
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     8,     8,     8,     1,     7,     4,
       7,     4,     5,     5,     2,     2,     2,     1,     3,     2,
       2,     4,     4,     0,     1,     2,     2,     0,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     2,     5,     5,     5,     1,
       1,     3,     1,     2,     3,     3,     3,     5,     1,     3,
       2,     2,     1,     3,     1,     3,     2,     2,     2,     2,
       1,     1,     3,     3,     5,     2,     2,     4,     4,     3,
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
       1,     1,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     5,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     0,     1,     0,     1,     0,     1,     1,
       1
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
  "'.'", "BRACKET", "JS_ABSTRACT", "JS_BOOLEAN", "JS_BREAK", "JS_BYTE",
  "JS_CASE", "JS_CATCH", "JS_CHAR", "JS_CLASS", "JS_CONST", "JS_CONTINUE",
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
  "JS_PARAM_BEGIN", "JS_PARAM_END", "JS_DOBJECT_BEGIN", "JS_DOBJECT_END",
  "JS_FORMAL_PARAMETER_IDENT", "JS_LET", "JS_EACH", "JS_PARAMETER_REST",
  "JS_MODULE", "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "JS_FROM",
  "JS_DSTA_BEGIN", "JS_DSTO_BEGIN", "JS_DSTA_END", "JS_DSTO_END", "')'",
  "'{'", "'}'", "':'", "'='", "';'", "']'", "$accept", "program", "$@1",
  "function_declaration", "function_expression",
  "arrow_function_expression", "shorten_function_body",
  "formal_parameter_list_with_rest", "formal_parameter_list",
  "formal_parameter_rest__opt", "formal_parameter_rest",
  "arguments_spread", "function_body", "source_elements",
  "source_elements_for_function", "source_element",
  "source_element_for_function", "formal_parameter_list__opt",
  "identifier__opt", "statement", "statement_with_block",
  "statement_no_block", "block", "module_block", "export_statement",
  "import_statement", "import_expression", "statement_list",
  "variable_statement", "let_statement", "let_assignment_list",
  "let_assignment_expression", "variable_declaration_list",
  "variable_declaration_list_no_in", "variable_declaration",
  "variable_declaration_no_in", "destructuring_assignment_left_hand_side",
  "array_left_hand_side", "array_left_hand_side_list",
  "object_left_hand_side", "object_member_left_hand_side_list",
  "initialiser", "initialiser_no_in", "empty_statement",
  "expression_statement", "if_statement", "iteration_statement",
  "continue_statement", "break_statement", "return_statement",
  "with_statement", "switch_statement", "case_block", "case_clauses",
  "case_clause", "default_clause", "labelled_statement", "throw_statement",
  "try_statement", "catch", "finally", "statement_list__opt",
  "initialiser__opt", "initialiser_no_in__opt", "case_clauses__opt",
  "literal", "null_literal", "boolean_literal", "primary_expression",
  "array_literal", "element_list", "elision", "array_comprehensions",
  "array_comprehension_iteration", "array_comprehension_if__opt",
  "object_literal", "property_name_and_value_list__opt",
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
  "expression_no_in__opt", "expression__opt", "elision__opt", "terminator", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       140,     0,    -1,    -1,   141,   152,    -1,    76,    79,    47,
     156,   132,   133,   151,   134,    -1,    60,    79,    47,   156,
     132,   133,   151,   134,    -1,    76,   157,    47,   156,   132,
     133,   151,   134,    -1,   144,    -1,   116,   156,   117,   113,
     133,   151,   134,    -1,   113,   133,   151,   134,    -1,   116,
     156,   117,   114,   133,   151,   134,    -1,   114,   133,   151,
     134,    -1,   116,   156,   117,   113,   145,    -1,   116,   156,
     117,   114,   145,    -1,   114,   145,    -1,   113,   145,    -1,
     125,   245,    -1,   147,    -1,   147,     3,   148,    -1,    79,
     201,    -1,   175,   201,    -1,   147,     3,    79,   201,    -1,
     147,     3,   175,   201,    -1,    -1,   149,    -1,   123,    79,
      -1,   123,    79,    -1,    -1,   153,    -1,   154,    -1,   152,
     154,    -1,   155,    -1,   153,   155,    -1,   158,    -1,   142,
      -1,   159,    -1,   142,    -1,    -1,   146,    -1,    -1,    79,
      -1,   159,    -1,   162,    -1,   163,    -1,   161,    -1,   160,
      -1,   167,    -1,   168,    -1,   182,    -1,   183,    -1,   184,
      -1,   185,    -1,   186,    -1,   187,    -1,   188,    -1,   189,
      -1,   195,    -1,   190,    -1,   196,    -1,   197,    -1,   164,
      -1,   133,   134,    -1,   133,   166,   134,    -1,   124,   157,
     158,    -1,    68,   173,   253,    -1,    68,   142,    -1,    82,
      79,   127,   165,   253,    -1,    82,   175,   127,   165,   253,
      -1,    82,    97,   127,   165,   253,    -1,    97,    -1,    79,
      -1,   165,    50,    79,    -1,   158,    -1,   166,   158,    -1,
     107,   171,   253,    -1,    60,   171,   253,    -1,   121,   171,
     253,    -1,   121,    47,   169,   132,   158,    -1,   170,    -1,
     169,     3,   170,    -1,    79,   201,    -1,   175,   180,    -1,
     173,    -1,   171,     3,   173,    -1,   174,    -1,   172,     3,
     174,    -1,    79,   201,    -1,   175,   201,    -1,    79,   202,
      -1,   175,   202,    -1,   176,    -1,   178,    -1,   128,   252,
     130,    -1,   128,   177,   130,    -1,   128,   177,     3,   252,
     130,    -1,   252,    79,    -1,   252,   175,    -1,   177,     3,
     252,    79,    -1,   177,     3,   252,   175,    -1,   129,   179,
     131,    -1,    79,    -1,   217,   135,    79,    -1,   217,   135,
     175,    -1,   179,     3,   217,   135,    79,    -1,   179,     3,
      79,    -1,   179,     3,   217,   135,   175,    -1,   136,   245,
      -1,   136,   246,    -1,   253,    -1,   248,   253,    -1,    80,
      47,   248,   132,   158,    66,   158,    -1,    80,    47,   248,
     132,   158,    -1,    64,   158,   109,    47,   248,   132,   253,
      -1,   109,    47,   248,   132,   158,    -1,    74,    47,   250,
     137,   251,   137,   251,   132,   158,    -1,    74,    47,   107,
     172,   137,   251,   137,   251,   132,   158,    -1,    74,    47,
     223,    28,   248,   132,   158,    -1,    74,    47,   107,   174,
      28,   248,   132,   158,    -1,    74,   122,    47,   223,    28,
     248,   132,   158,    -1,    74,   122,    47,   107,   174,    28,
     248,   132,   158,    -1,    61,   157,   253,    -1,    54,   157,
     253,    -1,    94,   251,   253,    -1,   110,    47,   248,   132,
     158,    -1,    99,    47,   248,   132,   191,    -1,   133,   203,
     134,    -1,   133,   203,   194,   203,   134,    -1,   193,    -1,
     192,   193,    -1,    56,   248,   135,   200,    -1,    63,   135,
     200,    -1,    79,   135,   158,    -1,   102,   248,   253,    -1,
     106,   161,   198,    -1,   106,   161,   199,    -1,   106,   161,
     198,   199,    -1,    57,    47,    79,   132,   161,    -1,    72,
     161,    -1,    -1,   166,    -1,    -1,   180,    -1,    -1,   181,
      -1,    -1,   192,    -1,   205,    -1,   206,    -1,    88,    -1,
      97,    -1,    93,    -1,    87,    -1,   105,    -1,    70,    -1,
     101,    -1,    79,    -1,   204,    -1,   208,    -1,   214,    -1,
      47,   248,   132,    -1,    49,   252,   138,    -1,    49,   209,
     138,    -1,    49,   209,     3,   252,   138,    -1,    49,   209,
     211,   138,    -1,   252,   245,    -1,   209,     3,   252,   245,
      -1,     3,    -1,   210,     3,    -1,   212,   213,    -1,    74,
      47,   223,    28,   248,   132,    -1,    74,   122,    47,   223,
      28,   248,   132,    -1,    -1,    80,    47,   248,   132,    -1,
     133,   215,   134,    -1,    -1,   216,   137,    -1,   217,   135,
     245,    -1,   216,     3,   217,   135,   245,    -1,    79,    -1,
      97,    -1,    88,    -1,   207,    -1,   143,    -1,   218,    49,
     248,   138,    -1,   218,    50,    79,    -1,    48,   218,   221,
      -1,   218,    -1,    48,   219,    -1,   218,   221,    -1,   220,
     221,    -1,   220,    49,   248,   138,    -1,   220,    50,    79,
      -1,    47,   132,    -1,    47,   222,   132,    -1,   245,    -1,
     150,    -1,   222,     3,   245,    -1,   222,     3,   150,    -1,
     219,    -1,   220,    -1,   176,    -1,   178,    -1,   223,    -1,
     223,    46,    -1,   223,    45,    -1,   224,    -1,    42,   225,
      -1,    43,   225,    -1,    44,   225,    -1,    46,   225,    -1,
      45,   225,    -1,    35,   225,    -1,    36,   225,    -1,    41,
     225,    -1,    40,   225,    -1,   225,    -1,   226,    37,   225,
      -1,   226,    38,   225,    -1,   226,    39,   225,    -1,   226,
      -1,   227,    35,   226,    -1,   227,    36,   226,    -1,   227,
      -1,   228,    34,   227,    -1,   228,    33,   227,    -1,   228,
      32,   227,    -1,   228,    -1,   229,    26,   228,    -1,   229,
      25,   228,    -1,   229,    29,   228,    -1,   229,    78,   228,
      -1,   229,    27,   228,    -1,   229,    28,   228,    -1,   228,
      -1,   230,    26,   228,    -1,   230,    25,   228,    -1,   230,
      29,   228,    -1,   230,    78,   228,    -1,   230,    27,   228,
      -1,   229,    -1,   231,    23,   229,    -1,   231,    22,   229,
      -1,   231,    24,   229,    -1,   231,    21,   229,    -1,   230,
      -1,   232,    23,   230,    -1,   232,    22,   230,    -1,   232,
      24,   230,    -1,   232,    21,   230,    -1,   231,    -1,   233,
      20,   231,    -1,   232,    -1,   234,    20,   232,    -1,   233,
      -1,   235,    19,   233,    -1,   234,    -1,   236,    19,   234,
      -1,   235,    -1,   237,    18,   235,    -1,   236,    -1,   238,
      18,   236,    -1,   237,    -1,   239,    17,   237,    -1,   238,
      -1,   240,    17,   238,    -1,   239,    -1,   241,    16,   239,
      -1,   240,    -1,   242,    16,   240,    -1,   241,    -1,   241,
      15,   245,   135,   245,    -1,   242,    -1,   242,    15,   246,
     135,   246,    -1,   243,    -1,   223,   247,   245,    -1,   244,
      -1,   223,   247,   246,    -1,   136,    -1,    10,    -1,    12,
      -1,    11,    -1,    14,    -1,     5,    -1,     7,    -1,     6,
      -1,     4,    -1,    13,    -1,     9,    -1,     8,    -1,   245,
      -1,   248,     3,   245,    -1,   246,    -1,   249,     3,   246,
      -1,    -1,   249,    -1,    -1,   248,    -1,    -1,   210,    -1,
     137,    -1,   112,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,    16,    25,    34,    36,    44,
      49,    57,    62,    68,    74,    77,    80,    83,    85,    89,
      92,    95,   100,   105,   106,   108,   111,   114,   115,   117,
     119,   122,   124,   127,   129,   131,   133,   135,   136,   138,
     139,   141,   143,   145,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   171,   173,   175,   177,
     179,   181,   184,   188,   192,   196,   199,   205,   211,   217,
     219,   221,   225,   227,   230,   234,   238,   242,   248,   250,
     254,   257,   260,   262,   266,   268,   272,   275,   278,   281,
     284,   286,   288,   292,   296,   302,   305,   308,   313,   318,
     322,   324,   328,   332,   338,   342,   348,   351,   354,   356,
     359,   367,   373,   381,   387,   397,   408,   416,   425,   434,
     444,   448,   452,   456,   462,   468,   472,   478,   480,   483,
     488,   492,   496,   500,   504,   508,   513,   519,   522,   523,
     525,   526,   528,   529,   531,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   554,   556,   558,   560,
     564,   568,   572,   578,   583,   586,   591,   593,   596,   599,
     606,   614,   615,   620,   624,   625,   628,   632,   638,   640,
     642,   644,   646,   648,   653,   657,   661,   663,   666,   669,
     672,   677,   681,   684,   688,   690,   692,   696,   700,   702,
     704,   706,   708,   710,   713,   716,   718,   721,   724,   727,
     730,   733,   736,   739,   742,   745,   747,   751,   755,   759,
     761,   765,   769,   771,   775,   779,   783,   785,   789,   793,
     797,   801,   805,   809,   811,   815,   819,   823,   827,   831,
     833,   837,   841,   845,   849,   851,   855,   859,   863,   867,
     869,   873,   875,   879,   881,   885,   887,   891,   893,   897,
     899,   903,   905,   909,   911,   915,   917,   921,   923,   927,
     929,   935,   937,   943,   945,   949,   951,   955,   957,   959,
     961,   963,   965,   967,   969,   971,   973,   975,   977,   979,
     981,   985,   987,   991,   992,   994,   995,   997,   998,  1000,
    1002
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   341,   341,   341,   355,   372,   388,   398,   411,   420,
     429,   439,   449,   459,   470,   481,   495,   506,   507,   525,
     541,   549,   559,   569,   570,   579,   596,   606,   607,   611,
     619,   629,   637,   647,   648,   658,   659,   669,   670,   677,
     678,   687,   688,   693,   701,   706,   710,   715,   719,   724,
     729,   734,   739,   744,   749,   754,   759,   764,   769,   774,
     779,   786,   793,   804,   817,   824,   835,   852,   867,   887,
     895,   903,   913,   921,   932,   940,   948,   959,   969,   975,
     982,   990,  1001,  1009,  1019,  1025,  1033,  1041,  1051,  1059,
    1070,  1074,  1081,  1091,  1098,  1111,  1123,  1133,  1143,  1154,
    1165,  1175,  1187,  1197,  1207,  1215,  1226,  1230,  1234,  1238,
    1248,  1257,  1269,  1277,  1285,  1297,  1309,  1320,  1332,  1343,
    1357,  1367,  1377,  1387,  1398,  1409,  1413,  1422,  1428,  1436,
    1447,  1458,  1471,  1481,  1490,  1499,  1511,  1522,  1530,  1531,
    1535,  1536,  1540,  1541,  1545,  1546,  1550,  1551,  1552,  1559,
    1566,  1576,  1586,  1593,  1603,  1610,  1617,  1618,  1619,  1620,
    1628,  1638,  1645,  1655,  1666,  1676,  1687,  1688,  1693,  1701,
    1708,  1718,  1719,  1728,  1743,  1746,  1753,  1762,  1772,  1779,
    1786,  1796,  1800,  1804,  1817,  1832,  1848,  1849,  1859,  1872,
    1885,  1898,  1916,  1917,  1921,  1927,  1933,  1938,  1946,  1947,
    1948,  1949,  1953,  1957,  1964,  1974,  1975,  1982,  1989,  1996,
    2003,  2010,  2017,  2024,  2031,  2041,  2042,  2046,  2050,  2057,
    2058,  2062,  2069,  2070,  2074,  2078,  2085,  2086,  2090,  2094,
    2098,  2102,  2106,  2113,  2114,  2118,  2122,  2126,  2130,  2137,
    2138,  2142,  2146,  2150,  2157,  2158,  2162,  2166,  2170,  2177,
    2178,  2185,  2186,  2193,  2194,  2201,  2202,  2209,  2210,  2217,
    2218,  2225,  2226,  2233,  2234,  2241,  2242,  2249,  2250,  2257,
    2258,  2267,  2268,  2277,  2281,  2291,  2295,  2306,  2307,  2308,
    2309,  2310,  2311,  2312,  2313,  2314,  2315,  2316,  2317,  2321,
    2328,  2336,  2343,  2351,  2352,  2356,  2357,  2361,  2362,  2366,
    2367
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
      47,   132,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   135,   137,
      26,   136,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   138,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   133,    18,   134,    41,     2,     2,     2,
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
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 1873;
  const int ParserImplementation::yynnts_ = 115;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 139;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 369;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 5008 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2370 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


