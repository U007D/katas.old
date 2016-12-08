#include <numeric>
#include <tuple>
#include "BowlingGame.h"

u32 BowlingGame::CalculateScore(const Rolls &rolls) const {
    return std::get<0>(CalculateScore(std::begin(rolls), std::end(rolls), 1_u8));
}

std::tuple<Score, Roll, Roll> BowlingGame::CalculateScore(Rolls::const_iterator beg, Rolls::const_iterator end,
                                                          u32 frameNo) const {
    if(beg == end) { return std::make_tuple(0, 0, 0); }
    auto restOfScore = CalculateScore(beg + (*beg == 10 ? 1 : 2), end, frameNo + 1);
    auto bonus = 0_u32;
    if( *beg == 10 )
    {
        bonus = std::get<1>(restOfScore) + std::get<2>(restOfScore);
    }
    else if( *beg + *(beg + 1) == 10)
    {
        bonus = std::get<1>(restOfScore);
    }
    return std::make_tuple(*beg + (*beg == 10 ? 0 : *(beg + 1)) + std::get<0>(restOfScore) + bonus, *beg, *(beg + 1));
}
