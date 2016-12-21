#include "BowlingGame.h"
#include "range/v3/all.hpp"

u16 Score(const std::vector<u8>& rolls)
{
    return static_cast<u16>(ranges::accumulate(rolls, 0));
}
