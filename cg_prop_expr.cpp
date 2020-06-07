#include "codegen.h"

namespace depkit
{

	z3::expr CodeGenZ3::Visit(PropExprAtomPtr& e)
	{
		auto prop_name = e->prop_name_;
		auto str = e->string_;
		auto pack = get_pack(curr_pack_name_);
		switch (e->type_)
		{
		case AtomType::IN:
		case AtomType::NIN:
			if (prop_name == "backend")
			{
				const z3::expr& res = pack.get_backend(str);
				if (e->type_ == AtomType::IN) return res;
				else return !res;
			}
			if (prop_name == "feature")
			{
				const z3::expr& res = pack.get_feature(str);
				if (e->type_ == AtomType::IN) return res;
				else return !res;
			}
			ERROR("Only backend and feature are allowed with `in` and `not in`.");
		case AtomType::EQ:
			ASSERT(prop_name == "version", "Only version is allowed with `==`");
			return pack.version_ == ctx_.real_val(str.c_str());
		case AtomType::NE:
			ASSERT(prop_name == "version", "Only version is allowed with `!=`");
			return pack.version_ != ctx_.real_val(str.c_str());
		case AtomType::GE:
			ASSERT(prop_name == "version", "Only version is allowed with `>=`");
			return pack.version_ >= ctx_.real_val(str.c_str());
		case AtomType::LE:
			ASSERT(prop_name == "version", "Only version is allowed with `<=`");
			return pack.version_ <= ctx_.real_val(str.c_str());
		case AtomType::GT:
			ASSERT(prop_name == "version", "Only version is allowed with `>`");
			return pack.version_ > ctx_.real_val(str.c_str());
		case AtomType::LT:
			ASSERT(prop_name == "version", "Only version is allowed with `<`");
			return pack.version_ < ctx_.real_val(str.c_str());
		default:
			ERROR("Unsupport expression type");
		}
	}

	z3::expr CodeGenZ3::Visit(PropExprUnaryPtr& e)
	{
		auto expr = Visit(e->expr_);
		switch (e->type_)
		{
		case UnaryType::NOT:
			return !expr;
		default:
			ERROR("Unsupport unary type");
		}
	}

	z3::expr CodeGenZ3::Visit(PropExprBinaryPtr& e)
	{
		auto lhs = Visit(e->lhs_);
		auto rhs = Visit(e->rhs_);
		switch (e->type_)
		{
		case BinaryType::AND:
			return lhs && rhs;
		case BinaryType::OR:
			return lhs || rhs;
		default:
			ERROR("Unsupport binary type");
		}
	}

}
