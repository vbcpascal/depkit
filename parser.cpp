// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

// //                    "%code top" blocks.
#line 16 "parser.yy"

#include <cstdio>
#include <map>
#include <vector>

#line 44 "parser.cpp"




#include "parser.hpp"


// Unqualified %code blocks.
#line 33 "parser.yy"

TermsPtr terms;

#include "lex.hpp"
#undef yylex
#define yylex lexer.yylex

#line 61 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy"
namespace depkit { namespace yy {
#line 156 "parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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
  Parser::Parser (depkit::yy::Lexer& lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 46: // package_definition
        value.YY_MOVE_OR_COPY< DefinitionPtr > (YY_MOVE (that.value));
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.YY_MOVE_OR_COPY< DependencyPtr > (YY_MOVE (that.value));
        break;

      case 39: // package_identification
        value.YY_MOVE_OR_COPY< IdentificationPtr > (YY_MOVE (that.value));
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.YY_MOVE_OR_COPY< PackageExprPtr > (YY_MOVE (that.value));
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.YY_MOVE_OR_COPY< PropExprPtr > (YY_MOVE (that.value));
        break;

      case 40: // property_list
        value.YY_MOVE_OR_COPY< PropertyListPtr > (YY_MOVE (that.value));
        break;

      case 65: // requirement
        value.YY_MOVE_OR_COPY< RequirementPtr > (YY_MOVE (that.value));
        break;

      case 35: // terms
        value.YY_MOVE_OR_COPY< TermsPtr > (YY_MOVE (that.value));
        break;

      case 5: // S_DOT
      case 6: // S_COMMA
      case 7: // S_COLON
      case 8: // S_SEMI
      case 9: // S_LPR
      case 10: // S_RPR
      case 11: // S_LSR
      case 12: // S_RSR
      case 13: // S_LBR
      case 14: // S_RBR
      case 15: // S_ASSIGN
      case 16: // S_EQ
      case 17: // S_NE
      case 18: // S_GE
      case 19: // S_LE
      case 20: // S_GT
      case 21: // S_LT
      case 22: // S_AND
      case 23: // S_OR
      case 24: // S_NOT
      case 25: // S_SEP
      case 26: // K_IN
      case 27: // K_NIN
      case 28: // K_IF
      case 29: // K_ELSE
      case 30: // K_REQ
      case 31: // K_V
      case 32: // K_F
      case 33: // K_B
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 36: // definitions
        value.YY_MOVE_OR_COPY< std::list<DefinitionPtr> > (YY_MOVE (that.value));
        break;

      case 37: // dependencies
        value.YY_MOVE_OR_COPY< std::list<DependencyPtr> > (YY_MOVE (that.value));
        break;

      case 51: // depend_list
        value.YY_MOVE_OR_COPY< std::list<PackageExprPtr> > (YY_MOVE (that.value));
        break;

      case 49: // require_list
        value.YY_MOVE_OR_COPY< std::list<PropExprPtr> > (YY_MOVE (that.value));
        break;

      case 38: // requirements
        value.YY_MOVE_OR_COPY< std::list<RequirementPtr> > (YY_MOVE (that.value));
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.YY_MOVE_OR_COPY< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 4: // C_DOUBLE
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 46: // package_definition
        value.move< DefinitionPtr > (YY_MOVE (that.value));
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.move< DependencyPtr > (YY_MOVE (that.value));
        break;

      case 39: // package_identification
        value.move< IdentificationPtr > (YY_MOVE (that.value));
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.move< PackageExprPtr > (YY_MOVE (that.value));
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.move< PropExprPtr > (YY_MOVE (that.value));
        break;

      case 40: // property_list
        value.move< PropertyListPtr > (YY_MOVE (that.value));
        break;

      case 65: // requirement
        value.move< RequirementPtr > (YY_MOVE (that.value));
        break;

      case 35: // terms
        value.move< TermsPtr > (YY_MOVE (that.value));
        break;

      case 5: // S_DOT
      case 6: // S_COMMA
      case 7: // S_COLON
      case 8: // S_SEMI
      case 9: // S_LPR
      case 10: // S_RPR
      case 11: // S_LSR
      case 12: // S_RSR
      case 13: // S_LBR
      case 14: // S_RBR
      case 15: // S_ASSIGN
      case 16: // S_EQ
      case 17: // S_NE
      case 18: // S_GE
      case 19: // S_LE
      case 20: // S_GT
      case 21: // S_LT
      case 22: // S_AND
      case 23: // S_OR
      case 24: // S_NOT
      case 25: // S_SEP
      case 26: // K_IN
      case 27: // K_NIN
      case 28: // K_IF
      case 29: // K_ELSE
      case 30: // K_REQ
      case 31: // K_V
      case 32: // K_F
      case 33: // K_B
        value.move< int > (YY_MOVE (that.value));
        break;

      case 36: // definitions
        value.move< std::list<DefinitionPtr> > (YY_MOVE (that.value));
        break;

      case 37: // dependencies
        value.move< std::list<DependencyPtr> > (YY_MOVE (that.value));
        break;

      case 51: // depend_list
        value.move< std::list<PackageExprPtr> > (YY_MOVE (that.value));
        break;

      case 49: // require_list
        value.move< std::list<PropExprPtr> > (YY_MOVE (that.value));
        break;

      case 38: // requirements
        value.move< std::list<RequirementPtr> > (YY_MOVE (that.value));
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.move< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 4: // C_DOUBLE
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 46: // package_definition
        value.move< DefinitionPtr > (that.value);
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.move< DependencyPtr > (that.value);
        break;

      case 39: // package_identification
        value.move< IdentificationPtr > (that.value);
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.move< PackageExprPtr > (that.value);
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.move< PropExprPtr > (that.value);
        break;

      case 40: // property_list
        value.move< PropertyListPtr > (that.value);
        break;

      case 65: // requirement
        value.move< RequirementPtr > (that.value);
        break;

      case 35: // terms
        value.move< TermsPtr > (that.value);
        break;

      case 5: // S_DOT
      case 6: // S_COMMA
      case 7: // S_COLON
      case 8: // S_SEMI
      case 9: // S_LPR
      case 10: // S_RPR
      case 11: // S_LSR
      case 12: // S_RSR
      case 13: // S_LBR
      case 14: // S_RBR
      case 15: // S_ASSIGN
      case 16: // S_EQ
      case 17: // S_NE
      case 18: // S_GE
      case 19: // S_LE
      case 20: // S_GT
      case 21: // S_LT
      case 22: // S_AND
      case 23: // S_OR
      case 24: // S_NOT
      case 25: // S_SEP
      case 26: // K_IN
      case 27: // K_NIN
      case 28: // K_IF
      case 29: // K_ELSE
      case 30: // K_REQ
      case 31: // K_V
      case 32: // K_F
      case 33: // K_B
        value.move< int > (that.value);
        break;

      case 36: // definitions
        value.move< std::list<DefinitionPtr> > (that.value);
        break;

      case 37: // dependencies
        value.move< std::list<DependencyPtr> > (that.value);
        break;

      case 51: // depend_list
        value.move< std::list<PackageExprPtr> > (that.value);
        break;

      case 49: // require_list
        value.move< std::list<PropExprPtr> > (that.value);
        break;

      case 38: // requirements
        value.move< std::list<RequirementPtr> > (that.value);
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.move< std::list<std::string> > (that.value);
        break;

      case 3: // C_IDENTIFIER
      case 4: // C_DOUBLE
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 46: // package_definition
        yylhs.value.emplace< DefinitionPtr > ();
        break;

      case 47: // package_dependency
      case 48: // dep_body
        yylhs.value.emplace< DependencyPtr > ();
        break;

      case 39: // package_identification
        yylhs.value.emplace< IdentificationPtr > ();
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        yylhs.value.emplace< PackageExprPtr > ();
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        yylhs.value.emplace< PropExprPtr > ();
        break;

      case 40: // property_list
        yylhs.value.emplace< PropertyListPtr > ();
        break;

      case 65: // requirement
        yylhs.value.emplace< RequirementPtr > ();
        break;

      case 35: // terms
        yylhs.value.emplace< TermsPtr > ();
        break;

      case 5: // S_DOT
      case 6: // S_COMMA
      case 7: // S_COLON
      case 8: // S_SEMI
      case 9: // S_LPR
      case 10: // S_RPR
      case 11: // S_LSR
      case 12: // S_RSR
      case 13: // S_LBR
      case 14: // S_RBR
      case 15: // S_ASSIGN
      case 16: // S_EQ
      case 17: // S_NE
      case 18: // S_GE
      case 19: // S_LE
      case 20: // S_GT
      case 21: // S_LT
      case 22: // S_AND
      case 23: // S_OR
      case 24: // S_NOT
      case 25: // S_SEP
      case 26: // K_IN
      case 27: // K_NIN
      case 28: // K_IF
      case 29: // K_ELSE
      case 30: // K_REQ
      case 31: // K_V
      case 32: // K_F
      case 33: // K_B
        yylhs.value.emplace< int > ();
        break;

      case 36: // definitions
        yylhs.value.emplace< std::list<DefinitionPtr> > ();
        break;

      case 37: // dependencies
        yylhs.value.emplace< std::list<DependencyPtr> > ();
        break;

      case 51: // depend_list
        yylhs.value.emplace< std::list<PackageExprPtr> > ();
        break;

      case 49: // require_list
        yylhs.value.emplace< std::list<PropExprPtr> > ();
        break;

      case 38: // requirements
        yylhs.value.emplace< std::list<RequirementPtr> > ();
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        yylhs.value.emplace< std::list<std::string> > ();
        break;

      case 3: // C_IDENTIFIER
      case 4: // C_DOUBLE
      case 66: // prop_name
      case 67: // name
      case 68: // str
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 71 "parser.yy"
    { terms = std::make_shared<Terms>(yystack_[4].value.as < std::list<DefinitionPtr> > (), yystack_[2].value.as < std::list<DependencyPtr> > (), yystack_[0].value.as < std::list<RequirementPtr> > ()); }
#line 1019 "parser.cpp"
    break;

  case 3:
#line 75 "parser.yy"
    { yystack_[1].value.as < std::list<DefinitionPtr> > ().push_back(yystack_[0].value.as < DefinitionPtr > ()); yylhs.value.as < std::list<DefinitionPtr> > () = yystack_[1].value.as < std::list<DefinitionPtr> > (); }
#line 1025 "parser.cpp"
    break;

  case 4:
#line 76 "parser.yy"
    { yylhs.value.as < std::list<DefinitionPtr> > () = std::list<DefinitionPtr>(); }
#line 1031 "parser.cpp"
    break;

  case 5:
#line 80 "parser.yy"
    { yystack_[1].value.as < std::list<DependencyPtr> > ().push_back(yystack_[0].value.as < DependencyPtr > ()); yylhs.value.as < std::list<DependencyPtr> > () = yystack_[1].value.as < std::list<DependencyPtr> > (); }
#line 1037 "parser.cpp"
    break;

  case 6:
#line 81 "parser.yy"
    { yylhs.value.as < std::list<DependencyPtr> > () = std::list<DependencyPtr>(); }
#line 1043 "parser.cpp"
    break;

  case 7:
#line 85 "parser.yy"
    { yystack_[1].value.as < std::list<RequirementPtr> > ().push_back(yystack_[0].value.as < RequirementPtr > ()); yylhs.value.as < std::list<RequirementPtr> > () = yystack_[1].value.as < std::list<RequirementPtr> > (); }
#line 1049 "parser.cpp"
    break;

  case 8:
#line 86 "parser.yy"
    { yylhs.value.as < std::list<RequirementPtr> > () = std::list<RequirementPtr>(); }
#line 1055 "parser.cpp"
    break;

  case 9:
#line 90 "parser.yy"
    { yylhs.value.as < IdentificationPtr > () = std::make_shared<Identification>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < PropertyListPtr > ()); }
#line 1061 "parser.cpp"
    break;

