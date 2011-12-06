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
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1103 "grammar/grammar.yy"
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
#line 1120 "grammar/grammar.yy"
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
#line 1135 "grammar/grammar.yy"
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
#line 1155 "grammar/grammar.yy"
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
#line 1163 "grammar/grammar.yy"
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
#line 1171 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1181 "grammar/grammar.yy"
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
#line 1189 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1200 "grammar/grammar.yy"
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
#line 1208 "grammar/grammar.yy"
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
#line 1216 "grammar/grammar.yy"
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
#line 1227 "grammar/grammar.yy"
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
#line 1237 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1243 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1250 "grammar/grammar.yy"
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
#line 1258 "grammar/grammar.yy"
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
#line 1269 "grammar/grammar.yy"
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
#line 1277 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1287 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1293 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1301 "grammar/grammar.yy"
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
#line 1309 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1319 "grammar/grammar.yy"
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
#line 1327 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1338 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1342 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1349 "grammar/grammar.yy"
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
#line 1359 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1366 "grammar/grammar.yy"
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
#line 1379 "grammar/grammar.yy"
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
#line 1391 "grammar/grammar.yy"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1401 "grammar/grammar.yy"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1411 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1422 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1433 "grammar/grammar.yy"
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

  case 137:

/* Line 690 of lalr1.cc  */
#line 1443 "grammar/grammar.yy"
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

  case 138:

/* Line 690 of lalr1.cc  */
#line 1455 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1465 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1475 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1483 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1493 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1497 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1501 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1506 "grammar/grammar.yy"
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

  case 146:

/* Line 690 of lalr1.cc  */
#line 1520 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1529 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1541 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1557 "grammar/grammar.yy"
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

  case 151:

/* Line 690 of lalr1.cc  */
#line 1569 "grammar/grammar.yy"
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

  case 152:

/* Line 690 of lalr1.cc  */
#line 1581 "grammar/grammar.yy"
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

  case 153:

/* Line 690 of lalr1.cc  */
#line 1592 "grammar/grammar.yy"
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

  case 154:

/* Line 690 of lalr1.cc  */
#line 1604 "grammar/grammar.yy"
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

  case 155:

/* Line 690 of lalr1.cc  */
#line 1615 "grammar/grammar.yy"
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

  case 156:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1639 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1649 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1659 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1670 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1681 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1685 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1694 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1700 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1708 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1719 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1730 "grammar/grammar.yy"
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

  case 168:

/* Line 690 of lalr1.cc  */
#line 1743 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1753 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1762 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1771 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1783 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1794 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1801 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1802 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1806 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1807 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1811 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1812 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1816 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1817 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1821 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1822 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1824 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1831 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1838 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1848 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1858 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1865 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1875 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1882 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1888 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1889 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1892 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1900 "grammar/grammar.yy"
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

  case 197:

/* Line 690 of lalr1.cc  */
#line 1910 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1917 "grammar/grammar.yy"
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

  case 199:

/* Line 690 of lalr1.cc  */
#line 1927 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1938 "grammar/grammar.yy"
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

  case 201:

/* Line 690 of lalr1.cc  */
#line 1948 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1965 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1973 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1980 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1989 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1991 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2000 "grammar/grammar.yy"
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

  case 210:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2018 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2025 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2034 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2044 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2051 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2068 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2072 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2076 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2081 "grammar/grammar.yy"
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
#line 2094 "grammar/grammar.yy"
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

  case 222:

/* Line 690 of lalr1.cc  */
#line 2109 "grammar/grammar.yy"
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

  case 223:

/* Line 690 of lalr1.cc  */
#line 2124 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2126 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2136 "grammar/grammar.yy"
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

  case 226:

/* Line 690 of lalr1.cc  */
#line 2149 "grammar/grammar.yy"
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
#line 2162 "grammar/grammar.yy"
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

  case 228:

/* Line 690 of lalr1.cc  */
#line 2175 "grammar/grammar.yy"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2192 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2193 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2198 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
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
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2215 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2222 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2223 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2224 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2225 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2230 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2234 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2241 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2250 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2252 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2259 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2266 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2273 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2280 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2287 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2294 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2301 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2317 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2319 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2323 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2327 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2335 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2339 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2345 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2347 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2351 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2355 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2361 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2363 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2367 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2371 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2375 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2379 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2383 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2389 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2391 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2395 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2399 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2403 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2407 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2413 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2415 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2419 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2423 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2427 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2433 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2435 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2439 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2443 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2447 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2453 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2455 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2461 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2463 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2469 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2471 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2477 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2479 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2485 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2487 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2493 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2495 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2501 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2503 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2509 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2511 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2517 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2519 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2525 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2527 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2533 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2535 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2543 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2545 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2554 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2558 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2568 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2572 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2582 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2583 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2584 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2585 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2587 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2588 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2589 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2590 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2591 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2592 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2593 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2598 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2605 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2613 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2620 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2627 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2628 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2632 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2633 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2637 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2638 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2642 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2643 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4045 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -420;
  const short int
  ParserImplementation::yypact_[] =
  {
      -420,    52,  1723,  -420,  2627,  2627,  2627,  2627,  2627,  2627,
    2627,  2627,  2627,  2627,  2772,    40,    54,   110,    54,  1825,
     141,  -420,    69,   103,    -8,    93,   179,  -420,  -420,  -420,
    2433,  -420,   149,  -420,  2627,  -420,   118,   169,   177,   210,
    -420,    19,    27,   205,    22,    54,    40,    42,  1004,  -420,
    -420,   232,  -420,  -420,  -420,  1107,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,   107,  -420,   292,   632,
    -420,  -420,   347,   265,   377,   182,   303,   274,   266,   301,
     294,   290,  -420,  -420,    24,  -420,  -420,    54,  -420,   250,
     300,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
      33,   107,  -420,  -420,    18,   318,   798,  -420,   -42,    -5,
      26,  -420,   188,  -420,  -420,   -42,   169,   240,   169,     2,
     264,   272,  -420,  -420,   352,   673,   322,   349,   351,  1825,
    2627,   304,   329,   331,   417,   -42,  2627,    24,  1209,   143,
     188,    26,  2627,  2627,  2627,  1927,  -420,  1927,  -420,   188,
    -420,   425,   343,   188,   224,    26,  1825,    60,   116,   323,
    -420,  -420,    45,   324,    -8,   325,   326,  -420,  -420,  1312,
     330,    32,   327,    54,  -420,  2235,  2627,   382,  -420,  2627,
     389,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  2627,  2627,  2627,  2627,
    2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,
    2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,
    2627,  2627,  -420,  -420,  -420,  -420,    40,    70,  -420,   328,
     391,  -420,  -420,  -420,  -420,   205,  2627,  -420,  -420,   169,
    -420,  -420,  -420,   422,   352,   205,   426,   427,   231,   100,
     377,   208,   371,   452,   456,   460,   462,   342,  -420,  -420,
     477,   341,  2674,   205,   205,  -420,    47,     5,     5,     5,
    -420,    48,  -420,   436,   118,   412,  -420,  -420,    59,    61,
    -420,  -420,   350,  2030,  -420,  -420,   353,  -420,   194,   248,
    -420,   188,    65,  -420,   188,  -420,  -420,    40,  -420,  -420,
    -420,  -420,   293,  -420,   235,  -420,  -420,  -420,   250,  -420,
    2627,   -35,   407,  -420,  -420,    68,  -420,    35,  -420,    38,
    -420,  -420,  -420,  -420,  -420,   347,   347,   265,   265,   265,
     377,   377,   377,   377,   377,   377,   182,   182,   182,   182,
     303,   274,   266,   301,   355,   294,  -420,   901,  2725,   441,
    -420,   442,  -420,   354,  -420,  -420,  2627,   359,   360,   205,
     362,    43,   463,   362,  2627,  2627,  2627,  2627,  2627,  2627,
    2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,  2627,
    2627,  2627,  2133,   231,   471,   366,   368,  1825,  -420,  -420,
       8,     8,     8,   372,   421,  -420,  -420,  1825,  1825,  -420,
    -420,  -420,   188,   431,  -420,  -420,   188,    28,   106,  -420,
     224,  1825,  -420,   138,   323,   373,  -420,  -420,   374,  -420,
    -420,  -420,   378,  2796,  -420,  2530,  -420,  -420,  -420,  2627,
    -420,  -420,   487,  2725,  2627,   380,    83,   384,   385,   392,
    2627,  -420,  -420,   231,  2133,  2627,  -420,    84,   632,  -420,
     377,   377,   377,   377,   377,   208,   208,   208,   208,   371,
     452,   456,   460,   383,   462,  -420,   388,   503,  2627,   401,
     402,   478,   464,  -420,  -420,  -420,   489,  -420,   409,  -420,
    -420,  -420,  -420,  -420,  1927,  -420,  1927,  -420,  -420,  -420,
    -420,  -420,  -420,   237,  2627,   203,  2796,   364,  -420,  -420,
    -420,  2627,   523,    85,  1927,   -42,  1927,  1927,   423,  -420,
    -420,   419,    87,  1825,  2627,  2334,  2627,    88,  1927,  1927,
    1825,  -420,  2627,   489,  -420,     4,   118,   416,   428,  -420,
    -420,  -420,   141,   141,   141,   511,   432,  -420,  2802,  -420,
    -420,  -420,  -420,  -420,  -420,   -42,  -420,   107,    90,  2627,
    -420,   433,  -420,   434,   435,  1927,  2334,  1825,  -420,  -420,
     439,    91,  1825,   437,   443,  -420,    44,  -420,   429,  -420,
     489,  -420,  -420,  -420,   -42,   -42,   -42,   205,  -420,  -420,
    -420,  -420,    94,  -420,  -420,  -420,   445,   440,  -420,  1825,
    1825,  -420,  -420,  -420,  1415,  1415,   446,  -420,  -420,  -420,
     448,  -420,  -420,  1825,  -420,  -420,  1415,  -420,  -420,  -420,
     451,  -420,  1517,  -420,  -420,  -420,   447,  1620,  -420,  -420,
    -420,  -420
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     5,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   334,    76,     6,    76,     5,
       5,   189,     0,    76,   191,     0,     0,   187,   184,   186,
     332,   185,     0,   190,     5,   188,     0,     0,     0,     0,
     337,     0,     0,    74,     0,    76,   334,     0,     5,   336,
     219,     0,    67,   218,    36,     3,    60,    66,    78,    82,
      81,    79,    80,    97,    83,    84,   237,   238,    85,    86,
      87,    88,    89,    90,    91,    92,    94,    93,    95,    96,
     192,   182,   183,   217,   193,   194,   223,   235,   236,   239,
     242,   252,   256,   259,   263,   276,   286,   290,   294,   298,
     302,   306,   310,   326,     0,   144,     6,    76,   191,   210,
     239,   248,   249,   251,   250,   243,   244,   245,   247,   246,
       0,   223,   224,   202,     0,   335,     5,    77,     0,   176,
       0,   118,   176,   126,   127,     0,     6,     0,     6,   176,
       0,     0,    29,   101,    27,     5,     0,     0,     0,     5,
       5,     0,     0,     0,   333,     0,     5,     0,     5,     0,
     176,     0,     5,     5,     5,     5,    44,     5,    43,   176,
      75,    46,     0,   176,     0,     0,     5,     0,     0,   136,
     216,   215,     0,     0,   191,   184,   185,    98,   108,     5,
       0,     0,     0,    76,    61,     5,     5,     0,   225,     5,
       0,   226,   322,   319,   321,   320,   325,   324,   315,   317,
     316,   323,   318,   241,   240,   314,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,   145,   214,   195,   222,   334,     0,   197,     0,
     207,   203,   196,   200,   157,    74,     5,   177,   122,     0,
     111,   123,   156,     0,    28,    74,     0,     0,     0,   239,
     270,   281,   288,   292,   296,   300,   304,   308,   312,   328,
     331,     0,     5,    74,    74,   167,     0,     0,     0,     0,
     158,     0,   168,     0,     0,   169,   170,   110,     0,     0,
      45,    73,     0,     5,    64,    72,     0,    48,    52,     0,
      49,   176,     0,   114,     0,   112,   100,   334,   129,   131,
     128,   132,     0,   135,     0,    99,   109,   209,     0,   211,
       5,     7,     0,   229,   232,     0,   231,     0,   221,     0,
     228,   311,   253,   254,   255,   257,   258,   262,   261,   260,
     265,   264,   268,   269,   266,   267,   280,   278,   277,   279,
     287,   291,   295,   299,     0,   303,   327,     5,     5,     0,
     199,     0,   204,     0,   142,   119,     5,     0,     0,    74,
     178,     0,   120,   178,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     0,     0,     0,     0,     5,   106,   105,
       0,     0,     0,     0,     0,   173,   171,     5,     5,    38,
      65,    40,   176,     0,    47,    53,   176,     0,     0,   116,
       0,     5,   117,     0,   140,     0,   137,   138,     0,   212,
       9,    10,     0,     5,    55,     5,   230,   220,   227,     5,
     198,   201,     0,     5,     5,     0,     0,     0,     0,     0,
       5,   179,   124,     0,     5,     5,   125,     0,   239,   313,
     272,   271,   275,   273,   274,   285,   283,   282,   284,   289,
     293,   297,   301,     0,   305,   329,     0,     0,     5,     0,
       0,   147,     0,   102,   104,   103,   180,   160,     0,   149,
     159,    50,    54,    51,     5,    41,     5,    42,   115,   113,
     133,   130,   134,     0,     5,     5,     5,     8,   234,   233,
     307,     5,     0,     0,     5,     0,     5,     5,     0,   143,
     121,     0,     0,     5,     5,     5,     5,     0,     5,     5,
       5,   107,     5,   181,   163,     0,     0,     0,     0,   139,
     141,   213,     5,     5,     5,     0,     0,    12,     5,    14,
      16,    18,    19,    20,    21,     0,    17,     0,     0,     5,
     208,     0,   148,     0,     0,     5,     5,     5,   152,   309,
       0,     0,     5,     0,     0,   146,     0,   164,     0,   161,
     180,   172,    37,    39,     0,     0,     0,    74,     4,    15,
      23,   205,     0,    34,    30,    31,     0,     0,   153,     5,
       5,   154,    33,    35,   174,   174,     0,    26,    25,    24,
       0,   206,    32,     5,   150,   155,   175,   165,   166,   162,
       0,   151,     5,    70,    71,    69,     0,     5,    62,    68,
      22,    63
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -420,  -420,  -420,     3,  -420,  -420,  -420,  -420,  -420,  -420,
      21,  -420,  -420,  -420,  -419,  -396,   -18,    -2,  -420,  -420,
     -27,  -420,  -420,  -420,  -420,   144,  -420,  -150,  -420,  -420,
    -420,   533,   -47,   289,  -210,    12,    -1,  -156,  -420,   -29,
    -420,  -420,  -420,   134,  -162,  -420,  -420,  -420,   165,    78,
    -420,   335,  -344,    -6,   -12,  -420,    -4,  -420,   282,  -420,
    -397,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,    55,  -420,  -420,  -420,  -420,  -420,   302,   -16,  -113,
     218,    13,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,   -41,   -11,   588,  -420,   164,
    -420,   430,  -420,    71,   234,   226,   298,   171,    53,   369,
     211,   375,   209,   376,   213,   379,   214,   381,   215,  -420,
    -420,  -420,  -420,   -37,  -375,   525,    31,  -420,  -420,  -398,
     -34,   -32
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    50,    51,   442,   443,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   301,    53,    54,
     166,   170,   171,   424,   425,   334,   636,   302,    55,   637,
     303,    56,   638,   304,   172,   148,   188,    58,    59,    60,
      61,    62,    63,   410,   189,    64,    65,   312,   313,   144,
     381,   131,   382,   132,    66,   177,    67,   182,   257,   461,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   497,
     543,   544,   590,    77,    78,    79,   295,   296,   627,   258,
     462,   545,    80,    81,    82,    83,    84,   124,   125,   249,
     250,   372,    85,   190,   191,   192,    86,    87,    88,   245,
     335,    89,    90,    91,    92,    93,    94,    95,   271,    96,
     272,    97,   273,    98,   274,    99,   275,   100,   276,   101,
     277,   102,   278,   103,   279,   385,   104,   280,   281,   155,
     126,   105
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -333;
  const short int
  ParserImplementation::yytable_[] =
  {
        52,    57,   143,   121,   486,   133,   183,   159,   133,   305,
     469,   305,   178,   134,   133,   168,   134,   306,   137,   261,
     153,   246,   134,   142,   483,   133,   485,   241,   128,   259,
     135,   133,   133,   134,   440,   328,   241,   173,   241,   134,
     134,   241,   255,   123,   120,   373,   463,   241,   322,   265,
     241,   241,     3,    52,    57,   377,   307,   176,   492,   487,
     310,   154,   241,   317,   241,   157,   531,   588,   430,   174,
      40,   445,   242,   405,   406,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   408,   529,   241,   241,   241,   253,
     241,   241,   247,   241,   241,   130,   254,   241,   260,    49,
     441,   160,   409,   262,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   161,   145,   368,   566,   530,
      40,   179,   175,   290,   133,   292,   133,   300,   384,   297,
     180,   149,   134,   127,   134,   256,    40,   580,    40,   181,
     150,   589,   256,   315,   164,   213,   214,   305,   285,    49,
      46,    47,   164,   164,   195,   165,   196,   197,   336,   579,
     248,   566,   133,   167,   504,    49,   133,    49,   314,   459,
     134,   244,   321,   329,   134,   316,   323,   447,   607,   341,
     448,   286,   147,   614,   464,   407,   413,   291,   326,   129,
     318,   146,   369,   298,   299,   319,   156,   417,   429,   418,
     293,   138,   364,   431,   366,   331,   446,   225,   226,   227,
     228,   229,   367,   633,   130,   294,   264,   510,   633,   374,
     139,   525,   533,   570,   162,   577,   582,   337,   601,   610,
     339,   164,   621,   386,   387,   388,   634,   389,    46,    47,
     215,   634,   506,   133,    46,    47,   320,   133,   160,   173,
     198,   134,   201,   133,   158,   134,   133,   163,   151,   173,
     230,   134,   383,   138,   134,   415,    46,    47,   511,    46,
      47,   133,   133,   422,   140,   141,   152,   173,   173,   134,
     134,   435,   139,   433,   169,   236,   390,   438,   342,   343,
     344,   193,   552,   439,   235,   553,   133,    46,    47,   554,
     220,   221,   426,   311,   134,   239,   240,    46,    47,   501,
     380,   238,   133,   503,   436,    40,   549,   423,   437,   237,
     134,   251,    46,    47,   231,   232,   233,   234,   256,   243,
     451,    46,    47,    46,    47,   555,   140,   141,   180,   195,
     -11,   199,   200,   266,    49,   213,   214,   181,   305,   263,
     305,   267,    46,    47,   547,   259,   548,   399,   400,    46,
      47,   427,   428,    46,    47,    46,    47,   133,   305,   282,
     305,   305,   434,   173,   571,   134,   573,   574,   493,   494,
     495,   180,   305,   305,   217,   218,   219,   620,   583,   584,
     181,   133,   391,   392,   393,   394,   283,   383,   284,   134,
     505,   507,   356,   357,   358,   359,   491,   456,   519,   222,
     223,   224,   520,   196,   197,   467,   499,   500,   133,   305,
     241,   133,   411,   412,   314,   606,   134,   512,   308,   134,
     509,   287,   517,   154,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   270,   475,   476,   477,   478,   347,   348,
     349,   133,   626,   626,   345,   346,   288,   383,   289,   134,
     309,   338,  -214,   324,  -216,  -215,   330,   327,   340,   376,
     370,   371,   395,   378,   379,   396,   639,   551,   397,   398,
     401,   639,   402,   414,   294,   523,   444,   419,   453,   454,
     421,   465,   455,   572,   449,   154,   532,   457,   458,   488,
     498,   133,   460,   133,   489,   567,   490,   550,   496,   134,
     502,   134,   513,   514,   515,   521,   524,   591,   142,   537,
     526,   527,   534,   350,   351,   352,   353,   354,   355,   535,
     528,   536,   578,   600,   594,   595,   596,   538,   539,   585,
     133,   133,   133,   541,   540,   542,   133,   546,   134,   134,
     134,   569,   568,   592,   134,   142,   142,   142,   597,   575,
     576,   142,   617,   618,   619,   593,   154,   581,   615,   598,
     603,   604,   605,   586,   612,   269,   608,   609,   623,   599,
     613,   611,   622,   629,   640,   133,   630,   632,   194,   518,
     641,   173,   420,   134,   375,   508,   432,   416,   587,   628,
     602,   466,   122,   616,   360,   480,   479,   154,   624,   625,
     481,   361,   482,   362,   216,   484,     0,   363,     0,     0,
       0,   365,   631,     0,     0,   326,     0,     0,     0,     0,
     635,     0,     0,     0,     0,   635,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,     0,
     110,     0,     0,     0,     0,     0,     0,   213,   214,     0,
       0,     0,     0,   270,   470,   471,   472,   473,   474,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,   404,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   107,
       0,     0,   108,     0,     0,     0,     0,     0,   270,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,   215,     0,    33,     0,     0,     0,    35,     0,
     268,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,   452,     0,
       0,    46,    47,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,  -330,   468,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   468,
     110,   468,   270,     4,     5,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   107,     0,     0,   108,     0,     0,
       0,     0,     0,   522,     0,    27,    28,     0,     0,     0,
     468,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,   109,     0,     4,     5,     0,     0,
     252,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   468,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   107,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,     0,     0,     0,    31,     0,
       0,     0,    33,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,   109,     0,     4,
       5,     0,     0,   450,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   136,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
     107,     0,     0,   184,    25,     0,    26,     0,     0,     0,
       0,    27,   185,     0,     0,     0,     0,    29,    30,     0,
       0,   186,     0,    32,     0,    33,    34,     0,     0,    35,
      36,    37,     0,    38,    39,     0,    40,    41,    42,     0,
      43,     0,     0,     0,     0,    44,     0,     0,    45,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
      48,   187,     4,     5,     0,    49,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    -5,    17,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,    48,     4,     5,     0,     0,    49,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,   136,
      18,     0,     0,    19,     0,     0,     0,    20,     0,    21,
       0,     0,     0,    22,     0,   107,     0,     0,    24,    25,
       0,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      33,    34,     0,     0,    35,    36,    37,     0,    38,    39,
       0,    40,    41,    42,     0,    43,     0,     0,     0,     0,
      44,     0,     0,    45,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,    48,   187,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   136,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,   107,     0,
       0,    24,    25,     0,    26,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    33,    34,     0,     0,    35,    36,    37,
       0,    38,    39,     0,    40,    41,    42,     0,    43,     0,
       0,     0,     0,    44,     0,     0,    45,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,    48,   325,
       4,     5,     0,    49,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,    -5,   136,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,   107,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,    45,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,    48,     4,     5,     0,     0,    49,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,   552,     0,     0,   553,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,    48,   -56,     4,     5,     0,    49,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,    23,     0,     0,    24,
      25,     0,    26,     0,     0,     0,     0,    27,    28,   552,
       0,     0,   553,    29,    30,     0,     0,    31,     0,    32,
       0,    33,    34,     0,     0,    35,    36,    37,     0,    38,
      39,     0,    40,    41,    42,     0,    43,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,    48,   -57,     4,     5,
       0,    49,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,    23,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,     0,     0,     0,    48,
       4,     5,     0,     0,    49,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   136,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,   107,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,    45,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,    48,     4,     5,     0,     0,    49,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,    48,   -58,     4,     5,     0,    49,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,    23,     0,     0,    24,
      25,     0,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    33,    34,     0,     0,    35,    36,    37,     0,    38,
      39,     0,    40,    41,    42,     0,    43,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,    48,   -59,     4,     5,
       0,    49,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,     0,     0,     0,     0,   109,
       4,     5,     0,     0,  -332,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     4,
       5,   109,     0,   333,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     4,     5,
     109,     0,  -332,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -5,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,     4,     5,     0,     0,   109,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   107,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,    46,    47,
       0,     0,     4,     5,     0,     0,   109,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,   107,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    13,    14,    15,    31,     0,     0,     0,    33,     0,
       0,     0,    35,     0,   106,     0,     0,     0,     0,     0,
      41,    42,     0,    43,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,    46,    47,     0,     0,     0,
       0,    27,    28,   109,     0,     0,     0,    29,     0,     0,
       0,    31,    13,    14,    15,    33,     0,     0,     0,    35,
       0,   403,     0,     0,     0,   106,     0,    41,    42,     0,
      43,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   107,    46,    47,   108,     0,     0,     0,     0,     0,
     109,     0,    27,    28,     0,     0,     0,     0,    29,    13,
      14,    15,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,   106,     0,     0,     0,     0,     0,    41,    42,
       0,    43,    21,    13,   516,    15,     0,     0,   107,     0,
       0,   108,     0,    46,    47,     0,   106,     0,     0,    27,
      28,   109,   138,     0,     0,    29,    21,     0,     0,    31,
       0,     0,   107,    33,     0,   108,     0,    35,     0,     0,
       0,   139,     0,    27,    28,    41,    42,     0,    43,    29,
       0,   552,     0,    31,   553,     0,     0,    33,   554,     0,
       0,    35,     0,     0,     0,     0,     0,     0,   109,    41,
      42,     0,    43,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,   109,     0,   555,   140,   141,     0,     0,   -13,
       0,     0,     0,    49
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,     2,    20,    14,   402,    17,    47,    36,    20,   165,
     385,   167,    46,    17,    26,    42,    20,   167,    19,   132,
      26,     3,    26,    20,   399,    37,   401,     3,    16,     3,
      18,    43,    44,    37,    69,     3,     3,    43,     3,    43,
      44,     3,    47,     3,    13,   255,     3,     3,     3,    47,
       3,     3,     0,    55,    55,   265,   169,    45,    50,   403,
     173,    30,     3,     3,     3,    34,   464,    63,     3,    47,
     112,     3,   104,   283,   284,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    79,   460,     3,     3,     3,   126,
       3,     3,    74,     3,     3,    17,   128,     3,   130,   141,
     135,    79,    97,   135,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    37,    47,    47,   515,   463,
     112,    79,    44,   155,   136,   157,   138,   164,    28,   161,
      88,   139,   136,    79,   138,   140,   112,   535,   112,    97,
      47,   137,   140,   175,   125,    45,    46,   303,   149,   141,
     128,   129,   125,   125,    47,   136,    49,    50,   195,   534,
     142,   558,   174,   136,   136,   141,   178,   141,   174,   379,
     174,   138,   178,   141,   178,   176,   131,   142,   576,   216,
     142,   150,    79,   139,   141,   138,   138,   156,   189,    79,
     130,   122,   122,   162,   163,    79,    47,   138,   311,   138,
      57,    60,   239,   138,   241,   193,   138,    25,    26,    27,
      28,    29,   246,   632,   136,    72,   138,    79,   637,   256,
      79,   138,   138,   138,    47,   138,   138,   196,   138,   138,
     199,   125,   138,    25,    26,    27,   632,    29,   128,   129,
     140,   637,   136,   255,   128,   129,   130,   259,    79,   255,
      86,   255,    88,   265,   136,   259,   268,    47,    79,   265,
      78,   265,   268,    60,   268,   294,   128,   129,   130,   128,
     129,   283,   284,    79,   133,   134,    97,   283,   284,   283,
     284,   322,    79,   317,    79,    19,    78,   328,   217,   218,
     219,    59,    89,   330,    20,    92,   308,   128,   129,    96,
      35,    36,   308,    79,   308,    15,    16,   128,   129,   422,
      79,    17,   324,   426,    79,   112,    79,   123,   324,    18,
     324,     3,   128,   129,    21,    22,    23,    24,   140,    79,
     367,   128,   129,   128,   129,   132,   133,   134,    88,    47,
     137,    49,    50,    79,   141,    45,    46,    97,   504,   109,
     506,    79,   128,   129,   504,     3,   506,    15,    16,   128,
     129,   113,   114,   128,   129,   128,   129,   379,   524,    47,
     526,   527,    79,   379,   524,   379,   526,   527,   410,   411,
     412,    88,   538,   539,    37,    38,    39,   597,   538,   539,
      97,   403,    21,    22,    23,    24,    47,   403,    47,   403,
     427,   428,   231,   232,   233,   234,   407,   376,   445,    32,
      33,    34,   449,    49,    50,   384,   417,   418,   430,   575,
       3,   433,   288,   289,   430,   575,   430,   433,     3,   433,
     431,   127,   443,   402,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   145,   391,   392,   393,   394,   222,   223,
     224,   463,   614,   615,   220,   221,   127,   463,   127,   463,
     117,    79,   139,   139,   139,   139,   139,   137,    79,    47,
     142,    80,    20,    47,    47,    19,   632,   514,    18,    17,
       3,   637,   141,    47,    72,   454,    79,   137,    47,    47,
     137,    28,   138,   525,   139,   464,   465,   138,   138,    28,
      79,   513,   140,   515,   138,   516,   138,   513,   136,   513,
      79,   515,   139,   139,   136,    28,   136,   546,   515,   488,
     136,   136,   139,   225,   226,   227,   228,   229,   230,   141,
     138,    28,   533,   565,   552,   553,   554,   136,   136,   540,
     552,   553,   554,    79,    66,    56,   558,   138,   552,   553,
     554,    28,   521,   137,   558,   552,   553,   554,    47,   136,
     141,   558,   594,   595,   596,   137,   535,   536,   139,   137,
     137,   137,   137,   542,   137,   145,   577,   138,   138,   558,
     137,   582,   137,   137,   137,   597,   138,   136,    55,   445,
     637,   597,   303,   597,   259,   430,   314,   295,   543,   615,
     569,   383,    14,   590,   235,   396,   395,   576,   609,   610,
     397,   236,   398,   237,    89,   400,    -1,   238,    -1,    -1,
      -1,   240,   623,    -1,    -1,   626,    -1,    -1,    -1,    -1,
     632,    -1,    -1,    -1,    -1,   637,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,   282,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,   140,    -1,   101,    -1,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   534,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    87,    88,    -1,    -1,    -1,
     460,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    35,    36,    -1,    -1,
     142,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    35,
      36,    -1,    -1,   142,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,
     106,   107,    -1,   109,   110,    -1,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,    35,    36,    -1,   141,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    35,    36,    -1,    -1,   141,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,   106,   107,    -1,   109,   110,
      -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
     121,    -1,    -1,   124,    -1,    -1,    -1,   128,   129,    -1,
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
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
      35,    36,    -1,   141,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    35,    36,    -1,    -1,   141,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    35,    36,    -1,   141,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,    92,    93,    94,    -1,    -1,    97,    -1,    99,
      -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    35,    36,
      -1,   141,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      35,    36,    -1,    -1,   141,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    35,    36,    -1,    -1,   141,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    35,    36,    -1,   141,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,    99,
      -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    35,    36,
      -1,   141,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      35,    36,    -1,    -1,   141,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    35,
      36,   136,    -1,   138,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    35,    36,
     136,    -1,   138,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    35,    36,    -1,    -1,   136,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    35,    36,    -1,    -1,   136,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    47,    48,    49,    97,    -1,    -1,    -1,   101,    -1,
      -1,    -1,   105,    -1,    60,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,   128,   129,    -1,    -1,    -1,
      -1,    87,    88,   136,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    47,    48,    49,   101,    -1,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    60,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,   128,   129,    79,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    47,
      48,    49,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    60,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    70,    47,    48,    49,    -1,    -1,    76,    -1,
      -1,    79,    -1,   128,   129,    -1,    60,    -1,    -1,    87,
      88,   136,    60,    -1,    -1,    93,    70,    -1,    -1,    97,
      -1,    -1,    76,   101,    -1,    79,    -1,   105,    -1,    -1,
      -1,    79,    -1,    87,    88,   113,   114,    -1,   116,    93,
      -1,    89,    -1,    97,    92,    -1,    -1,   101,    96,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   136,   113,
     114,    -1,   116,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   136,    -1,   132,   133,   134,    -1,    -1,   137,
      -1,    -1,    -1,   141
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
     192,   194,   196,   197,   199,   178,    60,   179,    60,    79,
     133,   134,   146,   159,   192,    47,   122,    79,   178,   139,
      47,    79,    97,   196,   269,   272,    47,   269,   136,   182,
      79,   192,    47,    47,   125,   136,   163,   136,   163,    79,
     164,   165,   177,   196,    47,   192,   178,   198,   273,    79,
      88,    97,   200,   238,    79,    88,    97,   137,   179,   187,
     236,   237,   238,    59,   174,    47,    49,    50,   242,    49,
      50,   242,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    45,    46,   140,   268,    37,    38,    39,
      35,    36,    32,    33,    34,    25,    26,    27,    28,    29,
      78,    21,    22,    23,    24,    20,    19,    18,    17,    15,
      16,     3,   274,    79,   138,   242,     3,    74,   142,   232,
     233,     3,   142,   266,   274,    47,   140,   201,   222,     3,
     274,   222,   274,   109,   192,    47,    79,    79,   107,   244,
     249,   251,   253,   255,   257,   259,   261,   263,   265,   267,
     270,   271,    47,    47,    47,   179,   269,   127,   127,   127,
     274,   269,   274,    57,    72,   219,   220,   274,   269,   269,
     266,   160,   170,   173,   176,   180,   170,   222,     3,   117,
     222,    79,   190,   191,   196,   274,   179,     3,   130,    79,
     130,   196,     3,   131,   139,   137,   179,   137,     3,   141,
     139,   178,   123,   138,   168,   243,   266,   269,    79,   269,
      79,   266,   246,   246,   246,   247,   247,   248,   248,   248,
     249,   249,   249,   249,   249,   249,   250,   250,   250,   250,
     252,   254,   256,   258,   266,   260,   266,   273,    47,   122,
     142,    80,   234,   177,   266,   194,    47,   177,    47,    47,
      79,   193,   195,   196,    28,   268,    25,    26,    27,    29,
      78,    21,    22,    23,    24,    20,    19,    18,    17,    15,
      16,     3,   141,   107,   244,   177,   177,   138,    79,    97,
     186,   186,   186,   138,    47,   182,   220,   138,   138,   137,
     176,   137,    79,   123,   166,   167,   196,   113,   114,   222,
       3,   138,   201,   273,    79,   238,    79,   196,   238,   266,
      69,   135,   148,   149,    79,     3,   138,   142,   142,   139,
     142,   266,   244,    47,    47,   138,   269,   138,   138,   177,
     140,   202,   223,     3,   141,    28,   223,   269,   244,   267,
     249,   249,   249,   249,   249,   251,   251,   251,   251,   253,
     255,   257,   259,   267,   261,   267,   272,   195,    28,   138,
     138,   179,    50,   274,   274,   274,   136,   212,    79,   179,
     179,   222,    79,   222,   136,   163,   136,   163,   191,   179,
      79,   130,   196,   139,   139,   136,    48,   239,   168,   266,
     266,    28,   244,   269,   136,   138,   136,   136,   138,   267,
     195,   272,   269,   138,   139,   141,    28,   269,   136,   136,
      66,    79,    56,   213,   214,   224,   138,   170,   170,    79,
     196,   266,    89,    92,    96,   132,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   203,   239,   269,    28,
     138,   170,   274,   170,   170,   136,   141,   138,   179,   267,
     272,   269,   138,   170,   170,   179,   269,   214,    63,   137,
     215,   182,   137,   137,   159,   159,   159,    47,   137,   153,
     274,   138,   269,   137,   137,   137,   170,   272,   179,   138,
     138,   179,   137,   137,   139,   139,   224,   274,   274,   274,
     177,   138,   137,   138,   179,   179,   187,   221,   221,   137,
     138,   179,   136,   157,   158,   160,   169,   172,   175,   180,
     137,   175
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
     183,   184,   185,   185,   185,   186,   186,   186,   187,   187,
     188,   188,   188,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     197,   198,   198,   198,   198,   199,   200,   200,   200,   200,
     200,   200,   201,   202,   203,   204,   205,   205,   206,   206,
     206,   206,   206,   206,   206,   206,   207,   208,   209,   210,
     211,   212,   212,   213,   213,   214,   215,   216,   217,   218,
     218,   218,   219,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   225,   225,   225,   225,   226,   227,   227,
     228,   228,   228,   228,   228,   228,   229,   229,   229,   229,
     230,   230,   231,   231,   232,   233,   233,   234,   234,   235,
     236,   236,   237,   237,   238,   238,   238,   239,   239,   239,
     239,   239,   239,   240,   240,   241,   241,   241,   241,   242,
     242,   243,   243,   243,   243,   244,   244,   244,   244,   245,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   247,   247,   247,   247,   248,   248,   248,   249,
     249,   249,   249,   250,   250,   250,   250,   250,   250,   250,
     251,   251,   251,   251,   251,   251,   252,   252,   252,   252,
     252,   253,   253,   253,   253,   253,   254,   254,   255,   255,
     256,   256,   257,   257,   258,   258,   259,   259,   260,   260,
     261,   261,   262,   262,   263,   263,   264,   264,   265,   265,
     266,   266,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     271,   271,   272,   272,   273,   273,   274,   274
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
       3,     2,     5,     5,     5,     1,     1,     3,     1,     2,
       3,     3,     3,     5,     1,     3,     2,     2,     1,     3,
       1,     3,     2,     2,     2,     2,     1,     1,     3,     3,
       5,     2,     2,     4,     4,     3,     1,     3,     3,     5,
       3,     5,     2,     2,     1,     2,     7,     5,     7,     5,
       9,    10,     7,     8,     8,     9,     3,     3,     3,     5,
       5,     3,     5,     1,     2,     4,     3,     3,     3,     3,
       3,     4,     5,     2,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     5,     4,
       2,     4,     1,     2,     2,     6,     7,     0,     4,     3,
       0,     2,     3,     5,     1,     1,     1,     1,     1,     1,
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
     124,   178,   179,    -1,    68,   159,    -1,    82,    79,   127,
     186,   274,    -1,    82,   196,   127,   186,   274,    -1,    82,
      97,   127,   186,   274,    -1,    97,    -1,    79,    -1,   186,
      50,    79,    -1,   179,    -1,   187,   179,    -1,   107,   192,
     274,    -1,    60,   192,   274,    -1,   121,   192,   274,    -1,
     121,    47,   190,   138,   179,    -1,   191,    -1,   190,     3,
     191,    -1,    79,   222,    -1,   196,   201,    -1,   194,    -1,
     192,     3,   194,    -1,   195,    -1,   193,     3,   195,    -1,
      79,   222,    -1,   196,   222,    -1,    79,   223,    -1,   196,
     223,    -1,   197,    -1,   199,    -1,   128,   273,   130,    -1,
     128,   198,   130,    -1,   128,   198,     3,   273,   130,    -1,
     273,    79,    -1,   273,   196,    -1,   198,     3,   273,    79,
      -1,   198,     3,   273,   196,    -1,   129,   200,   131,    -1,
      79,    -1,   238,   139,    79,    -1,   238,   139,   196,    -1,
     200,     3,   238,   139,    79,    -1,   200,     3,    79,    -1,
     200,     3,   238,   139,   196,    -1,   140,   266,    -1,   140,
     267,    -1,   274,    -1,   269,   274,    -1,    80,    47,   269,
     138,   179,    66,   179,    -1,    80,    47,   269,   138,   179,
      -1,    64,   179,   109,    47,   269,   138,   274,    -1,   109,
      47,   269,   138,   179,    -1,    74,    47,   271,   141,   272,
     141,   272,   138,   179,    -1,    74,    47,   107,   193,   141,
     272,   141,   272,   138,   179,    -1,    74,    47,   244,    28,
     269,   138,   179,    -1,    74,    47,   107,   195,    28,   269,
     138,   179,    -1,    74,   122,    47,   244,    28,   269,   138,
     179,    -1,    74,   122,    47,   107,   195,    28,   269,   138,
     179,    -1,    61,   178,   274,    -1,    54,   178,   274,    -1,
      94,   272,   274,    -1,   110,    47,   269,   138,   179,    -1,
      99,    47,   269,   138,   212,    -1,   136,   224,   137,    -1,
     136,   224,   215,   224,   137,    -1,   214,    -1,   213,   214,
      -1,    56,   269,   139,   221,    -1,    63,   139,   221,    -1,
      79,   139,   179,    -1,   102,   269,   274,    -1,   106,   182,
     219,    -1,   106,   182,   220,    -1,   106,   182,   219,   220,
      -1,    57,    47,    79,   138,   182,    -1,    72,   182,    -1,
      -1,   187,    -1,    -1,   201,    -1,    -1,   202,    -1,    -1,
     213,    -1,   226,    -1,   227,    -1,    88,    -1,    97,    -1,
      93,    -1,    87,    -1,   105,    -1,    70,    -1,   101,    -1,
      79,    -1,   225,    -1,   229,    -1,   235,    -1,    47,   269,
     138,    -1,    49,   273,   142,    -1,    49,   230,   142,    -1,
      49,   230,     3,   273,   142,    -1,    49,   230,   232,   142,
      -1,   273,   266,    -1,   230,     3,   273,   266,    -1,     3,
      -1,   231,     3,    -1,   233,   234,    -1,    74,    47,   244,
      28,   269,   138,    -1,    74,   122,    47,   244,    28,   269,
     138,    -1,    -1,    80,    47,   269,   138,    -1,   136,   236,
     137,    -1,    -1,   237,   141,    -1,   238,   139,   266,    -1,
     237,     3,   238,   139,   266,    -1,    79,    -1,    97,    -1,
      88,    -1,   228,    -1,   161,    -1,   146,    -1,   239,    49,
     269,   142,    -1,   239,    50,    79,    -1,    48,   239,   242,
      -1,   239,    -1,    48,   240,    -1,   239,   242,    -1,   241,
     242,    -1,   241,    49,   269,   142,    -1,   241,    50,    79,
      -1,    47,   138,    -1,    47,   243,   138,    -1,   266,    -1,
     168,    -1,   243,     3,   266,    -1,   243,     3,   168,    -1,
     240,    -1,   241,    -1,   197,    -1,   199,    -1,   244,    -1,
     244,    46,    -1,   244,    45,    -1,   245,    -1,    42,   246,
      -1,    43,   246,    -1,    44,   246,    -1,    46,   246,    -1,
      45,   246,    -1,    35,   246,    -1,    36,   246,    -1,    41,
     246,    -1,    40,   246,    -1,   246,    -1,   247,    37,   246,
      -1,   247,    38,   246,    -1,   247,    39,   246,    -1,   247,
      -1,   248,    35,   247,    -1,   248,    36,   247,    -1,   248,
      -1,   249,    34,   248,    -1,   249,    33,   248,    -1,   249,
      32,   248,    -1,   249,    -1,   250,    26,   249,    -1,   250,
      25,   249,    -1,   250,    29,   249,    -1,   250,    78,   249,
      -1,   250,    27,   249,    -1,   250,    28,   249,    -1,   249,
      -1,   251,    26,   249,    -1,   251,    25,   249,    -1,   251,
      29,   249,    -1,   251,    78,   249,    -1,   251,    27,   249,
      -1,   250,    -1,   252,    23,   250,    -1,   252,    22,   250,
      -1,   252,    24,   250,    -1,   252,    21,   250,    -1,   251,
      -1,   253,    23,   251,    -1,   253,    22,   251,    -1,   253,
      24,   251,    -1,   253,    21,   251,    -1,   252,    -1,   254,
      20,   252,    -1,   253,    -1,   255,    20,   253,    -1,   254,
      -1,   256,    19,   254,    -1,   255,    -1,   257,    19,   255,
      -1,   256,    -1,   258,    18,   256,    -1,   257,    -1,   259,
      18,   257,    -1,   258,    -1,   260,    17,   258,    -1,   259,
      -1,   261,    17,   259,    -1,   260,    -1,   262,    16,   260,
      -1,   261,    -1,   263,    16,   261,    -1,   262,    -1,   262,
      15,   266,   139,   266,    -1,   263,    -1,   263,    15,   267,
     139,   267,    -1,   264,    -1,   244,   268,   266,    -1,   265,
      -1,   244,   268,   267,    -1,   140,    -1,    10,    -1,    12,
      -1,    11,    -1,    14,    -1,     5,    -1,     7,    -1,     6,
      -1,     4,    -1,    13,    -1,     9,    -1,     8,    -1,   266,
      -1,   269,     3,   266,    -1,   267,    -1,   270,     3,   267,
      -1,    -1,   270,    -1,    -1,   269,    -1,    -1,   231,    -1,
     141,    -1,   112,    -1
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
     300,   304,   307,   313,   319,   325,   327,   329,   333,   335,
     338,   342,   346,   350,   356,   358,   362,   365,   368,   370,
     374,   376,   380,   383,   386,   389,   392,   394,   396,   400,
     404,   410,   413,   416,   421,   426,   430,   432,   436,   440,
     446,   450,   456,   459,   462,   464,   467,   475,   481,   489,
     495,   505,   516,   524,   533,   542,   552,   556,   560,   564,
     570,   576,   580,   586,   588,   591,   596,   600,   604,   608,
     612,   616,   621,   627,   630,   631,   633,   634,   636,   637,
     639,   640,   642,   644,   646,   648,   650,   652,   654,   656,
     658,   660,   662,   664,   666,   668,   672,   676,   680,   686,
     691,   694,   699,   701,   704,   707,   714,   722,   723,   728,
     732,   733,   736,   740,   746,   748,   750,   752,   754,   756,
     758,   763,   767,   771,   773,   776,   779,   782,   787,   791,
     794,   798,   800,   802,   806,   810,   812,   814,   816,   818,
     820,   823,   826,   828,   831,   834,   837,   840,   843,   846,
     849,   852,   855,   857,   861,   865,   869,   871,   875,   879,
     881,   885,   889,   893,   895,   899,   903,   907,   911,   915,
     919,   921,   925,   929,   933,   937,   941,   943,   947,   951,
     955,   959,   961,   965,   969,   973,   977,   979,   983,   985,
     989,   991,   995,   997,  1001,  1003,  1007,  1009,  1013,  1015,
    1019,  1021,  1025,  1027,  1031,  1033,  1037,  1039,  1045,  1047,
    1053,  1055,  1059,  1061,  1065,  1067,  1069,  1071,  1073,  1075,
    1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,  1095,  1097,
    1101,  1102,  1104,  1105,  1107,  1108,  1110,  1112
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
    1077,  1090,  1102,  1119,  1134,  1154,  1162,  1170,  1180,  1188,
    1199,  1207,  1215,  1226,  1236,  1242,  1249,  1257,  1268,  1276,
    1286,  1292,  1300,  1308,  1318,  1326,  1337,  1341,  1348,  1358,
    1365,  1378,  1390,  1400,  1410,  1421,  1432,  1442,  1454,  1464,
    1474,  1482,  1493,  1497,  1501,  1505,  1519,  1528,  1540,  1548,
    1556,  1568,  1580,  1591,  1603,  1614,  1628,  1638,  1648,  1658,
    1669,  1680,  1684,  1693,  1699,  1707,  1718,  1729,  1742,  1752,
    1761,  1770,  1782,  1793,  1801,  1802,  1806,  1807,  1811,  1812,
    1816,  1817,  1821,  1822,  1823,  1830,  1837,  1847,  1857,  1864,
    1874,  1881,  1888,  1889,  1890,  1891,  1899,  1909,  1916,  1926,
    1937,  1947,  1958,  1959,  1964,  1972,  1979,  1989,  1990,  1999,
    2014,  2017,  2024,  2033,  2043,  2050,  2057,  2067,  2071,  2075,
    2080,  2093,  2108,  2124,  2125,  2135,  2148,  2161,  2174,  2192,
    2193,  2197,  2203,  2209,  2214,  2222,  2223,  2224,  2225,  2229,
    2233,  2240,  2250,  2251,  2258,  2265,  2272,  2279,  2286,  2293,
    2300,  2307,  2317,  2318,  2322,  2326,  2333,  2334,  2338,  2345,
    2346,  2350,  2354,  2361,  2362,  2366,  2370,  2374,  2378,  2382,
    2389,  2390,  2394,  2398,  2402,  2406,  2413,  2414,  2418,  2422,
    2426,  2433,  2434,  2438,  2442,  2446,  2453,  2454,  2461,  2462,
    2469,  2470,  2477,  2478,  2485,  2486,  2493,  2494,  2501,  2502,
    2509,  2510,  2517,  2518,  2525,  2526,  2533,  2534,  2543,  2544,
    2553,  2557,  2567,  2571,  2582,  2583,  2584,  2585,  2586,  2587,
    2588,  2589,  2590,  2591,  2592,  2593,  2597,  2604,  2612,  2619,
    2627,  2628,  2632,  2633,  2637,  2638,  2642,  2643
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
  const int ParserImplementation::yylast_ = 2943;
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
#line 5669 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2646 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


