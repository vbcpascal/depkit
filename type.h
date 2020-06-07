#pragma once

#include <string>

#define ASSERT(EXPR, MSG, ...)		\
	if (!(EXPR)) {					\
		printf(MSG, ##__VA_ARGS__); \
		printf("\n");				\
		abort();					\
	}

#define ERROR(MSG, ...) ASSERT(false, MSG, ##__VA_ARGS__)

namespace depkit
{

	using PropName = std::string;

	enum class UnaryType : int { NOT, };
	enum class BinaryType : int { AND, OR };
	enum class AtomType : int {
		EQ,	NE, GT, LT,	GE,	LE,	IN,	NIN,
	};

	enum class PropLabel : int {
		version,
		feature,
		backend,
	};
	
}