  case 10:
#line 95 "parser.yy"
    { yylhs.value.as < PropertyListPtr > () = std::make_shared<PropertyList>(yystack_[5].value.as < std::list<std::string> > (), yystack_[3].value.as < std::list<std::string> > (), yystack_[1].value.as < std::list<std::string> > ()); }
#line 1067 "parser.cpp"
    break;

  case 11:
#line 99 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1073 "parser.cpp"
    break;

  case 12:
#line 103 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1079 "parser.cpp"
    break;

  case 13:
#line 107 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1085 "parser.cpp"
    break;

  case 14:
#line 111 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = yystack_[0].value.as < std::list<std::string> > (); }
#line 1091 "parser.cpp"
    break;

  case 15:
#line 112 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = std::list<std::string>(); }
#line 1097 "parser.cpp"
    break;

  case 16:
#line 116 "parser.yy"
    { yystack_[2].value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > (); }
#line 1103 "parser.cpp"
    break;

  case 17:
#line 117 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = std::list<std::string>(); yylhs.value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); }
#line 1109 "parser.cpp"
    break;

  case 18:
#line 121 "parser.yy"
    { yylhs.value.as < DefinitionPtr > () = std::make_shared<Definition>(yystack_[3].value.as < IdentificationPtr > ()); }
#line 1115 "parser.cpp"
    break;

