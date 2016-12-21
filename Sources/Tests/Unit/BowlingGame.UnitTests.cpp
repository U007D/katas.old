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

        WHEN("a spare, a 3-roll followed by gutterballs is rolled")
        {
            auto score = Score({5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 16")
            {
                REQUIRE(score == 16);
            }
        }

        WHEN("a strike, a 3-roll, a 4-roll followed by gutterballs is rolled")
        {
            auto score = Score({10, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

            THEN("the score should be 24")
            {
                REQUIRE(score == 24);
            }
        }
    }
}
