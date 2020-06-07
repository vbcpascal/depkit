#include <memory>
#include <list>

#include "definition.h"
#include "dependency.h"
#include "requirement.h"

namespace depkit {

	// `terms` in BNF 
	class Terms {
	public:
		Terms() { }
		Terms(std::list<DefinitionPtr>& def, std::list<DependencyPtr>& dep, std::list<RequirementPtr>& req)
			: definitions_(def), dependencies_(dep), requirements_(req) { }

	public:
		std::list<DefinitionPtr> definitions_;
		std::list<DependencyPtr> dependencies_;
		std::list<RequirementPtr> requirements_;
	};
	using TermsPtr = std::shared_ptr<Terms>;

}