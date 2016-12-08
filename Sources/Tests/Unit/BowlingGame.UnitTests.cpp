#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game instance")
    {
        auto game = BowlingGame();

        WHEN("a game of all gutterballs is rolled")
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

        AND_WHEN("a game starting with a spare, followed by a 3-roll with gutterballs for the rest")
        {
            auto score = game.CalculateScore({0, 10, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 16")
            {
                REQUIRE(score == 16);
            }
        }

        AND_WHEN("a game starts with a strike, followed by a 3- and 4-roll with gutterballs for the rest")
        {
            auto score = game.CalculateScore({10, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 24")
            {
                REQUIRE(score == 24);
            }
        }

        AND_WHEN("a perfect game is rolled")
        {
            auto score = game.CalculateScore({10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10});
            {
                THEN("the score should be 300")
                {
                    REQUIRE(score == 300);
                }
            }
        }
    }
}