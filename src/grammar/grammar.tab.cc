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
#line 366 "grammar/grammar.yy"
    {int yydebug_ = 0;}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 367 "grammar/grammar.yy"
    {
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( tracer->GetPath());
    root->Append( (yysemantic_stack_[(2) - (2)].node_list) );
    ast_root->InsertBefore( root );
  }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 378 "grammar/grammar.yy"
    {
    Class* cls = ManagedHandle::Retain( new Class( (yysemantic_stack_[(7) - (4)].ast) , (yysemantic_stack_[(7) - (1)].opt) ) );
    cls->Name( (yysemantic_stack_[(7) - (3)].ast) );
    cls->Body( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.cls) = cls;
  }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 388 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 389 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 394 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 396 "grammar/grammar.yy"
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
#line 409 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 410 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 415 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 416 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 420 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 426 "grammar/grammar.yy"
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
#line 447 "grammar/grammar.yy"
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
#line 471 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 476 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 477 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 478 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 479 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 480 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 486 "grammar/grammar.yy"
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
#line 501 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 511 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 521 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 530 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 539 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 541 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 546 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 548 "grammar/grammar.yy"
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
#line 559 "grammar/grammar.yy"
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
#line 571 "grammar/grammar.yy"
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
#line 586 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 599 "grammar/grammar.yy"
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
#line 616 "grammar/grammar.yy"
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
#line 632 "grammar/grammar.yy"
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
#line 641 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 655 "grammar/grammar.yy"
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
#line 664 "grammar/grammar.yy"
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
#line 673 "grammar/grammar.yy"
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
#line 683 "grammar/grammar.yy"
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
#line 693 "grammar/grammar.yy"
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
#line 703 "grammar/grammar.yy"
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
#line 714 "grammar/grammar.yy"
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
#line 725 "grammar/grammar.yy"
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
#line 739 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 749 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 751 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 769 "grammar/grammar.yy"
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
#line 785 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    (yysemantic_stack_[(2) - (1)].value_node)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    list->AddChild( (yysemantic_stack_[(2) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 793 "grammar/grammar.yy"
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
#line 803 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(4) - (3)].value_node)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 812 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 823 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 840 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 849 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 850 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 854 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 855 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 860 "grammar/grammar.yy"
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
#line 868 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 879 "grammar/grammar.yy"
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
#line 887 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 898 "grammar/grammar.yy"
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
#line 906 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 915 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 917 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 927 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 929 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 935 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 936 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 941 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 943 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 952 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 954 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 960 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 962 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 970 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 972 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 977 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 985 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 989 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 994 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 999 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1003 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1008 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1013 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1018 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1023 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1028 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1033 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1038 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1043 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1048 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1053 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1058 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1063 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1067 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1074 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1081 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1092 "grammar/grammar.yy"
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
#line 1105 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1117 "grammar/grammar.yy"
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
#line 1134 "grammar/grammar.yy"
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
#line 1149 "grammar/grammar.yy"
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
#line 1169 "grammar/grammar.yy"
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
#line 1177 "grammar/grammar.yy"
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
#line 1185 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1195 "grammar/grammar.yy"
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
#line 1203 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1214 "grammar/grammar.yy"
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
#line 1222 "grammar/grammar.yy"
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
#line 1230 "grammar/grammar.yy"
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
#line 1241 "grammar/grammar.yy"
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
#line 1251 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1257 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1264 "grammar/grammar.yy"
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
#line 1272 "grammar/grammar.yy"
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
#line 1283 "grammar/grammar.yy"
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
#line 1291 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1301 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1307 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1315 "grammar/grammar.yy"
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
#line 1323 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1333 "grammar/grammar.yy"
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
#line 1341 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1352 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1356 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1363 "grammar/grammar.yy"
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
#line 1373 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1380 "grammar/grammar.yy"
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
#line 1393 "grammar/grammar.yy"
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
#line 1405 "grammar/grammar.yy"
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
#line 1415 "grammar/grammar.yy"
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
#line 1425 "grammar/grammar.yy"
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
#line 1436 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1447 "grammar/grammar.yy"
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
#line 1457 "grammar/grammar.yy"
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
#line 1469 "grammar/grammar.yy"
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
#line 1479 "grammar/grammar.yy"
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
#line 1489 "grammar/grammar.yy"
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
#line 1497 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1507 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1511 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1515 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1520 "grammar/grammar.yy"
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
#line 1534 "grammar/grammar.yy"
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
#line 1543 "grammar/grammar.yy"
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
#line 1555 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1571 "grammar/grammar.yy"
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

  case 153:

/* Line 690 of lalr1.cc  */
#line 1583 "grammar/grammar.yy"
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

  case 154:

/* Line 690 of lalr1.cc  */
#line 1595 "grammar/grammar.yy"
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

  case 155:

/* Line 690 of lalr1.cc  */
#line 1606 "grammar/grammar.yy"
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

  case 156:

/* Line 690 of lalr1.cc  */
#line 1618 "grammar/grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1629 "grammar/grammar.yy"
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

  case 158:

/* Line 690 of lalr1.cc  */
#line 1643 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1653 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1663 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1673 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1684 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1695 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1699 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1708 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1714 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1722 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1733 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1744 "grammar/grammar.yy"
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

  case 170:

/* Line 690 of lalr1.cc  */
#line 1757 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1767 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1776 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1785 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1797 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1808 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1815 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1816 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1820 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1821 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1825 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1826 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1830 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1831 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1835 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1836 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1838 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1845 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1852 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1862 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1872 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1879 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1889 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1896 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1902 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1903 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1904 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1906 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1914 "grammar/grammar.yy"
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

  case 199:

/* Line 690 of lalr1.cc  */
#line 1924 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1931 "grammar/grammar.yy"
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

  case 201:

/* Line 690 of lalr1.cc  */
#line 1941 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1952 "grammar/grammar.yy"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1979 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1987 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1994 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2003 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2005 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2014 "grammar/grammar.yy"
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

  case 212:

/* Line 690 of lalr1.cc  */
#line 2028 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2032 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2039 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2048 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2058 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2065 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2072 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 2082 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2086 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2090 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2095 "grammar/grammar.yy"
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

  case 223:

/* Line 690 of lalr1.cc  */
#line 2108 "grammar/grammar.yy"
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

  case 224:

/* Line 690 of lalr1.cc  */
#line 2123 "grammar/grammar.yy"
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

  case 225:

/* Line 690 of lalr1.cc  */
#line 2138 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2140 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2150 "grammar/grammar.yy"
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
#line 2163 "grammar/grammar.yy"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2176 "grammar/grammar.yy"
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

  case 230:

