#include "Hello.h"

#include <limits>
#include <cstdint>

std::string Hello::Greet() const
{
	return "Hello " + std::to_string(std::numeric_limits<size_t>::digits) + "-bit World!\n";
}