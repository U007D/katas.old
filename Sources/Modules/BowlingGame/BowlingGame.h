#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include "Helpers/AbbreviatedTypes.h"

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
	/// Returns the current game score
	u16 Score() const;

    /// Returns the current game frame
    u8 CurrentFrame() const;

    /// Returns the current frame ball
    u8 CurrentBall() const;

    /// Report a score as a result of a roll
    BowlingGame Roll(u8 rollScore);

private:
    u8 currentBall_ = 1;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H