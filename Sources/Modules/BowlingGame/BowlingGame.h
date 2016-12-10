#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include <array>

#include "3rdParty/variant/variant"
#include "Helpers/UserDefinedTypes.h"

namespace xstd = std::experimental;

/// BowlingGame class contains all information about 1 game (10 frames) of bowling
class BowlingGame
{
public:
    BowlingGame Roll(const std::vector<u32>& rolls);
    u32 Score() const;

private:
    u32 score_ = 0;
    struct Frame
    {
        struct OpenFrame { std::array<u32, 2> rolls; };
        struct ClosedFrame {};
        struct StrikeFrame : public ClosedFrame { std::array<u32, 1> rolls; };
        struct SpareFrame : public ClosedFrame { std::array<u32, 2> rolls; };
        struct StrikeFinalFrame : public ClosedFrame { std::array<u32, 3> rolls; };
        struct SpareFinalFrame: public ClosedFrame { std::array<u32, 3> rolls; };

        xstd::variant<OpenFrame, StrikeFrame, SpareFrame, StrikeFinalFrame, SpareFinalFrame> frame_t;
    };
};

/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// \example ../Tests/Unit/BowlingGame.UnitTests.cpp
/// This is an example of how to use the BowlingGame class.

#endif //BOWLING_GAME_H