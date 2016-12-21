#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
u16 Score(const std::vector<u8>& rolls, const u8 frame = 1);

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H
