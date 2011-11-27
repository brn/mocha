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
#line 339 "grammar/grammar.yy"
    {int yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 340 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 354 "grammar/grammar.yy"
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
#line 371 "grammar/grammar.yy"
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
#line 387 "grammar/grammar.yy"
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
#line 396 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 410 "grammar/grammar.yy"
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
#line 419 "grammar/grammar.yy"
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
#line 428 "grammar/grammar.yy"
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
#line 438 "grammar/grammar.yy"
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
#line 448 "grammar/grammar.yy"
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
#line 458 "grammar/grammar.yy"
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
#line 469 "grammar/grammar.yy"
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
#line 480 "grammar/grammar.yy"
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
#line 494 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 514 "grammar/grammar.yy"
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
#line 530 "grammar/grammar.yy"
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
#line 541 "grammar/grammar.yy"
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
#line 551 "grammar/grammar.yy"
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
#line 561 "grammar/grammar.yy"
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
#line 576 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 593 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 602 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 603 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 608 "grammar/grammar.yy"
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
#line 616 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 626 "grammar/grammar.yy"
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
#line 634 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 643 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 645 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 654 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 656 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 665 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 667 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 673 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 675 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 683 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 685 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 690 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 698 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 702 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 707 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 712 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 716 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 721 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 726 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 731 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 736 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 741 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 746 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 751 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 756 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 761 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 766 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 771 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 776 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 783 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 790 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 801 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 814 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(3) - (2)].value_node) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 821 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].function) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 832 "grammar/grammar.yy"
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

  case 64:

/* Line 690 of lalr1.cc  */
#line 849 "grammar/grammar.yy"
    {
  ValueNode* node = (yysemantic_stack_[(5) - (4)].ast)->FirstChild()->CastToValue();
  int type;
  if ( node && node->ValueType() == ValueNode::kString ) {
    type = ImportStmt::kFile;
  } else {
    type = ImportStmt::kModule;
  }
  ImportStmt* stmt = ManagedHandle::Retain( new ImportStmt( ImportStmt::kDst , type ) );
  stmt->Exp( (yysemantic_stack_[(5) - (2)].ast) );
  stmt->From( (yysemantic_stack_[(5) - (4)].ast) );
  stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
  (yyval.ast) = stmt;
}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 864 "grammar/grammar.yy"
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

  case 66:

/* Line 690 of lalr1.cc  */
#line 884 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 892 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 900 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 910 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 918 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 929 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 937 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 945 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 956 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 966 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 972 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 979 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 987 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].ast) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 998 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1006 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 1016 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1022 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1030 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1038 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1056 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].ast) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1067 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1078 "grammar/grammar.yy"
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

  case 90:

/* Line 690 of lalr1.cc  */
#line 1088 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1095 "grammar/grammar.yy"
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

  case 92:

/* Line 690 of lalr1.cc  */
#line 1108 "grammar/grammar.yy"
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

  case 93:

/* Line 690 of lalr1.cc  */
#line 1120 "grammar/grammar.yy"
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

  case 94:

/* Line 690 of lalr1.cc  */
#line 1130 "grammar/grammar.yy"
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

  case 95:

/* Line 690 of lalr1.cc  */
#line 1140 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1151 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1162 "grammar/grammar.yy"
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

  case 98:

/* Line 690 of lalr1.cc  */
#line 1172 "grammar/grammar.yy"
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

  case 99:

/* Line 690 of lalr1.cc  */
#line 1184 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1194 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1204 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1212 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1222 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1226 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1230 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1235 "grammar/grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(2) - (1)].expression)->Line() );
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1245 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1254 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1266 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1274 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1282 "grammar/grammar.yy"
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

  case 112:

/* Line 690 of lalr1.cc  */
#line 1294 "grammar/grammar.yy"
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

  case 113:

/* Line 690 of lalr1.cc  */
#line 1306 "grammar/grammar.yy"
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

  case 114:

/* Line 690 of lalr1.cc  */
#line 1317 "grammar/grammar.yy"
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

  case 115:

/* Line 690 of lalr1.cc  */
#line 1329 "grammar/grammar.yy"
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

  case 116:

/* Line 690 of lalr1.cc  */
#line 1340 "grammar/grammar.yy"
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

  case 117:

/* Line 690 of lalr1.cc  */
#line 1354 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1364 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1374 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1384 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1395 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1406 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1410 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1419 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1425 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1433 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1444 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar/grammar.yy"
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

  case 129:

/* Line 690 of lalr1.cc  */
#line 1468 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1478 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1487 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1496 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1508 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1519 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1527 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1531 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1532 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1536 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1537 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1541 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1542 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1546 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1547 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1556 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1573 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1583 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1590 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1600 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1607 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1613 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1614 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1615 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1625 "grammar/grammar.yy"
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

  case 158:

/* Line 690 of lalr1.cc  */
#line 1635 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar/grammar.yy"
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

  case 160:

/* Line 690 of lalr1.cc  */
#line 1652 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar/grammar.yy"
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

  case 162:

/* Line 690 of lalr1.cc  */
#line 1673 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1690 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1698 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1705 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1716 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1725 "grammar/grammar.yy"
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

  case 171:

/* Line 690 of lalr1.cc  */
#line 1739 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1750 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1759 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1769 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1776 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1783 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1793 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1797 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1801 "grammar/grammar.yy"
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
#line 1814 "grammar/grammar.yy"
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
#line 1829 "grammar/grammar.yy"
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

  case 183:

/* Line 690 of lalr1.cc  */
#line 1844 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1846 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1856 "grammar/grammar.yy"
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

  case 186:

/* Line 690 of lalr1.cc  */
#line 1869 "grammar/grammar.yy"
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

  case 187:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar/grammar.yy"
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

  case 188:

/* Line 690 of lalr1.cc  */
#line 1895 "grammar/grammar.yy"
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

  case 189:

/* Line 690 of lalr1.cc  */
#line 1912 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1913 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1918 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1930 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1935 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1942 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1943 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1944 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1945 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1950 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1961 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1970 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1972 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1979 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1993 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2000 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2007 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2021 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2028 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2037 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2039 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2043 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2047 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2053 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2055 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2059 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2065 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2067 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2071 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2075 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2081 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2083 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2087 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2091 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2095 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2099 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2103 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2109 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2111 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2115 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2119 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2123 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2127 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2133 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2135 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2139 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2143 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2147 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2153 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2155 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2159 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2163 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2167 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2173 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2175 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2181 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2183 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2189 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2191 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2197 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2199 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2205 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2207 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2213 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2215 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2221 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2223 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2229 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2231 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2237 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2239 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2245 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2247 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2253 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2255 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2263 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2265 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2274 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2278 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2288 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2292 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2302 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2303 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2304 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2305 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2306 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2307 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2309 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2310 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2311 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2312 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2313 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2318 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2325 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2340 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2347 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2348 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2352 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2353 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2357 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2358 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2362 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2363 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 3642 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -365;
  const short int
  ParserImplementation::yypact_[] =
  {
      -365,    16,  1107,  -365,  1689,  1689,  1689,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1784,    53,    13,   104,    13,  1206,
     135,  -365,    -1,    30,   -39,    65,   171,  -365,  -365,  -365,
    1689,  -365,    76,  -365,  1689,  -365,   -47,   190,    78,   123,
    -365,   -23,   -11,   236,    36,    13,    53,   111,   807,  -365,
    -365,  -365,  -365,  1107,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,   293,  -365,   311,   594,  -365,  -365,
     356,    -3,   385,   220,   281,    79,   157,   191,   195,   119,
    -365,  -365,    20,  -365,    13,  -365,   308,   197,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,     9,   293,  -365,
    -365,    21,   226,   608,  -365,   -60,   -32,    24,  -365,   102,
    -365,  -365,   -60,   190,   148,   136,   181,   102,  -365,   -60,
    1499,   215,   218,   223,  1206,  1689,   170,   182,   202,   328,
     -60,  1689,    20,   907,    48,    24,  1689,  1689,  1689,  1305,
    -365,  1305,  -365,   102,     7,   102,   247,    24,  1206,    47,
       1,   198,  -365,  -365,     6,   204,   -39,   209,   211,  -365,
    -365,  1007,   229,    25,   244,  -365,  1404,  1689,   292,  -365,
    1689,   318,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,
    1689,  1689,  1689,  -365,  -365,  -365,  -365,    53,    66,  -365,
     266,   326,  -365,  -365,  -365,  -365,   236,  1689,  -365,  -365,
     190,  -365,  -365,  -365,   367,   376,   218,  -365,   255,   213,
     385,   175,   345,   410,   414,   416,   435,   297,  -365,  -365,
     459,   337,  1722,   236,   236,  -365,    35,     0,     0,     0,
    -365,    37,  -365,   428,   -47,   391,  -365,  -365,    39,    40,
    -365,  -365,   342,  1305,  -365,  -365,   343,  -365,   188,   122,
    -365,   102,    41,  -365,   102,  -365,  -365,    53,  -365,  -365,
    -365,  -365,   319,  -365,   257,  -365,  -365,  -365,   308,  -365,
    1689,   399,  -365,  -365,    42,  -365,    17,  -365,    22,  -365,
    -365,  -365,  -365,  -365,   356,   356,    -3,    -3,    -3,   385,
     385,   385,   385,   385,   385,   220,   220,   220,   220,   281,
      79,   157,   191,   344,   195,  -365,   708,  1777,   434,  -365,
     437,  -365,   479,   355,  -365,  -365,  1689,   352,    26,   461,
     352,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,  1689,
     255,   463,   360,   362,  1206,  -365,  -365,    56,    56,    56,
     366,   421,  -365,  -365,  1206,  1206,  -365,  -365,  -365,   102,
     422,  -365,   102,    -6,   106,  -365,   247,  1206,  -365,   126,
     198,   370,  -365,  -365,   372,  -365,  -365,  1594,  -365,  -365,
    -365,  1689,  -365,  -365,   467,  1777,  1689,   375,    50,  1689,
    -365,  -365,   255,  1689,  1689,  -365,    52,   594,  -365,   385,
     385,   385,   385,   385,   175,   175,   175,   175,   345,   410,
     414,   416,   374,   435,  -365,   373,   484,  1689,   380,   382,
     451,   440,  -365,  -365,  -365,   464,  -365,   389,  -365,  -365,
    -365,  -365,  -365,  1305,  -365,  1305,  -365,  -365,  -365,  -365,
    -365,  -365,   262,  1689,  -365,  -365,  -365,  1689,   494,    54,
    1305,   -60,  -365,  -365,   386,    55,  1206,  1689,  1689,  1689,
      57,  1305,  1305,  1206,  -365,  1689,   464,  -365,   -49,   -47,
     390,   392,  -365,  -365,  -365,    59,  1689,  -365,   393,  -365,
    1689,  1206,  -365,  -365,   396,    60,  1206,   397,   398,  -365,
       5,  -365,   395,  -365,   464,  -365,  -365,  -365,  -365,    62,
    -365,   401,  -365,  1206,  1206,  -365,  -365,  -365,  1206,  1206,
     402,  -365,  1206,  -365,  -365,  1206,  -365,  -365,  -365,  -365
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,    36,     0,    36,     0,
       0,   150,     0,    36,   152,     0,     0,   148,   145,   147,
     292,   146,     0,   151,     0,   149,     0,     0,     0,     0,
     297,     0,     0,     0,     0,    36,   294,     0,     0,   296,
      31,   179,     7,     3,    26,    30,    38,    42,    41,    39,
      40,    57,    43,    44,   197,   198,    45,    46,    47,    48,
      49,    50,    51,    52,    54,    53,    55,    56,   153,   143,
     144,   178,   154,   155,   183,   195,   196,   199,   202,   212,
     216,   219,   223,   236,   246,   250,   254,   258,   262,   266,
     270,   286,     0,   105,    36,   152,   171,   199,   208,   209,
     211,   210,   203,   204,   205,   207,   206,     0,   183,   184,
     163,     0,   295,     0,    37,     0,   137,     0,    79,   137,
      87,    88,     0,     0,     0,     0,     0,   137,    62,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      15,    24,    14,   137,     0,   137,     0,     0,     0,     0,
       0,    97,   177,   176,     0,     0,   152,   145,   146,    58,
      69,     0,     0,     0,     0,    27,     0,     0,     0,   185,
       0,     0,   186,   282,   279,   281,   280,   285,   284,   275,
     277,   276,   283,   278,   201,   200,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   175,   156,   182,   294,     0,   158,
       0,   168,   164,   157,   161,   118,    34,     0,   138,    83,
       0,    72,    84,   117,     0,     0,     0,    61,     0,   199,
     230,   241,   248,   252,   256,   260,   264,   268,   272,   288,
     291,     0,     0,    34,    34,   128,     0,     0,     0,     0,
     119,     0,   129,     0,     0,   130,   131,    71,     0,     0,
      16,    33,     0,    25,    28,    32,     0,    17,     0,     0,
      18,   137,     0,    75,     0,    73,    60,   294,    90,    92,
      89,    93,     0,    96,     0,    59,    70,   170,     0,   172,
       0,     0,   189,   192,     0,   191,     0,   181,     0,   188,
     271,   213,   214,   215,   217,   218,   222,   221,   220,   225,
     224,   228,   229,   226,   227,   240,   238,   237,   239,   247,
     251,   255,   259,     0,   263,   287,     0,     0,     0,   160,
       0,   165,    35,     0,   103,    80,     0,   139,     0,    81,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,    67,    66,     0,     0,     0,
       0,     0,   134,   132,     0,     0,     9,    29,    11,   137,
       0,    21,   137,     0,     0,    77,     0,     0,    78,     0,
     101,     0,    98,    99,     0,   173,    23,     0,   190,   180,
     187,     0,   159,   162,     0,     0,     0,     0,     0,     0,
     140,    85,     0,   292,     0,    86,     0,   199,   273,   232,
     231,   235,   233,   234,   245,   243,   242,   244,   249,   253,
     257,   261,     0,   265,   289,     0,     0,     0,     0,     0,
     108,     0,    63,    65,    64,   141,   121,     0,   110,   120,
      19,    22,    20,    24,    12,    24,    13,    76,    74,    94,
      91,    95,     0,     0,   194,   193,   267,     0,     0,     0,
      24,     0,   104,    82,     0,     0,     0,     0,   292,     0,
       0,    24,    24,     0,    68,     0,   142,   124,     0,     0,
       0,     0,   100,   102,   174,     0,     0,   169,     0,   109,
     292,     0,   113,   269,     0,     0,     0,     0,     0,   107,
       0,   125,     0,   122,   141,   133,     8,    10,   166,     0,
       5,     0,   114,     0,     0,   115,     4,     6,   135,   135,
       0,   167,     0,   111,   116,   136,   126,   127,   123,   112
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -365,  -365,  -365,   208,  -365,  -365,   -40,   482,  -365,   108,
    -130,  -365,  -365,   485,   246,   138,    71,    -2,  -155,  -365,
     -33,  -365,  -365,  -365,   121,  -150,  -365,  -365,  -365,   124,
     169,  -365,   -13,  -364,   155,    64,  -365,    74,  -365,   233,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,    27,  -365,  -365,  -365,  -365,  -365,   256,   -15,
    -116,   172,     2,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,   -17,   533,   534,  -365,
     -20,  -365,    63,  -365,   142,   210,   212,   240,   243,    92,
     323,   168,   327,   174,   325,   177,   329,   179,   324,   178,
    -365,  -365,  -365,  -365,  -104,  -351,   472,   -12,  -365,  -365,
    -350,   -41,   -91
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,   291,    51,    52,   160,   362,   411,   323,
     292,    53,   293,    54,   294,   363,   143,   180,    56,    57,
      58,    59,    60,    61,   397,   181,    62,    63,   302,   303,
     127,   368,   128,   369,   129,    64,   169,    65,   174,   248,
     440,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     476,   516,   517,   544,    75,    76,    77,   285,   286,   566,
     249,   441,   518,    78,    79,    80,    81,    82,   121,   122,
     240,   241,   361,    83,   182,   183,   184,    84,    85,    86,
     189,   324,    87,    88,    89,    90,    91,    92,    93,   261,
      94,   262,    95,   263,    96,   264,    97,   265,    98,   266,
      99,   267,   100,   268,   101,   269,   372,   102,   270,   271,
     150,   123,   103
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -178;
  const short int
  ParserImplementation::yytable_[] =
  {
        55,   117,   162,   154,   295,   170,   295,   139,   232,   312,
     298,   233,   232,   252,   542,   246,     3,   134,   149,   244,
     232,   448,   152,   232,   237,   232,   466,   250,   318,   442,
     175,   296,   211,   212,   245,   462,   251,   464,   232,   465,
     232,   253,   232,   232,   416,   427,   140,   297,   257,   300,
     307,    55,    40,   232,   290,   232,   120,   232,   232,   280,
     232,   282,   232,   232,   287,   232,   192,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   305,    49,   503,   395,
     309,   130,   325,   166,   130,   543,   153,   125,   502,   132,
     130,   131,   124,   504,   131,   238,   144,   396,   236,   226,
     131,   130,   158,   330,   247,   283,   471,   130,   130,   142,
     159,   131,   145,   357,   158,   137,   168,   131,   131,   158,
     284,   141,   161,   151,   299,   156,   353,   483,   355,    46,
      47,   310,    40,   276,   230,   231,    40,   313,   295,   281,
     558,   235,   275,   364,   288,   289,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   429,   533,    49,   534,   239,
     430,    49,   319,   443,    46,    47,   306,   394,    40,   400,
     157,   404,   405,   417,   428,   326,   227,   308,   328,   316,
     551,   148,   501,   126,   506,   415,   527,   531,   358,   536,
     171,   548,   554,    49,   561,   135,   356,   130,   165,   172,
     373,   374,   375,   259,   376,   489,   155,   131,   173,   228,
      50,   136,   229,   167,   137,   255,   425,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   138,   242,
     130,   158,    46,    47,   130,   413,   414,   365,   247,   485,
     131,   371,   204,   205,   131,   216,   217,   218,   219,   220,
     146,   402,   433,   377,    46,    47,   490,   254,   204,   205,
     256,    50,   272,    46,    47,   273,   419,   409,   147,   137,
     274,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   480,   107,   421,   482,   277,   221,    46,
      47,   424,   222,   223,   224,   225,   472,   473,   474,   278,
     130,   410,   386,   387,   130,   163,    46,    47,    46,    47,
     131,   304,   130,   495,   131,   311,   301,   496,   295,   279,
     295,   232,   131,  -175,   367,   391,   422,   130,   130,   314,
     186,   522,   187,   188,  -177,   295,  -176,   131,   131,   206,
     331,   332,   333,   520,   438,   521,   295,   295,   186,   446,
     190,   191,   130,   317,    46,    47,   378,   379,   380,   381,
     528,   327,   131,   484,   486,    46,    47,   149,   130,   320,
     260,   537,   538,    46,    47,    46,    47,   234,   131,   524,
      46,    47,   470,   208,   209,   210,   172,   329,   420,   398,
     399,   165,   478,   479,   359,   173,   360,   172,   565,   565,
     529,   392,   393,   370,   366,   488,   173,   213,   214,   215,
     434,   334,   335,   246,   499,   336,   337,   338,   165,   165,
     382,   149,   505,   383,   384,   447,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   447,
     107,   447,   385,   412,   130,   510,   339,   340,   341,   342,
     343,   344,   388,   284,   131,   345,   346,   347,   348,   423,
     454,   455,   456,   457,   389,   401,   406,   408,   426,   431,
     130,   435,   298,   130,   436,   525,   545,   437,   439,   444,
     131,   467,   468,   131,   469,   497,   149,   535,   498,   475,
     477,   481,   447,   540,   532,   492,   130,   493,   500,   507,
     508,   539,   509,   511,   549,   512,   131,   513,   149,   514,
     515,   519,   526,   530,   546,   164,   547,   550,   553,   552,
     559,   556,   557,   562,   555,   494,   568,   418,   185,   407,
     487,   403,   445,   541,   567,   370,   560,   118,   119,   349,
     458,   563,   564,   351,   350,   354,   130,   459,   352,   207,
     569,   460,     0,   316,   461,   463,   131,     0,     0,     0,
     447,   304,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,   260,   449,   450,   451,   452,   453,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     205,     0,     0,     4,     5,     0,     0,   523,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,   260,
       0,     0,     0,     0,   104,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
     206,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,   106,     0,     4,     5,     0,   243,   260,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   104,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,   106,     4,     5,     0,     0,   432,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   133,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   104,     0,     0,   176,    25,     0,    26,
       0,     0,     0,     0,    27,   177,     0,     0,     0,     0,
      29,    30,     0,     0,   178,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,    47,     0,     0,     0,
      48,   179,     4,     5,    49,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   133,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   104,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,    47,     0,     0,     0,
      48,   179,     4,     5,    49,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   133,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   104,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,    47,     0,     0,     0,
      48,   315,     4,     5,    49,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,    47,     0,     0,     0,
      48,     4,     5,     0,    49,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   133,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,   104,     0,     0,    24,    25,     0,    26,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    33,    34,     0,
       0,    35,    36,    37,     0,    38,    39,     0,    40,    41,
      42,     0,    43,     0,     0,     0,     0,    44,     0,     0,
      45,     0,     0,     0,    46,    47,     0,     0,     0,    48,
       4,     5,     0,    49,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
       0,    23,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,    46,    47,     0,     0,     0,    48,     4,
       5,     0,    49,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     104,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,    46,    47,     4,     5,   322,   106,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,   104,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,   258,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     4,
       5,     0,   106,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     104,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,    46,    47,     4,     5,     0,   106,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,   104,     0,     0,   105,    13,
      14,    15,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,     0,     0,     0,    31,     0,     0,     0,
      33,     0,    21,     0,    35,     0,     0,     0,   104,     0,
       0,   105,    41,    42,     0,    43,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,     0,    46,    47,    31,
       0,     0,   106,    33,    13,    14,    15,    35,     0,   390,
       0,    13,    14,    15,     0,    41,    42,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
      46,    47,     0,   104,    21,   106,   105,     0,     0,     0,
     104,     0,     0,   105,    27,    28,     0,     0,     0,     0,
      29,    27,    28,     0,    31,     0,     0,    29,    33,     0,
       0,    31,    35,     0,     0,    33,     0,     0,     0,    35,
      41,    42,     0,    43,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,    46,    47,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   106
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,    13,    42,    36,   159,    46,   161,    20,     3,     3,
       3,   102,     3,   129,    63,    47,     0,    19,    30,   123,
       3,   372,    34,     3,     3,     3,   390,     3,     3,     3,
      47,   161,    35,    36,   125,   386,   127,   388,     3,   389,
       3,   132,     3,     3,     3,     3,    47,   163,   139,   165,
       3,    53,   112,     3,   158,     3,     3,     3,     3,   150,
       3,   152,     3,     3,   155,     3,    86,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   167,   137,   442,    79,
      79,    17,   186,    47,    20,   134,   133,    16,   439,    18,
      26,    17,    79,   443,    20,    74,   135,    97,   118,    20,
      26,    37,   125,   207,   136,    57,    50,    43,    44,    79,
     133,    37,    47,    47,   125,    79,    45,    43,    44,   125,
      72,   122,   133,    47,   117,    47,   230,   133,   232,   128,
     129,   130,   112,   145,    15,    16,   112,   131,   293,   151,
     135,   132,   144,   247,   156,   157,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   138,   507,   137,   508,   138,
     138,   137,   137,   137,   128,   129,   168,   132,   112,   132,
      47,   132,   132,   132,   132,   187,    19,   130,   190,   181,
     530,    26,   132,    79,   132,   301,   132,   132,   122,   132,
      79,   132,   132,   137,   132,    60,   237,   133,    43,    88,
      25,    26,    27,   140,    29,    79,    37,   133,    97,    18,
       2,    76,    17,    44,    79,    79,   320,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    20,     3,
     166,   125,   128,   129,   170,   113,   114,   250,   136,   133,
     166,    28,    45,    46,   170,    25,    26,    27,    28,    29,
      79,   284,   356,    78,   128,   129,   130,   109,    45,    46,
      79,    53,    47,   128,   129,    47,   307,    79,    97,    79,
      47,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   409,   231,   312,   412,   127,    78,   128,
     129,   318,    21,    22,    23,    24,   397,   398,   399,   127,
     246,   123,    15,    16,   250,    79,   128,   129,   128,   129,
     246,   166,   258,   427,   250,   170,    79,   431,   483,   127,
     485,     3,   258,   135,    79,   272,    79,   273,   274,   135,
      47,    79,    49,    50,   135,   500,   135,   273,   274,   136,
     208,   209,   210,   483,   366,   485,   511,   512,    47,   371,
      49,    50,   298,   134,   128,   129,    21,    22,    23,    24,
     500,    79,   298,   413,   414,   128,   129,   389,   314,   135,
     140,   511,   512,   128,   129,   128,   129,    79,   314,   493,
     128,   129,   394,    37,    38,    39,    88,    79,    79,   278,
     279,   246,   404,   405,   138,    97,    80,    88,   558,   559,
     501,   273,   274,   258,    47,   417,    97,    32,    33,    34,
     357,   211,   212,    47,   436,   213,   214,   215,   273,   274,
      20,   443,   444,    19,    18,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,    17,   298,   390,   467,   216,   217,   218,   219,
     220,   221,     3,    72,   390,   222,   223,   224,   225,   314,
     378,   379,   380,   381,   137,    47,   134,   134,    79,   135,
     416,    47,     3,   419,    47,   497,   519,   132,   136,    28,
     416,    28,   132,   419,   132,    28,   508,   509,   435,   133,
      79,    79,   439,   515,   506,   135,   442,   135,   133,   135,
     137,   513,    28,   133,   526,   133,   442,    66,   530,    79,
      56,   132,    28,   137,   134,    43,   134,   134,   132,   531,
     135,   134,   134,   132,   536,   427,   134,   304,    53,   293,
     416,   285,   370,   516,   559,   390,   544,    14,    14,   226,
     382,   553,   554,   228,   227,   231,   492,   383,   229,    87,
     562,   384,    -1,   565,   385,   387,   492,    -1,    -1,    -1,
     507,   416,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    35,    36,    -1,    -1,   492,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,   439,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    -1,    35,    36,    -1,   138,   507,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    35,    36,    -1,    -1,   138,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,   134,    35,    36,   137,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,   134,    35,    36,   137,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,   134,    35,    36,   137,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,    35,    36,    -1,   137,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,
      -1,   105,   106,   107,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
     124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,   133,
      35,    36,    -1,   137,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,   133,    35,
      36,    -1,   137,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,    35,    36,   132,   133,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    35,
      36,    -1,   133,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,    35,    36,    -1,   133,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    47,
      48,    49,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    70,    -1,   105,    -1,    -1,    -1,    76,    -1,
      -1,    79,   113,   114,    -1,   116,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    -1,   128,   129,    97,
      -1,    -1,   133,   101,    47,    48,    49,   105,    -1,   107,
      -1,    47,    48,    49,    -1,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
     128,   129,    -1,    76,    70,   133,    79,    -1,    -1,    -1,
      76,    -1,    -1,    79,    87,    88,    -1,    -1,    -1,    -1,
      93,    87,    88,    -1,    97,    -1,    -1,    93,   101,    -1,
      -1,    97,   105,    -1,    -1,   101,    -1,    -1,    -1,   105,
     113,   114,    -1,   116,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   133
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
     142,   143,   144,   150,   152,   156,   157,   158,   159,   160,
     161,   162,   165,   166,   174,   176,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   193,   194,   195,   202,   203,
     204,   205,   206,   212,   216,   217,   218,   221,   222,   223,
     224,   225,   226,   227,   229,   231,   233,   235,   237,   239,
     241,   243,   246,   251,    76,    79,   133,   221,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   246,   216,   217,
       3,   207,   208,   250,    79,   155,    79,   169,   171,   173,
     174,   176,   155,    60,   156,    60,    76,    79,   142,   171,
      47,   122,    79,   155,   135,    47,    79,    97,   173,   246,
     249,    47,   246,   133,   159,   169,    47,    47,   125,   133,
     145,   133,   145,    79,   146,   173,    47,   169,   155,   175,
     250,    79,    88,    97,   177,   215,    79,    88,    97,   134,
     156,   164,   213,   214,   215,   152,    47,    49,    50,   219,
      49,    50,   219,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    45,    46,   136,   245,    37,    38,
      39,    35,    36,    32,    33,    34,    25,    26,    27,    28,
      29,    78,    21,    22,    23,    24,    20,    19,    18,    17,
      15,    16,     3,   251,    79,   132,   219,     3,    74,   138,
     209,   210,     3,   138,   243,   251,    47,   136,   178,   199,
       3,   251,   199,   251,   109,    79,    79,   251,   107,   221,
     226,   228,   230,   232,   234,   236,   238,   240,   242,   244,
     247,   248,    47,    47,    47,   156,   246,   127,   127,   127,
     251,   246,   251,    57,    72,   196,   197,   251,   246,   246,
     243,   142,   149,   151,   153,   157,   149,   199,     3,   117,
     199,    79,   167,   168,   173,   251,   156,     3,   130,    79,
     130,   173,     3,   131,   135,   134,   156,   134,     3,   137,
     135,   123,   132,   148,   220,   243,   246,    79,   246,    79,
     243,   223,   223,   223,   224,   224,   225,   225,   225,   226,
     226,   226,   226,   226,   226,   227,   227,   227,   227,   229,
     231,   233,   235,   243,   237,   243,   250,    47,   122,   138,
      80,   211,   146,   154,   243,   171,    47,    79,   170,   172,
     173,    28,   245,    25,    26,    27,    29,    78,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   137,
     107,   221,   154,   154,   132,    79,    97,   163,   163,   163,
     132,    47,   159,   197,   132,   132,   134,   153,   134,    79,
     123,   147,   173,   113,   114,   199,     3,   132,   178,   250,
      79,   215,    79,   173,   215,   243,    79,     3,   132,   138,
     138,   135,   138,   243,   221,    47,    47,   132,   246,   136,
     179,   200,     3,   137,    28,   200,   246,   221,   244,   226,
     226,   226,   226,   226,   228,   228,   228,   228,   230,   232,
     234,   236,   244,   238,   244,   249,   172,    28,   132,   132,
     156,    50,   251,   251,   251,   133,   189,    79,   156,   156,
     199,    79,   199,   133,   145,   133,   145,   168,   156,    79,
     130,   173,   135,   135,   148,   243,   243,    28,   221,   246,
     133,   132,   244,   172,   249,   246,   132,   135,   137,    28,
     246,   133,   133,    66,    79,    56,   190,   191,   201,   132,
     149,   149,    79,   173,   243,   246,    28,   132,   149,   251,
     137,   132,   156,   244,   249,   246,   132,   149,   149,   156,
     246,   191,    63,   134,   192,   159,   134,   134,   132,   246,
     134,   249,   156,   132,   132,   156,   134,   134,   135,   135,
     201,   132,   132,   156,   156,   164,   198,   198,   134,   156
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
     144,   144,   144,   144,   144,   144,   145,   146,   146,   146,
     146,   146,   147,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   159,   159,
     160,   161,   161,   162,   162,   162,   163,   163,   163,   164,
     164,   165,   165,   165,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   172,   172,   173,   173,   174,
     174,   174,   175,   175,   175,   175,   176,   177,   177,   177,
     177,   177,   177,   178,   179,   180,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   184,   185,   186,
     187,   188,   189,   189,   190,   190,   191,   192,   193,   194,
     195,   195,   195,   196,   197,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   202,   202,   202,   203,   204,
     204,   205,   205,   205,   205,   205,   205,   206,   206,   206,
     206,   207,   207,   208,   208,   209,   210,   210,   211,   211,
     212,   213,   213,   214,   214,   215,   215,   215,   216,   216,
     216,   216,   216,   217,   217,   218,   218,   218,   218,   219,
     219,   220,   220,   220,   220,   221,   221,   221,   221,   222,
     222,   222,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   224,   224,   224,   224,   225,   225,   225,   226,
     226,   226,   226,   227,   227,   227,   227,   227,   227,   227,
     228,   228,   228,   228,   228,   228,   229,   229,   229,   229,
     229,   230,   230,   230,   230,   230,   231,   231,   232,   232,
     233,   233,   234,   234,   235,   235,   236,   236,   237,   237,
     238,   238,   239,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   251,   251
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     2,     5,     5,     5,     1,     1,     3,     1,
       2,     3,     3,     3,     5,     1,     3,     2,     2,     1,
       3,     1,     3,     2,     2,     2,     2,     1,     1,     3,
       3,     5,     2,     2,     4,     4,     3,     1,     3,     3,
       5,     3,     5,     2,     2,     1,     2,     7,     5,     7,
       5,     9,    10,     7,     8,     8,     9,     3,     3,     3,
       5,     5,     3,     5,     1,     2,     4,     3,     3,     3,
       3,     3,     4,     5,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     5,
       4,     2,     4,     1,     2,     2,     6,     7,     0,     4,
       3,     0,     2,     3,     5,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     2,     2,     2,     4,     3,     2,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     5,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       0,     1,     0,     1,     0,     1,     1,     1
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
  "formal_parameter_list", "formal_parameter_rest", "arguments_spread",
  "function_body", "source_elements", "source_elements_for_function",
  "source_element", "source_element_for_function",
  "formal_parameter_list__opt", "identifier__opt", "statement",
  "statement_with_block", "statement_no_block", "block", "module_block",
  "export_statement", "import_statement", "import_expression",
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
       140,     0,    -1,    -1,   141,   150,    -1,    76,    79,    47,
     154,   132,   133,   149,   134,    -1,    60,    79,    47,   154,
     132,   133,   149,   134,    -1,    76,   155,    47,   154,   132,
     133,   149,   134,    -1,   144,    -1,   116,   146,   117,   113,
     133,   149,   134,    -1,   113,   133,   149,   134,    -1,   116,
     146,   117,   114,   133,   149,   134,    -1,   114,   133,   149,
     134,    -1,   116,   146,   117,   113,   145,    -1,   116,   146,
     117,   114,   145,    -1,   114,   145,    -1,   113,   145,    -1,
     125,   243,    -1,    79,   199,    -1,   173,   199,    -1,   146,
       3,    79,   199,    -1,   146,     3,   173,   199,    -1,   146,
       3,   147,    -1,   123,    79,    -1,   123,    79,    -1,    -1,
     151,    -1,   152,    -1,   150,   152,    -1,   153,    -1,   151,
     153,    -1,   156,    -1,   142,    -1,   157,    -1,   142,    -1,
      -1,   146,    -1,    -1,    79,    -1,   157,    -1,   160,    -1,
     161,    -1,   159,    -1,   158,    -1,   165,    -1,   166,    -1,
     180,    -1,   181,    -1,   182,    -1,   183,    -1,   184,    -1,
     185,    -1,   186,    -1,   187,    -1,   193,    -1,   188,    -1,
     194,    -1,   195,    -1,   162,    -1,   133,   134,    -1,   133,
     164,   134,    -1,   124,   155,   156,    -1,    68,   171,   251,
      -1,    68,   142,    -1,    82,    79,   127,   163,   251,    -1,
      82,   173,   127,   163,   251,    -1,    82,    97,   127,   163,
     251,    -1,    97,    -1,    79,    -1,   163,    50,    79,    -1,
     156,    -1,   164,   156,    -1,   107,   169,   251,    -1,    60,
     169,   251,    -1,   121,   169,   251,    -1,   121,    47,   167,
     132,   156,    -1,   168,    -1,   167,     3,   168,    -1,    79,
     199,    -1,   173,   178,    -1,   171,    -1,   169,     3,   171,
      -1,   172,    -1,   170,     3,   172,    -1,    79,   199,    -1,
     173,   199,    -1,    79,   200,    -1,   173,   200,    -1,   174,
      -1,   176,    -1,   128,   250,   130,    -1,   128,   175,   130,
      -1,   128,   175,     3,   250,   130,    -1,   250,    79,    -1,
     250,   173,    -1,   175,     3,   250,    79,    -1,   175,     3,
     250,   173,    -1,   129,   177,   131,    -1,    79,    -1,   215,
     135,    79,    -1,   215,   135,   173,    -1,   177,     3,   215,
     135,    79,    -1,   177,     3,    79,    -1,   177,     3,   215,
     135,   173,    -1,   136,   243,    -1,   136,   244,    -1,   251,
      -1,   246,   251,    -1,    80,    47,   246,   132,   156,    66,
     156,    -1,    80,    47,   246,   132,   156,    -1,    64,   156,
     109,    47,   246,   132,   251,    -1,   109,    47,   246,   132,
     156,    -1,    74,    47,   248,   137,   249,   137,   249,   132,
     156,    -1,    74,    47,   107,   170,   137,   249,   137,   249,
     132,   156,    -1,    74,    47,   221,    28,   246,   132,   156,
      -1,    74,    47,   107,   172,    28,   246,   132,   156,    -1,
      74,   122,    47,   221,    28,   246,   132,   156,    -1,    74,
     122,    47,   107,   172,    28,   246,   132,   156,    -1,    61,
     155,   251,    -1,    54,   155,   251,    -1,    94,   249,   251,
      -1,   110,    47,   246,   132,   156,    -1,    99,    47,   246,
     132,   189,    -1,   133,   201,   134,    -1,   133,   201,   192,
     201,   134,    -1,   191,    -1,   190,   191,    -1,    56,   246,
     135,   198,    -1,    63,   135,   198,    -1,    79,   135,   156,
      -1,   102,   246,   251,    -1,   106,   159,   196,    -1,   106,
     159,   197,    -1,   106,   159,   196,   197,    -1,    57,    47,
      79,   132,   159,    -1,    72,   159,    -1,    -1,   164,    -1,
      -1,   178,    -1,    -1,   179,    -1,    -1,   190,    -1,   203,
      -1,   204,    -1,    88,    -1,    97,    -1,    93,    -1,    87,
      -1,   105,    -1,    70,    -1,   101,    -1,    79,    -1,   202,
      -1,   206,    -1,   212,    -1,    47,   246,   132,    -1,    49,
     250,   138,    -1,    49,   207,   138,    -1,    49,   207,     3,
     250,   138,    -1,    49,   207,   209,   138,    -1,   250,   243,
      -1,   207,     3,   250,   243,    -1,     3,    -1,   208,     3,
      -1,   210,   211,    -1,    74,    47,   221,    28,   246,   132,
      -1,    74,   122,    47,   221,    28,   246,   132,    -1,    -1,
      80,    47,   246,   132,    -1,   133,   213,   134,    -1,    -1,
     214,   137,    -1,   215,   135,   243,    -1,   214,     3,   215,
     135,   243,    -1,    79,    -1,    97,    -1,    88,    -1,   205,
      -1,   143,    -1,   216,    49,   246,   138,    -1,   216,    50,
      79,    -1,    48,   216,   219,    -1,   216,    -1,    48,   217,
      -1,   216,   219,    -1,   218,   219,    -1,   218,    49,   246,
     138,    -1,   218,    50,    79,    -1,    47,   132,    -1,    47,
     220,   132,    -1,   243,    -1,   148,    -1,   220,     3,   243,
      -1,   220,     3,   148,    -1,   217,    -1,   218,    -1,   174,
      -1,   176,    -1,   221,    -1,   221,    46,    -1,   221,    45,
      -1,   222,    -1,    42,   223,    -1,    43,   223,    -1,    44,
     223,    -1,    46,   223,    -1,    45,   223,    -1,    35,   223,
      -1,    36,   223,    -1,    41,   223,    -1,    40,   223,    -1,
     223,    -1,   224,    37,   223,    -1,   224,    38,   223,    -1,
     224,    39,   223,    -1,   224,    -1,   225,    35,   224,    -1,
     225,    36,   224,    -1,   225,    -1,   226,    34,   225,    -1,
     226,    33,   225,    -1,   226,    32,   225,    -1,   226,    -1,
     227,    26,   226,    -1,   227,    25,   226,    -1,   227,    29,
     226,    -1,   227,    78,   226,    -1,   227,    27,   226,    -1,
     227,    28,   226,    -1,   226,    -1,   228,    26,   226,    -1,
     228,    25,   226,    -1,   228,    29,   226,    -1,   228,    78,
     226,    -1,   228,    27,   226,    -1,   227,    -1,   229,    23,
     227,    -1,   229,    22,   227,    -1,   229,    24,   227,    -1,
     229,    21,   227,    -1,   228,    -1,   230,    23,   228,    -1,
     230,    22,   228,    -1,   230,    24,   228,    -1,   230,    21,
     228,    -1,   229,    -1,   231,    20,   229,    -1,   230,    -1,
     232,    20,   230,    -1,   231,    -1,   233,    19,   231,    -1,
     232,    -1,   234,    19,   232,    -1,   233,    -1,   235,    18,
     233,    -1,   234,    -1,   236,    18,   234,    -1,   235,    -1,
     237,    17,   235,    -1,   236,    -1,   238,    17,   236,    -1,
     237,    -1,   239,    16,   237,    -1,   238,    -1,   240,    16,
     238,    -1,   239,    -1,   239,    15,   243,   135,   243,    -1,
     240,    -1,   240,    15,   244,   135,   244,    -1,   241,    -1,
     221,   245,   243,    -1,   242,    -1,   221,   245,   244,    -1,
     136,    -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,
       5,    -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,
       9,    -1,     8,    -1,   243,    -1,   246,     3,   243,    -1,
     244,    -1,   247,     3,   244,    -1,    -1,   247,    -1,    -1,
     246,    -1,    -1,   208,    -1,   137,    -1,   112,    -1
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
     160,   162,   164,   166,   168,   170,   172,   174,   176,   179,
     183,   187,   191,   194,   200,   206,   212,   214,   216,   220,
     222,   225,   229,   233,   237,   243,   245,   249,   252,   255,
     257,   261,   263,   267,   270,   273,   276,   279,   281,   283,
     287,   291,   297,   300,   303,   308,   313,   317,   319,   323,
     327,   333,   337,   343,   346,   349,   351,   354,   362,   368,
     376,   382,   392,   403,   411,   420,   429,   439,   443,   447,
     451,   457,   463,   467,   473,   475,   478,   483,   487,   491,
     495,   499,   503,   508,   514,   517,   518,   520,   521,   523,
     524,   526,   527,   529,   531,   533,   535,   537,   539,   541,
     543,   545,   547,   549,   551,   553,   555,   559,   563,   567,
     573,   578,   581,   586,   588,   591,   594,   601,   609,   610,
     615,   619,   620,   623,   627,   633,   635,   637,   639,   641,
     643,   648,   652,   656,   658,   661,   664,   667,   672,   676,
     679,   683,   685,   687,   691,   695,   697,   699,   701,   703,
     705,   708,   711,   713,   716,   719,   722,   725,   728,   731,
     734,   737,   740,   742,   746,   750,   754,   756,   760,   764,
     766,   770,   774,   778,   780,   784,   788,   792,   796,   800,
     804,   806,   810,   814,   818,   822,   826,   828,   832,   836,
     840,   844,   846,   850,   854,   858,   862,   864,   868,   870,
     874,   876,   880,   882,   886,   888,   892,   894,   898,   900,
     904,   906,   910,   912,   916,   918,   922,   924,   930,   932,
     938,   940,   944,   946,   950,   952,   954,   956,   958,   960,
     962,   964,   966,   968,   970,   972,   974,   976,   980,   982,
     986,   987,   989,   990,   992,   993,   995,   997
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   339,   339,   339,   353,   370,   386,   396,   409,   418,
     427,   437,   447,   457,   468,   479,   493,   513,   529,   540,
     550,   560,   575,   592,   602,   603,   607,   615,   625,   633,
     643,   644,   654,   655,   665,   666,   673,   674,   683,   684,
     689,   697,   702,   706,   711,   715,   720,   725,   730,   735,
     740,   745,   750,   755,   760,   765,   770,   775,   782,   789,
     800,   813,   820,   831,   848,   863,   883,   891,   899,   909,
     917,   928,   936,   944,   955,   965,   971,   978,   986,   997,
    1005,  1015,  1021,  1029,  1037,  1047,  1055,  1066,  1070,  1077,
    1087,  1094,  1107,  1119,  1129,  1139,  1150,  1161,  1171,  1183,
    1193,  1203,  1211,  1222,  1226,  1230,  1234,  1244,  1253,  1265,
    1273,  1281,  1293,  1305,  1316,  1328,  1339,  1353,  1363,  1373,
    1383,  1394,  1405,  1409,  1418,  1424,  1432,  1443,  1454,  1467,
    1477,  1486,  1495,  1507,  1518,  1526,  1527,  1531,  1532,  1536,
    1537,  1541,  1542,  1546,  1547,  1548,  1555,  1562,  1572,  1582,
    1589,  1599,  1606,  1613,  1614,  1615,  1616,  1624,  1634,  1641,
    1651,  1662,  1672,  1683,  1684,  1689,  1697,  1704,  1714,  1715,
    1724,  1739,  1742,  1749,  1758,  1768,  1775,  1782,  1792,  1796,
    1800,  1813,  1828,  1844,  1845,  1855,  1868,  1881,  1894,  1912,
    1913,  1917,  1923,  1929,  1934,  1942,  1943,  1944,  1945,  1949,
    1953,  1960,  1970,  1971,  1978,  1985,  1992,  1999,  2006,  2013,
    2020,  2027,  2037,  2038,  2042,  2046,  2053,  2054,  2058,  2065,
    2066,  2070,  2074,  2081,  2082,  2086,  2090,  2094,  2098,  2102,
    2109,  2110,  2114,  2118,  2122,  2126,  2133,  2134,  2138,  2142,
    2146,  2153,  2154,  2158,  2162,  2166,  2173,  2174,  2181,  2182,
    2189,  2190,  2197,  2198,  2205,  2206,  2213,  2214,  2221,  2222,
    2229,  2230,  2237,  2238,  2245,  2246,  2253,  2254,  2263,  2264,
    2273,  2277,  2287,  2291,  2302,  2303,  2304,  2305,  2306,  2307,
    2308,  2309,  2310,  2311,  2312,  2313,  2317,  2324,  2332,  2339,
    2347,  2348,  2352,  2353,  2357,  2358,  2362,  2363
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
  const int ParserImplementation::yylast_ = 1917;
  const int ParserImplementation::yynnts_ = 113;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 139;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 369;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 4993 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2366 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


