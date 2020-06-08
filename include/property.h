#pragma once

#include <list>
#include <memory>
#include <ostream>
#include <string>

#include "version.h"

namespace depkit {
using Feature = std::string;
using Backend = std::string;

// `property-list` in BNF
class PropertyList {
public:
  PropertyList() = default;
  PropertyList(std::list<Version> &vs, std::list<Feature> &fs,
               std::list<Backend> &bs)
      : versions_(vs), features_(fs), backends_(bs) {}

  void add_version(const Version &v) { versions_.push_back(std::move(v)); }
  void add_feature(const Feature &f) { features_.push_back(std::move(f)); }
  void add_backend(const Backend &b) { backends_.push_back(std::move(b)); }

public:
  std::list<Version> versions_ = {};
  std::list<Feature> features_ = {};
  std::list<Backend> backends_ = {};
};
using PropertyListPtr = std::shared_ptr<PropertyList>;

} // namespace depkit