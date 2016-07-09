//
// Created by bRad on 7/9/16.
//

#include <vector>
#include <range/v3/all.hpp>
#include <gtest/gtest.h>

#include "BowlingGame.h"

TEST(BowlingScore, all_gutter_balls_yields_0_score)
{
    //Given
    auto rolls = std::vector<int>(10);
    ranges::fill(rolls, 0);
    auto expectedScore = 0;
    auto game = std::make_unique<BowlingGame>();

    //When
    auto result = game->Score(rolls);

    //Then
    EXPECT_EQ(result, expectedScore);
}