  case 19:
#line 125 "parser.yy"
    { yystack_[0].value.as < DependencyPtr > ()->identification_ = yystack_[2].value.as < IdentificationPtr > (); yylhs.value.as < DependencyPtr > () = yystack_[0].value.as < DependencyPtr > (); }
#line 1121 "parser.cpp"
    break;

  case 20:
#line 126 "parser.yy"
    { yystack_[0].value.as < DependencyPtr > ()->identification_ = std::make_shared<Identification>(yystack_[2].value.as < std::string > ()); yylhs.value.as < DependencyPtr > () = yystack_[0].value.as < DependencyPtr > (); }
#line 1127 "parser.cpp"
    break;

  case 21:
#line 130 "parser.yy"
    { yylhs.value.as < DependencyPtr > () = std::make_shared<Dependency>(yystack_[2].value.as < std::list<PropExprPtr> > (), yystack_[1].value.as < std::list<PackageExprPtr> > ()); }
#line 1133 "parser.cpp"
    break;

  case 22:
#line 134 "parser.yy"
    { yystack_[1].value.as < std::list<PropExprPtr> > ().push_back(yystack_[0].value.as < PropExprPtr > ()); yylhs.value.as < std::list<PropExprPtr> > () = yystack_[1].value.as < std::list<PropExprPtr> > (); }
#line 1139 "parser.cpp"
    break;

