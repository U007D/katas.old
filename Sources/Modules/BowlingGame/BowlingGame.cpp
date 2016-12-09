#include <numeric>
#include <tuple>
#include "BowlingGame.h"

u32 BowlingGame::CalculateScore(const Rolls &rolls) const {
    return std::get<0>(CalculateScore(std::begin(rolls), std::end(rolls), 1_u8));
}

std::tuple<Score, Roll, Roll> BowlingGame::CalculateScore(Rolls::const_iterator beg, Rolls::const_iterator end,
                                                          u32 frameNo) const {
    if(beg == end) { return std::make_tuple(0, 0, 0); }

    auto restOfScore = CalculateScore(beg + RollsThisFrame(beg, frameNo), end, frameNo + 1);

    auto bonusThisFrame = 0_u32;
    if( IsStrikeFrame(beg, frameNo) )
    {
        bonusThisFrame = std::get<1>(restOfScore) + std::get<2>(restOfScore);
    }
    else if(IsSpareFrame(beg, frameNo))
    {
        bonusThisFrame = std::get<1>(restOfScore);
    }
    return std::make_tuple(frameNo <= 10 ? *beg + (IsStrikeFrame(beg, frameNo) ? 0 : *(beg + 1)) + std::get<0>(restOfScore) + bonusThisFrame : 0, *beg, *(beg + 1));
}

u32 BowlingGame::RollsThisFrame(const Rolls::const_iterator &beg, const u32 frameNo) const {
    return IsStrikeFrame(beg, frameNo) ? (frameNo == 10 ? 3 : 1) : 2;
}

bool BowlingGame::IsStrikeFrame(const Rolls::const_iterator &beg, const u32 frameNo) const {
    return *beg == 10 && frameNo <= 10 ? true : false;
}

bool BowlingGame::IsSpareFrame(const Rolls::const_iterator &beg, u32 frameNo) const {
    return frameNo <= 10 && !IsStrikeFrame(beg, frameNo) ? *beg + *(beg + 1) == 10 : false;
}
