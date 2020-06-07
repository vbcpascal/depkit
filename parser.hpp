// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hpp
 ** Define the depkit::yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 22 "parser.yy"

#include "codegen.h"
using namespace depkit;

namespace depkit::yy{
	class Lexer;
}

#line 57 "parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "parser.yy"
namespace depkit { namespace yy {
#line 173 "parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // package_definition
      char dummy1[sizeof (DefinitionPtr)];

      // package_dependency
      // dep_body
      char dummy2[sizeof (DependencyPtr)];

      // package_identification
      char dummy3[sizeof (IdentificationPtr)];

      // depend_clause
      // if_package
      // if_else_package
      // package_expr
      // package_expr_or
      // package_expr_and
      // package_expr_not
      // package_expr_atom
      char dummy4[sizeof (PackageExprPtr)];

      // require_clause
      // property_expr
      // prop_expr_or
      // prop_expr_and
      // prop_expr_not
      // prop_expr_atom
      char dummy5[sizeof (PropExprPtr)];

      // property_list
      char dummy6[sizeof (PropertyListPtr)];

      // requirement
      char dummy7[sizeof (RequirementPtr)];

      // terms
      char dummy8[sizeof (TermsPtr)];

      // C_DOUBLE
      char dummy9[sizeof (double)];

      // S_DOT
      // S_COMMA
      // S_COLON
      // S_SEMI
      // S_LPR
      // S_RPR
      // S_LSR
      // S_RSR
      // S_LBR
      // S_RBR
      // S_ASSIGN
      // S_EQ
      // S_NE
      // S_GE
      // S_LE
      // S_GT
      // S_LT
      // S_AND
      // S_OR
      // S_NOT
      // S_SEP
      // K_IN
      // K_NIN
      // K_IF
      // K_ELSE
      // K_REQ
      // K_V
      // K_F
      // K_B
      char dummy10[sizeof (int)];

      // definitions
      char dummy11[sizeof (std::list<DefinitionPtr>)];

      // dependencies
      char dummy12[sizeof (std::list<DependencyPtr>)];

      // depend_list
      char dummy13[sizeof (std::list<PackageExprPtr>)];

      // require_list
      char dummy14[sizeof (std::list<PropExprPtr>)];

      // requirements
      char dummy15[sizeof (std::list<RequirementPtr>)];

      // version_list
      // feature_list
      // backend_list
      // tok_list
      // tok_list_nonempty
      char dummy16[sizeof (std::list<std::string>)];

