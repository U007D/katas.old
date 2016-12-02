#include <cassert>
#include "BowlingGame.h"
#include "Helpers/Exceptions.h"

u32 BowlingGame::Score() const
{
	return score_;
}

u32 BowlingGame::Frame() const
{
    return frame_;
}

u32 BowlingGame::Ball() const
{
    return ball_;
}

BowlingGame BowlingGame::Roll(u32 pins)
{
    if( pins > MAX_PINS_PER_ROLL ) { throw OutOfRangeException(); }

    if( ++ball_ > FrameLength(frame_))
    {
        ball_ = 1;
        ++frame_;
    }
    score_ += pins;
    return *this;
}

u32 BowlingGame::FrameLength(u32 frameNo) const
{
    if( frameNo < 1 || frameNo > NUM_FRAMES_PER_GAME ) { throw OutOfRangeException(); }
    return frameNo == 10 ? 3 : 2;
}
