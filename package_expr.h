#pragma once

#include "property.h"
#include "property_expr.h"
#include "type.h"

namespace depkit
{
	enum class PackageExprType : int {
		None,
		If,
		IfElse,
		Unary,
		Binary,
		AtomWithName,
		AtomWithProp,
	};

	// `depend-clause` and `package-expr` in BNF
	class PackageExpr
	{
	public:
		PackageExpr(const PackageExprType& type = PackageExprType::None) : expr_type_(type) { }

	public:
		PackageExprType expr_type_;
	};
	using PackageExprPtr = std::shared_ptr<PackageExpr>;

	// `if-package` in BNF
	class IfPackage : public PackageExpr
	{
	public:
		IfPackage() : PackageExpr(PackageExprType::If) { }
		IfPackage(PropExprPtr& cond, PackageExprPtr& body)
			: PackageExpr(PackageExprType::If), cond_(cond), body_(body) { }
		
	public:
		PropExprPtr cond_;
		PackageExprPtr body_;
	};
	using IfPackagePtr = std::shared_ptr<IfPackage>;

	// `if-else-package` in BNF
	class IfElsePackage : public PackageExpr
	{
	public:
		IfElsePackage() : PackageExpr(PackageExprType::IfElse) { }
		IfElsePackage(PropExprPtr& cond, PackageExprPtr& body, PackageExprPtr& else_body)
			: PackageExpr(PackageExprType::If), cond_(cond), body_(body), else_body_(else_body) { }

	public:
		PropExprPtr cond_;
		PackageExprPtr body_;
		PackageExprPtr else_body_;
	};
	using IfElsePackagePtr = std::shared_ptr<IfElsePackage>;
	
	// `package-expr` with ! in BNF
	class PackageExprUnary : public PackageExpr
	{
	public:
		PackageExprUnary() : PackageExpr(PackageExprType::Unary) {}

	public:
		UnaryType type_;
		PackageExprPtr expr_;
	};
	using PackageExprUnaryPtr = std::shared_ptr<PackageExprUnary>;

	// `package-expr` with && or || in BNF
	class PackageExprBinary : public PackageExpr
	{
	public:
		PackageExprBinary() : PackageExpr(PackageExprType::Binary) {}

	public:
		BinaryType type_;
		PackageExprPtr lhs_;
		PackageExprPtr rhs_;
	};
	using PackageExprBinaryPtr = std::shared_ptr<PackageExprBinary>;

	// `prop-expr-atom` not <name> in BNF
	class PackageExprAtomWithProp : public PackageExpr
	{
	public:
		PackageExprAtomWithProp(AtomType type, const std::string& pack_name, const PropName& prop_name, const std::string& string)
			: PackageExpr(PackageExprType::AtomWithProp), type_(type), pack_name_(pack_name),
			prop_name_(prop_name), string_(string) { }

		PackageExprAtomWithProp(const std::string& pack_name, const PropName& prop_name, const std::string& string)
		: PackageExpr(PackageExprType::AtomWithProp), pack_name_(pack_name),
		  prop_name_(prop_name), string_(string) { }

	public:
		AtomType type_;
		std::string pack_name_;		// `name` in BNF
		PropName prop_name_;		// `prop-name` in BNF
		std::string string_;		// `string` in BNF
	};
	using PackageExprAtomWithPropPtr = std::shared_ptr<PackageExprAtomWithProp>;

	// `prop-expr-atom` <name> in BNF
	class PackageExprAtomWithName : public PackageExpr
	{
	public:
		PackageExprAtomWithName(const std::string& pack_name)
		: PackageExpr(PackageExprType::AtomWithName), pack_name_(pack_name) { }
		
	public:
		std::string pack_name_;		// `name` in BNF
	};
	using PackageExprAtomWithNamePtr = std::shared_ptr<PackageExprAtomWithName>;

}