      // C_IDENTIFIER
      // prop_name
      // name
      // str
      char dummy17[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        C_IDENTIFIER = 258,
        C_DOUBLE = 259,
        S_DOT = 260,
        S_COMMA = 261,
        S_COLON = 262,
        S_SEMI = 263,
        S_LPR = 264,
        S_RPR = 265,
        S_LSR = 266,
        S_RSR = 267,
        S_LBR = 268,
        S_RBR = 269,
        S_ASSIGN = 270,
        S_EQ = 271,
        S_NE = 272,
        S_GE = 273,
        S_LE = 274,
        S_GT = 275,
        S_LT = 276,
        S_AND = 277,
        S_OR = 278,
        S_NOT = 279,
        S_SEP = 280,
        K_IN = 281,
        K_NIN = 282,
        K_IF = 283,
        K_ELSE = 284,
        K_REQ = 285,
        K_V = 286,
        K_F = 287,
        K_B = 288
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DefinitionPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DefinitionPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DependencyPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DependencyPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IdentificationPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IdentificationPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PackageExprPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PackageExprPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PropExprPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PropExprPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PropertyListPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PropertyListPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RequirementPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RequirementPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TermsPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TermsPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<DefinitionPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<DefinitionPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<DependencyPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<DependencyPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<PackageExprPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<PackageExprPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<PropExprPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<PropExprPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<RequirementPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<RequirementPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 46: // package_definition
        value.template destroy< DefinitionPtr > ();
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.template destroy< DependencyPtr > ();
        break;

      case 39: // package_identification
        value.template destroy< IdentificationPtr > ();
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.template destroy< PackageExprPtr > ();
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.template destroy< PropExprPtr > ();
        break;

      case 40: // property_list
        value.template destroy< PropertyListPtr > ();
        break;

      case 65: // requirement
        value.template destroy< RequirementPtr > ();
        break;

      case 35: // terms
        value.template destroy< TermsPtr > ();
        break;

      case 4: // C_DOUBLE
        value.template destroy< double > ();
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
        value.template destroy< int > ();
        break;

      case 36: // definitions
        value.template destroy< std::list<DefinitionPtr> > ();
        break;

      case 37: // dependencies
        value.template destroy< std::list<DependencyPtr> > ();
        break;

      case 51: // depend_list
        value.template destroy< std::list<PackageExprPtr> > ();
        break;

      case 49: // require_list
        value.template destroy< std::list<PropExprPtr> > ();
        break;

      case 38: // requirements
        value.template destroy< std::list<RequirementPtr> > ();
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.template destroy< std::list<std::string> > ();
        break;

      case 3: // C_IDENTIFIER
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == 0);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == 0);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::C_DOUBLE);
      }
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::C_DOUBLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::S_DOT || tok == token::S_COMMA || tok == token::S_COLON || tok == token::S_SEMI || tok == token::S_LPR || tok == token::S_RPR || tok == token::S_LSR || tok == token::S_RSR || tok == token::S_LBR || tok == token::S_RBR || tok == token::S_ASSIGN || tok == token::S_EQ || tok == token::S_NE || tok == token::S_GE || tok == token::S_LE || tok == token::S_GT || tok == token::S_LT || tok == token::S_AND || tok == token::S_OR || tok == token::S_NOT || tok == token::S_SEP || tok == token::K_IN || tok == token::K_NIN || tok == token::K_IF || tok == token::K_ELSE || tok == token::K_REQ || tok == token::K_V || tok == token::K_F || tok == token::K_B);
      }
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::S_DOT || tok == token::S_COMMA || tok == token::S_COLON || tok == token::S_SEMI || tok == token::S_LPR || tok == token::S_RPR || tok == token::S_LSR || tok == token::S_RSR || tok == token::S_LBR || tok == token::S_RBR || tok == token::S_ASSIGN || tok == token::S_EQ || tok == token::S_NE || tok == token::S_GE || tok == token::S_LE || tok == token::S_GT || tok == token::S_LT || tok == token::S_AND || tok == token::S_OR || tok == token::S_NOT || tok == token::S_SEP || tok == token::K_IN || tok == token::K_NIN || tok == token::K_IF || tok == token::K_ELSE || tok == token::K_REQ || tok == token::K_V || tok == token::K_F || tok == token::K_B);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::C_IDENTIFIER);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::C_IDENTIFIER);
      }
