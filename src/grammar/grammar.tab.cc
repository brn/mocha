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
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
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
  const short int ParserImplementation::yypact_ninf_ = -529;
  const short int
  ParserImplementation::yypact_[] =
  {
      -529,    97,  1621,  -529,  2724,  2724,  2724,  2724,  2724,  2724,
    2724,  2724,  2724,  2433,  2786,   104,    34,   132,    34,  1723,
     185,  -529,    24,    78,    46,    93,   154,  -529,  -529,  -529,
    2530,  -529,   160,  -529,  2724,  -529,    43,   156,   174,   183,
    -529,   -22,   123,   164,    68,    34,   104,   902,  -529,  -529,
     210,  -529,  -529,  -529,  1005,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,   318,  -529,   329,   583,  -529,  -529,
     295,    69,   351,   145,   319,   252,   256,   260,   175,   105,
    -529,  -529,    47,  -529,  -529,    34,  -529,    29,    82,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,   170,   182,
      37,  2724,   318,  -529,  -529,    16,   324,   631,  -529,    49,
       1,    54,  -529,   189,  -529,  -529,    49,   156,   235,   156,
      28,   280,   285,  -529,  -529,   367,  2031,   326,   333,   334,
    1723,  2724,   267,   276,   277,   402,    49,  2724,    47,  1107,
      53,   189,    54,  2724,  2724,  2724,  1825,  -529,  1825,  -529,
     189,  -529,   403,   290,   189,   194,    54,  1723,    86,    98,
      46,   271,   272,  -529,  -529,  1210,   278,    40,   274,    34,
    -529,  2235,  2724,   335,  -529,  2724,   337,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,
    2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,
    2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  -529,  -529,
    -529,  -529,   282,    71,   283,  -529,  -529,  -529,   104,    45,
    -529,   287,   344,  -529,  -529,  -529,  -529,   164,  2724,  -529,
    -529,   156,  -529,  -529,  -529,   378,   367,   164,   380,   383,
     197,   458,   351,    73,   325,   411,   425,   433,   436,   238,
    -529,  -529,   451,   314,   655,   164,   164,  -529,    42,   135,
     135,   135,  -529,    56,  -529,   409,    43,   387,  -529,  -529,
      61,    62,  -529,  -529,   336,  1928,  -529,  -529,   338,  -529,
      15,   237,  -529,   189,    63,  -529,   189,  -529,  -529,   104,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,    29,  -529,  2724,
      27,   395,  -529,  -529,    65,  -529,    21,  -529,    36,  -529,
    -529,  -529,  -529,  -529,   295,   295,    69,    69,    69,   351,
     351,   351,   351,   351,   351,   145,   145,   145,   145,   319,
     252,   256,   260,   339,   175,  -529,   177,  -529,   202,   799,
    2731,   430,  -529,   432,  -529,   342,  -529,  -529,  2724,   345,
     346,   164,   347,    48,   448,   347,  2724,  2724,  2724,  2724,
    2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,  2724,
    2724,  2724,  2724,  2724,  2133,   197,   454,   350,   353,  1723,
    -529,  -529,    41,    41,    41,   349,   410,  -529,  -529,  1723,
    1723,  -529,  -529,  -529,   189,   413,  -529,  -529,   189,   143,
     152,  -529,   194,  1723,  -529,   108,   354,  -529,  -529,  -529,
     358,  2822,  -529,  2627,  -529,  -529,  -529,  2724,   282,   356,
    -529,  -529,  -529,  -529,   468,  2731,  2724,   362,    66,   364,
     366,   368,  2724,  -529,  -529,   197,  2133,  2724,  -529,    67,
     583,  -529,   351,   351,   351,   351,   351,    73,    73,    73,
      73,   325,   411,   425,   433,   370,   436,  -529,   369,   477,
    2724,   375,   376,   447,   437,  -529,  -529,  -529,   459,  -529,
     379,  -529,  -529,  -529,  -529,  -529,  1825,  -529,  1825,  -529,
    -529,  -529,  -529,  -529,  -529,  2724,  2816,  2822,   241,  -529,
    -529,  -529,   207,  2724,   492,    70,  1825,    49,  1825,  1825,
     388,  -529,  -529,   384,    74,  1723,  2724,  2334,  2724,    75,
    1825,  1825,  1723,  -529,  2724,   459,  -529,    32,    43,   389,
     390,  -529,   185,   185,   185,   483,   394,  -529,  2851,  -529,
    -529,  -529,  -529,  -529,  -529,    49,  -529,   318,  -529,  -529,
      77,  2724,  -529,   396,  -529,   399,   405,  1825,  2334,  1723,
    -529,  -529,   414,    79,  1723,   416,   418,  -529,    59,  -529,
     393,  -529,   459,  -529,  -529,  -529,    49,    49,    49,   164,
    -529,  -529,  -529,  -529,    81,  -529,  -529,  -529,   419,   420,
    -529,  1723,  1723,  -529,  -529,  -529,  1313,  1313,   423,  -529,
    -529,  -529,   426,  -529,  -529,  1723,  -529,  -529,  1313,  -529,
    -529,  -529,   404,  -529,  1415,  -529,  -529,  -529,   424,  1518,
    -529,  -529,  -529,  -529
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
     337,     0,     0,    74,     0,    76,   334,     5,   336,   219,
       0,    67,   218,    36,     3,    60,    66,    78,    82,    81,
      79,    80,    97,    83,    84,   237,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    93,    95,    96,   192,   182,
     183,   217,   193,   194,   223,   235,   236,   239,   242,   252,
     256,   259,   263,   276,   286,   290,   294,   298,   302,   306,
     310,   326,     0,   144,     6,    76,   191,   210,   239,   248,
     249,   251,   250,   243,   244,   245,   247,   246,     0,     0,
       0,     5,   223,   224,   202,     0,   335,     5,    77,     0,
     176,     0,   118,   176,   126,   127,     0,     6,     0,     6,
     176,     0,     0,    29,   101,    27,     5,     0,     0,     0,
       5,     5,     0,     0,     0,   333,     0,     5,     0,     5,
       0,   176,     0,     5,     5,     5,     5,    44,     5,    43,
     176,    75,    46,     0,   176,     0,     0,     5,     0,     0,
     191,   184,   185,    98,   108,     5,     0,     0,     0,    76,
      61,     5,     5,     0,   225,     5,     0,   226,   322,   319,
     321,   320,   325,   324,   315,   317,   316,   323,   318,   241,
     240,   314,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,   145,   214,
     216,   215,   136,     0,     0,   238,   195,   222,   334,     0,
     197,     0,   207,   203,   196,   200,   157,    74,     5,   177,
     122,     0,   111,   123,   156,     0,    28,    74,     0,     0,
       0,   239,   270,   281,   288,   292,   296,   300,   304,   308,
     312,   328,   331,     0,     5,    74,    74,   167,     0,     0,
       0,     0,   158,     0,   168,     0,     0,   169,   170,   110,
       0,     0,    45,    73,     0,     5,    64,    72,     0,    48,
      52,     0,    49,   176,     0,   114,     0,   112,   100,   334,
     129,   131,   128,   132,    99,   109,   209,     0,   211,     5,
       7,     0,   229,   232,     0,   231,     0,   221,     0,   228,
     311,   253,   254,   255,   257,   258,   262,   261,   260,   265,
     264,   268,   269,   266,   267,   280,   278,   277,   279,   287,
     291,   295,   299,     0,   303,   327,     0,   135,     0,     5,
       5,     0,   199,     0,   204,     0,   142,   119,     5,     0,
       0,    74,   178,     0,   120,   178,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     0,     0,     0,     0,     5,
     106,   105,     0,     0,     0,     0,     0,   173,   171,     5,
       5,    38,    65,    40,   176,     0,    47,    53,   176,     0,
       0,   116,     0,     5,   117,     0,     0,   212,     9,    10,
       0,     5,    55,     5,   230,   220,   227,     5,   140,     0,
     137,   138,   198,   201,     0,     5,     5,     0,     0,     0,
       0,     0,     5,   179,   124,     0,     5,     5,   125,     0,
     239,   313,   272,   271,   275,   273,   274,   285,   283,   282,
     284,   289,   293,   297,   301,     0,   305,   329,     0,     0,
       5,     0,     0,   147,     0,   102,   104,   103,   180,   160,
       0,   149,   159,    50,    54,    51,     5,    41,     5,    42,
     115,   113,   133,   130,   134,     5,     5,     5,     8,   234,
     233,   307,     0,     5,     0,     0,     5,     0,     5,     5,
       0,   143,   121,     0,     0,     5,     5,     5,     5,     0,
       5,     5,     5,   107,     5,   181,   163,     0,     0,     0,
       0,   213,     5,     5,     5,     0,     0,    12,     5,    14,
      16,    18,    19,    20,    21,     0,    17,     0,   139,   141,
       0,     5,   208,     0,   148,     0,     0,     5,     5,     5,
     152,   309,     0,     0,     5,     0,     0,   146,     0,   164,
       0,   161,   180,   172,    37,    39,     0,     0,     0,    74,
       4,    15,    23,   205,     0,    34,    30,    31,     0,     0,
     153,     5,     5,   154,    33,    35,   174,   174,     0,    26,
      25,    24,     0,   206,    32,     5,   150,   155,   175,   165,
     166,   162,     0,   151,     5,    70,    71,    69,     0,     5,
      62,    68,    22,    63
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -529,  -529,  -529,    -8,  -529,  -529,  -529,  -529,  -529,  -529,
      -7,  -529,  -529,  -529,  -528,  -345,    -5,    -2,  -529,  -529,
     -32,  -529,  -529,  -529,  -529,   114,  -529,  -154,  -529,  -529,
    -529,   509,   -74,   261,  -244,    31,    -1,   -80,  -529,   -30,
    -529,  -529,  -529,    25,  -260,  -529,  -529,  -529,   136,    92,
    -529,   306,  -320,   -23,   -15,  -529,   557,  -529,   255,  -529,
    -393,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,    35,  -529,  -529,  -529,  -529,  -529,   275,   -44,  -107,
     192,   -18,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -109,     2,   565,  -529,   138,
    -529,   429,  -529,    26,   172,   173,   -91,   133,     6,   355,
     184,   371,   187,   372,   200,   348,   201,   373,   198,  -529,
    -529,  -529,  -529,  -119,  -343,   515,    -9,  -529,  -529,  -387,
     -39,   -75
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    49,    50,   440,   441,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   303,    52,    53,
     167,   171,   172,   426,   427,   333,   638,   304,    54,   639,
     305,    55,   640,   306,   173,   149,   184,    57,    58,    59,
      60,    61,    62,   412,   185,    63,    64,   314,   315,   145,
     383,   132,   384,   133,    65,   178,   135,   243,   259,   463,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   499,
     545,   546,   592,    75,    76,    77,   297,   298,   629,   260,
     464,   547,    78,    79,    80,    81,    82,   125,   126,   251,
     252,   374,    83,   186,   187,   188,    84,    85,    86,   247,
     334,    87,    88,    89,    90,    91,    92,    93,   273,    94,
     274,    95,   275,    96,   276,    97,   277,    98,   278,    99,
     279,   100,   280,   101,   281,   387,   102,   282,   283,   156,
     127,   103
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -333;
  const short int
  ParserImplementation::yytable_[] =
  {
        51,    56,   134,   154,   120,   134,   160,   179,   255,   244,
     169,   134,   143,   375,   308,   144,   122,   488,   138,   248,
     174,   155,   134,   379,   237,   158,   263,   238,   134,   134,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   237,
     237,   407,   408,   327,   471,   237,   302,   129,   257,   136,
     237,   465,    51,    56,   256,   272,   262,   261,   485,   237,
     487,   264,   237,   309,   237,   237,   432,   312,   443,   237,
     237,   146,   335,   237,   366,   267,   177,   237,   237,   533,
     237,   292,   237,   294,   237,   489,   307,   299,   307,   319,
     249,   494,   370,   340,   424,   590,   438,     3,   388,   389,
     390,   317,   391,   165,   216,   217,   635,   124,   239,   131,
     295,   635,   120,   128,   166,   175,   363,   240,   365,   531,
     235,   236,   134,   566,   134,   296,   241,   209,   210,   162,
     349,   350,   351,   352,   353,   354,   176,   461,   425,   376,
     151,   258,   288,    46,   118,   532,   147,   161,   293,   287,
     582,   392,   316,    40,   300,   301,   323,   148,   250,    40,
     134,    40,   439,   445,   134,   566,    40,   371,   258,   591,
     221,   222,   223,   224,   225,   246,   318,   321,   446,   159,
     409,   328,    48,   336,   325,   150,   338,   512,    48,   466,
      48,   609,   234,   581,   415,    48,    46,   118,   616,   419,
     420,   433,   367,   444,   527,   535,   431,   157,   572,   369,
     437,   130,   579,   584,   410,   603,   320,   612,   436,   623,
     330,   163,   194,   226,   197,   307,    46,   118,   322,   131,
     164,   266,   411,   152,   174,   161,    46,   118,   513,   341,
     342,   343,   134,   170,   174,   139,   134,   385,   165,   242,
     453,   153,   134,   401,   402,   134,   448,   449,   240,   168,
      46,   118,   174,   174,   140,   240,   417,   241,   165,   189,
     134,   134,   231,   313,   241,   232,   382,   165,   233,   506,
     435,   450,    46,   118,    46,   118,   568,   428,   508,   636,
     192,   193,    46,   118,   636,   134,   272,   472,   473,   474,
     475,   476,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,    46,   118,   413,   414,   503,   141,   142,
     245,   505,    46,   118,   520,    46,   118,   253,   521,   258,
      46,   118,   213,   214,   215,    46,   118,   495,   496,   497,
     227,   228,   229,   230,   265,   451,   393,   394,   395,   396,
     429,   430,   549,   134,   550,   622,   628,   628,   174,   268,
     355,   356,   357,   358,   269,   191,   134,   192,   193,   458,
     261,   272,   573,   284,   575,   576,   191,   469,   195,   196,
     285,   286,   385,   218,   219,   220,   585,   586,   344,   345,
     134,   346,   347,   348,   289,   155,   551,   507,   509,   477,
     478,   479,   480,   290,   291,   237,   310,   311,   493,   316,
    -216,  -215,   514,   329,   337,   326,   339,   134,   501,   502,
     134,  -214,   368,   608,   373,   378,   307,   380,   307,   372,
     381,   397,   511,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   385,   518,   398,   272,   307,   525,   307,   307,
     134,   399,   574,   400,   403,   404,   416,   155,   534,   296,
     307,   307,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   421,   442,   423,   467,   455,   447,   456,
     457,   539,   490,   459,   460,   498,   386,   462,   491,   500,
     602,   492,   504,   515,   516,   522,   523,   307,   526,   569,
     528,   134,   529,   209,   210,   538,   530,   134,   143,   536,
     537,   540,   541,   542,   570,   544,   543,   548,   593,   567,
     571,   619,   620,   621,   577,   578,   594,   595,   155,   583,
     599,   600,   617,   605,   580,   588,   606,   134,   134,   134,
     634,   587,   607,   134,   143,   143,   143,   596,   597,   598,
     143,   601,   611,   614,   641,   615,   624,   519,   625,   641,
     631,   642,   604,   190,   632,   643,   422,   377,   510,   155,
     119,   434,   418,   630,   618,   271,   174,   468,   610,   123,
     589,   481,   362,   613,   134,   482,   359,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   211,   483,
     486,   484,   212,   360,     0,   361,     0,     0,     0,   364,
     626,   627,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   633,     0,     0,   325,   209,   210,
       0,     0,   637,     0,     0,     0,     0,   637,     0,     0,
       0,     0,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,     0,   108,     4,     5,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    13,    14,    15,     0,     0,   105,     0,     0,
     106,     0,     0,   406,     0,   104,     0,     0,    27,    28,
       0,     0,     0,   211,    29,    21,     0,     0,    31,     0,
       0,   105,    33,     0,   106,     0,    35,     0,     0,     0,
       0,     0,    27,    28,    41,    42,     0,    43,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,    46,
      35,     0,   405,     0,     0,     0,     0,   107,    41,    42,
       0,    43,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     470,   108,   470,     0,     4,     5,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,   105,     0,     0,   106,     0,
       0,     0,     0,     0,   524,     0,    27,    28,     0,     0,
       0,   470,    29,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     4,     5,     0,
       0,   452,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   137,    18,     0,   470,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,   105,     0,
       0,   180,    25,     0,    26,     0,     0,     0,     0,    27,
     181,     0,     0,     0,     0,    29,    30,     0,     0,   182,
       0,    32,     0,    33,    34,     0,     0,    35,    36,    37,
       0,    38,    39,     0,    40,    41,    42,     0,    43,     0,
       0,     0,     0,    44,     0,     0,    45,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,    47,   183,
       4,     5,     0,    48,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,    -5,    17,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,    23,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,    45,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,    47,     4,     5,     0,     0,    48,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   137,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   105,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,    47,   183,     4,     5,     0,    48,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     137,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,   105,     0,     0,    24,
      25,     0,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    33,    34,     0,     0,    35,    36,    37,     0,    38,
      39,     0,    40,    41,    42,     0,    43,     0,     0,     0,
       0,    44,     0,     0,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,    47,   324,     4,     5,
       0,    48,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,    -5,   137,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   105,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    47,
       4,     5,     0,     0,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
       0,    23,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,   552,     0,     0,   553,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,    47,   -56,     4,     5,     0,    48,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,     0,
      26,     0,     0,     0,     0,    27,    28,   552,     0,     0,
     553,    29,    30,     0,     0,    31,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,    47,   -57,     4,     5,     0,    48,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,    23,     0,     0,
      24,    25,     0,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    33,    34,     0,     0,    35,    36,    37,     0,
      38,    39,     0,    40,    41,    42,     0,    43,     0,     0,
       0,     0,    44,     0,     0,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,    47,     4,     5,
       0,     0,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   137,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   105,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    47,
       4,     5,     0,     0,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
       0,    23,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,    47,   -58,     4,     5,     0,    48,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,    47,   -59,     4,     5,     0,    48,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,     0,     0,     0,    31,     0,
       0,     0,    33,     0,     0,     0,    35,     0,   270,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,   107,     4,     5,
       0,     0,  -330,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   105,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,   107,
       4,     5,     0,     0,  -332,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   105,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     4,
       5,   107,     0,   332,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     105,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     4,     5,
     107,     0,  -332,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   105,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,   118,     0,     0,     4,     5,     0,     0,   107,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -5,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   105,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     4,     5,     0,     0,   107,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,   105,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,    46,     0,     0,     0,     4,
       5,     0,     0,   107,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,   104,     0,     0,    21,     0,     0,     0,     0,     0,
     105,    21,     0,   106,     0,     0,     0,   105,     0,     0,
     106,    27,    28,     0,     0,     0,     0,    29,    27,    28,
       0,    31,     0,     0,    29,    33,     0,     0,    31,    35,
       0,     0,    33,   121,    14,    15,    35,    41,    42,     0,
      43,     0,     0,     0,    41,    42,   104,    43,     0,     0,
       0,     0,    46,     0,     0,     0,    21,     0,     0,    46,
     107,     0,   105,     0,     0,   106,     0,   107,     0,   121,
     517,    15,     0,    27,    28,     0,   139,     0,     0,    29,
       0,     0,   104,    31,     0,     0,     0,    33,     0,     0,
       0,    35,    21,     0,     0,   140,     0,     0,   105,    41,
      42,   106,    43,     0,     0,   552,     0,     0,   553,    27,
      28,   139,   554,     0,     0,    29,     0,     0,     0,    31,
       0,     0,   107,    33,     0,     0,     0,    35,    40,     0,
     140,     0,     0,     0,     0,    41,    42,     0,    43,     0,
     552,     0,     0,   553,    46,   118,     0,   554,   555,   141,
     142,     0,     0,   -11,     0,     0,     0,    48,   107,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
     118,     0,     0,   555,   141,   142,     0,     0,   -13,     0,
       0,     0,    48
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,     2,    17,    26,    13,    20,    36,    46,   127,   118,
      42,    26,    20,   257,   168,    20,    14,   404,    19,     3,
      43,    30,    37,   267,     3,    34,   133,   102,    43,    44,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       3,   285,   286,     3,   387,     3,   165,    16,    47,    18,
       3,     3,    54,    54,   129,   146,   131,     3,   401,     3,
     403,   136,     3,   170,     3,     3,     3,   174,     3,     3,
       3,    47,   191,     3,     3,    47,    45,     3,     3,   466,
       3,   156,     3,   158,     3,   405,   166,   162,   168,     3,
      74,    50,    47,   212,    79,    63,    69,     0,    25,    26,
      27,   176,    29,   125,    35,    36,   634,     3,    79,    17,
      57,   639,   121,    79,   136,    47,   235,    88,   237,   462,
      15,    16,   137,   516,   139,    72,    97,    45,    46,    37,
     221,   222,   223,   224,   225,   226,    44,   381,   123,   258,
      47,   140,   151,   128,   129,   465,   122,    79,   157,   150,
     537,    78,   175,   112,   163,   164,   179,    79,   142,   112,
     175,   112,   135,   142,   179,   558,   112,   122,   140,   137,
      25,    26,    27,    28,    29,   138,   177,    79,   142,   136,
     138,   141,   141,   192,   185,   139,   195,    79,   141,   141,
     141,   578,    17,   536,   138,   141,   128,   129,   139,   138,
     138,   138,   131,   138,   138,   138,   313,    47,   138,   248,
     329,    79,   138,   138,    79,   138,   130,   138,   327,   138,
     189,    47,    84,    78,    86,   305,   128,   129,   130,   137,
      47,   139,    97,    79,   257,    79,   128,   129,   130,   213,
     214,   215,   257,    79,   267,    60,   261,   270,   125,    79,
     369,    97,   267,    15,    16,   270,    79,   366,    88,   136,
     128,   129,   285,   286,    79,    88,   296,    97,   125,    59,
     285,   286,    20,    79,    97,    19,    79,   125,    18,   136,
     319,    79,   128,   129,   128,   129,    79,   310,   136,   634,
      49,    50,   128,   129,   639,   310,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   128,   129,   290,   291,   424,   133,   134,
     138,   428,   128,   129,   443,   128,   129,     3,   447,   140,
     128,   129,    37,    38,    39,   128,   129,   412,   413,   414,
      21,    22,    23,    24,   109,   368,    21,    22,    23,    24,
     113,   114,   506,   368,   508,   599,   616,   617,   381,    79,
     227,   228,   229,   230,    79,    47,   381,    49,    50,   378,
       3,   462,   526,    47,   528,   529,    47,   386,    49,    50,
      47,    47,   405,    32,    33,    34,   540,   541,   216,   217,
     405,   218,   219,   220,   127,   404,   515,   429,   430,   393,
     394,   395,   396,   127,   127,     3,     3,   117,   409,   432,
     139,   139,   435,   139,    79,   137,    79,   432,   419,   420,
     435,   139,   139,   577,    80,    47,   506,    47,   508,   142,
      47,    20,   433,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   465,   441,    19,   536,   526,   456,   528,   529,
     465,    18,   527,    17,     3,   141,    47,   466,   467,    72,
     540,   541,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   137,    79,   137,    28,    47,   139,    47,
     138,   490,    28,   138,   138,   136,    28,   140,   138,    79,
     565,   138,    79,   139,   136,   139,    28,   577,   136,   522,
     136,   516,   136,    45,    46,    28,   138,   522,   516,   139,
     141,   136,   136,    66,   523,    56,    79,   138,   548,   517,
      28,   596,   597,   598,   136,   141,   137,   137,   537,   538,
      47,   137,   139,   137,   535,   544,   137,   552,   553,   554,
     136,   542,   137,   558,   552,   553,   554,   552,   553,   554,
     558,   558,   138,   137,   634,   137,   137,   443,   138,   639,
     137,   137,   571,    54,   138,   639,   305,   261,   432,   578,
      13,   316,   297,   617,   592,   146,   599,   385,   579,    14,
     545,   397,   234,   584,   599,   398,   231,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   140,   399,
     402,   400,    87,   232,    -1,   233,    -1,    -1,    -1,   236,
     611,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   625,    -1,    -1,   628,    45,    46,
      -1,    -1,   634,    -1,    -1,    -1,    -1,   639,    -1,    -1,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,   236,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    47,    48,    49,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,   284,    -1,    60,    -1,    -1,    87,    88,
      -1,    -1,    -1,   140,    93,    70,    -1,    -1,    97,    -1,
      -1,    76,   101,    -1,    79,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    87,    88,   113,   114,    -1,   116,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   128,
     105,    -1,   107,    -1,    -1,    -1,    -1,   136,   113,   114,
      -1,   116,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,    -1,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    87,    88,    -1,    -1,
      -1,   462,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    35,    36,    -1,
      -1,   142,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,   536,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,   107,
      -1,   109,   110,    -1,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
      35,    36,    -1,   141,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    35,    36,    -1,    -1,   141,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    35,    36,    -1,   141,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,    99,
      -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,   124,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    35,    36,
      -1,   141,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      35,    36,    -1,    -1,   141,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,    35,    36,    -1,   141,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    35,    36,
      -1,    -1,   141,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      35,    36,    -1,    -1,   141,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,    35,    36,    -1,   141,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    35,    36,    -1,   141,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    35,    36,
      -1,    -1,   141,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      35,    36,    -1,    -1,   141,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    35,
      36,   136,    -1,   138,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    35,    36,
     136,    -1,   138,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    35,    36,    -1,    -1,   136,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    35,    36,    -1,    -1,   136,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    35,
      36,    -1,    -1,   136,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    70,    -1,    79,    -1,    -1,    -1,    76,    -1,    -1,
      79,    87,    88,    -1,    -1,    -1,    -1,    93,    87,    88,
      -1,    97,    -1,    -1,    93,   101,    -1,    -1,    97,   105,
      -1,    -1,   101,    47,    48,    49,   105,   113,   114,    -1,
     116,    -1,    -1,    -1,   113,   114,    60,   116,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    70,    -1,    -1,   128,
     136,    -1,    76,    -1,    -1,    79,    -1,   136,    -1,    47,
      48,    49,    -1,    87,    88,    -1,    60,    -1,    -1,    93,
      -1,    -1,    60,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,   105,    70,    -1,    -1,    79,    -1,    -1,    76,   113,
     114,    79,   116,    -1,    -1,    89,    -1,    -1,    92,    87,
      88,    60,    96,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,   136,   101,    -1,    -1,    -1,   105,   112,    -1,
      79,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,
      89,    -1,    -1,    92,   128,   129,    -1,    96,   132,   133,
     134,    -1,    -1,   137,    -1,    -1,    -1,   141,   136,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,   132,   133,   134,    -1,    -1,   137,    -1,
      -1,    -1,   141
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
     112,   113,   114,   116,   121,   124,   128,   136,   141,   146,
     147,   160,   161,   162,   171,   174,   179,   180,   181,   182,
     183,   184,   185,   188,   189,   197,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   216,   217,   218,   225,   226,
     227,   228,   229,   235,   239,   240,   241,   244,   245,   246,
     247,   248,   249,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   269,   274,    60,    76,    79,   136,   244,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   129,   199,
     269,    47,   239,   240,     3,   230,   231,   273,    79,   178,
      79,   192,   194,   196,   197,   199,   178,    60,   179,    60,
      79,   133,   134,   146,   159,   192,    47,   122,    79,   178,
     139,    47,    79,    97,   196,   269,   272,    47,   269,   136,
     182,    79,   192,    47,    47,   125,   136,   163,   136,   163,
      79,   164,   165,   177,   196,    47,   192,   178,   198,   273,
      79,    88,    97,   137,   179,   187,   236,   237,   238,    59,
     174,    47,    49,    50,   242,    49,    50,   242,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    45,
      46,   140,   268,    37,    38,    39,    35,    36,    32,    33,
      34,    25,    26,    27,    28,    29,    78,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   274,    79,
      88,    97,    79,   200,   238,   138,   138,   242,     3,    74,
     142,   232,   233,     3,   142,   266,   274,    47,   140,   201,
     222,     3,   274,   222,   274,   109,   192,    47,    79,    79,
     107,   244,   249,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   270,   271,    47,    47,    47,   179,   269,   127,
     127,   127,   274,   269,   274,    57,    72,   219,   220,   274,
     269,   269,   266,   160,   170,   173,   176,   180,   170,   222,
       3,   117,   222,    79,   190,   191,   196,   274,   179,     3,
     130,    79,   130,   196,   137,   179,   137,     3,   141,   139,
     178,   123,   138,   168,   243,   266,   269,    79,   269,    79,
     266,   246,   246,   246,   247,   247,   248,   248,   248,   249,
     249,   249,   249,   249,   249,   250,   250,   250,   250,   252,
     254,   256,   258,   266,   260,   266,     3,   131,   139,   273,
      47,   122,   142,    80,   234,   177,   266,   194,    47,   177,
      47,    47,    79,   193,   195,   196,    28,   268,    25,    26,
      27,    29,    78,    21,    22,    23,    24,    20,    19,    18,
      17,    15,    16,     3,   141,   107,   244,   177,   177,   138,
      79,    97,   186,   186,   186,   138,    47,   182,   220,   138,
     138,   137,   176,   137,    79,   123,   166,   167,   196,   113,
     114,   222,     3,   138,   201,   273,   238,   266,    69,   135,
     148,   149,    79,     3,   138,   142,   142,   139,    79,   238,
      79,   196,   142,   266,   244,    47,    47,   138,   269,   138,
     138,   177,   140,   202,   223,     3,   141,    28,   223,   269,
     244,   267,   249,   249,   249,   249,   249,   251,   251,   251,
     251,   253,   255,   257,   259,   267,   261,   267,   272,   195,
      28,   138,   138,   179,    50,   274,   274,   274,   136,   212,
      79,   179,   179,   222,    79,   222,   136,   163,   136,   163,
     191,   179,    79,   130,   196,   139,   136,    48,   239,   168,
     266,   266,   139,    28,   244,   269,   136,   138,   136,   136,
     138,   267,   195,   272,   269,   138,   139,   141,    28,   269,
     136,   136,    66,    79,    56,   213,   214,   224,   138,   170,
     170,   266,    89,    92,    96,   132,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   203,   239,    79,   196,
     269,    28,   138,   170,   274,   170,   170,   136,   141,   138,
     179,   267,   272,   269,   138,   170,   170,   179,   269,   214,
      63,   137,   215,   182,   137,   137,   159,   159,   159,    47,
     137,   153,   274,   138,   269,   137,   137,   137,   170,   272,
     179,   138,   138,   179,   137,   137,   139,   139,   224,   274,
     274,   274,   177,   138,   137,   138,   179,   179,   187,   221,
     221,   137,   138,   179,   136,   157,   158,   160,   169,   172,
     175,   180,   137,   175
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
       3,     1,     1,     3,     3,     1,     1,     1,     3,     1,
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
     240,    -1,   241,    -1,   197,    -1,    47,   199,   138,    -1,
     244,    -1,   244,    46,    -1,   244,    45,    -1,   245,    -1,
      42,   246,    -1,    43,   246,    -1,    44,   246,    -1,    46,
     246,    -1,    45,   246,    -1,    35,   246,    -1,    36,   246,
      -1,    41,   246,    -1,    40,   246,    -1,   246,    -1,   247,
      37,   246,    -1,   247,    38,   246,    -1,   247,    39,   246,
      -1,   247,    -1,   248,    35,   247,    -1,   248,    36,   247,
      -1,   248,    -1,   249,    34,   248,    -1,   249,    33,   248,
      -1,   249,    32,   248,    -1,   249,    -1,   250,    26,   249,
      -1,   250,    25,   249,    -1,   250,    29,   249,    -1,   250,
      78,   249,    -1,   250,    27,   249,    -1,   250,    28,   249,
      -1,   249,    -1,   251,    26,   249,    -1,   251,    25,   249,
      -1,   251,    29,   249,    -1,   251,    78,   249,    -1,   251,
      27,   249,    -1,   250,    -1,   252,    23,   250,    -1,   252,
      22,   250,    -1,   252,    24,   250,    -1,   252,    21,   250,
      -1,   251,    -1,   253,    23,   251,    -1,   253,    22,   251,
      -1,   253,    24,   251,    -1,   253,    21,   251,    -1,   252,
      -1,   254,    20,   252,    -1,   253,    -1,   255,    20,   253,
      -1,   254,    -1,   256,    19,   254,    -1,   255,    -1,   257,
      19,   255,    -1,   256,    -1,   258,    18,   256,    -1,   257,
      -1,   259,    18,   257,    -1,   258,    -1,   260,    17,   258,
      -1,   259,    -1,   261,    17,   259,    -1,   260,    -1,   262,
      16,   260,    -1,   261,    -1,   263,    16,   261,    -1,   262,
      -1,   262,    15,   266,   139,   266,    -1,   263,    -1,   263,
      15,   267,   139,   267,    -1,   264,    -1,   244,   268,   266,
      -1,   265,    -1,   244,   268,   267,    -1,   140,    -1,    10,
      -1,    12,    -1,    11,    -1,    14,    -1,     5,    -1,     7,
      -1,     6,    -1,     4,    -1,    13,    -1,     9,    -1,     8,
      -1,   266,    -1,   269,     3,   266,    -1,   267,    -1,   270,
       3,   267,    -1,    -1,   270,    -1,    -1,   269,    -1,    -1,
     231,    -1,   141,    -1,   112,    -1
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
     794,   798,   800,   802,   806,   810,   812,   814,   816,   820,
     822,   825,   828,   830,   833,   836,   839,   842,   845,   848,
     851,   854,   857,   859,   863,   867,   871,   873,   877,   881,
     883,   887,   891,   895,   897,   901,   905,   909,   913,   917,
     921,   923,   927,   931,   935,   939,   943,   945,   949,   953,
     957,   961,   963,   967,   971,   975,   979,   981,   985,   987,
     991,   993,   997,   999,  1003,  1005,  1009,  1011,  1015,  1017,
    1021,  1023,  1027,  1029,  1033,  1035,  1039,  1041,  1047,  1049,
    1055,  1057,  1061,  1063,  1067,  1069,  1071,  1073,  1075,  1077,
    1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1097,  1099,
    1103,  1104,  1106,  1107,  1109,  1110,  1112,  1114
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
  const int ParserImplementation::yylast_ = 2992;
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
#line 5679 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2646 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


