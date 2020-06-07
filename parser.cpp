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
#line 12 "parser.yy"

#include <cstdio>
#include <map>
#include <vector>

#line 44 "parser.cpp"




#include "parser.hpp"


// Unqualified %code blocks.
#line 29 "parser.yy"

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
#line 137 "parser.cpp"


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
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 44: // package_definition
        value.YY_MOVE_OR_COPY< DefinitionPtr > (YY_MOVE (that.value));
        break;

      case 45: // package_dependency
      case 46: // dep_body
        value.YY_MOVE_OR_COPY< DependencyPtr > (YY_MOVE (that.value));
        break;

      case 38: // package_identification
        value.YY_MOVE_OR_COPY< IdentificationPtr > (YY_MOVE (that.value));
        break;

      case 50: // depend_clause
      case 51: // if_package
      case 52: // if_else_package
      case 58: // package_expr
      case 59: // package_expr_or
      case 60: // package_expr_and
      case 61: // package_expr_not
      case 62: // package_expr_atom
        value.YY_MOVE_OR_COPY< PackageExprPtr > (YY_MOVE (that.value));
        break;

      case 48: // require_clause
      case 53: // property_expr
      case 54: // prop_expr_or
      case 55: // prop_expr_and
      case 56: // prop_expr_not
      case 57: // prop_expr_atom
        value.YY_MOVE_OR_COPY< PropExprPtr > (YY_MOVE (that.value));
        break;

      case 39: // property_list
        value.YY_MOVE_OR_COPY< PropertyListPtr > (YY_MOVE (that.value));
        break;

      case 63: // requirement
        value.YY_MOVE_OR_COPY< RequirementPtr > (YY_MOVE (that.value));
        break;

      case 34: // terms
        value.YY_MOVE_OR_COPY< TermsPtr > (YY_MOVE (that.value));
        break;

      case 4: // C_DOUBLE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
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
      case 25: // K_IN
      case 26: // K_NIN
      case 27: // K_IF
      case 28: // K_ELSE
      case 29: // K_REQ
      case 30: // K_V
      case 31: // K_F
      case 32: // K_B
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 42: // backend_list
        value.YY_MOVE_OR_COPY< std::list<Backend> > (YY_MOVE (that.value));
        break;

      case 35: // definitions
        value.YY_MOVE_OR_COPY< std::list<DefinitionPtr> > (YY_MOVE (that.value));
        break;

      case 36: // dependencies
        value.YY_MOVE_OR_COPY< std::list<DependencyPtr> > (YY_MOVE (that.value));
        break;

      case 41: // feature_list
        value.YY_MOVE_OR_COPY< std::list<Feature> > (YY_MOVE (that.value));
        break;

      case 49: // depend_list
        value.YY_MOVE_OR_COPY< std::list<PackageExprPtr> > (YY_MOVE (that.value));
        break;

      case 47: // require_list
        value.YY_MOVE_OR_COPY< std::list<PropExprPtr> > (YY_MOVE (that.value));
        break;

      case 37: // requirements
        value.YY_MOVE_OR_COPY< std::list<RequirementPtr> > (YY_MOVE (that.value));
        break;

      case 40: // version_list
        value.YY_MOVE_OR_COPY< std::list<Version> > (YY_MOVE (that.value));
        break;

      case 43: // tok_list
        value.YY_MOVE_OR_COPY< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 64: // prop_name
      case 65: // name
      case 66: // str
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
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 44: // package_definition
        value.move< DefinitionPtr > (YY_MOVE (that.value));
        break;

      case 45: // package_dependency
      case 46: // dep_body
        value.move< DependencyPtr > (YY_MOVE (that.value));
        break;

      case 38: // package_identification
        value.move< IdentificationPtr > (YY_MOVE (that.value));
        break;

      case 50: // depend_clause
      case 51: // if_package
      case 52: // if_else_package
      case 58: // package_expr
      case 59: // package_expr_or
      case 60: // package_expr_and
      case 61: // package_expr_not
      case 62: // package_expr_atom
        value.move< PackageExprPtr > (YY_MOVE (that.value));
        break;

      case 48: // require_clause
      case 53: // property_expr
      case 54: // prop_expr_or
      case 55: // prop_expr_and
      case 56: // prop_expr_not
      case 57: // prop_expr_atom
        value.move< PropExprPtr > (YY_MOVE (that.value));
        break;

      case 39: // property_list
        value.move< PropertyListPtr > (YY_MOVE (that.value));
        break;

      case 63: // requirement
        value.move< RequirementPtr > (YY_MOVE (that.value));
        break;

      case 34: // terms
        value.move< TermsPtr > (YY_MOVE (that.value));
        break;

      case 4: // C_DOUBLE
        value.move< double > (YY_MOVE (that.value));
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
      case 25: // K_IN
      case 26: // K_NIN
      case 27: // K_IF
      case 28: // K_ELSE
      case 29: // K_REQ
      case 30: // K_V
      case 31: // K_F
      case 32: // K_B
        value.move< int > (YY_MOVE (that.value));
        break;

      case 42: // backend_list
        value.move< std::list<Backend> > (YY_MOVE (that.value));
        break;

      case 35: // definitions
        value.move< std::list<DefinitionPtr> > (YY_MOVE (that.value));
        break;

      case 36: // dependencies
        value.move< std::list<DependencyPtr> > (YY_MOVE (that.value));
        break;

      case 41: // feature_list
        value.move< std::list<Feature> > (YY_MOVE (that.value));
        break;

      case 49: // depend_list
        value.move< std::list<PackageExprPtr> > (YY_MOVE (that.value));
        break;

      case 47: // require_list
        value.move< std::list<PropExprPtr> > (YY_MOVE (that.value));
        break;

      case 37: // requirements
        value.move< std::list<RequirementPtr> > (YY_MOVE (that.value));
        break;

      case 40: // version_list
        value.move< std::list<Version> > (YY_MOVE (that.value));
        break;

      case 43: // tok_list
        value.move< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 64: // prop_name
      case 65: // name
      case 66: // str
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
      case 44: // package_definition
        value.move< DefinitionPtr > (that.value);
        break;

      case 45: // package_dependency
      case 46: // dep_body
        value.move< DependencyPtr > (that.value);
        break;

      case 38: // package_identification
        value.move< IdentificationPtr > (that.value);
        break;

      case 50: // depend_clause
      case 51: // if_package
      case 52: // if_else_package
      case 58: // package_expr
      case 59: // package_expr_or
      case 60: // package_expr_and
      case 61: // package_expr_not
      case 62: // package_expr_atom
        value.move< PackageExprPtr > (that.value);
        break;

      case 48: // require_clause
      case 53: // property_expr
      case 54: // prop_expr_or
      case 55: // prop_expr_and
      case 56: // prop_expr_not
      case 57: // prop_expr_atom
        value.move< PropExprPtr > (that.value);
        break;

      case 39: // property_list
        value.move< PropertyListPtr > (that.value);
        break;

      case 63: // requirement
        value.move< RequirementPtr > (that.value);
        break;

      case 34: // terms
        value.move< TermsPtr > (that.value);
        break;

      case 4: // C_DOUBLE
        value.move< double > (that.value);
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
      case 25: // K_IN
      case 26: // K_NIN
      case 27: // K_IF
      case 28: // K_ELSE
      case 29: // K_REQ
      case 30: // K_V
      case 31: // K_F
      case 32: // K_B
        value.move< int > (that.value);
        break;

      case 42: // backend_list
        value.move< std::list<Backend> > (that.value);
        break;

      case 35: // definitions
        value.move< std::list<DefinitionPtr> > (that.value);
        break;

      case 36: // dependencies
        value.move< std::list<DependencyPtr> > (that.value);
        break;

      case 41: // feature_list
        value.move< std::list<Feature> > (that.value);
        break;

      case 49: // depend_list
        value.move< std::list<PackageExprPtr> > (that.value);
        break;

      case 47: // require_list
        value.move< std::list<PropExprPtr> > (that.value);
        break;

      case 37: // requirements
        value.move< std::list<RequirementPtr> > (that.value);
        break;

      case 40: // version_list
        value.move< std::list<Version> > (that.value);
        break;

      case 43: // tok_list
        value.move< std::list<std::string> > (that.value);
        break;

      case 3: // C_IDENTIFIER
      case 64: // prop_name
      case 65: // name
      case 66: // str
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

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
        << ' ' << yytname_[yytype] << " (";
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
      case 44: // package_definition
        yylhs.value.emplace< DefinitionPtr > ();
        break;

      case 45: // package_dependency
      case 46: // dep_body
        yylhs.value.emplace< DependencyPtr > ();
        break;

      case 38: // package_identification
        yylhs.value.emplace< IdentificationPtr > ();
        break;

      case 50: // depend_clause
      case 51: // if_package
      case 52: // if_else_package
      case 58: // package_expr
      case 59: // package_expr_or
      case 60: // package_expr_and
      case 61: // package_expr_not
      case 62: // package_expr_atom
        yylhs.value.emplace< PackageExprPtr > ();
        break;

      case 48: // require_clause
      case 53: // property_expr
      case 54: // prop_expr_or
      case 55: // prop_expr_and
      case 56: // prop_expr_not
      case 57: // prop_expr_atom
        yylhs.value.emplace< PropExprPtr > ();
        break;

      case 39: // property_list
        yylhs.value.emplace< PropertyListPtr > ();
        break;

      case 63: // requirement
        yylhs.value.emplace< RequirementPtr > ();
        break;

      case 34: // terms
        yylhs.value.emplace< TermsPtr > ();
        break;

      case 4: // C_DOUBLE
        yylhs.value.emplace< double > ();
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
      case 25: // K_IN
      case 26: // K_NIN
      case 27: // K_IF
      case 28: // K_ELSE
      case 29: // K_REQ
      case 30: // K_V
      case 31: // K_F
      case 32: // K_B
        yylhs.value.emplace< int > ();
        break;

      case 42: // backend_list
        yylhs.value.emplace< std::list<Backend> > ();
        break;

      case 35: // definitions
        yylhs.value.emplace< std::list<DefinitionPtr> > ();
        break;

      case 36: // dependencies
        yylhs.value.emplace< std::list<DependencyPtr> > ();
        break;

      case 41: // feature_list
        yylhs.value.emplace< std::list<Feature> > ();
        break;

      case 49: // depend_list
        yylhs.value.emplace< std::list<PackageExprPtr> > ();
        break;

      case 47: // require_list
        yylhs.value.emplace< std::list<PropExprPtr> > ();
        break;

      case 37: // requirements
        yylhs.value.emplace< std::list<RequirementPtr> > ();
        break;

      case 40: // version_list
        yylhs.value.emplace< std::list<Version> > ();
        break;

      case 43: // tok_list
        yylhs.value.emplace< std::list<std::string> > ();
        break;

      case 3: // C_IDENTIFIER
      case 64: // prop_name
      case 65: // name
      case 66: // str
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
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
#line 70 "parser.yy"
    { yylhs.value.as < TermsPtr > () = std::make_shared<Terms>(yystack_[2].value.as < std::list<DefinitionPtr> > (), yystack_[1].value.as < std::list<DependencyPtr> > (), yystack_[0].value.as < std::list<RequirementPtr> > ()); }
