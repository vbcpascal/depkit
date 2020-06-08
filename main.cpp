#include "codegen.h"
#include "docopt.h"
#include "lex.hpp"
#include "option.h"
#include "parser.hpp"
#include "printer.h"
#include "z3++.h"

#include <fstream>

static const char USAGE[] =
    R"(DepKit Compiler.

    Usage:
      depkit [--oa FILE] [--ob FILE] [--output FILE] <input>
      depkit (-s | --stdin) [--oa FILE] [--ob FILE] [--output FILE]
      depkit (-h | --help)
      depkit --version

    Options:
      -h --help           Show this screen.
      -v --version        Show version.
      -s --stdin          Read program from stdin instead of input file.
      -o --output FILE    Print result to the file instead of stdout.
      -a --oa FILE        Print SMT-LIB format constraint file to the file.
      -b --ob FILE        Print SMT-LIB format module file to the file.
    )";

using namespace depkit;

extern TermsPtr terms;
Options options;
CodeGenZ3 cg;

void parse() {
  if (options.readFromStdin) {
    yy::Lexer lexer(std::cin);
    yy::Parser parser(lexer);
    if (parser.parse() != 0)
      ERROR("DepKit: [Error] Syntax error.")
  } else {
    std::ifstream in(options.inputFile, std::ios::in);
    yy::Lexer lexer(in);
    yy::Parser parser(lexer);
    if (parser.parse() != 0)
      ERROR("DepKit: [Error] Syntax error.")
  }
}

void codegen() {
  cg.codegen(terms);
  if (options.printSMTConstraint) {
    std::ofstream out(options.constraintFile, std::ios::out);
    cg.print(out);
  }
}

void solve() { cg.solve(options); }

#define TEST_LOG(Msg) printf("\033[;1m%s\033[0m\n", Msg);

void build_example() {
  using namespace depkit;
  auto terms = std::make_shared<Terms>();

  /* Definitions */

  { // LLVM {9.0, 10.0, 11.0} {z3, debug, release}, {aarch64, riscv}
    auto plist = std::make_shared<PropertyList>();
    plist->add_version("9.0");
    plist->add_version("10.0");
    plist->add_version("11.0");
    plist->add_feature("z3");
    plist->add_feature("debug");
    plist->add_feature("release");
    plist->add_backend("aarch64");
    plist->add_backend("riscv");
    auto id = std::make_shared<Identification>("LLVM");
    id->property_list_ = plist;
    auto def = std::make_shared<Definition>();
    def->identification_ = id;
    terms->definitions_.push_back(def);
  }
  { // Z3 {4.0} {debug, release}, {x64, riscv}
    auto plist = std::make_shared<PropertyList>();
    plist->add_version("4.0");
    plist->add_feature("debug");
    plist->add_feature("release");
    plist->add_backend("x64");
    plist->add_backend("riscv");
    auto id = std::make_shared<Identification>("z3");
    id->property_list_ = plist;
    auto def = std::make_shared<Definition>();
    def->identification_ = id;
    terms->definitions_.push_back(def);
  }

  /* Dependencies */
  {
    auto id = std::make_shared<Identification>("LLVM");
    auto dep = std::make_shared<Dependency>();
    dep->identification_ = id;
    { // LLVM require (version <= 10.0 || z3 not in feature)
      auto lhs = std::make_shared<PropExprAtom>("version", "10.0");
      lhs->type_ = AtomType::LE;
      auto rhs = std::make_shared<PropExprAtom>("feature", "z3");
      rhs->type_ = AtomType::NIN;
      PropExprBinaryPtr req = std::make_shared<PropExprBinary>();
      req->lhs_ = lhs;
      req->rhs_ = rhs;
      req->type_ = BinaryType::OR;
      dep->require_list_.push_back(req);
    }
    { // LLVM dependency: if z3 in feature: z3
      auto if_cond = std::make_shared<PropExprAtom>("feature", "z3");
      if_cond->type_ = AtomType::IN;
      auto if_body = std::make_shared<PackageExprAtomWithName>("z3");
      auto if_ = std::make_shared<IfPackage>();
      if_->cond_ = if_cond;
      if_->body_ = if_body;
      dep->depend_list_.push_back(if_);
    }
    { // LLVM dependency
      auto if_cond_lhs = std::make_shared<PropExprAtom>("feature", "z3");
      if_cond_lhs->type_ = AtomType::IN;
      auto if_cond_rhs = std::make_shared<PropExprAtom>("feature", "debug");
      if_cond_rhs->type_ = AtomType::IN;
      auto if_cond = std::make_shared<PropExprBinary>();
      if_cond->lhs_ = if_cond_lhs;
      if_cond->rhs_ = if_cond_rhs;
      if_cond->type_ = BinaryType::AND;
      auto if_body =
          std::make_shared<PackageExprAtomWithProp>("z3", "feature", "debug");
      if_body->type_ = AtomType::IN;
      auto if_ = std::make_shared<IfPackage>();
      if_->cond_ = if_cond;
      if_->body_ = if_body;
      dep->depend_list_.push_back(if_);
    }
    terms->dependencies_.push_back(dep);
  }

  /* Requirements */
  { // LLVM 11.0 z3 debug riscv
    auto plist = std::make_shared<PropertyList>();
    plist->add_version("11.0");
    plist->add_feature("z3");
    plist->add_feature("debug");
    plist->add_backend("riscv");
    auto id = std::make_shared<Identification>("LLVM");
    id->property_list_ = plist;
    auto req = std::make_shared<Requirement>();
    req->requirement_ = id;
    terms->requirements_.push_back(req);
  }

  CodeGenZ3 cg;
  cg.codegen(terms);
  cg.print();
}

int main(int argc, const char **argv) {
  std::map<std::string, docopt::value> args = docopt::docopt(
      USAGE, {argv + 1, argv + argc}, true, "DepKit Compiler 1.0.");

  if (args["--stdin"].asBool()) {
    options.readFromStdin = true;
  }
  if (args["--oa"].isString()) {
    options.printSMTConstraint = true;
    options.constraintFile = args["--oa"].asString();
  }
  if (args["--ob"].isString()) {
    options.printSMTResult = true;
    options.resultFile = args["--ob"].asString();
  }
  if (args["--output"].isString()) {
    options.outputToFile = true;
    options.outputFile = args["--output"].asString();
  }
  if (args["<input>"].isString()) {
    options.inputFile = args["<input>"].asString();
  }

  parse();
  codegen();
  solve();
  return 0;
}