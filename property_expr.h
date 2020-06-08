#pragma once

#include "property.h"
#include "type.h"

namespace depkit {
enum class PropExprType : int { None, Unary, Binary, Atom };

// `property-expr` in BNF
class PropExpr {
public:
  PropExpr(const PropExprType &type = PropExprType::None) : expr_type_(type) {}

public:
  PropExprType expr_type_;
};
using PropExprPtr = std::shared_ptr<PropExpr>;

class PropExprUnary : public PropExpr {
public:
  PropExprUnary() : PropExpr(expr_type_) {}
  PropExprUnary(UnaryType type, PropExprPtr &expr)
      : PropExpr(expr_type_), type_(type), expr_(expr) {}

public:
  static constexpr PropExprType expr_type_ = PropExprType::Unary;
  UnaryType type_;
  PropExprPtr expr_;
};
using PropExprUnaryPtr = std::shared_ptr<PropExprUnary>;

class PropExprBinary : public PropExpr {
public:
  PropExprBinary() : PropExpr(expr_type_) {}
  PropExprBinary(BinaryType type, PropExprPtr &lhs, PropExprPtr &rhs)
      : PropExpr(expr_type_), type_(type), lhs_(lhs), rhs_(rhs) {}

public:
  static constexpr PropExprType expr_type_ = PropExprType::Binary;
  BinaryType type_;
  PropExprPtr lhs_;
  PropExprPtr rhs_;
};
using PropExprBinaryPtr = std::shared_ptr<PropExprBinary>;

// `prop-expr-atom` in BNF
class PropExprAtom : public PropExpr {
public:
  PropExprAtom(AtomType type, const PropName &prop_name,
               const std::string &string)
      : PropExpr(expr_type_), type_(type), prop_name_(prop_name),
        string_(string) {}

  PropExprAtom(const PropName &prop_name, const std::string &string)
      : PropExpr(expr_type_), prop_name_(prop_name), string_(string) {}

public:
  static constexpr PropExprType expr_type_ = PropExprType::Atom;
  AtomType type_;
  PropName prop_name_; // `prop-name` in BNF
  std::string string_; // `string` in BNF
};
using PropExprAtomPtr = std::shared_ptr<PropExprAtom>;

} // namespace depkit
