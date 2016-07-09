//
// Created by bRad on 7/9/16.
//

#include <vector>
#include <range/v3/all.hpp>
#include <gtest/gtest.h>

#include "BowlingGame.h"

TEST(BowlingScoreTests, all_gutter_balls_yield_0_score)
{
    //Given
    auto rolls = std::vector<int>{ranges::view::repeat_n(0, 20)};
    auto expectedScore = 0;
    auto game = std::make_unique<BowlingGame>();

    //When
    auto result = game->Score(rolls);

    //Then
    EXPECT_EQ(result, expectedScore);
}

TEST(BowlingScoreTests, all_1_balls_yield_20_score)
{
    //Given
    auto rolls = std::vector<int>{ranges::view::repeat_n(1, 20)};
    auto expectedScore = 20;
    auto game = std::make_unique<BowlingGame>();

    //When
    auto result = game->Score(rolls);

    //Then
    EXPECT_EQ(result, expectedScore);
}

TEST(BowlingScoreTests, all_5_balls_yield_150_score)
{
    //Given
    auto rolls = std::vector<int>{ranges::view::repeat_n(5, 21)};
    auto expectedScore = 150;
    auto game = std::make_unique<BowlingGame>();

    //When
    auto result = game->Score(rolls);

    //Then
    EXPECT_EQ(result, expectedScore);
}

TEST(BowlingScoreTests, all_10_balls_yield_300_score)
{
    //Given
    auto rolls = std::vector<int>{ranges::view::repeat_n(10, 12)};
    auto expectedScore = 300;
    auto game = std::make_unique<BowlingGame>();

    //When
    auto result = game->Score(rolls);

    //Then
    EXPECT_EQ(result, expectedScore);
}