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
    expandar->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = expandar;
  }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 411 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 412 "grammar/grammar.yy"
    { (yyval.info) = (yysemantic_stack_[(1) - (1)].info); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 417 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 418 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 422 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].prop); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 428 "grammar/grammar.yy"
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
#line 449 "grammar/grammar.yy"
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
#line 473 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kConstructor ) );
    member->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 478 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 479 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 480 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 481 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 482 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 488 "grammar/grammar.yy"
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
#line 503 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrototype ) );
    member->AddChild( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 513 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kStatic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 523 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPublic ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 532 "grammar/grammar.yy"
    {
    ClassMember* member = ManagedHandle::Retain( new ClassMember( ClassMember::kPrivate ) );
    member->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.ast) = member;
  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 541 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 543 "grammar/grammar.yy"
    {
    ValueNode* val = ManagedHandle::Retain( new ValueNode( ValueNode::kConstant ) );
    val->Node( (yysemantic_stack_[(2) - (2)].node_list) );
    (yyval.ast) = val;
  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 548 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 550 "grammar/grammar.yy"
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
#line 561 "grammar/grammar.yy"
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
#line 573 "grammar/grammar.yy"
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
#line 588 "grammar/grammar.yy"
    {
    VersionStmt* stmt = ManagedHandle::Retain( new VersionStmt( (yysemantic_stack_[(7) - (3)].info) ) );
    stmt->AddChild( (yysemantic_stack_[(7) - (6)].ast) );
    (yyval.ast) = stmt;
  }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 601 "grammar/grammar.yy"
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
#line 618 "grammar/grammar.yy"
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
#line 634 "grammar/grammar.yy"
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
#line 643 "grammar/grammar.yy"
    { (yyval.function) = (yysemantic_stack_[(1) - (1)].function); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 657 "grammar/grammar.yy"
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
#line 666 "grammar/grammar.yy"
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
#line 675 "grammar/grammar.yy"
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
#line 685 "grammar/grammar.yy"
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
#line 695 "grammar/grammar.yy"
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
#line 705 "grammar/grammar.yy"
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
#line 716 "grammar/grammar.yy"
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
#line 727 "grammar/grammar.yy"
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
#line 741 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
  }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 751 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 753 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 759 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 777 "grammar/grammar.yy"
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

  case 51:

/* Line 690 of lalr1.cc  */
#line 793 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    list->AddChild( value );
    (yyval.node_list) = list;
  }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 803 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(4) - (3)].info)->GetLineNumber() );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Symbol( (yysemantic_stack_[(4) - (3)].info) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 813 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    value->Node( (yysemantic_stack_[(4) - (3)].value_node) );
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( value );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 824 "grammar/grammar.yy"
    { (yyval.ast) = ManagedHandle::Retain<Empty>(); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 825 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 835 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRest ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 852 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kSpread ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (2)].info) );
    (yyval.ast) = value;
  }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 861 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 862 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 866 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 867 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 872 "grammar/grammar.yy"
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
#line 880 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 891 "grammar/grammar.yy"
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
#line 899 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 910 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 918 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 927 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 929 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 939 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 941 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 947 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 948 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 953 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 955 "grammar/grammar.yy"
    { 
    ExpressionStmt *stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->Line( (yysemantic_stack_[(1) - (1)].function)->Line() );
    stmt->AddChild( (yysemantic_stack_[(1) - (1)].function) );
    (yyval.ast) = stmt;
  }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 964 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 966 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].node_list);
  }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 972 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 974 "grammar/grammar.yy"
    {
    ValueNode *value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 982 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 984 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].module_stmt);
  }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 989 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].export_stmt);
  }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 997 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].block);
  }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1001 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1006 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].variable_stmt);
  }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1011 "grammar/grammar.yy"
    { 
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].let_stmt);
  }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1015 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1020 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression_stmt);
  }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1025 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].if_stmt);
  }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1030 "grammar/grammar.yy"
    {
    
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].iteration_stmt);
  }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1035 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].continue_stmt);
  }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1040 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].break_stmt);
  }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1045 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].return_stmt);
  }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1050 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].with_stmt);
  }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1055 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].labelled_stmt);
  }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1060 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].switch_stmt);
  }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1065 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].throw_stmt);
  }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1070 "grammar/grammar.yy"
    {

    (yyval.ast) = (yysemantic_stack_[(1) - (1)].try_stmt);
  }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1075 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1079 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1086 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( connector->GetLineNumber() );
    block->AddChild( GetEmptyNode() );
    (yyval.block) = block;
  }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1093 "grammar/grammar.yy"
    {
    BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
    block->Line( (yysemantic_stack_[(3) - (2)].ast)->Line() );
    block->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.block) = block;
  }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1104 "grammar/grammar.yy"
    {
    ModuleStmt* module = ManagedHandle::Retain<ModuleStmt>();
    module->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    module->Name( (yysemantic_stack_[(3) - (2)].ast) );

    module->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.module_stmt) = module;
  }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1117 "grammar/grammar.yy"
    {
    ExportStmt *exports = ManagedHandle::Retain<ExportStmt>();
    exports->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    exports->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.export_stmt) = exports;
  }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1129 "grammar/grammar.yy"
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

  case 106:

/* Line 690 of lalr1.cc  */
#line 1146 "grammar/grammar.yy"
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

  case 107:

/* Line 690 of lalr1.cc  */
#line 1161 "grammar/grammar.yy"
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

  case 108:

/* Line 690 of lalr1.cc  */
#line 1181 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1189 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    (yyval.ast) = list;
  }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1197 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( value );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1207 "grammar/grammar.yy"
    {
    StatementList* list = ManagedHandle::Retain<StatementList>();
    if ( !(yysemantic_stack_[(1) - (1)].ast)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    }
    (yyval.ast) = list;
  }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1215 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(2) - (2)].ast)->IsEmpty() ) {
      (yysemantic_stack_[(2) - (1)].ast)->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    }
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1226 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kNormal );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1234 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kConst );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1242 "grammar/grammar.yy"
    {
    VariableStmt* var = ManagedHandle::Retain<VariableStmt>();
    var->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    var->VarType( VariableStmt::kLet );
    var->Append( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.variable_stmt) = var;
  }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1253 "grammar/grammar.yy"
    {
    LetStmt* let = ManagedHandle::Retain<LetStmt>();
    let->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    let->Exp( (yysemantic_stack_[(5) - (3)].ast) );
    let->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.let_stmt) = let;
  }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1263 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1269 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].ast)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = (yysemantic_stack_[(3) - (1)].ast);
  }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1276 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    value->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1284 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(2) - (1)].value_node)->Line() );
    value->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    value->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1295 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( !(yysemantic_stack_[(1) - (1)].value_node)->IsEmpty() ) {
      list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    }
    (yyval.node_list) = list;
  }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1303 "grammar/grammar.yy"
    {
    if ( !(yysemantic_stack_[(3) - (3)].value_node)->IsEmpty() ) {
      (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    }
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1313 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].value_node) );
    (yyval.node_list) = list;
  }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1319 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1327 "grammar/grammar.yy"
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
#line 1335 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1345 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kVariable ) );
    node->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(2) - (1)].info) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1353 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    node->Node( (yysemantic_stack_[(2) - (1)].value_node) );
    node->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.value_node) = node;
  }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1364 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1368 "grammar/grammar.yy"
    {
    (yyval.value_node) = (yysemantic_stack_[(1) - (1)].value_node);
  }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1375 "grammar/grammar.yy"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1385 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDstArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1392 "grammar/grammar.yy"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1405 "grammar/grammar.yy"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1417 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    if ( (yysemantic_stack_[(2) - (1)].opt) ) {
      list->AddChild( GetEmptyNode() );
    }
    list->AddChild( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1426 "grammar/grammar.yy"
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

  case 137:

/* Line 690 of lalr1.cc  */
#line 1436 "grammar/grammar.yy"
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

  case 138:

/* Line 690 of lalr1.cc  */
#line 1446 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1454 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1465 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kDst ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->Node( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.value_node) = value;
  }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1476 "grammar/grammar.yy"
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

  case 142:

/* Line 690 of lalr1.cc  */
#line 1486 "grammar/grammar.yy"
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

  case 143:

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

  case 144:

/* Line 690 of lalr1.cc  */
#line 1508 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(5) - (5)].info) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1518 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    node->Symbol( (yysemantic_stack_[(3) - (3)].info) );
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( node );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1526 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].value_node) );
    (yyval.node_list) = (yysemantic_stack_[(5) - (1)].node_list);
  }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1536 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1540 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(2) - (2)].ast); }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1544 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1549 "grammar/grammar.yy"
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

  case 151:

