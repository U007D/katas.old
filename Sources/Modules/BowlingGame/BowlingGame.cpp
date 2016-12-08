#include <numeric>
#include "BowlingGame.h"

BowlingGame::BowlingGame(const std::vector<u8>& rolls)
{
    score_ = std::accumulate(std::begin(rolls), std::end(rolls), 0_u32, [&](u32 score, u8 roll){
        static u8 frame = 1;    //this lambda is not thread-safe
        static u8 ball = 1;
        static u8 nextRollBonus = 0;
        static u8 nextNextRollBonus = 0;
        static u8 frameScore = 0;

        score = score + roll * (nextRollBonus + 1);
        nextRollBonus = nextNextRollBonus;
        nextNextRollBonus = 0;

        frameScore += roll;
        if(frameScore == 10)
        {
            ++nextRollBonus;
            frameScore = 0;
            if(ball == 1)
            {
                ++nextNextRollBonus;
                ++frame;
            }
            else
            {
                ++frame;
                --ball;
            }
        }
        else
        {
            if(ball == 2)
            {
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