  case 23:
#line 135 "parser.yy"
    { yylhs.value.as < std::list<PropExprPtr> > () = std::list<PropExprPtr>(); }
#line 1145 "parser.cpp"
    break;

  case 24:
#line 139 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[2].value.as < PropExprPtr > (); }
#line 1151 "parser.cpp"
    break;

  case 25:
#line 143 "parser.yy"
    { yystack_[1].value.as < std::list<PackageExprPtr> > ().push_back(yystack_[0].value.as < PackageExprPtr > ()); yylhs.value.as < std::list<PackageExprPtr> > () = yystack_[1].value.as < std::list<PackageExprPtr> > (); }
#line 1157 "parser.cpp"
    break;

  case 26:
#line 144 "parser.yy"
    { yylhs.value.as < std::list<PackageExprPtr> > () = std::list<PackageExprPtr>(); }
#line 1163 "parser.cpp"
    break;

  case 27:
#line 148 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1169 "parser.cpp"
    break;

  case 28:
#line 149 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1175 "parser.cpp"
    break;

  case 29:
#line 150 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1181 "parser.cpp"
    break;

  case 30:
#line 154 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<IfPackage>(yystack_[3].value.as < PropExprPtr > (), yystack_[1].value.as < PackageExprPtr > ()); }
#line 1187 "parser.cpp"
    break;

  case 31:
#line 159 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<IfElsePackage>(yystack_[7].value.as < PropExprPtr > (), yystack_[5].value.as < PackageExprPtr > (), yystack_[1].value.as < PackageExprPtr > ()); }
#line 1193 "parser.cpp"
    break;

  case 32:
#line 163 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1199 "parser.cpp"
    break;

  case 33:
#line 167 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1205 "parser.cpp"
    break;

  case 34:
#line 168 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprBinary>(BinaryType::OR, yystack_[2].value.as < PropExprPtr > (), yystack_[0].value.as < PropExprPtr > ()); }
#line 1211 "parser.cpp"
    break;

