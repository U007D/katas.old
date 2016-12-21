#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("bowling game scoring system")
    {
        WHEN("all gutterballs are rolled")
        {
            auto score = Score({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 0")
            {
                REQUIRE(score == 0);
            }
        }

        WHEN("all one-balls are rolled")
        {
            auto score = Score({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

            THEN("the score should be 20")
            {
                REQUIRE(score == 20);
            }
        }
    }
}
