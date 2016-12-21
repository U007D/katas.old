#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

using Rolls = std::vector<u8>;

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    BowlingGame();

    u16 Score() const;
    BowlingGame Roll(const Rolls& rolls) noexcept;
private:
    u16 ScoreRollsByFrame(const Rolls&& rolls, const u8 frame = 1) const;

    Rolls rolls_;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H