#line 988 "parser.cpp"
    break;

  case 3:
#line 74 "parser.yy"
    { yystack_[1].value.as < std::list<DefinitionPtr> > ().push_back(yystack_[0].value.as < DefinitionPtr > ()); yylhs.value.as < std::list<DefinitionPtr> > () = yystack_[1].value.as < std::list<DefinitionPtr> > (); }
#line 994 "parser.cpp"
    break;

  case 4:
#line 75 "parser.yy"
    { yylhs.value.as < std::list<DefinitionPtr> > () = std::list<DefinitonPtr>(); }
#line 1000 "parser.cpp"
    break;

  case 5:
#line 79 "parser.yy"
    { yystack_[1].value.as < std::list<DependencyPtr> > ().push_back(yystack_[0].value.as < DependencyPtr > ()); yylhs.value.as < std::list<DependencyPtr> > () = yystack_[1].value.as < std::list<DependencyPtr> > (); }
#line 1006 "parser.cpp"
    break;

  case 6:
#line 80 "parser.yy"
    { yylhs.value.as < std::list<DependencyPtr> > () = std::list<DependencyPtr>(); }
#line 1012 "parser.cpp"
    break;

  case 7:
#line 84 "parser.yy"
    { yystack_[1].value.as < std::list<RequirementPtr> > ().push_back(yystack_[0].value.as < RequirementPtr > ()); yylhs.value.as < std::list<RequirementPtr> > () = yystack_[1].value.as < std::list<RequirementPtr> > (); }
