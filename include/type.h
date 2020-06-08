#pragma once

#include <string>

#define DEPKIT_ASSERT(EXPR, MSG, ...)                                          \
  if (!(EXPR)) {                                                               \
    printf(MSG, ##__VA_ARGS__);                                                \
    printf("\n");                                                              \
    exit(1);                                                                   \
  }

#define ERROR(MSG, ...) DEPKIT_ASSERT(false, MSG, ##__VA_ARGS__)

namespace depkit {

using PropName = std::string;

enum class UnaryType : int {
  NOT,
};
enum class BinaryType : int { AND, OR };
enum class AtomType : int {
  EQ,
  NE,
  GT,
  LT,
  GE,
  LE,
  IN,
  NIN,
};

enum class PropLabel : int {
  version,
  feature,
  backend,
};

} // namespace depkit
