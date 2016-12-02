#include "BowlingGame.h"

u16 BowlingGame::Score() const
{
	return 0;
}

u8 BowlingGame::CurrentFrame() const
{
    return 1;
}

u8 BowlingGame::CurrentBall() const
{
    return currentBall_;
}

BowlingGame BowlingGame::Roll(u8 rollScore)
{
    (void)rollScore;
    ++currentBall_;
    return *this;
}
