#include <numeric>
#include <tuple>
#include "BowlingGame.h"

BowlingGame BowlingGame::Roll(const std::vector<u32>& rolls) const
{
    (void)rolls;
    return *this;
}

u32 BowlingGame::Score() const
{
    return 0;
}


