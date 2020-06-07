#include <list>

#include "identification.h"

namespace depkit
{
	// `requirement` in BNF
	class Requirement
	{
	public:

	public:
		IdentificationPtr requirement_;
	};
	using RequirementPtr = std::shared_ptr<Requirement>;
}
