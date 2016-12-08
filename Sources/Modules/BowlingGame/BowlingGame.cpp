#include <numeric>
#include "BowlingGame.h"

u32 BowlingGame::Score(const std::vector<u8>& rolls) {
    return std::accumulate(std::begin(rolls), std::end(rolls), 0_u32);
}
