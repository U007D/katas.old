#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game instance")
    {
        auto game = BowlingGame();

        WHEN("a game of all gutterballs is rolled")
        {
            game.Roll({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be zero")
            {
                REQUIRE(game.Score() == 0);
            }
        }

        WHEN("a game of all one balls is rolled")
        {
            game.Roll({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

            THEN("the score should be 20")
            {
                REQUIRE(game.Score() == 20);
            }
        }
    }
}