#endif
    };

    /// Build a parser object.
    Parser (depkit::yy::Lexer& lexer_yyarg);
    virtual ~Parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_C_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::C_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_C_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::C_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_C_DOUBLE (double v, location_type l)
      {
        return symbol_type (token::C_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_C_DOUBLE (const double& v, const location_type& l)
      {
        return symbol_type (token::C_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_DOT (int v, location_type l)
      {
        return symbol_type (token::S_DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_DOT (const int& v, const location_type& l)
      {
        return symbol_type (token::S_DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_COMMA (int v, location_type l)
      {
        return symbol_type (token::S_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_COMMA (const int& v, const location_type& l)
      {
        return symbol_type (token::S_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_COLON (int v, location_type l)
      {
        return symbol_type (token::S_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_COLON (const int& v, const location_type& l)
      {
        return symbol_type (token::S_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_SEMI (int v, location_type l)
      {
        return symbol_type (token::S_SEMI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_SEMI (const int& v, const location_type& l)
      {
        return symbol_type (token::S_SEMI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_LPR (int v, location_type l)
      {
        return symbol_type (token::S_LPR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_LPR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_LPR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_RPR (int v, location_type l)
      {
        return symbol_type (token::S_RPR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_RPR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_RPR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_LSR (int v, location_type l)
      {
        return symbol_type (token::S_LSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_LSR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_LSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_RSR (int v, location_type l)
      {
        return symbol_type (token::S_RSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_RSR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_RSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_LBR (int v, location_type l)
      {
        return symbol_type (token::S_LBR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_LBR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_LBR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_RBR (int v, location_type l)
      {
        return symbol_type (token::S_RBR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_RBR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_RBR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_ASSIGN (int v, location_type l)
      {
        return symbol_type (token::S_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_ASSIGN (const int& v, const location_type& l)
      {
        return symbol_type (token::S_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_EQ (int v, location_type l)
      {
        return symbol_type (token::S_EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_EQ (const int& v, const location_type& l)
      {
        return symbol_type (token::S_EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_NE (int v, location_type l)
      {
        return symbol_type (token::S_NE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_NE (const int& v, const location_type& l)
      {
        return symbol_type (token::S_NE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_GE (int v, location_type l)
      {
        return symbol_type (token::S_GE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_GE (const int& v, const location_type& l)
      {
        return symbol_type (token::S_GE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_LE (int v, location_type l)
      {
        return symbol_type (token::S_LE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_LE (const int& v, const location_type& l)
      {
        return symbol_type (token::S_LE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_GT (int v, location_type l)
      {
        return symbol_type (token::S_GT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_GT (const int& v, const location_type& l)
      {
        return symbol_type (token::S_GT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_LT (int v, location_type l)
      {
        return symbol_type (token::S_LT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_LT (const int& v, const location_type& l)
      {
        return symbol_type (token::S_LT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_AND (int v, location_type l)
      {
        return symbol_type (token::S_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_AND (const int& v, const location_type& l)
      {
        return symbol_type (token::S_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_OR (int v, location_type l)
      {
        return symbol_type (token::S_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_OR (const int& v, const location_type& l)
      {
        return symbol_type (token::S_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_NOT (int v, location_type l)
      {
        return symbol_type (token::S_NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_NOT (const int& v, const location_type& l)
      {
        return symbol_type (token::S_NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_SEP (int v, location_type l)
      {
        return symbol_type (token::S_SEP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S_SEP (const int& v, const location_type& l)
      {
        return symbol_type (token::S_SEP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_IN (int v, location_type l)
      {
        return symbol_type (token::K_IN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_IN (const int& v, const location_type& l)
      {
        return symbol_type (token::K_IN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_NIN (int v, location_type l)
      {
        return symbol_type (token::K_NIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_NIN (const int& v, const location_type& l)
      {
        return symbol_type (token::K_NIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_IF (int v, location_type l)
      {
        return symbol_type (token::K_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_IF (const int& v, const location_type& l)
      {
        return symbol_type (token::K_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_ELSE (int v, location_type l)
      {
        return symbol_type (token::K_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_ELSE (const int& v, const location_type& l)
      {
        return symbol_type (token::K_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_REQ (int v, location_type l)
      {
        return symbol_type (token::K_REQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_REQ (const int& v, const location_type& l)
      {
        return symbol_type (token::K_REQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_V (int v, location_type l)
      {
        return symbol_type (token::K_V, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_V (const int& v, const location_type& l)
      {
        return symbol_type (token::K_V, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_F (int v, location_type l)
      {
        return symbol_type (token::K_F, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_F (const int& v, const location_type& l)
      {
        return symbol_type (token::K_F, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_K_B (int v, location_type l)
      {
        return symbol_type (token::K_B, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_K_B (const int& v, const location_type& l)
      {
        return symbol_type (token::K_B, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const unsigned char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 126,     ///< Last index in yytable_.
      yynnts_ = 35,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 34  ///< Number of tokens.
    };


    // User arguments.
    depkit::yy::Lexer& lexer;
  };

  inline
  Parser::token_number_type
  Parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    const unsigned user_token_number_max_ = 288;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 46: // package_definition
        value.move< DefinitionPtr > (std::move (that.value));
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.move< DependencyPtr > (std::move (that.value));
        break;

      case 39: // package_identification
        value.move< IdentificationPtr > (std::move (that.value));
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.move< PackageExprPtr > (std::move (that.value));
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.move< PropExprPtr > (std::move (that.value));
        break;

      case 40: // property_list
        value.move< PropertyListPtr > (std::move (that.value));
        break;

      case 65: // requirement
        value.move< RequirementPtr > (std::move (that.value));
        break;

      case 35: // terms
        value.move< TermsPtr > (std::move (that.value));
        break;

      case 4: // C_DOUBLE
        value.move< double > (std::move (that.value));
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
        value.move< int > (std::move (that.value));
        break;

      case 36: // definitions
        value.move< std::list<DefinitionPtr> > (std::move (that.value));
        break;

      case 37: // dependencies
        value.move< std::list<DependencyPtr> > (std::move (that.value));
        break;

      case 51: // depend_list
        value.move< std::list<PackageExprPtr> > (std::move (that.value));
        break;

      case 49: // require_list
        value.move< std::list<PropExprPtr> > (std::move (that.value));
        break;

      case 38: // requirements
        value.move< std::list<RequirementPtr> > (std::move (that.value));
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.move< std::list<std::string> > (std::move (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 46: // package_definition
        value.copy< DefinitionPtr > (YY_MOVE (that.value));
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.copy< DependencyPtr > (YY_MOVE (that.value));
        break;

      case 39: // package_identification
        value.copy< IdentificationPtr > (YY_MOVE (that.value));
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.copy< PackageExprPtr > (YY_MOVE (that.value));
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.copy< PropExprPtr > (YY_MOVE (that.value));
        break;

      case 40: // property_list
        value.copy< PropertyListPtr > (YY_MOVE (that.value));
        break;

      case 65: // requirement
        value.copy< RequirementPtr > (YY_MOVE (that.value));
        break;

      case 35: // terms
        value.copy< TermsPtr > (YY_MOVE (that.value));
        break;

      case 4: // C_DOUBLE
        value.copy< double > (YY_MOVE (that.value));
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
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 36: // definitions
        value.copy< std::list<DefinitionPtr> > (YY_MOVE (that.value));
        break;

      case 37: // dependencies
        value.copy< std::list<DependencyPtr> > (YY_MOVE (that.value));
        break;

      case 51: // depend_list
        value.copy< std::list<PackageExprPtr> > (YY_MOVE (that.value));
        break;

      case 49: // require_list
        value.copy< std::list<PropExprPtr> > (YY_MOVE (that.value));
        break;

      case 38: // requirements
        value.copy< std::list<RequirementPtr> > (YY_MOVE (that.value));
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.copy< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 3: // C_IDENTIFIER
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 46: // package_definition
        value.move< DefinitionPtr > (YY_MOVE (s.value));
        break;

      case 47: // package_dependency
      case 48: // dep_body
        value.move< DependencyPtr > (YY_MOVE (s.value));
        break;

      case 39: // package_identification
        value.move< IdentificationPtr > (YY_MOVE (s.value));
        break;

      case 52: // depend_clause
      case 53: // if_package
      case 54: // if_else_package
      case 60: // package_expr
      case 61: // package_expr_or
      case 62: // package_expr_and
      case 63: // package_expr_not
      case 64: // package_expr_atom
        value.move< PackageExprPtr > (YY_MOVE (s.value));
        break;

      case 50: // require_clause
      case 55: // property_expr
      case 56: // prop_expr_or
      case 57: // prop_expr_and
      case 58: // prop_expr_not
      case 59: // prop_expr_atom
        value.move< PropExprPtr > (YY_MOVE (s.value));
        break;

      case 40: // property_list
        value.move< PropertyListPtr > (YY_MOVE (s.value));
        break;

      case 65: // requirement
        value.move< RequirementPtr > (YY_MOVE (s.value));
        break;

      case 35: // terms
        value.move< TermsPtr > (YY_MOVE (s.value));
        break;

      case 4: // C_DOUBLE
        value.move< double > (YY_MOVE (s.value));
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
        value.move< int > (YY_MOVE (s.value));
        break;

      case 36: // definitions
        value.move< std::list<DefinitionPtr> > (YY_MOVE (s.value));
        break;

      case 37: // dependencies
        value.move< std::list<DependencyPtr> > (YY_MOVE (s.value));
        break;

      case 51: // depend_list
        value.move< std::list<PackageExprPtr> > (YY_MOVE (s.value));
        break;

      case 49: // require_list
        value.move< std::list<PropExprPtr> > (YY_MOVE (s.value));
        break;

      case 38: // requirements
        value.move< std::list<RequirementPtr> > (YY_MOVE (s.value));
        break;

      case 41: // version_list
      case 42: // feature_list
      case 43: // backend_list
      case 44: // tok_list
      case 45: // tok_list_nonempty
        value.move< std::list<std::string> > (YY_MOVE (s.value));
        break;

      case 3: // C_IDENTIFIER
      case 66: // prop_name
      case 67: // name
      case 68: // str
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  Parser::token_type
  Parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
    };
    return token_type (yytoken_number_[type]);
  }

#line 5 "parser.yy"
} } // depkit::yy
#line 2434 "parser.hpp"





#endif // !YY_YY_PARSER_HPP_INCLUDED
