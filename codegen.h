#pragma once

#include <map>
#include <vector>

#include "terms.h"
#include "z3++.h"

namespace depkit
{
	class PackageCodeGen
	{
	public:
		PackageCodeGen(const z3::expr& package, const z3::expr& version)
		: package_(package), version_(version) { }

		const z3::expr& get_feature(const std::string& feat_name) const noexcept
		{
			try
			{
				return features_.at(feat_name);
			} catch (const std::out_of_range&)
			{
				ERROR("Undefined feature: %s.", feat_name.c_str());
			}
		} 

		const z3::expr& get_backend(const std::string& back_name) const noexcept
		{
			try
			{
				return backends_.at(back_name);
			} catch (const std::out_of_range&)
			{
				ERROR("Undefined backend: %s.", back_name.c_str())
			}
		}
		
	public:
		z3::expr package_;
		z3::expr version_;
		std::vector<Version> versions_;
		std::map<std::string, z3::expr> features_;
		std::map<std::string, z3::expr> backends_;
	};

	enum class CurrState : int {
		None,
		Definition,
		Dependency,
		Requirement,
	};

	class CodeGenZ3
	{
	public:
		
		void codegen(TermsPtr& terms);
		void print() { std::cout << *solver_ << std::endl; }
		
	private:
		void buildSolver();
		void addVersionConstraint();
		
		void VisitDefinitions(TermsPtr& terms);
		void VisitDependencies(TermsPtr& terms);
		void VisitRequirements(TermsPtr& terms);
		
		void Visit(DefinitionPtr& def);
		void Visit(DependencyPtr& dep);
		void Visit(RequirementPtr& req);
		void Visit(IdentificationPtr& id);
		void Visit(PropertyListPtr& plist);
		z3::expr Visit(PropExprPtr& expr);
		z3::expr Visit(PropExprUnaryPtr& e);
		z3::expr Visit(PropExprBinaryPtr& e);
		z3::expr Visit(PropExprAtomPtr& e);
		z3::expr Visit(PackageExprPtr& expr);
		z3::expr Visit(IfPackagePtr& e);
		z3::expr Visit(IfElsePackagePtr& e);
		z3::expr Visit(PackageExprAtomWithNamePtr& e);
		z3::expr Visit(PackageExprAtomWithPropPtr& e);
		z3::expr Visit(PackageExprUnaryPtr& e);
		z3::expr Visit(PackageExprBinaryPtr& e);

		PackageCodeGen& get_pack(const std::string& pack_name) noexcept;
		
		z3::context ctx_;
		std::shared_ptr<z3::solver> solver_;
		std::map<std::string, PackageCodeGen> packs_;

		CurrState current_state_ = CurrState::None;
		std::string curr_pack_name_;
	};
	
}
