//
// Created by bRad on 7/9/16.
//

#include "BowlingGame.h"
#include "range/v3/all.hpp"

int BowlingGame::Score(const std::vector<int>& rolls) const
{
    return CalculateFrameScores(rolls, 1);
}

int BowlingGame::CalculateFrameScores(const std::vector<int>& rolls, int depth) const
{
    if (rolls.empty() || depth > 10)  //No more rolls or we're computing score for frame > 10 (bonus rolls for mark in frame 10 were already counted)
    {
        return 0;                     //Either way, end recursion
    }

    assert(rolls.size() <=
           std::numeric_limits<size_t>::max() >> 1); //Ranges uses signed parameters, so ensure no overflow

    auto nextFrameStartIndex = 2;   //Frame nominally composed of two rolls
    auto markThisFrame = false;
    auto currentRoll = 0;
    auto scoreThisFrame = 0;
    return ranges::accumulate(
            rolls
            | ranges::view::take(3) //Maximum possible rolls contributing to any frame's score
            | ranges::view::transform(
                    [&](auto value) mutable
                    {
                        ++currentRoll;
                        if (currentRoll == 1 && value == 10) //Strike - only one roll this frame -- include two bonus rolls
                        {
                            markThisFrame = true;
                            nextFrameStartIndex = 1;
                        }
                        else if (currentRoll == 2 && scoreThisFrame + value == 10) //Spare -- include bonus roll
                        {
                            markThisFrame = true;
                        }
                        else if (currentRoll == 3 && !markThisFrame) //Open frame -- do not include third roll as bonus
                        {
                            value = 0;
                        }
                        scoreThisFrame += value;
                        return value;
                    }
            ), 0) + CalculateFrameScores(rolls | ranges::view::slice(nextFrameStartIndex, static_cast<int>(rolls.size())),
                                ++depth);
}