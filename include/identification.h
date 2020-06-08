#pragma once

#include <list>
#include <string>

#include "property.h"

namespace depkit {

// `package-identification` in BNF
class Identification {
public:
  Identification(std::string name) : name_(name) {}

  Identification(std::string name, PropertyListPtr &property_list)
      : name_(name), property_list_(property_list) {}

public:
  std::string name_;              // `name` in BNF
  PropertyListPtr property_list_; // `property-list` in BNF
};
using IdentificationPtr = std::shared_ptr<Identification>;

} // namespace depkit
