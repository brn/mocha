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
#line 654 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 668 "grammar/grammar.yy"
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
#line 677 "grammar/grammar.yy"
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
#line 686 "grammar/grammar.yy"
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
#line 696 "grammar/grammar.yy"
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
#line 706 "grammar/grammar.yy"
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
#line 716 "grammar/grammar.yy"
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
#line 727 "grammar/grammar.yy"
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
#line 738 "grammar/grammar.yy"
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
#line 752 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 762 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 764 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 770 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 788 "grammar/grammar.yy"
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
#line 804 "grammar/grammar.yy"
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
#line 814 "grammar/grammar.yy"
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
#line 824 "grammar/grammar.yy"
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
#line 835 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 836 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 846 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 863 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 872 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 873 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 877 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 878 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 883 "grammar/grammar.yy"
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
#line 891 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 902 "grammar/grammar.yy"
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
#line 910 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 921 "grammar/grammar.yy"
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
#line 929 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 938 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 940 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 950 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 952 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 958 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 959 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 964 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 966 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 975 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 977 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 983 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 985 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 993 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 995 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 1000 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1008 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1012 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1017 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1022 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1026 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1031 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1036 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1041 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1046 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1051 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1056 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1061 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1066 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1071 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1076 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1081 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1086 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1090 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1097 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1104 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1115 "grammar/grammar.yy"
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
#line 1128 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1140 "grammar/grammar.yy"
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
#line 1157 "grammar/grammar.yy"
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
#line 1172 "grammar/grammar.yy"
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
#line 1192 "grammar/grammar.yy"
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
#line 1200 "grammar/grammar.yy"
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
#line 1208 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1218 "grammar/grammar.yy"
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
#line 1226 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1237 "grammar/grammar.yy"
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
#line 1245 "grammar/grammar.yy"
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
#line 1253 "grammar/grammar.yy"
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
#line 1264 "grammar/grammar.yy"
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
#line 1274 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1280 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1287 "grammar/grammar.yy"
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
#line 1295 "grammar/grammar.yy"
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
#line 1306 "grammar/grammar.yy"
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
#line 1314 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1324 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1330 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar/grammar.yy"
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
#line 1346 "grammar/grammar.yy"
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
#line 1357 "grammar/grammar.yy"
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
#line 1365 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1377 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1381 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1388 "grammar/grammar.yy"
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
#line 1398 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1405 "grammar/grammar.yy"
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
#line 1418 "grammar/grammar.yy"
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
#line 1430 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1439 "grammar/grammar.yy"
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

  case 136:

/* Line 690 of lalr1.cc  */
#line 1449 "grammar/grammar.yy"
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

  case 137:

/* Line 690 of lalr1.cc  */
#line 1460 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1468 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1479 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1490 "grammar/grammar.yy"
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

  case 141:

/* Line 690 of lalr1.cc  */
#line 1500 "grammar/grammar.yy"
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

  case 142:

/* Line 690 of lalr1.cc  */
#line 1513 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1523 "grammar/grammar.yy"
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

  case 144:

/* Line 690 of lalr1.cc  */
#line 1534 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(3) - (3)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1543 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1553 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1557 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1561 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1566 "grammar/grammar.yy"
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

  case 150:

