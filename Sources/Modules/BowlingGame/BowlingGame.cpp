#include <numeric>

#include "range/v3/all.hpp"
#include "BowlingGame.h"

BowlingGame::BowlingGame()
{
    rolls_.reserve(BowlingConstants::MAX_ROLLS_PER_GAME);
}

BowlingGame BowlingGame::Roll(const Rolls& rolls) noexcept
{
    //TODO: implement semantic insert - ensure rolls_ contains exactly one valid bowling game; ignore extra rolls
    rolls_.insert(std::end(rolls_), std::begin(rolls), std::end(rolls));
    return *this;
}

u16 BowlingGame::Score() const
{
    return ScoreRollsByFrame(Rolls(rolls_));
}

u8 BowlingGame::RollsContributingToScore(const Rolls& rolls) const
{
    return ranges::accumulate(rolls
               | ranges::view::take(2), 0) >= 10 ? 3 : 2;
}

u8 BowlingGame::RollsInFrame(const Rolls& rolls) const
{
    return ranges::accumulate(rolls
                              | ranges::view::take(1), 0) == 10 ? 1 : 2;
}

u16 BowlingGame::ScoreRollsByFrame(const Rolls&& rolls, const u8 frame) const
{
    if(ranges::empty(rolls) || frame > 10) { return 0; }

    return static_cast<u16>(ranges::accumulate(rolls
                                | ranges::view::take_exactly(RollsContributingToScore(rolls)), 0)
                            + ScoreRollsByFrame(rolls
                                | ranges::view::drop(RollsInFrame(rolls)), frame + 1));
}
