#include "z3++.h"
#include "codegen.h"

void find_model_example1() {
	using namespace z3;
	context c;
	expr x = c.int_const("x");
	auto xx = x;
	expr y = c.int_const("y");
	expr z = c.int_const("z");
	expr b = c.bool_const("b");
	solver s(c);

	auto mm = xx >= 1;
	auto nn = y < x + 3;
	s.add(implies(b, mm && nn));
	
	s.add(xx >= 1);
	s.add(y < x + 3);
	std::cout << s << "\n";
	std::cout << s.check() << "\n";

	model m = s.get_model();
	std::cout << m << "\n";

	for (unsigned i = 0; i < m.size(); i++) {
		func_decl v = m[i];
		assert(v.arity() == 0);
		std::cout << v.name() << "=" << m.get_const_interp(v) << "\n";
	}

	std::cout << "x + y + 1 = " << m.eval(x + y + 1) << "\n";
}

int main() {
	using namespace depkit;
	auto terms = std::make_shared<Terms>();

	/* Definitions */
	
	{ // LLVM {9.0, 10.0, 11.0} {z3, debug, release}, {aarch64, riscv}
		auto plist = std::make_shared<PropertyList>();
		plist->add_version("9.0"); plist->add_version("10.0"); plist->add_version("11.0");
		plist->add_feature("z3"); plist->add_feature("debug"); plist->add_feature("release");
		plist->add_backend("aarch64"); plist->add_backend("riscv");
		auto id = std::make_shared<Identification>("LLVM"); id->property_list_ = plist;
		auto def = std::make_shared<Definition>(); def->identification_ = id;
		terms->definitions_.push_back(def);
	}
	{ // Z3 {4.0} {debug, release}, {x64, riscv}
		auto plist = std::make_shared<PropertyList>();
		plist->add_version("4.0");
		plist->add_feature("debug"); plist->add_feature("release");
		plist->add_backend("x64"); plist->add_backend("riscv");
		auto id = std::make_shared<Identification>("z3"); id->property_list_ = plist;
		auto def = std::make_shared<Definition>(); def->identification_ = id;
		terms->definitions_.push_back(def);
	}

	/* Dependencies */
	{
		auto id = std::make_shared<Identification>("LLVM");
		auto dep = std::make_shared<Dependency>(); dep->identification_ = id;
		{ // LLVM require (version <= 10.0 || z3 not in feature)
			auto lhs = std::make_shared<PropExprAtom>("version", "10.0"); lhs->type_ = AtomType::LE;
			auto rhs = std::make_shared<PropExprAtom>("feature", "z3"); rhs->type_ = AtomType::NIN;
			PropExprBinaryPtr req = std::make_shared<PropExprBinary>(); req->lhs_ = lhs; req->rhs_ = rhs; req->type_ = BinaryType::OR;
			dep->require_list_.push_back(req);
		}
		{ // LLVM dependency: if z3 in feature: z3
			auto if_cond = std::make_shared<PropExprAtom>("feature", "z3"); if_cond->type_ = AtomType::IN;
			auto if_body = std::make_shared<PackageExprAtomWithName>("z3");
			auto if_ = std::make_shared<IfPackage>(); if_->cond_ = if_cond; if_->body_ = if_body;
			dep->depend_list_.push_back(if_);
		}
		{ // LLVM dependency
			auto if_cond_lhs = std::make_shared<PropExprAtom>("feature", "z3"); if_cond_lhs->type_ = AtomType::IN;
			auto if_cond_rhs = std::make_shared<PropExprAtom>("feature", "debug"); if_cond_rhs->type_ = AtomType::IN;
			auto if_cond = std::make_shared<PropExprBinary>(); if_cond->lhs_ = if_cond_lhs; if_cond->rhs_ = if_cond_rhs; if_cond->type_ = BinaryType::AND;
			auto if_body = std::make_shared<PackageExprAtomWithProp>("z3", "feature", "debug"); if_body->type_ = AtomType::IN;
			auto if_ = std::make_shared<IfPackage>(); if_->cond_ = if_cond; if_->body_ = if_body;
			dep->depend_list_.push_back(if_);
		}
		terms->dependencies_.push_back(dep);
	}

	/* Requirements */
	{ // LLVM 11.0 z3 debug riscv
		auto plist = std::make_shared<PropertyList>();
		plist->add_version("11.0");
		plist->add_feature("z3"); plist->add_feature("debug");
		plist->add_backend("riscv");
		auto id = std::make_shared<Identification>("LLVM"); id->property_list_ = plist;
		auto req = std::make_shared<Requirement>(); req->requirement_ = id;
		terms->requirements_.push_back(req);
	}
	
	CodeGenZ3 cg;
	cg.codegen(terms);
	cg.print();
	// find_model_example1();
	return 0;
}