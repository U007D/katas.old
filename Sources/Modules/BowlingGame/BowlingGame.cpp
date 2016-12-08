#include <numeric>
#include "BowlingGame.h"

BowlingGame::BowlingGame(const std::vector<u8>& rolls)
{
    score_ = std::accumulate(std::begin(rolls), std::end(rolls), 0_u32);
}

u32 BowlingGame::Score()
{
    return score_;
}

