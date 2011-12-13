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
#line 367 "grammar/grammar.yy"
    {int yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 368 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 379 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 389 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 390 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 395 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 397 "grammar/grammar.yy"
    {
    ClassExpandar* expandar;
    if ( (yysemantic_stack_[(2) - (1)].info)->GetType() == yy::ParserImplementation::token::JS_PROTOTYPE ) {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kPrototype ) );
    } else {
      expandar = ManagedHandle::Retain( new ClassExpandar( ClassExpandar::kExtends ) );
    }
    (yyval.ast) = expandar;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 410 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 411 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 416 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 417 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 421 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 427 "grammar/grammar.yy"
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

  case 15:

/* Line 690 of lalr1.cc  */
#line 448 "grammar/grammar.yy"
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

  case 16:

/* Line 690 of lalr1.cc  */
#line 472 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 477 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 478 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 479 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 480 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 481 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 487 "grammar/grammar.yy"
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

  case 23:

/* Line 690 of lalr1.cc  */
#line 502 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 512 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 522 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 531 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 540 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 542 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 547 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 549 "grammar/grammar.yy"
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

  case 31:

/* Line 690 of lalr1.cc  */
#line 560 "grammar/grammar.yy"
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

  case 32:

/* Line 690 of lalr1.cc  */
#line 572 "grammar/grammar.yy"
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

  case 33:

/* Line 690 of lalr1.cc  */
#line 587 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 600 "grammar/grammar.yy"
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

  case 35:

/* Line 690 of lalr1.cc  */
#line 617 "grammar/grammar.yy"
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

  case 36:

/* Line 690 of lalr1.cc  */
#line 633 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    fn->Name( (yysemantic_stack_[(8) - (2)].ast) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 642 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 656 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 665 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 674 "grammar/grammar.yy"
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

  case 41:

/* Line 690 of lalr1.cc  */
#line 684 "grammar/grammar.yy"
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

  case 42:

/* Line 690 of lalr1.cc  */
#line 694 "grammar/grammar.yy"
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

  case 43:

/* Line 690 of lalr1.cc  */
#line 704 "grammar/grammar.yy"
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

  case 44:

/* Line 690 of lalr1.cc  */
#line 715 "grammar/grammar.yy"
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

  case 45:

/* Line 690 of lalr1.cc  */
#line 726 "grammar/grammar.yy"
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

  case 46:

/* Line 690 of lalr1.cc  */
#line 740 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 750 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 752 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 770 "grammar/grammar.yy"
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

  case 50:

/* Line 690 of lalr1.cc  */
#line 786 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(2) - (1)].value_node)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    list->AddChild( (yysemantic_stack_[(2) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 794 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 804 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(4) - (3)].value_node)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 814 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 824 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 841 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 850 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 851 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 855 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 856 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 861 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 869 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 880 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 888 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 899 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 907 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 916 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 918 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 928 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 930 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 936 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 937 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 942 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 944 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 953 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 955 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 961 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 963 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 971 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 973 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 978 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 986 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 990 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 995 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1000 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1004 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1009 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1014 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1019 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1024 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1029 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1034 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1039 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1044 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1049 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1054 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1059 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1064 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1068 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1082 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1093 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1106 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1118 "grammar/grammar.yy"
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

  case 105:

/* Line 690 of lalr1.cc  */
#line 1135 "grammar/grammar.yy"
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

  case 106:

/* Line 690 of lalr1.cc  */
#line 1150 "grammar/grammar.yy"
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

  case 107:

/* Line 690 of lalr1.cc  */
#line 1170 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1178 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1186 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1196 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1204 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1215 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1223 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1231 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1242 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1252 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1258 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1265 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1273 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1284 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1292 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1302 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1308 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1316 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1324 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1334 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1342 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1357 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1364 "grammar/grammar.yy"
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

  case 131:

/* Line 690 of lalr1.cc  */
#line 1374 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar/grammar.yy"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1394 "grammar/grammar.yy"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1406 "grammar/grammar.yy"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1416 "grammar/grammar.yy"
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

  case 136:

/* Line 690 of lalr1.cc  */
#line 1426 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1437 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1448 "grammar/grammar.yy"
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

  case 139:

/* Line 690 of lalr1.cc  */
#line 1458 "grammar/grammar.yy"
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

  case 140:

/* Line 690 of lalr1.cc  */
#line 1470 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1480 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1490 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1498 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1508 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1512 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1516 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1521 "grammar/grammar.yy"
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

  case 148:

/* Line 690 of lalr1.cc  */
#line 1535 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1544 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1553 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    stmt->Then( (yysemantic_stack_[(3) - (3)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1565 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1573 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1581 "grammar/grammar.yy"
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

  case 154:

/* Line 690 of lalr1.cc  */
#line 1593 "grammar/grammar.yy"
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

  case 155:

/* Line 690 of lalr1.cc  */
#line 1605 "grammar/grammar.yy"
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

  case 156:

/* Line 690 of lalr1.cc  */
#line 1616 "grammar/grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1628 "grammar/grammar.yy"
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

  case 158:

/* Line 690 of lalr1.cc  */
#line 1639 "grammar/grammar.yy"
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

  case 159:

/* Line 690 of lalr1.cc  */
#line 1653 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1673 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1683 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1705 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1709 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1718 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1724 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1732 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1754 "grammar/grammar.yy"
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

  case 171:

/* Line 690 of lalr1.cc  */
#line 1767 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1777 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1786 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1807 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1818 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1825 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1826 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1830 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1831 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1835 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1836 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1840 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1841 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1845 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1846 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1848 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1855 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1862 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1872 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1889 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1899 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1906 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1912 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1913 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1916 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar/grammar.yy"
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

  case 200:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1941 "grammar/grammar.yy"
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

  case 202:

/* Line 690 of lalr1.cc  */
#line 1951 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar/grammar.yy"
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

  case 204:

/* Line 690 of lalr1.cc  */
#line 1972 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1989 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1997 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2004 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2013 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2015 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2024 "grammar/grammar.yy"
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

  case 213:

/* Line 690 of lalr1.cc  */
#line 2038 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2042 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2049 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2068 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2075 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2082 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2092 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2096 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2100 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2105 "grammar/grammar.yy"
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

  case 224:

/* Line 690 of lalr1.cc  */
#line 2118 "grammar/grammar.yy"
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

  case 225:

/* Line 690 of lalr1.cc  */
#line 2130 "grammar/grammar.yy"
    {
    int depth = 0;
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    ValueNode* ident = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
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

  case 226:

/* Line 690 of lalr1.cc  */
#line 2145 "grammar/grammar.yy"
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

  case 227:

/* Line 690 of lalr1.cc  */
#line 2160 "grammar/grammar.yy"
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

  case 228:

/* Line 690 of lalr1.cc  */
#line 2175 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2177 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2187 "grammar/grammar.yy"
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2200 "grammar/grammar.yy"
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

  case 232:

/* Line 690 of lalr1.cc  */
#line 2213 "grammar/grammar.yy"
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

  case 233:

/* Line 690 of lalr1.cc  */
#line 2226 "grammar/grammar.yy"
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

  case 234:

/* Line 690 of lalr1.cc  */
#line 2243 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2244 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2249 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2255 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2261 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2266 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2273 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2274 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2275 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2276 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2281 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2285 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2292 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2301 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2303 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2310 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2317 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2324 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2331 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2338 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2345 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2352 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2359 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2368 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2370 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2374 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2378 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2384 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2386 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2390 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2396 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2398 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2402 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2406 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2412 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2414 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2418 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2422 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2426 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2430 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2434 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2440 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2442 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2446 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2450 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2454 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2458 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2464 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2466 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2470 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2474 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2478 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2484 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2486 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2490 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2494 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2498 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2504 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2506 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2512 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2514 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2520 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2522 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2528 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2530 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2536 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2538 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2544 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2546 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2552 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2554 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2560 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2562 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2568 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2570 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2576 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2578 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2584 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2594 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2596 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2605 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2609 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2619 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2623 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2633 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2634 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2635 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2636 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2637 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2639 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2640 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2641 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2642 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2643 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2644 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2649 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2656 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2664 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2671 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2678 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2679 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2683 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2684 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2688 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2689 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2693 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2694 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4116 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -569;
  const short int
  ParserImplementation::yypact_[] =
  {
      -569,    94,  1685,  -569,  3020,  3020,  3020,  3020,  3020,  3020,
    3020,  3020,  3020,  2723,  3138,   117,    36,   148,    36,  1789,
     211,  -569,     5,    70,   -16,   132,  3020,   327,  -569,  -569,
      90,  -569,  2822,  -569,   185,  -569,  3020,  -569,    99,   224,
     205,   218,  -569,   -22,    50,   268,   157,    36,   117,   221,
    1057,  -569,  -569,   189,  -569,  -569,  -569,  -569,  1162,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,   212,  -569,
     354,   405,  -569,  -569,   237,    72,   272,   273,   437,   236,
     239,   262,   279,    96,  -569,  -569,    39,  -569,  -569,    36,
    -569,     3,   139,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,    16,   149,    26,  3020,   212,  -569,  -569,    10,
     307,   847,  -569,   -37,   -10,    43,  -569,   223,  -569,  -569,
     -37,   224,   257,   224,    -4,   291,   294,  -569,  -569,   371,
    2313,   333,   339,   375,  1789,  3020,   674,   295,   302,   309,
    3020,   347,   432,   -37,  3020,    39,  1266,    46,   223,    43,
    3020,  3020,  3020,  2103,  -569,  2103,  -569,   223,  -569,   436,
     322,   223,   298,    43,  1789,    37,   229,   362,   -16,   305,
     308,  -569,  -569,  1371,   324,    28,   325,    36,  -569,  2521,
    3020,   369,  -569,  3020,   386,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,
    3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,
    3020,  3020,  3020,  3020,  3020,  3020,  -569,  -569,  -569,  -569,
     336,    33,   337,  -569,  -569,  -569,   117,    40,  -569,   335,
     401,  -569,  -569,  -569,  -569,   268,  3020,  -569,  -569,   224,
    -569,  -569,  -569,   435,   371,   268,   447,   455,   313,   201,
     272,   213,   465,   463,   484,   486,   488,   186,  -569,  -569,
     503,   364,  3053,   268,   268,  -569,    35,  -569,    38,    38,
      38,    20,  -569,  -569,    41,  -569,   461,    99,   438,  -569,
    -569,    47,    51,  -569,  -569,   370,  2208,  -569,  -569,   372,
    -569,   209,   130,  -569,   223,    55,  -569,   223,  -569,  -569,
     117,  -569,  -569,  -569,  -569,   374,  -569,  -569,  -569,     3,
    -569,  3020,   -14,   433,  -569,  -569,    56,  -569,    23,  -569,
      25,  -569,  -569,  -569,  -569,  -569,   237,   237,    72,    72,
      72,   272,   272,   272,   272,   272,   272,   273,   273,   273,
     273,   437,   236,   239,   262,   376,   279,  -569,   263,  -569,
     323,   952,  3105,   468,  -569,   469,  -569,   378,  -569,  -569,
    3020,   380,   381,   268,   384,    29,   495,   384,  3020,  3020,
    3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,  3020,
    3020,  3020,  3020,  3020,  3020,  3020,  2417,   313,   499,   388,
     390,  1789,  -569,  -569,    87,    87,    87,  -569,   393,   453,
    -569,  -569,  1789,  1789,  -569,  -569,  -569,   223,   454,  -569,
    -569,   223,    52,   105,  -569,   298,  1789,  -569,   265,   397,
     395,  -569,  -569,  -569,   399,  3190,  -569,  2921,  -569,  -569,
    -569,  3020,   336,   398,  -569,  -569,  -569,  -569,   510,  3105,
    3020,   403,    57,   404,   408,   410,  3020,  -569,  -569,   313,
    2417,  3020,  -569,    58,   405,  -569,   272,   272,   272,   272,
     272,   213,   213,   213,   213,   465,   463,   484,   486,   402,
     488,  -569,   411,   520,  3020,   417,   426,   501,   490,  -569,
    -569,  -569,   514,  -569,   431,  -569,  -569,  -569,  -569,  -569,
    2103,  -569,  2103,  -569,  -569,  -569,  -569,  -569,  -569,  1476,
    3020,   528,  3190,   243,  -569,  -569,  -569,   355,  3020,   547,
      59,  2103,   -37,  2103,  2103,   439,  -569,  -569,   440,    76,
    1789,  3020,  2622,  3020,    77,  2103,  2103,  1789,  -569,  3020,
     514,  -569,    12,    99,   441,   442,  1581,   443,  -569,   211,
     211,   211,   529,   445,  -569,   700,  -569,  -569,  -569,  -569,
    -569,  -569,   -37,  -569,   212,  -569,  -569,    78,  3020,  -569,
     446,  -569,   448,   450,  2103,  2622,  1789,  -569,  -569,   451,
      82,  1789,   457,   458,  -569,    32,  -569,   449,  -569,   514,
    -569,  -569,  -569,  -569,   -37,   -37,   -37,   268,  -569,  -569,
    -569,  -569,    85,  -569,  -569,  -569,   459,   452,  -569,  1789,
    1789,  -569,  -569,  -569,  1581,  1581,   460,  -569,  -569,  -569,
     466,  -569,  -569,  1789,  -569,  -569,  -569,  -569,  -569,   456,
    -569,  1893,   200,  -569,  -569,  -569,   462,  1998,  -569,  -569,
    -569,  -569
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     5,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   339,    77,     6,    77,     5,
       5,   192,     0,    77,   194,     0,     5,     0,   190,   187,
       0,   189,   337,   188,     0,   193,     5,   191,     0,     0,
       0,     0,   342,     0,     0,    75,     0,    77,   339,     0,
       5,   341,   222,     0,    99,    68,   221,    37,     3,    61,
      67,    79,    83,    82,    80,    81,    98,    84,    85,   242,
      86,    87,    88,    89,    90,    91,    92,    93,    95,    94,
      96,    97,   195,   185,   186,   220,   196,   197,   228,   240,
     241,   244,   247,   257,   261,   264,   268,   281,   291,   295,
     299,   303,   307,   311,   315,   331,     0,   146,     6,    77,
     194,   213,   244,   253,   254,   256,   255,   248,   249,   250,
     252,   251,     0,     0,     0,     5,   228,   229,   205,     0,
     340,     5,    78,     0,   179,     0,   120,   179,   128,   129,
       0,     6,     0,     6,   179,     0,     0,    29,   103,    27,
       5,     0,     0,     0,     5,     5,     5,     0,     0,     0,
       5,     0,   338,     0,     5,     0,     5,     0,   179,     0,
       5,     5,     5,     5,    45,     5,    44,   179,    76,    47,
       0,   179,     0,     0,     5,     0,     0,     0,   194,   187,
     188,   100,   110,     5,     0,     0,     0,    77,    62,     5,
       5,     0,   230,     5,     0,   231,   327,   324,   326,   325,
     330,   329,   320,   322,   321,   328,   323,   246,   245,   319,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,   147,   217,   219,   218,
     138,     0,     0,   243,   198,   227,   339,     0,   200,     0,
     210,   206,   199,   203,   160,    75,     5,   180,   124,     0,
     113,   125,   159,     0,    28,    75,     0,     0,     0,   244,
     275,   286,   293,   297,   301,   305,   309,   313,   317,   333,
     336,     0,     5,    75,    75,   170,     0,   150,     0,     0,
       0,     0,   225,   161,     0,   171,     0,     0,   172,   173,
     112,     0,     0,    46,    74,     0,     5,    65,    73,     0,
      49,    53,     0,    50,   179,     0,   116,     0,   114,   102,
     339,   131,   133,   130,   134,     0,   101,   111,   212,     0,
     214,     5,     7,     0,   234,   237,     0,   236,     0,   226,
       0,   233,   316,   258,   259,   260,   262,   263,   267,   266,
     265,   270,   269,   273,   274,   271,   272,   285,   283,   282,
     284,   292,   296,   300,   304,     0,   308,   332,     0,   137,
       0,     5,     5,     0,   202,     0,   207,     0,   144,   121,
       5,     0,     0,    75,   181,     0,   122,   181,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     0,     0,     0,
       0,     5,   108,   107,     0,     0,     0,   224,     0,     0,
     176,   174,     5,     5,    39,    66,    41,   179,     0,    48,
      54,   179,     0,     0,   118,     0,     5,   119,     0,     0,
       0,   215,     9,    10,     0,     5,    56,     5,   235,   223,
     232,     5,   142,     0,   139,   140,   201,   204,     0,     5,
       5,     0,     0,     0,     0,     0,     5,   182,   126,     0,
       5,     5,   127,     0,   244,   318,   277,   276,   280,   278,
     279,   290,   288,   287,   289,   294,   298,   302,   306,     0,
     310,   334,     0,     0,     5,     0,     0,   149,     0,   104,
     106,   105,   183,   163,     0,   152,   162,    51,    55,    52,
       5,    42,     5,    43,   117,   115,   135,   132,   136,     5,
       5,     5,     5,     8,   239,   238,   312,     0,     5,     0,
       0,     5,     0,     5,     5,     0,   145,   123,     0,     0,
       5,     5,     5,     5,     0,     5,     5,     5,   109,     5,
     184,   166,     0,     0,     0,     0,   178,     0,   216,     5,
       5,     5,     0,     0,    12,     5,    14,    16,    18,    19,
      20,    21,     0,    17,     0,   141,   143,     0,     5,   211,
       0,   151,     0,     0,     5,     5,     5,   155,   314,     0,
       0,     5,     0,     0,   148,     0,   167,     0,   164,   183,
     175,    38,    40,    33,     0,     0,     0,    75,     4,    15,
      23,   208,     0,    35,    30,    31,     0,     0,   156,     5,
       5,   157,    34,    36,   177,   177,     0,    26,    25,    24,
       0,   209,    32,     5,   153,   158,   168,   169,   165,     0,
     154,     5,     5,    71,    72,    70,     0,     5,    63,    69,
      22,    64
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -569,  -569,  -569,    -9,  -569,  -569,  -569,  -569,  -569,  -569,
       4,  -569,  -569,  -569,  -568,  -527,   -18,  -569,    -2,  -569,
    -569,   -35,  -569,  -569,  -569,  -569,   121,  -569,  -165,  -569,
    -569,  -569,   545,   -71,   288,  -245,     6,    -1,  -156,  -569,
     -34,  -569,  -569,  -569,    63,    60,  -569,  -569,  -569,   163,
      80,  -569,   340,  -318,   -24,   -12,  -569,   597,  -569,   284,
    -569,  -466,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,    53,  -569,  -569,  -569,  -569,  -569,   304,  -303,
    -130,   222,    11,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -106,    -8,   601,  -569,
      45,  -569,   464,  -569,    62,   112,   122,   -87,   255,    91,
     383,   215,   387,   216,   389,   220,   391,   225,   392,   230,
    -569,  -569,  -569,  -569,   -86,  -374,   541,    64,  -569,  -569,
    -402,   -36,   -42
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    52,    53,   454,   455,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,    54,   314,    56,
      57,   174,   178,   179,   439,   440,   345,   656,   315,    58,
     657,   316,    59,   658,   317,   180,   153,   192,    61,    62,
      63,    64,    65,    66,   424,   566,    67,    68,   325,   326,
     149,   395,   136,   396,   137,    69,   185,   139,   251,   267,
     477,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     513,   560,   561,   609,    79,    80,    81,   308,   309,   567,
     268,   478,   562,    82,    83,    84,    85,    86,   129,   130,
     259,   260,   386,    87,   194,   195,   196,    88,    89,    90,
     255,   346,    91,    92,    93,    94,    95,    96,    97,   281,
      98,   282,    99,   283,   100,   284,   101,   285,   102,   286,
     103,   287,   104,   288,   105,   289,   399,   106,   290,   291,
     163,   131,   107
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -338;
  const short int
  ParserImplementation::yytable_[] =
  {
        55,    60,   148,   159,   167,   138,   126,   271,   138,   176,
     319,   147,   186,   256,   502,   138,   252,   318,   142,   318,
     387,   181,   133,   245,   140,   485,   245,   138,   245,   245,
     391,   339,   479,   138,   138,   245,   378,   265,   245,   499,
     330,   501,   245,   275,   245,   263,   269,   320,   419,   420,
     245,   323,   150,   184,   245,   452,    55,    60,   445,   457,
     245,   245,   245,   280,   246,   583,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   607,    42,   124,   548,   245,
     245,   245,   247,   653,   257,   245,   313,   382,   245,   653,
     156,   264,   248,   270,     3,   250,   162,   135,   272,   503,
     165,   249,   546,   306,   172,   248,    51,   224,   225,   583,
     193,   243,   244,   347,   249,   132,   173,   422,   307,   169,
     128,   303,   453,   305,   654,   154,   183,   310,   151,   138,
     654,   138,   266,   202,   352,   205,   423,   508,   266,   160,
     161,   328,   361,   362,   363,   364,   365,   366,   475,   152,
     599,   608,    42,   295,   258,   297,    42,   375,   327,   377,
     318,   547,   334,   383,   427,   379,   254,   459,   331,   460,
     138,   340,   480,   634,   138,   421,   172,   598,   172,   155,
     388,   428,    51,   329,   217,   218,    51,   432,   175,   124,
     520,   433,   337,   627,   444,   446,   458,   542,   550,   589,
      42,   413,   414,   342,   182,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   596,   601,   621,   296,
     381,   135,   630,   274,   301,   641,   193,   134,   304,   398,
      51,   172,   164,   450,   311,   312,   168,   166,   400,   401,
     402,   181,   403,   522,   442,   443,   217,   218,   197,   160,
     161,   181,   170,   138,   397,   451,   239,   138,   240,   199,
     143,   200,   201,   138,   348,   171,   138,   350,   187,   181,
     181,   143,   463,   430,   221,   222,   223,    48,   122,   144,
     241,   138,   138,   353,   354,   355,    48,   122,   437,   253,
     144,   404,   200,   201,   448,   467,   242,   441,   229,   230,
     231,   232,   233,   168,   226,   227,   228,   517,   332,   138,
     261,   519,   280,   486,   487,   488,   489,   490,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,    48,
     122,   646,   647,   438,   145,   146,   356,   357,    48,   122,
      48,   122,   462,   219,   526,   145,   146,   177,   358,   359,
     360,   234,   248,    48,   122,   564,   465,   565,    48,   122,
     333,   249,   425,   426,   318,   266,   318,   273,   138,   181,
     276,   535,   640,   277,   269,   536,   590,   324,   592,   593,
     292,   138,   509,   510,   511,   318,   293,   318,   318,   280,
     602,   603,   394,   397,    48,   122,   527,    48,   122,   318,
     318,   199,   464,   203,   204,   138,   157,   521,   523,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     507,   327,   294,   298,   528,   158,   302,    48,   122,   626,
     299,   515,   516,   138,   585,   245,   138,   300,   318,   321,
     322,   335,    48,   122,   568,   525,  -219,   533,   349,  -218,
     217,   218,    48,   122,   472,   397,    48,   122,   235,   236,
     237,   238,   483,   338,   280,   351,   341,   138,   112,   112,
     112,   112,   112,   112,   112,   112,   112,  -217,   380,   384,
     162,   385,   390,   409,    48,   122,   405,   406,   407,   408,
     367,   368,   369,   370,   392,   659,   491,   492,   493,   494,
     591,   659,   393,   410,   411,   412,   415,   416,   429,   434,
     307,   436,   456,   586,   449,   469,   470,   461,   471,   138,
     473,   474,   147,   481,   584,   138,   476,   504,   505,   610,
     506,   512,   514,   518,   540,   529,   530,   531,   538,   537,
     620,   541,   543,   551,   162,   549,   544,   219,   553,   597,
     545,   614,   615,   616,   552,   555,   604,   138,   138,   138,
     147,   147,   147,   138,   556,   337,   147,   557,   554,   558,
     559,   563,   637,   638,   639,   588,   617,   594,   534,   619,
     611,   612,   613,   595,   618,   623,   661,   624,   143,   625,
     635,   629,   643,   181,   651,   628,   632,   633,   642,   648,
     631,   660,   587,   198,   435,   138,   649,   144,   524,   389,
     123,   447,   431,   606,   279,   127,   162,   600,   569,   482,
     636,   570,   371,   605,   495,   571,   496,   372,   644,   645,
     373,   497,   220,   374,   614,     0,   376,   498,     0,     0,
     138,    42,   650,   147,   500,     0,     0,     0,     0,   655,
       0,     0,   622,     0,     0,   655,     0,    48,   122,   162,
       0,   572,   145,   146,     0,     0,     0,   -11,     0,     0,
       0,    51,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,     0,     0,     0,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,     0,   112,     4,
       5,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   141,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
     109,     0,     0,    24,    25,    26,   418,    27,     0,     0,
     143,     0,    28,    29,    30,     0,     0,     0,    31,    32,
       0,     0,    33,     0,    34,     0,    35,    36,     0,   144,
      37,    38,    39,     0,    40,    41,     0,    42,    43,    44,
     569,    45,     0,   570,     0,     0,    46,   571,     0,    47,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    42,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     122,     0,     0,   572,   145,   146,     0,     0,     0,   -13,
       0,     0,     0,    51,     0,     0,   468,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   484,   112,   484,
       0,     0,     4,     5,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,   109,     0,     0,   110,     0,     0,     0,
       0,     0,     0,   539,     0,    28,    29,    30,     0,     0,
     484,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     4,     5,     0,
       0,   262,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,   484,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     4,     5,     0,     0,   466,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   141,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   109,     0,     0,   188,    25,    26,     0,
      27,     0,     0,     0,     0,    28,   189,    30,     0,     0,
       0,    31,    32,     0,     0,   190,     0,    34,     0,    35,
      36,     0,     0,    37,    38,    39,     0,    40,    41,     0,
      42,    43,    44,     0,    45,     0,     0,     0,     0,    46,
       0,     0,    47,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,    49,    50,   191,     4,     5,     0,
      51,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,    -5,    17,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,    26,     0,    27,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
      33,     0,    34,     0,    35,    36,     0,     0,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
       0,     0,     0,     0,    46,     0,     0,    47,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     4,     5,     0,     0,    51,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   141,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,   109,     0,     0,    24,    25,    26,     0,    27,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      31,    32,     0,     0,    33,     0,    34,     0,    35,    36,
       0,     0,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    49,    50,   191,     4,     5,     0,    51,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,   141,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,   109,     0,     0,
      24,    25,    26,     0,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,    33,
       0,    34,     0,    35,    36,     0,     0,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    49,    50,
     336,     4,     5,     0,    51,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   141,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,   109,     0,     0,    24,    25,    26,     0,    27,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      31,    32,     0,     0,    33,     0,    34,     0,    35,    36,
       0,     0,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    49,    50,  -177,     4,     5,     0,    51,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
      -5,   141,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,   109,     0,     0,
      24,    25,    26,     0,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,    33,
       0,    34,     0,    35,    36,     0,     0,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    49,    50,
       4,     5,     0,     0,    51,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,    23,     0,     0,    24,    25,    26,     0,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,    33,     0,    34,     0,    35,    36,     0,
       0,    37,    38,    39,     0,    40,    41,     0,    42,    43,
      44,     0,    45,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,    49,    50,     4,     5,     0,     0,    51,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,   141,
      18,     0,     0,    19,     0,     0,     0,    20,     0,    21,
       0,     0,     0,    22,     0,   109,     0,     0,    24,    25,
      26,     0,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,    33,     0,    34,
       0,    35,    36,     0,     0,    37,    38,    39,     0,    40,
      41,     0,    42,    43,    44,     0,    45,     0,     0,     0,
       0,    46,     0,     0,    47,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,    49,    50,     4,     5,
       0,     0,    51,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,     0,    23,
       0,     0,    24,    25,    26,     0,    27,     0,     0,     0,
       0,    28,    29,   652,     0,     0,   570,    31,    32,     0,
       0,    33,     0,    34,     0,    35,    36,     0,     0,    37,
      38,    39,     0,    40,    41,     0,    42,    43,    44,     0,
      45,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
      49,    50,   -57,     4,     5,     0,    51,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,    26,
       0,    27,     0,     0,     0,     0,    28,    29,   652,     0,
       0,   570,    31,    32,     0,     0,    33,     0,    34,     0,
      35,    36,     0,     0,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,    45,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,    49,    50,   -58,     4,     5,
       0,    51,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,     0,    23,
       0,     0,    24,    25,    26,     0,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,    33,     0,    34,     0,    35,    36,     0,     0,    37,
      38,    39,     0,    40,    41,     0,    42,    43,    44,     0,
      45,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
      49,    50,   -59,     4,     5,     0,    51,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,    26,
       0,    27,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,    31,    32,     0,     0,    33,     0,    34,     0,
      35,    36,     0,     0,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,    45,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,    49,    50,   -60,     4,     5,
       0,    51,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   109,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,    37,
       0,   278,     0,     0,     0,     0,     0,    43,    44,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     4,     5,     0,     0,  -335,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,   109,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     4,     5,     0,     0,
    -337,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,   343,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     4,     5,   111,
       0,   344,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     4,     5,
     111,     0,  -337,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   109,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,   122,     0,     0,     0,     4,     5,     0,
       0,   111,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -5,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     4,     5,     0,     0,
     111,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,   343,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     4,     5,     0,     0,   111,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   109,     0,     0,   110,
      13,    14,    15,     0,     0,     0,     0,     0,    28,    29,
      30,     0,     0,   108,    31,     0,     0,     0,    33,     0,
       0,     0,    35,    21,     0,     0,    37,     0,     0,   109,
       0,     0,   110,     0,    43,    44,     0,    45,     0,     0,
       0,    28,    29,    30,     0,     0,     0,    31,     0,    48,
       0,    33,    13,    14,    15,    35,     0,     0,   111,    37,
       0,   417,     0,     0,     0,   108,     0,    43,    44,     0,
      45,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   109,    48,     0,   110,   125,    14,    15,     0,     0,
       0,   111,     0,    28,    29,    30,     0,     0,   108,    31,
       0,     0,     0,    33,     0,     0,     0,    35,    21,     0,
       0,    37,     0,     0,   109,     0,     0,   110,     0,    43,
      44,     0,    45,     0,     0,     0,    28,    29,    30,     0,
       0,     0,    31,     0,    48,     0,    33,   125,   532,    15,
      35,     0,     0,   111,    37,     0,     0,     0,     0,     0,
     108,     0,    43,    44,     0,    45,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,   111,     0,    28,    29,
      30,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,    35,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,     2,    20,    27,    38,    17,    14,   137,    20,    44,
     175,    20,    48,     3,   416,    27,   122,   173,    19,   175,
     265,    45,    16,     3,    18,   399,     3,    39,     3,     3,
     275,     3,     3,    45,    46,     3,     3,    47,     3,   413,
       3,   415,     3,    47,     3,   131,     3,   177,   293,   294,
       3,   181,    47,    47,     3,    69,    58,    58,     3,     3,
       3,     3,     3,   150,   106,   531,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    63,   113,    13,   480,     3,
       3,     3,    79,   651,    74,     3,   172,    47,     3,   657,
      26,   133,    89,   135,     0,    79,    32,    17,   140,   417,
      36,    98,   476,    57,   126,    89,   143,    35,    36,   575,
      50,    15,    16,   199,    98,    79,   138,    79,    72,    39,
       3,   163,   136,   165,   651,   141,    46,   169,   123,   141,
     657,   143,   142,    88,   220,    90,    98,    50,   142,    49,
      50,   183,   229,   230,   231,   232,   233,   234,   393,    79,
     552,   139,   113,   154,   144,   156,   113,   243,   182,   245,
     316,   479,   186,   123,   144,   132,   140,   144,   131,   144,
     182,   143,   143,   141,   186,   140,   126,   551,   126,    47,
     266,   140,   143,   184,    45,    46,   143,   140,   138,   125,
     138,   140,   193,   595,   324,   140,   140,   140,   140,   140,
     113,    15,    16,   197,    47,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   140,   140,   140,   155,
     256,   141,   140,   143,   160,   140,   166,    79,   164,    28,
     143,   126,    47,   339,   170,   171,    79,   138,    25,    26,
      27,   265,    29,   138,   114,   115,    45,    46,    59,    49,
      50,   275,    47,   265,   278,   341,    20,   269,    19,    47,
      60,    49,    50,   275,   200,    47,   278,   203,    47,   293,
     294,    60,   378,   307,    37,    38,    39,   129,   130,    79,
      18,   293,   294,   221,   222,   223,   129,   130,    79,   140,
      79,    78,    49,    50,   330,   381,    17,   321,    25,    26,
      27,    28,    29,    79,    32,    33,    34,   437,    79,   321,
       3,   441,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   129,
     130,   634,   635,   124,   134,   135,   224,   225,   129,   130,
     129,   130,    79,   142,    79,   134,   135,    79,   226,   227,
     228,    78,    89,   129,   130,   520,   380,   522,   129,   130,
     131,    98,   299,   300,   520,   142,   522,   110,   380,   393,
      79,   457,   617,    79,     3,   461,   541,    79,   543,   544,
      47,   393,   424,   425,   426,   541,    47,   543,   544,   476,
     555,   556,    79,   417,   129,   130,   131,   129,   130,   555,
     556,    47,    79,    49,    50,   417,    79,   442,   443,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     421,   445,    47,   128,   448,    98,    79,   129,   130,   594,
     128,   432,   433,   445,    79,     3,   448,   128,   594,     3,
     118,    79,   129,   130,   530,   446,   141,   455,    79,   141,
      45,    46,   129,   130,   390,   479,   129,   130,    21,    22,
      23,    24,   398,   139,   551,    79,   141,   479,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   141,   141,   144,
     416,    80,    47,    20,   129,   130,    21,    22,    23,    24,
     235,   236,   237,   238,    47,   651,   405,   406,   407,   408,
     542,   657,    47,    19,    18,    17,     3,   143,    47,   139,
      72,   139,    79,   537,   140,    47,    47,   141,   140,   531,
     140,   140,   531,    28,   532,   537,   142,    28,   140,   563,
     140,   138,    79,    79,   470,   138,   141,   138,    28,   141,
     582,   138,   138,   141,   480,   481,   138,   142,    28,   550,
     140,   569,   570,   571,   143,   138,   557,   569,   570,   571,
     569,   570,   571,   575,   138,   566,   575,    66,   504,    79,
      56,   140,   614,   615,   616,    28,    47,   138,   457,   575,
     139,   139,   139,   143,   139,   139,   657,   139,    60,   139,
     141,   140,   140,   617,   138,   596,   139,   139,   139,   139,
     601,   139,   538,    58,   316,   617,   140,    79,   445,   269,
      13,   327,   308,   560,   150,    14,   552,   553,    90,   397,
     609,    93,   239,   559,   409,    97,   410,   240,   629,   630,
     241,   411,    91,   242,   652,    -1,   244,   412,    -1,    -1,
     652,   113,   643,   652,   414,    -1,    -1,    -1,    -1,   651,
      -1,    -1,   588,    -1,    -1,   657,    -1,   129,   130,   595,
      -1,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,   244,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,   292,    83,    -1,    -1,
      60,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    79,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      90,   117,    -1,    93,    -1,    -1,   122,    97,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   113,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   143,    -1,    -1,   382,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    88,    89,    90,    -1,    -1,
     476,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    35,    36,    -1,
      -1,   144,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,   551,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    35,    36,    -1,    -1,   144,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,
     103,    -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    35,    36,    -1,
     143,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,    35,    36,    -1,    -1,   143,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    35,    36,    -1,   143,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    35,    36,    -1,   143,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    35,    36,    -1,   143,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
      35,    36,    -1,    -1,   143,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,    35,    36,    -1,    -1,   143,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    35,    36,
      -1,    -1,   143,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    35,    36,    -1,   143,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    35,    36,
      -1,   143,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    35,    36,    -1,   143,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    35,    36,
      -1,   143,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    35,    36,    -1,    -1,   143,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    35,    36,    -1,    -1,
     143,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   138,
      -1,   140,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
     138,    -1,   140,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,    -1,    -1,    35,    36,    -1,
      -1,   138,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
     138,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   138,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    60,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    70,    -1,    -1,   106,    -1,    -1,    76,
      -1,    -1,    79,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,   129,
      -1,    98,    47,    48,    49,   102,    -1,    -1,   138,   106,
      -1,   108,    -1,    -1,    -1,    60,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,   129,    -1,    79,    47,    48,    49,    -1,    -1,
      -1,   138,    -1,    88,    89,    90,    -1,    -1,    60,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    70,    -1,
      -1,   106,    -1,    -1,    76,    -1,    -1,    79,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,   129,    -1,    98,    47,    48,    49,
     102,    -1,    -1,   138,   106,    -1,    -1,    -1,    -1,    -1,
      60,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  ParserImplementation::yystos_[] =
  {
         0,   146,   147,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    54,    60,    61,    64,
      68,    70,    74,    76,    79,    80,    81,    83,    88,    89,
      90,    94,    95,    98,   100,   102,   103,   106,   107,   108,
     110,   111,   113,   114,   115,   117,   122,   125,   129,   137,
     138,   143,   148,   149,   162,   163,   164,   165,   174,   177,
     182,   183,   184,   185,   186,   187,   188,   191,   192,   200,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   219,
     220,   221,   228,   229,   230,   231,   232,   238,   242,   243,
     244,   247,   248,   249,   250,   251,   252,   253,   255,   257,
     259,   261,   263,   265,   267,   269,   272,   277,    60,    76,
      79,   138,   247,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   130,   202,   272,    47,   242,   243,     3,   233,
     234,   276,    79,   181,    79,   195,   197,   199,   200,   202,
     181,    60,   182,    60,    79,   134,   135,   148,   161,   195,
      47,   123,    79,   181,   141,    47,   272,    79,    98,   199,
      49,    50,   272,   275,    47,   272,   138,   185,    79,   195,
      47,    47,   126,   138,   166,   138,   166,    79,   167,   168,
     180,   199,    47,   195,   181,   201,   276,    47,    79,    89,
      98,   139,   182,   190,   239,   240,   241,    59,   177,    47,
      49,    50,   245,    49,    50,   245,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   142,
     271,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    78,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   277,    79,    89,    98,
      79,   203,   241,   140,   140,   245,     3,    74,   144,   235,
     236,     3,   144,   269,   277,    47,   142,   204,   225,     3,
     277,   225,   277,   110,   195,    47,    79,    79,   108,   247,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     273,   274,    47,    47,    47,   182,   272,   182,   128,   128,
     128,   272,    79,   277,   272,   277,    57,    72,   222,   223,
     277,   272,   272,   269,   163,   173,   176,   179,   183,   173,
     225,     3,   118,   225,    79,   193,   194,   199,   277,   182,
       3,   131,    79,   131,   199,    79,   139,   182,   139,     3,
     143,   141,   181,   124,   140,   171,   246,   269,   272,    79,
     272,    79,   269,   249,   249,   249,   250,   250,   251,   251,
     251,   252,   252,   252,   252,   252,   252,   253,   253,   253,
     253,   255,   257,   259,   261,   269,   263,   269,     3,   132,
     141,   276,    47,   123,   144,    80,   237,   180,   269,   197,
      47,   180,    47,    47,    79,   196,   198,   199,    28,   271,
      25,    26,    27,    29,    78,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   143,   108,   247,   180,
     180,   140,    79,    98,   189,   189,   189,   144,   140,    47,
     185,   223,   140,   140,   139,   179,   139,    79,   124,   169,
     170,   199,   114,   115,   225,     3,   140,   204,   276,   140,
     241,   269,    69,   136,   150,   151,    79,     3,   140,   144,
     144,   141,    79,   241,    79,   199,   144,   269,   247,    47,
      47,   140,   272,   140,   140,   180,   142,   205,   226,     3,
     143,    28,   226,   272,   247,   270,   252,   252,   252,   252,
     252,   254,   254,   254,   254,   256,   258,   260,   262,   270,
     264,   270,   275,   198,    28,   140,   140,   182,    50,   277,
     277,   277,   138,   215,    79,   182,   182,   225,    79,   225,
     138,   166,   138,   166,   194,   182,    79,   131,   199,   138,
     141,   138,    48,   242,   171,   269,   269,   141,    28,   247,
     272,   138,   140,   138,   138,   140,   270,   198,   275,   272,
     140,   141,   143,    28,   272,   138,   138,    66,    79,    56,
     216,   217,   227,   140,   173,   173,   190,   224,   269,    90,
      93,    97,   133,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   206,   242,    79,   199,   272,    28,   140,
     173,   277,   173,   173,   138,   143,   140,   182,   270,   275,
     272,   140,   173,   173,   182,   272,   217,    63,   139,   218,
     185,   139,   139,   139,   161,   161,   161,    47,   139,   155,
     277,   140,   272,   139,   139,   139,   173,   275,   182,   140,
     140,   182,   139,   139,   141,   141,   227,   277,   277,   277,
     180,   140,   139,   140,   182,   182,   224,   224,   139,   140,
     182,   138,    90,   159,   160,   163,   172,   175,   178,   183,
     139,   178
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
     368,   369,   370,   371,   372,   373,   374,   375,   123,   125,
      41,    58,    61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   145,   147,   146,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   154,   154,   155,   155,   155,   155,
     155,   155,   156,   157,   158,   159,   160,   161,   161,   161,
     161,   161,   161,   162,   163,   163,   164,   164,   165,   165,
     165,   165,   165,   165,   165,   165,   166,   167,   167,   168,
     168,   168,   168,   169,   169,   170,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   182,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   186,   187,   188,   188,   188,   189,   189,   189,
     190,   190,   191,   191,   191,   192,   193,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   200,   201,   201,   201,   201,   202,   203,   203,
     203,   203,   203,   203,   204,   205,   206,   207,   208,   208,
     208,   209,   209,   209,   209,   209,   209,   209,   209,   210,
     211,   212,   213,   214,   215,   215,   216,   216,   217,   218,
     219,   220,   221,   221,   221,   222,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   228,   228,   228,   228,   228,
     229,   230,   230,   231,   231,   231,   231,   231,   231,   232,
     232,   232,   232,   233,   233,   234,   234,   235,   236,   236,
     237,   237,   238,   239,   239,   240,   240,   241,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   245,   245,   246,   246,   246,   246,
     247,   247,   247,   247,   248,   248,   248,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   250,   250,   250,
     250,   251,   251,   251,   252,   252,   252,   252,   253,   253,
     253,   253,   253,   253,   253,   254,   254,   254,   254,   254,
     254,   255,   255,   255,   255,   255,   256,   256,   256,   256,
     256,   257,   257,   258,   258,   259,   259,   260,   260,   261,
     261,   262,   262,   263,   263,   264,   264,   265,   265,   266,
     266,   267,   267,   268,   268,   269,   269,   270,   270,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   272,   272,   273,   273,   274,   274,   275,   275,   276,
     276,   277,   277
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     7,     0,     1,     0,     2,     1,
       1,     0,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     7,     2,     3,     3,     3,     1,     2,     1,
       7,     7,     8,     7,     8,     8,     8,     1,     7,     4,
       7,     4,     5,     5,     2,     2,     2,     1,     3,     2,
       2,     4,     4,     0,     1,     2,     2,     0,     1,     0,
       1,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     2,     5,     5,     5,     1,     1,     3,
       1,     2,     3,     3,     3,     5,     1,     3,     2,     2,
       1,     3,     1,     3,     2,     2,     2,     2,     1,     1,
       3,     3,     5,     2,     2,     4,     4,     3,     1,     3,
       3,     5,     3,     5,     2,     2,     1,     2,     7,     5,
       3,     7,     5,     9,    10,     7,     8,     8,     9,     3,
       3,     3,     5,     5,     3,     5,     1,     2,     4,     3,
       3,     3,     3,     3,     4,     5,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     4,     2,     4,     1,     2,     2,     6,     7,
       0,     4,     3,     0,     2,     3,     5,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     3,     3,     1,     2,
       2,     2,     4,     3,     2,     3,     1,     1,     3,     3,
       1,     1,     1,     3,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     5,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     0,     1,     0,     1,     0,
       1,     1,     1
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
  "'{'", "'}'", "')'", "':'", "'='", "';'", "']'", "$accept", "program",
  "$@1", "class_initialiser", "class_adjective__opt",
  "inherit_declaration__opt", "inherit_declaration", "class_body__opt",
  "class_body", "class_element_list", "class_element",
  "constructor_definition", "prototype_property_definition",
  "class_property_definition", "instance_property_definition",
  "private_property_definition", "exportable_definition",
  "version_statement", "function_declaration", "function_expression",
  "arrow_function_expression", "shorten_function_body",
  "formal_parameter_list_with_rest", "formal_parameter_list",
  "formal_parameter_rest__opt", "formal_parameter_rest",
  "arguments_spread", "constructor_function_body", "function_body",
  "source_elements", "source_elements_for_constructor",
  "source_elements_for_function", "source_element",
  "source_element_for_constructor", "source_element_for_function",
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
       146,     0,    -1,    -1,   147,   174,    -1,   149,    59,   181,
     150,   138,   152,   139,    -1,    -1,    60,    -1,    -1,   151,
     242,    -1,    69,    -1,   136,    -1,    -1,   153,    -1,   154,
      -1,   155,    -1,   154,   155,    -1,   156,    -1,   206,    -1,
     157,    -1,   158,    -1,   159,    -1,   160,    -1,   133,    47,
     180,   140,   138,   172,   139,    -1,   161,   277,    -1,    97,
     161,   277,    -1,    93,   161,   277,    -1,    90,   161,   277,
      -1,   195,    -1,    60,   195,    -1,   148,    -1,    79,    47,
     180,   140,   138,   173,   139,    -1,   134,    79,    47,   140,
     138,   173,   139,    -1,   135,    79,    47,   180,   140,   138,
     173,   139,    -1,   137,    47,    79,   140,   138,   224,   139,
      -1,    76,    79,    47,   180,   140,   138,   173,   139,    -1,
      60,    79,    47,   180,   140,   138,   173,   139,    -1,    76,
     181,    47,   180,   140,   138,   173,   139,    -1,   165,    -1,
     117,   180,   118,   114,   138,   173,   139,    -1,   114,   138,
     173,   139,    -1,   117,   180,   118,   115,   138,   173,   139,
      -1,   115,   138,   173,   139,    -1,   117,   180,   118,   114,
     166,    -1,   117,   180,   118,   115,   166,    -1,   115,   166,
      -1,   114,   166,    -1,   126,   269,    -1,   168,    -1,   168,
       3,   169,    -1,    79,   225,    -1,   199,   225,    -1,   168,
       3,    79,   225,    -1,   168,     3,   199,   225,    -1,    -1,
     170,    -1,   124,    79,    -1,   124,    79,    -1,    -1,   175,
      -1,    -1,   176,    -1,   177,    -1,   174,   177,    -1,   178,
      -1,   175,   178,    -1,   179,    -1,   176,   179,    -1,   182,
      -1,   163,    -1,   183,    -1,   163,    -1,   159,    -1,   160,
      -1,   183,    -1,   163,    -1,    -1,   167,    -1,    -1,    79,
      -1,   183,    -1,   186,    -1,   187,    -1,   185,    -1,   184,
      -1,   191,    -1,   192,    -1,   206,    -1,   207,    -1,   208,
      -1,   209,    -1,   210,    -1,   211,    -1,   212,    -1,   213,
      -1,   219,    -1,   214,    -1,   220,    -1,   221,    -1,   188,
      -1,   162,    -1,   138,   139,    -1,   138,   190,   139,    -1,
     125,   181,   182,    -1,    68,   161,    -1,    83,    79,   128,
     189,   277,    -1,    83,   199,   128,   189,   277,    -1,    83,
      98,   128,   189,   277,    -1,    98,    -1,    79,    -1,   189,
      50,    79,    -1,   182,    -1,   190,   182,    -1,   108,   195,
     277,    -1,    60,   195,   277,    -1,   122,   195,   277,    -1,
     122,    47,   193,   140,   182,    -1,   194,    -1,   193,     3,
     194,    -1,    79,   225,    -1,   199,   204,    -1,   197,    -1,
     195,     3,   197,    -1,   198,    -1,   196,     3,   198,    -1,
      79,   225,    -1,   199,   225,    -1,    79,   226,    -1,   199,
     226,    -1,   200,    -1,   202,    -1,   129,   276,   131,    -1,
     129,   201,   131,    -1,   129,   201,     3,   276,   131,    -1,
     276,    79,    -1,   276,   199,    -1,   201,     3,   276,    79,
      -1,   201,     3,   276,   199,    -1,   130,   203,   132,    -1,
      79,    -1,   241,   141,    79,    -1,   241,   141,   199,    -1,
     203,     3,   241,   141,    79,    -1,   203,     3,    79,    -1,
     203,     3,   241,   141,   199,    -1,   142,   269,    -1,   142,
     270,    -1,   277,    -1,   272,   277,    -1,    80,    47,   272,
     140,   182,    66,   182,    -1,    80,    47,   272,   140,   182,
      -1,    81,   272,   182,    -1,    64,   182,   110,    47,   272,
     140,   277,    -1,   110,    47,   272,   140,   182,    -1,    74,
      47,   274,   143,   275,   143,   275,   140,   182,    -1,    74,
      47,   108,   196,   143,   275,   143,   275,   140,   182,    -1,
      74,    47,   247,    28,   272,   140,   182,    -1,    74,    47,
     108,   198,    28,   272,   140,   182,    -1,    74,   123,    47,
     247,    28,   272,   140,   182,    -1,    74,   123,    47,   108,
     198,    28,   272,   140,   182,    -1,    61,   181,   277,    -1,
      54,   181,   277,    -1,    95,   275,   277,    -1,   111,    47,
     272,   140,   182,    -1,   100,    47,   272,   140,   215,    -1,
     138,   227,   139,    -1,   138,   227,   218,   227,   139,    -1,
     217,    -1,   216,   217,    -1,    56,   272,   141,   224,    -1,
      63,   141,   224,    -1,    79,   141,   182,    -1,   103,   272,
     277,    -1,   107,   185,   222,    -1,   107,   185,   223,    -1,
     107,   185,   222,   223,    -1,    57,    47,    79,   140,   185,
      -1,    72,   185,    -1,    -1,   190,    -1,    -1,   204,    -1,
      -1,   205,    -1,    -1,   216,    -1,   229,    -1,   230,    -1,
      89,    -1,    98,    -1,    94,    -1,    88,    -1,   106,    -1,
      70,    -1,   102,    -1,    79,    -1,   228,    -1,   232,    -1,
     238,    -1,    47,   272,   140,    -1,    49,   276,   144,    -1,
      49,   233,   144,    -1,    49,   233,     3,   276,   144,    -1,
      49,   233,   235,   144,    -1,   276,   269,    -1,   233,     3,
     276,   269,    -1,     3,    -1,   234,     3,    -1,   236,   237,
      -1,    74,    47,   247,    28,   272,   140,    -1,    74,   123,
      47,   247,    28,   272,   140,    -1,    -1,    80,    47,   272,
     140,    -1,   138,   239,   139,    -1,    -1,   240,   143,    -1,
     241,   141,   269,    -1,   240,     3,   241,   141,   269,    -1,
      79,    -1,    98,    -1,    89,    -1,   231,    -1,   164,    -1,
     148,    -1,   242,    49,   272,   144,    -1,    90,    49,   272,
     144,    -1,    90,    50,    79,    -1,   242,    50,    79,    -1,
      48,   242,   245,    -1,   242,    -1,    48,   243,    -1,   242,
     245,    -1,   244,   245,    -1,   244,    49,   272,   144,    -1,
     244,    50,    79,    -1,    47,   140,    -1,    47,   246,   140,
      -1,   269,    -1,   171,    -1,   246,     3,   269,    -1,   246,
       3,   171,    -1,   243,    -1,   244,    -1,   200,    -1,    47,
     202,   140,    -1,   247,    -1,   247,    46,    -1,   247,    45,
      -1,   248,    -1,    42,   249,    -1,    43,   249,    -1,    44,
     249,    -1,    46,   249,    -1,    45,   249,    -1,    35,   249,
      -1,    36,   249,    -1,    41,   249,    -1,    40,   249,    -1,
     249,    -1,   250,    37,   249,    -1,   250,    38,   249,    -1,
     250,    39,   249,    -1,   250,    -1,   251,    35,   250,    -1,
     251,    36,   250,    -1,   251,    -1,   252,    34,   251,    -1,
     252,    33,   251,    -1,   252,    32,   251,    -1,   252,    -1,
     253,    26,   252,    -1,   253,    25,   252,    -1,   253,    29,
     252,    -1,   253,    78,   252,    -1,   253,    27,   252,    -1,
     253,    28,   252,    -1,   252,    -1,   254,    26,   252,    -1,
     254,    25,   252,    -1,   254,    29,   252,    -1,   254,    78,
     252,    -1,   254,    27,   252,    -1,   253,    -1,   255,    23,
     253,    -1,   255,    22,   253,    -1,   255,    24,   253,    -1,
     255,    21,   253,    -1,   254,    -1,   256,    23,   254,    -1,
     256,    22,   254,    -1,   256,    24,   254,    -1,   256,    21,
     254,    -1,   255,    -1,   257,    20,   255,    -1,   256,    -1,
     258,    20,   256,    -1,   257,    -1,   259,    19,   257,    -1,
     258,    -1,   260,    19,   258,    -1,   259,    -1,   261,    18,
     259,    -1,   260,    -1,   262,    18,   260,    -1,   261,    -1,
     263,    17,   261,    -1,   262,    -1,   264,    17,   262,    -1,
     263,    -1,   265,    16,   263,    -1,   264,    -1,   266,    16,
     264,    -1,   265,    -1,   265,    15,   269,   141,   269,    -1,
     266,    -1,   266,    15,   270,   141,   270,    -1,   267,    -1,
     247,   271,   269,    -1,   268,    -1,   247,   271,   270,    -1,
     142,    -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,
       5,    -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,
       9,    -1,     8,    -1,   269,    -1,   272,     3,   269,    -1,
     270,    -1,   273,     3,   270,    -1,    -1,   273,    -1,    -1,
     272,    -1,    -1,   234,    -1,   143,    -1,   113,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,    15,    16,    18,    19,    22,
      24,    26,    27,    29,    31,    33,    36,    38,    40,    42,
      44,    46,    48,    56,    59,    63,    67,    71,    73,    76,
      78,    86,    94,   103,   111,   120,   129,   138,   140,   148,
     153,   161,   166,   172,   178,   181,   184,   187,   189,   193,
     196,   199,   204,   209,   210,   212,   215,   218,   219,   221,
     222,   224,   226,   229,   231,   234,   236,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   256,   258,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     303,   306,   310,   314,   317,   323,   329,   335,   337,   339,
     343,   345,   348,   352,   356,   360,   366,   368,   372,   375,
     378,   380,   384,   386,   390,   393,   396,   399,   402,   404,
     406,   410,   414,   420,   423,   426,   431,   436,   440,   442,
     446,   450,   456,   460,   466,   469,   472,   474,   477,   485,
     491,   495,   503,   509,   519,   530,   538,   547,   556,   566,
     570,   574,   578,   584,   590,   594,   600,   602,   605,   610,
     614,   618,   622,   626,   630,   635,   641,   644,   645,   647,
     648,   650,   651,   653,   654,   656,   658,   660,   662,   664,
     666,   668,   670,   672,   674,   676,   678,   680,   682,   686,
     690,   694,   700,   705,   708,   713,   715,   718,   721,   728,
     736,   737,   742,   746,   747,   750,   754,   760,   762,   764,
     766,   768,   770,   772,   777,   782,   786,   790,   794,   796,
     799,   802,   805,   810,   814,   817,   821,   823,   825,   829,
     833,   835,   837,   839,   843,   845,   848,   851,   853,   856,
     859,   862,   865,   868,   871,   874,   877,   880,   882,   886,
     890,   894,   896,   900,   904,   906,   910,   914,   918,   920,
     924,   928,   932,   936,   940,   944,   946,   950,   954,   958,
     962,   966,   968,   972,   976,   980,   984,   986,   990,   994,
     998,  1002,  1004,  1008,  1010,  1014,  1016,  1020,  1022,  1026,
    1028,  1032,  1034,  1038,  1040,  1044,  1046,  1050,  1052,  1056,
    1058,  1062,  1064,  1070,  1072,  1078,  1080,  1084,  1086,  1090,
    1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,
    1112,  1114,  1116,  1120,  1122,  1126,  1127,  1129,  1130,  1132,
    1133,  1135,  1137
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   367,   367,   367,   378,   389,   390,   395,   396,   410,
     411,   416,   417,   421,   426,   447,   471,   477,   478,   479,
     480,   481,   486,   501,   511,   521,   530,   540,   541,   547,
     548,   559,   571,   586,   599,   616,   632,   642,   655,   664,
     673,   683,   693,   703,   714,   725,   739,   750,   751,   769,
     785,   793,   803,   813,   814,   823,   840,   850,   851,   855,
     856,   860,   868,   879,   887,   898,   906,   916,   917,   928,
     929,   936,   937,   942,   943,   953,   954,   961,   962,   971,
     972,   977,   985,   990,   994,   999,  1003,  1008,  1013,  1018,
    1023,  1028,  1033,  1038,  1043,  1048,  1053,  1058,  1063,  1067,
    1074,  1081,  1092,  1105,  1117,  1134,  1149,  1169,  1177,  1185,
    1195,  1203,  1214,  1222,  1230,  1241,  1251,  1257,  1264,  1272,
    1283,  1291,  1301,  1307,  1315,  1323,  1333,  1341,  1352,  1356,
    1363,  1373,  1380,  1393,  1405,  1415,  1425,  1436,  1447,  1457,
    1469,  1479,  1489,  1497,  1508,  1512,  1516,  1520,  1534,  1543,
    1552,  1564,  1572,  1580,  1592,  1604,  1615,  1627,  1638,  1652,
    1662,  1672,  1682,  1693,  1704,  1708,  1717,  1723,  1731,  1742,
    1753,  1766,  1776,  1785,  1794,  1806,  1817,  1825,  1826,  1830,
    1831,  1835,  1836,  1840,  1841,  1845,  1846,  1847,  1854,  1861,
    1871,  1881,  1888,  1898,  1905,  1912,  1913,  1914,  1915,  1923,
    1933,  1940,  1950,  1961,  1971,  1982,  1983,  1988,  1996,  2003,
    2013,  2014,  2023,  2038,  2041,  2048,  2057,  2067,  2074,  2081,
    2091,  2095,  2099,  2104,  2117,  2129,  2144,  2159,  2175,  2176,
    2186,  2199,  2212,  2225,  2243,  2244,  2248,  2254,  2260,  2265,
    2273,  2274,  2275,  2276,  2280,  2284,  2291,  2301,  2302,  2309,
    2316,  2323,  2330,  2337,  2344,  2351,  2358,  2368,  2369,  2373,
    2377,  2384,  2385,  2389,  2396,  2397,  2401,  2405,  2412,  2413,
    2417,  2421,  2425,  2429,  2433,  2440,  2441,  2445,  2449,  2453,
    2457,  2464,  2465,  2469,  2473,  2477,  2484,  2485,  2489,  2493,
    2497,  2504,  2505,  2512,  2513,  2520,  2521,  2528,  2529,  2536,
    2537,  2544,  2545,  2552,  2553,  2560,  2561,  2568,  2569,  2576,
    2577,  2584,  2585,  2594,  2595,  2604,  2608,  2618,  2622,  2633,
    2634,  2635,  2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,
    2644,  2648,  2655,  2663,  2670,  2678,  2679,  2683,  2684,  2688,
    2689,  2693,  2694
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
      47,   140,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   141,   143,
      26,   142,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   144,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,    18,   139,    41,     2,     2,     2,
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
     132,   133,   134,   135,   136,   137
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3328;
  const int ParserImplementation::yynnts_ = 133;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 145;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 375;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 5829 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2697 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


