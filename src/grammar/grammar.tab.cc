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
#include <ast/visitors/ast_transformer.h>
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
#line 377 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(1) - (1)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 388 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 402 "grammar/grammar.yy"
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
#line 419 "grammar/grammar.yy"
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
#line 435 "grammar/grammar.yy"
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
#line 443 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 457 "grammar/grammar.yy"
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
#line 466 "grammar/grammar.yy"
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
#line 475 "grammar/grammar.yy"
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
#line 485 "grammar/grammar.yy"
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
#line 495 "grammar/grammar.yy"
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
#line 505 "grammar/grammar.yy"
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
#line 516 "grammar/grammar.yy"
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
#line 527 "grammar/grammar.yy"
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
#line 541 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 551 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 553 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 559 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 577 "grammar/grammar.yy"
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

  case 21:

/* Line 690 of lalr1.cc  */
#line 593 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 603 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 613 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].value_node) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 624 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 625 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 635 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 652 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 661 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 662 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 666 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 667 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 672 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 680 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 691 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 699 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 710 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 718 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 727 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 732 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 733 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 734 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 739 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 743 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 745 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 751 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 753 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 761 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 763 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 768 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 776 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 780 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 785 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 789 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 791 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 798 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 802 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 807 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 812 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 817 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 822 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 827 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 832 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 837 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 842 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 847 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 852 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 857 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 862 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 866 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 873 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 880 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 891 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    val->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    PragmaStmt* prg_stmt = ManagedHandle::Retain<PragmaStmt>();
    prg_stmt->Op( val );
    prg_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = prg_stmt;
  }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 904 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 917 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 929 "grammar/grammar.yy"
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

  case 76:

/* Line 690 of lalr1.cc  */
#line 946 "grammar/grammar.yy"
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

  case 77:

/* Line 690 of lalr1.cc  */
#line 961 "grammar/grammar.yy"
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

  case 78:

/* Line 690 of lalr1.cc  */
#line 981 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 989 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 997 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 1007 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1042 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1063 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1069 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1076 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1084 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1095 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1103 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1113 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1119 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1127 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1135 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1146 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1154 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1166 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1170 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1177 "grammar/grammar.yy"
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

  case 102:

/* Line 690 of lalr1.cc  */
#line 1187 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1194 "grammar/grammar.yy"
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

  case 104:

/* Line 690 of lalr1.cc  */
#line 1207 "grammar/grammar.yy"
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

  case 105:

/* Line 690 of lalr1.cc  */
#line 1219 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1228 "grammar/grammar.yy"
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

  case 107:

/* Line 690 of lalr1.cc  */
#line 1238 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (4)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(4) - (4)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1249 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1257 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1268 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1279 "grammar/grammar.yy"
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

  case 112:

/* Line 690 of lalr1.cc  */
#line 1289 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( node );
    node->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1302 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1312 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(5) - (5)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1332 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1342 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1346 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1350 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1355 "grammar/grammar.yy"
    {
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(2) - (1)].expression)->Line() );
    if ( (yysemantic_stack_[(2) - (1)].expression)->FirstChild()->NodeType() == AstNode::kClass ) {
      Class* cls = reinterpret_cast<Class*>( (yysemantic_stack_[(2) - (1)].expression)->FirstChild() );
      cls->Decl( true );
    }
    stmt->AddChild( (yysemantic_stack_[(2) - (1)].expression) );
    (yyval.expression_stmt) = stmt;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1369 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1378 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1387 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    stmt->Then( (yysemantic_stack_[(3) - (3)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1399 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1401 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1402 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(9) - (6)].expression) );
    iter->AddChild( (yysemantic_stack_[(9) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1410 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1411 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1412 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (4)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1420 "grammar/grammar.yy"
    {
    std::string error_msg = "Parse error. For loop condition must be non empty expression. for( <here> ){...}";
    error( yylloc , error_msg );
    YYABORT;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1425 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1426 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1427 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kFor ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(11) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(11) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(11) - (6)].ast) );
    list->AddChild( (yysemantic_stack_[(11) - (8)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(11) - (11)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1438 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1439 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1440 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(12) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(12) - (4)].node_list) );
    list->AddChild( (yysemantic_stack_[(12) - (7)].ast) );
    list->AddChild( (yysemantic_stack_[(12) - (9)].ast) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(12) - (12)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1452 "grammar/grammar.yy"
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

  case 138:

/* Line 690 of lalr1.cc  */
#line 1463 "grammar/grammar.yy"
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

  case 139:

/* Line 690 of lalr1.cc  */
#line 1475 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(6) - (4)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "parse error unexpected ";
      error_msg += (yysemantic_stack_[(6) - (4)].info)->GetToken();
      error_msg += " expected of.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1484 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForOf ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(8) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(8) - (5)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(8) - (8)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1495 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(7) - (5)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "Parse error, unexpected ";
      error_msg += (yysemantic_stack_[(7) - (5)].info)->GetToken();
      error_msg += ". mismatched for loop condition separator. Expect 'in','of' or ';'.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1504 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kForOfWithVar ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    list->AddChild( (yysemantic_stack_[(9) - (4)].value_node) );
    list->AddChild( (yysemantic_stack_[(9) - (6)].expression) );
    iter->Exp( list );
    iter->AddChild( (yysemantic_stack_[(9) - (9)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1516 "grammar/grammar.yy"
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

  case 144:

/* Line 690 of lalr1.cc  */
#line 1527 "grammar/grammar.yy"
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

  case 145:

/* Line 690 of lalr1.cc  */
#line 1541 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1551 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1561 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1571 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1582 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1593 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1597 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1612 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1620 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1631 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar/grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1655 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1665 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1674 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1683 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1695 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1706 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1713 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1718 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1719 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1723 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1724 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1728 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1729 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1733 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1734 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1736 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1750 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1760 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1770 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1777 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1787 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1794 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1800 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1801 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1802 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1804 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1812 "grammar/grammar.yy"
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

  case 186:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1829 "grammar/grammar.yy"
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

  case 188:

/* Line 690 of lalr1.cc  */
#line 1839 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(6) - (5)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(6) - (4)].ast)->AddChild( (yysemantic_stack_[(6) - (5)].ast) );
    }
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->Node( (yysemantic_stack_[(6) - (2)].node_list) );
    value->AddChild( (yysemantic_stack_[(6) - (4)].ast) );
    value->Line( (yysemantic_stack_[(6) - (2)].node_list)->Line() );
    (yyval.ast) = value;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1853 "grammar/grammar.yy"
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

  case 190:

/* Line 690 of lalr1.cc  */
#line 1863 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1880 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1886 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1894 "grammar/grammar.yy"
    {
    IterationStmt *for_of = ManagedHandle::Retain( new IterationStmt( AstNode::kForOf ) );
    for_of->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(6) - (3)].ast) );
    list->AddChild( (yysemantic_stack_[(6) - (5)].expression) );
    for_of->Exp( list );
    (yyval.ast) = for_of;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1906 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1908 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1917 "grammar/grammar.yy"
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

  case 199:

/* Line 690 of lalr1.cc  */
#line 1931 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1935 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1939 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1946 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1955 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    val->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    val->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    child->ValueType( ValueNode::kIdentifier );
    val->AddChild( child );
    list->AddChild( val );
    (yyval.ast) = list;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1968 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    value->Symbol( (yysemantic_stack_[(7) - (1)].info) );
    ValueNode* name = value->Clone()->CastToValue();
    fn->Name( name );
    fn->Argv ( (yysemantic_stack_[(7) - (3)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    value->AddChild( fn );
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1983 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    val->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    val->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    child->ValueType( ValueNode::kIdentifier );
    val->AddChild( child );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( val );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2002 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(9) - (1)].ast)->Line() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(9) - (3)].info) );
    ValueNode* name = value->Clone()->CastToValue();
    fn->Name( name );
    fn->Argv ( (yysemantic_stack_[(9) - (5)].ast) );
    fn->Append( (yysemantic_stack_[(9) - (8)].node_list) );
    value->AddChild( fn );
    (yysemantic_stack_[(9) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(9) - (1)].ast);
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2019 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2026 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2033 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2040 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kPrivateProperty ) );
    node->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    node->Node( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2050 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2054 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2063 "grammar/grammar.yy"
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

  case 216:

/* Line 690 of lalr1.cc  */
#line 2076 "grammar/grammar.yy"
    {
    int depth = 0;
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kPrivate ) );
    exp->Line( value->Line() );
    exp->Callable( value );
    exp->Args( (yysemantic_stack_[(4) - (3)].expression) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2088 "grammar/grammar.yy"
    {
    int depth = 0;
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    ValueNode* ident = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    value->Symbol( (yysemantic_stack_[(3) - (1)].info) );
    ident->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    value->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kPrivate ) );
    exp->Line( value->Line() );
    exp->Callable( value );
    exp->Args( ident );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2103 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
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

  case 219:

