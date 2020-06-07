#pragma once

#include <iostream>

#include "terms.h"

namespace depkit
{

	class Printer
	{
	public:
		void print(const TermsPtr& terms);

	private:
        void VisitDefinitions(const TermsPtr& terms);
        void VisitDependencies(const TermsPtr& terms);
        void VisitRequirements(const TermsPtr& terms);

        void Visit(const DefinitionPtr& def);
        void Visit(const DependencyPtr& dep);
        void Visit(const RequirementPtr& req);
        void Visit(const IdentificationPtr& id);
        void Visit(const PropertyListPtr& plist);
        void Visit(const PropExprPtr& expr);
        void Visit(const PropExprUnaryPtr& e);
        void Visit(const PropExprBinaryPtr& e);
        void Visit(const PropExprAtomPtr& e);
        void Visit(const PackageExprPtr& expr);
        void Visit(const IfPackagePtr& e);
        void Visit(const IfElsePackagePtr& e);
        void Visit(const PackageExprAtomWithNamePtr& e);
        void Visit(const PackageExprAtomWithPropPtr& e);
        void Visit(const PackageExprUnaryPtr& e);
        void Visit(const PackageExprBinaryPtr& e);
	};
	
}