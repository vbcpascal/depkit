#include "codegen.h"

namespace depkit {

z3::expr CodeGenZ3::Visit(const PackageExprAtomWithNamePtr &e) {
  // z3 in dependencies of llvm -> assert(=> llvm z3)
  return get_pack(e->pack_name_).package_;
}

z3::expr CodeGenZ3::Visit(const PackageExprAtomWithPropPtr &e) {
  const auto &pack_name = e->pack_name_;
  const auto &prop_name = e->prop_name_;
  const auto &str = e->string_;
  const auto &pack = get_pack(pack_name);
  const auto &p = pack.package_;
  switch (e->type_) {
  case AtomType::IN:
  case AtomType::NIN:
    // llvm: z3.debug => (z3 && z3.feature.debug)
    if (prop_name == "backend") {
      const z3::expr &res = pack.get_backend(str);
      if (e->type_ == AtomType::IN)
        return p && res;
      else
        return p && !res;
    }
    if (prop_name == "feature") {
      const z3::expr &res = pack.get_feature(str);
      if (e->type_ == AtomType::IN)
        return p && res;
      else
        return p && !res;
    }
    ERROR("Only backend and feature are allowed with `in` and `not in`.");
  case AtomType::EQ:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `==`");
    return p && pack.version_ == ctx_.real_val(str.c_str());
  case AtomType::NE:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `!=`");
    return p && pack.version_ != ctx_.real_val(str.c_str());
  case AtomType::GE:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `>=`");
    return p && pack.version_ >= ctx_.real_val(str.c_str());
  case AtomType::LE:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `<=`");
    return p && pack.version_ <= ctx_.real_val(str.c_str());
  case AtomType::GT:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `>`");
    return p && pack.version_ > ctx_.real_val(str.c_str());
  case AtomType::LT:
    DEPKIT_ASSERT(prop_name == "version", "Only version is allowed with `<`");
    return p && pack.version_ < ctx_.real_val(str.c_str());
  default:
    ERROR("Unsupport expression type");
  }
}

z3::expr CodeGenZ3::Visit(const PackageExprUnaryPtr &e) {
  auto expr = Visit(e->expr_);
  switch (e->type_) {
  case UnaryType::NOT:
    return !expr;
  default:
    ERROR("Unsupport unary type");
  }
}

z3::expr CodeGenZ3::Visit(const PackageExprBinaryPtr &e) {
  auto lhs = Visit(e->lhs_);
  auto rhs = Visit(e->rhs_);
  switch (e->type_) {
  case BinaryType::AND:
    return lhs && rhs;
  case BinaryType::OR:
    return lhs || rhs;
  default:
    ERROR("Unsupport binary type");
  }
}

z3::expr CodeGenZ3::Visit(const IfPackagePtr &e) {
  auto cond = Visit(e->cond_);
  auto body = Visit(e->body_);
  return z3::implies(cond, body);
}

z3::expr CodeGenZ3::Visit(const IfElsePackagePtr &e) {
  auto cond = Visit(e->cond_);
  auto body = Visit(e->body_);
  auto else_body = Visit(e->else_body_);
  return z3::ite(cond, body, else_body);
}

} // namespace depkit
