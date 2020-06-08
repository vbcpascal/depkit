#pragma once

#include <string>

namespace depkit {

class Options {
public:
  bool readFromStdin = false;
  bool printSMTConstraint = false;
  bool printSMTResult = false;
  bool outputToFile = false;

  std::string constraintFile = "";
  std::string resultFile = "";
  std::string outputFile = "";
  std::string inputFile = "";
};

} // namespace depkit
