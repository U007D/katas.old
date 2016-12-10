#include <numeric>
#include <tuple>
#include "BowlingGame.h"

u32 BowlingGame::CalculateScore(const std::vector<u32>& rolls) const
{
    return CalculateRemainingScore(std::begin(rolls), std::end(rolls), 1);
}

u32 BowlingGame::CalculateRemainingScore(const std::vector<u32>::const_iterator& currRoll,
                                         const std::vector<u32>::const_iterator& endOfRolls,
                                         u32 frameNo) const
{
    if (frameNo > 10) { return 0; }

    auto score = std::accumulate(currRoll, std::next(currRoll, RollsThisFrame(currRoll)), 0_u32);
    auto bonus = IsClosedFrame(currRoll)
                 ? *(std::next(currRoll, RollsThisFrame(currRoll))) + (IsStrikeFrame(currRoll)
                          ? *(std::next(currRoll, RollsThisFrame(currRoll) + 1))
                          : 0)
                 : 0;

    return score + bonus +
           CalculateRemainingScore(std::next(currRoll, RollsThisFrame(currRoll)), endOfRolls, frameNo + 1);
}

u32 BowlingGame::RollsThisFrame(const std::vector<u32>::const_iterator& currRoll) const
{
    return IsStrikeFrame(currRoll) ? 1 : 2;
}

bool BowlingGame::IsStrikeFrame(const std::vector<u32>::const_iterator& currRoll) const
{
    return *currRoll == 10;
}

bool BowlingGame::IsSpareFrame(const std::vector<u32>::const_iterator& currRoll) const
{
    return !IsStrikeFrame(currRoll) && *currRoll + *(std::next(currRoll, 1)) == 10;
}

bool BowlingGame::IsClosedFrame(const std::vector<u32>::const_iterator& currRoll) const
{
    return IsStrikeFrame(currRoll) || IsSpareFrame(currRoll);
}

