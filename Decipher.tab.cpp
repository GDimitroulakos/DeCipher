/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

/* Line 279 of lalr1.cc  */
#line 38 "Decipher.tab.cpp"


#include "Decipher.tab.h"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 46 "Decipher.tab.cpp"
/* Unqualified %code blocks.  */
/* Line 286 of lalr1.cc  */
#line 52 "Decipher.y"

	#include "CD_driver.h"


/* Line 286 of lalr1.cc  */
#line 55 "Decipher.tab.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

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

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 353 of lalr1.cc  */
#line 12 "Decipher.y"
namespace decipher {
/* Line 353 of lalr1.cc  */
#line 151 "Decipher.tab.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  DecipherParserClass::yytnamerr_ (const char *yystr)
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
  DecipherParserClass::DecipherParserClass (DecipherParser_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  DecipherParserClass::~DecipherParserClass ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  DecipherParserClass::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  DecipherParserClass::yy_symbol_print_ (int yytype,
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
  DecipherParserClass::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  DecipherParserClass::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  DecipherParserClass::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  DecipherParserClass::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  DecipherParserClass::debug_level_type
  DecipherParserClass::debug_level () const
  {
    return yydebug_;
  }

  void
  DecipherParserClass::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  DecipherParserClass::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  DecipherParserClass::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  DecipherParserClass::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 545 of lalr1.cc  */
#line 35 "Decipher.y"
{
	// Initialize the initial location.
	//@$.begin.filename = @$.end.filename = &driver.file;
}
/* Line 545 of lalr1.cc  */
#line 352 "Decipher.tab.cpp"

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
        yychar = yylex (&yylval, &yylloc, driver);
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

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 72 "Decipher.y"
    {driver.m_ASTRoot = NULL; }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 73 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclaration_unit((CDASTscdeclarations *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclaration_unit__Scdeclarations_ );driver.m_ASTRoot = (yyval.ast); }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 75 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclarations((CDASTscdeclaration *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__Scdeclaration_ ); }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 76 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclarations((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTtype_name *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__TYPE_EXPRESSION_Type_name_ ); }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 77 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclarations((CDASTscdeclaration *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTscdeclarations *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__Scdeclaration_Scdeclarations_ ); }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 78 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclarations((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTtype_name *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTscdeclarations *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__TYPE_EXPRESSION_Type_name_Scdeclarations_ ); }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 80 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclaration((CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclaration__Declaration_specifiers_SEMICOLON_ ); }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 81 "Decipher.y"
    { (yyval.ast)= new CDASTscdeclaration((CDASTdeclaration_specifiers *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTinit_declarator_list *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Scdeclaration__Declaration_specifiers_Init_declarator_list_SEMICOLON_ ); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 83 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTstorage_class_specifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Storage_class_specifier_ ); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 84 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTstorage_class_specifier *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Storage_class_specifier_Declaration_specifiers_ ); }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 85 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTtype_specifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_specifier_ ); }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 86 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTtype_specifier *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_specifier_Declaration_specifiers_ ); }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 87 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTtype_qualifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_qualifier_ ); }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 88 "Decipher.y"
    { (yyval.ast)= new CDASTdeclaration_specifiers((CDASTtype_qualifier *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_qualifier_Declaration_specifiers_ ); }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 90 "Decipher.y"
    { (yyval.ast)= new CDASTinit_declarator_list((CDASTinit_declarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Init_declarator_list__Init_declarator_ ); }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 91 "Decipher.y"
    { (yyval.ast)= new CDASTinit_declarator_list((CDASTinit_declarator_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTinit_declarator *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Init_declarator_list__Init_declarator_list_COMMA_Init_declarator_ ); }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 93 "Decipher.y"
    { (yyval.ast)= new CDASTinit_declarator((CDASTdeclarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Init_declarator__Declarator_ ); }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 94 "Decipher.y"
    { (yyval.ast)= new CDASTinit_declarator((CDASTdeclarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTinitializer *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Init_declarator__Declarator_EQUALSIGN_Initializer_ ); }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 96 "Decipher.y"
    {g_IsTypedef = true; (yyval.ast)= new CDASTstorage_class_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__TYPEDEF_ ); }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 97 "Decipher.y"
    { (yyval.ast)= new CDASTstorage_class_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__EXTERN_ ); }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 98 "Decipher.y"
    { (yyval.ast)= new CDASTstorage_class_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__STATIC_ ); }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 99 "Decipher.y"
    { (yyval.ast)= new CDASTstorage_class_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__AUTO_ ); }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 100 "Decipher.y"
    { (yyval.ast)= new CDASTstorage_class_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__REGISTER_ ); }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 102 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__VOID_ ); }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 103 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__CHAR_ ); }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 104 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__SHORT_ ); }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 105 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__INT_ ); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 106 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__LONG_ ); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 107 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__FLOAT_ ); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 108 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__DOUBLE_ ); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 109 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__SIGNED_ ); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 110 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__UNSIGNED_ ); }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 111 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTstruct_or_union_specifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__Struct_or_union_specifier_ ); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 112 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTenum_specifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__Enum_specifier_ ); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 113 "Decipher.y"
    { (yyval.ast)= new CDASTtype_specifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_specifier__TYPE_NAME_ ); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 115 "Decipher.y"
    { g_IsInStructUnionDeclaration = false;(yyval.ast)= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)(yysemantic_stack_[(5) - (1)].ast) ,(CDASTqualified_id *)(yysemantic_stack_[(5) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(5) - (3)].ast),(CDASTstruct_declaration_list *)(yysemantic_stack_[(5) - (4)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(5) - (5)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_LBRACE_Struct_declaration_list_RBRACE_ ); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 116 "Decipher.y"
    { g_IsInStructUnionDeclaration = false; (yyval.ast)= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTstruct_declaration_list *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_LBRACE_Struct_declaration_list_RBRACE_ ); }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 117 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTqualified_id *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_ ); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 119 "Decipher.y"
    {g_IsInStructUnionDeclaration = true; (yyval.ast)= new CDASTstruct_or_union((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_or_union__STRUCT_ ); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 120 "Decipher.y"
    { g_IsInStructUnionDeclaration = true; (yyval.ast)= new CDASTstruct_or_union((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_or_union__UNION_ ); }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 122 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declaration_list((CDASTstruct_declaration *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declaration_list__Struct_declaration_ ); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 123 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declaration_list((CDASTstruct_declaration_list *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTstruct_declaration *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declaration_list__Struct_declaration_list_Struct_declaration_ ); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 125 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declaration((CDASTspecifier_qualifier_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTstruct_declarator_list *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declaration__Specifier_qualifier_list_Struct_declarator_list_SEMICOLON_ ); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 127 "Decipher.y"
    { (yyval.ast)= new CDASTspecifier_qualifier_list((CDASTtype_specifier *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTspecifier_qualifier_list *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_specifier_Specifier_qualifier_list_ ); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 128 "Decipher.y"
    { (yyval.ast)= new CDASTspecifier_qualifier_list((CDASTtype_specifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_specifier_ ); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 129 "Decipher.y"
    { (yyval.ast)= new CDASTspecifier_qualifier_list((CDASTtype_qualifier *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTspecifier_qualifier_list *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_qualifier_Specifier_qualifier_list_ ); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 130 "Decipher.y"
    { (yyval.ast)= new CDASTspecifier_qualifier_list((CDASTtype_qualifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_qualifier_ ); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 132 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declarator_list((CDASTstruct_declarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declarator_list__Struct_declarator_ ); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 133 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declarator_list((CDASTstruct_declarator_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTstruct_declarator *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declarator_list__Struct_declarator_list_COMMA_Struct_declarator_ ); }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 135 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declarator((CDASTdeclarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__Declarator_ ); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 136 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declarator((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__COLON_Constant_expression_ ); }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 137 "Decipher.y"
    { (yyval.ast)= new CDASTstruct_declarator((CDASTdeclarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__Declarator_COLON_Constant_expression_ ); }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 139 "Decipher.y"
    { (yyval.ast)= new CDASTenum_specifier((CDASTTOKEN *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTenumerator_list *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_LBRACE_Enumerator_list_RBRACE_ ); }
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 140 "Decipher.y"
    { (yyval.ast)= new CDASTenum_specifier((CDASTTOKEN *)(yysemantic_stack_[(5) - (1)].ast) ,(CDASTqualified_id *)(yysemantic_stack_[(5) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(5) - (3)].ast) ,(CDASTenumerator_list *)(yysemantic_stack_[(5) - (4)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(5) - (5)].ast) ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_Qualified_id_LBRACE_Enumerator_list_RBRACE_ ); }
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 141 "Decipher.y"
    { (yyval.ast)= new CDASTenum_specifier((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTqualified_id *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_Qualified_id_ ); }
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 143 "Decipher.y"
    { (yyval.ast)= new CDASTenumerator_list((CDASTenumerator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Enumerator_list__Enumerator_ ); }
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 144 "Decipher.y"
    { (yyval.ast)= new CDASTenumerator_list((CDASTenumerator_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTenumerator *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Enumerator_list__Enumerator_list_COMMA_Enumerator_ ); }
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 146 "Decipher.y"
    { (yyval.ast)= new CDASTenumerator((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Enumerator__IDENTIFIER_ ); }
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 147 "Decipher.y"
    { (yyval.ast)= new CDASTenumerator((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Enumerator__IDENTIFIER_EQUALSIGN_Constant_expression_ ); }
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 149 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__CONST_ ); }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 150 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__VOLATILE_ ); }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 151 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__IN_ ); }
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 152 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__OUT_ ); }
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 154 "Decipher.y"
    { (yyval.ast)= new CDASTdeclarator((CDASTpointer *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdirect_declarator *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Declarator__Pointer_Direct_declarator_ ); }
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 155 "Decipher.y"
    { (yyval.ast)= new CDASTdeclarator((CDASTdirect_declarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Declarator__Direct_declarator_ ); }
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 157 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTqualified_id *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Qualified_id_ ); }
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 158 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTdeclarator *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__LPARENTHESIS_Declarator_RPARENTHESIS_ ); }
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 159 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTdirect_declarator *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LBRACKET_Constant_expression_RBRACKET_ ); }
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 160 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTdirect_declarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LBRACKET_RBRACKET_ ); }
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 161 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTdirect_declarator *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTparameter_type_list *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 162 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_declarator((CDASTdirect_declarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_RPARENTHESIS_ ); }
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 164 "Decipher.y"
    { (yyval.ast)= new CDASTpointer((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_ ); }
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 165 "Decipher.y"
    { (yyval.ast)= new CDASTpointer((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTtype_qualifier_list *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Type_qualifier_list_ ); }
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 166 "Decipher.y"
    { (yyval.ast)= new CDASTpointer((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTpointer *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Pointer_ ); }
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 167 "Decipher.y"
    { (yyval.ast)= new CDASTpointer((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTtype_qualifier_list *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTpointer *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Type_qualifier_list_Pointer_ ); }
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 169 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier_list((CDASTtype_qualifier *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier_list__Type_qualifier_ ); }
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 170 "Decipher.y"
    { (yyval.ast)= new CDASTtype_qualifier_list((CDASTtype_qualifier_list *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTtype_qualifier *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_qualifier_list__Type_qualifier_list_Type_qualifier_ ); }
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 172 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_type_list((CDASTparameter_list *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_type_list__Parameter_list_ ); }
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 173 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_type_list((CDASTparameter_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_type_list__Parameter_list_COMMA_ELLIPSIS_ ); }
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 175 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_list((CDASTparameter_declaration *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_list__Parameter_declaration_ ); }
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 176 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_list((CDASTparameter_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTparameter_declaration *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_list__Parameter_list_COMMA_Parameter_declaration_ ); }
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 178 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdeclarator *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_Declarator_ ); }
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 179 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTabstract_declarator *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_Abstract_declarator_ ); }
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 180 "Decipher.y"
    { (yyval.ast)= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_ ); }
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 182 "Decipher.y"
    { (yyval.ast)= new CDASTtype_name((CDASTspecifier_qualifier_list *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTabstract_declarator *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Type_name__Specifier_qualifier_list_Abstract_declarator_ ); }
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 184 "Decipher.y"
    { (yyval.ast)= new CDASTabstract_declarator((CDASTpointer *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Pointer_ ); }
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 185 "Decipher.y"
    { (yyval.ast)= new CDASTabstract_declarator((CDASTdirect_abstract_declarator *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Direct_abstract_declarator_ ); }
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 186 "Decipher.y"
    { (yyval.ast)= new CDASTabstract_declarator((CDASTpointer *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTdirect_abstract_declarator *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Pointer_Direct_abstract_declarator_ ); }
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 188 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTabstract_declarator *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_Abstract_declarator_RPARENTHESIS_ ); }
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 189 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LBRACKET_RBRACKET_ ); }
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 190 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LBRACKET_Constant_expression_RBRACKET_ ); }
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 191 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_RBRACKET_ ); }
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 192 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTconstant_expression *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_Constant_expression_RBRACKET_ ); }
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 193 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_RPARENTHESIS_ ); }
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 194 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTparameter_type_list *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 195 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_RPARENTHESIS_ ); }
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 196 "Decipher.y"
    { (yyval.ast)= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTparameter_type_list *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 198 "Decipher.y"
    { (yyval.ast)= new CDASTinitializer((CDASTassignment_expression *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Initializer__Assignment_expression_ ); }
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 199 "Decipher.y"
    { (yyval.ast)= new CDASTinitializer((CDASTTOKEN *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTinitializer_list *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Initializer__LBRACE_Initializer_list_RBRACE_ ); }
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 200 "Decipher.y"
    { (yyval.ast)= new CDASTinitializer((CDASTTOKEN *)(yysemantic_stack_[(4) - (1)].ast) ,(CDASTinitializer_list *)(yysemantic_stack_[(4) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (3)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(4) - (4)].ast) ,(decipher::location *)&yylloc ,DLAST_Initializer__LBRACE_Initializer_list_COMMA_RBRACE_ ); }
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 202 "Decipher.y"
    { (yyval.ast)= new CDASTinitializer_list((CDASTinitializer *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Initializer_list__Initializer_ ); }
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 203 "Decipher.y"
    { (yyval.ast)= new CDASTinitializer_list((CDASTinitializer_list *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTinitializer *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Initializer_list__Initializer_list_COMMA_Initializer_ ); }
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 205 "Decipher.y"
    { if ( g_IsTypedef && !g_IsInStructUnionDeclaration ){
								g_TypesSymbolTable.push_back((string)((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast))->m_tokenstring);
								g_IsTypedef = false;
								g_IsDirectDeclarator = false;
							}
							(yyval.ast)= new CDASTqualified_id((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Qualified_id__IDENTIFIER_ ); }
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 211 "Decipher.y"
    {	if ( g_IsTypedef && !g_IsInStructUnionDeclaration ){
								g_TypesSymbolTable.push_back((string)((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast))->m_tokenstring);
								g_IsTypedef = false;
								g_IsDirectDeclarator = false;
							}
							(yyval.ast)= new CDASTqualified_id((CDASTTOKEN *)(yysemantic_stack_[(2) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(2) - (2)].ast) ,(decipher::location *)&yylloc ,DLAST_Qualified_id__SCOPE_OP_IDENTIFIER_ ); }
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 217 "Decipher.y"
    { (yyval.ast)= new CDASTqualified_id((CDASTqualified_id *)(yysemantic_stack_[(3) - (1)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (2)].ast) ,(CDASTTOKEN *)(yysemantic_stack_[(3) - (3)].ast) ,(decipher::location *)&yylloc ,DLAST_Qualified_id__Qualified_id_SCOPE_OP_IDENTIFIER_ ); }
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 219 "Decipher.y"
    { (yyval.ast)= new CDASTassignment_expression((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Assignment_expression__CONSTANT_EXPRESSION_ ); }
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 221 "Decipher.y"
    { (yyval.ast)= new CDASTconstant_expression((CDASTTOKEN *)(yysemantic_stack_[(1) - (1)].ast) ,(decipher::location *)&yylloc ,DLAST_Constant_expression__CONSTANT_EXPRESSION_ ); }
    break;


/* Line 670 of lalr1.cc  */
#line 1124 "Decipher.tab.cpp"
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
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  DecipherParserClass::yysyntax_error_ (int yystate, int yytoken)
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

    char const* yyformat = YY_NULL;
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
  const signed char DecipherParserClass::yypact_ninf_ = -101;
  const short int
  DecipherParserClass::yypact_[] =
  {
       281,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,     8,  -101,  -101,  -101,  -101,  -101,  -101,   359,
    -101,  -101,  -101,  -101,    23,  -101,   281,    47,   333,   333,
    -101,    17,  -101,   333,    -8,  -101,     1,     2,   359,   129,
     359,   281,  -101,  -101,  -101,    81,   247,    26,  -101,    31,
     104,   259,    43,  -101,  -101,   359,    16,  -101,    79,   142,
    -101,  -101,    -8,    68,  -101,   177,    57,   209,  -101,   239,
    -101,  -101,   113,  -101,  -101,   247,  -101,    81,    73,   207,
      71,   104,    88,  -101,    58,   359,   126,    -8,  -101,   173,
    -101,  -101,    76,   134,   154,  -101,   140,  -101,  -101,   188,
     239,   237,    74,  -101,  -101,  -101,  -101,  -101,    73,  -101,
    -101,  -101,   179,  -101,   200,  -101,  -101,   126,   238,  -101,
     211,   115,  -101,  -101,  -101,   146,  -101,   108,  -101,  -101,
     307,  -101,  -101,  -101,   220,  -101,   226,  -101,   204,  -101,
    -101,  -101,  -101,    58,   126,  -101,  -101,  -101,  -101,  -101,
      90,  -101,  -101,  -101,  -101,  -101
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  DecipherParserClass::yydefact_[] =
  {
         2,    28,    29,    24,    30,    31,    33,    32,    36,    40,
      41,    20,     0,    21,    22,    23,    25,    26,    27,     0,
      64,    63,    62,    61,     0,     3,     4,     0,    10,    12,
      34,     0,    35,    14,     0,   104,     0,    56,    46,     0,
      48,     5,     1,     6,     8,     0,    73,     0,    16,    18,
      66,     0,    67,    11,    13,     0,    39,    15,    59,     0,
      57,   105,     0,     0,    45,     0,     0,    87,    86,    88,
      47,     7,     0,    77,    75,    74,     9,     0,     0,     0,
       0,    65,     0,    42,     0,     0,     0,     0,    54,     0,
     106,    95,    85,     0,    79,    81,     0,   108,    91,     0,
      89,     0,     0,    68,    78,    76,    17,   107,     0,    19,
      99,    72,     0,    70,     0,    38,    43,     0,     0,    49,
      51,     0,    60,    58,    55,     0,    83,    87,    84,    96,
       0,    90,    92,    97,     0,    93,     0,   102,     0,    71,
      69,    52,    44,     0,     0,    37,    80,    82,    98,    94,
       0,   100,    50,    53,   101,   103
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  DecipherParserClass::yypgoto_[] =
  {
      -101,  -101,   -12,  -101,    18,  -101,   174,  -101,   -18,  -101,
    -101,   189,   -73,    36,  -101,   130,  -101,   217,   193,   -19,
     -43,   -48,   -35,  -101,   -66,  -101,   151,  -101,   -32,   -62,
    -100,  -101,     3,  -101,   -74
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  DecipherParserClass::yydefgoto_[] =
  {
        -1,    24,    25,    26,    92,    47,    48,    28,    29,    30,
      31,    82,    83,    84,   118,   119,    32,    59,    60,    33,
      49,    50,    51,    75,    93,    94,    95,    41,    96,    69,
     109,   138,    52,   110,    99
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char DecipherParserClass::yytable_ninf_ = -1;
  const unsigned char
  DecipherParserClass::yytable_[] =
  {
        40,    38,    72,    81,    67,   100,   114,    68,   137,   116,
      62,    74,   122,   112,    43,    37,    34,    58,    27,    40,
      38,    40,    38,    42,    85,    55,    61,    73,   136,    71,
      67,    76,    77,    35,    56,   134,    40,    38,    78,    63,
     105,   120,    35,   141,    27,    36,    53,    54,   116,   126,
     155,    57,    44,    63,    36,    39,   104,   127,    45,    27,
     128,    97,    46,    40,    38,   100,    40,    38,   117,    45,
     153,    98,    35,    46,    64,    97,    70,   107,    97,    81,
      63,   108,    72,    35,    36,   113,    86,   125,   135,    66,
     127,    46,    45,    90,   107,    36,    46,   115,   108,   154,
     120,    35,    40,    38,     1,     2,    35,     4,     5,     6,
       7,     8,     9,    36,    10,    79,    12,    80,    36,   125,
      16,    66,    17,    18,   145,   103,    20,    21,    22,    23,
      97,     1,     2,    35,     4,     5,     6,     7,     8,     9,
      65,    10,    66,    12,    46,    36,   129,    16,    87,    17,
      18,    88,   131,    20,    21,    22,    23,   125,    91,    66,
     130,    46,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    35,    10,    11,    12,    13,    14,    15,    16,    87,
      17,    18,   124,    36,    20,    21,    22,    23,    65,    91,
      66,   139,    46,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   132,    10,    11,    12,    13,    14,    15,    16,
     150,    17,    18,   151,   140,    20,    21,    22,    23,   111,
      65,   144,    66,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   148,    10,    11,    12,    13,    14,    15,    16,
     149,    17,    18,   142,   143,    20,    21,    22,    23,   133,
     101,   106,   102,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    46,    10,    11,    12,    13,    14,    15,    16,
      45,    17,    18,   152,   121,    20,    21,    22,    23,    89,
     123,   147,     0,     0,    35,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,    36,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,     0,    17,    18,    19,     0,    20,
      21,    22,    23,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
     146,    17,    18,     0,     0,    20,    21,    22,    23,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,     0,
       0,    20,    21,    22,    23,     1,     2,     0,     4,     5,
       6,     7,     8,     9,     0,    10,     0,    12,     0,     0,
       0,    16,     0,    17,    18,     0,     0,    20,    21,    22,
      23
  };

  /* YYCHECK.  */
  const short int
  DecipherParserClass::yycheck_[] =
  {
        19,    19,    45,    51,    39,    67,    80,    39,   108,    82,
       8,    46,    86,    79,    26,    12,     8,    25,     0,    38,
      38,    40,    40,     0,     8,     8,    25,    46,   102,    41,
      65,     5,     6,    25,    31,   101,    55,    55,     7,    37,
      75,    84,    25,   117,    26,    37,    28,    29,   121,    92,
     150,    33,     5,    37,    37,    19,    75,    92,    11,    41,
      92,     4,    15,    82,    82,   127,    85,    85,    10,    11,
     144,    14,    25,    15,    38,     4,    40,     4,     4,   127,
      37,     8,   125,    25,    37,    14,     7,    11,    14,    13,
     125,    15,    11,    25,     4,    37,    15,     9,     8,     9,
     143,    25,   121,   121,    16,    17,    25,    19,    20,    21,
      22,    23,    24,    37,    26,    11,    28,    13,    37,    11,
      32,    13,    34,    35,     9,    12,    38,    39,    40,    41,
       4,    16,    17,    25,    19,    20,    21,    22,    23,    24,
      11,    26,    13,    28,    15,    37,    12,    32,     6,    34,
      35,     9,    12,    38,    39,    40,    41,    11,    12,    13,
       6,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     6,
      34,    35,     9,    37,    38,    39,    40,    41,    11,    12,
      13,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    14,    26,    27,    28,    29,    30,    31,    32,
       6,    34,    35,     9,    14,    38,    39,    40,    41,    12,
      11,    10,    13,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    12,    26,    27,    28,    29,    30,    31,    32,
      14,    34,    35,     5,     6,    38,    39,    40,    41,    12,
      11,    77,    13,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    15,    26,    27,    28,    29,    30,    31,    32,
      11,    34,    35,   143,    85,    38,    39,    40,    41,    62,
      87,   130,    -1,    -1,    25,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    -1,    38,
      39,    40,    41,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    38,    39,    40,    41,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    -1,
      -1,    38,    39,    40,    41,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    -1,    28,    -1,    -1,
      -1,    32,    -1,    34,    35,    -1,    -1,    38,    39,    40,
      41
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  DecipherParserClass::yystos_[] =
  {
         0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    34,    35,    36,
      38,    39,    40,    41,    43,    44,    45,    46,    49,    50,
      51,    52,    58,    61,     8,    25,    37,    74,    50,    55,
      61,    69,     0,    44,     5,    11,    15,    47,    48,    62,
      63,    64,    74,    46,    46,     8,    74,    46,    25,    59,
      60,    25,     8,    37,    55,    11,    13,    64,    70,    71,
      55,    44,    62,    61,    64,    65,     5,     6,     7,    11,
      13,    63,    53,    54,    55,     8,     7,     6,     9,    59,
      25,    12,    46,    66,    67,    68,    70,     4,    14,    76,
      71,    11,    13,    12,    61,    64,    48,     4,     8,    72,
      75,    12,    66,    14,    76,     9,    54,    10,    56,    57,
      62,    53,    76,    60,     9,    11,    62,    64,    70,    12,
       6,    12,    14,    12,    66,    14,    76,    72,    73,    12,
      14,    76,     5,     6,    10,     9,    33,    68,    12,    14,
       6,     9,    57,    76,     9,    72
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  DecipherParserClass::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  DecipherParserClass::yyr1_[] =
  {
         0,    42,    43,    43,    44,    44,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    47,    47,    48,    48,
      49,    49,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    69,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    76
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  DecipherParserClass::yyr2_[] =
  {
         0,     2,     0,     1,     1,     2,     2,     3,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     3,     4,
       3,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     2,     3,     1,     1
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const DecipherParserClass::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "LEAST",
  "CONSTANT_EXPRESSION", "SEMICOLON", "COMMA", "EQUALSIGN", "LBRACE",
  "RBRACE", "COLON", "LPARENTHESIS", "RPARENTHESIS", "LBRACKET",
  "RBRACKET", "ASTERISK", "INT", "LONG", "REGISTER", "FLOAT", "DOUBLE",
  "UNSIGNED", "SIGNED", "TYPE_NAME", "STRUCT", "IDENTIFIER", "UNION",
  "TYPEDEF", "ENUM", "EXTERN", "STATIC", "AUTO", "VOID", "ELLIPSIS",
  "CHAR", "SHORT", "TYPE_EXPRESSION", "SCOPE_OP", "OUT", "IN", "VOLATILE",
  "CONST", "$accept", "scdeclaration_unit", "scdeclarations",
  "scdeclaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "qualified_id", "assignment_expression", "constant_expression", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const DecipherParserClass::rhs_number_type
  DecipherParserClass::yyrhs_[] =
  {
        43,     0,    -1,    -1,    44,    -1,    45,    -1,    36,    69,
      -1,    45,    44,    -1,    36,    69,    44,    -1,    46,     5,
      -1,    46,    47,     5,    -1,    49,    -1,    49,    46,    -1,
      50,    -1,    50,    46,    -1,    61,    -1,    61,    46,    -1,
      48,    -1,    47,     6,    48,    -1,    62,    -1,    62,     7,
      72,    -1,    27,    -1,    29,    -1,    30,    -1,    31,    -1,
      18,    -1,    32,    -1,    34,    -1,    35,    -1,    16,    -1,
      17,    -1,    19,    -1,    20,    -1,    22,    -1,    21,    -1,
      51,    -1,    58,    -1,    23,    -1,    52,    74,     8,    53,
       9,    -1,    52,     8,    53,     9,    -1,    52,    74,    -1,
      24,    -1,    26,    -1,    54,    -1,    53,    54,    -1,    55,
      56,     5,    -1,    50,    55,    -1,    50,    -1,    61,    55,
      -1,    61,    -1,    57,    -1,    56,     6,    57,    -1,    62,
      -1,    10,    76,    -1,    62,    10,    76,    -1,    28,     8,
      59,     9,    -1,    28,    74,     8,    59,     9,    -1,    28,
      74,    -1,    60,    -1,    59,     6,    60,    -1,    25,    -1,
      25,     7,    76,    -1,    41,    -1,    40,    -1,    39,    -1,
      38,    -1,    64,    63,    -1,    63,    -1,    74,    -1,    11,
      62,    12,    -1,    63,    13,    76,    14,    -1,    63,    13,
      14,    -1,    63,    11,    66,    12,    -1,    63,    11,    12,
      -1,    15,    -1,    15,    65,    -1,    15,    64,    -1,    15,
      65,    64,    -1,    61,    -1,    65,    61,    -1,    67,    -1,
      67,     6,    33,    -1,    68,    -1,    67,     6,    68,    -1,
      46,    62,    -1,    46,    70,    -1,    46,    -1,    55,    70,
      -1,    64,    -1,    71,    -1,    64,    71,    -1,    11,    70,
      12,    -1,    13,    14,    -1,    13,    76,    14,    -1,    71,
      13,    14,    -1,    71,    13,    76,    14,    -1,    11,    12,
      -1,    11,    66,    12,    -1,    71,    11,    12,    -1,    71,
      11,    66,    12,    -1,    75,    -1,     8,    73,     9,    -1,
       8,    73,     6,     9,    -1,    72,    -1,    73,     6,    72,
      -1,    25,    -1,    37,    25,    -1,    74,    37,    25,    -1,
       4,    -1,     4,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  DecipherParserClass::yyprhs_[] =
  {
         0,     0,     3,     4,     6,     8,    11,    14,    18,    21,
      25,    27,    30,    32,    35,    37,    40,    42,    46,    48,
      52,    54,    56,    58,    60,    62,    64,    66,    68,    70,
      72,    74,    76,    78,    80,    82,    84,    86,    92,    97,
     100,   102,   104,   106,   109,   113,   116,   118,   121,   123,
     125,   129,   131,   134,   138,   143,   149,   152,   154,   158,
     160,   164,   166,   168,   170,   172,   175,   177,   179,   183,
     188,   192,   197,   201,   203,   206,   209,   213,   215,   218,
     220,   224,   226,   230,   233,   236,   238,   241,   243,   245,
     248,   252,   255,   259,   263,   268,   271,   275,   279,   284,
     286,   290,   295,   297,   301,   303,   306,   310,   312
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  DecipherParserClass::yyrline_[] =
  {
         0,    72,    72,    73,    75,    76,    77,    78,    80,    81,
      83,    84,    85,    86,    87,    88,    90,    91,    93,    94,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   115,   116,   117,
     119,   120,   122,   123,   125,   127,   128,   129,   130,   132,
     133,   135,   136,   137,   139,   140,   141,   143,   144,   146,
     147,   149,   150,   151,   152,   154,   155,   157,   158,   159,
     160,   161,   162,   164,   165,   166,   167,   169,   170,   172,
     173,   175,   176,   178,   179,   180,   182,   184,   185,   186,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   198,
     199,   200,   202,   203,   205,   211,   217,   219,   221
  };

  // Print the state stack on the debug stream.
  void
  DecipherParserClass::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  DecipherParserClass::yy_reduce_print_ (int yyrule)
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
  DecipherParserClass::token_number_type
  DecipherParserClass::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int DecipherParserClass::yyeof_ = 0;
  const int DecipherParserClass::yylast_ = 400;
  const int DecipherParserClass::yynnts_ = 35;
  const int DecipherParserClass::yyempty_ = -2;
  const int DecipherParserClass::yyfinal_ = 42;
  const int DecipherParserClass::yyterror_ = 1;
  const int DecipherParserClass::yyerrcode_ = 256;
  const int DecipherParserClass::yyntokens_ = 42;

  const unsigned int DecipherParserClass::yyuser_token_number_max_ = 296;
  const DecipherParserClass::token_number_type DecipherParserClass::yyundef_token_ = 2;

/* Line 1141 of lalr1.cc  */
#line 12 "Decipher.y"
} // decipher
/* Line 1141 of lalr1.cc  */
#line 1849 "Decipher.tab.cpp"
/* Line 1142 of lalr1.cc  */
#line 223 "Decipher.y"

bool g_IsDirectDeclarator =false;
bool g_IsInStructUnionDeclaration=false;
bool g_IsTypedef=false;