/* Line 690 of lalr1.cc  */
#line 2118 "grammar/grammar.yy"
    {
    int depth = 0;
    if ( (yysemantic_stack_[(3) - (1)].ast)->NodeType() == AstNode::kCallExp ) {
      depth = reinterpret_cast<CallExp*>( (yysemantic_stack_[(3) - (1)].ast) )->Depth() + 1;
    }
    CallExp* exp = ManagedHandle::Retain( new CallExp( CallExp::kExtend ) );
    exp->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    exp->Callable( (yysemantic_stack_[(3) - (1)].ast) );
    exp->Args( (yysemantic_stack_[(3) - (3)].ast) );
    exp->Depth( depth );
    (yyval.ast) = exp;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2131 "grammar/grammar.yy"
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

  case 221:

/* Line 690 of lalr1.cc  */
#line 2146 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2148 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2158 "grammar/grammar.yy"
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

  case 224:

/* Line 690 of lalr1.cc  */
#line 2171 "grammar/grammar.yy"
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

  case 225:

/* Line 690 of lalr1.cc  */
#line 2184 "grammar/grammar.yy"
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

  case 226:

/* Line 690 of lalr1.cc  */
#line 2197 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
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

  case 227:

/* Line 690 of lalr1.cc  */
#line 2214 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2215 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2220 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2226 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2232 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2237 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2245 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Line( (yysemantic_stack_[(7) - (2)].info)->GetLineNumber() );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2256 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2257 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2262 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2264 "grammar/grammar.yy"
    {
    ClassExpandar* expandar;
    if ( (yysemantic_stack_[(2) - (1)].info)->GetType() == yy::ParserImplementation::token::JS_PROTOTYPE ) {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kPrototype ) );
    } else {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kExtends ) );
    }
    expandar->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    expandar->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = expandar;
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2279 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2280 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2285 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2286 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2290 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2296 "grammar/grammar.yy"
    {
    ClassProperties* list = ManagedHandle::Retain<ClassProperties>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
#define TYPE( name )                            \
      case ClassMember::k##name :               \
        list->name( (yysemantic_stack_[(1) - (1)].ast) );                       \
        break

      ClassMember* mem = reinterpret_cast<ClassMember*>( (yysemantic_stack_[(1) - (1)].ast) );
      switch ( mem->Attr() ) {
        TYPE(Private);
        TYPE(Public);
        TYPE(Static);
        TYPE(Prototype);
        TYPE(Constructor);
      }
#undef TYPE
    }
    (yyval.prop) = list;
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2317 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
#define TYPE( name )                            \
      case ClassMember::k##name :               \
        (yysemantic_stack_[(2) - (1)].prop)->name( (yysemantic_stack_[(2) - (2)].ast) );                         \
        break

      ClassMember* mem = reinterpret_cast<ClassMember*>( (yysemantic_stack_[(2) - (2)].ast) );
      switch ( mem->Attr() ) {
        TYPE(Private);
        TYPE(Public);
        TYPE(Static);
        TYPE(Prototype);
        TYPE(Constructor);
      }
