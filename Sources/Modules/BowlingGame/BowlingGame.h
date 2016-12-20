#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

struct BowlingConstants
{
    static constexpr u8 MAX_ROLLS_PER_GAME = 21;
};

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    BowlingGame();
    u16 Score() const;
    BowlingGame Roll(const std::vector<u8>& rolls);
private:
    std::vector<u8> rolls_;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H