#line 1018 "parser.cpp"
    break;

  case 8:
#line 85 "parser.yy"
    { yylhs.value.as < std::list<RequirementPtr> > () = std::list<RequirementPtr>(); }
#line 1024 "parser.cpp"
    break;

  case 9:
#line 89 "parser.yy"
    { yylhs.value.as < IdentificationPtr > () = std::make_shared<Identification>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < PropertyListPtr > ()); }
#line 1030 "parser.cpp"
    break;

  case 10:
#line 94 "parser.yy"
    { yylhs.value.as < PropertyListPtr > () = std::make_shared<PropertyList>(yystack_[4].value.as < std::list<Version> > (), yystack_[2].value.as < std::list<Feature> > (), yystack_[0].value.as < std::list<Backend> > ()); }
#line 1036 "parser.cpp"
    break;

  case 11:
#line 98 "parser.yy"
    { yylhs.value.as < std::list<Version> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1042 "parser.cpp"
    break;

  case 12:
#line 102 "parser.yy"
    { yylhs.value.as < std::list<Feature> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1048 "parser.cpp"
    break;

  case 13:
#line 106 "parser.yy"
    { yylhs.value.as < std::list<Backend> > () = yystack_[1].value.as < std::list<std::string> > (); }
#line 1054 "parser.cpp"
    break;

  case 14:
#line 110 "parser.yy"
    { yystack_[2].value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > (); }
#line 1060 "parser.cpp"
    break;

  case 15:
#line 111 "parser.yy"
    { yylhs.value.as < std::list<std::string> > () = std::list<std::string>(); }
#line 1066 "parser.cpp"
    break;

  case 16:
#line 115 "parser.yy"
    { yylhs.value.as < DefinitionPtr > () = std::make_shared<Definition>(yystack_[3].value.as < IdentificationPtr > ()); }
#line 1072 "parser.cpp"
    break;

  case 17:
#line 119 "parser.yy"
    { yystack_[0].value.as < DependencyPtr > ()->identification_ = yystack_[2].value.as < IdentificationPtr > (); yylhs.value.as < DependencyPtr > () = yystack_[0].value.as < DependencyPtr > (); }
#line 1078 "parser.cpp"
    break;

  case 18:
#line 123 "parser.yy"
    { yylhs.value.as < DependencyPtr > () = std::make_shared<Dependency>(yystack_[2].value.as < std::list<PropExprPtr> > (), yystack_[1].value.as < std::list<PackageExprPtr> > ()); }
#line 1084 "parser.cpp"
    break;

  case 19:
#line 127 "parser.yy"
    { yystack_[1].value.as < std::list<PropExprPtr> > ().push_back(yystack_[0].value.as < PropExprPtr > ()); yylhs.value.as < std::list<PropExprPtr> > () = yystack_[1].value.as < std::list<PropExprPtr> > (); }
#line 1090 "parser.cpp"
    break;

  case 20:
#line 128 "parser.yy"
    { yylhs.value.as < std::list<PropExprPtr> > () = std::list<PropExprPtr>(); }
#line 1096 "parser.cpp"
    break;

  case 21:
#line 132 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[2].value.as < PropExprPtr > (); }
#line 1102 "parser.cpp"
    break;

  case 22:
#line 136 "parser.yy"
    { yystack_[1].value.as < PackageExprPtr > ().push_back(yystack_[0].value.as < std::list<PackageExprPtr> > ()); yylhs.value.as < std::list<PackageExprPtr> > () = yystack_[1].value.as < PackageExprPtr > (); }
#line 1108 "parser.cpp"
    break;

  case 23:
#line 137 "parser.yy"
    { yylhs.value.as < std::list<PackageExprPtr> > () = std::list<PackageExprPtr>(); }
#line 1114 "parser.cpp"
    break;

  case 24:
#line 141 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1120 "parser.cpp"
    break;

  case 25:
#line 142 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1126 "parser.cpp"
    break;

  case 26:
#line 143 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1132 "parser.cpp"
    break;

  case 27:
#line 147 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<IfPackagePtr>(yystack_[3].value.as < PropExprPtr > (), yystack_[1].value.as < PackageExprPtr > ()); }
#line 1138 "parser.cpp"
    break;

  case 28:
#line 152 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<IfElsePackagePtr>(yystack_[7].value.as < PropExprPtr > (), yystack_[5].value.as < PackageExprPtr > (), yystack_[1].value.as < PackageExprPtr > ()); }
#line 1144 "parser.cpp"
    break;

  case 29:
#line 156 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1150 "parser.cpp"
    break;

  case 30:
#line 160 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1156 "parser.cpp"
    break;

  case 31:
#line 161 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprBinary>(BinaryType::OR, yystack_[2].value.as < PropExprPtr > (), yystack_[0].value.as < PropExprPtr > ()); }
#line 1162 "parser.cpp"
    break;

  case 32:
#line 165 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1168 "parser.cpp"
    break;

  case 33:
#line 166 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprBinary>(BinaryType::AND, yystack_[2].value.as < PropExprPtr > (), yystack_[0].value.as < PropExprPtr > ()); }
#line 1174 "parser.cpp"
    break;

  case 34:
#line 170 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = yystack_[0].value.as < PropExprPtr > (); }
#line 1180 "parser.cpp"
    break;

  case 35:
#line 171 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprBinary>(UnaryType::NOT, yystack_[0].value.as < PropExprPtr > ()); }
#line 1186 "parser.cpp"
    break;

  case 36:
#line 175 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::EQ, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1192 "parser.cpp"
    break;

  case 37:
#line 176 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::NE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1198 "parser.cpp"
    break;

  case 38:
#line 177 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::GT, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1204 "parser.cpp"
    break;

  case 39:
#line 178 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::LT, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1210 "parser.cpp"
    break;

  case 40:
#line 179 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::GE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1216 "parser.cpp"
    break;

  case 41:
#line 180 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::LE, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1222 "parser.cpp"
    break;

  case 42:
#line 181 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::IN, yystack_[0].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1228 "parser.cpp"
    break;

  case 43:
#line 182 "parser.yy"
    { yylhs.value.as < PropExprPtr > () = std::make_shared<PropExprAtom>(AtomType::NIN, yystack_[0].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1234 "parser.cpp"
    break;

  case 44:
#line 186 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1240 "parser.cpp"
    break;

  case 45:
#line 190 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1246 "parser.cpp"
    break;

  case 46:
#line 191 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprBinary>(BinaryType::OR, yystack_[2].value.as < PackageExprPtr > (), yystack_[0].value.as < PackageExprPtr > ()); }
#line 1252 "parser.cpp"
    break;

  case 47:
#line 195 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1258 "parser.cpp"
    break;

  case 48:
#line 196 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprBinary>(BinaryType::AND, yystack_[2].value.as < PackageExprPtr > (), yystack_[0].value.as < PackageExprPtr > ()); }
#line 1264 "parser.cpp"
    break;

  case 49:
#line 200 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = yystack_[0].value.as < PackageExprPtr > (); }
#line 1270 "parser.cpp"
    break;

  case 50:
#line 201 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprBinary>(UnaryType::NOT, yystack_[0].value.as < PackageExprPtr > ()); }
#line 1276 "parser.cpp"
    break;

  case 51:
#line 205 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithName>(yystack_[0].value.as < std::string > ()); }
#line 1282 "parser.cpp"
    break;

  case 52:
#line 206 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::EQ, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1288 "parser.cpp"
    break;

  case 53:
#line 207 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::NE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1294 "parser.cpp"
    break;

  case 54:
#line 208 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::GT, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1300 "parser.cpp"
    break;

  case 55:
#line 209 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::LT, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1306 "parser.cpp"
    break;

  case 56:
#line 210 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::GE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1312 "parser.cpp"
    break;

  case 57:
#line 211 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::LE, yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1318 "parser.cpp"
    break;

  case 58:
#line 212 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::IN, yystack_[0].value.as < std::string > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1324 "parser.cpp"
    break;

  case 59:
#line 213 "parser.yy"
    { yylhs.value.as < PackageExprPtr > () = std::make_shared<PackageExprAtomWithProp>(AtomType::NIN, yystack_[0].value.as < std::string > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1330 "parser.cpp"
    break;

  case 60:
#line 217 "parser.yy"
    { yylhs.value.as < RequirementPtr > () = std::make_shared<Requirement>(yystack_[0].value.as < IdentificationPtr > ()); }
#line 1336 "parser.cpp"
    break;

  case 61:
#line 221 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1342 "parser.cpp"
    break;

  case 62:
#line 225 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1348 "parser.cpp"
    break;

  case 63:
#line 229 "parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1354 "parser.cpp"
    break;


#line 1358 "parser.cpp"

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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


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

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


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
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -73;

  const signed char Parser::yytable_ninf_ = -64;

  const signed char
  Parser::yypact_[] =
  {
     -73,    17,    21,   -73,   -73,    21,     5,   -73,    14,    21,
      53,   -73,    19,    31,   -73,   -73,    49,    54,    56,    61,
      66,   -73,   -73,   -73,    68,   -73,    52,     2,   -73,    75,
      76,    25,     8,    10,    77,   -73,    71,     6,   -73,   -73,
     -73,   -73,    64,    67,   -73,    83,    30,     0,    78,    58,
     -73,    25,    10,    79,   -73,    70,    72,   -73,    20,    32,
      10,   -73,   -73,     8,     8,    92,    21,    21,    93,   -73,
     -73,    90,   -73,   -73,     6,    10,    10,    93,    93,    93,
      93,    93,    93,    92,    92,    88,   -73,   -73,   -73,    51,
      94,    95,   -73,   -73,     4,    89,    87,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,    96,    93,    93,
      93,    93,    93,    93,    92,    92,   -73,   -73,    80,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     9,    97,
     -73,     6,    91,   -73
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     6,     1,    62,     8,     0,     3,     0,     2,
       0,     5,     0,     0,    60,     7,     0,     0,     0,     0,
       0,    20,    17,    16,     0,     9,     0,    23,    15,     0,
       0,    62,     0,     0,     0,    19,     0,    23,    25,    26,
      24,    44,    45,    47,    49,    51,     0,     0,     0,     0,
      50,    61,     0,     0,    29,    30,    32,    34,     0,     0,
       0,    18,    22,     0,     0,     0,     0,     0,     0,    11,
      15,     0,    10,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    48,    61,     0,
       0,     0,    63,    14,     0,     0,     0,    31,    33,    36,
      37,    40,    41,    38,    39,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    15,    27,    21,
      52,    53,    56,    57,    54,    55,    58,    59,     0,     0,
      13,     0,     0,    28
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -73,   -73,   -73,   -73,   -73,     7,   -73,   -73,   -73,   -73,
     -63,   -73,   -73,   -73,   -73,   -73,    69,   -72,   -73,   -73,
      43,    34,    35,    55,   -73,   -73,    50,    48,    82,   -73,
     -73,   -62,    -1,   -33
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,     9,     6,    19,    20,    30,    72,
      47,     7,    11,    22,    27,    35,    36,    37,    38,    39,
      53,    54,    55,    56,    57,    40,    41,    42,    43,    44,
      15,    58,    45,    46
  };

  const short
  Parser::yytable_[] =
  {
      59,     8,    96,    89,     8,    31,    68,    94,     8,    31,
      68,    31,    10,    51,    69,    68,    14,     3,   116,    59,
      12,   105,   106,   130,     4,    13,    32,    59,    17,    33,
      32,    34,    32,    33,    52,    93,    77,    78,    79,    80,
      81,    82,    59,    59,    99,   100,   101,   102,   103,   104,
     -63,   -63,   126,   127,   128,    66,    67,    83,    84,   132,
      16,    18,    21,    24,    23,    90,    91,   108,   109,   110,
     111,   112,   113,    25,    26,   120,   121,   122,   123,   124,
     125,    28,    48,    29,    49,    61,    60,    63,    65,    64,
      71,    70,    74,    75,    76,    88,    92,    95,   107,   114,
     115,   118,   117,    85,   119,   133,    62,    73,   129,    97,
     131,    98,    87,    86,    50
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      33,     2,    74,    65,     5,     3,     6,    70,     9,     3,
       6,     3,     5,     3,    14,     6,     9,     0,    14,    52,
      15,    83,    84,    14,     3,    11,    24,    60,     9,    27,
      24,    29,    24,    27,    24,    68,    16,    17,    18,    19,
      20,    21,    75,    76,    77,    78,    79,    80,    81,    82,
      25,    26,   114,   115,   117,    25,    26,    25,    26,   131,
       7,    30,    13,     7,    10,    66,    67,    16,    17,    18,
      19,    20,    21,    12,     8,   108,   109,   110,   111,   112,
     113,    13,     7,    31,     8,    14,     9,    23,     5,    22,
      32,    13,    13,    23,    22,     3,     3,     7,    10,     5,
       5,    14,    13,    60,     8,    14,    37,    52,    28,    75,
      13,    76,    64,    63,    32
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    34,    35,     0,     3,    36,    38,    44,    65,    37,
      38,    45,    15,    11,    38,    63,     7,     9,    30,    39,
      40,    13,    46,    10,     7,    12,     8,    47,    13,    31,
      41,     3,    24,    27,    29,    48,    49,    50,    51,    52,
      58,    59,    60,    61,    62,    65,    66,    43,     7,     8,
      61,     3,    24,    53,    54,    55,    56,    57,    64,    66,
       9,    14,    49,    23,    22,     5,    25,    26,     6,    14,
      13,    32,    42,    56,    13,    23,    22,    16,    17,    18,
      19,    20,    21,    25,    26,    53,    59,    60,     3,    64,
      65,    65,     3,    66,    43,     7,    50,    54,    55,    66,
      66,    66,    66,    66,    66,    64,    64,    10,    16,    17,
      18,    19,    20,    21,     5,     5,    14,    13,    14,     8,
      66,    66,    66,    66,    66,    66,    64,    64,    43,    28,
      14,    13,    50,    14
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      39,    40,    41,    42,    43,    43,    44,    45,    46,    47,
      47,    48,    49,    49,    50,    50,    50,    51,    52,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    65,    66
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     3,     2,     0,     2,     0,     2,     0,     4,
       5,     5,     5,     5,     3,     0,     4,     3,     4,     2,
       0,     5,     2,     0,     1,     1,     1,     5,     9,     1,
       1,     3,     1,     3,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     1,     3,     1,
       2,     1,     5,     5,     5,     5,     5,     5,     5,     5,
       1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "C_IDENTIFIER", "C_DOUBLE", "S_DOT",
  "S_COMMA", "S_COLON", "S_SEMI", "S_LPR", "S_RPR", "S_LSR", "S_RSR",
  "S_LBR", "S_RBR", "S_ASSIGN", "S_EQ", "S_NE", "S_GE", "S_LE", "S_GT",
  "S_LT", "S_AND", "S_OR", "S_NOT", "K_IN", "K_NIN", "K_IF", "K_ELSE",
  "K_REQ", "K_V", "K_F", "K_B", "$accept", "terms", "definitions",
  "dependencies", "requirements", "package_identification",
  "property_list", "version_list", "feature_list", "backend_list",
  "tok_list", "package_definition", "package_dependency", "dep_body",
  "require_list", "require_clause", "depend_list", "depend_clause",
  "if_package", "if_else_package", "property_expr", "prop_expr_or",
  "prop_expr_and", "prop_expr_not", "prop_expr_atom", "package_expr",
  "package_expr_or", "package_expr_and", "package_expr_not",
  "package_expr_atom", "requirement", "prop_name", "name", "str", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    70,    70,    74,    75,    79,    80,    84,    85,    89,
      93,    98,   102,   106,   110,   111,   115,   119,   123,   127,
     128,   132,   136,   137,   141,   142,   143,   147,   151,   156,
     160,   161,   165,   166,   170,   171,   175,   176,   177,   178,
     179,   180,   181,   182,   186,   190,   191,   195,   196,   200,
     201,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     217,   221,   225,   229
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
#line 1739 "parser.cpp"

#line 232 "parser.yy"


void depkit::yy::Parser::error(const std::string& msg)
{
	std::cerr << msg << std::endl;
	if (lexer.size() == 0) 
		lexer.matcher().winput();
}
