#include "printer.h"

#define VISIT_CAST(T) Visit(std::static_pointer_cast<T>(expr))

namespace depkit {

void Printer::print(const TermsPtr &terms) {
  VisitDefinitions(terms);
  std::cout << "%%\n\n";
  VisitDependencies(terms);
  std::cout << "%%\n\n";
  VisitRequirements(terms);
}

void Printer::VisitDefinitions(const TermsPtr &terms) {
  for (auto &def : terms->definitions_) {
    Visit(def);
    std::cout << std::endl;
  }
}

void Printer::VisitDependencies(const TermsPtr &terms) {
  for (auto &dep : terms->dependencies_) {
    Visit(dep);
    std::cout << std::endl;
  }
}

void Printer::VisitRequirements(const TermsPtr &terms) {
  for (auto &req : terms->requirements_) {
    Visit(req);
    std::cout << std::endl;
  }
}

void Printer::Visit(const DefinitionPtr &def) {
  Visit(def->identification_);
  std::cout << " = ()\n";
}

void Printer::Visit(const DependencyPtr &dep) {
  Visit(dep->identification_);
  std::cout << " :\n";
  for (auto &expr : dep->require_list_) {
    std::cout << "require (";
    Visit(expr);
    std::cout << ");\n";
  }
  for (auto &expr : dep->depend_list_) {
    Visit(expr);
    std::cout << "\n";
  }
}

void Printer::Visit(const RequirementPtr &req) {
  Visit(req->requirement_);
  std::cout << "\n";
}

void Printer::Visit(const IdentificationPtr &id) {
  if (id->property_list_) {
    std::cout << id->name_ << " [\n";
    Visit(id->property_list_);
    std::cout << "]";
  } else {
    std::cout << id->name_;
  }
}

void Printer::Visit(const PropertyListPtr &plist) {
  std::cout << "version: {";
  for (auto &v : plist->versions_)
    std::cout << v << ", ";
  std::cout << "};\nfeature: {";
  for (auto &f : plist->features_)
    std::cout << f << ", ";
  std::cout << "};\nbackend: {";
  for (auto &b : plist->backends_)
    std::cout << b << ", ";
  std::cout << "};\n";
}

void Printer::Visit(const PropExprPtr &expr) {
  switch (expr->expr_type_) {
  case PropExprType::Atom:
    VISIT_CAST(PropExprAtom);
    return;
  case PropExprType::Unary:
    VISIT_CAST(PropExprUnary);
    return;
  case PropExprType::Binary:
    VISIT_CAST(PropExprBinary);
    return;
  default:
    ERROR("unsupported expression type.");
  }
}

void Printer::Visit(const PropExprAtomPtr &e) {
  std::cout << e->prop_name_ << " " << (int)e->type_ << " " << e->string_;
}

void Printer::Visit(const PropExprUnaryPtr &e) { Visit(e->expr_); }

void Printer::Visit(const PropExprBinaryPtr &e) {
  Visit(e->lhs_);
  std::cout << " " << (int)e->type_ << " ";
  Visit(e->rhs_);
}

void Printer::Visit(const PackageExprPtr &expr) {
  switch (expr->expr_type_) {
  case PackageExprType::AtomWithName:
    VISIT_CAST(PackageExprAtomWithName);
    return;
  case PackageExprType::AtomWithProp:
    VISIT_CAST(PackageExprAtomWithProp);
    return;
  case PackageExprType::Unary:
    VISIT_CAST(PackageExprUnary);
    return;
  case PackageExprType::Binary:
    VISIT_CAST(PackageExprBinary);
    return;
  case PackageExprType::If:
    VISIT_CAST(IfPackage);
    return;
  case PackageExprType::IfElse:
    VISIT_CAST(IfElsePackage);
    return;
  default:
    ERROR("unsupported expression type.");
  }
}

void Printer::Visit(const PackageExprAtomWithNamePtr &e) {
  std::cout << e->pack_name_;
}

void Printer::Visit(const PackageExprAtomWithPropPtr &e) {
  std::cout << e->pack_name_ << "." << e->prop_name_ << " " << (int)e->type_
            << " " << e->string_;
}

void Printer::Visit(const PackageExprUnaryPtr &e) {
  std::cout << "!";
  Visit(e->expr_);
}

void Printer::Visit(const PackageExprBinaryPtr &e) {
  Visit(e->lhs_);
  std::cout << " " << (int)e->type_ << " ";
  Visit(e->rhs_);
}

void Printer::Visit(const IfPackagePtr &e) {
  std::cout << "if ";
  Visit(e->cond_);
  std::cout << " {\n";
  Visit(e->body_);
  std::cout << "\n}";
}

void Printer::Visit(const IfElsePackagePtr &e) {
  std::cout << "if ";
  Visit(e->cond_);
  std::cout << " {\n";
  Visit(e->body_);
  std::cout << "\n} else {\n";
  Visit(e->else_body_);
  std::cout << "\n}";
}

} // namespace depkit
