#pragma once

#include <list>

#include "identification.h"

namespace depkit {
// `requirement` in BNF
class Requirement {
public:
  Requirement() {}
  Requirement(IdentificationPtr &req) : requirement_(req) {}

public:
  IdentificationPtr requirement_;
};
using RequirementPtr = std::shared_ptr<Requirement>;
} // namespace depkit
