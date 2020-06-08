#include "codegen.h"

#define VISIT_CAST(T) Visit(std::static_pointer_cast<T>(expr))

namespace depkit {

PackageCodeGen &CodeGenZ3::get_pack(const std::string &pack_name) noexcept {
  try {
    return packs_.at(pack_name);
  } catch (const std::out_of_range &) {
    ERROR("Undefined package: %s.", pack_name.c_str());
  }
}

void CodeGenZ3::codegen(const TermsPtr &terms) {
  VisitDefinitions(terms); // read all definitions
  buildSolver();           // build Z3 solver
  addVersionConstraint();
  VisitDependencies(terms);
  VisitRequirements(terms);
}

void CodeGenZ3::solve(const Options &options) {
  if (solver_->check() == z3::unsat) {
    if (options.outputToFile) {
      std::ofstream out(options.outputFile, std::ios::out);
      out << "Cannot install due to conflict" << std::endl;
    } else {
      std::cout << "Cannot install due to conflict" << std::endl;
    }
  } else {
    z3::model m = solver_->get_model();
    if (options.printSMTResult) {
      std::ofstream out(options.resultFile, std::ios::out);
      out << m << std::endl;
    }
    if (options.outputToFile) {
      std::ofstream out(options.outputFile, std::ios::out);
      handleModel(m, out);
    } else {
      handleModel(m);
    }
  }
}

void CodeGenZ3::handleModel(const z3::model &m, std::ostream &os) {
  z3::set_param("pp.decimal", true);
  for (auto &pp : packs_) {
    std::string pack_name = pp.first;
    auto &pack = pp.second;
    if (m.eval(pack.package_).is_true()) {
      // check each feature and backend
      std::vector<std::string> feat_req, feat_no, feat_opt;
      std::vector<std::string> back_req, back_no, back_opt;
      for (auto &sf : pack.features_) {
        std::string name = sf.first;
        z3::expr res = m.eval(sf.second);
        if (res.is_true())
          feat_req.push_back(name);
        else if (res.is_false())
          feat_no.push_back(name);
        else
          feat_opt.push_back(name);
      }
      for (auto &sf : pack.backends_) {
        std::string name = sf.first;
        z3::expr res = m.eval(sf.second);
        if (res.is_true())
          back_req.push_back(name);
        else if (res.is_false())
          back_no.push_back(name);
        else
          back_opt.push_back(name);
      }

      // print
      os << pack_name << " " << m.eval(pack.version_) << std::endl;
      os << "  features: ";
      for (auto &s : feat_req)
        os << s << " ";
      os << "[ ";
      for (auto &s : feat_opt)
        os << s << " ";
      os << "]\n";
      os << "  backends: ";
      for (auto &s : back_req)
        os << s << " ";
      os << "[ ";
      for (auto &s : back_opt)
        os << s << " ";
      os << "]\n";
    }
  }
}

void CodeGenZ3::buildSolver() { solver_ = std::make_shared<z3::solver>(ctx_); }

void CodeGenZ3::addVersionConstraint() {
  // (=> llvm (or (== llvm.version 9.0) (== llvm.version 10.0)))
  for (auto &packpair : packs_) {
    auto &pack = packpair.second;
    auto &package = pack.package_;
    auto &version = pack.version_;
    auto &versions = pack.versions_;
    z3::expr constraint = version == ctx_.real_val(versions[0].c_str());
    for (unsigned i = 1; i < versions.size(); ++i)
      constraint =
          constraint || (version == ctx_.real_val(versions[i].c_str()));
    solver_->add(z3::implies(package, constraint));
  }
}

void CodeGenZ3::VisitDefinitions(const TermsPtr &terms) {
  current_state_ = CurrState::Definition;
  for (auto &def : terms->definitions_)
    Visit(def);
}

void CodeGenZ3::VisitDependencies(const TermsPtr &terms) {
  current_state_ = CurrState::Dependency;
  for (auto &dep : terms->dependencies_)
    Visit(dep);
}

void CodeGenZ3::VisitRequirements(const TermsPtr &terms) {
  current_state_ = CurrState::Requirement;
  for (auto &req : terms->requirements_)
    Visit(req);
}

void CodeGenZ3::Visit(const DefinitionPtr &def) { Visit(def->identification_); }

void CodeGenZ3::Visit(const DependencyPtr &dep) {
  Visit(dep->identification_);
  const z3::expr &pack = get_pack(curr_pack_name_).package_;
  for (auto &expr : dep->require_list_) {
    auto req_expr = Visit(expr);
    solver_->add(z3::implies(pack, req_expr));
  }
  for (auto &expr : dep->depend_list_) {
    auto dep_expr = Visit(expr);
    solver_->add(z3::implies(pack, dep_expr));
  }
}

void CodeGenZ3::Visit(const RequirementPtr &req) { Visit(req->requirement_); }

void CodeGenZ3::Visit(const IdentificationPtr &id) {
  curr_pack_name_ = id->name_;
  if (current_state_ == CurrState::Definition) {
    const z3::expr name = ctx_.bool_const(curr_pack_name_.c_str()); // A as bool
    const z3::expr version = ctx_.real_const(
        (curr_pack_name_ + ".version").c_str()); // A.version as float
    packs_.emplace(curr_pack_name_, PackageCodeGen(name, version));
    Visit(id->property_list_);
  } else if (current_state_ == CurrState::Dependency) {
    // do nothing
  } else if (current_state_ == CurrState::Requirement) {
    solver_->add(get_pack(curr_pack_name_).package_); // (assert A)
    Visit(id->property_list_);
  }
}

void CodeGenZ3::Visit(const PropertyListPtr &plist) {
  auto &p = get_pack(curr_pack_name_);
  if (current_state_ == CurrState::Definition) {
    for (auto &v : plist->versions_)
      p.versions_.push_back(v);
    for (auto &f : plist->features_) {
      const z3::expr feat =
          ctx_.bool_const((curr_pack_name_ + ".feat." + f).c_str());
      p.features_.emplace(f, feat); // A.feat.xxx as bool
    }
    for (auto &b : plist->backends_) {
      const z3::expr backend =
          ctx_.bool_const((curr_pack_name_ + ".backend." + b).c_str());
      p.backends_.emplace(b, backend); // A.backend.xxx as bool
    }
  } else if (current_state_ == CurrState::Requirement) {
    DEPKIT_ASSERT(plist->versions_.size() <= 1,
                  "Cannot specify more than one version in requirement.");
    if (plist->versions_.size() == 1) {
      const char *version_str = plist->versions_.begin()->c_str();
      solver_->add(p.version_ ==
                   ctx_.real_val(version_str)); // (assert (== A.version mm.nn))
    }
    for (auto &f : plist->features_) {
      const z3::expr &feat = p.get_feature(f);
      solver_->add(feat); // (assert A.feat.xxx)
    }
    for (auto &b : plist->backends_) {
      const z3::expr &backend = p.get_backend(b);
      solver_->add(backend); // (assert A.backend.xxx)
    }
  }
}

z3::expr CodeGenZ3::Visit(const PropExprPtr &expr) {
  switch (expr->expr_type_) {
  case PropExprType::Atom:
    return VISIT_CAST(PropExprAtom);
  case PropExprType::Unary:
    return VISIT_CAST(PropExprUnary);
  case PropExprType::Binary:
    return VISIT_CAST(PropExprBinary);
  default:
    ERROR("unsupported expression type.");
  }
}

z3::expr CodeGenZ3::Visit(const PackageExprPtr &expr) {
  switch (expr->expr_type_) {
  case PackageExprType::AtomWithName:
    return VISIT_CAST(PackageExprAtomWithName);
  case PackageExprType::AtomWithProp:
    return VISIT_CAST(PackageExprAtomWithProp);
  case PackageExprType::Unary:
    return VISIT_CAST(PackageExprUnary);
  case PackageExprType::Binary:
    return VISIT_CAST(PackageExprBinary);
  case PackageExprType::If:
    return VISIT_CAST(IfPackage);
  case PackageExprType::IfElse:
    return VISIT_CAST(IfElsePackage);
  default:
    ERROR("unsupported expression type.");
  }
}

} // namespace depkit
