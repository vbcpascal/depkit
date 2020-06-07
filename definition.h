#pragma once

#include "identification.h"

namespace depkit {
// `metadata` in BNF
using MetaData = std::string;

// `package-definition` in BNF
class Definition {
public:
  Definition() {}

  Definition(IdentificationPtr identification)
      : identification_(identification) {}

  void set_matadata(const MetaData &metadata = "()") { metadata_ = metadata; }

public:
  IdentificationPtr identification_;
  MetaData metadata_;
};
using DefinitionPtr = std::shared_ptr<Definition>;

} // namespace depkit
