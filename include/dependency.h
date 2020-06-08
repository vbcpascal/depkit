#pragma once

#include <memory>

#include "identification.h"
#include "package_expr.h"
#include "property_expr.h"

namespace depkit {
// `package-dependency` in BNF
class Dependency {
public:
  Dependency() {}
  Dependency(std::list<PropExprPtr> &reqs, std::list<PackageExprPtr> &deps)
      : require_list_(reqs), depend_list_(deps) {}

public:
  IdentificationPtr identification_;
  std::list<PropExprPtr> require_list_;
  std::list<PackageExprPtr> depend_list_;
};
using DependencyPtr = std::shared_ptr<Dependency>;
} // namespace depkit
