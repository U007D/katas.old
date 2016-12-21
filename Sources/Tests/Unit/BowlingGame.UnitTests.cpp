#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game")
    {
        auto game = BowlingGame();

        THEN("the initial score should be zero")
        {
            REQUIRE(game.Score() == 0);
        }

        WHEN("a frame of gutterballs is rolled")
        {
            auto score = game.Roll({0, 0}).Score();

            THEN("the score should be zero")
            {
                REQUIRE(score == 0);
            }
        }

        WHEN("a frame of one-balls is rolled")
        {
            auto score = game.Roll({1, 1}).Score();

            THEN("the score should be two")
            {
                REQUIRE(score == 2);
            }
        }

        WHEN("a spare, a 3-ball followed by a gutterball is rolled")
        {
            auto score = game.Roll({5, 5, 3, 0}).Score();

            THEN("the score should be 16")
            {
                REQUIRE(score == 16);
            }
        }
    }
}
