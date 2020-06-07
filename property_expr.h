#pragma once

#include "property.h"
#include "type.h"

namespace depkit
{
	enum class PropExprType : int {
		None, Unary, Binary, Atom
	};

	// `property-expr` in BNF
	class PropExpr
	{
	public:
		PropExpr(const PropExprType& type = PropExprType::None): expr_type_(type) { }

	public:
		PropExprType expr_type_;
	};
	using PropExprPtr = std::shared_ptr<PropExpr>;
	
	class PropExprUnary : public PropExpr
	{
	public:
		PropExprUnary() : PropExpr(PropExprType::Unary) {}
		
	public:
		UnaryType type_;
		PropExprPtr expr_;
	};
	using PropExprUnaryPtr = std::shared_ptr<PropExprUnary>;

	class PropExprBinary : public PropExpr
	{
	public:
		PropExprBinary() : PropExpr(PropExprType::Binary) {}

	public:
		BinaryType type_;
		PropExprPtr lhs_;
		PropExprPtr rhs_;
	};
	using PropExprBinaryPtr = std::shared_ptr<PropExprBinary>;

	// `prop-expr-atom` in BNF
	class PropExprAtom : public PropExpr
	{
	public:
		PropExprAtom(const PropName& prop_name, const std::string& string)
		: PropExpr(PropExprType::Atom), prop_name_(prop_name), string_(string) { }

	public:
		AtomType type_;
		PropName prop_name_;	// `prop-name` in BNF
		std::string string_;	// `string` in BNF
	};
	using PropExprAtomPtr = std::shared_ptr<PropExprAtom>;

}
