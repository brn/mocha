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
#line 375 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(1) - (1)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 386 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Line( (yysemantic_stack_[(7) - (2)].info)->GetLineNumber() );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 397 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 398 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 403 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 405 "grammar/grammar.yy"
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

  case 8:

/* Line 690 of lalr1.cc  */
#line 420 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 421 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 426 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 427 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 431 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 437 "grammar/grammar.yy"
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

  case 14:

/* Line 690 of lalr1.cc  */
#line 458 "grammar/grammar.yy"
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

  case 15:

/* Line 690 of lalr1.cc  */
#line 482 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 487 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 488 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 489 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 490 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 491 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 497 "grammar/grammar.yy"
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

  case 22:

/* Line 690 of lalr1.cc  */
#line 512 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 522 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 532 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 541 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 550 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 552 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 558 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 560 "grammar/grammar.yy"
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

  case 30:

/* Line 690 of lalr1.cc  */
#line 571 "grammar/grammar.yy"
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

  case 31:

/* Line 690 of lalr1.cc  */
#line 583 "grammar/grammar.yy"
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

  case 32:

/* Line 690 of lalr1.cc  */
#line 598 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 612 "grammar/grammar.yy"
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

  case 34:

/* Line 690 of lalr1.cc  */
#line 629 "grammar/grammar.yy"
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

  case 35:

