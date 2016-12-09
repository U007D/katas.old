#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

using Roll = u32;
using Rolls = std::vector<Roll>;

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    u32 CalculateScore(const Rolls& rolls) const;

private:
    u32 CalculateRemainingScore(const Rolls::const_iterator& currRoll,
                                const Rolls::const_iterator& endOfRolls,
                                u32 frameNo) const;
    u32 RollsThisFrame(const Rolls::const_iterator& currRoll) const;

    bool IsStrikeFrame(const Rolls::const_iterator& currRoll) const;
    bool IsSpareFrame(const Rolls::const_iterator& currRoll) const;
    bool IsClosedFrame(const Rolls::const_iterator& currRoll) const;

};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H