/* Line 690 of lalr1.cc  */
#line 1580 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1589 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1598 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    stmt->Then( (yysemantic_stack_[(3) - (3)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1610 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1612 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1613 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(9) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(9) - (6)].expression) );
    iter->AddChild( (yysemantic_stack_[(9) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1622 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1623 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (4)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1630 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1631 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1632 "grammar/grammar.yy"
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

  case 162:

/* Line 690 of lalr1.cc  */
#line 1643 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1644 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1645 "grammar/grammar.yy"
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

  case 165:

/* Line 690 of lalr1.cc  */
#line 1657 "grammar/grammar.yy"
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

  case 166:

/* Line 690 of lalr1.cc  */
#line 1668 "grammar/grammar.yy"
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

  case 167:

/* Line 690 of lalr1.cc  */
#line 1680 "grammar/grammar.yy"
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

  case 168:

/* Line 690 of lalr1.cc  */
#line 1691 "grammar/grammar.yy"
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

  case 169:

/* Line 690 of lalr1.cc  */
#line 1705 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1715 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1725 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1735 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1746 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1757 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1761 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1770 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1776 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1784 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1806 "grammar/grammar.yy"
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

  case 181:

/* Line 690 of lalr1.cc  */
#line 1819 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1829 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1838 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1847 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1859 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1870 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1877 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1878 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1883 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1887 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1888 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1892 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1893 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1897 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1898 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1900 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1907 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1941 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1951 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1958 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1964 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1965 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1966 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1968 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1976 "grammar/grammar.yy"
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

  case 210:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1993 "grammar/grammar.yy"
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

  case 212:

/* Line 690 of lalr1.cc  */
#line 2003 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar/grammar.yy"
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

  case 214:

/* Line 690 of lalr1.cc  */
#line 2024 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2041 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2049 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2056 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2065 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2067 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2076 "grammar/grammar.yy"
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

  case 223:

/* Line 690 of lalr1.cc  */
#line 2090 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2094 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2098 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2105 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2114 "grammar/grammar.yy"
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

  case 228:

/* Line 690 of lalr1.cc  */
#line 2126 "grammar/grammar.yy"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2141 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2148 "grammar/grammar.yy"
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2159 "grammar/grammar.yy"
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

  case 232:

/* Line 690 of lalr1.cc  */
#line 2176 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2183 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2190 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2200 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2204 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2208 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 238:

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

  case 239:

/* Line 690 of lalr1.cc  */
#line 2226 "grammar/grammar.yy"
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

  case 240:

/* Line 690 of lalr1.cc  */
#line 2238 "grammar/grammar.yy"
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

  case 241:

/* Line 690 of lalr1.cc  */
#line 2253 "grammar/grammar.yy"
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

  case 242:

/* Line 690 of lalr1.cc  */
#line 2268 "grammar/grammar.yy"
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

  case 243:

/* Line 690 of lalr1.cc  */
#line 2283 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2285 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2295 "grammar/grammar.yy"
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

  case 246:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
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

  case 247:

/* Line 690 of lalr1.cc  */
#line 2321 "grammar/grammar.yy"
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

  case 248:

/* Line 690 of lalr1.cc  */
#line 2334 "grammar/grammar.yy"
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

  case 249:

/* Line 690 of lalr1.cc  */
#line 2351 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2352 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2357 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2363 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2369 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2374 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2381 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2382 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2383 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2384 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2389 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2393 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2400 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2409 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2411 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2418 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2425 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2432 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2439 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2446 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2453 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2460 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2467 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2476 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2478 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2482 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2486 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2492 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2494 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2498 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2504 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2506 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2510 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2514 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2520 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2522 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2526 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2530 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2534 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2538 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2542 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2548 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2550 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2554 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2558 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2562 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2566 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2572 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2574 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2578 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2582 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2592 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2594 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2598 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2602 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2606 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2612 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2614 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2620 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2622 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2628 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2630 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2636 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2644 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2646 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2652 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2654 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2660 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2662 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2668 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2670 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2676 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2678 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2684 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2686 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2692 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2694 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2702 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2704 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2712 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2714 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2718 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2726 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2728 "grammar/grammar.yy"
    {
    (yyval.ast) = ManagedHandle::Retain<YieldExp>();
  }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2732 "grammar/grammar.yy"
    {
    YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = yield_exp;
  }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2741 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2745 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2755 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2759 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2769 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2770 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2771 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2772 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2773 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2774 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2775 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2776 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2777 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2778 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2779 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2780 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2785 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2792 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2800 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2807 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2814 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2815 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2819 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2820 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2824 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2825 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2829 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2830 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4353 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -541;
  const short int
  ParserImplementation::yypact_[] =
  {
      1731,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,
    2809,  3672,   103,    52,   140,    52,  1839,   365,  -541,    80,
      65,    18,   101,  3340,    17,  -541,  -541,    64,  -541,  2914,
    -541,   161,  -541,  3340,  -541,    90,   150,  -541,   204,  -541,
      62,   120,   240,   181,    52,   103,   225,  3019,   855,  -541,
     316,  -541,   273,  -541,  -541,  -541,  -541,  1188,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,   206,  -541,   318,
     317,  -541,  -541,   353,   209,   457,   323,   373,   298,   315,
     325,   337,    94,  -541,  -541,  -541,    24,  -541,  -541,    52,
    -541,   207,   220,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,    37,   216,    30,  3340,   206,  -541,  -541,     5,
     369,   970,  -541,    -9,   -18,    36,  -541,   228,  -541,  -541,
      -9,   150,   266,   150,    53,   303,   306,  -541,  -541,   384,
    2383,   361,   376,   379,  1839,  3340,   676,   300,   302,   304,
    3340,   360,   443,    -9,  3340,    24,  1296,   152,   228,    36,
     402,  3340,  3340,  2165,  -541,  2165,  -541,   228,   372,  -541,
     454,  -541,   341,   228,   159,    36,  1839,    39,   119,   382,
    -541,  -541,  -541,    44,  -541,  1405,   321,  -541,    52,  -541,
    2599,  3340,   403,  -541,  3340,   414,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  3340,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,
    3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,
    3550,  3550,  3550,  3550,  3340,  3550,  3340,  -541,   356,  -541,
    -541,    70,   362,  -541,  -541,  -541,   103,    82,  -541,   374,
     425,  -541,  -541,  -541,  -541,   240,  3340,  -541,  -541,   150,
    -541,  -541,  -541,  -541,   384,   240,   474,   476,   259,  3127,
      79,   457,   332,   488,   506,   508,   510,   514,   262,  -541,
    -541,  -541,   529,  -541,  3583,   240,   240,  -541,    38,  -541,
      60,    60,    60,     6,  -541,  -541,    41,  -541,   486,    90,
     467,  -541,  -541,  3340,    49,  -541,  -541,   399,  2274,  -541,
    -541,   404,  -541,  -541,   254,   172,  -541,   228,    66,  -541,
     228,  -541,  -541,   103,  -541,  -541,  -541,  -541,  -541,   411,
       7,     9,   412,  -541,  -541,  -541,    33,   477,  -541,  -541,
      69,  -541,    27,  -541,    31,  -541,  -541,  -541,  -541,  -541,
     353,   353,   209,   209,   209,   457,   457,   457,   457,   457,
     457,   323,   323,   323,   323,   373,   298,   315,   325,   413,
     337,  -541,   128,  -541,   355,  1079,  3639,   513,  -541,   516,
    -541,   420,  -541,  -541,   518,   423,   426,   240,   437,   587,
     563,   437,  -541,   317,  -541,  3340,  3445,  3550,  3550,  3550,
    3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,  3550,
    3445,  3550,  3445,   445,   259,   565,   450,   452,  1839,  -541,
    -541,    47,    47,    47,  -541,   455,   521,  -541,  -541,   443,
    1839,  -541,  -541,  -541,   228,  -541,  -541,   228,   121,   126,
    -541,   159,  1839,  -541,   211,   459,   240,   144,  -541,  3340,
    -541,  -541,   463,  3728,  -541,  3235,  -541,  -541,  -541,  3340,
     356,   461,  -541,  -541,  -541,  -541,   579,  3639,  3340,   466,
    3340,   471,   475,   465,  3445,  -541,  -541,   259,   472,  3340,
    -541,    71,  -541,   457,   457,   457,   457,   457,   332,   332,
     332,   332,   488,   506,   508,   510,   473,   514,  -541,  2491,
     583,  3340,   478,   479,   556,   545,  -541,  -541,  -541,   569,
    -541,   482,   484,  -541,  -541,  -541,  2165,  -541,  2165,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  1514,   485,    61,   487,
    -541,   345,  3728,   349,  -541,  -541,  -541,   357,  3340,   603,
      72,  2165,   443,  2165,  2165,   491,  -541,  -541,  2491,    74,
    1839,  3445,   489,  3340,    77,  2165,  2165,  1839,  -541,  3340,
     569,  -541,    48,    90,  1839,   492,   494,  1623,   496,   498,
     240,  3340,   365,   365,   365,   594,   499,  -541,   469,  -541,
    -541,  -541,  -541,  -541,  -541,    -9,  -541,   206,  -541,  -541,
      78,  3340,  -541,   500,   490,   501,   502,  2165,   503,  1839,
    -541,  -541,  2704,    91,  1839,   504,   505,  -541,    20,  -541,
     507,  -541,   569,  -541,  -541,  -541,  -541,  -541,  2165,   509,
    -541,    -9,    -9,    -9,   240,  -541,  -541,  -541,  -541,    92,
    -541,    -9,  -541,  -541,   511,  2704,  -541,  -541,  1839,  -541,
    -541,  -541,  1623,  1623,   512,   515,   517,  -541,  -541,  -541,
     519,  -541,  -541,  -541,  -541,   520,  -541,  -541,  -541,  -541,
    -541,  2165,   523,   522,  1839,   524,  1947,  1839,  -541,  -541,
     287,  -541,  -541,  -541,   525,  2056,  -541,  -541,  -541,  -541,
    -541
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   360,    77,     5,    77,     4,     4,   202,     0,
      77,   204,     0,     4,     0,   200,   197,     0,   199,   358,
     198,     0,   203,     4,   201,     0,     0,   156,     0,   363,
       0,     0,    75,     0,    77,   360,     0,     4,     4,   362,
       0,   237,     0,    99,    68,   236,    36,     2,    61,    67,
      79,    83,    82,    80,    81,    98,    84,    85,   257,    86,
      87,    88,    89,    90,    91,    92,    93,    95,    94,    96,
      97,   205,   195,   196,   235,   206,   207,   243,   255,   256,
     259,   262,   272,   276,   279,   283,   296,   306,   310,   314,
     318,   322,   326,   330,   336,   352,     0,   148,     5,    77,
     204,     0,   259,   268,   269,   271,   270,   263,   264,   265,
     267,   266,     0,     0,     0,     4,   243,   244,   215,     0,
     361,     4,    78,     0,   189,     0,   120,   189,   128,   129,
       0,     5,     0,     5,   189,     0,     0,    28,   103,    26,
       4,     0,     0,     0,     4,     4,     4,     0,     0,     0,
       4,     0,   359,     0,     4,     0,     4,     0,   189,     0,
       0,     4,     4,     4,    44,     4,    43,   189,     0,    76,
      46,    47,     0,   189,     0,     0,     4,     0,     0,     0,
     331,   332,   100,   223,   110,     4,     0,     1,    77,    62,
       4,     4,     0,   245,     4,     0,   246,   348,   345,   347,
     346,   351,   350,   341,   343,   342,   349,   344,   261,   260,
     340,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,   149,   140,   234,
     233,     0,     0,   258,   208,   242,   360,     0,   210,     0,
     220,   216,   209,   213,   170,    75,     4,   190,   124,     0,
     113,   125,   169,   153,    27,    75,     0,     0,     0,     4,
     259,   290,   301,   308,   312,   316,   320,   324,   328,   333,
     338,   354,   357,   159,     4,    75,    75,   180,     0,   152,
       0,     0,     0,     0,   240,   171,     0,   181,     0,     0,
     182,   183,   112,     4,     0,    45,    74,     0,     4,    65,
      73,     0,    49,    55,    53,     0,    50,   189,     0,   116,
       0,   114,   102,   360,   131,   133,   130,   134,   135,     0,
     227,   225,     0,   101,   111,   222,     6,     0,   249,   252,
       0,   251,     0,   241,     0,   248,   337,   273,   274,   275,
     277,   278,   282,   281,   280,   285,   284,   288,   289,   286,
     287,   300,   298,   297,   299,   307,   311,   315,   319,     0,
     323,   353,     0,   139,     0,     4,     4,     0,   212,     0,
     217,     0,   146,   121,     0,     0,     0,    75,   191,   162,
     122,   191,   334,   259,   335,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     0,     0,     0,     0,     4,   108,
     107,     0,     0,     0,   239,     0,     0,   186,   184,   157,
       4,    38,    66,    40,   189,    48,    54,   189,     0,     0,
     118,     0,     4,   119,     0,     0,    75,     0,   224,     4,
       8,     9,     0,     4,    56,     4,   250,   238,   247,     4,
     144,     0,   141,   142,   211,   214,     0,     4,     4,     0,
       4,     0,     0,     0,     4,   192,   126,     0,     0,     4,
     127,     0,   339,   292,   291,   295,   293,   294,   305,   303,
     302,   304,   309,   313,   317,   321,     0,   325,   355,     4,
       0,     4,     0,     0,   151,     0,   104,   106,   105,   193,
     173,     0,     0,   172,    51,    52,     4,    41,     4,    42,
     117,   115,   136,   132,   137,   138,     4,     0,   230,     0,
     226,     4,     4,     7,   254,   253,   327,     0,     4,     0,
       0,     4,   154,     4,     4,     0,   147,   123,     4,     0,
       4,     4,     0,     4,     0,     4,     4,     4,   109,     4,
     194,   176,     0,     0,     4,     0,     0,   188,     0,     0,
      75,     4,     4,     4,     4,     0,     0,    11,     4,    13,
      15,    17,    18,    19,    20,     0,    16,     0,   143,   145,
       0,     4,   221,     0,     0,     0,     0,     4,     0,     4,
     165,   329,     4,     0,     4,     0,     0,   150,     0,   177,
       0,   174,   193,   185,   158,    37,    39,    32,     4,     0,
     229,     0,     0,     0,    75,     3,    14,    22,   218,     0,
      34,     0,    29,    30,     0,     4,   166,   160,     4,   167,
      33,    35,   187,   187,     0,     0,     0,    25,    24,    23,
       0,   219,   155,    31,   163,     0,   168,   178,   179,   175,
     228,     4,     0,     0,     4,     0,     4,     4,   161,   231,
       4,    71,    72,    70,     0,     4,    63,    69,   164,    21,
      64
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -541,  -541,    -3,  -541,  -541,  -541,  -541,  -541,  -541,    58,
    -541,  -541,  -541,  -540,  -465,     4,  -541,     0,  -541,  -541,
     -37,  -541,  -541,  -541,  -181,   186,  -541,  -147,  -541,  -541,
    -541,   599,   -28,   342,  -225,     3,     1,  -151,  -541,   -33,
    -541,  -541,  -541,   153,    -5,  -541,  -541,  -541,   210,    98,
    -541,   393,  -323,    -4,   -11,  -541,   660,  -541,   343,  -541,
    -438,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,   102,
    -541,  -541,  -541,  -541,  -541,   364,  -150,  -132,   279,    86,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -182,    -1,   670,  -541,   170,  -541,   464,
    -541,    59,   288,   269,  -113,   280,   138,   442,   267,   493,
     293,   497,   295,   483,   296,   527,   307,  -541,  -541,  -541,
    -541,  -541,  -541,   -32,  -244,   624,    26,  -541,  -541,  -453,
     -19,   -87
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,    50,    51,    52,   462,   463,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,    53,   316,    55,    56,
     174,   179,   180,   445,   181,   349,   684,   317,    57,   685,
     318,    58,   686,   319,   182,   153,   194,    60,    61,    62,
      63,    64,    65,   431,   577,    66,    67,   328,   329,   149,
     399,   136,   400,   137,    68,   187,   139,   251,   267,   485,
      69,    70,    71,    72,   394,   604,   170,   522,   423,   665,
     488,   673,    73,    74,    75,    76,    77,   520,   570,   571,
     622,    78,    79,    80,   310,   311,   578,   268,   486,   572,
      81,    82,    83,    84,    85,   129,   130,   259,   260,   390,
      86,   196,   341,   252,    87,    88,    89,   255,   350,    90,
      91,    92,    93,    94,    95,    96,   282,    97,   283,    98,
     284,    99,   285,   100,   286,   101,   287,   102,   288,   103,
     289,   104,   290,   105,   291,   406,   106,   292,   293,   163,
     131,   107
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -359;
  const short int
  ParserImplementation::yytable_[] =
  {
        54,    59,   167,   138,   176,   271,   138,   337,   256,   246,
     126,   342,   457,   138,   147,   191,   133,   142,   140,   247,
     159,   148,   320,   246,   320,   138,   188,   246,   321,   265,
     246,   138,   138,   246,   246,   404,   124,   281,   183,   269,
     391,   246,   333,   195,   246,   322,   264,   186,   270,   156,
     395,   326,   246,   272,   456,   162,   562,    54,    59,   165,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   451,
     426,   427,   465,   382,   246,   246,   305,   246,   307,   257,
     246,   246,   312,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   246,   246,   157,   515,   331,   263,
     275,   510,   460,   596,    39,   608,   128,   405,   580,   244,
     245,   620,   135,   160,   161,   158,   248,   365,   366,   367,
     368,   369,   370,   340,   218,   219,   249,   150,   266,   386,
     138,   132,   138,   249,   169,   250,   681,    39,    49,   429,
     315,   185,   250,   446,   152,   681,    45,   122,   155,    39,
     596,   124,  -232,   258,   434,   297,   458,   299,   430,   647,
      39,   195,   492,   154,   557,   652,   281,   320,   351,   461,
     334,    49,   483,   138,   254,   467,   506,   138,   508,   468,
     330,   298,   428,    49,   338,   435,   303,   332,   172,   356,
     306,   621,   664,   440,    49,   450,   344,   314,   335,   266,
     471,   346,   383,   151,   173,   387,  -232,   470,   164,   308,
     452,   682,   379,   466,   381,   560,   602,   249,   609,   134,
     682,   614,   638,   538,   309,   220,   250,   352,   184,   168,
     354,   537,   166,   249,   392,   648,   661,   385,   327,   135,
     556,   274,   250,   178,   225,   226,   172,   172,    45,   122,
     336,   171,   172,   200,   138,   201,   202,   203,   138,   206,
     168,   183,   175,   526,   138,   218,   219,   138,   528,    45,
     122,   183,   189,   534,   401,   539,   437,   420,   421,    45,
     122,   357,   358,   359,   138,   138,   448,   449,    45,   122,
     532,   183,   183,   281,   493,   494,   495,   496,   497,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
      45,   122,   524,   138,   454,   525,   197,   611,   240,   177,
     447,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   198,   444,   241,   178,   160,   161,   398,   439,
      45,   122,   533,   242,   516,   517,   518,   143,   230,   231,
     232,   233,   234,   475,   243,   629,   193,   407,   408,   409,
     253,   410,   218,   219,   178,   200,   144,   204,   205,    45,
     122,   281,   261,   138,   266,   320,   273,   320,   178,   575,
     473,   576,   276,    45,   122,   277,   138,   269,    45,   122,
     222,   223,   224,   183,   236,   237,   238,   239,   201,   202,
     320,   235,   320,   320,   603,   143,   605,   606,   294,   660,
     411,   527,   529,   138,   320,   320,    45,   122,   615,   616,
     401,   145,   146,   295,   144,   143,   296,   540,   300,   514,
     301,   491,   302,   545,   472,   582,   598,   546,   583,   304,
     138,   523,   584,   138,   144,   138,   246,   330,   281,   313,
     535,   323,   183,   531,   432,   433,   320,   324,    39,   325,
     644,   339,   543,   220,   345,   112,   112,   112,   112,   112,
     112,   112,   112,   112,    45,   122,   138,   320,   585,   145,
     146,   655,   353,   401,    45,   122,    45,   122,   -10,   227,
     228,   229,    49,   355,    45,   122,   362,   363,   364,   145,
     146,  -232,   667,   668,   550,   389,   552,   384,   637,   412,
     413,   414,   415,   360,   361,   559,   371,   372,   373,   374,
     320,   396,   388,   397,   675,   687,   416,   417,   418,   143,
     138,   419,   422,   436,   687,   162,   138,   564,   147,   309,
     623,   597,   441,   599,   657,   658,   659,   443,   144,   630,
     498,   499,   500,   501,   662,   455,   464,   459,   469,   582,
     477,   610,   583,   478,   479,   480,   584,   481,   617,   138,
     482,   138,   138,   138,   600,   624,   183,   138,   344,   147,
     147,   147,    39,   484,   162,   147,   631,   632,   633,   613,
     487,   489,   509,   511,   512,   618,   513,   519,    45,   122,
     521,   536,   585,   145,   146,   541,   547,   548,   551,   555,
     646,   563,   -12,   553,   280,   649,    49,   554,   561,   558,
     565,   566,   567,   138,   568,   569,   573,   639,   574,   579,
     183,   601,   581,   607,   641,   625,   612,   626,   162,   627,
     628,   634,   635,   640,   642,   643,   636,   650,   651,   666,
     645,   544,   653,   656,   663,   669,   199,   690,   670,   671,
     442,   530,   393,   672,   674,   676,   677,   679,   689,   138,
     123,   162,   619,   453,   438,   678,   683,   147,   688,   246,
     490,   127,   375,   502,   631,   683,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   654,   112,
     503,     1,     2,   504,   221,   505,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   378,     0,   507,     0,
      13,     0,     0,     0,   376,     0,   141,    15,     0,   377,
      16,     0,     0,   403,    17,     0,    18,     0,     0,     0,
      19,     0,   109,     0,     0,    21,    22,    23,   425,    24,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,    29,   380,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,     0,     0,    48,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     403,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   403,   112,   403,     0,     0,     0,
       1,     2,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,   141,    15,     0,     0,    16,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,   109,     0,     0,    21,    22,    23,     0,    24,     0,
       0,   549,     0,    25,    26,    27,     0,     0,   403,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,   192,     0,
       0,     0,    49,     0,   193,     1,     2,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,   403,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,     0,    28,     0,     0,     0,    30,     0,
       0,     0,    32,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,   111,     0,     1,     2,     0,     0,   262,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,   111,     0,     1,     2,     0,     0,   474,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    -4,    14,    15,
       0,     0,    16,     0,     0,     0,    17,     0,    18,     0,
       0,     0,    19,     0,    20,     0,     0,    21,    22,    23,
       0,    24,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,    29,     0,     0,    30,     0,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,     0,     0,     0,
      43,     0,     0,    44,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    46,     0,    47,     0,     0,
      48,     1,     2,     0,     0,    49,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,   141,    15,     0,     0,
      16,     0,     0,     0,    17,     0,    18,     0,     0,     0,
      19,     0,   109,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,     0,     0,    48,   192,
       1,     2,     0,    49,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,   141,    15,     0,     0,    16,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,   109,     0,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,   343,     1,
       2,     0,    49,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,   141,    15,     0,     0,    16,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,     0,
     109,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,    44,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,  -187,     1,     2,
       0,    49,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    -4,   141,    15,     0,     0,    16,     0,     0,
       0,    17,     0,    18,     0,     0,     0,    19,     0,   109,
       0,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,     0,     0,     0,    43,     0,     0,    44,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,     0,     0,    48,     1,     2,     0,     0,
      49,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,    25,
      26,    27,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,    44,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,     0,     0,    48,     1,     2,     0,     0,    49,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,   141,
      15,     0,     0,    16,     0,     0,     0,    17,     0,    18,
       0,     0,     0,    19,     0,   109,     0,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,     0,
       0,    48,     1,     2,     0,     0,    49,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
       0,    16,     0,     0,     0,     0,     0,    18,     0,     0,
       0,    19,     0,    20,     0,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,    25,    26,   680,     0,     0,
     583,    28,    29,     0,     0,    30,     0,    31,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    47,     0,     0,    48,
     -57,     1,     2,     0,    49,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,    14,    15,     0,     0,
      16,     0,     0,     0,     0,     0,    18,     0,     0,     0,
      19,     0,    20,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     0,     0,    25,    26,   680,     0,     0,   583,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,     0,     0,    48,   -58,
       1,     2,     0,    49,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,    14,    15,     0,     0,    16,
       0,     0,     0,     0,     0,    18,     0,     0,     0,    19,
       0,    20,     0,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,   -59,     1,
       2,     0,    49,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,    16,     0,
       0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,    29,
       0,     0,    30,     0,    31,     0,    32,    33,     0,     0,
      34,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,     0,     0,    48,   -60,     1,     2,
       0,    49,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   109,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,   278,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,     0,   111,     1,     2,     0,     0,
    -356,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,     0,     0,     0,    28,     0,     0,     0,    30,
       0,     0,     0,    32,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,   111,     1,     2,     0,     0,  -358,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,   347,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     1,
       2,   111,     0,   348,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     1,     2,   111,     0,  -358,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,   122,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     1,
       2,   111,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     1,     2,   111,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,   190,
       0,   111,     1,     2,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,   109,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,     0,     0,
       0,    28,     0,     0,     0,    30,     0,     0,     0,    32,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,   402,     0,   111,
       1,     2,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,   347,
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
       0,     0,     0,     0,   279,     1,     2,   111,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,   109,     0,     0,   110,
      10,    11,    12,     0,     0,     0,     0,     0,    25,    26,
      27,     0,     0,   108,    28,     0,     0,     0,    30,     0,
       0,     0,    32,    18,     0,     0,    34,     0,     0,   109,
       0,     0,   110,     0,    40,    41,     0,    42,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,    45,
       0,    30,     0,     0,     0,    32,    10,    11,    12,    34,
       0,   424,   111,     0,     0,     0,     0,    40,    41,   108,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    45,     0,     0,   109,     0,     0,   110,   125,
      11,    12,     0,     0,     0,   111,     0,    25,    26,    27,
       0,     0,   108,    28,     0,     0,     0,    30,     0,     0,
       0,    32,    18,     0,     0,    34,     0,     0,   109,     0,
       0,   110,     0,    40,    41,     0,    42,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,     0,    45,     0,
      30,     0,     0,     0,    32,   125,   542,    12,    34,     0,
       0,   111,     0,     0,     0,     0,    40,    41,   108,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   109,     0,     0,   110,     0,     0,
       0,     0,     0,     0,   111,     0,    25,    26,    27,     0,
       0,     0,    28,     0,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         0,     0,    35,    14,    41,   137,    17,   188,     3,     3,
      11,   193,     3,    24,    17,    47,    13,    16,    15,   106,
      24,    17,   173,     3,   175,    36,    45,     3,   175,    47,
       3,    42,    43,     3,     3,   279,    10,   150,    42,     3,
     265,     3,     3,    48,     3,   177,   133,    44,   135,    23,
     275,   183,     3,   140,    47,    29,   509,    57,    57,    33,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     3,
     295,   296,     3,     3,     3,     3,   163,     3,   165,    74,
       3,     3,   169,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     3,    79,    50,   185,   131,
      47,   424,    69,   541,   113,   558,     3,    28,    47,    15,
      16,    63,    14,    49,    50,    98,    79,   230,   231,   232,
     233,   234,   235,    79,    45,    46,    89,    47,   146,    47,
     141,    79,   143,    89,    36,    98,   676,   113,   147,    79,
     172,    43,    98,   324,    79,   685,   129,   130,    47,   113,
     588,   125,   145,   148,   148,   154,   147,   156,    98,   612,
     113,   166,   406,   145,   487,   145,   279,   318,   200,   136,
     131,   147,   397,   184,   144,   148,   420,   188,   422,   148,
     184,   155,   144,   147,   188,   144,   160,   186,   126,   221,
     164,   143,   645,   144,   147,   327,   195,   171,    79,   146,
     382,   198,   132,   123,   142,   123,   145,    79,    47,    57,
     144,   676,   244,   144,   246,   144,   144,    89,   144,    79,
     685,   144,   144,    79,    72,   146,    98,   201,    47,    79,
     204,   456,   142,    89,   266,   144,   144,   256,    79,   141,
     484,   143,    98,   124,    35,    36,   126,   126,   129,   130,
     131,    47,   126,    47,   265,    49,    50,    87,   269,    89,
      79,   265,   142,   142,   275,    45,    46,   278,   142,   129,
     130,   275,    47,   454,   278,   457,   309,    15,    16,   129,
     130,   222,   223,   224,   295,   296,   114,   115,   129,   130,
      79,   295,   296,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     129,   130,   444,   324,   333,   447,     0,   561,    20,    79,
     324,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    59,    79,    19,   124,    49,    50,    79,   313,
     129,   130,   131,    18,   431,   432,   433,    60,    25,    26,
      27,    28,    29,   385,    17,   580,   149,    25,    26,    27,
     144,    29,    45,    46,   124,    47,    79,    49,    50,   129,
     130,   484,     3,   384,   146,   526,   110,   528,   124,   526,
     384,   528,    79,   129,   130,    79,   397,     3,   129,   130,
      37,    38,    39,   397,    21,    22,    23,    24,    49,    50,
     551,    78,   553,   554,   551,    60,   553,   554,    47,   634,
      78,   448,   449,   424,   565,   566,   129,   130,   565,   566,
     424,   134,   135,    47,    79,    60,    47,   459,   128,   428,
     128,   405,   128,   465,    79,    90,    79,   469,    93,    79,
     451,   440,    97,   454,    79,   456,     3,   451,   561,    47,
     454,    79,   456,   452,   301,   302,   607,     3,   113,   118,
     607,    79,   463,   146,   143,     1,     2,     3,     4,     5,
       6,     7,     8,     9,   129,   130,   487,   628,   133,   134,
     135,   628,    79,   487,   129,   130,   129,   130,   143,    32,
      33,    34,   147,    79,   129,   130,   227,   228,   229,   134,
     135,   145,   652,   653,   478,    80,   480,   145,   595,    21,
      22,    23,    24,   225,   226,   489,   236,   237,   238,   239,
     671,    47,   148,    47,   671,   676,    20,    19,    18,    60,
     541,    17,     3,    47,   685,   509,   547,   511,   541,    72,
     573,   542,   143,   547,   631,   632,   633,   143,    79,   581,
     412,   413,   414,   415,   641,   144,    79,   145,   145,    90,
      47,   560,    93,    47,   144,    47,    97,   144,   567,   580,
     144,   582,   583,   584,   548,   574,   580,   588,   577,   582,
     583,   584,   113,   146,   558,   588,   582,   583,   584,   563,
       3,    28,   147,    28,   144,   569,   144,   142,   129,   130,
      79,   142,   133,   134,   135,   142,   145,    28,   142,   144,
     609,    28,   143,   142,   150,   614,   147,   142,   145,   147,
     142,   142,    66,   634,    79,    56,   144,   601,   144,   144,
     634,    28,   145,   142,   144,   143,   147,   143,   612,   143,
     142,    47,   143,   143,   143,   143,   588,   143,   143,   648,
     147,   465,   145,   144,   143,   143,    57,   685,   143,   142,
     318,   451,   269,   144,   144,   142,   144,   143,   143,   680,
      10,   645,   570,   330,   310,   674,   676,   680,   677,     3,
     401,    11,   240,   416,   680,   685,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   622,   245,
     417,    35,    36,   418,    90,   419,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   243,    -1,   421,    -1,
      54,    -1,    -1,    -1,   241,    -1,    60,    61,    -1,   242,
      64,    -1,    -1,   279,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,   294,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,   245,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,   477,    -1,    88,    89,    90,    -1,    -1,   484,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,    -1,    -1,   142,   143,    -1,
      -1,    -1,   147,    -1,   149,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,    -1,    35,    36,    -1,    -1,   148,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,   139,    -1,    -1,
     142,    35,    36,    -1,    -1,   147,    40,    41,    42,    43,
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
      -1,   137,    -1,   139,    -1,    -1,   142,   143,    35,    36,
      -1,   147,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,    -1,    -1,   142,    35,    36,    -1,    -1,
     147,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   142,    35,    36,    -1,    -1,   147,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
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
      -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,
     103,    -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   142,
     143,    35,    36,    -1,   147,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    93,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   142,   143,
      35,    36,    -1,   147,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,    -1,    -1,   142,   143,    35,
      36,    -1,   147,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   142,   143,    35,    36,
      -1,   147,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,   142,    35,    36,    -1,    -1,
     147,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    35,    36,    -1,    -1,   147,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,   129,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    35,
      36,   142,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    35,    36,   142,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,   142,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,   142,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
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
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    60,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    70,    -1,    -1,   106,    -1,    -1,    76,
      -1,    -1,    79,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,   129,
      -1,    98,    -1,    -1,    -1,   102,    47,    48,    49,   106,
      -1,   108,   142,    -1,    -1,    -1,    -1,   114,   115,    60,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,   129,    -1,    -1,    76,    -1,    -1,    79,    47,
      48,    49,    -1,    -1,    -1,   142,    -1,    88,    89,    90,
      -1,    -1,    60,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    70,    -1,    -1,   106,    -1,    -1,    76,    -1,
      -1,    79,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,   129,    -1,
      98,    -1,    -1,    -1,   102,    47,    48,    49,   106,    -1,
      -1,   142,    -1,    -1,    -1,    -1,   114,   115,    60,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142
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
     211,   212,   213,   222,   223,   224,   225,   226,   231,   232,
     233,   240,   241,   242,   243,   244,   250,   254,   255,   256,
     259,   260,   261,   262,   263,   264,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   286,   291,    60,    76,
      79,   142,   259,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   130,   206,   286,    47,   254,   255,     3,   245,
     246,   290,    79,   185,    79,   199,   201,   203,   204,   206,
     185,    60,   186,    60,    79,   134,   135,   152,   165,   199,
      47,   123,    79,   185,   145,    47,   286,    79,    98,   203,
      49,    50,   286,   289,    47,   286,   142,   189,    79,   199,
     216,    47,   126,   142,   170,   142,   170,    79,   124,   171,
     172,   174,   184,   203,    47,   199,   185,   205,   290,    47,
     140,   283,   143,   149,   186,   194,   251,     0,    59,   181,
      47,    49,    50,   257,    49,    50,   257,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    45,    46,
     146,   285,    37,    38,    39,    35,    36,    32,    33,    34,
      25,    26,    27,    28,    29,    78,    21,    22,    23,    24,
      20,    19,    18,    17,    15,    16,     3,   291,    79,    89,
      98,   207,   253,   144,   144,   257,     3,    74,   148,   247,
     248,     3,   148,   283,   291,    47,   146,   208,   237,     3,
     291,   237,   291,   110,   199,    47,    79,    79,   108,   139,
     259,   264,   266,   268,   270,   272,   274,   276,   278,   280,
     282,   284,   287,   288,    47,    47,    47,   186,   286,   186,
     128,   128,   128,   286,    79,   291,   286,   291,    57,    72,
     234,   235,   291,    47,   286,   283,   167,   177,   180,   183,
     187,   177,   237,    79,     3,   118,   237,    79,   197,   198,
     203,   291,   186,     3,   131,    79,   131,   174,   203,    79,
      79,   252,   253,   143,   186,   143,   185,   124,   144,   175,
     258,   283,   286,    79,   286,    79,   283,   261,   261,   261,
     262,   262,   263,   263,   263,   264,   264,   264,   264,   264,
     264,   265,   265,   265,   265,   267,   269,   271,   273,   283,
     275,   283,     3,   132,   145,   290,    47,   123,   148,    80,
     249,   184,   283,   201,   214,   184,    47,    47,    79,   200,
     202,   203,   140,   259,   284,    28,   285,    25,    26,    27,
      29,    78,    21,    22,    23,    24,    20,    19,    18,    17,
      15,    16,     3,   218,   108,   259,   184,   184,   144,    79,
      98,   193,   193,   193,   148,   144,    47,   189,   235,   286,
     144,   143,   183,   143,    79,   173,   174,   203,   114,   115,
     237,     3,   144,   208,   290,   144,    47,     3,   147,   145,
      69,   136,   154,   155,    79,     3,   144,   148,   148,   145,
      79,   253,    79,   203,   148,   283,   259,    47,    47,   144,
      47,   144,   144,   184,   146,   209,   238,     3,   220,    28,
     238,   286,   284,   264,   264,   264,   264,   264,   266,   266,
     266,   266,   268,   270,   272,   274,   284,   276,   284,   147,
     202,    28,   144,   144,   186,    50,   291,   291,   291,   142,
     227,    79,   217,   186,   237,   237,   142,   170,   142,   170,
     198,   186,    79,   131,   174,   203,   142,   184,    79,   253,
     283,   142,    48,   254,   175,   283,   283,   145,    28,   259,
     286,   142,   286,   142,   142,   144,   284,   202,   147,   286,
     144,   145,   289,    28,   286,   142,   142,    66,    79,    56,
     228,   229,   239,   144,   144,   177,   177,   194,   236,   144,
      47,   145,    90,    93,    97,   133,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   210,   254,    79,   203,
     286,    28,   144,   177,   215,   177,   177,   142,   289,   144,
     186,   284,   147,   286,   144,   177,   177,   186,   286,   229,
      63,   143,   230,   189,   186,   143,   143,   143,   142,   184,
     283,   165,   165,   165,    47,   143,   159,   291,   144,   286,
     143,   144,   143,   143,   177,   147,   186,   289,   144,   186,
     143,   143,   145,   145,   239,   177,   144,   291,   291,   291,
     184,   144,   291,   143,   289,   219,   186,   236,   236,   143,
     143,   142,   144,   221,   144,   177,   142,   144,   186,   143,
      90,   163,   164,   167,   176,   179,   182,   187,   186,   143,
     182
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
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   187,   187,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     189,   189,   190,   191,   192,   192,   192,   193,   193,   193,
     194,   194,   195,   195,   195,   196,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   204,   205,   205,   205,   205,   205,   205,   206,
     207,   207,   207,   207,   207,   207,   208,   209,   210,   211,
     212,   212,   212,   214,   215,   213,   216,   217,   213,   218,
     219,   213,   220,   221,   213,   213,   213,   213,   213,   222,
     223,   224,   225,   226,   227,   227,   228,   228,   229,   230,
     231,   232,   233,   233,   233,   234,   235,   236,   236,   237,
     237,   238,   238,   239,   239,   240,   240,   240,   240,   240,
     241,   242,   242,   243,   243,   243,   243,   243,   243,   244,
     244,   244,   244,   245,   245,   246,   246,   247,   248,   248,
     249,   249,   250,   251,   251,   251,   252,   252,   252,   252,
     252,   252,   253,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   255,   255,   256,   256,   256,   256,   257,
     257,   258,   258,   258,   258,   259,   259,   259,   259,   260,
     260,   260,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   262,   262,   262,   262,   263,   263,   263,   264,
     264,   264,   264,   265,   265,   265,   265,   265,   265,   265,
     266,   266,   266,   266,   266,   266,   267,   267,   267,   267,
     267,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     271,   271,   272,   272,   273,   273,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   280,   280,
     281,   281,   281,   282,   282,   282,   283,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   289,
     290,   290,   291,   291
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
       1,     1,     1,     1,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     2,     5,     5,     5,     1,     1,     3,
       1,     2,     3,     3,     3,     5,     1,     3,     2,     2,
       1,     3,     1,     3,     2,     2,     2,     2,     1,     1,
       3,     3,     5,     2,     2,     2,     4,     4,     4,     3,
       1,     3,     3,     5,     3,     5,     2,     2,     1,     2,
       7,     5,     3,     0,     0,     9,     0,     0,     7,     0,
       0,    11,     0,     0,    12,     7,     8,     8,     9,     3,
       3,     3,     5,     5,     3,     5,     1,     2,     4,     3,
       3,     3,     3,     3,     4,     5,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     4,     2,     4,     1,     2,     2,     6,     7,
       0,     4,     3,     1,     3,     2,     3,     1,     7,     5,
       3,     9,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     3,     3,     1,     2,     2,     2,     4,     3,     2,
       3,     1,     1,     3,     3,     1,     1,     1,     3,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     5,
       1,     2,     2,     1,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     0,     1,     0,     1,
       0,     1,     1,     1
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
  "$@8", "continue_statement", "break_statement", "return_statement",
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
     156,   143,    -1,    -1,    60,    -1,    -1,   155,   254,    -1,
      69,    -1,   136,    -1,    -1,   157,    -1,   158,    -1,   159,
      -1,   158,   159,    -1,   160,    -1,   210,    -1,   161,    -1,
     162,    -1,   163,    -1,   164,    -1,   133,    47,   184,   144,
     142,   176,   143,    -1,   165,   291,    -1,    97,   165,   291,
      -1,    93,   165,   291,    -1,    90,   165,   291,    -1,   199,
      -1,    60,   199,    -1,   152,    -1,    79,    47,   184,   144,
     142,   177,   143,    -1,   134,    79,    47,   144,   142,   177,
     143,    -1,   135,    79,    47,   184,   144,   142,   177,   143,
      -1,   137,    47,    79,   144,   142,   236,   143,    -1,    76,
      79,    47,   184,   144,   142,   177,   143,    -1,    60,    79,
      47,   184,   144,   142,   177,   143,    -1,    76,   185,    47,
     184,   144,   142,   177,   143,    -1,   169,    -1,   117,   184,
     118,   114,   142,   177,   143,    -1,   114,   142,   177,   143,
      -1,   117,   184,   118,   115,   142,   177,   143,    -1,   115,
     142,   177,   143,    -1,   117,   184,   118,   114,   170,    -1,
     117,   184,   118,   115,   170,    -1,   115,   170,    -1,   114,
     170,    -1,   126,   283,    -1,   172,    -1,   174,    -1,   172,
       3,   173,    -1,    79,   237,    -1,   203,   237,    -1,   172,
       3,    79,   237,    -1,   172,     3,   203,   237,    -1,    -1,
     174,    -1,   124,    79,    -1,   124,    79,    -1,    -1,   179,
      -1,    -1,   180,    -1,   181,    -1,   178,   181,    -1,   182,
      -1,   179,   182,    -1,   183,    -1,   180,   183,    -1,   186,
      -1,   167,    -1,   187,    -1,   167,    -1,   163,    -1,   164,
      -1,   187,    -1,   167,    -1,    -1,   171,    -1,    -1,    79,
      -1,   187,    -1,   190,    -1,   191,    -1,   189,    -1,   188,
      -1,   195,    -1,   196,    -1,   210,    -1,   211,    -1,   212,
      -1,   213,    -1,   222,    -1,   223,    -1,   224,    -1,   225,
      -1,   231,    -1,   226,    -1,   232,    -1,   233,    -1,   192,
      -1,   166,    -1,   142,   143,    -1,   142,   194,   143,    -1,
     125,   185,   186,    -1,    68,   165,    -1,    83,    79,   128,
     193,   291,    -1,    83,   203,   128,   193,   291,    -1,    83,
      98,   128,   193,   291,    -1,    98,    -1,    79,    -1,   193,
      50,    79,    -1,   186,    -1,   194,   186,    -1,   108,   199,
     291,    -1,    60,   199,   291,    -1,   122,   199,   291,    -1,
     122,    47,   197,   144,   186,    -1,   198,    -1,   197,     3,
     198,    -1,    79,   237,    -1,   203,   208,    -1,   201,    -1,
     199,     3,   201,    -1,   202,    -1,   200,     3,   202,    -1,
      79,   237,    -1,   203,   237,    -1,    79,   238,    -1,   203,
     238,    -1,   204,    -1,   206,    -1,   129,   290,   131,    -1,
     129,   205,   131,    -1,   129,   205,     3,   290,   131,    -1,
     290,    79,    -1,   290,   174,    -1,   290,   203,    -1,   205,
       3,   290,    79,    -1,   205,     3,   290,   174,    -1,   205,
       3,   290,   203,    -1,   130,   207,   132,    -1,    79,    -1,
     253,   145,    79,    -1,   253,   145,   203,    -1,   207,     3,
     253,   145,    79,    -1,   207,     3,    79,    -1,   207,     3,
     253,   145,   203,    -1,   146,   283,    -1,   146,   284,    -1,
     291,    -1,   286,   291,    -1,    80,    47,   286,   144,   186,
      66,   186,    -1,    80,    47,   286,   144,   186,    -1,    81,
     286,   186,    -1,    -1,    -1,    64,   186,   110,   214,    47,
     286,   215,   144,   291,    -1,    -1,    -1,   110,   216,    47,
     286,   217,   144,   186,    -1,    -1,    -1,    74,    47,   288,
     218,   147,   289,   147,   289,   219,   144,   186,    -1,    -1,
      -1,    74,    47,   108,   200,   220,   147,   289,   147,   289,
     221,   144,   186,    -1,    74,    47,   259,    28,   286,   144,
     186,    -1,    74,    47,   108,   202,    28,   286,   144,   186,
      -1,    74,   123,    47,   259,    28,   286,   144,   186,    -1,
      74,   123,    47,   108,   202,    28,   286,   144,   186,    -1,
      61,   185,   291,    -1,    54,   185,   291,    -1,    95,   289,
     291,    -1,   111,    47,   286,   144,   186,    -1,   100,    47,
     286,   144,   227,    -1,   142,   239,   143,    -1,   142,   239,
     230,   239,   143,    -1,   229,    -1,   228,   229,    -1,    56,
     286,   145,   236,    -1,    63,   145,   236,    -1,    79,   145,
     186,    -1,   103,   286,   291,    -1,   107,   189,   234,    -1,
     107,   189,   235,    -1,   107,   189,   234,   235,    -1,    57,
      47,    79,   144,   189,    -1,    72,   189,    -1,    -1,   194,
      -1,    -1,   208,    -1,    -1,   209,    -1,    -1,   228,    -1,
     241,    -1,   242,    -1,    89,    -1,    98,    -1,    94,    -1,
      88,    -1,   106,    -1,    70,    -1,   102,    -1,    79,    -1,
     240,    -1,   244,    -1,   250,    -1,    47,   286,   144,    -1,
      49,   290,   148,    -1,    49,   245,   148,    -1,    49,   245,
       3,   290,   148,    -1,    49,   245,   247,   148,    -1,   290,
     283,    -1,   245,     3,   290,   283,    -1,     3,    -1,   246,
       3,    -1,   248,   249,    -1,    74,    47,   259,    28,   286,
     144,    -1,    74,   123,    47,   259,    28,   286,   144,    -1,
      -1,    80,    47,   286,   144,    -1,   142,   251,   143,    -1,
     149,    -1,   149,   252,   147,    -1,   149,   252,    -1,   253,
     145,   283,    -1,    79,    -1,    79,    47,   184,   144,   142,
     177,   143,    -1,   252,     3,   253,   145,   283,    -1,   252,
       3,    79,    -1,   252,     3,    79,    47,   184,   144,   142,
     177,   143,    -1,    79,    -1,    98,    -1,    89,    -1,   243,
      -1,   168,    -1,   152,    -1,   254,    49,   286,   148,    -1,
      90,    49,   286,   148,    -1,    90,    50,    79,    -1,   254,
      50,    79,    -1,    48,   254,   257,    -1,   254,    -1,    48,
     255,    -1,   254,   257,    -1,   256,   257,    -1,   256,    49,
     286,   148,    -1,   256,    50,    79,    -1,    47,   144,    -1,
      47,   258,   144,    -1,   283,    -1,   175,    -1,   258,     3,
     283,    -1,   258,     3,   175,    -1,   255,    -1,   256,    -1,
     204,    -1,    47,   206,   144,    -1,   259,    -1,   259,    46,
      -1,   259,    45,    -1,   260,    -1,    42,   261,    -1,    43,
     261,    -1,    44,   261,    -1,    46,   261,    -1,    45,   261,
      -1,    35,   261,    -1,    36,   261,    -1,    41,   261,    -1,
      40,   261,    -1,   261,    -1,   262,    37,   261,    -1,   262,
      38,   261,    -1,   262,    39,   261,    -1,   262,    -1,   263,
      35,   262,    -1,   263,    36,   262,    -1,   263,    -1,   264,
      34,   263,    -1,   264,    33,   263,    -1,   264,    32,   263,
      -1,   264,    -1,   265,    26,   264,    -1,   265,    25,   264,
      -1,   265,    29,   264,    -1,   265,    78,   264,    -1,   265,
      27,   264,    -1,   265,    28,   264,    -1,   264,    -1,   266,
      26,   264,    -1,   266,    25,   264,    -1,   266,    29,   264,
      -1,   266,    78,   264,    -1,   266,    27,   264,    -1,   265,
      -1,   267,    23,   265,    -1,   267,    22,   265,    -1,   267,
      24,   265,    -1,   267,    21,   265,    -1,   266,    -1,   268,
      23,   266,    -1,   268,    22,   266,    -1,   268,    24,   266,
      -1,   268,    21,   266,    -1,   267,    -1,   269,    20,   267,
      -1,   268,    -1,   270,    20,   268,    -1,   269,    -1,   271,
      19,   269,    -1,   270,    -1,   272,    19,   270,    -1,   271,
      -1,   273,    18,   271,    -1,   272,    -1,   274,    18,   272,
      -1,   273,    -1,   275,    17,   273,    -1,   274,    -1,   276,
      17,   274,    -1,   275,    -1,   277,    16,   275,    -1,   276,
      -1,   278,    16,   276,    -1,   277,    -1,   277,    15,   283,
     145,   283,    -1,   278,    -1,   278,    15,   284,   145,   284,
      -1,   279,    -1,   139,   140,    -1,   139,   283,    -1,   280,
      -1,   139,   140,    -1,   139,   284,    -1,   281,    -1,   259,
     285,   283,    -1,   282,    -1,   259,   285,   284,    -1,   146,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   283,    -1,   286,     3,   283,    -1,   284,
      -1,   287,     3,   284,    -1,    -1,   287,    -1,    -1,   286,
      -1,    -1,   246,    -1,   147,    -1,   113,    -1
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
     245,   247,   249,   251,   253,   255,   256,   258,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     303,   306,   310,   314,   317,   323,   329,   335,   337,   339,
     343,   345,   348,   352,   356,   360,   366,   368,   372,   375,
     378,   380,   384,   386,   390,   393,   396,   399,   402,   404,
     406,   410,   414,   420,   423,   426,   429,   434,   439,   444,
     448,   450,   454,   458,   464,   468,   474,   477,   480,   482,
     485,   493,   499,   503,   504,   505,   515,   516,   517,   525,
     526,   527,   539,   540,   541,   554,   562,   571,   580,   590,
     594,   598,   602,   608,   614,   618,   624,   626,   629,   634,
     638,   642,   646,   650,   654,   659,   665,   668,   669,   671,
     672,   674,   675,   677,   678,   680,   682,   684,   686,   688,
     690,   692,   694,   696,   698,   700,   702,   704,   706,   710,
     714,   718,   724,   729,   732,   737,   739,   742,   745,   752,
     760,   761,   766,   770,   772,   776,   779,   783,   785,   793,
     799,   803,   813,   815,   817,   819,   821,   823,   825,   830,
     835,   839,   843,   847,   849,   852,   855,   858,   863,   867,
     870,   874,   876,   878,   882,   886,   888,   890,   892,   896,
     898,   901,   904,   906,   909,   912,   915,   918,   921,   924,
     927,   930,   933,   935,   939,   943,   947,   949,   953,   957,
     959,   963,   967,   971,   973,   977,   981,   985,   989,   993,
     997,   999,  1003,  1007,  1011,  1015,  1019,  1021,  1025,  1029,
    1033,  1037,  1039,  1043,  1047,  1051,  1055,  1057,  1061,  1063,
    1067,  1069,  1073,  1075,  1079,  1081,  1085,  1087,  1091,  1093,
    1097,  1099,  1103,  1105,  1109,  1111,  1115,  1117,  1123,  1125,
    1131,  1133,  1136,  1139,  1141,  1144,  1147,  1149,  1153,  1155,
    1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175,  1177,
    1179,  1181,  1183,  1185,  1189,  1191,  1195,  1196,  1198,  1199,
    1201,  1202,  1204,  1206
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   374,   374,   385,   397,   398,   403,   404,   420,   421,
     426,   427,   431,   436,   457,   481,   487,   488,   489,   490,
     491,   496,   511,   521,   531,   540,   550,   551,   558,   559,
     570,   582,   597,   611,   628,   644,   654,   667,   676,   685,
     695,   705,   715,   726,   737,   751,   762,   763,   769,   787,
     803,   813,   823,   835,   836,   845,   862,   872,   873,   877,
     878,   882,   890,   901,   909,   920,   928,   938,   939,   950,
     951,   958,   959,   964,   965,   975,   976,   983,   984,   993,
     994,   999,  1007,  1012,  1016,  1021,  1025,  1030,  1035,  1040,
    1045,  1050,  1055,  1060,  1065,  1070,  1075,  1080,  1085,  1089,
    1096,  1103,  1114,  1127,  1139,  1156,  1171,  1191,  1199,  1207,
    1217,  1225,  1236,  1244,  1252,  1263,  1273,  1279,  1286,  1294,
    1305,  1313,  1323,  1329,  1337,  1345,  1356,  1364,  1376,  1380,
    1387,  1397,  1404,  1417,  1429,  1438,  1448,  1459,  1467,  1478,
    1489,  1499,  1512,  1522,  1533,  1542,  1553,  1557,  1561,  1565,
    1579,  1588,  1597,  1610,  1612,  1609,  1621,  1622,  1620,  1630,
    1631,  1630,  1643,  1644,  1643,  1656,  1667,  1679,  1690,  1704,
    1714,  1724,  1734,  1745,  1756,  1760,  1769,  1775,  1783,  1794,
    1805,  1818,  1828,  1837,  1846,  1858,  1869,  1877,  1878,  1882,
    1883,  1887,  1888,  1892,  1893,  1897,  1898,  1899,  1906,  1913,
    1923,  1933,  1940,  1950,  1957,  1964,  1965,  1966,  1967,  1975,
    1985,  1992,  2002,  2013,  2023,  2034,  2035,  2040,  2048,  2055,
    2065,  2066,  2075,  2089,  2093,  2097,  2104,  2113,  2125,  2140,
    2147,  2158,  2175,  2182,  2189,  2199,  2203,  2207,  2212,  2225,
    2237,  2252,  2267,  2283,  2284,  2294,  2307,  2320,  2333,  2351,
    2352,  2356,  2362,  2368,  2373,  2381,  2382,  2383,  2384,  2388,
    2392,  2399,  2409,  2410,  2417,  2424,  2431,  2438,  2445,  2452,
    2459,  2466,  2476,  2477,  2481,  2485,  2492,  2493,  2497,  2504,
    2505,  2509,  2513,  2520,  2521,  2525,  2529,  2533,  2537,  2541,
    2548,  2549,  2553,  2557,  2561,  2565,  2572,  2573,  2577,  2581,
    2585,  2592,  2593,  2597,  2601,  2605,  2612,  2613,  2620,  2621,
    2628,  2629,  2636,  2637,  2644,  2645,  2652,  2653,  2660,  2661,
    2668,  2669,  2676,  2677,  2684,  2685,  2692,  2693,  2702,  2703,
    2712,  2713,  2717,  2726,  2727,  2731,  2740,  2744,  2754,  2758,
    2769,  2770,  2771,  2772,  2773,  2774,  2775,  2776,  2777,  2778,
    2779,  2780,  2784,  2791,  2799,  2806,  2814,  2815,  2819,  2820,
    2824,  2825,  2829,  2830
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
  const int ParserImplementation::yylast_ = 3870;
  const int ParserImplementation::yynnts_ = 142;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 197;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 150;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 379;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 6203 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2833 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


