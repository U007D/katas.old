#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game")
    {
        auto game = BowlingGame();

        THEN("the score should be zero")
        {
            REQUIRE(game.Score() == 0);
        }

        WHEN("a frame of gutterballs is rolled")
        {
            game.Roll({0, 0});

            THEN("the score should be zero")
            {
                REQUIRE(game.Score() == 0);
            }
        }

        WHEN("a frame of one-balls is rolled")
        {
            game.Roll({1, 1});

            THEN("the score should be two")
            {
                REQUIRE(game.Score() == 2);
            }
        }
    }
}
