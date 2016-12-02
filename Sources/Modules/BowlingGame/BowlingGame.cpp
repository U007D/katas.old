#include <cassert>
#include "BowlingGame.h"
#include "Helpers/Exceptions.h"

u32 BowlingGame::Score() const
{
	return score_;
}

u32 BowlingGame::CurrentFrame() const
{
    return 1;
}

u32 BowlingGame::CurrentBall() const
{
    return ball_;
}

BowlingGame BowlingGame::Roll(u32 pins)
{
    if( pins > MAX_PINS_PER_ROLL ) { throw OutOfRangeException(); }
    ++ball_;
    score_ += pins;
    return *this;
}
