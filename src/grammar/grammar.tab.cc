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
#line 381 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(1) - (1)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 430 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 446 "grammar/grammar.yy"
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
#line 463 "grammar/grammar.yy"
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
#line 479 "grammar/grammar.yy"
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
#line 487 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 501 "grammar/grammar.yy"
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
#line 510 "grammar/grammar.yy"
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
#line 519 "grammar/grammar.yy"
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
#line 529 "grammar/grammar.yy"
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
#line 595 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 597 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 603 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 621 "grammar/grammar.yy"
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

  case 16:

/* Line 690 of lalr1.cc  */
#line 637 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 647 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 657 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].value_node) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 668 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 669 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 679 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 696 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 705 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 706 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 710 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 711 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 716 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 724 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 735 "grammar/grammar.yy"
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
#line 743 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 754 "grammar/grammar.yy"
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
#line 762 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 771 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 776 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 777 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 778 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 783 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 787 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 789 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 795 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 797 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 805 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 808 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 821 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 825 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 830 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 834 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 836 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 843 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 847 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 852 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 857 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 862 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 867 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 872 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 877 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 882 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 887 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 892 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 897 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 902 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 907 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 911 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 918 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 925 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 936 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    val->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    PragmaStmt* prg_stmt = ManagedHandle::Retain<PragmaStmt>();
    prg_stmt->Op( val );
    prg_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = prg_stmt;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 949 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 962 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 974 "grammar/grammar.yy"
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

  case 71:

/* Line 690 of lalr1.cc  */
#line 991 "grammar/grammar.yy"
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

  case 72:

/* Line 690 of lalr1.cc  */
#line 1006 "grammar/grammar.yy"
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

  case 73:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1042 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1052 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1060 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1079 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1087 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 1098 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1108 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1114 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1121 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1129 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1140 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1148 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1158 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1164 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1172 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1180 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1191 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1199 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1211 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1215 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1222 "grammar/grammar.yy"
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

  case 97:

/* Line 690 of lalr1.cc  */
#line 1232 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1239 "grammar/grammar.yy"
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

  case 99:

/* Line 690 of lalr1.cc  */
#line 1252 "grammar/grammar.yy"
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

  case 100:

/* Line 690 of lalr1.cc  */
#line 1264 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1273 "grammar/grammar.yy"
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

  case 102:

/* Line 690 of lalr1.cc  */
#line 1283 "grammar/grammar.yy"
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

  case 103:

/* Line 690 of lalr1.cc  */
#line 1294 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1302 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1313 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1324 "grammar/grammar.yy"
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

  case 107:

/* Line 690 of lalr1.cc  */
#line 1334 "grammar/grammar.yy"
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

  case 108:

/* Line 690 of lalr1.cc  */
#line 1347 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1357 "grammar/grammar.yy"
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

  case 110:

/* Line 690 of lalr1.cc  */
#line 1368 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1377 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1387 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1391 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1395 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1400 "grammar/grammar.yy"
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

  case 116:

/* Line 690 of lalr1.cc  */
#line 1414 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1423 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1432 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    stmt->Then( (yysemantic_stack_[(3) - (3)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1444 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1446 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1447 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(9) - (6)].expression) );
    iter->AddChild( (yysemantic_stack_[(9) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1456 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1457 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (4)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1465 "grammar/grammar.yy"
    {
    std::string error_msg = "Parse error. For loop condition must be non empty expression. for( <here> ){...}";
    error( yylloc , error_msg );
    YYABORT;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1470 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1471 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1472 "grammar/grammar.yy"
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

  case 129:

/* Line 690 of lalr1.cc  */
#line 1483 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1484 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1485 "grammar/grammar.yy"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1497 "grammar/grammar.yy"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1508 "grammar/grammar.yy"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1520 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(6) - (4)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "parse error unexpected ";
      error_msg += (yysemantic_stack_[(6) - (4)].info)->GetToken();
      error_msg += " expected of.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1529 "grammar/grammar.yy"
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

  case 136:

/* Line 690 of lalr1.cc  */
#line 1540 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(7) - (5)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "Parse error, unexpected ";
      error_msg += (yysemantic_stack_[(7) - (5)].info)->GetToken();
      error_msg += ". mismatched for loop condition separator. Expect 'in','of' or ';'.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar/grammar.yy"
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

  case 138:

/* Line 690 of lalr1.cc  */
#line 1561 "grammar/grammar.yy"
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

  case 139:

/* Line 690 of lalr1.cc  */
#line 1572 "grammar/grammar.yy"
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

  case 140:

/* Line 690 of lalr1.cc  */
#line 1586 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1596 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1616 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1627 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1638 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1651 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1657 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1665 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1676 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1687 "grammar/grammar.yy"
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

  case 152:

/* Line 690 of lalr1.cc  */
#line 1700 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1710 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1719 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1728 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1740 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1751 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1758 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1759 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1763 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1764 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1768 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1769 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1773 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1774 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1778 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1779 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1781 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1788 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1805 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1815 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1832 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1839 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1845 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1846 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1847 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1849 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1857 "grammar/grammar.yy"
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

  case 181:

/* Line 690 of lalr1.cc  */
#line 1867 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1874 "grammar/grammar.yy"
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

  case 183:

/* Line 690 of lalr1.cc  */
#line 1884 "grammar/grammar.yy"
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

  case 184:

/* Line 690 of lalr1.cc  */
#line 1898 "grammar/grammar.yy"
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

  case 185:

/* Line 690 of lalr1.cc  */
#line 1908 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1925 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1931 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1939 "grammar/grammar.yy"
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

  case 191:

/* Line 690 of lalr1.cc  */
#line 1951 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1953 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar/grammar.yy"
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

  case 194:

/* Line 690 of lalr1.cc  */
#line 1976 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1980 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1984 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1991 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2000 "grammar/grammar.yy"
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

  case 199:

/* Line 690 of lalr1.cc  */
#line 2013 "grammar/grammar.yy"
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

  case 200:

/* Line 690 of lalr1.cc  */
#line 2028 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2035 "grammar/grammar.yy"
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

  case 202:

/* Line 690 of lalr1.cc  */
#line 2047 "grammar/grammar.yy"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 2064 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2071 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2078 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2085 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kPrivateProperty ) );
    node->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    node->Node( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2095 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2099 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2103 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2108 "grammar/grammar.yy"
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

  case 211:

/* Line 690 of lalr1.cc  */
#line 2121 "grammar/grammar.yy"
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

  case 212:

/* Line 690 of lalr1.cc  */
#line 2133 "grammar/grammar.yy"
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

  case 213:

/* Line 690 of lalr1.cc  */
#line 2148 "grammar/grammar.yy"
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

  case 214:

/* Line 690 of lalr1.cc  */
#line 2163 "grammar/grammar.yy"
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

  case 215:

/* Line 690 of lalr1.cc  */
#line 2176 "grammar/grammar.yy"
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

  case 216:

/* Line 690 of lalr1.cc  */
#line 2191 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2193 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2203 "grammar/grammar.yy"
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

  case 219:

/* Line 690 of lalr1.cc  */
#line 2216 "grammar/grammar.yy"
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

  case 220:

/* Line 690 of lalr1.cc  */
#line 2229 "grammar/grammar.yy"
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

  case 221:

/* Line 690 of lalr1.cc  */
#line 2242 "grammar/grammar.yy"
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

  case 222:

/* Line 690 of lalr1.cc  */
#line 2259 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2260 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2265 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2271 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2277 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2282 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2296 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Line( (yysemantic_stack_[(7) - (2)].info)->GetLineNumber() );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2307 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2313 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2315 "grammar/grammar.yy"
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

  case 236:

/* Line 690 of lalr1.cc  */
#line 2330 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2331 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2336 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2337 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2341 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2347 "grammar/grammar.yy"
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

  case 242:

/* Line 690 of lalr1.cc  */
#line 2368 "grammar/grammar.yy"
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

  case 243:

/* Line 690 of lalr1.cc  */
#line 2392 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2397 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2398 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2399 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2400 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2401 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2407 "grammar/grammar.yy"
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

  case 250:

/* Line 690 of lalr1.cc  */
#line 2422 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2432 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2442 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2451 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2460 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2462 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2468 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2470 "grammar/grammar.yy"
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

  case 258:

/* Line 690 of lalr1.cc  */
#line 2481 "grammar/grammar.yy"
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

  case 259:

/* Line 690 of lalr1.cc  */
#line 2493 "grammar/grammar.yy"
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

  case 260:

/* Line 690 of lalr1.cc  */
#line 2508 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2509 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2510 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2511 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2512 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2517 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2521 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2528 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2537 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2539 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2546 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2553 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2560 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2567 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2574 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2581 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2588 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2595 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2604 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2606 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2610 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2614 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2620 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2622 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2626 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2632 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2634 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2642 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2648 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2650 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2654 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2658 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2662 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2666 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2670 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2676 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2678 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2682 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2686 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2690 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2694 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2700 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2702 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2706 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2710 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2714 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2720 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2722 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2726 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2730 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2734 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2740 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2742 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2748 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2750 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2756 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2758 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2764 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2766 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2772 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2774 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2780 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2782 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2788 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2790 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2796 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2798 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2804 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2806 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2812 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2814 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2820 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2822 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2830 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2832 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2840 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2842 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2847 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2856 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2858 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2863 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2873 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2877 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2887 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2891 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2901 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2902 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2903 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2904 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2905 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2906 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2907 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2908 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2909 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2910 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2911 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2912 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2917 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2924 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2932 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2939 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2946 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2947 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2951 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2952 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2956 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2957 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2961 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2962 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4398 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -487;
  const short int
  ParserImplementation::yypact_[] =
  {
      1660,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,
    2327,   251,    75,    -5,     5,    -5,  1660,   243,  -487,    29,
       4,   -63,    57,  2969,   178,  -487,  -487,   193,  -487,  2434,
    -487,    59,  -487,  2969,  -487,    -9,   152,  -487,    93,  -487,
       8,    82,   230,   161,    -5,    75,   179,  2541,   211,   985,
    -487,   260,  -487,  -487,  -487,  -487,  1322,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,   223,  -487,   332,
    -487,  -487,   216,   115,  -487,  -487,   462,   212,   481,   208,
     405,   259,   265,   279,   284,   239,  -487,  -487,  -487,    26,
    -487,  -487,    -5,  -487,   154,   249,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,   342,   165,    25,  2969,   388,
    -487,  -487,    16,   312,  1098,  -487,   -51,   -17,    34,  -487,
     169,  -487,  -487,   -51,   226,   152,    56,   245,   264,   335,
    -487,  -487,  1996,   303,   305,   309,  1660,  2969,   872,   257,
     262,   266,  2969,   288,   355,   -51,  2969,    26,  1434,   155,
     169,    34,   324,  2969,  1884,  1884,   169,   295,  -487,   384,
    -487,   278,   169,   187,    34,  1660,    32,   138,   322,  -487,
    -487,   325,  -487,   376,  -487,  1547,   263,  -487,  -487,    86,
    2220,  2969,    -2,  -487,  2969,   334,  -487,    -5,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  2969,  3183,  3183,  3183,  3183,  3183,  3183,  3183,
    3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,
    3183,  3183,  3183,  3183,  3183,  2969,  3183,  2969,  -487,  2969,
     270,  -487,  -487,    49,   272,  -487,  -487,  -487,    75,   349,
    -487,  -487,  -487,  -487,  -487,   230,  2969,  -487,  -487,   152,
    -487,  -487,  -487,  -487,   335,   230,   394,   412,   276,  2648,
    1660,   103,   481,   224,   426,   441,   453,   455,   458,   273,
    -487,  -487,  -487,   483,  -487,  3216,   230,   230,  -487,    41,
    -487,   -39,   -39,   -39,    22,  -487,  -487,    42,  -487,   450,
      -9,   434,  -487,  -487,  2969,    43,   372,  1884,  -487,  -487,
     373,  -487,  -487,   246,   214,  -487,   169,    45,  -487,   169,
    -487,  -487,    75,  -487,  -487,  -487,  -487,  -487,   377,   378,
      21,    28,   379,  -487,  -487,  -487,  -487,    -9,   442,  -487,
    -487,    46,  -487,    23,  -487,  -487,    24,  -487,     6,  -487,
    -487,  -487,  -487,   462,   462,   212,   212,   212,   481,   481,
     481,   481,   481,   481,   208,   208,   208,   208,   405,   259,
     265,   279,   380,   284,  -487,   375,   409,  -487,   285,  1210,
     477,   144,  -487,   385,  -487,  -487,   482,   386,   387,   230,
     390,   530,    72,   390,  -487,   115,  -487,  -487,  2969,  2969,
    3076,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,  3183,
    3183,  3183,  3183,  3183,  3076,  3183,  3076,   395,   276,   508,
     404,   408,  1660,  -487,  -487,    80,    80,    80,  -487,   414,
     461,  -487,  -487,   355,  1660,  -487,  -487,  -487,   169,  -487,
    -487,   169,   415,   416,  -487,   187,  1660,  -487,   269,   417,
    1660,   230,   413,  -487,  2969,  -487,  -487,  2755,  -487,  -487,
    -487,  -487,  -487,   418,   757,  2969,  -487,   270,   402,  -487,
    -487,  -487,  -487,  3278,   507,  -487,   420,   419,  2969,   422,
     423,   410,  3076,  -487,  -487,   276,   424,  2969,  2969,  -487,
      47,    51,  -487,   481,   481,   481,   481,   481,   224,   224,
     224,   224,   426,   441,   453,   455,   411,   458,  -487,  2108,
     538,  2969,   427,   429,   510,   498,  -487,  -487,  -487,   536,
    -487,   448,   449,  -487,  -487,  -487,  1884,  1884,  -487,  -487,
    -487,  -487,  -487,  -487,  1322,  -487,   460,    71,   459,  -487,
    -487,  -487,   735,   757,   297,  -487,   304,   524,  2969,  -487,
    1884,   355,  1884,  1884,   463,  -487,  -487,  2108,    52,    61,
    1660,  -487,  3076,   456,  2969,    64,  1884,  1884,  1660,  -487,
    2969,   536,  -487,    73,    -9,  1660,   465,   467,  1322,   468,
     464,   230,  2969,   243,   243,   243,   561,  -487,   469,  -487,
    1076,  -487,  -487,  -487,  -487,  -487,  -487,   -51,   388,  -487,
    -487,  2969,    68,   473,   478,   474,   484,  1884,   475,  1660,
    -487,  -487,  1660,  -487,  2862,    69,  1660,   485,   486,  -487,
      14,  -487,   487,  -487,   536,  -487,  -487,  -487,  -487,  -487,
    1884,   489,  -487,   -51,   -51,   -51,   230,  -487,  -487,  -487,
      70,  -487,  -487,   -51,  -487,  -487,   490,  2862,  -487,  1660,
    -487,  -487,  1660,  -487,  -487,  -487,  1322,  1322,   491,   492,
     494,  -487,  -487,  -487,   496,  -487,  -487,  -487,  -487,  -487,
     499,  -487,  -487,  -487,  -487,  -487,  1884,   497,   501,  1660,
     500,  1772,  1660,  -487,  -487,   282,   502,  1772,  -487,  -487,
    -487,  -487,  -487,  -487,  -487
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
       232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   366,    40,   233,    40,   232,   232,   173,     0,
      40,   175,     0,   232,     0,   171,   168,     0,   170,   364,
     169,     0,   174,   232,   172,     0,     0,   122,     0,   369,
       0,     0,    38,     0,    40,   366,     0,   232,     0,   232,
     368,     0,    64,    49,   208,     7,     2,    27,    33,    42,
      46,    45,    48,    43,    44,    63,    47,    50,   263,    51,
      52,    53,    54,    55,    56,    57,    58,    60,    59,    61,
      62,   176,   166,   167,   207,   177,   178,   216,   260,   261,
     262,   209,     0,   265,   268,   278,   282,   285,   289,   302,
     312,   316,   320,   324,   328,   332,   336,   342,   358,     0,
     114,   233,    40,   175,     0,   265,   274,   275,   277,   276,
     269,   270,   271,   273,   272,     0,     0,     0,   232,   216,
     217,   186,     0,   367,   232,    41,     0,   160,     0,    86,
     160,    94,    95,     0,     0,   233,   160,     0,     0,   254,
     256,    69,   232,     0,     0,     0,   232,   232,   232,     0,
       0,     0,   232,     0,   365,     0,   232,     0,   232,     0,
     160,     0,     0,   232,    25,    25,   160,     0,    39,    12,
      13,     0,   160,     0,     0,   232,     0,     0,     0,   337,
     338,     0,    65,   194,    76,   232,     0,     1,    28,     0,
     232,   232,     0,   218,   232,     0,   219,    40,   354,   351,
     353,   352,   357,   356,   347,   349,   348,   355,   350,   267,
     266,   346,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   115,   232,
     106,   205,   204,     0,     0,   264,   179,   215,   366,     0,
     181,   187,   180,   184,   141,    38,   232,   161,    90,     0,
      79,    91,   140,   119,   255,    38,     0,     0,     0,   232,
     232,   265,   296,   307,   314,   318,   322,   326,   330,   334,
     339,   344,   360,   363,   126,   232,    38,    38,   151,     0,
     118,     0,     0,     0,     0,   212,   142,     0,   152,     0,
       0,   153,   154,    78,   232,     0,     0,    26,    31,    37,
       0,    15,    21,    19,     0,    16,   160,     0,    82,     0,
      80,    68,   366,    97,    99,    96,   100,   101,     0,     0,
     198,   196,     0,    66,    77,   193,   230,   228,     0,   222,
     225,     0,   224,     0,   213,   214,     0,   221,   234,   343,
     279,   280,   281,   283,   284,   288,   287,   286,   291,   290,
     294,   295,   292,   293,   306,   304,   303,   305,   313,   317,
     321,   325,     0,   329,   359,     0,     0,   105,     0,   232,
       0,   191,   188,     0,   112,    87,     0,     0,     0,    38,
     162,   129,    88,   162,   340,   265,   341,   125,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,     0,     0,     0,
       0,     0,   232,    74,    73,     0,     0,     0,   211,     0,
       0,   157,   155,   123,   232,     9,    32,    11,   160,    14,
      20,   160,     0,     0,    84,     0,   232,    85,     0,     0,
     232,    38,     0,   195,   232,   229,    22,   232,   223,   210,
     220,   236,   237,     0,   232,   232,   206,   110,     0,   107,
     108,   182,   185,   232,     0,   189,     0,     0,   232,     0,
       0,     0,   232,   163,    92,     0,     0,   232,   232,    93,
       0,     0,   345,   298,   297,   301,   299,   300,   311,   309,
     308,   310,   315,   319,   323,   327,     0,   331,   361,   232,
       0,   232,     0,     0,   117,     0,    70,    72,    71,   164,
     144,     0,     0,   143,    17,    18,    25,    25,    83,    81,
     102,    98,   103,   104,   158,    67,     0,   201,     0,   197,
     227,   226,   232,   232,   235,   333,     0,     0,   232,   183,
      25,   120,    25,    25,     0,   113,    89,   232,     0,     0,
     232,   134,   232,     0,   232,     0,    25,    25,   232,    75,
     232,   165,   147,     0,     0,   232,     0,     0,   159,     0,
       0,    38,   232,   232,   232,   232,     0,   244,     0,   239,
     232,   241,   243,   245,   246,   247,   248,     0,     0,   109,
     111,   232,     0,     0,     0,     0,     0,    25,     0,   232,
     136,   132,   232,   335,   232,     0,   232,     0,     0,   116,
       0,   148,     0,   145,   164,   156,   124,     8,    10,     3,
      25,     0,   200,     0,     0,     0,    38,   231,   242,   250,
       0,   192,     5,     0,   257,   258,     0,   232,   133,   232,
     135,   127,   232,   138,     4,     6,   158,   158,     0,     0,
       0,   253,   252,   251,     0,   190,   121,   259,   130,   137,
       0,   139,   149,   150,   146,   199,    25,     0,     0,   232,
       0,    23,   232,   128,   202,   232,     0,    24,    29,    34,
      35,    36,   131,   249,    30
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -173,
     162,  -487,  -174,  -487,  -487,  -487,   574,   -61,   333,  -254,
       9,     0,   -73,  -487,   -27,  -487,  -487,  -487,  -487,   105,
      12,  -487,  -487,  -487,   196,    44,  -487,   383,  -349,   -19,
      -4,  -487,   643,  -487,   326,  -487,  -447,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,    76,  -487,  -487,
    -487,  -487,  -487,   343,  -214,  -125,   253,    30,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,   267,  -487,   466,  -487,
    -487,  -175,    -7,   649,  -487,    -1,  -487,  -487,   -14,  -487,
    -487,  -487,  -487,  -487,  -487,    63,  -487,  -487,  -487,  -468,
    -452,   -11,   476,  -487,    89,   290,   280,   366,   231,    77,
     425,   247,   428,   244,   430,   250,   431,   248,   432,   252,
    -487,  -487,  -487,  -487,  -487,  -487,   -45,  -267,   576,    37,
    -487,  -487,  -486,   -36,  -102
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,    51,    52,    53,    54,    55,   178,   179,   449,   180,
     350,   696,   316,    56,   697,   317,    57,   698,   318,   181,
     155,   194,    59,    60,    61,    62,    63,    64,    65,   435,
     588,    66,    67,   327,   328,   149,   401,   139,   402,   140,
      68,   186,   142,   253,   267,   493,    69,    70,    71,    72,
     396,   614,   172,   532,   427,   680,   496,   688,   622,   659,
      73,    74,    75,    76,    77,   530,   581,   582,   634,    78,
      79,    80,   311,   312,   589,   268,   494,   583,    81,    82,
      83,    84,    85,   132,   133,   391,   392,   486,    86,   196,
     341,   254,    87,    88,    89,   257,   351,    90,    91,    92,
     473,   474,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,    93,    94,    95,    96,    97,    98,    99,   283,
     100,   284,   101,   285,   102,   286,   103,   287,   104,   288,
     105,   289,   106,   290,   107,   291,   108,   292,   410,   109,
     293,   294,   165,   134,   110
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -365;
  const short int
  ParserImplementation::yytable_[] =
  {
        58,   320,   190,   150,   129,   161,   151,   248,   169,   187,
     141,   393,   406,   141,   336,   271,   144,   247,   342,   258,
     141,   397,   136,   182,   143,   247,   247,   247,   247,   247,
     265,   462,   141,   573,   264,   332,   270,   269,   141,   141,
     433,   272,   430,   431,   247,   247,   247,   127,   455,   467,
     247,   321,   386,   185,   247,   247,    58,   325,   138,   434,
     158,   195,    39,   306,   247,   308,   164,   247,   461,   313,
     167,   247,   247,   247,   135,   471,   152,   354,   131,   520,
     171,   618,   330,   154,   137,   156,   203,   184,   206,   263,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    50,
     497,   319,   319,   275,   157,   597,   166,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   591,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     525,   408,   266,   200,    45,   125,   632,   168,   661,    39,
     173,   141,   472,   502,   114,   491,   566,    39,   219,   220,
     450,   498,   153,   597,   174,   352,   298,   516,   300,   518,
     219,   220,   666,   333,   329,   127,   259,   260,   337,  -203,
     256,   678,   346,   438,   469,   470,    50,   359,   463,   141,
     195,   387,   409,   141,    50,   331,   432,   439,   444,   274,
     456,   468,   570,    39,   299,   344,   571,   619,   347,   304,
     382,   454,   384,   307,   385,   266,   620,   546,   183,   626,
     315,   478,   309,   651,   662,   675,   358,   334,   390,  -203,
     633,   394,   389,   700,   484,   565,   188,   310,   175,   700,
      50,   170,   168,   231,   232,   233,   234,   235,   353,   701,
     170,   356,   162,   163,   319,   701,   182,   226,   227,   411,
     412,   413,   221,   414,   245,   246,   182,   159,   191,   403,
     197,   141,   177,   199,   221,   141,   326,    45,   125,   335,
     200,   141,   201,   202,   141,   207,   160,   182,   182,   241,
     407,    45,   125,   441,   242,   542,   236,   548,   424,   425,
      45,   125,   141,   141,   219,   220,   458,   243,   128,    11,
      12,   244,   415,   145,   451,   623,   193,    45,   125,   176,
     255,   111,   360,   361,   362,   261,    45,   125,   266,   141,
     465,    18,   146,   534,   276,   448,   535,   112,   452,   453,
     113,   162,   163,   526,   527,   528,   273,   641,   269,    25,
      26,    27,   145,   277,   482,    28,   201,   202,   540,    30,
     295,   443,   296,    32,   177,   400,   297,    34,   247,    45,
     125,   146,   586,   587,   479,    40,    41,   305,    42,   480,
     177,   314,    45,   125,   322,    45,   125,   147,   148,   200,
     182,   204,   205,   609,   141,   301,   613,   323,   615,   616,
     302,   249,   674,   177,   303,   141,   324,   114,    45,   125,
     541,   338,   627,   628,   339,    45,   125,   436,   437,   403,
     345,    45,   125,   357,    45,   125,   147,   148,  -203,   549,
     388,   250,   551,   390,   141,   249,   237,   238,   239,   240,
     555,   251,   524,    45,   125,   200,   329,   201,   202,   543,
     252,   398,   182,   656,   533,   500,   501,   416,   417,   418,
     419,   141,   682,   683,   141,   340,   539,   141,   249,   399,
     545,   420,   249,   319,   319,   251,   669,   554,   374,   375,
     376,   377,   421,   422,   252,   423,   403,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   426,   319,   477,   319,
     319,   141,   547,   508,   509,   510,   511,   440,   251,   223,
     224,   225,   251,   319,   319,   649,   310,   252,   365,   366,
     367,   252,   690,   228,   229,   230,   363,   364,   282,   445,
     447,   466,   459,   460,   483,   561,   476,   464,   475,   488,
     487,   489,   490,   495,   568,   569,   521,   610,   150,   492,
     531,   671,   672,   673,   319,   519,   608,   642,   141,   522,
     556,   676,   141,   523,   558,   564,   164,   635,   575,   572,
     529,   536,   537,   544,   552,   560,   574,   319,   562,   563,
     621,   559,   182,   576,   567,   577,   578,   579,   629,   150,
     150,   150,   643,   644,   645,   636,   150,   141,   344,   141,
     141,   141,   580,   584,   585,   612,   141,   368,   369,   370,
     371,   372,   373,   611,   164,   590,   624,   592,   646,   617,
     640,   625,   637,   319,   638,   639,   647,   630,   699,   658,
     652,   654,   660,   653,   699,   657,   663,   182,   281,   550,
     198,   655,   664,   665,   670,   667,   704,   677,   684,   685,
     686,   687,   141,   691,   689,   282,   692,   694,   650,   703,
     446,   538,   395,   126,   442,   457,   499,   631,   485,   679,
     130,   164,   681,   648,   668,   513,   378,   512,   355,   222,
     379,   515,   514,   380,     0,   381,     0,   517,   383,     0,
       0,   150,     0,     0,   643,     0,     0,     0,     0,   693,
       0,   141,   702,     0,   164,     0,     0,     0,     0,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   429,     0,     0,     0,     0,   282,   503,   504,   505,
     506,   507,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   553,    12,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,   593,     0,    18,   594,     0,
       0,     0,   595,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    39,     0,
       0,    28,     0,     0,     0,    30,     0,     0,   282,    32,
       0,     0,     0,    34,    45,   125,     0,     0,   596,   147,
     148,    40,    41,     0,    42,   247,     0,     0,     0,     0,
       0,     0,  -238,     0,     0,    50,   405,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     405,   115,   405,   114,     0,     0,     0,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,    16,     0,   282,     0,
      17,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,   557,
      25,    26,    27,     0,     0,     0,    28,    29,   405,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,    48,     0,     0,     0,    49,     0,
       1,     2,    50,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,    14,    15,     0,   405,    16,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,    20,     0,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,     0,     0,
       0,    49,   192,     1,     2,    50,   145,   193,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,   593,     0,    18,   594,
       0,     0,     0,   595,   112,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    39,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,    45,   125,     0,     0,   596,
     147,   148,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,  -240,     0,     0,    50,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   114,     1,     2,     0,     0,   262,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   112,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,   114,     1,     2,     0,
       0,   481,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,  -232,    14,    15,     0,     0,    16,     0,     0,     0,
      17,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,    48,     0,     0,     0,    49,     1,
       2,     0,    50,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,    16,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,     0,     0,     0,
      49,   192,     1,     2,    50,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
       0,    16,     0,     0,     0,    17,     0,    18,     0,     0,
       0,    19,     0,    20,     0,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,    25,    26,    27,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,    43,
       0,     0,    44,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    47,     0,     0,    48,
       0,     0,     0,    49,   343,     1,     2,    50,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      14,    15,     0,     0,    16,     0,     0,     0,    17,     0,
      18,     0,     0,     0,    19,     0,    20,     0,     0,    21,
      22,    23,     0,    24,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,    29,     0,     0,    30,     0,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,     0,
       0,     0,    43,     0,     0,    44,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    47,
       0,     0,    48,     0,     0,     0,    49,     1,     2,     0,
      50,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,  -232,    14,    15,     0,     0,    16,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,   695,     0,     0,   594,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,    48,     0,     0,     0,    49,     1,
       2,     0,    50,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,  -232,    14,    15,     0,     0,    16,     0,
       0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,     0,     0,     0,
      49,     1,     2,     0,    50,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   112,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,   278,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
       0,   280,   114,     1,     2,     0,  -362,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   112,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   114,     1,     2,     0,  -364,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   112,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     1,     2,     0,   349,   114,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,   125,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     1,
       2,     0,     0,   114,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -232,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     112,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     1,     2,     0,     0,
     114,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,   112,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,   189,     0,     1,     2,     0,     0,   114,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   112,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   404,     0,
       1,     2,     0,     0,   114,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   112,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,   348,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     1,     2,     0,
       0,   114,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,   112,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,     0,     0,     0,
      30,     0,     0,     0,    32,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     1,     2,     0,  -364,   114,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   112,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     1,     2,     0,     0,   114,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   112,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     1,     2,
       0,     0,   114,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   112,
       0,     0,   113,    10,    11,    12,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,   111,    28,     0,     0,
       0,    30,     0,     0,     0,    32,    18,     0,     0,    34,
       0,     0,   112,     0,     0,   113,     0,    40,    41,     0,
      42,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,    45,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,   428,    10,    11,    12,     0,   114,
      40,    41,     0,    42,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,    45,     0,     0,    18,     0,
       0,     0,     0,     0,   112,     0,     0,   113,     0,     0,
       0,     0,   114,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         0,   175,    47,    17,    11,    24,    17,   109,    35,    45,
      14,   265,   279,    17,   187,   140,    16,     3,   193,     3,
      24,   275,    13,    42,    15,     3,     3,     3,     3,     3,
      47,     3,    36,   519,   136,     3,   138,     3,    42,    43,
      79,   143,   296,   297,     3,     3,     3,    10,     3,     3,
       3,   176,     3,    44,     3,     3,    56,   182,    14,    98,
      23,    49,   113,   165,     3,   167,    29,     3,    47,   171,
      33,     3,     3,     3,    79,    69,    47,    79,     3,   428,
      36,   567,   184,    79,    79,   148,    87,    43,    89,   134,
       1,     2,     3,     4,     5,     6,     7,     8,     9,   150,
      28,   174,   175,    47,    47,   552,    47,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    47,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      50,    28,   149,    47,   129,   130,    63,   146,   624,   113,
      47,   145,   136,   410,   146,   399,   495,   113,    45,    46,
     323,    79,   123,   600,   146,   200,   156,   424,   158,   426,
      45,    46,   148,   131,   183,   128,   150,   151,   187,   148,
     145,   657,   199,   151,   151,   151,   150,   222,   150,   183,
     168,   132,    79,   187,   150,   185,   145,   145,   145,   145,
     145,   145,   145,   113,   157,   195,   145,   145,   199,   162,
     245,   326,   247,   166,   249,   149,   145,   461,    47,   145,
     173,   386,    57,   145,   145,   145,   207,    79,    74,   148,
     147,   266,   258,   691,    80,   492,    47,    72,   146,   697,
     150,    79,   146,    25,    26,    27,    28,    29,   201,   691,
      79,   204,    49,    50,   317,   697,   265,    35,    36,    25,
      26,    27,   149,    29,    15,    16,   275,    79,    47,   278,
       0,   265,   124,    40,   149,   269,    79,   129,   130,   131,
      47,   275,    49,    50,   278,    59,    98,   296,   297,    20,
     280,   129,   130,   310,    19,   458,    78,   462,    15,    16,
     129,   130,   296,   297,    45,    46,   332,    18,    47,    48,
      49,    17,    78,    60,   323,   572,   152,   129,   130,    79,
     145,    60,   223,   224,   225,     3,   129,   130,   149,   323,
     347,    70,    79,   448,    79,    79,   451,    76,   114,   115,
      79,    49,    50,   435,   436,   437,   110,   591,     3,    88,
      89,    90,    60,    79,   389,    94,    49,    50,    79,    98,
      47,   314,    47,   102,   124,    79,    47,   106,     3,   129,
     130,    79,   536,   537,    79,   114,   115,    79,   117,   388,
     124,    47,   129,   130,    79,   129,   130,   134,   135,    47,
     399,    49,    50,    79,   388,   128,   560,     3,   562,   563,
     128,    49,   646,   124,   128,   399,   118,   146,   129,   130,
     131,    79,   576,   577,    79,   129,   130,   302,   303,   428,
     147,   129,   130,    79,   129,   130,   134,   135,   148,   464,
     148,    79,   467,    74,   428,    49,    21,    22,    23,    24,
     475,    89,   432,   129,   130,    47,   455,    49,    50,   458,
      98,    47,   461,   617,   444,   408,   409,    21,    22,    23,
      24,   455,   666,   667,   458,    79,   456,   461,    49,    47,
     460,    20,    49,   536,   537,    89,   640,   474,   237,   238,
     239,   240,    19,    18,    98,    17,   495,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     3,   560,    79,   562,
     563,   495,    79,   416,   417,   418,   419,    47,    89,    37,
      38,    39,    89,   576,   577,   607,    72,    98,   228,   229,
     230,    98,   686,    32,    33,    34,   226,   227,   152,   147,
     147,    79,   145,   145,    47,   488,   151,   148,   148,    47,
     145,   145,   145,     3,   497,   498,    28,   556,   552,   149,
      79,   643,   644,   645,   617,   150,   553,   592,   552,   145,
     148,   653,   556,   145,    47,   145,   519,   584,   521,   148,
     146,   146,   146,   146,   146,   146,    28,   640,   146,   146,
     570,   151,   591,   146,   150,   146,    66,    79,   578,   593,
     594,   595,   593,   594,   595,   585,   600,   591,   588,   593,
     594,   595,    56,   145,   145,   558,   600,   231,   232,   233,
     234,   235,   236,    79,   567,   145,   150,   148,    47,   146,
     146,   574,   147,   686,   147,   147,   147,   580,   691,   619,
     147,   147,   622,   145,   697,   150,   626,   646,   152,   467,
      56,   147,   147,   147,   145,   148,   697,   147,   147,   147,
     146,   145,   646,   146,   145,   279,   145,   147,   611,   147,
     317,   455,   269,    10,   311,   329,   403,   581,   391,   659,
      11,   624,   662,   600,   634,   421,   241,   420,   202,    93,
     242,   423,   422,   243,    -1,   244,    -1,   425,   246,    -1,
      -1,   695,    -1,    -1,   695,    -1,    -1,    -1,    -1,   689,
      -1,   695,   692,    -1,   657,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    70,    93,    -1,
      -1,    -1,    97,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,   113,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   492,   102,
      -1,    -1,    -1,   106,   129,   130,    -1,    -1,   133,   134,
     135,   114,   115,    -1,   117,     3,    -1,    -1,    -1,    -1,
      -1,    -1,   147,    -1,    -1,   150,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   146,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,   572,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,   483,
      88,    89,    90,    -1,    -1,    -1,    94,    95,   492,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,   146,    -1,
      35,    36,   150,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,   572,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,
      -1,   146,   147,    35,    36,   150,    60,   152,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    70,    93,
      -1,    -1,    -1,    97,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,   113,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,   129,   130,    -1,    -1,   133,
     134,   135,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,   150,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    35,    36,    -1,    -1,   151,
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
      -1,    -1,    -1,    -1,    -1,    -1,   146,    35,    36,    -1,
      -1,   151,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,   146,    35,
      36,    -1,   150,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,
     146,   147,    35,    36,   150,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,
     103,    -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,   146,   147,    35,    36,   150,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,
      -1,    -1,   142,    -1,    -1,    -1,   146,    35,    36,    -1,
     150,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,   146,    35,
      36,    -1,   150,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,
     146,    35,    36,    -1,   150,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,   108,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,   145,   146,    35,    36,    -1,   150,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    35,    36,    -1,   150,    -1,
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
      -1,    -1,    35,    36,    -1,   145,   146,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    35,
      36,    -1,    -1,   146,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    35,    36,    -1,    -1,
     146,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    35,    36,    -1,    -1,   146,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      35,    36,    -1,    -1,   146,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    35,    36,    -1,
      -1,   146,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    35,    36,    -1,   145,   146,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    35,    36,    -1,    -1,   146,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    35,    36,
      -1,    -1,   146,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    60,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    70,    -1,    -1,   106,
      -1,    -1,    76,    -1,    -1,    79,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,   129,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,   108,    47,    48,    49,    -1,   146,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146
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
     114,   115,   117,   122,   125,   129,   137,   139,   142,   146,
     150,   154,   155,   156,   157,   158,   166,   169,   174,   175,
     176,   177,   178,   179,   180,   181,   184,   185,   193,   199,
     200,   201,   202,   213,   214,   215,   216,   217,   222,   223,
     224,   231,   232,   233,   234,   235,   241,   245,   246,   247,
     250,   251,   252,   265,   266,   267,   268,   269,   270,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   289,   292,
     297,    60,    76,    79,   146,   265,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   130,   195,   292,    47,   245,
     246,     3,   236,   237,   296,    79,   173,    79,   188,   190,
     192,   193,   195,   173,   174,    60,    79,   134,   135,   188,
     251,   264,    47,   123,    79,   173,   148,    47,   292,    79,
      98,   192,    49,    50,   292,   295,    47,   292,   146,   177,
      79,   188,   205,    47,   146,   146,    79,   124,   159,   160,
     162,   172,   192,    47,   188,   173,   194,   296,    47,   140,
     289,    47,   147,   152,   174,   183,   242,     0,   169,    40,
      47,    49,    50,   248,    49,    50,   248,    59,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    45,
      46,   149,   291,    37,    38,    39,    35,    36,    32,    33,
      34,    25,    26,    27,    28,    29,    78,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   297,    49,
      79,    89,    98,   196,   244,   145,   145,   248,     3,   150,
     151,     3,   151,   289,   297,    47,   149,   197,   228,     3,
     297,   228,   297,   110,   188,    47,    79,    79,   108,   139,
     145,   265,   270,   272,   274,   276,   278,   280,   282,   284,
     286,   288,   290,   293,   294,    47,    47,    47,   174,   292,
     174,   128,   128,   128,   292,    79,   297,   292,   297,    57,
      72,   225,   226,   297,    47,   292,   165,   168,   171,   175,
     165,   228,    79,     3,   118,   228,    79,   186,   187,   192,
     297,   174,     3,   131,    79,   131,   162,   192,    79,    79,
      79,   243,   244,   147,   174,   147,   177,   248,   124,   145,
     163,   249,   289,   292,    79,   241,   292,    79,   173,   289,
     267,   267,   267,   268,   268,   269,   269,   269,   270,   270,
     270,   270,   270,   270,   271,   271,   271,   271,   273,   275,
     277,   279,   289,   281,   289,   289,     3,   132,   148,   296,
      74,   238,   239,   172,   289,   190,   203,   172,    47,    47,
      79,   189,   191,   192,   140,   265,   290,   174,    28,    79,
     291,    25,    26,    27,    29,    78,    21,    22,    23,    24,
      20,    19,    18,    17,    15,    16,     3,   207,   108,   265,
     172,   172,   145,    79,    98,   182,   182,   182,   151,   145,
      47,   177,   226,   292,   145,   147,   171,   147,    79,   161,
     162,   192,   114,   115,   228,     3,   145,   197,   296,   145,
     145,    47,     3,   150,   148,   177,    79,     3,   145,   151,
     151,    69,   136,   253,   254,   148,   151,    79,   244,    79,
     192,   151,   289,    47,    80,   239,   240,   145,    47,   145,
     145,   172,   149,   198,   229,     3,   209,    28,    79,   229,
     292,   292,   290,   270,   270,   270,   270,   270,   272,   272,
     272,   272,   274,   276,   278,   280,   290,   282,   290,   150,
     191,    28,   145,   145,   174,    50,   297,   297,   297,   146,
     218,    79,   206,   174,   228,   228,   146,   146,   187,   174,
      79,   131,   162,   192,   146,   174,   172,    79,   244,   289,
     163,   289,   146,    48,   245,   289,   148,   265,    47,   151,
     146,   292,   146,   146,   145,   290,   191,   150,   292,   292,
     145,   145,   148,   295,    28,   292,   146,   146,    66,    79,
      56,   219,   220,   230,   145,   145,   165,   165,   183,   227,
     145,    47,   148,    90,    93,    97,   133,   199,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   245,    79,
     192,    79,   292,   165,   204,   165,   165,   146,   295,   145,
     145,   174,   211,   290,   150,   292,   145,   165,   165,   174,
     292,   220,    63,   147,   221,   177,   174,   147,   147,   147,
     146,   172,   289,   264,   264,   264,    47,   147,   258,   297,
     292,   145,   147,   145,   147,   147,   165,   150,   174,   212,
     174,   295,   145,   174,   147,   147,   148,   148,   230,   165,
     145,   297,   297,   297,   172,   145,   297,   147,   295,   174,
     208,   174,   227,   227,   147,   147,   146,   145,   210,   145,
     165,   146,   145,   174,   147,    90,   164,   167,   170,   175,
     262,   263,   174,   147,   170
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
     378,   379,   380,   381,   382,    41,   123,   125,    58,    61,
      59,    93,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   153,   154,   155,   156,   156,   157,   157,   158,   158,
     158,   158,   159,   159,   159,   160,   160,   160,   160,   161,
     161,   162,   163,   164,   164,   165,   165,   166,   166,   167,
     167,   168,   168,   169,   170,   170,   170,   171,   172,   172,
     173,   173,   174,   174,   174,   175,   175,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   178,   179,   180,
     181,   181,   181,   182,   182,   182,   183,   183,   184,   184,
     184,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   193,   194,
     194,   194,   194,   194,   194,   195,   196,   196,   196,   196,
     196,   196,   197,   198,   199,   200,   201,   201,   201,   203,
     204,   202,   205,   206,   202,   202,   207,   208,   202,   209,
     210,   202,   202,   202,   211,   202,   212,   202,   202,   202,
     213,   214,   215,   216,   217,   218,   218,   219,   219,   220,
     221,   222,   223,   224,   224,   224,   225,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   232,   233,   233,   234,   234,   234,   234,   234,   234,
     235,   235,   235,   235,   236,   236,   237,   237,   238,   238,
     239,   240,   240,   241,   242,   242,   242,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   244,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   246,   246,   247,   247,
     247,   247,   248,   248,   249,   249,   249,   249,   250,   250,
     250,   251,   252,   252,   253,   253,   254,   254,   255,   255,
     256,   257,   257,   258,   258,   258,   258,   258,   258,   259,
     260,   261,   262,   263,   264,   264,   264,   264,   264,   264,
     265,   265,   265,   265,   265,   266,   266,   266,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   268,   268,
     268,   268,   269,   269,   269,   270,   270,   270,   270,   271,
     271,   271,   271,   271,   271,   271,   272,   272,   272,   272,
     272,   272,   273,   273,   273,   273,   273,   274,   274,   274,
     274,   274,   275,   275,   276,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   287,   288,
     288,   288,   289,   289,   290,   290,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   296,   296,   297,   297
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     1,     7,     8,     8,     8,     1,     7,     4,
       7,     4,     1,     1,     3,     2,     2,     4,     4,     0,
       1,     2,     2,     0,     1,     0,     1,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     3,     2,
       5,     5,     5,     1,     1,     3,     1,     2,     3,     3,
       3,     5,     1,     3,     2,     2,     1,     3,     1,     3,
       2,     2,     2,     2,     1,     1,     3,     3,     5,     2,
       2,     2,     4,     4,     4,     3,     1,     3,     3,     5,
       3,     5,     2,     2,     1,     2,     7,     5,     3,     0,
       0,     9,     0,     0,     7,     4,     0,     0,    11,     0,
       0,    12,     7,     8,     0,     8,     0,     9,     8,     9,
       3,     3,     3,     5,     5,     3,     5,     1,     2,     4,
       3,     3,     3,     3,     3,     4,     5,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     5,     6,     2,     4,     1,     2,     1,     2,
       6,     0,     4,     3,     1,     3,     2,     3,     1,     7,
       5,     3,     9,     1,     1,     1,     3,     1,     1,     1,
       4,     4,     3,     3,     3,     3,     1,     2,     2,     2,
       4,     3,     2,     3,     1,     1,     3,     3,     3,     4,
       3,     7,     0,     1,     0,     2,     1,     1,     0,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     7,
       2,     3,     3,     3,     1,     2,     1,     7,     7,     8,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     5,     1,     2,     2,     1,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     0,     1,     0,     1,     0,     1,     1,     1
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
  "MOCHA_PRAGMA", "MOCHA_NAMESPACE", "MOCHA_DEF", "')'", "'{'", "'}'",
  "':'", "'='", "';'", "']'", "'@'", "$accept", "program",
  "version_statement", "function_declaration", "function_expression",
  "arrow_function_expression", "formal_parameter_list_with_rest",
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
  "directive_call", "class_initialiser", "class_adjective__opt",
  "inherit_declaration__opt", "inherit_declaration", "class_body__opt",
  "class_body", "class_element_list", "class_element",
  "constructor_definition", "prototype_property_definition",
  "class_property_definition", "instance_property_definition",
  "private_property_definition", "exportable_definition",
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
  "yield_expression", "yield_expression_no_in", "assignment_expression",
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
       154,     0,    -1,   166,    -1,   137,    47,    79,   145,   146,
     227,   147,    -1,    76,    79,    47,   172,   145,   146,   165,
     147,    -1,    60,    79,    47,   172,   145,   146,   165,   147,
      -1,    76,   173,    47,   172,   145,   146,   165,   147,    -1,
     158,    -1,   117,   172,   118,   114,   146,   165,   147,    -1,
     114,   146,   165,   147,    -1,   117,   172,   118,   115,   146,
     165,   147,    -1,   115,   146,   165,   147,    -1,   160,    -1,
     162,    -1,   160,     3,   161,    -1,    79,   228,    -1,   192,
     228,    -1,   160,     3,    79,   228,    -1,   160,     3,   192,
     228,    -1,    -1,   162,    -1,   124,    79,    -1,   124,    79,
      -1,    -1,   167,    -1,    -1,   168,    -1,   169,    -1,   166,
     169,    -1,   170,    -1,   167,   170,    -1,   171,    -1,   168,
     171,    -1,   174,    -1,   175,    -1,   262,    -1,   263,    -1,
     175,    -1,    -1,   159,    -1,    -1,    79,    -1,   175,    -1,
     179,    -1,   180,    -1,   177,    -1,   176,    -1,   184,    -1,
     178,    -1,   156,    -1,   185,    -1,   199,    -1,   200,    -1,
     201,    -1,   202,    -1,   213,    -1,   214,    -1,   215,    -1,
     216,    -1,   222,    -1,   217,    -1,   223,    -1,   224,    -1,
     181,    -1,   155,    -1,   146,   147,    -1,   146,   183,   147,
      -1,   142,    47,    79,   145,   174,    -1,   125,   173,   174,
      -1,    68,   264,    -1,    83,    79,   128,   182,   297,    -1,
      83,   192,   128,   182,   297,    -1,    83,    98,   128,   182,
     297,    -1,    98,    -1,    79,    -1,   182,    50,    79,    -1,
     174,    -1,   183,   174,    -1,   108,   188,   297,    -1,    60,
     188,   297,    -1,   122,   188,   297,    -1,   122,    47,   186,
     145,   174,    -1,   187,    -1,   186,     3,   187,    -1,    79,
     228,    -1,   192,   197,    -1,   190,    -1,   188,     3,   190,
      -1,   191,    -1,   189,     3,   191,    -1,    79,   228,    -1,
     192,   228,    -1,    79,   229,    -1,   192,   229,    -1,   193,
      -1,   195,    -1,   129,   296,   131,    -1,   129,   194,   131,
      -1,   129,   194,     3,   296,   131,    -1,   296,    79,    -1,
     296,   162,    -1,   296,   192,    -1,   194,     3,   296,    79,
      -1,   194,     3,   296,   162,    -1,   194,     3,   296,   192,
      -1,   130,   196,   132,    -1,    79,    -1,   244,   148,    79,
      -1,   244,   148,   192,    -1,   196,     3,   244,   148,    79,
      -1,   196,     3,    79,    -1,   196,     3,   244,   148,   192,
      -1,   149,   289,    -1,   149,   290,    -1,   297,    -1,   292,
     297,    -1,    80,    47,   292,   145,   174,    66,   174,    -1,
      80,    47,   292,   145,   174,    -1,    81,   292,   174,    -1,
      -1,    -1,    64,   174,   110,   203,    47,   292,   204,   145,
     297,    -1,    -1,    -1,   110,   205,    47,   292,   206,   145,
     174,    -1,    74,    47,   145,   174,    -1,    -1,    -1,    74,
      47,   294,   207,   150,   295,   150,   295,   208,   145,   174,
      -1,    -1,    -1,    74,    47,   108,   189,   209,   150,   295,
     150,   295,   210,   145,   174,    -1,    74,    47,   265,    28,
     292,   145,   174,    -1,    74,    47,   108,   191,    28,   292,
     145,   174,    -1,    -1,    74,    47,   265,    79,   292,   145,
     211,   174,    -1,    -1,    74,    47,   108,   191,    79,   292,
     145,   212,   174,    -1,    74,   123,    47,   265,    28,   292,
     145,   174,    -1,    74,   123,    47,   108,   191,    28,   292,
     145,   174,    -1,    61,   173,   297,    -1,    54,   173,   297,
      -1,    95,   295,   297,    -1,   111,    47,   292,   145,   174,
      -1,   100,    47,   292,   145,   218,    -1,   146,   230,   147,
      -1,   146,   230,   221,   230,   147,    -1,   220,    -1,   219,
     220,    -1,    56,   292,   148,   227,    -1,    63,   148,   227,
      -1,    79,   148,   174,    -1,   103,   292,   297,    -1,   107,
     177,   225,    -1,   107,   177,   226,    -1,   107,   177,   225,
     226,    -1,    57,    47,    79,   145,   177,    -1,    72,   177,
      -1,    -1,   183,    -1,    -1,   197,    -1,    -1,   198,    -1,
      -1,   219,    -1,   232,    -1,   233,    -1,    89,    -1,    98,
      -1,    94,    -1,    88,    -1,   106,    -1,    70,    -1,   102,
      -1,    79,    -1,   231,    -1,   235,    -1,   241,    -1,    47,
     292,   145,    -1,    49,   296,   151,    -1,    49,   236,   151,
      -1,    49,   236,     3,   296,   151,    -1,    49,   236,   150,
     238,   240,   151,    -1,   296,   289,    -1,   236,     3,   296,
     289,    -1,     3,    -1,   237,     3,    -1,   239,    -1,   238,
     239,    -1,    74,    47,   265,    79,   292,   145,    -1,    -1,
      80,    47,   292,   145,    -1,   146,   242,   147,    -1,   152,
      -1,   152,   243,   150,    -1,   152,   243,    -1,   244,   148,
     289,    -1,    79,    -1,    79,    47,   172,   145,   146,   165,
     147,    -1,   243,     3,   244,   148,   289,    -1,   243,     3,
      79,    -1,   243,     3,    79,    47,   172,   145,   146,   165,
     147,    -1,    79,    -1,    98,    -1,    89,    -1,    49,   289,
     151,    -1,   234,    -1,   157,    -1,   251,    -1,   245,    49,
     292,   151,    -1,    90,    49,   292,   151,    -1,    90,    50,
      79,    -1,   245,    50,    79,    -1,   245,    50,   241,    -1,
      48,   245,   248,    -1,   245,    -1,    48,   246,    -1,   245,
     248,    -1,   247,   248,    -1,   247,    49,   292,   151,    -1,
     247,    50,    79,    -1,    47,   145,    -1,    47,   249,   145,
      -1,   289,    -1,   163,    -1,   249,     3,   289,    -1,   249,
       3,   163,    -1,   245,    40,   248,    -1,   245,    40,   248,
     177,    -1,   245,    40,   177,    -1,   252,    59,   173,   253,
     146,   255,   147,    -1,    -1,    60,    -1,    -1,   254,   245,
      -1,    69,    -1,   136,    -1,    -1,   256,    -1,   257,    -1,
     258,    -1,   257,   258,    -1,   259,    -1,   199,    -1,   260,
      -1,   261,    -1,   262,    -1,   263,    -1,   133,    47,   172,
     145,   146,   164,   147,    -1,   264,   297,    -1,    97,   264,
     297,    -1,    93,   264,   297,    -1,    90,   264,   297,    -1,
     188,    -1,    60,   188,    -1,   251,    -1,    79,    47,   172,
     145,   146,   165,   147,    -1,   134,    79,    47,   145,   146,
     165,   147,    -1,   135,    79,    47,   172,   145,   146,   165,
     147,    -1,   246,    -1,   247,    -1,   250,    -1,   193,    -1,
      47,   195,   145,    -1,   265,    -1,   265,    46,    -1,   265,
      45,    -1,   266,    -1,    42,   267,    -1,    43,   267,    -1,
      44,   267,    -1,    46,   267,    -1,    45,   267,    -1,    35,
     267,    -1,    36,   267,    -1,    41,   267,    -1,    40,   267,
      -1,   267,    -1,   268,    37,   267,    -1,   268,    38,   267,
      -1,   268,    39,   267,    -1,   268,    -1,   269,    35,   268,
      -1,   269,    36,   268,    -1,   269,    -1,   270,    34,   269,
      -1,   270,    33,   269,    -1,   270,    32,   269,    -1,   270,
      -1,   271,    26,   270,    -1,   271,    25,   270,    -1,   271,
      29,   270,    -1,   271,    78,   270,    -1,   271,    27,   270,
      -1,   271,    28,   270,    -1,   270,    -1,   272,    26,   270,
      -1,   272,    25,   270,    -1,   272,    29,   270,    -1,   272,
      78,   270,    -1,   272,    27,   270,    -1,   271,    -1,   273,
      23,   271,    -1,   273,    22,   271,    -1,   273,    24,   271,
      -1,   273,    21,   271,    -1,   272,    -1,   274,    23,   272,
      -1,   274,    22,   272,    -1,   274,    24,   272,    -1,   274,
      21,   272,    -1,   273,    -1,   275,    20,   273,    -1,   274,
      -1,   276,    20,   274,    -1,   275,    -1,   277,    19,   275,
      -1,   276,    -1,   278,    19,   276,    -1,   277,    -1,   279,
      18,   277,    -1,   278,    -1,   280,    18,   278,    -1,   279,
      -1,   281,    17,   279,    -1,   280,    -1,   282,    17,   280,
      -1,   281,    -1,   283,    16,   281,    -1,   282,    -1,   284,
      16,   282,    -1,   283,    -1,   283,    15,   289,   148,   289,
      -1,   284,    -1,   284,    15,   290,   148,   290,    -1,   285,
      -1,   139,   140,    -1,   139,   289,    -1,   286,    -1,   139,
     140,    -1,   139,   290,    -1,   287,    -1,   265,   291,   289,
      -1,   288,    -1,   265,   291,   290,    -1,   149,    -1,    10,
      -1,    12,    -1,    11,    -1,    14,    -1,     5,    -1,     7,
      -1,     6,    -1,     4,    -1,    13,    -1,     9,    -1,     8,
      -1,   289,    -1,   292,     3,   289,    -1,   290,    -1,   293,
       3,   290,    -1,    -1,   293,    -1,    -1,   292,    -1,    -1,
     237,    -1,   150,    -1,   113,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     5,    13,    22,    31,    40,    42,    50,
      55,    63,    68,    70,    72,    76,    79,    82,    87,    92,
      93,    95,    98,   101,   102,   104,   105,   107,   109,   112,
     114,   117,   119,   122,   124,   126,   128,   130,   132,   133,
     135,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   187,   191,   197,   201,
     204,   210,   216,   222,   224,   226,   230,   232,   235,   239,
     243,   247,   253,   255,   259,   262,   265,   267,   271,   273,
     277,   280,   283,   286,   289,   291,   293,   297,   301,   307,
     310,   313,   316,   321,   326,   331,   335,   337,   341,   345,
     351,   355,   361,   364,   367,   369,   372,   380,   386,   390,
     391,   392,   402,   403,   404,   412,   417,   418,   419,   431,
     432,   433,   446,   454,   463,   464,   473,   474,   484,   493,
     503,   507,   511,   515,   521,   527,   531,   537,   539,   542,
     547,   551,   555,   559,   563,   567,   572,   578,   581,   582,
     584,   585,   587,   588,   590,   591,   593,   595,   597,   599,
     601,   603,   605,   607,   609,   611,   613,   615,   617,   619,
     623,   627,   631,   637,   644,   647,   652,   654,   657,   659,
     662,   669,   670,   675,   679,   681,   685,   688,   692,   694,
     702,   708,   712,   722,   724,   726,   728,   732,   734,   736,
     738,   743,   748,   752,   756,   760,   764,   766,   769,   772,
     775,   780,   784,   787,   791,   793,   795,   799,   803,   807,
     812,   816,   824,   825,   827,   828,   831,   833,   835,   836,
     838,   840,   842,   845,   847,   849,   851,   853,   855,   857,
     865,   868,   872,   876,   880,   882,   885,   887,   895,   903,
     912,   914,   916,   918,   920,   924,   926,   929,   932,   934,
     937,   940,   943,   946,   949,   952,   955,   958,   961,   963,
     967,   971,   975,   977,   981,   985,   987,   991,   995,   999,
    1001,  1005,  1009,  1013,  1017,  1021,  1025,  1027,  1031,  1035,
    1039,  1043,  1047,  1049,  1053,  1057,  1061,  1065,  1067,  1071,
    1075,  1079,  1083,  1085,  1089,  1091,  1095,  1097,  1101,  1103,
    1107,  1109,  1113,  1115,  1119,  1121,  1125,  1127,  1131,  1133,
    1137,  1139,  1143,  1145,  1151,  1153,  1159,  1161,  1164,  1167,
    1169,  1172,  1175,  1177,  1181,  1183,  1187,  1189,  1191,  1193,
    1195,  1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,
    1217,  1219,  1223,  1224,  1226,  1227,  1229,  1230,  1232,  1234
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   380,   380,   429,   445,   462,   478,   487,   500,   509,
     518,   528,   595,   596,   602,   620,   636,   646,   656,   668,
     669,   678,   695,   705,   706,   710,   711,   715,   723,   734,
     742,   753,   761,   771,   776,   777,   778,   783,   787,   788,
     795,   796,   805,   807,   812,   820,   825,   829,   834,   835,
     842,   846,   851,   856,   861,   866,   871,   876,   881,   886,
     891,   896,   901,   906,   910,   917,   924,   935,   948,   961,
     973,   990,  1005,  1025,  1033,  1041,  1051,  1059,  1070,  1078,
    1086,  1097,  1107,  1113,  1120,  1128,  1139,  1147,  1157,  1163,
    1171,  1179,  1190,  1198,  1210,  1214,  1221,  1231,  1238,  1251,
    1263,  1272,  1282,  1293,  1301,  1312,  1323,  1333,  1346,  1356,
    1367,  1376,  1387,  1391,  1395,  1399,  1413,  1422,  1431,  1444,
    1446,  1443,  1455,  1456,  1454,  1464,  1470,  1471,  1470,  1483,
    1484,  1483,  1496,  1507,  1520,  1519,  1540,  1539,  1560,  1571,
    1585,  1595,  1605,  1615,  1626,  1637,  1641,  1650,  1656,  1664,
    1675,  1686,  1699,  1709,  1718,  1727,  1739,  1750,  1758,  1759,
    1763,  1764,  1768,  1769,  1773,  1774,  1778,  1779,  1780,  1787,
    1794,  1804,  1814,  1821,  1831,  1838,  1845,  1846,  1847,  1848,
    1856,  1866,  1873,  1883,  1897,  1907,  1918,  1919,  1924,  1930,
    1938,  1951,  1952,  1961,  1975,  1979,  1983,  1990,  1999,  2012,
    2027,  2034,  2046,  2063,  2070,  2077,  2084,  2094,  2098,  2102,
    2107,  2120,  2132,  2147,  2162,  2175,  2191,  2192,  2202,  2215,
    2228,  2241,  2259,  2260,  2264,  2270,  2276,  2281,  2289,  2290,
    2291,  2295,  2307,  2308,  2313,  2314,  2330,  2331,  2336,  2337,
    2341,  2346,  2367,  2391,  2397,  2398,  2399,  2400,  2401,  2406,
    2421,  2431,  2441,  2450,  2460,  2461,  2468,  2469,  2480,  2492,
    2508,  2509,  2510,  2511,  2512,  2516,  2520,  2527,  2537,  2538,
    2545,  2552,  2559,  2566,  2573,  2580,  2587,  2594,  2604,  2605,
    2609,  2613,  2620,  2621,  2625,  2632,  2633,  2637,  2641,  2648,
    2649,  2653,  2657,  2661,  2665,  2669,  2676,  2677,  2681,  2685,
    2689,  2693,  2700,  2701,  2705,  2709,  2713,  2720,  2721,  2725,
    2729,  2733,  2740,  2741,  2748,  2749,  2756,  2757,  2764,  2765,
    2772,  2773,  2780,  2781,  2788,  2789,  2796,  2797,  2804,  2805,
    2812,  2813,  2820,  2821,  2830,  2831,  2840,  2841,  2846,  2856,
    2857,  2862,  2872,  2876,  2886,  2890,  2901,  2902,  2903,  2904,
    2905,  2906,  2907,  2908,  2909,  2910,  2911,  2912,  2916,  2923,
    2931,  2938,  2946,  2947,  2951,  2952,  2956,  2957,  2961,  2962
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
      47,   145,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   148,   150,
      26,   149,    25,    15,   152,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   151,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   146,    18,   147,    41,     2,     2,     2,
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
     142,   143,   144
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3424;
  const int ParserImplementation::yynnts_ = 145;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 197;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 153;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 382;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 6168 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2965 "grammar/grammar.yy"


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


