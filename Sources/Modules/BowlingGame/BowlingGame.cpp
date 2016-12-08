#include <numeric>
#include <iostream>
#include "BowlingGame.h"

BowlingGame::BowlingGame(const std::vector<u8>& rolls)
{
    frame = 1;
    ball = 1;
    nextRollBonus = 0;
    nextNextRollBonus = 0;
    frameScore = 0;
    calls = 0;

    score_ = std::accumulate(std::begin(rolls), std::end(rolls), 0_u32, [ ](u32 score, u8 roll) {

        std::cout << "Call: " << static_cast<u32>(++calls) << std::endl;

        score = score + roll * (nextRollBonus + 1);
        frameScore += roll;
        if(frame > 10)
        {
//            std::cout << "Frame: " << static_cast<u32>(frame) << std::endl;
            score -= roll;
        }
        nextRollBonus = nextNextRollBonus;
        nextNextRollBonus = 0;

        if (frameScore == 10) {
            ++nextRollBonus;
            frameScore = 0;
            if (ball == 1) {
                ++nextNextRollBonus;
                ++frame;
            } else {
                ++frame;
                --ball;
            }
        }
        else
        {
            if (ball == 2) {
                --ball;
                ++frame;
                frameScore = 0;
            }
            else
            {
                ++ball;
            }
        }
        return score;
    });
}

u32 BowlingGame::Score()
{
    return score_;
}

