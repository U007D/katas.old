#include <numeric>

#include "range/v3/all.hpp"
#include "BowlingGame.h"

BowlingGame::BowlingGame()
{
    rolls_.reserve(BowlingConstants::MAX_ROLLS_PER_GAME);
}

BowlingGame BowlingGame::Roll(const std::vector<u8>& rolls)
{
    rolls_.insert(std::end(rolls_), std::begin(rolls), std::end(rolls));
    return *this;
}

u16 BowlingGame::Score() const
{
    // C++'s feature known as usual arithmetic conversions doesn't allow a
    // u16 accumulator + u8 values to yield a u16 result.  It yields an i32 instead :(.
    // Hence, the use of static_cast<u16>().  Note: In bowling, score cannot exceed 300.
    return static_cast<u16>(ranges::accumulate(rolls_, 0));
}
