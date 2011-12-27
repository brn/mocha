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
#line 372 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(1) - (1)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 383 "grammar/grammar.yy"
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
#line 394 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 395 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 400 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 402 "grammar/grammar.yy"
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
#line 417 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 418 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 423 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 424 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 428 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 434 "grammar/grammar.yy"
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
#line 455 "grammar/grammar.yy"
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
#line 479 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 484 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 485 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 486 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 487 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 488 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 494 "grammar/grammar.yy"
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
#line 509 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 519 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 529 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 538 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 547 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 549 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 555 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 557 "grammar/grammar.yy"
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
#line 568 "grammar/grammar.yy"
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
#line 580 "grammar/grammar.yy"
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
#line 595 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 609 "grammar/grammar.yy"
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
#line 626 "grammar/grammar.yy"
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
#line 642 "grammar/grammar.yy"
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
#line 651 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 665 "grammar/grammar.yy"
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
#line 674 "grammar/grammar.yy"
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
#line 683 "grammar/grammar.yy"
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
#line 693 "grammar/grammar.yy"
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
#line 703 "grammar/grammar.yy"
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
#line 713 "grammar/grammar.yy"
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
#line 724 "grammar/grammar.yy"
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
#line 735 "grammar/grammar.yy"
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
#line 749 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 759 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 761 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 767 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 785 "grammar/grammar.yy"
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
#line 801 "grammar/grammar.yy"
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
#line 811 "grammar/grammar.yy"
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
#line 821 "grammar/grammar.yy"
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
#line 832 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 833 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 843 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 860 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 869 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 870 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 874 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 875 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 61:

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

  case 62:

/* Line 690 of lalr1.cc  */
#line 888 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 63:

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

  case 64:

/* Line 690 of lalr1.cc  */
#line 907 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 918 "grammar/grammar.yy"
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
#line 926 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 935 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 937 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 947 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 949 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 955 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 956 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 961 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 963 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 972 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 974 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 980 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 982 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 990 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 992 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 997 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 1005 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1009 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1014 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1019 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1023 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1028 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1033 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1038 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1043 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1058 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1063 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1068 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1073 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1078 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1083 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1087 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1094 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1101 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1112 "grammar/grammar.yy"
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
#line 1125 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1137 "grammar/grammar.yy"
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
#line 1154 "grammar/grammar.yy"
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
#line 1169 "grammar/grammar.yy"
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
#line 1189 "grammar/grammar.yy"
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
#line 1197 "grammar/grammar.yy"
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
#line 1205 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1215 "grammar/grammar.yy"
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
#line 1223 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1234 "grammar/grammar.yy"
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
#line 1242 "grammar/grammar.yy"
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
#line 1250 "grammar/grammar.yy"
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
#line 1261 "grammar/grammar.yy"
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
#line 1271 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1277 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1284 "grammar/grammar.yy"
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
#line 1292 "grammar/grammar.yy"
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
#line 1303 "grammar/grammar.yy"
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
#line 1311 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1321 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1327 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1335 "grammar/grammar.yy"
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
#line 1343 "grammar/grammar.yy"
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
#line 1354 "grammar/grammar.yy"
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
#line 1362 "grammar/grammar.yy"
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
#line 1374 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1378 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1385 "grammar/grammar.yy"
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
#line 1395 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1402 "grammar/grammar.yy"
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
#line 1415 "grammar/grammar.yy"
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
#line 1427 "grammar/grammar.yy"
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
#line 1436 "grammar/grammar.yy"
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
#line 1446 "grammar/grammar.yy"
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
#line 1457 "grammar/grammar.yy"
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
#line 1465 "grammar/grammar.yy"
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
#line 1476 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1487 "grammar/grammar.yy"
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
#line 1497 "grammar/grammar.yy"
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
#line 1510 "grammar/grammar.yy"
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
#line 1520 "grammar/grammar.yy"
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
#line 1531 "grammar/grammar.yy"
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
#line 1540 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1550 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1554 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1558 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar/grammar.yy"
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
#line 1577 "grammar/grammar.yy"
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
#line 1586 "grammar/grammar.yy"
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
#line 1595 "grammar/grammar.yy"
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
#line 1607 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1609 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1610 "grammar/grammar.yy"
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
#line 1618 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1619 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1620 "grammar/grammar.yy"
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
#line 1627 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1628 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar/grammar.yy"
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
#line 1640 "grammar/grammar.yy"
    { tracer->AllowExpression( true ); }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1641 "grammar/grammar.yy"
    { tracer->AllowExpression( false ); }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1642 "grammar/grammar.yy"
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
#line 1654 "grammar/grammar.yy"
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
#line 1665 "grammar/grammar.yy"
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
#line 1677 "grammar/grammar.yy"
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
#line 1688 "grammar/grammar.yy"
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
#line 1702 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1712 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1722 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1732 "grammar/grammar.yy"
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
#line 1743 "grammar/grammar.yy"
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
#line 1754 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1758 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1767 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1773 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1781 "grammar/grammar.yy"
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
#line 1792 "grammar/grammar.yy"
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
#line 1803 "grammar/grammar.yy"
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
#line 1816 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1826 "grammar/grammar.yy"
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
#line 1835 "grammar/grammar.yy"
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
#line 1844 "grammar/grammar.yy"
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
#line 1856 "grammar/grammar.yy"
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
#line 1867 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1874 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1875 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1879 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1880 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1884 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1885 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1889 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1894 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1895 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1897 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1911 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1921 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1931 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1938 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1948 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1955 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1961 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1963 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1965 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1973 "grammar/grammar.yy"
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
#line 1983 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar/grammar.yy"
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
#line 2000 "grammar/grammar.yy"
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
#line 2011 "grammar/grammar.yy"
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
#line 2021 "grammar/grammar.yy"
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
#line 2038 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2046 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2053 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2062 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2064 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2073 "grammar/grammar.yy"
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
#line 2087 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2091 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2095 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2102 "grammar/grammar.yy"
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
#line 2111 "grammar/grammar.yy"
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
#line 2123 "grammar/grammar.yy"
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
#line 2138 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2145 "grammar/grammar.yy"
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
#line 2156 "grammar/grammar.yy"
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
#line 2173 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2180 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2187 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2197 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2201 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2205 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2210 "grammar/grammar.yy"
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
#line 2223 "grammar/grammar.yy"
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
#line 2235 "grammar/grammar.yy"
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
#line 2250 "grammar/grammar.yy"
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
#line 2265 "grammar/grammar.yy"
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
#line 2280 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2282 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2292 "grammar/grammar.yy"
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
#line 2305 "grammar/grammar.yy"
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
#line 2318 "grammar/grammar.yy"
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
#line 2331 "grammar/grammar.yy"
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
#line 2348 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2349 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2354 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2360 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2366 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2371 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2378 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2379 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2380 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2381 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2386 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2390 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2397 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2406 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2408 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2415 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2422 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2429 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2436 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2443 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2450 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2457 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2464 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2473 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2475 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2479 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2483 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2489 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2491 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2495 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2501 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2503 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2507 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2511 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2517 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2519 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2523 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2527 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2531 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2535 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2539 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2545 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2547 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2551 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2555 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2559 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2563 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2569 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2571 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2575 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2579 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2583 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2589 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2591 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2595 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2599 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2603 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2609 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2611 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2617 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2619 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2625 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2627 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2633 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2635 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2641 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2643 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2649 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2651 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2657 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2659 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2665 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2667 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2673 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2675 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2681 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2683 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2689 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2691 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2699 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2701 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2710 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2714 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2724 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2728 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2738 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2739 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2740 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2741 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2742 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2743 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2744 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2745 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2746 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2747 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2748 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2749 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2754 "grammar/grammar.yy"
    {
    YieldExp *yield_exp = ManagedHandle::Retain<YieldExp>();
    yield_exp->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    yield_exp->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    (yyval.yield_exp) = yield_exp;
  }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2763 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2770 "grammar/grammar.yy"
    {
    (yyval.expression) = (yysemantic_stack_[(1) - (1)].yield_exp);
  }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2774 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2782 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2789 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2796 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2797 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2801 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2802 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2806 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2807 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2811 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2812 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4320 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -523;
  const short int
  ParserImplementation::yypact_[] =
  {
      1789,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,
    2823,   755,    90,   -23,    89,   -23,  1895,   162,  -523,    53,
      18,   -48,    77,  3025,   164,  -523,  -523,   178,  -523,  2924,
    -523,    88,  -523,  3025,  -523,   -13,   157,  -523,   131,  -523,
       2,     5,   239,    34,   -23,    90,   138,  3216,   968,  -523,
     137,  -523,   139,  -523,  -523,  -523,  -523,  1256,  -523,  -523,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,   355,  -523,   379,
     648,  -523,  -523,    82,   196,   432,   221,   394,   187,   246,
     222,   244,   256,  -523,  -523,  -523,     9,  -523,  -523,   -23,
    -523,   120,   297,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,   141,   132,    40,  3025,   355,  -523,  -523,     6,
     273,  1076,  -523,   -30,    -6,    21,  -523,   156,  -523,  -523,
     -30,   157,   192,   157,    -5,   232,   234,  -523,  -523,   305,
    2429,   275,   277,   300,  1895,  3025,   862,   223,   228,   233,
    3025,   286,   364,   -30,  3025,     9,  1362,    76,   156,    21,
     339,  3025,  3216,  2215,  -523,  2215,  -523,   156,   310,  -523,
     410,  -523,   301,   156,   201,    21,  1895,    63,   204,   343,
    -523,  -523,   180,  -523,  1469,   283,  -523,   -23,  -523,  2625,
    3025,   351,  -523,  3025,   357,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,
    3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,
    3216,  3216,  3216,  3216,  3216,  3216,  -523,   299,  -523,  -523,
      37,   302,  -523,  -523,  -523,    90,    78,  -523,   294,   387,
    -523,  -523,  -523,  -523,   239,  3216,  -523,  -523,   157,  -523,
    -523,  -523,  -523,   305,   239,   426,   427,   216,    98,   432,
     229,   428,   455,   457,   469,   471,   269,  -523,  -523,   486,
    -523,  3249,   239,   239,  -523,    47,  -523,   146,   146,   146,
       7,  -523,  -523,    49,  -523,   443,   -13,   419,  -523,  -523,
    3025,    51,  -523,  -523,   352,  2322,  -523,  -523,   353,  -523,
    -523,   250,   261,  -523,   156,    57,  -523,   156,  -523,  -523,
      90,  -523,  -523,  -523,  -523,  -523,   350,    16,    27,   354,
    -523,  -523,  -523,    67,   416,  -523,  -523,    58,  -523,    24,
    -523,    25,  -523,  -523,  -523,  -523,  -523,    82,    82,   196,
     196,   196,   432,   432,   432,   432,   432,   432,   221,   221,
     221,   221,   394,   187,   246,   222,   356,   244,  -523,   314,
    -523,   258,  1166,  2722,   449,  -523,   454,  -523,   362,  -523,
    -523,   458,   365,   366,   239,   367,   503,   482,   367,  3025,
    3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,  3216,
    3216,  3216,  3216,  3216,  3216,  3216,  3216,   368,   216,   484,
     372,   373,  1895,  -523,  -523,    79,    79,    79,  -523,   376,
     438,  -523,  -523,   364,  1895,  -523,  -523,  -523,   156,  -523,
    -523,   156,   111,   112,  -523,   201,  1895,  -523,   242,   378,
     239,   322,  -523,  3216,  -523,  -523,   380,  1083,  -523,  3126,
    -523,  -523,  -523,  3216,   299,   381,  -523,  -523,  -523,  -523,
     493,  2722,  3025,   382,  3025,   386,   389,   385,  3216,  -523,
    -523,   216,   390,  3025,  -523,    62,   648,  -523,   432,   432,
     432,   432,   432,   229,   229,   229,   229,   428,   455,   457,
     469,   391,   471,  -523,  2519,   495,  3025,   396,   402,   479,
     464,  -523,  -523,  -523,   490,  -523,   405,   406,  -523,  -523,
    -523,  2215,  -523,  2215,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  1576,   408,    32,   409,  -523,   219,  1083,   383,  -523,
    -523,  -523,   262,  3025,   523,    64,  2215,   364,  2215,  2215,
     413,  -523,  -523,  2519,    66,  1895,  3216,   412,  3025,    68,
    2215,  2215,  1895,  -523,  3025,   490,  -523,    55,   -13,  1895,
     414,   417,  1683,   418,   420,   239,  3216,   162,   162,   162,
     507,   421,  -523,   265,  -523,  -523,  -523,  -523,  -523,  -523,
     -30,  -523,   355,  -523,  -523,    70,  3025,  -523,   424,   435,
     437,   444,  2215,   441,  1895,  -523,  -523,  2715,    72,  1895,
     446,   447,  -523,    31,  -523,   448,  -523,   490,  -523,  -523,
    -523,  -523,  -523,  2215,   450,  -523,   -30,   -30,   -30,   239,
    -523,  -523,  -523,  -523,    74,  -523,   -30,  -523,  -523,   452,
    2715,  -523,  -523,  1895,  -523,  -523,  -523,  1683,  1683,   453,
     456,   466,  -523,  -523,  -523,   462,  -523,  -523,  -523,  -523,
     465,  -523,  -523,  -523,  -523,  -523,  2215,   468,   467,  1895,
     470,  2001,  1895,  -523,  -523,   185,  -523,  -523,  -523,   472,
    2108,  -523,  -523,  -523,  -523,  -523
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   356,    77,     5,    77,     4,     4,   202,     0,
      77,   204,     0,     4,     0,   200,   197,     0,   199,   354,
     198,     0,   203,     4,   201,     0,     0,   156,     0,   359,
       0,     0,    75,     0,    77,   356,     0,     4,     4,   358,
       0,   237,     0,    99,    68,   236,    36,     2,    61,    67,
      79,    83,    82,    80,    81,    98,    84,    85,   257,    86,
      87,    88,    89,    90,    91,    92,    93,    95,    94,    96,
      97,   205,   195,   196,   235,   206,   207,   243,   255,   256,
     259,   262,   272,   276,   279,   283,   296,   306,   310,   314,
     318,   322,   326,   330,   347,   348,     0,   148,     5,    77,
     204,     0,   259,   268,   269,   271,   270,   263,   264,   265,
     267,   266,     0,     0,     0,     4,   243,   244,   215,     0,
     357,     4,    78,     0,   189,     0,   120,   189,   128,   129,
       0,     5,     0,     5,   189,     0,     0,    28,   103,    26,
       4,     0,     0,     0,     4,     4,     4,     0,     0,     0,
       4,     0,   355,     0,     4,     0,     4,     0,   189,     0,
       0,     4,     4,     4,    44,     4,    43,   189,     0,    76,
      46,    47,     0,   189,     0,     0,     4,     0,     0,     0,
     346,   100,   223,   110,     4,     0,     1,    77,    62,     4,
       4,     0,   245,     4,     0,   246,   342,   339,   341,   340,
     345,   344,   335,   337,   336,   343,   338,   261,   260,   334,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   149,   140,   234,   233,
       0,     0,   258,   208,   242,   356,     0,   210,     0,   220,
     216,   209,   213,   170,    75,     4,   190,   124,     0,   113,
     125,   169,   153,    27,    75,     0,     0,     0,   259,   290,
     301,   308,   312,   316,   320,   324,   328,   332,   350,   353,
     159,     4,    75,    75,   180,     0,   152,     0,     0,     0,
       0,   240,   171,     0,   181,     0,     0,   182,   183,   112,
       4,     0,    45,    74,     0,     4,    65,    73,     0,    49,
      55,    53,     0,    50,   189,     0,   116,     0,   114,   102,
     356,   131,   133,   130,   134,   135,     0,   227,   225,     0,
     101,   111,   222,     6,     0,   249,   252,     0,   251,     0,
     241,     0,   248,   331,   273,   274,   275,   277,   278,   282,
     281,   280,   285,   284,   288,   289,   286,   287,   300,   298,
     297,   299,   307,   311,   315,   319,     0,   323,   349,     0,
     139,     0,     4,     4,     0,   212,     0,   217,     0,   146,
     121,     0,     0,     0,    75,   191,   162,   122,   191,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     0,     0,
       0,     0,     4,   108,   107,     0,     0,     0,   239,     0,
       0,   186,   184,   157,     4,    38,    66,    40,   189,    48,
      54,   189,     0,     0,   118,     0,     4,   119,     0,     0,
      75,     0,   224,     4,     8,     9,     0,     4,    56,     4,
     250,   238,   247,     4,   144,     0,   141,   142,   211,   214,
       0,     4,     4,     0,     4,     0,     0,     0,     4,   192,
     126,     0,     0,     4,   127,     0,   259,   333,   292,   291,
     295,   293,   294,   305,   303,   302,   304,   309,   313,   317,
     321,     0,   325,   351,     4,     0,     4,     0,     0,   151,
       0,   104,   106,   105,   193,   173,     0,     0,   172,    51,
      52,     4,    41,     4,    42,   117,   115,   136,   132,   137,
     138,     4,     0,   230,     0,   226,     4,     4,     7,   254,
     253,   327,     0,     4,     0,     0,     4,   154,     4,     4,
       0,   147,   123,     4,     0,     4,     4,     0,     4,     0,
       4,     4,     4,   109,     4,   194,   176,     0,     0,     4,
       0,     0,   188,     0,     0,    75,     4,     4,     4,     4,
       0,     0,    11,     4,    13,    15,    17,    18,    19,    20,
       0,    16,     0,   143,   145,     0,     4,   221,     0,     0,
       0,     0,     4,     0,     4,   165,   329,     4,     0,     4,
       0,     0,   150,     0,   177,     0,   174,   193,   185,   158,
      37,    39,    32,     4,     0,   229,     0,     0,     0,    75,
       3,    14,    22,   218,     0,    34,     0,    29,    30,     0,
       4,   166,   160,     4,   167,    33,    35,   187,   187,     0,
       0,     0,    25,    24,    23,     0,   219,   155,    31,   163,
       0,   168,   178,   179,   175,   228,     4,     0,     0,     4,
       0,     4,     4,   161,   231,     4,    71,    72,    70,     0,
       4,    63,    69,   164,    21,    64
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -523,  -523,    -3,  -523,  -523,  -523,  -523,  -523,  -523,   -22,
    -523,  -523,  -523,  -522,  -515,     4,  -523,     0,  -523,  -523,
     -34,  -523,  -523,  -523,  -180,   130,  -523,  -164,  -523,  -523,
    -523,   538,   -84,   304,  -248,    20,     1,   128,  -523,   -31,
    -523,  -523,  -523,   159,   -19,  -523,  -523,  -523,   167,    80,
    -523,   346,  -367,    -4,   -11,  -523,   605,  -523,   289,  -523,
    -466,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,    52,
    -523,  -523,  -523,  -523,  -523,   313,  -179,  -115,   225,    11,
    -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,  -523,
    -523,  -523,  -523,  -174,    -9,   610,  -523,   -15,  -523,   477,
    -523,    83,   247,   -66,   369,   218,    54,   392,   214,   395,
     215,   388,   220,   397,   217,   393,   226,  -523,  -523,  -523,
    -523,   -32,  -377,   544,  -523,    26,  -523,  -523,  -457,   -40,
     -87
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,    50,    51,    52,   456,   457,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,    53,   313,    55,    56,
     174,   179,   180,   439,   181,   346,   679,   314,    57,   680,
     315,    58,   681,   316,   182,   153,   193,    60,    61,    62,
      63,    64,    65,   425,   572,    66,    67,   325,   326,   149,
     396,   136,   397,   137,    68,   187,   139,   250,   266,   479,
      69,    70,    71,    72,   391,   599,   170,   517,   417,   660,
     482,   668,    73,    74,    75,    76,    77,   515,   565,   566,
     617,    78,    79,    80,   307,   308,   573,   267,   480,   567,
      81,    82,    83,    84,    85,   129,   130,   258,   259,   387,
      86,   195,   338,   251,    87,    88,    89,   254,   347,    90,
      91,    92,    93,    94,    95,    96,   280,    97,   281,    98,
     282,    99,   283,   100,   284,   101,   285,   102,   286,   103,
     287,   104,   288,   400,   105,   106,   289,   290,   163,   131,
     107
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -355;
  const short int
  ParserImplementation::yytable_[] =
  {
        54,    59,   126,   138,   167,   188,   138,   176,   334,   255,
     245,   318,   245,   138,   147,   190,   388,   142,   339,   246,
     159,   148,   270,   487,   268,   138,   392,   245,   245,   194,
     451,   138,   138,   133,   245,   140,   124,   501,   183,   503,
     379,   264,   274,   245,   420,   421,   263,   557,   269,   156,
     245,   505,   245,   271,   245,   162,   132,    54,    59,   165,
     445,   459,   319,   450,   186,   245,   330,   245,   323,   245,
     591,   245,   202,   245,   205,   245,   302,   245,   304,   575,
     256,   184,   309,    39,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   128,   135,   154,   603,   152,   328,   262,
     150,   551,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   168,   552,    49,   169,   591,   615,   221,
     222,   223,    39,   185,   155,   383,   399,   166,   172,   510,
     138,   172,   138,   305,    39,   164,   454,   196,   265,   265,
     312,   440,   173,   217,   218,   175,   477,   194,   306,   676,
     642,   124,   257,   428,    49,   294,   677,   296,   676,  -232,
     359,   360,   361,    45,   122,   677,    49,   348,   134,   380,
     461,   462,   452,   138,   647,  -232,   151,   138,   171,   606,
     327,   295,   253,   659,   335,   189,   300,   329,   353,   422,
     303,   429,    39,   434,   331,   341,   616,   311,   197,   446,
     460,   384,   532,   455,   555,   465,   597,   239,   604,   444,
     609,   376,   633,   378,   643,   382,   656,   343,    45,   122,
     247,   135,   143,   273,    49,   423,   349,   160,   161,   351,
     248,   224,   225,   389,   160,   161,   168,   172,   172,   249,
     241,   144,   219,   157,   424,   143,   229,   230,   231,   232,
     233,   521,   523,   138,   401,   402,   403,   138,   404,   337,
     183,   242,   158,   138,   144,   240,   138,   192,   529,   248,
     183,   243,   244,   398,   252,   431,   260,   534,   249,   143,
     324,   138,   138,   332,   414,   415,    45,   122,   183,   183,
     448,    45,   122,    45,   122,   395,   145,   146,   144,   234,
     265,   317,   272,   317,   354,   355,   356,   405,   268,   577,
     138,   275,   578,   276,    45,   122,   579,   441,   177,   145,
     146,   527,   291,   519,   292,   143,   520,   624,   178,   438,
      45,   122,    39,    45,   122,   333,   433,   466,   511,   512,
     513,   593,   217,   218,   144,    45,   122,   293,    45,   122,
     469,   297,   580,   145,   146,   577,   298,   570,   578,   571,
     -10,   299,   579,   178,    49,   301,   178,   245,    45,   122,
     138,    45,   122,   528,   178,   442,   443,   467,    39,    45,
     122,   655,   598,   138,   600,   601,   310,    45,   122,   320,
     183,    45,   122,   464,    45,   122,   610,   611,   580,   145,
     146,   533,   199,   248,   200,   201,   -12,   138,   522,   524,
      49,   248,   249,   321,   398,   235,   236,   237,   238,   322,
     249,   535,   336,   509,   342,   485,   199,   540,   203,   204,
     350,   541,   200,   201,   138,   518,   352,   138,   639,   138,
     385,   327,  -232,   317,   530,   381,   183,   526,   538,   406,
     407,   408,   409,   368,   369,   370,   371,   426,   427,   650,
     493,   494,   495,   496,   226,   227,   228,   386,   662,   663,
     138,   357,   358,   393,   394,   410,   411,   398,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   412,   413,   416,
     430,   306,   449,   435,   437,   458,   471,   453,   545,   463,
     547,   472,   670,   632,   473,   474,   481,   475,   476,   554,
     483,   478,   506,   504,   507,   508,   514,   516,   531,   279,
     536,   543,   546,   558,   542,   138,   548,   550,   592,   549,
     162,   138,   559,   147,   556,   553,   560,   618,   594,   652,
     653,   654,   561,   563,   625,   562,   564,   568,   569,   657,
     574,   596,   576,   602,   629,   620,   605,   607,   621,   622,
     623,   631,   630,   612,   138,   635,   138,   138,   138,   595,
     619,   183,   138,   341,   147,   147,   147,   636,   637,   162,
     147,   626,   627,   628,   608,   638,   640,   645,   646,   539,
     613,   648,   651,   658,   664,   198,   685,   665,   362,   363,
     364,   365,   366,   367,   667,   641,   666,   669,   671,   672,
     644,   674,   525,   684,   390,   123,   447,   614,   138,   436,
     432,   127,   634,   484,   497,   183,   498,   278,   649,   374,
     500,   372,   499,   162,   220,   373,     0,   377,     0,   375,
       0,   502,     0,     0,   661,     0,     0,     0,     0,   317,
       0,   317,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   138,     0,   162,     0,     0,     0,
     673,   678,   147,   683,   317,     0,   317,   317,     0,   626,
     678,     0,     0,     0,     0,     0,     0,     0,   317,   317,
       0,     0,     0,   217,   218,     0,     0,     0,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,   279,
     488,   489,   490,   491,   492,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,     0,     0,     0,     0,
       0,     0,   219,     0,   317,     0,     0,     0,     0,   682,
       0,     0,   125,    11,    12,     0,     0,     0,   682,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,   279,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
     470,    34,     0,     0,     0,   245,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,   486,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   486,   112,   486,     0,   111,     0,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,   141,    15,     0,   279,    16,     0,     0,     0,
      17,     0,    18,     0,     0,     0,    19,     0,   109,     0,
       0,    21,    22,    23,     0,    24,     0,     0,   544,     0,
      25,    26,    27,     0,     0,   486,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,    48,     1,     2,     0,     0,    49,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,   141,    15,
       0,     0,    16,   486,     0,     0,    17,     0,    18,     0,
       0,     0,    19,     0,   109,     0,     0,    21,    22,    23,
       0,    24,     0,     0,     0,     0,    25,    26,    27,     0,
       0,     0,    28,    29,     0,     0,    30,     0,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,     0,     0,     0,
      43,     0,     0,    44,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    46,     0,    47,    48,   191,
       0,     1,     2,    49,     0,   192,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
     125,   537,    12,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   108,     0,     0,    18,     0,     0,     0,
       0,     0,   109,    18,     0,   110,     0,     0,     0,   109,
       0,     0,   110,     0,    25,    26,    27,     0,     0,     0,
      28,    25,    26,    27,    30,     0,     0,    28,    32,     0,
       0,    30,    34,     0,     0,    32,     0,     0,     0,    34,
      40,    41,     0,    42,     0,     0,     0,    40,    41,     0,
      42,     1,     2,     0,     0,    45,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   111,     0,     0,     0,
       0,     0,   261,   111,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   109,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,    45,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   111,     0,     0,     0,
      13,     0,   468,     0,     0,    -4,    14,    15,     0,     0,
      16,     0,     0,     0,    17,     0,    18,     0,     0,     0,
      19,     0,    20,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,    48,     1,     2,     0,
       0,    49,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,   141,    15,     0,     0,    16,     0,     0,     0,
      17,     0,    18,     0,     0,     0,    19,     0,   109,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,    48,   191,     1,     2,     0,    49,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,   141,
      15,     0,     0,    16,     0,     0,     0,    17,     0,    18,
       0,     0,     0,    19,     0,   109,     0,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,    48,
     340,     1,     2,     0,    49,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,   141,    15,     0,     0,
      16,     0,     0,     0,    17,     0,    18,     0,     0,     0,
      19,     0,   109,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,    29,     0,     0,    30,     0,    31,     0,    32,    33,
       0,     0,    34,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,     0,     0,     0,    43,     0,
       0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,    48,  -187,     1,     2,
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
      46,     0,    47,    48,     1,     2,     0,     0,    49,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    14,
      15,     0,     0,    16,     0,     0,     0,    17,     0,    18,
       0,     0,     0,    19,     0,    20,     0,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,    29,     0,     0,    30,     0,    31,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,     0,     0,
       0,    43,     0,     0,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,    48,
       1,     2,     0,     0,    49,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,   141,    15,     0,     0,    16,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,   109,     0,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,    48,     1,     2,     0,     0,
      49,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    19,     0,    20,     0,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,    25,
      26,   675,     0,     0,   578,    28,    29,     0,     0,    30,
       0,    31,     0,    32,    33,     0,     0,    34,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,    48,   -57,     1,     2,     0,    49,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,    14,    15,
       0,     0,    16,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    19,     0,    20,     0,     0,    21,    22,    23,
       0,    24,     0,     0,     0,     0,    25,    26,   675,     0,
       0,   578,    28,    29,     0,     0,    30,     0,    31,     0,
      32,    33,     0,     0,    34,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    46,     0,    47,    48,   -58,
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
       0,     0,    46,     0,    47,    48,   -59,     1,     2,     0,
      49,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,    16,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,    26,    27,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,    48,   -60,     1,     2,     0,    49,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,   277,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,    45,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   111,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,     0,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,   111,
       1,     2,     0,     0,  -354,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,   344,
       1,     2,     0,     0,    45,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   111,     0,   345,     0,    10,
      11,    12,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,   108,     0,     0,    18,     0,     0,     0,     0,
       0,   109,    18,     0,   110,     0,     0,     0,   109,     0,
       0,   110,     0,    25,    26,    27,     0,     0,     0,    28,
      25,    26,    27,    30,     0,     0,    28,    32,     0,     0,
      30,    34,     0,     0,    32,     0,     0,     0,    34,    40,
      41,     0,    42,     0,     0,     0,    40,    41,     0,    42,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,    45,     0,     0,    47,   111,     0,  -354,     1,     2,
       0,     0,   111,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,   109,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    30,     0,     0,     0,    32,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,   122,     0,     0,     0,     0,     0,     1,
       2,     0,    47,   111,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,    28,     0,
       0,     0,    30,     0,     0,     0,    32,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       1,     2,     0,    47,   111,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   109,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,     0,    32,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     1,     2,     0,    47,   111,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   109,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    30,     0,     0,     0,    32,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,     0,
     344,     1,     2,     0,     0,    45,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   109,     0,     0,   110,    10,    11,    12,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,   108,
      28,     0,     0,     0,    30,     0,     0,     0,    32,    18,
       0,     0,    34,     0,     0,   109,     0,     0,   110,     0,
      40,    41,     0,    42,     0,     0,     0,    25,    26,    27,
       0,     0,     0,    28,     0,    45,     0,    30,     0,     0,
       0,    32,     0,     0,     0,    34,   111,   418,     0,     0,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         0,     0,    11,    14,    35,    45,    17,    41,   188,     3,
       3,   175,     3,    24,    17,    47,   264,    16,   192,   106,
      24,    17,   137,   400,     3,    36,   274,     3,     3,    48,
       3,    42,    43,    13,     3,    15,    10,   414,    42,   416,
       3,    47,    47,     3,   292,   293,   133,   504,   135,    23,
       3,   418,     3,   140,     3,    29,    79,    57,    57,    33,
       3,     3,   177,    47,    44,     3,     3,     3,   183,     3,
     536,     3,    87,     3,    89,     3,   163,     3,   165,    47,
      74,    47,   169,   113,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     3,    14,   143,   553,    79,   185,   131,
      47,   478,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    79,   481,   145,    36,   583,    63,    37,
      38,    39,   113,    43,    47,    47,    28,   140,   126,    50,
     141,   126,   143,    57,   113,    47,    69,     0,   144,   144,
     172,   321,   140,    45,    46,   140,   394,   166,    72,   671,
     607,   125,   146,   146,   145,   154,   671,   156,   680,   143,
     226,   227,   228,   129,   130,   680,   145,   199,    79,   132,
     146,   146,   145,   184,   143,   143,   123,   188,    47,   556,
     184,   155,   142,   640,   188,    47,   160,   186,   220,   142,
     164,   142,   113,   142,   131,   194,   141,   171,    59,   142,
     142,   123,   450,   136,   142,   379,   142,    20,   142,   324,
     142,   243,   142,   245,   142,   255,   142,   197,   129,   130,
      79,   141,    60,   143,   145,    79,   200,    49,    50,   203,
      89,    35,    36,   265,    49,    50,    79,   126,   126,    98,
      18,    79,   144,    79,    98,    60,    25,    26,    27,    28,
      29,   140,   140,   264,    25,    26,    27,   268,    29,    79,
     264,    17,    98,   274,    79,    19,   277,   147,   448,    89,
     274,    15,    16,   277,   142,   306,     3,   451,    98,    60,
      79,   292,   293,    79,    15,    16,   129,   130,   292,   293,
     330,   129,   130,   129,   130,    79,   134,   135,    79,    78,
     144,   173,   110,   175,   221,   222,   223,    78,     3,    90,
     321,    79,    93,    79,   129,   130,    97,   321,    79,   134,
     135,    79,    47,   438,    47,    60,   441,   575,   124,    79,
     129,   130,   113,   129,   130,   131,   310,    79,   425,   426,
     427,    79,    45,    46,    79,   129,   130,    47,   129,   130,
     382,   128,   133,   134,   135,    90,   128,   521,    93,   523,
     141,   128,    97,   124,   145,    79,   124,     3,   129,   130,
     381,   129,   130,   131,   124,   114,   115,   381,   113,   129,
     130,   629,   546,   394,   548,   549,    47,   129,   130,    79,
     394,   129,   130,    79,   129,   130,   560,   561,   133,   134,
     135,    79,    47,    89,    49,    50,   141,   418,   442,   443,
     145,    89,    98,     3,   418,    21,    22,    23,    24,   118,
      98,   453,    79,   422,   141,   399,    47,   459,    49,    50,
      79,   463,    49,    50,   445,   434,    79,   448,   602,   450,
     146,   445,   143,   315,   448,   143,   450,   446,   457,    21,
      22,    23,    24,   235,   236,   237,   238,   298,   299,   623,
     406,   407,   408,   409,    32,    33,    34,    80,   647,   648,
     481,   224,   225,    47,    47,    20,    19,   481,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    18,    17,     3,
      47,    72,   142,   141,   141,    79,    47,   143,   472,   143,
     474,    47,   666,   590,   142,    47,     3,   142,   142,   483,
      28,   144,    28,   145,   142,   142,   140,    79,   140,   150,
     140,    28,   140,    28,   143,   536,   140,   142,   537,   140,
     504,   542,   506,   536,   143,   145,   140,   568,   542,   626,
     627,   628,   140,    79,   576,    66,    56,   142,   142,   636,
     142,    28,   143,   140,    47,   141,   555,   145,   141,   141,
     140,   583,   141,   562,   575,   141,   577,   578,   579,   543,
     569,   575,   583,   572,   577,   578,   579,   142,   141,   553,
     583,   577,   578,   579,   558,   141,   145,   141,   141,   459,
     564,   143,   142,   141,   141,    57,   680,   141,   229,   230,
     231,   232,   233,   234,   142,   604,   140,   142,   140,   142,
     609,   141,   445,   141,   268,    10,   327,   565,   629,   315,
     307,    11,   596,   398,   410,   629,   411,   150,   617,   241,
     413,   239,   412,   607,    90,   240,    -1,   244,    -1,   242,
      -1,   415,    -1,    -1,   643,    -1,    -1,    -1,    -1,   521,
      -1,   523,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,   675,    -1,   640,    -1,    -1,    -1,
     669,   671,   675,   672,   546,    -1,   548,   549,    -1,   675,
     680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,   561,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,   666,    -1,    -1,    -1,    -1,   671,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,   680,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,   478,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     383,   106,    -1,    -1,    -1,     3,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,    -1,   140,    -1,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,   556,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,   471,    -1,
      88,    89,    90,    -1,    -1,   478,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,   140,    35,    36,    -1,    -1,   145,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,   556,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      -1,    35,    36,   145,    -1,   147,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    70,    -1,    79,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    88,    89,    90,    98,    -1,    -1,    94,   102,    -1,
      -1,    98,   106,    -1,    -1,   102,    -1,    -1,    -1,   106,
     114,   115,    -1,   117,    -1,    -1,    -1,   114,   115,    -1,
     117,    35,    36,    -1,    -1,   129,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   140,    -1,    -1,    -1,
      -1,    -1,   146,   140,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,   129,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   140,    -1,    -1,    -1,
      54,    -1,   146,    -1,    -1,    59,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   139,   140,    35,    36,    -1,
      -1,   145,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,   140,   141,    35,    36,    -1,   145,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,
     141,    35,    36,    -1,   145,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,
      -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   139,   140,   141,    35,    36,
      -1,   145,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,
     107,   108,    -1,   110,   111,    -1,   113,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,   140,    35,    36,    -1,    -1,   145,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,
      35,    36,    -1,    -1,   145,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,   140,    35,    36,    -1,    -1,
     145,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,   108,
      -1,   110,   111,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,   140,   141,    35,    36,    -1,   145,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,   141,
      35,    36,    -1,   145,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,   140,   141,    35,    36,    -1,
     145,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,   140,   141,    35,    36,    -1,   145,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   129,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,   140,
      -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      35,    36,    -1,    -1,   145,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      35,    36,    -1,    -1,   129,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   140,    -1,   142,    -1,    47,
      48,    49,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    70,    -1,    79,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      88,    89,    90,    98,    -1,    -1,    94,   102,    -1,    -1,
      98,   106,    -1,    -1,   102,    -1,    -1,    -1,   106,   114,
     115,    -1,   117,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,   139,   140,    -1,   142,    35,    36,
      -1,    -1,   140,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,   139,   140,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,   139,   140,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,   139,   140,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    35,    36,    -1,    -1,   129,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    60,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    70,
      -1,    -1,   106,    -1,    -1,    76,    -1,    -1,    79,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,   129,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,   140,   108,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140
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
     114,   115,   117,   122,   125,   129,   137,   139,   140,   145,
     149,   150,   151,   164,   165,   166,   167,   176,   179,   184,
     185,   186,   187,   188,   189,   190,   193,   194,   202,   208,
     209,   210,   211,   220,   221,   222,   223,   224,   229,   230,
     231,   238,   239,   240,   241,   242,   248,   252,   253,   254,
     257,   258,   259,   260,   261,   262,   263,   265,   267,   269,
     271,   273,   275,   277,   279,   282,   283,   288,    60,    76,
      79,   140,   257,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   130,   204,   283,    47,   252,   253,     3,   243,
     244,   287,    79,   183,    79,   197,   199,   201,   202,   204,
     183,    60,   184,    60,    79,   134,   135,   150,   163,   197,
      47,   123,    79,   183,   143,    47,   283,    79,    98,   201,
      49,    50,   283,   286,    47,   283,   140,   187,    79,   197,
     214,    47,   126,   140,   168,   140,   168,    79,   124,   169,
     170,   172,   182,   201,    47,   197,   183,   203,   287,    47,
     279,   141,   147,   184,   192,   249,     0,    59,   179,    47,
      49,    50,   255,    49,    50,   255,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    45,    46,   144,
     281,    37,    38,    39,    35,    36,    32,    33,    34,    25,
      26,    27,    28,    29,    78,    21,    22,    23,    24,    20,
      19,    18,    17,    15,    16,     3,   288,    79,    89,    98,
     205,   251,   142,   142,   255,     3,    74,   146,   245,   246,
       3,   146,   279,   288,    47,   144,   206,   235,     3,   288,
     235,   288,   110,   197,    47,    79,    79,   108,   257,   262,
     264,   266,   268,   270,   272,   274,   276,   278,   280,   284,
     285,    47,    47,    47,   184,   283,   184,   128,   128,   128,
     283,    79,   288,   283,   288,    57,    72,   232,   233,   288,
      47,   283,   279,   165,   175,   178,   181,   185,   175,   235,
      79,     3,   118,   235,    79,   195,   196,   201,   288,   184,
       3,   131,    79,   131,   172,   201,    79,    79,   250,   251,
     141,   184,   141,   183,   124,   142,   173,   256,   279,   283,
      79,   283,    79,   279,   259,   259,   259,   260,   260,   261,
     261,   261,   262,   262,   262,   262,   262,   262,   263,   263,
     263,   263,   265,   267,   269,   271,   279,   273,   279,     3,
     132,   143,   287,    47,   123,   146,    80,   247,   182,   279,
     199,   212,   182,    47,    47,    79,   198,   200,   201,    28,
     281,    25,    26,    27,    29,    78,    21,    22,    23,    24,
      20,    19,    18,    17,    15,    16,     3,   216,   108,   257,
     182,   182,   142,    79,    98,   191,   191,   191,   146,   142,
      47,   187,   233,   283,   142,   141,   181,   141,    79,   171,
     172,   201,   114,   115,   235,     3,   142,   206,   287,   142,
      47,     3,   145,   143,    69,   136,   152,   153,    79,     3,
     142,   146,   146,   143,    79,   251,    79,   201,   146,   279,
     257,    47,    47,   142,    47,   142,   142,   182,   144,   207,
     236,     3,   218,    28,   236,   283,   257,   280,   262,   262,
     262,   262,   262,   264,   264,   264,   264,   266,   268,   270,
     272,   280,   274,   280,   145,   200,    28,   142,   142,   184,
      50,   288,   288,   288,   140,   225,    79,   215,   184,   235,
     235,   140,   168,   140,   168,   196,   184,    79,   131,   172,
     201,   140,   182,    79,   251,   279,   140,    48,   252,   173,
     279,   279,   143,    28,   257,   283,   140,   283,   140,   140,
     142,   280,   200,   145,   283,   142,   143,   286,    28,   283,
     140,   140,    66,    79,    56,   226,   227,   237,   142,   142,
     175,   175,   192,   234,   142,    47,   143,    90,    93,    97,
     133,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   208,   252,    79,   201,   283,    28,   142,   175,   213,
     175,   175,   140,   286,   142,   184,   280,   145,   283,   142,
     175,   175,   184,   283,   227,    63,   141,   228,   187,   184,
     141,   141,   141,   140,   182,   279,   163,   163,   163,    47,
     141,   157,   288,   142,   283,   141,   142,   141,   141,   175,
     145,   184,   286,   142,   184,   141,   141,   143,   143,   237,
     175,   142,   288,   288,   288,   182,   142,   288,   141,   286,
     217,   184,   234,   234,   141,   141,   140,   142,   219,   142,
     175,   140,   142,   184,   141,    90,   161,   162,   165,   174,
     177,   180,   185,   184,   141,   180
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
     123,   125,    41,    58,    61,    59,    93,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   148,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   157,   157,   157,   157,   157,
     157,   158,   159,   160,   161,   162,   163,   163,   163,   163,
     163,   163,   164,   165,   165,   166,   166,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   169,   169,   169,   170,
     170,   170,   170,   171,   171,   172,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   180,   180,   181,   181,   182,   182,   183,   183,   184,
     184,   184,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   187,   188,   189,   190,   190,   190,   191,   191,   191,
     192,   192,   193,   193,   193,   194,   195,   195,   196,   196,
     197,   197,   198,   198,   199,   199,   200,   200,   201,   201,
     202,   202,   202,   203,   203,   203,   203,   203,   203,   204,
     205,   205,   205,   205,   205,   205,   206,   207,   208,   209,
     210,   210,   210,   212,   213,   211,   214,   215,   211,   216,
     217,   211,   218,   219,   211,   211,   211,   211,   211,   220,
     221,   222,   223,   224,   225,   225,   226,   226,   227,   228,
     229,   230,   231,   231,   231,   232,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   238,   238,   238,
     239,   240,   240,   241,   241,   241,   241,   241,   241,   242,
     242,   242,   242,   243,   243,   244,   244,   245,   246,   246,
     247,   247,   248,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   251,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   252,   253,   253,   254,   254,   254,   254,   255,
     255,   256,   256,   256,   256,   257,   257,   257,   257,   258,
     258,   258,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   260,   260,   260,   260,   261,   261,   261,   262,
     262,   262,   262,   263,   263,   263,   263,   263,   263,   263,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   265,
     265,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     269,   269,   270,   270,   271,   271,   272,   272,   273,   273,
     274,   274,   275,   275,   276,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   283,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   288,   288
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
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     3,
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
  "JS_PROPERTY", "JS_YIELD", "'{'", "'}'", "')'", "':'", "'='", "';'",
  "']'", "'@'", "$accept", "program", "class_initialiser",
  "class_adjective__opt", "inherit_declaration__opt",
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
  "assignment_expression", "assignment_expression_no_in",
  "assignment_operator", "yield_expression", "expression",
  "expression_no_in", "expression_no_in__opt", "expression__opt",
  "elision__opt", "terminator", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ParserImplementation::rhs_number_type
  ParserImplementation::yyrhs_[] =
  {
       149,     0,    -1,   176,    -1,   151,    59,   183,   152,   140,
     154,   141,    -1,    -1,    60,    -1,    -1,   153,   252,    -1,
      69,    -1,   136,    -1,    -1,   155,    -1,   156,    -1,   157,
      -1,   156,   157,    -1,   158,    -1,   208,    -1,   159,    -1,
     160,    -1,   161,    -1,   162,    -1,   133,    47,   182,   142,
     140,   174,   141,    -1,   163,   288,    -1,    97,   163,   288,
      -1,    93,   163,   288,    -1,    90,   163,   288,    -1,   197,
      -1,    60,   197,    -1,   150,    -1,    79,    47,   182,   142,
     140,   175,   141,    -1,   134,    79,    47,   142,   140,   175,
     141,    -1,   135,    79,    47,   182,   142,   140,   175,   141,
      -1,   137,    47,    79,   142,   140,   234,   141,    -1,    76,
      79,    47,   182,   142,   140,   175,   141,    -1,    60,    79,
      47,   182,   142,   140,   175,   141,    -1,    76,   183,    47,
     182,   142,   140,   175,   141,    -1,   167,    -1,   117,   182,
     118,   114,   140,   175,   141,    -1,   114,   140,   175,   141,
      -1,   117,   182,   118,   115,   140,   175,   141,    -1,   115,
     140,   175,   141,    -1,   117,   182,   118,   114,   168,    -1,
     117,   182,   118,   115,   168,    -1,   115,   168,    -1,   114,
     168,    -1,   126,   279,    -1,   170,    -1,   172,    -1,   170,
       3,   171,    -1,    79,   235,    -1,   201,   235,    -1,   170,
       3,    79,   235,    -1,   170,     3,   201,   235,    -1,    -1,
     172,    -1,   124,    79,    -1,   124,    79,    -1,    -1,   177,
      -1,    -1,   178,    -1,   179,    -1,   176,   179,    -1,   180,
      -1,   177,   180,    -1,   181,    -1,   178,   181,    -1,   184,
      -1,   165,    -1,   185,    -1,   165,    -1,   161,    -1,   162,
      -1,   185,    -1,   165,    -1,    -1,   169,    -1,    -1,    79,
      -1,   185,    -1,   188,    -1,   189,    -1,   187,    -1,   186,
      -1,   193,    -1,   194,    -1,   208,    -1,   209,    -1,   210,
      -1,   211,    -1,   220,    -1,   221,    -1,   222,    -1,   223,
      -1,   229,    -1,   224,    -1,   230,    -1,   231,    -1,   190,
      -1,   164,    -1,   140,   141,    -1,   140,   192,   141,    -1,
     125,   183,   184,    -1,    68,   163,    -1,    83,    79,   128,
     191,   288,    -1,    83,   201,   128,   191,   288,    -1,    83,
      98,   128,   191,   288,    -1,    98,    -1,    79,    -1,   191,
      50,    79,    -1,   184,    -1,   192,   184,    -1,   108,   197,
     288,    -1,    60,   197,   288,    -1,   122,   197,   288,    -1,
     122,    47,   195,   142,   184,    -1,   196,    -1,   195,     3,
     196,    -1,    79,   235,    -1,   201,   206,    -1,   199,    -1,
     197,     3,   199,    -1,   200,    -1,   198,     3,   200,    -1,
      79,   235,    -1,   201,   235,    -1,    79,   236,    -1,   201,
     236,    -1,   202,    -1,   204,    -1,   129,   287,   131,    -1,
     129,   203,   131,    -1,   129,   203,     3,   287,   131,    -1,
     287,    79,    -1,   287,   172,    -1,   287,   201,    -1,   203,
       3,   287,    79,    -1,   203,     3,   287,   172,    -1,   203,
       3,   287,   201,    -1,   130,   205,   132,    -1,    79,    -1,
     251,   143,    79,    -1,   251,   143,   201,    -1,   205,     3,
     251,   143,    79,    -1,   205,     3,    79,    -1,   205,     3,
     251,   143,   201,    -1,   144,   279,    -1,   144,   280,    -1,
     288,    -1,   283,   288,    -1,    80,    47,   283,   142,   184,
      66,   184,    -1,    80,    47,   283,   142,   184,    -1,    81,
     283,   184,    -1,    -1,    -1,    64,   184,   110,   212,    47,
     283,   213,   142,   288,    -1,    -1,    -1,   110,   214,    47,
     283,   215,   142,   184,    -1,    -1,    -1,    74,    47,   285,
     216,   145,   286,   145,   286,   217,   142,   184,    -1,    -1,
      -1,    74,    47,   108,   198,   218,   145,   286,   145,   286,
     219,   142,   184,    -1,    74,    47,   257,    28,   283,   142,
     184,    -1,    74,    47,   108,   200,    28,   283,   142,   184,
      -1,    74,   123,    47,   257,    28,   283,   142,   184,    -1,
      74,   123,    47,   108,   200,    28,   283,   142,   184,    -1,
      61,   183,   288,    -1,    54,   183,   288,    -1,    95,   286,
     288,    -1,   111,    47,   283,   142,   184,    -1,   100,    47,
     283,   142,   225,    -1,   140,   237,   141,    -1,   140,   237,
     228,   237,   141,    -1,   227,    -1,   226,   227,    -1,    56,
     283,   143,   234,    -1,    63,   143,   234,    -1,    79,   143,
     184,    -1,   103,   283,   288,    -1,   107,   187,   232,    -1,
     107,   187,   233,    -1,   107,   187,   232,   233,    -1,    57,
      47,    79,   142,   187,    -1,    72,   187,    -1,    -1,   192,
      -1,    -1,   206,    -1,    -1,   207,    -1,    -1,   226,    -1,
     239,    -1,   240,    -1,    89,    -1,    98,    -1,    94,    -1,
      88,    -1,   106,    -1,    70,    -1,   102,    -1,    79,    -1,
     238,    -1,   242,    -1,   248,    -1,    47,   283,   142,    -1,
      49,   287,   146,    -1,    49,   243,   146,    -1,    49,   243,
       3,   287,   146,    -1,    49,   243,   245,   146,    -1,   287,
     279,    -1,   243,     3,   287,   279,    -1,     3,    -1,   244,
       3,    -1,   246,   247,    -1,    74,    47,   257,    28,   283,
     142,    -1,    74,   123,    47,   257,    28,   283,   142,    -1,
      -1,    80,    47,   283,   142,    -1,   140,   249,   141,    -1,
     147,    -1,   147,   250,   145,    -1,   147,   250,    -1,   251,
     143,   279,    -1,    79,    -1,    79,    47,   182,   142,   140,
     175,   141,    -1,   250,     3,   251,   143,   279,    -1,   250,
       3,    79,    -1,   250,     3,    79,    47,   182,   142,   140,
     175,   141,    -1,    79,    -1,    98,    -1,    89,    -1,   241,
      -1,   166,    -1,   150,    -1,   252,    49,   283,   146,    -1,
      90,    49,   283,   146,    -1,    90,    50,    79,    -1,   252,
      50,    79,    -1,    48,   252,   255,    -1,   252,    -1,    48,
     253,    -1,   252,   255,    -1,   254,   255,    -1,   254,    49,
     283,   146,    -1,   254,    50,    79,    -1,    47,   142,    -1,
      47,   256,   142,    -1,   279,    -1,   173,    -1,   256,     3,
     279,    -1,   256,     3,   173,    -1,   253,    -1,   254,    -1,
     202,    -1,    47,   204,   142,    -1,   257,    -1,   257,    46,
      -1,   257,    45,    -1,   258,    -1,    42,   259,    -1,    43,
     259,    -1,    44,   259,    -1,    46,   259,    -1,    45,   259,
      -1,    35,   259,    -1,    36,   259,    -1,    41,   259,    -1,
      40,   259,    -1,   259,    -1,   260,    37,   259,    -1,   260,
      38,   259,    -1,   260,    39,   259,    -1,   260,    -1,   261,
      35,   260,    -1,   261,    36,   260,    -1,   261,    -1,   262,
      34,   261,    -1,   262,    33,   261,    -1,   262,    32,   261,
      -1,   262,    -1,   263,    26,   262,    -1,   263,    25,   262,
      -1,   263,    29,   262,    -1,   263,    78,   262,    -1,   263,
      27,   262,    -1,   263,    28,   262,    -1,   262,    -1,   264,
      26,   262,    -1,   264,    25,   262,    -1,   264,    29,   262,
      -1,   264,    78,   262,    -1,   264,    27,   262,    -1,   263,
      -1,   265,    23,   263,    -1,   265,    22,   263,    -1,   265,
      24,   263,    -1,   265,    21,   263,    -1,   264,    -1,   266,
      23,   264,    -1,   266,    22,   264,    -1,   266,    24,   264,
      -1,   266,    21,   264,    -1,   265,    -1,   267,    20,   265,
      -1,   266,    -1,   268,    20,   266,    -1,   267,    -1,   269,
      19,   267,    -1,   268,    -1,   270,    19,   268,    -1,   269,
      -1,   271,    18,   269,    -1,   270,    -1,   272,    18,   270,
      -1,   271,    -1,   273,    17,   271,    -1,   272,    -1,   274,
      17,   272,    -1,   273,    -1,   275,    16,   273,    -1,   274,
      -1,   276,    16,   274,    -1,   275,    -1,   275,    15,   279,
     143,   279,    -1,   276,    -1,   276,    15,   280,   143,   280,
      -1,   277,    -1,   257,   281,   279,    -1,   278,    -1,   257,
     281,   280,    -1,   144,    -1,    10,    -1,    12,    -1,    11,
      -1,    14,    -1,     5,    -1,     7,    -1,     6,    -1,     4,
      -1,    13,    -1,     9,    -1,     8,    -1,   139,   279,    -1,
     279,    -1,   282,    -1,   283,     3,   279,    -1,   280,    -1,
     284,     3,   280,    -1,    -1,   284,    -1,    -1,   283,    -1,
      -1,   244,    -1,   145,    -1,   113,    -1
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
    1131,  1133,  1137,  1139,  1143,  1145,  1147,  1149,  1151,  1153,
    1155,  1157,  1159,  1161,  1163,  1165,  1167,  1170,  1172,  1174,
    1178,  1180,  1184,  1185,  1187,  1188,  1190,  1191,  1193,  1195
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   371,   371,   382,   394,   395,   400,   401,   417,   418,
     423,   424,   428,   433,   454,   478,   484,   485,   486,   487,
     488,   493,   508,   518,   528,   537,   547,   548,   555,   556,
     567,   579,   594,   608,   625,   641,   651,   664,   673,   682,
     692,   702,   712,   723,   734,   748,   759,   760,   766,   784,
     800,   810,   820,   832,   833,   842,   859,   869,   870,   874,
     875,   879,   887,   898,   906,   917,   925,   935,   936,   947,
     948,   955,   956,   961,   962,   972,   973,   980,   981,   990,
     991,   996,  1004,  1009,  1013,  1018,  1022,  1027,  1032,  1037,
    1042,  1047,  1052,  1057,  1062,  1067,  1072,  1077,  1082,  1086,
    1093,  1100,  1111,  1124,  1136,  1153,  1168,  1188,  1196,  1204,
    1214,  1222,  1233,  1241,  1249,  1260,  1270,  1276,  1283,  1291,
    1302,  1310,  1320,  1326,  1334,  1342,  1353,  1361,  1373,  1377,
    1384,  1394,  1401,  1414,  1426,  1435,  1445,  1456,  1464,  1475,
    1486,  1496,  1509,  1519,  1530,  1539,  1550,  1554,  1558,  1562,
    1576,  1585,  1594,  1607,  1609,  1606,  1618,  1619,  1617,  1627,
    1628,  1627,  1640,  1641,  1640,  1653,  1664,  1676,  1687,  1701,
    1711,  1721,  1731,  1742,  1753,  1757,  1766,  1772,  1780,  1791,
    1802,  1815,  1825,  1834,  1843,  1855,  1866,  1874,  1875,  1879,
    1880,  1884,  1885,  1889,  1890,  1894,  1895,  1896,  1903,  1910,
    1920,  1930,  1937,  1947,  1954,  1961,  1962,  1963,  1964,  1972,
    1982,  1989,  1999,  2010,  2020,  2031,  2032,  2037,  2045,  2052,
    2062,  2063,  2072,  2086,  2090,  2094,  2101,  2110,  2122,  2137,
    2144,  2155,  2172,  2179,  2186,  2196,  2200,  2204,  2209,  2222,
    2234,  2249,  2264,  2280,  2281,  2291,  2304,  2317,  2330,  2348,
    2349,  2353,  2359,  2365,  2370,  2378,  2379,  2380,  2381,  2385,
    2389,  2396,  2406,  2407,  2414,  2421,  2428,  2435,  2442,  2449,
    2456,  2463,  2473,  2474,  2478,  2482,  2489,  2490,  2494,  2501,
    2502,  2506,  2510,  2517,  2518,  2522,  2526,  2530,  2534,  2538,
    2545,  2546,  2550,  2554,  2558,  2562,  2569,  2570,  2574,  2578,
    2582,  2589,  2590,  2594,  2598,  2602,  2609,  2610,  2617,  2618,
    2625,  2626,  2633,  2634,  2641,  2642,  2649,  2650,  2657,  2658,
    2665,  2666,  2673,  2674,  2681,  2682,  2689,  2690,  2699,  2700,
    2709,  2713,  2723,  2727,  2738,  2739,  2740,  2741,  2742,  2743,
    2744,  2745,  2746,  2747,  2748,  2749,  2753,  2762,  2769,  2773,
    2781,  2788,  2796,  2797,  2801,  2802,  2806,  2807,  2811,  2812
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
      47,   142,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   143,   145,
      26,   144,    25,    15,   147,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   146,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   140,    18,   141,    41,     2,     2,     2,
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
     132,   133,   134,   135,   136,   137,   138,   139
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3389;
  const int ParserImplementation::yynnts_ = 141;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 196;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 148;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 377;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 6064 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2815 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


