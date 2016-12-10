#include <numeric>
#include <tuple>
#include "BowlingGame.h"

BowlingGame BowlingGame::Roll(const std::vector<u32>& rolls)
{
    score_ = std::accumulate(std::cbegin(rolls), std::cend(rolls), score_);
    return *this;
}

u32 BowlingGame::Score() const
{
    return score_;
}


