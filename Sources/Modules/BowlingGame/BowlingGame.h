#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include "Helpers/AbbreviatedTypes.h"

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
	/// Returns the current game score
	u32 Score() const;

    /// Returns the current game frame
    u32 CurrentFrame() const;

    /// Returns the current frame ball
    u32 CurrentBall() const;

    /// Report a score as a result of a roll
    BowlingGame Roll(u32 pins);

private:
    static constexpr u32 MAX_PINS_PER_ROLL = 10;
    u32 score_ = 0;
    u32 ball_ = 1;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H