/* Line 690 of lalr1.cc  */
#line 645 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(8) - (1)].info)->GetLineNumber() );
    fn->Name( (yysemantic_stack_[(8) - (2)].ast) );
    fn->Argv ( (yysemantic_stack_[(8) - (4)].ast) );
    fn->Append( (yysemantic_stack_[(8) - (7)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 653 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 667 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( (yysemantic_stack_[(7) - (2)].ast) );
    fn->Append( (yysemantic_stack_[(7) - (6)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 676 "grammar/grammar.yy"
    {
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    fn->Name( GetEmptyNode() );
    fn->Argv( GetEmptyNode() );
    fn->Append( (yysemantic_stack_[(4) - (3)].node_list) );
    (yyval.function) = fn;
  }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 685 "grammar/grammar.yy"
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

  case 40:

/* Line 690 of lalr1.cc  */
#line 695 "grammar/grammar.yy"
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

  case 41:

/* Line 690 of lalr1.cc  */
#line 705 "grammar/grammar.yy"
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

  case 42:

/* Line 690 of lalr1.cc  */
#line 715 "grammar/grammar.yy"
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

  case 43:

/* Line 690 of lalr1.cc  */
#line 726 "grammar/grammar.yy"
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

  case 44:

/* Line 690 of lalr1.cc  */
#line 737 "grammar/grammar.yy"
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

  case 45:

/* Line 690 of lalr1.cc  */
#line 751 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 761 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 763 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 769 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 787 "grammar/grammar.yy"
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
#line 803 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
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
#line 823 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].value_node) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 834 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 835 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 845 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 862 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 871 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 872 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 876 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 877 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 882 "grammar/grammar.yy"
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
#line 890 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 901 "grammar/grammar.yy"
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
#line 909 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 920 "grammar/grammar.yy"
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
#line 928 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 937 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 942 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 943 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 944 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 949 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 953 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 955 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 961 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 963 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 971 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 973 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 978 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 986 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 990 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 995 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1000 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1007 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1011 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1016 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1021 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1031 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1036 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1041 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1046 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1051 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1056 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1061 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1066 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1082 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1089 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1100 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1113 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1125 "grammar/grammar.yy"
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

  case 103:

/* Line 690 of lalr1.cc  */
#line 1142 "grammar/grammar.yy"
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

  case 104:

/* Line 690 of lalr1.cc  */
#line 1157 "grammar/grammar.yy"
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

  case 105:

/* Line 690 of lalr1.cc  */
#line 1177 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1185 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1193 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1203 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1211 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1222 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1230 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1238 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1249 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1259 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1265 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1272 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1280 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1291 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1299 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1309 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1315 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1323 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1331 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1342 "grammar/grammar.yy"
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
#line 1350 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1362 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1366 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1373 "grammar/grammar.yy"
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

  case 129:

/* Line 690 of lalr1.cc  */
#line 1383 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1390 "grammar/grammar.yy"
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

  case 131:

/* Line 690 of lalr1.cc  */
#line 1403 "grammar/grammar.yy"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1415 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1424 "grammar/grammar.yy"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1434 "grammar/grammar.yy"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1445 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1453 "grammar/grammar.yy"
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
#line 1464 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1475 "grammar/grammar.yy"
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
#line 1485 "grammar/grammar.yy"
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

  case 140:

/* Line 690 of lalr1.cc  */
#line 1498 "grammar/grammar.yy"
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
#line 1508 "grammar/grammar.yy"
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

  case 142:

/* Line 690 of lalr1.cc  */
#line 1519 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1528 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1538 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1542 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1546 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1551 "grammar/grammar.yy"
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
#line 1565 "grammar/grammar.yy"
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
#line 1574 "grammar/grammar.yy"
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
#line 1583 "grammar/grammar.yy"
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
#line 1595 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1597 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1598 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(9) - (6)].expression) );
    iter->AddChild( (yysemantic_stack_[(9) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1607 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1608 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (4)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1615 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1616 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1617 "grammar/grammar.yy"
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

  case 160:

/* Line 690 of lalr1.cc  */
#line 1628 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1630 "grammar/grammar.yy"
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

  case 163:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar/grammar.yy"
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

  case 164:

/* Line 690 of lalr1.cc  */
#line 1653 "grammar/grammar.yy"
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

  case 165:

/* Line 690 of lalr1.cc  */
#line 1665 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(6) - (4)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "parse error unexpected ";
      error_msg += (yysemantic_stack_[(6) - (4)].info)->GetToken();
      error_msg += " expected of.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1674 "grammar/grammar.yy"
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

  case 167:

/* Line 690 of lalr1.cc  */
#line 1685 "grammar/grammar.yy"
    {
    if ( strcmp( (yysemantic_stack_[(7) - (5)].info)->GetToken() , "of" ) != 0 ) {
      std::string error_msg = "parse error unexpected ";
      error_msg += (yysemantic_stack_[(7) - (5)].info)->GetToken();
      error_msg += " expected of.";
      error( yylloc , error_msg );
    }
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar/grammar.yy"
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

  case 169:

/* Line 690 of lalr1.cc  */
#line 1706 "grammar/grammar.yy"
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

  case 170:

/* Line 690 of lalr1.cc  */
#line 1717 "grammar/grammar.yy"
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

  case 171:

/* Line 690 of lalr1.cc  */
#line 1731 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1741 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1751 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1761 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1772 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1783 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1787 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1796 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1802 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1810 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1821 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1832 "grammar/grammar.yy"
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

  case 183:

/* Line 690 of lalr1.cc  */
#line 1845 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1855 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1864 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1873 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1885 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1903 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1908 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1909 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1913 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1918 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1919 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1923 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1926 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1933 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1940 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1950 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1960 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1967 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1977 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1984 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1991 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1992 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1994 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2002 "grammar/grammar.yy"
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

  case 212:

/* Line 690 of lalr1.cc  */
#line 2012 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2019 "grammar/grammar.yy"
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

  case 214:

/* Line 690 of lalr1.cc  */
#line 2029 "grammar/grammar.yy"
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

  case 215:

/* Line 690 of lalr1.cc  */
#line 2043 "grammar/grammar.yy"
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

  case 216:

/* Line 690 of lalr1.cc  */
#line 2053 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2070 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2076 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2084 "grammar/grammar.yy"
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

  case 222:

/* Line 690 of lalr1.cc  */
#line 2096 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2098 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2107 "grammar/grammar.yy"
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

  case 225:

/* Line 690 of lalr1.cc  */
#line 2121 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2125 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2129 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2136 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2145 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    val->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    val->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    val->AddChild( child );
    list->AddChild( val );
    (yyval.ast) = list;
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2157 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    Function *fn = ManagedHandle::Retain<Function>();
    fn->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2172 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2179 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    val->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    val->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    ValueNode* child = val->Clone()->CastToValue();
    val->AddChild( child );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( val );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2190 "grammar/grammar.yy"
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

  case 234:

/* Line 690 of lalr1.cc  */
#line 2207 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2214 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2221 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2228 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kPrivateProperty ) );
    node->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    node->Node( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2238 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2242 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2246 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2251 "grammar/grammar.yy"
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

  case 242:

/* Line 690 of lalr1.cc  */
#line 2264 "grammar/grammar.yy"
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

  case 243:

/* Line 690 of lalr1.cc  */
#line 2276 "grammar/grammar.yy"
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

  case 244:

/* Line 690 of lalr1.cc  */
#line 2291 "grammar/grammar.yy"
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

  case 245:

/* Line 690 of lalr1.cc  */
#line 2306 "grammar/grammar.yy"
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

  case 246:

/* Line 690 of lalr1.cc  */
#line 2321 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2323 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
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

  case 249:

/* Line 690 of lalr1.cc  */
#line 2346 "grammar/grammar.yy"
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

  case 250:

/* Line 690 of lalr1.cc  */
#line 2359 "grammar/grammar.yy"
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

  case 251:

/* Line 690 of lalr1.cc  */
#line 2372 "grammar/grammar.yy"
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

  case 252:

/* Line 690 of lalr1.cc  */
#line 2389 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2390 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2395 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2401 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2407 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2412 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2419 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2420 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2421 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2422 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2427 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2431 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2438 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2447 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2449 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2456 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2463 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2470 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2477 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2484 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2491 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2498 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2505 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2514 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2516 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2520 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2524 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2530 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2532 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2536 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2542 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2544 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2548 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2552 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2558 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2560 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2564 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2568 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2572 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2576 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2580 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2588 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2592 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2596 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2600 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2604 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2610 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2612 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2616 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2620 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2624 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2630 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2632 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2636 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2640 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2644 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2650 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2652 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2658 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2660 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2666 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2668 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2674 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2676 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2682 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2684 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2690 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2692 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2698 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2700 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2706 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2708 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2714 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2716 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2722 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2724 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2730 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2732 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2740 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2742 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2750 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2752 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2757 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2766 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2768 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
    (yyval.ast)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
  }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2773 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2783 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2787 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2797 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2801 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2811 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2812 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2813 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2814 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2815 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2816 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2817 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2818 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2819 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2820 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2821 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2822 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2827 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2834 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2842 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2849 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2856 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2857 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2861 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2862 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2866 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2867 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2871 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2872 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4410 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -424;
  const short int
  ParserImplementation::yypact_[] =
  {
      1624,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,
    2594,   189,    77,     7,   156,     7,  1624,   289,  -424,    90,
     108,   -28,   144,  3125,   250,  -424,  -424,   107,  -424,  2699,
    -424,   216,  -424,  3125,  -424,   -38,   229,  -424,   220,  -424,
     -64,   -52,   142,   171,     7,    77,   227,  2804,   861,  -424,
     284,  -424,   237,  -424,  -424,  -424,  -424,  1189,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,   404,  -424,   450,
     101,  -424,  -424,   467,   217,   489,   214,   207,   279,   333,
     329,   337,   367,  -424,  -424,  -424,    15,  -424,  -424,     7,
    -424,   215,   355,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,   209,   234,    33,  3125,   404,  -424,  -424,    18,
     366,   971,  -424,   -68,    14,    37,  -424,   241,  -424,  -424,
     -68,   280,   229,    35,   314,   336,  -424,  -424,   409,  2168,
     370,   383,   388,  1624,  3125,   684,   312,   339,   341,  3125,
     363,   461,   -68,  3125,    15,  1297,   -23,   241,    37,   425,
    3125,  3125,  1950,  -424,  1950,  -424,   241,   431,  -424,   521,
    -424,   416,   241,   265,    37,  1624,    23,   226,   458,  -424,
    -424,  -424,   286,  -424,  1406,   400,  -424,     7,  -424,  2384,
    3125,   466,  -424,  3125,   468,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    3125,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,
    3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,
    3335,  3335,  3335,  3125,  3335,  3125,  -424,  3125,   401,  -424,
    -424,    29,   403,  -424,  -424,  -424,    77,   476,  -424,  -424,
    -424,  -424,  -424,   142,  3125,  -424,  -424,   229,  -424,  -424,
    -424,  -424,   409,   142,   504,   505,   298,  2912,    88,   489,
     219,   350,   533,   535,   538,   540,   432,  -424,  -424,  -424,
     555,  -424,  3368,   142,   142,  -424,    44,  -424,     5,     5,
       5,    16,  -424,  -424,    51,  -424,   512,   -38,   488,  -424,
    -424,  3125,    52,  -424,   418,  2059,  -424,  -424,   420,  -424,
    -424,   326,   345,  -424,   241,    53,  -424,   241,  -424,  -424,
      77,  -424,  -424,  -424,  -424,  -424,   423,    34,    25,   419,
    -424,  -424,  -424,   -47,   487,  -424,  -424,    57,  -424,    20,
    -424,    22,  -424,  -424,  -424,  -424,  -424,   467,   467,   217,
     217,   217,   489,   489,   489,   489,   489,   489,   214,   214,
     214,   214,   207,   279,   333,   329,   427,   337,  -424,   428,
     287,  -424,   328,  1080,   537,   153,  -424,   424,  -424,  -424,
     539,   448,   449,   142,   451,   591,   181,   451,  -424,   101,
    -424,  3125,  3125,  3230,  3335,  3335,  3335,  3335,  3335,  3335,
    3335,  3335,  3335,  3335,  3335,  3335,  3335,  3230,  3335,  3230,
     452,   298,   567,   454,   457,  1624,  -424,  -424,    85,    85,
      85,  -424,   460,   517,  -424,  -424,   461,  1624,  -424,  -424,
    -424,   241,  -424,  -424,   241,     6,   225,  -424,   265,  1624,
    -424,   267,   462,   142,   422,  -424,  3125,  -424,  -424,   463,
    3457,  -424,  3020,  -424,  -424,  -424,  3125,  -424,   401,   464,
    -424,  -424,  -424,  -424,  3424,   556,  -424,   459,   470,  3125,
     471,   473,   472,  3230,  -424,  -424,   298,   477,  3125,  3125,
    -424,    62,    64,  -424,   489,   489,   489,   489,   489,   219,
     219,   219,   219,   350,   533,   535,   538,   465,   540,  -424,
    2276,   578,  3125,   475,   478,   542,   546,  -424,  -424,  -424,
     563,  -424,   483,   484,  -424,  -424,  -424,  1950,  -424,  1950,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  1515,   485,    38,
     486,  -424,   717,  3457,   435,  -424,  -424,  -424,   332,   551,
    3125,  -424,  1950,   461,  1950,  1950,   479,  -424,  -424,  2276,
      66,    67,  1624,  -424,  3230,   490,  3125,    68,  1950,  1950,
    1624,  -424,  3125,   563,  -424,   111,   -38,  1624,   491,   493,
    1189,   495,   497,   142,  3125,   289,   289,   289,   585,   498,
    -424,   949,  -424,  -424,  -424,  -424,  -424,  -424,   -68,  -424,
     404,  -424,  -424,  3125,    70,   499,   496,   500,   501,  1950,
     502,  1624,  -424,  -424,  1624,  -424,  2489,    72,  1624,   503,
     507,  -424,    24,  -424,   508,  -424,   563,  -424,  -424,  -424,
    -424,  -424,  1950,   513,  -424,   -68,   -68,   -68,   142,  -424,
    -424,  -424,    73,  -424,  -424,   -68,  -424,  -424,   509,  2489,
    -424,  1624,  -424,  -424,  1624,  -424,  -424,  -424,  1189,  1189,
     515,   516,   506,  -424,  -424,  -424,   518,  -424,  -424,  -424,
    -424,  -424,   519,  -424,  -424,  -424,  -424,  -424,  1950,   514,
     520,  1624,   522,  1732,  1624,  -424,  -424,   384,  -424,  -424,
     523,  1841,  -424,  -424,  -424,  -424,  -424
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   363,    74,     5,    74,     4,     4,   204,     0,
      74,   206,     0,     4,     0,   202,   199,     0,   201,   361,
     200,     0,   205,     4,   203,     0,     0,   154,     0,   366,
       0,     0,    72,     0,    74,   363,     0,     4,     4,   365,
       0,   240,     0,    97,    82,   239,    36,     2,    61,    67,
      76,    80,    79,    77,    78,    96,    81,    83,   260,    84,
      85,    86,    87,    88,    89,    90,    91,    93,    92,    94,
      95,   207,   197,   198,   238,   208,   209,   246,   258,   259,
     262,   265,   275,   279,   282,   286,   299,   309,   313,   317,
     321,   325,   329,   333,   339,   355,     0,   146,     5,    74,
     206,     0,   262,   271,   272,   274,   273,   266,   267,   268,
     270,   269,     0,     0,     0,     4,   246,   247,   217,     0,
     364,     4,    75,     0,   191,     0,   118,   191,   126,   127,
       0,     0,     5,   191,     0,     0,    28,   101,    26,     4,
       0,     0,     0,     4,     4,     4,     0,     0,     0,     4,
       0,   362,     0,     4,     0,     4,     0,   191,     0,     0,
       4,     4,     4,    44,     4,    43,   191,     0,    73,    46,
      47,     0,   191,     0,     0,     4,     0,     0,     0,   334,
     335,    98,   225,   108,     4,     0,     1,    74,    62,     4,
       4,     0,   248,     4,     0,   249,   351,   348,   350,   349,
     354,   353,   344,   346,   345,   352,   347,   264,   263,   343,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   147,     4,   138,   236,
     235,     0,     0,   261,   210,   245,   363,     0,   212,   218,
     211,   215,   172,    72,     4,   192,   122,     0,   111,   123,
     171,   151,    27,    72,     0,     0,     0,     4,   262,   293,
     304,   311,   315,   319,   323,   327,   331,   336,   341,   357,
     360,   157,     4,    72,    72,   182,     0,   150,     0,     0,
       0,     0,   243,   173,     0,   183,     0,     0,   184,   185,
     110,     4,     0,    45,     0,     4,    65,    71,     0,    49,
      55,    53,     0,    50,   191,     0,   114,     0,   112,   100,
     363,   129,   131,   128,   132,   133,     0,   229,   227,     0,
      99,   109,   224,     6,     0,   252,   255,     0,   254,     0,
     244,     0,   251,   340,   276,   277,   278,   280,   281,   285,
     284,   283,   288,   287,   291,   292,   289,   290,   303,   301,
     300,   302,   310,   314,   318,   322,     0,   326,   356,     0,
       0,   137,     0,     4,     0,   222,   219,     0,   144,   119,
       0,     0,     0,    72,   193,   160,   120,   193,   337,   262,
     338,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     0,     0,     0,     0,     4,   106,   105,     0,     0,
       0,   242,     0,     0,   188,   186,   155,     4,    38,    66,
      40,   191,    48,    54,   191,     0,     0,   116,     0,     4,
     117,     0,     0,    72,     0,   226,     4,     8,     9,     0,
       4,    56,     4,   253,   241,   250,     4,   237,   142,     0,
     139,   140,   213,   216,     4,     0,   220,     0,     0,     4,
       0,     0,     0,     4,   194,   124,     0,     0,     4,     4,
     125,     0,     0,   342,   295,   294,   298,   296,   297,   308,
     306,   305,   307,   312,   316,   320,   324,     0,   328,   358,
       4,     0,     4,     0,     0,   149,     0,   102,   104,   103,
     195,   175,     0,     0,   174,    51,    52,     4,    41,     4,
      42,   115,   113,   134,   130,   135,   136,     4,     0,   232,
       0,   228,     4,     4,     7,   257,   256,   330,     0,     0,
       4,   214,     4,   152,     4,     4,     0,   145,   121,     4,
       0,     0,     4,   165,     4,     0,     4,     0,     4,     4,
       4,   107,     4,   196,   178,     0,     0,     4,     0,     0,
     190,     0,     0,    72,     4,     4,     4,     4,     0,     0,
      11,     4,    13,    15,    17,    18,    19,    20,     0,    16,
       0,   141,   143,     4,     0,     0,     0,     0,     0,     4,
       0,     4,   167,   163,     4,   332,     4,     0,     4,     0,
       0,   148,     0,   179,     0,   176,   195,   187,   156,    37,
      39,    32,     4,     0,   231,     0,     0,     0,    72,     3,
      14,    22,     0,   223,    34,     0,    29,    30,     0,     4,
     164,     4,   166,   158,     4,   169,    33,    35,   189,   189,
       0,     0,     0,    25,    24,    23,     0,   221,   153,    31,
     161,   168,     0,   170,   180,   181,   177,   230,     4,     0,
       0,     4,     0,     4,     4,   159,   233,     4,    69,    70,
       0,     4,    63,    68,   162,    21,    64
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -424,  -424,    -4,  -424,  -424,  -424,  -424,  -424,  -424,    42,
    -424,  -424,  -424,  -421,  -389,     3,  -424,  -424,  -424,  -424,
     -32,  -424,  -424,  -424,  -176,   183,  -424,  -123,  -424,  -424,
    -424,   590,   -31,   346,  -230,     2,     0,  -166,  -424,   -34,
    -424,  -424,  -424,   196,   -13,  -424,  -424,  -424,   221,   115,
    -424,   405,  -368,    17,   -12,  -424,   657,  -424,   343,  -424,
    -322,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,    98,  -424,  -424,  -424,  -424,  -424,   365,  -143,   -99,
     277,    50,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
     292,  -424,  -424,  -424,  -424,  -178,    -8,   667,  -424,   273,
    -424,   474,  -424,   118,   308,   300,   -91,   252,    82,   440,
     269,   445,   266,   447,   271,   480,   275,   492,   274,  -424,
    -424,  -424,  -424,  -424,  -424,   -40,  -227,   599,    19,  -424,
    -424,  -423,   -41,   -96
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,    50,    51,    52,   459,   460,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,    53,    54,    55,    56,
     173,   178,   179,   442,   180,   346,   690,   314,    57,   691,
     315,    58,   692,   316,   181,   152,   193,    60,    61,    62,
      63,    64,    65,   428,   580,    66,    67,   325,   326,   148,
     395,   136,   396,   137,    68,   186,   139,   251,   265,   484,
      69,    70,    71,    72,   390,   606,   169,   523,   420,   672,
     487,   680,   614,   651,    73,    74,    75,    76,    77,   521,
     573,   574,   626,    78,    79,    80,   308,   309,   581,   266,
     485,   575,    81,    82,    83,    84,    85,   129,   130,   385,
     386,   477,    86,   195,   338,   252,    87,    88,    89,   255,
     347,    90,    91,    92,    93,    94,    95,    96,   280,    97,
     281,    98,   282,    99,   283,   100,   284,   101,   285,   102,
     286,   103,   287,   104,   288,   105,   289,   403,   106,   290,
     291,   162,   131,   107
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -362;
  const short int
  ParserImplementation::yytable_[] =
  {
        59,   166,   138,   126,   187,   138,   317,   190,   317,   175,
     246,   334,   138,   146,   339,   133,   141,   140,   245,   245,
     147,   256,   457,   245,   138,   245,   330,   245,   454,   124,
     138,   138,   380,   387,   306,   194,   245,   262,   269,   268,
     267,   158,   155,   391,   270,    39,   185,   245,   161,   307,
     400,   318,   164,   511,   245,   245,   448,    59,   279,   182,
     462,   263,   171,   423,   424,   245,   303,   245,   305,   245,
     245,   245,   310,   245,   171,   245,   245,   319,   172,    49,
     128,   453,   273,   323,   426,   583,   132,   565,   328,   458,
     174,   261,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   427,   165,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   401,   153,   558,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    39,   135,
     138,   313,   171,   217,   218,   516,   610,   149,   362,   363,
     364,   365,   366,   367,   124,   443,   217,   218,   527,   317,
      39,   168,   194,   295,   331,   297,   159,   160,   184,   348,
     264,   381,    49,   482,   431,   257,   258,   402,   464,   658,
     465,   138,   455,   296,   624,   138,   493,   254,   301,  -234,
     353,   264,   304,  -234,    49,   329,   279,   151,   425,   312,
     507,   154,   509,   653,   341,   432,   437,   449,    39,   343,
     327,   463,   469,   376,   335,   378,   562,   379,   563,   488,
     611,   612,   618,   150,   643,   383,   654,   667,   183,   349,
     599,   176,   351,   538,   388,   447,   670,   384,   235,   236,
     237,   238,    49,   475,   219,   134,   125,    11,    12,   229,
     230,   231,   232,   233,   404,   405,   406,   219,   407,   108,
     167,   138,   224,   225,   625,   138,   557,   272,   247,    18,
     489,   138,   688,   163,   138,   109,   177,   170,   110,   599,
     688,    45,   122,   434,   188,   535,   540,    25,    26,    27,
     182,   138,   138,    28,   196,    45,   122,    30,   248,   451,
     182,    32,   234,   397,   689,    34,   197,   408,   249,   239,
      45,   122,   689,    40,    41,   332,    42,   250,   167,   138,
     182,   182,   279,   494,   495,   496,   497,   498,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   156,
     436,   111,   517,   518,   519,   247,   247,   615,   444,   354,
     355,   356,   525,   473,   324,   526,   533,   241,   157,   142,
     177,   171,   240,   633,   242,    45,   122,   333,    45,   122,
     202,   317,   205,   317,   192,   337,   468,   529,   143,   259,
     138,   409,   410,   411,   412,   249,   249,   394,   253,    45,
     122,   138,   243,   244,   250,   250,   317,   264,   317,   317,
     271,   177,   279,   274,    45,   122,    45,   122,   534,   471,
     217,   218,   317,   317,   578,   441,   579,   470,   666,   138,
     182,   601,   267,   528,   530,   275,   541,   292,    45,   122,
     491,   492,   546,   144,   145,   515,   547,    45,   122,   605,
     293,   607,   608,   159,   160,   294,   138,   524,   397,   138,
     298,   138,   302,   317,   142,   619,   620,   417,   418,   532,
     177,   199,   544,   200,   201,    45,   122,    45,   122,   445,
     446,    45,   122,   143,   245,   327,   317,   299,   536,   300,
     182,   247,   311,   279,   138,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   200,   201,   648,   368,   369,   370,
     371,   499,   500,   501,   502,   429,   430,   199,   553,   203,
     204,   539,   641,   397,   221,   222,   223,   560,   561,   661,
     320,   249,   317,    45,   122,   674,   675,   693,   144,   145,
     250,   226,   227,   228,   321,   693,   359,   360,   361,   161,
     138,   567,   357,   358,   322,   600,   138,   336,   146,   663,
     664,   665,   627,   342,   634,   350,  -234,   352,   382,   668,
     384,   392,   393,   413,   414,   682,   415,   416,   419,   433,
     307,   438,   613,   440,   456,   602,   461,   452,   478,   604,
     621,   138,   466,   138,   138,   138,   467,   628,   161,   138,
     341,   146,   146,   146,   474,   617,   479,   146,   635,   636,
     637,   622,   480,   481,   486,   512,   522,   483,   513,   510,
     182,   514,   520,   550,   537,   542,   566,   551,   570,   548,
     564,   650,   552,   554,   652,   555,   556,   568,   655,   572,
     569,   609,   642,   278,   559,   571,   138,   576,   577,   582,
     603,   584,   638,   640,   629,   161,   630,   616,   631,   632,
     645,   639,   644,   646,   647,   545,   656,   198,   678,   649,
     657,   671,   669,   659,   673,   182,   683,   662,   676,   677,
     696,   439,   679,   681,   684,   686,   695,   123,   161,   531,
     450,   623,   389,   435,   490,   138,   660,   476,   127,   372,
     504,   685,   503,   146,   694,   373,   505,   245,   374,   220,
     635,   506,   508,     0,     0,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,     0,   112,     1,
       2,     0,   375,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,   377,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,    16,     0,
       0,   399,    17,     0,    18,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,   422,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,   142,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,   143,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,   585,     0,    44,
     586,     0,     0,    45,   587,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,     0,     0,     0,
      39,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,   122,     0,     0,
     588,   144,   145,     0,     0,     0,     0,     0,     0,     0,
     -10,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   399,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   399,   112,   399,     0,     0,     1,     2,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,   549,    25,
      26,    27,     0,     0,     0,    28,    29,   399,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    48,   191,     0,     1,     2,    49,   142,
     192,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   399,   585,
       0,    18,   586,     0,     0,     0,   587,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    39,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,    45,   122,
       0,     0,   588,   144,   145,    40,    41,     0,    42,     0,
       0,     0,   -12,     0,     0,     0,    49,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,   111,     0,     1,     2,     0,     0,   260,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,   111,     0,     1,     2,     0,     0,   472,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    -4,    14,
      15,     0,     0,    16,     0,     0,     0,    17,     0,    18,
       0,     0,     0,    19,     0,    20,     0,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,     0,
       0,    48,     1,     2,     0,     0,    49,     3,     4,     5,
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
     191,     1,     2,     0,    49,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,    14,    15,     0,     0,
      16,     0,     0,     0,    17,     0,    18,     0,     0,     0,
      19,     0,    20,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,     0,     0,    48,   340,
       1,     2,     0,    49,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,    14,    15,     0,     0,    16,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,    20,     0,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,  -189,     1,
       2,     0,    49,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,    16,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,     1,     2,     0,
       0,    49,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,    16,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,   687,     0,     0,   586,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,    48,   -57,     1,     2,     0,    49,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,    25,
      26,   687,     0,     0,   586,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    48,   -58,     1,     2,     0,    49,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      14,    15,     0,     0,    16,     0,     0,     0,     0,     0,
      18,     0,     0,     0,    19,     0,    20,     0,     0,    21,
      22,    23,     0,    24,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,    29,     0,     0,    30,     0,
      31,     0,    32,    33,     0,     0,    34,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    47,
       0,     0,    48,   -59,     1,     2,     0,    49,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    14,
      15,     0,     0,    16,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    19,     0,    20,     0,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,     0,
       0,    48,   -60,     1,     2,     0,    49,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   109,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,   276,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
     111,     1,     2,     0,     0,  -359,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   109,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,   111,     1,
       2,     0,     0,  -361,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,   344,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     1,     2,   111,     0,   345,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     1,
       2,   111,     0,  -361,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,   122,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     1,     2,   111,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     1,
       2,   111,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,   189,     0,   111,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,     0,     0,     0,
      30,     0,     0,     0,    32,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   398,     0,   111,     1,     2,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,   344,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       1,     2,   111,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     1,     2,   111,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       1,     2,   111,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,    10,    11,    12,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,   108,    28,
       0,     0,     0,    30,     0,     0,     0,    32,    18,     0,
       0,    34,     0,     0,   109,     0,     0,   110,     0,    40,
      41,     0,    42,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,     0,    45,     0,    30,     0,     0,     0,
      32,    10,    11,    12,    34,     0,   421,   111,     0,     0,
       0,     0,    40,    41,   108,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    45,     0,     0,
     109,     0,     0,   110,   125,   543,    12,     0,     0,     0,
     111,     0,    25,    26,    27,     0,     0,   108,    28,     0,
       0,     0,    30,     0,     0,     0,    32,    18,     0,     0,
      34,     0,     0,   109,     0,     0,   110,     0,    40,    41,
       0,    42,     0,     0,     0,    25,    26,    27,     0,     0,
       0,    28,     0,    45,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,   111,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         0,    35,    14,    11,    45,    17,   172,    47,   174,    41,
     106,   187,    24,    17,   192,    13,    16,    15,     3,     3,
      17,     3,    69,     3,    36,     3,     3,     3,     3,    10,
      42,    43,     3,   263,    57,    48,     3,   133,   137,   135,
       3,    24,    23,   273,   140,   113,    44,     3,    29,    72,
     277,   174,    33,   421,     3,     3,     3,    57,   149,    42,
       3,    47,   126,   293,   294,     3,   162,     3,   164,     3,
       3,     3,   168,     3,   126,     3,     3,   176,   142,   147,
       3,    47,    47,   182,    79,    47,    79,   510,   184,   136,
     142,   131,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    98,   142,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    28,   145,   486,     1,
       2,     3,     4,     5,     6,     7,     8,     9,   113,    14,
     142,   171,   126,    45,    46,    50,   559,    47,   229,   230,
     231,   232,   233,   234,   125,   321,    45,    46,   142,   315,
     113,    36,   165,   153,   131,   155,    49,    50,    43,   199,
     146,   132,   147,   393,   148,   147,   148,    79,   148,   145,
     148,   183,   147,   154,    63,   187,   403,   144,   159,   145,
     220,   146,   163,   145,   147,   185,   277,    79,   144,   170,
     417,    47,   419,   616,   194,   144,   144,   144,   113,   197,
     183,   144,   380,   243,   187,   245,   144,   247,   144,    28,
     144,   144,   144,   123,   144,   256,   144,   144,    47,   200,
     542,    79,   203,   453,   264,   324,   649,    74,    21,    22,
      23,    24,   147,    80,   146,    79,    47,    48,    49,    25,
      26,    27,    28,    29,    25,    26,    27,   146,    29,    60,
      79,   263,    35,    36,   143,   267,   483,   142,    49,    70,
      79,   273,   683,    47,   276,    76,   124,    47,    79,   591,
     691,   129,   130,   307,    47,   451,   454,    88,    89,    90,
     263,   293,   294,    94,     0,   129,   130,    98,    79,   330,
     273,   102,    78,   276,   683,   106,    59,    78,    89,    20,
     129,   130,   691,   114,   115,    79,   117,    98,    79,   321,
     293,   294,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,    79,
     311,   142,   428,   429,   430,    49,    49,   564,   321,   221,
     222,   223,   441,   383,    79,   444,    79,    18,    98,    60,
     124,   126,    19,   583,    17,   129,   130,   131,   129,   130,
      87,   527,    89,   529,   149,    79,    79,   142,    79,     3,
     382,    21,    22,    23,    24,    89,    89,    79,   144,   129,
     130,   393,    15,    16,    98,    98,   552,   146,   554,   555,
     110,   124,   483,    79,   129,   130,   129,   130,   131,   382,
      45,    46,   568,   569,   527,    79,   529,    79,   638,   421,
     393,    79,     3,   445,   446,    79,   456,    47,   129,   130,
     401,   402,   462,   134,   135,   425,   466,   129,   130,   552,
      47,   554,   555,    49,    50,    47,   448,   437,   421,   451,
     128,   453,    79,   609,    60,   568,   569,    15,    16,   449,
     124,    47,   460,    49,    50,   129,   130,   129,   130,   114,
     115,   129,   130,    79,     3,   448,   632,   128,   451,   128,
     453,    49,    47,   564,   486,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    49,    50,   609,   235,   236,   237,
     238,   409,   410,   411,   412,   299,   300,    47,   479,    49,
      50,    79,   598,   486,    37,    38,    39,   488,   489,   632,
      79,    89,   678,   129,   130,   658,   659,   683,   134,   135,
      98,    32,    33,    34,     3,   691,   226,   227,   228,   510,
     542,   512,   224,   225,   118,   543,   548,    79,   542,   635,
     636,   637,   576,   143,   584,    79,   145,    79,   145,   645,
      74,    47,    47,    20,    19,   678,    18,    17,     3,    47,
      72,   143,   562,   143,   145,   548,    79,   144,   144,   550,
     570,   583,   145,   585,   586,   587,   148,   577,   559,   591,
     580,   585,   586,   587,    47,   566,    47,   591,   585,   586,
     587,   572,   144,   144,     3,    28,    79,   146,   144,   147,
     583,   144,   142,    47,   142,   142,    28,   148,    66,   145,
     145,   611,   142,   142,   614,   142,   144,   142,   618,    56,
     142,   142,   603,   149,   147,    79,   638,   144,   144,   144,
      79,   145,    47,   591,   143,   616,   143,   147,   143,   142,
     144,   143,   143,   143,   143,   462,   143,    57,   142,   147,
     143,   651,   143,   145,   654,   638,   142,   144,   143,   143,
     691,   315,   144,   144,   144,   143,   143,    10,   649,   448,
     327,   573,   267,   308,   397,   687,   626,   385,    11,   239,
     414,   681,   413,   687,   684,   240,   415,     3,   241,    90,
     687,   416,   418,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,   244,    35,
      36,    -1,   242,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,   244,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,   277,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,   292,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    60,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    79,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    90,    -1,   125,
      93,    -1,    -1,   129,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,
     113,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,    -1,    -1,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,   474,    88,
      89,    90,    -1,    -1,    -1,    94,    95,   483,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   142,   143,    -1,    35,    36,   147,    60,
     149,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,   564,    90,
      -1,    70,    93,    -1,    -1,    -1,    97,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,   113,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,   129,   130,
      -1,    -1,   133,   134,   135,   114,   115,    -1,   117,    -1,
      -1,    -1,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    -1,    35,    36,    -1,    -1,   148,
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
      -1,    -1,   142,    -1,    35,    36,    -1,    -1,   148,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,    -1,
      -1,   142,    35,    36,    -1,    -1,   147,    40,    41,    42,
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
     143,    35,    36,    -1,   147,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   142,   143,
      35,    36,    -1,   147,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,    -1,    -1,   142,   143,    35,
      36,    -1,   147,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,    35,    36,    -1,
      -1,   147,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,   142,   143,    35,    36,    -1,   147,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   142,   143,    35,    36,    -1,   147,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,
      -1,    -1,   142,   143,    35,    36,    -1,   147,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,    -1,
      -1,   142,   143,    35,    36,    -1,   147,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    35,    36,    -1,    -1,   147,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,    35,
      36,    -1,    -1,   147,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    35,    36,   142,    -1,   144,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    35,
      36,   142,    -1,   144,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    35,    36,   142,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    35,
      36,   142,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,   142,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,   142,    35,    36,    -1,    -1,    -1,
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
      35,    36,   142,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    35,    36,   142,    -1,    -1,
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
      35,    36,   142,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    60,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    70,    -1,
      -1,   106,    -1,    -1,    76,    -1,    -1,    79,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,   129,    -1,    98,    -1,    -1,    -1,
     102,    47,    48,    49,   106,    -1,   108,   142,    -1,    -1,
      -1,    -1,   114,   115,    60,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,   129,    -1,    -1,
      76,    -1,    -1,    79,    47,    48,    49,    -1,    -1,    -1,
     142,    -1,    88,    89,    90,    -1,    -1,    60,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    70,    -1,    -1,
     106,    -1,    -1,    76,    -1,    -1,    79,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,   129,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142
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
     114,   115,   117,   122,   125,   129,   137,   139,   142,   147,
     151,   152,   153,   166,   167,   168,   169,   178,   181,   186,
     187,   188,   189,   190,   191,   192,   195,   196,   204,   210,
     211,   212,   213,   224,   225,   226,   227,   228,   233,   234,
     235,   242,   243,   244,   245,   246,   252,   256,   257,   258,
     261,   262,   263,   264,   265,   266,   267,   269,   271,   273,
     275,   277,   279,   281,   283,   285,   288,   293,    60,    76,
      79,   142,   261,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   130,   206,   288,    47,   256,   257,     3,   247,
     248,   292,    79,   185,    79,   199,   201,   203,   204,   206,
     185,   186,    60,    79,   134,   135,   152,   165,   199,    47,
     123,    79,   185,   145,    47,   288,    79,    98,   203,    49,
      50,   288,   291,    47,   288,   142,   189,    79,   199,   216,
      47,   126,   142,   170,   142,   170,    79,   124,   171,   172,
     174,   184,   203,    47,   199,   185,   205,   292,    47,   140,
     285,   143,   149,   186,   194,   253,     0,    59,   181,    47,
      49,    50,   259,    49,    50,   259,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   146,
     287,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    78,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   293,    49,    79,    89,
      98,   207,   255,   144,   144,   259,     3,   147,   148,     3,
     148,   285,   293,    47,   146,   208,   239,     3,   293,   239,
     293,   110,   199,    47,    79,    79,   108,   139,   261,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     289,   290,    47,    47,    47,   186,   288,   186,   128,   128,
     128,   288,    79,   293,   288,   293,    57,    72,   236,   237,
     293,    47,   288,   285,   177,   180,   183,   187,   177,   239,
      79,     3,   118,   239,    79,   197,   198,   203,   293,   186,
       3,   131,    79,   131,   174,   203,    79,    79,   254,   255,
     143,   186,   143,   185,   124,   144,   175,   260,   285,   288,
      79,   288,    79,   285,   263,   263,   263,   264,   264,   265,
     265,   265,   266,   266,   266,   266,   266,   266,   267,   267,
     267,   267,   269,   271,   273,   275,   285,   277,   285,   285,
       3,   132,   145,   292,    74,   249,   250,   184,   285,   201,
     214,   184,    47,    47,    79,   200,   202,   203,   140,   261,
     286,    28,    79,   287,    25,    26,    27,    29,    78,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     218,   108,   261,   184,   184,   144,    79,    98,   193,   193,
     193,   148,   144,    47,   189,   237,   288,   144,   143,   183,
     143,    79,   173,   174,   203,   114,   115,   239,     3,   144,
     208,   292,   144,    47,     3,   147,   145,    69,   136,   154,
     155,    79,     3,   144,   148,   148,   145,   148,    79,   255,
      79,   203,   148,   285,    47,    80,   250,   251,   144,    47,
     144,   144,   184,   146,   209,   240,     3,   220,    28,    79,
     240,   288,   288,   286,   266,   266,   266,   266,   266,   268,
     268,   268,   268,   270,   272,   274,   276,   286,   278,   286,
     147,   202,    28,   144,   144,   186,    50,   293,   293,   293,
     142,   229,    79,   217,   186,   239,   239,   142,   170,   142,
     170,   198,   186,    79,   131,   174,   203,   142,   184,    79,
     255,   285,   142,    48,   256,   175,   285,   285,   145,   261,
      47,   148,   142,   288,   142,   142,   144,   286,   202,   147,
     288,   288,   144,   144,   145,   291,    28,   288,   142,   142,
      66,    79,    56,   230,   231,   241,   144,   144,   177,   177,
     194,   238,   144,    47,   145,    90,    93,    97,   133,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   210,
     256,    79,   203,    79,   288,   177,   215,   177,   177,   142,
     291,   144,   144,   186,   222,   286,   147,   288,   144,   177,
     177,   186,   288,   231,    63,   143,   232,   189,   186,   143,
     143,   143,   142,   184,   285,   165,   165,   165,    47,   143,
     159,   293,   288,   144,   143,   144,   143,   143,   177,   147,
     186,   223,   186,   291,   144,   186,   143,   143,   145,   145,
     241,   177,   144,   293,   293,   293,   184,   144,   293,   143,
     291,   186,   219,   186,   238,   238,   143,   143,   142,   144,
     221,   144,   177,   142,   144,   186,   143,    90,   163,   164,
     176,   179,   182,   187,   186,   143,   182
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
     378,   379,   123,   125,    41,    58,    61,    59,    93,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   150,   151,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   158,   158,   159,   159,   159,   159,   159,
     159,   160,   161,   162,   163,   164,   165,   165,   165,   165,
     165,   165,   166,   167,   167,   168,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   171,   171,   171,   172,
     172,   172,   172,   173,   173,   174,   175,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   182,   182,
     182,   183,   184,   184,   185,   185,   186,   186,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     190,   191,   192,   192,   192,   193,   193,   193,   194,   194,
     195,   195,   195,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   203,   204,   204,
     204,   205,   205,   205,   205,   205,   205,   206,   207,   207,
     207,   207,   207,   207,   208,   209,   210,   211,   212,   212,
     212,   214,   215,   213,   216,   217,   213,   218,   219,   213,
     220,   221,   213,   213,   213,   222,   213,   223,   213,   213,
     213,   224,   225,   226,   227,   228,   229,   229,   230,   230,
     231,   232,   233,   234,   235,   235,   235,   236,   237,   238,
     238,   239,   239,   240,   240,   241,   241,   242,   242,   242,
     242,   242,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   246,   246,   246,   246,   247,   247,   248,   248,   249,
     249,   250,   251,   251,   252,   253,   253,   253,   254,   254,
     254,   254,   254,   254,   255,   255,   255,   255,   256,   256,
     256,   256,   256,   256,   256,   256,   257,   257,   258,   258,
     258,   258,   259,   259,   260,   260,   260,   260,   261,   261,
     261,   261,   262,   262,   262,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   264,   264,   264,   264,   265,
     265,   265,   266,   266,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   268,   268,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   270,   270,   270,   270,   270,   271,
     271,   272,   272,   273,   273,   274,   274,   275,   275,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   283,   283,   284,   284,   284,   285,
     285,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   288,   288,   289,   289,   290,
     290,   291,   291,   292,   292,   293,   293
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     1,     7,     0,     1,     0,     2,     1,     1,
       0,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     7,     2,     3,     3,     3,     1,     2,     1,     7,
       7,     8,     7,     8,     8,     8,     1,     7,     4,     7,
       4,     5,     5,     2,     2,     2,     1,     1,     3,     2,
       2,     4,     4,     0,     1,     2,     2,     0,     1,     0,
       1,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     2,     5,     5,     5,     1,     1,     3,     1,     2,
       3,     3,     3,     5,     1,     3,     2,     2,     1,     3,
       1,     3,     2,     2,     2,     2,     1,     1,     3,     3,
       5,     2,     2,     2,     4,     4,     4,     3,     1,     3,
       3,     5,     3,     5,     2,     2,     1,     2,     7,     5,
       3,     0,     0,     9,     0,     0,     7,     0,     0,    11,
       0,     0,    12,     7,     8,     0,     8,     0,     9,     8,
       9,     3,     3,     3,     5,     5,     3,     5,     1,     2,
       4,     3,     3,     3,     3,     3,     4,     5,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     5,     6,     2,     4,     1,     2,     1,
       2,     6,     0,     4,     3,     1,     3,     2,     3,     1,
       7,     5,     3,     9,     1,     1,     1,     3,     1,     1,
       1,     4,     4,     3,     3,     3,     1,     2,     2,     2,
       4,     3,     2,     3,     1,     1,     3,     3,     1,     1,
       1,     3,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     5,     1,     2,     2,     1,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     0,
       1,     0,     1,     0,     1,     1,     1
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
  "JS_PROPERTY", "JS_YIELD", "JS_YIELD_SENTINEL", "EX_TOKEN_YIELD", "'{'",
  "'}'", "')'", "':'", "'='", "';'", "']'", "'@'", "$accept", "program",
  "class_initialiser", "class_adjective__opt", "inherit_declaration__opt",
  "inherit_declaration", "class_body__opt", "class_body",
  "class_element_list", "class_element", "constructor_definition",
  "prototype_property_definition", "class_property_definition",
  "instance_property_definition", "private_property_definition",
  "exportable_definition", "version_statement", "function_declaration",
  "function_expression", "arrow_function_expression",
  "shorten_function_body", "formal_parameter_list_with_rest",
  "formal_parameter_list", "formal_parameter_rest__opt",
  "formal_parameter_rest", "arguments_spread", "constructor_function_body",
  "function_body", "source_elements", "source_elements_for_constructor",
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
  "iteration_statement", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "continue_statement", "break_statement",
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
       151,     0,    -1,   178,    -1,   153,    59,   185,   154,   142,
     156,   143,    -1,    -1,    60,    -1,    -1,   155,   256,    -1,
      69,    -1,   136,    -1,    -1,   157,    -1,   158,    -1,   159,
      -1,   158,   159,    -1,   160,    -1,   210,    -1,   161,    -1,
     162,    -1,   163,    -1,   164,    -1,   133,    47,   184,   144,
     142,   176,   143,    -1,   165,   293,    -1,    97,   165,   293,
      -1,    93,   165,   293,    -1,    90,   165,   293,    -1,   199,
      -1,    60,   199,    -1,   152,    -1,    79,    47,   184,   144,
     142,   177,   143,    -1,   134,    79,    47,   144,   142,   177,
     143,    -1,   135,    79,    47,   184,   144,   142,   177,   143,
      -1,   137,    47,    79,   144,   142,   238,   143,    -1,    76,
      79,    47,   184,   144,   142,   177,   143,    -1,    60,    79,
      47,   184,   144,   142,   177,   143,    -1,    76,   185,    47,
     184,   144,   142,   177,   143,    -1,   169,    -1,   117,   184,
     118,   114,   142,   177,   143,    -1,   114,   142,   177,   143,
      -1,   117,   184,   118,   115,   142,   177,   143,    -1,   115,
     142,   177,   143,    -1,   117,   184,   118,   114,   170,    -1,
     117,   184,   118,   115,   170,    -1,   115,   170,    -1,   114,
     170,    -1,   126,   285,    -1,   172,    -1,   174,    -1,   172,
       3,   173,    -1,    79,   239,    -1,   203,   239,    -1,   172,
       3,    79,   239,    -1,   172,     3,   203,   239,    -1,    -1,
     174,    -1,   124,    79,    -1,   124,    79,    -1,    -1,   179,
      -1,    -1,   180,    -1,   181,    -1,   178,   181,    -1,   182,
      -1,   179,   182,    -1,   183,    -1,   180,   183,    -1,   186,
      -1,   187,    -1,   163,    -1,   164,    -1,   187,    -1,    -1,
     171,    -1,    -1,    79,    -1,   187,    -1,   190,    -1,   191,
      -1,   189,    -1,   188,    -1,   195,    -1,   167,    -1,   196,
      -1,   210,    -1,   211,    -1,   212,    -1,   213,    -1,   224,
      -1,   225,    -1,   226,    -1,   227,    -1,   233,    -1,   228,
      -1,   234,    -1,   235,    -1,   192,    -1,   166,    -1,   142,
     143,    -1,   142,   194,   143,    -1,   125,   185,   186,    -1,
      68,   165,    -1,    83,    79,   128,   193,   293,    -1,    83,
     203,   128,   193,   293,    -1,    83,    98,   128,   193,   293,
      -1,    98,    -1,    79,    -1,   193,    50,    79,    -1,   186,
      -1,   194,   186,    -1,   108,   199,   293,    -1,    60,   199,
     293,    -1,   122,   199,   293,    -1,   122,    47,   197,   144,
     186,    -1,   198,    -1,   197,     3,   198,    -1,    79,   239,
      -1,   203,   208,    -1,   201,    -1,   199,     3,   201,    -1,
     202,    -1,   200,     3,   202,    -1,    79,   239,    -1,   203,
     239,    -1,    79,   240,    -1,   203,   240,    -1,   204,    -1,
     206,    -1,   129,   292,   131,    -1,   129,   205,   131,    -1,
     129,   205,     3,   292,   131,    -1,   292,    79,    -1,   292,
     174,    -1,   292,   203,    -1,   205,     3,   292,    79,    -1,
     205,     3,   292,   174,    -1,   205,     3,   292,   203,    -1,
     130,   207,   132,    -1,    79,    -1,   255,   145,    79,    -1,
     255,   145,   203,    -1,   207,     3,   255,   145,    79,    -1,
     207,     3,    79,    -1,   207,     3,   255,   145,   203,    -1,
     146,   285,    -1,   146,   286,    -1,   293,    -1,   288,   293,
      -1,    80,    47,   288,   144,   186,    66,   186,    -1,    80,
      47,   288,   144,   186,    -1,    81,   288,   186,    -1,    -1,
      -1,    64,   186,   110,   214,    47,   288,   215,   144,   293,
      -1,    -1,    -1,   110,   216,    47,   288,   217,   144,   186,
      -1,    -1,    -1,    74,    47,   290,   218,   147,   291,   147,
     291,   219,   144,   186,    -1,    -1,    -1,    74,    47,   108,
     200,   220,   147,   291,   147,   291,   221,   144,   186,    -1,
      74,    47,   261,    28,   288,   144,   186,    -1,    74,    47,
     108,   202,    28,   288,   144,   186,    -1,    -1,    74,    47,
     261,    79,   288,   144,   222,   186,    -1,    -1,    74,    47,
     108,   202,    79,   288,   144,   223,   186,    -1,    74,   123,
      47,   261,    28,   288,   144,   186,    -1,    74,   123,    47,
     108,   202,    28,   288,   144,   186,    -1,    61,   185,   293,
      -1,    54,   185,   293,    -1,    95,   291,   293,    -1,   111,
      47,   288,   144,   186,    -1,   100,    47,   288,   144,   229,
      -1,   142,   241,   143,    -1,   142,   241,   232,   241,   143,
      -1,   231,    -1,   230,   231,    -1,    56,   288,   145,   238,
      -1,    63,   145,   238,    -1,    79,   145,   186,    -1,   103,
     288,   293,    -1,   107,   189,   236,    -1,   107,   189,   237,
      -1,   107,   189,   236,   237,    -1,    57,    47,    79,   144,
     189,    -1,    72,   189,    -1,    -1,   194,    -1,    -1,   208,
      -1,    -1,   209,    -1,    -1,   230,    -1,   243,    -1,   244,
      -1,    89,    -1,    98,    -1,    94,    -1,    88,    -1,   106,
      -1,    70,    -1,   102,    -1,    79,    -1,   242,    -1,   246,
      -1,   252,    -1,    47,   288,   144,    -1,    49,   292,   148,
      -1,    49,   247,   148,    -1,    49,   247,     3,   292,   148,
      -1,    49,   247,   147,   249,   251,   148,    -1,   292,   285,
      -1,   247,     3,   292,   285,    -1,     3,    -1,   248,     3,
      -1,   250,    -1,   249,   250,    -1,    74,    47,   261,    79,
     288,   144,    -1,    -1,    80,    47,   288,   144,    -1,   142,
     253,   143,    -1,   149,    -1,   149,   254,   147,    -1,   149,
     254,    -1,   255,   145,   285,    -1,    79,    -1,    79,    47,
     184,   144,   142,   177,   143,    -1,   254,     3,   255,   145,
     285,    -1,   254,     3,    79,    -1,   254,     3,    79,    47,
     184,   144,   142,   177,   143,    -1,    79,    -1,    98,    -1,
      89,    -1,    49,   285,   148,    -1,   245,    -1,   168,    -1,
     152,    -1,   256,    49,   288,   148,    -1,    90,    49,   288,
     148,    -1,    90,    50,    79,    -1,   256,    50,    79,    -1,
      48,   256,   259,    -1,   256,    -1,    48,   257,    -1,   256,
     259,    -1,   258,   259,    -1,   258,    49,   288,   148,    -1,
     258,    50,    79,    -1,    47,   144,    -1,    47,   260,   144,
      -1,   285,    -1,   175,    -1,   260,     3,   285,    -1,   260,
       3,   175,    -1,   257,    -1,   258,    -1,   204,    -1,    47,
     206,   144,    -1,   261,    -1,   261,    46,    -1,   261,    45,
      -1,   262,    -1,    42,   263,    -1,    43,   263,    -1,    44,
     263,    -1,    46,   263,    -1,    45,   263,    -1,    35,   263,
      -1,    36,   263,    -1,    41,   263,    -1,    40,   263,    -1,
     263,    -1,   264,    37,   263,    -1,   264,    38,   263,    -1,
     264,    39,   263,    -1,   264,    -1,   265,    35,   264,    -1,
     265,    36,   264,    -1,   265,    -1,   266,    34,   265,    -1,
     266,    33,   265,    -1,   266,    32,   265,    -1,   266,    -1,
     267,    26,   266,    -1,   267,    25,   266,    -1,   267,    29,
     266,    -1,   267,    78,   266,    -1,   267,    27,   266,    -1,
     267,    28,   266,    -1,   266,    -1,   268,    26,   266,    -1,
     268,    25,   266,    -1,   268,    29,   266,    -1,   268,    78,
     266,    -1,   268,    27,   266,    -1,   267,    -1,   269,    23,
     267,    -1,   269,    22,   267,    -1,   269,    24,   267,    -1,
     269,    21,   267,    -1,   268,    -1,   270,    23,   268,    -1,
     270,    22,   268,    -1,   270,    24,   268,    -1,   270,    21,
     268,    -1,   269,    -1,   271,    20,   269,    -1,   270,    -1,
     272,    20,   270,    -1,   271,    -1,   273,    19,   271,    -1,
     272,    -1,   274,    19,   272,    -1,   273,    -1,   275,    18,
     273,    -1,   274,    -1,   276,    18,   274,    -1,   275,    -1,
     277,    17,   275,    -1,   276,    -1,   278,    17,   276,    -1,
     277,    -1,   279,    16,   277,    -1,   278,    -1,   280,    16,
     278,    -1,   279,    -1,   279,    15,   285,   145,   285,    -1,
     280,    -1,   280,    15,   286,   145,   286,    -1,   281,    -1,
     139,   140,    -1,   139,   285,    -1,   282,    -1,   139,   140,
      -1,   139,   286,    -1,   283,    -1,   261,   287,   285,    -1,
     284,    -1,   261,   287,   286,    -1,   146,    -1,    10,    -1,
      12,    -1,    11,    -1,    14,    -1,     5,    -1,     7,    -1,
       6,    -1,     4,    -1,    13,    -1,     9,    -1,     8,    -1,
     285,    -1,   288,     3,   285,    -1,   286,    -1,   289,     3,
     286,    -1,    -1,   289,    -1,    -1,   288,    -1,    -1,   248,
      -1,   147,    -1,   113,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     5,    13,    14,    16,    17,    20,    22,
      24,    25,    27,    29,    31,    34,    36,    38,    40,    42,
      44,    46,    54,    57,    61,    65,    69,    71,    74,    76,
      84,    92,   101,   109,   118,   127,   136,   138,   146,   151,
     159,   164,   170,   176,   179,   182,   185,   187,   189,   193,
     196,   199,   204,   209,   210,   212,   215,   218,   219,   221,
     222,   224,   226,   229,   231,   234,   236,   239,   241,   243,
     245,   247,   249,   250,   252,   253,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   302,
     306,   310,   313,   319,   325,   331,   333,   335,   339,   341,
     344,   348,   352,   356,   362,   364,   368,   371,   374,   376,
     380,   382,   386,   389,   392,   395,   398,   400,   402,   406,
     410,   416,   419,   422,   425,   430,   435,   440,   444,   446,
     450,   454,   460,   464,   470,   473,   476,   478,   481,   489,
     495,   499,   500,   501,   511,   512,   513,   521,   522,   523,
     535,   536,   537,   550,   558,   567,   568,   577,   578,   588,
     597,   607,   611,   615,   619,   625,   631,   635,   641,   643,
     646,   651,   655,   659,   663,   667,   671,   676,   682,   685,
     686,   688,   689,   691,   692,   694,   695,   697,   699,   701,
     703,   705,   707,   709,   711,   713,   715,   717,   719,   721,
     723,   727,   731,   735,   741,   748,   751,   756,   758,   761,
     763,   766,   773,   774,   779,   783,   785,   789,   792,   796,
     798,   806,   812,   816,   826,   828,   830,   832,   836,   838,
     840,   842,   847,   852,   856,   860,   864,   866,   869,   872,
     875,   880,   884,   887,   891,   893,   895,   899,   903,   905,
     907,   909,   913,   915,   918,   921,   923,   926,   929,   932,
     935,   938,   941,   944,   947,   950,   952,   956,   960,   964,
     966,   970,   974,   976,   980,   984,   988,   990,   994,   998,
    1002,  1006,  1010,  1014,  1016,  1020,  1024,  1028,  1032,  1036,
    1038,  1042,  1046,  1050,  1054,  1056,  1060,  1064,  1068,  1072,
    1074,  1078,  1080,  1084,  1086,  1090,  1092,  1096,  1098,  1102,
    1104,  1108,  1110,  1114,  1116,  1120,  1122,  1126,  1128,  1132,
    1134,  1140,  1142,  1148,  1150,  1153,  1156,  1158,  1161,  1164,
    1166,  1170,  1172,  1176,  1178,  1180,  1182,  1184,  1186,  1188,
    1190,  1192,  1194,  1196,  1198,  1200,  1202,  1206,  1208,  1212,
    1213,  1215,  1216,  1218,  1219,  1221,  1223
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   374,   374,   385,   397,   398,   403,   404,   420,   421,
     426,   427,   431,   436,   457,   481,   487,   488,   489,   490,
     491,   496,   511,   521,   531,   540,   550,   551,   558,   559,
     570,   582,   597,   611,   628,   644,   653,   666,   675,   684,
     694,   704,   714,   725,   736,   750,   761,   762,   768,   786,
     802,   812,   822,   834,   835,   844,   861,   871,   872,   876,
     877,   881,   889,   900,   908,   919,   927,   937,   942,   943,
     944,   949,   953,   954,   961,   962,   971,   972,   977,   985,
     990,   994,   999,  1006,  1010,  1015,  1020,  1025,  1030,  1035,
    1040,  1045,  1050,  1055,  1060,  1065,  1070,  1074,  1081,  1088,
    1099,  1112,  1124,  1141,  1156,  1176,  1184,  1192,  1202,  1210,
    1221,  1229,  1237,  1248,  1258,  1264,  1271,  1279,  1290,  1298,
    1308,  1314,  1322,  1330,  1341,  1349,  1361,  1365,  1372,  1382,
    1389,  1402,  1414,  1423,  1433,  1444,  1452,  1463,  1474,  1484,
    1497,  1507,  1518,  1527,  1538,  1542,  1546,  1550,  1564,  1573,
    1582,  1595,  1597,  1594,  1606,  1607,  1605,  1615,  1616,  1615,
    1628,  1629,  1628,  1641,  1652,  1665,  1664,  1685,  1684,  1705,
    1716,  1730,  1740,  1750,  1760,  1771,  1782,  1786,  1795,  1801,
    1809,  1820,  1831,  1844,  1854,  1863,  1872,  1884,  1895,  1903,
    1904,  1908,  1909,  1913,  1914,  1918,  1919,  1923,  1924,  1925,
    1932,  1939,  1949,  1959,  1966,  1976,  1983,  1990,  1991,  1992,
    1993,  2001,  2011,  2018,  2028,  2042,  2052,  2063,  2064,  2069,
    2075,  2083,  2096,  2097,  2106,  2120,  2124,  2128,  2135,  2144,
    2156,  2171,  2178,  2189,  2206,  2213,  2220,  2227,  2237,  2241,
    2245,  2250,  2263,  2275,  2290,  2305,  2321,  2322,  2332,  2345,
    2358,  2371,  2389,  2390,  2394,  2400,  2406,  2411,  2419,  2420,
    2421,  2422,  2426,  2430,  2437,  2447,  2448,  2455,  2462,  2469,
    2476,  2483,  2490,  2497,  2504,  2514,  2515,  2519,  2523,  2530,
    2531,  2535,  2542,  2543,  2547,  2551,  2558,  2559,  2563,  2567,
    2571,  2575,  2579,  2586,  2587,  2591,  2595,  2599,  2603,  2610,
    2611,  2615,  2619,  2623,  2630,  2631,  2635,  2639,  2643,  2650,
    2651,  2658,  2659,  2666,  2667,  2674,  2675,  2682,  2683,  2690,
    2691,  2698,  2699,  2706,  2707,  2714,  2715,  2722,  2723,  2730,
    2731,  2740,  2741,  2750,  2751,  2756,  2766,  2767,  2772,  2782,
    2786,  2796,  2800,  2811,  2812,  2813,  2814,  2815,  2816,  2817,
    2818,  2819,  2820,  2821,  2822,  2826,  2833,  2841,  2848,  2856,
    2857,  2861,  2862,  2866,  2867,  2871,  2872
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
      47,   144,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   145,   147,
      26,   146,    25,    15,   149,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   148,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   142,    18,   143,    41,     2,     2,     2,
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
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3599;
  const int ParserImplementation::yynnts_ = 144;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 196;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 150;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 379;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 6207 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2875 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


