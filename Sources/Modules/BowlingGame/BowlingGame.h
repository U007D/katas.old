#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <array>
#include <3rdParty/variant/variant>
#include "Helpers/AbbreviatedTypes.h"

namespace xstd = std::experimental;

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    using StandardFrame = std::array<u8, 2>;
    using LastFrame = std::array<u8, 3>;
    using Frame = xstd::variant<StandardFrame, LastFrame>;
    static u8 constexpr FRAMES_PER_GAME = 10;
    u32 Score(std::array<Frame,FRAMES_PER_GAME> frames);
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H