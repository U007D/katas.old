#include <regex>

#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
	GIVEN("an empty bowling game")
	{
		auto game = BowlingGame();

		WHEN("the score is requested")
		{
			auto result = game.Score();

			THEN("the result is 0")
			{
				REQUIRE(result == 0);
			}

			AND_THEN("the current frame is 1")
			{
				REQUIRE(game.CurrentFrame() == 1);
			}

			AND_THEN("the current ball is 1")
			{
				REQUIRE(game.CurrentBall() == 1);
			}
		}
	}
}