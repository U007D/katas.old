#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    BowlingGame(const std::vector<u8>& rolls);
    u32 Score();

private:
    u32 score_ = 0;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H