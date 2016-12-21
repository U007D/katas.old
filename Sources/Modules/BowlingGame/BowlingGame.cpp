#include "BowlingGame.h"
#include "range/v3/all.hpp"

u16 Score(const std::vector<u8>& rolls, const u8 frame)
{
    return frame > 10 || ranges::empty(rolls)
            ? 0
            : static_cast<u16>(ranges::accumulate(rolls
                                            | ranges::view::take(rolls[0] + rolls[1] >= 10 ? 3 : 2) , 0)
                                        + Score(rolls
                                            | ranges::view::drop(rolls[0] == 10 ? 1 : 2), frame + 1));
}
