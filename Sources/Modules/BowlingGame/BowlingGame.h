#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include "Helpers/UserDefinedTypes.h"

using Roll = u8;
using Score = u32;
using Rolls = std::vector<Roll>;

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    Score CalculateScore(const Rolls &rolls) const;

private:
    std::tuple<Score, Roll, Roll> CalculateScore(Rolls::const_iterator beg, Rolls::const_iterator end, u32 frameNo) const;
    u32 RollsThisFrame(const Rolls::const_iterator &beg, const u32 frameNo) const;

    bool IsStrikeFrame(const Rolls::const_iterator &beg, const u32 frameNo) const;

    bool IsSpareFrame(const Rolls::const_iterator &beg, u32 frameNo) const;
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H