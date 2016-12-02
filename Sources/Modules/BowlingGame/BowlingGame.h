#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <experimental/optional>
namespace xstd = std::experimental;

#include "Helpers/AbbreviatedTypes.h"

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
	/// Returns the current game score
    xstd::optional<u32> Score() const;

    /// Returns the current game frame
    u32 Frame() const;

    /// Returns the current frame ball
    u32 Ball() const;

    /// Report a score as a result of a roll
    BowlingGame Roll(u32 pins);

private:
    u32 FrameLength(u32 frameNo) const;
    bool IsInOpenFrame() const;

    static constexpr u32 MAX_PINS_PER_ROLL = 10;
    static constexpr u32 NUM_FRAMES_PER_GAME = 10;
    static constexpr u32 MAX_SCORE_PER_FRAME = 10;
    u32 score_ = 0;
    u32 frame_ = 1;
    u32 ball_ = 1;
    u32 maxPinsRemaining_ = MAX_SCORE_PER_FRAME;
    u32 openFrameCount_ = 0;

};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H