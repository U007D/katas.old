#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game instance")
    {
        auto game = BowlingGame();

        WHEN("a game of all gutter-balls is rolled")
        {
            auto score = game.CalculateScore({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be zero")
            {
                REQUIRE(score == 0);
            }
        }

        AND_WHEN("a game of all ones is rolled")
        {
            auto score = game.CalculateScore({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

            THEN("the score should be 20")
            {
                REQUIRE(score == 20);
            }
        }

        AND_WHEN("a game starting with a spare, followed by a 3-roll and gutterballs for the rest")
        {
            auto score = game.CalculateScore({0, 10, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 16")
            {
                REQUIRE(score == 16);
            }
        }
    }
}