/* Line 690 of lalr1.cc  */
#line 1563 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(7) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(7) - (5)].ast) );
    stmt->Else( (yysemantic_stack_[(7) - (7)].ast) );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1572 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    stmt->Then( (yysemantic_stack_[(5) - (5)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1581 "grammar/grammar.yy"
    {
    IFStmt *stmt = ManagedHandle::Retain<IFStmt>();
    stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    stmt->Then( (yysemantic_stack_[(3) - (3)].ast) );
    stmt->Else( GetEmptyNode() );
    (yyval.if_stmt) = stmt;
  }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1593 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kDoWhile ) );
    iter->Line( (yysemantic_stack_[(7) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(7) - (5)].expression) );
    iter->AddChild( (yysemantic_stack_[(7) - (2)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1601 "grammar/grammar.yy"
    {
    IterationStmt* iter = ManagedHandle::Retain( new IterationStmt( AstNode::kWhile ) );
    iter->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    iter->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    iter->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.iteration_stmt) = iter;
  }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1609 "grammar/grammar.yy"
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

  case 157:

/* Line 690 of lalr1.cc  */
#line 1621 "grammar/grammar.yy"
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

  case 158:

/* Line 690 of lalr1.cc  */
#line 1633 "grammar/grammar.yy"
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

  case 159:

/* Line 690 of lalr1.cc  */
#line 1644 "grammar/grammar.yy"
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

  case 160:

/* Line 690 of lalr1.cc  */
#line 1656 "grammar/grammar.yy"
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

  case 161:

/* Line 690 of lalr1.cc  */
#line 1667 "grammar/grammar.yy"
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

  case 162:

/* Line 690 of lalr1.cc  */
#line 1681 "grammar/grammar.yy"
    {
    ContinueStmt *cont = ManagedHandle::Retain<ContinueStmt>();
    cont->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    cont->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.continue_stmt) = cont;
  }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1691 "grammar/grammar.yy"
    {
    BreakStmt *break_stmt = ManagedHandle::Retain<BreakStmt>();
    break_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    break_stmt->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.break_stmt) = break_stmt;
  }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1701 "grammar/grammar.yy"
    {
    ReturnStmt *ret = ManagedHandle::Retain<ReturnStmt>();
    ret->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    ret->AddChild( (yysemantic_stack_[(3) - (2)].ast) );
    (yyval.return_stmt) = ret;
  }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1711 "grammar/grammar.yy"
    {
    WithStmt *with_stmt = ManagedHandle::Retain<WithStmt>();
    with_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    with_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    with_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.with_stmt) = with_stmt;
  }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1722 "grammar/grammar.yy"
    {
    SwitchStmt *switch_stmt = ManagedHandle::Retain<SwitchStmt>();
    switch_stmt->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    switch_stmt->Exp( (yysemantic_stack_[(5) - (3)].expression) );
    switch_stmt->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.switch_stmt) = switch_stmt;
  }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1733 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list);
  }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1737 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(5) - (2)].node_list)->AddChild( (yysemantic_stack_[(5) - (3)].case_clause) );
    (yysemantic_stack_[(5) - (2)].node_list)->Append( (yysemantic_stack_[(5) - (4)].node_list) );    
    (yyval.ast) = (yysemantic_stack_[(5) - (2)].node_list);
  }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1746 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].case_clause) );
    (yyval.node_list) = list;
  }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1752 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].node_list)->AddChild( (yysemantic_stack_[(2) - (2)].case_clause) );
    (yyval.node_list) = (yysemantic_stack_[(2) - (1)].node_list);
  }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1760 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    clause->Exp( (yysemantic_stack_[(4) - (2)].expression) );
    clause->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1771 "grammar/grammar.yy"
    {
    CaseClause *clause = ManagedHandle::Retain<CaseClause> ();
    clause->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    clause->Exp( GetEmptyNode() );
    clause->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.case_clause) = clause;
  }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1782 "grammar/grammar.yy"
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

  case 174:

/* Line 690 of lalr1.cc  */
#line 1795 "grammar/grammar.yy"
    {
    ThrowStmt* throw_stmt = ManagedHandle::Retain<ThrowStmt>();
    throw_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    throw_stmt->Exp( (yysemantic_stack_[(3) - (2)].expression) );
    (yyval.throw_stmt) = throw_stmt;
  }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1805 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(3) - (3)].ast) );
    try_stmt->Finally( GetEmptyNode() );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1814 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(3) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(3) - (2)].block) );
    try_stmt->Catch( GetEmptyNode() );
    try_stmt->Finally( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1823 "grammar/grammar.yy"
    {
    TryStmt* try_stmt = ManagedHandle::Retain<TryStmt>();
    try_stmt->Line( (yysemantic_stack_[(4) - (1)].info)->GetLineNumber() );
    try_stmt->AddChild( (yysemantic_stack_[(4) - (2)].block) );
    try_stmt->Catch( (yysemantic_stack_[(4) - (3)].ast) );
    try_stmt->Finally( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.try_stmt) = try_stmt;
  }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1835 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(5) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(5) - (3)].info) );
    value->AddChild( (yysemantic_stack_[(5) - (5)].block) );
    (yyval.ast) = value;
  }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1846 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (2)].block)->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    (yyval.ast) = (yysemantic_stack_[(2) - (2)].block);
  }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1853 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1854 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1858 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1859 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1863 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1864 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1868 "grammar/grammar.yy"
    { (yyval.node_list) = ManagedHandle::Retain<NodeList>(); }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1869 "grammar/grammar.yy"
    { (yyval.node_list) = (yysemantic_stack_[(1) - (1)].node_list); }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1873 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1874 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1876 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1883 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1890 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kRegExp ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1900 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kNull ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1910 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kTrue ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1917 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kFalse ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1927 "grammar/grammar.yy"
    { 
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kThis ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1934 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kIdentifier ) );
    value->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    value->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.ast) = value;
  }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1940 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1941 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1942 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1944 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (2)].expression)->Paren ();
    (yyval.ast) = (yysemantic_stack_[(3) - (2)].expression);
  }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1952 "grammar/grammar.yy"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 1962 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    value->Line( (yysemantic_stack_[(3) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(3) - (2)].node_list) );
    (yyval.ast) = value;
  }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1969 "grammar/grammar.yy"
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

  case 205:

/* Line 690 of lalr1.cc  */
#line 1979 "grammar/grammar.yy"
    {
    ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kArrayComp ) );
    value->AddChild( (yysemantic_stack_[(4) - (2)].node_list) );
    value->Line( (yysemantic_stack_[(4) - (2)].node_list)->Line() );
    value->AddChild( (yysemantic_stack_[(4) - (3)].ast) );
    (yyval.ast) = value;
  }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1990 "grammar/grammar.yy"
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

  case 207:

/* Line 690 of lalr1.cc  */
#line 2000 "grammar/grammar.yy"
    {
    if ( (yysemantic_stack_[(4) - (3)].opt) ) {
      (yysemantic_stack_[(4) - (1)].node_list)->AddChild( GetEmptyNode() );
    }
    (yysemantic_stack_[(4) - (1)].node_list)->AddChild( (yysemantic_stack_[(4) - (4)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(4) - (1)].node_list);
  }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2017 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(2) - (1)].ast)->After( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
  }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2025 "grammar/grammar.yy"
    {
    IterationStmt *for_in = ManagedHandle::Retain( new IterationStmt( AstNode::kForIn ) );
    for_in->Exp( (yysemantic_stack_[(6) - (3)].ast) );
    (yysemantic_stack_[(6) - (3)].ast)->After( (yysemantic_stack_[(6) - (5)].expression) );
    (yyval.ast) = for_in;
  }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2032 "grammar/grammar.yy"
    {
    IterationStmt *for_each = ManagedHandle::Retain( new IterationStmt( AstNode::kForEach ) );
    for_each->Exp( (yysemantic_stack_[(7) - (4)].ast) );
    (yysemantic_stack_[(7) - (4)].ast)->After( (yysemantic_stack_[(7) - (6)].expression) );
    (yyval.ast) = for_each;
  }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2041 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2043 "grammar/grammar.yy"
    {
    IFStmt *if_stmt = ManagedHandle::Retain<IFStmt> ();
    if_stmt->Exp( (yysemantic_stack_[(4) - (3)].expression) );
    (yyval.ast) = if_stmt;
  }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2052 "grammar/grammar.yy"
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

  case 216:

/* Line 690 of lalr1.cc  */
#line 2066 "grammar/grammar.yy"
    {
  (yyval.ast) = GetEmptyNode();
}
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2070 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
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
#line 2081 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(3) - (1)].value_node) );
    list->Line( (yysemantic_stack_[(3) - (1)].value_node)->Line() );
    (yysemantic_stack_[(3) - (1)].value_node)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.ast) = list;
  }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2090 "grammar/grammar.yy"
    {
    tracer->SetState( ParserTracer::kObjectLiteralEnd );
    (yysemantic_stack_[(5) - (1)].ast)->AddChild( (yysemantic_stack_[(5) - (3)].value_node) );
    (yysemantic_stack_[(5) - (3)].value_node)->AddChild( (yysemantic_stack_[(5) - (5)].ast) );
    (yyval.ast) = (yysemantic_stack_[(5) - (1)].ast);
  }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2100 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kProperty ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2107 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kString ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2114 "grammar/grammar.yy"
    {
    ValueNode* node = ManagedHandle::Retain( new ValueNode( ValueNode::kNumeric ) );
    node->Line( (yysemantic_stack_[(1) - (1)].info)->GetLineNumber() );
    node->Symbol( (yysemantic_stack_[(1) - (1)].info) );
    (yyval.value_node) = node;
  }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2124 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2128 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].function);
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2132 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(1) - (1)].cls)->Decl( false );
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].cls);
  }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2137 "grammar/grammar.yy"
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
#line 2150 "grammar/grammar.yy"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2162 "grammar/grammar.yy"
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

  case 230:

