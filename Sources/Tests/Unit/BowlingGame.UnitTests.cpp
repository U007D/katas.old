#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a game consisting of all gutter balls")
    {
        auto game = BowlingGame({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

        THEN("the score should be 0")
        {
            REQUIRE(game.Score() == 0);
        }
    }

    GIVEN("a game consisting of all 1-rolls")
    {
        auto game = BowlingGame({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

        THEN("the score should be 20")
        {
            REQUIRE(game.Score() == 20);
        }
    }
}