#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game instance")
    {
        auto game = BowlingGame();

        WHEN("a game consisting of all gutter-balls is rolled")
        {
            auto score = game.Score({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be zero")
            {
                REQUIRE(score == 0);
            }
        }
    }
}