#include <regex>

#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
    GIVEN("a bowling game with no scores")
    {
        auto rolls = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

            THEN("the score should be 0")
            {
                REQUIRE(BowlingGame::Score(rolls) == 0);
            }
        }
    }
}