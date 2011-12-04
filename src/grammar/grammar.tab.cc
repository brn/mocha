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
#line 364 "grammar/grammar.yy"
    {int yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 365 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 376 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 386 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 387 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 392 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 394 "grammar/grammar.yy"
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
#line 407 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 408 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 413 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 414 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 418 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 424 "grammar/grammar.yy"
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
#line 445 "grammar/grammar.yy"
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
#line 469 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 474 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 475 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 476 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 477 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 478 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 484 "grammar/grammar.yy"
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
#line 499 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 509 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 519 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 528 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 537 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 539 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 544 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 546 "grammar/grammar.yy"
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
#line 557 "grammar/grammar.yy"
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
#line 569 "grammar/grammar.yy"
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
#line 589 "grammar/grammar.yy"
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
#line 606 "grammar/grammar.yy"
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
#line 622 "grammar/grammar.yy"
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
#line 631 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 645 "grammar/grammar.yy"
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
#line 654 "grammar/grammar.yy"
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
#line 663 "grammar/grammar.yy"
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
#line 673 "grammar/grammar.yy"
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
#line 683 "grammar/grammar.yy"
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
#line 693 "grammar/grammar.yy"
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
#line 704 "grammar/grammar.yy"
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
#line 715 "grammar/grammar.yy"
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
#line 729 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 739 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 741 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 759 "grammar/grammar.yy"
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

  case 49:

/* Line 690 of lalr1.cc  */
#line 775 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(2) - (1)].value_node)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    list->AddChild( (yysemantic_stack_[(2) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 783 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 793 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(4) - (3)].value_node)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 802 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 803 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 830 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 839 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 840 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 844 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 845 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 850 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 858 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 869 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 877 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 888 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 896 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 905 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 907 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 917 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 919 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 925 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 926 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 931 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 933 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 942 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 944 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 950 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 952 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 960 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 962 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 967 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 975 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 979 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 984 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 989 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 993 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 998 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1003 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1008 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1013 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1018 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1023 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1028 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1033 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1038 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1043 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1060 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1067 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1078 "grammar/grammar.yy"
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
#line 1091 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(3) - (2)].value_node) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1098 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].function) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1109 "grammar/grammar.yy"
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

  case 104:

/* Line 690 of lalr1.cc  */
#line 1126 "grammar/grammar.yy"
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

  case 105:

/* Line 690 of lalr1.cc  */
#line 1141 "grammar/grammar.yy"
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

  case 106:

/* Line 690 of lalr1.cc  */
#line 1161 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1169 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1177 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1187 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1195 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1206 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1214 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1222 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1233 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1243 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1249 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1256 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1264 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1275 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1283 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1293 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1299 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1307 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1315 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1325 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1344 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1348 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1355 "grammar/grammar.yy"
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

  case 130:

/* Line 690 of lalr1.cc  */
#line 1365 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1372 "grammar/grammar.yy"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1385 "grammar/grammar.yy"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1397 "grammar/grammar.yy"
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
#line 1407 "grammar/grammar.yy"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1417 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1428 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1439 "grammar/grammar.yy"
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

  case 138:

/* Line 690 of lalr1.cc  */
#line 1449 "grammar/grammar.yy"
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

  case 139:

/* Line 690 of lalr1.cc  */
#line 1461 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1471 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1481 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1489 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1499 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1503 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1507 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1512 "grammar/grammar.yy"
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

  case 147:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1535 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1547 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1555 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar/grammar.yy"
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

  case 152:

/* Line 690 of lalr1.cc  */
#line 1575 "grammar/grammar.yy"
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

  case 153:

/* Line 690 of lalr1.cc  */
#line 1587 "grammar/grammar.yy"
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

  case 154:

/* Line 690 of lalr1.cc  */
#line 1598 "grammar/grammar.yy"
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

  case 155:

/* Line 690 of lalr1.cc  */
#line 1610 "grammar/grammar.yy"
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

  case 156:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar/grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1635 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1645 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1655 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1665 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1676 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1687 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1691 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1700 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1706 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1725 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1736 "grammar/grammar.yy"
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

  case 169:

/* Line 690 of lalr1.cc  */
#line 1749 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1759 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1768 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1777 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1789 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1800 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1807 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1808 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1812 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1813 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1817 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1818 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1823 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1827 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1828 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1830 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1837 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1844 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1854 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1864 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1871 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1881 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1888 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1894 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1895 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1898 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1906 "grammar/grammar.yy"
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

  case 198:

/* Line 690 of lalr1.cc  */
#line 1916 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1923 "grammar/grammar.yy"
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

  case 200:

/* Line 690 of lalr1.cc  */
#line 1933 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1944 "grammar/grammar.yy"
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

  case 202:

/* Line 690 of lalr1.cc  */
#line 1954 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1971 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1979 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1986 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1995 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1997 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2006 "grammar/grammar.yy"
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

  case 211:

/* Line 690 of lalr1.cc  */
#line 2020 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2024 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2031 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2040 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2050 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2057 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2064 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2074 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2078 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2082 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2087 "grammar/grammar.yy"
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

  case 222:

/* Line 690 of lalr1.cc  */
#line 2100 "grammar/grammar.yy"
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

  case 223:

/* Line 690 of lalr1.cc  */
#line 2115 "grammar/grammar.yy"
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

  case 224:

/* Line 690 of lalr1.cc  */
#line 2130 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2132 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2142 "grammar/grammar.yy"
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

  case 227:

/* Line 690 of lalr1.cc  */
#line 2155 "grammar/grammar.yy"
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

  case 228:

/* Line 690 of lalr1.cc  */
#line 2168 "grammar/grammar.yy"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2181 "grammar/grammar.yy"
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

  case 230:

/* Line 690 of lalr1.cc  */
#line 2198 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2199 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2204 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2210 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2216 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2221 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2228 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2229 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2230 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2231 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2236 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2240 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2247 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2256 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2258 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2265 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2272 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2279 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2286 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2293 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2300 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2307 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2314 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2323 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2325 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2329 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2339 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2341 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2345 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2351 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2353 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2357 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2361 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2367 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2369 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2373 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2377 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2381 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2385 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2389 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2395 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2397 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2401 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2405 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2409 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2413 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2419 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2421 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2425 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2429 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2433 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2439 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2441 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2445 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2449 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2453 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2459 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2461 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2467 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2469 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2475 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2477 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2483 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2485 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2491 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2493 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2499 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2501 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2507 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2509 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2515 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2517 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2523 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2525 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2531 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2533 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2539 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2541 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2549 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2551 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2560 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2564 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2574 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2578 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2588 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2589 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2590 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2591 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2592 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2593 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2594 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2595 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2596 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2597 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2598 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2599 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2604 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2611 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2619 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2626 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2633 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2634 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2639 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2643 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2644 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2648 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2649 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4057 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -492;
  const short int
  ParserImplementation::yypact_[] =
  {
      -492,   107,  1732,  -492,  2738,  2738,  2738,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,   656,   116,    50,   133,    50,  1834,
     157,  -492,    13,    98,    -5,   166,    29,  -492,  -492,  -492,
    2544,  -492,   169,  -492,  2738,  -492,    12,   136,   187,   213,
    -492,    -4,    -3,   163,    93,    50,   116,    39,  1013,  -492,
    -492,   104,  -492,  -492,  -492,  1116,  -492,  -492,  -492,  -492,
    -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
    -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
    -492,  -492,  -492,  -492,  -492,  -492,   205,  -492,   263,   450,
    -492,  -492,   200,   108,   364,    77,   337,   180,   148,   252,
     255,   373,  -492,  -492,    40,  -492,  -492,    50,  -492,   147,
     356,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
      44,   205,  -492,  -492,    24,   274,   806,  -492,   -13,     9,
      42,  -492,   143,  -492,  -492,   -13,   136,   191,   229,   244,
     143,  -492,   -13,  2142,   281,   291,   293,  1834,  2738,   224,
     226,   240,   339,   -13,  2738,    40,  1218,    43,    42,  2738,
    2738,  2738,  1936,  -492,  1936,  -492,   143,  -492,   352,   253,
     143,   177,    42,  1834,    88,   188,   235,  -492,  -492,    45,
     260,    -5,   270,   277,  -492,  -492,  1321,   284,    27,   309,
      50,  -492,  2346,  2738,   344,  -492,  2738,   372,  -492,  -492,
    -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
    -492,  -492,  -492,  2738,  2738,  2738,  2738,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  -492,
    -492,  -492,  -492,   116,    23,  -492,   311,   385,  -492,  -492,
    -492,  -492,   163,  2738,  -492,  -492,   136,  -492,  -492,  -492,
     419,   420,   291,  -492,   197,   678,   364,    84,   355,   449,
     456,   458,   460,   398,  -492,  -492,   476,   341,   649,   163,
     163,  -492,    46,   101,   101,   101,  -492,    55,  -492,   436,
      12,   415,  -492,  -492,    56,    59,  -492,  -492,   351,  2039,
    -492,  -492,   353,  -492,   120,   305,  -492,   143,    64,  -492,
     143,  -492,  -492,   116,  -492,  -492,  -492,  -492,   236,  -492,
     201,  -492,  -492,  -492,   147,  -492,  2738,    54,   410,  -492,
    -492,    66,  -492,    33,  -492,    36,  -492,  -492,  -492,  -492,
    -492,   200,   200,   108,   108,   108,   364,   364,   364,   364,
     364,   364,    77,    77,    77,    77,   337,   180,   148,   252,
     354,   255,  -492,   910,  2785,   444,  -492,   451,  -492,   363,
    -492,  -492,  2738,   365,    51,   475,   365,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,  2738,  2244,   197,   478,   366,   369,
    1834,  -492,  -492,    47,    47,    47,   374,   432,  -492,  -492,
    1834,  1834,  -492,  -492,  -492,   143,   433,  -492,  -492,   143,
      94,    95,  -492,   177,  1834,  -492,   192,   235,   375,  -492,
    -492,   376,  -492,  -492,  -492,   377,  2832,  -492,  2641,  -492,
    -492,  -492,  2738,  -492,  -492,   489,  2785,  2738,   382,    68,
    2738,  -492,  -492,   197,  2244,  2738,  -492,    69,   450,  -492,
     364,   364,   364,   364,   364,    84,    84,    84,    84,   355,
     449,   456,   458,   380,   460,  -492,   381,   493,  2738,   388,
     389,   463,   447,  -492,  -492,  -492,   482,  -492,   396,  -492,
    -492,  -492,  -492,  -492,  1936,  -492,  1936,  -492,  -492,  -492,
    -492,  -492,  -492,   203,  2738,   215,  2832,   387,  -492,  -492,
    -492,  2738,   512,    70,  1936,   -13,  -492,  -492,   400,    71,
    1834,  2738,  2445,  2738,    72,  1936,  1936,  1834,  -492,  2738,
     482,  -492,    14,    12,   406,   411,  -492,  -492,  -492,   136,
      10,   168,   168,   168,   502,   471,   472,  -492,   418,  -492,
    2843,  -492,  -492,  -492,  -492,  -492,  -492,   -13,   549,  -492,
     205,    73,  2738,  -492,   421,  -492,  2445,  1834,  -492,  -492,
     424,    85,  1834,   422,   426,  -492,    32,  -492,   417,  -492,
     482,  -492,  -492,  -492,   549,   163,   -13,   -13,   -13,   163,
     510,   514,  -492,  -492,  -492,  -492,    87,  -492,   427,  -492,
    1834,  1834,  -492,  -492,  -492,  1424,  1424,   431,   435,  -492,
    -492,  -492,   437,   438,   163,  -492,  1834,  -492,  -492,  1424,
    -492,  -492,  -492,   428,   434,   441,   443,  -492,  1936,  1526,
    1936,   446,   452,  -492,  -492,  -492,   454,  1629,  -492,  -492,
     455,  1936,  -492,  -492,  -492,  -492,   457,  -492
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     5,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   335,    76,     6,    76,     5,
       0,   190,     0,    76,   192,     0,     0,   188,   185,   187,
     333,   186,     0,   191,     5,   189,     0,     0,     0,     0,
     338,     0,     0,    74,     0,    76,   335,     0,     5,   337,
     220,     0,    67,   219,    36,     3,    60,    66,    78,    82,
      81,    79,    80,    97,    83,    84,   238,   239,    85,    86,
      87,    88,    89,    90,    91,    92,    94,    93,    95,    96,
     193,   183,   184,   218,   194,   195,   224,   236,   237,   240,
     243,   253,   257,   260,   264,   277,   287,   291,   295,   299,
     303,   307,   311,   327,     0,   145,     6,    76,   192,   211,
     240,   249,   250,   252,   251,   244,   245,   246,   248,   247,
       0,   224,   225,   203,     0,   336,     5,    77,     0,   177,
       0,   119,   177,   127,   128,     0,     6,     0,     0,     0,
     177,   102,     0,     5,     0,     0,     0,     5,     5,     0,
       0,     0,   334,     0,     5,     0,     5,     0,     0,     5,
       5,     5,     5,    44,     5,    43,   177,    75,    46,     0,
     177,     0,     0,     5,     0,     0,   137,   217,   216,     0,
       0,   192,   185,   186,    98,   109,     5,     0,     0,     0,
      76,    61,     5,     5,     0,   226,     5,     0,   227,   323,
     320,   322,   321,   326,   325,   316,   318,   317,   324,   319,
     242,   241,   315,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,   146,
     215,   196,   223,   335,     0,   198,     0,   208,   204,   197,
     201,   158,    74,     5,   178,   123,     0,   112,   124,   157,
       0,     0,     0,   101,     0,   240,   271,   282,   289,   293,
     297,   301,   305,   309,   313,   329,   332,     0,     5,    74,
      74,   168,     0,     0,     0,     0,   159,     0,   169,     0,
       0,   170,   171,   111,     0,     0,    45,    73,     0,     5,
      64,    72,     0,    48,    52,     0,    49,   177,     0,   115,
       0,   113,   100,   335,   130,   132,   129,   133,     0,   136,
       0,    99,   110,   210,     0,   212,     5,     7,     0,   230,
     233,     0,   232,     0,   222,     0,   229,   312,   254,   255,
     256,   258,   259,   263,   262,   261,   266,   265,   269,   270,
     267,   268,   281,   279,   278,   280,   288,   292,   296,   300,
       0,   304,   328,     5,     5,     0,   200,     0,   205,     0,
     143,   120,     5,   179,     0,   121,   179,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     0,     0,     0,     0,
       5,   107,   106,     0,     0,     0,     0,     0,   174,   172,
       5,     5,    38,    65,    40,   177,     0,    47,    53,   177,
       0,     0,   117,     0,     5,   118,     0,   141,     0,   138,
     139,     0,   213,     9,    10,     0,     5,    55,     5,   231,
     221,   228,     5,   199,   202,     0,     5,     5,     0,     0,
       5,   180,   125,     0,     5,     5,   126,     0,   240,   314,
     273,   272,   276,   274,   275,   286,   284,   283,   285,   290,
     294,   298,   302,     0,   306,   330,     0,     0,     5,     0,
       0,   148,     0,   103,   105,   104,   181,   161,     0,   150,
     160,    50,    54,    51,     5,    41,     5,    42,   116,   114,
     134,   131,   135,     0,     5,     5,     5,     8,   235,   234,
     308,     5,     0,     0,     5,     0,   144,   122,     0,     0,
       5,     5,     5,     5,     0,     5,     5,     5,   108,     5,
     182,   164,     0,     0,     0,     0,   140,   142,   214,     6,
     177,     5,     5,     5,     0,     0,     0,    29,     0,    12,
       5,    14,    16,    18,    19,    20,    21,     0,    27,    17,
       0,     0,     5,   209,     0,   149,     5,     5,   153,   310,
       0,     0,     5,     0,     0,   147,     0,   165,     0,   162,
     181,   173,    37,    39,    28,    74,     0,     0,     0,    74,
       0,     0,     4,    15,    23,   206,     0,    34,     0,   154,
       5,     5,   155,    33,    35,   175,   175,     0,     0,    26,
      25,    24,     0,     0,    74,   207,     5,   151,   156,   176,
     166,   167,   163,     0,     0,     0,     0,   152,     5,     5,
       5,     0,     0,    70,    71,    69,     0,     5,    62,    68,
       0,     5,    30,    22,    63,    31,     0,    32
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -492,  -492,  -492,  -170,  -492,  -492,  -492,  -492,  -492,  -492,
      19,  -492,  -492,  -492,  -491,  -397,  -137,    -2,  -492,  -492,
     -34,  -492,  -492,  -492,  -492,   142,  -492,  -160,  -492,  -492,
    -492,   516,   -51,   288,  -239,     6,     0,  -157,  -492,   -33,
    -492,  -492,  -492,   159,  -156,  -492,  -492,  -492,   172,   -16,
    -492,     3,  -300,    -1,   -11,  -492,    -6,  -492,   286,  -492,
    -413,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
    -492,    75,  -492,  -492,  -492,  -492,  -492,   307,    -7,  -120,
     230,    22,  -492,  -492,  -492,  -492,  -492,  -492,  -492,  -492,
    -492,  -492,  -492,  -492,  -492,   -37,     2,   590,  -492,   115,
    -492,   423,  -492,    74,   228,   220,   442,   153,     7,   378,
     219,   379,   222,   383,   225,   386,   218,   391,   221,  -492,
    -492,  -492,  -492,   -97,  -326,   529,    31,  -492,  -492,  -361,
     -29,   -41
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    50,    51,   435,   436,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   297,    53,    54,
     163,   167,   168,   417,   418,   330,   636,   298,    55,   637,
     299,    56,   638,   300,   169,   146,   185,    58,    59,    60,
      61,    62,    63,   403,   186,    64,    65,   308,   309,   558,
     374,   131,   375,   132,    66,   174,    67,   179,   254,   451,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   487,
     530,   531,   580,    77,    78,    79,   291,   292,   620,   255,
     452,   532,    80,    81,    82,    83,    84,   124,   125,   246,
     247,   368,    85,   187,   188,   189,    86,    87,    88,   242,
     331,    89,    90,    91,    92,    93,    94,    95,   267,    96,
     268,    97,   269,    98,   270,    99,   271,   100,   272,   101,
     273,   102,   274,   103,   275,   378,   104,   276,   277,   153,
     126,   105
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -334;
  const short int
  ParserImplementation::yytable_[] =
  {
        52,   130,    57,   157,   302,   301,   133,   301,   165,   133,
     180,   134,   258,   369,   134,   133,   121,   175,   141,   137,
     134,   158,   128,   142,   135,   151,   133,   243,   172,   250,
     324,   134,   133,   133,   476,   238,   238,   134,   134,   238,
     398,   399,   170,   238,   120,   256,   303,   238,   318,   238,
     306,   173,   459,    52,   453,    57,   252,   585,   238,   238,
     143,   152,   238,   239,   296,   155,   473,   423,   475,   438,
     364,   238,   238,   238,   238,   238,   238,   578,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   251,   238,   257,
     238,   313,   559,   518,   259,   332,   477,   482,   244,    40,
     289,   263,   222,   223,   224,   225,   226,     3,   149,   379,
     380,   381,   286,   382,   288,   290,   337,   293,   176,   123,
     130,   161,   161,   433,   516,   133,   150,   177,    49,   127,
     134,   311,   162,   164,   147,   144,   178,   559,   633,   360,
     171,   362,   301,   217,   218,   365,   633,   281,   156,   253,
     253,   579,    40,   517,    40,   227,   370,    46,    47,    40,
     133,   570,   383,   190,   133,   134,   245,   233,   325,   134,
     310,   605,   140,   312,   317,   440,   319,   145,   441,   282,
     401,    49,   241,    49,   400,   287,   322,   422,    49,   434,
     294,   295,   454,   406,   410,   569,   327,   411,   402,   415,
     232,   195,   424,   198,   439,   598,   515,   520,   563,   567,
     572,   595,   129,   148,   363,   140,   154,   138,   314,   161,
     161,    46,    47,   601,   333,   615,   240,   335,   539,   432,
     494,   496,   634,   139,   159,   177,   140,   214,   215,   216,
     634,   133,   166,   416,   178,   133,   134,   540,    46,    47,
     134,   170,   192,   133,   193,   194,   307,   408,   134,   371,
     160,    46,    47,   376,    46,    47,   444,   315,   133,   133,
     234,   500,   235,   134,   134,   539,   373,   248,   170,   170,
     429,   428,   536,   253,   426,    46,    47,   431,   338,   339,
     340,    46,    47,   133,   540,   491,    46,    47,   134,   493,
     260,   545,   546,   419,   541,    46,    47,   542,   261,   133,
     192,   543,   196,   197,   134,   427,    46,    47,   316,   430,
      46,    47,   501,   262,   177,    46,    47,    40,   278,    46,
      47,    46,    47,   178,   534,   547,   535,   301,   279,   301,
     280,   509,   238,    46,    47,   510,   608,   544,   545,   546,
     612,   283,   -11,   284,   564,   304,    49,   301,   228,   229,
     230,   231,   483,   484,   485,   573,   574,   285,   301,   301,
     305,   547,   547,   547,  -215,   626,   384,   385,   386,   387,
     547,   352,   353,   354,   355,   133,   495,   497,   236,   237,
     134,   465,   466,   467,   468,   376,   219,   220,   221,   320,
     481,   210,   211,   449,   586,   587,   588,   538,   457,  -217,
     489,   490,   133,   392,   393,   133,  -216,   134,   420,   421,
     134,   323,   310,   334,   499,   502,   152,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   193,   194,   507,   343,
     344,   345,   133,   404,   405,   341,   342,   134,   326,   619,
     619,   336,   376,   366,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   367,   372,   252,   632,   388,
     640,   301,   639,   301,   565,   389,   390,   391,   513,   394,
     639,   646,   395,   407,   301,   152,   519,   290,   412,   437,
     414,   446,   133,   442,   133,   210,   211,   134,   447,   134,
     581,   448,   537,   455,   479,   450,   478,   480,   560,   524,
     486,   488,   492,   505,   503,   504,   594,   511,   514,   521,
     568,   523,   522,   584,   525,   526,   528,   575,   133,   527,
     133,   133,   133,   134,   533,   134,   134,   134,   529,   133,
     562,   566,   561,   582,   134,   609,   610,   611,   583,   589,
     590,   591,   256,   152,   571,   592,   606,   613,   597,   603,
     576,   614,   600,   604,   628,   616,   265,   599,   622,   593,
     629,   191,   602,   623,   133,   624,   625,   630,   133,   134,
     508,   631,   641,   134,   170,   266,   644,   413,   170,   642,
     212,   643,   645,   596,   647,   498,   425,   152,   409,   621,
     617,   618,   607,   133,   122,   577,   456,   469,   134,   472,
     356,   470,   357,   170,   474,   471,   627,   358,   213,   322,
       0,   359,     0,     0,     0,     0,     0,   635,   361,     0,
       0,     0,     0,     0,     0,   635,     0,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,     0,
     110,     0,     0,     0,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,     0,     0,    13,    14,    15,     0,
       0,   397,     0,    13,    14,    15,   377,     0,     0,   106,
       0,     0,     0,     0,     0,     0,   106,     0,     0,    21,
       0,     0,     0,   210,   211,   107,    21,     0,   108,     0,
       0,     0,   107,     0,     0,   108,    27,    28,     0,     0,
       0,     0,    29,    27,    28,     0,    31,     0,     0,    29,
      33,     0,     0,    31,    35,     0,   396,    33,     0,     0,
       0,    35,    41,    42,     0,    43,     0,     0,     0,    41,
      42,     0,    43,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,   109,     0,   445,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   458,   110,   458,   212,     0,
     266,   460,   461,   462,   463,   464,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,   512,
       0,     0,     0,   458,     0,     0,    21,     0,     0,     0,
       0,     0,   107,     0,     0,   108,     0,     0,     0,     0,
       0,     0,   266,    27,    28,     0,     0,     0,     0,    29,
       0,     0,     0,    31,     0,     0,     0,    33,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    41,
      42,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,   109,     0,   458,     4,     5,     0,   249,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   107,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,   109,     0,     4,     5,
       0,     0,   443,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   136,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   107,
       0,     0,   181,    25,     0,    26,     0,     0,     0,     0,
      27,   182,     0,     0,     0,     0,    29,    30,     0,     0,
     183,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,     0,     0,     0,    48,
     184,     4,     5,     0,    49,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,    -5,    17,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,    23,     0,     0,    24,    25,     0,    26,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    33,    34,     0,
       0,    35,    36,    37,     0,    38,    39,     0,    40,    41,
      42,     0,    43,     0,     0,     0,     0,    44,     0,     0,
      45,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,    48,     4,     5,     0,     0,    49,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   136,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,   107,     0,     0,    24,    25,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,    45,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,    48,   184,     4,     5,     0,    49,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,   136,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,   107,     0,     0,
      24,    25,     0,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    33,    34,     0,     0,    35,    36,    37,     0,
      38,    39,     0,    40,    41,    42,     0,    43,     0,     0,
       0,     0,    44,     0,     0,    45,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,    48,   321,     4,
       5,     0,    49,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,    -5,   136,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
     107,     0,     0,    24,    25,     0,    26,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    33,    34,     0,     0,    35,
      36,    37,     0,    38,    39,     0,    40,    41,    42,     0,
      43,     0,     0,     0,     0,    44,     0,     0,    45,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
      48,     4,     5,     0,     0,    49,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,     0,    23,     0,     0,    24,    25,     0,    26,     0,
       0,     0,     0,    27,    28,   541,     0,     0,   542,    29,
      30,     0,     0,    31,     0,    32,     0,    33,    34,     0,
       0,    35,    36,    37,     0,    38,    39,     0,    40,    41,
      42,     0,    43,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,    48,   -56,     4,     5,     0,    49,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,     0,    23,     0,     0,    24,    25,
       0,    26,     0,     0,     0,     0,    27,    28,   541,     0,
       0,   542,    29,    30,     0,     0,    31,     0,    32,     0,
      33,    34,     0,     0,    35,    36,    37,     0,    38,    39,
       0,    40,    41,    42,     0,    43,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,    48,   -57,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,     0,    26,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    33,    34,     0,     0,    35,    36,    37,
       0,    38,    39,     0,    40,    41,    42,     0,    43,     0,
       0,     0,     0,    44,     0,     0,    45,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,    48,     4,
       5,     0,     0,    49,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   136,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
     107,     0,     0,    24,    25,     0,    26,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    33,    34,     0,     0,    35,
      36,    37,     0,    38,    39,     0,    40,    41,    42,     0,
      43,     0,     0,     0,     0,    44,     0,     0,    45,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
      48,     4,     5,     0,     0,    49,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,     0,    23,     0,     0,    24,    25,     0,    26,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    33,    34,     0,
       0,    35,    36,    37,     0,    38,    39,     0,    40,    41,
      42,     0,    43,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,    48,   -58,     4,     5,     0,    49,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,     0,    23,     0,     0,    24,    25,
       0,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      33,    34,     0,     0,    35,    36,    37,     0,    38,    39,
       0,    40,    41,    42,     0,    43,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,    48,   -59,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   107,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,     0,     0,     0,    35,     0,   264,
       0,     0,     0,     0,     0,    41,    42,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,   109,     4,
       5,     0,     0,  -331,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
     109,     4,     5,     0,     0,  -333,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,   107,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    29,
       0,     0,     0,    31,     0,     0,     0,    33,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    41,
      42,     0,    43,     0,     0,     0,     0,     0,     0,   328,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       4,     5,   109,     0,   329,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     4,
       5,   109,     0,  -333,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -5,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,     0,     0,     4,     5,     0,     0,
     109,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   107,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,     0,     0,     0,    31,     0,
       0,     0,    33,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,   328,     0,     0,     0,     0,    46,
      47,     0,     0,     4,     5,     0,     0,   109,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   107,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    13,    14,    15,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,   106,     0,     0,     0,     0,
       0,    41,    42,     0,    43,    21,     0,     0,     0,     0,
       0,   107,     0,     0,   108,     0,    46,    47,     0,     0,
       0,     0,    27,    28,   109,     0,     0,     0,    29,    13,
     506,    15,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,   106,     0,     0,     0,     0,     0,    41,    42,
       0,    43,    21,   539,     0,     0,     0,     0,   107,     0,
       0,   108,     0,    46,    47,     0,     0,     0,     0,    27,
      28,   109,   540,     0,     0,    29,     0,     0,     0,    31,
       0,     0,   541,    33,     0,   542,     0,    35,     0,   543,
       0,     0,     0,     0,     0,    41,    42,     0,    43,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,    46,    47,     0,     0,   544,   545,   546,     0,     0,
     -13,     0,     0,     0,    49
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,    17,     2,    36,   164,   162,    17,   164,    42,    20,
      47,    17,   132,   252,    20,    26,    14,    46,    20,    19,
      26,    37,    16,    20,    18,    26,    37,     3,    44,   126,
       3,    37,    43,    44,   395,     3,     3,    43,    44,     3,
     279,   280,    43,     3,    13,     3,   166,     3,     3,     3,
     170,    45,   378,    55,     3,    55,    47,    47,     3,     3,
      47,    30,     3,   104,   161,    34,   392,     3,   394,     3,
      47,     3,     3,     3,     3,     3,     3,    63,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   128,     3,   130,
       3,     3,   505,   454,   135,   192,   396,    50,    74,   112,
      57,   142,    25,    26,    27,    28,    29,     0,    79,    25,
      26,    27,   153,    29,   155,    72,   213,   158,    79,     3,
     136,   125,   125,    69,   450,   136,    97,    88,   141,    79,
     136,   172,   136,   136,   139,   122,    97,   550,   629,   236,
      47,   238,   299,    35,    36,   122,   637,   147,   136,   140,
     140,   137,   112,   453,   112,    78,   253,   128,   129,   112,
     171,   522,    78,    59,   175,   171,   142,    19,   141,   175,
     171,   139,    79,   173,   175,   142,   131,    79,   142,   148,
      79,   141,   138,   141,   138,   154,   186,   307,   141,   135,
     159,   160,   141,   138,   138,   521,   190,   138,    97,    79,
      20,    86,   138,    88,   138,   566,   138,   138,   138,   138,
     138,   138,    79,    47,   243,    79,    47,    60,   130,   125,
     125,   128,   129,   138,   193,   138,    79,   196,    60,   326,
     136,   136,   629,    76,    47,    88,    79,    37,    38,    39,
     637,   252,    79,   123,    97,   256,   252,    79,   128,   129,
     256,   252,    47,   264,    49,    50,    79,   290,   264,   256,
      47,   128,   129,   264,   128,   129,   363,    79,   279,   280,
      18,    79,    17,   279,   280,    60,    79,     3,   279,   280,
      79,   318,    79,   140,   313,   128,   129,   324,   214,   215,
     216,   128,   129,   304,    79,   415,   128,   129,   304,   419,
     109,   133,   134,   304,    89,   128,   129,    92,    79,   320,
      47,    96,    49,    50,   320,    79,   128,   129,   130,   320,
     128,   129,   130,    79,    88,   128,   129,   112,    47,   128,
     129,   128,   129,    97,   494,   505,   496,   494,    47,   496,
      47,   438,     3,   128,   129,   442,   585,   132,   133,   134,
     589,   127,   137,   127,   514,     3,   141,   514,    21,    22,
      23,    24,   403,   404,   405,   525,   526,   127,   525,   526,
     117,   541,   542,   543,   139,   614,    21,    22,    23,    24,
     550,   228,   229,   230,   231,   396,   420,   421,    15,    16,
     396,   384,   385,   386,   387,   396,    32,    33,    34,   139,
     400,    45,    46,   372,   541,   542,   543,   504,   377,   139,
     410,   411,   423,    15,    16,   426,   139,   423,   113,   114,
     426,   137,   423,    79,   424,   426,   395,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    49,    50,   436,   219,
     220,   221,   453,   284,   285,   217,   218,   453,   139,   605,
     606,    79,   453,   142,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    80,    47,    47,   628,    20,
     630,   628,   629,   630,   515,    19,    18,    17,   447,     3,
     637,   641,   141,    47,   641,   454,   455,    72,   137,    79,
     137,    47,   503,   139,   505,    45,    46,   503,    47,   505,
     533,   138,   503,    28,   138,   140,    28,   138,   506,   478,
     136,    79,    79,   136,   139,   139,   557,    28,   136,   139,
     520,    28,   141,   539,   136,   136,    79,   527,   539,    66,
     541,   542,   543,   539,   138,   541,   542,   543,    56,   550,
      28,   141,   511,   137,   550,   586,   587,   588,   137,    47,
      79,    79,     3,   522,   523,   137,   139,    47,   137,   137,
     529,    47,   138,   137,   136,   138,   143,   567,   137,   550,
     136,    55,   572,   138,   585,   138,   138,   136,   589,   585,
     438,   138,   136,   589,   585,   143,   637,   299,   589,   137,
     140,   137,   137,   562,   137,   423,   310,   566,   291,   606,
     600,   601,   580,   614,    14,   530,   376,   388,   614,   391,
     232,   389,   233,   614,   393,   390,   616,   234,    89,   619,
      -1,   235,    -1,    -1,    -1,    -1,    -1,   629,   237,    -1,
      -1,    -1,    -1,    -1,    -1,   637,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
     237,    -1,    -1,    -1,   222,   223,   224,   225,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,   278,    -1,    47,    48,    49,    28,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    70,
      -1,    -1,    -1,    45,    46,    76,    70,    -1,    79,    -1,
      -1,    -1,    76,    -1,    -1,    79,    87,    88,    -1,    -1,
      -1,    -1,    93,    87,    88,    -1,    97,    -1,    -1,    93,
     101,    -1,    -1,    97,   105,    -1,   107,   101,    -1,    -1,
      -1,   105,   113,   114,    -1,   116,    -1,    -1,    -1,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   364,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   140,    -1,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,   446,
      -1,    -1,    -1,   450,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,   450,    87,    88,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   521,    35,    36,    -1,   142,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    35,    36,
      -1,    -1,   142,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,    35,    36,    -1,   141,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,
      -1,   105,   106,   107,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
     124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    35,    36,    -1,    -1,   141,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    35,    36,    -1,   141,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,
     109,   110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    35,
      36,    -1,   141,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,
     106,   107,    -1,   109,   110,    -1,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    35,    36,    -1,    -1,   141,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,
      -1,   105,   106,   107,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,    35,    36,    -1,   141,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,   106,   107,    -1,   109,   110,
      -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,    35,    36,    -1,
     141,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,   107,
      -1,   109,   110,    -1,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    35,
      36,    -1,    -1,   141,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,
     106,   107,    -1,   109,   110,    -1,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    35,    36,    -1,    -1,   141,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,
      -1,   105,   106,   107,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,    35,    36,    -1,   141,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,   106,   107,    -1,   109,   110,
      -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,    35,    36,    -1,
     141,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    35,
      36,    -1,    -1,   141,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    35,    36,    -1,    -1,   141,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      35,    36,   136,    -1,   138,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    35,
      36,   136,    -1,   138,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    35,    36,    -1,    -1,
     136,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    35,    36,    -1,    -1,   136,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    47,    48,    49,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    60,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,   128,   129,    -1,    -1,
      -1,    -1,    87,    88,   136,    -1,    -1,    -1,    93,    47,
      48,    49,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    60,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    70,    60,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,   128,   129,    -1,    -1,    -1,    -1,    87,
      88,   136,    79,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,    89,   101,    -1,    92,    -1,   105,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,   128,   129,    -1,    -1,   132,   133,   134,    -1,    -1,
     137,    -1,    -1,    -1,   141
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  ParserImplementation::yystos_[] =
  {
         0,   144,   145,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    54,    60,    61,    64,
      68,    70,    74,    76,    79,    80,    82,    87,    88,    93,
      94,    97,    99,   101,   102,   105,   106,   107,   109,   110,
     112,   113,   114,   116,   121,   124,   128,   129,   136,   141,
     146,   147,   160,   161,   162,   171,   174,   179,   180,   181,
     182,   183,   184,   185,   188,   189,   197,   199,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   216,   217,   218,
     225,   226,   227,   228,   229,   235,   239,   240,   241,   244,
     245,   246,   247,   248,   249,   250,   252,   254,   256,   258,
     260,   262,   264,   266,   269,   274,    60,    76,    79,   136,
     244,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     269,   239,   240,     3,   230,   231,   273,    79,   178,    79,
     192,   194,   196,   197,   199,   178,    60,   179,    60,    76,
      79,   160,   194,    47,   122,    79,   178,   139,    47,    79,
      97,   196,   269,   272,    47,   269,   136,   182,   192,    47,
      47,   125,   136,   163,   136,   163,    79,   164,   165,   177,
     196,    47,   192,   178,   198,   273,    79,    88,    97,   200,
     238,    79,    88,    97,   137,   179,   187,   236,   237,   238,
      59,   174,    47,    49,    50,   242,    49,    50,   242,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      45,    46,   140,   268,    37,    38,    39,    35,    36,    32,
      33,    34,    25,    26,    27,    28,    29,    78,    21,    22,
      23,    24,    20,    19,    18,    17,    15,    16,     3,   274,
      79,   138,   242,     3,    74,   142,   232,   233,     3,   142,
     266,   274,    47,   140,   201,   222,     3,   274,   222,   274,
     109,    79,    79,   274,   107,   244,   249,   251,   253,   255,
     257,   259,   261,   263,   265,   267,   270,   271,    47,    47,
      47,   179,   269,   127,   127,   127,   274,   269,   274,    57,
      72,   219,   220,   274,   269,   269,   266,   160,   170,   173,
     176,   180,   170,   222,     3,   117,   222,    79,   190,   191,
     196,   274,   179,     3,   130,    79,   130,   196,     3,   131,
     139,   137,   179,   137,     3,   141,   139,   178,   123,   138,
     168,   243,   266,   269,    79,   269,    79,   266,   246,   246,
     246,   247,   247,   248,   248,   248,   249,   249,   249,   249,
     249,   249,   250,   250,   250,   250,   252,   254,   256,   258,
     266,   260,   266,   273,    47,   122,   142,    80,   234,   177,
     266,   194,    47,    79,   193,   195,   196,    28,   268,    25,
      26,    27,    29,    78,    21,    22,    23,    24,    20,    19,
      18,    17,    15,    16,     3,   141,   107,   244,   177,   177,
     138,    79,    97,   186,   186,   186,   138,    47,   182,   220,
     138,   138,   137,   176,   137,    79,   123,   166,   167,   196,
     113,   114,   222,     3,   138,   201,   273,    79,   238,    79,
     196,   238,   266,    69,   135,   148,   149,    79,     3,   138,
     142,   142,   139,   142,   266,   244,    47,    47,   138,   269,
     140,   202,   223,     3,   141,    28,   223,   269,   244,   267,
     249,   249,   249,   249,   249,   251,   251,   251,   251,   253,
     255,   257,   259,   267,   261,   267,   272,   195,    28,   138,
     138,   179,    50,   274,   274,   274,   136,   212,    79,   179,
     179,   222,    79,   222,   136,   163,   136,   163,   191,   179,
      79,   130,   196,   139,   139,   136,    48,   239,   168,   266,
     266,    28,   244,   269,   136,   138,   267,   195,   272,   269,
     138,   139,   141,    28,   269,   136,   136,    66,    79,    56,
     213,   214,   224,   138,   170,   170,    79,   196,   266,    60,
      79,    89,    92,    96,   132,   133,   134,   146,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   192,   203,
     239,   269,    28,   138,   170,   274,   141,   138,   179,   267,
     272,   269,   138,   170,   170,   179,   269,   214,    63,   137,
     215,   182,   137,   137,   192,    47,   159,   159,   159,    47,
      79,    79,   137,   153,   274,   138,   269,   137,   272,   179,
     138,   138,   179,   137,   137,   139,   139,   224,   177,   274,
     274,   274,   177,    47,    47,   138,   138,   179,   179,   187,
     221,   221,   137,   138,   138,   138,   177,   179,   136,   136,
     136,   138,   170,   157,   158,   160,   169,   172,   175,   180,
     170,   136,   137,   137,   175,   137,   170,   137
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
     368,   369,   370,   371,   372,   373,   123,   125,    41,    58,
      61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   143,   145,   144,   146,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   152,   152,   153,   153,   153,   153,
     153,   153,   154,   155,   156,   157,   158,   159,   159,   159,
     159,   159,   159,   160,   160,   161,   161,   162,   162,   162,
     162,   162,   162,   162,   162,   163,   164,   164,   165,   165,
     165,   165,   166,   166,   167,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     179,   180,   180,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   182,   182,
     183,   184,   184,   185,   185,   185,   186,   186,   186,   187,
     187,   188,   188,   188,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   197,   198,   198,   198,   198,   199,   200,   200,   200,
     200,   200,   200,   201,   202,   203,   204,   205,   205,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   208,   209,
     210,   211,   212,   212,   213,   213,   214,   215,   216,   217,
     218,   218,   218,   219,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   226,   227,
     227,   228,   228,   228,   228,   228,   228,   229,   229,   229,
     229,   230,   230,   231,   231,   232,   233,   233,   234,   234,
     235,   236,   236,   237,   237,   238,   238,   238,   239,   239,
     239,   239,   239,   239,   240,   240,   241,   241,   241,   241,
     242,   242,   243,   243,   243,   243,   244,   244,   244,   244,
     245,   245,   245,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   247,   247,   247,   247,   248,   248,   248,
     249,   249,   249,   249,   250,   250,   250,   250,   250,   250,
     250,   251,   251,   251,   251,   251,   251,   252,   252,   252,
     252,   252,   253,   253,   253,   253,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   269,   269,   270,
     270,   271,   271,   272,   272,   273,   273,   274,   274
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     7,     0,     1,     0,     2,     1,
       1,     0,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     7,     2,     3,     3,     3,     1,     2,     1,
       7,     7,     8,     8,     8,     8,     1,     7,     4,     7,
       4,     5,     5,     2,     2,     2,     1,     3,     2,     2,
       4,     4,     0,     1,     2,     2,     0,     1,     0,     1,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
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
       1,     4,     3,     3,     1,     2,     2,     2,     4,     3,
       2,     3,     1,     1,     3,     3,     1,     1,     1,     1,
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
  "JS_DSTA_BEGIN", "JS_DSTO_BEGIN", "JS_DSTA_END", "JS_DSTO_END",
  "JS_CONSTRUCTOR", "JS_GET", "JS_SET", "JS_PROTOTYPE", "'{'", "'}'",
  "')'", "':'", "'='", "';'", "']'", "$accept", "program", "$@1",
  "class_initialiser", "class_adjective__opt", "inherit_declaration__opt",
  "inherit_declaration", "class_body__opt", "class_body",
  "class_element_list", "class_element", "constructor_definition",
  "prototype_property_definition", "class_property_definition",
  "instance_property_definition", "private_property_definition",
  "exportable_definition", "function_declaration", "function_expression",
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
       144,     0,    -1,    -1,   145,   171,    -1,   147,    59,   178,
     148,   136,   150,   137,    -1,    -1,    60,    -1,    -1,   149,
     239,    -1,    69,    -1,   135,    -1,    -1,   151,    -1,   152,
      -1,   153,    -1,   152,   153,    -1,   154,    -1,   203,    -1,
     155,    -1,   156,    -1,   157,    -1,   158,    -1,   132,    47,
     177,   138,   136,   169,   137,    -1,   159,   274,    -1,    96,
     159,   274,    -1,    92,   159,   274,    -1,    89,   159,   274,
      -1,   192,    -1,    60,   192,    -1,   146,    -1,    79,    47,
     177,   138,   136,   170,   137,    -1,   133,    79,    47,   138,
     136,   170,   137,    -1,   134,    79,    47,   177,   138,   136,
     170,   137,    -1,    76,    79,    47,   177,   138,   136,   170,
     137,    -1,    60,    79,    47,   177,   138,   136,   170,   137,
      -1,    76,   178,    47,   177,   138,   136,   170,   137,    -1,
     162,    -1,   116,   177,   117,   113,   136,   170,   137,    -1,
     113,   136,   170,   137,    -1,   116,   177,   117,   114,   136,
     170,   137,    -1,   114,   136,   170,   137,    -1,   116,   177,
     117,   113,   163,    -1,   116,   177,   117,   114,   163,    -1,
     114,   163,    -1,   113,   163,    -1,   125,   266,    -1,   165,
      -1,   165,     3,   166,    -1,    79,   222,    -1,   196,   222,
      -1,   165,     3,    79,   222,    -1,   165,     3,   196,   222,
      -1,    -1,   167,    -1,   123,    79,    -1,   123,    79,    -1,
      -1,   172,    -1,    -1,   173,    -1,   174,    -1,   171,   174,
      -1,   175,    -1,   172,   175,    -1,   176,    -1,   173,   176,
      -1,   179,    -1,   160,    -1,   180,    -1,   160,    -1,   157,
      -1,   158,    -1,   180,    -1,   160,    -1,    -1,   164,    -1,
      -1,    79,    -1,   180,    -1,   183,    -1,   184,    -1,   182,
      -1,   181,    -1,   188,    -1,   189,    -1,   203,    -1,   204,
      -1,   205,    -1,   206,    -1,   207,    -1,   208,    -1,   209,
      -1,   210,    -1,   216,    -1,   211,    -1,   217,    -1,   218,
      -1,   185,    -1,   136,   137,    -1,   136,   187,   137,    -1,
     124,   178,   179,    -1,    68,   194,   274,    -1,    68,   160,
      -1,    82,    79,   127,   186,   274,    -1,    82,   196,   127,
     186,   274,    -1,    82,    97,   127,   186,   274,    -1,    97,
      -1,    79,    -1,   186,    50,    79,    -1,   179,    -1,   187,
     179,    -1,   107,   192,   274,    -1,    60,   192,   274,    -1,
     121,   192,   274,    -1,   121,    47,   190,   138,   179,    -1,
     191,    -1,   190,     3,   191,    -1,    79,   222,    -1,   196,
     201,    -1,   194,    -1,   192,     3,   194,    -1,   195,    -1,
     193,     3,   195,    -1,    79,   222,    -1,   196,   222,    -1,
      79,   223,    -1,   196,   223,    -1,   197,    -1,   199,    -1,
     128,   273,   130,    -1,   128,   198,   130,    -1,   128,   198,
       3,   273,   130,    -1,   273,    79,    -1,   273,   196,    -1,
     198,     3,   273,    79,    -1,   198,     3,   273,   196,    -1,
     129,   200,   131,    -1,    79,    -1,   238,   139,    79,    -1,
     238,   139,   196,    -1,   200,     3,   238,   139,    79,    -1,
     200,     3,    79,    -1,   200,     3,   238,   139,   196,    -1,
     140,   266,    -1,   140,   267,    -1,   274,    -1,   269,   274,
      -1,    80,    47,   269,   138,   179,    66,   179,    -1,    80,
      47,   269,   138,   179,    -1,    64,   179,   109,    47,   269,
     138,   274,    -1,   109,    47,   269,   138,   179,    -1,    74,
      47,   271,   141,   272,   141,   272,   138,   179,    -1,    74,
      47,   107,   193,   141,   272,   141,   272,   138,   179,    -1,
      74,    47,   244,    28,   269,   138,   179,    -1,    74,    47,
     107,   195,    28,   269,   138,   179,    -1,    74,   122,    47,
     244,    28,   269,   138,   179,    -1,    74,   122,    47,   107,
     195,    28,   269,   138,   179,    -1,    61,   178,   274,    -1,
      54,   178,   274,    -1,    94,   272,   274,    -1,   110,    47,
     269,   138,   179,    -1,    99,    47,   269,   138,   212,    -1,
     136,   224,   137,    -1,   136,   224,   215,   224,   137,    -1,
     214,    -1,   213,   214,    -1,    56,   269,   139,   221,    -1,
      63,   139,   221,    -1,    79,   139,   179,    -1,   102,   269,
     274,    -1,   106,   182,   219,    -1,   106,   182,   220,    -1,
     106,   182,   219,   220,    -1,    57,    47,    79,   138,   182,
      -1,    72,   182,    -1,    -1,   187,    -1,    -1,   201,    -1,
      -1,   202,    -1,    -1,   213,    -1,   226,    -1,   227,    -1,
      88,    -1,    97,    -1,    93,    -1,    87,    -1,   105,    -1,
      70,    -1,   101,    -1,    79,    -1,   225,    -1,   229,    -1,
     235,    -1,    47,   269,   138,    -1,    49,   273,   142,    -1,
      49,   230,   142,    -1,    49,   230,     3,   273,   142,    -1,
      49,   230,   232,   142,    -1,   273,   266,    -1,   230,     3,
     273,   266,    -1,     3,    -1,   231,     3,    -1,   233,   234,
      -1,    74,    47,   244,    28,   269,   138,    -1,    74,   122,
      47,   244,    28,   269,   138,    -1,    -1,    80,    47,   269,
     138,    -1,   136,   236,   137,    -1,    -1,   237,   141,    -1,
     238,   139,   266,    -1,   237,     3,   238,   139,   266,    -1,
      79,    -1,    97,    -1,    88,    -1,   228,    -1,   161,    -1,
     146,    -1,   239,    49,   269,   142,    -1,   239,    50,    79,
      -1,    48,   239,   242,    -1,   239,    -1,    48,   240,    -1,
     239,   242,    -1,   241,   242,    -1,   241,    49,   269,   142,
      -1,   241,    50,    79,    -1,    47,   138,    -1,    47,   243,
     138,    -1,   266,    -1,   168,    -1,   243,     3,   266,    -1,
     243,     3,   168,    -1,   240,    -1,   241,    -1,   197,    -1,
     199,    -1,   244,    -1,   244,    46,    -1,   244,    45,    -1,
     245,    -1,    42,   246,    -1,    43,   246,    -1,    44,   246,
      -1,    46,   246,    -1,    45,   246,    -1,    35,   246,    -1,
      36,   246,    -1,    41,   246,    -1,    40,   246,    -1,   246,
      -1,   247,    37,   246,    -1,   247,    38,   246,    -1,   247,
      39,   246,    -1,   247,    -1,   248,    35,   247,    -1,   248,
      36,   247,    -1,   248,    -1,   249,    34,   248,    -1,   249,
      33,   248,    -1,   249,    32,   248,    -1,   249,    -1,   250,
      26,   249,    -1,   250,    25,   249,    -1,   250,    29,   249,
      -1,   250,    78,   249,    -1,   250,    27,   249,    -1,   250,
      28,   249,    -1,   249,    -1,   251,    26,   249,    -1,   251,
      25,   249,    -1,   251,    29,   249,    -1,   251,    78,   249,
      -1,   251,    27,   249,    -1,   250,    -1,   252,    23,   250,
      -1,   252,    22,   250,    -1,   252,    24,   250,    -1,   252,
      21,   250,    -1,   251,    -1,   253,    23,   251,    -1,   253,
      22,   251,    -1,   253,    24,   251,    -1,   253,    21,   251,
      -1,   252,    -1,   254,    20,   252,    -1,   253,    -1,   255,
      20,   253,    -1,   254,    -1,   256,    19,   254,    -1,   255,
      -1,   257,    19,   255,    -1,   256,    -1,   258,    18,   256,
      -1,   257,    -1,   259,    18,   257,    -1,   258,    -1,   260,
      17,   258,    -1,   259,    -1,   261,    17,   259,    -1,   260,
      -1,   262,    16,   260,    -1,   261,    -1,   263,    16,   261,
      -1,   262,    -1,   262,    15,   266,   139,   266,    -1,   263,
      -1,   263,    15,   267,   139,   267,    -1,   264,    -1,   244,
     268,   266,    -1,   265,    -1,   244,   268,   267,    -1,   140,
      -1,    10,    -1,    12,    -1,    11,    -1,    14,    -1,     5,
      -1,     7,    -1,     6,    -1,     4,    -1,    13,    -1,     9,
      -1,     8,    -1,   266,    -1,   269,     3,   266,    -1,   267,
      -1,   270,     3,   267,    -1,    -1,   270,    -1,    -1,   269,
      -1,    -1,   231,    -1,   141,    -1,   112,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ParserImplementation::yyprhs_[] =
  {
         0,     0,     3,     4,     7,    15,    16,    18,    19,    22,
      24,    26,    27,    29,    31,    33,    36,    38,    40,    42,
      44,    46,    48,    56,    59,    63,    67,    71,    73,    76,
      78,    86,    94,   103,   112,   121,   130,   132,   140,   145,
     153,   158,   164,   170,   173,   176,   179,   181,   185,   188,
     191,   196,   201,   202,   204,   207,   210,   211,   213,   214,
     216,   218,   221,   223,   226,   228,   231,   233,   235,   237,
     239,   241,   243,   245,   247,   248,   250,   251,   253,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   296,
     300,   304,   308,   311,   317,   323,   329,   331,   333,   337,
     339,   342,   346,   350,   354,   360,   362,   366,   369,   372,
     374,   378,   380,   384,   387,   390,   393,   396,   398,   400,
     404,   408,   414,   417,   420,   425,   430,   434,   436,   440,
     444,   450,   454,   460,   463,   466,   468,   471,   479,   485,
     493,   499,   509,   520,   528,   537,   546,   556,   560,   564,
     568,   574,   580,   584,   590,   592,   595,   600,   604,   608,
     612,   616,   620,   625,   631,   634,   635,   637,   638,   640,
     641,   643,   644,   646,   648,   650,   652,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   676,   680,   684,
     690,   695,   698,   703,   705,   708,   711,   718,   726,   727,
     732,   736,   737,   740,   744,   750,   752,   754,   756,   758,
     760,   762,   767,   771,   775,   777,   780,   783,   786,   791,
     795,   798,   802,   804,   806,   810,   814,   816,   818,   820,
     822,   824,   827,   830,   832,   835,   838,   841,   844,   847,
     850,   853,   856,   859,   861,   865,   869,   873,   875,   879,
     883,   885,   889,   893,   897,   899,   903,   907,   911,   915,
     919,   923,   925,   929,   933,   937,   941,   945,   947,   951,
     955,   959,   963,   965,   969,   973,   977,   981,   983,   987,
     989,   993,   995,   999,  1001,  1005,  1007,  1011,  1013,  1017,
    1019,  1023,  1025,  1029,  1031,  1035,  1037,  1041,  1043,  1049,
    1051,  1057,  1059,  1063,  1065,  1069,  1071,  1073,  1075,  1077,
    1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1099,
    1101,  1105,  1106,  1108,  1109,  1111,  1112,  1114,  1116
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   364,   364,   364,   375,   386,   387,   392,   393,   407,
     408,   413,   414,   418,   423,   444,   468,   474,   475,   476,
     477,   478,   483,   498,   508,   518,   527,   537,   538,   544,
     545,   556,   568,   588,   605,   621,   631,   644,   653,   662,
     672,   682,   692,   703,   714,   728,   739,   740,   758,   774,
     782,   792,   802,   803,   812,   829,   839,   840,   844,   845,
     849,   857,   868,   876,   887,   895,   905,   906,   917,   918,
     925,   926,   931,   932,   942,   943,   950,   951,   960,   961,
     966,   974,   979,   983,   988,   992,   997,  1002,  1007,  1012,
    1017,  1022,  1027,  1032,  1037,  1042,  1047,  1052,  1059,  1066,
    1077,  1090,  1097,  1108,  1125,  1140,  1160,  1168,  1176,  1186,
    1194,  1205,  1213,  1221,  1232,  1242,  1248,  1255,  1263,  1274,
    1282,  1292,  1298,  1306,  1314,  1324,  1332,  1343,  1347,  1354,
    1364,  1371,  1384,  1396,  1406,  1416,  1427,  1438,  1448,  1460,
    1470,  1480,  1488,  1499,  1503,  1507,  1511,  1525,  1534,  1546,
    1554,  1562,  1574,  1586,  1597,  1609,  1620,  1634,  1644,  1654,
    1664,  1675,  1686,  1690,  1699,  1705,  1713,  1724,  1735,  1748,
    1758,  1767,  1776,  1788,  1799,  1807,  1808,  1812,  1813,  1817,
    1818,  1822,  1823,  1827,  1828,  1829,  1836,  1843,  1853,  1863,
    1870,  1880,  1887,  1894,  1895,  1896,  1897,  1905,  1915,  1922,
    1932,  1943,  1953,  1964,  1965,  1970,  1978,  1985,  1995,  1996,
    2005,  2020,  2023,  2030,  2039,  2049,  2056,  2063,  2073,  2077,
    2081,  2086,  2099,  2114,  2130,  2131,  2141,  2154,  2167,  2180,
    2198,  2199,  2203,  2209,  2215,  2220,  2228,  2229,  2230,  2231,
    2235,  2239,  2246,  2256,  2257,  2264,  2271,  2278,  2285,  2292,
    2299,  2306,  2313,  2323,  2324,  2328,  2332,  2339,  2340,  2344,
    2351,  2352,  2356,  2360,  2367,  2368,  2372,  2376,  2380,  2384,
    2388,  2395,  2396,  2400,  2404,  2408,  2412,  2419,  2420,  2424,
    2428,  2432,  2439,  2440,  2444,  2448,  2452,  2459,  2460,  2467,
    2468,  2475,  2476,  2483,  2484,  2491,  2492,  2499,  2500,  2507,
    2508,  2515,  2516,  2523,  2524,  2531,  2532,  2539,  2540,  2549,
    2550,  2559,  2563,  2573,  2577,  2588,  2589,  2590,  2591,  2592,
    2593,  2594,  2595,  2596,  2597,  2598,  2599,  2603,  2610,  2618,
    2625,  2633,  2634,  2638,  2639,  2643,  2644,  2648,  2649
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
      47,   138,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   139,   141,
      26,   140,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   142,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,    18,   137,    41,     2,     2,     2,
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
     132,   133,   134,   135
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 2984;
  const int ParserImplementation::yynnts_ = 132;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 143;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 373;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 5689 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2652 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