  case 35:
#line 172 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1217 "parser.cpp"
    break;

  case 36:
#line 173 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprBinary>(BinaryType::AND, yystack_[2].value.as < PropExprPtr > (), yystack_[0].value.as < PropExprPtr > ()); }
#line 1223 "parser.cpp"
    break;

  case 37:
#line 177 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1229 "parser.cpp"
    break;

  case 38:
#line 178 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprUnary>(UnaryType::NOT, yystack_[0].value.as < PropExprPtr > ()); }
#line 1235 "parser.cpp"
    break;

  case 39:
#line 182 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::EQ, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1241 "parser.cpp"
    break;

  case 40:
#line 183 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::NE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1247 "parser.cpp"
    break;

  case 41:
#line 184 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::GT, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1253 "parser.cpp"
    break;

  case 42:
#line 185 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::LT, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1259 "parser.cpp"
    break;

  case 43:
#line 186 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::GE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1265 "parser.cpp"
    break;

  case 44:
#line 187 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::LE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1271 "parser.cpp"
    break;

  case 45:
#line 188 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::IN, yystack_[0].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1277 "parser.cpp"
    break;

  case 46:
#line 189 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::NIN, yystack_[0].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1283 "parser.cpp"
    break;

  case 47:
#line 193 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1289 "parser.cpp"
    break;

  case 48:
#line 197 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1295 "parser.cpp"
    break;

  case 49:
#line 198 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprBinary>(BinaryType::OR, yystack_[2].value.as < PackageExprPtr > (), yystack_[0].value.as < PackageExprPtr > ()); }
#line 1301 "parser.cpp"
    break;

  case 50:
#line 202 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1307 "parser.cpp"
    break;

  case 51:
#line 203 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprBinary>(BinaryType::AND, yystack_[2].value.as < PackageExprPtr > (), yystack_[0].value.as < PackageExprPtr > ()); }
#line 1313 "parser.cpp"
    break;

  case 52:
#line 207 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1319 "parser.cpp"
    break;

  case 53:
#line 208 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprUnary>(UnaryType::NOT, yystack_[0].value.as < PackageExprPtr > ()); }
#line 1325 "parser.cpp"
    break;

  case 54:
#line 212 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithName>(yystack_[0].value.as < std::string > ()); }
#line 1331 "parser.cpp"
    break;

  case 55:
#line 213 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::EQ, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1337 "parser.cpp"
    break;

  case 56:
#line 214 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::NE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1343 "parser.cpp"
    break;

  case 57:
#line 215 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::GT, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1349 "parser.cpp"
    break;

  case 58:
#line 216 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::LT, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1355 "parser.cpp"
    break;

  case 59:
#line 217 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::GE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1361 "parser.cpp"
    break;

  case 60:
#line 218 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::LE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1367 "parser.cpp"
    break;

  case 61:
#line 219 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::IN, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[4].value.as < std::string > ()); }
#line 1373 "parser.cpp"
    break;

  case 62:
#line 220 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::NIN, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[4].value.as < std::string > ()); }
#line 1379 "parser.cpp"
    break;

  case 63:
#line 224 "parser.yy"
    { yylhs.value.as < RequirementPtr > () = std::make_shared<Requirement>(yystack_[0].value.as < IdentificationPtr > ()); }
#line 1385 "parser.cpp"
    break;

  case 64:
#line 228 "parser.yy"
    { yylhs.value.as < std::string > () = "version"; }
#line 1391 "parser.cpp"
    break;

  case 65:
#line 229 "parser.yy"
    { yylhs.value.as < std::string > () = "feature"; }
#line 1397 "parser.cpp"
    break;

  case 66:
#line 230 "parser.yy"
    { yylhs.value.as < std::string > () = "backend"; }
#line 1403 "parser.cpp"
    break;

  case 67:
#line 234 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1409 "parser.cpp"
    break;

  case 68:
#line 238 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1415 "parser.cpp"
    break;

  case 69:
#line 239 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1421 "parser.cpp"
    break;


#line 1425 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
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
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
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
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
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

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
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


  const signed char Parser::yypact_ninf_ = -100;

  const signed char Parser::yytable_ninf_ = -69;

