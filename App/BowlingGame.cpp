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
    if(rolls.empty() || depth > 10)  //No more rolls or we're computing score for frame > 10 (bonus rolls for mark in frame 10 were already counted)
    {
        return 0;                    //Either way, end recursion
    }

    auto nextFrameRollIndex = 0;
    auto scoreThisFrame = 0;
    return ranges::accumulate(
            rolls | ranges::view::take(3) //Maximum possible rolls contributing to any frame's score
                  | ranges::view::transform(
                        [&nextFrameRollIndex, &scoreThisFrame](auto value) mutable
                        {
                            if(nextFrameRollIndex == 2 && scoreThisFrame < 10)
                            {
                                value = 0;
                            }
                            else
                            {
                                ++nextFrameRollIndex;
                            }
                            scoreThisFrame += value;
                            return value;
                        }
                    )
                , 0) + CalculateFrameScores(rolls | ranges::view::slice(nextFrameRollIndex, rolls.end()), ++depth);
}