/* Line 690 of lalr1.cc  */
#line 2189 "grammar/grammar.yy"
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2206 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2207 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2212 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2218 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2224 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2229 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2236 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2237 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2238 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2239 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2244 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2248 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2255 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2264 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
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
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2294 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2301 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2315 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2322 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2331 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2337 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2341 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2347 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2349 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2353 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2359 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2361 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2365 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2369 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2375 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2377 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2381 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2385 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2389 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2393 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2397 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2403 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2405 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2409 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2413 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2417 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2421 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2427 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2429 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2433 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2437 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2441 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2447 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2449 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2453 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2457 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2461 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2467 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2469 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2475 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2477 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2483 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2485 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2491 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2493 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2499 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2501 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2507 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2509 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2515 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2517 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2523 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2525 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2531 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2533 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2539 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2541 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2547 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2549 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2557 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2559 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
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
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2596 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2597 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2598 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2599 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2600 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2601 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2602 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2603 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2604 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2605 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2606 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2607 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2612 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2619 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2627 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2634 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2641 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2642 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2646 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2647 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2651 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2652 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2656 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2657 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4065 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -504;
  const short int
  ParserImplementation::yypact_[] =
  {
      -504,    86,  1848,  -504,  2862,  2862,  2862,  2862,  2862,  2862,
    2862,  2862,  2862,  2568,  2988,   121,   104,   112,   104,  1951,
     166,  -504,     6,   111,    82,   105,    51,  -504,  -504,  -504,
    2666,  -504,   151,  -504,  2862,  -504,   101,   152,   155,   197,
    -504,    18,    24,   175,    95,   104,   121,   202,  1018,  -504,
    -504,   205,  -504,  -504,  -504,  -504,  1122,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,   284,  -504,   297,   593,
    -504,  -504,   259,   192,   273,   207,   293,   248,   251,   256,
     285,    74,  -504,  -504,    33,  -504,  -504,   104,  -504,    26,
     214,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
      28,   154,    49,  2862,   284,  -504,  -504,    14,   308,   810,
    -504,   -29,    30,    34,  -504,   194,  -504,  -504,   -29,   152,
     233,   152,    32,   269,   286,  -504,  -504,   360,  2262,   321,
     330,   336,  1951,  2862,   258,   262,   263,   388,   -29,  2862,
      33,  1225,    54,   194,    34,  2862,  2862,  2862,  2054,  -504,
    2054,  -504,   194,  -504,   389,   277,   194,   184,    34,  1951,
      42,     5,   314,    82,   255,   260,  -504,  -504,  1329,   261,
      35,   265,   104,  -504,   683,  2862,   317,  -504,  2862,   319,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  2862,  2862,  2862,  2862,  2862,
    2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,
    2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,
    2862,  -504,  -504,  -504,  -504,   266,    36,   267,  -504,  -504,
    -504,   121,    10,  -504,   268,   328,  -504,  -504,  -504,  -504,
     175,  2862,  -504,  -504,   152,  -504,  -504,  -504,   362,   360,
     175,   363,   367,   208,   472,   273,   246,   329,   395,   399,
     401,   403,   306,  -504,  -504,   418,   283,  2904,   175,   175,
    -504,    55,    12,    12,    12,  -504,    56,  -504,   379,   101,
     357,  -504,  -504,    58,    60,  -504,  -504,   294,  2158,  -504,
    -504,   295,  -504,   128,   216,  -504,   194,    61,  -504,   194,
    -504,  -504,   121,  -504,  -504,  -504,  -504,   292,  -504,  -504,
    -504,    26,  -504,  2862,   -20,   355,  -504,  -504,    62,  -504,
      19,  -504,    23,  -504,  -504,  -504,  -504,  -504,   259,   259,
     192,   192,   192,   273,   273,   273,   273,   273,   273,   207,
     207,   207,   207,   293,   248,   251,   256,   313,   285,  -504,
      43,  -504,   210,   914,  2946,   407,  -504,   409,  -504,   307,
    -504,  -504,  2862,   318,   320,   175,   326,    40,   432,   326,
    2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,
    2862,  2862,  2862,  2862,  2862,  2862,  2862,  2862,  2365,   208,
     434,   322,   331,  1951,  -504,  -504,    44,    44,    44,   332,
     392,  -504,  -504,  1951,  1951,  -504,  -504,  -504,   194,   393,
    -504,  -504,   194,    59,   118,  -504,   184,  1951,  -504,    91,
     337,   333,  -504,  -504,  -504,   350,  3030,  -504,  2764,  -504,
    -504,  -504,  2862,   266,   348,  -504,  -504,  -504,  -504,   440,
    2946,  2862,   353,    65,   354,   356,   358,  2862,  -504,  -504,
     208,  2365,  2862,  -504,    66,   593,  -504,   273,   273,   273,
     273,   273,   246,   246,   246,   246,   329,   395,   399,   401,
     352,   403,  -504,   359,   466,  2862,   361,   366,   429,   417,
    -504,  -504,  -504,   443,  -504,   365,  -504,  -504,  -504,  -504,
    -504,  2054,  -504,  2054,  -504,  -504,  -504,  -504,  -504,  -504,
    1433,  2862,   150,  3030,   276,  -504,  -504,  -504,   212,  2862,
     478,    67,  2054,   -29,  2054,  2054,   374,  -504,  -504,   370,
      69,  1951,  2862,  2468,  2862,    70,  2054,  2054,  1951,  -504,
    2862,   443,  -504,   -17,   101,   376,   377,  1537,   381,  -504,
     166,   166,   166,   473,   383,  -504,   839,  -504,  -504,  -504,
    -504,  -504,  -504,   -29,  -504,   284,  -504,  -504,    73,  2862,
    -504,   386,  -504,   394,   396,  2054,  2468,  1951,  -504,  -504,
     397,    78,  1951,   404,   405,  -504,    41,  -504,   406,  -504,
     443,  -504,  -504,  -504,  -504,   -29,   -29,   -29,   175,  -504,
    -504,  -504,  -504,    79,  -504,  -504,  -504,   420,   400,  -504,
    1951,  1951,  -504,  -504,  -504,  1537,  1537,   422,  -504,  -504,
    -504,   402,  -504,  -504,  1951,  -504,  -504,  -504,  -504,  -504,
     398,  -504,  1640,  -504,  -504,  -504,   427,  1744,  -504,  -504,
    -504,  -504
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     5,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   336,    77,     6,    77,     5,
       5,   191,     0,    77,   193,     0,     0,   189,   186,   188,
     334,   187,     0,   192,     5,   190,     0,     0,     0,     0,
     339,     0,     0,    75,     0,    77,   336,     0,     5,   338,
     221,     0,    99,    68,   220,    37,     3,    61,    67,    79,
      83,    82,    80,    81,    98,    84,    85,   239,    86,    87,
      88,    89,    90,    91,    92,    93,    95,    94,    96,    97,
     194,   184,   185,   219,   195,   196,   225,   237,   238,   241,
     244,   254,   258,   261,   265,   278,   288,   292,   296,   300,
     304,   308,   312,   328,     0,   146,     6,    77,   193,   212,
     241,   250,   251,   253,   252,   245,   246,   247,   249,   248,
       0,     0,     0,     5,   225,   226,   204,     0,   337,     5,
      78,     0,   178,     0,   120,   178,   128,   129,     0,     6,
       0,     6,   178,     0,     0,    29,   103,    27,     5,     0,
       0,     0,     5,     5,     0,     0,     0,   335,     0,     5,
       0,     5,     0,   178,     0,     5,     5,     5,     5,    45,
       5,    44,   178,    76,    47,     0,   178,     0,     0,     5,
       0,     0,     0,   193,   186,   187,   100,   110,     5,     0,
       0,     0,    77,    62,     5,     5,     0,   227,     5,     0,
     228,   324,   321,   323,   322,   327,   326,   317,   319,   318,
     325,   320,   243,   242,   316,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,   147,   216,   218,   217,   138,     0,     0,   240,   197,
     224,   336,     0,   199,     0,   209,   205,   198,   202,   159,
      75,     5,   179,   124,     0,   113,   125,   158,     0,    28,
      75,     0,     0,     0,   241,   272,   283,   290,   294,   298,
     302,   306,   310,   314,   330,   333,     0,     5,    75,    75,
     169,     0,     0,     0,     0,   160,     0,   170,     0,     0,
     171,   172,   112,     0,     0,    46,    74,     0,     5,    65,
      73,     0,    49,    53,     0,    50,   178,     0,   116,     0,
     114,   102,   336,   131,   133,   130,   134,     0,   101,   111,
     211,     0,   213,     5,     7,     0,   231,   234,     0,   233,
       0,   223,     0,   230,   313,   255,   256,   257,   259,   260,
     264,   263,   262,   267,   266,   270,   271,   268,   269,   282,
     280,   279,   281,   289,   293,   297,   301,     0,   305,   329,
       0,   137,     0,     5,     5,     0,   201,     0,   206,     0,
     144,   121,     5,     0,     0,    75,   180,     0,   122,   180,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     0,
       0,     0,     0,     5,   108,   107,     0,     0,     0,     0,
       0,   175,   173,     5,     5,    39,    66,    41,   178,     0,
      48,    54,   178,     0,     0,   118,     0,     5,   119,     0,
       0,     0,   214,     9,    10,     0,     5,    56,     5,   232,
     222,   229,     5,   142,     0,   139,   140,   200,   203,     0,
       5,     5,     0,     0,     0,     0,     0,     5,   181,   126,
       0,     5,     5,   127,     0,   241,   315,   274,   273,   277,
     275,   276,   287,   285,   284,   286,   291,   295,   299,   303,
       0,   307,   331,     0,     0,     5,     0,     0,   149,     0,
     104,   106,   105,   182,   162,     0,   151,   161,    51,    55,
      52,     5,    42,     5,    43,   117,   115,   135,   132,   136,
       5,     5,     5,     5,     8,   236,   235,   309,     0,     5,
       0,     0,     5,     0,     5,     5,     0,   145,   123,     0,
       0,     5,     5,     5,     5,     0,     5,     5,     5,   109,
       5,   183,   165,     0,     0,     0,     0,   177,     0,   215,
       5,     5,     5,     0,     0,    12,     5,    14,    16,    18,
      19,    20,    21,     0,    17,     0,   141,   143,     0,     5,
     210,     0,   150,     0,     0,     5,     5,     5,   154,   311,
       0,     0,     5,     0,     0,   148,     0,   166,     0,   163,
     182,   174,    38,    40,    33,     0,     0,     0,    75,     4,
      15,    23,   207,     0,    35,    30,    31,     0,     0,   155,
       5,     5,   156,    34,    36,   176,   176,     0,    26,    25,
      24,     0,   208,    32,     5,   152,   157,   167,   168,   164,
       0,   153,     5,    71,    72,    70,     0,     5,    63,    69,
      22,    64
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -504,  -504,  -504,    -9,  -504,  -504,  -504,  -504,  -504,  -504,
     -33,  -504,  -504,  -504,  -503,  -479,     1,  -504,    -2,  -504,
    -504,   -30,  -504,  -504,  -504,  -504,    97,  -504,  -168,  -504,
    -504,  -504,   499,   -81,   264,  -247,    11,    -1,   -83,  -504,
     -32,  -504,  -504,  -504,    81,     3,  -504,  -504,  -504,   131,
      75,  -504,   304,  -334,   -23,   -12,  -504,   556,  -504,   252,
    -504,  -429,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,    25,  -504,  -504,  -504,  -504,  -504,   270,  -267,
    -105,   185,   -25,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -101,     2,   563,  -504,
      20,  -504,   433,  -504,    92,   168,   159,   302,   124,   -28,
     344,   178,   347,   181,   351,   186,   371,   180,   349,   187,
    -504,  -504,  -504,  -504,  -120,  -357,   501,    -6,  -504,  -504,
    -393,   -36,   -98
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    50,    51,   445,   446,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,    52,   306,    54,
      55,   169,   173,   174,   430,   431,   337,   646,   307,    56,
     647,   308,    57,   648,   309,   175,   151,   187,    59,    60,
      61,    62,    63,    64,   416,   557,    65,    66,   317,   318,
     147,   387,   134,   388,   135,    67,   180,   137,   246,   262,
     468,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     504,   551,   552,   600,    77,    78,    79,   300,   301,   558,
     263,   469,   553,    80,    81,    82,    83,    84,   127,   128,
     254,   255,   378,    85,   189,   190,   191,    86,    87,    88,
     250,   338,    89,    90,    91,    92,    93,    94,    95,   276,
      96,   277,    97,   278,    98,   279,    99,   280,   100,   281,
     101,   282,   102,   283,   103,   284,   391,   104,   285,   286,
     158,   129,   105
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -335;
  const short int
  ParserImplementation::yytable_[] =
  {
        53,    58,   311,   156,   162,   136,   241,   122,   136,   258,
     181,   145,   171,   379,   136,   493,   124,   251,   140,   247,
     176,   146,   240,   383,   157,   136,   240,   131,   160,   138,
     266,   136,   136,   259,   476,   265,   240,   264,   331,   370,
     267,   411,   412,   470,   240,   322,   598,   305,   490,   443,
     492,   188,   240,   148,    53,    58,   179,   374,   240,   240,
     295,   240,   297,   240,   436,   448,   302,   312,   240,   240,
     240,   315,   240,   240,   339,   494,   240,   260,   539,   270,
     320,   240,   240,    40,   324,   310,     3,   310,   252,   238,
     239,   414,   133,   574,   499,   344,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   242,   197,   245,   200,   415,
     537,   298,   164,    49,   243,   444,   243,   122,   367,   178,
     369,   599,   453,   244,   126,   244,   299,   136,   149,   136,
     154,   243,   375,    46,   120,   325,   538,   574,   466,   643,
     244,   380,   177,   167,   643,    40,    40,   291,   155,   167,
     590,   290,   153,   296,   319,   168,    40,   253,   326,   303,
     304,   170,   450,   644,   188,   136,   451,   371,   644,   136,
     517,   261,   323,   261,   163,    49,    49,   332,   321,    46,
     120,   625,   471,   130,   167,   589,    49,   329,   249,   340,
     150,   132,   342,   618,   413,   419,   511,   423,   159,   424,
     437,   449,   165,   334,   533,   541,   580,   428,   587,   592,
     141,   435,   612,   442,   133,   373,   269,   621,   632,    46,
     120,   518,   152,    46,   120,   310,   141,   219,   220,   142,
     441,   163,   224,   225,   226,   227,   228,   176,   161,   560,
      46,   120,   561,   167,   166,   142,   562,   176,   136,   182,
     389,   429,   136,   458,   172,   513,    46,   120,   136,   212,
     213,   136,    40,   316,   192,   176,   176,   421,   234,   454,
     235,   392,   393,   394,   236,   395,   136,   136,    46,   120,
      46,   120,   563,   143,   144,   229,   439,   386,   -11,   455,
     432,   576,    49,   248,    46,   120,   216,   217,   218,   143,
     144,   136,   237,    46,   120,   221,   222,   223,   345,   346,
     347,   256,    46,   120,   230,   231,   232,   233,   500,   501,
     502,   405,   406,   508,   396,   195,   196,   510,   526,   433,
     434,   194,   527,   195,   196,   261,    46,   120,    46,   120,
      46,   120,   268,   555,   194,   556,   198,   199,   271,   456,
     397,   398,   399,   400,   359,   360,   361,   362,   637,   638,
     136,   631,   176,   264,   581,   272,   583,   584,   287,   482,
     483,   484,   485,   136,   417,   418,   463,   288,   593,   594,
     350,   351,   352,   289,   474,   292,   389,   348,   349,   293,
     294,   240,   313,   327,   314,  -218,   341,   136,   343,   330,
    -217,   559,   157,   512,   514,   333,  -216,   372,   377,   382,
     384,   376,   498,   319,   385,   401,   519,   617,   402,   403,
     404,   407,   506,   507,   136,   408,   420,   136,   310,   299,
     310,   440,   425,   427,   447,   582,   516,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   462,   389,   524,   310,
     275,   310,   310,   452,   460,   531,   461,   464,   136,   465,
     472,   496,   495,   310,   310,   157,   540,   467,   529,   503,
     497,   505,   509,   521,   520,   611,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   522,   528,   545,
     532,   534,   542,   535,   544,   548,   549,   536,   546,   550,
     390,   543,   310,   547,   554,   577,   579,   628,   629,   630,
     136,   585,   586,   145,   602,   603,   136,   212,   213,   604,
     608,   609,   601,   578,   614,   575,   353,   354,   355,   356,
     357,   358,   615,   610,   616,   642,   620,   157,   591,   634,
     588,   640,   623,   624,   596,   525,   626,   595,   136,   136,
     136,   145,   145,   145,   136,   193,   329,   145,   633,   649,
     639,   605,   606,   607,   649,   650,   651,   515,   381,   121,
     422,   438,   426,   613,   473,   627,   597,   125,   363,   486,
     157,   274,   364,   487,   489,   176,   619,   365,   368,   488,
     215,   622,     0,   491,     0,     0,   136,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   366,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,   635,
     636,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,     0,     0,     0,     0,   212,   213,
     645,     0,     0,     0,     0,   645,     0,     0,     0,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,   477,   478,   479,   480,   481,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
     410,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,   214,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   275,
      27,    28,     0,     0,     0,     0,    29,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,   335,   459,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,   336,     0,   475,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   475,   110,
     475,     0,     0,     0,   275,     4,     5,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   107,     0,     0,   108,
       0,     0,     0,   530,     0,     0,     0,    27,    28,   141,
     475,     0,     0,    29,     0,     0,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,   142,     0,
       0,     0,     0,    41,    42,     0,    43,     0,   560,     0,
       0,   561,     0,     0,     0,   562,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     4,
       5,    40,     0,   257,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    46,   120,     0,
       0,   563,   143,   144,   106,   475,     0,   -13,     0,     0,
       0,    49,     0,     0,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     4,     5,     0,     0,   457,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   139,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,   107,     0,     0,   183,    25,     0,
      26,     0,     0,     0,     0,    27,   184,     0,     0,     0,
       0,    29,    30,     0,     0,   185,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,    45,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,    47,    48,   186,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,    -5,    17,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,     0,    26,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    33,    34,     0,     0,    35,    36,    37,
       0,    38,    39,     0,    40,    41,    42,     0,    43,     0,
       0,     0,     0,    44,     0,     0,    45,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       4,     5,     0,     0,    49,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   139,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,   107,     0,     0,    24,    25,     0,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      35,    36,    37,     0,    38,    39,     0,    40,    41,    42,
       0,    43,     0,     0,     0,     0,    44,     0,     0,    45,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,    47,    48,   186,     4,     5,     0,    49,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,   139,
      18,     0,     0,    19,     0,     0,     0,    20,     0,    21,
       0,     0,     0,    22,     0,   107,     0,     0,    24,    25,
       0,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      33,    34,     0,     0,    35,    36,    37,     0,    38,    39,
       0,    40,    41,    42,     0,    43,     0,     0,     0,     0,
      44,     0,     0,    45,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,    47,    48,   328,     4,     5,
       0,    49,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,   139,    18,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     0,    22,     0,   107,
       0,     0,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    33,    34,     0,     0,    35,    36,
      37,     0,    38,    39,     0,    40,    41,    42,     0,    43,
       0,     0,     0,     0,    44,     0,     0,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    47,
      48,  -176,     4,     5,     0,    49,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    -5,   139,    18,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    22,     0,   107,     0,     0,    24,    25,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,    35,    36,    37,     0,    38,    39,     0,    40,
      41,    42,     0,    43,     0,     0,     0,     0,    44,     0,
       0,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,    47,    48,     4,     5,     0,     0,    49,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,    23,     0,     0,    24,
      25,     0,    26,     0,     0,     0,     0,    27,    28,   560,
       0,     0,   561,    29,    30,     0,     0,    31,     0,    32,
       0,    33,    34,     0,     0,    35,    36,    37,     0,    38,
      39,     0,    40,    41,    42,     0,    43,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,    47,    48,   -57,     4,
       5,     0,    49,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,     0,
      23,     0,     0,    24,    25,     0,    26,     0,     0,     0,
       0,    27,    28,   560,     0,     0,   561,    29,    30,     0,
       0,    31,     0,    32,     0,    33,    34,     0,     0,    35,
      36,    37,     0,    38,    39,     0,    40,    41,    42,     0,
      43,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
      47,    48,   -58,     4,     5,     0,    49,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,    45,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     4,     5,     0,     0,
      49,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,   139,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,   107,     0,     0,
      24,    25,     0,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    33,    34,     0,     0,    35,    36,    37,     0,
      38,    39,     0,    40,    41,    42,     0,    43,     0,     0,
       0,     0,    44,     0,     0,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     4,
       5,     0,     0,    49,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,     0,
      23,     0,     0,    24,    25,     0,    26,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    33,    34,     0,     0,    35,
      36,    37,     0,    38,    39,     0,    40,    41,    42,     0,
      43,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
      47,    48,   -59,     4,     5,     0,    49,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,     0,     0,    24,    25,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    33,
      34,     0,     0,    35,    36,    37,     0,    38,    39,     0,
      40,    41,    42,     0,    43,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,    47,    48,   -60,     4,     5,     0,
      49,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   107,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,     0,     0,     0,    35,     0,   273,
       0,     0,     0,     0,     0,    41,    42,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       4,     5,     0,     0,  -332,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     4,     5,     0,     0,  -334,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   107,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     4,     5,   109,     0,  -334,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   107,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,   120,     0,     0,
       0,     4,     5,     0,     0,   109,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -5,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,   107,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    29,
       0,     0,     0,    31,     0,     0,     0,    33,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    41,
      42,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     4,
       5,     0,     0,   109,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     4,     5,     0,
       0,   109,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   107,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,    27,
      28,    13,    14,    15,     0,    29,     0,     0,     0,    31,
       0,     0,     0,    33,   106,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    21,    41,    42,     0,    43,     0,
     107,     0,     0,   108,     0,     0,     0,     0,     0,     0,
      46,    27,    28,    13,    14,    15,     0,    29,     0,   109,
       0,    31,     0,     0,     0,    33,   106,     0,     0,    35,
       0,   409,     0,     0,     0,     0,    21,    41,    42,     0,
      43,     0,   107,     0,     0,   108,     0,     0,     0,     0,
       0,     0,    46,    27,    28,   123,    14,    15,     0,    29,
       0,   109,     0,    31,     0,     0,     0,    33,   106,     0,
       0,    35,     0,     0,     0,     0,     0,     0,    21,    41,
      42,     0,    43,     0,   107,     0,     0,   108,     0,     0,
       0,     0,     0,     0,    46,    27,    28,   123,   523,    15,
       0,    29,     0,   109,     0,    31,     0,     0,     0,    33,
     106,     0,     0,    35,     0,     0,     0,     0,     0,     0,
      21,    41,    42,     0,    43,     0,   107,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,   109,     0,    31,     0,     0,
       0,    33,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,     2,   170,    26,    36,    17,   104,    13,    20,   129,
      46,    20,    42,   260,    26,   408,    14,     3,    19,   120,
      43,    20,     3,   270,    30,    37,     3,    16,    34,    18,
     135,    43,    44,   131,   391,   133,     3,     3,     3,     3,
     138,   288,   289,     3,     3,     3,    63,   167,   405,    69,
     407,    48,     3,    47,    56,    56,    45,    47,     3,     3,
     158,     3,   160,     3,     3,     3,   164,   172,     3,     3,
       3,   176,     3,     3,   194,   409,     3,    47,   471,    47,
     178,     3,     3,   112,    79,   168,     0,   170,    74,    15,
      16,    79,    17,   522,    50,   215,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    79,    86,    79,    88,    97,
     467,    57,    37,   142,    88,   135,    88,   123,   238,    44,
     240,   138,    79,    97,     3,    97,    72,   139,   122,   141,
      79,    88,   122,   128,   129,   130,   470,   566,   385,   642,
      97,   261,    47,   125,   647,   112,   112,   153,    97,   125,
     543,   152,    47,   159,   177,   137,   112,   143,   181,   165,
     166,   137,   143,   642,   161,   177,   143,   131,   647,   181,
      79,   141,   130,   141,    79,   142,   142,   142,   179,   128,
     129,   140,   142,    79,   125,   542,   142,   188,   139,   195,
      79,    79,   198,   586,   139,   139,   137,   139,    47,   139,
     139,   139,    47,   192,   139,   139,   139,    79,   139,   139,
      60,   316,   139,   333,   139,   251,   141,   139,   139,   128,
     129,   130,   140,   128,   129,   308,    60,    35,    36,    79,
     331,    79,    25,    26,    27,    28,    29,   260,   137,    89,
     128,   129,    92,   125,    47,    79,    96,   270,   260,    47,
     273,   123,   264,   373,    79,   137,   128,   129,   270,    45,
      46,   273,   112,    79,    59,   288,   289,   299,    20,   370,
      19,    25,    26,    27,    18,    29,   288,   289,   128,   129,
     128,   129,   132,   133,   134,    78,   322,    79,   138,    79,
     313,    79,   142,   139,   128,   129,    37,    38,    39,   133,
     134,   313,    17,   128,   129,    32,    33,    34,   216,   217,
     218,     3,   128,   129,    21,    22,    23,    24,   416,   417,
     418,    15,    16,   428,    78,    49,    50,   432,   448,   113,
     114,    47,   452,    49,    50,   141,   128,   129,   128,   129,
     128,   129,   109,   511,    47,   513,    49,    50,    79,   372,
      21,    22,    23,    24,   230,   231,   232,   233,   625,   626,
     372,   608,   385,     3,   532,    79,   534,   535,    47,   397,
     398,   399,   400,   385,   293,   294,   382,    47,   546,   547,
     221,   222,   223,    47,   390,   127,   409,   219,   220,   127,
     127,     3,     3,    79,   117,   140,    79,   409,    79,   138,
     140,   521,   408,   433,   434,   140,   140,   140,    80,    47,
      47,   143,   413,   436,    47,    20,   439,   585,    19,    18,
      17,     3,   423,   424,   436,   142,    47,   439,   511,    72,
     513,   139,   138,   138,    79,   533,   437,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   139,   470,   446,   532,
     148,   534,   535,   140,    47,   461,    47,   139,   470,   139,
      28,   139,    28,   546,   547,   471,   472,   141,    28,   137,
     139,    79,    79,   140,   137,   573,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   137,   140,   495,
     137,   137,   140,   137,    28,    66,    79,   139,   137,    56,
      28,   142,   585,   137,   139,   528,    28,   605,   606,   607,
     522,   137,   142,   522,   138,   138,   528,    45,    46,   138,
      47,   138,   554,   529,   138,   523,   224,   225,   226,   227,
     228,   229,   138,   566,   138,   137,   139,   543,   544,   139,
     541,   139,   138,   138,   550,   448,   140,   548,   560,   561,
     562,   560,   561,   562,   566,    56,   557,   566,   138,   642,
     138,   560,   561,   562,   647,   138,   647,   436,   264,    13,
     300,   319,   308,   579,   389,   600,   551,    14,   234,   401,
     586,   148,   235,   402,   404,   608,   587,   236,   239,   403,
      89,   592,    -1,   406,    -1,    -1,   608,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   237,    -1,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   620,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,    -1,    -1,    -1,    -1,    45,    46,
     642,    -1,    -1,    -1,    -1,   647,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
     287,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,   467,
      87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   374,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,    -1,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,    -1,    -1,   542,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    87,    88,    60,
     467,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    79,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    35,
      36,   112,    -1,   143,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,   128,   129,    -1,
      -1,   132,   133,   134,    60,   542,    -1,   138,    -1,    -1,
      -1,   142,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    35,    36,    -1,    -1,   143,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    35,    36,    -1,
     142,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,   107,
      -1,   109,   110,    -1,   112,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
      35,    36,    -1,    -1,   142,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,
     105,   106,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,   124,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    35,    36,    -1,   142,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,   106,   107,    -1,   109,   110,
      -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
     121,    -1,    -1,   124,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,    35,    36,
      -1,   142,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   106,
     107,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
      -1,    -1,    -1,    -1,   121,    -1,    -1,   124,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,    35,    36,    -1,   142,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    35,    36,    -1,    -1,   142,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,    92,    93,    94,    -1,    -1,    97,    -1,    99,
      -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,    35,
      36,    -1,   142,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,
     106,   107,    -1,   109,   110,    -1,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,    35,    36,    -1,   142,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    35,    36,    -1,    -1,
     142,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,   102,    -1,    -1,   105,   106,   107,    -1,
     109,   110,    -1,   112,   113,   114,    -1,   116,    -1,    -1,
      -1,    -1,   121,    -1,    -1,   124,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    35,
      36,    -1,    -1,   142,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,
     106,   107,    -1,   109,   110,    -1,   112,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,    35,    36,    -1,   142,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
     102,    -1,    -1,   105,   106,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    35,    36,    -1,
     142,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      35,    36,    -1,    -1,   142,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    35,    36,    -1,    -1,   142,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,   137,    -1,   139,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,    35,    36,    -1,    -1,   137,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,   137,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,   137,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    47,    48,    49,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,   101,    60,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    70,   113,   114,    -1,   116,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    87,    88,    47,    48,    49,    -1,    93,    -1,   137,
      -1,    97,    -1,    -1,    -1,   101,    60,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    70,   113,   114,    -1,
     116,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    87,    88,    47,    48,    49,    -1,    93,
      -1,   137,    -1,    97,    -1,    -1,    -1,   101,    60,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    70,   113,
     114,    -1,   116,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    87,    88,    47,    48,    49,
      -1,    93,    -1,   137,    -1,    97,    -1,    -1,    -1,   101,
      60,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      70,   113,   114,    -1,   116,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    -1,    93,    -1,   137,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  ParserImplementation::yystos_[] =
  {
         0,   145,   146,     0,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    54,    60,    61,    64,
      68,    70,    74,    76,    79,    80,    82,    87,    88,    93,
      94,    97,    99,   101,   102,   105,   106,   107,   109,   110,
     112,   113,   114,   116,   121,   124,   128,   136,   137,   142,
     147,   148,   161,   162,   163,   164,   173,   176,   181,   182,
     183,   184,   185,   186,   187,   190,   191,   199,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   218,   219,   220,
     227,   228,   229,   230,   231,   237,   241,   242,   243,   246,
     247,   248,   249,   250,   251,   252,   254,   256,   258,   260,
     262,   264,   266,   268,   271,   276,    60,    76,    79,   137,
     246,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     129,   201,   271,    47,   241,   242,     3,   232,   233,   275,
      79,   180,    79,   194,   196,   198,   199,   201,   180,    60,
     181,    60,    79,   133,   134,   147,   160,   194,    47,   122,
      79,   180,   140,    47,    79,    97,   198,   271,   274,    47,
     271,   137,   184,    79,   194,    47,    47,   125,   137,   165,
     137,   165,    79,   166,   167,   179,   198,    47,   194,   180,
     200,   275,    47,    79,    88,    97,   138,   181,   189,   238,
     239,   240,    59,   176,    47,    49,    50,   244,    49,    50,
     244,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    45,    46,   141,   270,    37,    38,    39,    35,
      36,    32,    33,    34,    25,    26,    27,    28,    29,    78,
      21,    22,    23,    24,    20,    19,    18,    17,    15,    16,
       3,   276,    79,    88,    97,    79,   202,   240,   139,   139,
     244,     3,    74,   143,   234,   235,     3,   143,   268,   276,
      47,   141,   203,   224,     3,   276,   224,   276,   109,   194,
      47,    79,    79,   107,   246,   251,   253,   255,   257,   259,
     261,   263,   265,   267,   269,   272,   273,    47,    47,    47,
     181,   271,   127,   127,   127,   276,   271,   276,    57,    72,
     221,   222,   276,   271,   271,   268,   162,   172,   175,   178,
     182,   172,   224,     3,   117,   224,    79,   192,   193,   198,
     276,   181,     3,   130,    79,   130,   198,    79,   138,   181,
     138,     3,   142,   140,   180,   123,   139,   170,   245,   268,
     271,    79,   271,    79,   268,   248,   248,   248,   249,   249,
     250,   250,   250,   251,   251,   251,   251,   251,   251,   252,
     252,   252,   252,   254,   256,   258,   260,   268,   262,   268,
       3,   131,   140,   275,    47,   122,   143,    80,   236,   179,
     268,   196,    47,   179,    47,    47,    79,   195,   197,   198,
      28,   270,    25,    26,    27,    29,    78,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   142,   107,
     246,   179,   179,   139,    79,    97,   188,   188,   188,   139,
      47,   184,   222,   139,   139,   138,   178,   138,    79,   123,
     168,   169,   198,   113,   114,   224,     3,   139,   203,   275,
     139,   240,   268,    69,   135,   149,   150,    79,     3,   139,
     143,   143,   140,    79,   240,    79,   198,   143,   268,   246,
      47,    47,   139,   271,   139,   139,   179,   141,   204,   225,
       3,   142,    28,   225,   271,   246,   269,   251,   251,   251,
     251,   251,   253,   253,   253,   253,   255,   257,   259,   261,
     269,   263,   269,   274,   197,    28,   139,   139,   181,    50,
     276,   276,   276,   137,   214,    79,   181,   181,   224,    79,
     224,   137,   165,   137,   165,   193,   181,    79,   130,   198,
     137,   140,   137,    48,   241,   170,   268,   268,   140,    28,
     246,   271,   137,   139,   137,   137,   139,   269,   197,   274,
     271,   139,   140,   142,    28,   271,   137,   137,    66,    79,
      56,   215,   216,   226,   139,   172,   172,   189,   223,   268,
      89,    92,    96,   132,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   205,   241,    79,   198,   271,    28,
     139,   172,   276,   172,   172,   137,   142,   139,   181,   269,
     274,   271,   139,   172,   172,   181,   271,   216,    63,   138,
     217,   184,   138,   138,   138,   160,   160,   160,    47,   138,
     154,   276,   139,   271,   138,   138,   138,   172,   274,   181,
     139,   139,   181,   138,   138,   140,   140,   226,   276,   276,
     276,   179,   139,   138,   139,   181,   181,   223,   223,   138,
     139,   181,   137,   158,   159,   162,   171,   174,   177,   182,
     138,   177
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
     368,   369,   370,   371,   372,   373,   374,   123,   125,    41,
      58,    61,    59,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  ParserImplementation::yyr1_[] =
  {
         0,   144,   146,   145,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   156,   157,   158,   159,   160,   160,   160,
     160,   160,   160,   161,   162,   162,   163,   163,   164,   164,
     164,   164,   164,   164,   164,   164,   165,   166,   166,   167,
     167,   167,   167,   168,   168,   169,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     181,   181,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   184,   185,   186,   187,   187,   187,   188,   188,   188,
     189,   189,   190,   190,   190,   191,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   199,   200,   200,   200,   200,   201,   202,   202,
     202,   202,   202,   202,   203,   204,   205,   206,   207,   207,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   210,
     211,   212,   213,   214,   214,   215,   215,   216,   217,   218,
     219,   220,   220,   220,   221,   222,   223,   223,   224,   224,
     225,   225,   226,   226,   227,   227,   227,   227,   227,   228,
     229,   229,   230,   230,   230,   230,   230,   230,   231,   231,
     231,   231,   232,   232,   233,   233,   234,   235,   235,   236,
     236,   237,   238,   238,   239,   239,   240,   240,   240,   241,
     241,   241,   241,   241,   241,   242,   242,   243,   243,   243,
     243,   244,   244,   245,   245,   245,   245,   246,   246,   246,
     246,   247,   247,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   249,   249,   249,   249,   250,   250,
     250,   251,   251,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   253,   253,   253,   253,   253,   253,   254,   254,
     254,   254,   254,   255,   255,   255,   255,   255,   256,   256,
     257,   257,   258,   258,   259,   259,   260,   260,   261,   261,
     262,   262,   263,   263,   264,   264,   265,   265,   266,   266,
     267,   267,   268,   268,   269,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   271,
     272,   272,   273,   273,   274,   274,   275,   275,   276,   276
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
       7,     5,     9,    10,     7,     8,     8,     9,     3,     3,
       3,     5,     5,     3,     5,     1,     2,     4,     3,     3,
       3,     3,     3,     4,     5,     2,     0,     1,     0,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       5,     4,     2,     4,     1,     2,     2,     6,     7,     0,
       4,     3,     0,     2,     3,     5,     1,     1,     1,     1,
       1,     1,     4,     3,     3,     1,     2,     2,     2,     4,
       3,     2,     3,     1,     1,     3,     3,     1,     1,     1,
       3,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     5,     1,     3,     1,     3,     1,     1,     1,     1,
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
       145,     0,    -1,    -1,   146,   173,    -1,   148,    59,   180,
     149,   137,   151,   138,    -1,    -1,    60,    -1,    -1,   150,
     241,    -1,    69,    -1,   135,    -1,    -1,   152,    -1,   153,
      -1,   154,    -1,   153,   154,    -1,   155,    -1,   205,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   132,    47,
     179,   139,   137,   171,   138,    -1,   160,   276,    -1,    96,
     160,   276,    -1,    92,   160,   276,    -1,    89,   160,   276,
      -1,   194,    -1,    60,   194,    -1,   147,    -1,    79,    47,
     179,   139,   137,   172,   138,    -1,   133,    79,    47,   139,
     137,   172,   138,    -1,   134,    79,    47,   179,   139,   137,
     172,   138,    -1,   136,    47,    79,   139,   137,   223,   138,
      -1,    76,    79,    47,   179,   139,   137,   172,   138,    -1,
      60,    79,    47,   179,   139,   137,   172,   138,    -1,    76,
     180,    47,   179,   139,   137,   172,   138,    -1,   164,    -1,
     116,   179,   117,   113,   137,   172,   138,    -1,   113,   137,
     172,   138,    -1,   116,   179,   117,   114,   137,   172,   138,
      -1,   114,   137,   172,   138,    -1,   116,   179,   117,   113,
     165,    -1,   116,   179,   117,   114,   165,    -1,   114,   165,
      -1,   113,   165,    -1,   125,   268,    -1,   167,    -1,   167,
       3,   168,    -1,    79,   224,    -1,   198,   224,    -1,   167,
       3,    79,   224,    -1,   167,     3,   198,   224,    -1,    -1,
     169,    -1,   123,    79,    -1,   123,    79,    -1,    -1,   174,
      -1,    -1,   175,    -1,   176,    -1,   173,   176,    -1,   177,
      -1,   174,   177,    -1,   178,    -1,   175,   178,    -1,   181,
      -1,   162,    -1,   182,    -1,   162,    -1,   158,    -1,   159,
      -1,   182,    -1,   162,    -1,    -1,   166,    -1,    -1,    79,
      -1,   182,    -1,   185,    -1,   186,    -1,   184,    -1,   183,
      -1,   190,    -1,   191,    -1,   205,    -1,   206,    -1,   207,
      -1,   208,    -1,   209,    -1,   210,    -1,   211,    -1,   212,
      -1,   218,    -1,   213,    -1,   219,    -1,   220,    -1,   187,
      -1,   161,    -1,   137,   138,    -1,   137,   189,   138,    -1,
     124,   180,   181,    -1,    68,   160,    -1,    82,    79,   127,
     188,   276,    -1,    82,   198,   127,   188,   276,    -1,    82,
      97,   127,   188,   276,    -1,    97,    -1,    79,    -1,   188,
      50,    79,    -1,   181,    -1,   189,   181,    -1,   107,   194,
     276,    -1,    60,   194,   276,    -1,   121,   194,   276,    -1,
     121,    47,   192,   139,   181,    -1,   193,    -1,   192,     3,
     193,    -1,    79,   224,    -1,   198,   203,    -1,   196,    -1,
     194,     3,   196,    -1,   197,    -1,   195,     3,   197,    -1,
      79,   224,    -1,   198,   224,    -1,    79,   225,    -1,   198,
     225,    -1,   199,    -1,   201,    -1,   128,   275,   130,    -1,
     128,   200,   130,    -1,   128,   200,     3,   275,   130,    -1,
     275,    79,    -1,   275,   198,    -1,   200,     3,   275,    79,
      -1,   200,     3,   275,   198,    -1,   129,   202,   131,    -1,
      79,    -1,   240,   140,    79,    -1,   240,   140,   198,    -1,
     202,     3,   240,   140,    79,    -1,   202,     3,    79,    -1,
     202,     3,   240,   140,   198,    -1,   141,   268,    -1,   141,
     269,    -1,   276,    -1,   271,   276,    -1,    80,    47,   271,
     139,   181,    66,   181,    -1,    80,    47,   271,   139,   181,
      -1,    64,   181,   109,    47,   271,   139,   276,    -1,   109,
      47,   271,   139,   181,    -1,    74,    47,   273,   142,   274,
     142,   274,   139,   181,    -1,    74,    47,   107,   195,   142,
     274,   142,   274,   139,   181,    -1,    74,    47,   246,    28,
     271,   139,   181,    -1,    74,    47,   107,   197,    28,   271,
     139,   181,    -1,    74,   122,    47,   246,    28,   271,   139,
     181,    -1,    74,   122,    47,   107,   197,    28,   271,   139,
     181,    -1,    61,   180,   276,    -1,    54,   180,   276,    -1,
      94,   274,   276,    -1,   110,    47,   271,   139,   181,    -1,
      99,    47,   271,   139,   214,    -1,   137,   226,   138,    -1,
     137,   226,   217,   226,   138,    -1,   216,    -1,   215,   216,
      -1,    56,   271,   140,   223,    -1,    63,   140,   223,    -1,
      79,   140,   181,    -1,   102,   271,   276,    -1,   106,   184,
     221,    -1,   106,   184,   222,    -1,   106,   184,   221,   222,
      -1,    57,    47,    79,   139,   184,    -1,    72,   184,    -1,
      -1,   189,    -1,    -1,   203,    -1,    -1,   204,    -1,    -1,
     215,    -1,   228,    -1,   229,    -1,    88,    -1,    97,    -1,
      93,    -1,    87,    -1,   105,    -1,    70,    -1,   101,    -1,
      79,    -1,   227,    -1,   231,    -1,   237,    -1,    47,   271,
     139,    -1,    49,   275,   143,    -1,    49,   232,   143,    -1,
      49,   232,     3,   275,   143,    -1,    49,   232,   234,   143,
      -1,   275,   268,    -1,   232,     3,   275,   268,    -1,     3,
      -1,   233,     3,    -1,   235,   236,    -1,    74,    47,   246,
      28,   271,   139,    -1,    74,   122,    47,   246,    28,   271,
     139,    -1,    -1,    80,    47,   271,   139,    -1,   137,   238,
     138,    -1,    -1,   239,   142,    -1,   240,   140,   268,    -1,
     239,     3,   240,   140,   268,    -1,    79,    -1,    97,    -1,
      88,    -1,   230,    -1,   163,    -1,   147,    -1,   241,    49,
     271,   143,    -1,   241,    50,    79,    -1,    48,   241,   244,
      -1,   241,    -1,    48,   242,    -1,   241,   244,    -1,   243,
     244,    -1,   243,    49,   271,   143,    -1,   243,    50,    79,
      -1,    47,   139,    -1,    47,   245,   139,    -1,   268,    -1,
     170,    -1,   245,     3,   268,    -1,   245,     3,   170,    -1,
     242,    -1,   243,    -1,   199,    -1,    47,   201,   139,    -1,
     246,    -1,   246,    46,    -1,   246,    45,    -1,   247,    -1,
      42,   248,    -1,    43,   248,    -1,    44,   248,    -1,    46,
     248,    -1,    45,   248,    -1,    35,   248,    -1,    36,   248,
      -1,    41,   248,    -1,    40,   248,    -1,   248,    -1,   249,
      37,   248,    -1,   249,    38,   248,    -1,   249,    39,   248,
      -1,   249,    -1,   250,    35,   249,    -1,   250,    36,   249,
      -1,   250,    -1,   251,    34,   250,    -1,   251,    33,   250,
      -1,   251,    32,   250,    -1,   251,    -1,   252,    26,   251,
      -1,   252,    25,   251,    -1,   252,    29,   251,    -1,   252,
      78,   251,    -1,   252,    27,   251,    -1,   252,    28,   251,
      -1,   251,    -1,   253,    26,   251,    -1,   253,    25,   251,
      -1,   253,    29,   251,    -1,   253,    78,   251,    -1,   253,
      27,   251,    -1,   252,    -1,   254,    23,   252,    -1,   254,
      22,   252,    -1,   254,    24,   252,    -1,   254,    21,   252,
      -1,   253,    -1,   255,    23,   253,    -1,   255,    22,   253,
      -1,   255,    24,   253,    -1,   255,    21,   253,    -1,   254,
      -1,   256,    20,   254,    -1,   255,    -1,   257,    20,   255,
      -1,   256,    -1,   258,    19,   256,    -1,   257,    -1,   259,
      19,   257,    -1,   258,    -1,   260,    18,   258,    -1,   259,
      -1,   261,    18,   259,    -1,   260,    -1,   262,    17,   260,
      -1,   261,    -1,   263,    17,   261,    -1,   262,    -1,   264,
      16,   262,    -1,   263,    -1,   265,    16,   263,    -1,   264,
      -1,   264,    15,   268,   140,   268,    -1,   265,    -1,   265,
      15,   269,   140,   269,    -1,   266,    -1,   246,   270,   268,
      -1,   267,    -1,   246,   270,   269,    -1,   141,    -1,    10,
      -1,    12,    -1,    11,    -1,    14,    -1,     5,    -1,     7,
      -1,     6,    -1,     4,    -1,    13,    -1,     9,    -1,     8,
      -1,   268,    -1,   271,     3,   268,    -1,   269,    -1,   272,
       3,   269,    -1,    -1,   272,    -1,    -1,   271,    -1,    -1,
     233,    -1,   142,    -1,   112,    -1
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
     491,   499,   505,   515,   526,   534,   543,   552,   562,   566,
     570,   574,   580,   586,   590,   596,   598,   601,   606,   610,
     614,   618,   622,   626,   631,   637,   640,   641,   643,   644,
     646,   647,   649,   650,   652,   654,   656,   658,   660,   662,
     664,   666,   668,   670,   672,   674,   676,   678,   682,   686,
     690,   696,   701,   704,   709,   711,   714,   717,   724,   732,
     733,   738,   742,   743,   746,   750,   756,   758,   760,   762,
     764,   766,   768,   773,   777,   781,   783,   786,   789,   792,
     797,   801,   804,   808,   810,   812,   816,   820,   822,   824,
     826,   830,   832,   835,   838,   840,   843,   846,   849,   852,
     855,   858,   861,   864,   867,   869,   873,   877,   881,   883,
     887,   891,   893,   897,   901,   905,   907,   911,   915,   919,
     923,   927,   931,   933,   937,   941,   945,   949,   953,   955,
     959,   963,   967,   971,   973,   977,   981,   985,   989,   991,
     995,   997,  1001,  1003,  1007,  1009,  1013,  1015,  1019,  1021,
    1025,  1027,  1031,  1033,  1037,  1039,  1043,  1045,  1049,  1051,
    1057,  1059,  1065,  1067,  1071,  1073,  1077,  1079,  1081,  1083,
    1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,
    1107,  1109,  1113,  1114,  1116,  1117,  1119,  1120,  1122,  1124
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   366,   366,   366,   377,   388,   389,   394,   395,   409,
     410,   415,   416,   420,   425,   446,   470,   476,   477,   478,
     479,   480,   485,   500,   510,   520,   529,   539,   540,   546,
     547,   558,   570,   585,   598,   615,   631,   641,   654,   663,
     672,   682,   692,   702,   713,   724,   738,   749,   750,   768,
     784,   792,   802,   812,   813,   822,   839,   849,   850,   854,
     855,   859,   867,   878,   886,   897,   905,   915,   916,   927,
     928,   935,   936,   941,   942,   952,   953,   960,   961,   970,
     971,   976,   984,   989,   993,   998,  1002,  1007,  1012,  1017,
    1022,  1027,  1032,  1037,  1042,  1047,  1052,  1057,  1062,  1066,
    1073,  1080,  1091,  1104,  1116,  1133,  1148,  1168,  1176,  1184,
    1194,  1202,  1213,  1221,  1229,  1240,  1250,  1256,  1263,  1271,
    1282,  1290,  1300,  1306,  1314,  1322,  1332,  1340,  1351,  1355,
    1362,  1372,  1379,  1392,  1404,  1414,  1424,  1435,  1446,  1456,
    1468,  1478,  1488,  1496,  1507,  1511,  1515,  1519,  1533,  1542,
    1554,  1562,  1570,  1582,  1594,  1605,  1617,  1628,  1642,  1652,
    1662,  1672,  1683,  1694,  1698,  1707,  1713,  1721,  1732,  1743,
    1756,  1766,  1775,  1784,  1796,  1807,  1815,  1816,  1820,  1821,
    1825,  1826,  1830,  1831,  1835,  1836,  1837,  1844,  1851,  1861,
    1871,  1878,  1888,  1895,  1902,  1903,  1904,  1905,  1913,  1923,
    1930,  1940,  1951,  1961,  1972,  1973,  1978,  1986,  1993,  2003,
    2004,  2013,  2028,  2031,  2038,  2047,  2057,  2064,  2071,  2081,
    2085,  2089,  2094,  2107,  2122,  2138,  2139,  2149,  2162,  2175,
    2188,  2206,  2207,  2211,  2217,  2223,  2228,  2236,  2237,  2238,
    2239,  2243,  2247,  2254,  2264,  2265,  2272,  2279,  2286,  2293,
    2300,  2307,  2314,  2321,  2331,  2332,  2336,  2340,  2347,  2348,
    2352,  2359,  2360,  2364,  2368,  2375,  2376,  2380,  2384,  2388,
    2392,  2396,  2403,  2404,  2408,  2412,  2416,  2420,  2427,  2428,
    2432,  2436,  2440,  2447,  2448,  2452,  2456,  2460,  2467,  2468,
    2475,  2476,  2483,  2484,  2491,  2492,  2499,  2500,  2507,  2508,
    2515,  2516,  2523,  2524,  2531,  2532,  2539,  2540,  2547,  2548,
    2557,  2558,  2567,  2571,  2581,  2585,  2596,  2597,  2598,  2599,
    2600,  2601,  2602,  2603,  2604,  2605,  2606,  2607,  2611,  2618,
    2626,  2633,  2641,  2642,  2646,  2647,  2651,  2652,  2656,  2657
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
      47,   139,    37,    35,     3,    36,    50,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   140,   142,
      26,   141,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,   143,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,    18,   138,    41,     2,     2,     2,
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
     132,   133,   134,   135,   136
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ParserImplementation::yyeof_ = 0;
  const int ParserImplementation::yylast_ = 3167;
  const int ParserImplementation::yynnts_ = 133;
  const int ParserImplementation::yyempty_ = -2;
  const int ParserImplementation::yyfinal_ = 3;
  const int ParserImplementation::yyterror_ = 1;
  const int ParserImplementation::yyerrcode_ = 256;
  const int ParserImplementation::yyntokens_ = 144;

  const unsigned int ParserImplementation::yyuser_token_number_max_ = 374;
  const ParserImplementation::token_number_type ParserImplementation::yyundef_token_ = 2;


} // yy

/* Line 1136 of lalr1.cc  */
#line 5738 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2660 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