#undef TYPE
    }
    (yyval.prop) = (yysemantic_stack_[(2) - (1)].prop);
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2341 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2346 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2347 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2348 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2349 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2350 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2356 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(7) - (1)].info) );
    fn->Name( value );
    fn->Argv ( (yysemantic_stack_[(7) - (3)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.ast) = fn;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2371 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2381 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2391 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2400 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2409 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2411 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2417 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2419 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(7) - (1)].info) );
    fn->Name( value );
    fn->Argv ( (yysemantic_stack_[(7) - (3)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.ast) = fn;
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2430 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Attr( Function::kGet );
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(7) - (2)].info) );
    fn->Name( value );
    fn->Argv ( ManagedHandle::Retain<Empty>() );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.ast) = fn;
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2442 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Attr( Function::kSet );
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(8) - (2)].info) );
    fn->Name( value );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.ast) = fn;
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2457 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2458 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2459 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2460 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2465 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2469 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2476 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2485 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2487 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2494 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2501 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2508 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2515 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2522 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2529 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2536 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2543 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2552 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2554 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2558 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2562 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2568 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2570 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2574 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2580 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2582 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2590 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2596 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2598 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2602 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2606 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2610 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2614 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2618 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2624 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2626 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2630 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2634 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2642 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2648 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2650 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2654 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2658 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2662 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2668 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2670 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2674 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2678 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2682 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2688 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2690 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2696 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2698 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2704 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2706 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2712 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2714 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2720 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2722 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2728 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2730 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2736 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2738 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2744 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2746 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2752 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2754 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2760 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2762 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2768 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2770 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2778 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2780 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2788 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2790 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2795 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2804 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2806 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2811 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2821 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2825 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2835 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2839 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2849 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2850 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2851 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2852 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2853 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2854 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2855 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2856 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2857 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2858 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2859 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2860 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2865 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2872 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2880 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2887 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2894 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2895 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2899 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2900 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2904 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2905 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2909 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2910 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4462 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -484;
  const short int
  ParserImplementation::yypact_[] =
  {
      1533,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,
    2188,  3148,    89,     4,     3,     4,  1533,   180,  -484,    20,
     171,   -33,    75,  2820,   182,  -484,  -484,    76,  -484,  2293,
    -484,    83,  -484,  2820,  -484,   130,   141,  -484,   240,  -484,
     -15,   100,   221,    60,     4,    89,   257,  2398,   260,   870,
    -484,   290,  -484,  -484,  -484,  -484,  1201,  -484,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,   196,  -484,   363,
    -484,   282,    91,  -484,  -484,   362,    82,   435,   189,   352,
     329,   346,   353,   364,   378,  -484,  -484,  -484,    21,  -484,
    -484,     4,  -484,   233,   381,  -484,  -484,  -484,  -484,  -484,
    -484,  -484,  -484,  -484,   293,   236,    18,  2820,   196,  -484,
    -484,    19,   386,   981,  -484,   -55,    -6,    47,  -484,   239,
    -484,  -484,   -55,   308,   141,     6,   341,   354,   405,  -484,
    -484,  1863,   388,   396,   408,  1533,  2820,   734,   337,   342,
     369,  2820,   412,   495,   -55,  2820,    21,  1311,   289,   239,
      47,   452,  2820,  2820,  1753,  -484,  1753,  -484,   239,   421,
    -484,   498,  -484,   384,   239,   162,    47,  1533,    31,   -10,
     424,  -484,  -484,   425,  -484,   298,  -484,  1422,   360,  -484,
    -484,  2083,  2820,    36,  -484,  2820,   427,  -484,     4,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,
    -484,  -484,  -484,  2820,  3030,  3030,  3030,  3030,  3030,  3030,
    3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,
    3030,  3030,  3030,  3030,  3030,  3030,  2820,  3030,  2820,  -484,
    2820,   361,  -484,  -484,    33,   365,  -484,  -484,  -484,    89,
     434,  -484,  -484,  -484,  -484,  -484,   221,  2820,  -484,  -484,
     141,  -484,  -484,  -484,  -484,   405,   221,   462,   463,   210,
    2504,  1533,   223,   435,   227,   383,   492,   494,   496,   499,
     422,  -484,  -484,  -484,   512,  -484,  3063,   221,   221,  -484,
      30,  -484,    12,    12,    12,    22,  -484,  -484,    34,  -484,
     470,   130,   446,  -484,  -484,  2820,    39,  -484,   374,  1753,
    -484,  -484,   375,  -484,  -484,   224,   326,  -484,   239,    41,
    -484,   239,  -484,  -484,    89,  -484,  -484,  -484,  -484,  -484,
     379,   380,    40,    15,   385,  -484,  -484,  -484,   442,  -484,
    -484,    48,  -484,    23,  -484,  -484,    27,  -484,    43,  -484,
    -484,  -484,  -484,   362,   362,    82,    82,    82,   435,   435,
     435,   435,   435,   435,   189,   189,   189,   189,   352,   329,
     346,   353,   389,   364,  -484,   376,   313,  -484,   229,  1091,
     479,   126,  -484,   387,  -484,  -484,   480,   393,   394,   221,
     382,   529,   197,   382,  -484,    91,  -484,  -484,  2820,  2820,
    2925,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,  3030,
    3030,  3030,  3030,  3030,  2925,  3030,  2925,   395,   210,   513,
     399,   401,  1533,  -484,  -484,    11,    11,    11,  -484,   402,
     466,  -484,  -484,   495,  1533,  -484,  -484,  -484,   239,  -484,
    -484,   239,   129,   173,  -484,   162,  1533,  -484,   134,   406,
    1533,   221,   336,  -484,  2820,  -484,  2610,  -484,  -484,  -484,
    -484,  -484,   410,  3200,  2820,  -484,   361,   413,  -484,  -484,
    -484,  -484,  3115,   505,  -484,   407,   414,  2820,   416,   417,
     419,  2925,  -484,  -484,   210,   415,  2820,  2820,  -484,    51,
      56,  -484,   435,   435,   435,   435,   435,   227,   227,   227,
     227,   383,   492,   494,   496,   423,   499,  -484,  1973,   539,
    2820,   426,   428,   502,   497,  -484,  -484,  -484,   519,  -484,
     450,   451,  -484,  -484,  -484,  1753,  -484,  1753,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  1201,  -484,   455,    42,   431,
    -484,  -484,  -484,   959,  3200,   400,  -484,   234,   516,  2820,
    -484,  1753,   495,  1753,  1753,   456,  -484,  -484,  1973,    61,
      65,  1533,  -484,  2925,   430,  2820,    68,  1753,  1753,  1533,
    -484,  2820,   519,  -484,   -18,   130,  1533,   454,   457,  1201,
     458,   460,   221,  2820,   180,   180,   180,   554,  -484,   461,
    -484,  1069,  -484,  -484,  -484,  -484,  -484,  -484,   -55,   196,
    -484,  -484,  2820,    78,   464,   465,   468,   469,  1753,   459,
    1533,  -484,  -484,  1533,  -484,  2715,   105,  1533,   471,   472,
    -484,    28,  -484,   473,  -484,   519,  -484,  -484,  -484,  -484,
    -484,  1753,   467,  -484,   -55,   -55,   -55,   221,  -484,  -484,
    -484,   106,  -484,  -484,   -55,  -484,  -484,   476,  2715,  -484,
    1533,  -484,  -484,  1533,  -484,  -484,  -484,  1201,  1201,   477,
     484,   481,  -484,  -484,  -484,   487,  -484,  -484,  -484,  -484,
    -484,   488,  -484,  -484,  -484,  -484,  -484,  1753,   489,   491,
    1533,   490,  1643,  1533,  -484,  -484,   318,   493,  1643,  -484,
    -484,  -484,  -484,  -484,  -484,  -484
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
       234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   367,    45,   235,    45,   234,   234,   178,     0,
      45,   180,     0,   234,     0,   176,   173,     0,   175,   365,
     174,     0,   179,   234,   177,     0,     0,   127,     0,   370,
       0,     0,    43,     0,    45,   367,     0,   234,     0,   234,
     369,     0,    69,    54,   213,     7,     2,    32,    38,    47,
      51,    50,    53,    48,    49,    68,    52,    55,   264,    56,
      57,    58,    59,    60,    61,    62,    63,    65,    64,    66,
      67,   181,   171,   172,   212,   182,   183,   221,   262,   263,
     214,     0,   266,   269,   279,   283,   286,   290,   303,   313,
     317,   321,   325,   329,   333,   337,   343,   359,     0,   119,
     235,    45,   180,     0,   266,   275,   276,   278,   277,   270,
     271,   272,   274,   273,     0,     0,     0,   234,   221,   222,
     191,     0,   368,   234,    46,     0,   165,     0,    91,   165,
      99,   100,     0,     0,   235,   165,     0,     0,   256,   258,
      74,   234,     0,     0,     0,   234,   234,   234,     0,     0,
       0,   234,     0,   366,     0,   234,     0,   234,     0,   165,
       0,     0,   234,   234,    30,    15,    30,    14,   165,     0,
      44,    17,    18,     0,   165,     0,     0,   234,     0,     0,
       0,   338,   339,     0,    70,   199,    81,   234,     0,     1,
      33,   234,   234,     0,   223,   234,     0,   224,    45,   355,
     352,   354,   353,   358,   357,   348,   350,   349,   356,   351,
     268,   267,   347,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   120,
     234,   111,   210,   209,     0,     0,   265,   184,   220,   367,
       0,   186,   192,   185,   189,   146,    43,   234,   166,    95,
       0,    84,    96,   145,   124,   257,    43,     0,     0,     0,
     234,   234,   266,   297,   308,   315,   319,   323,   327,   331,
     335,   340,   345,   361,   364,   131,   234,    43,    43,   156,
       0,   123,     0,     0,     0,     0,   217,   147,     0,   157,
       0,     0,   158,   159,    83,   234,     0,    16,     0,    31,
      36,    42,     0,    20,    26,    24,     0,    21,   165,     0,
      87,     0,    85,    73,   367,   102,   104,   101,   105,   106,
       0,     0,   203,   201,     0,    71,    82,   198,     0,   227,
     230,     0,   229,     0,   218,   219,     0,   226,   236,   344,
     280,   281,   282,   284,   285,   289,   288,   287,   292,   291,
     295,   296,   293,   294,   307,   305,   304,   306,   314,   318,
     322,   326,     0,   330,   360,     0,     0,   110,     0,   234,
       0,   196,   193,     0,   117,    92,     0,     0,     0,    43,
     167,   134,    93,   167,   341,   266,   342,   130,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,     0,     0,     0,
       0,     0,   234,    79,    78,     0,     0,     0,   216,     0,
       0,   162,   160,   128,   234,     9,    37,    11,   165,    19,
      25,   165,     0,     0,    89,     0,   234,    90,     0,     0,
     234,    43,     0,   200,   234,    27,   234,   228,   215,   225,
     238,   239,     0,   234,   234,   211,   115,     0,   112,   113,
     187,   190,   234,     0,   194,     0,     0,   234,     0,     0,
       0,   234,   168,    97,     0,     0,   234,   234,    98,     0,
       0,   346,   299,   298,   302,   300,   301,   312,   310,   309,
     311,   316,   320,   324,   328,     0,   332,   362,   234,     0,
     234,     0,     0,   122,     0,    75,    77,    76,   169,   149,
       0,     0,   148,    22,    23,    30,    12,    30,    13,    88,
      86,   107,   103,   108,   109,   163,    72,     0,   206,     0,
     202,   232,   231,   234,   234,   237,   334,     0,     0,   234,
     188,    30,   125,    30,    30,     0,   118,    94,   234,     0,
       0,   234,   139,   234,     0,   234,     0,    30,    30,   234,
      80,   234,   170,   152,     0,     0,   234,     0,     0,   164,
       0,     0,    43,   234,   234,   234,   234,     0,   246,     0,
     241,   234,   243,   245,   247,   248,   249,   250,     0,     0,
     114,   116,   234,     0,     0,     0,     0,     0,    30,     0,
     234,   141,   137,   234,   336,   234,     0,   234,     0,     0,
     121,     0,   153,     0,   150,   169,   161,   129,     8,    10,
       3,    30,     0,   205,     0,     0,     0,    43,   233,   244,
     252,     0,   197,     5,     0,   259,   260,     0,   234,   138,
     234,   140,   132,   234,   143,     4,     6,   163,   163,     0,
       0,     0,   255,   254,   253,     0,   195,   126,   261,   135,
     142,     0,   144,   154,   155,   151,   204,    30,     0,     0,
     234,     0,    28,   234,   133,   207,   234,     0,    29,    34,
      39,    40,    41,   136,   251,    35
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -484,  -484,  -484,  -484,  -484,  -484,   -30,  -484,  -484,  -484,
    -174,   145,  -484,  -147,  -484,  -484,  -484,   559,   -74,   317,
    -249,    -1,     0,   109,  -484,   -34,  -484,  -484,  -484,  -484,
     155,    -9,  -484,  -484,  -484,   177,    80,  -484,   367,  -363,
     -19,    -4,  -484,   629,  -484,   309,  -484,  -418,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,  -484,    59,  -484,
    -484,  -484,  -484,  -484,   330,  -175,  -132,   242,    13,  -484,
    -484,  -484,  -484,  -484,  -484,  -484,  -484,   256,  -484,   447,
    -484,  -484,  -176,    -7,   640,  -484,   231,  -484,   -14,  -484,
    -484,  -484,  -484,  -484,  -484,    52,  -484,  -484,  -484,  -410,
    -332,   -11,   475,  -484,    71,   268,   243,   -88,   248,    45,
     429,   232,   411,   235,   420,   237,   432,   238,   418,   230,
    -484,  -484,  -484,  -484,  -484,  -484,   -45,  -272,   565,    37,
    -484,  -484,  -483,   -36,   -80
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,    51,    52,    53,    54,    55,   175,   180,   181,   449,
     182,   350,   697,   318,    56,   698,   319,    57,   699,   320,
     183,   154,   196,    59,    60,    61,    62,    63,    64,    65,
     435,   589,    66,    67,   329,   330,   148,   401,   138,   402,
     139,    68,   188,   141,   254,   268,   492,    69,    70,    71,
      72,   396,   615,   171,   531,   427,   681,   495,   689,   623,
     660,    73,    74,    75,    76,    77,   529,   582,   583,   635,
      78,    79,    80,   312,   313,   590,   269,   493,   584,    81,
      82,    83,    84,    85,   131,   132,   391,   392,   485,    86,
     198,   343,   255,    87,    88,    89,   258,   351,    90,    91,
     472,   473,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,    92,    93,    94,    95,    96,    97,    98,   284,
      99,   285,   100,   286,   101,   287,   102,   288,   103,   289,
     104,   290,   105,   291,   106,   292,   107,   293,   410,   108,
     294,   295,   164,   133,   109
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -366;
  const short int
  ParserImplementation::yytable_[] =
  {
        58,   168,   192,   149,   128,   160,   150,   272,   406,   189,
     140,   177,   135,   140,   142,   338,   143,   393,   462,   344,
     140,   248,   259,   184,   248,   248,   248,   397,   249,   322,
     248,   248,   140,   248,   334,   574,   386,   248,   140,   140,
     197,   266,   248,   187,   455,   633,   323,   126,   430,   431,
     270,   466,   327,   276,   248,   265,    58,   271,    39,   248,
     157,   524,   273,   283,   248,   519,   163,   151,   248,   336,
     166,   248,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   248,   136,   134,   307,   619,   309,   461,   264,   592,
     314,   433,   130,    50,   137,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   332,   185,   248,   248,
     434,   173,   470,   155,   179,   354,   170,   227,   228,    45,
     124,   337,   156,   186,    39,   161,   162,   634,   317,   174,
     165,   567,    45,   124,    39,   598,   220,   221,   501,   169,
     140,   267,   662,   152,   368,   369,   370,   371,   372,   373,
     490,   450,   515,   267,   517,   299,   352,   301,   197,    50,
      39,   257,   335,   463,   126,   387,   331,   260,   261,    50,
     339,   438,   468,   432,   667,   679,   469,   439,   359,   471,
     113,   140,   444,   598,   456,   140,  -208,   333,  -208,    45,
     124,   467,   283,   300,   571,    50,   454,   346,   305,   572,
     390,   382,   308,   384,   620,   385,   483,   358,   621,   316,
     477,   627,   547,   541,   232,   233,   234,   235,   236,   566,
     169,   652,   394,   389,   275,   496,   173,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   222,   353,
     144,   328,   356,   201,   176,   202,   203,   184,   663,   676,
     153,   408,   411,   412,   413,   173,   414,   184,   179,   145,
     403,   158,   140,    45,   124,   542,   140,   237,   220,   221,
      45,   124,   140,   535,   167,   140,   497,   441,   184,   184,
     159,   407,   701,   321,   543,   321,   549,   172,   701,   400,
     199,    45,   124,   140,   140,   360,   361,   362,   458,   173,
     178,   624,   409,   448,   190,   415,   451,   193,   478,    45,
     124,    45,   124,   610,   146,   147,   533,   537,   204,   534,
     207,   140,   283,   502,   503,   504,   505,   506,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,    45,
     124,   208,   250,   642,   481,   179,   310,   250,   179,   242,
      45,   124,   443,    45,   124,   525,   526,   527,    45,   124,
     702,   311,   250,    45,   124,   243,   702,   161,   162,   479,
     222,   244,   251,   238,   239,   240,   241,   342,   144,   256,
     184,   245,   252,   195,   140,   250,   267,   252,   587,   262,
     588,   253,   476,   246,   247,   140,   253,   145,   675,   224,
     225,   226,   252,   283,   416,   417,   418,   419,   270,   403,
     201,   253,   205,   206,   614,   548,   616,   617,   274,   550,
     277,   552,   536,   538,   140,   252,   220,   221,   321,   556,
     628,   629,   523,   278,   253,   296,   331,   424,   425,   544,
     452,   453,   184,   297,   532,   499,   500,    45,   124,   202,
     203,   140,   146,   147,   140,   298,   540,   140,   436,   437,
     546,   507,   508,   509,   510,   302,   555,   229,   230,   231,
     303,   657,   365,   366,   367,   403,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   283,   374,   375,   376,   377,
     140,   306,   683,   684,   670,   363,   364,   304,   248,   315,
     324,   325,   326,   340,   341,   347,   357,  -208,   390,   398,
     399,   388,   420,   421,   422,   426,   423,   440,   311,   445,
     447,   465,   459,   460,   562,   475,   482,   487,   650,   491,
     486,   464,   494,   569,   570,   474,   488,   489,   611,   149,
     691,   520,   521,   518,   522,   530,   528,   609,   643,   140,
     545,   636,   559,   140,   553,   163,   560,   576,   561,   557,
     563,   564,   565,   568,   672,   673,   674,   575,   579,   573,
     577,   622,   578,   184,   677,   581,   580,   593,   625,   630,
     149,   149,   149,   644,   645,   646,   637,   149,   140,   346,
     140,   140,   140,   585,   586,   612,   613,   140,   591,   638,
     618,   647,   639,   640,   641,   163,   648,   658,   654,   653,
     671,   551,   626,   655,   656,   200,   665,   666,   631,   668,
     659,   678,   685,   661,   705,   687,   282,   664,   184,   686,
     688,   690,   539,   692,   693,   695,   446,   395,   704,   125,
     457,   632,   442,   140,   321,   498,   321,   484,   669,   651,
     355,   129,   511,   649,   379,   516,   512,   223,     0,   513,
     680,   514,   163,   682,   380,   383,     0,     0,     0,     0,
     321,   378,   321,   321,     0,     0,     0,   381,     0,     0,
       0,     0,   149,     0,     0,   644,   321,   321,     0,     0,
     694,     0,   140,   703,     0,   163,     0,     0,     0,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,     0,   114,     0,     0,     0,     0,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     321,     0,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,   429,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,   321,     0,    16,     0,
       0,   700,    17,     0,    18,     0,     0,   700,    19,     0,
      20,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,     0,    49,     0,
       0,     0,    50,     0,     0,   405,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   405,
     114,   405,     0,     0,     0,     1,     2,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      14,    15,     0,     0,    16,     0,     0,     0,    17,     0,
      18,     0,     0,     0,    19,     0,    20,     0,     0,    21,
      22,    23,     0,    24,     0,     0,     0,   558,    25,    26,
      27,     0,     0,     0,    28,    29,   405,     0,    30,     0,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,     0,
       0,     0,    43,     0,     0,    44,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    47,
       0,     0,    48,     0,    49,   194,     1,     2,    50,   144,
     195,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,   110,     0,     0,     0,     0,     0,     0,   405,   594,
       0,    18,   595,     0,     0,     0,   596,   111,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    39,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,    45,   124,
       0,     0,   597,   146,   147,    40,    41,     0,    42,     0,
       0,     0,     0,     0,  -240,     0,     0,    50,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,   113,     1,     2,     0,   144,
     263,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,   594,
       0,    18,   595,     0,     0,     0,   596,   111,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    39,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,    45,   124,
       0,     0,   597,   146,   147,    40,    41,     0,    42,     0,
       0,     0,     0,     0,  -242,     0,     0,    50,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,   113,     1,     2,     0,     0,
     480,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
    -234,    14,    15,     0,     0,    16,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,    25,
      26,    27,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    48,     0,    49,     1,     2,     0,    50,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,    25,
      26,    27,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    48,     0,    49,   194,     1,     2,    50,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,    16,     0,     0,     0,
      17,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,    48,     0,    49,   345,     1,     2,
      50,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,    14,    15,     0,     0,    16,     0,     0,
       0,    17,     0,    18,     0,     0,     0,    19,     0,    20,
       0,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,     0,     0,    48,     0,    49,     1,     2,
       0,    50,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,     0,  -234,    14,    15,     0,     0,    16,     0,     0,
       0,     0,     0,    18,     0,     0,     0,    19,     0,    20,
       0,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,    25,    26,   696,     0,     0,   595,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,     0,     0,    48,     0,    49,     1,     2,
       0,    50,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,     0,  -234,    14,    15,     0,     0,    16,     0,     0,
       0,     0,     0,    18,     0,     0,     0,    19,     0,    20,
       0,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,     0,     0,    48,     0,    49,     1,     2,
       0,    50,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   111,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,   279,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,     0,   281,   113,     1,     2,
       0,  -363,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   111,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,   113,     1,     2,
       0,  -365,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   111,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,   348,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     1,     2,     0,   349,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   111,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,   124,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     1,     2,
       0,     0,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -234,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   111,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     1,     2,     0,     0,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   111,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,   191,     1,
       2,     0,   113,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     111,     0,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,   404,     1,     2,     0,   113,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   111,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       1,     2,     0,     0,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   111,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     1,     2,     0,  -365,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   111,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       1,     2,     0,     0,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   111,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     1,     2,     0,     0,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   111,     0,     0,   112,
      10,    11,    12,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,   110,    28,     0,     0,     0,    30,     0,
       0,     0,    32,    18,     0,     0,    34,     0,     0,   111,
       0,     0,   112,     0,    40,    41,     0,    42,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,    45,
       0,    30,    10,    11,    12,    32,     0,     0,     0,    34,
       0,   428,     0,     0,   113,   110,     0,    40,    41,     0,
      42,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   111,    45,     0,   112,   127,    11,    12,     0,     0,
       0,     0,     0,    25,    26,    27,     0,   113,   110,    28,
       0,     0,     0,    30,     0,     0,     0,    32,    18,     0,
       0,    34,     0,     0,   111,     0,     0,   112,     0,    40,
      41,     0,    42,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,    45,     0,    30,   127,   554,    12,
      32,     0,     0,     0,    34,     0,     0,     0,     0,   113,
     110,     0,    40,    41,     0,    42,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   111,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,   113,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         0,    35,    47,    17,    11,    24,    17,   139,   280,    45,
      14,    41,    13,    17,    15,   189,    16,   266,     3,   195,
      24,     3,     3,    42,     3,     3,     3,   276,   108,   176,
       3,     3,    36,     3,     3,   518,     3,     3,    42,    43,
      49,    47,     3,    44,     3,    63,   178,    10,   297,   298,
       3,     3,   184,    47,     3,   135,    56,   137,   113,     3,
      23,    50,   142,   151,     3,   428,    29,    47,     3,    79,
      33,     3,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     3,    79,    79,   164,   568,   166,    47,   133,    47,
     170,    79,     3,   148,    14,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   186,    47,     3,     3,
      98,   126,    69,   146,   124,    79,    36,    35,    36,   129,
     130,   131,    47,    43,   113,    49,    50,   145,   173,   144,
      47,   494,   129,   130,   113,   553,    45,    46,   410,    79,
     144,   147,   625,   123,   232,   233,   234,   235,   236,   237,
     399,   325,   424,   147,   426,   155,   201,   157,   167,   148,
     113,   143,   131,   148,   127,   132,   185,   148,   149,   148,
     189,   149,   149,   143,   146,   658,   149,   143,   223,   136,
     144,   185,   143,   601,   143,   189,   146,   187,   146,   129,
     130,   143,   280,   156,   143,   148,   328,   197,   161,   143,
      74,   246,   165,   248,   143,   250,    80,   208,   143,   172,
     386,   143,   461,    79,    25,    26,    27,    28,    29,   491,
      79,   143,   267,   259,   144,    28,   126,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   147,   202,
      60,    79,   205,    47,   144,    49,    50,   266,   143,   143,
      79,    28,    25,    26,    27,   126,    29,   276,   124,    79,
     279,    79,   266,   129,   130,   131,   270,    78,    45,    46,
     129,   130,   276,   144,   144,   279,    79,   311,   297,   298,
      98,   281,   692,   174,   458,   176,   462,    47,   698,    79,
       0,   129,   130,   297,   298,   224,   225,   226,   334,   126,
      79,   573,    79,    79,    47,    78,   325,    47,    79,   129,
     130,   129,   130,    79,   134,   135,   448,   144,    87,   451,
      89,   325,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   129,
     130,    59,    49,   592,   389,   124,    57,    49,   124,    20,
     129,   130,   315,   129,   130,   435,   436,   437,   129,   130,
     692,    72,    49,   129,   130,    19,   698,    49,    50,   388,
     147,    18,    79,    21,    22,    23,    24,    79,    60,   143,
     399,    17,    89,   150,   388,    49,   147,    89,   535,     3,
     537,    98,    79,    15,    16,   399,    98,    79,   647,    37,
      38,    39,    89,   491,    21,    22,    23,    24,     3,   428,
      47,    98,    49,    50,   561,    79,   563,   564,   110,   464,
      79,   466,   452,   453,   428,    89,    45,    46,   319,   474,
     577,   578,   432,    79,    98,    47,   455,    15,    16,   458,
     114,   115,   461,    47,   444,   408,   409,   129,   130,    49,
      50,   455,   134,   135,   458,    47,   456,   461,   303,   304,
     460,   416,   417,   418,   419,   128,   473,    32,    33,    34,
     128,   618,   229,   230,   231,   494,     1,     2,     3,     4,
       5,     6,     7,     8,     9,   573,   238,   239,   240,   241,
     494,    79,   667,   668,   641,   227,   228,   128,     3,    47,
      79,     3,   118,    79,    79,   145,    79,   146,    74,    47,
      47,   146,    20,    19,    18,     3,    17,    47,    72,   145,
     145,    79,   143,   143,   487,   149,    47,    47,   608,   147,
     143,   146,     3,   496,   497,   146,   143,   143,   557,   553,
     687,    28,   143,   148,   143,    79,   144,   554,   593,   553,
     144,   585,    47,   557,   144,   518,   149,   520,   144,   146,
     144,   144,   143,   148,   644,   645,   646,    28,    66,   146,
     144,   571,   144,   592,   654,    56,    79,   146,   148,   579,
     594,   595,   596,   594,   595,   596,   586,   601,   592,   589,
     594,   595,   596,   143,   143,    79,   559,   601,   143,   145,
     144,    47,   145,   145,   144,   568,   145,   148,   143,   145,
     143,   466,   575,   145,   145,    56,   145,   145,   581,   146,
     620,   145,   145,   623,   698,   144,   151,   627,   647,   145,
     143,   143,   455,   144,   143,   145,   319,   270,   145,    10,
     331,   582,   312,   647,   535,   403,   537,   391,   635,   612,
     203,    11,   420,   601,   243,   425,   421,    92,    -1,   422,
     660,   423,   625,   663,   244,   247,    -1,    -1,    -1,    -1,
     561,   242,   563,   564,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   696,    -1,    -1,   696,   577,   578,    -1,    -1,
     690,    -1,   696,   693,    -1,   658,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,   247,    -1,    -1,    -1,    -1,   618,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     641,    -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,   296,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,   687,    -1,    64,    -1,
      -1,   692,    68,    -1,    70,    -1,    -1,   698,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,    -1,   144,    -1,
      -1,    -1,   148,    -1,    -1,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,   482,    88,    89,
      90,    -1,    -1,    -1,    94,    95,   491,    -1,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,
      -1,    -1,   142,    -1,   144,   145,    35,    36,   148,    60,
     150,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,   573,    90,
      -1,    70,    93,    -1,    -1,    -1,    97,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,   113,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,   129,   130,
      -1,    -1,   133,   134,   135,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   148,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,   144,    35,    36,    -1,    60,
     149,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    70,    93,    -1,    -1,    -1,    97,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,   113,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,   129,   130,
      -1,    -1,   133,   134,   135,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   148,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,   144,    35,    36,    -1,    -1,
     149,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   142,    -1,   144,    35,    36,    -1,   148,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   142,    -1,   144,   145,    35,    36,   148,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,   144,   145,    35,    36,
     148,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,    -1,    -1,   142,    -1,   144,    35,    36,
      -1,   148,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,    -1,    -1,   142,    -1,   144,    35,    36,
      -1,   148,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,    -1,    -1,   142,    -1,   144,    35,    36,
      -1,   148,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   143,   144,    35,    36,
      -1,   148,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,   144,    35,    36,
      -1,   148,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    35,    36,    -1,   143,   144,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    35,    36,
      -1,    -1,   144,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    35,    36,    -1,    -1,   144,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    35,
      36,    -1,   144,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    35,    36,    -1,   144,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      35,    36,    -1,    -1,   144,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    35,    36,    -1,   143,   144,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      35,    36,    -1,    -1,   144,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    35,    36,    -1,    -1,   144,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    60,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    70,    -1,    -1,   106,    -1,    -1,    76,
      -1,    -1,    79,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,   129,
      -1,    98,    47,    48,    49,   102,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,   144,    60,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,   129,    -1,    79,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,   144,    60,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    70,    -1,
      -1,   106,    -1,    -1,    76,    -1,    -1,    79,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,   129,    -1,    98,    47,    48,    49,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   144,
      60,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,   144,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  ParserImplementation::yystos_[] =
  {
         0,    35,    36,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    54,    60,    61,    64,    68,    70,    74,
      76,    79,    80,    81,    83,    88,    89,    90,    94,    95,
      98,   100,   102,   103,   106,   107,   108,   110,   111,   113,
     114,   115,   117,   122,   125,   129,   137,   139,   142,   144,
     148,   152,   153,   154,   155,   156,   165,   168,   173,   174,
     175,   176,   177,   178,   179,   180,   183,   184,   192,   198,
     199,   200,   201,   212,   213,   214,   215,   216,   221,   222,
     223,   230,   231,   232,   233,   234,   240,   244,   245,   246,
     249,   250,   263,   264,   265,   266,   267,   268,   269,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   290,   295,
      60,    76,    79,   144,   263,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   130,   194,   290,    47,   244,   245,
       3,   235,   236,   294,    79,   172,    79,   187,   189,   191,
     192,   194,   172,   173,    60,    79,   134,   135,   187,   249,
     262,    47,   123,    79,   172,   146,    47,   290,    79,    98,
     191,    49,    50,   290,   293,    47,   290,   144,   176,    79,
     187,   204,    47,   126,   144,   157,   144,   157,    79,   124,
     158,   159,   161,   171,   191,    47,   187,   172,   193,   294,
      47,   140,   287,    47,   145,   150,   173,   182,   241,     0,
     168,    47,    49,    50,   247,    49,    50,   247,    59,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      45,    46,   147,   289,    37,    38,    39,    35,    36,    32,
      33,    34,    25,    26,    27,    28,    29,    78,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   295,
      49,    79,    89,    98,   195,   243,   143,   143,   247,     3,
     148,   149,     3,   149,   287,   295,    47,   147,   196,   227,
       3,   295,   227,   295,   110,   187,    47,    79,    79,   108,
     139,   143,   263,   268,   270,   272,   274,   276,   278,   280,
     282,   284,   286,   288,   291,   292,    47,    47,    47,   173,
     290,   173,   128,   128,   128,   290,    79,   295,   290,   295,
      57,    72,   224,   225,   295,    47,   290,   287,   164,   167,
     170,   174,   164,   227,    79,     3,   118,   227,    79,   185,
     186,   191,   295,   173,     3,   131,    79,   131,   161,   191,
      79,    79,    79,   242,   243,   145,   173,   145,   124,   143,
     162,   248,   287,   290,    79,   240,   290,    79,   172,   287,
     265,   265,   265,   266,   266,   267,   267,   267,   268,   268,
     268,   268,   268,   268,   269,   269,   269,   269,   271,   273,
     275,   277,   287,   279,   287,   287,     3,   132,   146,   294,
      74,   237,   238,   171,   287,   189,   202,   171,    47,    47,
      79,   188,   190,   191,   140,   263,   288,   173,    28,    79,
     289,    25,    26,    27,    29,    78,    21,    22,    23,    24,
      20,    19,    18,    17,    15,    16,     3,   206,   108,   263,
     171,   171,   143,    79,    98,   181,   181,   181,   149,   143,
      47,   176,   225,   290,   143,   145,   170,   145,    79,   160,
     161,   191,   114,   115,   227,     3,   143,   196,   294,   143,
     143,    47,     3,   148,   146,    79,     3,   143,   149,   149,
      69,   136,   251,   252,   146,   149,    79,   243,    79,   191,
     149,   287,    47,    80,   238,   239,   143,    47,   143,   143,
     171,   147,   197,   228,     3,   208,    28,    79,   228,   290,
     290,   288,   268,   268,   268,   268,   268,   270,   270,   270,
     270,   272,   274,   276,   278,   288,   280,   288,   148,   190,
      28,   143,   143,   173,    50,   295,   295,   295,   144,   217,
      79,   205,   173,   227,   227,   144,   157,   144,   157,   186,
     173,    79,   131,   161,   191,   144,   173,   171,    79,   243,
     287,   162,   287,   144,    48,   244,   287,   146,   263,    47,
     149,   144,   290,   144,   144,   143,   288,   190,   148,   290,
     290,   143,   143,   146,   293,    28,   290,   144,   144,    66,
      79,    56,   218,   219,   229,   143,   143,   164,   164,   182,
     226,   143,    47,   146,    90,    93,    97,   133,   198,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   244,
      79,   191,    79,   290,   164,   203,   164,   164,   144,   293,
     143,   143,   173,   210,   288,   148,   290,   143,   164,   164,
     173,   290,   219,    63,   145,   220,   176,   173,   145,   145,
     145,   144,   171,   287,   262,   262,   262,    47,   145,   256,
     295,   290,   143,   145,   143,   145,   145,   164,   148,   173,
     211,   173,   293,   143,   173,   145,   145,   146,   146,   229,
     164,   143,   295,   295,   295,   171,   143,   295,   145,   293,
     173,   207,   173,   226,   226,   145,   145,   144,   143,   209,
     143,   164,   144,   143,   173,   145,    90,   163,   166,   169,
     174,   260,   261,   173,   145,   169
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
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,    41,   123,   125,    58,    61,    59,    93,
      64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   151,   152,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   158,   158,   158,
     159,   159,   159,   159,   160,   160,   161,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   169,
     169,   169,   170,   171,   171,   172,   172,   173,   173,   173,
     174,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   177,   178,   179,   180,   180,   180,   181,   181,
     181,   182,   182,   183,   183,   183,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   192,   193,   193,   193,   193,   193,   193,
     194,   195,   195,   195,   195,   195,   195,   196,   197,   198,
     199,   200,   200,   200,   202,   203,   201,   204,   205,   201,
     201,   206,   207,   201,   208,   209,   201,   201,   201,   210,
     201,   211,   201,   201,   201,   212,   213,   214,   215,   216,
     217,   217,   218,   218,   219,   220,   221,   222,   223,   223,
     223,   224,   225,   226,   226,   227,   227,   228,   228,   229,
     229,   230,   230,   230,   230,   230,   231,   232,   232,   233,
     233,   233,   233,   233,   233,   234,   234,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   239,   239,   240,   241,
     241,   241,   242,   242,   242,   242,   242,   242,   243,   243,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   245,   245,   246,   246,   246,   246,   247,   247,   248,
     248,   248,   248,   249,   250,   250,   251,   251,   252,   252,
     253,   253,   254,   255,   255,   256,   256,   256,   256,   256,
     256,   257,   258,   259,   260,   261,   262,   262,   262,   262,
     262,   262,   263,   263,   263,   263,   264,   264,   264,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   266,
     266,   266,   266,   267,   267,   267,   268,   268,   268,   268,
     269,   269,   269,   269,   269,   269,   269,   270,   270,   270,
     270,   270,   270,   271,   271,   271,   271,   271,   272,   272,
     272,   272,   272,   273,   273,   274,   274,   275,   275,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   283,   284,   284,   285,   285,   285,
     286,   286,   286,   287,   287,   288,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     290,   291,   291,   292,   292,   293,   293,   294,   294,   295,
     295
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     1,     7,     8,     8,     8,     1,     7,     4,
       7,     4,     5,     5,     2,     2,     2,     1,     1,     3,
       2,     2,     4,     4,     0,     1,     2,     2,     0,     1,
       0,     1,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     5,     3,     2,     5,     5,     5,     1,     1,
       3,     1,     2,     3,     3,     3,     5,     1,     3,     2,
       2,     1,     3,     1,     3,     2,     2,     2,     2,     1,
       1,     3,     3,     5,     2,     2,     2,     4,     4,     4,
       3,     1,     3,     3,     5,     3,     5,     2,     2,     1,
       2,     7,     5,     3,     0,     0,     9,     0,     0,     7,
       4,     0,     0,    11,     0,     0,    12,     7,     8,     0,
       8,     0,     9,     8,     9,     3,     3,     3,     5,     5,
       3,     5,     1,     2,     4,     3,     3,     3,     3,     3,
       4,     5,     2,     0,     1,     0,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     5,     6,     2,
       4,     1,     2,     1,     2,     6,     0,     4,     3,     1,
       3,     2,     3,     1,     7,     5,     3,     9,     1,     1,
       1,     3,     1,     1,     1,     4,     4,     3,     3,     3,
       3,     1,     2,     2,     2,     4,     3,     2,     3,     1,
       1,     3,     3,     7,     0,     1,     0,     2,     1,     1,
       0,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     7,     2,     3,     3,     3,     1,     2,     1,     7,
       7,     8,     1,     1,     1,     3,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     5,     1,     2,     2,
       1,     2,     2,     1,     3,     1,     3,     1,     1,     1,
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
  "JS_GRATER_EQUAL", "JS_IDENTIFIER", "JS_IF", "JS_IF_OPT",
  "JS_IMPLEMENTS", "JS_IMPORT", "JS_INT", "JS_INTERFACE", "JS_LONG",
  "JS_NATIVE", "JS_K_NULL", "JS_NUMERIC_LITERAL", "JS_PRIVATE",
  "JS_PACKAGE_RESERVED", "JS_PROTECTED", "JS_PUBLIC", "JS_REGEXP_LITERAL",
  "JS_RETURN", "JS_SHORT", "JS_STATIC", "JS_STRING_LITERAL", "JS_SUPER",
  "JS_SWITCH", "JS_SYNCHRONIZED", "JS_THIS", "JS_THROW", "JS_THROWS",
  "JS_TRANSIENT", "JS_TRUE", "JS_TRY", "JS_VAR", "JS_VOLATILE", "JS_WHILE",
  "JS_WITH", "JS_TERMINATE", "JS_LINE_BREAK", "JS_FUNCTION_GLYPH",
  "JS_FUNCTION_GLYPH_WITH_CONTEXT", "JS_FUNCTION_IDENTIFIER",
  "JS_PARAM_BEGIN", "JS_PARAM_END", "JS_DOBJECT_BEGIN", "JS_DOBJECT_END",
  "JS_FORMAL_PARAMETER_IDENT", "JS_LET", "JS_EACH", "JS_PARAMETER_REST",
  "JS_MODULE", "JS_EXP_CLOSURE_BEGIN", "JS_EXP_CLOSURE_END", "JS_FROM",
  "JS_DSTA_BEGIN", "JS_DSTO_BEGIN", "JS_DSTA_END", "JS_DSTO_END",
  "JS_CONSTRUCTOR", "JS_GET", "JS_SET", "JS_PROTOTYPE", "MOCHA_VERSIONOF",
  "JS_PROPERTY", "JS_YIELD", "JS_YIELD_SENTINEL", "EX_TOKEN_YIELD",
  "MOCHA_PRAGMA", "')'", "'{'", "'}'", "':'", "'='", "';'", "']'", "'@'",
  "$accept", "program", "version_statement", "function_declaration",
  "function_expression", "arrow_function_expression",
  "shorten_function_body", "formal_parameter_list_with_rest",
  "formal_parameter_list", "formal_parameter_rest__opt",
  "formal_parameter_rest", "arguments_spread", "constructor_function_body",
  "function_body", "source_elements", "source_elements_for_constructor",
  "source_elements_for_function", "source_element",
  "source_element_for_constructor", "source_element_for_function",
  "formal_parameter_list__opt", "identifier__opt", "statement",
  "statement_with_block", "statement_no_block", "block",
  "pragma_statement", "module_block", "export_statement",
  "import_statement", "import_expression", "statement_list",
  "variable_statement", "let_statement", "let_assignment_list",
  "let_assignment_expression", "variable_declaration_list",
  "variable_declaration_list_no_in", "variable_declaration",
  "variable_declaration_no_in", "destructuring_assignment_left_hand_side",
  "array_left_hand_side", "array_left_hand_side_list",
  "object_left_hand_side", "object_member_left_hand_side_list",
  "initialiser", "initialiser_no_in", "empty_statement",
  "expression_statement", "if_statement", "iteration_statement", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
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
  "class_initialiser", "class_adjective__opt", "inherit_declaration__opt",
  "inherit_declaration", "class_body__opt", "class_body",
  "class_element_list", "class_element", "constructor_definition",
  "prototype_property_definition", "class_property_definition",
  "instance_property_definition", "private_property_definition",
  "exportable_definition", "left_hand_side_expression",
  "postfix_expression", "unary_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "relational_expression_no_in", "equality_expression",
  "equality_expression_no_in", "bitwise_and_expression",
  "bitwise_and_expression_no_in", "bitwise_xor_expression",
  "bitwise_xor_expression_no_in", "bitwise_or_expression",
  "bitwise_or_expression_no_in", "logical_and_expression",
  "logical_and_expression_no_in", "logical_or_expression",
  "logical_or_expression_no_in", "conditional_expression",
  "conditional_expression_no_in", "yield_expression",
  "yield_expression_no_in", "assignment_expression",
  "assignment_expression_no_in", "assignment_operator", "expression",
  "expression_no_in", "expression_no_in__opt", "expression__opt",
  "elision__opt", "terminator", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       152,     0,    -1,   165,    -1,   137,    47,    79,   143,   144,
     226,   145,    -1,    76,    79,    47,   171,   143,   144,   164,
     145,    -1,    60,    79,    47,   171,   143,   144,   164,   145,
      -1,    76,   172,    47,   171,   143,   144,   164,   145,    -1,
     156,    -1,   117,   171,   118,   114,   144,   164,   145,    -1,
     114,   144,   164,   145,    -1,   117,   171,   118,   115,   144,
     164,   145,    -1,   115,   144,   164,   145,    -1,   117,   171,
     118,   114,   157,    -1,   117,   171,   118,   115,   157,    -1,
     115,   157,    -1,   114,   157,    -1,   126,   287,    -1,   159,
      -1,   161,    -1,   159,     3,   160,    -1,    79,   227,    -1,
     191,   227,    -1,   159,     3,    79,   227,    -1,   159,     3,
     191,   227,    -1,    -1,   161,    -1,   124,    79,    -1,   124,
      79,    -1,    -1,   166,    -1,    -1,   167,    -1,   168,    -1,
     165,   168,    -1,   169,    -1,   166,   169,    -1,   170,    -1,
     167,   170,    -1,   173,    -1,   174,    -1,   260,    -1,   261,
      -1,   174,    -1,    -1,   158,    -1,    -1,    79,    -1,   174,
      -1,   178,    -1,   179,    -1,   176,    -1,   175,    -1,   183,
      -1,   177,    -1,   154,    -1,   184,    -1,   198,    -1,   199,
      -1,   200,    -1,   201,    -1,   212,    -1,   213,    -1,   214,
      -1,   215,    -1,   221,    -1,   216,    -1,   222,    -1,   223,
      -1,   180,    -1,   153,    -1,   144,   145,    -1,   144,   182,
     145,    -1,   142,    47,    79,   143,   173,    -1,   125,   172,
     173,    -1,    68,   262,    -1,    83,    79,   128,   181,   295,
      -1,    83,   191,   128,   181,   295,    -1,    83,    98,   128,
     181,   295,    -1,    98,    -1,    79,    -1,   181,    50,    79,
      -1,   173,    -1,   182,   173,    -1,   108,   187,   295,    -1,
      60,   187,   295,    -1,   122,   187,   295,    -1,   122,    47,
     185,   143,   173,    -1,   186,    -1,   185,     3,   186,    -1,
      79,   227,    -1,   191,   196,    -1,   189,    -1,   187,     3,
     189,    -1,   190,    -1,   188,     3,   190,    -1,    79,   227,
      -1,   191,   227,    -1,    79,   228,    -1,   191,   228,    -1,
     192,    -1,   194,    -1,   129,   294,   131,    -1,   129,   193,
     131,    -1,   129,   193,     3,   294,   131,    -1,   294,    79,
      -1,   294,   161,    -1,   294,   191,    -1,   193,     3,   294,
      79,    -1,   193,     3,   294,   161,    -1,   193,     3,   294,
     191,    -1,   130,   195,   132,    -1,    79,    -1,   243,   146,
      79,    -1,   243,   146,   191,    -1,   195,     3,   243,   146,
      79,    -1,   195,     3,    79,    -1,   195,     3,   243,   146,
     191,    -1,   147,   287,    -1,   147,   288,    -1,   295,    -1,
     290,   295,    -1,    80,    47,   290,   143,   173,    66,   173,
      -1,    80,    47,   290,   143,   173,    -1,    81,   290,   173,
      -1,    -1,    -1,    64,   173,   110,   202,    47,   290,   203,
     143,   295,    -1,    -1,    -1,   110,   204,    47,   290,   205,
     143,   173,    -1,    74,    47,   143,   173,    -1,    -1,    -1,
      74,    47,   292,   206,   148,   293,   148,   293,   207,   143,
     173,    -1,    -1,    -1,    74,    47,   108,   188,   208,   148,
     293,   148,   293,   209,   143,   173,    -1,    74,    47,   263,
      28,   290,   143,   173,    -1,    74,    47,   108,   190,    28,
     290,   143,   173,    -1,    -1,    74,    47,   263,    79,   290,
     143,   210,   173,    -1,    -1,    74,    47,   108,   190,    79,
     290,   143,   211,   173,    -1,    74,   123,    47,   263,    28,
     290,   143,   173,    -1,    74,   123,    47,   108,   190,    28,
     290,   143,   173,    -1,    61,   172,   295,    -1,    54,   172,
     295,    -1,    95,   293,   295,    -1,   111,    47,   290,   143,
     173,    -1,   100,    47,   290,   143,   217,    -1,   144,   229,
     145,    -1,   144,   229,   220,   229,   145,    -1,   219,    -1,
     218,   219,    -1,    56,   290,   146,   226,    -1,    63,   146,
     226,    -1,    79,   146,   173,    -1,   103,   290,   295,    -1,
     107,   176,   224,    -1,   107,   176,   225,    -1,   107,   176,
     224,   225,    -1,    57,    47,    79,   143,   176,    -1,    72,
     176,    -1,    -1,   182,    -1,    -1,   196,    -1,    -1,   197,
      -1,    -1,   218,    -1,   231,    -1,   232,    -1,    89,    -1,
      98,    -1,    94,    -1,    88,    -1,   106,    -1,    70,    -1,
     102,    -1,    79,    -1,   230,    -1,   234,    -1,   240,    -1,
      47,   290,   143,    -1,    49,   294,   149,    -1,    49,   235,
     149,    -1,    49,   235,     3,   294,   149,    -1,    49,   235,
     148,   237,   239,   149,    -1,   294,   287,    -1,   235,     3,
     294,   287,    -1,     3,    -1,   236,     3,    -1,   238,    -1,
     237,   238,    -1,    74,    47,   263,    79,   290,   143,    -1,
      -1,    80,    47,   290,   143,    -1,   144,   241,   145,    -1,
     150,    -1,   150,   242,   148,    -1,   150,   242,    -1,   243,
     146,   287,    -1,    79,    -1,    79,    47,   171,   143,   144,
     164,   145,    -1,   242,     3,   243,   146,   287,    -1,   242,
       3,    79,    -1,   242,     3,    79,    47,   171,   143,   144,
     164,   145,    -1,    79,    -1,    98,    -1,    89,    -1,    49,
     287,   149,    -1,   233,    -1,   155,    -1,   249,    -1,   244,
      49,   290,   149,    -1,    90,    49,   290,   149,    -1,    90,
      50,    79,    -1,   244,    50,    79,    -1,   244,    50,   240,
      -1,    48,   244,   247,    -1,   244,    -1,    48,   245,    -1,
     244,   247,    -1,   246,   247,    -1,   246,    49,   290,   149,
      -1,   246,    50,    79,    -1,    47,   143,    -1,    47,   248,
     143,    -1,   287,    -1,   162,    -1,   248,     3,   287,    -1,
     248,     3,   162,    -1,   250,    59,   172,   251,   144,   253,
     145,    -1,    -1,    60,    -1,    -1,   252,   244,    -1,    69,
      -1,   136,    -1,    -1,   254,    -1,   255,    -1,   256,    -1,
     255,   256,    -1,   257,    -1,   198,    -1,   258,    -1,   259,
      -1,   260,    -1,   261,    -1,   133,    47,   171,   143,   144,
     163,   145,    -1,   262,   295,    -1,    97,   262,   295,    -1,
      93,   262,   295,    -1,    90,   262,   295,    -1,   187,    -1,
      60,   187,    -1,   249,    -1,    79,    47,   171,   143,   144,
     164,   145,    -1,   134,    79,    47,   143,   144,   164,   145,
      -1,   135,    79,    47,   171,   143,   144,   164,   145,    -1,
     245,    -1,   246,    -1,   192,    -1,    47,   194,   143,    -1,
     263,    -1,   263,    46,    -1,   263,    45,    -1,   264,    -1,
      42,   265,    -1,    43,   265,    -1,    44,   265,    -1,    46,
     265,    -1,    45,   265,    -1,    35,   265,    -1,    36,   265,
      -1,    41,   265,    -1,    40,   265,    -1,   265,    -1,   266,
      37,   265,    -1,   266,    38,   265,    -1,   266,    39,   265,
      -1,   266,    -1,   267,    35,   266,    -1,   267,    36,   266,
      -1,   267,    -1,   268,    34,   267,    -1,   268,    33,   267,
      -1,   268,    32,   267,    -1,   268,    -1,   269,    26,   268,
      -1,   269,    25,   268,    -1,   269,    29,   268,    -1,   269,
      78,   268,    -1,   269,    27,   268,    -1,   269,    28,   268,
      -1,   268,    -1,   270,    26,   268,    -1,   270,    25,   268,
      -1,   270,    29,   268,    -1,   270,    78,   268,    -1,   270,
      27,   268,    -1,   269,    -1,   271,    23,   269,    -1,   271,
      22,   269,    -1,   271,    24,   269,    -1,   271,    21,   269,
      -1,   270,    -1,   272,    23,   270,    -1,   272,    22,   270,
      -1,   272,    24,   270,    -1,   272,    21,   270,    -1,   271,
      -1,   273,    20,   271,    -1,   272,    -1,   274,    20,   272,
      -1,   273,    -1,   275,    19,   273,    -1,   274,    -1,   276,
      19,   274,    -1,   275,    -1,   277,    18,   275,    -1,   276,
      -1,   278,    18,   276,    -1,   277,    -1,   279,    17,   277,
      -1,   278,    -1,   280,    17,   278,    -1,   279,    -1,   281,
      16,   279,    -1,   280,    -1,   282,    16,   280,    -1,   281,
      -1,   281,    15,   287,   146,   287,    -1,   282,    -1,   282,
      15,   288,   146,   288,    -1,   283,    -1,   139,   140,    -1,
     139,   287,    -1,   284,    -1,   139,   140,    -1,   139,   288,
      -1,   285,    -1,   263,   289,   287,    -1,   286,    -1,   263,
     289,   288,    -1,   147,    -1,    10,    -1,    12,    -1,    11,
      -1,    14,    -1,     5,    -1,     7,    -1,     6,    -1,     4,
      -1,    13,    -1,     9,    -1,     8,    -1,   287,    -1,   290,
       3,   287,    -1,   288,    -1,   291,     3,   288,    -1,    -1,
     291,    -1,    -1,   290,    -1,    -1,   236,    -1,   148,    -1,
     113,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     5,    13,    22,    31,    40,    42,    50,
      55,    63,    68,    74,    80,    83,    86,    89,    91,    93,
      97,   100,   103,   108,   113,   114,   116,   119,   122,   123,
     125,   126,   128,   130,   133,   135,   138,   140,   143,   145,
     147,   149,   151,   153,   154,   156,   157,   159,   161,   163,
     165,   167,   169,   171,   173,   175,   177,   179,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   208,   212,   218,   222,   225,   231,   237,   243,   245,
     247,   251,   253,   256,   260,   264,   268,   274,   276,   280,
     283,   286,   288,   292,   294,   298,   301,   304,   307,   310,
     312,   314,   318,   322,   328,   331,   334,   337,   342,   347,
     352,   356,   358,   362,   366,   372,   376,   382,   385,   388,
     390,   393,   401,   407,   411,   412,   413,   423,   424,   425,
     433,   438,   439,   440,   452,   453,   454,   467,   475,   484,
     485,   494,   495,   505,   514,   524,   528,   532,   536,   542,
     548,   552,   558,   560,   563,   568,   572,   576,   580,   584,
     588,   593,   599,   602,   603,   605,   606,   608,   609,   611,
     612,   614,   616,   618,   620,   622,   624,   626,   628,   630,
     632,   634,   636,   638,   640,   644,   648,   652,   658,   665,
     668,   673,   675,   678,   680,   683,   690,   691,   696,   700,
     702,   706,   709,   713,   715,   723,   729,   733,   743,   745,
     747,   749,   753,   755,   757,   759,   764,   769,   773,   777,
     781,   785,   787,   790,   793,   796,   801,   805,   808,   812,
     814,   816,   820,   824,   832,   833,   835,   836,   839,   841,
     843,   844,   846,   848,   850,   853,   855,   857,   859,   861,
     863,   865,   873,   876,   880,   884,   888,   890,   893,   895,
     903,   911,   920,   922,   924,   926,   930,   932,   935,   938,
     940,   943,   946,   949,   952,   955,   958,   961,   964,   967,
     969,   973,   977,   981,   983,   987,   991,   993,   997,  1001,
    1005,  1007,  1011,  1015,  1019,  1023,  1027,  1031,  1033,  1037,
    1041,  1045,  1049,  1053,  1055,  1059,  1063,  1067,  1071,  1073,
    1077,  1081,  1085,  1089,  1091,  1095,  1097,  1101,  1103,  1107,
    1109,  1113,  1115,  1119,  1121,  1125,  1127,  1131,  1133,  1137,
    1139,  1143,  1145,  1149,  1151,  1157,  1159,  1165,  1167,  1170,
    1173,  1175,  1178,  1181,  1183,  1187,  1189,  1193,  1195,  1197,
    1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,  1217,
    1219,  1223,  1225,  1229,  1230,  1232,  1233,  1235,  1236,  1238,
    1240
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   376,   376,   387,   401,   418,   434,   443,   456,   465,
     474,   484,   494,   504,   515,   526,   540,   551,   552,   558,
     576,   592,   602,   612,   624,   625,   634,   651,   661,   662,
     666,   667,   671,   679,   690,   698,   709,   717,   727,   732,
     733,   734,   739,   743,   744,   751,   752,   761,   762,   767,
     775,   780,   784,   789,   790,   797,   801,   806,   811,   816,
     821,   826,   831,   836,   841,   846,   851,   856,   861,   865,
     872,   879,   890,   903,   916,   928,   945,   960,   980,   988,
     996,  1006,  1014,  1025,  1033,  1041,  1052,  1062,  1068,  1075,
    1083,  1094,  1102,  1112,  1118,  1126,  1134,  1145,  1153,  1165,
    1169,  1176,  1186,  1193,  1206,  1218,  1227,  1237,  1248,  1256,
    1267,  1278,  1288,  1301,  1311,  1322,  1331,  1342,  1346,  1350,
    1354,  1368,  1377,  1386,  1399,  1401,  1398,  1410,  1411,  1409,
    1419,  1425,  1426,  1425,  1438,  1439,  1438,  1451,  1462,  1475,
    1474,  1495,  1494,  1515,  1526,  1540,  1550,  1560,  1570,  1581,
    1592,  1596,  1605,  1611,  1619,  1630,  1641,  1654,  1664,  1673,
    1682,  1694,  1705,  1713,  1714,  1718,  1719,  1723,  1724,  1728,
    1729,  1733,  1734,  1735,  1742,  1749,  1759,  1769,  1776,  1786,
    1793,  1800,  1801,  1802,  1803,  1811,  1821,  1828,  1838,  1852,
    1862,  1873,  1874,  1879,  1885,  1893,  1906,  1907,  1916,  1930,
    1934,  1938,  1945,  1954,  1967,  1982,  1989,  2001,  2018,  2025,
    2032,  2039,  2049,  2053,  2057,  2062,  2075,  2087,  2102,  2117,
    2130,  2146,  2147,  2157,  2170,  2183,  2196,  2214,  2215,  2219,
    2225,  2231,  2236,  2244,  2256,  2257,  2262,  2263,  2279,  2280,
    2285,  2286,  2290,  2295,  2316,  2340,  2346,  2347,  2348,  2349,
    2350,  2355,  2370,  2380,  2390,  2399,  2409,  2410,  2417,  2418,
    2429,  2441,  2457,  2458,  2459,  2460,  2464,  2468,  2475,  2485,
    2486,  2493,  2500,  2507,  2514,  2521,  2528,  2535,  2542,  2552,
    2553,  2557,  2561,  2568,  2569,  2573,  2580,  2581,  2585,  2589,
    2596,  2597,  2601,  2605,  2609,  2613,  2617,  2624,  2625,  2629,
    2633,  2637,  2641,  2648,  2649,  2653,  2657,  2661,  2668,  2669,
    2673,  2677,  2681,  2688,  2689,  2696,  2697,  2704,  2705,  2712,
    2713,  2720,  2721,  2728,  2729,  2736,  2737,  2744,  2745,  2752,
    2753,  2760,  2761,  2768,  2769,  2778,  2779,  2788,  2789,  2794,
    2804,  2805,  2810,  2820,  2824,  2834,  2838,  2849,  2850,  2851,
    2852,  2853,  2854,  2855,  2856,  2857,  2858,  2859,  2860,  2864,
    2871,  2879,  2886,  2894,  2895,  2899,  2900,  2904,  2905,  2909,
    2910
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
      47,   143,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   146,   148,
      26,   147,    25,    15,   150,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   149,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,    18,   145,    41,     2,     2,     2,
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
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3344;
  const int ParserImplementation::yynnts_ = 145;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 199;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 151;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 380;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 6221 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2913 "grammar/grammar.yy"


void Replace( std::string& msg , const char* find , const char* rep ) {
  size_t pos = 0;
  while ( ( pos = msg.find( find , 0 ) ) != std::string::npos ) {
    msg.replace( pos , strlen( find ) , rep );
  }
}

void yy::ParserImplementation::error (const location_type& loc, const std::string& row_msg ) {
  std::string msg = row_msg;
  Replace( msg , "JS_ADD_LET" , "'+='" );
  Replace( msg , "JS_AND_LET" , "'&='" );
  Replace( msg , "JS_BOOLEAN" , "'boolean'" );
  Replace( msg , "JS_BREAK" , "'break'" );
  Replace( msg , "JS_BYTE" , "'byte'" );
  Replace( msg , "JS_CASE" , "'case'" );
  Replace( msg , "JS_CATCH" , "'catch'" );
  Replace( msg , "JS_CHAR" , "'char'" );
  Replace( msg , "JS_CLASS" , "'class'" );
  Replace( msg , "JS_CONST" , "'const'" );
  Replace( msg , "JS_CONTINUE" , "'continue'" );
  Replace( msg , "JS_DEBUGGER" , "'debugger'" );
  Replace( msg , "JS_DECREMENT" , "'--'" );
  Replace( msg , "JS_DEFAULT" , "'default'" );
  Replace( msg , "JS_DELETE" , "'delete'" );
  Replace( msg , "JS_DIV_LET" , "'/='" );
  Replace( msg , "JS_DO" , "'do'" );
  Replace( msg , "JS_DOUBLE" , "'double'" );
  Replace( msg , "JS_ELSE" , "'else'" );
  Replace( msg , "JS_ENUM" , "'enum'" );
  Replace( msg , "JS_EQ" , "'=='" );
  Replace( msg , "JS_EQUAL" , "'==='" );
  Replace( msg , "JS_EXPORT" , "'export'" );
  Replace( msg , "JS_EXTENDS" , "'extends'" );
  Replace( msg , "JS_FALSE" , "'false'" );
  Replace( msg , "JS_FINAL" , "'final'" );
  Replace( msg , "JS_FINALLY" , "'finally'" );
  Replace( msg , "JS_FLOAT" , "'float'" );
  Replace( msg , "JS_FOR" , "'for'" );
  Replace( msg , "JS_COMP_FOR" , "'for'" );
  Replace( msg , "JS_GOTO" , "'goto'" );
  Replace( msg , "JS_GRATER_EQUAL" , "'>='" );
  Replace( msg , "JS_IDENTIFIER" , "'identifier'" );
  Replace( msg , "JS_IF" , "'if'" );
  Replace( msg , "JS_IF_OPT" , "'if'" );
  Replace( msg , "JS_IMPLEMENTS" , "'implements'" );
  Replace( msg , "JS_IMPORT" , "'import'" );
  Replace( msg , "JS_IN" , "'in'" );
  Replace( msg , "JS_INCREMENT" , "'++'" );
  Replace( msg , "JS_INSTANCEOF" , "'instanceof'" );
  Replace( msg , "JS_INT" , "'int'" );
  Replace( msg , "JS_INTERFACE" , "'interface'" );
  Replace( msg , "JS_LESS_EQUAL" , "'<='" );
  Replace( msg , "JS_LOGICAL_AND" , "'&&'" );
  Replace( msg , "JS_LOGICAL_OR" , "'||'" );
  Replace( msg , "JS_LONG" , "'long'" );
  Replace( msg , "JS_MOD_LET" , "'/='" );
  Replace( msg , "JS_MUL_LET" , "'*='" );
  Replace( msg , "JS_NATIVE" , "'native'" );
  Replace( msg , "JS_NEW" , "'new'" );
  Replace( msg , "JS_NOT_EQ" , "'!='" );
  Replace( msg , "JS_NOT_EQUAL" , "'!=='" );
  Replace( msg , "JS_NOT_LET" , "'^='" );
  Replace( msg , "JS_K_NULL" , "'null'" );
  Replace( msg , "JS_NUMERIC_LITERAL" , "'number literal'" );
  Replace( msg , "JS_OR_LET" , "'|='" );
  Replace( msg , "JS_PRIVATE" , "'private'" );
  Replace( msg , "JS_PACKAGE_RESERVED" , "'package'" );
  Replace( msg , "JS_PROTECTED" , "'protected'" );
  Replace( msg , "JS_PUBLIC" , "'public'" );
  Replace( msg , "JS_REGEXP_LITERAL" , "'regexp literal'");
  Replace( msg , "JS_RETURN" , "'return'" );
  Replace( msg , "JS_SHIFT_LEFT" , "'<<'" );
  Replace( msg , "JS_SHIFT_LEFT_LET" , "'<<='" );
  Replace( msg , "JS_SHIFT_RIGHT" , "'>>'" );
  Replace( msg , "JS_SHIFT_RIGHT_LET" , "'>>='" );
  Replace( msg , "JS_SHORT" , "'short'" );
  Replace( msg , "JS_STATIC" , "'static'" );
  Replace( msg , "JS_STRING_LITERAL" , "'string literal'" );
  Replace( msg , "JS_SUB_LET" , "'=-'" );
  Replace( msg , "JS_SUPER" , "'super'" );
  Replace( msg , "JS_SWITCH" , "'switch'" );
  Replace( msg , "JS_SYNCHRONIZED" , "'synchronized'" );
  Replace( msg , "JS_THIS" , "'this'" );
  Replace( msg , "JS_THROW" , "'throw'" );
  Replace( msg , "JS_THROWS" , "'throws'" );
  Replace( msg , "JS_TRANSIENT" , "'transient'" );
  Replace( msg , "JS_TRUE" , "'try'" );
  Replace( msg , "JS_TRY" , "'try'" );
  Replace( msg , "JS_TYPEOF" , "'typeof'" );
  Replace( msg , "JS_U_SHIFT_RIGHT" , "'>>>'" );
  Replace( msg , "JS_U_SHIFT_RIGHT_LET" , "'>>>='" );
  Replace( msg , "JS_VAR" , "'var'" );
  Replace( msg , "JS_VOID" , "'void'" );
  Replace( msg , "JS_VOLATILE" , "'volatile'" );
  Replace( msg , "JS_WHILE" , "'while'" );
  Replace( msg , "JS_WITH" , "'with'" );
  Replace( msg , "JS_TERMINATE" , "';'" );
  Replace( msg , "JS_FUNCTION_GLYPH_WITH_CONTEXT" , "'=>'" );
  Replace( msg , "JS_FUNCTION_GLYPH" , "'->'" );
  Replace( msg , "JS_FUNCTION" , "'function'" );
  Replace( msg , "JS_PARAM_BEGIN" , "'('" );
  Replace( msg , "JS_PARAM_END" , "')'" );
  Replace( msg , "JS_LET" , "'let'" );
  Replace( msg , "JS_EACH" , "'each'" );
  Replace( msg , "JS_PARAMETER_REST" , "'...'" );
  Replace( msg , "JS_MODULE" , "'module'" );
  Replace( msg , "JS_FROM" , "'from'" );
  Replace( msg , "JS_CONSTRUCTOR" , "'constructor'" );
  Replace( msg , "JS_GET" , "'get'" );
  Replace( msg , "JS_SET" , "'set'" );
  Replace( msg , "JS_DSTA_BEGIN" , "'['" );
  Replace( msg , "JS_DSTO_BEGIN" , "'{'" );
  Replace( msg , "JS_DSTA_END" , "']'" );
  Replace( msg , "JS_DSTO_END" , "'}'" );
  Replace( msg , "MOCHA_PRAGMA" , "'@pragma'" );
  Replace( msg , "MOCHA_VERSIONOF" , "'@version'" );
  tracer->SyntaxError ( connector->GetLineNumber() , msg.c_str() );
}


