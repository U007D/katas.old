#include <numeric>

#include "range/v3/all.hpp"
#include "BowlingGame.h"

struct Consts
{
    static constexpr u8 MAX_ROLLS_PER_GAME = 21;
    static constexpr u8 FRAMES_PER_GAME = 10;
    static constexpr u8 ROLLS_IN_STRIKE_FRAME = 1;
    static constexpr u8 ROLLS_IN_NORMAL_FRAME = 2;
    static constexpr u8 ROLLS_IN_CLOSED_FRAME_SCORE = 3;
    static constexpr u8 ROLLS_IN_OPEN_FRAME_SCORE = 2;
    static constexpr u8 PINS_IN_CLOSED_FRAME = 10;
};

BowlingGame::BowlingGame()
{
    rolls_.reserve(Consts::MAX_ROLLS_PER_GAME);
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

u16 BowlingGame::ScoreRollsByFrame(const Rolls&& rolls, const u8 frame) const
{
    return ranges::empty(rolls) || frame > Consts::FRAMES_PER_GAME
        ? 0
        : static_cast<u16>(ranges::accumulate(rolls
           | ranges::view::take_exactly(ranges::accumulate(rolls
                | ranges::view::take(Consts::ROLLS_IN_NORMAL_FRAME), 0) >= Consts::PINS_IN_CLOSED_FRAME
                                        ? Consts::ROLLS_IN_CLOSED_FRAME_SCORE
                                        : Consts::ROLLS_IN_OPEN_FRAME_SCORE), 0)
        + ScoreRollsByFrame(rolls
                | ranges::view::drop(ranges::accumulate(rolls
                    | ranges::view::take(Consts::ROLLS_IN_STRIKE_FRAME), 0) == Consts::PINS_IN_CLOSED_FRAME
                                        ? Consts::ROLLS_IN_STRIKE_FRAME
                                        : Consts::ROLLS_IN_NORMAL_FRAME), frame + 1));
}