  const signed char
  Parser::yypact_[] =
  {
    -100,    15,     4,  -100,  -100,  -100,     3,  -100,    13,     5,
      31,    14,  -100,    52,  -100,    32,    78,    90,    86,    91,
      97,    88,    88,  -100,    89,  -100,    71,  -100,  -100,  -100,
    -100,  -100,     9,    98,    96,    76,  -100,  -100,    30,  -100,
    -100,    94,    75,   100,  -100,    23,     9,  -100,     9,   103,
     104,     1,    29,  -100,    49,     1,  -100,  -100,  -100,  -100,
    -100,    92,    95,  -100,   106,    45,  -100,    40,   101,  -100,
       1,  -100,  -100,  -100,   108,  -100,    93,    99,  -100,    58,
      69,  -100,   107,    49,    49,    37,    97,    97,  -100,     9,
    -100,   105,     1,     1,     9,     9,     9,     9,     9,     9,
      37,    37,     7,  -100,  -100,    64,   114,   117,    44,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
     109,     9,     9,     9,     9,     9,     9,    37,    37,  -100,
     102,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   111,
       7,   112,  -100
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     0,     1,    67,     6,     0,     3,     0,     0,
       0,     0,     8,     0,     5,     0,     0,     0,     0,     0,
       2,     0,     0,    18,     0,     9,     0,    63,     7,    23,
      19,    20,    15,     0,     0,    26,    68,    69,     0,    14,
      17,     0,     0,     0,    22,     0,     0,    11,    15,     0,
       0,     0,    67,    21,     0,     0,    25,    28,    29,    27,
      47,    48,    50,    52,    54,     0,    16,     0,     0,    10,
       0,    64,    65,    66,     0,    32,    33,    35,    37,     0,
       0,    53,     0,     0,     0,     0,     0,     0,    12,    15,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    51,     0,     0,     0,     0,    24,
      34,    36,    39,    40,    43,    44,    41,    42,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      30,    55,    56,    59,    60,    57,    58,    61,    62,     0,
       0,     0,    31
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -100,  -100,  -100,  -100,  -100,     8,  -100,  -100,  -100,  -100,
     -47,  -100,  -100,  -100,   110,  -100,  -100,  -100,   -99,  -100,
    -100,    70,    35,    36,    60,  -100,  -100,    50,    51,    74,
    -100,  -100,   -79,     0,   -32
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,     9,    20,     6,    18,    19,    34,    50,
      38,    39,     7,    14,    30,    35,    44,    45,    56,    57,
      58,    74,    75,    76,    77,    78,    59,    60,    61,    62,
      63,    28,    79,    64,    65
  };

  const short
  Parser::yytable_[] =
  {
      40,    67,     8,   120,    36,    37,   105,     4,     4,    15,
      52,    37,    36,    37,    66,     3,    40,    13,    10,    80,
       8,   118,   119,    80,    11,    70,    52,    37,    27,     5,
      12,    54,    71,    72,    73,    55,    46,    53,    80,    22,
      16,   141,   108,    11,    47,    17,    46,    54,   137,   138,
      46,    55,    52,    37,    88,   -68,   -68,    40,   129,    21,
      80,    80,   112,   113,   114,   115,   116,   117,    71,    72,
      73,    86,    87,    54,    94,    95,    96,    97,    98,    99,
     121,   122,   123,   124,   125,   126,   106,   107,    23,   131,
     132,   133,   134,   135,   136,   100,   101,    24,    25,    26,
       4,    29,    32,    33,    42,    41,    43,    48,    49,    51,
      68,    85,    69,   109,    89,    83,    92,    84,    91,   127,
     102,    93,   128,   130,   140,    82,   142,   110,    81,   111,
      90,   139,    31,   103,     0,   104
  };