/* Line 690 of lalr1.cc  */
#line 2177 "grammar/grammar.yy"
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2192 "grammar/grammar.yy"
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

  case 232:

/* Line 690 of lalr1.cc  */
#line 2207 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2209 "grammar/grammar.yy"
    {
    NewExp* ret = ManagedHandle::Retain<NewExp>();
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Constructor( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2219 "grammar/grammar.yy"
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

  case 235:

/* Line 690 of lalr1.cc  */
#line 2232 "grammar/grammar.yy"
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

  case 236:

/* Line 690 of lalr1.cc  */
#line 2245 "grammar/grammar.yy"
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

  case 237:

/* Line 690 of lalr1.cc  */
#line 2258 "grammar/grammar.yy"
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

  case 238:

/* Line 690 of lalr1.cc  */
#line 2275 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2276 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].node_list); }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2281 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2287 "grammar/grammar.yy"
    {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.node_list) = list;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2293 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2298 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].node_list)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.node_list) = (yysemantic_stack_[(3) - (1)].node_list);
  }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2305 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2306 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2307 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].value_node); }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2308 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(3) - (2)].value_node); }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2313 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2317 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2324 "grammar/grammar.yy"
    {
    PostfixExp *ret = ManagedHandle::Retain ( new PostfixExp ( (yysemantic_stack_[(2) - (2)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (1)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2333 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2335 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2342 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2349 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2356 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2363 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( (yysemantic_stack_[(2) - (1)].info)->GetType() ) );
    ret->Line( (yysemantic_stack_[(2) - (1)].info)->GetLineNumber() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2370 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '+' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2377 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '-' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2384 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '~' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2391 "grammar/grammar.yy"
    {
    UnaryExp *ret = ManagedHandle::Retain ( new UnaryExp ( '!' ) );
    ret->Line( (yysemantic_stack_[(2) - (2)].ast)->Line() );
    ret->Exp( (yysemantic_stack_[(2) - (2)].ast) );
    (yyval.ast) = ret;
  }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2400 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2402 "grammar/grammar.yy"
    {
    BINARY_ACTION('*',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2406 "grammar/grammar.yy"
    {
    BINARY_ACTION('/',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2410 "grammar/grammar.yy"
    {
    BINARY_ACTION('%',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2416 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2418 "grammar/grammar.yy"
    {
    BINARY_ACTION('+',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2422 "grammar/grammar.yy"
    {
    BINARY_ACTION('-',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2428 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2430 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2434 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2438 "grammar/grammar.yy"
    {
    BINARY_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2444 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2446 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2450 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2454 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2458 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2462 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2466 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2472 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2474 "grammar/grammar.yy"
    {
    COMPARE_ACTION('<',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2478 "grammar/grammar.yy"
    {
    COMPARE_ACTION('>',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2482 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2486 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2490 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2496 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2498 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2502 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2506 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2510 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2516 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2518 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2522 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2526 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2530 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2536 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2538 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2544 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2546 "grammar/grammar.yy"
    {
    BINARY_ACTION('&',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2552 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2554 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2560 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);}
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2562 "grammar/grammar.yy"
    {
    BINARY_ACTION('^',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2568 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2570 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2576 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2578 "grammar/grammar.yy"
    {
    BINARY_ACTION('|',(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2584 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2586 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2592 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2594 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2600 "grammar/grammar.yy"
    {(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2602 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2608 "grammar/grammar.yy"
    { (yyval.ast) =(yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2610 "grammar/grammar.yy"
    {
    COMPARE_ACTION((yysemantic_stack_[(3) - (2)].info)->GetType(),(yysemantic_stack_[(3) - (1)].ast),(yysemantic_stack_[(3) - (3)].ast),(yyval.ast));
  }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2616 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2618 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2626 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast); }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2628 "grammar/grammar.yy"
    {
    ConditionalExp *ret = ManagedHandle::Retain ( new ConditionalExp ( (yysemantic_stack_[(5) - (1)].ast) , (yysemantic_stack_[(5) - (3)].ast) , (yysemantic_stack_[(5) - (5)].ast) ) );
    ret->Line( (yysemantic_stack_[(5) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2637 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2641 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2651 "grammar/grammar.yy"
    {
    (yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
  }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2655 "grammar/grammar.yy"
    {
    AssignmentExp *ret = ManagedHandle::Retain ( new AssignmentExp( (yysemantic_stack_[(3) - (2)].num) , (yysemantic_stack_[(3) - (1)].ast) , (yysemantic_stack_[(3) - (3)].ast) ) );
    ret->Line( (yysemantic_stack_[(3) - (1)].ast)->Line() );
    (yyval.ast) = ret;
  }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2665 "grammar/grammar.yy"
    { (yyval.num) = '='; }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2666 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2667 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2668 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2669 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2670 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2671 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2672 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2673 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2674 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2675 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2676 "grammar/grammar.yy"
    { (yyval.num) = (yysemantic_stack_[(1) - (1)].info)->GetType(); }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2681 "grammar/grammar.yy"
    {
    Expression *exp = ManagedHandle::Retain<Expression>();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2688 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2696 "grammar/grammar.yy"
    { 
    Expression *exp = ManagedHandle::Retain<Expression> ();
    exp->Line( (yysemantic_stack_[(1) - (1)].ast)->Line() );
    exp->AddChild( (yysemantic_stack_[(1) - (1)].ast) );
    (yyval.expression) = exp;
  }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2703 "grammar/grammar.yy"
    {
    (yysemantic_stack_[(3) - (1)].expression)->AddChild( (yysemantic_stack_[(3) - (3)].ast) );
    (yyval.expression) = (yysemantic_stack_[(3) - (1)].expression);
  }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2710 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2711 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2715 "grammar/grammar.yy"
    { (yyval.ast) = GetEmptyNode(); }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2716 "grammar/grammar.yy"
    { (yyval.ast) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2720 "grammar/grammar.yy"
    { (yyval.opt) = false; }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2721 "grammar/grammar.yy"
    { (yyval.opt) = true; }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2725 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2726 "grammar/grammar.yy"
    {(yyval.num) = ';';}
    break;



/* Line 690 of lalr1.cc  */
#line 4168 "grammar/grammar.tab.cc"
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
  const short int ParserImplementation::yypact_ninf_ = -540;
  const short int
  ParserImplementation::yypact_[] =
  {
      -540,   107,  1774,  -540,  3008,  3008,  3008,  3008,  3008,  3008,
    3008,  3008,  3008,  2711,  3126,   122,    16,   176,    16,  1878,
     147,  -540,    21,    66,     1,    93,  3008,   164,  -540,  -540,
     163,  -540,  2810,  -540,   109,  -540,  3008,  -540,    24,   191,
     124,   127,  -540,    91,   113,   123,   112,    16,   122,   141,
    1146,  -540,  -540,   110,  -540,  -540,  -540,  -540,  1251,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,   159,  -540,
     301,   469,  -540,  -540,   366,    69,   388,    85,   378,   172,
     209,   212,   215,   326,  -540,  -540,    33,  -540,  -540,    16,
    -540,    39,   314,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,   116,    96,    35,  3008,   159,  -540,  -540,    23,
     242,   936,  -540,   -10,   -15,    44,  -540,   108,  -540,  -540,
     -10,   191,   151,   191,     6,   186,   199,  -540,  -540,   277,
    2402,   245,   252,   257,  1878,  3008,   832,   183,   196,   219,
    3008,   235,   313,   -10,  3008,    33,  1355,    36,   108,    44,
    3008,  3008,  3008,  2192,  -540,  2192,  -540,   108,   265,  -540,
     316,  -540,   237,   108,   207,    44,  1878,    49,   167,   286,
       1,   230,   234,  -540,  -540,  1460,   238,    40,   244,    16,
    -540,   707,  3008,   308,  -540,  3008,   332,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,
    3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,
    3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  -540,  -540,
    -540,  -540,   272,    38,   289,  -540,  -540,  -540,   122,    41,
    -540,   249,   352,  -540,  -540,  -540,  -540,   123,  3008,  -540,
    -540,   191,  -540,  -540,  -540,   386,   277,   123,   387,   391,
     223,   321,   388,    73,   395,   419,   427,   429,   443,   347,
    -540,  -540,   481,   329,  3041,   123,   123,  -540,    42,  -540,
      37,    37,    37,    22,  -540,  -540,    46,  -540,   438,    24,
     415,  -540,  -540,    56,    61,  -540,  -540,   349,  2297,  -540,
    -540,   350,  -540,  -540,   216,   254,  -540,   108,    63,  -540,
     108,  -540,  -540,   122,  -540,  -540,  -540,  -540,  -540,   351,
    -540,  -540,  -540,    39,  -540,  3008,    -7,   411,  -540,  -540,
      64,  -540,    28,  -540,    34,  -540,  -540,  -540,  -540,  -540,
     366,   366,    69,    69,    69,   388,   388,   388,   388,   388,
     388,    85,    85,    85,    85,   378,   172,   209,   212,   353,
     215,  -540,   170,  -540,   228,  1041,  3093,   448,  -540,   449,
    -540,   357,  -540,  -540,  3008,   358,   360,   123,   359,    47,
     465,   359,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,
    3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,  3008,
    2506,   223,   475,   364,   365,  1878,  -540,  -540,    84,    84,
      84,  -540,   368,   428,  -540,  -540,  1878,  1878,  -540,  -540,
    -540,   108,  -540,  -540,   108,   137,   145,  -540,   207,  1878,
    -540,   179,   370,   369,  -540,  -540,  -540,   371,  3178,  -540,
    2909,  -540,  -540,  -540,  3008,   272,   377,  -540,  -540,  -540,
    -540,   483,  3093,  3008,   381,    75,   382,   383,   384,  3008,
    -540,  -540,   223,  2506,  3008,  -540,    76,   469,  -540,   388,
     388,   388,   388,   388,    73,    73,    73,    73,   395,   419,
     427,   429,   385,   443,  -540,   379,   497,  3008,   389,   390,
     464,   453,  -540,  -540,  -540,   477,  -540,   394,  -540,  -540,
    -540,  -540,  2192,  -540,  2192,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  1565,  3008,   520,  3178,   331,  -540,  -540,  -540,
     259,  3008,   507,    78,  2192,   -10,  2192,  2192,   399,  -540,
    -540,   397,    79,  1878,  3008,  2610,  3008,    80,  2192,  2192,
    1878,  -540,  3008,   477,  -540,   -49,    24,   402,   403,  1670,
     410,  -540,   147,   147,   147,   503,   412,  -540,  3055,  -540,
    -540,  -540,  -540,  -540,  -540,   -10,  -540,   159,  -540,  -540,
      81,  3008,  -540,   414,  -540,   418,   430,  2192,  2610,  1878,
    -540,  -540,   434,    82,  1878,   436,   437,  -540,    17,  -540,
     417,  -540,   477,  -540,  -540,  -540,  -540,   -10,   -10,   -10,
     123,  -540,  -540,  -540,  -540,    83,  -540,  -540,  -540,   439,
     441,  -540,  1878,  1878,  -540,  -540,  -540,  1670,  1670,   440,
    -540,  -540,  -540,   442,  -540,  -540,  1878,  -540,  -540,  -540,
    -540,  -540,   445,  -540,  1982,   188,  -540,  -540,  -540,   447,
    2087,  -540,  -540,  -540,  -540
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  ParserImplementation::yydefact_[] =
  {
         2,     0,     5,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   343,    78,     6,    78,     5,
       5,   195,     0,    78,   197,     0,     5,     0,   193,   190,
       0,   192,   341,   191,     0,   196,     5,   194,     0,     0,
       0,     0,   346,     0,     0,    76,     0,    78,   343,     0,
       5,   345,   226,     0,   100,    69,   225,    37,     3,    62,
      68,    80,    84,    83,    81,    82,    99,    85,    86,   246,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    95,
      97,    98,   198,   188,   189,   224,   199,   200,   232,   244,
     245,   248,   251,   261,   265,   268,   272,   285,   295,   299,
     303,   307,   311,   315,   319,   335,     0,   149,     6,    78,
     197,   216,   248,   257,   258,   260,   259,   252,   253,   254,
     256,   255,     0,     0,     0,     5,   232,   233,   208,     0,
     344,     5,    79,     0,   182,     0,   121,   182,   129,   130,
       0,     6,     0,     6,   182,     0,     0,    29,   104,    27,
       5,     0,     0,     0,     5,     5,     5,     0,     0,     0,
       5,     0,   342,     0,     5,     0,     5,     0,   182,     0,
       5,     5,     5,     5,    45,     5,    44,   182,     0,    77,
      47,    48,     0,   182,     0,     0,     5,     0,     0,     0,
     197,   190,   191,   101,   111,     5,     0,   218,     0,    78,
      63,     5,     5,     0,   234,     5,     0,   235,   331,   328,
     330,   329,   334,   333,   324,   326,   325,   332,   327,   250,
     249,   323,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,   150,   221,
     223,   222,   141,     0,     0,   247,   201,   231,   343,     0,
     203,     0,   213,   209,   202,   206,   163,    76,     5,   183,
     125,     0,   114,   126,   162,     0,    28,    76,     0,     0,
       0,   248,   279,   290,   297,   301,   305,   309,   313,   317,
     321,   337,   340,     0,     5,    76,    76,   173,     0,   153,
       0,     0,     0,     0,   229,   164,     0,   174,     0,     0,
     175,   176,   113,     0,     0,    46,    75,     0,     5,    66,
      74,     0,    50,    56,    54,     0,    51,   182,     0,   117,
       0,   115,   103,   343,   132,   134,   131,   135,   136,     0,
     102,   112,   215,     0,   217,     5,     7,     0,   238,   241,
       0,   240,     0,   230,     0,   237,   320,   262,   263,   264,
     266,   267,   271,   270,   269,   274,   273,   277,   278,   275,
     276,   289,   287,   286,   288,   296,   300,   304,   308,     0,
     312,   336,     0,   140,     0,     5,     5,     0,   205,     0,
     210,     0,   147,   122,     5,     0,     0,    76,   184,     0,
     123,   184,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     0,     0,     0,     0,     5,   109,   108,     0,     0,
       0,   228,     0,     0,   179,   177,     5,     5,    39,    67,
      41,   182,    49,    55,   182,     0,     0,   119,     0,     5,
     120,     0,     0,     0,   219,     9,    10,     0,     5,    57,
       5,   239,   227,   236,     5,   145,     0,   142,   143,   204,
     207,     0,     5,     5,     0,     0,     0,     0,     0,     5,
     185,   127,     0,     5,     5,   128,     0,   248,   322,   281,
     280,   284,   282,   283,   294,   292,   291,   293,   298,   302,
     306,   310,     0,   314,   338,     0,     0,     5,     0,     0,
     152,     0,   105,   107,   106,   186,   166,     0,   155,   165,
      52,    53,     5,    42,     5,    43,   118,   116,   137,   133,
     138,   139,     5,     5,     5,     5,     8,   243,   242,   316,
       0,     5,     0,     0,     5,     0,     5,     5,     0,   148,
     124,     0,     0,     5,     5,     5,     5,     0,     5,     5,
       5,   110,     5,   187,   169,     0,     0,     0,     0,   181,
       0,   220,     5,     5,     5,     0,     0,    12,     5,    14,
      16,    18,    19,    20,    21,     0,    17,     0,   144,   146,
       0,     5,   214,     0,   154,     0,     0,     5,     5,     5,
     158,   318,     0,     0,     5,     0,     0,   151,     0,   170,
       0,   167,   186,   178,    38,    40,    33,     0,     0,     0,
      76,     4,    15,    23,   211,     0,    35,    30,    31,     0,
       0,   159,     5,     5,   160,    34,    36,   180,   180,     0,
      26,    25,    24,     0,   212,    32,     5,   156,   161,   171,
     172,   168,     0,   157,     5,     5,    72,    73,    71,     0,
       5,    64,    70,    22,    65
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yypgoto_[] =
  {
      -540,  -540,  -540,   -18,  -540,  -540,  -540,  -540,  -540,  -540,
       9,  -540,  -540,  -540,  -539,  -511,    -8,  -540,    -2,  -540,
    -540,   -31,  -540,  -540,  -540,  -164,   117,  -540,  -152,  -540,
    -540,  -540,   530,   -71,   274,  -256,    11,    -1,  -168,  -540,
     -35,  -540,  -540,  -540,    95,    13,  -540,  -540,  -540,   142,
      92,  -540,   322,  -330,   -23,   -11,  -540,   581,  -540,   270,
    -540,  -442,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,    43,  -540,  -540,  -540,  -540,  -540,   285,  -229,
    -129,   201,    -5,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -103,     3,   587,  -540,
      32,  -540,   446,  -540,    65,   200,   240,   312,   204,    55,
     363,   192,   372,   194,   373,   197,   374,   203,   375,   205,
    -540,  -540,  -540,  -540,  -121,  -373,   524,    29,  -540,  -540,
    -387,   -33,   -46
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ParserImplementation::yydefgoto_[] =
  {
        -1,     1,     2,    52,    53,   457,   458,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,    54,   316,    56,
      57,   174,   179,   180,   442,   181,   349,   659,   317,    58,
     660,   318,    59,   661,   319,   182,   153,   194,    61,    62,
      63,    64,    65,    66,   428,   569,    67,    68,   328,   329,
     149,   399,   136,   400,   137,    69,   187,   139,   253,   269,
     480,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     516,   563,   564,   612,    79,    80,    81,   310,   311,   570,
     270,   481,   565,    82,    83,    84,    85,    86,   129,   130,
     261,   262,   390,    87,   196,   197,   198,    88,    89,    90,
     257,   350,    91,    92,    93,    94,    95,    96,    97,   283,
      98,   284,    99,   285,   100,   286,   101,   287,   102,   288,
     103,   289,   104,   290,   105,   291,   403,   106,   292,   293,
     163,   131,   107
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int ParserImplementation::yytable_ninf_ = -342;
  const short int
  ParserImplementation::yytable_[] =
  {
        55,    60,   147,   167,   159,   320,   138,   320,   273,   138,
     265,   391,   148,   176,   610,   188,   138,   126,   142,   254,
     247,   395,   183,   321,   337,   247,   258,   133,   138,   140,
     488,   247,   267,   505,   138,   138,   247,   247,   247,   423,
     424,   382,   124,   343,   502,   247,   504,   271,   322,   247,
     482,   315,   333,   277,   326,   156,    55,    60,   186,   247,
     248,   162,   455,   195,   247,   165,   448,   460,   150,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   247,   247,
     351,   247,   247,   247,   247,   247,   247,   266,   386,   272,
     611,   506,   586,   308,   274,   132,   551,   259,   404,   405,
     406,   356,   407,    42,   226,   227,   549,     3,   309,   135,
     231,   232,   233,   234,   235,   656,   426,   305,   249,   307,
     204,   656,   207,   312,   379,   128,   381,   268,   250,   456,
     138,   169,   138,    51,   511,   427,   586,   251,   185,   331,
     155,   478,   154,   657,   151,   152,    42,   392,   268,   657,
     320,   408,   550,   297,   124,   299,   164,    42,   637,   184,
     443,   330,   166,   236,   387,   338,   431,   260,   602,   199,
     383,   170,   462,   138,   171,   256,    51,   138,   463,   195,
     334,   601,   425,   344,   298,   332,   432,    51,   189,   303,
     483,   168,   241,   306,   341,   252,   436,    42,   447,   313,
     314,   437,   177,   449,   461,   250,   201,   143,   202,   203,
     346,   630,   160,   161,   251,   545,   553,   172,   592,   599,
     604,   624,   633,   644,   454,   385,   144,    51,   242,   173,
     243,   352,   244,   135,   354,   276,   255,   160,   161,   172,
     453,    48,   122,   157,   183,   263,   335,   178,   143,   465,
     268,   175,    48,   122,   183,   134,   138,   401,   528,   250,
     138,   275,   158,   172,   470,   278,   138,   144,   251,   138,
     168,   172,   183,   183,   434,   522,    48,   122,   279,   466,
     271,   145,   146,   524,   138,   138,   327,   530,   357,   358,
     359,   178,   294,    48,   122,   441,    48,   122,   336,   295,
     451,   444,   398,   178,   296,    48,   122,   467,    48,   122,
     529,   300,   520,   138,   304,   521,   247,    48,   122,   324,
      48,   122,   145,   146,   301,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    48,   122,   588,   538,
     178,   245,   246,   539,   323,    48,   122,   302,   201,   402,
     205,   206,    48,   122,   320,   325,   320,    48,   122,   219,
     220,   468,   417,   418,   643,   339,   219,   220,   445,   446,
     567,  -223,   568,   138,   183,  -222,   320,   342,   320,   320,
     202,   203,   512,   513,   514,   345,   138,   353,    48,   122,
     320,   320,   593,   388,   595,   596,   429,   430,   401,   237,
     238,   239,   240,   223,   224,   225,   605,   606,   649,   650,
     138,   355,   571,  -221,   523,   525,   409,   410,   411,   412,
     228,   229,   230,   475,   510,   330,   360,   361,   531,   320,
     384,   486,   389,   394,   396,   518,   519,   138,   397,   413,
     138,   371,   372,   373,   374,   629,   414,   415,   527,   162,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   401,
     416,   536,   282,   221,   494,   495,   496,   497,   362,   363,
     364,   138,   420,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   419,   433,   662,   309,   438,   440,
     459,   452,   662,   484,   464,   472,   473,   474,   476,   594,
     477,   479,   543,   507,   508,   509,   515,   517,   532,   534,
     533,   541,   162,   552,   219,   220,   147,   589,   540,   544,
     546,   547,   555,   138,   548,   556,   554,   558,   559,   138,
     560,   613,   561,   562,   566,   591,   557,   597,   587,   623,
     598,   614,   615,   365,   366,   367,   368,   369,   370,   616,
     620,   621,   600,   626,   147,   147,   147,   627,   638,   607,
     147,   138,   138,   138,   617,   618,   619,   138,   341,   628,
     590,   640,   641,   642,   632,   635,   636,   537,   645,   651,
     143,   646,   652,   654,   162,   603,   663,   622,   200,   664,
     526,   608,   439,   393,   123,   435,   281,   183,   631,   144,
     450,   127,   485,   634,   375,   498,   609,   639,   499,   138,
     572,   221,   500,   573,   376,   222,   377,   574,   378,   501,
     625,   380,     0,   503,     0,     0,     0,   162,     0,     0,
       0,   647,   648,    42,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,   138,   653,     0,   617,     0,    48,
     122,     0,   658,   575,   145,   146,     0,     0,   658,   -11,
       0,     0,     0,    51,     0,     0,     0,     0,     0,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,   489,   490,   491,   492,
     493,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,     0,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     4,     5,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,   109,     0,     0,   110,     0,     0,     0,
       0,   282,     0,     0,     0,    28,    29,    30,     0,     0,
       0,    31,     0,     0,     0,    33,     0,     0,     0,    35,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,   347,   471,     0,     0,   247,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   348,     0,   487,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   487,   112,   487,   282,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   141,    18,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     0,    22,     0,   109,     0,
       0,    24,    25,    26,     0,    27,     0,     0,   542,     0,
      28,    29,    30,     0,     0,   487,    31,    32,     0,     0,
      33,     0,    34,     0,    35,    36,     0,     0,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
       0,     0,     0,     0,    46,     0,     0,    47,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     4,     5,     0,     0,    51,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     487,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,   109,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     4,     5,     0,     0,
     264,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     4,     5,     0,     0,   469,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   141,    18,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     0,
      22,     0,   109,     0,     0,   190,    25,    26,     0,    27,
       0,     0,     0,     0,    28,   191,    30,     0,     0,     0,
      31,    32,     0,     0,   192,     0,    34,     0,    35,    36,
       0,     0,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    49,    50,   193,     4,     5,     0,    51,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
      -5,    17,    18,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,     0,    23,     0,     0,
      24,    25,    26,     0,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,    33,
       0,    34,     0,    35,    36,     0,     0,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    49,    50,
       4,     5,     0,     0,    51,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   141,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,   109,     0,     0,    24,    25,    26,     0,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,    33,     0,    34,     0,    35,    36,     0,
       0,    37,    38,    39,     0,    40,    41,     0,    42,    43,
      44,     0,    45,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,    49,    50,   193,     4,     5,     0,    51,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     141,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,   109,     0,     0,    24,
      25,    26,     0,    27,     0,     0,     0,     0,    28,    29,
      30,     0,     0,     0,    31,    32,     0,     0,    33,     0,
      34,     0,    35,    36,     0,     0,    37,    38,    39,     0,
      40,    41,     0,    42,    43,    44,     0,    45,     0,     0,
       0,     0,    46,     0,     0,    47,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    49,    50,   340,
       4,     5,     0,    51,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   141,    18,     0,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,     0,    22,
       0,   109,     0,     0,    24,    25,    26,     0,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,    33,     0,    34,     0,    35,    36,     0,
       0,    37,    38,    39,     0,    40,    41,     0,    42,    43,
      44,     0,    45,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,    49,    50,  -180,     4,     5,     0,    51,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    -5,
     141,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     0,    22,     0,   109,     0,     0,    24,
      25,    26,     0,    27,     0,     0,     0,     0,    28,    29,
      30,     0,     0,     0,    31,    32,     0,     0,    33,     0,
      34,     0,    35,    36,     0,     0,    37,    38,    39,     0,
      40,    41,     0,    42,    43,    44,     0,    45,     0,     0,
       0,     0,    46,     0,     0,    47,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    49,    50,     4,
       5,     0,     0,    51,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     0,    22,     0,
      23,     0,     0,    24,    25,    26,     0,    27,     0,     0,
       0,     0,    28,    29,    30,     0,     0,     0,    31,    32,
       0,     0,    33,     0,    34,     0,    35,    36,     0,     0,
      37,    38,    39,     0,    40,    41,     0,    42,    43,    44,
       0,    45,     0,     0,     0,     0,    46,     0,     0,    47,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    49,    50,     4,     5,     0,     0,    51,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,   141,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     0,    22,     0,   109,     0,     0,    24,    25,    26,
       0,    27,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,    31,    32,     0,     0,    33,     0,    34,     0,
      35,    36,     0,     0,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,    45,     0,     0,     0,     0,
      46,     0,     0,    47,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,    49,    50,     4,     5,     0,
       0,    51,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,    26,     0,    27,     0,     0,     0,     0,
      28,    29,   655,     0,     0,   573,    31,    32,     0,     0,
      33,     0,    34,     0,    35,    36,     0,     0,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    49,
      50,   -58,     4,     5,     0,    51,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,    26,     0,
      27,     0,     0,     0,     0,    28,    29,   655,     0,     0,
     573,    31,    32,     0,     0,    33,     0,    34,     0,    35,
      36,     0,     0,    37,    38,    39,     0,    40,    41,     0,
      42,    43,    44,     0,    45,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,    49,    50,   -59,     4,     5,     0,
      51,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,    23,     0,
       0,    24,    25,    26,     0,    27,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
      33,     0,    34,     0,    35,    36,     0,     0,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    49,
      50,   -60,     4,     5,     0,    51,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,    25,    26,     0,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,    33,     0,    34,     0,    35,
      36,     0,     0,    37,    38,    39,     0,    40,    41,     0,
      42,    43,    44,     0,    45,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,    49,    50,   -61,     4,     5,     0,
      51,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,    31,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,    37,     0,
     280,     0,     0,     0,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     4,     5,     0,     0,  -339,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,   109,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      31,     0,     0,     0,    33,     0,     0,     0,    35,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     4,     5,     0,     0,  -341,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      30,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,    35,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     4,     5,   111,     0,
    -341,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,   109,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,    31,     0,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,   122,     0,     0,     0,     4,     5,     0,     0,   111,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -5,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,   109,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      30,     0,     0,     0,    31,     0,     0,     0,    33,     0,
       0,     0,    35,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     4,     5,     0,     0,   111,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     0,    31,     0,     0,     0,    33,     0,     0,
       0,    35,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,   347,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     4,     5,     0,     0,   111,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   109,     0,     0,   110,    13,    14,
      15,     0,     0,     0,     0,     0,    28,    29,    30,     0,
       0,   108,    31,     0,     0,     0,    33,     0,     0,     0,
      35,    21,     0,     0,    37,   143,     0,   109,     0,     0,
     110,     0,    43,    44,     0,    45,     0,     0,     0,    28,
      29,    30,     0,     0,   144,    31,     0,    48,     0,    33,
      13,    14,    15,    35,     0,   572,   111,    37,   573,   421,
       0,     0,   574,   108,     0,    43,    44,     0,    45,     0,
       0,     0,     0,    21,     0,     0,     0,     0,    42,   109,
      48,     0,   110,   125,    14,    15,     0,     0,     0,   111,
       0,    28,    29,    30,    48,   122,   108,    31,   575,   145,
     146,    33,     0,     0,   -13,    35,    21,     0,    51,    37,
       0,     0,   109,     0,     0,   110,     0,    43,    44,     0,
      45,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      31,     0,    48,     0,    33,   125,   535,    15,    35,     0,
       0,   111,    37,     0,     0,     0,     0,     0,   108,     0,
      43,    44,     0,    45,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   109,     0,     0,   110,     0,     0,
       0,     0,     0,     0,   111,     0,    28,    29,    30,     0,
       0,     0,    31,     0,     0,     0,    33,     0,     0,     0,
      35,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111
  };

  /* YYCHECK.  */
  const short int
  ParserImplementation::yycheck_[] =
  {
         2,     2,    20,    38,    27,   173,    17,   175,   137,    20,
     131,   267,    20,    44,    63,    48,    27,    14,    19,   122,
       3,   277,    45,   175,   188,     3,     3,    16,    39,    18,
     403,     3,    47,   420,    45,    46,     3,     3,     3,   295,
     296,     3,    13,     3,   417,     3,   419,     3,   177,     3,
       3,   172,     3,    47,   183,    26,    58,    58,    47,     3,
     106,    32,    69,    50,     3,    36,     3,     3,    47,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
     201,     3,     3,     3,     3,     3,     3,   133,    47,   135,
     139,   421,   534,    57,   140,    79,   483,    74,    25,    26,
      27,   222,    29,   113,    35,    36,   479,     0,    72,    17,
      25,    26,    27,    28,    29,   654,    79,   163,    79,   165,
      88,   660,    90,   169,   245,     3,   247,   142,    89,   136,
     141,    39,   143,   143,    50,    98,   578,    98,    46,   185,
      47,   397,   141,   654,   123,    79,   113,   268,   142,   660,
     318,    78,   482,   154,   125,   156,    47,   113,   141,    47,
     324,   184,   138,    78,   123,   188,   144,   144,   555,    59,
     132,    47,   144,   184,    47,   140,   143,   188,   144,   166,
     131,   554,   140,   143,   155,   186,   140,   143,    47,   160,
     143,    79,    20,   164,   195,    79,   140,   113,   327,   170,
     171,   140,    79,   140,   140,    89,    47,    60,    49,    50,
     199,   598,    49,    50,    98,   140,   140,   126,   140,   140,
     140,   140,   140,   140,   345,   258,    79,   143,    19,   138,
      18,   202,    17,   141,   205,   143,   140,    49,    50,   126,
     343,   129,   130,    79,   267,     3,    79,   124,    60,    79,
     142,   138,   129,   130,   277,    79,   267,   280,    79,    89,
     271,   110,    98,   126,   385,    79,   277,    79,    98,   280,
      79,   126,   295,   296,   309,   138,   129,   130,    79,   382,
       3,   134,   135,   138,   295,   296,    79,   451,   223,   224,
     225,   124,    47,   129,   130,    79,   129,   130,   131,    47,
     333,   324,    79,   124,    47,   129,   130,    79,   129,   130,
     131,   128,   441,   324,    79,   444,     3,   129,   130,     3,
     129,   130,   134,   135,   128,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   129,   130,    79,   460,
     124,    15,    16,   464,    79,   129,   130,   128,    47,    28,
      49,    50,   129,   130,   522,   118,   524,   129,   130,    45,
      46,   384,    15,    16,   620,    79,    45,    46,   114,   115,
     522,   141,   524,   384,   397,   141,   544,   139,   546,   547,
      49,    50,   428,   429,   430,   141,   397,    79,   129,   130,
     558,   559,   544,   144,   546,   547,   301,   302,   421,    21,
      22,    23,    24,    37,    38,    39,   558,   559,   637,   638,
     421,    79,   533,   141,   445,   446,    21,    22,    23,    24,
      32,    33,    34,   394,   425,   448,   226,   227,   451,   597,
     141,   402,    80,    47,    47,   436,   437,   448,    47,    20,
     451,   237,   238,   239,   240,   597,    19,    18,   449,   420,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   482,
      17,   458,   150,   142,   409,   410,   411,   412,   228,   229,
     230,   482,   143,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,    47,   654,    72,   139,   139,
      79,   140,   660,    28,   141,    47,    47,   140,   140,   545,
     140,   142,   473,    28,   140,   140,   138,    79,   138,   138,
     141,    28,   483,   484,    45,    46,   534,   540,   141,   138,
     138,   138,   143,   534,   140,    28,   141,   138,   138,   540,
      66,   566,    79,    56,   140,    28,   507,   138,   535,   585,
     143,   139,   139,   231,   232,   233,   234,   235,   236,   139,
      47,   139,   553,   139,   572,   573,   574,   139,   141,   560,
     578,   572,   573,   574,   572,   573,   574,   578,   569,   139,
     541,   617,   618,   619,   140,   139,   139,   460,   139,   139,
      60,   140,   140,   138,   555,   556,   139,   578,    58,   660,
     448,   562,   318,   271,    13,   310,   150,   620,   599,    79,
     330,    14,   401,   604,   241,   413,   563,   612,   414,   620,
      90,   142,   415,    93,   242,    91,   243,    97,   244,   416,
     591,   246,    -1,   418,    -1,    -1,    -1,   598,    -1,    -1,
      -1,   632,   633,   113,    -1,    -1,    -1,   655,    -1,    -1,
      -1,    -1,    -1,    -1,   655,   646,    -1,   655,    -1,   129,
     130,    -1,   654,   133,   134,   135,    -1,    -1,   660,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     294,    -1,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,   479,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   386,    -1,    -1,     3,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,    -1,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   554,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,   472,    -1,
      88,    89,    90,    -1,    -1,   479,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,    35,    36,    -1,    -1,   143,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
     554,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    35,    36,    -1,    -1,
     144,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    35,    36,    -1,    -1,   144,    40,    41,    42,    43,
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
      -1,    -1,   137,   138,   139,    35,    36,    -1,   143,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      35,    36,    -1,   143,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,
      -1,   106,   107,   108,    -1,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    35,    36,    -1,   143,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,   106,   107,   108,    -1,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    35,
      36,    -1,    -1,   143,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,   102,   103,    -1,    -1,
     106,   107,   108,    -1,   110,   111,    -1,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,    35,    36,    -1,    -1,   143,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
     102,   103,    -1,    -1,   106,   107,   108,    -1,   110,   111,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,    35,    36,    -1,
      -1,   143,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    35,    36,    -1,   143,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,
     103,    -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    35,    36,    -1,
     143,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,    -1,    -1,   106,   107,
     108,    -1,   110,   111,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    35,    36,    -1,   143,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,   102,
     103,    -1,    -1,   106,   107,   108,    -1,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    35,    36,    -1,
     143,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,
     108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    35,    36,    -1,    -1,   143,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    35,    36,    -1,    -1,   143,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   138,    -1,
     140,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,    -1,    -1,    35,    36,    -1,    -1,   138,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   138,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,   138,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    60,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    70,    -1,    -1,   106,    60,    -1,    76,    -1,    -1,
      79,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    79,    94,    -1,   129,    -1,    98,
      47,    48,    49,   102,    -1,    90,   138,   106,    93,   108,
      -1,    -1,    97,    60,    -1,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,   113,    76,
     129,    -1,    79,    47,    48,    49,    -1,    -1,    -1,   138,
      -1,    88,    89,    90,   129,   130,    60,    94,   133,   134,
     135,    98,    -1,    -1,   139,   102,    70,    -1,   143,   106,
      -1,    -1,    76,    -1,    -1,    79,    -1,   114,   115,    -1,
     117,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,   129,    -1,    98,    47,    48,    49,   102,    -1,
      -1,   138,   106,    -1,    -1,    -1,    -1,    -1,    60,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138
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
      47,    47,   126,   138,   166,   138,   166,    79,   124,   167,
     168,   170,   180,   199,    47,   195,   181,   201,   276,    47,
      79,    89,    98,   139,   182,   190,   239,   240,   241,    59,
     177,    47,    49,    50,   245,    49,    50,   245,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    45,
      46,   142,   271,    37,    38,    39,    35,    36,    32,    33,
      34,    25,    26,    27,    28,    29,    78,    21,    22,    23,
      24,    20,    19,    18,    17,    15,    16,     3,   277,    79,
      89,    98,    79,   203,   241,   140,   140,   245,     3,    74,
     144,   235,   236,     3,   144,   269,   277,    47,   142,   204,
     225,     3,   277,   225,   277,   110,   195,    47,    79,    79,
     108,   247,   252,   254,   256,   258,   260,   262,   264,   266,
     268,   270,   273,   274,    47,    47,    47,   182,   272,   182,
     128,   128,   128,   272,    79,   277,   272,   277,    57,    72,
     222,   223,   277,   272,   272,   269,   163,   173,   176,   179,
     183,   173,   225,    79,     3,   118,   225,    79,   193,   194,
     199,   277,   182,     3,   131,    79,   131,   170,   199,    79,
     139,   182,   139,     3,   143,   141,   181,   124,   140,   171,
     246,   269,   272,    79,   272,    79,   269,   249,   249,   249,
     250,   250,   251,   251,   251,   252,   252,   252,   252,   252,
     252,   253,   253,   253,   253,   255,   257,   259,   261,   269,
     263,   269,     3,   132,   141,   276,    47,   123,   144,    80,
     237,   180,   269,   197,    47,   180,    47,    47,    79,   196,
     198,   199,    28,   271,    25,    26,    27,    29,    78,    21,
      22,    23,    24,    20,    19,    18,    17,    15,    16,     3,
     143,   108,   247,   180,   180,   140,    79,    98,   189,   189,
     189,   144,   140,    47,   185,   223,   140,   140,   139,   179,
     139,    79,   169,   170,   199,   114,   115,   225,     3,   140,
     204,   276,   140,   241,   269,    69,   136,   150,   151,    79,
       3,   140,   144,   144,   141,    79,   241,    79,   199,   144,
     269,   247,    47,    47,   140,   272,   140,   140,   180,   142,
     205,   226,     3,   143,    28,   226,   272,   247,   270,   252,
     252,   252,   252,   252,   254,   254,   254,   254,   256,   258,
     260,   262,   270,   264,   270,   275,   198,    28,   140,   140,
     182,    50,   277,   277,   277,   138,   215,    79,   182,   182,
     225,   225,   138,   166,   138,   166,   194,   182,    79,   131,
     170,   199,   138,   141,   138,    48,   242,   171,   269,   269,
     141,    28,   247,   272,   138,   140,   138,   138,   140,   270,
     198,   275,   272,   140,   141,   143,    28,   272,   138,   138,
      66,    79,    56,   216,   217,   227,   140,   173,   173,   190,
     224,   269,    90,    93,    97,   133,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   206,   242,    79,   199,
     272,    28,   140,   173,   277,   173,   173,   138,   143,   140,
     182,   270,   275,   272,   140,   173,   173,   182,   272,   217,
      63,   139,   218,   185,   139,   139,   139,   161,   161,   161,
      47,   139,   155,   277,   140,   272,   139,   139,   139,   173,
     275,   182,   140,   140,   182,   139,   139,   141,   141,   227,
     277,   277,   277,   180,   140,   139,   140,   182,   182,   224,
     224,   139,   140,   182,   138,    90,   159,   160,   163,   172,
     175,   178,   183,   139,   178
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
     165,   165,   165,   165,   165,   165,   166,   167,   167,   167,
     168,   168,   168,   168,   169,   169,   170,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   178,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182,   182,   183,   183,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   185,   185,   186,   187,   188,   188,   188,   189,   189,
     189,   190,   190,   191,   191,   191,   192,   193,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198,   199,
     199,   200,   200,   200,   201,   201,   201,   201,   201,   201,
     202,   203,   203,   203,   203,   203,   203,   204,   205,   206,
     207,   208,   208,   208,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   211,   212,   213,   214,   215,   215,   216,
     216,   217,   218,   219,   220,   221,   221,   221,   222,   223,
     224,   224,   225,   225,   226,   226,   227,   227,   228,   228,
     228,   228,   228,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   232,   232,   232,   232,   233,   233,   234,   234,
     235,   236,   236,   237,   237,   238,   239,   239,   239,   240,
     240,   241,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   243,   243,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   247,   247,   247,   248,   248,
     248,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   250,   250,   250,   251,   251,   251,   252,   252,
     252,   252,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   254,   254,   254,   254,   255,   255,   255,   255,   255,
     256,   256,   256,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   262,   263,   263,   264,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   272,   272,   273,   273,   274,
     274,   275,   275,   276,   276,   277,   277
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ParserImplementation::yyr2_[] =
  {
         0,     2,     0,     2,     7,     0,     1,     0,     2,     1,
       1,     0,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     7,     2,     3,     3,     3,     1,     2,     1,
       7,     7,     8,     7,     8,     8,     8,     1,     7,     4,
       7,     4,     5,     5,     2,     2,     2,     1,     1,     3,
       2,     2,     4,     4,     0,     1,     2,     2,     0,     1,
       0,     1,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     5,     5,     5,     1,     1,
       3,     1,     2,     3,     3,     3,     5,     1,     3,     2,
       2,     1,     3,     1,     3,     2,     2,     2,     2,     1,
       1,     3,     3,     5,     2,     2,     2,     4,     4,     4,
       3,     1,     3,     3,     5,     3,     5,     2,     2,     1,
       2,     7,     5,     3,     7,     5,     9,    10,     7,     8,
       8,     9,     3,     3,     3,     5,     5,     3,     5,     1,
       2,     4,     3,     3,     3,     3,     3,     4,     5,     2,
       0,     1,     0,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     5,     4,     2,     4,     1,     2,
       2,     6,     7,     0,     4,     3,     0,     2,     1,     3,
       5,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       3,     3,     1,     2,     2,     2,     4,     3,     2,     3,
       1,     1,     3,     3,     1,     1,     1,     3,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     5,     1,
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
      -1,   114,   166,    -1,   126,   269,    -1,   168,    -1,   170,
      -1,   168,     3,   169,    -1,    79,   225,    -1,   199,   225,
      -1,   168,     3,    79,   225,    -1,   168,     3,   199,   225,
      -1,    -1,   170,    -1,   124,    79,    -1,   124,    79,    -1,
      -1,   175,    -1,    -1,   176,    -1,   177,    -1,   174,   177,
      -1,   178,    -1,   175,   178,    -1,   179,    -1,   176,   179,
      -1,   182,    -1,   163,    -1,   183,    -1,   163,    -1,   159,
      -1,   160,    -1,   183,    -1,   163,    -1,    -1,   167,    -1,
      -1,    79,    -1,   183,    -1,   186,    -1,   187,    -1,   185,
      -1,   184,    -1,   191,    -1,   192,    -1,   206,    -1,   207,
      -1,   208,    -1,   209,    -1,   210,    -1,   211,    -1,   212,
      -1,   213,    -1,   219,    -1,   214,    -1,   220,    -1,   221,
      -1,   188,    -1,   162,    -1,   138,   139,    -1,   138,   190,
     139,    -1,   125,   181,   182,    -1,    68,   161,    -1,    83,
      79,   128,   189,   277,    -1,    83,   199,   128,   189,   277,
      -1,    83,    98,   128,   189,   277,    -1,    98,    -1,    79,
      -1,   189,    50,    79,    -1,   182,    -1,   190,   182,    -1,
     108,   195,   277,    -1,    60,   195,   277,    -1,   122,   195,
     277,    -1,   122,    47,   193,   140,   182,    -1,   194,    -1,
     193,     3,   194,    -1,    79,   225,    -1,   199,   204,    -1,
     197,    -1,   195,     3,   197,    -1,   198,    -1,   196,     3,
     198,    -1,    79,   225,    -1,   199,   225,    -1,    79,   226,
      -1,   199,   226,    -1,   200,    -1,   202,    -1,   129,   276,
     131,    -1,   129,   201,   131,    -1,   129,   201,     3,   276,
     131,    -1,   276,    79,    -1,   276,   170,    -1,   276,   199,
      -1,   201,     3,   276,    79,    -1,   201,     3,   276,   170,
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
     240,    -1,   241,   141,   269,    -1,   240,     3,   241,   141,
     269,    -1,    79,    -1,    98,    -1,    89,    -1,   231,    -1,
     164,    -1,   148,    -1,   242,    49,   272,   144,    -1,    90,
      49,   272,   144,    -1,    90,    50,    79,    -1,   242,    50,
      79,    -1,    48,   242,   245,    -1,   242,    -1,    48,   243,
      -1,   242,   245,    -1,   244,   245,    -1,   244,    49,   272,
     144,    -1,   244,    50,    79,    -1,    47,   140,    -1,    47,
     246,   140,    -1,   269,    -1,   171,    -1,   246,     3,   269,
      -1,   246,     3,   171,    -1,   243,    -1,   244,    -1,   200,
      -1,    47,   202,   140,    -1,   247,    -1,   247,    46,    -1,
     247,    45,    -1,   248,    -1,    42,   249,    -1,    43,   249,
      -1,    44,   249,    -1,    46,   249,    -1,    45,   249,    -1,
      35,   249,    -1,    36,   249,    -1,    41,   249,    -1,    40,
     249,    -1,   249,    -1,   250,    37,   249,    -1,   250,    38,
     249,    -1,   250,    39,   249,    -1,   250,    -1,   251,    35,
     250,    -1,   251,    36,   250,    -1,   251,    -1,   252,    34,
     251,    -1,   252,    33,   251,    -1,   252,    32,   251,    -1,
     252,    -1,   253,    26,   252,    -1,   253,    25,   252,    -1,
     253,    29,   252,    -1,   253,    78,   252,    -1,   253,    27,
     252,    -1,   253,    28,   252,    -1,   252,    -1,   254,    26,
     252,    -1,   254,    25,   252,    -1,   254,    29,   252,    -1,
     254,    78,   252,    -1,   254,    27,   252,    -1,   253,    -1,
     255,    23,   253,    -1,   255,    22,   253,    -1,   255,    24,
     253,    -1,   255,    21,   253,    -1,   254,    -1,   256,    23,
     254,    -1,   256,    22,   254,    -1,   256,    24,   254,    -1,
     256,    21,   254,    -1,   255,    -1,   257,    20,   255,    -1,
     256,    -1,   258,    20,   256,    -1,   257,    -1,   259,    19,
     257,    -1,   258,    -1,   260,    19,   258,    -1,   259,    -1,
     261,    18,   259,    -1,   260,    -1,   262,    18,   260,    -1,
     261,    -1,   263,    17,   261,    -1,   262,    -1,   264,    17,
     262,    -1,   263,    -1,   265,    16,   263,    -1,   264,    -1,
     266,    16,   264,    -1,   265,    -1,   265,    15,   269,   141,
     269,    -1,   266,    -1,   266,    15,   270,   141,   270,    -1,
     267,    -1,   247,   271,   269,    -1,   268,    -1,   247,   271,
     270,    -1,   142,    -1,    10,    -1,    12,    -1,    11,    -1,
      14,    -1,     5,    -1,     7,    -1,     6,    -1,     4,    -1,
      13,    -1,     9,    -1,     8,    -1,   269,    -1,   272,     3,
     269,    -1,   270,    -1,   273,     3,   270,    -1,    -1,   273,
      -1,    -1,   272,    -1,    -1,   234,    -1,   143,    -1,   113,
      -1
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
     153,   161,   166,   172,   178,   181,   184,   187,   189,   191,
     195,   198,   201,   206,   211,   212,   214,   217,   220,   221,
     223,   224,   226,   228,   231,   233,   236,   238,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   258,   260,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     303,   305,   308,   312,   316,   319,   325,   331,   337,   339,
     341,   345,   347,   350,   354,   358,   362,   368,   370,   374,
     377,   380,   382,   386,   388,   392,   395,   398,   401,   404,
     406,   408,   412,   416,   422,   425,   428,   431,   436,   441,
     446,   450,   452,   456,   460,   466,   470,   476,   479,   482,
     484,   487,   495,   501,   505,   513,   519,   529,   540,   548,
     557,   566,   576,   580,   584,   588,   594,   600,   604,   610,
     612,   615,   620,   624,   628,   632,   636,   640,   645,   651,
     654,   655,   657,   658,   660,   661,   663,   664,   666,   668,
     670,   672,   674,   676,   678,   680,   682,   684,   686,   688,
     690,   692,   696,   700,   704,   710,   715,   718,   723,   725,
     728,   731,   738,   746,   747,   752,   756,   757,   760,   762,
     766,   772,   774,   776,   778,   780,   782,   784,   789,   794,
     798,   802,   806,   808,   811,   814,   817,   822,   826,   829,
     833,   835,   837,   841,   845,   847,   849,   851,   855,   857,
     860,   863,   865,   868,   871,   874,   877,   880,   883,   886,
     889,   892,   894,   898,   902,   906,   908,   912,   916,   918,
     922,   926,   930,   932,   936,   940,   944,   948,   952,   956,
     958,   962,   966,   970,   974,   978,   980,   984,   988,   992,
     996,   998,  1002,  1006,  1010,  1014,  1016,  1020,  1022,  1026,
    1028,  1032,  1034,  1038,  1040,  1044,  1046,  1050,  1052,  1056,
    1058,  1062,  1064,  1068,  1070,  1074,  1076,  1082,  1084,  1090,
    1092,  1096,  1098,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1122,  1124,  1126,  1128,  1132,  1134,  1138,
    1139,  1141,  1142,  1144,  1145,  1147,  1149
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ParserImplementation::yyrline_[] =
  {
         0,   367,   367,   367,   378,   389,   390,   395,   396,   411,
     412,   417,   418,   422,   427,   448,   472,   478,   479,   480,
     481,   482,   487,   502,   512,   522,   531,   541,   542,   548,
     549,   560,   572,   587,   600,   617,   633,   643,   656,   665,
     674,   684,   694,   704,   715,   726,   740,   751,   752,   758,
     776,   792,   802,   812,   824,   825,   834,   851,   861,   862,
     866,   867,   871,   879,   890,   898,   909,   917,   927,   928,
     939,   940,   947,   948,   953,   954,   964,   965,   972,   973,
     982,   983,   988,   996,  1001,  1005,  1010,  1014,  1019,  1024,
    1029,  1034,  1039,  1044,  1049,  1054,  1059,  1064,  1069,  1074,
    1078,  1085,  1092,  1103,  1116,  1128,  1145,  1160,  1180,  1188,
    1196,  1206,  1214,  1225,  1233,  1241,  1252,  1262,  1268,  1275,
    1283,  1294,  1302,  1312,  1318,  1326,  1334,  1344,  1352,  1363,
    1367,  1374,  1384,  1391,  1404,  1416,  1425,  1435,  1445,  1453,
    1464,  1475,  1485,  1497,  1507,  1517,  1525,  1536,  1540,  1544,
    1548,  1562,  1571,  1580,  1592,  1600,  1608,  1620,  1632,  1643,
    1655,  1666,  1680,  1690,  1700,  1710,  1721,  1732,  1736,  1745,
    1751,  1759,  1770,  1781,  1794,  1804,  1813,  1822,  1834,  1845,
    1853,  1854,  1858,  1859,  1863,  1864,  1868,  1869,  1873,  1874,
    1875,  1882,  1889,  1899,  1909,  1916,  1926,  1933,  1940,  1941,
    1942,  1943,  1951,  1961,  1968,  1978,  1989,  1999,  2010,  2011,
    2016,  2024,  2031,  2041,  2042,  2051,  2066,  2069,  2073,  2080,
    2089,  2099,  2106,  2113,  2123,  2127,  2131,  2136,  2149,  2161,
    2176,  2191,  2207,  2208,  2218,  2231,  2244,  2257,  2275,  2276,
    2280,  2286,  2292,  2297,  2305,  2306,  2307,  2308,  2312,  2316,
    2323,  2333,  2334,  2341,  2348,  2355,  2362,  2369,  2376,  2383,
    2390,  2400,  2401,  2405,  2409,  2416,  2417,  2421,  2428,  2429,
    2433,  2437,  2444,  2445,  2449,  2453,  2457,  2461,  2465,  2472,
    2473,  2477,  2481,  2485,  2489,  2496,  2497,  2501,  2505,  2509,
    2516,  2517,  2521,  2525,  2529,  2536,  2537,  2544,  2545,  2552,
    2553,  2560,  2561,  2568,  2569,  2576,  2577,  2584,  2585,  2592,
    2593,  2600,  2601,  2608,  2609,  2616,  2617,  2626,  2627,  2636,
    2640,  2650,  2654,  2665,  2666,  2667,  2668,  2669,  2670,  2671,
    2672,  2673,  2674,  2675,  2676,  2680,  2687,  2695,  2702,  2710,
    2711,  2715,  2716,  2720,  2721,  2725,  2726
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
  const int ParserImplementation::yylast_ = 3316;
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
#line 5881 "grammar/grammar.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 2729 "grammar/grammar.yy"


void yy::ParserImplementation::error (const location_type& loc, const std::string& msg) {
  tracer->SyntaxError ( connector->GetLineNumber () , msg.c_str () );
}


