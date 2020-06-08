#pragma once

#include <fstream>
#include <map>
#include <vector>

#include "option.h"
#include "terms.h"
#include "z3++.h"

namespace depkit {
class PackageCodeGen {
public:
  PackageCodeGen(const z3::expr &package, const z3::expr &version)
      : package_(package), version_(version) {}

  const z3::expr &get_feature(const std::string &feat_name) const noexcept {
    try {
      return features_.at(feat_name);
    } catch (const std::out_of_range &) {
      ERROR("Undefined feature: %s.", feat_name.c_str());
    }
  }

  const z3::expr &get_backend(const std::string &back_name) const noexcept {
    try {
      return backends_.at(back_name);
    } catch (const std::out_of_range &) {
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

class CodeGenZ3 {
public:
  void codegen(const TermsPtr &terms);
  void solve(const Options &options);

  void print(std::ostream &os = std::cout) { os << *solver_ << std::endl; }

private:
  void buildSolver();
  void addVersionConstraint();

  void VisitDefinitions(const TermsPtr &terms);
  void VisitDependencies(const TermsPtr &terms);
  void VisitRequirements(const TermsPtr &terms);

  void Visit(const DefinitionPtr &def);
  void Visit(const DependencyPtr &dep);
  void Visit(const RequirementPtr &req);
  void Visit(const IdentificationPtr &id);
  void Visit(const PropertyListPtr &plist);
  z3::expr Visit(const PropExprPtr &expr);
  z3::expr Visit(const PropExprUnaryPtr &e);
  z3::expr Visit(const PropExprBinaryPtr &e);
  z3::expr Visit(const PropExprAtomPtr &e);
  z3::expr Visit(const PackageExprPtr &expr);
  z3::expr Visit(const IfPackagePtr &e);
  z3::expr Visit(const IfElsePackagePtr &e);
  z3::expr Visit(const PackageExprAtomWithNamePtr &e);
  z3::expr Visit(const PackageExprAtomWithPropPtr &e);
  z3::expr Visit(const PackageExprUnaryPtr &e);
  z3::expr Visit(const PackageExprBinaryPtr &e);

  PackageCodeGen &get_pack(const std::string &pack_name) noexcept;

  void handleModel(const z3::model &m, std::ostream &os = std::cout);

  z3::context ctx_;
  std::shared_ptr<z3::solver> solver_;
  std::map<std::string, PackageCodeGen> packs_;

  CurrState current_state_ = CurrState::None;
  std::string curr_pack_name_;
};

} // namespace depkit
