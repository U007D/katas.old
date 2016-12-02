#include <cassert>
#include "BowlingGame.h"
#include "Helpers/Exceptions.h"

xstd::optional<u32> BowlingGame::Score() const
{
	if (IsInOpenFrame())
    {
        return xstd::nullopt;
    }
    else
    {
        return score_;
    }
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
    if( pins > MAX_PINS_PER_ROLL || pins > maxPinsRemaining_ ) { throw OutOfRangeException(); }

    score_ += pins;
    maxPinsRemaining_ -= pins;

    if( !maxPinsRemaining_ )
    {
        ++openFrameCount_;
    }

    if( ++ball_ > FrameLength(frame_) || maxPinsRemaining_ == 0)
    {
        ball_ = 1;
        ++frame_;
        maxPinsRemaining_ = MAX_SCORE_PER_FRAME;
    }

    return *this;
}

u32 BowlingGame::FrameLength(u32 frameNo) const
{
    if( frameNo < 1 || frameNo > NUM_FRAMES_PER_GAME ) { throw OutOfRangeException(); }
    return frameNo == 10 ? 3 : 2;
}

bool BowlingGame::IsInOpenFrame() const
{
    return openFrameCount_ == 0 ? true : false;
}