  const short
  Parser::yycheck_[] =
  {
      32,    48,     2,   102,     3,     4,    85,     3,     3,     9,
       3,     4,     3,     4,    46,     0,    48,     9,    15,    51,
      20,   100,   101,    55,    11,    24,     3,     4,    20,    25,
      25,    24,    31,    32,    33,    28,     6,    14,    70,     7,
       9,   140,    89,    11,    14,    31,     6,    24,   127,   128,
       6,    28,     3,     4,    14,    26,    27,    89,    14,     7,
      92,    93,    94,    95,    96,    97,    98,    99,    31,    32,
      33,    26,    27,    24,    16,    17,    18,    19,    20,    21,
      16,    17,    18,    19,    20,    21,    86,    87,    10,   121,
     122,   123,   124,   125,   126,    26,    27,     7,    12,     8,
       3,    13,    13,    32,     8,     7,    30,    13,    33,     9,
       7,     5,     8,     8,    13,    23,    23,    22,    10,     5,
      13,    22,     5,    14,    13,    55,    14,    92,    54,    93,
      70,    29,    22,    83,    -1,    84
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    35,    36,     0,     3,    25,    39,    46,    67,    37,
      15,    11,    25,    39,    47,    67,     9,    31,    40,    41,
      38,     7,     7,    10,     7,    12,     8,    39,    65,    13,
      48,    48,    13,    32,    42,    49,     3,     4,    44,    45,
      68,     7,     8,    30,    50,    51,     6,    14,    13,    33,
      43,     9,     3,    14,    24,    28,    52,    53,    54,    60,
      61,    62,    63,    64,    67,    68,    68,    44,     7,     8,
      24,    31,    32,    33,    55,    56,    57,    58,    59,    66,
      68,    63,    55,    23,    22,     5,    26,    27,    14,    13,
      58,    10,    23,    22,    16,    17,    18,    19,    20,    21,
      26,    27,    13,    61,    62,    66,    67,    67,    44,     8,
      56,    57,    68,    68,    68,    68,    68,    68,    66,    66,
      52,    16,    17,    18,    19,    20,    21,     5,     5,    14,
      14,    68,    68,    68,    68,    68,    68,    66,    66,    29,
      13,    52,    14
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      40,    41,    42,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    51,    51,    52,    52,    52,
      53,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    66,    66,    66,    67,    68,    68
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     5,     2,     0,     2,     0,     2,     0,     4,
       6,     5,     5,     5,     1,     0,     3,     1,     4,     3,
       3,     4,     2,     0,     5,     2,     0,     1,     1,     1,
       5,     9,     1,     1,     3,     1,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       1,     3,     1,     2,     1,     5,     5,     5,     5,     5,
       5,     5,     5,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "C_IDENTIFIER", "C_DOUBLE", "S_DOT",
  "S_COMMA", "S_COLON", "S_SEMI", "S_LPR", "S_RPR", "S_LSR", "S_RSR",
  "S_LBR", "S_RBR", "S_ASSIGN", "S_EQ", "S_NE", "S_GE", "S_LE", "S_GT",
  "S_LT", "S_AND", "S_OR", "S_NOT", "S_SEP", "K_IN", "K_NIN", "K_IF",
  "K_ELSE", "K_REQ", "K_V", "K_F", "K_B", "$accept", "terms",
  "definitions", "dependencies", "requirements", "package_identification",
  "property_list", "version_list", "feature_list", "backend_list",
  "tok_list", "tok_list_nonempty", "package_definition",
  "package_dependency", "dep_body", "require_list", "require_clause",
  "depend_list", "depend_clause", "if_package", "if_else_package",
  "property_expr", "prop_expr_or", "prop_expr_and", "prop_expr_not",
  "prop_expr_atom", "package_expr", "package_expr_or", "package_expr_and",
  "package_expr_not", "package_expr_atom", "requirement", "prop_name",
  "name", "str", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    71,    71,    75,    76,    80,    81,    85,    86,    90,
      94,    99,   103,   107,   111,   112,   116,   117,   121,   125,
     126,   130,   134,   135,   139,   143,   144,   148,   149,   150,
     154,   158,   163,   167,   168,   172,   173,   177,   178,   182,
     183,   184,   185,   186,   187,   188,   189,   193,   197,   198,
     202,   203,   207,   208,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   224,   228,   229,   230,   234,   238,   239
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 5 "parser.yy"
} } // depkit::yy
#line 1908 "parser.cpp"

#line 242 "parser.yy"


void depkit::yy::Parser::error(const location& loc, const std::string& msg)
{
  std::cerr << loc << ": " << msg << std::endl;
  if (lexer.size() == 0)      // if token is unknown (no match)
    lexer.matcher().winput(); // skip character
}
